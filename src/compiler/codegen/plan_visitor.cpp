/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: plan_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "plan_visitor.h"
  
#include "compiler/expression/expr.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/flwor_iterator.h"
#include "util/tracer.h"
#include "functions/function.h"
#include "util/stl_extra.h"

#ifndef NDEBUG
#  include "zorba/util/properties.h"
#endif

#include <iostream>
#include <vector>


#ifndef NDEBUG
#define CODEGEN_TRACE(msg)                      \
  if (Properties::instance()->traceCodegen())   \
    std::cout << (msg) << TRACE << std::endl;
#define CODEGEN_TRACE_IN( msg )  \
  CODEGEN_TRACE (std::string (++depth, ' ') + msg)
#define CODEGEN_TRACE_OUT( msg ) \
  CODEGEN_TRACE (std::string (depth--, ' ') + msg)
#else
#define CODEGEN_TRACE(msg)
#define CODEGEN_TRACE_IN(msg)
#define CODEGEN_TRACE_OUT(msg)
#endif

using namespace std;
namespace xqp 
{

static uint32_t depth = 0;

#define ITEM_FACTORY (Store::getInstance().getItemFactory())

/*..........................................
 :  begin visit                            :
 :.........................................*/
bool plan_visitor::begin_visit(expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void plan_visitor::end_visit(expr& v)
{
  CODEGEN_TRACE_OUT("");
}


bool plan_visitor::begin_visit(var_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void plan_visitor::end_visit(var_expr& v)
{
  CODEGEN_TRACE_OUT("");

  switch (v.kind) {
  case var_expr::for_var: {
    var_iterator *v_p = new var_iterator(v.get_varname ()->getLocalName (),v.get_loc(), (void *) &v);
    vector<var_iter_t> *map = NULL;
    
    Assert (fvar_iter_map.get ((uint64_t) &v, map));
    map->push_back (v_p);
    itstack.push(v_p);
  }
    break;
  case var_expr::pos_var: {
    var_iterator *v_p = new var_iterator(v.get_varname ()->getLocalName (),v.get_loc(), (void *) &v);
    vector<var_iter_t> *map = NULL;
    Assert (pvar_iter_map.get ((uint64_t) &v, map));
    map->push_back (v_p);
    itstack.push(v_p);
  }
    break;
  case var_expr::let_var: {
    RefIterator *v_p = new RefIterator(v.get_varname ()->getLocalName (),v.get_loc(), (void *) &v);
    vector<ref_iter_t> *map = NULL;
    
    Assert (lvar_iter_map.get ((uint64_t) &v, map));
    map->push_back (v_p);
    itstack.push(v_p);
  }
    break;
  case var_expr::context_var:
    break;
  case var_expr::unknown_var:
    assert (false);
    break;
  default:
    assert (false);
    break;
  }
}

bool plan_visitor::begin_visit(order_modifier& v)
{
  CODEGEN_TRACE_IN("");
  // not implemented, but this is a performance, not a conformance issue
  return true;
}

void plan_visitor::end_visit(order_modifier& v)
{
  CODEGEN_TRACE_OUT("");
}

bool plan_visitor::begin_visit(flwor_expr& v)
{
  CODEGEN_TRACE_IN("");
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it) {
    rchandle<var_expr> vh = (*it)->var_h;
    uint64_t k = (uint64_t) &*vh;
    if (vh->kind == var_expr::for_var) {
      fvar_iter_map.put (k, new vector<var_iter_t>());
      var_expr *pos_vp = &*(*it)->get_pos_var ();
      if (pos_vp != NULL)
        pvar_iter_map.put ((uint64_t) pos_vp, new vector<var_iter_t>());
    } else if (vh->kind == var_expr::let_var)
      lvar_iter_map.put (k, new vector<ref_iter_t>());
  }
  return true;
}


void plan_visitor::end_visit(flwor_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t ret = pop_itstack ();

  vector<FLWORIterator::OrderSpec> orderSpecs;
  for (vector<flwor_expr::orderspec_t>::const_iterator i = v.orderspec_begin ();
       i != v.orderspec_end ();
       i++) {
    flwor_expr::orderspec_t spec = *i;
    orderSpecs.push_back (FLWORIterator::OrderSpec (pop_itstack (), spec.second->empty_mode, spec.second->dir == dir_descending));
  }
  FLWORIterator::OrderByClause *orderby = new FLWORIterator::OrderByClause (orderSpecs, v.get_order_stable ());

  PlanIter_t where = NULL;
  if (v.get_where () != NULL)
    where = pop_itstack ();

  vector<FLWORIterator::ForLetClause> clauses;
  stack<PlanIter_t> inputs;
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it)
    inputs.push (pop_itstack ());
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it) {
    PlanIter_t input = inputs.top (); inputs.pop ();
    if ((*it)->type == forlet_clause::for_clause) {
      vector<var_iter_t> *var_iters = NULL, *pvar_iters = NULL;
      Assert (fvar_iter_map.get ((uint64_t) & *(*it)->var_h, var_iters));
      var_expr *pos_vp = &* (*it)->get_pos_var ();
      if (pos_vp == NULL)
        clauses.push_back (FLWORIterator::ForLetClause (*var_iters, input));
      else {
        Assert (pvar_iter_map.get ((uint64_t) pos_vp, pvar_iters));
        clauses.push_back (FLWORIterator::ForLetClause (*var_iters, *pvar_iters, input));
      }
    } else if ((*it)->type == forlet_clause::let_clause) {
      vector<ref_iter_t> *var_iters = NULL;
      Assert (lvar_iter_map.get ((uint64_t) & *(*it)->var_h, var_iters));
      clauses.push_back (FLWORIterator::ForLetClause (*var_iters, input, true));
    }
  }
  FLWORIterator *iter =
    new FLWORIterator (v.get_loc (), clauses, where, orderby, ret, false);
  itstack.push (iter);
}


bool plan_visitor::begin_visit(case_clause& v)
{
  CODEGEN_TRACE_IN("");
  // TODO: Not implemented
  return true;
}


void plan_visitor::end_visit(case_clause& v)
{
  CODEGEN_TRACE_OUT("");
}

bool plan_visitor::begin_visit(promote_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void plan_visitor::end_visit(promote_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  // TODO: Currently we use cast. Promotion may be more efficient.
  itstack.push(new CastIterator(v.get_loc(), lChild, v.get_target_type()));
}

bool plan_visitor::begin_visit(typeswitch_expr& v)
{
  CODEGEN_TRACE_IN("");
  Assert (false);
  return true;
}


void plan_visitor::end_visit(typeswitch_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


bool plan_visitor::begin_visit(if_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void plan_visitor::end_visit(if_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t iterElse = pop_itstack();
  PlanIter_t iterThen = pop_itstack();
  PlanIter_t iterCond = pop_itstack();
  PlanIter_t iterIfThenElse = new IfThenElseIterator(v.get_loc(), iterCond, iterThen, iterElse);
  itstack.push(&*iterIfThenElse);
}


bool plan_visitor::begin_visit(fo_expr& v)
{
  CODEGEN_TRACE_IN ("");

  // If the function is an enclosed expression and we are in the context of
  // a node constructor, push a NULL in the constructors stack to "hide" the
  // current constructor context (so that a new constructor context can be
  // started if a node constructor exists inside the enclosed expr).
  //xqp_string fname = v.get_func()->get_fname()->getLocalName();
  if (!theConstructorsStack.empty() &&
      v.get_func()->get_fname()->getLocalName() == ":enclosed-expr")
  {
    theConstructorsStack.push(NULL);
  }

	return true;
}


void plan_visitor::end_visit(fo_expr& v) 
{
  CODEGEN_TRACE_OUT("");

  const function* func = v.get_func();
  Assert (func != NULL);

  vector<PlanIter_t> argv (v.size ());
  generate (argv.rbegin (), argv.rend (), stack_to_generator (itstack));

  const yy::location& loc = v.get_loc ();

  if (func->validate_args (argv)) {
    PlanIter_t iter = (*func) (loc, argv);
    Assert (iter != NULL);
    itstack.push (iter);

    if (!theConstructorsStack.empty() &&
        dynamic_cast<EnclosedIterator*>(iter.get_ptr()) != NULL)
    {
      Assert(theConstructorsStack.top() == NULL);
      theConstructorsStack.pop();
    }
  } else {
    ZORBA_ERROR_ALERT_OSS (error_messages::XPST0017,
                           &loc, false, func->get_signature ().get_name ()->getStringProperty (), argv.size ());
  }
}


bool plan_visitor::begin_visit(ft_select_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool plan_visitor::begin_visit(ft_contains_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool plan_visitor::begin_visit(instanceof_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void plan_visitor::end_visit(instanceof_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t p = pop_itstack ();
  itstack.push (new InstanceOfIterator (v.get_loc (), p, v.get_type ()));
}

bool plan_visitor::begin_visit(treat_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool plan_visitor::begin_visit(castable_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool plan_visitor::begin_visit(cast_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void plan_visitor::end_visit(cast_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  itstack.push(new CastIterator(v.get_loc(), lChild, v.get_type()));
}

bool plan_visitor::begin_visit(validate_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool plan_visitor::begin_visit(extension_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


/*******************************************************************************

********************************************************************************/
bool plan_visitor::begin_visit(relpath_expr& v)
{
  CODEGEN_TRACE_IN("");
  // Done in axis itself
  return true;
}


void plan_visitor::end_visit(relpath_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool plan_visitor::begin_visit(axis_step_expr& v)
{
  CODEGEN_TRACE_IN("");

  bool result = true;

  PlanIter_t input = pop_itstack();

  // TODO ??? In this case the input should be the context node
  if (input == NULL)
  {
    input = new var_iterator("context_node", v.get_loc(), &v);
  }

  PlanIter_t axisIte;

  switch (v.getAxis())
  {
  case axis_kind_self:
  {
    axisIte = new SelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_child:
  {
    axisIte = new ChildAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_parent:
  {
    axisIte = new ParentAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_descendant:
  {
    axisIte = new DescendantAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_descendant_or_self:
  {
    axisIte = new DescendantSelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_ancestor:
  {
    axisIte = new AncestorAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_ancestor_or_self:
  {
    axisIte = new AncestorSelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_following_sibling:
  {
    axisIte = new RSiblingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_following:
  {
    axisIte = new FollowingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_preceding_sibling:
  {
    axisIte = new LSiblingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_preceding:
  {
    axisIte = new PrecedingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_attribute:
  {
    if (v.getTest()->getTestKind() == match_name_test ||
        v.getTest()->getTestKind() == match_attr_test ||
        v.getTest()->getTestKind() == match_xs_attr_test ||
        v.getTest()->getTestKind() == match_anykind_test)
    {
      axisIte = new AttributeAxisIterator(v.get_loc(), input);
    }
    else
    {
      axisIte = new EmptyIterator(v.get_loc());
      result = false;
    }

    break;
  }
  default:
  {
    ZORBA_ERROR_ALERT(
       error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
       NULL,
       false,
       "Unknown axis kind");
    break;
  }
  }

  itstack.push(axisIte);

  return result;
}


void plan_visitor::end_visit(axis_step_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool plan_visitor::begin_visit(match_expr& v)
{
  CODEGEN_TRACE_IN ("");

  PlanIter_t axisIte = pop_itstack();
  AxisIteratorHelper* axisItep = dynamic_cast<AxisIteratorHelper*>(&*axisIte);
  Assert(axisItep != NULL);

  PlanIter_t matchIte;
  QNameItem_t qname;
  QNameItem_t tname;

  ItemFactory& iFactory = Store::getInstance().getItemFactory();

  if (v.getTestKind() == match_name_test)
  {
    // Note: the attribute axis iterator does not do any filtering based on
    // the node kind, so it is ok to set the principal node kind to elementNode
    // in all cases.
    axisItep->setNodeKind(StoreConsts::elementNode);

    match_wild_t wildKind = v.getWildKind();

    if (wildKind == match_no_wild)
    {
      qname = iFactory.createQName("",
                                   v.getQName()->getPrefix ().c_str(),
                                   v.getQName()->getLocalName ().c_str());

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else if (wildKind == match_prefix_wild)
    {
      qname = iFactory.createQName("", "wildcard", v.getWildName().c_str());

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else if (wildKind == match_name_wild)
    {
      qname = iFactory.createQName("", v.getWildName().c_str(), "wildcard");

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else
    {
      matchIte = axisIte;
    }
  }
  else
  {
    axisItep->setNodeKind(v.getNodeKind());

    if (v.getQName() != NULL)
    {
      qname = iFactory.createQName("",
                                   v.getQName()->getPrefix ().c_str(),
                                   v.getQName()->getLocalName ().c_str());
    }

    if (v.getTypeName() != NULL)
    {
      tname = iFactory.createQName("",
                                   v.getTypeName()->getPrefix ().c_str(),
                                   v.getTypeName()->getLocalName ().c_str());
    }

    matchIte = new KindTestIterator(v.get_loc(), axisIte, qname, tname,
                                    v.getTestKind(), v.getDocTestKind(),
                                    v.getNilledAllowed());
  }

  itstack.push(matchIte);

  return true;
}


void plan_visitor::end_visit(match_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

  Node Constructors

********************************************************************************/

bool plan_visitor::begin_visit(doc_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void plan_visitor::end_visit(doc_expr& v)
{
  CODEGEN_TRACE_OUT("");
  
  PlanIter_t lContent = pop_itstack();
  PlanIter_t lContIter = new DocumentContentIterator(v.get_loc(), lContent);
  PlanIter_t lDocIter = new DocumentIterator(v.get_loc(), lContIter);
  itstack.push(lDocIter);
}


bool plan_visitor::begin_visit(elem_expr& v)
{
  CODEGEN_TRACE_IN ("");

  // Start a new construction context, if we are not in such a context already.
  if (theConstructorsStack.empty() || theConstructorsStack.top() == NULL)
    theConstructorsStack.push(&v);

	return true;
}


void plan_visitor::end_visit ( elem_expr& v )
{
  CODEGEN_TRACE_OUT ("");

  PlanIter_t lQNameIter = 0;
  PlanIter_t lContentIter = 0;
  PlanIter_t lAttrsIter = 0;

  ItemFactory& iFactory = Store::getInstance().getItemFactory();

  if ( v.getContent() != 0 )
  {
    lContentIter = pop_itstack();
    lContentIter = new ElementContentIterator ( v.get_loc(), lContentIter );
  }

  if ( v.getAttrs() != 0 )
    lAttrsIter = pop_itstack();

  lQNameIter = pop_itstack();

  bool assignId = false;
  Assert(!theConstructorsStack.empty());
  if (theConstructorsStack.top() == &v)
  {
    theConstructorsStack.pop();
    assignId = true;
  }

	PlanIter_t iter = new ElementIterator(v.get_loc(),
                                        lQNameIter,
                                        lAttrsIter,
                                        lContentIter,
                                        assignId);
  itstack.push ( iter );
}


bool plan_visitor::begin_visit(attr_expr& v)
{
  CODEGEN_TRACE_IN("");

  // Start a new construction context, if we are not in such a context already.
  if (theConstructorsStack.empty() || theConstructorsStack.top() == NULL)
    theConstructorsStack.push(&v);

	return true;
}


void plan_visitor::end_visit(attr_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t lQNameIter = 0;
  PlanIter_t lVarIter = 0;
  PlanIter_t lContentIter = 0;
  
  ItemFactory& iFactory = Store::getInstance().getItemFactory();

  if (v.getValueExpr() != 0) {
    lVarIter = pop_itstack();
  }
  else
  {
    lVarIter = new EmptyIterator(v.get_loc());
  }
  
  PlanIter_t lAttrIter = 0;
  lQNameIter = pop_itstack();
  
  bool assignId = false;
  Assert(!theConstructorsStack.empty());
  if (theConstructorsStack.top() == &v)
  {
    theConstructorsStack.pop();
    assignId = true;
  }

  lAttrIter = new AttributeIterator(v.get_loc(), lQNameIter, lVarIter, assignId);
  
  itstack.push(lAttrIter);
}


bool plan_visitor::begin_visit(text_expr& v)
{
  CODEGEN_TRACE_IN ("");

  // Start a new construction context, if we are not in such a context already.
  if (theConstructorsStack.empty() || theConstructorsStack.top() == NULL)
    theConstructorsStack.push(&v);

	return true;
}


void plan_visitor::end_visit(text_expr& v)
{
  CODEGEN_TRACE_OUT ("");

  PlanIter_t content = pop_itstack ();

  bool assignId = false;
  Assert(!theConstructorsStack.empty());
  if (theConstructorsStack.top() == &v)
  {
    theConstructorsStack.pop();
    assignId = true;
  }

  switch (v.get_type ()) {
  case text_expr::text_constructor:
//     // assume this comes from a direct text constructor for now
//     // we can't afford to break direct text construction
//     {
//       xqpString text = v.get_text ().cast<const_expr> ()->get_val ()->getStringValue ();
//       itstack.push (new SingletonIterator (v.get_loc (), ITEM_FACTORY.createTextNode (text)));
//     }
    itstack.push (new TextIterator(v.get_loc(), content, assignId));
    break;

  case text_expr::comment_constructor:
    itstack.push (new CommentIterator (v.get_loc(), content, assignId));
    break;

  default:
    break;
  }
}


bool plan_visitor::begin_visit(pi_expr& v)
{
  CODEGEN_TRACE_IN("");
  Assert (false);
  return true;
}


void plan_visitor::end_visit(pi_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************


********************************************************************************/

bool plan_visitor::begin_visit(const_expr& v)
{
  CODEGEN_TRACE_IN ("");
  return true;
}

bool plan_visitor::begin_visit(order_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


/*..........................................
 :  end visit                              :
 :.........................................*/

void plan_visitor::end_visit(ft_select_expr& v)
{
  CODEGEN_TRACE_OUT("");
}

void plan_visitor::end_visit(ft_contains_expr& v)
{
  CODEGEN_TRACE_OUT("");
}

void plan_visitor::end_visit(treat_expr& v)
{
  CODEGEN_TRACE_OUT("");
}

void plan_visitor::end_visit(castable_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  itstack.push(new CastableIterator(v.get_loc(), lChild, v.get_type()));
}

void plan_visitor::end_visit(validate_expr& v)
{
  CODEGEN_TRACE_OUT("");
}

void plan_visitor::end_visit(extension_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


void plan_visitor::end_visit(const_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t it = new SingletonIterator (v.get_loc (), v.get_val ());
  itstack.push (it);
}

void plan_visitor::end_visit(order_expr& v)
{
  CODEGEN_TRACE_OUT("");
}



} /* namespace xqp */
