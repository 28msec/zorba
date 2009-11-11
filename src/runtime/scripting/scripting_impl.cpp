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

  for (; i < theChildren.size(); ++i) 
  {
    while (CONSUME(result, i))
    {
      if (i == theChildren.size() - 1)
      {
        STACK_PUSH(true, state);
        i = theChildren.size() - 1;
      }
    }
  }

  STACK_END (state);
}

bool
LoopIterator::nextImpl (store::Item_t& result, PlanState& planState) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  for (;;) {
    try {
      while (! CONSUME (result, 0)) {
        if (planState.theHasToQuit) {
          goto done;
        }
        theChildren [0]->reset (planState);
      }
    } catch (FlowCtlException &e) {
      switch (e.act) {
      case FlowCtlException::BREAK:
        goto done;
      case FlowCtlException::CONTINUE:
        theChildren [0]->reset (planState);
        continue;
      default:
        throw;
      }
    }
    STACK_PUSH (true, state);
  }

done:
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
