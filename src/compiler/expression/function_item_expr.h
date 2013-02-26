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
#ifndef ZORBA_COMPILER_FUNCTION_ITEM_EXPR_H
#define ZORBA_COMPILER_FUNCTION_ITEM_EXPR_H

#include <vector>

#include "compiler/expression/expr_base.h"

#include "store/naive/shared_types.h"

#include "runtime/function_item/function_item.h"


namespace zorba {

/*******************************************************************************
  [133]     ArgumentPlaceholder      ::=      "?"
********************************************************************************/
class argument_placeholder_expr : public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  argument_placeholder_expr(CompilerCB* ccb, static_context* sctx, user_function* udf, const QueryLoc& loc)
    :
    expr(ccb, sctx, udf, loc, argument_placeholder_expr_kind)
  {
    compute_scripting_kind();
  }

public:
  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream& os) const;
};


/*******************************************************************************

  [121] FilterExpr ::= PrimaryExpr (Predicate | DynamicFunctionInvocation)*

  [164] DynamicFunctionInvocation ::= "(" (ExprSingle ("," ExprSingle)*)? ")"

  theExpr : The input expr that produces a function item
  theArgs : The arg exprs to pass to the function.
********************************************************************************/
class dynamic_function_invocation_expr : public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  expr                * theExpr;
  std::vector<expr*>    theArgs;
  
  std::vector<expr*>    theDotVars; // context item vars

protected:
  dynamic_function_invocation_expr(CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* anExpr,
      const std::vector<expr*>& args,
      const std::vector<expr*>& dotVars);

public:
  const expr* get_function() const { return theExpr; }

  const std::vector<expr*>& get_args() const { return theArgs; }
  
  const std::vector<expr*>& get_dot_vars() const { return theDotVars; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream& os) const;
};



/*******************************************************************************
  Represents a LiteralFunctionItem expr or an InlineFunction expr.

  LiteralFunctionItem ::= QName "#" IntegerLiteral

  InlineFunction ::= "function" "(" ParamList? ")" ("as" SequenceType)? EnclosedExpr

  theFunction :
  This is always a pointer to a user_function obj. In case of an inline function
  expr, it is an anonymous user_function obj that is created on-the-fly by the
  translator to represent the body and signature of the inline function. In case
  of LiteralFunctionItem where the named function is a UDF, it is the
  user_function obj of that UDF. Finally, in case of LiteralFunctionItem where
  the named function F is not a UDF, it is an anonymous user_function obj UF
  that is created on-the-fly by the translator. The signature of UF is the same
  as that of F, and its body simply invokes F. The reason why UF is built is to
  unify the implemenation of dynamic function invocation.

  theArity :
  We need to store the arity also here because the function above doesn't know
  about its arity in case it's a variadic function.

  theScopedVariables :
  Empty in the case of LiteralFunctionItem. Otherwise, the FLWOR vars that are
  in scope at the place where the InlineFunction expr appears at.
********************************************************************************/
class function_item_expr: public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  DynamicFunctionInfo_t       theDynamicFunctionInfo;
  
protected:
  function_item_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      static_context* closureSctx,
      function* f,
      store::Item* aQName,
      uint32_t aArity,
      bool isInline,
      bool needsContextItem);

  function_item_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      static_context* closureSctx,
      bool isInline,
      bool needsContextItem);
  
  virtual ~function_item_expr();
  
public:
  DynamicFunctionInfo* get_dynamic_fn_info() { return theDynamicFunctionInfo; }

  void add_variable(expr* var, var_expr* substVar, const store::Item_t& name, int isGlobal);

  const std::vector<var_expr*>& get_subst_vars_values() const { return theDynamicFunctionInfo->theSubstVarsValues; }

  const std::vector<store::Item_t>& get_scoped_vars_names() const { return theDynamicFunctionInfo->theScopedVarsNames; }

  const std::vector<int>& get_is_global_var() const { return theDynamicFunctionInfo->theIsGlobalVar; }

  void set_function(user_function* udf);

  function* get_function() const { return theDynamicFunctionInfo->theFunction; }

  const store::Item_t& get_qname() const { return theDynamicFunctionInfo->theQName; }

  uint32_t get_arity() const { return theDynamicFunctionInfo->theArity; }
  
  bool is_inline() const { return theDynamicFunctionInfo->theIsInline; }
  
  bool needs_context_item() const { return theDynamicFunctionInfo->theNeedsContextItem; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream& os) const;
  
public:
  // Given a location, will create an inline function name string such 
  // as "inline function(loc)"
  static store::Item_t create_inline_fname(const QueryLoc& loc);
};

} //end of namespace

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
