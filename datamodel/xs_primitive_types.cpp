
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "xs_primitive_types.h"

using namespace std;
namespace xqp {
 


///////////////////////////////
//  anyURI
///////////////////////////////

xs_anyURI::xs_anyURI()
{
}
 
xs_anyURI::~xs_anyURI()
{
}

xs_anyURI::xs_anyURI(
	xqp_anyURI const& _value)
:
	value(_value)
{
}

type::typename_t xs_anyURI::get_type()
{
	return XS_ANYURI;
}

void xs_anyURI::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_anyURI::decode(xml_istream& xis)
throw (xqp_exception)
{
}
   


///////////////////////////////
//  Base64Binary
///////////////////////////////

xs_base64Binary::xs_base64Binary()
{
}
 
xs_base64Binary::~xs_base64Binary()
{
}

xs_base64Binary::xs_base64Binary(
	xqp_base64Binary const& _value)
:
	value(_value)
{
}

type::typename_t Base64Binary::get_type()
{
	return type::XS_BASE64BINARY;
}

	//int len = apr_base64_encode_len(value->getSize());	    
	//len = apr_base64_encode_binary(serializedValue, pTemp, size);

void xs_base64Binary::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_base64Binary::decode(xml_istream& xis)
throw (xqp_exception)
{
}
   
 
 
///////////////////////////////
//  xs_boolean
///////////////////////////////

xs_boolean::xs_boolean()
{
}
 
xs_boolean::~xs_boolean()
{
}

xs_boolean::xs_boolean(
	xqp_boolean const& _value)
:
	value(_value)
{
}

type::typename_t xs_boolean::get_type()
{
	return XS_ANYURI;
}

void xs_boolean::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_boolean::decode(xml_istream& xis)
throw (xqp_exception)
{
}
   


///////////////////////////////
//  xs_byte
///////////////////////////////

xs_byte::xs_byte()
{
}
 
xs_byte::~xs_byte()
{
}

xs_byte::xs_byte(
	xqp_byte const& _value)
:
	value(_value)
{
}

type::typename_t xs_byte::get_type()
{
	return XS_ANYURI;
}

void xs_byte::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_byte::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_date
///////////////////////////////

xs_date::xs_nnn()
{
}
 
xs_date::~xs_date()
{
}

xs_date::xs_date(
	xqp_date const& _value)
:
	value(_value)
{
}

type::typename_t xs_date::get_type()
{
	return XS_ANYURI;
}

void xs_date::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_date::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_dateTime
///////////////////////////////
xs_dateTime::xs_dateTime()
{
}
 
xs_dateTime::~xs_dateTime()
{
}

xs_dateTime::xs_dateTime(
	xqp_dateTime const& _value)
:
	value(_value)
{
}

type::typename_t xs_dateTime::get_type()
{
	return XS_DATETIME;
}

void xs_dateTime::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_dateTime::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_decimal
///////////////////////////////
xs_decimal::xs_decimal()
{
}
 
xs_decimal::~xs_decimal()
{
}

xs_decimal::xs_decimal(
	xqp_decimal const& _value)
:
	value(_value)
{
}

type::typename_t xs_decimal::get_type()
{
	return XS_DECIMAL;
}

void xs_decimal::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_decimal::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_double
///////////////////////////////
xs_double::xs_double()
{
}
 
xs_double::~xs_double()
{
}

xs_double::xs_double(
	xqp_double const& _value)
:
	value(_value)
{
}

type::typename_t xs_double::get_type()
{
	return XS_DOUBLE;
}

void xs_double::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_double::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_duration
///////////////////////////////
xs_duration::xs_nnn()
{
}
 
xs_duration::~xs_nnn()
{
}

xs_duration::xs_nnn(
	xqp_duration const& _value)
:
	value(_value)
{
}

type::typename_t xs_duration::get_type()
{
	return XS_DURATION;
}

void xs_duration::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_duration::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_float
///////////////////////////////
xs_float::xs_nnn()
{
}
 
xs_float::~xs_nnn()
{
}

xs_float::xs_nnn(
	xqp_float const& _value)
:
	value(_value)
{
}

type::typename_t xs_float::get_type()
{
	return XS_FLOAT;
}

void xs_float::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_float::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gDay
///////////////////////////////

xs_gDay::xs_gDay()
{
}
 
xs_gDay::~xs_gDay()
{
}

xs_gDay::xs_gDay(
	xqp_gDay const& _value)
:
	value(_value)
{
}

type::typename_t xs_gDay::get_type()
{
	return XS_GDAY;
}

void xs_gDay::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_gDay::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gMonth
///////////////////////////////

xs_gMonth::xs_gMonth()
{
}
 
xs_gMonth::~xs_gMonth()
{
}

xs_gMonth::xs_gMonth(
	xqp_gMonth const& _value)
:
	value(_value)
{
}

type::typename_t xs_gMonth::get_type()
{
	return XS_GMONTH;
}

void xs_gMonth::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_gMonth::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gMonthDay
///////////////////////////////

xs_gMonthDay::xs_nnn()
{
}
 
xs_gMonthDay::~xs_nnn()
{
}

xs_gMonthDay::xs_nnn(
	xqp_gMonthDay const& _value)
:
	value(_value)
{
}

type::typename_t xs_gMonthDay::get_type()
{
	return XS_GMONTHDAY;
}

void xs_gMonthDay::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_gMonthDay::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gYear
///////////////////////////////

xs_gYear::xs_gYear()
{
}
 
xs_gYear::~xs_gYear()
{
}

xs_gYear::xs_gYear(
	xqp_gYear const& _value)
:
	value(_value)
{
}

type::typename_t xs_gYear::get_type()
{
	return XS_GYEAR;
}

void xs_gYear::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_gYear::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gYearMonth
///////////////////////////////

xs_gYearMonth::xs_gYearMonth()
{
}
 
xs_gYearMonth::~xs_gYearMonth()
{
}

xs_gYearMonth::xs_gYearMonth(
	xqp_gYearMonth const& _value)
:
	value(_value)
{
}

type::typename_t xs_gYearMonth::get_type()
{
	return XS_GYEARMONTH;
}

void xs_gYearMonth::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_gYearMonth::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_hexBinary
///////////////////////////////

xs_hexBinary::xs_hexBinary()
{
}
 
xs_hexBinary::~xs_hexBinary()
{
}

xs_hexBinary::xs_hexBinary(
	xqp_hexBinary const& _value)
:
	value(_value)
{
}

type::typename_t xs_hexBinary::get_type()
{
	return XS_HEXBINARY;
}

void xs_hexBinary::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_hexBinary::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_int
///////////////////////////////

xs_int::xs_nnn()
{
}
 
xs_int::~xs_nnn()
{
}

xs_int::xs_nnn(
	xqp_int const& _value)
:
	value(_value)
{
}

type::typename_t xs_int::get_type()
{
	return XS_INT;
}

void xs_int::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_int::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_integer
///////////////////////////////

xs_integer::xs_nnn()
{
}
 
xs_integer::~xs_nnn()
{
}

xs_integer::xs_nnn(
	xqp_integer const& _value)
:
	value(_value)
{
}

type::typename_t xs_integer::get_type()
{
	return XS_INTEGER;
}

void xs_integer::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_integer::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_language
///////////////////////////////

xs_language::xs_language()
{
}
 
xs_language::~xs_language()
{
}

xs_language::xs_language(
	xqp_language const& _value)
:
	value(_value)
{
}

type::typename_t xs_language::get_type()
{
	return XS_LANGUAGE;
}

void xs_language::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_language::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_long
///////////////////////////////

xs_long::xs_long()
{
}
 
xs_long::~xs_long()
{
}

xs_long::xs_long(
	xqp_long const& _value)
:
	value(_value)
{
}

type::typename_t xs_long::get_type()
{
	return XS_LONG;
}

void xs_long::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_long::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_negativeInteger
///////////////////////////////

xs_negativeInteger::xs_negativeInteger()
{
}
 
xs_negativeInteger::~xs_negativeInteger()
{
}

xs_negativeInteger::xs_negativeInteger(
	xqp_negativeInteger const& _value)
:
	value(_value)
{
}

type::typename_t xs_negativeInteger::get_type()
{
	return XS_NEGATIVEINTEGER;
}

void xs_negativeInteger::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_negativeInteger::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_nonNegativeInteger
///////////////////////////////

xs_nonNegativeInteger::xs_nonNegativeInteger()
{
}
 
xs_nonNegativeInteger::~xs_nonNegativeInteger()
{
}

xs_nonNegativeInteger::xs_nonNegativeInteger(
	xqp_nonNegativeInteger const& _value)
:
	value(_value)
{
}

type::typename_t xs_nonNegativeInteger::get_type()
{
	return XS_NONNEGATIVEINTEGER;
}

void xs_nonNegativeInteger::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_nonNegativeInteger::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_nonPositiveInteger
///////////////////////////////

xs_nonPositiveInteger::xs_nonPositiveInteger()
{
}
 
xs_nonPositiveInteger::~xs_nonPositiveInteger()
{
}

xs_nonPositiveInteger::xs_nonPositiveInteger(
	xqp_nonPositiveInteger const& _value)
:
	value(_value)
{
}

type::typename_t xs_nonPositiveInteger::get_type()
{
	return XS_NONPOSITIVEINTEGER;
}

void xs_nonPositiveInteger::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_nonPositiveInteger::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_normalizedString
///////////////////////////////

xs_normalizedString::xs_normalizedString()
{
}
 
xs_normalizedString::~xs_normalizedString()
{
}

xs_normalizedString::xs_normalizedString(
	xqp_normalizedString const& _value)
:
	value(_value)
{
}

type::typename_t xs_normalizedString::get_type()
{
	return XS_NORMALIZEDSTRING;
}

void xs_normalizedString::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_normalizedString::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_positiveInteger
///////////////////////////////

xs_positiveInteger::xs_positiveInteger()
{
}
 
xs_positiveInteger::~xs_positiveInteger()
{
}

xs_positiveInteger::xs_positiveInteger(
	xqp_positiveInteger const& _value)
:
	value(_value)
{
}

type::typename_t xs_positiveInteger::get_type()
{
	return XS_POSITIVEINTEGER;
}

void xs_positiveInteger::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_positiveInteger::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_short
///////////////////////////////

xs_short::xs_short()
{
}
 
xs_short::~xs_short()
{
}

xs_short::xs_short(
	xqp_short const& _value)
:
	value(_value)
{
}

type::typename_t xs_short::get_type()
{
	return XS_SHORT;
}

void xs_short::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_short::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_string
///////////////////////////////

xs_string::xs_string()
{
}
 
xs_string::~xs_string()
{
}

xs_string::xs_string(
	xqp_string const& _value)
:
	value(_value)
{
}

type::typename_t xs_string::get_type()
{
	return XS_STRING;
}

void xs_string::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_string::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_time
///////////////////////////////

xs_time::xs_time()
{
}
 
xs_time::~xs_time()
{
}

xs_time::xs_time(
	xqp_time const& _value)
:
	value(_value)
{
}

type::typename_t xs_time::get_type()
{
	return XS_TIME;
}

void xs_time::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_time::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_token
///////////////////////////////

xs_token::xs_token()
{
}
 
xs_token::~xs_token()
{
}

xs_token::xs_token(
	xqp_token const& _value)
:
	value(_value)
{
}

type::typename_t xs_token::get_type()
{
	return XS_TOKEN;
}

void xs_token::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_token::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedByte
///////////////////////////////

xs_unsignedByte::xs_unsignedByte()
{
}
 
xs_unsignedByte::~xs_unsignedByte()
{
}

xs_unsignedByte::xs_unsignedByte(
	xqp_unsignedByte const& _value)
:
	value(_value)
{
}

type::typename_t xs_unsignedByte::get_type()
{
	return XS_unsignedByte;
}

void xs_unsignedByte::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_unsignedByte::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedInt
///////////////////////////////

xs_unsignedInt::xs_unsignedInt()
{
}
 
xs_unsignedInt::~xs_unsignedInt()
{
}

xs_unsignedInt::xs_unsignedInt(
	xqp_unsignedInt const& _value)
:
	value(_value)
{
}

type::typename_t xs_unsignedInt::get_type()
{
	return XS_unsignedInt;
}

void xs_unsignedInt::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_unsignedInt::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedLong
///////////////////////////////

xs_unsignedLong::xs_unsignedLong()
{
}
 
xs_unsignedLong::~xs_unsignedLong()
{
}

xs_unsignedLong::xs_unsignedLong(
	xqp_unsignedLong const& _value)
:
	value(_value)
{
}

type::typename_t xs_unsignedLong::get_type()
{
	return XS_unsignedLong;
}

void xs_unsignedLong::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_unsignedLong::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedShort
///////////////////////////////

xs_unsignedShort::xs_unsignedShort()
{
}
 
xs_unsignedShort::~xs_unsignedShort()
{
}

xs_unsignedShort::xs_unsignedShort(
	xqp_unsignedShort const& _value)
:
	value(_value)
{
}

type::typename_t xs_unsignedShort::get_type()
{
	return XS_unsignedShort;
}

void xs_unsignedShort::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_unsignedShort::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_ENTITIES
///////////////////////////////

xs_ENTITIES::xs_ENTITIES()
{
}
 
xs_ENTITIES::~xs_ENTITIES()
{
}

xs_ENTITIES::xs_ENTITIES(
	xqp_ENTITIES const& _value)
:
	value(_value)
{
}

type::typename_t xs_ENTITIES::get_type()
{
	return XS_ENTITIES;
}

void xs_ENTITIES::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_ENTITIES::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_ENTITY
///////////////////////////////

xs_ENTITY::xs_ENTITY()
{
}
 
xs_ENTITY::~xs_ENTITY()
{
}

xs_ENTITY::xs_ENTITY(
	xqp_ENTITY const& _value)
:
	value(_value)
{
}

type::typename_t xs_ENTITY::get_type()
{
	return XS_ENTITY;
}

void xs_ENTITY::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_ENTITY::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_ID
///////////////////////////////

xs_ID::xs_ID()
{
}
 
xs_ID::~xs_ID()
{
}

xs_ID::xs_ID(
	xqp_ID const& _value)
:
	value(_value)
{
}

type::typename_t xs_ID::get_type()
{
	return XS_ID;
}

void xs_ID::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_ID::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_IDREF
///////////////////////////////

xs_IDREF::xs_IDREF()
{
}
 
xs_IDREF::~xs_IDREF()
{
}

xs_IDREF::xs_IDREF(
	xqp_IDREF const& _value)
:
	value(_value)
{
}

type::typename_t xs_IDREF::get_type()
{
	return XS_IDREF;
}

void xs_IDREF::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_IDREF::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_IDREFS
///////////////////////////////

xs_IDREFS::xs_IDREFS()
{
}
 
xs_IDREFS::~xs_IDREFS()
{
}

xs_IDREFS::xs_IDREFS(
	xqp_IDREFS const& _value)
:
	value(_value)
{
}

type::typename_t xs_IDREFS::get_type()
{
	return XS_IDREFS;
}

void xs_IDREFS::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_IDREFS::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NCName
///////////////////////////////

xs_NCNAME::xs_NCNAME()
{
}
 
xs_NCNAME::~xs_NCNAME()
{
}

xs_NCNAME::xs_NCNAME(
	xqp_NCNAME const& _value)
:
	value(_value)
{
}

type::typename_t xs_NCNAME::get_type()
{
	return XS_NCNAME;
}

void xs_NCNAME::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_NCNAME::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NMTOKEN
///////////////////////////////

xs_NMTOKEN::xs_NMTOKEN()
{
}
 
xs_NMTOKEN::~xs_NMTOKEN()
{
}

xs_NMTOKEN::xs_NMTOKEN(
	xqp_NMTOKEN const& _value)
:
	value(_value)
{
}

type::typename_t xs_NMTOKEN::get_type()
{
	return XS_NMTOKEN;
}

void xs_NMTOKEN::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_NMTOKEN::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NMTOKENS
///////////////////////////////

xs_NMTOKENS::xs_NMTOKENS()
{
}
 
xs_NMTOKENS::~xs_NMTOKENS()
{
}

xs_NMTOKENS::xs_NMTOKENS(
	xqp_NMTOKENS const& _value)
:
	value(_value)
{
}

type::typename_t xs_NMTOKENS::get_type()
{
	return XS_NMTOKENS;
}

void xs_NMTOKENS::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_NMTOKENS::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NOTATION
///////////////////////////////

xs_NOTATION::xs_NOTATION()
{
}
 
xs_NOTATION::~xs_NOTATION()
{
}

xs_NOTATION::xs_NOTATION(
	xqp_NOTATION const& _value)
:
	value(_value)
{
}

type::typename_t xs_NOTATION::get_type()
{
	return XS_NOTATION;
}

void xs_NOTATION::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_NOTATION::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_Name
///////////////////////////////

xs_Name::xs_Name()
{
}
 
xs_Name::~xs_Name()
{
}

xs_Name::xs_Name(
	xqp_Name const& _value)
:
	value(_value)
{
}

type::typename_t xs_Name::get_type()
{
	return XS_NAME;
}

void xs_Name::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_Name::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_QName
///////////////////////////////

xs_QName::xs_QName()
{
}
 
xs_QName::~xs_QName()
{
}

xs_QName::xs_QName(
	xqp_QName const& _value)
:
	value(_value)
{
}

type::typename_t xs_QName::get_type()
{
	return XS_QNAME;
}

void xs_QName::encode(xml_ostream* xos)
throw (xqp_exception)
{
	return 0;
}
    
void xs_QName::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 
