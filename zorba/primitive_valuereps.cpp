/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: primitive_valuereps.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "primitive_valuereps.h"
#include "../types/typecodes.h"

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


// numericRep
// ----------
ostream& numericRep::put(ostream& os) const
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


// timeRep
// -------
timeRep::timeRep(
	sequence_type_t t,
	struct tm _val)
:
	atomic_valueRep(t),
	theVal(_val)
{
}

ostream& timeRep::put(ostream& os) const
{
	os << "dateTime(";
	return _put(os,&theVal,theType) << ')';
}


// stringRep
// ---------
stringRep::stringRep(
	const string& s)
:
	atomic_valueRep(xs_string),
	theVal(s)
{
}

ostream& stringRep::put(
	ostream& os) const
{
	return os << theVal;
}


// binaryRep
// ---------
binaryRep::binaryRep(
	unsigned char* p,
	size_t _length)
:
	atomic_valueRep(xs_rawBinaryType),
	theVal(new unsigned char[_length]),
	length(_length)
{
	memcpy(theVal, p, length);
}

binaryRep::~binaryRep()
{
	delete[] theVal;
}

ostream& binaryRep::put(
	std::ostream& os) const
{
	return os;
}


}	/* namespace xqp */

