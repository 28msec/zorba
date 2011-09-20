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
#include "stdafx.h"

#include "system/globalenv.h"

#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/binary.h"

#include "runtime/base64/base64.h"


#include "store/api/item.h"
#include "store/api/item_factory.h"

namespace zorba {

bool Base64DecodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  Base64 lDecodedData;
  zstring lResultString;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState))
  {
    lDecodedData = lItem->getBase64BinaryValue();
    lResultString = lDecodedData.decode().str();
    GENV_ITEMFACTORY->createString(result, lResultString);
    STACK_PUSH (true, state);
  }

  STACK_END (state);
}


bool Base64EncodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  Base64        lBase64;
  zstring       lTmpString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) 
  {
    lItem->getStringValue2(lTmpString);
    Base64::encode(lTmpString, lBase64);
    if (GENV_ITEMFACTORY->createBase64Binary(result, lBase64)) 
    {
      STACK_PUSH (true, state);
    }
    else
    {
      throw XQUERY_EXCEPTION(
        zerr::ZXQP0025_ITEM_CREATION_FAILED, ERROR_LOC( loc )
      );
    } 
  }
  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
