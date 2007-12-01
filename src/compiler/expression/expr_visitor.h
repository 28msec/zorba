/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: expr_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_EXPR_VISITOR_H
#define XQP_EXPR_VISITOR_H

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace xqp 
{

class context;
class expr;
class var_expr;
class order_modifier;
class flwor_expr;
class quantified_expr;
class case_clause;
class typeswitch_expr;
class if_expr;
class fo_expr;
class ft_select_expr;
class ft_contains_expr;
class instanceof_expr;
class treat_expr;
class castable_expr;
class cast_expr;
class validate_expr;
class extension_expr;
class relpath_expr;
class axis_step_expr;
class match_expr;
class primary_expr;
class const_expr;
class order_expr;
class funcall_expr;
class elem_expr;
class doc_expr;
class compElem_expr;
class attr_expr;
class text_expr;
class pi_expr;


class expr_visitor
{
public:	
	virtual ~expr_visitor() {}

public:

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	virtual bool begin_visit(expr&) = 0;
	virtual bool begin_visit(var_expr&) = 0;
	virtual bool begin_visit(order_modifier&) = 0;
	virtual bool begin_visit(flwor_expr&) = 0;
	virtual bool begin_visit(quantified_expr&) = 0;
	virtual bool begin_visit(case_clause&) = 0;
	virtual bool begin_visit(typeswitch_expr&) = 0;
	virtual bool begin_visit(if_expr&) = 0;
	virtual bool begin_visit(fo_expr&) = 0;
	virtual bool begin_visit(ft_select_expr&) = 0;
	virtual bool begin_visit(ft_contains_expr&) = 0;
	virtual bool begin_visit(instanceof_expr&) = 0;
	virtual bool begin_visit(treat_expr&) = 0;
	virtual bool begin_visit(castable_expr&) = 0;
	virtual bool begin_visit(cast_expr&) = 0;
	virtual bool begin_visit(validate_expr&) = 0;
	virtual bool begin_visit(extension_expr&) = 0;
	virtual bool begin_visit(relpath_expr&) = 0;
	virtual bool begin_visit(axis_step_expr&) = 0;
	virtual bool begin_visit(match_expr&) = 0;
	virtual bool begin_visit(const_expr&) = 0;
	virtual bool begin_visit(order_expr&) = 0;
	virtual bool begin_visit(elem_expr&) = 0;
	virtual bool begin_visit(doc_expr&) = 0;
	virtual bool begin_visit(compElem_expr&) = 0;
	virtual bool begin_visit(attr_expr&) = 0;
	virtual bool begin_visit(text_expr&) = 0;
	virtual bool begin_visit(pi_expr&) = 0;

 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	virtual void end_visit(expr&) = 0;
	virtual void end_visit(var_expr&) = 0;
	virtual void end_visit(order_modifier&) = 0;
	virtual void end_visit(flwor_expr&) = 0;
	virtual void end_visit(quantified_expr&) = 0;
	virtual void end_visit(case_clause&) = 0;
	virtual void end_visit(typeswitch_expr&) = 0;
	virtual void end_visit(if_expr&) = 0;
	virtual void end_visit(fo_expr&) = 0;
	virtual void end_visit(ft_select_expr&) = 0;
	virtual void end_visit(ft_contains_expr&) = 0;
	virtual void end_visit(instanceof_expr&) = 0;
	virtual void end_visit(treat_expr&) = 0;
	virtual void end_visit(castable_expr&) = 0;
	virtual void end_visit(cast_expr&) = 0;
	virtual void end_visit(validate_expr&) = 0;
	virtual void end_visit(extension_expr&) = 0;
	virtual void end_visit(relpath_expr&) = 0;
	virtual void end_visit(axis_step_expr&) = 0;
  virtual void end_visit(match_expr&) = 0;
	virtual void end_visit(const_expr&) = 0;
	virtual void end_visit(order_expr&) = 0;
	virtual void end_visit(elem_expr&) = 0;
	virtual void end_visit(doc_expr&) = 0;
	virtual void end_visit(compElem_expr&) = 0;
	virtual void end_visit(attr_expr&) = 0;
	virtual void end_visit(text_expr&) = 0;
	virtual void end_visit(pi_expr&) = 0;

};

} /* namespace xqp */
#endif /* XQP_EXPR_VISITOR_H */
