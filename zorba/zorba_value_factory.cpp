/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_value_factory.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "zorba_value_factory.h"
#include "zorba_qname.h"

using namespace std;
namespace xqp {

rchandle<atomic_value> zorba_value_factory::make_qname(
	const string& uri,
	const string& prefix,
	const string& localname)
{  
	qname* result = new zorba_qname(uri,prefix,localname);
	return dynamic_cast<atomic_value*>(result);
}

rchandle<atomic_value> zorba_value_factory::make_xs_anyURI(
  const string& uri)
{
	return new stringValue(xs_anyURI,uri);
}

rchandle<atomic_value> zorba_value_factory::make_xs_base64Binary(
	const void* v, uint32_t length)
{
	return new binaryValue(xs_base64Binary,v,length);
}

rchandle<atomic_value> zorba_value_factory::make_xs_boolean(
  bool b)
{
	return new booleanValue(b);
}

rchandle<atomic_value> zorba_value_factory::make_xs_decimal(
	long double v)
{
	return new numericValue(xs_decimal, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_integer(
  int v)
{
	return new numericValue(xs_integer, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_long(
  long v)
{
	return new numericValue(xs_long, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_int(
  int v)
{
  return new numericValue(xs_int,v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_short(
  short v)
{
	return new numericValue(xs_short, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_byte(
  char v)
{
	return new numericValue(xs_byte, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_date(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_dateTime(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_double(
  double v)
{
	return new numericValue(xs_double, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_duration(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_ENTITIES(
	const string& v)
{
	return new stringValue(xs_entitySeq, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_ENTITY(
	const string& v)
{
	return new stringValue(xs_entity, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_float(
  float v)
{
	return new numericValue(xs_float, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_gDay(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_gMonth(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_gMonthDay(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_gYear()
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_gYearMonth(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_hexBinary(
	const void* v, uint32_t n)
{
	return new binaryValue(xs_hexBinary,v,n);
}

rchandle<atomic_value> zorba_value_factory::make_xs_ID(
	const string& v)
{
	return new stringValue(xs_id, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_IDREF(
	const string& v)
{
	return new stringValue(xs_idref, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_IDREFS(
	const string& v)
{
	return new stringValue(xs_idrefSeq, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_language(
  const string& v)
{
	return new stringValue(xs_language, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_NCName(
  const string& v)
{
	return new stringValue(xs_ncName, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_NMTOKEN(
  const string& v)
{
	return new stringValue(xs_nmtoken, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_NMTOKENS(
  const string& v)
{
	return new stringValue(xs_nmtokenSeq, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_NOTATION(
  const string& v)
{
	return new stringValue(xs_notation, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_Name(
  const string& v)
{
	return new stringValue(xs_name, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_negativeInteger(
  int v)
{
	return new numericValue(xs_negativeInteger, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_nonNegativeInteger(
  int v)
{
	return new numericValue(xs_nonNegativeInteger, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_nonPositiveInteger(
  int v)
{
	return new numericValue(xs_nonPositiveInteger, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_normalizedString(
  const string& v)
{
	return new stringValue(xs_normalizedString, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_positiveInteger(
  unsigned int v)
{
	return new numericValue(xs_positiveInteger, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_string(
  const string& v)
{
	return new stringValue(xs_string,v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_time(
	)
{
	return NULL;
}

rchandle<atomic_value> zorba_value_factory::make_xs_token(
  const string& v)
{
	return new stringValue(xs_token,v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_unsignedByte(
  unsigned char v)
{
	return new numericValue(xs_unsignedByte, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_unsignedInt(
  unsigned int v)
{
	return new numericValue(xs_unsignedInt, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_unsignedLong(
  unsigned long v)
{
	return new numericValue(xs_unsignedLong, v);
}

rchandle<atomic_value> zorba_value_factory::make_xs_unsignedShort(
  uint16_t v)
{
	return new numericValue(xs_unsignedShort, v);
}


/*
atomic_value* zorba_value_factory::cast_as(
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
*/


} /* namespace xqp */

