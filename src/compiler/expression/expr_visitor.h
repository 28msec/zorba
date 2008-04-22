/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: expr_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef ZORBA_EXPR_VISITOR_H
#define ZORBA_EXPR_VISITOR_H

#include "common/shared_types.h"

/*______________________________________________________________________
|  
|  Design note: Visitor pattern.  See, for example:
|  "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace zorba 
{

class expr_visitor
{
public: 
  virtual ~expr_visitor() {}

public:
  
#define EXPR_VISITOR_METHODS( e )         \
  virtual bool begin_visit(e&) = 0;       \
  virtual void end_visit(e&) = 0
  
  EXPR_VISITOR_METHODS (expr);
  EXPR_VISITOR_METHODS (sequential_expr);
  EXPR_VISITOR_METHODS (var_expr);
  EXPR_VISITOR_METHODS (order_modifier);
  EXPR_VISITOR_METHODS (flwor_expr);
  EXPR_VISITOR_METHODS (case_clause);
  EXPR_VISITOR_METHODS (promote_expr);
  EXPR_VISITOR_METHODS (trycatch_expr);
  EXPR_VISITOR_METHODS (eval_expr);
  EXPR_VISITOR_METHODS (typeswitch_expr);
  EXPR_VISITOR_METHODS (if_expr);
  EXPR_VISITOR_METHODS (fo_expr);
  EXPR_VISITOR_METHODS (ft_select_expr);
  EXPR_VISITOR_METHODS (ft_contains_expr);
  EXPR_VISITOR_METHODS (instanceof_expr);
  EXPR_VISITOR_METHODS (treat_expr);
  EXPR_VISITOR_METHODS (castable_expr);
  EXPR_VISITOR_METHODS (cast_expr);
  EXPR_VISITOR_METHODS (name_cast_expr);
  EXPR_VISITOR_METHODS (validate_expr);
  EXPR_VISITOR_METHODS (extension_expr);
  EXPR_VISITOR_METHODS (relpath_expr);
  EXPR_VISITOR_METHODS (axis_step_expr);
  EXPR_VISITOR_METHODS (match_expr);
  EXPR_VISITOR_METHODS (const_expr);
  EXPR_VISITOR_METHODS (order_expr);
  EXPR_VISITOR_METHODS (elem_expr);
  EXPR_VISITOR_METHODS (doc_expr);
  EXPR_VISITOR_METHODS (attr_expr);
  EXPR_VISITOR_METHODS (text_expr);
  EXPR_VISITOR_METHODS (pi_expr);
  EXPR_VISITOR_METHODS (function_def_expr);
  EXPR_VISITOR_METHODS (insert_expr);
  EXPR_VISITOR_METHODS (delete_expr);
  EXPR_VISITOR_METHODS (rename_expr);
  EXPR_VISITOR_METHODS (replace_expr);
  EXPR_VISITOR_METHODS (transform_expr);

#undef EXPR_VISITOR_METHODS
};

} /* namespace zorba */
#endif /* ZORBA_EXPR_VISITOR_H */
