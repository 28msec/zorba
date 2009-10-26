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

#include "system/globalenv.h"

#include "compiler/expression/expr.h"

#include "functions/function.h"

#include "context/static_context.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "util/properties.h"

using namespace std;

namespace zorba 
{



static xqtref_t create_axis_step_type(
    TypeManager* tm,
    store::StoreConsts::NodeKind nodekind,
    const store::Item_t& nodename,
    TypeConstants::quantifier_t quant,
    bool untyped);



xqtref_t flwor_expr::return_type_impl(static_context *sctx) 
{
  // TODO: quant multiplication
  return sctx->get_typemanager()->create_type(*theReturnExpr->return_type(sctx),
                                              TypeConstants::QUANT_STAR);
}



static xqtref_t axist_step_type(
    static_context* sctx,
    const axis_step_expr* axisStep,
    const NodeXQType* inputType)
{

#define RAISE_XPST0005()                            \
  {                                                 \
    ZORBA_ERROR_LOC(XPST0005, loc);                 \
    return RTM.EMPTY_TYPE;                          \
  }


  RootTypeManager& RTM = GENV_TYPESYSTEM;
  TypeManager* tm = sctx->get_typemanager();

  const QueryLoc& loc = axisStep->get_loc();

  axis_kind_t axisKind = axisStep->getAxis();
  match_expr* nodeTest = axisStep->getTest().getp();

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


xqtref_t relpath_expr::return_type_impl(static_context* sctx) 
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


xqtref_t axis_step_expr::return_type_impl(static_context *sctx) 
{
  return theNodeTest == NULL ? GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE : theNodeTest->return_type (sctx);
}


xqtref_t match_expr::return_type_impl(static_context *sctx) 
{
  return GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE;
}

  

xqtref_t order_expr::return_type_impl(static_context *sctx) 
{
  return expr_h->return_type (sctx); 
}
  

xqtref_t var_expr::return_type_impl(static_context* sctx) 
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t derivedType;
  expr* domainExpr;

  // The translator has already set theDeclaredType of pos_vars, count_vars,
  // wincond_out_pos_vars, and wincond_in_pos_vars to xs:positiveInteger.
  if (theKind == pos_var ||
      theKind == wincond_out_pos_var ||
      theKind == wincond_in_pos_var)
  {
    return theDeclaredType;
  }
  else if (theKind == for_var ||
           theKind == let_var ||
           theKind == win_var || 
           theKind == wincond_in_var ||
           theKind == wincond_out_var ||
           theKind == groupby_var ||
           theKind == non_groupby_var ||
           theKind == copy_var) 
  {
    domainExpr = get_domain_expr();
    ZORBA_ASSERT(domainExpr != NULL);

    xqtref_t domainType = domainExpr->return_type(sctx);

    if (theKind == for_var) 
    {
      derivedType = TypeOps::prime_type(*domainType);
    }
    else if (theKind == wincond_in_var || theKind == wincond_out_var)
    {
      // TODO: we can be a little more specific here: if the quantifier of the
      // domain type is PLUS or ONE, then the quantifier of the "current" cond
      // var is ONE.
      derivedType = rtm.create_type(*domainType, TypeConstants::QUANT_QUESTION);
    }
    else if (theKind == non_groupby_var)
    {
      derivedType = rtm.create_type(*domainType, TypeConstants::QUANT_STAR);
    }
    else
    {
      derivedType = domainType;
    }
  }

  if (derivedType == NULL) 
  {
    return (theDeclaredType == NULL ? rtm.ITEM_TYPE_STAR : theDeclaredType);
  }

  return (theDeclaredType == NULL ?
          derivedType :
          TypeOps::intersect_type(*derivedType, *theDeclaredType));
}


};  // namespace zorba
