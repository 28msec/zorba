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

  xqtref_t expr::return_type(static_context *sctx) {
    if (! cache_compliant ())
      return DEBUG_RT(this, return_type_impl (sctx));
    if (! cache.type.valid
        || (cache.type.sctx != sctx && ! TypeOps::is_subtype (*cache.type.t, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE)))
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


  xqtref_t if_expr::return_type_impl (static_context *sctx) {
    return TypeOps::union_type (*then_expr_h->return_type (sctx), *else_expr_h->return_type (sctx));
  }

  xqtref_t fo_expr::return_type_impl(static_context *sctx)
  {
    vector<xqtref_t> types;
    for (vector<expr_t>::iterator i = begin (); i != end (); i++)
      types.push_back ((*i)->return_type (sctx));
    return func->return_type (types);
  }

  xqtref_t treat_expr::return_type_impl (static_context *sctx) {
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

xqtref_t relpath_expr::return_type_impl(static_context *sctx) {
  if (size () == 0)
    return GENV_TYPESYSTEM.EMPTY_TYPE;
  if (size () == 1)
    return theSteps [0]->return_type(sctx);

  for (unsigned i = 1; i < size (); i++) {
    switch (theSteps [i].cast<axis_step_expr> ()->getAxis ()) {
    case axis_kind_self:
    case axis_kind_descendant:
    case axis_kind_descendant_or_self:
    case axis_kind_child:
    case axis_kind_attribute:
      break;
    default:
      return GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR;
    }
  }
  xqtref_t base_xqt = TypeOps::prime_type (*theSteps [0]->return_type(sctx));
  if (base_xqt->type_kind () != XQType::NODE_TYPE_KIND)
    return GENV_TYPESYSTEM.NONE_TYPE;
  base_xqt = static_cast<const NodeXQType &> (*base_xqt).get_content_type ();
  if (base_xqt != NULL && base_xqt->type_kind () == XQType::UNTYPED_KIND)
    return GENV_TYPESYSTEM.ANY_NODE_UNTYPED_CONT_TYPE_STAR;
  return GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR;
}

  xqtref_t axis_step_expr::return_type_impl(static_context *sctx) {
    return theNodeTest == NULL ? GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE : theNodeTest->return_type (sctx);
  }

  xqtref_t match_expr::return_type_impl(static_context *sctx) {
    return GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE;
  }

  xqtref_t const_expr::return_type_impl(static_context *sctx)
  {
    xqtref_t type = sctx->get_typemanager()->
      create_named_type(val->getType(), TypeConstants::QUANT_ONE);
    return type;
  }

  xqtref_t elem_expr::return_type_impl (static_context *sctx) {
    return
      sctx->get_typemanager ()->create_node_type (NodeTest::ELEMENT_TEST, theContent == NULL ? NULL : theContent->return_type (sctx), TypeConstants::QUANT_ONE, false);
  }

  xqtref_t doc_expr::return_type_impl (static_context *sctx) {
    return sctx->get_typemanager ()->create_node_type (NodeTest::DOCUMENT_TEST, theContent == NULL ? NULL : theContent->return_type (sctx), TypeConstants::QUANT_ONE, false);
  }

  xqtref_t attr_expr::return_type_impl (static_context *sctx) {
    return sctx->get_typemanager ()->create_node_type (NodeTest::ATTRIBUTE_TEST, theValueExpr == NULL ? NULL : theValueExpr->return_type (sctx), TypeConstants::QUANT_ONE, false);
  }

  xqtref_t text_expr::return_type_impl (static_context *sctx) {
    rchandle<NodeTest> nt;
    TypeConstants::quantifier_t q = TypeConstants::QUANT_ONE;
    switch (type) {
    case text_constructor: {
      xqtref_t t  = get_text ()->return_type (sctx);
      if (TypeOps::is_empty (*t))
        return t;
      else if (TypeOps::type_min_cnt (*t) == 0)
        q = TypeConstants::QUANT_QUESTION;
      nt = NodeTest::TEXT_TEST;
      break;
    }
    case comment_constructor: nt = NodeTest::COMMENT_TEST; break;
    case pi_constructor: nt = NodeTest::PI_TEST; break;
    default: ZORBA_ASSERT (false); break;
    }
    return sctx->get_typemanager ()->create_node_type (nt, text == NULL ? NULL : text->return_type (sctx), q, false);
  }

  xqtref_t castable_base_expr::return_type_impl (static_context *sctx) {
    return sctx->get_typemanager ()->create_atomic_type (TypeConstants::XS_BOOLEAN, TypeConstants::QUANT_ONE);
  }
  
  xqtref_t cast_base_expr::return_type_impl (static_context *sctx) {
    TypeConstants::quantifier_t q =
      TypeOps::intersect_quant (TypeOps::quantifier (*get_input ()->return_type (sctx)),
                                TypeOps::quantifier (*target_type));
    return sctx->get_typemanager ()->create_type_x_quant (*target_type, q);
  }
  
  xqtref_t promote_expr::return_type_impl (static_context *sctx) {
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
  
  xqtref_t order_expr::return_type_impl(static_context *sctx) { return expr_h->return_type (sctx); }
  

xqtref_t wrapper_expr::return_type_impl(static_context *sctx) {
  return wrapped->return_type(sctx);
}


xqtref_t var_expr::return_type_impl(static_context* sctx) 
{
  xqtref_t type1 = NULL;
  if (kind == for_var || kind == let_var || kind == win_var) 
  {
    assert (theFlworClause != NULL);

    type1 = reinterpret_cast<forletwin_clause*>(get_flwor_clause())->
            get_expr()->return_type(sctx);

    if (kind == for_var) 
    {
      type1 = TypeOps::prime_type(*type1);
    }
  }

  if (type1 == NULL) 
  {
    return type == NULL ? GENV_TYPESYSTEM.ITEM_TYPE_STAR : type;
  }

  return type == NULL ? type1 : TypeOps::intersect_type(*type1, *type);
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
