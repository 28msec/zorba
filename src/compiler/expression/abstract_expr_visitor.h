#ifndef ZORBA_ABSTRACT_EXPR_VISITOR_H
#define ZORBA_ABSTRACT_EXPR_VISITOR_H

#include "common/shared_types.h"
#include "compiler/expression/expr_visitor.h"

/*______________________________________________________________________
|  
|  Design note: Visitor pattern.  See, for example:
|  "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace zorba 
{

class abstract_expr_visitor : public expr_visitor
{
public: 
  virtual ~abstract_expr_visitor() {}

public:

 /*..........................................
  :  begin visit                            :
  :.........................................*/
  virtual bool begin_visit(expr&) { return true; }
  virtual bool begin_visit(var_expr&) { return true; }
  virtual bool begin_visit(order_modifier&) { return true; }
  virtual bool begin_visit(flwor_expr&) { return true; }
  virtual bool begin_visit(case_clause&) { return true; }
  virtual bool begin_visit(promote_expr&) { return true; }
  virtual bool begin_visit(trycatch_expr&) { return true; }
  virtual bool begin_visit(typeswitch_expr&) { return true; }
  virtual bool begin_visit(if_expr&) { return true; }
  virtual bool begin_visit(fo_expr&) { return true; }
  virtual bool begin_visit(ft_select_expr&) { return true; }
  virtual bool begin_visit(ft_contains_expr&) { return true; }
  virtual bool begin_visit(instanceof_expr&) { return true; }
  virtual bool begin_visit(treat_expr&) { return true; }
  virtual bool begin_visit(castable_expr&) { return true; }
  virtual bool begin_visit(cast_expr&) { return true; }
  virtual bool begin_visit(name_cast_expr&) { return true; }
  virtual bool begin_visit(validate_expr&) { return true; }
  virtual bool begin_visit(extension_expr&) { return true; }
  virtual bool begin_visit(relpath_expr&) { return true; }
  virtual bool begin_visit(axis_step_expr&) { return true; }
  virtual bool begin_visit(match_expr&) { return true; }
  virtual bool begin_visit(const_expr&) { return true; }
  virtual bool begin_visit(order_expr&) { return true; }
  virtual bool begin_visit(elem_expr&) { return true; }
  virtual bool begin_visit(doc_expr&) { return true; }
  virtual bool begin_visit(attr_expr&) { return true; }
  virtual bool begin_visit(text_expr&) { return true; }
  virtual bool begin_visit(pi_expr&) { return true; }
  virtual bool begin_visit(function_def_expr&) { return true; }
  virtual bool begin_visit(insert_expr&) { return true; }
  virtual bool begin_visit(delete_expr&) { return true; }
  virtual bool begin_visit(rename_expr&) { return true; }
  virtual bool begin_visit(replace_expr&) { return true; }
  virtual bool begin_visit(transform_expr&) { return true; }

 /*..........................................
  :  end visit                              :
  :.........................................*/
  virtual void end_visit(expr&) { }
  virtual void end_visit(var_expr&) { }
  virtual void end_visit(order_modifier&) { }
  virtual void end_visit(flwor_expr&) { }
  virtual void end_visit(case_clause&) { }
  virtual void end_visit(promote_expr&) { }
  virtual void end_visit(trycatch_expr&) { }
  virtual void end_visit(typeswitch_expr&) { }
  virtual void end_visit(if_expr&) { }
  virtual void end_visit(fo_expr&) { }
  virtual void end_visit(ft_select_expr&) { }
  virtual void end_visit(ft_contains_expr&) { }
  virtual void end_visit(instanceof_expr&) { }
  virtual void end_visit(treat_expr&) { }
  virtual void end_visit(castable_expr&) { }
  virtual void end_visit(cast_expr&) { }
  virtual void end_visit(name_cast_expr&) { }
  virtual void end_visit(validate_expr&) { }
  virtual void end_visit(extension_expr&) { }
  virtual void end_visit(relpath_expr&) { }
  virtual void end_visit(axis_step_expr&) { }
  virtual void end_visit(match_expr&) { }
  virtual void end_visit(const_expr&) { }
  virtual void end_visit(order_expr&) { }
  virtual void end_visit(elem_expr&) { }
  virtual void end_visit(doc_expr&) { }
  virtual void end_visit(attr_expr&) { }
  virtual void end_visit(text_expr&) { }
  virtual void end_visit(pi_expr&) { }
  virtual void end_visit(function_def_expr&) { }
  virtual void end_visit(insert_expr&) { }
  virtual void end_visit(delete_expr&) { }
  virtual void end_visit(rename_expr&) { }
  virtual void end_visit(replace_expr&) { }
  virtual void end_visit(transform_expr&) { }

};

} /* namespace zorba */
#endif /* ZORBA_ABSTRACT_EXPR_VISITOR_H */
