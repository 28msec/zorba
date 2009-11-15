/*
 * Copyright 2006-2009 The FLWOR Foundation.
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

#include "runtime/indexing/value_index_context.h"
#include "runtime/visitors/planiter_visitor.h"

#include "context/static_context.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/index.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(IsAvailableIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IsAvailableIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(AvailableIndexesIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AvailableIndexesIterator)

SERIALIZABLE_CLASS_VERSIONS(IsDeclaredIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IsDeclaredIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(DeclaredIndexesIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DeclaredIndexesIterator)


NARY_ACCEPT(IsAvailableIndexIterator);
NARY_ACCEPT(AvailableIndexesIterator);
NARY_ACCEPT(IsDeclaredIndexIterator);
NARY_ACCEPT(DeclaredIndexesIterator);


bool
IsDeclaredIndexIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  PlanIteratorState *lState;
  store::Item_t      lName;

  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  consumeNext(lName, theChildren[0].getp(), aPlanState);
  if (theSctx->lookup_index(lName.getp()) == 0) {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( aResult, false ), lState);
  }
  else {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( aResult, true ), lState);   
  }
  STACK_END (lState);
}


IndexNamesListState::~IndexNamesListState()
{
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}


void IndexNamesListState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}


void IndexNamesListState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}


bool
DeclaredIndexesIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  IndexNamesListState * lState;
  store::Item_t              lName;

  DEFAULT_STACK_INIT(IndexNamesListState, lState, aPlanState);

  for ((lState->nameItState = theSctx->list_index_names())->open ();
       lState->nameItState->next(lName); ) 
  {
    aResult = lName;
    STACK_PUSH( true, lState);
  }

  lState->nameItState->close();

  STACK_END (lState);
}

bool
IsAvailableIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       lName;
  bool                res = false;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  {
    store::Index_t lIndex = GENV_STORE.getIndex(lName);
    res = (lIndex != 0);
  }

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state );

  STACK_END (state);
}


bool
AvailableIndexesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  IndexNamesListState * state;
  store::Item_t              nameItem;

  DEFAULT_STACK_INIT(IndexNamesListState, state, planState);

  for ((state->nameItState = GENV_STORE.listIndexNames())->open ();
       state->nameItState->next(nameItem); ) 
  {
    result = nameItem;
    STACK_PUSH( true, state);
  }

  state->nameItState->close();

  STACK_END (state);
}


} /* namespace zorba */
