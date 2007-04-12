/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: abstract_value_factory.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_ABSTRACT_VALUE_FACTORY_H
#define XQP_ABSTRACT_VALUE_FACTORY_H

#include "qname_value.h"
#include "xs_primitive_values.h"
#include "../util/rchandle.h"
#include <string>

namespace xqp {

class abstract_value_factory : public rcobject
{
public:
	virtual qname_value* make_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname) = 0;

	virtual uri_value* make_uri(
		const std::string&) = 0;

	virtual xs_anyURIValue* make_xs_anyURI() = 0;
	virtual xs_base64BinaryValue* make_xs_base64Binary() = 0;
	virtual xs_booleanValue* make_xs_boolean(bool) = 0;
	virtual xs_decimalValue* make_xs_decimal() = 0;
	virtual xs_integerValue* make_xs_integer(int) = 0;
	virtual xs_longValue* make_xs_long(long) = 0;
	virtual xs_intValue* make_xs_int(int) = 0;
	virtual xs_shortValue* make_xs_short(short) = 0;
	virtual xs_byteValue* make_xs_byte(char) = 0;
	virtual xs_dateValue* make_xs_date() = 0;
	virtual xs_dateTimeValue* make_xs_dateTime() = 0;
	virtual xs_doubleValue* make_xs_double(double) = 0;
	virtual xs_durationValue* make_xs_duration() = 0;
	virtual xs_ENTITIESValue* make_xs_ENTITIES() = 0;
	virtual xs_ENTITYValue* make_xs_ENTITY() = 0;
	virtual xs_floatValue* make_xs_float(float) = 0;
	virtual xs_gDayValue* make_xs_gDay() = 0;
	virtual xs_gMonthValue* make_xs_gMonth() = 0;
	virtual xs_gMonthDayValue* make_xs_gMonthDay() = 0;
	virtual xs_gYearValue* make_xs_gYear() = 0;
	virtual xs_gYearMonthValue* make_xs_gYearMonth() = 0;
	virtual xs_hexBinaryValue* make_xs_hexBinary() = 0;
	virtual xs_IDValue* make_xs_ID() = 0;
	virtual xs_IDREFValue* make_xs_IDREF() = 0;
	virtual xs_IDREFSValue* make_xs_IDREFS() = 0;
	virtual xs_languageValue* make_xs_language(const std::string&) = 0;
	virtual xs_NCNameValue* make_xs_NCName(const std::string&) = 0;
	virtual xs_NMTOKENValue* make_xs_NMTOKEN(const std::string&) = 0;
	virtual xs_NMTOKENSValue* make_xs_NMTOKENS(const std::string&) = 0;
	virtual xs_NOTATIONValue* make_xs_NOTATION(const std::string&) = 0;
	virtual xs_NameValue* make_xs_Name(const std::string&) = 0;
	virtual xs_negativeIntegerValue* make_xs_negativeInteger(int) = 0;
	virtual xs_nonNegativeIntegerValue* make_xs_nonNegativeInteger(int) = 0;
	virtual xs_nonPositiveIntegerValue* make_xs_nonPositiveInteger(int) = 0;
	virtual xs_normalizedStringValue* make_xs_normalizedString(const std::string&) = 0;
	virtual xs_positiveIntegerValue* make_xs_positiveInteger(unsigned int) = 0;
	virtual xs_stringValue* make_xs_string(const std::string&) = 0;
	virtual xs_timeValue* make_xs_time() = 0;
	virtual xs_tokenValue* make_xs_token(const std::string&) = 0;
	virtual xs_unsignedByteValue* make_xs_unsignedByte(unsigned char) = 0;
	virtual xs_unsignedIntValue* make_xs_unsignedInt(unsigned int) = 0;
	virtual xs_unsignedLongValue* make_xs_unsignedLong(unsigned long) = 0;
	virtual xs_unsignedShortValue* make_xs_unsignedShort(uint16_t) = 0;

public:
	virtual ~abstract_value_factory() {}
};


} /* namespace xqp */
#endif /* XQP_VALUE_FACTORY_H */

