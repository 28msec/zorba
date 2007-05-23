/* -*- mode: c++; indent-tabs-mode: nil -*-
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
bool plan_visitor::begin_visit(expr const& v)
{
cout << indent[++depth] << TRACE << ": expr" << endl;
	return true;
}

bool plan_visitor::begin_visit(expr_list const& v)
{
cout << indent[++depth] << TRACE << ": expr_list" << endl;
	itstack.push(NULL);
	return true;
}

bool plan_visitor::begin_visit(var_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(order_modifier const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(flwor_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(quantified_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(case_clause const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(typeswitch_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(if_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(fo_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(ft_select_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(ft_contains_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(instanceof_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(treat_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(castable_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(cast_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(unary_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(validate_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(extension_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(relpath_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(axis_step_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(primary_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(literal_expr const& v)
{
cout << indent[++depth] << TRACE << ": literal_expr" << endl;
	return true;
}

bool plan_visitor::begin_visit(order_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(funcall_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(doc_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(elem_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(attr_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(text_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(comment_expr const& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(pi_expr const& v)
{
cout << TRACE << endl;
	return true;
}



/*..........................................
 :  end visit                              :
 :.........................................*/
void plan_visitor::end_visit(expr const& v)
{
cout << indent[depth--] << TRACE << ": expr" << endl;
}

void plan_visitor::end_visit(expr_list const& v)
{
cout << indent[depth--] << TRACE << ": expr_list" << endl;
	vector<iterator_t> it_list;
	while (true) {
		iterator_t it = pop_itstack();
		if (it==NULL) break;
		it_list.push_back(it);
	}
cout << TRACE << " : [1]\n";
	rchandle<concat_iterator> cit_h =
		new concat_iterator(zorp, it_list[0], it_list[1]);

	// impl note: use this pattern for code gen of all funcall_expr nodes
	//  it_h = new funcall_iterator(fun, it_list)

cout << TRACE << " : [2]\n";
	itstack.push(&*cit_h);
cout << TRACE << " : [3]\n";
}

void plan_visitor::end_visit(var_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(order_modifier const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(flwor_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(quantified_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(case_clause const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(typeswitch_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(if_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(fo_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(ft_select_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(ft_contains_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(instanceof_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(treat_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(castable_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(cast_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(unary_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(validate_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(extension_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(relpath_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(axis_step_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(primary_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(literal_expr const& v)
{
cout << indent[depth--] << TRACE << ": literal_expr" << endl;
  switch (v.get_type()) {
  case literal_expr::lit_string: {
    iterator_t it = new singleton_iterator(new stringValue("test string"));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_integer: {
    iterator_t it = new singleton_iterator(new numericValue(xs_integer,v.get_ival()));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_decimal: {
    iterator_t it = new singleton_iterator(new numericValue(xs_decimal,v.get_decval()));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_double: {
    iterator_t it = new singleton_iterator(new numericValue(xs_double,v.get_dval()));
    itstack.push(it);
    break;
  }
  case literal_expr::lit_bool: {
    iterator_t it = new singleton_iterator(new booleanValue(v.get_bval()));
    itstack.push(it);
    break;
  }
  }
}

void plan_visitor::end_visit(order_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(funcall_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(doc_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(elem_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(attr_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(text_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(comment_expr const& v)
{
cout << TRACE << endl;
}

void plan_visitor::end_visit(pi_expr const& v)
{
cout << TRACE << endl;
}


} /* namespace xqp */
