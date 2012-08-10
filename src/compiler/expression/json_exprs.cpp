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

#ifdef ZORBA_WITH_JSON

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
    const QueryLoc& loc,
    const expr_t& content)
  :
  expr(ccb, sctx, loc, json_array_expr_kind),
  theContentExpr(content)
{
  compute_scripting_kind();
}


void json_array_expr::compute_scripting_kind()
{
  if (theContentExpr)
  {
    checkNonUpdating(theContentExpr);

    theScriptingKind = theContentExpr->get_scripting_detail();

    theScriptingKind &= ~VACUOUS_EXPR;
  }
  else
  {
    theScriptingKind = SIMPLE_EXPR;
  }
}


expr_t json_array_expr::clone(substitution_t& subst) const
{
  return theCCB->theEM->create_json_array_expr(theSctx,
                             get_loc(),
                             theContentExpr->clone(subst));
}


/*******************************************************************************
  SimpleObjectUnion ::= "{|" Expr? "|}"

  AccumulatorObjectUnion ::= "{[" Expr? "]}"

  The Expr must return a sequence of zero or more objects
********************************************************************************/
json_object_expr::json_object_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& content,
    bool accumulate)
  :
  expr(ccb, sctx, loc, json_object_expr_kind),
  theContentExpr(content),
  theAccumulate(accumulate)
{
  compute_scripting_kind();
}


void json_object_expr::compute_scripting_kind()
{
  if (theContentExpr)
  {
    checkNonUpdating(theContentExpr);

    theScriptingKind = theContentExpr->get_scripting_detail();

    theScriptingKind &= ~VACUOUS_EXPR;
  }
  else
  {
    theScriptingKind = SIMPLE_EXPR;
  }
}


expr_t json_object_expr::clone(substitution_t& subst) const
{
  return theCCB->theEM->create_json_object_expr(theSctx,
                              get_loc(),
                              (theContentExpr ?
                               theContentExpr->clone(subst) :
                               NULL),
                              theAccumulate);
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
    const QueryLoc& loc,
    std::vector<expr_t>& names,
    std::vector<expr_t>& values)
  :
  expr(ccb, sctx, loc, json_direct_object_expr_kind)
{
  assert(names.size() == values.size());

  theNames.swap(names);
  theValues.swap(values);

  compute_scripting_kind();
}


void json_direct_object_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  std::vector<expr_t>::const_iterator ite = theNames.begin();
  std::vector<expr_t>::const_iterator end = theNames.end();
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


expr_t json_direct_object_expr::clone(substitution_t& subst) const
{
  std::vector<expr_t> names;
  std::vector<expr_t> values;

  names.reserve(theNames.size());
  values.reserve(theValues.size());

  std::vector<expr_t>::const_iterator ite = theNames.begin();
  std::vector<expr_t>::const_iterator end = theNames.end();
  for (; ite != end; ++ite)
  {
    names.push_back((*ite)->clone(subst));
  }

  ite = theValues.begin();
  end = theValues.end();
  for (; ite != end; ++ite)
  {
    values.push_back((*ite)->clone(subst));
  }

  return theCCB->theEM->
      create_json_direct_object_expr(theSctx, get_loc(), names, values);
}


}
#endif // ZORBA_WITH_JSON

