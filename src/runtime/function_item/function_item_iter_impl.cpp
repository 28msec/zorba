#include "runtime/function_item/function_item_iter.h"

#include <vector>

#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/function_item/store_iterator.h"
#include "runtime/function_item/function_item.h"

#include "compiler/parsetree/parsenodes.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "store/api/item_factory.h"


using namespace std;

namespace zorba {

/*******************************************************************************
 ******************************************************************************/
void
DynamicFunctionInvocationIteratorState::init(PlanState& planState)
{
   PlanIteratorState::init(planState);
   thePlan = NULL;
   theIsOpen = false;
}

/*******************************************************************************
 ******************************************************************************/
void
DynamicFunctionInvocationIteratorState::reset(PlanState& planState)
{
   PlanIteratorState::reset(planState);
   if (theIsOpen) {
     thePlan->reset();
   }
}

/*******************************************************************************
 ******************************************************************************/
DynamicFunctionInvocationIteratorState::~DynamicFunctionInvocationIteratorState()
{
  if (theIsOpen) {
    thePlan->close();
  }
}

/*******************************************************************************
 ******************************************************************************/
bool
DynamicFunctionInvocationIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  PlanIterator* lChild = theChildren[0].getp();
  store::Item_t lFItem, lItem;
  store::FunctionItem*         lFunctionItem;
  store::FunctionItemIterator* lFuncIter = 0;
  std::vector<PlanIter_t>      lScopedVariables;

  DynamicFunctionInvocationIteratorState* state;

  DEFAULT_STACK_INIT(DynamicFunctionInvocationIteratorState, state, planState);

  // first child must return exactly one item which is a function item
  // otherwise XPTY0004 is raised
  if (!consumeNext(lFItem, lChild, planState) &&
      !lFItem->isFunction() &&
      consumeNext(lItem, lChild, planState)) {
    ZORBA_ERROR_LOC(XPTY0004, loc);
  }

  lFunctionItem = static_cast<store::FunctionItem*>(lFItem.getp());
  state->thePlan = lFunctionItem->getFunctionImplementation();
  lFuncIter = static_cast<store::FunctionItemIterator*>(state->thePlan.getp());

  lFunctionItem->getFunctionVariables(lScopedVariables);
  {
    vector<PlanIter_t>::const_iterator lIter = lScopedVariables.begin();
    for(; lIter != lScopedVariables.end(); ++lIter) {
      lFuncIter->addArg(*lIter);
    }
  }

  {
    vector<PlanIter_t>::const_iterator lIter = theFunctionArgs.begin();
    for(; lIter != theFunctionArgs.end(); ++lIter) {
      lFuncIter->addArg(*lIter); 
    }
  }

  // must be opened after vars and params are set
  state->thePlan->open();
  state->theIsOpen = true;
  
  while(state->thePlan->next(r)) {
    STACK_PUSH(true, state);
  }

  // need to close here early in case the plan is completely
  // consumed. Otherwise, the plan would still be opened
  // if destroyed from the state's destructor.
  state->thePlan->close();
  state->theIsOpen = false;

  STACK_END(state);
};

/*******************************************************************************
 ******************************************************************************/
bool
FunctionNameIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  store::Item_t        lFItem;
  store::FunctionItem* lFunctionItem = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lFItem, theChildren[0], planState);

  // function signature guarantees that
  ZORBA_ASSERT(lFItem->isFunction());

  lFunctionItem = static_cast<store::FunctionItem*>(lFItem.getp());

  if (lFunctionItem->getFunctionName()) {
    // non-inline function
    r = lFunctionItem->getFunctionName();
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}

/*******************************************************************************
 ******************************************************************************/
bool
FunctionArityIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  store::Item_t        lFItem;
  store::FunctionItem* lFunctionItem = 0;
  xqp_integer          lInt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lFItem, theChildren[0], planState);

  // function signature guarantees that
  ZORBA_ASSERT(lFItem->isFunction());

  lFunctionItem = static_cast<store::FunctionItem*>(lFItem.getp());

  lInt = Integer::parseUInt(lFunctionItem->getFunctionArity());

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(r, lInt), state);

  STACK_END(state);
}


}//zorba namespace
