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
#include "system/globalenv.h"

#include "compiler/api/compilercb.h"

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/store.h"
#include "store/api/item.h"

namespace zorba 
{
SERIALIZABLE_CLASS_VERSIONS(NodeDistinctIterator)
END_SERIALIZABLE_CLASS_VERSIONS(NodeDistinctIterator)

SERIALIZABLE_CLASS_VERSIONS(NodeSortIterator)
END_SERIALIZABLE_CLASS_VERSIONS(NodeSortIterator)

/*******************************************************************************

********************************************************************************/
void NodeDistinctState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}


void NodeDistinctState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theStoreIterator->reset();
}


void NodeDistinctIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>::
  openImpl(planState, offset);

  NodeDistinctState* state;
  state = StateTraitsImpl<NodeDistinctState>::getState(planState, theStateOffset);

  store::Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  state->theStoreIterator = GENV.getStore().distinctNodes(input, theAcceptAtomics);
  state->theStoreIterator->open();
}


bool NodeDistinctIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  NodeDistinctState* state;
  state = StateTraitsImpl<NodeDistinctState>::getState(planState, theStateOffset);

  return state->theStoreIterator->next(result);
}


UNARY_ACCEPT(NodeDistinctIterator);


/*******************************************************************************

********************************************************************************/
void NodeSortState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}


void NodeSortState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theStoreIterator->reset();
}


void NodeSortIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<NodeSortIterator, NodeSortState>::
  openImpl(planState, offset);

  store::Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  NodeSortState* state;
  state = StateTraitsImpl<NodeSortState>::getState(planState, theStateOffset);

  state->theStoreIterator = GENV.getStore().sortNodes(input,
                                                      theAscendant,
                                                      theDistinct,
                                                      theAcceptAtomics);
  state->theStoreIterator->open();
}


bool NodeSortIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  NodeSortState* state;
  state = StateTraitsImpl<NodeSortState>::getState(planState, theStateOffset);

  return state->theStoreIterator->next(result);
}


UNARY_ACCEPT(NodeSortIterator);


}
