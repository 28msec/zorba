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

#include "compiler/api/compilercb.h"

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/store.h"
#include "store/api/item.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(NodeDistinctIterator)

SERIALIZABLE_CLASS_VERSIONS(NodeSortIterator)


/*******************************************************************************

********************************************************************************/
NodeDistinctState::~NodeDistinctState()
{
}


void NodeDistinctState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}


void NodeDistinctState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theStoreIterator->reset();
}


NodeDistinctIterator::NodeDistinctIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t input,
    bool acceptAtomics,
    bool checkDistinct)
  :
  UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>(sctx, loc, input),
  theAcceptAtomics(acceptAtomics),
  theCheckDistinct(checkDistinct)
{
}


void NodeDistinctIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>*)this);

  ar & theAcceptAtomics;
  ar & theCheckDistinct;
}


void NodeDistinctIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>::
  openImpl(planState, offset);

  NodeDistinctState* state;
  state = StateTraitsImpl<NodeDistinctState>::getState(planState, theStateOffset);

  store::Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  state->theStoreIterator = (theCheckDistinct ?
                             GENV.getStore().checkDistinctNodes(input) :
                             GENV.getStore().distinctNodes(input, theAcceptAtomics));
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
NodeSortState::~NodeSortState()
{
}


void NodeSortState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}


void NodeSortState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theStoreIterator->reset();
}


void NodeSortIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (UnaryBaseIterator<NodeSortIterator, NodeSortState>*)this);
  ar & theAscendant;
  ar & theDistinct;
  ar & theAcceptAtomics;
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
/* vim:set et sw=2 ts=2: */
