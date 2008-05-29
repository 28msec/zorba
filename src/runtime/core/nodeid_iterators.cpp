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
#include "store/api/store.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/api/plan_iterator_wrapper.h"

namespace zorba 
{

/*******************************************************************************

********************************************************************************/
void
NodeDistinctState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}

void
NodeDistinctState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theStoreIterator->reset();
}

bool NodeDistinctIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  NodeDistinctState* state;
  state = StateTraitsImpl<NodeDistinctState>::getState(planState, this->stateOffset);

  return state->theStoreIterator->next(result);
}

void NodeDistinctIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  this->stateOffset = offset;
  offset += getStateSize();

  NodeDistinctState* state = new (planState.theBlock + stateOffset) NodeDistinctState;

  store::Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  state->theStoreIterator = GENV.getStore().distinctNodes(input, theAcceptAtomics);
  state->theStoreIterator->open();
  theChild->open(planState, offset);
}


void NodeDistinctIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<NodeDistinctState>::reset(planState, this->stateOffset);

  theChild->reset(planState);
}


void NodeDistinctIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);
  // Question: do we need to call state->theStoreIterator->close() ?

  StateTraitsImpl<NodeDistinctState>::destroyState(planState, this->stateOffset);
}

/*******************************************************************************

********************************************************************************/
void
NodeSortState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}

void
NodeSortState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theStoreIterator->reset();
}

void NodeSortIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<NodeSortState>::createState(planState, this->stateOffset, offset);

  theChild->open(planState, offset);
  store::Iterator_t input = new PlanIteratorWrapper(theChild, planState);
  // input->open();

  NodeSortState* state;
  state = StateTraitsImpl<NodeSortState>::getState(planState, this->stateOffset);

  state->theStoreIterator = GENV.getStore().sortNodes(input,
                                                           theAscendant,
                                                           theDistinct,
                                                           theAcceptAtomics);
  state->theStoreIterator->open();
}

bool NodeSortIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  NodeSortState* state;
  state = StateTraitsImpl<NodeSortState>::getState(planState, this->stateOffset);

  return state->theStoreIterator->next(result);
}


void NodeSortIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<NodeSortState>::reset(planState, this->stateOffset);


  theChild->reset(planState);
}


void NodeSortIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);
  
  StateTraitsImpl<NodeSortState>::destroyState(planState, this->stateOffset);
}

}
