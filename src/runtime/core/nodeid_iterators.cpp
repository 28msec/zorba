
#include "runtime/core/nodeid_iterators.h"

namespace xqp 
{

/*******************************************************************************

********************************************************************************/
Item_t NodeDistinctIterator::nextImpl(PlanState& planState)
{
  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);

  return state->theStoreIterator->next();
}


void NodeDistinctIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<NodeDistinctIterator>::resetImpl(planState);

  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);
  state->theStoreIterator->reset();
}


void NodeDistinctIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<NodeDistinctIterator>::releaseResourcesImpl(planState);

  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);
  state->theStoreIterator = NULL;
}


void NodeDistinctIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<NodeDistinctIterator>::setOffset(planState, offset);

  NodeDistinctState* state = new (planState.block + stateOffset) NodeDistinctState;

  Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  state->theStoreIterator = Store::getInstance().distinctNodes(input);
}


/*******************************************************************************

********************************************************************************/
Item_t NodeSortIterator::nextImpl(PlanState& planState)
{
  NodeSortState* state;
  GET_STATE(NodeSortState, state, planState);

  return state->theStoreIterator->next();
}


void NodeSortIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<NodeSortIterator>::resetImpl(planState);

  NodeSortState* state;
  GET_STATE(NodeSortState, state, planState);
  state->theStoreIterator->reset();
}


void NodeSortIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<NodeSortIterator>::releaseResourcesImpl(planState);

  NodeSortState* state;
  GET_STATE(NodeSortState, state, planState);
  state->theStoreIterator = NULL;
}


void NodeSortIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<NodeSortIterator>::setOffset(planState, offset);

  NodeSortState* state = new (planState.block + stateOffset) NodeSortState;

  Iterator_t input = new PlanIteratorWrapper(theChild, planState);

  state->theStoreIterator = Store::getInstance().sortNodes(input,
                                                           theAscendant,
                                                           theDistinct);
}


}
