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
#include "compiler/expression/json_exprs.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/api/compilercb.h"

namespace zorba
{

DEF_EXPR_ACCEPT(json_array_expr)
DEF_EXPR_ACCEPT(json_object_expr)
DEF_EXPR_ACCEPT(json_direct_object_expr)

/*******************************************************************************
 JSONArrayConstructor ::= "[" Expr? "]"
********************************************************************************/
json_array_expr::json_array_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* content)
  :
  expr(ccb, sctx, udf, loc, json_array_expr_kind),
  theContentExpr(content)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void json_array_expr::compute_scripting_kind()
{
  if (theContentExpr)
  {
    checkNonUpdating(theContentExpr);

    theScriptingKind = theContentExpr->get_scripting_detail();

    if (theScriptingKind == VACUOUS_EXPR)
      theScriptingKind = SIMPLE_EXPR;
    else
      theScriptingKind &= ~VACUOUS_EXPR;
  }
  else
  {
    theScriptingKind = SIMPLE_EXPR;
  }
}


/*******************************************************************************
  SimpleObjectUnion ::= "{|" Expr? "|}"

  AccumulatorObjectUnion ::= "{[" Expr? "]}"

  The Expr must return a sequence of zero or more objects
********************************************************************************/
json_object_expr::json_object_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* content,
    bool accumulate)
  :
  expr(ccb, sctx, udf, loc, json_object_expr_kind),
  theContentExpr(content),
  theAccumulate(accumulate)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void json_object_expr::compute_scripting_kind()
{
  if (theContentExpr)
  {
    checkNonUpdating(theContentExpr);

    theScriptingKind = theContentExpr->get_scripting_detail();

    if (theScriptingKind == VACUOUS_EXPR)
      theScriptingKind = SIMPLE_EXPR;
    else
      theScriptingKind &= ~VACUOUS_EXPR;
  }
  else
  {
    theScriptingKind = SIMPLE_EXPR;
  }
}


/*******************************************************************************
  DirectObjectConstructor ::= "{" PairConstructor ("," PairConstructor )* "}"

  PairConstructor ::= ExprSingle ":" ExprSingle

  The 1st ExprSingle must return exactly one string.
  The 2nd ExprSingle must contain exactly one item of any kind.
********************************************************************************/
json_direct_object_expr::json_direct_object_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    std::vector<expr*>& names,
    std::vector<expr*>& values)
  :
  expr(ccb, sctx, udf, loc, json_direct_object_expr_kind)
{
  assert(names.size() == values.size());

  theNames.swap(names);
  theValues.swap(values);

  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void json_direct_object_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  std::vector<expr*>::const_iterator ite = theNames.begin();
  std::vector<expr*>::const_iterator end = theNames.end();
  for (; ite != end; ++ite)
  {
    theScriptingKind |= (*ite)->get_scripting_detail();
  }

  ite = theValues.begin();
  end = theValues.end();
  for (; ite != end; ++ite)
  {
    theScriptingKind |= (*ite)->get_scripting_detail();
  }

  theScriptingKind &= ~VACUOUS_EXPR;

  if (theScriptingKind & UPDATING_EXPR)
    theScriptingKind &= ~SIMPLE_EXPR;

  if (is_sequential(theScriptingKind))
    theScriptingKind &= ~SIMPLE_EXPR;

  checkScriptingKind();
}


}
