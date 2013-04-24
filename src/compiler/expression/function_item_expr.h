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

#include "runtime/hof/function_item.h"


namespace zorba {

/*******************************************************************************
  ArgumentPlaceholder ::= "?"
********************************************************************************/
class argument_placeholder_expr : public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  argument_placeholder_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc)
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

  PostfixExpr ::= PrimaryExpr (Predicate | ArgumentList)*

  ArgumentList ::= "(" (Argument ("," Argument)*)? ")"

  Argument ::= ExprSingle

  theExpr:
  --------
  The input expr that produces a function item

  theArgs:
  --------
  The arg exprs to pass to the function.
 
********************************************************************************/
class dynamic_function_invocation_expr : public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  expr                * theExpr;
  std::vector<expr*>    theArgs;

protected:
  dynamic_function_invocation_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* anExpr,
      const std::vector<expr*>& args);

public:
  const expr* get_function() const { return theExpr; }

  const std::vector<expr*>& get_args() const { return theArgs; }
  
  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream& os) const;
};



/*******************************************************************************
  Represents a LiteralFunctionItem expr or an InlineFunction expr.

  LiteralFunctionItem ::= QName "#" IntegerLiteral

  InlineFunction ::= "function" "(" ParamList? ")" ("as" SequenceType)? EnclosedExpr

  theFunctionItemInfo:
  --------------------
  See class definition in src/runtime/hof/function_item.h

********************************************************************************/
class function_item_expr: public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  FunctionItemInfo_t  theFunctionItemInfo;
  
protected:
  function_item_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      function* f,
      csize arity,
      bool isInline,
      bool isCoercion);

  function_item_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      bool isInline,
      bool isCoercion);
  
  virtual ~function_item_expr();
  
public:
  FunctionItemInfo* get_dynamic_fn_info() { return theFunctionItemInfo; }

  void add_variable(expr* var, var_expr* substVar);

  const std::vector<var_expr*>& get_in_scope_vars() const
  {
    return theFunctionItemInfo->theInScopeVars;
  }

  const std::vector<store::Item_t>& get_in_scope_var_names() const
  {
    return theFunctionItemInfo->theInScopeVarNames;
  }

  void set_function(user_function* udf, csize arity);

  function* get_function() const { return theFunctionItemInfo->theFunction; }

  const store::Item_t& get_qname() const { return theFunctionItemInfo->theQName; }

  csize get_arity() const { return theFunctionItemInfo->theArity; }
  
  bool is_inline() const { return theFunctionItemInfo->theIsInline; }
  
  bool is_coercion() const { return theFunctionItemInfo->theIsCoercion; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream& os) const;
  
public:
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
