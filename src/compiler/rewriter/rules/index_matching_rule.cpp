

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
#include "compiler/rewriter/tools/expr_tools.h"

#include "compiler/api/compilercb.h"

#include "functions/function.h"
#include "functions/library.h"

#include "util/dynamic_bitset.h"

#include "diagnostics/assert.h"


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

  for (csize i = 1; i < numVClauses; ++i)
  {
    assert(theViewExpr->get_clause(i)->get_kind() == flwor_clause::let_clause);
    let_clause* lc = static_cast<let_clause*>(theViewExpr->get_clause(i));
    theKeyExprs.push_back(lc->get_expr());
  }
}


/*******************************************************************************

********************************************************************************/
expr* IndexMatchingRule::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  modified = false;

  if (node->get_expr_kind() == flwor_expr_kind)
  {
    theQueryExpr = static_cast<flwor_expr*>(node);

    bool matched = matchIndex();

    if (matched)
    {
      modified = true;
      return node;
    }
  }

  ExprIterator iter(node);
  while (!iter.done())
  {
    expr* currChild = **iter;

    expr* newChild = apply(rCtx, currChild, modified);

    ZORBA_ASSERT(currChild == newChild);

    if (modified)
      break;

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
  csize probeFORclausePos;
  DynamicBitset matchedFORs(numQClauses);
  matchedFORs.reset();

  // Match the FOR clauses of the view FLWOR
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

      csize qi = nextQueryClause;

      for (; qi < numQClauses; ++qi)
      {
        flwor_clause* qc = theQueryExpr->get_clause(qi);

        if (qc->get_kind() != flwor_clause::for_clause)
          continue;

        for_clause* qfc = static_cast<for_clause*>(qc);
        expr* qdomExpr = qfc->get_expr();
        var_expr* qvarExpr = qfc->get_var();

        if (expr_tools::match_exact(qdomExpr, vdomExpr, subst))
        {
          nextQueryClause = qi+1;
          subst[vvarExpr] = qvarExpr;
          matchedFORs.set(qi, true);

          if (!probeFORclause)
          {
            probeFORclause = qfc;
            probeFORclausePos = qi;
          }

          break;
        }
      }

      if (qi == numQClauses)
        return false;
    }
    case flwor_clause::let_clause:
    {
      break;
    }
    default:
    {
      // For now we can match only indexes whose domain and key expressions
      assert(false);
      return false;
    }
    }
  }

  std::vector<expr*> probeArgs;
  probeArgs.reserve(theKeyExprs.size() + 1);

  // create the index-name expr
  store::Item_t indexName = theIndexDecl->getName();

  expr* qnameExpr = ccb->theEM->
  create_const_expr(sctx, udf, probeFORclause->get_loc(), indexName);

  probeArgs.push_back(qnameExpr);

  // match predicates
  std::vector<expr**> preds;
  std::vector<expr**> unmatchedPreds;
  std::vector<expr**> matchedPreds;

  getQueryPreds(preds);

  std::vector<expr*>::const_iterator keyIte = theKeyExprs.begin();
  std::vector<expr*>::const_iterator keyEnd = theKeyExprs.end();

  for (; keyIte != keyEnd; ++keyIte)
  {
    expr* keyExpr = *keyIte;
    bool matched = false;

    std::vector<expr**>::iterator predIte = preds.begin();
    std::vector<expr**>::iterator predEnd = preds.end();

    for (; predIte != predEnd; ++predIte)
    {
      if ((**predIte)->get_expr_kind() != fo_expr_kind)
      {
        unmatchedPreds.push_back(*predIte);
        continue;
      }

      fo_expr* predExpr = static_cast<fo_expr*>(**predIte);
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
    expr* pred = *unmatchedPreds[i];
    if (!checkFreeVars(pred, domVar, matchedFORs))
      return false;
  }

  if (!checkFreeVars(theQueryExpr->get_return_expr(), domVar, matchedFORs))
      return false;

  for (csize i = numQClauses-1; i > 0; --i)
  {
    if (matchedFORs.get(i))
      continue;

    flwor_clause* c = theQueryExpr->get_clause(i);

    switch (c->get_kind())
    {
    case flwor_clause::for_clause:
    {
      if (matchedFORs.get(i))
        continue;
    }
    case flwor_clause::let_clause:
    {
      forlet_clause* flc = static_cast<forlet_clause*>(c);
      var_expr* var = flc->get_var();

      if (!var->isVisited(1))
        continue;

      if (!checkFreeVars(flc->get_expr(), domVar, matchedFORs))
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
        if (!checkFreeVars(*ite, domVar, matchedFORs))
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
        if (!checkFreeVars(ite->first, domVar, matchedFORs))
          return false;
      }

      ite = gc->beginNonGroupVars();
      end = gc->endNonGroupVars();
      for (; ite != end; ++ite)
      {
        if (!checkFreeVars(ite->first, domVar, matchedFORs))
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
  fo_expr* probeExpr = ccb->theEM->
  create_fo_expr(sctx,
                 udf,
                 probeFORclause->get_loc(),
                 BUILTIN_FUNC(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N),
                 probeArgs);

  probeFORclause->set_expr(probeExpr);

  csize numRemoved = 0;
  for (csize i = probeFORclausePos + 1; i < matchedFORs.size(); ++i)
  {
    theQueryExpr->remove_clause(i - numRemoved);
    ++numRemoved;
  }

  for (csize i = 0; i < matchedPreds.size(); ++i)
  {
    expr* trueExpr = ccb->theEM->
    create_const_expr(sctx, udf, (*matchedPreds[i])->get_loc(), xs_boolean(true));

    *matchedPreds[i] = trueExpr;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
void IndexMatchingRule::getQueryPreds(std::vector<expr**>& preds)
{
  csize numQClauses = theQueryExpr->num_clauses();

  for (csize i = 0; i < numQClauses; ++i)
  {
    flwor_clause* qc = theQueryExpr->get_clause(i);

    if (qc->get_kind() != flwor_clause::where_clause)
      continue;

    where_clause* wqc = static_cast<where_clause*>(qc); 
    expr* whereExpr = wqc->get_expr();

    if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_N)
    {
      ExprIterator ite(whereExpr);

      while (!ite.done())
      {
        preds.push_back(*ite);
        ite.next();
      }
    }
    else
    {
      preds.push_back(wqc->get_expr_ref());
    }
  }
}


/*******************************************************************************

********************************************************************************/
bool IndexMatchingRule::checkFreeVars(
    const expr* qexpr,
    const var_expr* domVar,
    const DynamicBitset& matchedFORs)
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

    for (csize i = 0; i < matchedFORs.size(); ++i)
    {
      if (matchedFORs.get(i) &&
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
