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

#include "runtime/context/ContextImpl.h"
#include "runtime/api/runtimecb.h"

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

bool
ZorbaListCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaListCollectionsIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaCreateCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       itemUri, itemNode;
  xqpStringStore_t    strURI, strResult, strBaseURI;
  URI::error_t        err;
  store::Collection_t theColl;
  
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() == 1 && consumeNext(itemUri, theChildren[0].getp(), planState))
    strURI = itemUri->getStringValue();

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
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaDeleteCollectionIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaDeleteAllCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaDeleteAllCollectionsIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaInsertNodeFirstIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaInsertNodeFirstIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaInsertNodeLastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaInsertNodeLastIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaInsertNodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaInsertNodeBeforeIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaInsertNodeAfterIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaInsertNodeAfterIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaInsertNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaInsertNodeAtIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaRemoveNodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaRemoveNodeIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaRemoveNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaRemoveNodeAtIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaNodeCountIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaNodeCountIterator not implemented");
  
  STACK_END (state);
}

bool
ZorbaNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaNodeAtIterator not implemented");
  
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
