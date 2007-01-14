/*
 * Copyright 2003-2004 The Apache Software Foundation.
 * (c) Copyright IBM Corp. 2004, 2006 All Rights Reserved
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#ifndef XQP_XSD_MAPPING_H
#define XQP_XSD_MAPPING_H

#include <time.h>
#include <string>
#include <vector>

namespace xqp {

/*______________________________________________________________________
|
|	The mapping of basic xsd types to the C++ language types.
|	
|	The following xsd basic types are supported:
|	anyURI, base64Binary, boolean, byte, date, dateTime,
|	decimal, double, duration, float, hexBinary, int, integer,
|	long, NMTOKEN, NOTATION, QName, short, string, time,
|	unsignedByte, unsignedInt, unsignedLong, and unsignedShort.
|_______________________________________________________________________*/

/**
 * @typedef xsd_string
 * Axis C++ defined type for xml basic type string
 */
typedef std::string xsd_string;


/**
 * @typedef xsd_normalizedString
 * Axis C++ defined type for xml basic type normalizedString
 */
typedef std::string xsd_normalizedString;


/**
 * @typedef xsd_token
 * Axis C++ defined type for xml basic type token
 */
typedef std::string xsd_token;


/**
 * @typedef xsd_language
 * Axis C++ defined type for xml basic type language
 */
typedef std::string xsd_language;


/**
 * @typedef xsd_Name
 * Axis C++ defined type for xml basic type Name
 */
typedef std::string xsd_Name;


/**
 * @typedef xsd_NCName
 * Axis C++ defined type for xml basic type NCName
 */
typedef std::string xsd_NCName;


/**
 * @typedef xsd_ID
 * Axis C++ defined type for xml basic type ID
 */
typedef std::string xsd_ID;


/**
 * @typedef xsd_IDREF
 * Axis C++ defined type for xml basic type IDREF
 */
typedef std::string xsd_IDREF;


/**
 * @typedef xsd_IDREFS
 * Axis C++ defined type for xml basic type IDREFS
 */
typedef std::string xsd_IDREFS;


/**
 * @typedef xsd_ENTITY
 * Axis C++ defined type for xml basic type ENTITY
 */
typedef std::string xsd_ENTITY;


/**
 * @typedef xsd_ENTITIES
 * Axis C++ defined type for xml basic type ENTITIES
 */
typedef std::string xsd_ENTITIES;


/**
 * @typedef xsd_NMTOKEN
 * Axis C++ defined type for xml basic type NMTOKEN
 */
typedef std::string xsd_NMTOKEN;


/**
 * @typedef xsd_NMTOKENS
 * Axis C++ defined type for xml basic type NMTOKENS
 */
typedef std::string xsd_NMTOKENS;


/**
 * @typedef xsd_integer
 * Axis C++ defined type for xml basic type integer
 */
#ifdef WIN32
typedef __int64 xsd_integer;
#else
typedef long long xsd_integer;
#endif


/**
 * @typedef xsd_int
 * Axis C++ defined type for xml basic type int
 */
typedef int xsd_int;


/**
 * @typedef xsd_long
 * Axis C++ defined type for xml basic type long
 */
#ifdef WIN32
typedef __int64 xsd_long;
#else
typedef long long xsd_long;
#endif


/**
 * @typedef xsd_short
 * Axis C++ defined type for xml basic type short
 */
typedef short xsd_short;


/**
 * @typedef xsd_decimal
 * Axis C++ defined type for xml basic type decimal
 */
typedef double xsd_decimal;


/**
 * @typedef xsd_float
 * Axis C++ defined type for xml basic type float
 */
typedef float xsd_float;


/**
 * @typedef xsd_double
 * Axis C++ defined type for xml basic type double
 */
typedef double xsd_double;


/**
 * @typedef xsd_boolean
 * Axis C++ defined type for xml basic type boolean
 */
typedef enum { false_=0, true_=1 } xsd_boolean;


/**
 * @typedef xsd_byte
 * Axis C++ defined type for xml basic type byte
 */
typedef signed char xsd_byte;


/**
 * @typedef xsd_QName
 * Axis C++ defined type for xml basic type QName
 */
typedef std::string xsd_QName;


/**
 * @typedef xsd_NOTATION
 * Axis C++ defined type for xml basic type NOTATION
 */
typedef std::string xsd_NOTATION;


/**
 * @typedef xsd_dateTime
 * Axis C++ defined type for xml basic type dateTime
 */
typedef struct tm xsd_dateTime;


/**
 * @typedef xsd_date
 * Axis C++ defined type for xml basic type date
 */
typedef struct tm xsd_date;


/**
 * @typedef xsd_time
 * Axis C++ defined type for xml basic type time
 */
typedef struct tm xsd_time;


/**
 * @typedef xsd_gYearMonth
 * Axis C++ defined type for xml basic type gYearMonth
 */
typedef struct tm xsd_gYearMonth;


/**
 * @typedef xsd_gYear
 * Axis C++ defined type for xml basic type gYear
 */
typedef struct tm xsd_gYear;


/**
 * @typedef xsd_gMonthDay
 * Axis C++ defined type for xml basic type gMonthDay
 */
typedef struct tm xsd_gMonthDay;


/**
 * @typedef xsd_gDay
 * Axis C++ defined type for xml basic type gDay
 */
typedef struct tm xsd_gDay;


/**
 * @typedef xsd_gMonth
 * Axis C++ defined type for xml basic type gMonth
 */
typedef struct tm xsd_gMonth;


/**
 * @typedef xsd_duration
 * Axis C++ defined type for xml basic type duration
 */
typedef long xsd_duration;


/**
 * @typedef xsd_nonNegativeInteger
 * Axis C++ defined type for xml basic type nonNegativeInteger
 */
#ifdef WIN32
typedef unsigned __int64 xsd_nonNegativeInteger;
#else
typedef unsigned long long xsd_nonNegativeInteger;
#endif


/**
 * @typedef xsd_unsignedByte
 * Axis C++ defined type for xml basic type unsignedByte
 */
typedef unsigned char xsd_unsignedByte;


/**
 * @typedef xsd_unsignedInt
 * Axis C++ defined type for xml basic type unsignedInt
 */
typedef unsigned int xsd_unsignedInt;


/**
 * @typedef xsd_unsignedLong
 * Axis C++ defined type for xml basic type unsignedLong
 */
#ifdef WIN32
typedef unsigned __int64 xsd_unsignedLong;
#else
typedef unsigned long long xsd_unsignedLong;
#endif
/**
 * @typedef xsd_unsignedShort
 * Axis C++ defined type for xml basic type unsignedShort
 */
typedef unsigned short xsd_unsignedShort;


/**
 * @typedef xsd_nonPositiveInteger
 * Axis C++ defined type for xml basic type nonPositiveInteger
 */
#ifdef WIN32
typedef __int64 xsd_nonPositiveInteger;
#else
typedef long long xsd_nonPositiveInteger;
#endif


/**
 * @typedef xsd_positiveInteger
 * Axis C++ defined type for xml basic type positiveInteger
 */
#ifdef WIN32
typedef unsigned __int64 xsd_positiveInteger;
#else
typedef unsigned long long xsd_positiveInteger;
#endif


/**
 * @typedef xsd_negativeInteger
 * Axis C++ defined type for xml basic type negativeInteger
 */
#ifdef WIN32
typedef __int64 xsd_negativeInteger;
#else
typedef long long xsd_negativeInteger;
#endif


/**
 * @struct xsd_base64Binary
 * Axis C++ defined type for xml basic type base64Binary
 */
typedef struct
{
	xsd_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
} xsd_base64Binary;


/**
 * @struct xsd_hexBinary
 * Axis C++ defined type for xml basic type hexBinary
 */
typedef struct
{
	xsd_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
} xsd_hexBinary;


/**
 * @typedef xsd_anyURI
 * Axis C++ defined type for xml basic type anyURI
 */
typedef std::string xsd_anyURI;


static const xsd_boolean xsd_boolean_true = (xsd_boolean) 1;
static const xsd_boolean xsd_boolean_false = (xsd_boolean) 0;


/**
 * @struct AxiscAnyType
 * Axis C++ defined type for handling xsd:any.
 */
typedef struct
{
	// an array of xml encoded strings.
	std::vector<std::string> _array;

} AnyType;



}	/* namespace xqp */
#endif	/* XQP_XSD_MAPPING_H */
