
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
  UnaryBaseIterator<NodeDistinctIterator>::reset(planState);

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

  Iterator_t input = new PlanIterWrapper(theChild, planState);

  state->theStoreIterator = Store::getInstance().distinctNodeStable(input);
}


}
