

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
#include "compiler/xqddf/collection_decl.h"

#include "compiler/rewriter/rules/index_matching_rule.h"
#include "compiler/rewriter/rules/fold_rules.h"
#include "compiler/rewriter/tools/expr_tools.h"

#include "compiler/api/compilercb.h"

#include "functions/function.h"
#include "functions/library.h"

#include "types/typeops.h"

#include "util/dynamic_bitset.h"

#include "diagnostics/assert.h"

#include <zorba/properties.h>


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
  theKeyClauses(NULL),
  theParentNode(NULL)
{
}


/*******************************************************************************

********************************************************************************/
expr* IndexMatchingRule::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  expr* result = node;
  modified = false;

  // TODO remove this
  if (theIndexDecl->isGeneral())
    return node;

  if (node->get_expr_kind() == flwor_expr_kind)
  {
    if (theViewExpr == NULL)
      theViewExpr = theIndexDecl->getViewExpr(theKeyClauses);

    theQueryExpr = static_cast<flwor_expr*>(node);

    bool matched = matchIndex();

    if (matched)
    {
      modified = true;

      flwor_expr* flwor = static_cast<flwor_expr*>(node);

      if (flwor->get_return_expr()->get_expr_kind() == const_expr_kind &&
          theParentNode != NULL &&
          theParentNode->get_expr_kind() == fo_expr_kind)
      {
        fo_expr* pnode = static_cast<fo_expr*>(theParentNode);

        if (pnode->get_func() == BUILTIN_FUNC(FN_COUNT_1) ||
            pnode->get_func() == BUILTIN_FUNC(FN_EMPTY_1) ||
            pnode->get_func() == BUILTIN_FUNC(FN_EXISTS_1))
        {
          csize pos;
          if (flwor->is_single_for(pos))
          {
            for_clause* fc = static_cast<for_clause*>(flwor->get_clause(pos));
          
            result = fc->get_expr();
          }
        }
      }
    }
  }

  ExprIterator iter(node);
  while (!iter.done())
  {
    expr* currChild = **iter;

    bool childModified = false;

    theParentNode = node;

    expr* newChild = apply(rCtx, currChild, childModified);

    if (currChild != newChild)
      **iter = newChild;

    if (childModified)
      modified = true;

    iter.next();
  }

  return result;
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

  theUnmatchedQPreds.clear();
  theMatchedQPreds.clear();
  theProbeArgs.clear();
  theProbeArgs.reserve(theKeyClauses->size() + 1);

  expr::substitution_t subst;

  for_clause* firstMatchedFOR = NULL;
  csize firstMatchedFORpos = 0;
  csize lastMatchedFORpos = 0;
  csize lastMatchedWHEREpos = 0;
  csize firstOrderByPos = 0;
  DynamicBitset matchedClauses(numQClauses);
  matchedClauses.reset();

  std::vector<PredInfo> vpreds;

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

          if (!qfc->is_allowing_empty() &&
              expr_tools::match_exact(qdomExpr, vdomExpr, subst))
          {
            nextQueryClause = qi+1;
            subst[vvarExpr] = qvarExpr;
            matchedClauses.set(qi, true);

            if (firstMatchedFOR == NULL)
            {
              firstMatchedFOR = qfc;
              firstMatchedFORpos = qi;
            }

            lastMatchedFORpos = qi;
            matched = true;
            break;
          }
          else if (firstMatchedFOR != NULL)
          {
            // TODO allow for FOR clause reordering, if conditions allow it
            return false;
          }

          break;
        }
        case flwor_clause::let_clause:
        {
          if (firstMatchedFOR != NULL)
          {
            let_clause* qlc = static_cast<let_clause*>(qc);
            expr* qdomExpr = qlc->get_expr();

            if (qdomExpr->is_sequential())
              return false;
          }
          break;
        }
        case flwor_clause::window_clause:
        case flwor_clause::orderby_clause:
        {
          if (firstMatchedFOR != NULL)
          {
            // TODO allow for FOR clause reordering, if conditions allow it
            return false; // todo
          }

          break;
        }
        case flwor_clause::where_clause:
        {
          getWherePreds(qi, static_cast<where_clause*>(qc), theUnmatchedQPreds);
          break;
        }
        case flwor_clause::count_clause:
        case flwor_clause::groupby_clause:
        case flwor_clause::materialize_clause:
        {
          if (firstMatchedFOR != NULL)
            return false;

          break;
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

  // Collect the rest of the query preds, if any, as well as the first orderby
  for (csize qi = nextQueryClause; qi < numQClauses; ++qi)
  {
    flwor_clause* qc = theQueryExpr->get_clause(qi);

    switch (qc->get_kind())
    {
    case flwor_clause::where_clause:
    {
      getWherePreds(qi, static_cast<where_clause*>(qc), theUnmatchedQPreds);
      break;
    }
    case flwor_clause::orderby_clause:
    {
      if (firstOrderByPos == 0)
        firstOrderByPos = qi;
      
      break;
    }
    default:
      break;
    }
  }

  // Find a match for each index predicate
  std::vector<PredInfo>::iterator vpredIte = vpreds.begin();
  std::vector<PredInfo>::iterator vpredEnd = vpreds.end();

  for (; vpredIte != vpredEnd; ++vpredIte)
  {
    expr* vpredExpr = vpredIte->theExpr;
    bool matched = false;

    std::vector<PredInfo>::iterator qpredIte = theUnmatchedQPreds.begin();
    std::vector<PredInfo>::iterator qpredEnd = theUnmatchedQPreds.end();

    for (; qpredIte != qpredEnd; ++qpredIte)
    {
      PredInfo& qpred = *qpredIte;
      expr* qpredExpr = qpred.theExpr;

      if (expr_tools::match_exact(qpredExpr, vpredExpr, subst))
      {
        matched = true;
        theMatchedQPreds.push_back(qpred);
        theUnmatchedQPreds.erase(qpredIte);

        if (qpred.theClausePos > lastMatchedWHEREpos)
          lastMatchedWHEREpos = qpred.theClausePos;

        break;
      }
    }

    if (!matched)
      return false;
  }

  // Create the index-name expr and make it the 1st arg of the probe function
  store::Item_t indexName = theIndexDecl->getName();

  expr* qnameExpr = ccb->theEM->
  create_const_expr(sctx, udf, firstMatchedFOR->get_loc(), indexName);

  theProbeArgs.push_back(qnameExpr);

  // Match the key exprs
  if (theIndexDecl->isOrdered())
  {
    if (!matchKeyExprsForRangeIndex(subst, lastMatchedWHEREpos) &&
        vpreds.empty())
      return false;
  }
  else
  {
    if (!matchKeyExprsForEqIndex(subst, lastMatchedWHEREpos))
      return false;
  }

  // Make sure thare are no "ilegal" query clauses between the last matched FOR
  // clause and the last WHERE clause containing a matched pred.
  for (csize i = lastMatchedFORpos + 1; i < lastMatchedWHEREpos; ++i)
  {
    flwor_clause* qc = theQueryExpr->get_clause(i);

    switch (qc->get_kind())
    {
    case flwor_clause::for_clause:
    case flwor_clause::let_clause:
    case flwor_clause::window_clause:
    {
      forletwin_clause* qflwc = static_cast<forletwin_clause*>(qc);
      expr* qdomExpr = qflwc->get_expr();

      if (qdomExpr->is_sequential())
        return false;
      
      break;
    }
    case flwor_clause::count_clause:
    case flwor_clause::groupby_clause:
    case flwor_clause::materialize_clause:
    {
      return false;
    }
    case flwor_clause::where_clause:
    case flwor_clause::orderby_clause:
    {
      break;
    }
    default:
      ZORBA_ASSERT(false);
    }
  }

  // Match orderby exprs, if any, with the index key exprs
  if (theIndexDecl->isOrdered() && firstOrderByPos != 0)
  {
    orderby_clause* ob = 
    static_cast<orderby_clause*>(theQueryExpr->get_clause(firstOrderByPos));
    
    csize numKeys = theKeyClauses->size();
    csize numSortKeys = ob->num_columns();

    if (numSortKeys <= numKeys)
    {
      csize i;
      for (i = 0; i < numSortKeys; ++i)
      {
        if (!ob->is_ascending(i) ||
            ob->get_collation(i) != theIndexDecl->getCollation(i))
          break;

        if (!matchKeyExpr(ob->get_column_expr(i),
                          (*theKeyClauses)[i]->get_expr(),
                          subst))
          break;
      }

      if (i == numSortKeys)
        matchedClauses.set(firstOrderByPos, true);
    }
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
 
  for (csize i = 0; i < theUnmatchedQPreds.size(); ++i)
  {
    expr* pred = theUnmatchedQPreds[i].theExpr;
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
      {
        if (c->get_kind() == flwor_clause::let_clause)
          matchedClauses.set(i, true);

        continue;
      }

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
    case flwor_clause::orderby_clause:
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
  for (csize i = 0; i < theMatchedQPreds.size(); ++i)
  {
    PredInfo& pred = theMatchedQPreds[i];

    if (pred.theAndExpr != NULL)
    {
      fo_expr* andExpr = pred.theAndExpr;

      pred.theAndExpr->remove_arg(pred.theArgPos);

      csize j = i+1;
      while (j < theMatchedQPreds.size() &&
             theMatchedQPreds[j].theAndExpr == andExpr)
      {
        if (theMatchedQPreds[j].theArgPos > pred.theArgPos)
          --theMatchedQPreds[j].theArgPos;

        ++j;
      }

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

  fo_expr* probeExpr;

  if (theIndexDecl->isOrdered())
  {
    probeExpr = ccb->theEM->
    create_fo_expr(sctx,
                   udf,
                   firstMatchedFOR->get_loc(),
                   BUILTIN_FUNC(FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N),
                   theProbeArgs);
  }
  else
  {
    probeExpr = ccb->theEM->
    create_fo_expr(sctx,
                   udf,
                   firstMatchedFOR->get_loc(),
                   BUILTIN_FUNC(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N),
                   theProbeArgs);
  }

  if (! (theQueryExpr->ignoresSortedNodes() ||
         firstOrderByPos != 0 ||
         (theIndexDecl->numSources() == 1 &&
          !sctx->lookup_collection(theIndexDecl->getSourceName(0))->isOrdered())))
  {
    probeExpr =  ccb->theEM->
    create_fo_expr(sctx,
                   udf,
                   firstMatchedFOR->get_loc(),
                   BUILTIN_FUNC(OP_SORT_NODES_ASC_1),
                   probeExpr);
  }

  firstMatchedFOR->set_expr(probeExpr);

  csize numRemoved = 0;
  for (csize i = firstMatchedFORpos + 1; i < matchedClauses.size(); ++i)
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
bool IndexMatchingRule::matchKeyExprsForRangeIndex(
    expr::substitution_t& subst,
    csize& lastMatchedWHEREpos)
{
  CompilerCB* ccb = theQueryExpr->get_ccb();
  static_context* sctx = theQueryExpr->get_sctx();
  user_function* udf = theQueryExpr->get_udf();

  expr* trueExpr = ccb->theEM->create_const_expr(sctx, udf, QueryLoc::null, true);
  expr* falseExpr = ccb->theEM->create_const_expr(sctx, udf, QueryLoc::null, false);

  bool matchedFirstKey = false;

  std::vector<let_clause*>::const_iterator keyIte = theKeyClauses->begin();
  std::vector<let_clause*>::const_iterator keyEnd = theKeyClauses->end();

  for (; keyIte != keyEnd; ++keyIte)
  {
    expr* bounds[2] = { NULL };
    bool boundsIncluded[2] = { false };
    expr* keyExpr = (*keyIte)->get_expr();

    std::vector<PredInfo>::iterator qpredIte = theUnmatchedQPreds.begin();
    
    for (; qpredIte != theUnmatchedQPreds.end(); ++qpredIte)
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

      CompareConsts::CompareType compKind = qpredFunc->comparisonKind();

      if (compKind == CompareConsts::VALUE_EQUAL ||
          compKind == CompareConsts::VALUE_LESS ||
          compKind == CompareConsts::VALUE_LESS_EQUAL ||
          compKind == CompareConsts::VALUE_GREATER ||
          compKind == CompareConsts::VALUE_GREATER_EQUAL)
      {
        int matched = -1;

        if (matchKeyExpr(qpredExpr->get_arg(0), keyExpr, subst))
          matched = 0;
        else if (matchKeyExpr(qpredExpr->get_arg(1), keyExpr, subst))
          matched = 1;

        if (matched < 0)
          continue;
        
        if (compKind == CompareConsts::VALUE_EQUAL)
        {
          bounds[0] = bounds[1] = qpredExpr->get_arg(1 - matched);
          boundsIncluded[0] = boundsIncluded[1] = true;
          matched = 2;
        }
        else if (compKind == CompareConsts::VALUE_LESS)
        {
          if (bounds[1-matched] == NULL)
          {
            bounds[1-matched] = qpredExpr->get_arg(1 - matched);
            boundsIncluded[1-matched] = false;
            matched = 2;
          }
        }
        else if (compKind == CompareConsts::VALUE_LESS_EQUAL)
        {
          if (bounds[1-matched] == NULL)
          {
            bounds[1-matched] = qpredExpr->get_arg(1 - matched);
            boundsIncluded[1-matched] = true;
            matched = 2;
          }
        }
        else if (compKind == CompareConsts::VALUE_GREATER)
        {
          if (bounds[matched] == NULL)
          {
            bounds[matched] = qpredExpr->get_arg(1 - matched);
            boundsIncluded[matched] = false;
            matched = 2;
          }
        }
        else if (compKind == CompareConsts::VALUE_GREATER_EQUAL)
        {
          if (bounds[matched] == NULL)
          {
            bounds[matched] = qpredExpr->get_arg(1 - matched);
            boundsIncluded[matched] = true;
            matched = 2;
          }
        }
        
        if (matched == 2)
        {
          theMatchedQPreds.push_back(qpred);
          qpredIte = theUnmatchedQPreds.erase(qpredIte);
		  
		  if (!theUnmatchedQPreds.empty() && qpredIte != theUnmatchedQPreds.begin())
            --qpredIte;

          if (qpred.theClausePos > lastMatchedWHEREpos)
            lastMatchedWHEREpos = qpred.theClausePos;
        }
        
        if ((bounds[0] != NULL && bounds[1] != NULL) || theUnmatchedQPreds.empty())
          break;
      }
    } // for each query pred

    // $lowerBound
    if (bounds[0] != NULL)
      theProbeArgs.push_back(bounds[0]);
    else
      theProbeArgs.push_back(ccb->theEM->create_seq(sctx, udf, QueryLoc::null));

    // $upperBound
    if (bounds[1] != NULL)
      theProbeArgs.push_back(bounds[1]);
    else
      theProbeArgs.push_back(ccb->theEM->create_seq(sctx, udf, QueryLoc::null));

    // $haveLowerBound
    if (bounds[0] != NULL)
      theProbeArgs.push_back(trueExpr);  
    else
      theProbeArgs.push_back(falseExpr);

    // $haveUpperBound
    if (bounds[1] != NULL)
      theProbeArgs.push_back(trueExpr);  
    else
      theProbeArgs.push_back(falseExpr);

    // $lowerBoundIncluded
    if (boundsIncluded[0])
      theProbeArgs.push_back(trueExpr);
    else
      theProbeArgs.push_back(falseExpr);
    
    // $upperBoundIncluded
    if (boundsIncluded[1])
      theProbeArgs.push_back(trueExpr);
    else
      theProbeArgs.push_back(falseExpr);

    if (keyIte == theKeyClauses->begin() &&
        (bounds[0] != NULL || bounds[1] != NULL))
      matchedFirstKey = true;
  }

  if (!matchedFirstKey)
  {
    return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool IndexMatchingRule::matchKeyExprsForEqIndex(
    expr::substitution_t& subst,
    csize& lastMatchedWHEREpos)
{
  std::vector<let_clause*>::const_iterator keyIte = theKeyClauses->begin();
  std::vector<let_clause*>::const_iterator keyEnd = theKeyClauses->end();

  for (; keyIte != keyEnd; ++keyIte)
  {
    int matched = -1;
    expr* keyExpr = (*keyIte)->get_expr();

    std::vector<PredInfo>::iterator qpredIte = theUnmatchedQPreds.begin();
    std::vector<PredInfo>::iterator qpredEnd = theUnmatchedQPreds.end();

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

      CompareConsts::CompareType compKind = qpredFunc->comparisonKind();

      if (compKind != CompareConsts::VALUE_EQUAL)
        continue;

      if (matchKeyExpr(qpredExpr->get_arg(0), keyExpr, subst))
        matched = 0;
      else if (matchKeyExpr(qpredExpr->get_arg(1), keyExpr, subst))
        matched = 1;

      if (matched >= 0)
      {
        theMatchedQPreds.push_back(qpred);
        theUnmatchedQPreds.erase(qpredIte);

        if (qpred.theClausePos > lastMatchedWHEREpos)
          lastMatchedWHEREpos = qpred.theClausePos;

        theProbeArgs.push_back(qpredExpr->get_arg(1 - matched));

        // do not try to match another query pred with the current index key.
        break;
      }
    }

    if (matched < 0)
      return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool IndexMatchingRule::matchKeyExpr(
    expr* qexpr,
    expr* vexpr,
    expr::substitution_t& subst)
{
  TypeManager* tm = qexpr->get_type_manager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  if (qexpr->get_expr_kind() == promote_expr_kind &&
      vexpr->get_expr_kind() == promote_expr_kind)
  {
    promote_expr* qe = static_cast<promote_expr*>(qexpr);
    promote_expr* ve = static_cast<promote_expr*>(vexpr);
    xqtref_t qtype = qe->get_return_type();
    xqtref_t vtype = ve->get_target_type();

    if (TypeOps::is_subtype(tm, *vtype, *qtype) ||
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

    if (TypeOps::is_subtype(tm, *vtype, *qtype) ||
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

    if (qexpr->get_expr_kind() == promote_expr_kind)
    {
      promote_expr* qe = static_cast<promote_expr*>(qexpr);
      xqtref_t qtype = qe->get_return_type();
      xqtref_t vtype = ve->get_target_type();

      if (TypeOps::is_subtype(tm, *vtype, *qtype))
      {
        return expr_tools::match_exact(qe->get_input(), ve->get_input(), subst);
      }
    }

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

    if (freeVar->get_flwor_clause() != NULL &&
        freeVar->get_flwor_clause()->get_flwor_expr() == theQueryExpr)
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
