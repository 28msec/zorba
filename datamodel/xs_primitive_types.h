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

#include <time.h>
#include <ctime>
#include <string>
#include <vector>

#include "../util/xqp_exception.h"


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

typedef struct
{
	xqp_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
} xqp_base64Binary;

typedef struct
{
	xqp_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
} xqp_hexBinary;

typedef struct
{
	// an array of xml encoded strings.
	std::vector<std::string> _array;
} xs_anyType;



/*______________________________________________________________________
|  
|	Schema primitive type hierarchy.
|	[http://www.w3.org/TR/xmlschema-2/#built-in-primitive-datatypes]
|_______________________________________________________________________*/

class xs_anyURI : public xs_anyAtomicType
{
protected:
	xqp_anyURI value;

public:
	xs_anyURI::xs_anyURI(xqp_anyURI const& _value);
	xs_anyURI::xs_anyURI();
	xs_anyURI::~xs_anyURI();

public:
	void xs_anyURI::encode(xml_ostream* xos)
	throw (xqp_exception)
    
	void xs_anyURI::decode(xml_istream& xis)
	throw (xqp_exception);

public:
	uint32_t get_fingerprint() const;
	std::string get_displayname() const;
	std::string describe() const;

	bool operator==(schema_type const&);

	bool is_complex() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_anonymous() const;
	bool is_atomic() const;
	bool is_list() const;
	bool is_union() const;
	bool is_external() const;
	bool is_namespace_sensitive() const;
	bool allows_derivation(enum derivation_method derivation) const;

	enum type::type_name get_type() const;
	enum type::whitespace_action get_whitespace_action() const;
	enum type::derivation_method get_derivation_method() const;
	enum type::validation_status get_validation_status() const;

	rchandle<schema_type> get_base_type() const throws xqp_exception;
	rchandle<atomic_type> get_common_atomic_type() const;
	rchandle<schema_type> get_builtin_base_type() const;

	void analyze_expression(
		rchandle<expr>,
		int kind,
		context const&) const
	throw (xqp_exception);

	rchandle<item_iterator> atomize(node const&) const
	throw (xqp_xception);

	rchandle<item_iterator> get_typed_value(node const&)
	const throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(
		char const*,
		rchandle<namespace_resolver>)
	throw (xqp_exception);

	rchandle<validation_error> validate_content(
		char const* value,
		rchandle<namespace_resolver>)
	throw (xqp_exception);

};



class xs_base64Binary : public xs_anySimpleType
{
protected:
	xqp_base64Binary value;

public:
	xs_base64Binary(xqp_base64Binary const& _value);
	xs_base64Binary();
	~xs_base64Binary();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_boolean : public xs_anySimpleType
{
protected:
	xqp_boolean value;
	
public:
	xs_boolean(xqp_boolean const& _value);
	xs_boolean();
	~xs_boolean();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);
    
	void decode(xml_istream& xis)
	throw (xqp_exception);

};



lass xs_byte : public xs_short
{
protected:
	xqp_byte value;

public:
	xs_byte(xqp_byte const& _value);
	xs_byte();
	~xs_byte();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_date : public xs_anySimpleType
{
protected:
	xqp_date value;

public:
	xs_date(xqp_date const& _value);
	xs_date();
	~xs_date();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_dateTime : public xs_anySimpleType
{
protected:
	xqp_dateTime value;

public:
	xs_dateTime(xqp_dateTime const& _value);
	xs_dateTime();
	~xs_dateTime();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_decimal : public xs_anySimpleType
{
protected:
	xqp_decimal value;

public:
	xs_decimal(xqp_decimal const& _value);
	xs_decimal();
	~xs_decimal();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_double : public xs_anySimpleType
{
protected:
	xqp_double value;

public:
	xs_double(xqp_double const& _value);
	xs_double();
	~xs_double();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_duration : public xs_anySimpleType
{
protected:
	xqp_duration value;

public:
	xs_duration(xqp_duration const& _value);
	xs_duration();
	~xs_duration();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_ENTITIES : public xs_anySimpleType
{
protected:
	xqp_ENTITIES value;

public:
	xs_ENTITIES(xqp_ENTITIES const& _value);
	xs_ENTITIES();
	~xs_ENTITIES();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_ENTITY : public xs_NCName
{
protected:
	xqp_ENTITY value;

public:
	xs_ENTITY(xqp_ENTITY const& _value);
	xs_ENTITY();
	~xs_ENTITY();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_float : public xs_anyAtomicType
{
protected:
	xqp_float value;

public:
	xs_float(xqp_float const& _value);
	xs_float();
	~xs_float();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_gDay : public xs_anyAtomicType
{
protected:
	xqp_gDay value;

public:
	xs_gDay(xqp_gDay const& _value);
	xs_gDay();
	~xs_gDay();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_gMonth : public xs_anyAtomicType
{
protected:
	xqp_gMonth value;

public:
	xs_gMonth(xqp_gMonth const& _value);
	xs_gMonth();
	~xs_gMonth();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_gMonthDay : public xs_anyAtomicType
{
protected:
	xqp_gMonthDay value;

public:
	xs_gMonthDay(xqp_gMonthDay const& _value);
	xs_gMonthDay();
	~xs_gMonthDay();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_gYear : public xs_anyAtomicType
{
protected:
	xqp_gYear value;

public:
	xs_gYear(xqp_gYear const& _value);
	xs_gYear();
	~xs_gYear();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_gYearMonth : public xs_anyAtomicType
{
protected:
	xqp_gYearMonth value;

public:
	xs_gYearMonth(xqp_gYearMonth const& _value);
	xs_gYearMonth();
	~xs_gYearMonth();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_hexBinary : public xs_anyAtomicType
{
protected:
	xqp_hexBinary value;

public:
	xs_hexBinary(xqp_hexBinary const& _value);
	xs_hexBinary();
	~xs_hexBinary();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_ID : public xs_NCName
{
protected:
	xqp_id value;

public:
	xs_ID(xqp_id const& _value);
	xs_ID();
	~xs_ID();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_IDREF : public xs_NCName
{
protected:
	xqp_IDREF value;

public:
	xs_IDREF(xqp_IDREF const& _value);
	xs_IDREF();
	~xs_IDREF();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_IDREFS : public xs_anySimpleType
{
protected:
	xqp_IDREFS value;

public:
	xs_IDREFS(xqp_IDREFS const& _value);
	xs_IDREFS();
	~xs_IDREFS();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_int : public xs_long
{
protected:
	xqp_int value;

public:
	xs_int(xqp_int const& _value);
	xs_int();
	~xs_int();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_integer : public xs_decimal
{
protected:
	xqp_integer value;

public:
	xs_integer(xqp_integer const& _value);
	xs_integer();
	~xs_integer();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_language : public xs_token
{
protected:
	xqp_language value;

public:
	xs_language(xqp_language const& _value);
	xs_language();
	~xs_language();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_long : public xs_integer
{
protected:
	xqp_long value;

public:
	xs_long(xqp_long const& _value);
	xs_long();
	~xs_long();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_NCName : public xs_Name
{
protected:
	xqp_NCName value;

public:
	xs_NCName(xqp_NCName const& _value);
	xs_NCName();
	~xs_NCName();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_NMTOKEN : public xs_token
{
protected:
	xqp_NMTOKEN value;

public:
	xs_NMTOKEN(xqp_NMTOKEN const& _value);
	xs_NMTOKEN();
	~xs_NMTOKEN();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_NMTOKENS : public xs_anySimpleType
{
protected:
	xqp_NMTOKENS value;

public:
	xs_NMTOKENS(xqp_NMTOKENS const& _value);
	xs_NMTOKENS();
	~xs_NMTOKENS();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_NOTATION : public xs_anyAtomicType
{
protected:
	xqp_NOTATION value;

public:
	xs_NOTATION(xqp_NOTATION const& _value);
	xs_NOTATION();
	~xs_NOTATION();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_Name : public xs_token
{
protected:
	xqp_Name value;

public:
	xs_Name(xqp_name const& _value);
	xs_Name();
	~xs_Name();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_negativeInteger : public xs_nonPositiveInteger
{
protected:
	xqp_negativeInteger value;

public:
	xs_negativeInteger(xqp_negativeInteger const& _value);
	xs_negativeInteger();
	~xs_negativeInteger();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class non_negativeInteger : public xs_integer
{
protected:
	xqp_nonNegativeInteger value;

public:
	xs_nonNegativeInteger(xqp_nonNegativeInteger const& _value);
	xs_nonNegativeInteger();
	~xs_nonNegativeInteger();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_nonPositiveInteger : public xs_integer
{
protected:
	xqp_nonPositiveInteger value;

public:
	xs_nonPositiveInteger(xqp_nonPositiveInteger const& _value);
	xs_nonPositiveInteger();
	~xs_nonPositiveInteger();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_normalizedString : public xs_string
{
protected:
	xqp_normalizedString value;

public:
	xs_normalizedString(xqp_normalizedString const& _value);
	xs_normalizedString();
	~xs_normalizedString();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_positiveInteger : public xs_nonNegativeInteger
{
protected:
	xqp_positiveInteger value;

public:
	xs_positiveInteger(xqp_positiveInteger const& _value);
	xs_positiveInteger();
	~xs_positiveInteger();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_short : public xs_int
{
protected:
	xqp_short value;

public:
	xs_short(xqp_short const& _value);
	xs_short();
	~xs_short();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_string : public xs_anyAtomicType
{
protected:
	xqp_string value;

public:
	xs_string(xqp_string const& _value);
	xs_string();
	~xs_string();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_time : public xs_anyAtomicType
{
protected:
	xqp_time value;

public:
	xs_time(xqp_time const& _value);
	xs_time();
	~xs_time();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_token : public xs_normalizedString
{
protected:
	xqp_token value;

public:
	xs_token(xqp_token const& _value);
	xs_token();
	~xs_token();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_unsignedByte : public xs_unsignedShort
{
protected:
	xqp_unsignedByte value;

public:
	xs_unsignedByte(xqp_unsignedByte const& _value);
	xs_unsignedByte();
	~xs_unsignedByte();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_unsignedInt : public xs_unsignedLong
{
protected:
	xqp_unsignedInt value;

public:
	xs_unsignedInt(xqp_unsignedInt const& _value);
	xs_unsignedInt();
	~xs_unsignedInt();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_unsignedLong : public xs_nonNegativeInteger
{
protected:
	xqp_unsignedLong value;

public:
	xs_unsignedLong(xqp_unsignedLong const& _value);
	xs_unsignedLong();
	~xs_unsignedLong();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};



class xs_unsignedShort : public xs_unsignedInt
{
protected:
	xqp_unsignedShort value;

public:
	xs_unsignedShort(xqp_unsignedShort const& _value);
	xs_unsignedShort();
	~xs_unsignedShort();

public:
	type::typename_t get_type();

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

};


}	/* namespace xqp */
#endif	/* XQP_XS_PRIMITIVE_TYPES_H */
