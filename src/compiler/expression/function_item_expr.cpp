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

#include "compiler/expression/function_item_expr.h"

#include "zorbautils/checked_vector.h"

#include "compiler/expression/expr_utils.h"
#include "compiler/expression/expr_visitor.h"

#include "functions/function.h"

using namespace std;

namespace zorba {

/**
 *
 */ 
SERIALIZABLE_CLASS_VERSIONS(dynamic_function_invocation_expr)
END_SERIALIZABLE_CLASS_VERSIONS(dynamic_function_invocation_expr)
DEF_EXPR_ACCEPT (dynamic_function_invocation_expr)

class dynamic_function_invocation_expr_iterator_data : public expr_iterator_data 
{
public:
  checked_vector<expr_t>::iterator iter;

  dynamic_function_invocation_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};

void dynamic_function_invocation_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER2(dynamic_function_invocation_expr);
  ITER(theExpr);
  ITER_FOR_EACH(iter, theArgs.begin(), theArgs.end(), (*vv.iter));
  END_EXPR_ITER();
}

void dynamic_function_invocation_expr::compute_scripting_kind() const 
{
  theCache.scripting_kind.kind = SIMPLE_EXPR;
}

expr_iterator_data* dynamic_function_invocation_expr::make_iter()
{
  return new dynamic_function_invocation_expr_iterator_data(this);
}

/**
 *
 */
SERIALIZABLE_CLASS_VERSIONS(function_item_expr)
END_SERIALIZABLE_CLASS_VERSIONS(function_item_expr)
DEF_EXPR_ACCEPT (function_item_expr)

class function_item_expr_iterator_data : public expr_iterator_data 
{
public:
  checked_vector<expr_t>::iterator iter;

  function_item_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};

function_item_expr::~function_item_expr(){}

void function_item_expr::compute_scripting_kind() const 
{
  theCache.scripting_kind.kind = SIMPLE_EXPR;
}

void function_item_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER2(function_item_expr);
  ITER_FOR_EACH(iter, theScopedVariables.begin(),
    theScopedVariables.end(),
    (*vv.iter));
  END_EXPR_ITER();
}

expr_iterator_data* function_item_expr::make_iter()
{
  return new function_item_expr_iterator_data(this);
}
}//end of namespace
