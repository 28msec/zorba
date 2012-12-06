/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#include "runtime/reference/reference.h"
//#include "zorbamisc/ns_consts.h"

#include "system/globalenv.h"
#include "context/static_context.h"

#include "store/api/item.h"
//#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

//#include "util/string_util.h"
//#include "util/uri_util.h"
//#include "zorbautils/string_util.h"

using namespace std;

namespace zorba {

/*******************************************************************************

********************************************************************************/
bool
ReferenceIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  store::Item_t lItem;
  bool lHasRef;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lItem, theChildren[0].getp(), aPlanState);

  try
  {
    lHasRef = GENV_STORE.getNodeReference(aResult, lItem);
  }
  catch (ZorbaException& e)
  {
    set_source( e, loc );
    throw;
  }
  STACK_PUSH(lHasRef, state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
HasReferenceIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  store::Item_t lItem;
  xs_boolean lHasReference;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lItem, theChildren[0].getp(), aPlanState);

  lHasReference = GENV_STORE.hasReference(lItem);

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, lHasReference), state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
AssignReferenceIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  store::Item_t lItem;
  store::Item_t lUUID;
  xs_boolean lHaveResult;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lItem, theChildren[0].getp(), aPlanState);
  consumeNext(lUUID, theChildren[1].getp(), aPlanState);
  try
  {
    lHaveResult = GENV_STORE.assignReference(lItem, lUUID->getStringValue());
  }
  catch (ZorbaException& e)
  {
    set_source( e, loc );
    throw;
  }
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, lHaveResult), state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
DereferenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUUID;
  bool haveResult;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUUID, theChildren[0].getp(), planState);
  try
  {
    haveResult = GENV_STORE.getNodeByReference(result, lUUID->getStringValue());
  }
  catch (ZorbaException& e)
  {
    set_source( e, loc );
    throw;
  }
  STACK_PUSH(haveResult, state);

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
