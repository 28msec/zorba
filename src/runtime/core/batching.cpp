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

#include "runtime/core/batching.h"

#include "util/zorba.h"

namespace xqp {

/* begin IteratorTreeStateBlock */
IteratorTreeStateBlock::IteratorTreeStateBlock(int32_t blockSize) 
: block(new int8_t[blockSize]) 
{
	memset(this->block, 0, blockSize);
}
/* end IteratorTreeStateBlock */

/* begin class BasicIterator */
BasicIterator::BasicIterator(yy::location _loc) :
	loc(_loc){
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}

BasicIterator::BasicIterator(const BasicIterator& it) :
	rcobject(it),
	loc(it.loc) {
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}

BasicIterator::~BasicIterator() {
}

Item_t BasicIterator::produceNext(IteratorTreeStateBlock& stateBlock) {
	ZorbaErrorAlerts::error_alert(
					error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
					error_messages::SYSTEM_ERROR,
					NULL
				);
	return NULL;///unreachable
}

void 
BasicIterator::reset(IteratorTreeStateBlock& stateBlock) {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}

void 
BasicIterator::releaseResources(IteratorTreeStateBlock& stateBlock) {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}

int32_t
BasicIterator::getStateSize() {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
	return 0;
}

int32_t
BasicIterator::getStateSizeOfSubtree() {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
	return 0;
}

void
BasicIterator::setOffset(int32_t& offset) {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}


std::ostream& BasicIterator::show(std::ostream& os)
{
	os << IT_INDENT << "<" << this << " type=\"" << typeid(*this).name() << "\">" << std::endl;
	_show(os);
	os << IT_OUTDENT<< "</"<< this << ">"<< std::endl;
	return os;
}
/* end class BasicIterator */

/* begin class IteratorWrapper */
void
BasicIterator::BasicIteratorState::init() {
	this->duffsLine = 0;
}

void
BasicIterator::BasicIteratorState::reset() {
	this->duffsLine = 0;
}

void
BasicIterator::BasicIteratorState::setDuffsLine(int32_t value) {
	this->duffsLine = value;
}

int32_t
BasicIterator::BasicIteratorState::getDuffsLine() {
	return this->duffsLine;
}


IteratorWrapper::IteratorWrapper(Iterator_t& iter) : iterator(iter) {
	int32_t stackSize = this->iterator->getStateSizeOfSubtree();
	this->stateBlock = new IteratorTreeStateBlock(stackSize);
	int32_t offset = 0;
	this->iterator->setOffset(offset);
}

IteratorWrapper::~IteratorWrapper() {
	this->iterator->releaseResources(*this->stateBlock);
	delete this->stateBlock;
}

Item_t
IteratorWrapper::next() {
	return this->iterator->produceNext(*this->stateBlock);
}
/* end class IteratorWrapper */
}
