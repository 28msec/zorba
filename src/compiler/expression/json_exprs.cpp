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

#include "compiler/expression/json_exprs.h"
#include "compiler/expression/expr_visitor.h"

#ifdef ZORBA_WITH_JSON

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(json_object_expr)
END_SERIALIZABLE_CLASS_VERSIONS(json_object_expr)

SERIALIZABLE_CLASS_VERSIONS(json_array_expr)
END_SERIALIZABLE_CLASS_VERSIONS(json_array_expr)

DEF_EXPR_ACCEPT(json_object_expr)
DEF_EXPR_ACCEPT(json_array_expr)


/*******************************************************************************
 JSONObjectConstructor ::= "{" Expr? "}"
********************************************************************************/
json_object_expr::json_object_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& content)
  :
  expr(sctx, loc, json_object_expr_kind),
  theContentExpr(content)
{
  compute_scripting_kind();
}


void json_object_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theContentExpr;
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
  return new json_object_expr(theSctx,
                              get_loc(),
                              (theContentExpr ?
                               theContentExpr->clone(subst) :
                               NULL));
}


/*******************************************************************************
 JSONArrayConstructor ::= "[" Expr? "]"
********************************************************************************/
json_array_expr::json_array_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& content)
  :
  expr(sctx, loc, json_array_expr_kind),
  theContentExpr(content)
{
  compute_scripting_kind();
}


void json_array_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theContentExpr;
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
  return new json_array_expr(theSctx,
                             get_loc(),
                             theContentExpr->clone(subst));
}


}

#endif // ZORBA_WITH_JSON

