/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: value_factory.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_VALUE_FACTORY_H
#define XQP_VALUE_FACTORY_H

#include "abstract_value_factory.h"
#include "xs_primitive_values.h"
#include "../context/common.h"
#include "../types/sequence_type.h"

namespace xqp {

class atomic_value;

class value_factory
{
protected:
	itemstore* istore;

	//debugging
	uint32_t buf[1<<16];
	uint32_t eos;

public:
	value_factory() : istore(NULL), eos(0) {}
	virtual ~value_factory() {}

public:
	qname_value* make_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

	uri_value* make_uri(
		const std::string&);

	xs_anyURIValue* make_xs_anyURI();
	xs_base64BinaryValue* make_xs_base64Binary();
	xs_booleanValue* make_xs_boolean(bool);
	xs_decimalValue* make_xs_decimal();
	xs_integerValue* make_xs_integer(int);
	xs_longValue* make_xs_long(long);
	xs_intValue* make_xs_int(int);
	xs_shortValue* make_xs_short(short);
	xs_byteValue* make_xs_byte(char);
	xs_dateValue* make_xs_date();
	xs_dateTimeValue* make_xs_dateTime();
	xs_doubleValue* make_xs_double(double);
	xs_durationValue* make_xs_duration();
	xs_ENTITIESValue* make_xs_ENTITIES();
	xs_ENTITYValue* make_xs_ENTITY();
	xs_floatValue* make_xs_float(float);
	xs_gDayValue* make_xs_gDay();
	xs_gMonthValue* make_xs_gMonth();
	xs_gMonthDayValue* make_xs_gMonthDay();
	xs_gYearValue* make_xs_gYear();
	xs_gYearMonthValue* make_xs_gYearMonth();
	xs_hexBinaryValue* make_xs_hexBinary();
	xs_IDValue* make_xs_ID();
	xs_IDREFValue* make_xs_IDREF();
	xs_IDREFSValue* make_xs_IDREFS();
	xs_languageValue* make_xs_language(const string&);
	xs_NCNameValue* make_xs_NCName(const string&);
	xs_NMTOKENValue* make_xs_NMTOKEN(const string&);
	xs_NMTOKENSValue* make_xs_NMTOKENS(const string&);
	xs_NOTATIONValue* make_xs_NOTATION(const string&);
	xs_NameValue* make_xs_Name(const string&);
	xs_negativeIntegerValue* make_xs_negativeInteger(int);
	xs_nonNegativeIntegerValue* make_xs_nonNegativeInteger(int);
	xs_nonPositiveIntegerValue* make_xs_nonPositiveInteger(int);
	xs_normalizedStringValue* make_xs_normalizedString(const string&);
	xs_positiveIntegerValue* make_xs_positiveInteger(unsigned int);
	xs_stringValue* make_xs_string(const string&);
	xs_timeValue* make_xs_time();
	xs_tokenValue* make_xs_token(const string&);
	xs_unsignedByteValue* make_xs_unsignedByte(unsigned char);
	xs_unsignedIntValue* make_xs_unsignedInt(unsigned int);
	xs_unsignedLongValue* make_xs_unsignedLong(unsigned long);
	xs_unsignedShortValue* make_xs_unsignedShort(uint16_t);

	static atomic_value* cast_as(iterator_t,sequence_type_t);

};


} /* namespace xqp */
#endif /* XQP_VALUE_FACTORY_H */

