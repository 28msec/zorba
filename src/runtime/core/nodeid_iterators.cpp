
#include "store/api/store.h"
#include "system/globalenv.h"
#include <zorba/item.h>
#include "runtime/core/nodeid_iterators.h"
#include "runtime/base/plan_iterator_wrapper.h"

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

store::Item_t NodeDistinctIterator::nextImpl(PlanState& planState) const
{
  NodeDistinctState* state;
  state = StateTraitsImpl<NodeDistinctState>::getState(planState, this->stateOffset);

  return state->theStoreIterator->next();
}

void NodeDistinctIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  this->stateOffset = offset;
  offset += getStateSize();

  NodeDistinctState* state = new (planState.theBlock + stateOffset) NodeDistinctState;

  Iterator_t input = new PlanIteratorWrapper(theChild, planState);

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
  Iterator_t input = new PlanIteratorWrapper(theChild, planState);
  // input->open();

  NodeSortState* state;
  state = StateTraitsImpl<NodeSortState>::getState(planState, this->stateOffset);

  state->theStoreIterator = GENV.getStore().sortNodes(input,
                                                           theAscendant,
                                                           theDistinct,
                                                           theAcceptAtomics);
  state->theStoreIterator->open();
}

store::Item_t NodeSortIterator::nextImpl(PlanState& planState) const
{
  NodeSortState* state;
  state = StateTraitsImpl<NodeSortState>::getState(planState, this->stateOffset);

  return state->theStoreIterator->next();
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
