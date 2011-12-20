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
#ifndef ZORBA_FUNCTIONS_NODEID_INTERNAL_H
#define ZORBA_FUNCTIONS_NODEID_INTERNAL_H

#include "functions/function_impl.h"
#include "functions/function_consts.h"

namespace zorba 
{

void populateContext_DocOrder(static_context* sctx);


/*******************************************************************************
  Base class for all functions that perform some combination of the following
  actions on the result of some input expr E:

  1. Sorting the result of E in ascending document order.
  2. Sorting the result of E in descending document order.
  3. Eliminating duplicate nodes in the result of E.
  4. Checking that the result of E consists of nodes only or atomic values only.

  The particular combination of actions performed by a specific instance of
  op_node_sort_distinct is called the "action set" of that instance.

  Note: the actions are not completely orthogonal to each other: Actions 1, 2,
  or 3 by themselves imply that the result of E must consist of nodes only. 
  However, if any of these actions appears together with action 4 in an action
  set, then the result of E may consist of nodes only or atomic values only, 
  and if it consists of atomic values only, then actions 1, 2, 3 become no-ops.  
********************************************************************************/
class op_node_sort_distinct_base : public function 
{
public:
  typedef enum 
  {
    SORT_ASC   = 0,  // sort input nodes in ascending doc order
    SORT_DESC  = 1,  // sort input nodes in descending doc order
    DISTINCT   = 2,  // eliminate duplicate nodes from input
    NOA        = 3,  // allow input seq to contain nodes only or atomic values only 
  }
  Actions;

public:
  op_node_sort_distinct_base(
        const signature& sig,
        FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
  }

  // (sort_asc?, sort_desc?, distinct?, atomics?)
  virtual const bool* action() const = 0;

  bool isNodeDistinctFunction() const { return action()[DISTINCT]; }

  virtual function* optimize(const expr* self, expr* child) const;

  xqtref_t getReturnType(const fo_expr* caller) const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, ulong input) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, ulong input) const;

  CODEGEN_DECL();
};




}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
