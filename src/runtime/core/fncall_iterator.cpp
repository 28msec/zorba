#include "errors/error_factory.h"
#include "runtime/core/fncall_iterator.h"

namespace xqp {

Item_t UDFunctionCallIterator::nextImpl(PlanState& planState)
{
  return NULL;
}

void UDFunctionCallIterator::resetImpl(PlanState& planState)
{
  NaryBaseIterator<UDFunctionCallIterator>::resetImpl(planState);

  UDFunctionCallIteratorState* state;
  GET_STATE(UDFunctionCallIteratorState, state, planState);
  state->reset();
}

void UDFunctionCallIterator::releaseResourcesImpl(PlanState& planState)
{
  NaryBaseIterator<UDFunctionCallIterator>::releaseResourcesImpl(planState);
  
  UDFunctionCallIteratorState* state;
  GET_STATE(UDFunctionCallIteratorState, state, planState);
  
  // do we need a releaseResouces function in the state or is it always the same as reset?
  state->reset(); 
}

void UDFunctionCallIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<UDFunctionCallIterator>::setOffset(planState, offset);
  UDFunctionCallIteratorState* state = 
    new (planState.block + stateOffset) UDFunctionCallIteratorState;
}

void UDFunctionCallIterator::UDFunctionCallIteratorState::init()
{
}

void UDFunctionCallIterator::UDFunctionCallIteratorState::reset()
{
}

}

/* vim:set ts=2 sw=2: */
