/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "xs_primitive_values.h"

#include "../context/context.h"
#include "../types/typecodes.h"

#include <iostream>

using namespace std;
namespace xqp {


ostream& put(
	ostream& os,
	struct tm const* t,
	sequence_type_t type)
{
	char buf[1024];
	size_t n = 0;
	switch (type) { // XXX add timezones here
	case xs_dateTime: n = strftime(buf, 1024, "%Y-%m-%dT%X", t); break;
	case xs_date: n = strftime(buf, 1024, "%Y-%m-%d", t); break;
	case xs_time: n = strftime(buf, 1024, "%X", t); break;
	case xs_gYearMonth: n = strftime(buf, 1024, "-%Y-%m", t); break;
	case xs_gYear: n = strftime(buf, 1024, "-%Y", t); break;
	case xs_gMonthDay: n = strftime(buf, 1024, "--%m-%d", t); break;
	case xs_gDay: n = strftime(buf, 1024, "---%d", t); break;
	case xs_gMonth: n = strftime(buf, 1024, "--%m", t); break;
	default: buf[0] = 0; n = 0;
	}
	return os << string(buf,0,n);
}

ostream& put(
	ostringstream& os,
	struct tm const* t,
	sequence_type_t type)
{
	char buf[1024];
	size_t n = 0;
	switch (type) { // XXX add timezones here
	case xs_dateTime: n = strftime(buf, 1024, "%Y-%m-%dT%X", t); break;
	case xs_date: n = strftime(buf, 1024, "%Y-%m-%d", t); break;
	case xs_time: n = strftime(buf, 1024, "%X", t); break;
	case xs_gYearMonth: n = strftime(buf, 1024, "-%Y-%m", t); break;
	case xs_gYear: n = strftime(buf, 1024, "-%Y", t); break;
	case xs_gMonthDay: n = strftime(buf, 1024, "--%m-%d", t); break;
	case xs_gDay: n = strftime(buf, 1024, "---%d", t); break;
	case xs_gMonth: n = strftime(buf, 1024, "--%m", t); break;
	default: buf[0] = 0; n = 0;
	}
	return os << string(buf,0,n);
}


///////////////////////////////
//  anyURI
///////////////////////////////
string xs_anyURIValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_anyURI[" << val << ']'; 
	return oss.str();
}

string xs_anyURIValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_anyURIValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_anyURI[" << val << ']'; 
}

xs_anyURIValue::xs_anyURIValue()
: atomic_value(xs_anyURI,0)
{
}
 
xs_anyURIValue::~xs_anyURIValue()
{
}

xs_anyURIValue::xs_anyURIValue(
	xqp_anyURI const& _val)
:
	atomic_value(xs_anyURI,0),
	val(_val)
{
}


///////////////////////////////
//  Base64Binary
///////////////////////////////

string xs_base64BinaryValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_base64Binary[" << val << ']'; 
	return oss.str();
}

string xs_base64BinaryValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_base64BinaryValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_base64Binary[" << val << ']'; 
}

xs_base64BinaryValue::xs_base64BinaryValue()
: atomic_value(xs_base64Binary,0)
{
}
 
xs_base64BinaryValue::~xs_base64BinaryValue()
{
}

xs_base64BinaryValue::xs_base64BinaryValue(
	xqp_base64Binary const& _val)
:
  atomic_value(xs_base64Binary,0),
	val(_val)
{
}

 
///////////////////////////////
//  xs_boolean
///////////////////////////////

string xs_booleanValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_boolean[" << m_val << ']'; 
	return oss.str();
}

string xs_booleanValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << m_val; 
	return oss.str();
}

ostream& xs_booleanValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_boolean[" << m_val << ']'; 
}


///////////////////////////////
//  xs_byte
///////////////////////////////

string xs_byteValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_byte[" << val << ']'; 
	return oss.str();
}

string xs_byteValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_byteValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_byte[" << val << ']'; 
}

xs_byteValue::xs_byteValue()
:	atomic_value(xs_byte,0)
{
}
 
xs_byteValue::~xs_byteValue()
{
}

xs_byteValue::xs_byteValue(
	xqp_byte const& _val)
:
	atomic_value(xs_byte,0),
	val(_val)
{
}


///////////////////////////////
//	xs_date
///////////////////////////////

string xs_dateValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_date[";
	xqp::put(oss,&val,xs_date) << ']';
	return oss.str();
}

string xs_dateValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_date);
	return oss.str();
}

ostream& xs_dateValue::put(ostream& os, context * ctx_p) const
{
	os << "xs_date[";
	xqp::put(os,&val,xs_date) << ']';
	return os; 
}

xs_dateValue::xs_dateValue()
: atomic_value(xs_date,0)
{
}
 
xs_dateValue::~xs_dateValue()
{
}

xs_dateValue::xs_dateValue(
	xqp_date const& _val)
:
	atomic_value(xs_date,0),
	val(_val)
{
}


///////////////////////////////
//	xs_dateTime
///////////////////////////////

string xs_dateTimeValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_dateTime[";
	xqp::put(oss,&val,xs_dateTime) << ']';
	return oss.str();
}

string xs_dateTimeValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_dateTime);
	return oss.str();
}

ostream& xs_dateTimeValue::put(ostream& os, context * ctx_p) const
{
	os << "xs_dateTime[";
	xqp::put(os,&val,xs_dateTime) << ']';
	return os; 
}

xs_dateTimeValue::xs_dateTimeValue()
: atomic_value(xs_dateTime,0)
{
}
 
xs_dateTimeValue::~xs_dateTimeValue()
{
}

xs_dateTimeValue::xs_dateTimeValue(
	xqp_dateTime const& _val)
:	
	atomic_value(xs_dateTime,0),
	val(_val)
{
}


///////////////////////////////
//	xs_decimal
///////////////////////////////

string xs_decimalValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_decimal[" << val << ']'; 
	return oss.str();
}

string xs_decimalValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_decimalValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_decimal[" << val << ']'; 
}

xs_decimalValue::xs_decimalValue()
: atomic_value(xs_decimal,0)
{
}
 
xs_decimalValue::~xs_decimalValue()
{
}

xs_decimalValue::xs_decimalValue(
	xqp_decimal const& _val)
:
	atomic_value(xs_decimal,0),
	val(_val)
{
}


///////////////////////////////
//	xs_double
///////////////////////////////

string xs_doubleValue::describe(
  context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_double[" << m_val << ']'; 
	return oss.str();
}

string xs_doubleValue::stringValue(
  context const* ctx_p) const
{
	ostringstream oss;
	oss << m_val; 
	return oss.str();
}

ostream& xs_doubleValue::put(
  ostream& os, context * ctx_p) const
{
	return os << "xs_double[" << m_val << ']'; 
}


///////////////////////////////
//	xs_duration
///////////////////////////////

string xs_durationValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_duration[" << val << ']'; 
	return oss.str();
}

string xs_durationValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_durationValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_duration[" << val << ']'; 
}

xs_durationValue::xs_durationValue()
: atomic_value(xs_duration,0)
{
}
 
xs_durationValue::~xs_durationValue()
{
}

xs_durationValue::xs_durationValue(
	xqp_duration const& _val)
:
	atomic_value(xs_duration,0),
	val(_val)
{
}


///////////////////////////////
//	xs_float
///////////////////////////////

string xs_floatValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_float[" << val << ']'; 
	return oss.str();
}

string xs_floatValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_floatValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_float[" << val << ']'; 
}

xs_floatValue::xs_floatValue()
: atomic_value(xs_float,0)
{
}
 
xs_floatValue::~xs_floatValue()
{
}

xs_floatValue::xs_floatValue(
	xqp_float const& _val)
:
	atomic_value(xs_float,0),
	val(_val)
{
}


///////////////////////////////
//	xs_gDay
///////////////////////////////

string xs_gDayValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_gDay[";
	xqp::put(oss,&val,xs_gDay) << ']';
	return oss.str();
}

string xs_gDayValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_gDay);
	return oss.str();
}

ostream& xs_gDayValue::put(ostream& os, context * ctx_p) const
{
	os << "xs_gDay[";
	xqp::put(os,&val,xs_gDay) << ']';
	return os; 
}

xs_gDayValue::xs_gDayValue()
: atomic_value(xs_gDay,0)
{
}
 
xs_gDayValue::~xs_gDayValue()
{
}

xs_gDayValue::xs_gDayValue(
	xqp_gDay const& _val)
:
	atomic_value(xs_gDay,0),
	val(_val)
{
}


///////////////////////////////
//	xs_gMonth
///////////////////////////////

string xs_gMonthValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_gMonth[";
	xqp::put(oss,&val,xs_gMonth) << ']';
	return oss.str();
}

string xs_gMonthValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_gMonth);
	return oss.str();
}

ostream& xs_gMonthValue::put(ostream& os, context * ctx_p) const
{
	os << "xs_gMonth[";
	xqp::put(os,&val,xs_gMonth) << ']';
	return os; 
}

xs_gMonthValue::xs_gMonthValue()
: atomic_value(xs_gMonth,0)
{
}
 
xs_gMonthValue::~xs_gMonthValue()
{
}

xs_gMonthValue::xs_gMonthValue(
	xqp_gMonth const& _val)
:
	atomic_value(xs_gMonth,0),
	val(_val)
{
}


///////////////////////////////
//	xs_gMonthDay
///////////////////////////////

string xs_gMonthDayValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_gMonthDay[";
	xqp::put(oss,&val,xs_gMonthDay) << ']';
	return oss.str();
}

string xs_gMonthDayValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_gMonthDay);
	return oss.str();
}

ostream& xs_gMonthDayValue::put(ostream& os, context * ctx_p) const
{
	os << "xs_gMonthDay[";
	xqp::put(os,&val,xs_gMonthDay) << ']';
	return os; 
}

xs_gMonthDayValue::xs_gMonthDayValue()
: atomic_value(xs_gMonthDay,0)
{
}
 
xs_gMonthDayValue::~xs_gMonthDayValue()
{
}

xs_gMonthDayValue::xs_gMonthDayValue(
	xqp_gMonthDay const& _val)
:
	atomic_value(xs_gMonthDay,0),
	val(_val)
{
}


///////////////////////////////
//	xs_gYear
///////////////////////////////

string xs_gYearValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_gYear[";
	xqp::put(oss,&val,xs_gYear) << ']';
	return oss.str();
}

string xs_gYearValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_gYear);
	return oss.str();
}

ostream& xs_gYearValue::put(ostream& os, context * ctx_p) const
{
	os << "xs_gYear[";
	xqp::put(os,&val,xs_gYear) << ']';
	return os; 
}

xs_gYearValue::xs_gYearValue()
: atomic_value(xs_gYear,0)
{
}
 
xs_gYearValue::~xs_gYearValue()
{
}

xs_gYearValue::xs_gYearValue(
	xqp_gYear const& _val)
:
	atomic_value(xs_gYear,0),
	val(_val)
{
}


///////////////////////////////
//	xs_gYearMonth
///////////////////////////////

string xs_gYearMonthValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_gYearMonth[";
	xqp::put(oss,&val,xs_gYearMonth) << ']';
	return oss.str();
}

string xs_gYearMonthValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_gYearMonth);
	return oss.str();
}

ostream& xs_gYearMonthValue::put(ostream& os, context * ctx_p) const
{
	os << "xs_gYearMonth[";
	xqp::put(os,&val,xs_gYearMonth) << ']';
	return os; 
}

xs_gYearMonthValue::xs_gYearMonthValue()
: atomic_value(xs_gYearMonth,0)
{
}
 
xs_gYearMonthValue::~xs_gYearMonthValue()
{
}

xs_gYearMonthValue::xs_gYearMonthValue(
	xqp_gYearMonth const& _val)
:
	atomic_value(xs_gYearMonth,0),
	val(_val)
{
}


///////////////////////////////
//	xs_hexBinary
///////////////////////////////

string xs_hexBinaryValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_hexBinary[" << val << ']'; 
	return oss.str();
}

string xs_hexBinaryValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_hexBinaryValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_hexBinary[" << val << ']'; 
}

xs_hexBinaryValue::xs_hexBinaryValue()
: atomic_value(xs_hexBinary,0)
{
}
 
xs_hexBinaryValue::~xs_hexBinaryValue()
{
}

xs_hexBinaryValue::xs_hexBinaryValue(
	xqp_hexBinary const& _val)
:
	atomic_value(xs_hexBinary,0),
	val(_val)
{
}


///////////////////////////////
//	xs_int
///////////////////////////////

string xs_intValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_int(" << m_val << ')'; 
	return oss.str();
}

string xs_intValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << m_val; 
	return oss.str();
}

ostream& xs_intValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_int[" << m_val << ']'; 
}


///////////////////////////////
//	xs_integer
///////////////////////////////

string xs_integerValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_integer[" << val << ']'; 
	return oss.str();
}

string xs_integerValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_integerValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_integer[" << val << ']'; 
}

xs_integerValue::xs_integerValue()
: atomic_value(xs_integer,0)
{
}
 
xs_integerValue::~xs_integerValue()
{
}

xs_integerValue::xs_integerValue(
	xqp_integer const& _val)
:
	atomic_value(xs_integer,0),
	val(_val)
{
}


///////////////////////////////
//	xs_language
///////////////////////////////

string xs_languageValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_language[" << val << ']'; 
	return oss.str();
}

string xs_languageValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_languageValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_language[" << val << ']'; 
}

xs_languageValue::xs_languageValue()
: atomic_value(xs_language,0)
{
}
 
xs_languageValue::~xs_languageValue()
{
}

xs_languageValue::xs_languageValue(
	xqp_language const& _val)
:
	atomic_value(xs_language,0),
	val(_val)
{
}


///////////////////////////////
//	xs_long
///////////////////////////////

string xs_longValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_long[" << m_val << ']'; 
	return oss.str();
}

string xs_longValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << m_val; 
	return oss.str();
}

ostream& xs_longValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_long[" << m_val << ']'; 
}


///////////////////////////////
//	xs_negativeInteger
///////////////////////////////

string xs_negativeIntegerValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_negativeInteger[" << val << ']'; 
	return oss.str();
}

string xs_negativeIntegerValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_negativeIntegerValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_negativeInteger[" << val << ']'; 
}

xs_negativeIntegerValue::xs_negativeIntegerValue()
: atomic_value(xs_negativeInteger,0)
{
}
 
xs_negativeIntegerValue::~xs_negativeIntegerValue()
{
}

xs_negativeIntegerValue::xs_negativeIntegerValue(
	xqp_negativeInteger const& _val)
:
	atomic_value(xs_negativeInteger,0),
	val(_val)
{
}


///////////////////////////////
//	xs_nonNegativeInteger
///////////////////////////////

string xs_nonNegativeIntegerValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_nonNegativeInteger[" << val << ']'; 
	return oss.str();
}

string xs_nonNegativeIntegerValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_nonNegativeIntegerValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_nonNegativeInteger[" << val << ']'; 
}

xs_nonNegativeIntegerValue::xs_nonNegativeIntegerValue()
: atomic_value(xs_nonNegativeInteger,0)
{
}
 
xs_nonNegativeIntegerValue::~xs_nonNegativeIntegerValue()
{
}

xs_nonNegativeIntegerValue::xs_nonNegativeIntegerValue(
	xqp_nonNegativeInteger const& _val)
:
	atomic_value(xs_nonNegativeInteger,0),
	val(_val)
{
}


///////////////////////////////
//	xs_nonPositiveInteger
///////////////////////////////

string xs_nonPositiveIntegerValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_nonPositiveInteger[" << val << ']'; 
	return oss.str();
}

string xs_nonPositiveIntegerValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_nonPositiveIntegerValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_nonPositiveInteger[" << val << ']'; 
}

xs_nonPositiveIntegerValue::xs_nonPositiveIntegerValue()
: atomic_value(xs_nonPositiveInteger,0)
{
}
 
xs_nonPositiveIntegerValue::~xs_nonPositiveIntegerValue()
{
}

xs_nonPositiveIntegerValue::xs_nonPositiveIntegerValue(
	xqp_nonPositiveInteger const& _val)
:
	atomic_value(xs_nonPositiveInteger,0),
	val(_val)
{
}


///////////////////////////////
//	xs_normalizedString
///////////////////////////////

string xs_normalizedStringValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_normalizedString[" << val << ']'; 
	return oss.str();
}

string xs_normalizedStringValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_normalizedStringValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_normalizedString[" << val << ']'; 
}

xs_normalizedStringValue::xs_normalizedStringValue()
: atomic_value(xs_normalizedString,0)
{
}
 
xs_normalizedStringValue::~xs_normalizedStringValue()
{
}

xs_normalizedStringValue::xs_normalizedStringValue(
	xqp_normalizedString const& _val)
:
	atomic_value(xs_normalizedString,0),
	val(_val)
{
}


///////////////////////////////
//	xs_positiveInteger
///////////////////////////////

string xs_positiveIntegerValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_positiveInteger[" << val << ']'; 
	return oss.str();
}

string xs_positiveIntegerValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_positiveIntegerValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_positiveInteger[" << val << ']'; 
}

xs_positiveIntegerValue::xs_positiveIntegerValue()
: atomic_value(xs_positiveInteger,0)
{
}
 
xs_positiveIntegerValue::~xs_positiveIntegerValue()
{
}

xs_positiveIntegerValue::xs_positiveIntegerValue(
	xqp_positiveInteger const& _val)
:
	atomic_value(xs_positiveInteger,0),
	val(_val)
{
}


///////////////////////////////
//	xs_short
///////////////////////////////

string xs_shortValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_short[" << val << ']'; 
	return oss.str();
}

string xs_shortValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_shortValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_short[" << val << ']'; 
}

xs_shortValue::xs_shortValue()
: atomic_value(xs_short,0)
{
}
 
xs_shortValue::~xs_shortValue()
{
}

xs_shortValue::xs_shortValue(
	xqp_short const& _val)
:
	atomic_value(xs_short,0),
	val(_val)
{
}


///////////////////////////////
//	xs_string
///////////////////////////////

string xs_stringValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_string[" << rest << ']'; 
	return oss.str();
}

string xs_stringValue::stringValue(
	context const* ctx_p) const
{
	ostringstream oss;
	oss << rest; 
	return oss.str();
}

ostream& xs_stringValue::put(
	ostream& os,
	context * ctx_p) const
{
	return os << "xs_string[" << rest << ']'; 
}

xs_stringValue::xs_stringValue(
	itemstore& istore,
	string const& s)
:
	atomic_value(xs_string,s.length())
{
	istore.add_text(s);
}
 
string xs_stringValue::str() const
{
	ostringstream oss;
	oss << rest; 
	return oss.str();
}
 


///////////////////////////////
//	qname_value
///////////////////////////////

qname_value::qname_value(
	itemstore& istore,
	qnamekey_t key,
	itemref_t nameref)
:
	atomic_value(xs_qname,sizeof(qname_value)),
	m_qnamekey(key),
	m_nameref(nameref)
{
//cout << TRACE << " : nameref = " << m_nameref << endl;
}

qname_value::qname_value(
	context * ctx_p,
	string const& name)
:
	atomic_value(xs_qname,sizeof(qname_value)),
	m_qnamekey(hashfun::h64(name))
{
//cout << TRACE << " : nameref = " << m_nameref << endl;
  itemstore & istore = *ctx_p->istore();
  m_nameref = istore.eos();
  new(istore) xs_stringValue(istore,name);
}

qname_value::qname_value()
{
//cout << TRACE << " : nameref = " << m_nameref << endl;
}

string qname_value::prefix(
	itemstore& istore) const
{
	xs_stringValue* s_p = new(istore,m_nameref) xs_stringValue();
	string name = s_p->str();
	string::size_type n = name.find(':');
  return name.substr(0,n);
}

string qname_value::localname(
	itemstore& istore) const
{
  xs_stringValue* s_p = new(istore,m_nameref) xs_stringValue();
	string name = s_p->str();
	string::size_type n = name.find(':');
  return name.substr(n+1);
}

void* qname_value::operator new(
	size_t node_size,
	itemstore& istore)
{
	return istore.alloc(node_size);
}

void* qname_value::operator new(
	size_t node_size,
	itemstore& istore,
	off_t offset)
{
	return &istore[offset];
}

void* qname_value::operator new(
	size_t n,
	void* p)
{
	return p;
}

ostream& qname_value::put(
	ostream& os,
	context * ctx_p) const
{
	return os << "";
}

string qname_value::describe(
	context * ctx_p) const
{
	return "xs_qname()";
}

rchandle<item_iterator> qname_value::atomized_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> qname_value::effective_boolean_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

string qname_value::string_value(
	context const* ctx_p) const
{
	return "";
}


///////////////////////////////
//	xs_time
///////////////////////////////

string xs_timeValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_time[";
	xqp::put(oss,&val,xs_time) << ']';
	return oss.str();
}

string xs_timeValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	xqp::put(oss,&val,xs_time);
	return oss.str();
}

ostream& xs_timeValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_time[";
	xqp::put(os,&val,xs_time) << ']';
	return os; 
}

xs_timeValue::xs_timeValue()
: atomic_value(xs_time,0)
{
}
 
xs_timeValue::~xs_timeValue()
{
}

xs_timeValue::xs_timeValue(
	xqp_time const& _val)
:
	atomic_value(xs_time,0),
	val(_val)
{
}


///////////////////////////////
//	xs_token
///////////////////////////////

string xs_tokenValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_token[" << val << ']'; 
	return oss.str();
}

string xs_tokenValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_tokenValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_token[" << val << ']'; 
}

xs_tokenValue::xs_tokenValue()
: atomic_value(xs_token,0)
{
}
 
xs_tokenValue::~xs_tokenValue()
{
}

xs_tokenValue::xs_tokenValue(
	xqp_token const& _val)
:
	atomic_value(xs_token,0),
	val(_val)
{
}


///////////////////////////////
//	xs_unsignedByte
///////////////////////////////

string xs_unsignedByteValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_unsignedByte[" << val << ']'; 
	return oss.str();
}

string xs_unsignedByteValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_unsignedByteValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_unsignedByte[" << val << ']'; 
}

xs_unsignedByteValue::xs_unsignedByteValue()
: atomic_value(xs_unsignedByte,0)
{
}
 
xs_unsignedByteValue::~xs_unsignedByteValue()
{
}

xs_unsignedByteValue::xs_unsignedByteValue(
	xqp_unsignedByte const& _val)
:
	atomic_value(xs_unsignedByte,0),
	val(_val)
{
}


///////////////////////////////
//	xs_unsignedInt
///////////////////////////////

string xs_unsignedIntValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_unsignedInt[" << val << ']'; 
	return oss.str();
}

string xs_unsignedIntValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_unsignedIntValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_unsignedInt[" << val << ']'; 
}

xs_unsignedIntValue::xs_unsignedIntValue()
: atomic_value(xs_unsignedInt,0)
{
}
 
xs_unsignedIntValue::~xs_unsignedIntValue()
{
}

xs_unsignedIntValue::xs_unsignedIntValue(
	xqp_unsignedInt const& _val)
:
	atomic_value(xs_unsignedInt,0),
	val(_val)
{
}


///////////////////////////////
//	xs_unsignedLong
///////////////////////////////

string xs_unsignedLongValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_unsignedLong[" << val << ']'; 
	return oss.str();
}

string xs_unsignedLongValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_unsignedLongValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_unsignedLong[" << val << ']'; 
}

xs_unsignedLongValue::xs_unsignedLongValue()
: atomic_value(xs_unsignedLong,0)
{
}
 
xs_unsignedLongValue::~xs_unsignedLongValue()
{
}

xs_unsignedLongValue::xs_unsignedLongValue(
	xqp_unsignedLong const& _val)
:
	atomic_value(xs_unsignedLong,0),
	val(_val)
{
}


///////////////////////////////
//	xs_unsignedShort
///////////////////////////////

string xs_unsignedShortValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_unsignedShort[" << val << ']'; 
	return oss.str();
}

string xs_unsignedShortValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_unsignedShortValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_unsignedShort[" << val << ']'; 
}

xs_unsignedShortValue::xs_unsignedShortValue()
: atomic_value(xs_unsignedShort,0)
{
}
 
xs_unsignedShortValue::~xs_unsignedShortValue()
{
}

xs_unsignedShortValue::xs_unsignedShortValue(
	xqp_unsignedShort const& _val)
:
	atomic_value(xs_unsignedShort,0),
	val(_val)
{
}


///////////////////////////////
//	xs_ENTITIES
///////////////////////////////

string xs_ENTITIESValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_ENTITIES[" << val << ']'; 
	return oss.str();
}

string xs_ENTITIESValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_ENTITIESValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_ENTITIES[" << val << ']'; 
}

xs_ENTITIESValue::xs_ENTITIESValue()
: atomic_value(xs_entitySeq,0)
{
}
 
xs_ENTITIESValue::~xs_ENTITIESValue()
{
}

xs_ENTITIESValue::xs_ENTITIESValue(
	xqp_ENTITIES const& _val)
:
	atomic_value(xs_entitySeq,0),
	val(_val)
{
}


///////////////////////////////
//	xs_ENTITY
///////////////////////////////

string xs_ENTITYValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_ENTITY[" << val << ']'; 
	return oss.str();
}

string xs_ENTITYValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_ENTITYValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_ENTITY[" << val << ']'; 
}

xs_ENTITYValue::xs_ENTITYValue()
: atomic_value(xs_entity,0)
{
}
 
xs_ENTITYValue::~xs_ENTITYValue()
{
}

xs_ENTITYValue::xs_ENTITYValue(
	xqp_ENTITY const& _val)
:
	atomic_value(xs_entity,0),
	val(_val)
{
}



///////////////////////////////
//	xs_ID
///////////////////////////////

string xs_IDValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_ID[" << val << ']'; 
	return oss.str();
}

string xs_IDValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_IDValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_ID[" << val << ']'; 
}

xs_IDValue::xs_IDValue()
: atomic_value(xs_id,0)
{
}
 
xs_IDValue::~xs_IDValue()
{
}

xs_IDValue::xs_IDValue(
	xqp_ID const& _val)
:
	atomic_value(xs_id,0),
	val(_val)
{
}



///////////////////////////////
//	xs_IDREF
///////////////////////////////

string xs_IDREFValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_IDREF[" << val << ']'; 
	return oss.str();
}

string xs_IDREFValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_IDREFValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_IDREF[" << val << ']'; 
}

xs_IDREFValue::xs_IDREFValue()
: atomic_value(xs_idref,0)
{
}
 
xs_IDREFValue::~xs_IDREFValue()
{
}

xs_IDREFValue::xs_IDREFValue(
	xqp_IDREF const& _val)
:
	atomic_value(xs_idref,0),
	val(_val)
{
}



///////////////////////////////
//	xs_IDREFS
///////////////////////////////

string xs_IDREFSValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_IDREFS[" << val << ']'; 
	return oss.str();
}

string xs_IDREFSValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_IDREFSValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_IDREFS[" << val << ']'; 
}

xs_IDREFSValue::xs_IDREFSValue()
: atomic_value(xs_idrefSeq,0)
{
}
 
xs_IDREFSValue::~xs_IDREFSValue()
{
}

xs_IDREFSValue::xs_IDREFSValue(
	xqp_IDREFS const& _val)
:
	atomic_value(xs_idrefSeq,0),
	val(_val)
{
}


///////////////////////////////
//	xs_NCName
///////////////////////////////

string xs_NCNameValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_NCName[" << val << ']'; 
	return oss.str();
}

string xs_NCNameValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_NCNameValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_NCName[" << val << ']'; 
}

xs_NCNameValue::xs_NCNameValue()
: atomic_value(xs_ncName,0)
{
}
 
xs_NCNameValue::~xs_NCNameValue()
{
}

xs_NCNameValue::xs_NCNameValue(
	xqp_NCName const& _val)
:
	atomic_value(xs_ncName,0),
	val(_val)
{
}



///////////////////////////////
//	xs_NMTOKEN
///////////////////////////////

string xs_NMTOKENValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_NMTOKEN[" << val << ']'; 
	return oss.str();
}

string xs_NMTOKENValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_NMTOKENValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_NMTOKEN[" << val << ']'; 
}

xs_NMTOKENValue::xs_NMTOKENValue()
: atomic_value(xs_nmtoken,0)
{
}
 
xs_NMTOKENValue::~xs_NMTOKENValue()
{
}

xs_NMTOKENValue::xs_NMTOKENValue(
	xqp_NMTOKEN const& _val)
:
	atomic_value(xs_nmtoken ,0),
	val(_val)
{
}


///////////////////////////////
//	xs_NMTOKENS
///////////////////////////////

string xs_NMTOKENSValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_NMTOKENS[" << val << ']'; 
	return oss.str();
}

string xs_NMTOKENSValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_NMTOKENSValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_NMTOKENS[" << val << ']'; 
}

xs_NMTOKENSValue::xs_NMTOKENSValue()
: atomic_value(xs_nmtokenSeq ,0)
{
}
 
xs_NMTOKENSValue::~xs_NMTOKENSValue()
{
}

xs_NMTOKENSValue::xs_NMTOKENSValue(
	xqp_NMTOKENS const& _val)
:
	atomic_value(xs_nmtokenSeq ,0),
	val(_val)
{
}



///////////////////////////////
//	xs_NOTATION
///////////////////////////////

string xs_NOTATIONValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_NOTATION[" << val << ']'; 
	return oss.str();
}

string xs_NOTATIONValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_NOTATIONValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_NOTATION[" << val << ']'; 
}

xs_NOTATIONValue::xs_NOTATIONValue()
: atomic_value(xs_notation ,0)
{
}
 
xs_NOTATIONValue::~xs_NOTATIONValue()
{
}

xs_NOTATIONValue::xs_NOTATIONValue(
	xqp_NOTATION const& _val)
:
	atomic_value(xs_notation ,0),
	val(_val)
{
}


///////////////////////////////
//	xs_Name
///////////////////////////////

string xs_NameValue::describe(context * ctx_p) const
{
	ostringstream oss;
	oss << "xs_Name[" << val << ']'; 
	return oss.str();
}

string xs_NameValue::stringValue(context const* ctx_p) const
{
	ostringstream oss;
	oss << val; 
	return oss.str();
}

ostream& xs_NameValue::put(ostream& os, context * ctx_p) const
{
	return os << "xs_Name[" << val << ']'; 
}

xs_NameValue::xs_NameValue()
: atomic_value(xs_name ,0)
{
}
 
xs_NameValue::~xs_NameValue()
{
}

xs_NameValue::xs_NameValue(
	xqp_Name const& _val)
:
	atomic_value(xs_name ,0),
	val(_val)
{
}



}	/* namespace xqp */

