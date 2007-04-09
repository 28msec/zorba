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
		const std::string& localname);

	virtual xs_anyURIValue* make_xs_anyURIValue() = 0;
	virtual xs_base64BinaryValue* make_xs_base64BinaryValue() = 0;
	virtual xs_booleanValue* make_xs_booleanValue(bool) = 0;
	virtual xs_decimalValue* make_xs_decimalValue() = 0;
	virtual xs_integerValue* make_xs_integerValue(int) = 0;
	virtual xs_longValue* make_xs_longValue(long) = 0;
	virtual xs_intValue* make_xs_intValue(int) = 0;
	virtual xs_shortValue* make_xs_shortValue(short) = 0;
	virtual xs_byteValue* make_xs_byteValue(char) = 0;
	virtual xs_dateValue* make_xs_dateValue() = 0;
	virtual xs_dateTimeValue* make_xs_dateTimeValue() = 0;
	virtual xs_doubleValue* make_xs_doubleValue(double) = 0;
	virtual xs_durationValue* make_xs_durationValue() = 0;
	virtual xs_ENTITIESValue* make_xs_ENTITIESValue() = 0;
	virtual xs_ENTITYValue* make_xs_ENTITYValue() = 0;
	virtual xs_floatValue* make_xs_floatValue(float) = 0;
	virtual xs_gDayValue* make_xs_gDayValue() = 0;
	virtual xs_gMonthValue* make_xs_gMonthValue() = 0;
	virtual xs_gMonthDayValue* make_xs_gMonthDayValue() = 0;
	virtual xs_gYearValue* make_xs_gYearValue() = 0;
	virtual xs_gYearMonthValue* make_xs_gYearMonthValue() = 0;
	virtual xs_hexBinaryValue* make_xs_hexBinaryValue() = 0;
	virtual xs_IDValue* make_xs_IDValue() = 0;
	virtual xs_IDREFValue* make_xs_IDREFValue() = 0;
	virtual xs_IDREFSValue* make_xs_IDREFSValue() = 0;
	virtual xs_languageValue* make_xs_languageValue(const std::string&) = 0;
	virtual xs_NCNameValue* make_xs_NCNameValue(const std::string&) = 0;
	virtual xs_NMTOKENValue* make_xs_NMTOKENValue(const std::string&) = 0;
	virtual xs_NMTOKENSValue* make_xs_NMTOKENSValue(const std::string&) = 0;
	virtual xs_NOTATIONValue* make_xs_NOTATIONValue(const std::string&) = 0;
	virtual xs_NameValue* make_xs_NameValue(const std::string&) = 0;
	virtual xs_negativeIntegerValue* make_xs_negativeIntegerValue(int) = 0;
	virtual xs_nonNegativeIntegerValue* make_xs_nonNegativeIntegerValue(int) = 0;
	virtual xs_nonPositiveIntegerValue* make_xs_nonPositiveIntegerValue(int) = 0;
	virtual xs_normalizedStringValue* make_xs_normalizedStringValue(const std::string&) = 0;
	virtual xs_positiveIntegerValue* make_xs_positiveIntegerValue(unsigned int) = 0;
	virtual xs_stringValue* make_xs_stringValue(const std::string&) = 0;
	virtual uri_value* make_uri_value(const std::string&) = 0;
	virtual xs_timeValue* make_xs_timeValue() = 0;
	virtual xs_tokenValue* make_xs_tokenValue(const std::string&) = 0;
	virtual xs_unsignedByteValue* make_xs_unsignedByteValue(unsigned char) = 0;
	virtual xs_unsignedIntValue* make_xs_unsignedIntValue(unsigned int) = 0;
	virtual xs_unsignedLongValue* make_xs_unsignedLongValue(unsigned long) = 0;
	virtual xs_unsignedShortValue* make_xs_unsignedShortValue(uint16_t) = 0;

public:
	virtual ~abstract_value_factory() {}
};


} /* namespace xqp */
#endif /* XQP_VALUE_FACTORY_H */

