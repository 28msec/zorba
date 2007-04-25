/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_primitive_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "zorba_primitive_values.h"
#include "primitive_valuereps.h"
#include "../types/typecodes.h"
#include "../zorba/zorba_iterator.h"

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
string zorba_anyURIValue::describe() const
{
	ostringstream oss;
	oss << "zorba_anyURI["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_anyURIValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_anyURIValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_anyURIValue::put(ostream& os) const
{
	os << "zorba_anyURI[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//  Base64Binary
///////////////////////////////

string zorba_base64BinaryValue::describe() const
{
	ostringstream oss;
	oss << "zorba_base64Binary["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_base64BinaryValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_base64BinaryValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_base64BinaryValue::put(ostream& os) const
{
	os << "zorba_base64Binary[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//  zorba_boolean
///////////////////////////////

string zorba_booleanValue::describe() const
{
	ostringstream oss;
	oss << "zorba_boolean["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_booleanValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_booleanValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_booleanValue::put(ostream& os) const
{
	os << "zorba_boolean[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//  zorba_byte
///////////////////////////////

string zorba_byteValue::describe() const
{
	ostringstream oss;
	oss << "zorba_byte["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_byteValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_byteValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_byteValue::put(ostream& os) const
{
	os << "zorba_byte[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_date
///////////////////////////////

string zorba_dateValue::describe() const
{
	ostringstream oss;
	oss << "zorba_date["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_dateValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_dateValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_dateValue::put(ostream& os) const
{
	os << "zorba_date[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_dateTime
///////////////////////////////

string zorba_dateTimeValue::describe() const
{
	ostringstream oss;
	oss << "zorba_dateTime["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_dateTimeValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_dateTimeValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_dateTimeValue::put(ostream& os) const
{
	os << "zorba_dateTime[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_decimal
///////////////////////////////

string zorba_decimalValue::describe() const
{
	ostringstream oss;
	oss << "zorba_decimal["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_decimalValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_decimalValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_decimalValue::put(ostream& os) const
{
	os << "zorba_decimal[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_double
///////////////////////////////

string zorba_doubleValue::describe() const
{
	ostringstream oss;
	oss << "zorba_double["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_doubleValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_doubleValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_doubleValue::put(ostream& os) const
{
	os << "zorba_double[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_duration
///////////////////////////////

string zorba_durationValue::describe() const
{
	ostringstream oss;
	oss << "zorba_duration["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_durationValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_durationValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_durationValue::put(ostream& os) const
{
	os << "zorba_duration[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_float
///////////////////////////////

string zorba_floatValue::describe() const
{
	ostringstream oss;
	oss << "zorba_float["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_floatValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_floatValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_floatValue::put(ostream& os) const
{
	os << "zorba_float[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_gDay
///////////////////////////////

string zorba_gDayValue::describe() const
{
	ostringstream oss;
	oss << "zorba_gDay["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_gDayValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_gDayValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_gDayValue::put(ostream& os) const
{
	os << "zorba_gDay[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_gMonth
///////////////////////////////

string zorba_gMonthValue::describe() const
{
	ostringstream oss;
	oss << "zorba_gMonth["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_gMonthValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_gMonthValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_gMonthValue::put(ostream& os) const
{
	os << "zorba_gMonth[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_gMonthDay
///////////////////////////////

string zorba_gMonthDayValue::describe() const
{
	ostringstream oss;
	oss << "zorba_gMonthDay["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_gMonthDayValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_gMonthDayValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_gMonthDayValue::put(ostream& os) const
{
	os << "zorba_gMonthDay[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_gYear
///////////////////////////////

string zorba_gYearValue::describe() const
{
	ostringstream oss;
	oss << "zorba_gYear["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_gYearValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_gYearValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_gYearValue::put(ostream& os) const
{
	os << "zorba_gYear[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_gYearMonth
///////////////////////////////

string zorba_gYearMonthValue::describe() const
{
	ostringstream oss;
	oss << "zorba_gYearMonth["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_gYearMonthValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_gYearMonthValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_gYearMonthValue::put(ostream& os) const
{
	os << "zorba_gYearMonth[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_hexBinary
///////////////////////////////

string zorba_hexBinaryValue::describe() const
{
	ostringstream oss;
	oss << "zorba_hexBinary["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_hexBinaryValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_hexBinaryValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_hexBinaryValue::put(ostream& os) const
{
	os << "zorba_hexBinary[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_int
///////////////////////////////

string zorba_intValue::describe() const
{
	ostringstream oss;
	oss << "zorba_int["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_intValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_intValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_intValue::put(ostream& os) const
{
	os << "zorba_int[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_integer
///////////////////////////////

string zorba_integerValue::describe() const
{
	ostringstream oss;
	oss << "zorba_integer["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_integerValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_integerValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_integerValue::put(ostream& os) const
{
	os << "zorba_integer[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_language
///////////////////////////////

string zorba_languageValue::describe() const
{
	ostringstream oss;
	oss << "zorba_language["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_languageValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_languageValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_languageValue::put(ostream& os) const
{
	os << "zorba_language[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_long
///////////////////////////////

string zorba_longValue::describe() const
{
	ostringstream oss;
	oss << "zorba_long["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_longValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_longValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_longValue::put(ostream& os) const
{
	os << "zorba_long[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_negativeInteger
///////////////////////////////

string zorba_negativeIntegerValue::describe() const
{
	ostringstream oss;
	oss << "zorba_negativeInteger["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_negativeIntegerValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_negativeIntegerValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_negativeIntegerValue::put(ostream& os) const
{
	os << "zorba_negativeInteger[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_nonNegativeInteger
///////////////////////////////

string zorba_nonNegativeIntegerValue::describe() const
{
	ostringstream oss;
	oss << "zorba_nonNegativeInteger["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_nonNegativeIntegerValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_nonNegativeIntegerValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_nonNegativeIntegerValue::put(ostream& os) const
{
	os << "zorba_nonNegativeInteger[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_nonPositiveInteger
///////////////////////////////

string zorba_nonPositiveIntegerValue::describe() const
{
	ostringstream oss;
	oss << "zorba_nonPositiveInteger["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_nonPositiveIntegerValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_nonPositiveIntegerValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_nonPositiveIntegerValue::put(ostream& os) const
{
	os << "zorba_nonPositiveInteger[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_normalizedString
///////////////////////////////

string zorba_normalizedStringValue::describe() const
{
	ostringstream oss;
	oss << "zorba_normalizedString["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_normalizedStringValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_normalizedStringValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_normalizedStringValue::put(ostream& os) const
{
	os << "zorba_normalizedString[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_positiveInteger
///////////////////////////////

string zorba_positiveIntegerValue::describe() const
{
	ostringstream oss;
	oss << "zorba_positiveInteger["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_positiveIntegerValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_positiveIntegerValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_positiveIntegerValue::put(ostream& os) const
{
	os << "zorba_positiveInteger[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_short
///////////////////////////////

string zorba_shortValue::describe() const
{
	ostringstream oss;
	oss << "zorba_short["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_shortValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_shortValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_shortValue::put(ostream& os) const
{
	os << "zorba_short[";
	return rep->put(os) << ']'; 
}


inline uint32_t _mod4(uint32_t n)
{
	return (n/4 + (n%4 ? 1 : 0));
}


///////////////////////////////
//	zorba_string
///////////////////////////////

string zorba_stringValue::describe() const
{
	ostringstream oss;
	oss << "zorba_string["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_stringValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_stringValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_stringValue::put(ostream& os) const
{
	os << "zorba_string[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_time
///////////////////////////////

string zorba_timeValue::describe() const
{
	ostringstream oss;
	oss << "zorba_time["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_timeValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_timeValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_timeValue::put(ostream& os) const
{
	os << "zorba_time[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_token
///////////////////////////////

string zorba_tokenValue::describe() const
{
	ostringstream oss;
	oss << "zorba_token["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_tokenValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_tokenValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_tokenValue::put(ostream& os) const
{
	os << "zorba_token[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_unsignedByte
///////////////////////////////

string zorba_unsignedByteValue::describe() const
{
	ostringstream oss;
	oss << "zorba_unsignedByte["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_unsignedByteValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_unsignedByteValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_unsignedByteValue::put(ostream& os) const
{
	os << "zorba_unsignedByte[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_unsignedInt
///////////////////////////////

string zorba_unsignedIntValue::describe() const
{
	ostringstream oss;
	oss << "zorba_unsignedInt["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_unsignedIntValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_unsignedIntValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_unsignedIntValue::put(ostream& os) const
{
	os << "zorba_unsignedInt[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_unsignedLong
///////////////////////////////

string zorba_unsignedLongValue::describe() const
{
	ostringstream oss;
	oss << "zorba_unsignedLong["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_unsignedLongValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_unsignedLongValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_unsignedLongValue::put(ostream& os) const
{
	os << "zorba_unsignedLong[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_unsignedShort
///////////////////////////////

string zorba_unsignedShortValue::describe() const
{
	ostringstream oss;
	oss << "zorba_unsignedShort["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_unsignedShortValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_unsignedShortValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_unsignedShortValue::put(ostream& os) const
{
	os << "zorba_unsignedShort[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_ENTITIES
///////////////////////////////

string zorba_ENTITIESValue::describe() const
{
	ostringstream oss;
	oss << "zorba_ENTITIES["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_ENTITIESValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_ENTITIESValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_ENTITIESValue::put(ostream& os) const
{
	os << "zorba_ENTITIES[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_ENTITY
///////////////////////////////

string zorba_ENTITYValue::describe() const
{
	ostringstream oss;
	oss << "zorba_ENTITY["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_ENTITYValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_ENTITYValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_ENTITYValue::put(ostream& os) const
{
	os << "zorba_ENTITY[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_ID
///////////////////////////////

string zorba_IDValue::describe() const
{
	ostringstream oss;
	oss << "zorba_ID["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_IDValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_IDValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_IDValue::put(ostream& os) const
{
	os << "zorba_ID[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_IDREF
///////////////////////////////

string zorba_IDREFValue::describe() const
{
	ostringstream oss;
	oss << "zorba_IDREF["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_IDREFValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_IDREFValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_IDREFValue::put(ostream& os) const
{
	os << "zorba_IDREF[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_IDREFS
///////////////////////////////

string zorba_IDREFSValue::describe() const
{
	ostringstream oss;
	oss << "zorba_IDREFS["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_IDREFSValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_IDREFSValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_IDREFSValue::put(ostream& os) const
{
	os << "zorba_IDREFS[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_NCName
///////////////////////////////

string zorba_NCNameValue::describe() const
{
	ostringstream oss;
	oss << "zorba_NCName["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_NCNameValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_NCNameValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_NCNameValue::put(ostream& os) const
{
	os << "zorba_NCName[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_NMTOKEN
///////////////////////////////

string zorba_NMTOKENValue::describe() const
{
	ostringstream oss;
	oss << "zorba_NMTOKEN["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_NMTOKENValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_NMTOKENValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_NMTOKENValue::put(ostream& os) const
{
	os << "zorba_NMTOKEN[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_NMTOKENS
///////////////////////////////

string zorba_NMTOKENSValue::describe() const
{
	ostringstream oss;
	oss << "zorba_NMTOKENS["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_NMTOKENSValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_NMTOKENSValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_NMTOKENSValue::put(ostream& os) const
{
	os << "zorba_NMTOKENS[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_NOTATION
///////////////////////////////

string zorba_NOTATIONValue::describe() const
{
	ostringstream oss;
	oss << "zorba_NOTATION["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_NOTATIONValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_NOTATIONValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_NOTATIONValue::put(ostream& os) const
{
	os << "zorba_NOTATION[";
	return rep->put(os) << ']'; 
}


///////////////////////////////
//	zorba_Name
///////////////////////////////

string zorba_NameValue::describe() const
{
	ostringstream oss;
	oss << "zorba_Name["; rep->put(oss) << ']'; 
	return oss.str();
}

string zorba_NameValue::string_value() const
{
	ostringstream oss;
	rep->put(oss); 
	return oss.str();
}

iterator_t zorba_NameValue::atomized_value() const
{
	return new singleton_iterator(this);
}

ostream& zorba_NameValue::put(ostream& os) const
{
	os << "zorba_Name[";
	return rep->put(os) << ']'; 
}


}	/* namespace xqp */

