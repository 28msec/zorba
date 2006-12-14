/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: builtin_types.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_BUILTIN_TYPES_H
#define XQP_BUILTIN_TYPES_H

/*
Pick up the Apache axis module.
*/

namespace xqp {

enum static_type_t {

//Schema primitive datatypes
	xs_string,
	xs_boolean,
	xs_decimal,
	xs_float,
	xs_double,
	xs_duration,
	xs_dateTime,
	xs_time,
	xs_date,
	xs_gYearMonth,
	xs_gYear,
	xs_gMonthDay,
	xs_gDay,
	xs_gMonth,
	xs_hexBinary,
	xs_base64Binary,
	xs_anyURI,
	xs_QName,
	xs_NOTATION,

//XQuery primitive datatypes
	xs_untyped,
	xs_untypedAtomic,
	xs_anyAtomicType,
	xs_dayTimeDuration,
	xs_yearMonthDuration

};

}	/* namespace xqp */
#endif	/* XQP_BUILTIN_TYPES_H */
