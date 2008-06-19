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
#ifndef ZORBA_RUNTIME_FN_CONTEXT_IMPL_H
#define ZORBA_RUNTIME_FN_CONTEXT_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"
#include "runtime/util/plan_wrapper_holder.h"

#include "context/dynamic_context.h"

namespace zorba
{
  
/*******************************************************************************

  CtxVariableIterator

  Used in the evaluation of external variables: For each external variable, the
  dynamic context maps the name of the variable to an iterator that computes the
  variable's value. CtxVariableIterator has one child only, which produces the
  name of an external variabe. Using this name, CtxVariableIterator extracts the
  associated iterator from the dynamic context and just returns the items that
  it produces.

  The global context item is also considered an external variable whose name is
  ".". Since the value of the context item is always a single item (or the empty
  seq), the dynamic context maps "." to an Item (instead of an Iterator). So,
  a CtxVariableIterator that represents the context item, returns just the item
  associated with "." in the dynamic context.

********************************************************************************/
class CtxVariableIteratorState : public  PlanIteratorState 
{
public:
  store::Iterator_t theIter;
};

NARY_ITER_STATE (CtxVariableIterator, CtxVariableIteratorState);


/*******************************************************************************

********************************************************************************/
NARY_ITER (CtxVarAssignIterator);


/*******************************************************************************

********************************************************************************/
class EvalIteratorState : public PlanIteratorState {
public:
  PlanWrapperHolder eval_plan;
  std::auto_ptr<CompilerCB> ccb;
  std::auto_ptr<dynamic_context> dctx;
};


class EvalIterator : public NaryBaseIterator<EvalIterator, EvalIteratorState> {
  checked_vector<store::Item_t> varnames;
  checked_vector<std::string> var_keys;  
  checked_vector<xqtref_t> vartypes;

public:
  EvalIterator(const QueryLoc& loc,
               checked_vector<store::Item_t> varnames_,
               checked_vector<std::string> var_keys_,
               checked_vector<xqtref_t> vartypes_,
               std::vector<PlanIter_t>& aChildren)
    :
    NaryBaseIterator<EvalIterator, EvalIteratorState> (loc, aChildren),
    varnames (varnames_), var_keys (var_keys_), vartypes (vartypes_)
  {}

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

}

#endif //ZORBA_FN_CONTEXT_IMPL_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
