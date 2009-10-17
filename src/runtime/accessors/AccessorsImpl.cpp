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
 
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "system/globalenv.h"

#include "context/namespace_context.h"

#include "runtime/accessors/AccessorsImpl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnDataIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDataIterator)


/*******************************************************************************
  2.4 fn:data
********************************************************************************/
void FnDataIteratorState::init(PlanState& planState) 
{ 
  PlanIteratorState::init( planState );
  theTypedValueIter = NULL;
}


void FnDataIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset( planState );
  theTypedValueIter = NULL;
}


bool
FnDataIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIter_t iter;
  store::Item_t itemNode;

  FnDataIteratorState* state;
  DEFAULT_STACK_INIT(FnDataIteratorState, state, planState);
  
  while (true) 
  {
    if (!consumeNext(result, theChild, planState))
      break;

    if (result->isAtomic())
    {
      STACK_PUSH(true, state);
    }
    else
    {
      assert(result->isNode());

      itemNode.transfer(result);
      itemNode->getTypedValue(result, state->theTypedValueIter);

      if (state->theTypedValueIter == NULL)
      {
        if (result == NULL)
          continue;

        STACK_PUSH(true, state );
      }
      else
      {
        state->theTypedValueIter->open();
      
        while (true) 
        {
          if (!state->theTypedValueIter->next(result))
            break;

          assert(!result->isNode());
          STACK_PUSH(true, state );
        }
      }
    }
  }

  state->theTypedValueIter = 0; // TODO remove???
  STACK_END (state);
}


UNARY_ACCEPT(FnDataIterator);

} /* namespace zorba */
/* vim:set ts=2 sw=2: */
