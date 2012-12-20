

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

#include "types/typeops.h"

#include "util/dynamic_bitset.h"

#include "diagnostics/assert.h"

#include "system/properties.h"


namespace zorba
{


/*******************************************************************************

********************************************************************************/
IndexMatchingRule::PredInfo::PredInfo(
    where_clause* wc,
    csize wcPos,
    fo_expr* andExpr,
    csize argPos)
  :
  theClause(wc),
  theClausePos(wcPos),
  theAndExpr(andExpr),
  theArgPos(argPos)
{
  if (theAndExpr)
  {
    assert(theAndExpr->get_func()->getKind() == FunctionConsts::OP_AND_N);

    theExpr = theAndExpr->get_arg(theArgPos);
  }
  else
  {
    theExpr = theClause->get_expr();
  }
}


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

  std::vector<PredInfo> vpreds;
  std::vector<PredInfo> unmatchedQPreds;
  std::vector<PredInfo> matchedQPreds;

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
          getWherePreds(qi, static_cast<where_clause*>(qc), unmatchedQPreds);
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

      break;
    }
    case flwor_clause::let_clause:
    {
      break;
    }
    case flwor_clause::where_clause:
    {
      where_clause* vwc = static_cast<where_clause*>(vc);
      getWherePreds(vi, vwc, vpreds);

      break;
    }
    default:
    {
      assert(false);
      return false;
    }
    }
  }

  // Collect the rest of the query preds, if any
  for (csize qi = nextQueryClause; qi < numQClauses; ++qi)
  {
    flwor_clause* qc = theQueryExpr->get_clause(qi);

    if (qc->get_kind() != flwor_clause::where_clause)
      continue;

    getWherePreds(qi, static_cast<where_clause*>(qc), unmatchedQPreds);
  }

  // Find a match for each index predicate
  std::vector<PredInfo>::iterator vpredIte = vpreds.begin();
  std::vector<PredInfo>::iterator vpredEnd = vpreds.end();

  for (; vpredIte != vpredEnd; ++vpredIte)
  {
    expr* vpredExpr = vpredIte->theExpr;
    bool matched = false;

    std::vector<PredInfo>::iterator qpredIte = unmatchedQPreds.begin();
    std::vector<PredInfo>::iterator qpredEnd = unmatchedQPreds.end();

    for (; qpredIte != qpredEnd; ++qpredIte)
    {
      PredInfo& qpred = *qpredIte;
      expr* qpredExpr = qpred.theExpr;

      if (expr_tools::match_exact(qpredExpr, vpredExpr, subst))
      {
        matched = true;
        matchedQPreds.push_back(qpred);
        unmatchedQPreds.erase(qpredIte);

        break;
      }
    }

    if (!matched)
      return false;
  }

  // Create the vector to store the args of the probe function
  std::vector<expr*> probeArgs;
  probeArgs.reserve(theKeyClauses.size() + 1);

  // Create the index-name expr and make it the 1st arg of the probe function
  store::Item_t indexName = theIndexDecl->getName();

  expr* qnameExpr = ccb->theEM->
  create_const_expr(sctx, udf, probeFORclause->get_loc(), indexName);

  probeArgs.push_back(qnameExpr);

  // Match the key exprs
  std::vector<let_clause*>::const_iterator keyIte = theKeyClauses.begin();
  std::vector<let_clause*>::const_iterator keyEnd = theKeyClauses.end();

  for (; keyIte != keyEnd; ++keyIte)
  {
    int matched = -1;
    expr* keyExpr = (*keyIte)->get_expr();

    std::vector<PredInfo>::iterator qpredIte = unmatchedQPreds.begin();
    std::vector<PredInfo>::iterator qpredEnd = unmatchedQPreds.end();

    for (; qpredIte != qpredEnd; ++qpredIte)
    {
      PredInfo& qpred = *qpredIte;

      if (qpred.theExpr->get_expr_kind() != fo_expr_kind)
        continue;

      fo_expr* qpredExpr = static_cast<fo_expr*>(qpred.theExpr);
      function* qpredFunc = qpredExpr->get_func();

      if (qpredFunc->getKind() == FunctionConsts::FN_BOOLEAN_1)
      {
        if (qpredExpr->get_arg(0)->get_expr_kind() != fo_expr_kind)
          continue;

        qpredExpr = static_cast<fo_expr*>(qpredExpr->get_arg(0));
        qpredFunc = qpredExpr->get_func();
      }

      if (qpredFunc->comparisonKind() != CompareConsts::VALUE_EQUAL)
        continue;

      if (matchKeyExpr(qpredExpr->get_arg(0), keyExpr, subst))
        matched = 0;
      else if (matchKeyExpr(qpredExpr->get_arg(1), keyExpr, subst))
        matched = 1;

      if (matched >= 0)
      {
        matchedQPreds.push_back(qpred);
        unmatchedQPreds.erase(qpredIte);
        probeArgs.push_back(qpredExpr->get_arg(1 - matched));
        break;
      }
    }

    if (matched < 0)
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
 
  for (csize i = 0; i < unmatchedQPreds.size(); ++i)
  {
    expr* pred = unmatchedQPreds[i].theExpr;
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
    case flwor_clause::let_clause:
    {
      forlet_clause* flc = static_cast<forlet_clause*>(c);
      var_expr* var = flc->get_var();
      var_expr* posVar = flc->get_pos_var();

      if (!var->isVisited(1) && (posVar == NULL || !posVar->isVisited(1)))
        continue;

      if (!checkFreeVars(flc->get_expr(), domVar, matchedClauses))
        return false;

      break;
    }
    case flwor_clause::window_clause:
    {
      window_clause* wc = static_cast<window_clause*>(c);
      var_expr* var = wc->get_var();
      flwor_wincond* startCond = wc->get_win_start();
      flwor_wincond* stopCond = wc->get_win_stop();

      bool used = var->isVisited(1);

      if (! used && startCond)
      {
        const flwor_wincond_vars& vars = startCond->get_out_vars();

        if ((vars.posvar && vars.posvar->isVisited(1)) ||
            (vars.curr && vars.curr->isVisited(1)) ||
            (vars.prev && vars.prev->isVisited(1)) ||
            (vars.next && vars.next->isVisited(1)))
          used = true;
      }

      if (! used && stopCond)
      {
        const flwor_wincond_vars& vars = stopCond->get_out_vars();

        if ((vars.posvar && vars.posvar->isVisited(1)) ||
            (vars.curr && vars.curr->isVisited(1)) ||
            (vars.prev && vars.prev->isVisited(1)) ||
            (vars.next && vars.next->isVisited(1)))
          used = true;
      }

      if (used)
      {
        if (!checkFreeVars(wc->get_expr(), domVar, matchedClauses))
          return false;

        if (startCond &&
            !checkFreeVars(startCond->get_expr(), domVar, matchedClauses))
          return false;

        if (stopCond &&
            !checkFreeVars(stopCond->get_expr(), domVar, matchedClauses))
          return false;
      }

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
  for (csize i = 0; i < matchedQPreds.size(); ++i)
  {
    PredInfo& pred = matchedQPreds[i];

    if (pred.theAndExpr != NULL)
    {
      fo_expr* andExpr = pred.theAndExpr;
      csize numRemoved = 0;

      while (matchedQPreds[i].theAndExpr == andExpr)
      {
        matchedQPreds[i].theAndExpr->remove_arg(pred.theArgPos - numRemoved);
        ++i;
      }

      --i;

      if (andExpr->num_args() == 1)
      {
        pred.theClause->set_expr(pred.theAndExpr->get_arg(0));
      }
      else if (andExpr->num_args() == 0)
      {
        matchedClauses.set(pred.theClausePos, true);
      }
    }
    else
    {
      matchedClauses.set(pred.theClausePos, true);
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
void IndexMatchingRule::getWherePreds(
    csize clausePos,
    where_clause* wc,
    std::vector<PredInfo>& preds)
{
  expr* whereExpr = wc->get_expr();

  if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_N)
  {
    fo_expr* andExpr = static_cast<fo_expr*>(whereExpr);
    csize numArgs = andExpr->num_args();

    for (csize i = 0; i < numArgs; ++i)
    {
      preds.push_back(PredInfo(wc, clausePos, andExpr, i));
    }
  }
  else
  {
    preds.push_back(PredInfo(wc, clausePos, NULL, 0));
  }
}


/*******************************************************************************

********************************************************************************/
bool IndexMatchingRule::matchKeyExpr(
    expr* qexpr,
    expr* vexpr,
    expr::substitution_t& subst)
{
  if (qexpr->get_expr_kind() == promote_expr_kind &&
      vexpr->get_expr_kind() == promote_expr_kind)
  {
    promote_expr* qe = static_cast<promote_expr*>(qexpr);
    promote_expr* ve = static_cast<promote_expr*>(vexpr);
    xqtref_t qtype = qe->get_return_type();
    xqtref_t vtype = ve->get_target_type();

    TypeManager* tm = qe->get_type_manager();
    RootTypeManager& rtm = GENV_TYPESYSTEM;

    if (TypeOps::is_subtype(tm, *qtype, *vtype) ||
        (TypeOps::is_subtype(tm, *qtype, *rtm.UNTYPED_ATOMIC_TYPE_STAR) &&
         TypeOps::is_subtype(tm, *vtype, *rtm.STRING_TYPE_STAR)))
    {
      return expr_tools::match_exact(qe->get_input(), ve->get_input(), subst);
    }

    return false;
  }
  else if (vexpr->get_expr_kind() == promote_expr_kind &&
           qexpr->get_expr_kind() != promote_expr_kind)
  {
    promote_expr* ve = static_cast<promote_expr*>(vexpr);
    xqtref_t qtype = qexpr->get_return_type();
    xqtref_t vtype = ve->get_target_type();

    TypeManager* tm = qexpr->get_type_manager();
    RootTypeManager& rtm = GENV_TYPESYSTEM;

    if (TypeOps::is_subtype(tm, *qtype, *vtype) ||
        (TypeOps::is_subtype(tm, *qtype, *rtm.UNTYPED_ATOMIC_TYPE_STAR) &&
         TypeOps::is_subtype(tm, *vtype, *rtm.STRING_TYPE_STAR)))
    {
      return expr_tools::match_exact(qexpr, ve->get_input(), subst);
    }

    return false;
  }
  else if (vexpr->get_expr_kind() == treat_expr_kind &&
           qexpr->get_expr_kind() != treat_expr_kind)
  {
    treat_expr* ve = static_cast<treat_expr*>(vexpr);

    return expr_tools::match_exact(qexpr, ve->get_input(), subst);
  }

  return expr_tools::match_exact(qexpr, vexpr, subst);
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
