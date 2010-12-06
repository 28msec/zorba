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

#include "runtime/scripting/scripting.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/util/flowctl_exception.h"
#include "runtime/api/plan_iterator_wrapper.h"

namespace zorba {

bool
SequentialIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ulong i = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  for (; i < (ulong)theChildren.size(); ++i) 
  {
    while (CONSUME(result, i))
    {
      if (i == (ulong)theChildren.size() - 1)
      {
        STACK_PUSH(true, state);
        i = (ulong)theChildren.size() - 1;
      }
    }
  }

  STACK_END (state);
}

bool
LoopIterator::nextImpl (store::Item_t& result, PlanState& planState) const {
  bool lBreakLoop = false;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  while (!lBreakLoop) {
    try {
      while (! CONSUME (result, 0)) {
        // bugfix: removed a goto in case
        // planState.theHasToQuit was true
        // this should not be needed because
        // the FlowCtlException::INTERRUPT 
        // exception is rethrown below
        theChildren [0]->reset (planState);
      }
    } catch (FlowCtlException &e) {
      switch (e.act) {
      case FlowCtlException::BREAK:
        lBreakLoop = true;
        break;
      case FlowCtlException::CONTINUE:
        theChildren [0]->reset (planState);
        continue;
      default:
        throw;
      }
    }
    if (!lBreakLoop) {
      STACK_PUSH (true, state);
    } 
  }
  STACK_END (state);
}

bool
FlowCtlIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  switch (act) {
  case FlowCtlException::EXIT:
    throw ExitException (new PlanIteratorWrapper (theChildren [0], planState));
  default:
    throw FlowCtlException (act);
  }
    
  STACK_END (state);
}

void
FlowCtlIterator::serialize( ::zorba::serialization::Archiver &ar )
{
  serialize_baseclass(ar,
    (NaryBaseIterator<FlowCtlIterator, PlanIteratorState >*)this);

  SERIALIZE_ENUM(enum FlowCtlException::action, act);
}

} /* namespace zorba */
