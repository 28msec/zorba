/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "xs_primitive_values.h"
#include <iostream>

using namespace std;
namespace xqp {



ostream& put(
	ostream& os,
	struct tm const* t,
	enum type::typecode type)
{
	char buf[1024];
	size_t n = 0;
	switch (type) { // XXX add timezones here
	case type::XS_DATETIME: n = strftime(buf, 1024, "%Y-%m-%dT%X", t); break;
	case type::XS_DATE: n = strftime(buf, 1024, "%Y-%m-%d", t); break;
	case type::XS_TIME: n = strftime(buf, 1024, "%X", t); break;
	case type::XS_GYEARMONTH: n = strftime(buf, 1024, "-%Y-%m", t); break;
	case type::XS_GYEAR: n = strftime(buf, 1024, "-%Y", t); break;
	case type::XS_GMONTHDAY: n = strftime(buf, 1024, "--%m-%d", t); break;
	case type::XS_GDAY: n = strftime(buf, 1024, "---%d", t); break;
	case type::XS_GMONTH: n = strftime(buf, 1024, "--%m", t); break;
	default: buf[0] = 0; n = 0;
	}
	return os << string(buf,0,n);
}

ostream& put(
	ostringstream& os,
	struct tm const* t,
	enum type::typecode type)
{
	char buf[1024];
	size_t n = 0;
	switch (type) { // XXX add timezones here
	case type::XS_DATETIME: n = strftime(buf, 1024, "%Y-%m-%dT%X", t); break;
	case type::XS_DATE: n = strftime(buf, 1024, "%Y-%m-%d", t); break;
	case type::XS_TIME: n = strftime(buf, 1024, "%X", t); break;
	case type::XS_GYEARMONTH: n = strftime(buf, 1024, "-%Y-%m", t); break;
	case type::XS_GYEAR: n = strftime(buf, 1024, "-%Y", t); break;
	case type::XS_GMONTHDAY: n = strftime(buf, 1024, "--%m-%d", t); break;
	case type::XS_GDAY: n = strftime(buf, 1024, "---%d", t); break;
	case type::XS_GMONTH: n = strftime(buf, 1024, "--%m", t); break;
	default: buf[0] = 0; n = 0;
	}
	return os << string(buf,0,n);
}



///////////////////////////////
//  anyURI
///////////////////////////////
string xs_anyURI_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_anyURI[" << val << ']'; 
	return oss.str();
}

ostream& xs_anyURI_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_anyURI[" << val << ']'; 
}

xs_anyURI_value::xs_anyURI_value()
{
}
 
xs_anyURI_value::~xs_anyURI_value()
{
}

xs_anyURI_value::xs_anyURI_value(
	xqp_anyURI const& _val)
:
	val(_val)
{
}

type::typecode xs_anyURI_value::get_typecode() const
{
	return type::XS_ANYURI;
}

void xs_anyURI_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_anyURI_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
   


///////////////////////////////
//  Base64Binary
///////////////////////////////

string xs_base64Binary_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_base64Binary[" << val << ']'; 
	return oss.str();
}

ostream& xs_base64Binary_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_base64Binary[" << val << ']'; 
}

xs_base64Binary_value::xs_base64Binary_value()
{
}
 
xs_base64Binary_value::~xs_base64Binary_value()
{
}

xs_base64Binary_value::xs_base64Binary_value(
	xqp_base64Binary const& _val)
:
	val(_val)
{
}

type::typecode xs_base64Binary_value::get_typecode() const
{
	return type::XS_BASE64BINARY;
}

void xs_base64Binary_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_base64Binary_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
   
 
 
///////////////////////////////
//  xs_boolean
///////////////////////////////

string xs_boolean_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_boolean[" << val << ']'; 
	return oss.str();
}

ostream& xs_boolean_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_boolean[" << val << ']'; 
}

xs_boolean_value::xs_boolean_value()
{
}
 
xs_boolean_value::~xs_boolean_value()
{
}

xs_boolean_value::xs_boolean_value(
	xqp_boolean const& _val)
:
	val(_val)
{
}

type::typecode xs_boolean_value::get_typecode() const
{
	return type::XS_ANYURI;
}

void xs_boolean_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_boolean_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
   


///////////////////////////////
//  xs_byte
///////////////////////////////

string xs_byte_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_byte[" << val << ']'; 
	return oss.str();
}

ostream& xs_byte_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_byte[" << val << ']'; 
}

xs_byte_value::xs_byte_value()
{
}
 
xs_byte_value::~xs_byte_value()
{
}

xs_byte_value::xs_byte_value(
	xqp_byte const& _val)
:
	val(_val)
{
}

type::typecode xs_byte_value::get_typecode() const
{
	return type::XS_ANYURI;
}

void xs_byte_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_byte_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_date
///////////////////////////////

string xs_date_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_date[";
	xqp::put(oss,&val,type::XS_DATE) << ']';
	return oss.str();
}

ostream& xs_date_value::put(ostream& os, context const& ctx) const
{
	os << "xs_date[";
	xqp::put(os,&val,type::XS_DATE) << ']';
	return os; 
}


xs_date_value::xs_date_value()
{
}
 
xs_date_value::~xs_date_value()
{
}

xs_date_value::xs_date_value(
	xqp_date const& _val)
:
	val(_val)
{
}

type::typecode xs_date_value::get_typecode() const
{
	return type::XS_ANYURI;
}

void xs_date_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_date_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_dateTime
///////////////////////////////

string xs_dateTime_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_dateTime[";
	xqp::put(oss,&val,type::XS_DATETIME) << ']';
	return oss.str();
}

ostream& xs_dateTime_value::put(ostream& os, context const& ctx) const
{
	os << "xs_dateTime[";
	xqp::put(os,&val,type::XS_DATETIME) << ']';
	return os; 
}

xs_dateTime_value::xs_dateTime_value()
{
}
 
xs_dateTime_value::~xs_dateTime_value()
{
}

xs_dateTime_value::xs_dateTime_value(
	xqp_dateTime const& _val)
:
	val(_val)
{
}

type::typecode xs_dateTime_value::get_typecode() const
{
	return type::XS_DATETIME;
}

void xs_dateTime_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_dateTime_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_decimal
///////////////////////////////

string xs_decimal_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_decimal[" << val << ']'; 
	return oss.str();
}

ostream& xs_decimal_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_decimal[" << val << ']'; 
}

xs_decimal_value::xs_decimal_value()
{
}
 
xs_decimal_value::~xs_decimal_value()
{
}

xs_decimal_value::xs_decimal_value(
	xqp_decimal const& _val)
:
	val(_val)
{
}

type::typecode xs_decimal_value::get_typecode() const
{
	return type::XS_DECIMAL;
}

void xs_decimal_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_decimal_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_double
///////////////////////////////

string xs_double_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_double[" << val << ']'; 
	return oss.str();
}

ostream& xs_double_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_double[" << val << ']'; 
}

xs_double_value::xs_double_value()
{
}
 
xs_double_value::~xs_double_value()
{
}

xs_double_value::xs_double_value(
	xqp_double const& _val)
:
	val(_val)
{
}

type::typecode xs_double_value::get_typecode() const
{
	return type::XS_DOUBLE;
}

void xs_double_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_double_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_duration
///////////////////////////////

string xs_duration_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_duration[" << val << ']'; 
	return oss.str();
}

ostream& xs_duration_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_duration[" << val << ']'; 
}

xs_duration_value::xs_duration_value()
{
}
 
xs_duration_value::~xs_duration_value()
{
}

xs_duration_value::xs_duration_value(
	xqp_duration const& _val)
:
	val(_val)
{
}

type::typecode xs_duration_value::get_typecode() const
{
	return type::XS_DURATION;
}

void xs_duration_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_duration_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 

///////////////////////////////
//	xs_float
///////////////////////////////

string xs_float_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_float[" << val << ']'; 
	return oss.str();
}

ostream& xs_float_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_float[" << val << ']'; 
}

xs_float_value::xs_float_value()
{
}
 
xs_float_value::~xs_float_value()
{
}

xs_float_value::xs_float_value(
	xqp_float const& _val)
:
	val(_val)
{
}

type::typecode xs_float_value::get_typecode() const
{
	return type::XS_FLOAT;
}

void xs_float_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_float_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gDay
///////////////////////////////

string xs_gDay_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_gDay[";
	xqp::put(oss,&val,type::XS_GDAY) << ']';
	return oss.str();
}

ostream& xs_gDay_value::put(ostream& os, context const& ctx) const
{
	os << "xs_gDay[";
	xqp::put(os,&val,type::XS_GDAY) << ']';
	return os; 
}


xs_gDay_value::xs_gDay_value()
{
}
 
xs_gDay_value::~xs_gDay_value()
{
}

xs_gDay_value::xs_gDay_value(
	xqp_gDay const& _val)
:
	val(_val)
{
}

type::typecode xs_gDay_value::get_typecode() const
{
	return type::XS_GDAY;
}

void xs_gDay_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_gDay_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gMonth
///////////////////////////////

string xs_gMonth_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_gMonth[";
	xqp::put(oss,&val,type::XS_GMONTH) << ']';
	return oss.str();
}

ostream& xs_gMonth_value::put(ostream& os, context const& ctx) const
{
	os << "xs_gMonth[";
	xqp::put(os,&val,type::XS_GMONTH) << ']';
	return os; 
}


xs_gMonth_value::xs_gMonth_value()
{
}
 
xs_gMonth_value::~xs_gMonth_value()
{
}

xs_gMonth_value::xs_gMonth_value(
	xqp_gMonth const& _val)
:
	val(_val)
{
}

type::typecode xs_gMonth_value::get_typecode() const
{
	return type::XS_GMONTH;
}

void xs_gMonth_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_gMonth_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gMonthDay
///////////////////////////////

string xs_gMonthDay_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_gMonthDay[";
	xqp::put(oss,&val,type::XS_GMONTHDAY) << ']';
	return oss.str();
}

ostream& xs_gMonthDay_value::put(ostream& os, context const& ctx) const
{
	os << "xs_gMonthDay[";
	xqp::put(os,&val,type::XS_GMONTHDAY) << ']';
	return os; 
}


xs_gMonthDay_value::xs_gMonthDay_value()
{
}
 
xs_gMonthDay_value::~xs_gMonthDay_value()
{
}

xs_gMonthDay_value::xs_gMonthDay_value(
	xqp_gMonthDay const& _val)
:
	val(_val)
{
}

type::typecode xs_gMonthDay_value::get_typecode() const
{
	return type::XS_GMONTHDAY;
}

void xs_gMonthDay_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_gMonthDay_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gYear
///////////////////////////////

string xs_gYear_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_gYear[";
	xqp::put(oss,&val,type::XS_GYEAR) << ']';
	return oss.str();
}

ostream& xs_gYear_value::put(ostream& os, context const& ctx) const
{
	os << "xs_gYear[";
	xqp::put(os,&val,type::XS_GYEAR) << ']';
	return os; 
}


xs_gYear_value::xs_gYear_value()
{
}
 
xs_gYear_value::~xs_gYear_value()
{
}

xs_gYear_value::xs_gYear_value(
	xqp_gYear const& _val)
:
	val(_val)
{
}

type::typecode xs_gYear_value::get_typecode() const
{
	return type::XS_GYEAR;
}

void xs_gYear_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_gYear_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_gYearMonth
///////////////////////////////

string xs_gYearMonth_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_gYearMonth[";
	xqp::put(oss,&val,type::XS_GYEARMONTH) << ']';
	return oss.str();
}

ostream& xs_gYearMonth_value::put(ostream& os, context const& ctx) const
{
	os << "xs_gYearMonth[";
	xqp::put(os,&val,type::XS_GYEARMONTH) << ']';
	return os; 
}


xs_gYearMonth_value::xs_gYearMonth_value()
{
}
 
xs_gYearMonth_value::~xs_gYearMonth_value()
{
}

xs_gYearMonth_value::xs_gYearMonth_value(
	xqp_gYearMonth const& _val)
:
	val(_val)
{
}

type::typecode xs_gYearMonth_value::get_typecode() const
{
	return type::XS_GYEARMONTH;
}

void xs_gYearMonth_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_gYearMonth_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_hexBinary
///////////////////////////////

string xs_hexBinary_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_hexBinary[" << val << ']'; 
	return oss.str();
}

ostream& xs_hexBinary_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_hexBinary[" << val << ']'; 
}


xs_hexBinary_value::xs_hexBinary_value()
{
}
 
xs_hexBinary_value::~xs_hexBinary_value()
{
}

xs_hexBinary_value::xs_hexBinary_value(
	xqp_hexBinary const& _val)
:
	val(_val)
{
}

type::typecode xs_hexBinary_value::get_typecode() const
{
	return type::XS_HEXBINARY;
}

void xs_hexBinary_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_hexBinary_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_int
///////////////////////////////

string xs_int_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_int[" << val << ']'; 
	return oss.str();
}

ostream& xs_int_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_int[" << val << ']'; 
}


xs_int_value::xs_int_value()
{
}
 
xs_int_value::~xs_int_value()
{
}

xs_int_value::xs_int_value(
	xqp_int const& _val)
:
	val(_val)
{
}

type::typecode xs_int_value::get_typecode() const
{
	return type::XS_INT;
}

void xs_int_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_int_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_integer
///////////////////////////////

string xs_integer_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_integer[" << val << ']'; 
	return oss.str();
}

ostream& xs_integer_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_integer[" << val << ']'; 
}


xs_integer_value::xs_integer_value()
{
}
 
xs_integer_value::~xs_integer_value()
{
}

xs_integer_value::xs_integer_value(
	xqp_integer const& _val)
:
	val(_val)
{
}

type::typecode xs_integer_value::get_typecode() const
{
	return type::XS_INTEGER;
}

void xs_integer_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_integer_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_language
///////////////////////////////

string xs_language_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_language[" << val << ']'; 
	return oss.str();
}

ostream& xs_language_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_language[" << val << ']'; 
}


xs_language_value::xs_language_value()
{
}
 
xs_language_value::~xs_language_value()
{
}

xs_language_value::xs_language_value(
	xqp_language const& _val)
:
	val(_val)
{
}

type::typecode xs_language_value::get_typecode() const
{
	return type::XS_LANGUAGE;
}

void xs_language_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_language_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_long
///////////////////////////////

string xs_long_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_long[" << val << ']'; 
	return oss.str();
}

ostream& xs_long_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_long[" << val << ']'; 
}


xs_long_value::xs_long_value()
{
}
 
xs_long_value::~xs_long_value()
{
}

xs_long_value::xs_long_value(
	xqp_long const& _val)
:
	val(_val)
{
}

type::typecode xs_long_value::get_typecode() const
{
	return type::XS_LONG;
}

void xs_long_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_long_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_negativeInteger
///////////////////////////////

string xs_negativeInteger_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_negativeInteger[" << val << ']'; 
	return oss.str();
}

ostream& xs_negativeInteger_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_negativeInteger[" << val << ']'; 
}


xs_negativeInteger_value::xs_negativeInteger_value()
{
}
 
xs_negativeInteger_value::~xs_negativeInteger_value()
{
}

xs_negativeInteger_value::xs_negativeInteger_value(
	xqp_negativeInteger const& _val)
:
	val(_val)
{
}

type::typecode xs_negativeInteger_value::get_typecode() const
{
	return type::XS_NEGATIVE_INTEGER;
}

void xs_negativeInteger_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_negativeInteger_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_nonNegativeInteger
///////////////////////////////

string xs_nonNegativeInteger_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_nonNegativeInteger[" << val << ']'; 
	return oss.str();
}

ostream& xs_nonNegativeInteger_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_nonNegativeInteger[" << val << ']'; 
}


xs_nonNegativeInteger_value::xs_nonNegativeInteger_value()
{
}
 
xs_nonNegativeInteger_value::~xs_nonNegativeInteger_value()
{
}

xs_nonNegativeInteger_value::xs_nonNegativeInteger_value(
	xqp_nonNegativeInteger const& _val)
:
	val(_val)
{
}

type::typecode xs_nonNegativeInteger_value::get_typecode() const
{
	return type::XS_NON_NEGATIVE_INTEGER;
}

void xs_nonNegativeInteger_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_nonNegativeInteger_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_nonPositiveInteger
///////////////////////////////

string xs_nonPositiveInteger_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_nonPositiveInteger[" << val << ']'; 
	return oss.str();
}

ostream& xs_nonPositiveInteger_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_nonPositiveInteger[" << val << ']'; 
}


xs_nonPositiveInteger_value::xs_nonPositiveInteger_value()
{
}
 
xs_nonPositiveInteger_value::~xs_nonPositiveInteger_value()
{
}

xs_nonPositiveInteger_value::xs_nonPositiveInteger_value(
	xqp_nonPositiveInteger const& _val)
:
	val(_val)
{
}

type::typecode xs_nonPositiveInteger_value::get_typecode() const
{
	return type::XS_NON_POSITIVE_INTEGER;
}

void xs_nonPositiveInteger_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_nonPositiveInteger_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_normalizedString
///////////////////////////////

string xs_normalizedString_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_normalizedString[" << val << ']'; 
	return oss.str();
}

ostream& xs_normalizedString_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_normalizedString[" << val << ']'; 
}


xs_normalizedString_value::xs_normalizedString_value()
{
}
 
xs_normalizedString_value::~xs_normalizedString_value()
{
}

xs_normalizedString_value::xs_normalizedString_value(
	xqp_normalizedString const& _val)
:
	val(_val)
{
}

type::typecode xs_normalizedString_value::get_typecode() const
{
	return type::XS_NORMALIZED_STRING;
}

void xs_normalizedString_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_normalizedString_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_positiveInteger
///////////////////////////////

string xs_positiveInteger_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_positiveInteger[" << val << ']'; 
	return oss.str();
}

ostream& xs_positiveInteger_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_positiveInteger[" << val << ']'; 
}


xs_positiveInteger_value::xs_positiveInteger_value()
{
}
 
xs_positiveInteger_value::~xs_positiveInteger_value()
{
}

xs_positiveInteger_value::xs_positiveInteger_value(
	xqp_positiveInteger const& _val)
:
	val(_val)
{
}

type::typecode xs_positiveInteger_value::get_typecode() const
{
	return type::XS_POSITIVE_INTEGER;
}

void xs_positiveInteger_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_positiveInteger_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_short
///////////////////////////////

string xs_short_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_short[" << val << ']'; 
	return oss.str();
}

ostream& xs_short_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_short[" << val << ']'; 
}


xs_short_value::xs_short_value()
{
}
 
xs_short_value::~xs_short_value()
{
}

xs_short_value::xs_short_value(
	xqp_short const& _val)
:
	val(_val)
{
}

type::typecode xs_short_value::get_typecode() const
{
	return type::XS_SHORT;
}

void xs_short_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_short_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_string
///////////////////////////////

string xs_string_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_string[" << val << ']'; 
	return oss.str();
}

ostream& xs_string_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_string[" << val << ']'; 
}


xs_string_value::xs_string_value()
{
}
 
xs_string_value::~xs_string_value()
{
}

xs_string_value::xs_string_value(
	xqp_string const& _val)
:
	val(_val)
{
}

type::typecode xs_string_value::get_typecode() const
{
	return type::XS_STRING;
}

void xs_string_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_string_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_time
///////////////////////////////

string xs_time_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_time[";
	xqp::put(oss,&val,type::XS_TIME) << ']';
	return oss.str();
}

ostream& xs_time_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_time[";
	xqp::put(os,&val,type::XS_TIME) << ']';
	return os; 
}


xs_time_value::xs_time_value()
{
}
 
xs_time_value::~xs_time_value()
{
}

xs_time_value::xs_time_value(
	xqp_time const& _val)
:
	val(_val)
{
}

type::typecode xs_time_value::get_typecode() const
{
	return type::XS_TIME;
}

void xs_time_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_time_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_token
///////////////////////////////

string xs_token_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_token[" << val << ']'; 
	return oss.str();
}

ostream& xs_token_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_token[" << val << ']'; 
}


xs_token_value::xs_token_value()
{
}
 
xs_token_value::~xs_token_value()
{
}

xs_token_value::xs_token_value(
	xqp_token const& _val)
:
	val(_val)
{
}

type::typecode xs_token_value::get_typecode() const
{
	return type::XS_TOKEN;
}

void xs_token_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_token_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedByte
///////////////////////////////

string xs_unsignedByte_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_unsignedByte[" << val << ']'; 
	return oss.str();
}

ostream& xs_unsignedByte_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_unsignedByte[" << val << ']'; 
}


xs_unsignedByte_value::xs_unsignedByte_value()
{
}
 
xs_unsignedByte_value::~xs_unsignedByte_value()
{
}

xs_unsignedByte_value::xs_unsignedByte_value(
	xqp_unsignedByte const& _val)
:
	val(_val)
{
}

type::typecode xs_unsignedByte_value::get_typecode() const
{
	return type::XS_UNSIGNED_BYTE;
}

void xs_unsignedByte_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_unsignedByte_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedInt
///////////////////////////////

string xs_unsignedInt_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_unsignedInt[" << val << ']'; 
	return oss.str();
}

ostream& xs_unsignedInt_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_unsignedInt[" << val << ']'; 
}


xs_unsignedInt_value::xs_unsignedInt_value()
{
}
 
xs_unsignedInt_value::~xs_unsignedInt_value()
{
}

xs_unsignedInt_value::xs_unsignedInt_value(
	xqp_unsignedInt const& _val)
:
	val(_val)
{
}

type::typecode xs_unsignedInt_value::get_typecode() const
{
	return type::XS_UNSIGNED_INT;
}

void xs_unsignedInt_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_unsignedInt_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedLong
///////////////////////////////

string xs_unsignedLong_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_unsignedLong[" << val << ']'; 
	return oss.str();
}

ostream& xs_unsignedLong_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_unsignedLong[" << val << ']'; 
}


xs_unsignedLong_value::xs_unsignedLong_value()
{
}
 
xs_unsignedLong_value::~xs_unsignedLong_value()
{
}

xs_unsignedLong_value::xs_unsignedLong_value(
	xqp_unsignedLong const& _val)
:
	val(_val)
{
}

type::typecode xs_unsignedLong_value::get_typecode() const
{
	return type::XS_UNSIGNED_LONG;
}

void xs_unsignedLong_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_unsignedLong_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_unsignedShort
///////////////////////////////

string xs_unsignedShort_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_unsignedShort[" << val << ']'; 
	return oss.str();
}

ostream& xs_unsignedShort_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_unsignedShort[" << val << ']'; 
}


xs_unsignedShort_value::xs_unsignedShort_value()
{
}
 
xs_unsignedShort_value::~xs_unsignedShort_value()
{
}

xs_unsignedShort_value::xs_unsignedShort_value(
	xqp_unsignedShort const& _val)
:
	val(_val)
{
}

type::typecode xs_unsignedShort_value::get_typecode() const
{
	return type::XS_UNSIGNED_SHORT;
}

void xs_unsignedShort_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_unsignedShort_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_ENTITIES
///////////////////////////////

string xs_ENTITIES_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_ENTITIES[" << val << ']'; 
	return oss.str();
}

ostream& xs_ENTITIES_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_ENTITIES[" << val << ']'; 
}


xs_ENTITIES_value::xs_ENTITIES_value()
{
}
 
xs_ENTITIES_value::~xs_ENTITIES_value()
{
}

xs_ENTITIES_value::xs_ENTITIES_value(
	xqp_ENTITIES const& _val)
:
	val(_val)
{
}

type::typecode xs_ENTITIES_value::get_typecode() const
{
	return type::XS_ENTITIES;
}

void xs_ENTITIES_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_ENTITIES_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_ENTITY
///////////////////////////////

string xs_ENTITY_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_ENTITY[" << val << ']'; 
	return oss.str();
}

ostream& xs_ENTITY_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_ENTITY[" << val << ']'; 
}


xs_ENTITY_value::xs_ENTITY_value()
{
}
 
xs_ENTITY_value::~xs_ENTITY_value()
{
}

xs_ENTITY_value::xs_ENTITY_value(
	xqp_ENTITY const& _val)
:
	val(_val)
{
}

type::typecode xs_ENTITY_value::get_typecode() const
{
	return type::XS_ENTITY;
}

void xs_ENTITY_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_ENTITY_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_ID
///////////////////////////////

string xs_ID_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_ID[" << val << ']'; 
	return oss.str();
}

ostream& xs_ID_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_ID[" << val << ']'; 
}


xs_ID_value::xs_ID_value()
{
}
 
xs_ID_value::~xs_ID_value()
{
}

xs_ID_value::xs_ID_value(
	xqp_ID const& _val)
:
	val(_val)
{
}

type::typecode xs_ID_value::get_typecode() const
{
	return type::XS_ID;
}

void xs_ID_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_ID_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_IDREF
///////////////////////////////

string xs_IDREF_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_IDREF[" << val << ']'; 
	return oss.str();
}

ostream& xs_IDREF_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_IDREF[" << val << ']'; 
}


xs_IDREF_value::xs_IDREF_value()
{
}
 
xs_IDREF_value::~xs_IDREF_value()
{
}

xs_IDREF_value::xs_IDREF_value(
	xqp_IDREF const& _val)
:
	val(_val)
{
}

type::typecode xs_IDREF_value::get_typecode() const
{
	return type::XS_IDREF;
}

void xs_IDREF_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_IDREF_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_IDREFS
///////////////////////////////

string xs_IDREFS_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_IDREFS[" << val << ']'; 
	return oss.str();
}

ostream& xs_IDREFS_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_IDREFS[" << val << ']'; 
}


xs_IDREFS_value::xs_IDREFS_value()
{
}
 
xs_IDREFS_value::~xs_IDREFS_value()
{
}

xs_IDREFS_value::xs_IDREFS_value(
	xqp_IDREFS const& _val)
:
	val(_val)
{
}

type::typecode xs_IDREFS_value::get_typecode() const
{
	return type::XS_IDREFS;
}

void xs_IDREFS_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_IDREFS_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NCName
///////////////////////////////

string xs_NCName_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_NCName[" << val << ']'; 
	return oss.str();
}

ostream& xs_NCName_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_NCName[" << val << ']'; 
}


xs_NCName_value::xs_NCName_value()
{
}
 
xs_NCName_value::~xs_NCName_value()
{
}

xs_NCName_value::xs_NCName_value(
	xqp_NCName const& _val)
:
	val(_val)
{
}

type::typecode xs_NCName_value::get_typecode() const
{
	return type::XS_NCNAME;
}

void xs_NCName_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_NCName_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NMTOKEN
///////////////////////////////

string xs_NMTOKEN_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_NMTOKEN[" << val << ']'; 
	return oss.str();
}

ostream& xs_NMTOKEN_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_NMTOKEN[" << val << ']'; 
}


xs_NMTOKEN_value::xs_NMTOKEN_value()
{
}
 
xs_NMTOKEN_value::~xs_NMTOKEN_value()
{
}

xs_NMTOKEN_value::xs_NMTOKEN_value(
	xqp_NMTOKEN const& _val)
:
	val(_val)
{
}

type::typecode xs_NMTOKEN_value::get_typecode() const
{
	return type::XS_NMTOKEN;
}

void xs_NMTOKEN_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_NMTOKEN_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NMTOKENS
///////////////////////////////

string xs_NMTOKENS_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_NMTOKENS[" << val << ']'; 
	return oss.str();
}

ostream& xs_NMTOKENS_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_NMTOKENS[" << val << ']'; 
}


xs_NMTOKENS_value::xs_NMTOKENS_value()
{
}
 
xs_NMTOKENS_value::~xs_NMTOKENS_value()
{
}

xs_NMTOKENS_value::xs_NMTOKENS_value(
	xqp_NMTOKENS const& _val)
:
	val(_val)
{
}

type::typecode xs_NMTOKENS_value::get_typecode() const
{
	return type::XS_NMTOKENS;
}

void xs_NMTOKENS_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_NMTOKENS_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_NOTATION
///////////////////////////////

string xs_NOTATION_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_NOTATION[" << val << ']'; 
	return oss.str();
}

ostream& xs_NOTATION_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_NOTATION[" << val << ']'; 
}


xs_NOTATION_value::xs_NOTATION_value()
{
}
 
xs_NOTATION_value::~xs_NOTATION_value()
{
}

xs_NOTATION_value::xs_NOTATION_value(
	xqp_NOTATION const& _val)
:
	val(_val)
{
}

type::typecode xs_NOTATION_value::get_typecode() const
{
	return type::XS_NOTATION;
}

void xs_NOTATION_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_NOTATION_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_Name
///////////////////////////////

string xs_Name_value::describe(context const& ctx) const
{
	ostringstream oss;
	oss << "xs_Name[" << val << ']'; 
	return oss.str();
}

ostream& xs_Name_value::put(ostream& os, context const& ctx) const
{
	return os << "xs_Name[" << val << ']'; 
}


xs_Name_value::xs_Name_value()
{
}
 
xs_Name_value::~xs_Name_value()
{
}

xs_Name_value::xs_Name_value(
	xqp_Name const& _val)
:
	val(_val)
{
}

type::typecode xs_Name_value::get_typecode() const
{
	return type::XS_NAME;
}

void xs_Name_value::encode(xml_ostream* xos)
throw (xqp_exception)
{
}
    
void xs_Name_value::decode(xml_istream& xis)
throw (xqp_exception)
{
}
 


///////////////////////////////
//	xs_QName - appears is a separate module 'QName'
///////////////////////////////


}	/* namespace xqp */

