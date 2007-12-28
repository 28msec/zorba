/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: plan_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_PLAN_VISITOR_H
#define XQP_PLAN_VISITOR_H

#include "compiler/expression/expr_visitor.h"
#include "runtime/core/item_iterator.h"
#include "util/rchandle.h"
#include "util/hashmap.h"

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
  typedef rchandle<var_iterator> var_iter_t;
  typedef rchandle<RefIterator> ref_iter_t;

protected:
	std::stack<PlanIter_t> itstack;

	std::stack<expr*>      theConstructorsStack;

  hash64map<std::vector<var_iter_t> *> fvar_iter_map;
  hash64map<std::vector<var_iter_t> *> pvar_iter_map;
  hash64map<std::vector<ref_iter_t> *> lvar_iter_map;

public:
	plan_visitor( ) {}
	~plan_visitor() {}

public:
	PlanIter_t pop_itstack()
	{
		assert (! itstack.empty());
		PlanIter_t it = itstack.top();
		itstack.pop();
		return it;
	}

public:

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	bool begin_visit(expr&);
	bool begin_visit(var_expr&);
	bool begin_visit(order_modifier&);
	bool begin_visit(flwor_expr&);
	bool begin_visit(case_clause&);
	bool begin_visit(promote_expr&);
	bool begin_visit(typeswitch_expr&);
	bool begin_visit(if_expr&);
	bool begin_visit(fo_expr&);
	bool begin_visit(ft_select_expr&);
	bool begin_visit(ft_contains_expr&);
	bool begin_visit(instanceof_expr&);
	bool begin_visit(treat_expr&);
	bool begin_visit(castable_expr&);
	bool begin_visit(cast_expr&);
	bool begin_visit(validate_expr&);
	bool begin_visit(extension_expr&);
	bool begin_visit(relpath_expr&);
	bool begin_visit(axis_step_expr&);
	bool begin_visit(match_expr&);
	bool begin_visit(const_expr&);
	bool begin_visit(order_expr&);
	bool begin_visit(elem_expr&);
	bool begin_visit(doc_expr&);
	bool begin_visit(attr_expr&);
	bool begin_visit(text_expr&);
	bool begin_visit(pi_expr&);


 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	void end_visit(expr&);
	void end_visit(var_expr&);
	void end_visit(order_modifier&);
	void end_visit(flwor_expr&);
	void end_visit(case_clause&);
	void end_visit(promote_expr&);
	void end_visit(typeswitch_expr&);
	void end_visit(if_expr&);
	void end_visit(fo_expr&);
	void end_visit(ft_select_expr&);
	void end_visit(ft_contains_expr&);
	void end_visit(instanceof_expr&);
	void end_visit(treat_expr&);
	void end_visit(castable_expr&);
	void end_visit(cast_expr&);
	void end_visit(validate_expr&);
	void end_visit(extension_expr&);
	void end_visit(relpath_expr&);
	void end_visit(axis_step_expr&);
	void end_visit(match_expr&);
	void end_visit(const_expr&);
	void end_visit(order_expr&);
	void end_visit(elem_expr&);
	void end_visit(doc_expr&);
	void end_visit(attr_expr&);
	void end_visit(text_expr&);
	void end_visit(pi_expr&);

};

} /* namespace xqp */
#endif /* XQP_PLAN_VISITOR_H */
