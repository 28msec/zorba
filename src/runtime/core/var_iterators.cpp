/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "zorbaerrors/Assert.h"

#include "system/globalenv.h"

#include "context/dynamic_context.h"

#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/base/noarybase.h"
#include "runtime/core/var_iterators.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/iterator.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(CtxVariableIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVariableIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarDeclIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarDeclIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarAssignIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarAssignIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarExistsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarExistsIterator)

SERIALIZABLE_CLASS_VERSIONS(ForVarIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ForVarIterator)

SERIALIZABLE_CLASS_VERSIONS(LetVarIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LetVarIterator)

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Declaration                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool CtxVarDeclIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  CONSUME (varName, 0);

  planState.theRuntimeCB->theDynamicContext->
  declare_variable(varName->getStringValue()->str());

  STACK_END (state);
}


NARY_ACCEPT(CtxVarDeclIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Initialization/Assignment                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool CtxVarAssignIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  CONSUME(varName, 0);

	if(varName->getStringValue()->byteEqual(".")) 
  {
    if (! CONSUME (item, 1))
			ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "context item must be a single item");

    planState.theRuntimeCB->theDynamicContext->set_context_item(item, 0);

    if (CONSUME (item, 1))
      ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "context item must be a single item");
  }
  else if (theSingleItem)
  {
    if (! CONSUME (item, 1))
			ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "variable value must be a single item");

    planState.theRuntimeCB->theDynamicContext->
    set_variable(varName->getStringValue()->str(), item);

    if (CONSUME (item, 1))
      ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "variable value must be a single item");
  }
  else
  {
    store::Iterator_t planIter = new PlanIteratorWrapper(theChildren[1], planState);
    planState.theRuntimeCB->theDynamicContext->
    set_variable(varName->getStringValue()->str(), planIter);
  }

  STACK_END (state);
}


NARY_ACCEPT(CtxVarAssignIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog Var Existence Check                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool CtxVarExistsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  store::Item_t varItem;
  store::Iterator_t varIter;
  dynamic_context* dctx = planState.theRuntimeCB->theDynamicContext;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  CONSUME(varName, 0);

	if(varName->getStringValue()->byteEqual(".")) 
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, dctx->context_item() != NULL),
               state);
	}
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result,
                                               dctx->get_variable(varName,
                                                                  varItem,
                                                                  varIter)),
               state);
  }
  STACK_END (state);
}


NARY_ACCEPT(CtxVarExistsIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Reference                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
CtxVariableIteratorState::CtxVariableIteratorState()
{}

CtxVariableIteratorState::~CtxVariableIteratorState()
{}

bool CtxVariableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  
  CtxVariableIteratorState* state;
  DEFAULT_STACK_INIT(CtxVariableIteratorState, state, planState);

  CONSUME (varName, 0);

  // looking for context item?
	if(varName->getStringValue()->byteEqual(".")) 
  {  
    result = planState.theRuntimeCB->theDynamicContext->context_item();
		if(result == NULL)
			ZORBA_ERROR_LOC_PARAM( XPDY0002, loc, "context item", "");

		STACK_PUSH(true, state);
	}
  else
  {
    planState.theRuntimeCB->theDynamicContext->
    get_variable(varName, result, state->theIter);

    if (result != NULL)
    {
      STACK_PUSH(true, state);
    }
    else if (state->theIter != NULL) 
    {
      state->theIter->open();

      while (state->theIter->next(result))
        STACK_PUSH(true, state);

      state->theIter->close();
    }
    else
    {
      std::string var_key = xqp_string (varName->getStringValue ());
			ZORBA_ERROR_LOC_PARAM( XPDY0002, loc, var_key.substr (var_key.find (":") + 1), "");
    }
	}

  STACK_END (state);
}


NARY_ACCEPT(CtxVariableIterator);



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ForVarIterator::ForVarIterator(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item* name)
  : 
  NoaryBaseIterator<ForVarIterator, ForVarState >(sctx, loc), 
  theVarName(name)
{
}


void ForVarIterator::bind(store::Item* value, PlanState& planState)
{
  ForVarState* state;
  state = StateTraitsImpl<ForVarState>::getState(planState, theStateOffset);

  state->theValue = value;
}


bool ForVarIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ForVarState* state;
  DEFAULT_STACK_INIT(ForVarState, state, planState);
  if ((result = state->theValue) != NULL)
  {
    STACK_PUSH(true, state);
  }
  STACK_END (state);
}


NOARY_ACCEPT(ForVarIterator);



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  LetVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

LetVarState::LetVarState()
{
}


LetVarState::~LetVarState()
{
  if (theSourceIter != NULL)
    theSourceIter->close();
}


void LetVarState::reset(PlanState& planState) 
{ 
  PlanIteratorState::reset(planState); 
  if (theSourceIter != NULL) 
    theSourceIter->reset();
}


LetVarIterator::LetVarIterator(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item* name)
  :
  NoaryBaseIterator<LetVarIterator, LetVarState>(sctx, loc),
  theVarName(name)
{
}


void LetVarIterator::bind(store::Iterator_t& it, PlanState& planState)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, theStateOffset);

  state->theSourceIter = it;
}


bool LetVarIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, theStateOffset);

  ZORBA_ASSERT (state->theSourceIter != NULL);
  return state->theSourceIter->next(result);
}


NOARY_ACCEPT(LetVarIterator);


} /* namespace zorba */
