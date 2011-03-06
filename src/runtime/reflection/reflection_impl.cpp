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

#include "runtime/reflection/reflection.h"
#include "runtime/core/fncall_iterator.h"
#include "context/static_context.h"
#include "util/string_util.h"
#include "functions/function.h"
#include "functions/udf.h"

namespace zorba
{

class InvokeAnnotationHolder : public AnnotationHolder
{
protected:
  function* theFunction;

public:
  InvokeAnnotationHolder(function* func) : theFunction(func) {  };
  virtual bool is_updating() const { return theFunction == NULL? false : theFunction->isUpdating(); }
};

/*******************************************************************************

********************************************************************************/

void InvokeIteratorState::init(PlanState &planState)
{
  thePlanState = NULL;
}

void InvokeIteratorState::reset(PlanState &planState)
{
  if (thePlanState != NULL)
  {
    if (thePlanState->theLocalDynCtx)
      delete thePlanState->theLocalDynCtx;
    delete thePlanState;
    thePlanState = NULL;
  }
}

InvokeIteratorState::~InvokeIteratorState()
{
  if (thePlanState != NULL)
  {
    if (thePlanState->theLocalDynCtx)
      delete thePlanState->theLocalDynCtx;
    delete thePlanState;
    thePlanState = NULL;
  }
}

/*******************************************************************************

********************************************************************************/
uint32_t InvokeIterator::getStateSizeOfSubtree() const
{
   uint32_t size = NaryBaseIterator<InvokeIterator, InvokeIteratorState>::getStateSizeOfSubtree();

   return size + sizeof(UDFunctionCallIteratorState);
}

bool InvokeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       func_name;
  function*           func;
  std::vector<PlanIter_t> args;
  uint32_t            state_offset = 0;

  InvokeIteratorState* state;
  DEFAULT_STACK_INIT(InvokeIteratorState, state, planState);

  if (theChildren.size() == 0)
  {
    ZORBA_ERROR_LOC_DESC(XPST0017, loc, "the first parameter to invoke() must a QName denoting an existing function.");
  }

  consumeNext(func_name, theChildren[0].getp(), planState);


  func = theSctx->lookup_fn(func_name, theChildren.size()-1);
  if (func == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XPST0017, loc, func_name->getStringValue(), ztd::to_string(theChildren.size()-1));
  }

  {
    for (unsigned int i=1; i<theChildren.size(); i++)
    {
      // theChildren[i]->open(planState, state_offset);
      args.push_back(theChildren[i]);
    }

    {
      InvokeAnnotationHolder ann(func);
      state->thePlan = func->codegen(planState.theCompilerCB, theSctx, loc, args, ann);
    }

    if (func->isUdf())
    {
      static_cast<UDFunctionCallIterator*>(state->thePlan.getp())->setDynamic();

      uint32_t thePlanStateSize = state->thePlan->getStateSizeOfSubtree();
      dynamic_context* localDCtx = new dynamic_context(planState.theGlobalDynCtx);
      state->thePlanState = new PlanState(planState.theGlobalDynCtx,
                                          localDCtx,
                                          thePlanStateSize,
                                          planState.theStackDepth + 1);

      state->thePlanState->theCompilerCB = planState.theCompilerCB;
      state->thePlanState->theDebuggerCommons = planState.theDebuggerCommons;
      state->thePlanState->theQuery = planState.theQuery;

      state_offset = theStateOffset;
      state->thePlan->open(planState, state_offset);
    }

  }

  for (;;)
  {
    bool success;

    try
    {
      // success = consumeNext(result, func_plan, *state->thePlanState);
      success = consumeNext(result, state->thePlan, planState);
    }
    catch (ExitException &e)
    {
      state->theExitValue = e.val;
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

  if (state->theExitValue != NULL)
  {
    while (state->theExitValue->next(result))
      STACK_PUSH(true, state);
  }

  STACK_END (state);
}


} /* namespace zorba */
