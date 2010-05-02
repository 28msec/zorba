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

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "system/globalenv.h"

//#include "types/root_typemanager.h"

#include "context/static_context.h"

#include "compiler/expression/path_expr.h"
#include "compiler/expression/expr_visitor.h"

#include "zorbaserialization/serialization_engine.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(relpath_expr)
END_SERIALIZABLE_CLASS_VERSIONS(relpath_expr)

SERIALIZABLE_CLASS_VERSIONS(axis_step_expr)
END_SERIALIZABLE_CLASS_VERSIONS(axis_step_expr)

SERIALIZABLE_CLASS_VERSIONS(match_expr)
END_SERIALIZABLE_CLASS_VERSIONS(match_expr)


DEF_EXPR_ACCEPT (relpath_expr)
DEF_EXPR_ACCEPT (axis_step_expr)
DEF_EXPR_ACCEPT (match_expr)


/*******************************************************************************

  RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
relpath_expr::relpath_expr(static_context* sctx, const QueryLoc& loc)
  :
expr(sctx, loc, relpath_expr_kind)
{
  compute_scripting_kind();
}


void relpath_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theSteps;
}


void relpath_expr::add_back(expr_t step)
{
  if (!step->is_simple() && !step->is_vacuous())
  {
    ZORBA_ERROR_LOC(XUST0001, step->get_loc());
  }

  theSteps.push_back(step);
}


void relpath_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


expr_t relpath_expr::clone(substitution_t& subst) const
{
  std::auto_ptr<relpath_expr> re(new relpath_expr(theSctx, get_loc()));

  for (unsigned i = 0; i < size(); ++i)
  {
    re->add_back((*this)[i]->clone(subst));
  }

  return re.release();
}



/*******************************************************************************

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
axis_step_expr::axis_step_expr(static_context* sctx, const QueryLoc& loc)
  :
  expr(sctx, loc, axis_step_expr_kind)
{
  compute_scripting_kind();
}


void axis_step_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(axis_kind_t, theAxis);
  ar & theNodeTest;
}


bool axis_step_expr::is_reverse_axis(axis_kind_t k) 
{
  return (k == axis_kind_ancestor ||
          k == axis_kind_ancestor_or_self ||
          k == axis_kind_parent ||
          k == axis_kind_preceding ||
          k == axis_kind_preceding_sibling);
}


void axis_step_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


expr_t axis_step_expr::clone(substitution_t& subst) const
{
  axis_step_expr* ae = new axis_step_expr(theSctx, get_loc());
  ae->setAxis(getAxis());
  ae->setTest(getTest());
  return ae;
}


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

********************************************************************************/
match_expr::match_expr(static_context* sctx, const QueryLoc& loc)
  :
  expr(sctx, loc, match_expr_kind),
  theDocTestKind(match_no_test),
  theWildKind(match_no_wild),
  theQName(NULL),
  theTypeName(NULL),
  theNilledAllowed(false)
{
  compute_scripting_kind();
}


void match_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(match_test_t, theTestKind);
  SERIALIZE_ENUM(match_test_t, theDocTestKind);
  SERIALIZE_ENUM(match_wild_t, theWildKind);
  ar & theWildName;
  ar & theQName;
  ar & theTypeName;
  ar & theNilledAllowed;
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


expr_t match_expr::clone(substitution_t& subst) const
{
  match_expr* me = new match_expr(theSctx, get_loc());
  me->setTestKind(getTestKind());
  me->setDocTestKind(getDocTestKind());
  me->setWildName(getWildName());
  me->setWildKind(getWildKind());
  me->setQName(getQName());
  me->setTypeName(getTypeName());
  me->setNilledAllowed(getNilledAllowed());
  return me;
}


}

