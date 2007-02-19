/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: plan_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "plan_visitor.h"
#include <iostream>

#define TRACE __FILE__<<":"<<__LINE__<<"::"<<__FUNCTION__

using namespace std;
namespace xqp 
{


plan_visitor::plan_visitor()
{
}

plan_visitor::~plan_visitor()
{
}


/*..........................................
 :  begin visit                            :
 :.........................................*/
bool begin_visit(expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(expr_list& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(var_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(order_modifier& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(flwor_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(quantified_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(case_clause& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(typeswitch_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(if_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(fo_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(ft_select_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(ft_contains_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(instanceof_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(treat_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(castable_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(cast_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(unary_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(validate_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(extension_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(relpath_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(axis_step_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(primary_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(literal_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(order_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(funcall_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(cons_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(doc_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(elem_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(attr_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(text_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(comment_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool begin_visit(pi_expr& v)
{
cout << TRACE << endl;
	return true;
}



/*..........................................
 :  end visit                              :
 :.........................................*/
void end_visit(expr& v)
{
cout << TRACE << endl;
}

void end_visit(expr_list& v)
{
cout << TRACE << endl;
}

void end_visit(var_expr& v)
{
cout << TRACE << endl;
}

void end_visit(order_modifier& v)
{
cout << TRACE << endl;
}

void end_visit(flwor_expr& v)
{
cout << TRACE << endl;
}

void end_visit(quantified_expr& v)
{
cout << TRACE << endl;
}

void end_visit(case_clause& v)
{
cout << TRACE << endl;
}

void end_visit(typeswitch_expr& v)
{
cout << TRACE << endl;
}

void end_visit(if_expr& v)
{
cout << TRACE << endl;
}

void end_visit(fo_expr& v)
{
cout << TRACE << endl;
}

void end_visit(ft_select_expr& v)
{
cout << TRACE << endl;
}

void end_visit(ft_contains_expr& v)
{
cout << TRACE << endl;
}

void end_visit(instanceof_expr& v)
{
cout << TRACE << endl;
}

void end_visit(treat_expr& v)
{
cout << TRACE << endl;
}

void end_visit(castable_expr& v)
{
cout << TRACE << endl;
}

void end_visit(cast_expr& v)
{
cout << TRACE << endl;
}

void end_visit(unary_expr& v)
{
cout << TRACE << endl;
}

void end_visit(validate_expr& v)
{
cout << TRACE << endl;
}

void end_visit(extension_expr& v)
{
cout << TRACE << endl;
}

void end_visit(relpath_expr& v)
{
cout << TRACE << endl;
}

void end_visit(axis_step_expr& v)
{
cout << TRACE << endl;
}

void end_visit(primary_expr& v)
{
cout << TRACE << endl;
}

void end_visit(literal_expr& v)
{
cout << TRACE << endl;
}

void end_visit(order_expr& v)
{
cout << TRACE << endl;
}

void end_visit(funcall_expr& v)
{
cout << TRACE << endl;
}

void end_visit(cons_expr& v)
{
cout << TRACE << endl;
}

void end_visit(doc_expr& v)
{
cout << TRACE << endl;
}

void end_visit(elem_expr& v)
{
cout << TRACE << endl;
}

void end_visit(attr_expr& v)
{
cout << TRACE << endl;
}

void end_visit(text_expr& v)
{
cout << TRACE << endl;
}

void end_visit(comment_expr& v)
{
cout << TRACE << endl;
}

void end_visit(pi_expr& v)
{
cout << TRACE << endl;
}


} /* namespace xqp */
