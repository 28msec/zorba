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
namespace zorba {

#define DEBUG_RT(e, t) t

#ifndef DEBUG_RT
#define DEBUG_RT(e, t) print_expr_and_type(e, t)

static xqtref_t print_expr_and_type(expr *e, xqtref_t t) {
  if (Properties::instance()->printStaticTypes ()) {
    std::cout << "Return type for " << e << ":\n";
    e->put(std::cout);
    std::cout << " => " << t->toString() << std::endl;
  }
  return t;
}

#endif

xqtref_t expr::return_type(static_context *sctx) 
{
  if (! cache_compliant ())
    return DEBUG_RT(this, return_type_impl (sctx));

  if (! cache.type.valid ||
      (cache.type.sctx != sctx &&
       ! TypeOps::is_subtype (*cache.type.t, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE)))
  {
    cache.type.t = DEBUG_RT (this, return_type_impl (sctx));
    cache.type.sctx = sctx;
    cache.type.valid = true;
  }
  return cache.type.t;
}


xqtref_t expr::return_type_impl(static_context *sctx)
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


xqtref_t const_expr::return_type_impl(static_context *sctx)
{
  xqtref_t type = sctx->get_typemanager()->
    create_named_type(val->getType(), TypeConstants::QUANT_ONE);
  return type;
}


xqtref_t fo_expr::return_type_impl(static_context *sctx)
{
  vector<xqtref_t> types;
  for (vector<expr_t>::iterator i = begin (); i != end (); i++)
    types.push_back ((*i)->return_type (sctx));
  return func->return_type (types);
}


xqtref_t sequential_expr::return_type_impl(static_context *sctx)
{
  return sequence [sequence.size () - 1]->return_type (sctx);
}


xqtref_t flwor_expr::return_type_impl(static_context *sctx) 
{
  // TODO: quant multiplication
  return sctx->get_typemanager()->create_type(*theReturnExpr->return_type(sctx),
                                              TypeConstants::QUANT_STAR);
}


xqtref_t if_expr::return_type_impl (static_context *sctx) 
{
  return TypeOps::union_type (*then_expr_h->return_type (sctx), *else_expr_h->return_type (sctx));
}


xqtref_t treat_expr::return_type_impl (static_context *sctx) 
{
  xqtref_t input_type = get_input ()->return_type (sctx);
  xqtref_t input_ptype = TypeOps::prime_type (*input_type),
    target_ptype = TypeOps::prime_type (*target_type);
  if (TypeOps::is_subtype (*input_ptype, *target_ptype)) {
    TypeConstants::quantifier_t q =
      TypeOps::intersect_quant (TypeOps::quantifier (*input_type),
                                TypeOps::quantifier (*target_type));
    return sctx->get_typemanager ()->create_type_x_quant (*input_ptype, q);
  }
  return target_type;
}



static xqtref_t axist_step_type(
    static_context* sctx,
    const axis_step_expr* axisStep,
    const NodeXQType* inputType)
{
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


#define returnTypeU(nodekind, nodename, untyped)                        \
  if (untyped && nodekind == store::StoreConsts::attributeNode)         \
  {                                                                     \
    return tm->create_node_type(nodekind,                               \
                                nodename,                               \
                                RTM.UNTYPED_ATOMIC_TYPE_ONE,            \
                                TypeConstants::QUANT_STAR,              \
                                false,                                  \
                                false);                                 \
  }                                                                     \
  else if (untyped)                                                     \
  {                                                                     \
    return tm->create_node_type(nodekind,                               \
                                nodename,                               \
                                RTM.UNTYPED_TYPE,                       \
                                TypeConstants::QUANT_STAR,              \
                                false,                                  \
                                false);                                 \
  }                                                                     \
  else                                                                  \
  {                                                                     \
    return tm->create_node_type(nodekind,                               \
                                nodename,                               \
                                RTM.ANY_TYPE,                           \
                                TypeConstants::QUANT_STAR,              \
                                false,                                  \
                                false);                                 \
  }


#define returnType(nodekind, nodename, quant, untyped)                  \
  if (untyped)                                                          \
  {                                                                     \
    xqtref_t contentType;                                               \
    if (nodekind == store::StoreConsts::attributeNode)                  \
      contentType = RTM.UNTYPED_ATOMIC_TYPE_ONE;                        \
    else                                                                \
      contentType = RTM.UNTYPED_TYPE;                                   \
                                                                        \
    if (TypeOps::is_sub_quant(quant, TypeConstants::QUANT_QUESTION))    \
    {                                                                   \
      return tm->create_node_type(nodekind,                             \
                                  nodename,                             \
                                  contentType,                          \
                                  TypeConstants::QUANT_QUESTION,        \
                                  false,                                \
                                  false);                               \
    }                                                                   \
    else                                                                \
    {                                                                   \
      return tm->create_node_type(nodekind,                             \
                                  nodename,                             \
                                  contentType,                          \
                                  TypeConstants::QUANT_STAR,            \
                                  false,                                \
                                  false);                               \
    }                                                                   \
  }                                                                     \
  else if (TypeOps::is_sub_quant(quant, TypeConstants::QUANT_QUESTION)) \
  {                                                                     \
    return tm->create_node_type(nodekind,                               \
                                nodename,                               \
                                RTM.ANY_TYPE,                           \
                                TypeConstants::QUANT_QUESTION,          \
                                false,                                  \
                                false);                                 \
  }                                                                     \
  else                                                                  \
  {                                                                     \
    return tm->create_node_type(nodekind,                               \
                                nodename,                               \
                                RTM.ANY_TYPE,                           \
                                TypeConstants::QUANT_STAR,              \
                                false,                                  \
                                false);                                 \
  }


#define RAISE_XPST0005()                            \
  {                                                 \
    ZORBA_ERROR_LOC(XPST0005, loc);                 \
    return RTM.EMPTY_TYPE;                          \
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

    returnType(testNodeKind, testNodeName, inQuant, false);

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
      returnType(testNodeKind, testNodeName, inQuant, false);
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
      returnType(testNodeKind, testNodeName, inQuant, false);
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
      returnType(inNodeKind, testNodeName, inQuant, inUntyped);

    case store::StoreConsts::textNode:
    case store::StoreConsts::piNode:
    case store::StoreConsts::commentNode:
      returnType(inNodeKind, testNodeName, inQuant, false);

    case store::StoreConsts::anyNode:
    {
      switch (testNodeKind)
      {
      case store::StoreConsts::anyNode:
      case store::StoreConsts::documentNode:
      case store::StoreConsts::elementNode:
      case store::StoreConsts::attributeNode:
        returnType(testNodeKind, testNodeName, inQuant, inUntyped);

      case store::StoreConsts::textNode:
      case store::StoreConsts::piNode:
      case store::StoreConsts::commentNode:
        returnType(testNodeKind, testNodeName, inQuant, false);

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
      returnTypeU(testNodeKind, testNodeName, inUntyped);

    case store::StoreConsts::elementNode:
      returnTypeU(testNodeKind, testNodeName, inUntyped);

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
      returnTypeU(testNodeKind, testNodeName, inUntyped);

    case store::StoreConsts::elementNode:
      returnTypeU(testNodeKind, testNodeName, inUntyped);

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
      returnType(store::StoreConsts::attributeNode, testNodeName, inQuant, inUntyped);
    }
    else
    {
      returnTypeU(store::StoreConsts::attributeNode, testNodeName, inUntyped);
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


xqtref_t relpath_expr::return_type_impl(static_context* sctx) 
{
  if (size() == 0)
    return GENV_TYPESYSTEM.EMPTY_TYPE;

  if (size() == 1)
    return theSteps[0]->return_type(sctx);

  xqtref_t sourceType = theSteps[0]->return_type(sctx);

  if (TypeOps::is_empty (*sourceType))
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

  
xqtref_t elem_expr::return_type_impl (static_context *sctx) 
{
  xqtref_t typeName =
           (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
            GENV_TYPESYSTEM.ANY_TYPE : 
            GENV_TYPESYSTEM.UNTYPED_TYPE);

  return sctx->get_typemanager()->
         create_node_type(store::StoreConsts::elementNode,
                          NULL,
                          typeName,
                          TypeConstants::QUANT_ONE,
                          false,
                          false);
}


xqtref_t doc_expr::return_type_impl (static_context *sctx) 
{
  return sctx->get_typemanager()->
         create_node_type(store::StoreConsts::documentNode,
                          NULL,
                          theContent == NULL ? NULL : theContent->return_type(sctx),
                          TypeConstants::QUANT_ONE,
                          false,
                          false);
}


xqtref_t attr_expr::return_type_impl (static_context *sctx) 
{
  return sctx->get_typemanager()->
         create_node_type(store::StoreConsts::attributeNode,
                          NULL,
                          theValueExpr == NULL ? NULL : theValueExpr->return_type(sctx),
                          TypeConstants::QUANT_ONE,
                          false,
                          false);
}

 
xqtref_t text_expr::return_type_impl (static_context *sctx) 
{
  store::StoreConsts::NodeKind nodeKind;

  TypeConstants::quantifier_t q = TypeConstants::QUANT_ONE;

  switch (type) 
  {
    case text_constructor: 
    {
      xqtref_t t = get_text()->return_type(sctx);

      if (TypeOps::is_empty (*t))
        return t;

      else if (TypeOps::type_min_cnt (*t) == 0)
        q = TypeConstants::QUANT_QUESTION;

      nodeKind = store::StoreConsts::textNode;
      break;
    }

  case comment_constructor:
    nodeKind = store::StoreConsts::commentNode;
    break;

  case pi_constructor:
    nodeKind = store::StoreConsts::piNode;
    break;

  default:
    ZORBA_ASSERT (false);
    break;
  }

  return sctx->get_typemanager()->create_node_type(nodeKind,
                                                   NULL,
                                                   NULL,
                                                   q,
                                                   false,
                                                   false);
}


xqtref_t castable_base_expr::return_type_impl (static_context *sctx) 
{
  return sctx->get_typemanager()->
         create_builtin_atomic_type(TypeConstants::XS_BOOLEAN,
                                    TypeConstants::QUANT_ONE);
}

  
xqtref_t cast_base_expr::return_type_impl (static_context *sctx) 
{
  TypeConstants::quantifier_t q =
    TypeOps::intersect_quant(TypeOps::quantifier(*get_input()->return_type(sctx)),
                             TypeOps::quantifier(*target_type));
  return sctx->get_typemanager()->create_type(*target_type, q);
}

  
xqtref_t promote_expr::return_type_impl (static_context *sctx) 
{
  TypeManager *tm = sctx->get_typemanager();
  xqtref_t in_type = input_expr_h->return_type(sctx),
    in_ptype = TypeOps::prime_type (*in_type),
    target_ptype = TypeOps::prime_type (*target_type);
  TypeConstants::quantifier_t q =
    TypeOps::intersect_quant (TypeOps::quantifier (*in_type),
                              TypeOps::quantifier (*target_type));
  if (TypeOps::is_subtype(*in_ptype, *target_ptype))
    return tm->create_type_x_quant (*in_ptype, q);

  // be liberal
  return tm->create_type_x_quant (*target_ptype, q);

#if 0
  RootTypeManager& ts = GENV_TYPESYSTEM;
  // TODO: for nodes, the result would be none
  if (TypeOps::is_equal (*in_ptype, *ts.UNTYPED_ATOMIC_TYPE_ONE))
    return tm->create_type_x_quant (*target_ptype, q);
  
  // decimal --> float
  if (TypeOps::is_subtype(*target_ptype, *ts.FLOAT_TYPE_ONE)) {
    if (TypeOps::is_subtype(*in_ptype, *ts.DECIMAL_TYPE_ONE))
      return tm->create_type_x_quant (*target_ptype, q);
  }
  
  // decimal/float --> double
  if (TypeOps::is_subtype(*target_ptype, *ts.DOUBLE_TYPE_ONE)) {
    if (TypeOps::is_subtype(*in_ptype, *ts.DECIMAL_TYPE_ONE)
        || TypeOps::is_subtype(*in_ptype, *ts.FLOAT_TYPE_ONE))
      return tm->create_type_x_quant (*target_ptype, q);
  }
  
  // uri --> string
  if (TypeOps::is_subtype(*target_ptype, *ts.STRING_TYPE_ONE)) {
    if (TypeOps::is_subtype(*in_ptype, *ts.ANY_URI_TYPE_ONE))
      return tm->create_type_x_quant (*target_ptype, q);
  }
#endif
}


xqtref_t order_expr::return_type_impl(static_context *sctx) 
{
  return expr_h->return_type (sctx); 
}
  

xqtref_t wrapper_expr::return_type_impl(static_context *sctx) 
{
  return wrapped->return_type(sctx);
}


xqtref_t var_expr::return_type_impl(static_context* sctx) 
{
  xqtref_t type1 = NULL;
  expr* domainExpr;

  if (theKind == for_var || theKind == let_var ||
      theKind == win_var || theKind == copy_var) 
  {
    domainExpr = get_domain_expr();
    assert(domainExpr != NULL);

    type1 = domainExpr->return_type(sctx);

    if (theKind == for_var) 
    {
      type1 = TypeOps::prime_type(*type1);
    }
  }

  // The translator has already set the type of pos_vars, count_vars,
  // wincond_out_pos_vars, and wincond_in_pos_vars to xs:positiveInteger.

  if (type1 == NULL) 
  {
    return theDeclaredType == NULL ? GENV_TYPESYSTEM.ITEM_TYPE_STAR : theDeclaredType;
  }

  return (theDeclaredType == NULL ?
          type1 :
          TypeOps::intersect_type(*type1, *theDeclaredType));
}


bool castable_expr::is_optional() const 
{
  return TypeOps::quantifier(*target_type) == TypeConstants::QUANT_QUESTION; 
}


bool cast_expr::is_optional() const 
{
  return TypeOps::quantifier(*target_type) == TypeConstants::QUANT_QUESTION; 
}


};  // namespace zorba
