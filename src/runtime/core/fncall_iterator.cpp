#include "errors/error_factory.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/fncall_iterator.h"

namespace xqp {

Item_t UDFunctionCallIterator::nextImpl(PlanState& planState)
{
  Item_t lSequenceItem;
  UDFunctionCallIteratorState *state;
  GET_STATE(UDFunctionCallIteratorState, state, planState);
  MANUAL_STACK_INIT(state);
  state->init();
  FINISHED_ALLOCATING_RESOURCES();

  state->thePlan = theUDF->get_plan().getp();
  state->theFnBodyStateBlock = theUDF->create_plan_state();

  // Bind the args.
  {
    uint32_t nargs = theUDF->get_params().size();
    std::vector<ref_iter_t>& iters = theUDF->get_param_iters();
    for(uint32_t i = 0; i < nargs; ++i) {
      ref_iter_t& ref = iters[i];
      if (ref != NULL) {
        ref->bind(new PlanIteratorWrapper(theChildren[i], planState), *state->theFnBodyStateBlock);
      }
    }
  }

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
    new (planState.theBlock + stateOffset) UDFunctionCallIteratorState;
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
