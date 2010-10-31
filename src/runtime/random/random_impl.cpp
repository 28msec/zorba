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

#include "system/globalenv.h"

#include "runtime/random/random.h"

#include "zorbatypes/numconversions.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "util/uuid/uuid.h"
#include "zorbatypes/xqpstring.h"

namespace zorba {

bool
NumGenIterator::nextImpl ( store::Item_t& result, PlanState& planState ) const
{
  NumGenIteratorState* state;
  DEFAULT_STACK_INIT ( NumGenIteratorState, state, planState );

  while ( state->theCurNumber < 100 )
  {
    STACK_PUSH (
                GENV_ITEMFACTORY->createInteger (result, Integer::parseInt(state->theCurNumber) ),
                state );
    state->theCurNumber ++;
  }
  STACK_END (state);
}

bool
PseudoRandomIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t    item;
  zstring seed;
  xqp_uint         seedInt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if((theChildren.size() == 1) &&
      consumeNext(item, theChildren[0].getp(), planState))
  {
    seed = item->getIntegerValue().toString();
    NumConversions::strToUInt(seed.c_str(), seedInt);
    std::srand((unsigned int)seedInt);
  }
  else
  {
    std::srand((unsigned int)(time(NULL)));
  }

  GENV_ITEMFACTORY->createInteger(result, Integer::parseInt (std::rand()));
  STACK_PUSH (true, state);

  STACK_END (state);
}

bool
RandomIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t    item;
  zstring seed;
  xqp_uint         seedInt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if((theChildren.size() == 1) &&
      consumeNext(item, theChildren[0].getp(), planState))
  {
    seed = item->getIntegerValue().toString();
    NumConversions::strToUInt(seed.c_str(), seedInt);
    std::srand((unsigned int)seedInt);
  }
  else
  {
    std::srand((unsigned int)(time(NULL)));
  }

  GENV_ITEMFACTORY->createInteger(result, Integer::parseInt(std::rand()));
  STACK_PUSH (true, state);

  STACK_END (state);
}

bool
UuidIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  uuid_t  u;
  zstring uuidStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  memset(&u, 0, sizeof(uuid_t));

  uuid_create(&u);
  uuidStr = uuidToString(u);

  GENV_ITEMFACTORY->createString(result, uuidStr);
  STACK_PUSH(true, state);

  STACK_END (state);
}

} /* namespace zorba */
