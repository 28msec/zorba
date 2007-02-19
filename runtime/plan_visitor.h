/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: plan_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_PLAN_VISITOR_H
#define XQP_PLAN_VISITOR_H

#include "expr_visitor.h"
#include "iterator.h"
#include "../util/rchandle.h"
#include <stack>

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace xqp {

class plan_visitor : public expr_visitor
{
public:
	typedef rchandle<item_iterator> it_h_t;

protected:
	context * ctx_p;
	std::stack<it_h_t> itstack;
	std::stack<it_h_t> argstack;

public:
	plan_visitor(context* _ctx_p) : ctx_p(_ctx_p) {}
	~plan_visitor() {}

public:
	it_h_t pop_nodestack()
	{
		if (itstack.empty()) return NULL;
		it_h_t it_h = itstack.top();
		itstack.pop();
		return it_h;
	}

public:

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	bool begin_visit(expr&);
	bool begin_visit(expr_list&);
	bool begin_visit(var_expr&);
	bool begin_visit(order_modifier&);
	bool begin_visit(flwor_expr&);
	bool begin_visit(quantified_expr&);
	bool begin_visit(case_clause&);
	bool begin_visit(typeswitch_expr&);
	bool begin_visit(if_expr&);
	bool begin_visit(fo_expr&);
	bool begin_visit(ft_select_expr&);
	bool begin_visit(ft_contains_expr&);
	bool begin_visit(instanceof_expr&);
	bool begin_visit(treat_expr&);
	bool begin_visit(castable_expr&);
	bool begin_visit(cast_expr&);
	bool begin_visit(unary_expr&);
	bool begin_visit(validate_expr&);
	bool begin_visit(extension_expr&);
	bool begin_visit(relpath_expr&);
	bool begin_visit(axis_step_expr&);
	bool begin_visit(primary_expr&);
	bool begin_visit(literal_expr&);
	bool begin_visit(order_expr&);
	bool begin_visit(funcall_expr&);
	bool begin_visit(cons_expr&);
	bool begin_visit(doc_expr&);
	bool begin_visit(elem_expr&);
	bool begin_visit(attr_expr&);
	bool begin_visit(text_expr&);
	bool begin_visit(comment_expr&);
	bool begin_visit(pi_expr&);


 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	void end_visit(expr&);
	void end_visit(expr_list&);
	void end_visit(var_expr&);
	void end_visit(order_modifier&);
	void end_visit(flwor_expr&);
	void end_visit(quantified_expr&);
	void end_visit(case_clause&);
	void end_visit(typeswitch_expr&);
	void end_visit(if_expr&);
	void end_visit(fo_expr&);
	void end_visit(ft_select_expr&);
	void end_visit(ft_contains_expr&);
	void end_visit(instanceof_expr&);
	void end_visit(treat_expr&);
	void end_visit(castable_expr&);
	void end_visit(cast_expr&);
	void end_visit(unary_expr&);
	void end_visit(validate_expr&);
	void end_visit(extension_expr&);
	void end_visit(relpath_expr&);
	void end_visit(axis_step_expr&);
	void end_visit(primary_expr&);
	void end_visit(literal_expr&);
	void end_visit(order_expr&);
	void end_visit(funcall_expr&);
	void end_visit(cons_expr&);
	void end_visit(doc_expr&);
	void end_visit(elem_expr&);
	void end_visit(attr_expr&);
	void end_visit(text_expr&);
	void end_visit(comment_expr&);
	void end_visit(pi_expr&);

};

} /* namespace xqp */
#endif /* XQP_PLAN_VISITOR_H */
