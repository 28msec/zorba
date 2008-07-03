/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_EXPR_VISITOR_H
#define ZORBA_EXPR_VISITOR_H

#include "compiler/expression/expr_classes.h"

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
  EXPR_VISITOR_METHODS (flwor_expr);
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
  EXPR_VISITOR_METHODS (exit_expr);
  EXPR_VISITOR_METHODS (while_expr);
  EXPR_VISITOR_METHODS (flowctl_expr);

#undef EXPR_VISITOR_METHODS
};

} /* namespace zorba */
#endif /* ZORBA_EXPR_VISITOR_H */
