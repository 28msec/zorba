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
#pragma once
#ifndef ZORBA_COMPILER_REWRITER_INDEX_MATCHING_H
#define ZORBA_COMPILER_REWRITER_INDEX_MATCHING_H


#include "compiler/rewriter/rules/rule_base.h"


namespace zorba
{

class IndexDecl;
class flwor_expr;
class DynamicBitset;
class fo_expr;
class where_clause;


/*******************************************************************************

********************************************************************************/
class IndexMatchingRule : public RewriteRule
{
  struct PredInfo
  {
    where_clause  * theClause;
    csize           theClausePos;

    fo_expr       * theAndExpr;
    csize           theArgPos;

    expr          * theExpr;

    PredInfo(where_clause* wc, csize wcPos, fo_expr* andExpr, csize argPos);
  };

protected:
  IndexDecl                 * theIndexDecl;
  flwor_expr                * theViewExpr;
  std::vector<let_clause*>  * theKeyClauses;

  flwor_expr                * theQueryExpr;

  std::vector<PredInfo>       theUnmatchedQPreds;
  std::vector<PredInfo>       theMatchedQPreds;
  std::vector<expr*>          theProbeArgs;

  expr                      * theParentNode;

public:
  IndexMatchingRule(IndexDecl* decl);

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);

protected:
  bool matchIndex();

  void getWherePreds(
      csize clausePos,
      where_clause* wc,
      std::vector<PredInfo>& preds);

  bool matchKeyExprsForEqIndex(
      expr::substitution_t& subst,
      csize& lastMatchedWHEREpos);

  bool matchKeyExprsForRangeIndex(
      expr::substitution_t& subst,
      csize& lastMatchedWHEREpos);

  bool matchKeyExpr(expr* qexpr, expr* vexpr, expr::substitution_t& subst);

  bool checkFreeVars(
      const expr* qexpr,
      const var_expr* domVar,
      const DynamicBitset& matchedFORs);
};


}

#endif
/* vim:set et sw=2 ts=2: */
