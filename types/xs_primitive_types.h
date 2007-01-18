/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_types.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen (pcp071098@yahoo.com)
 */

#ifndef XQP_XS_PRIMITIVE_TYPES_H
#define XQP_XS_PRIMITIVE_TYPES_H

#include "base_types.h"
#include "../util/xqp_exception.h"
#include "../values/node.h"

#include <time.h>
#include <ctime>
#include <ostream>
#include <sstream>
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
typedef long long						xqp_integer;
typedef int									xqp_int;
typedef long long						xqp_long;
typedef short								xqp_short;
typedef double							xqp_decimal;
typedef float								xqp_float;
typedef double							xqp_double;
typedef bool								xqp_boolean;
typedef signed char					xqp_byte;
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
typedef unsigned long long	xqp_nonNegativeInteger;
typedef unsigned char				xqp_unsignedByte;
typedef unsigned int				xqp_unsignedInt;
typedef unsigned long long	xqp_unsignedLong;
typedef unsigned short			xqp_unsignedShort;
typedef long long						xqp_nonPositiveInteger;
typedef unsigned long long	xqp_positiveInteger;
typedef long long						xqp_negativeInteger;

class xqp_base64Binary
{
public:
	xqp_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
	friend std::ostream& operator<<(std::ostream&, xqp_base64Binary const&);
};

class xqp_hexBinary
{
public:
	xqp_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
	friend std::ostream& operator<<(std::ostream&, xqp_hexBinary const&);
};


/*______________________________________________________________________
|  
|	Schema primitive type hierarchy.
|	[http://www.w3.org/TR/xmlschema-2/#built-in-primitive-datatypes]
|_______________________________________________________________________*/

class xs_anyURI : public xs_anyAtomicType
{
protected:
	xs_anyURI();
	~xs_anyURI();

public:
	std::string get_displayname() const;
	std::string describe() const;

	bool operator==(schema_type const&);

	bool is_complex() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_anonymous() const;
	bool is_list() const;
	bool is_union() const;
	bool is_external() const;
	bool is_namespace_sensitive() const;

	enum type::typecode get_typecode() const;

	schema_type const* get_base_type() const throw (xqp_exception);
	atomic_type const* get_common_atomic_type() const;
	schema_type const* get_builtin_base_type() const;

};



class xs_QName : public xs_anyAtomicType
{
protected:
	xs_QName();
	~xs_QName();

public:
	type::typecode get_typecode() const;

};



class xs_base64Binary : public xs_anyAtomicType
{
protected:
	xs_base64Binary();
	~xs_base64Binary();

public:
	type::typecode get_typecode() const;

};



class xs_boolean : public xs_anyAtomicType
{
protected:
	xs_boolean();
	~xs_boolean();

public:
	type::typecode get_typecode() const;

};



class xs_decimal : public xs_anyAtomicType
{
protected:
	xs_decimal();
	~xs_decimal();

public:
	type::typecode get_typecode() const;

};



class xs_integer : public xs_decimal
{
protected:
	xs_integer();
	~xs_integer();

public:
	type::typecode get_typecode() const;

};



class xs_long : public xs_integer
{
protected:
	xs_long();
	~xs_long();

public:
	type::typecode get_typecode() const;

};



class xs_int : public xs_long
{
protected:
	xs_int();
	~xs_int();

public:
	type::typecode get_typecode() const;

};



class xs_short : public xs_int
{
protected:
	xs_short();
	~xs_short();

public:
	type::typecode get_typecode() const;

};



class xs_byte : public xs_short
{
protected:
	xs_byte();
	~xs_byte();

public:
	type::typecode get_typecode() const;

};



class xs_date : public xs_anyAtomicType
{
protected:
	xs_date();
	~xs_date();

public:
	type::typecode get_typecode() const;

};



class xs_dateTime : public xs_anyAtomicType
{
protected:
	xs_dateTime();
	~xs_dateTime();

public:
	type::typecode get_typecode() const;

};



class xs_double : public xs_anyAtomicType
{
protected:
	xs_double();
	~xs_double();

public:
	type::typecode get_typecode() const;

};



class xs_duration : public xs_anyAtomicType
{
protected:
	xs_duration();
	~xs_duration();

public:
	type::typecode get_typecode() const;

};



class xs_ENTITIES : public xs_anySimpleType
{
protected:
	xs_ENTITIES();
	~xs_ENTITIES();

public:
	type::typecode get_typecode() const;

};



class xs_string : public xs_anyAtomicType
{
protected:
	xs_string();
	~xs_string();

public:
	type::typecode get_typecode() const;

};



class xs_normalizedString : public xs_string
{
protected:
	xs_normalizedString();
	~xs_normalizedString();

public:
	type::typecode get_typecode() const;

};



class xs_token : public xs_normalizedString
{
protected:
	xs_token();
	~xs_token();

public:
	type::typecode get_typecode() const;

};



class xs_Name : public xs_token
{
protected:
	xs_Name();
	~xs_Name();

public:
	type::typecode get_typecode() const;

};



class xs_NCName : public xs_Name
{
protected:
	xs_NCName();
	~xs_NCName();

public:
	type::typecode get_typecode() const;

};



class xs_ENTITY : public xs_NCName
{
protected:
	xs_ENTITY();
	~xs_ENTITY();

public:
	type::typecode get_typecode() const;

};



class xs_float : public xs_anyAtomicType
{
protected:
	xs_float();
	~xs_float();

public:
	type::typecode get_typecode() const;

};



class xs_gDay : public xs_anyAtomicType
{
protected:
	xs_gDay();
	~xs_gDay();

public:
	type::typecode get_typecode() const;

};



class xs_gMonth : public xs_anyAtomicType
{
protected:
	xs_gMonth();
	~xs_gMonth();

public:
	type::typecode get_typecode() const;

};



class xs_gMonthDay : public xs_anyAtomicType
{
protected:
	xs_gMonthDay();
	~xs_gMonthDay();

public:
	type::typecode get_typecode() const;

};



class xs_gYear : public xs_anyAtomicType
{

public:
	xs_gYear();
	~xs_gYear();

public:
	type::typecode get_typecode() const;

};



class xs_gYearMonth : public xs_anyAtomicType
{
protected:
	xs_gYearMonth();
	~xs_gYearMonth();

public:
	type::typecode get_typecode() const;

};



class xs_hexBinary : public xs_anyAtomicType
{
protected:
	xs_hexBinary();
	~xs_hexBinary();

public:
	type::typecode get_typecode() const;

};



class xs_ID : public xs_NCName
{
protected:
	xs_ID();
	~xs_ID();

public:
	type::typecode get_typecode() const;

};



class xs_IDREF : public xs_NCName
{
protected:
	xs_IDREF();
	~xs_IDREF();

public:
	type::typecode get_typecode() const;

};



class xs_IDREFS : public xs_anySimpleType
{
protected:
	xs_IDREFS();
	~xs_IDREFS();

public:
	type::typecode get_typecode() const;

};



class xs_language : public xs_token
{
protected:
	xs_language();
	~xs_language();

public:
	type::typecode get_typecode() const;

};



class xs_NMTOKEN : public xs_token
{
protected:
	xs_NMTOKEN();
	~xs_NMTOKEN();

public:
	type::typecode get_typecode() const;

};



class xs_NMTOKENS : public xs_anySimpleType
{
protected:
	xs_NMTOKENS();
	~xs_NMTOKENS();

public:
	type::typecode get_typecode() const;

};



class xs_NOTATION : public xs_anyAtomicType
{
protected:
	xs_NOTATION();
	~xs_NOTATION();

public:
	type::typecode get_typecode() const;

};



class xs_nonPositiveInteger : public xs_integer
{
protected:
	xs_nonPositiveInteger();
	~xs_nonPositiveInteger();

public:
	type::typecode get_typecode() const;

};



class xs_negativeInteger : public xs_nonPositiveInteger
{
protected:
	xs_negativeInteger();
	~xs_negativeInteger();

public:
	type::typecode get_typecode() const;

};



class xs_nonNegativeInteger : public xs_integer
{
protected:
	xs_nonNegativeInteger();
	~xs_nonNegativeInteger();

public:
	type::typecode get_typecode() const;

};



class xs_positiveInteger : public xs_nonNegativeInteger
{
protected:
	xs_positiveInteger();
	~xs_positiveInteger();

public:
	type::typecode get_typecode() const;

};



class xs_time : public xs_anyAtomicType
{
protected:
	xs_time();
	~xs_time();

public:
	type::typecode get_typecode() const;

};



class xs_unsignedLong : public xs_nonNegativeInteger
{
protected:
	xs_unsignedLong();
	~xs_unsignedLong();

public:
	type::typecode get_typecode() const;

};



class xs_unsignedInt : public xs_unsignedLong
{
protected:
	xs_unsignedInt();
	~xs_unsignedInt();

public:
	type::typecode get_typecode() const;

};



class xs_unsignedShort : public xs_unsignedInt
{
protected:
	xs_unsignedShort();
	~xs_unsignedShort();

public:
	type::typecode get_typecode() const;

};


class xs_unsignedByte : public xs_unsignedShort
{
protected:
	xs_unsignedByte();
	~xs_unsignedByte();

public:
	type::typecode get_typecode() const;

};



}	/* namespace xqp */
#endif	/* XQP_XS_PRIMITIVE_TYPES_H */
