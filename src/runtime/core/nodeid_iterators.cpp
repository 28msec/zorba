
#include "runtime/core/nodeid_iterators.h"

namespace xqp 
{

/*******************************************************************************

********************************************************************************/
Item_t NodeDistinctIterator::nextImpl(PlanState& planState)
{
  Item_t contextNode;

  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);

  while (true)
  {
    contextNode = consumeNext(theChild, planState);
    if (contextNode == NULL)
      return NULL;

    if (state->theHashSet.insert(contextNode).second)
      return contextNode;
  }
}


void NodeDistinctIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<NodeDistinctIterator>::reset(planState);

  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);
  state->theHashSet.clear();
}


void NodeDistinctIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<NodeDistinctIterator>::releaseResourcesImpl(planState);

  NodeDistinctState* state;
  GET_STATE(NodeDistinctState, state, planState);
  state->theHashSet.clear();
}


void NodeDistinctIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<NodeDistinctIterator>::setOffset(planState, offset);

  NodeDistinctState* state = new (planState.block + stateOffset) NodeDistinctState;
}


}
