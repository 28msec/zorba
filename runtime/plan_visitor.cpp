/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: plan_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "plan_visitor.h"
#include "indent.h"

#include "exprtree/expr.h"
#include "functions/SequencesImpl.h"
#include "runtime/item_iterator.h"
#include "util/tracer.h"

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
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const expr_list& v)
{
cout << indent[++depth] << TRACE << endl;
	itstack.push(NULL);
	return true;
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

bool plan_visitor::begin_visit(const quantified_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const case_clause& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const typeswitch_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const if_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const fo_expr& v)
{
cout << indent[++depth] << TRACE << endl;
	itstack.push(NULL);
	return true;
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

bool plan_visitor::begin_visit(const relpath_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const axis_step_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const literal_expr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const order_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const doc_expr& v)
{
cout << TRACE  << endl;
	return true;
}

bool plan_visitor::begin_visit(const elem_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const attr_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const text_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const comment_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(const pi_expr& v)
{
cout << TRACE << endl;
	return true;
}



/*..........................................
 :  end visit                              :
 :.........................................*/
void plan_visitor::end_visit(const expr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void plan_visitor::end_visit(const expr_list& v)
{
cout << indent[depth--] << TRACE << endl;
	vector<Iterator_t> argv;
	while (true) {
		Iterator_t it = pop_itstack();
		if (it==NULL) break;
		argv.insert(argv.begin(),it);
	}
	rchandle<ConcatIterator> cit_h = new ConcatIterator(v.get_loc(), argv);
	itstack.push(&*cit_h);
}

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

void plan_visitor::end_visit(const quantified_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const case_clause& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const typeswitch_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const if_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const fo_expr& v)
{
cout << indent[depth--] << TRACE << endl;

	const function* func_p = v.get_func();
	assert(func_p!=NULL);
	const function& func = *func_p;

	vector<Iterator_t> argv;
	while (true) {
		Iterator_t it_h = pop_itstack();
		if (it_h==NULL) break;
		vector<Iterator_t>::iterator begin = argv.begin();
 		argv.insert(begin, 1, it_h );
	}

	itstack.push(func(v.get_loc(),argv));
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

void plan_visitor::end_visit(const relpath_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const axis_step_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const literal_expr& v)
{
	cout << indent[depth--] << TRACE << endl;
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

void plan_visitor::end_visit(const doc_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const elem_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const attr_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const text_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const comment_expr& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(const pi_expr& v)
{
cout << TRACE << endl;
}


} /* namespace xqp */
