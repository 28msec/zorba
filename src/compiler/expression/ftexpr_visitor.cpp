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

#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/ftexpr.h"
#include "compiler/expression/ftexpr_visitor.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

ftexpr_visitor::~ftexpr_visitor() {
  // do nothing
}

///////////////////////////////////////////////////////////////////////////////

ftexpr_visitor& pass_thru_expr_visitor::get_ftexpr_visitor() {
  return ftexpr_visitor_;
}

#define V pass_thru_expr_visitor

DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, attr_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, axis_step_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, castable_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, cast_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, const_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, debugger_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, delete_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, doc_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, dynamic_function_invocation_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, elem_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, eval_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, exit_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, extension_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, flowctl_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, flwor_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, fo_expr )

bool V::begin_visit( ftcontains_expr &e ) {
  e.get_ftselection()->accept( get_ftexpr_visitor() );
  return true;
}

DEF_EXPR_VISITOR_END_VISIT( V, ftcontains_expr )

DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, function_item_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, if_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, insert_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, instanceof_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, match_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, name_cast_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, order_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, pi_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, promote_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, relpath_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, rename_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, replace_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, sequential_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, text_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, transform_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, treat_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, trycatch_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, validate_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, var_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, while_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, wrapper_expr )

#undef V

} // namespace zorba
/* vim:set et sw=2 ts=2: */
