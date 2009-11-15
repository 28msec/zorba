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

#include "api/serialization/serializer.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/debug/debug.h"
#include "runtime/util/iterator_impl.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "system/globalenv.h"

namespace zorba 
{

//Debug iterators:trace
bool
TraceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  TraceIteratorState *state;
  DEFAULT_STACK_INIT(TraceIteratorState, state, planState);

  if (!consumeNext(state->theTagItem, theChildren[1], planState)) {
    ZORBA_ERROR_LOC_DESC( FORG0006, loc,
        "An empty sequence is not allowed as as second argument to fn:trace");
  }

  state->theOS = theSctx->get_trace_stream();

  while (consumeNext(result, theChildren[0], planState)) 
  {
    (*state->theOS) << state->theTagItem->getStringValue() 
      << " [" << state->theIndex << "]: "
      << result->show()
      << std::endl;
    ++state->theIndex;

    STACK_PUSH(true, state);
  }


  STACK_END (state);
}

//Debug iterators:read-line
bool
ReadLineIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  xqpStringStore_t xstr;
  char str [512];
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  std::cin.getline (str, sizeof (str));
  xstr = new xqpStringStore (str);
  GENV_ITEMFACTORY->createString (result, xstr);
  STACK_PUSH (true, state);
  STACK_END (state);
}

//Debug iterators:print

// TODO: This print iterator has to be removed and the classes that need
// to be serialized have to implement the zorba:intern::Serializable
// interface.
bool PrintIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  std::ostringstream os;
  serializer* lSerializer = NULL;
  store::Item_t item;
  xqpStringStore_t resString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (CONSUME (item, theChildren.size () - 1))
  {
    if (item->isNode())
    {
      if (lSerializer == NULL)
      {
        lSerializer = new serializer(planState.theCompilerCB->theErrorManager);
        lSerializer->setParameter("omit-xml-declaration", "yes");
      }

      // TODO: This print iterator has to be removed and the classes that need
      // to be serialized have to implement the zorba:intern::Serializable
      // interface.
      if (thePrintToConsole) {
        // lSerializer->serialize(item.getp(), std::cout);
      } else {
        // lSerializer->serialize(item.getp(), os);
      }
    }
    else
    {
      if (thePrintToConsole) {
          std::cout << item->getStringValue ();
      } else {
        os << item->getStringValue();
      }
    }
  }
  if (!thePrintToConsole) {
    resString = new xqpStringStore(os.str());
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resString) , state);
  }
  STACK_END (state);
}

} /* namespace zorba */
