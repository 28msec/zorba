#include "errors/error_factory.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/fncall_iterator.h"
#include "functions/function.h"

namespace xqp {

Item_t UDFunctionCallIterator::nextImpl(PlanState& planState)
{
  Item_t lSequenceItem;
  UDFunctionCallIteratorState *state;
  GET_STATE(UDFunctionCallIteratorState, state, planState);
  MANUAL_STACK_INIT(state);
  state->init(planState);
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

UDFunctionCallIteratorState::UDFunctionCallIteratorState()
  : theFnBodyStateBlock(NULL),
    thePlan(NULL) { }

UDFunctionCallIteratorState::~UDFunctionCallIteratorState()
{
  if (theFnBodyStateBlock != NULL) {
    delete theFnBodyStateBlock;
  }
}

void UDFunctionCallIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  reset(planState);
}

void UDFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (theFnBodyStateBlock != NULL) {
    delete theFnBodyStateBlock;
  }

  theFnBodyStateBlock = NULL;
  thePlan = NULL;
}


}

/* vim:set ts=2 sw=2: */
