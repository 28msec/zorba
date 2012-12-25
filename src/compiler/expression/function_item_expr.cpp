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

#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_visitor.h"

#include "compiler/api/compilercb.h"

#include "functions/function.h"
#include "functions/udf.h"
#include "functions/signature.h"

namespace zorba {


DEF_EXPR_ACCEPT (dynamic_function_invocation_expr)


dynamic_function_invocation_expr::dynamic_function_invocation_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* anExpr,
    const std::vector<expr*>& args)
  :
  expr(ccb, sctx, udf, loc, dynamic_function_invocation_expr_kind),
  theExpr(anExpr),
  theArgs(args)
{
  assert(anExpr != 0);
  compute_scripting_kind();
}


void dynamic_function_invocation_expr::compute_scripting_kind()
{
  // TODO ????
  theScriptingKind = SIMPLE_EXPR;
#if 0
  theScriptingKind = (APPLYING_EXPR | SEQUENTIAL_FUNC_EXPR)
#endif
}


/*******************************************************************************

********************************************************************************/

DEF_EXPR_ACCEPT (function_item_expr)


function_item_expr::function_item_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    const store::Item* aQName,
    function* f,
    uint32_t aArity)
  :
  expr(ccb, sctx, udf, loc, function_item_expr_kind),
  theQName(const_cast<store::Item*>(aQName)),
  theFunction(f),
  theArity(aArity)
{
  assert(f != NULL);
  compute_scripting_kind();
}


function_item_expr::function_item_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc)
  :
  expr(ccb, sctx, udf, loc, function_item_expr_kind),
  theQName(0),
  theFunction(NULL),
  theArity(0)
{
  theScriptingKind = SIMPLE_EXPR;
}


function_item_expr::~function_item_expr()
{
}


user_function* function_item_expr::get_function() const 
{
  assert(theFunction->isUdf());
  return static_cast<user_function*>(theFunction.getp());
}


void function_item_expr::add_variable(expr* var)
{
  theScopedVariables.push_back(var);
}


const std::vector<expr*>& function_item_expr::get_vars() const
{
  return theScopedVariables;
}


void function_item_expr::set_function(user_function_t& udf)
{
  theFunction = udf;
  theArity = udf->getArity();
  compute_scripting_kind();
}


void function_item_expr::compute_scripting_kind()
{
  // ???? TODO
  theScriptingKind = SIMPLE_EXPR;
}


}//end of namespace
/* vim:set et sw=2 ts=2: */
