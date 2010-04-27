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

#include "runtime/core/fncall_iterator.h"

#include <map>

#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/pure_stateless_function.h>
#include <zorba/nonepure_stateless_function.h>
#include <zorba/exception.h>

#include "zorbaerrors/error_manager.h"

#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "functions/udf.h"

#include "runtime/core/var_iterators.h"
#include "runtime/util/flowctl_exception.h"  // for ExitException
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planiter_visitor.h"

#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(UDFunctionCallIterator)
END_SERIALIZABLE_CLASS_VERSIONS(UDFunctionCallIterator)

SERIALIZABLE_CLASS_VERSIONS(StatelessExtFunctionCallIterator)
END_SERIALIZABLE_CLASS_VERSIONS(StatelessExtFunctionCallIterator)


ulong UDFunctionCallIterator::theDepth = 0;


UDFunctionCallIteratorState::UDFunctionCallIteratorState()
  :
  thePlan(NULL),
  thePlanState(NULL),
  thePlanStateSize(0),
  thePlanOpen(false)
{
}


UDFunctionCallIteratorState::~UDFunctionCallIteratorState()
{
  if (thePlanOpen)
  {
    thePlan->close(*thePlanState);
    thePlanOpen = false;
  }

  if (thePlanState != NULL)
  {
    if (thePlanState->theDynamicContext)
      delete thePlanState->theDynamicContext;

    delete thePlanState;
    thePlanState = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIteratorState::open(PlanState& planState, user_function* udf)
{
  thePlan = udf->getPlan(planState.theCompilerCB).getp();

  thePlanStateSize = thePlan->getStateSizeOfSubtree();

  // Must allocate new dctx, as child of the "current" dctx, because the udf may
  // declare local block vars, some of which may hide vars with the same name in
  // the scope of the caller.
  dynamic_context* dctx = new dynamic_context(planState.theDynamicContext);

  thePlanState = new PlanState(dctx, thePlanStateSize, planState.theStackDepth + 1);
  thePlanState->theCompilerCB = planState.theCompilerCB;
  thePlanState->theDebuggerCommons = planState.theDebuggerCommons;
  thePlanState->theQuery = planState.theQuery;
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (thePlanOpen)
  {
    thePlan->reset(*thePlanState);
  }
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>*)this);

  ar & theUDF;
  ar & theIsDynamic;
}


/*******************************************************************************

********************************************************************************/
bool UDFunctionCallIterator::isUpdating() const
{
  return theUDF->isUpdating();
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UDFunctionCallIteratorState* state;

  if (!theIsDynamic)
  {
    NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
    openImpl(planState, offset);

    state = StateTraitsImpl<UDFunctionCallIteratorState>::
            getState(planState, theStateOffset);
  }
  else
  {
    theStateOffset = offset;

    state = new (planState.theBlock + offset) UDFunctionCallIteratorState();

    state->init(planState);
  }

  if (planState.theStackDepth + 1 > 256)
    ZORBA_ERROR_LOC_PARAM(XQP0019_INTERNAL_ERROR, loc, "stack overflow", "");

  // Create the plan for the udf body (if not done already) and allocate
  // the plan state (but not the state block) and dynamic context.
  state->open(planState, theUDF);

  // Create a wrapper over each subplan that computes an argument expr, if the
  // associated param is actually used anywhere in the function body.
  const std::vector<LetVarIter_t>& argRefs = theUDF->getArgVarRefIters();

  state->theArgWrappers.resize(argRefs.size());

  std::vector<LetVarIter_t>::const_iterator argRefsIte = argRefs.begin();
  std::vector<LetVarIter_t>::const_iterator argRefsEnd = argRefs.end();
  std::vector<PlanIter_t>::const_iterator argsIte = theChildren.begin();
  std::vector<store::Iterator_t>::iterator argWrapsIte = state->theArgWrappers.begin();
  for (; argRefsIte != argRefsEnd; ++argRefsIte, ++argsIte, ++argWrapsIte)
  {
    const LetVarIter_t& argRef = (*argRefsIte);
    if (argRef != NULL)
    {
      (*argWrapsIte) = new PlanIteratorWrapper((*argsIte), planState);

      // Cannot do the arg bind here because the state->thePlan has not been
      // opened yet, and as a result, state->thePlanState has not been
      // initialized either.
      //argRef->bind(*argWrapsIte, *state->thePlanState);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::resetImpl(PlanState& planState) const
{
  if (!theIsDynamic)
  {
    NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
    resetImpl(planState);
  }
  else
  {
    StateTraitsImpl<UDFunctionCallIteratorState>::
    reset(planState, theStateOffset);
  }
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::closeImpl(PlanState& planState)
{
  if (!theIsDynamic)
  {
    NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
    closeImpl(planState);
  }
  else
  {
    StateTraitsImpl<UDFunctionCallIteratorState>::
    destroyState(planState, theStateOffset);
  }
}



/*******************************************************************************

********************************************************************************/
bool UDFunctionCallIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool success = true;
  ZorbaDebuggerCommons* lDebugger = planState.theCompilerCB->theDebuggerCommons;
  std::stringstream name;

  UDFunctionCallIteratorState* state;
  DEFAULT_STACK_INIT(UDFunctionCallIteratorState, state, planState);

  if(lDebugger != 0)
  {
    name << theUDF->getName()->getStringValue() << '(';
  }

  // Open the plan, if not done already. This cannot be done in the openImpl
  // method because in the case of recursive functions, we will get into an
  // infinite loop.
  if (!state->thePlanOpen)
  {
    uint32_t planOffset = 0;
    state->thePlan->open(*state->thePlanState, planOffset);
    state->thePlanOpen = true;
  }

  // Bind the args.
  {
    const std::vector<LetVarIter_t>& argRefs = theUDF->getArgVarRefIters();

    std::vector<LetVarIter_t>::const_iterator argRefsIte = argRefs.begin();
    std::vector<LetVarIter_t>::const_iterator argRefsEnd = argRefs.end();
    std::vector<store::Iterator_t>::iterator argWrapsIte = state->theArgWrappers.begin();

    for (; argRefsIte != argRefsEnd; ++argRefsIte, ++argWrapsIte)
    {
      const LetVarIter_t& argRef = (*argRefsIte);
      if (argRef != NULL)
      {
        argRef->bind(*argWrapsIte, *state->thePlanState);

       if (lDebugger != 0)
       {
          store::Iterator_t it = (*argWrapsIte);
          it->open();
          store::Item_t item;
          name << '$' << argRef->getVarName() << '=';
          while (it->next(item))
          {
            String lValue(item->getStringValue());
            if(lValue.length() > 10)
            {
              name.write(lValue.c_str(), 10);
              name << "...";
            }
            else
            {
              name << item->getStringValue();
            }
            name << " (" << item->getType()->getStringValue() << ')';
          }
          it->reset();
        }
      }
    }
  }

  if (lDebugger != 0)
  {
    name << ')';
    //lDebugger->theLastKnownStack = lDebugger->theStack;
    //lDebugger->pushStack(std::make_pair<std::string, const QueryLoc>(name.str(), loc));
    //lDebugger->isFunctionExecution = true;
  }

  for (;;)
  {
    try
    {
      success = consumeNext(result, state->thePlan, *state->thePlanState);
    }
    catch (ExitException &e)
    {
      state->exitValue = e.val;
      success = false;
    }

    if (success)
    {
      STACK_PUSH(true, state);
    }
    else
    {
      break;
    }
  }

  if (state->exitValue != NULL)
  {
    while (state->exitValue->next(result))
      STACK_PUSH(true, state);
  }

  STACK_END(state);
}


NARY_ACCEPT(UDFunctionCallIterator);


/*******************************************************************************

********************************************************************************/

class ExtFuncArgItemSequence : public ItemSequence
{
private:
  PlanIter_t   theChild;
  PlanState  & thePlanState;

public:
  ExtFuncArgItemSequence(PlanIter_t& child, PlanState& state)
    :
    theChild(child),
    thePlanState(state)
  {
  }

  bool next(Item& item)
  {
    store::Item_t result;
    bool status = theChild->consumeNext(result, theChild.getp(), thePlanState);
    item = status ? result : NULL;
    return status;
  }
};


StatelessExtFunctionCallIteratorState::StatelessExtFunctionCallIteratorState()
{
}


StatelessExtFunctionCallIteratorState::~StatelessExtFunctionCallIteratorState()
{
  ulong n = m_extArgs.size();

  for (ulong i = 0; i < n; ++i) 
  {
    delete m_extArgs[i];
  }
}


void StatelessExtFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theResult.reset();
}


StatelessExtFunctionCallIterator::StatelessExtFunctionCallIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    const StatelessExternalFunction* function,
    bool isUpdating,
    const xqpStringStore_t& ns)
  :
  NaryBaseIterator<StatelessExtFunctionCallIterator,
                   StatelessExtFunctionCallIteratorState>(sctx, loc, args),
  theFunction(function),
  theIsUpdating(isUpdating),
  theNamespace(ns)
{
}


StatelessExtFunctionCallIterator::~StatelessExtFunctionCallIterator()
{
}


void StatelessExtFunctionCallIterator::serialize(serialization::Archiver& ar)
{
  ar.dont_allow_delay_for_plan_sctx = true;
  serialize_baseclass(ar,
                      static_cast<NaryBaseIterator<
                                  StatelessExtFunctionCallIterator,
                                  StatelessExtFunctionCallIteratorState>*>(this));
  ar.dont_allow_delay_for_plan_sctx = false;
  if (ar.is_serializing_out())
  {
    // serialize out: serialize prefix and localname of the function
    ar & theNamespace;
    xqpStringStore_t lTmp;
    lTmp = Unmarshaller::getInternalString(theFunction->getLocalName());
    ar.set_is_temp_field(true);
    ar & lTmp;
    ar.set_is_temp_field(false);
  }
  else
  {
    // serializing in: get the function from the static context
    //                 using the serialized prefix/uri and localname
    ar & theNamespace;
    xqpStringStore_t lLocalname;
    ar.set_is_temp_field(true);
    ar & lLocalname;
    ar.set_is_temp_field(false);
    if(theNamespace)
    {
      QueryLoc loc;
      theFunction = theSctx->lookup_stateless_external_function(theNamespace,
                                                                lLocalname.getp());
      if (!theFunction)
      {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because "
                             << " the external function with URI " << theNamespace
                             << " and local name " << lLocalname
                             << " is not available through any of the"
                             << " ExternalModules.");
      }
    }
    else
      theFunction = NULL;
  }

  ar & theIsUpdating;
}


void StatelessExtFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<StatelessExtFunctionCallIterator,
                   StatelessExtFunctionCallIteratorState>::openImpl(planState, offset);

  StatelessExtFunctionCallIteratorState* state =
  StateTraitsImpl<StatelessExtFunctionCallIteratorState>::getState(planState,
                                                                   theStateOffset);
  int n = theChildren.size();
  state->m_extArgs.resize(n);
  for(int i = 0; i < n; ++i)
  {
    state->m_extArgs[i] = new ExtFuncArgItemSequence(theChildren[i], planState);
  }
}


bool StatelessExtFunctionCallIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  Item lOutsideItem;
  const PureStatelessExternalFunction* lPureFct = 0;
  const NonePureStatelessExternalFunction* lNonePureFct = 0;

  StatelessExtFunctionCallIteratorState* state;
  DEFAULT_STACK_INIT(StatelessExtFunctionCallIteratorState, state, planState);

  try 
  {
    if (theFunction->isDeterministic()) 
    {
      lPureFct = dynamic_cast<const PureStatelessExternalFunction*>(theFunction);
      ZORBA_ASSERT(lPureFct);

      state->theResult = lPureFct->evaluate(state->m_extArgs);
    }
    else
    {
      lNonePureFct = dynamic_cast<const NonePureStatelessExternalFunction*>(theFunction);
      ZORBA_ASSERT(lNonePureFct);

      ZORBA_ASSERT(planState.theQuery);
      state->theResult = lNonePureFct->evaluate(state->m_extArgs,
                                               planState.theQuery->getStaticContext(),
                                               planState.theQuery->getDynamicContext());
    }

  }
  catch(const ZorbaException& e) 
  {
    // take all information from the exception raised in
    // the external function (e.g. file name) + add loc information
    throw error::ErrorManager::createException(e.getErrorCode(),
                                               e.getDescription().c_str(),
                                               e.getFileName().c_str(),
                                               e.getFileLineNumber(),
                                               loc.getLineBegin(),
                                               loc.getColumnBegin(),
                                               loc.getFilename());
  }
  while (true)
  {
    try 
    {
      if (state->theResult.get() == NULL) // This will happen if the user's external function returns a zorba::ItemSequence_t(NULL)
        break;

      if (!state->theResult->next(lOutsideItem)) 
      {
        break;
      }
    } 
    catch(const ZorbaException& e)
    {
      // take all information from the exception raised in
      // the external function (e.g. file name) + add loc information
      throw error::ErrorManager::createException(e.getErrorCode(),
                                                 e.getDescription().c_str(),
                                                 e.getFileName().c_str(),
                                                 e.getFileLineNumber(),
                                                 loc.getLineBegin(),
                                                 loc.getColumnBegin(),
                                                 loc.getFilename());
    }
    result = Unmarshaller::getInternalItem(lOutsideItem);
    if (theIsUpdating)
    {
      if (!result->isPul())
      {
        ZORBA_ERROR_LOC(XUDY0019, loc);
      }
    }
    else
    {
      if (result->isPul())
      {
        ZORBA_ERROR_LOC(XUDY0018, loc);
      }
    }
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}


NARY_ACCEPT(StatelessExtFunctionCallIterator);


} /* namespace zorba */

/* vim:set ts=2 sw=2: */
