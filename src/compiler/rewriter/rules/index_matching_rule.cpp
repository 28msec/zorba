

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

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"

#include "compiler/api/compilercb.h"

#include "functions/function.h"
#include "functions/library.h"


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

    expr* e = matchIndex(rCtx, modified);

    if (modified)
      return e;
  }

  ExprIterator iter(node);
  while (!iter.done())
  {
    expr* currChild = **iter;

    expr* newChild = apply(rCtx, currChild, modified);

    if (currChild != newChild)
    {
      assert(modified);
      **iter = newChild;
    }

    if (modified)
      break;

    iter.next();
  }

  return node;
}


/*******************************************************************************
  Match a flwor expr with an index
********************************************************************************/
expr* IndexMatchingRule::matchIndex(RewriterContext& rCtx, bool& modified)
{
  modified = false;

  CompilerCB* ccb = theQueryExpr->get_ccb();
  static_context* sctx = theQueryExpr->get_sctx();
  user_function* udf = theQueryExpr->get_udf();

  csize numVClauses = theViewExpr->num_clauses();
  csize numQClauses = theQueryExpr->num_clauses();
  csize nextQueryClause = 0;

  expr::substitution_t subst;

  std::vector<for_clause*> matchedFORs;
  std::vector<csize> matchedFORPositions;

  // match for clauses
  for (csize i = 0; i < numVClauses; ++i)
  {
    flwor_clause* vc = theViewExpr->get_clause(i);

    switch (vc->get_kind())
    {
    case flwor_clause::for_clause:
    {
      for_clause* vfc = static_cast<for_clause*>(vc);
      expr* vdomExpr = vfc->get_expr();
      var_expr* vvarExpr = vfc->get_var();

      csize j = nextQueryClause;

      for (; j < numQClauses; ++j)
      {
        flwor_clause* qc = theQueryExpr->get_clause(j);

        if (qc->get_kind() != flwor_clause::for_clause)
          continue;

        for_clause* qfc = static_cast<for_clause*>(qc);
        expr* qdomExpr = qfc->get_expr();
        var_expr* qvarExpr = qfc->get_var();

        if (expr_tools::match_exact(qdomExpr, vdomExpr, subst))
        {
          nextQueryClause = j+1;

          subst[vvarExpr] = qvarExpr;
          matchedFORPositions.push_back(j);
          matchedFORs.push_back(qfc);
          break;
        }
      }

      if (j == numQClauses)
        return theQueryExpr;
    }
    case flwor_clause::let_clause:
    {
      break;
    }
    default:
    {
      assert(false);
      return theQueryExpr;
    }
    }
  }

  std::vector<expr*> probeArgs;
  probeArgs.reserve(theKeyExprs.size() + 1);

  // create the index-name expr
  store::Item_t indexName = theIndexDecl->getName();

  expr* qnameExpr = ccb->theEM->
  create_const_expr(sctx, udf, matchedFORs[0]->get_loc(), indexName);

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
      return theQueryExpr;
  }

  // check for rejoins

  // Do the rewrite
  fo_expr* probeExpr = ccb->theEM->
  create_fo_expr(sctx,
                 udf,
                 matchedFORs[0]->get_loc(),
                 BUILTIN_FUNC(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N),
                 probeArgs);

  matchedFORs[0]->set_expr(probeExpr);

  csize numRemoved = 0;
  for (csize i = 1; i < matchedFORs.size(); ++i)
  {
    theQueryExpr->remove_clause(matchedFORPositions[i] - numRemoved);
    ++numRemoved;
  }

  for (csize i = 0; i < matchedPreds.size(); ++i)
  {
    expr* trueExpr = ccb->theEM->
    create_const_expr(sctx, udf, (*matchedPreds[i])->get_loc(), xs_boolean(true));

    *matchedPreds[i] = trueExpr;
  }

  modified = true;
  return theQueryExpr;
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


}

/* vim:set et sw=2 ts=2: */
