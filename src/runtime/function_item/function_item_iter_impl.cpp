#include "runtime/function_item/function_item_iter.h"

#include <vector>

#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/function_item/store_iterator.h"

#include "compiler/parsetree/parsenodes.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"


using namespace std;

namespace zorba {

/*******************************************************************************
 ******************************************************************************/
 void
 DynamicFunctionInvocationIteratorState::init(PlanState& planState)
 {
  PlanIteratorState::init(planState);
 }

/*******************************************************************************
 ******************************************************************************/
 void
 DynamicFunctionInvocationIteratorState::reset(PlanState& planState)
 {
  PlanIteratorState::reset(planState);
 }

/*******************************************************************************
 ******************************************************************************/
bool
DynamicFunctionInvocationIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const

{
#ifndef DEBUG
  ZORBA_ASSERT(theChildren.size() == 1);
#endif
  PlanIterator* lChild = theChildren[0].getp();
  store::Item_t lFunctionItem, lItem;
  DynamicFunctionInvocationIteratorState* state;

  DEFAULT_STACK_INIT(DynamicFunctionInvocationIteratorState, state, planState);

  // first child must return exactly one item which is a function item
  if (!consumeNext(lFunctionItem, lChild, planState) &&
      !lFunctionItem->isFunction() &&
      consumeNext(lItem, lChild, planState)) {
    ZORBA_ERROR_LOC(XPTY0004, loc);
  }

  state->thePlan = lFunctionItem->getFunctionImplementation();

  // Bind the function arguments if any
  if (theArgs.size() > 0) {

    store::FunctionItemIterator* lFuncIter =
#ifndef NDEBUG
      dynamic_cast<store::FunctionItemIterator*>(state->thePlan.getp());
#else
      static_cast<store::FunctionItemIterator*>(state->thePlan.getp());
#endif
    ZORBA_ASSERT(lFuncIter != 0);

    //We bind the scoped variables
    vector<store::Iterator_t> lScopedVariables;
    lFunctionItem->getFunctionVariables(lScopedVariables);
    vector<store::Iterator_t>::const_iterator lIter = lScopedVariables.begin();
    for(; lIter != lScopedVariables.end(); ++lIter)
    {
      PlanIterator_StoreIteratorWrapper* lWrapper = dynamic_cast<PlanIterator_StoreIteratorWrapper *>((*lIter).getp());  
      lFuncIter->addArg(lWrapper->getPlanIterator());
    }

    //We bind the args
    
    vector<PlanIter_t>::const_iterator lIt = theArgs.begin();
    for(; lIt != theArgs.end(); ++lIt) {
      lFuncIter->addArg(*lIt); 
    }
    
  }
  
  state->thePlan->open();
  while(state->thePlan->next(r)) {
    STACK_PUSH(true, state);
  }
  state->thePlan->close();
  state->thePlan = 0;

  STACK_END(state);
};

}//zorba namespace
