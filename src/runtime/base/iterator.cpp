/**
 *
 * @copyright
 * ========================================================================
 *  Copyright 2007 FLWOR Foundation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *    http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * ========================================================================
 *
 * @author Tim Kraska (tim.kraska@inf.ethz.ch), David Graf (dagraf@inf.ethz.ch)
 * @file runtime/core/batching.h
 *
 */

#include "runtime/base/iterator.h"

#include "system/zorba.h"
#include "system/zorba_engine.h"

namespace xqp
{
/*******************************************************************************
  class PlanState
********************************************************************************/

PlanState::PlanState(uint32_t blockSize)
{
  theBlockSize = blockSize;
  theBlock = new int8_t[theBlockSize];
  memset(theBlock, 0, theBlockSize);

  theZorba = ZORBA_FOR_CURRENT_THREAD();
}


PlanState::~PlanState()
{
  if (theBlock != NULL)
    delete[] theBlock;
}


/*******************************************************************************
  class PlanWraper
********************************************************************************/
PlanWrapper::PlanWrapper(PlanIter_t& aIter)
  :
  theIterator(aIter),
  theClosed(false)
{
  uint32_t stackSize = theIterator->getStateSizeOfSubtree();
  thePlanState = new PlanState(stackSize);
  uint32_t offset = 0;
  theIterator->setOffset(*thePlanState, offset);
}


PlanWrapper::~PlanWrapper()
{
  close();
}


Item_t
PlanWrapper::next()
{
  if (!theClosed)
  {
#if ZORBA_BATCHING_TYPE == 1
    return theIterator->consumeNext(theIterator, *thePlanState);
#else
    return theIterator->produceNext(*thePlanState);
#endif
  }
  else
  { 
    return NULL;
  }
}

void
PlanWrapper::reset()
{
  if (!theClosed)
    theIterator->reset(*thePlanState);
}

void
PlanWrapper::close()
{
  if (!theClosed)
  {
    theIterator->releaseResources(*thePlanState); 
    delete thePlanState;
    theClosed = true;
  }
}


/*******************************************************************************
  class PlanIteratorWrapper
********************************************************************************/
PlanIteratorWrapper::PlanIteratorWrapper(PlanIter_t& iter, PlanState& state) 
  :
  theIterator(iter),
  thePlanState(&state),
  theClosed(false)
{
}


PlanIteratorWrapper::~PlanIteratorWrapper()
{
}


Item_t
PlanIteratorWrapper::next()
{
  if (!theClosed)
  {
#if ZORBA_BATCHING_TYPE == 1
    return theIterator->consumeNext(theIterator, *thePlanState);
#else
    return theIterator->produceNext(*thePlanState);
#endif
  }
  else
  { 
    return NULL;
  }
}

void
PlanIteratorWrapper::reset()
{
  if (!theClosed)
    theIterator->reset(*thePlanState);
}


void
PlanIteratorWrapper::close()
{
  if (!theClosed)
  {
    theIterator->releaseResources(*thePlanState); 
    theClosed = true;
  }
}


}
