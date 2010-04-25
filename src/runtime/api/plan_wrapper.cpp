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
#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/api/runtimecb.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/util/timeout.h"


namespace zorba {

/*******************************************************************************
    class PlanWraper
********************************************************************************/
PlanWrapper::PlanWrapper(
    const PlanIter_t& aIter,
    CompilerCB* aCompilerCB,
    dynamic_context* aDynamicContext,
    XQueryImpl* query,
    uint32_t aStackDepth,
    long aTimeout)
  :
  theIterator(aIter),
  theDynamicContext(NULL),
#ifndef NDEBUG
  theIsOpened(false),
#endif
  theTimeout(0)
{
  assert (aCompilerCB);

  if (aDynamicContext == NULL)
  {
    // aDynamicContext is NULL when we try to execute the plan of an expression
    // that is being folded by the optimizer. 
    aDynamicContext = new dynamic_context();
    theDynamicContext = aDynamicContext;
  }

  uint32_t lStateSize = theIterator->getStateSizeOfSubtree();

  thePlanState = new PlanState(aDynamicContext, lStateSize, aStackDepth);

  // set the compiler cb in the state
  thePlanState->theCompilerCB = aCompilerCB;
  thePlanState->theQuery = query;
  thePlanState->theDebuggerCommons = aCompilerCB->theDebuggerCommons;

  if (aTimeout != -1) 
  {
    StateWrapper lWrapper(*thePlanState);
    theTimeout = new Timeout(aTimeout, lWrapper);
  }
}


PlanWrapper::~PlanWrapper()
{
#ifndef NDEBUG
  assert(!theIsOpened);
#endif
  if (theTimeout) 
  {
    // Terminate could throw an exception
    // but does not for this particular implementation
    theTimeout->terminate();
  }

  delete theTimeout;

  delete thePlanState; 
  thePlanState = NULL;

  // De-allocate locally allocated dctx, if any
  if (theDynamicContext != NULL)
  {
    delete theDynamicContext;
    theDynamicContext = NULL;
  }
}


void
PlanWrapper::open()
{
#ifndef NDEBUG
  assert(!theIsOpened);
#endif

  uint32_t offset = 0;
  theIterator->open(*thePlanState, offset);

  if (theTimeout) 
  {
    // Start a thread that will suspend itself for the given amount of time,
    // and then it will wake up and set theHasToQuit flag of the plan state.
    theTimeout->start();
  }

#ifndef NDEBUG
  theIsOpened = true;
#endif
}


bool
PlanWrapper::next(store::Item_t& result)
{
#ifndef NDEBUG
  assert(theIsOpened);
#endif

  return PlanIterator::consumeNext(result, theIterator.getp(), *thePlanState);
}


void
PlanWrapper::reset()
{
#ifndef NDEBUG
  assert(theIsOpened);
#endif
  theIterator->reset(*thePlanState); 
}


void PlanWrapper::close() throw ()
{
  theIterator->close(*thePlanState);

#ifndef NDEBUG
  theIsOpened = false;
#endif
}


void PlanWrapper::checkDepth (const QueryLoc& loc)
{
  thePlanState->checkDepth(loc);
}


bool PlanWrapper::nextSerializableItem(store::Item_t& aItem)
{
  if (!next(aItem)) 
  {
    return false;
  }
  return true;
}


} /* namespace zorba */
