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

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"

#include "runtime/context/ContextImpl.h"
#include "runtime/api/runtimecb.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/collection.h"

#include "api/collectionimpl.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "CollectionsImpl.h"

namespace zorba {

bool
ZorbaCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaCollectionIterator not implemented");

  STACK_END (state);
}

void
ZorbaListCollectionsState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  uriItState = NULL;
}

void
ZorbaListCollectionsState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  uriItState = NULL;
}

bool
ZorbaListCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ZorbaListCollectionsState * state;
  store::Iterator_t           uriItState;
  store::Item_t               uriItem;

  DEFAULT_STACK_INIT(ZorbaListCollectionsState, state, planState);

  for ((state->uriItState = GENV_STORE.listCollectionsUri())->open ();
       state->uriItState->next(uriItem); )
  {
    result = uriItem;
    STACK_PUSH( true, state);
  }

  STACK_END (state);
}

bool
ZorbaCreateCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       itemUri, itemNode;
  xqpStringStore_t    strURI, strResult, strBaseURI;
//   URI::error_t        err;
  store::Collection_t theColl;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  /*
  //if it is not a valix xs:anyURI
  if(!URI::is_valid(strURI, true) && !URI::is_valid(strURI, false))
    ZORBA_ERROR_LOC_DESC (FORG0002, loc, "Invalid uri given to fn:CreateCollection");

  //if this is a relative URI resolve it against the baseuri() property of the static context
  else if(URI::is_valid(strURI, false))
  {
    strBaseURI = planState.theRuntimeCB->theStaticContext->baseuri().getStore();
    err = URI::resolve_relative (strBaseURI, strURI, strResult);

    switch (err)
    {
      case URI::INVALID_URI:
        ZORBA_ERROR_LOC_DESC (FORG0002, loc, "Invalid uri given to fn:CreateCollection");
        break;
      case URI::RESOLUTION_ERROR:
        ZORBA_ERROR_LOC_DESC (FORG0009, loc, "Error in resolving a relative URI against a base URI in fn:resolve-uri.");
        break;
      case URI::MAX_ERROR_CODE:
        break;
    }
    theColl = GENV_STORE.createCollection(strResult);
  }
  else
  */
    theColl = GENV_STORE.createCollection(strURI);

  if(theChildren.size() == 2)
    //add the nodes to the newly created collection
    while (consumeNext(itemNode, theChildren[1].getp(), planState))
      ((CollectionImpl*)theColl.getp())->addNode(itemNode.getp());

  STACK_END (state);
}

bool
ZorbaDeleteCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       itemUri;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState ))
    GENV_STORE.deleteCollection(itemUri->getStringValue());

  STACK_END (state);
}

bool
ZorbaDeleteAllCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  GENV_STORE.deleteAllCollections();

  STACK_END (state);
}

bool
ZorbaInsertNodeFirstIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemNode;
  xqpStringStore_t    strURI;
  int                 pos = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  //add the nodes to the newly created collection
  while (consumeNext(itemNode, theChildren[1].getp(), planState))
    ((CollectionImpl*)theColl.getp())->addNode(itemNode.getp(), pos++);

  STACK_END (state);
}

bool
ZorbaInsertNodeLastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemNode;
  xqpStringStore_t    strURI;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  //add the nodes to the newly created collection
  while (consumeNext(itemNode, theChildren[1].getp(), planState))
    ((CollectionImpl*)theColl.getp())->addNode(itemNode.getp(), -1);

  STACK_END (state);
}

bool
ZorbaInsertNodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  xqpStringStore_t    strURI;
  store::Item_t       itemUri, itemTarget, itemNewNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  if(consumeNext(itemTarget, theChildren[1].getp(), planState))
  {
    //add the nodes to the newly created collection
    while (consumeNext(itemNewNode, theChildren[2].getp(), planState))
      ((CollectionImpl*)theColl.getp())->addNode(itemNewNode.getp(), itemTarget.getp(), true);
  }

  STACK_END (state);
}

bool
ZorbaInsertNodeAfterIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  xqpStringStore_t    strURI;
  store::Item_t       itemUri, itemTarget, itemNewNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  if(consumeNext(itemTarget, theChildren[1].getp(), planState))
  {
    //add the nodes to the newly created collection
    while (consumeNext(itemNewNode, theChildren[2].getp(), planState))
      ((CollectionImpl*)theColl.getp())->addNode(itemNewNode.getp(), itemTarget.getp(), false);
  }

  STACK_END (state);
}

bool
ZorbaInsertNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemPos, itemNode;
  xqpStringStore_t    strURI;
  int                 pos = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  if(consumeNext(itemPos, theChildren[1].getp(), planState))
  {
    if(itemPos->getIntegerValue() < Integer::zero())
      pos = itemPos->getIntValue();

    //add the nodes to the newly created collection
    while (consumeNext(itemNode, theChildren[2].getp(), planState))
      ((CollectionImpl*)theColl.getp())->addNode(itemNode.getp(), pos++);
  }

  STACK_END (state);
}

bool
ZorbaRemoveNodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  xqpStringStore_t    strURI;
  store::Item_t       itemUri, itemTarget;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  //delete the nodes
  while (consumeNext(itemTarget, theChildren[1].getp(), planState))
    ((CollectionImpl*)theColl.getp())->deleteNode(itemTarget.getp());

  STACK_END (state);
}

bool
ZorbaRemoveNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  xqpStringStore_t    strURI;
  store::Item_t       itemUri, itemPos;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  //delete the node
  if (consumeNext(itemPos, theChildren[1].getp(), planState))
  {
    if(itemPos->getIntegerValue() >= Integer::zero())
      ((CollectionImpl*)theColl.getp())->deleteNode(itemPos->getIntValue());
  }

  STACK_END (state);
}

bool
ZorbaNodeCountIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri;
  xqpStringStore_t    strURI;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(
             result,
             Integer::parseInt(((CollectionImpl*)theColl.getp())->size())), state);

  STACK_END (state);
}

bool
ZorbaNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemPos;
  xqpStringStore_t    strURI;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

  theColl = GENV_STORE.getCollection(strURI);

  if (consumeNext(itemPos, theChildren[1].getp(), planState))
  {
    if(itemPos->getIntegerValue() >= Integer::zero())
      STACK_PUSH(theColl->nodeAt(itemPos->getIntValue()), state);
  }

  STACK_END (state);
}

bool
ZorbaExportCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaExportCollectionIterator not implemented");
  
  STACK_END (state);
}

} /* namespace zorba */
