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
#pragma once
#ifndef ZORBA_COMPILER_EXPR_VISITOR_H
#define ZORBA_COMPILER_EXPR_VISITOR_H

#include <zorba/config.h>
#include "compiler/expression/expr_classes.h"

namespace zorba 
{

#ifndef ZORBA_NO_FULL_TEXT
class ftnode_visitor;
#endif /* ZORBA_NO_FULL_TEXT */

class expr_visitor
{
public: 

  virtual ~expr_visitor() { }

#ifndef ZORBA_NO_FULL_TEXT
  virtual ftnode_visitor* get_ftnode_visitor() = 0;
#endif /* ZORBA_NO_FULL_TEXT */

#define DECL_EXPR_VISITOR_VISIT_MEM_FNS(C)  \
  virtual bool begin_visit( C& ) = 0;       \
  virtual void end_visit( C& ) = 0

  DECL_EXPR_VISITOR_VISIT_MEM_FNS( expr );

  DECL_EXPR_VISITOR_VISIT_MEM_FNS( var_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( flwor_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( promote_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( if_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( fo_expr );
#ifndef ZORBA_NO_FULL_TEXT
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( ftcontains_expr );
#endif /* ZORBA_NO_FULL_TEXT */
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( instanceof_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( treat_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( castable_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( cast_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( name_cast_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( validate_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( extension_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( relpath_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( axis_step_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( match_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( const_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( order_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( elem_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( doc_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( attr_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( text_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( pi_expr );

  DECL_EXPR_VISITOR_VISIT_MEM_FNS( trycatch_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( function_item_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( dynamic_function_invocation_expr );

  DECL_EXPR_VISITOR_VISIT_MEM_FNS(insert_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(delete_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(rename_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(replace_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(transform_expr);

  DECL_EXPR_VISITOR_VISIT_MEM_FNS(block_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(var_decl_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(apply_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(exit_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(exit_catcher_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(while_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(flowctl_expr);

  DECL_EXPR_VISITOR_VISIT_MEM_FNS(eval_expr);
#ifdef ZORBA_WITH_DEBUGGER
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(debugger_expr);
#endif
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(function_trace_expr);
  DECL_EXPR_VISITOR_VISIT_MEM_FNS(wrapper_expr);


#undef DECL_EXPR_VISITOR_VISIT_MEM_FNS
#define DECL_EXPR_VISITOR_VISIT_MEM_FNS(C)  \
  bool begin_visit( C& );                   \
  void end_visit( C& )

#define DEF_EXPR_VISITOR_BEGIN_VISIT(V,C) \
  bool V::begin_visit( C& ) {             \
    return true;                          \
  }

#define DEF_EXPR_VISITOR_END_VISIT(V,C) \
  void V::end_visit( C& ) {             \
  }

#define DEF_EXPR_VISITOR_VISIT_MEM_FNS(V,C) \
  DEF_EXPR_VISITOR_BEGIN_VISIT(V,C)         \
  DEF_EXPR_VISITOR_END_VISIT(V,C)

};

} /* namespace zorba */
#endif /* ZORBA_EXPR_VISITOR_H */
/* vim:set et sw=2 ts=2: */
