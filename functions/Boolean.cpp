/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "Boolean.h"
#include "BooleanImpl.h"

namespace xqp {

/*______________________________________________________________________
|  
|	15.1.1 fn:boolean
|	fn:boolean($arg as item()*) as xs:boolean
|	
|	Computes the effective boolean value of the sequence $arg.
|_______________________________________________________________________*/
fn_boolean::fn_boolean(const signature& sig):function(sig){}

iterator_t fn_boolean::operator()(
	zorba* zorp,
	yy::location loc,
	vector<iterator_t>& argv) const
{
	if (!validate_args(argv)) {
		ZorbaErrorAlerts::error_alert(
			error_messages::XPST0017_STATIC_FUNCTION_NOT_FOUND,
			error_messages::STATIC_ERROR,
			&loc
		);
	}
	return new fn_boolean_iterator(loc, argv[0]);
}

sequence_type_t fn_boolean::type_check(
	signature& sig) const {
	return xs_boolean;
}

bool fn_boolean::validate_args(vector<iterator_t>& argv) const {
	return (argv.size() == 1);
}

}
