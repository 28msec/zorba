

/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"


#include "compiler/expression/expr.h"
#include "compiler/expression/expr_iter.h"

#include "compiler/xqddf/value_index.h"

#include "compiler/rewriter/rules/index_matching_rule.h"
#include "compiler/rewriter/rules/fold_rules.h"
#include "compiler/rewriter/tools/expr_tools.h"

#include "compiler/api/compilercb.h"

#include "functions/function.h"
#include "functions/library.h"

#include "util/dynamic_bitset.h"

#include "diagnostics/assert.h"

#include "system/properties.h"


namespace zorba
{


/*******************************************************************************

********************************************************************************/
IndexMatchingRule::IndexMatchingRule(IndexDecl* decl)
  :
  RewriteRule(RewriteRule::IndexJoin, "IndexJoin"),
  theIndexDecl(decl),
  theViewExpr(NULL),
  theDoTrace(true)
{
  theViewExpr = decl->getViewExpr();

  csize numVClauses = theViewExpr->num_clauses();

  theKeyClauses.reserve(numVClauses);

  for (csize i = 1; i < numVClauses; ++i)
  {
    assert(theViewExpr->get_clause(i)->get_kind() == flwor_clause::let_clause);
    let_clause* lc = static_cast<let_clause*>(theViewExpr->get_clause(i));
    theKeyClauses.push_back(lc);
  }

  std::ostringstream msg;
  msg << "normalization of candidate index: " << decl->getName()->getStringValue();

  RewriterContext rCtx(theViewExpr->get_ccb(),
                       theViewExpr,
                       theViewExpr->get_udf(),
                       msg.str(),
                       true);
  FoldRules foldRules;
  foldRules.rewrite(rCtx);

  if (Properties::instance()->printIntermediateOpt() && theDoTrace)
  {
    std::cout << "Canonical view expr for candidate index : " 
              << decl->getName()->getStringValue() << std::endl;
    rCtx.getRoot()->put(std::cout) << std::endl;
  }
}


/*******************************************************************************

********************************************************************************/
expr* IndexMatchingRule::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  modified = false;

  // TODO remove this
  if (theIndexDecl->isGeneral() || theIndexDecl->isOrdered())
    return node;

  if (node->get_expr_kind() == flwor_expr_kind ||
      node->get_expr_kind() == gflwor_expr_kind)
  {
    theQueryExpr = static_cast<flwor_expr*>(node);

    bool matched = matchIndex();

    if (matched)
      modified = true;
  }

  ExprIterator iter(node);
  while (!iter.done())
  {
    expr* currChild = **iter;

    bool childModified = false;

    expr* newChild = apply(rCtx, currChild, childModified);

    ZORBA_ASSERT(currChild == newChild);

    if (childModified)
      modified = true;

    iter.next();
  }

  return node;
}


/*******************************************************************************
  Match a flwor expr with an index
********************************************************************************/
bool IndexMatchingRule::matchIndex()
{
  CompilerCB* ccb = theQueryExpr->get_ccb();
  static_context* sctx = theQueryExpr->get_sctx();
  user_function* udf = theQueryExpr->get_udf();

  csize numVClauses = theViewExpr->num_clauses();
  csize numQClauses = theQueryExpr->num_clauses();
  csize nextQueryClause = 0;

  expr::substitution_t subst;

  for_clause* probeFORclause = NULL;
  csize probeFORclausePos = 0;
  DynamicBitset matchedClauses(numQClauses);
  matchedClauses.reset();

  std::vector<PredInfo> preds;
  std::vector<PredInfo> unmatchedPreds;
  std::vector<PredInfo> matchedPreds;

  // Match the FOR and WHERE clauses of the view FLWOR. For now, we can match
  // only indexes whose domain and key expressions consist of FOR, LET, and
  // WHERE clauses only.
  for (csize vi = 0; vi < numVClauses; ++vi)
  {
    flwor_clause* vc = theViewExpr->get_clause(vi);

    switch (vc->get_kind())
    {
    case flwor_clause::for_clause:
    {
      for_clause* vfc = static_cast<for_clause*>(vc);
      expr* vdomExpr = vfc->get_expr();
      var_expr* vvarExpr = vfc->get_var();

      bool matched = false;

      for (csize qi = nextQueryClause; qi < numQClauses && !matched; ++qi)
      {
        flwor_clause* qc = theQueryExpr->get_clause(qi);

        switch (qc->get_kind())
        {
        case flwor_clause::for_clause:
        {
          for_clause* qfc = static_cast<for_clause*>(qc);
          expr* qdomExpr = qfc->get_expr();
          var_expr* qvarExpr = qfc->get_var();

          if (expr_tools::match_exact(qdomExpr, vdomExpr, subst))
          {
            nextQueryClause = qi+1;
            subst[vvarExpr] = qvarExpr;
            matchedClauses.set(qi, true);

            if (!probeFORclause)
            {
              probeFORclause = qfc;
              probeFORclausePos = qi;
            }

            matched = true;
            break;
          }
          else if (probeFORclause != NULL)
          {
            // TODO allow for FOR clause reordering, if conditions allow it
            return false;
          }

          break;
        }
        case flwor_clause::let_clause:
        case flwor_clause::order_clause:
        {
          break;
        }
        case flwor_clause::window_clause:
        {
          if (probeFORclause != NULL)
          {
            // TODO allow for FOR clause reordering, if conditions allow it
            return false; // todo
          }

          break;
        }
        case flwor_clause::where_clause:
        {
          getQueryPreds(qi, preds);
          break;
        }
        case flwor_clause::count_clause:
        case flwor_clause::groupby_clause:
        case flwor_clause::materialize_clause:
        {
          return false;
        }
        default:
          ZORBA_ASSERT(false);
        }
      }

      if (!matched)
        return false;
    }
    case flwor_clause::let_clause:
    {
      break;
    }
    case flwor_clause::where_clause:
    {
      where_clause* vwc = static_cast<where_clause*>(vc);
      expr* vwhereExpr = vwc->get_expr();
      bool matched = false;

      for (csize qi = nextQueryClause; qi < numQClauses && !matched; ++qi)
      {
        flwor_clause* qc = theQueryExpr->get_clause(qi);

        if (qc->get_kind() != flwor_clause::where_clause)
          continue;

        where_clause* qwc = static_cast<where_clause*>(qc);
        expr* qwhereExpr = qwc->get_expr();

        if (expr_tools::match_exact(qwhereExpr, vwhereExpr, subst))
        {
          nextQueryClause = qi+1;
          matched = true;
          matchedClauses.set(qi, true);
          break;
        }
        else
        {
          getQueryPreds(qi, preds);
        }
      }

      if (!matched)
        return false;

      break;
    }
    default:
    {
      assert(false);
      return false;
    }
    }
  }

  // Create the vector to store the args of the probe function
  std::vector<expr*> probeArgs;
  probeArgs.reserve(theKeyClauses.size() + 1);

  // Create the index-name expr and make it the 1st arg of the probe function
  store::Item_t indexName = theIndexDecl->getName();

  expr* qnameExpr = ccb->theEM->
  create_const_expr(sctx, udf, probeFORclause->get_loc(), indexName);

  probeArgs.push_back(qnameExpr);

  // Collect the rest of the query preds, if any
  for (csize qi = nextQueryClause; qi < numQClauses; ++qi)
  {
    flwor_clause* qc = theQueryExpr->get_clause(qi);

    if (qc->get_kind() != flwor_clause::where_clause)
      continue;

    getQueryPreds(qi, preds);
  }

  // Match the predicates
  std::vector<let_clause*>::const_iterator keyIte = theKeyClauses.begin();
  std::vector<let_clause*>::const_iterator keyEnd = theKeyClauses.end();

  for (; keyIte != keyEnd; ++keyIte)
  {
    expr* keyExpr = (*keyIte)->get_expr();
    bool matched = false;

    std::vector<PredInfo>::iterator predIte = preds.begin();
    std::vector<PredInfo>::iterator predEnd = preds.end();

    for (; predIte != predEnd; ++predIte)
    {
      if (predIte->theExpr->get_expr_kind() != fo_expr_kind)
      {
        unmatchedPreds.push_back(*predIte);
        continue;
      }

      fo_expr* predExpr = static_cast<fo_expr*>(predIte->theExpr);
      function* predFunc = predExpr->get_func();

      if (predFunc->getKind() == FunctionConsts::FN_BOOLEAN_1)
      {
        if (predExpr->get_arg(0)->get_expr_kind() != fo_expr_kind)
        {
          unmatchedPreds.push_back(*predIte);
          continue;
        }

        predExpr = static_cast<fo_expr*>(predExpr->get_arg(0));
        predFunc = predExpr->get_func();
      }

      if (predFunc->comparisonKind() != CompareConsts::VALUE_EQUAL)
      {
        unmatchedPreds.push_back(*predIte);
        continue;
      }

      if (expr_tools::match_exact(predExpr->get_arg(0), keyExpr, subst))
      {
        matchedPreds.push_back(*predIte);
        probeArgs.push_back(predExpr->get_arg(1));
        matched = true;
        break;
      }
      else if (expr_tools::match_exact(predExpr->get_arg(1), keyExpr, subst))
      {
        matchedPreds.push_back(*predIte);
        probeArgs.push_back(predExpr->get_arg(0));
        matched = true;
        break;
      }
    }

    if (!matched)
      return false;
  }

  // Mark the flwor vars of the query flwor expr as "not used" initially
  std::vector<var_expr*> queryVars;
  theQueryExpr->get_vars(queryVars);

  for (csize i = 0; i < queryVars.size(); ++i)
  {
    queryVars[i]->setVisitId(0);
  }

  // Check for dependencies on query vars that will be eliminated by the rewrite
  const var_expr* domVar = theViewExpr->get_return_expr()->get_var();
  assert(domVar);
  assert(subst[domVar]->get_expr_kind() == var_expr_kind);
  domVar = static_cast<const var_expr*>(subst[domVar]);
 
  for (csize i = 0; i < unmatchedPreds.size(); ++i)
  {
    expr* pred = unmatchedPreds[i].theExpr;
    if (!checkFreeVars(pred, domVar, matchedClauses))
      return false;
  }

  if (!checkFreeVars(theQueryExpr->get_return_expr(), domVar, matchedClauses))
      return false;

  for (csize i = numQClauses-1; i > 0; --i)
  {
    if (matchedClauses.get(i))
      continue;

    flwor_clause* c = theQueryExpr->get_clause(i);

    switch (c->get_kind())
    {
    case flwor_clause::for_clause:
    {
      if (matchedClauses.get(i))
        continue;
    }
    case flwor_clause::let_clause:
    {
      forlet_clause* flc = static_cast<forlet_clause*>(c);
      var_expr* var = flc->get_var();

      if (!var->isVisited(1))
        continue;

      if (!checkFreeVars(flc->get_expr(), domVar, matchedClauses))
        return false;

      break;
    }
    case flwor_clause::order_clause:
    {
      orderby_clause* oc = static_cast<orderby_clause*>(c);

      std::vector<expr*>::const_iterator ite = oc->begin();
      std::vector<expr*>::const_iterator end = oc->end();
      for (; ite != end; ++ite)
      {
        if (!checkFreeVars(*ite, domVar, matchedClauses))
          return false;
      }

      break;
    }
    case flwor_clause::groupby_clause:
    {
      groupby_clause* gc = static_cast<groupby_clause*>(c);

      flwor_clause::rebind_list_t::const_iterator ite = gc->beginGroupVars();
      flwor_clause::rebind_list_t::const_iterator end = gc->endGroupVars();
      for (; ite != end; ++ite)
      {
        if (!checkFreeVars(ite->first, domVar, matchedClauses))
          return false;
      }

      ite = gc->beginNonGroupVars();
      end = gc->endNonGroupVars();
      for (; ite != end; ++ite)
      {
        if (!checkFreeVars(ite->first, domVar, matchedClauses))
          return false;
      }

      break;
    }
    case flwor_clause::count_clause:
    case flwor_clause::where_clause:
    case flwor_clause::materialize_clause:
    {
      break;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }

  // Do the rewrite
  for (csize i = 0; i < matchedPreds.size(); ++i)
  {
    if (matchedPreds[i].theClause != NULL)
    {
      matchedClauses.set(matchedPreds[i].thePos, true);
    }
    else
    {
      matchedPreds[i].theFoExpr->remove_arg(matchedPreds[i].thePos);
    }
  }

  fo_expr* probeExpr = ccb->theEM->
  create_fo_expr(sctx,
                 udf,
                 probeFORclause->get_loc(),
                 BUILTIN_FUNC(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N),
                 probeArgs);

  probeFORclause->set_expr(probeExpr);

  csize numRemoved = 0;
  for (csize i = probeFORclausePos + 1; i < matchedClauses.size(); ++i)
  {
    if (matchedClauses.get(i))
    {
      theQueryExpr->remove_clause(i - numRemoved);
      ++numRemoved;
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
void IndexMatchingRule::getQueryPreds(csize clausePos, std::vector<PredInfo>& preds)
{
  where_clause* wc = static_cast<where_clause*>(theQueryExpr->get_clause(clausePos));
  expr* whereExpr = wc->get_expr();

  if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_N)
  {
    fo_expr* andExpr = static_cast<fo_expr*>(whereExpr);
    csize numArgs = andExpr->num_args();

    for (csize i = 0; i < numArgs; ++i)
    {
      preds.push_back(PredInfo(andExpr->get_arg(i), i, NULL, andExpr));
    }
  }
  else
  {
    preds.push_back(PredInfo(wc->get_expr(), clausePos, wc, NULL));
  }
}


/*******************************************************************************

********************************************************************************/
bool IndexMatchingRule::checkFreeVars(
    const expr* qexpr,
    const var_expr* domVar,
    const DynamicBitset& matchedClauses)
{
  const expr::FreeVars& freeVars = qexpr->getFreeVars();

  expr::FreeVars::const_iterator ite = freeVars.begin();
  expr::FreeVars::const_iterator end = freeVars.end();
  for (; ite != end; ++ite)
  {
    var_expr* freeVar = *ite;

    if (freeVar == domVar)
      continue;

    if (freeVar->get_flwor_clause()->get_flwor_expr() == theQueryExpr)
    {
      freeVar->setVisitId(1);
    }

    if (freeVar->get_kind() != var_expr::for_var)
      continue;

    for (csize i = 0; i < matchedClauses.size(); ++i)
    {
      if (matchedClauses.get(i) &&
          freeVar->get_flwor_clause() == theQueryExpr->get_clause(i))
      {
        return false;
      }
    }
  }

  return true;
}


}

/* vim:set et sw=2 ts=2: */
