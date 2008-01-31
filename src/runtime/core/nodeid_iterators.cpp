
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
  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);
  state->reset(planState);

  state->theStoreIterator->reset();
  theChild->reset(planState);
}


void NodeDistinctIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);

  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);
  state->~NodeDistinctState();
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
}

void NodeSortIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  this->stateOffset = offset;
  offset += getStateSize();

  NodeSortState* state = new (planState.theBlock + stateOffset) NodeSortState;

  Iterator_t input = new PlanIteratorWrapper(theChild, planState);

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
  NodeSortState* state;
  GET_STATE(NodeSortState, state, planState);
  state->reset(planState);

  state->theStoreIterator->reset();

  theChild->reset(planState);
}


void NodeSortIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);

  NodeSortState* state;
  GET_STATE(NodeSortState, state, planState);
  state->~NodeSortState();
}

}
