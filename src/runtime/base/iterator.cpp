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

namespace xqp {

/* begin PlanState */
PlanState::PlanState(int32_t blockSize)
{
	this->block = new int8_t[blockSize];
	memset(this->block, 0, blockSize);
}

PlanState::~PlanState()
{
	delete[] block;
}
/* end PlanState */

/* begin class PlanIterator */
PlanIterator::PlanIterator(yy::location _loc) :
	loc(_loc){
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}

PlanIterator::PlanIterator(const PlanIterator& it) :
	rcobject(it),
	loc(it.loc) {
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}

PlanIterator::~PlanIterator() {
}

Item_t PlanIterator::produceNext(PlanState& planState) {
	ZorbaErrorAlerts::error_alert(
					error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
					error_messages::SYSTEM_ERROR,
					NULL
				);
	return NULL;///unreachable
}

void 
PlanIterator::reset(PlanState& planState) {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}

void 
PlanIterator::releaseResources(PlanState& planState) {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}

int32_t
PlanIterator::getStateSize() {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
	return 0;
}

int32_t
PlanIterator::getStateSizeOfSubtree() {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
	return 0;
}

void
PlanIterator::setOffset(PlanState& planState, int32_t& offset) {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}


std::ostream& PlanIterator::show(std::ostream& os)
{
	os << IT_INDENT << "<" << this << " type=\"" << typeid(*this).name() << "\">" << std::endl;
	_show(os);
	os << IT_OUTDENT<< "</"<< this << ">"<< std::endl;
	return os;
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
PlanIterator::PlanIteratorState::getDuffsLine() {
	return this->duffsLine;
}
/* end class PlanIterator */


/* begin class IteratorWrapper */
PlanIterWrapper::PlanIterWrapper(PlanIter_t& aIter)
  :
  theAlienBlock(false),
  theIterator(aIter)
{
	int32_t lStackSize = theIterator->getStateSizeOfSubtree();
	theStateBlock = new PlanState(lStackSize);
	int32_t lOffset = 0;
	theIterator->setOffset(*theStateBlock, lOffset);
}


PlanIterWrapper::PlanIterWrapper(PlanIter_t& aIter, PlanState& aStateBlock) 
  :
  theAlienBlock(true),
  theIterator(aIter),
  theStateBlock(&aStateBlock)
{
}


PlanIterWrapper::~PlanIterWrapper()
{
	if (!theAlienBlock) {
		theIterator->releaseResources(*theStateBlock);
		delete theStateBlock;
	}
}


Item_t
PlanIterWrapper::next()
{
#if BATCHING_TYPE == 1
  return theIterator->consumeNext(theIterator, *theStateBlock);
#else
	return theIterator->produceNext(*theStateBlock);
#endif
}


void
PlanIterWrapper::reset()
{
	theIterator->reset(*theStateBlock);
}
/* end class IteratorWrapper */

}
