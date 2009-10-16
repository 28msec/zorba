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
    XQueryImpl* aQuery,
    uint32_t aStackDepth,
    long aTimeout)
  :
  theIterator(aIter),
  theDynamicContext(NULL),
  theQuery(aQuery),
#ifndef NDEBUG
  theIsOpened(false),
#endif
  theTimeout(0)
{
  assert (aCompilerCB);

  uint32_t lStateSize = theIterator->getStateSizeOfSubtree();
  theStateBlock = new PlanState(lStateSize, aStackDepth);

  // set the compiler cb in the state
  theStateBlock->theCompilerCB = aCompilerCB;

  if (aDynamicContext == NULL)
  {
    theDynamicContext = aDynamicContext = new dynamic_context();
  }

  // for the moment, let's keep the runtime cb here
  theStateBlock->theRuntimeCB = new RuntimeCB();
  theStateBlock->theRuntimeCB->theDynamicContext = aDynamicContext;
  theStateBlock->theRuntimeCB->theQuery = theQuery;
  theStateBlock->theDebuggerCommons = aCompilerCB->theDebuggerCommons;
  if (aTimeout != -1) {
    StateWrapper lWrapper(*theStateBlock);
    theTimeout = new Timeout(aTimeout, lWrapper);
  }
}


PlanWrapper::~PlanWrapper()
{
#ifndef NDEBUG
  assert(!theIsOpened);
#endif
  if (theTimeout) {
    // Terminate could throw an exception
    // but does not for this particular implementation
    theTimeout->terminate();
  }
  delete theTimeout;

  // we created it
  delete theStateBlock->theRuntimeCB; 

  delete theStateBlock; 
  theStateBlock = NULL;

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
  theIterator->open(*theStateBlock, offset);
  if (theTimeout) {
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

  return PlanIterator::consumeNext(result, theIterator.getp(), *theStateBlock);
}


void
PlanWrapper::reset()
{
#ifndef NDEBUG
  assert(theIsOpened);
#endif
  theIterator->reset(*theStateBlock); 
}


void
PlanWrapper::close() throw ()
{
  theIterator->close(*theStateBlock);

#ifndef NDEBUG
  theIsOpened = false;
#endif
}


void PlanWrapper::checkDepth (const QueryLoc &loc)
{ theStateBlock->checkDepth (loc); }

const RuntimeCB *PlanWrapper::getRuntimeCB () const
{ return theStateBlock->getRuntimeCB (); }

} /* namespace zorba */
