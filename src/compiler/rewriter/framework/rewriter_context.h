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
#ifndef ZORBA_REWRITER_CONTEXT_H
#define ZORBA_REWRITER_CONTEXT_H

#include <map>
#include <vector>

#include "common/shared_types.h"

#include "util/dynamic_bitset.h"

#include "compiler/expression/var_expr.h"

namespace zorba 
{

class user_function;

typedef std::map<var_expr *, ulong> VarIdMap;
typedef std::vector<var_expr*> IdVarMap;
typedef std::map<const expr *, DynamicBitset> ExprVarsMap;


/*******************************************************************************

  theRoot:
  --------
  The root node of the expr DAG that is going to be optimized using this context.

  theVarIdMap:
  ------------
  Maps a var_expr to its unique "prefix" id. The "prefix" id has the following
  property: for 2 vars v1 and v2, v1 is defined before v2 if and only if 
  prefix-id(v1) < prefix-id(v2). See index_flwor_vars() function in
  tools/expr_tools.cpp for more details.

  theIdVarMap:
  ------------
  This is the reverse mapping of theVarIdMap.

  theExprVarsMap:
  ---------------
  An entry into this map maps an expr to the variables that are referenced by
  that expr and/or its sub-exprs. (Note: given that the domain expr of a var
  $x is not considered a sub-expr of $x, if $x is referenced by an expr E and
  the domain expr of $x references another var $y, $y is NOT considered to be
  referenced by E). Only variables that have been assigned a prolog id (i.e.,
  the ones that appear in theVarIdMap) are considered. The set of vars referenced
  by an expr is implemented by a bitset that is indexed by prolog var ids and
  whose size (in number of bits) is equal to the size of theVarIdMap.

  theFlworStack:
  --------------
  The current "in-scope" flwor exprs, ie., flwor exprs that the rule has 
  entered but not exited yet.
********************************************************************************/
class RewriterContext 
{
public:
  CompilerCB                 * theCCB;

  expr_t                       theRoot;

  user_function              * theUDF;

  zstring                      theMessage;

  int                          m_tempvarCounter;

  bool                         theIsInOrderedMode;

  VarIdMap                   * theVarIdMap;
  IdVarMap                   * theIdVarMap;
  ExprVarsMap                * theExprVarsMap;
  std::vector<expr_t>          theFlworStack;
  std::vector<bool>            theInReturnClause;

public:
  RewriterContext(
      CompilerCB* cb,
      const expr_t& root,
      user_function* udf,
      const zstring& msg,
      bool orderedMode);

  ~RewriterContext();

  CompilerCB* getCompilerCB() const { return theCCB; }

  expr_t getRoot();

  void setRoot(expr_t root);

  rchandle<var_expr> createTempVar(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr::var_kind kind);
};


/*******************************************************************************

********************************************************************************/
struct UDFCallChain
{
  fo_expr      * theFo;
  UDFCallChain * thePrev;

  UDFCallChain() : theFo(NULL), thePrev(NULL) {}

  UDFCallChain(fo_expr* caller, UDFCallChain* prevCaller)
    :
    theFo(caller),
    thePrev(prevCaller) 
  {
  }
};


}

#endif /* ZORBA_REWRITER_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
