/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "Accessors.h"
#include "AccessorsImpl.h"

namespace xqp {

	fn_data_func::fn_data_func ( const signature& sig ) :function ( sig ) {}

	Iterator_t
	fn_data_func::operator() (
	    yy::location loc,
	    vector<Iterator_t>& argv ) const
	{
		if ( !validate_args ( argv ) )
		{
			ZorbaErrorAlerts::error_alert (
			    error_messages::XPST0017_STATIC_FUNCTION_NOT_FOUND,
			    error_messages::STATIC_ERROR,
			    &loc
			);
		}
		return new FnDataIterator ( loc, argv[0] );
	}

	TypeCode
	fn_data_func::type_check (
	    signature& sig ) const
	{
// 		return xs_anySimpleTypeSeq;
		return xs_anyTypeSeq;
	}

	bool
	fn_data_func::validate_args ( vector<Iterator_t>& argv ) const
	{
		return ( argv.size() == 1 );
	}
	
} /* namespace xqp */
