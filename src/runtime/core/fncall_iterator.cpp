#include "errors/error_factory.h"
#include "runtime/core/fncall_iterator.h"

namespace xqp {

Item_t UDFunctionCallIterator::nextImpl(PlanState& planState)
{
  Item_t lSequenceItem;
  UDFunctionCallIteratorState *state;
  DEFAULT_STACK_INIT(UDFunctionCallIteratorState, state, planState);

  state->thePlan = theUDF->get_plan().get_ptr();
  state->theFnBodyStateBlock = theUDF->create_plan_state();
  state->thePlan->reset(*state->theFnBodyStateBlock);

  while((lSequenceItem = state->thePlan->produceNext(*state->theFnBodyStateBlock)) != NULL) {
    STACK_PUSH(lSequenceItem, state);
  }

  STACK_END();
}

UDFunctionCallIterator::UDFunctionCallIteratorState::UDFunctionCallIteratorState()
  : theFnBodyStateBlock(NULL),
  thePlan(NULL) { }

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
  reset();
}

void UDFunctionCallIterator::UDFunctionCallIteratorState::reset()
{
  if (theFnBodyStateBlock != NULL) {
    delete theFnBodyStateBlock;
  }
  theFnBodyStateBlock = NULL;
  thePlan = NULL;
}

}

/* vim:set ts=2 sw=2: */
