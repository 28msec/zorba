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

#include "util/zorba.h"

namespace xqp
{

int32_t iteratorTreeDepth = -1;


/* begin PlanState */
PlanState::PlanState(uint32_t blockSize)
{
  this->block = new int8_t[blockSize];
  memset(this->block, 0, blockSize);
  this->blockSize = blockSize;

  ///this zorp now gets specific for each iterator state object
  zorp = zorba::getZorbaForCurrentThread();
	xqbinary = NULL;
//	xqexecution = NULL;
}

PlanState::~PlanState()
{
  delete[] block;
}
/* end PlanState */

/* begin class PlanIterator */
PlanIterator::PlanIterator(yy::location _loc) :
  loc(_loc){
  //zorp = zorba::getZorbaForCurrentThread();
}

PlanIterator::PlanIterator(const PlanIterator& it) :
  rcobject(it),
  loc(it.loc) {
  //zorp = zorba::getZorbaForCurrentThread();
}

PlanIterator::~PlanIterator() {
}

void
PlanIterator::PlanIteratorState::init() {
  this->duffsLine = DUFFS_RELEASE_RESOURCES;
}

void
PlanIterator::PlanIteratorState::reset() {
  this->duffsLine = DUFFS_RESET;
}

void
PlanIterator::PlanIteratorState::releaseResources() {
  this->duffsLine = DUFFS_RELEASE_RESOURCES;
}

void
PlanIterator::PlanIteratorState::setDuffsLine(int32_t value) {
  this->duffsLine = value;
}

int32_t
PlanIterator::PlanIteratorState::getDuffsLine() const {
  return this->duffsLine;
}
/* end class PlanIterator */


/*******************************************************************************

********************************************************************************/
PlanWrapper::PlanWrapper(PlanIter_t& aIter)
  :
  theIterator(aIter),
  theClosed(false)
{
  uint32_t stackSize = theIterator->getStateSizeOfSubtree();
  theStateBlock = new PlanState(stackSize);
  uint32_t offset = 0;
  theIterator->setOffset(*theStateBlock, offset);
}


PlanWrapper::~PlanWrapper()
{
  if (!theClosed)
  {
    theIterator->releaseResources(*theStateBlock);
    delete theStateBlock;
  }
}


Item_t
PlanWrapper::next()
{
  if (!theClosed)
  {
#if ZORBA_BATCHING_TYPE == 1
    return theIterator->consumeNext(theIterator, *theStateBlock);
#else
    return theIterator->produceNext(*theStateBlock);
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
    theIterator->reset(*theStateBlock);
}

void
PlanWrapper::close()
{
  if (!theClosed)
  {
    theIterator->releaseResources(*theStateBlock); 
    delete theStateBlock;
    theClosed = true;
  }
}


/*******************************************************************************

********************************************************************************/
PlanIteratorWrapper::PlanIteratorWrapper(PlanIter_t& iter, PlanState& block) 
  :
  theIterator(iter),
  theStateBlock(&block),
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
    return theIterator->consumeNext(theIterator, *theStateBlock);
#else
    return theIterator->produceNext(*theStateBlock);
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
    theIterator->reset(*theStateBlock);
}


void
PlanIteratorWrapper::close()
{
  if (!theClosed)
  {
    theIterator->releaseResources(*theStateBlock); 
    theClosed = true;
  }
}


}
