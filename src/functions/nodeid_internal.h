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

#ifndef ZORBA_FUNCTIONS_NODEID_INTERNAL_H
#define ZORBA_FUNCTIONS_NODEID_INTERNAL_H

#include "functions/single_seq_func.h"
#include "functions/function_impl.h"
#include "functions/function_enum.h"

#include "zorbautils/checked_vector.h"

namespace zorba 
{

void populateContext_DocOrder(static_context* sctx);


/*******************************************************************************
  Base class for all function that perform document ordering and/or duplicate
  node elimination.
********************************************************************************/
class op_node_sort_distinct : public function 
{
public:
  typedef enum { NODES, ATOMICS, MIXED } nodes_or_atomics_t;

  static function* op_for_action(
        const static_context* sctx,
        const bool* a,
        const AnnotationHolder* parent,
        const AnnotationHolder* child,
        nodes_or_atomics_t noa);

public:
  op_node_sort_distinct(
        const signature& sig,
        FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
  }

  // (sort?, atomics?, distinct?, ascending?)
  virtual const bool* action() const = 0;

  bool isNodeDistinctFunction() const { return action()[2]; }

  virtual function* min_action(
        const static_context* sctx,
        const AnnotationHolder* self,
        const AnnotationHolder* child,
        nodes_or_atomics_t noa) const;

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const
  {
    return arg_types[0]; 
  }

  COMPUTE_ANNOTATION_DECL();

  CODEGEN_DECL();
};




}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
