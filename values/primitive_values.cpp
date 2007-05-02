/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: primitive_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "primitive_values.h"
#include "types/typecodes.h"
#include "util/tracer.h"
#include "runtime/item_iterator.h"
#include "runtime/singleton_iterators.h"

#include <iostream>
#include <sstream>

using namespace std;
namespace xqp {

ostream& _put(
	ostream& os,
	const struct tm* t,
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

ostream& _put(
	ostringstream& os,
	const struct tm* t,
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


// numericValue
// ------------
ostream& numericValue::put(
	zorba* zorp,
	ostream& os) const
{
	switch (type()) {
	case xs_decimal: return os << "decimal(" << theVal << ')';
	case xs_integer: return os << "integer(" << (int)theVal << ')';
	case xs_long: return os << "long(" << (long)theVal << ')';
	case xs_int: return os << "int(" << (int)theVal << ')';
	case xs_short: return os << "short(" << (short)theVal << ')';
	case xs_double: return os << "double(" << (double)theVal << ')';
	case xs_float: return os << "float(" << (float)theVal << ')';
	case xs_negativeInteger: return os << "negativeInteger(" << (int)theVal << ')';
	case xs_nonNegativeInteger: return os << "nonNegativeInteger(" << (int)theVal << ')';
	case xs_nonPositiveInteger: return os << "nonPositiveInteger(" << (int)theVal << ')';
	case xs_positiveInteger: return os << "positiveInteger(" << (int)theVal << ')';
	case xs_unsignedInt: return os << "unsignedInt(" << (unsigned int)theVal << ')';
	case xs_unsignedLong: return os << "unsignedLong(" << (unsigned long)theVal << ')';
	case xs_unsignedShort: return os << "unsignedShort(" << (unsigned short)theVal << ')';
	default: return os << "??";
	}
}

string numericValue::describe(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

numericValue::numericValue(
	sequence_type_t type,
	long double val)
:
	theType(type),
	theVal(val)
{
}

iterator_t numericValue::string_value(
	zorba* zorp) const
{
	return new string_singleton(stringValue(describe(zorp)));
}


// timeValue
// ---------
timeValue::timeValue(
	sequence_type_t type,
	struct tm t)
:
	theType(type),
	theVal(t)
{
}

timeValue::timeValue(
	const string& s)
:
	theType(xs_dateTime)
{
	// parse date-time-duration string
}

ostream& timeValue::put(
	zorba* zorp,
	ostream& os) const
{
	os << "time(";
	return _put(os,&theVal,theType) << ')';
}

string timeValue::describe(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

iterator_t timeValue::string_value(
	zorba* zorp) const
{
	return new string_singleton(stringValue(describe(zorp)));
}



// stringValue
// -----------
stringValue::stringValue(
	sequence_type_t type,
	const string& s)
:
	theType(type),
	theVal(s)
{
}

stringValue::stringValue(
	const string& s)
:
	theType(xs_string),
	theVal(s)
{
}

ostream& stringValue::put(
	zorba* zorp,
	ostream& os) const
{
	switch (type()) {
	case xs_string: return os << "string(" << theVal << ')';
	case xs_normalizedString: return os << "normalizedString(" << theVal << ')';
	case xs_token: return os << "Token(" << theVal << ')';
	case xs_language: return os << "language(" << theVal << ')';
	case xs_nmtoken: return os << "NMToken(" << theVal << ')';
	case xs_name: return os << "Name(" << theVal << ')';
	case xs_ncName: return os << "NCName(" << theVal << ')';
	case xs_id: return os << "ID(" << theVal << ')';
	case xs_idref: return os << "IDREF(" << theVal << ')';
	case xs_entity: return os << "ENTITY(" << theVal << ')';
	case xs_anyURI: return os << "anyURI(" << theVal << ')';
	default: return os << "??";
	}
}

string stringValue::describe(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

iterator_t stringValue::atomized_value(
	zorba* zorp) const
{
	return new string_singleton(*this);
}

iterator_t stringValue::effective_boolean_value(
	zorba* zorp) const
{
	return NULL;
}

iterator_t stringValue::string_value(
	zorba* zorp) const
{
	return new string_singleton(*this);
}



// binaryValue
// -----------
binaryValue::binaryValue(
	sequence_type_t type,
	const void* p,
	size_t length)
:
	theType(type),
	theVal(new unsigned char[length]),
	theLength(length)
{
	memcpy(theVal, p, theLength);
}

binaryValue::~binaryValue()
{
	delete[] theVal;
}

ostream& binaryValue::put(
	zorba* zorp,
	std::ostream& os) const
{
	return os;
	// some printable representation of binary
}

string binaryValue::describe(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

iterator_t binaryValue::string_value(
	zorba* zorp) const
{
	return new string_singleton(stringValue(describe(zorp)));
}



// booleanValue
// ------------
booleanValue::booleanValue(
	bool b)
:
	theType(xs_boolean),
	theVal(b)
{
}

ostream& booleanValue::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "boolean(" << theVal << ')';
}

string booleanValue::describe(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

iterator_t booleanValue::string_value(
	zorba* zorp) const
{
	return new string_singleton(stringValue(describe(zorp)));
}



}	/* namespace xqp */

