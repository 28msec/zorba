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
#ifndef ZORBA_FUNCTION_ITEM_EXPR_H
#define ZORBA_FUNCTION_ITEM_EXPR_H

#include <vector>

#include "compiler/expression/expr.h"

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"

#include "zorbaerrors/errors.h"

#include "functions/signature.h"

#include "store/naive/shared_types.h"

namespace zorba {

/**
 *  [121]   	FilterExpr	   ::=   	PrimaryExpr (Predicate | DynamicFunctionInvocation)*
 *  [164]   	DynamicFunctionInvocation	   ::=   	"(" (ExprSingle ("," ExprSingle)*)? ")"
 */
class dynamic_function_invocation_expr: public expr
{

public:
  SERIALIZABLE_CLASS(dynamic_function_invocation_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(dynamic_function_invocation_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar)
  { 
    serialize_baseclass(ar, (expr*)this);
    ar & theExpr;
    ar & theArgs;   
  }
  
private:
    expr_t theExpr;
    checked_vector<expr_t> theArgs;
    
public:
    dynamic_function_invocation_expr(short sctx, const QueryLoc& loc, expr_t anExpr, std::vector<expr_t>& args)
        : expr(sctx, loc), theExpr(anExpr), theArgs(args)
    {
        assert(anExpr != 0);
	      compute_scripting_kind();
    }
    
	expr_kind_t get_expr_kind() const { return dynamic_function_invocation_expr_kind; }
	
	const expr_t get_function() const { return theExpr; }
	
  const std::vector<expr_t>& get_args() const { return theArgs; }
	
	void compute_scripting_kind() const;
	
  void next_iter(expr_iterator_data& v);

	std::ostream& put(std::ostream& os) const{ /* TODO */ return os; }

	void accept(expr_visitor&);
  
  expr_iterator_data* make_iter(); 
};

class function_item_expr: public expr
{
private:
  store::Item_t theQName;
	function* theFunction;
  checked_vector<expr_t> theScopedVariables;

public:
  SERIALIZABLE_CLASS(function_item_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(function_item_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);
public:
	function_item_expr(short sctx, const QueryLoc& loc,
                     store::Item_t aQName, function* f)
	: expr(sctx, loc), theQName(aQName), theFunction(f)
	{
		assert(f != NULL);
	  compute_scripting_kind();
  }

  function_item_expr(short sctx, const QueryLoc& loc,
                     function* f, std::vector<expr_t> aScopedVariables)
	: expr(sctx, loc), theQName(0), theFunction(f), theScopedVariables(aScopedVariables) 
	{
		assert(f != NULL);
	  compute_scripting_kind();
	}

  ~function_item_expr();
	
  expr_kind_t get_expr_kind() const { return function_item_expr_kind; }
	
	const function* get_function() const { return theFunction; }
	
  const store::Item_t& get_qname() const { return theQName; }
  
  const checked_vector<expr_t> get_vars() const { return theScopedVariables; }

	void compute_scripting_kind() const;
	
  void next_iter(expr_iterator_data& v);

	std::ostream& put(std::ostream& os) const{ return os; }

	void accept(expr_visitor&);

  expr_iterator_data* make_iter();
};

} //end of namespace

#endif
