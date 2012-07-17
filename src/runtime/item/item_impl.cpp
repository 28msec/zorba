/*
 * Copyright 2012 The FLWOR Foundation.
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

#include "runtime/item/item.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "util/mem_sizeof.h"

using namespace std;

namespace zorba {

/*******************************************************************************
********************************************************************************/
bool
MemSizeIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lItem;
  xs_integer    lSize;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lItem, theChildren[0].getp(), planState);

  lSize = xs_integer(ztd::mem_sizeof(lItem));

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, lSize), state);

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */

