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

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "compiler/expression/path_expr.h"
#include "compiler/expression/expr_visitor.h"

#include "compiler/api/compilercb.h"


namespace zorba
{


DEF_EXPR_ACCEPT (relpath_expr)
DEF_EXPR_ACCEPT (axis_step_expr)
DEF_EXPR_ACCEPT (match_expr)


/*******************************************************************************

  RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
relpath_expr::relpath_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc)
  :
  expr(ccb, sctx, udf, loc, relpath_expr_kind)
{
  theScriptingKind = SIMPLE_EXPR;
}


void relpath_expr::add_back(expr* step)
{
  if (step->is_updating())
  {
    throw XQUERY_EXCEPTION(err::XUST0001,
                           ERROR_PARAMS(ZED(XUST0001_Generic)),
                           ERROR_LOC(get_loc()));
  }

  theScriptingKind |= step->get_scripting_detail();

  if (theScriptingKind & VACUOUS_EXPR)
    theScriptingKind &= ~VACUOUS_EXPR;

  if (is_sequential(theScriptingKind))
    theScriptingKind &= ~SIMPLE_EXPR;

  checkScriptingKind();

  theSteps.push_back(step);
}


void relpath_expr::compute_scripting_kind()
{
  theScriptingKind = UNKNOWN_SCRIPTING_KIND;

  for (unsigned i = 0; i < size(); ++i)
  {
    expr* step = theSteps[i];

    if (step->is_updating())
    {
      throw XQUERY_EXCEPTION(err::XUST0001,
                             ERROR_PARAMS(ZED(XUST0001_Generic)),
                             ERROR_LOC(get_loc()));
    }

    theScriptingKind |= step->get_scripting_detail();
  }

  theScriptingKind &= ~VACUOUS_EXPR;

  if (is_sequential(theScriptingKind))
    theScriptingKind &= ~SIMPLE_EXPR;

  checkScriptingKind();
}


/*******************************************************************************

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
axis_step_expr::axis_step_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc)
  :
  expr(ccb, sctx, udf, loc, axis_step_expr_kind),
  theReverseOrder(false)
{
  compute_scripting_kind();
}


bool axis_step_expr::is_reverse_axis(axis_kind_t k)
{
  return (k == axis_kind_ancestor ||
          k == axis_kind_ancestor_or_self ||
          k == axis_kind_parent ||
          k == axis_kind_preceding ||
          k == axis_kind_preceding_sibling);
}

void axis_step_expr::setTest(match_expr* v)
{
  theNodeTest = v;
}

void axis_step_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

********************************************************************************/
match_expr::match_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc)
  :
  expr(ccb, sctx, udf, loc, match_expr_kind),
  theDocTestKind(match_no_test),
  theWildKind(match_no_wild),
  theQName(NULL),
  theTypeName(NULL),
  theNilledAllowed(false)
{
  compute_scripting_kind();
}


store::StoreConsts::NodeKind match_expr::getNodeKind() const
{
  switch (theTestKind)
  {
  case match_name_test:
    return store::StoreConsts::elementNode;
  case match_doc_test:
    return store::StoreConsts::documentNode;
  case match_elem_test:
    return store::StoreConsts::elementNode;
  case match_xs_elem_test:
    return store::StoreConsts::elementNode;
  case match_attr_test:
    return store::StoreConsts::attributeNode;
  case match_xs_attr_test:
    return store::StoreConsts::attributeNode;
  case match_pi_test:
    return store::StoreConsts::piNode;
  case match_text_test:
    return store::StoreConsts::textNode;
  case match_namespace_test:
    return store::StoreConsts::namespaceNode;
  case match_comment_test:
    return store::StoreConsts::commentNode;
  case match_anykind_test:
    return store::StoreConsts::anyNode;
  default:
    ZORBA_ASSERT (false && "Unknown node test kind");
  }
  return store::StoreConsts::anyNode;
}


void match_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


bool match_expr::matches(const match_expr* other) const
{
  if (theTestKind != other->theTestKind)
    return false;

  switch (theTestKind)
  {
  case match_name_test:
  {
    if (getWildKind() != other->getWildKind())
      return false;

    if (getWildName() != other->getWildName())
      return false;

    if (getWildKind() == match_no_wild || getWildKind() == match_name_wild)
    {
      return getQName()->equals(other->getQName());
    }

    return true;
  }
  case match_anykind_test:
  case match_text_test:
  case match_comment_test:
  {
    return true;
  }
  case match_pi_test:
  {
    if (theQName == NULL && other->theQName == NULL)
      return true;

    if (theQName == NULL || other->theQName == NULL)
      return false;

    return theQName->equals(other->theQName);
  }
  case match_doc_test:
  {
    if (theDocTestKind != other->theDocTestKind)
      return false;

    if (theDocTestKind == match_xs_elem_test)
      goto schema_test;

    // else fall through
  }
  case match_elem_test:
  case match_attr_test:
  {
    if (theQName == NULL || other->theQName == NULL)
    {
      if (theQName != NULL || other->theQName != NULL)
        return false;
    }
    else if (!theQName->equals(other->theQName))
    {
      return false;
    }

    if (theTypeName == NULL || other->theTypeName == NULL)
    {
      if (theTypeName != NULL || other->theTypeName != NULL)
        return false;
    }
    else if (!theTypeName->equals(other->theTypeName))
    {
      return false;
    }

    if (theNilledAllowed != other->theNilledAllowed)
      return false;

    return true;
  }
  case match_xs_elem_test:
  case match_xs_attr_test:
  {
schema_test:
    return (theQName->equals(other->theQName) &&
            theTypeName->equals(other->theTypeName));
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }

  return false;
}


}

/* vim:set et sw=2 ts=2: */
