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
fn_boolean_iterator::fn_boolean_iterator(
	yy::location loc, 
	iterator_t _arg0)
:
	basic_iterator(NULL, loc),
	arg0(_arg0)
{
	this->donef = false;
}

void fn_boolean_iterator::_open()
{
	arg0->open();
}

void fn_boolean_iterator::_close()
{
	arg0->close();
}

std::ostream& fn_boolean_iterator::_show(std::ostream& os)
const
{
	arg0->show(os);
	return os;
}

bool fn_boolean_iterator::done() const
{
	return this->donef;
}

item_t fn_boolean_iterator::_next()
{
	this->donef = true;
	if(arg0->done()){///daniel ?? should it return NULL?
		return new booleanValue(false);
	}
	item_t n_h = arg0->next();

	if(&*n_h == NULL)
		return NULL;

	sequence_type_t type = n_h->type();
	bool retValue = false;
	
	if (int(type & ANY_NODE) > 0) {
		return new booleanValue(true);
	} else if (int(type & BOOLEAN_TYPE) > 0) {
		return n_h;
	} else if (int(type & NUMERIC_TYPE) > 0) {
		const numericValue& v = dynamic_cast<const numericValue&>(*n_h);
		if (v.val() == 0) {
			return new booleanValue(false);
		} else {
			return new booleanValue(true);
		}
	} else if (int(type & STRING_TYPE) > 0) {
		const stringValue& v = dynamic_cast<const stringValue&>(*n_h);
		string str = v.val();
		if (str.size() == 0) {
			return new booleanValue(false);
		} else {
			return new booleanValue(true);
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
	return NULL;
}

}
