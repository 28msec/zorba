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

#include "runtime/store/identifiers.h"
#include "zorbamisc/ns_consts.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/naive/ordpath.h"

#include "util/string_util.h"
#include "util/uri_util.h"
#include "zorbautils/string_util.h"

using namespace std;

namespace zorba {

/*******************************************************************************
********************************************************************************/
bool
NodeIdentifierIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lNode;
  store::Item_t generateUUID;
  store::Item_t registerUUID;
  zstring lNodeId;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lNode, theChildren[0].getp(), planState);
  consumeNext(generateUUID, theChildren[1].getp(), planState);
  consumeNext(registerUUID, theChildren[2].getp(), planState);

  lNodeId=lNode->getUUID(generateUUID->getBooleanValue(),registerUUID->getBooleanValue());

  STACK_PUSH(
      GENV_ITEMFACTORY->createString
      (result,
        lNodeId
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
HasIdentifierIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lNode, theChildren[0].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean
      (result,
          lNode->hasUUID()
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
NodeByIdentifierIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
	  store::Item_t lUUID;

	  PlanIteratorState *state;
	  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

	  consumeNext(lUUID, theChildren[0].getp(), planState);

	  STACK_PUSH(
		  GENV_STORE.getNodeByUUID
		  	  (result,
			   lUUID->getStringValue()
			  ), state);

	  STACK_END (state);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
