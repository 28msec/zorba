/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf, Tim Kraska, Markos Zaharioudakis
 */

#include "system/zorba.h"

#include "runtime/fncontext/FnContextImpl.h"
#include "api/external/xquery.h"
#include "context/dynamic_context.h"
#include "runtime/core/item_iterator.h"
#include "system/zorba_engine.h"
#include "zorba/runtime/iterator.h"

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


Item_t CtxVariableIterator::nextImpl(PlanState& planState) const
{
  Item_t item;
  Iterator_t iter;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);

	if(theVarName == ".")//looking for context item?
	{

		item = ZORBA_FOR_CURRENT_THREAD()->get_base_dynamic_context()->context_item();
		if(item == NULL)
		{
			ZORBA_ERROR_ALERT (ZorbaError::XPDY0002, &loc, DONT_CONTINUE_EXECUTION, theVarName);
		}
		STACK_PUSH( item, aState);
	}
	else
	{
		iter = ZORBA_FOR_CURRENT_THREAD()->
					 get_base_dynamic_context()->get_variable(theVarName);

		if (iter == NULL)
			ZORBA_ERROR_ALERT (ZorbaError::XPDY0002, &loc, DONT_CONTINUE_EXECUTION, theVarName);

		do
		{
			item = iter->next();
			STACK_PUSH (item , aState);
		}
	  while(item != NULL);
	}
  
  while(true)
  {
    STACK_PUSH (NULL , aState);
  }
  STACK_END();
}

void CtxVariableIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<PlanIteratorState>::reset(planState, this->stateOffset);

	if(theVarName == ".")//looking for context item?
	{
	}
	else
	{
		Iterator_t iter;

		iter = ZORBA_FOR_CURRENT_THREAD()->
					 get_base_dynamic_context()->get_variable(theVarName);

		iter->reset();
	}
}


void CtxVariableIterator::closeImpl(PlanState& planState)
{
/*daniel: dynamic context handles its own issues
  Iterator_t iter;

  Zorba* zorba = ZORBA_FOR_CURRENT_THREAD();

  iter = zorba->get_base_dynamic_context()->get_variable(theVarName);

  if (iter != NULL)
    iter->close();
*/

  StateTraitsImpl<PlanIteratorState>::destroyState(planState, this->stateOffset);
}

}
