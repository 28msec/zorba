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

#include "api/serialization/serializer.h"

#include "system/globalenv.h"

#include "types/schema/revalidateUtils.h"

#include "compiler/api/compilercb.h"

#include "runtime/misc/MiscImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/util/flowctl_exception.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/pul.h"

#include "context/static_context.h"

#include <iostream>


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(SequentialIterator)
END_SERIALIZABLE_CLASS_VERSIONS(SequentialIterator)

SERIALIZABLE_CLASS_VERSIONS(FlowCtlIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FlowCtlIterator)

SERIALIZABLE_CLASS_VERSIONS(LoopIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LoopIterator)

NARY_ACCEPT(SequentialIterator);

NARY_ACCEPT(FlowCtlIterator);

NARY_ACCEPT (LoopIterator);


bool SequentialIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  rchandle<store::PUL> lPul;
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


bool FlowCtlIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
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

void FlowCtlIterator::serialize( ::zorba::serialization::Archiver &ar )
{
  serialize_baseclass(ar,
    (NaryBaseIterator<FlowCtlIterator, PlanIteratorState >*)this);

  SERIALIZE_ENUM(enum FlowCtlException::action, act);
}

bool LoopIterator::nextImpl (store::Item_t& result, PlanState& planState) const {
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

} /* namespace zorba */
