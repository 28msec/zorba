/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
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
	this->duffsLine = 0;
}

void
PlanIterator::PlanIteratorState::reset() {
	this->duffsLine = 0;
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


/* begin class IteratorWrapper */
PlanIterWrapper::PlanIterWrapper(PlanIter_t& aIter)
  :
  theAlienBlock(false),
  theIterator(aIter),
  theClosed(false)
{
	uint32_t lStackSize = theIterator->getStateSizeOfSubtree();
	theStateBlock = new PlanState(lStackSize);
	uint32_t lOffset = 0;
	theIterator->setOffset(*theStateBlock, lOffset);
}


PlanIterWrapper::PlanIterWrapper(PlanIter_t& aIter, PlanState& aStateBlock) 
  :
  theAlienBlock(true),
  theIterator(aIter),
  theStateBlock(&aStateBlock),
  theClosed(false)
{
}


PlanIterWrapper::~PlanIterWrapper()
{
	if (!theClosed && !theAlienBlock) {
		theIterator->releaseResources(*theStateBlock);
		delete theStateBlock;
	}
}


Item_t
PlanIterWrapper::next()
{
  if (!theClosed)
#if BATCHING_TYPE == 1
    return theIterator->consumeNext(theIterator, *theStateBlock);
#else
	  return theIterator->produceNext(*theStateBlock);
#endif
  else 
    return NULL;
}

void
PlanIterWrapper::reset()
{
  if (!theClosed)
  	theIterator->reset(*theStateBlock);
}

void
PlanIterWrapper::close() {
  if (!theClosed && ! theAlienBlock) {
   theIterator->releaseResources(*theStateBlock); 
   delete theStateBlock;
   theClosed = true;
  }
}
/* end class IteratorWrapper */

}
