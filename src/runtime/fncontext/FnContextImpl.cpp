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
  xqpStringStore_t theVarName;
  xqpStringStore dot (".");
  
  CtxVariableIteratorState* state;
  DEFAULT_STACK_INIT(CtxVariableIteratorState, state, planState);

  item = consumeNext(theChildren[0].getp(), planState);

  if (item == NULL)
    return NULL;

  theVarName = item->getStringValue();

	if(theVarName->equals(&dot))  //looking for context item?
	{
    item = planState.theRuntimeCB->theDynamicContext->context_item();
		if(item == NULL)
		{
			ZORBA_ERROR_LOC_PARAM( ZorbaError::XPDY0002, loc, "context item", "");
		}
		STACK_PUSH( item, state);
	} else {
    state->iter = planState.theRuntimeCB->theDynamicContext->get_variable(xqpString(theVarName.getp()));
    if (state->iter == NULL)
			ZORBA_ERROR_LOC_PARAM( ZorbaError::XPDY0002, loc, theVarName, "");

    state->iter->open();

    while ( (item = state->iter->next()) != NULL )
			STACK_PUSH (item, state);

    state->iter->close();
	}

  STACK_END (state);  
}

}
