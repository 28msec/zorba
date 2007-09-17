/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: representations.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_REPRESENTATIONS_H
#define XQP_REPRESENTATIONS_H

#include "../utf8/xqpString.h"

namespace xqp {

/*______________________________________________________________________
|  
|	The mapping of basic schema types to C++ language types.
|_______________________________________________________________________*/

typedef std::string					xqp_anyURI;
typedef std::string					xqp_string;
typedef std::string					xqp_normalizedString;
typedef std::string					xqp_token;
typedef std::string					xqp_language;
typedef std::string					xqp_Name;
typedef std::string					xqp_NCName;
typedef std::string					xqp_ID;
typedef std::string					xqp_IDREF;
typedef std::string					xqp_IDREFS;
typedef std::string					xqp_ENTITY;
typedef std::string					xqp_ENTITIES;
typedef std::string					xqp_NMTOKEN;
typedef std::string					xqp_NMTOKENS;
typedef long long   				xqp_integer;
typedef int32_t							xqp_int;
typedef long								xqp_long;
typedef short								xqp_short;
typedef long double					xqp_decimal;
typedef float								xqp_float;
typedef double							xqp_double;
typedef char								xqp_byte;
typedef bool								xqp_boolean;
typedef std::string					xqp_QName;
typedef std::string					xqp_NOTATION;
typedef struct tm						xqp_dateTime;
typedef struct tm						xqp_date;
typedef struct tm						xqp_time;
typedef struct tm						xqp_gYearMonth;
typedef struct tm						xqp_gYear;
typedef struct tm						xqp_gMonthDay;
typedef struct tm						xqp_gDay;
typedef struct tm						xqp_gMonth;
typedef long								xqp_duration;
typedef long double					xqp_nonNegativeInteger;
typedef unsigned char				xqp_unsignedByte;
typedef uint32_t						xqp_unsignedInt;
typedef unsigned long				xqp_unsignedLong;
typedef unsigned short			xqp_unsignedShort;
typedef long long						xqp_nonPositiveInteger;
typedef unsigned long long	xqp_positiveInteger;
typedef long long						xqp_negativeInteger;
typedef void*								xqp_base64Binary;
typedef void*								xqp_base64Binary;
typedef void*								xqp_hexBinary;


} /* namespace xqp */
#endif /* XQP_REPRESENTATIONS_H */

