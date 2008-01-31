/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "runtime/fncontext/FnContextImpl.h"
#include "api/external/xquery.h"
#include "context/dynamic_context.h"
#include "runtime/core/item_iterator.h"

namespace xqp
{




CtxVariableIterator::CtxVariableIterator(
    const yy::location& loc,
    xqp_string aVarname)
  : 
  NoaryBaseIterator<CtxVariableIterator, PlanIteratorState>(loc),
  theVarName(aVarname)
{
}


CtxVariableIterator::~CtxVariableIterator()
{
}


Item_t CtxVariableIterator::nextImpl(PlanState& planState)
{
  Item_t item;
  Iterator_t iter;

  PlanIteratorState* aState;
  GET_STATE(PlanIteratorState, aState, planState);

  MANUAL_STACK_INIT(aState);

  FINISHED_ALLOCATING_RESOURCES();

  iter = ZORBA_FOR_CURRENT_THREAD()->
         current_xquery->internal_dyn_context->get_variable(theVarName);

  if (iter == NULL)
    ZORBA_ERROR_ALERT (ZorbaError::XPDY0002, &loc, false, theVarName);

  do
  {
    item = iter->next();
    STACK_PUSH (item , aState);
  }
  while(item != NULL);
  
  while(true)
  {
    STACK_PUSH (NULL , aState);
  }
  STACK_END();
}

void CtxVariableIterator::resetImpl(PlanState& planState)
{
  PlanIteratorState* state;
  GET_STATE ( PlanIteratorState, state, planState );
  state->reset(planState);

  Iterator_t iter;

  iter = ZORBA_FOR_CURRENT_THREAD()->
         current_xquery->internal_dyn_context->get_variable(theVarName);

  iter->reset();
}


void CtxVariableIterator::closeImpl(PlanState& planState)
{
  Iterator_t iter;

  Zorba* zorba = ZORBA_FOR_CURRENT_THREAD();

  iter = zorba->current_xquery->internal_dyn_context->get_variable(theVarName);

  if (iter != NULL)
    iter->close();

  PlanIteratorState* state;
  GET_STATE ( PlanIteratorState, state, planState );
  state->~PlanIteratorState();
}

}
