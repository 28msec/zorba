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

store::Item_t CtxVariableIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore_t varName;
  xqpStringStore dot (".");
  
  CtxVariableIteratorState* state;
  DEFAULT_STACK_INIT(CtxVariableIteratorState, state, planState);

  item = consumeNext(theChildren[0].getp(), planState);

  if (item == NULL)
    return NULL;

  varName = item->getStringValue();

	if(varName->equals(&dot))  //looking for context item?
	{
    item = planState.theRuntimeCB->theDynamicContext->context_item();
		if(item == NULL)
		{
			ZORBA_ERROR_LOC_PARAM( ZorbaError::XPDY0002, loc, "context item", "");
		}
		STACK_PUSH( item, state);
	} 
  else 
  {
    state->theIter = planState.theRuntimeCB->theDynamicContext->
                     get_variable(xqpString(varName.getp()));

    if (state->theIter == NULL)
			ZORBA_ERROR_LOC_PARAM( ZorbaError::XPDY0002, loc, varName, "");

    state->theIter->open();

    while ( (item = state->theIter->next()) != NULL )
			STACK_PUSH (item, state);

    state->theIter->close();
	}

  STACK_END (state);  
}

}
