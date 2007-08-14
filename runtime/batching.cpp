#include "batching.h"

#include "runtime/zorba.h"

namespace xqp {

OldIterator::OldIterator(){
	
}

OldIterator::~OldIterator() {}

void OldIterator::open() {
	assert(!open_b);
	open_b = true;

	// Initialization of the line info for Duff's device.
	_open();
}

void OldIterator::close() {
	assert(open_b);
	open_b = false;
	_close();
}

bool OldIterator::isOpen() const {
	return open_b;
}

bool OldIterator::done() const {
	return false;
}


/**
 * This method should be abstract. Only because of compatibility issues we implemented it
 */
void BasicIterator::reset() {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}

void BasicIterator::releaseResources() {
	ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
}


//*************************************************
//*************************************************
//
//		NO BATCHING
//
//*************************************************
//*************************************************
#if BATCHING_TYPE==0

BasicIterator::BasicIterator(yy::location _loc) :
	loc(_loc){
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}
BasicIterator::BasicIterator(const BasicIterator& it) :
	loc(it.loc) {
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}

BasicIterator::~BasicIterator() {
}

/**
 * This method should be abstract. Only because of compatibility issues we implemented it
 */
item_t BasicIterator::produceNext() {
	ZorbaErrorAlerts::error_alert(
					error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
					error_messages::SYSTEM_ERROR,
					NULL
				);
}

std::ostream& BasicIterator::show(std::ostream& os) {
	os << IT_INDENT<< "<"<< typeid(*this).name() << ">"<< std::endl;
	_show(os);
	os << IT_OUTDENT<< "</"<< typeid(*this).name() << ">"<< std::endl;
	return os;
}

item_t BasicIterator::next() {
	return produceNext();
}

//*************************************************
//*************************************************
//
//		SIMPLE BATCHING
//
//*************************************************
//*************************************************
#elif BATCHING_TYPE==1

std::ostream& BasicIterator::show(std::ostream& os) {
	os << IT_INDENT<< "<"<< typeid(*this).name() << ">"<< std::endl;
	_show(os);
	os << IT_OUTDENT<< "</"<< typeid(*this).name() << ">"<< std::endl;
	return os;
}

BasicIterator::BasicIterator(yy::location _loc) :
	loc(_loc), cItem(BATCHSIZE){
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}
BasicIterator::BasicIterator(const BasicIterator& it) :
	loc(it.loc), cItem(it.cItem) {
	this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}

BasicIterator::~BasicIterator() {
}
/**
 * This method should be abstract. Only because of compatibility issues we implemented it
 */
void BasicIterator::produceNext() {
	ZorbaErrorAlerts::error_alert(
					error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
					error_messages::SYSTEM_ERROR,
					NULL
				);
}

item_t BasicIterator::next() {
	if (cItem == BATCHSIZE) {
		produceNext();
		cItem = 0;
	}
	return batch[cItem++];
}


//*************************************************
//*************************************************
//
//		SUPER BATCHING
//
//*************************************************
//*************************************************
#elif BATCHING_TYPE==2

#endif 


}
