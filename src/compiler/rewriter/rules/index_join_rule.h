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
#ifndef ZORBA_COMPILER_REWRITER_INDEX_JOINS_H
#define ZORBA_COMPILER_REWRITER_INDEX_JOINS_H


#include "compiler/rewriter/rules/rule_base.h"
#include "compiler/rewriter/tools/expr_tools.h"

namespace zorba
{

class DynamicBitset;
struct PredicateInfo;


/*******************************************************************************

  theVarDefExprs:
  ---------------
  A stack Keeping track of "in-scope" variable-defining exprs. Var-defining 
  exprs are flwors, trycatch, and block exprs (TOD: include transform exprs).
  "in-scope" means that the rule has entered the expr but not exited it yet.

  theClauses:
  -----------

  theVarIdMap:
  ------------
  Maps a var_expr to its unique "prefix" id.  See tools/expr_tools/h for more
  details.

  theIdVarMap:
  ------------
  This is the reverse mapping of theVarIdMap.

  theExprVarsMap:
  ---------------
  An entry into this map maps an expr to the variables that are referenced by
  that expr and/or its sub-exprs. See tools/expr_tools/h for more details.

********************************************************************************/
class IndexJoinRule : public RewriteRule
{
protected:
  RewriterContext          * theRCtx;

  expr                     * theRootExpr;

  std::vector<expr*>         theVarDefExprs;
  std::vector<csize>         theChildPositions;

  expr_tools::VarIdMap     * theVarIdMap;
  expr_tools::IdVarMap     * theIdVarMap;
  expr_tools::ExprVarsMap  * theExprVarsMap;

public:
  IndexJoinRule(RewriterContext* rctx);

  ~IndexJoinRule();

  void reset();

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);

protected:
  bool isIndexJoinPredicate(PredicateInfo& predInfo);

  var_expr* findLoopVar(expr* predExpr, csize& loopVarId);

  bool checkVarDeps(expr* idxExpr, csize outerVarId, csize& boundVarId);

  bool findIndexPos(PredicateInfo& predInfo, csize boundVarId);

  void rewriteJoin(PredicateInfo& predInfo);

  void expandVars(expr* idxExpr, csize outerVarId, csize innerVarId);
};


}

#endif
/* vim:set et sw=2 ts=2: */
