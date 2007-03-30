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

#include "xs_primitive_values.h"

namespace xqp {

class value_factory : public abstract_value_factory
{
protected:
	itemstore& istore;

public:
	value_factort();
	~value_factort();

public:
	qname_value* make_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);
	xs_anyURIValue* make_xs_anyURIValue();
	xs_base64BinaryValue* make_xs_base64BinaryValue();
	xs_booleanValue* make_xs_booleanValue(bool);
	xs_decimalValue* make_xs_decimalValue();
	xs_integerValue* make_xs_integerValue(int);
	xs_longValue* make_xs_longValue(long);
	xs_intValue* make_xs_intValue(int);
	xs_shortValue* make_xs_shortValue(short);
	xs_byteValue* make_xs_byteValue(char);
	xs_dateValue* make_xs_dateValue();
	xs_dateTimeValue* make_xs_dateTimeValue();
	xs_doubleValue* make_xs_doubleValue(double);
	xs_durationValue* make_xs_durationValue();
	xs_ENTITIESValue* make_xs_ENTITIESValue();
	xs_ENTITYValue* make_xs_ENTITYValue();
	xs_floatValue* make_xs_floatValue(float);
	xs_gDayValue* make_xs_gDayValue();
	xs_gMonthValue* make_xs_gMonthValue();
	xs_gMonthDayValue* make_xs_gMonthDayValue();
	xs_gYearValue* make_xs_gYearValue();
	xs_gYearMonthValue* make_xs_gYearMonthValue();
	xs_hexBinaryValue* make_xs_hexBinaryValue();
	xs_IDValue* make_xs_IDValue();
	xs_IDREFValue* make_xs_IDREFValue();
	xs_IDREFSValue* make_xs_IDREFSValue();
	xs_languageValue* make_xs_languageValue(const string&);
	xs_NCNameValue* make_xs_NCNameValue(const string&);
	xs_NMTOKENValue* make_xs_NMTOKENValue(const string&);
	xs_NMTOKENSValue* make_xs_NMTOKENSValue(const string&);
	xs_NOTATIONValue* make_xs_NOTATIONValue(const string&);
	xs_NameValue* make_xs_NameValue(const string&);
	xs_negativeIntegerValue* make_xs_negativeIntegerValue();
	xs_nonNegativeIntegerValue* make_xs_nonNegativeIntegerValue();
	xs_nonPositiveIntegerValue* make_xs_nonPositiveIntegerValue();
	xs_normalizedStringValue* make_xs_normalizedStringValue(const string&);
	xs_positiveIntegerValue* make_xs_positiveIntegerValue(unsigned int);
	xs_stringValue* make_xs_stringValue(const string&);
	uri_value* make_uri_value(const string&);
	xs_timeValue* make_xs_timeValue();
	xs_tokenValue* make_xs_tokenValue(const string&);
	xs_unsignedByteValue* make_xs_unsignedByteValue(unsigned char);
	xs_unsignedIntValue* make_xs_unsignedIntValue(unsigned int);
	xs_unsignedLongValue* make_xs_unsignedLongValue(unsigned long);
	xs_unsignedShortValue* make_xs_unsignedShortValue(uint16_t);

} /* namespace xqp */
#endif /* XQP_VALUE_FACTORY_H */

