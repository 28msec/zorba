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
#include "util/Assert.h"

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
  delete[] theBlock; theBlock = 0;
}


/*******************************************************************************
  class PlanWraper
********************************************************************************/
PlanWrapper::PlanWrapper(PlanIter_t& aIter)
  : theIterator(aIter)
{
  uint32_t stackSize = theIterator->getStateSizeOfSubtree();
  theStateBlock = new PlanState(stackSize);
}


PlanWrapper::~PlanWrapper()
{
  delete theStateBlock; theStateBlock = 0;
}

void
PlanWrapper::open()
{
  uint32_t offset = 0;
  theIterator->open(*theStateBlock, offset);
}

Item_t
PlanWrapper::next()
{
  return PlanIterator::consumeNext(theIterator.getp(), *theStateBlock);
}

void
PlanWrapper::reset()
{
  theIterator->reset(*theStateBlock);
}

void
PlanWrapper::close()
{
  theIterator->close(*theStateBlock); 
}


/*******************************************************************************
  class PlanIteratorWrapper
********************************************************************************/
PlanIteratorWrapper::PlanIteratorWrapper(PlanIter_t& iter, PlanState& state) 
  : theIterator(iter),
    theStateBlock(&state)
{
}


PlanIteratorWrapper::~PlanIteratorWrapper()
{
}

void
PlanIteratorWrapper::open()
{
}

Item_t
PlanIteratorWrapper::next()
{
  return PlanIterator::consumeNext(theIterator.getp(), *theStateBlock);
}

void
PlanIteratorWrapper::reset()
{
  theIterator->reset(*theStateBlock);
}


void
PlanIteratorWrapper::close()
{
}


}
