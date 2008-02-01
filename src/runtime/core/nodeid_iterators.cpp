
#include "runtime/core/nodeid_iterators.h"

namespace xqp 
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

Item_t NodeDistinctIterator::nextImpl(PlanState& planState)
{
  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);

  return state->theStoreIterator->next();
}

void NodeDistinctIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  this->stateOffset = offset;
  offset += getStateSize();

  NodeDistinctState* state = new (planState.theBlock + stateOffset) NodeDistinctState;

  Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  state->theStoreIterator = Store::getInstance().distinctNodes(input, theAcceptAtomics);
  theChild->open(planState, offset);
}


void NodeDistinctIterator::resetImpl(PlanState& planState)
{
  StateTraitsImpl<NodeDistinctState>::reset(planState, this->stateOffset);

  theChild->reset(planState);
}


void NodeDistinctIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);

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

  Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  NodeSortState* state;
  GET_STATE(NodeSortState, state, planState);
  state->theStoreIterator = Store::getInstance().sortNodes(input,
                                                           theAscendant,
                                                           theDistinct,
                                                           theAcceptAtomics);
  theChild->open(planState, offset);
}

Item_t NodeSortIterator::nextImpl(PlanState& planState)
{
  NodeSortState* state;
  GET_STATE(NodeSortState, state, planState);

  return state->theStoreIterator->next();
}


void NodeSortIterator::resetImpl(PlanState& planState)
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
