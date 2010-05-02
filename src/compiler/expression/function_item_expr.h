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
#ifndef ZORBA_COMPILER_FUNCTION_ITEM_EXPR_H
#define ZORBA_COMPILER_FUNCTION_ITEM_EXPR_H

#include <vector>

#include "compiler/expression/expr_base.h"

#include "store/naive/shared_types.h"

namespace zorba {

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

public:
  SERIALIZABLE_CLASS(dynamic_function_invocation_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(dynamic_function_invocation_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar)
  { 
    serialize_baseclass(ar, (expr*)this);
    ar & theExpr;
    ar & theArgs;   
  }
  
protected:
  expr_t                 theExpr;
  checked_vector<expr_t> theArgs;
    
public:
  dynamic_function_invocation_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& anExpr,
      const std::vector<expr_t>& args);
    
	const expr_t get_function() const { return theExpr; }
	
  const std::vector<expr_t>& get_args() const { return theArgs; }
	
	void compute_scripting_kind();

	void accept(expr_visitor&);

	std::ostream& put(std::ostream& os) const;
};



/*******************************************************************************
  Represents a LiteralFunctionItem expr or an InlineFunction expr.

  theQName           : NULL in case of inline function. Otherwise, the qname of
                       the named function in the LiteralFunctionItem.
  theFunction        : In case of inline function expr, this is a pointer to an 
                       anonymous user_function obj that is created on-the-fly by
                       the translator to represent the body and signature of the 
                       inline function. In case of LiteralFunctionItem, it may 
                       be either a function or a user_function obj, depending on
                       the kind of the named function.
  theArity           : We need to store the arity also here because the function
                       above doesn't know about its arity in case it's a variadic
                       function.
  theScopedVariables : Empty in the case of LiteralFunctionItem. Otherwise, the
                       flwor vars that are in scope at the place where the
                       InlineFunction expr appears at.
********************************************************************************/
class function_item_expr: public expr
{
  friend class ExprIterator;
  friend class expr;

private:
  store::Item_t        theQName;
	function           * theFunction;
  uint32_t             theArity;
  std::vector<expr_t>  theScopedVariables;

public:
  SERIALIZABLE_CLASS(function_item_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(function_item_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	function_item_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const store::Item* aQName,
      function* f,
      uint32_t aArity);

  function_item_expr(
      static_context* sctx,
      const QueryLoc& loc);

  ~function_item_expr();
	
  void add_variable(expr* var);

  void set_function(function* udf);

	const function* get_function() const { return theFunction; }
	
  const store::Item_t& get_qname() const { return theQName; }

  uint32_t get_arity() const { return theArity; }
  
  const std::vector<expr_t>& get_vars() const { return theScopedVariables; }

	void compute_scripting_kind();
	
	void accept(expr_visitor&);

	std::ostream& put(std::ostream& os) const;
};

} //end of namespace

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
