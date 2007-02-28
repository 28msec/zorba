/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: representations.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_REPRESENTATIONS_H
#define XQP_REPRESENTATIONS_H

namespace xqp {

/*______________________________________________________________________
|  
|	The mapping of basic schema types to C++ language types.
|_______________________________________________________________________*/

typedef std::string				xqp_anyURI;
typedef std::string				xqp_string;
typedef std::string				xqp_normalizedString;
typedef std::string				xqp_token;
typedef std::string				xqp_language;
typedef std::string				xqp_Name;
typedef std::string				xqp_NCName;
typedef std::string				xqp_ID;
typedef std::string				xqp_IDREF;
typedef std::string				xqp_IDREFS;
typedef std::string				xqp_ENTITY;
typedef std::string				xqp_ENTITIES;
typedef std::string				xqp_NMTOKEN;
typedef std::string				xqp_NMTOKENS;
typedef double   					xqp_integer;
typedef double						xqp_int;
typedef double						xqp_long;
typedef double						xqp_short;
typedef double						xqp_decimal;
typedef double						xqp_float;
typedef double						xqp_double;
typedef double						xqp_byte;
typedef bool							xqp_boolean;
typedef std::string				xqp_QName;
typedef std::string				xqp_NOTATION;
typedef struct tm					xqp_dateTime;
typedef struct tm					xqp_date;
typedef struct tm					xqp_time;
typedef struct tm					xqp_gYearMonth;
typedef struct tm					xqp_gYear;
typedef struct tm					xqp_gMonthDay;
typedef struct tm					xqp_gDay;
typedef struct tm					xqp_gMonth;
typedef long							xqp_duration;
typedef double						xqp_nonNegativeInteger;
typedef double						xqp_unsignedByte;
typedef double						xqp_unsignedInt;
typedef double						xqp_unsignedLong;
typedef double						xqp_unsignedShort;
typedef double						xqp_nonPositiveInteger;
typedef double						xqp_positiveInteger;
typedef double						xqp_negativeInteger;
typedef void*							xqp_base64Binary;
typedef void*							xqp_base64Binary;
typedef void*							xqp_hexBinary;


} /* namespace xqp */
#endif /* XQP_REPRESENTATIONS_H */

