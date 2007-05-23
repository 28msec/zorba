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
#include "item_iterator.h"
#include "runtime/zorba.h"
#include "util/rchandle.h"

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
	typedef rchandle<expr> expr_h_t;

protected:
	zorba* zorp;
	std::stack<iterator_t> itstack;
	std::stack<iterator_t> argstack;

public:
	plan_visitor(zorba* _zorp) : zorp(_zorp) {}
	~plan_visitor() {}

public:
	iterator_t pop_itstack()
	{
		if (itstack.empty()) return NULL;
		iterator_t it = itstack.top();
		itstack.pop();
		return it;
	}

public:

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	bool begin_visit(expr const&);
	bool begin_visit(expr_list const&);
	bool begin_visit(var_expr const&);
	bool begin_visit(order_modifier const&);
	bool begin_visit(flwor_expr const&);
	bool begin_visit(quantified_expr const&);
	bool begin_visit(case_clause const&);
	bool begin_visit(typeswitch_expr const&);
	bool begin_visit(if_expr const&);
	bool begin_visit(fo_expr const&);
	bool begin_visit(ft_select_expr const&);
	bool begin_visit(ft_contains_expr const&);
	bool begin_visit(instanceof_expr const&);
	bool begin_visit(treat_expr const&);
	bool begin_visit(castable_expr const&);
	bool begin_visit(cast_expr const&);
	bool begin_visit(unary_expr const&);
	bool begin_visit(validate_expr const&);
	bool begin_visit(extension_expr const&);
	bool begin_visit(relpath_expr const&);
	bool begin_visit(axis_step_expr const&);
	bool begin_visit(primary_expr const&);
	bool begin_visit(literal_expr const&);
	bool begin_visit(order_expr const&);
	bool begin_visit(funcall_expr const&);
	bool begin_visit(doc_expr const&);
	bool begin_visit(elem_expr const&);
	bool begin_visit(attr_expr const&);
	bool begin_visit(text_expr const&);
	bool begin_visit(comment_expr const&);
	bool begin_visit(pi_expr const&);


 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	void end_visit(expr const&);
	void end_visit(expr_list const&);
	void end_visit(var_expr const&);
	void end_visit(order_modifier const&);
	void end_visit(flwor_expr const&);
	void end_visit(quantified_expr const&);
	void end_visit(case_clause const&);
	void end_visit(typeswitch_expr const&);
	void end_visit(if_expr const&);
	void end_visit(fo_expr const&);
	void end_visit(ft_select_expr const&);
	void end_visit(ft_contains_expr const&);
	void end_visit(instanceof_expr const&);
	void end_visit(treat_expr const&);
	void end_visit(castable_expr const&);
	void end_visit(cast_expr const&);
	void end_visit(unary_expr const&);
	void end_visit(validate_expr const&);
	void end_visit(extension_expr const&);
	void end_visit(relpath_expr const&);
	void end_visit(axis_step_expr const&);
	void end_visit(primary_expr const&);
	void end_visit(literal_expr const&);
	void end_visit(order_expr const&);
	void end_visit(funcall_expr const&);
	void end_visit(doc_expr const&);
	void end_visit(elem_expr const&);
	void end_visit(attr_expr const&);
	void end_visit(text_expr const&);
	void end_visit(comment_expr const&);
	void end_visit(pi_expr const&);

};

} /* namespace xqp */
#endif /* XQP_PLAN_VISITOR_H */
