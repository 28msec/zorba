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

#include <zorba/config.h>
#include "common/shared_types.h"

namespace zorba 
{
  class debugger_expr;
  class wrapper_expr;
  class sequential_expr; class exit_expr; class while_expr; class flowctl_expr;
  class order_modifier; class flwor_expr; class case_clause; class promote_expr;
  class gflwor_expr; class trycatch_expr; class eval_expr; 
  class if_expr; class fo_expr;
#ifndef ZORBA_NO_FULL_TEXT
  class ftcontains_expr;
#endif /* ZORBA_NO_FULL_TEXT */
  class instanceof_expr; class treat_expr; class castable_expr; class cast_expr; class name_cast_expr;
  class validate_expr; class extension_expr; class relpath_expr;
  class axis_step_expr; class match_expr; class primary_expr; class const_expr;
  class order_expr; class funcall_expr; class elem_expr; class doc_expr;
  class attr_expr; class text_expr; class pi_expr; class function_def_expr;
  class insert_expr; class delete_expr; class replace_expr; class rename_expr;
  class transform_expr;
  class function_item_expr; class dynamic_function_invocation_expr;
}
