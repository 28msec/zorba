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

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/binary.h"

#include "runtime/util/UtilImpl.h"


namespace zorba {

bool
ZorbaSchemaTypeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    result = item->getType();
    STACK_PUSH(true, state );
  }

  STACK_END (state);
}

bool
ZorbaBase64DecodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t        lItem;
  Base64               lDecodedData;
  xqpStringStore_t     lResultString;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) {
    lDecodedData = lItem->getBase64BinaryValue();
    lResultString = lDecodedData.decode().getStore();
    GENV_ITEMFACTORY->createString(result, lResultString);
    STACK_PUSH (true, state);
  }

  STACK_END (state);
}

bool
ZorbaBase64EncodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  Base64        lBase64;
  xqpStringStore* lTmpString;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) {
    lTmpString = lItem->getStringValueP();
    Base64::encode(lTmpString, lBase64);
    if (GENV_ITEMFACTORY->createBase64Binary(result, lBase64)) {
      STACK_PUSH (true, state);
    } else {
      ZORBA_ERROR_LOC(XQP0025_COULD_NOT_CREATE_ITEM, loc);
    } 
  }
  STACK_END (state);
}

} /* namespace zorba */
