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
#include "errors/error_manager.h"
#include "runtime/debug/debug_iterators.h"
#include "store/api/item.h"

using namespace std;

namespace zorba {

void 
FnTraceIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theTagItem = NULL;
}

void 
FnTraceIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theTagItem = NULL;
}

store::Item_t 
FnTraceIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lSequenceItem;

  FnTraceIteratorState *state;
  DEFAULT_STACK_INIT(FnTraceIteratorState, state, planState);

  if ( (state->theTagItem = consumeNext(theChildren[1], planState)) == NULL ) {
    ZORBA_ERROR_LOC_DESC( ZorbaError::FORG0006, loc,
        "An empty sequence is not allowed as as second argument to fn:trace");
  }

  while ((lSequenceItem = consumeNext(theChildren[0], planState)) != NULL) {
    // FIXME: check the standard how to return this
    cerr << state->theTagItem->getStringValue() << lSequenceItem->getStringValue() << endl;
    STACK_PUSH(lSequenceItem, state);
  }

  STACK_END (state);
}

} /* namespace zorba */

/* vim:set ts=2 sw=2: */
