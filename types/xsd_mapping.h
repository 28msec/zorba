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

#ifndef XQP_XSD_INCLUDE_H
#define XQP_XSD_INCLUDE_H

#include <time.h>
#include <string.h>

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

#define AxiscChar char
#define AxiscXMLCh char

typedef int AxiscBool;

/**
 * @typedef xsdc__string
 * Axis C++ defined type for xml basic type string
 */
typedef AxiscChar * xsdc__string;


/**
 * @typedef xsdc__normalizedString
 * Axis C++ defined type for xml basic type normalizedString
 */
typedef AxiscChar * xsdc__normalizedString;


/**
 * @typedef xsdc__token
 * Axis C++ defined type for xml basic type token
 */
typedef AxiscChar * xsdc__token;


/**
 * @typedef xsdc__language
 * Axis C++ defined type for xml basic type language
 */
typedef AxiscChar * xsdc__language;


/**
 * @typedef xsdc__Name
 * Axis C++ defined type for xml basic type Name
 */
typedef AxiscChar * xsdc__Name;


/**
 * @typedef xsdc__NCName
 * Axis C++ defined type for xml basic type NCName
 */
typedef AxiscChar * xsdc__NCName;


/**
 * @typedef xsdc__ID
 * Axis C++ defined type for xml basic type ID
 */
typedef AxiscChar * xsdc__ID;


/**
 * @typedef xsdc__IDREF
 * Axis C++ defined type for xml basic type IDREF
 */
typedef AxiscChar * xsdc__IDREF;


/**
 * @typedef xsdc__IDREFS
 * Axis C++ defined type for xml basic type IDREFS
 */
typedef AxiscChar * xsdc__IDREFS;


/**
 * @typedef xsdc__ENTITY
 * Axis C++ defined type for xml basic type ENTITY
 */
typedef AxiscChar * xsdc__ENTITY;


/**
 * @typedef xsdc__ENTITIES
 * Axis C++ defined type for xml basic type ENTITIES
 */
typedef AxiscChar * xsdc__ENTITIES;


/**
 * @typedef xsdc__NMTOKEN
 * Axis C++ defined type for xml basic type NMTOKEN
 */
typedef AxiscChar * xsdc__NMTOKEN;


/**
 * @typedef xsdc__NMTOKENS
 * Axis C++ defined type for xml basic type NMTOKENS
 */
typedef AxiscChar * xsdc__NMTOKENS;


/**
 * @typedef xsdc__integer
 * Axis C++ defined type for xml basic type integer
 */
#ifdef WIN32
typedef __int64 xsdc__integer;
#else
typedef long long xsdc__integer;
#endif


/**
 * @typedef xsdc__int
 * Axis C++ defined type for xml basic type int
 */
typedef int xsdc__int;


/**
 * @typedef xsdc__long
 * Axis C++ defined type for xml basic type long
 */
#ifdef WIN32
typedef __int64 xsdc__long;
#else
typedef long long xsdc__long;
#endif


/**
 * @typedef xsdc__short
 * Axis C++ defined type for xml basic type short
 */
typedef short xsdc__short;


/**
 * @typedef xsdc__decimal
 * Axis C++ defined type for xml basic type decimal
 */
typedef double xsdc__decimal;


/**
 * @typedef xsdc__float
 * Axis C++ defined type for xml basic type float
 */
typedef float xsdc__float;


/**
 * @typedef xsdc__double
 * Axis C++ defined type for xml basic type double
 */
typedef double xsdc__double;


/**
 * @typedef xsdc__boolean
 * Axis C++ defined type for xml basic type boolean
 */
typedef enum { false_=0, true_ } xsdc__boolean;


/**
 * @typedef xsdc__byte
 * Axis C++ defined type for xml basic type byte
 */
typedef signed char xsdc__byte;


/**
 * @typedef xsdc__QName
 * Axis C++ defined type for xml basic type QName
 */
typedef AxiscChar * xsdc__QName;


/**
 * @typedef xsd__NOTATION
 * Axis C++ defined type for xml basic type NOTATION
 */
typedef AxiscChar * xsdc__NOTATION;


/**
 * @typedef xsdc__dateTime
 * Axis C++ defined type for xml basic type dateTime
 */
typedef struct tm xsdc__dateTime;


/**
 * @typedef xsdc__date
 * Axis C++ defined type for xml basic type date
 */
typedef struct tm xsdc__date;


/**
 * @typedef xsdc__time
 * Axis C++ defined type for xml basic type time
 */
typedef struct tm xsdc__time;


/**
 * @typedef xsdc__gYearMonth
 * Axis C++ defined type for xml basic type gYearMonth
 */
typedef struct tm xsdc__gYearMonth;


/**
 * @typedef xsdc__gYear
 * Axis C++ defined type for xml basic type gYear
 */
typedef struct tm xsdc__gYear;


/**
 * @typedef xsdc__gMonthDay
 * Axis C++ defined type for xml basic type gMonthDay
 */
typedef struct tm xsdc__gMonthDay;


/**
 * @typedef xsdc__gDay
 * Axis C++ defined type for xml basic type gDay
 */
typedef struct tm xsdc__gDay;


/**
 * @typedef xsdc__gMonth
 * Axis C++ defined type for xml basic type gMonth
 */
typedef struct tm xsdc__gMonth;


/**
 * @typedef xsdc__duration
 * Axis C++ defined type for xml basic type duration
 */
typedef long xsdc__duration;


/**
 * @typedef xsdc__nonNegativeInteger
 * Axis C++ defined type for xml basic type nonNegativeInteger
 */
#ifdef WIN32
typedef unsigned __int64 xsdc__nonNegativeInteger;
#else
typedef unsigned long long xsdc__nonNegativeInteger;
#endif


/**
 * @typedef xsdc__unsignedByte
 * Axis C++ defined type for xml basic type unsignedByte
 */
typedef unsigned char xsdc__unsignedByte;


/**
 * @typedef xsdc__unsignedInt
 * Axis C++ defined type for xml basic type unsignedInt
 */
typedef unsigned int xsdc__unsignedInt;


/**
 * @typedef xsdc__unsignedLong
 * Axis C++ defined type for xml basic type unsignedLong
 */
#ifdef WIN32
typedef unsigned __int64 xsdc__unsignedLong;
#else
typedef unsigned long long xsdc__unsignedLong;
#endif
/**
 * @typedef xsdc__unsignedShort
 * Axis C++ defined type for xml basic type unsignedShort
 */
typedef unsigned short xsdc__unsignedShort;


/**
 * @typedef xsdc__nonPositiveInteger
 * Axis C++ defined type for xml basic type nonPositiveInteger
 */
#ifdef WIN32
typedef __int64 xsdc__nonPositiveInteger;
#else
typedef long long xsdc__nonPositiveInteger;
#endif


/**
 * @typedef xsdc__positiveInteger
 * Axis C++ defined type for xml basic type positiveInteger
 */
#ifdef WIN32
typedef unsigned __int64 xsdc__positiveInteger;
#else
typedef unsigned long long xsdc__positiveInteger;
#endif


/**
 * @typedef xsdc__negativeInteger
 * Axis C++ defined type for xml basic type negativeInteger
 */
#ifdef WIN32
typedef __int64 xsdc__negativeInteger;
#else
typedef long long xsdc__negativeInteger;
#endif


/**
 * @struct xsdc__base64Binary
 * Axis C++ defined type for xml basic type base64Binary
 */
typedef struct
{
	/**
	 * Binary data
	 */
	xsdc__unsignedByte * __ptr;
    
	/**
	 * Length, in bytes, of binary data
	 */
	xsdc__int __size;

} xsdc__base64Binary;


/**
 * @struct xsdc__hexBinary
 * Axis C++ defined type for xml basic type hexBinary
 */
typedef struct
{
	/**
	 * Binary data
	 */
	xsdc__unsignedByte * __ptr;
    
	/**
	 * Length, in bytes, of binary data
	 */
	xsdc__int __size;

} xsdc__hexBinary;


/**
 * @typedef xsdc__anyURI
 * Axis C++ defined type for xml basic type anyURI
 */
typedef AxiscChar * xsdc__anyURI;



static const xsdc__boolean xsdc_boolean_true = (xsdc__boolean) 1;
static const xsdc__boolean xsdc_boolean_false = (xsdc__boolean) 0;



/**
 * @typedef AXISC_XML_String
 * Axis C++ defined type for xml encoded string. This is used only in AnyType.
 */
typedef char* AXISC_XML_String;


/**
 * @struct AxiscAnyType
 * Axis C++ defined type for handling xsd:any.
 */
typedef struct
{
	/**
	 * @var _array Contains an array of xml encoded strings.
	 */
	AXISC_XML_String* _array;

	/**
	 * @var _size Contains how many xml strings are there in _array
	 */
	int _size;
} AxiscAnyType;



}	/* namespace xqp */
#endif	/* XQP_AXIS_XSD_H */
