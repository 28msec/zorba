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
#include <iostream>

#include "zorbaerrors/error_manager.h"

#include "compiler/api/compilercb.h"

#include "runtime/debug/debug_iterators.h"

#include "store/api/item.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnTraceIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnTraceIterator)


void 
FnTraceIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theTagItem = NULL;
  theIndex = 0;
  theOS = 0;
}

void 
FnTraceIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theTagItem = NULL;
  theIndex = 0;
}


void FnTraceIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<FnTraceIterator, FnTraceIteratorState>::
  openImpl(planState, offset);
    
  this->theSctx = planState.theCompilerCB->getStaticContext(this->sctx);
}


bool
FnTraceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  FnTraceIteratorState *state;
  DEFAULT_STACK_INIT(FnTraceIteratorState, state, planState);
  
  if (!consumeNext(state->theTagItem, theChildren[1], planState)) {
    ZORBA_ERROR_LOC_DESC( FORG0006, loc,
        "An empty sequence is not allowed as as second argument to fn:trace");
  }

  state->theOS = theSctx->get_trace_stream();

  while (consumeNext(result, theChildren[0], planState)) {
    (*state->theOS) << state->theTagItem->getStringValue() 
      << " [" << state->theIndex << "]: "
      << result->show()
      << std::endl;
    ++state->theIndex;

    STACK_PUSH(true, state);
  }
  

  STACK_END (state);
}

} /* namespace zorba */

/* vim:set ts=2 sw=2: */
