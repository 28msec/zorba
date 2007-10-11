/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: plan_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "plan_visitor.h"
 	
#include "compiler/expression/expr.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/item_iterator.h"
#include "runtime/paths/path_iterators.h"
#include "util/tracer.h"
#include "functions/function.h"

#include <iostream>
#include <vector>


using namespace std;
namespace xqp 
{

static uint32_t depth = 0;

/*..........................................
 :  begin visit                            :
 :.........................................*/
bool plan_visitor::begin_visit(const expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const expr& v)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
}


bool plan_visitor::begin_visit(const enclosed_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const enclosed_expr& v)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
	Iterator_t content = pop_itstack();
	Iterator_t enclosed = new EnclosedIterator(v.get_loc(), content);
	itstack.push(&*enclosed);
}


bool plan_visitor::begin_visit(const expr_list& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	itstack.push(NULL);
	return true;
}


void plan_visitor::end_visit(const expr_list& v)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
	vector<Iterator_t> argv;
	while (true) {
		Iterator_t it = pop_itstack();
		if (it==NULL) break;
		argv.insert(argv.begin(),it);
	}
	rchandle<ConcatIterator> cit_h = new ConcatIterator(v.get_loc(), argv);
	itstack.push(&*cit_h);
}


bool plan_visitor::begin_visit(const var_expr& v)
{
  cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const order_modifier& v)
{
  cout << TRACE << endl;
	return true;
}


bool plan_visitor::begin_visit(const flwor_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const flwor_expr& v)
{
  cout << TRACE << endl;
	Iterator_t expr = pop_itstack();
	Iterator_t input = pop_itstack();
	std::vector<var_iter_t> var_iters;
	
// 	while (true) {
	
		var_iter_t var = timstack.top(); timstack.pop();
// 		if (var==NULL) break;
		var_iters.push_back(&*var);
// 	}
	rchandle<MapIterator> map_iter = new MapIterator(v.get_loc(),input, expr, var_iters);
	itstack.push(&*map_iter);
// 	rchandle<map_iterator> m_h = new map_iterator();
}


bool plan_visitor::begin_visit(const quantified_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const quantified_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(const case_clause& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const case_clause& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(const typeswitch_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const typeswitch_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(const if_expr& v)
{
cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const if_expr& v)
{
  cout << TRACE << endl;
	Iterator_t iterElse = pop_itstack();
	Iterator_t iterThen = pop_itstack();
	Iterator_t iterCond = pop_itstack();
	Iterator_t iterIfThenElse = new IfThenElseIterator(v.get_loc(), iterCond, iterThen, iterElse);
	itstack.push(&*iterIfThenElse);
}


bool plan_visitor::begin_visit(const fo_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	itstack.push(NULL);
	return true;
}


void plan_visitor::end_visit(const fo_expr& v)
{
  cout << std::string(depth--, ' ') << TRACE << endl;

	const function* func_p = v.get_func();
	assert(func_p != NULL);
	const function& func = *func_p;

	vector<Iterator_t> argv;
	while (true)
  {
		Iterator_t it_h = pop_itstack();
		if (it_h == NULL)
      break;

		vector<Iterator_t>::iterator begin = argv.begin();
 		argv.insert(begin, 1, it_h );
	}

	itstack.push(func(v.get_loc(), argv));
}


bool plan_visitor::begin_visit(const ft_select_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const ft_contains_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const instanceof_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const treat_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const castable_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const cast_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const unary_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const validate_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const extension_expr& v)
{
cout << TRACE << endl;
	return true;
}


/*******************************************************************************


********************************************************************************/
bool plan_visitor::begin_visit(const relpath_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const relpath_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(const axis_step_expr& v)
{
  cout << TRACE << endl;

  bool result = true;

  Iterator_t input = pop_itstack();

  // TODO ??? In this case the input should be the context node
  if (input == NULL)
  {
    input = new var_iterator("context_node", v.get_loc());
  }

  Iterator_t axisIte;

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
    ZorbaErrorAlerts::error_alert(
       error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
       error_messages::SYSTEM_ERROR,
       NULL,
       false,
       "Unknown axis kind");
    break;
  }
  }

  itstack.push(axisIte);

  return result;
}


void plan_visitor::end_visit(const axis_step_expr& v)
{
  cout << TRACE << endl;
}


/*******************************************************************************


********************************************************************************/
bool plan_visitor::begin_visit(const match_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;

  Iterator_t axisIte = pop_itstack();
  AxisIteratorHelper* axisItep = dynamic_cast<AxisIteratorHelper*>(&*axisIte);
  Assert(axisItep != NULL);

  Iterator_t matchIte;
  Item_t qname;
  Item_t tname;

  if (v.getTestKind() == match_name_test)
  {
    // Note: the attribute axis iterator does not do any filtering based on
    // the node kind, so it is ok to set the principal node kind to elementNode
    // in all cases.
    axisItep->setNodeKind(elementNode);

    match_wild_t wildKind = v.getWildKind();

    if (wildKind == match_no_wild)
    {
      qname = zorba::getZorbaForCurrentThread()->getItemFactory()->
              createQName("", v.getQName()->prefix(), v.getQName()->local());

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else if (wildKind == match_prefix_wild)
    {
      qname = zorba::getZorbaForCurrentThread()->getItemFactory()->
              createQName("", "wildcard", v.getWildName());

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else if (wildKind == match_name_wild)
    {
      qname = zorba::getZorbaForCurrentThread()->getItemFactory()->
              createQName("", v.getWildName(), "wildcard");

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
      qname = zorba::getZorbaForCurrentThread()->getItemFactory()->
              createQName("", v.getQName()->prefix(), v.getQName()->local());
    }

    if (v.getTypeName() != NULL)
    {
      tname = zorba::getZorbaForCurrentThread()->getItemFactory()->
              createQName("", v.getTypeName()->prefix(), v.getTypeName()->local());
    }

    matchIte = new KindTestIterator(v.get_loc(), axisIte, qname, tname,
                                    v.getTestKind(), v.getNilledAllowed());
  }

  itstack.push(matchIte);

	return true;
}


void plan_visitor::end_visit(const match_expr& v)
{
  cout << TRACE << endl;
}


/*******************************************************************************


********************************************************************************/
bool plan_visitor::begin_visit(const doc_expr& v)
{
  cout << TRACE  << endl;
	return true;
}


void plan_visitor::end_visit(const doc_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(const elem_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const elem_expr& v)
{
  cout << std::string(--depth, ' ') << TRACE << endl;
	Iterator_t contentIter = NULL;
	Iterator_t attrIter = NULL;

	if (v.get_attrs_expr() != NULL)
		attrIter = pop_itstack();

	if (v.get_content_expr() != NULL)
	{
		contentIter = pop_itstack();
		contentIter = new ElementContentIterator(v.get_loc(), contentIter);
	}

	rchandle<qname_expr> qname = v.get_qname();
	Item_t itemQName = zorba::getZorbaForCurrentThread()->getItemFactory()->
                     createQName("", qname->prefix(), qname->local());

	Iterator_t iter = new ElementIterator(v.get_loc(), itemQName, contentIter, attrIter);

	itstack.push(iter);
}


bool plan_visitor::begin_visit(const compElem_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const compElem_expr& v)
{
  cout << std::string(--depth, ' ') << TRACE << endl;
}


bool plan_visitor::begin_visit(const attr_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const attr_expr& v)
{
  cout << TRACE << endl;

	// TODO dynamic qname
	rchandle<qname_expr> qname = v.get_qname();
	Item_t itemQName = zorba::getZorbaForCurrentThread()->getItemFactory()->
                     createQName("", qname->prefix(), qname->local());

	Iterator_t valueIter = NULL;
	if (v.get_val_expr() != NULL)
		valueIter = pop_itstack();

	Iterator_t attrIter = new AttributeIterator(v.get_loc(), itemQName, valueIter);

	itstack.push(&*attrIter);
}


bool plan_visitor::begin_visit(const text_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const text_expr& v)
{
  cout << std::string(--depth, ' ') << TRACE << endl;
	Item_t item = zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(v.get_text());
	Iterator_t text = new SingletonIterator(v.get_loc(), item);
	itstack.push(text);
}


bool plan_visitor::begin_visit(const comment_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const comment_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(const pi_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(const pi_expr& v)
{
  cout << TRACE << endl;
}




bool plan_visitor::begin_visit(const literal_expr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const order_expr& v)
{
cout << TRACE << endl;
	return true;
}


/*..........................................
 :  end visit                              :
 :.........................................*/
void plan_visitor::end_visit(const var_expr& v)
{
	var_iter_t v_h = new var_iterator("x",v.get_loc());
	itstack.push(&*v_h);
	timstack.push(&*v_h);
}

void plan_visitor::end_visit(const order_modifier& v)
{
  cout << TRACE << endl;
}


void plan_visitor::end_visit(const ft_select_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const ft_contains_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const instanceof_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const treat_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const castable_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const cast_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const unary_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const validate_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(const extension_expr& v)
{
  cout << TRACE << endl;
}


void plan_visitor::end_visit(const literal_expr& v)
{
	cout << std::string(depth--, ' ') << TRACE << endl;
  switch (v.get_type()) {
  case literal_expr::lit_string: {
    Iterator_t it = new SingletonIterator(
											v.get_loc(),
											zorba::getZorbaForCurrentThread()->getItemFactory()->createString(v.get_sval()));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_integer: {
    Iterator_t it = new SingletonIterator(
											v.get_loc(),
											zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(v.get_ival()));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_decimal: {
    Iterator_t it = new SingletonIterator(
											v.get_loc(),
											zorba::getZorbaForCurrentThread()->getItemFactory()->createDecimal(v.get_decval()));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_double: {
    Iterator_t it = new SingletonIterator(
											v.get_loc(),
											zorba::getZorbaForCurrentThread()->getItemFactory()->createDouble(v.get_dval()));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_bool: {
    Iterator_t it = new SingletonIterator(
											v.get_loc(),
											zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(v.get_bval()));
    itstack.push(it);
    break;
  }}
}

void plan_visitor::end_visit(const order_expr& v)
{
cout << TRACE << endl;
}



} /* namespace xqp */
