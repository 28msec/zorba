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

#include "types/root_typemanager.h"
#include "types/typeops.h"

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


#define RAISE_XPST0005()                            \
  {                                                 \
    ZORBA_ERROR_LOC(XPST0005, loc);                 \
    return RTM.EMPTY_TYPE;                          \
  }


static xqtref_t create_axis_step_type(
    TypeManager* tm,
    store::StoreConsts::NodeKind nodekind,
    const store::Item_t& nodename,
    TypeConstants::quantifier_t quant,
    bool untyped);


static xqtref_t axist_step_type(
    static_context* sctx,
    const axis_step_expr* axisStep,
    const NodeXQType* inputType);


/*******************************************************************************

********************************************************************************/
class relpath_expr_iterator_data : public expr_iterator_data 
{
public:
  ulong theCurrStep;

  relpath_expr_iterator_data(expr* e) 
    :
    expr_iterator_data(e),
    theCurrStep(0)
  {
  }
};


/*******************************************************************************

  RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
relpath_expr::relpath_expr(short sctx, const QueryLoc& loc)
  :
  expr(sctx, loc)
{
  theTargetPos = 0;
}


void relpath_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theSteps;
  ar & theTargetPos;
}


void relpath_expr::add_back(expr_t step)
{
  invalidate();

  if (!step->is_simple())
  {
    ZORBA_ERROR_LOC(XUST0001, step->get_loc());
  }

  theSteps.push_back(step);
}


void relpath_expr::compute_scripting_kind() const
{
  theCache.scripting_kind.kind = SIMPLE_EXPR;
  theCache.scripting_kind.valid = true;
}


xqtref_t relpath_expr::return_type_impl(static_context* sctx) const
{
  if (size() == 0)
    return GENV_TYPESYSTEM.EMPTY_TYPE;

  if (size() == 1)
    return theSteps[0]->return_type(sctx);

  xqtref_t sourceType = theSteps[0]->return_type(sctx);

  if (TypeOps::is_empty (*sourceType) || TypeOps::is_none (*sourceType))
    return sourceType;

  if (sourceType->type_kind() != XQType::NODE_TYPE_KIND)
  {
    ZORBA_ERROR_LOC(XPTY0020, get_loc());
    return GENV_TYPESYSTEM.NONE_TYPE;
  }

  xqtref_t stepType = sourceType;

  for (unsigned i = 1; i < size(); i++) 
  {
    const axis_step_expr* axisStep = theSteps[i].cast<axis_step_expr>();

    stepType = axist_step_type(sctx,
                               axisStep,
                               reinterpret_cast<const NodeXQType*>(stepType.getp()));
  }

  return stepType.getp();
}


expr_iterator_data* relpath_expr::make_iter()
{
  return new relpath_expr_iterator_data(this); 
}


void relpath_expr::next_iter(expr_iterator_data& v) 
{
  relpath_expr_iterator_data& vv = static_cast<relpath_expr_iterator_data&>(v);

  BEGIN_EXPR_ITER();

  for (; vv.theCurrStep < theSteps.size(); ++vv.theCurrStep)
  {
    ITER(theSteps[vv.theCurrStep]);
  }

  END_EXPR_ITER();
}


expr_t relpath_expr::clone(substitution_t& subst) const
{
  std::auto_ptr<relpath_expr> re(new relpath_expr(theSctxId, get_loc()));

  for (unsigned i = 0; i < size(); ++i)
  {
    re->add_back((*this)[i]->clone(subst));
  }

  return re.release();
}



/*******************************************************************************

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
axis_step_expr::axis_step_expr(short sctx, const QueryLoc& loc)
  :
  expr(sctx, loc)
{
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


void axis_step_expr::compute_scripting_kind() const
{
  theCache.scripting_kind.kind = SIMPLE_EXPR;
  theCache.scripting_kind.valid = true;
}


xqtref_t axis_step_expr::return_type_impl(static_context* sctx) const
{
  return (theNodeTest == NULL ?
          GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE :
          theNodeTest->return_type(sctx));
}


void axis_step_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();

  ITER(theNodeTest);

  END_EXPR_ITER();
}


expr_t axis_step_expr::clone(substitution_t& subst) const
{
  axis_step_expr* ae = new axis_step_expr(theSctxId, get_loc());
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
match_expr::match_expr(short sctx, const QueryLoc& loc)
  :
  expr(sctx, loc),
  theDocTestKind(match_no_test),
  theWildKind(match_no_wild),
  theQName(NULL),
  theTypeName(NULL),
  theNilledAllowed(false)
{
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


void match_expr::compute_scripting_kind() const
{
  theCache.scripting_kind.kind = SIMPLE_EXPR;
  theCache.scripting_kind.valid = true;
}


xqtref_t match_expr::return_type_impl(static_context* sctx) const
{
  return GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE;
}


void match_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


expr_t match_expr::clone(substitution_t& subst) const
{
  match_expr* me = new match_expr(theSctxId, get_loc());
  me->setTestKind(getTestKind());
  me->setDocTestKind(getDocTestKind());
  me->setWildName(getWildName());
  me->setWildKind(getWildKind());
  me->setQName(getQName());
  me->setTypeName(getTypeName());
  me->setNilledAllowed(getNilledAllowed());
  return me;
}


/*******************************************************************************

********************************************************************************/
static xqtref_t axist_step_type(
    static_context* sctx,
    const axis_step_expr* axisStep,
    const NodeXQType* inputType)
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;
  TypeManager* tm = sctx->get_typemanager();

  const QueryLoc& loc = axisStep->get_loc();

  axis_kind_t axisKind = axisStep->getAxis();
  match_expr* nodeTest = axisStep->getTest();

  match_test_t testKind =  nodeTest->getTestKind();
  store::StoreConsts::NodeKind testNodeKind = nodeTest->getNodeKind();
  store::Item* testSchemaType = nodeTest->getTypeName();
  store::Item* testNodeName = nodeTest->getQName();
  match_wild_t wildKind = nodeTest->getWildKind();

  TypeConstants::quantifier_t inQuant = inputType->get_quantifier();
  store::StoreConsts::NodeKind inNodeKind = inputType->get_node_kind();
  store::Item* inNodeName = inputType->get_node_name();
  xqtref_t inContentType = inputType->get_content_type();

  TypeConstants::quantifier_t star = TypeConstants::QUANT_STAR;

  bool inUntyped = false;
  if (inContentType != NULL)
  {
    if (inContentType == RTM.UNTYPED_TYPE)
    {
      inUntyped = true;
    }
    else if (inNodeKind == store::StoreConsts::documentNode &&
             inContentType->type_kind() == XQType::NODE_TYPE_KIND)
    {
      const NodeXQType* rootElemType = reinterpret_cast<const NodeXQType*>(
                                       inContentType.getp());
      if (rootElemType->get_content_type() == RTM.UNTYPED_TYPE)
        inUntyped = true;
    }
  }

  if (inUntyped &&
      (axisKind == axis_kind_self ||
       axisKind == axis_kind_descendant_or_self ||
       axisKind == axis_kind_descendant ||
       axisKind == axis_kind_child ||
       axisKind == axis_kind_attribute))
  {
    if (testKind == match_attr_test &&
        testSchemaType != NULL &&
        ! testSchemaType->equals(RTM.XS_UNTYPED_ATOMIC_QNAME))
    {
      RAISE_XPST0005(); 
    }
    else if ((testKind == match_elem_test || testKind == match_doc_test) &&
             testSchemaType != NULL &&
             ! testSchemaType->equals(RTM.XS_UNTYPED_QNAME))
    {
      RAISE_XPST0005(); 
    }
  }

  switch (axisKind)
  {
  case axis_kind_parent:
  {
    // Doc nodes do not have parent
    if (inNodeKind == store::StoreConsts::documentNode)
    {
      RAISE_XPST0005();
    }

    // Only element or doc nodes are reachable via the parent axis.
    if (testNodeKind != store::StoreConsts::documentNode &&
        testNodeKind != store::StoreConsts::elementNode && 
        testNodeKind != store::StoreConsts::anyNode)
    {
      RAISE_XPST0005();
    }

    // Doc nodes cannot be parents of attribute nodes
    if (inNodeKind == store::StoreConsts::attributeNode &&
        testNodeKind == store::StoreConsts::documentNode)
    {
      RAISE_XPST0005();
    }

    return create_axis_step_type(tm, testNodeKind, testNodeName, inQuant, false);

    break;
  }

  case axis_kind_ancestor:
  {
    // Doc nodes do not have ancestors
    if (inNodeKind == store::StoreConsts::documentNode)
    {
      RAISE_XPST0005();
    }

    // Only element or doc nodes are reachable via the ancestor axis.
    if (testNodeKind != store::StoreConsts::documentNode &&
        testNodeKind != store::StoreConsts::elementNode && 
        testNodeKind != store::StoreConsts::anyNode)
    {
      RAISE_XPST0005();
    }

    if (testNodeKind == store::StoreConsts::elementNode)
    {
      return RTM.ELEMENT_TYPE_STAR;
    }
    else if (testNodeKind == store::StoreConsts::documentNode)
    {
      return create_axis_step_type(tm, testNodeKind, testNodeName, inQuant, false);
    }
    else
    {
      assert(testKind == match_anykind_test);
      return RTM.ANY_NODE_TYPE_STAR;
    }

    break;
  }

  case axis_kind_ancestor_or_self:
  {
    if (testNodeKind == store::StoreConsts::elementNode)
    {
      return RTM.ELEMENT_TYPE_STAR;
    }
    else if (testNodeKind == store::StoreConsts::documentNode)
    {
      return create_axis_step_type(tm, testNodeKind, testNodeName, inQuant, false);
    }
    else if (testNodeKind == store::StoreConsts::anyNode)
    {
      return RTM.ANY_NODE_TYPE_STAR;
    }
    else 
    {
      // We are looking for attribute, test, pi, or comment ancestor nodes. Only
      // the "self" node may qualify, so we jump to the axis_kind_self case.
      goto self;
    }

    break;
  }

  case axis_kind_self:
  {
self:
    // The node kind of the self node must be compatible with the NodeTest.
    if (testNodeKind != store::StoreConsts::anyNode &&
        inNodeKind != store::StoreConsts::anyNode &&
        inNodeKind != testNodeKind)
    {
      RAISE_XPST0005();
    }

    if (testNodeName != NULL &&
        inNodeName != NULL &&
        !inNodeName->equals(testNodeName))
    {
      RAISE_XPST0005();
    }

    switch (inNodeKind)
    {
    case store::StoreConsts::documentNode:
    case store::StoreConsts::elementNode:
    case store::StoreConsts::attributeNode:
      return create_axis_step_type(tm, inNodeKind, testNodeName, inQuant, inUntyped);

    case store::StoreConsts::textNode:
    case store::StoreConsts::piNode:
    case store::StoreConsts::commentNode:
      return create_axis_step_type(tm, inNodeKind, testNodeName, inQuant, false);

    case store::StoreConsts::anyNode:
    {
      switch (testNodeKind)
      {
      case store::StoreConsts::anyNode:
      case store::StoreConsts::documentNode:
      case store::StoreConsts::elementNode:
      case store::StoreConsts::attributeNode:
        return create_axis_step_type(tm, testNodeKind, testNodeName, inQuant, inUntyped);

      case store::StoreConsts::textNode:
      case store::StoreConsts::piNode:
      case store::StoreConsts::commentNode:
        return create_axis_step_type(tm, testNodeKind, testNodeName, inQuant, false);

      default:
        ZORBA_ASSERT(false);
      }

      break;
    }

    default:
      ZORBA_ASSERT(false);
    }

    break;
  }

  case axis_kind_descendant_or_self:
  {
    // If we are looking for descendants or self of attribute, test, pi, or 
    // comment nodes, only the "self" node may qualify, so we jump to the
    // axis_kind_self case.
    if (inNodeKind == store::StoreConsts::attributeNode ||
        inNodeKind == store::StoreConsts::textNode ||
        inNodeKind == store::StoreConsts::piNode ||
        inNodeKind == store::StoreConsts::commentNode)
    {
      goto self;
    }

    // if we are looking for document or attribute descendants of a node, only
    // the "self" node may qualify, so we jump to the axis_kind_self case. 
    if (testNodeKind == store::StoreConsts::documentNode ||
        testNodeKind == store::StoreConsts::attributeNode)
    {
      goto self;
    }

    switch (testNodeKind)
    {
    case store::StoreConsts::anyNode:
      return create_axis_step_type(tm, testNodeKind, testNodeName, star, inUntyped);

    case store::StoreConsts::elementNode:
      return create_axis_step_type(tm, testNodeKind, testNodeName, star, inUntyped);

    case store::StoreConsts::textNode:
      return RTM.TEXT_TYPE_STAR;

    case store::StoreConsts::piNode:
      return RTM.PI_TYPE_STAR;
      
    case store::StoreConsts::commentNode:
      return RTM.COMMENT_TYPE_STAR;

    default:
      ZORBA_ASSERT(false);
    }

    break;
  }

  case axis_kind_descendant:
  case axis_kind_child:
  {
    if (inNodeKind == store::StoreConsts::attributeNode ||
        inNodeKind == store::StoreConsts::textNode ||
        inNodeKind == store::StoreConsts::piNode ||
        inNodeKind == store::StoreConsts::commentNode)
    {
      RAISE_XPST0005();
    }

    if (testNodeKind == store::StoreConsts::documentNode ||
        testNodeKind == store::StoreConsts::attributeNode)
    {
      RAISE_XPST0005();
    }

    switch (testNodeKind)
    {
    case store::StoreConsts::anyNode:
      return create_axis_step_type(tm, testNodeKind, testNodeName, star, inUntyped);

    case store::StoreConsts::elementNode:
      return create_axis_step_type(tm, testNodeKind, testNodeName, star, inUntyped);

    case store::StoreConsts::textNode:
      return RTM.TEXT_TYPE_STAR;

    case store::StoreConsts::piNode:
      return RTM.PI_TYPE_STAR;
      
    case store::StoreConsts::commentNode:
      return RTM.COMMENT_TYPE_STAR;

    default:
      ZORBA_ASSERT(false);
    }

    break;
  }

  case axis_kind_attribute:
  {
    // only element nodes have attributes.
    if (inNodeKind != store::StoreConsts::elementNode &&
        inNodeKind != store::StoreConsts::anyNode)
    {
      RAISE_XPST0005();
    }

    // only attribute nodes are reachable via the attribute axis.
    if (testKind != match_name_test &&
        testKind != match_anykind_test && 
        testKind != match_attr_test &&
        testKind != match_xs_attr_test)
    {
      RAISE_XPST0005();
    }

    if ((testKind == match_name_test && wildKind == match_no_wild) ||
        testKind == match_xs_attr_test)
    {
      return create_axis_step_type(tm,
                                   store::StoreConsts::attributeNode,
                                   testNodeName,
                                   inQuant,
                                   inUntyped);
    }
    else
    {
      return create_axis_step_type(tm,
                                   store::StoreConsts::attributeNode,
                                   testNodeName,
                                   star,
                                   inUntyped);
    }

    break;
  }

  case axis_kind_following_sibling:
  case axis_kind_preceding_sibling:
  case axis_kind_following:
  case axis_kind_preceding:
  {
    if (inNodeKind == store::StoreConsts::documentNode ||
        testNodeKind == store::StoreConsts::documentNode)
    {
      RAISE_XPST0005();
    }

    if ((axisKind == axis_kind_following_sibling ||
         axisKind == axis_kind_preceding_sibling) &&
        (inNodeKind == store::StoreConsts::attributeNode ||
         testNodeKind == store::StoreConsts::attributeNode))
    {
      RAISE_XPST0005();
    }

    switch (testNodeKind)
    {
    case store::StoreConsts::anyNode:
      return RTM.ANY_NODE_TYPE_STAR;

    case store::StoreConsts::elementNode:
      return RTM.ELEMENT_TYPE_STAR;

    case store::StoreConsts::attributeNode:
      return RTM.ATTRIBUTE_TYPE_STAR;

    case store::StoreConsts::textNode:
      return RTM.TEXT_TYPE_STAR;

    case store::StoreConsts::piNode:
      return RTM.PI_TYPE_STAR;
      
    case store::StoreConsts::commentNode:
      return RTM.COMMENT_TYPE_STAR;

    default:
      ZORBA_ASSERT(false);
    }

    break;
  }

  default:
  {
    ZORBA_ASSERT(false);
    return GENV_TYPESYSTEM.NONE_TYPE;
  }
  }

  ZORBA_ASSERT(false);
  return GENV_TYPESYSTEM.NONE_TYPE;
}


static xqtref_t create_axis_step_type(
    TypeManager* tm,
    store::StoreConsts::NodeKind nodekind,
    const store::Item_t& nodename,
    TypeConstants::quantifier_t quant,
    bool untyped)
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  if (untyped) 
  {
    xqtref_t contentType; 
    if (nodekind == store::StoreConsts::attributeNode)
      contentType = RTM.UNTYPED_ATOMIC_TYPE_ONE;
    else
      contentType = RTM.UNTYPED_TYPE;

    if (TypeOps::is_sub_quant(quant, TypeConstants::QUANT_QUESTION))
    {
      return tm->create_node_type(nodekind,
                                  nodename,
                                  contentType,
                                  TypeConstants::QUANT_QUESTION,
                                  false,
                                  false);
    }
    else
    {
      return tm->create_node_type(nodekind,
                                  nodename,
                                  contentType,
                                  TypeConstants::QUANT_STAR,
                                  false,
                                  false);
    }
  }
  else
  {
    xqtref_t contentType; 
    if (nodekind == store::StoreConsts::attributeNode)
      contentType = RTM.ANY_SIMPLE_TYPE;
    else
      contentType = RTM.ANY_TYPE;

    if (TypeOps::is_sub_quant(quant, TypeConstants::QUANT_QUESTION))
    {
      return tm->create_node_type(nodekind,
                                  nodename,
                                  contentType,
                                  TypeConstants::QUANT_QUESTION,
                                  false,
                                  false);
    }
    else
    {
      return tm->create_node_type(nodekind,
                                  nodename,
                                  contentType,
                                  TypeConstants::QUANT_STAR,
                                  false,
                                  false);
    }
  }
}


}

