/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf, Tim Kraska, Markos Zaharioudakis
 */

#include "store/api/iterator.h"
#include "runtime/fncontext/FnContextImpl.h"
#include "context/dynamic_context.h"
#include "runtime/core/item_iterator.h"
#include "runtime/api/runtimecb.h"

namespace zorba
{




CtxVariableIterator::CtxVariableIterator(
    const QueryLoc& loc,
    xqp_string aVarname)
  : 
  NoaryBaseIterator<CtxVariableIterator, CtxVariableIteratorState>(loc),
  theVarName(aVarname)
{
}

CtxVariableIterator::~CtxVariableIterator() { }



void
CtxVariableIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<CtxVariableIteratorState>::createState(planState, this->stateOffset, offset);

  StateTraitsImpl<CtxVariableIteratorState>::initState(planState, this->stateOffset);
  
  CtxVariableIteratorState* lState = StateTraitsImpl<CtxVariableIteratorState>::getState(planState, this->stateOffset);

  if (theVarName != ".")
    lState->iter = planState.theRuntimeCB->theDynamicContext->get_variable(theVarName);

}

store::Item_t CtxVariableIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;

  CtxVariableIteratorState* aState;
  DEFAULT_STACK_INIT(CtxVariableIteratorState, aState, planState);

	if(theVarName == ".")//looking for context item?
	{
    item = planState.theRuntimeCB->theDynamicContext->context_item();
		if(item == NULL)
		{
			ZORBA_ERROR_LOC_OSS ( ZorbaError::XPDY0002, loc, "context item", "");
		}
		STACK_PUSH( item, aState);
	}
	else
	{
		if (aState->iter == NULL)
			ZORBA_ERROR_LOC_OSS ( ZorbaError::XPDY0002, loc, theVarName, "");

    aState->iter->open();

		do
		{
			item = aState->iter->next();
			STACK_PUSH (item , aState);
		}
	  while(item != NULL);

    aState->iter->close();
	}

  while(true)
  {
    STACK_PUSH (NULL , aState);
  }
  STACK_END();

}

}
