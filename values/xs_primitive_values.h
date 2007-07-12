/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: xs_primitive_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *	Author: Paul Pedersen (pcp071098@yahoo.com)
 */

#ifndef XQP_XS_PRIMITIVE_VALUES_H
#define XQP_XS_PRIMITIVE_VALUES_H

#include "values.h"
#include "../types/representations.h"
#include "../types/sequence_type.h"

#include <string>
#include <vector>


namespace xqp {


class xs_anyURIValue : public atomic_value
{
public:
	virtual ~xs_anyURIValue() {}
	virtual std::string val() const = 0;

};


class xs_base64BinaryValue : public atomic_value
{
public:
	virtual ~xs_base64BinaryValue() {}
	virtual xqp_base64Binary val() const;

};


class xs_booleanValue : public atomic_value
{
public:
	virtual ~xs_booleanValue() {}
	virtual bool val() const = 0;

};


class xs_decimalValue : public atomic_value
{
public:
	virtual ~xs_decimalValue() {}
	virtual double val() const = 0;

};


class xs_integerValue : public atomic_value
{
public:
	virtual ~xs_integerValue() {}
	virtual int val() const = 0;

};


class xs_longValue : public atomic_value
{
public:
	virtual ~xs_longValue() {}
	virtual long val() const = 0;

};


class xs_intValue : public atomic_value
{
public:
	virtual ~xs_intValue() {}
	virtual int val() const = 0;

};


class xs_shortValue : public atomic_value
{
public:
	virtual ~xs_shortValue() {}
	virtual short val() const = 0;

};


class xs_byteValue : public atomic_value
{
public:
	virtual ~xs_byteValue() {}
	virtual unsigned char val() const = 0;

};


class xs_dateValue : public atomic_value
{
public:
	virtual ~xs_dateValue() {}
	virtual xqp_date val() const = 0;

};


class xs_dateTimeValue : public atomic_value
{
public:
	virtual ~xs_dateTimeValue() {}
	virtual xqp_dateTime val() const = 0;

};


class xs_doubleValue : public atomic_value
{
public:
	virtual ~xs_doubleValue() {}
	virtual double val() const = 0;

};


class xs_durationValue : public atomic_value
{
public:
	virtual ~xs_durationValue() {}
	virtual xqp_duration val() const = 0;

};


class xs_ENTITIESValue : public atomic_value
{
public:
	virtual ~xs_ENTITIESValue() {}
	virtual std::vector<std::string> val() const = 0;

};


class xs_ENTITYValue : public atomic_value
{
public:
	virtual ~xs_ENTITYValue() {}
	virtual std::string val() const = 0;

};


class xs_floatValue : public atomic_value
{
public:
	virtual ~xs_floatValue() {}
	virtual float val() const = 0;

};


class xs_gDayValue : public atomic_value
{
public:
	virtual ~xs_gDayValue() {}
	virtual xqp_gDay val() const = 0;

};


class xs_gMonthValue : public atomic_value
{
public:
	virtual ~xs_gMonthValue() {}
	virtual xqp_gMonth val() const = 0;

};


class xs_gMonthDayValue : public atomic_value
{
public:
	virtual ~xs_gMonthDayValue() {}
	virtual xqp_gMonthDay val() const = 0;

};


class xs_gYearValue : public atomic_value
{
public:
	virtual ~xs_gYearValue() {}
	virtual xqp_gYear val() const = 0;

};


class xs_gYearMonthValue : public atomic_value
{
public:
	virtual ~xs_gYearMonthValue() {}
	virtual xqp_gYearMonth val() const = 0;

};


class xs_hexBinaryValue : public atomic_value
{
public:
	virtual ~xs_hexBinaryValue() {}
	virtual xqp_hexBinary val() const = 0;

};


class xs_IDValue : public atomic_value
{
public:
	virtual ~xs_IDValue() {}
	virtual std::string id() const = 0;

};


class xs_IDREFValue : public atomic_value
{
public:
	virtual ~xs_IDREFValue() {}
	virtual std::string idref() const = 0;

};


class xs_IDREFSValue : public atomic_value
{
public:
	virtual ~xs_IDREFSValue() {}
	virtual std::vector<std::string> val() const = 0;

};


class xs_languageValue : public atomic_value
{
public:
	virtual ~xs_languageValue() {}
	virtual std::string val() const = 0;

};


class xs_NCNameValue : public atomic_value
{
public:
	virtual ~xs_NCNameValue() {}
	virtual std::string val() const = 0;

};


class xs_NMTOKENValue : public atomic_value
{
public:
	virtual ~xs_NMTOKENValue() {}
	virtual std::string val() const = 0;

};


class xs_NMTOKENSValue : public atomic_value
{
public:
	virtual ~xs_NMTOKENSValue() {}
	virtual std::vector<std::string> val() const = 0;

};


class xs_NOTATIONValue : public atomic_value
{
public:
	virtual ~xs_NOTATIONValue() {}
	virtual std::string val() const = 0;

};


class xs_NameValue : public atomic_value
{
public:
	virtual ~xs_NameValue() {}
	virtual std::string val() const = 0;

};


class xs_negativeIntegerValue : public atomic_value
{
public:
	virtual ~xs_negativeIntegerValue() {}

public:
	virtual int val() const = 0;

};


class xs_nonNegativeIntegerValue : public atomic_value
{
public:
	virtual ~xs_nonNegativeIntegerValue() {}
	virtual unsigned int val() const = 0;

};


class xs_nonPositiveIntegerValue : public atomic_value
{
public:
	virtual ~xs_nonPositiveIntegerValue() {}
	virtual int val() const = 0;

};


class xs_normalizedStringValue : public atomic_value
{
public:
	virtual ~xs_normalizedStringValue() {}
	virtual std::string val() const = 0;

};


class xs_positiveIntegerValue : public atomic_value
{
public:
	virtual ~xs_positiveIntegerValue() {}
	virtual unsigned int val() const = 0;

};


class xs_stringValue : public atomic_value
{
public:
	virtual ~xs_stringValue() {}
	virtual std::string val() const = 0;

};


class xs_timeValue : public atomic_value
{
public:
	virtual ~xs_timeValue() {}
	virtual xqp_time val() const = 0;

};


class xs_tokenValue : public atomic_value
{
public:
	virtual ~xs_tokenValue() {}
	virtual std::string val() const = 0;

};


class xs_unsignedByteValue : public atomic_value
{
public:
	virtual ~xs_unsignedByteValue() {}
	virtual unsigned char val() const = 0;

};


class xs_unsignedIntValue : public atomic_value
{
public:
	virtual ~xs_unsignedIntValue() {}
	virtual unsigned int val() const = 0;

};


class xs_unsignedLongValue : public atomic_value
{
public:
	virtual ~xs_unsignedLongValue() {}
	virtual unsigned long val() const = 0;

};


class xs_unsignedShortValue : public atomic_value
{
public:
	virtual ~xs_unsignedShortValue() {}
	virtual unsigned short val() const = 0;

};


}	/* namespace xqp */
#endif	/* XQP_XS_PRIMITIVE_VALUES_H */
