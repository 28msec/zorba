/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: value_factory.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "value_factory.h"
#include "../types/sequence_type.h"

using namespace std;
namespace xqp {

qname_value* value_factory::make_qname(
	const string& uri,
	const string& prefix,
	const string& localname)
{
	qname_value* result = new(&buf[eos]) qname_value(uri,prefix,localname);
	eos += result->length();
	return result;
}

xs_anyURIValue* value_factory::make_xs_anyURI()
{
	return NULL;
}

xs_base64BinaryValue* value_factory::make_xs_base64Binary()
{
	return NULL;
}

xs_booleanValue* value_factory::make_xs_boolean(bool)
{
	return NULL;
}

xs_decimalValue* value_factory::make_xs_decimal()
{
	return NULL;
}

xs_integerValue* value_factory::make_xs_integer(int)
{
	return NULL;
}

xs_longValue* value_factory::make_xs_long(long)
{
	return NULL;
}

xs_intValue* value_factory::make_xs_int(int n)
{
	xs_intValue* result = new(&buf[eos]) xs_intValue(n);
	eos += result->length();
	return result;
}

xs_shortValue* value_factory::make_xs_short(short)
{
	return NULL;
}

xs_byteValue* value_factory::make_xs_byte(char)
{
	return NULL;
}

xs_dateValue* value_factory::make_xs_date()
{
	return NULL;
}

xs_dateTimeValue* value_factory::make_xs_dateTime()
{
	return NULL;
}

xs_doubleValue* value_factory::make_xs_double(double)
{
	return NULL;
}

xs_durationValue* value_factory::make_xs_duration()
{
	return NULL;
}

xs_ENTITIESValue* value_factory::make_xs_ENTITIES()
{
	return NULL;
}

xs_ENTITYValue* value_factory::make_xs_ENTITY()
{
	return NULL;
}

xs_floatValue* value_factory::make_xs_float(float)
{
	return NULL;
}

xs_gDayValue* value_factory::make_xs_gDay()
{
	return NULL;
}

xs_gMonthValue* value_factory::make_xs_gMonth()
{
	return NULL;
}

xs_gMonthDayValue* value_factory::make_xs_gMonthDay()
{
	return NULL;
}

xs_gYearValue* value_factory::make_xs_gYear()
{
	return NULL;
}

xs_gYearMonthValue* value_factory::make_xs_gYearMonth()
{
	return NULL;
}

xs_hexBinaryValue* value_factory::make_xs_hexBinary()
{
	return NULL;
}

xs_IDValue* value_factory::make_xs_ID()
{
	return NULL;
}

xs_IDREFValue* value_factory::make_xs_IDREF()
{
	return NULL;
}

xs_IDREFSValue* value_factory::make_xs_IDREFS()
{
	return NULL;
}

xs_languageValue* value_factory::make_xs_language(const string&)
{
	return NULL;
}

xs_NCNameValue* value_factory::make_xs_NCName(const string&)
{
	return NULL;
}

xs_NMTOKENValue* value_factory::make_xs_NMTOKEN(const string&)
{
	return NULL;
}

xs_NMTOKENSValue* value_factory::make_xs_NMTOKENS(const string&)
{
	return NULL;
}

xs_NOTATIONValue* value_factory::make_xs_NOTATION(const string&)
{
	return NULL;
}

xs_NameValue* value_factory::make_xs_Name(const string&)
{
	return NULL;
}

xs_negativeIntegerValue* value_factory::make_xs_negativeInteger(int)
{
	return NULL;
}

xs_nonNegativeIntegerValue* value_factory::make_xs_nonNegativeInteger(int)
{
	return NULL;
}

xs_nonPositiveIntegerValue* value_factory::make_xs_nonPositiveInteger(int)
{
	return NULL;
}

xs_normalizedStringValue* value_factory::make_xs_normalizedString(const string&)
{
	return NULL;
}

xs_positiveIntegerValue* value_factory::make_xs_positiveInteger(unsigned int)
{
	return NULL;
}

xs_stringValue* value_factory::make_xs_string(const string& s)
{
	xs_stringValue* result = new(&buf[eos]) xs_stringValue(s);
	eos += result->length();
	return result;
}

uri_value* value_factory::make_uri(const string&)
{
	return NULL;
}

xs_timeValue* value_factory::make_xs_time()
{
	return NULL;
}

xs_tokenValue* value_factory::make_xs_token(const string&)
{
	return NULL;
}

xs_unsignedByteValue* value_factory::make_xs_unsignedByte(unsigned char)
{
	return NULL;
}

xs_unsignedIntValue* value_factory::make_xs_unsignedInt(unsigned int)
{
	return NULL;
}

xs_unsignedLongValue* value_factory::make_xs_unsignedLong(unsigned long)
{
	return NULL;
}

xs_unsignedShortValue* value_factory::make_xs_unsignedShort(uint16_t)
{
	return NULL;
}

atomic_value* value_factory::cast_as(
	iterator_t it, 
	sequence_type_t t)
{
	if (it->done()) return NULL;
	item* i_p = (item*)it->peek();
	if (i_p->type()!=t) return NULL;	//XXX upgrade this

	switch (t) {
	case xs_anyURI: return new(i_p) xs_anyURIValue();
	case xs_base64Binary: return new(i_p) xs_base64BinaryValue();
	case xs_boolean: return new(i_p) xs_booleanValue();
	case xs_decimal: return new(i_p) xs_decimalValue();
	case xs_integer: return new(i_p) xs_integerValue();
	case xs_long: return new(i_p) xs_longValue();
	case xs_int: return new(i_p) xs_intValue();
	case xs_short: return new(i_p) xs_shortValue();
	case xs_byte: return new(i_p) xs_byteValue();
	case xs_date: return new(i_p) xs_dateValue();
	case xs_dateTime: return new(i_p) xs_dateTimeValue();
	case xs_double: return new(i_p) xs_doubleValue();
	case xs_duration: return new(i_p) xs_durationValue();
	case xs_entitySeq: return new(i_p) xs_ENTITIESValue();
	case xs_entity: return new(i_p) xs_ENTITYValue();
	case xs_float: return new(i_p) xs_floatValue();
	case xs_gDay: return new(i_p) xs_gDayValue();
	case xs_gMonth: return new(i_p) xs_gMonthValue();
	case xs_gMonthDay: return new(i_p) xs_gMonthDayValue();
	case xs_gYear: return new(i_p) xs_gYearValue();
	case xs_gYearMonth: return new(i_p) xs_gYearMonthValue();
	case xs_hexBinary: return new(i_p) xs_hexBinaryValue();
	case xs_id: return new(i_p) xs_IDValue();
	case xs_idref: return new(i_p) xs_IDREFValue();
	case xs_idrefSeq: return new(i_p) xs_IDREFSValue();
	case xs_language: return new(i_p) xs_languageValue();
	case xs_ncName: return new(i_p) xs_NCNameValue();
	case xs_nmtoken: return new(i_p) xs_NMTOKENValue();
	case xs_nmtokenSeq: return new(i_p) xs_NMTOKENSValue();
	case xs_notation: return new(i_p) xs_NOTATIONValue();
	case xs_name: return new(i_p) xs_NameValue();
	case xs_negativeInteger: return new(i_p) xs_negativeIntegerValue();
	case xs_nonNegativeInteger: return new(i_p) xs_nonNegativeIntegerValue();
	case xs_nonPositiveInteger: return new(i_p) xs_nonPositiveIntegerValue();
	case xs_normalizedString: return new(i_p) xs_normalizedStringValue();
	case xs_positiveInteger: return new(i_p) xs_positiveIntegerValue();
	case xs_string: return new(i_p) xs_stringValue();
	case xs_time: return new(i_p) xs_timeValue();
	case xs_token: return new(i_p) xs_tokenValue();
	case xs_unsignedByte: return new(i_p) xs_unsignedByteValue();
	case xs_unsignedInt: return new(i_p) xs_unsignedIntValue();
	case xs_unsignedLong: return new(i_p) xs_unsignedLongValue();
	case xs_unsignedShort: return new(i_p) xs_unsignedShortValue();
	default: return NULL;
	}

}


} /* namespace xqp */

