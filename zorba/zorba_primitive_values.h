/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_primitive_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *	Author: John Cowan,Paul Pedersen
 */

#ifndef XQP_ZORBA_PRIMITIVE_VALUES_H
#define XQP_ZORBA_PRIMITIVE_VALUES_H

#include "../values/values.h"
#include "../values/xs_primitive_values.h"

#include <time.h>
#include <ctime>
#include <string>
#include <vector>

#include "zorba_values.h"
#include "../context/common.h"
#include "../types/representations.h"
#include "../types/sequence_type.h"
#include "../util/xqp_exception.h"

namespace xqp {

class binaryRep;
class dateTimeRep;
class numericRep;
class stringRep;
class uint32Rep;
class uint64Rep;

class zorba_anyURIValue : public zorba_atomic_value,
														public virtual xs_anyURIValue
{
protected:
	stringRep* rep;

public:
	~zorba_anyURIValue() {}
	zorba_anyURIValue() {}
	zorba_anyURIValue(const zorba_anyURIValue& val) : rep(val.rep) {}

public:
	std::string describe() const;
	sequence_type_t type() const { return xs_anyURI; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_base64BinaryValue : public zorba_atomic_value,
																	 public virtual xs_base64BinaryValue
{
protected:
	binaryRep* rep;

public:
	~zorba_base64BinaryValue() {}
	zorba_base64BinaryValue() {}
	zorba_base64BinaryValue(const zorba_base64BinaryValue& val) : rep(val.rep) {}

public:
	xqp_base64Binary val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_base64Binary; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_booleanValue : public zorba_atomic_value,
														 public virtual xs_booleanValue
{
protected:
	uint32Rep* rep;
	
public:
	~zorba_booleanValue() {}
	zorba_booleanValue() {}
	zorba_booleanValue(const zorba_booleanValue& val) : rep(val.rep) {}

public:
	bool val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_boolean; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_decimalValue : public zorba_atomic_value,
														 public virtual xs_decimalValue
{
protected:
	numericRep* rep;

public:
	~zorba_decimalValue() {}
	zorba_decimalValue() {}
	zorba_decimalValue(zorba_decimalValue const& val) : rep(val.rep) {}

public:
	xqp_decimal val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_decimal; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_integerValue : public zorba_atomic_value,
														 public virtual xs_integerValue
{
protected:
	numericRep* rep;

public:
	~zorba_integerValue() {}
	zorba_integerValue() {}
	zorba_integerValue(const zorba_integerValue& val) : rep(val.rep) {}

public:
	std::string describe() const;
	sequence_type_t type() const { return xs_integer; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_longValue : public zorba_atomic_value,
													 public virtual xs_longValue
{
protected:
	numericRep* rep;

public:
	~zorba_longValue() {}
	zorba_longValue() {}
	zorba_longValue(const zorba_longValue& val) : rep(val.rep) {}
	
private:

public:
	long val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_long; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_intValue : public zorba_atomic_value,
												 public virtual xs_intValue
{
protected:
	numericRep* rep;

public:
	~zorba_intValue() {}
	zorba_intValue() {}
	zorba_intValue(const zorba_intValue& val) : rep(val.rep) {}
	
private:

public:
	int val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_int; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_shortValue : public zorba_atomic_value,
													 public virtual xs_shortValue
{
protected:
	numericRep* rep;

public:
	~zorba_shortValue() {}
	zorba_shortValue() {}
	zorba_shortValue(zorba_shortValue& val) : rep(val.rep) {}

public:
	short val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_short; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_byteValue : public zorba_atomic_value,
													 public virtual xs_byteValue
{
protected:
	uint32Rep* rep;

public:
	~zorba_byteValue() {}
	zorba_byteValue() {}
	zorba_byteValue(const zorba_byteValue& val) : rep(val.rep) {}

public:
	unsigned char val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_byte; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_dateValue : public zorba_atomic_value,
													 public virtual xs_dateValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_dateValue() {}
	zorba_dateValue() {}
	zorba_dateValue(const zorba_dateValue& val) : rep(val.rep) {}

public:
	xqp_date val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_date; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_dateTimeValue : public zorba_atomic_value,
															 public virtual xs_dateValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_dateTimeValue() {}
	zorba_dateTimeValue() {}
	zorba_dateTimeValue(zorba_dateTimeValue& val) : rep(val.rep) {}

public:
	xqp_dateTime val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_dateTime; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_doubleValue : public zorba_atomic_value,
														 public virtual xs_doubleValue
{
protected:
	numericRep* rep;
	
public:
	~zorba_doubleValue() {}
	zorba_doubleValue() {}
	zorba_doubleValue(zorba_doubleValue& val) : rep(val.rep) {}
	
public:
	double val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_double; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_durationValue : public zorba_atomic_value,
															 public virtual xs_durationValue
{
protected:
	uint64Rep* rep;

public:
	~zorba_durationValue() {}
	zorba_durationValue() {}
	zorba_durationValue(const zorba_durationValue& val) : rep(val.rep) {}

public:
	xqp_duration val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_duration; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_ENTITIESValue : public zorba_atomic_value,
															 public virtual xs_ENTITIESValue
{
protected:
	stringRep* rep;	// "entity,entity,..."

public:
	~zorba_ENTITIESValue() {}
	zorba_ENTITIESValue() {}
	zorba_ENTITIESValue(const zorba_ENTITIESValue& val) : rep(val.rep) {}

public:
	std::vector<std::string> val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_entitySeq; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_ENTITYValue : public zorba_atomic_value,
														 public virtual xs_ENTITYValue
{
protected:
	stringRep* rep;

public:
	~zorba_ENTITYValue() {}
	zorba_ENTITYValue() {}
	zorba_ENTITYValue(const zorba_ENTITYValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_entity; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_floatValue : public zorba_atomic_value,
													 public virtual xs_floatValue
{
protected:
	numericRep* rep;

public:
	~zorba_floatValue() {}
	zorba_floatValue() {}
	zorba_floatValue(zorba_floatValue& val) : rep(val.rep) {}

public:
	float val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_float; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_gDayValue : public zorba_atomic_value,
													 public virtual xs_gDayValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_gDayValue() {}
	zorba_gDayValue() {}
	zorba_gDayValue(zorba_gDayValue& val) : rep(val.rep) {}

public:
	xqp_gDay val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_gDay; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_gMonthValue : public zorba_atomic_value,
														 public virtual xs_gMonthValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_gMonthValue() {}
	zorba_gMonthValue() {}
	zorba_gMonthValue(zorba_gMonthValue& val) : rep(val.rep) {}

public:
	xqp_gMonth val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_gMonth; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_gMonthDayValue : public zorba_atomic_value,
															 public virtual xs_gMonthDayValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_gMonthDayValue() {}
	zorba_gMonthDayValue() {}
	zorba_gMonthDayValue(const zorba_gMonthDayValue& val) : rep(val.rep) {}

public:
	xqp_gMonthDay val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_gMonthDay; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_gYearValue : public zorba_atomic_value,
													 public virtual xs_gYearValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_gYearValue() {}
	zorba_gYearValue() {}
	zorba_gYearValue(const zorba_gYearValue& val) : rep(val.rep) {}

public:
	xqp_gYear val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_gYear; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_gYearMonthValue : public zorba_atomic_value,
																 public virtual xs_gYearMonthValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_gYearMonthValue() {}
	zorba_gYearMonthValue() {}
	zorba_gYearMonthValue(const zorba_gYearMonthValue& val) : rep(val.rep) {}

public:
	xqp_gYearMonth val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_gYearMonth; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_hexBinaryValue : public zorba_atomic_value
{
protected:
	stringRep* rep;

public:
	~zorba_hexBinaryValue() {}
	zorba_hexBinaryValue() {}
	zorba_hexBinaryValue(const zorba_hexBinaryValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_hexBinary; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_IDValue : public zorba_atomic_value,
												 public virtual xs_IDValue
{
protected:
	stringRep* rep;

public:
	~zorba_IDValue() {}
	zorba_IDValue() {}
	zorba_IDValue(const zorba_IDValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_id; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_IDREFValue : public zorba_atomic_value,
													 public virtual xs_IDREFValue
{
protected:
	stringRep* rep;

public:
	~zorba_IDREFValue() {}
	zorba_IDREFValue() {}
	zorba_IDREFValue(const zorba_IDREFValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_idref; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_IDREFSValue : public zorba_atomic_value,
														 public virtual xs_IDREFSValue
{
protected:
	stringRep* rep;	// "IDREF,IDREF,..."

public:
	~zorba_IDREFSValue() {}
	zorba_IDREFSValue() {}
	zorba_IDREFSValue(const zorba_IDREFSValue& val) : rep(val.rep) {}

public:
	std::vector<std::string> val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_idrefSeq; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_languageValue : public zorba_atomic_value,
															 public virtual xs_languageValue
{
protected:
	stringRep* rep;

public:
	~zorba_languageValue() {}
	zorba_languageValue() {}
	zorba_languageValue(const zorba_languageValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_language; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_NCNameValue : public zorba_atomic_value,
														 public virtual xs_NCNameValue
{
protected:
	stringRep* rep;

public:
	~zorba_NCNameValue() {}
	zorba_NCNameValue() {}
	zorba_NCNameValue(const zorba_NCNameValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_ncName; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_NMTOKENValue : public zorba_atomic_value,
														 public virtual xs_NMTOKENValue
{
protected:
	stringRep* rep;

public:
	~zorba_NMTOKENValue() {}
	zorba_NMTOKENValue() {}
	zorba_NMTOKENValue(const zorba_NMTOKENValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_nmtoken; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_NMTOKENSValue : public zorba_atomic_value,
															 public virtual xs_NMTOKENSValue
{
protected:
	stringRep* rep;	// "token,token,..."

public:
	~zorba_NMTOKENSValue() {}
	zorba_NMTOKENSValue() {}
	zorba_NMTOKENSValue(const zorba_NMTOKENSValue& val) : rep(val.rep) {}

public:
	std::vector<std::string> val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_nmtokenSeq; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_NOTATIONValue : public zorba_atomic_value,
															 public virtual xs_NOTATIONValue
{
protected:
	stringRep* rep;

public:
	~zorba_NOTATIONValue() {}
	zorba_NOTATIONValue() {}
	zorba_NOTATIONValue(const zorba_NOTATIONValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_notation; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_NameValue : public zorba_atomic_value,
													 public virtual xs_NameValue
{
protected:
	stringRep* rep;

public:
	~zorba_NameValue() {}
	zorba_NameValue() {}
	zorba_NameValue(const zorba_NameValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_name; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_negativeIntegerValue : public zorba_atomic_value,
																		 public virtual xs_negativeIntegerValue
{
protected:
	numericRep* rep;

public:
	~zorba_negativeIntegerValue() {}
	zorba_negativeIntegerValue() {}
	zorba_negativeIntegerValue(const zorba_negativeIntegerValue& val) : rep(val.rep) {}

public:
	int val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_negativeInteger; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_nonNegativeIntegerValue : public zorba_atomic_value,
																				 public virtual xs_nonNegativeIntegerValue
{
protected:
	numericRep* rep;

public:
	~zorba_nonNegativeIntegerValue() {}
	zorba_nonNegativeIntegerValue() {}
	zorba_nonNegativeIntegerValue(const zorba_nonNegativeIntegerValue& val) : rep(val.rep) {}

public:
	unsigned int val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_nonNegativeInteger; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_nonPositiveIntegerValue : public zorba_atomic_value,
																				 public virtual xs_nonPositiveIntegerValue
{
protected:
	numericRep* rep;

public:
	~zorba_nonPositiveIntegerValue() {}
	zorba_nonPositiveIntegerValue() {}
	zorba_nonPositiveIntegerValue(const zorba_nonPositiveIntegerValue& val) : rep(val.rep) {}

public:
	int val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_nonPositiveInteger; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_normalizedStringValue : public zorba_atomic_value,
																			 public virtual xs_normalizedStringValue
{
protected:
	stringRep* rep;

public:
	~zorba_normalizedStringValue() {}
	zorba_normalizedStringValue() {}
	zorba_normalizedStringValue(const zorba_normalizedStringValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_normalizedString; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_positiveIntegerValue : public zorba_atomic_value,
																		 public virtual xs_positiveIntegerValue
{
protected:
	numericRep* rep;

public:
	~zorba_positiveIntegerValue() {}
	zorba_positiveIntegerValue() {}
	zorba_positiveIntegerValue(const zorba_positiveIntegerValue& val) : rep(val.rep) {}

public:
	unsigned int val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_positiveInteger; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_stringValue : public zorba_atomic_value,
														 public virtual xs_stringValue
{
protected:
	stringRep* rep;

public:
	~zorba_stringValue() {}
	zorba_stringValue() {}
	zorba_stringValue(const zorba_stringValue&);

public: 
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_string; }
	std::ostream& put(std::ostream&) const;

public:   // XQuery interface
  std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_timeValue : public zorba_atomic_value,
													 public virtual xs_timeValue
{
protected:
	dateTimeRep* rep;

public:
	~zorba_timeValue() {}
	zorba_timeValue() {}
	zorba_timeValue(const zorba_timeValue& val) : rep(val.rep) {}

public:
	xqp_time val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_time; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_tokenValue : public zorba_atomic_value,
													 public virtual xs_tokenValue
{
protected:
	stringRep* rep;

public:
	~zorba_tokenValue() {}
	zorba_tokenValue() {}
	zorba_tokenValue(const zorba_tokenValue& val) : rep(val.rep) {}

public:
	std::string val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_token; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_unsignedByteValue : public zorba_atomic_value,
																	 public virtual xs_unsignedByteValue
{
protected:
	uint32Rep* rep;

public:
	~zorba_unsignedByteValue() {}
	zorba_unsignedByteValue() {}
	zorba_unsignedByteValue(const zorba_unsignedByteValue& val) : rep(val.rep) {}

public:
	unsigned char val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_unsignedByte; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_unsignedIntValue : public zorba_atomic_value,
																 public virtual xs_unsignedIntValue
{
protected:
	numericRep* rep;

public:
	~zorba_unsignedIntValue() {}
	zorba_unsignedIntValue() {}
	zorba_unsignedIntValue(const zorba_unsignedIntValue& val) : rep(val.rep) {}

public:
	unsigned int val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_unsignedInt; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_unsignedLongValue : public zorba_atomic_value,
																	 public virtual xs_unsignedLongValue
{
protected:
	numericRep* rep;

public:
	~zorba_unsignedLongValue() {}
	zorba_unsignedLongValue() {}
	zorba_unsignedLongValue(const zorba_unsignedLongValue& val) : rep(val.rep) {}

public:
	unsigned long val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_unsignedLong; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class zorba_unsignedShortValue : public zorba_atomic_value,
																	 public virtual xs_unsignedShortValue
{
protected:
	numericRep* rep;

public:
	~zorba_unsignedShortValue() {}
	zorba_unsignedShortValue() {}
	zorba_unsignedShortValue(const zorba_unsignedShortValue& val) : rep(val.rep) {}

public:
	unsigned short val() const;
	std::string describe() const;
	sequence_type_t type() const { return xs_unsignedShort; }
	std::ostream& put(std::ostream&) const;

public:
	std::string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


}	/* namespace xqp */
#endif	/* XQP_ZORBA_PRIMITIVE_VALUES_H */
