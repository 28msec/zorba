/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "BooleanImpl.h"

namespace xqp{

/*______________________________________________________________________
|  
|	15.1.1 fn:boolean
|	fn:boolean($arg as item()*) as xs:boolean
|	
|	Computes the effective boolean value of the sequence $arg.
|_______________________________________________________________________*/
std::ostream& FnBooleanIterator::_show(std::ostream& os)
const
{
	this->arg0_->show(os);
	return os;
}

item_t FnBooleanIterator::nextImpl()
{
	item_t n_h;
	sequence_type_t type;
	const numericValue* numVal;
	const stringValue* strVal;
	string str;
	
	STACK_INIT();
	
	n_h = this->consumeNext(this->arg0_);
	
	if ( n_h == NULL) {
		STACK_PUSH (new booleanValue(false));
	} else {
		type = n_h->type();
	
		if (int(type & ANY_NODE) > 0) {
			STACK_PUSH(new booleanValue(true));
		} else if (int(type & BOOLEAN_TYPE) > 0) {
			STACK_PUSH(n_h);
		} else if (int(type & NUMERIC_TYPE) > 0) {
			numVal = dynamic_cast<const numericValue*>(&*n_h);
			if (numVal->val() == 0) {
				STACK_PUSH(new booleanValue(false));
			} else {
				STACK_PUSH(new booleanValue(true));
			}
		} else if (int(type & STRING_TYPE) > 0) {
			strVal = dynamic_cast<const stringValue*>(&*n_h);
			str = strVal->val();
			if (str.size() == 0) {
				STACK_PUSH(new booleanValue(false));
			} else {
				STACK_PUSH(new booleanValue(true));
			}
		} else if (int(type & ANY_URI_TYPE) > 0 || int(type & UNTYPED_ATOMIC_TYPE) > 0) {
			ZorbaErrorAlerts::error_alert(
				error_messages::XQP0004_SYSTEM_NOT_SUPPORTED,
				error_messages::SYSTEM_ERROR,
				NULL
			);
		} else {
			ZorbaErrorAlerts::error_alert(
				error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
				error_messages::RUNTIME_ERROR,
				NULL
			);
		}
	}
	
	STACK_PUSH(NULL);
	STACK_END();
}

void FnBooleanIterator::resetImpl() {
	this->resetChild(this->arg0_);
}

void FnBooleanIterator::releaseResourcesImpl() {
	this->releaseChildResources(this->arg0_);
}

}
