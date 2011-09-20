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

#include <fstream>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "system/globalenv.h"

#include "runtime/introspection/dctx.h"

#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/store.h"
#include "store/api/collection.h"
#include "store/api/index.h"
#include "store/api/ic.h"

namespace zorba 
{

class StaticallyKnownCollection;


// implemented in collections_impl.cpp
store::Collection_t getCollection(
    const static_context* aSctx,
    const store::Item_t,
    const QueryLoc&);

const StaticallyKnownCollection* getCollectionDecl(
    const static_context* aSctx,
    const store::Item_t aName,
    const QueryLoc& aLoc);


/*******************************************************************************

********************************************************************************/
bool IsAvailableCollectionIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t       lName;
  store::Collection_t lCollection;
  bool                res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  res = true;
  try 
  {
    (void)getCollectionDecl(theSctx, lName, loc);

    lCollection = getCollection(theSctx, lName, loc);
  }
  catch (ZorbaException const& e)
  {
    if (e.diagnostic() != zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST)
    {
      throw;
    }

    // collection is not available if the getCollection helper function throws
    // error ZDDY0003_COLLECTION_DOES_NOT_EXIST
    res = false;
  }

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state );

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
AvailableCollectionsIteratorState::~AvailableCollectionsIteratorState()
{
  if ( nameItState != NULL ) 
  {
    nameItState->close();
    nameItState = NULL;
  }
}


void AvailableCollectionsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}


void AvailableCollectionsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}


bool
AvailableCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  AvailableCollectionsIteratorState * state;
  store::Item_t              nameItem;

  DEFAULT_STACK_INIT(AvailableCollectionsIteratorState, state, planState);

  for ((state->nameItState = GENV_STORE.listCollectionNames())->open ();
       state->nameItState->next(nameItem); ) 
  {
    result = nameItem;
    STACK_PUSH( true, state);
  }

  state->nameItState->close();

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool IsAvailableIndexIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lName;
  bool res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  {
    store::Index_t lIndex = GENV_STORE.getIndex(lName);
    res = (lIndex != 0);
  }

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
AvailableIndexesIteratorState::~AvailableIndexesIteratorState()
{
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

void
AvailableIndexesIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}

void
AvailableIndexesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

bool
AvailableIndexesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t              nameItem;

  AvailableIndexesIteratorState * state;
  DEFAULT_STACK_INIT(AvailableIndexesIteratorState, state, planState);

  for ((state->nameItState = GENV_STORE.listIndexNames())->open ();
       state->nameItState->next(nameItem); ) 
  {
    result = nameItem;
    STACK_PUSH( true, state);
  }

  state->nameItState->close();

  STACK_END (state);
}

/*******************************************************************************
*******************************************************************************/
bool IsActivatedICIterator::nextImpl(store::Item_t& result, 
                                     PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       lName;
  bool                res = false;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  {
    store::IC_t lIc = GENV_STORE.getIC(lName);
    res = (lIc != 0);
  }

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state );

  STACK_END (state);
}

/*******************************************************************************
*******************************************************************************/
ActivatedICsIteratorState::~ActivatedICsIteratorState()
{
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

void
ActivatedICsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}

void
ActivatedICsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

bool
ActivatedICsIterator::nextImpl(store::Item_t& result, 
                               PlanState& planState) const
{
  store::Item_t              nameItem;

  ActivatedICsIteratorState * state;
  DEFAULT_STACK_INIT(ActivatedICsIteratorState, state, planState);

  for ((state->nameItState = GENV_STORE.listActiveICNames())->open ();
       state->nameItState->next(nameItem); ) 
  {
    result = nameItem;
    STACK_PUSH( true, state);
  }

  state->nameItState->close();

  STACK_END (state);
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
