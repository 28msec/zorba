/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_valuess.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen (pcp071098@yahoo.com)
 */

#ifndef XQP_XS_PRIMITIVE_VALUES_H
#define XQP_XS_PRIMITIVE_VALUES_H

#include "values.h"

#include <time.h>
#include <ctime>
#include <string>
#include <vector>

#include "../types/xs_primitive_types.h"
#include "../store/xml_ostream.h"
#include "../store/xml_istream.h"
#include "../util/xqp_exception.h"


namespace xqp {

class xs_anyURI_value : public atomic_value
{
protected:
	xqp_anyURI value;

public:
	xs_anyURI_value(xqp_anyURI const& _value) : value(_value) {}
	xs_anyURI_value() {}
	~xs_anyURI_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);
    
	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_base64Binary_value : public atomic_value
{
protected:
	xqp_base64Binary value;

public:
	xs_base64Binary_value(xqp_base64Binary const& _value) : value(_value) {}
	xs_base64Binary_value() {}
	~xs_base64Binary_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_boolean_value : public atomic_value
{
protected:
	xqp_boolean value;
	
public:
	xs_boolean_value(xqp_boolean const& _value) : value(_value) {}
	xs_boolean_value() {}
	~xs_boolean_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);
    
	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);
	rchandle<xqp_iterator> get_value() const;

};



class xs_decimal_value : public atomic_value
{
protected:
	xqp_decimal value;

public:
	xs_decimal_value(xqp_decimal const& _value) : value(_value) {}
	xs_decimal_value() {}
	~xs_decimal_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_integer_value : public atomic_value
{
protected:
	xqp_integer value;

public:
	xs_integer_value(xqp_integer const& _value) : value(_value) {}
	xs_integer_value() {}
	~xs_integer_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_long_value : public atomic_value
{
protected:
	xqp_long value;

public:
	xs_long_value(xqp_long const& _value) : value(_value) {}
	xs_long_value() {}
	~xs_long_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_int_value : public atomic_value
{
protected:
	xqp_int value;

public:
	xs_int_value(xqp_int const& _value) : value(_value) {}
	xs_int_value() {}
	~xs_int_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_short_value : public atomic_value
{
protected:
	xqp_short value;

public:
	xs_short_value(xqp_short const& _value) : value(_value) {}
	xs_short_value() {}
	~xs_short_value() {}

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_byte_value : public atomic_value
{
protected:
	xqp_byte value;

public:
	xs_byte(xqp_byte const& _value) : value(_value) {}
	xs_byte() {}
	~xs_byte() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_date_value : public atomic_value
{
protected:
	xqp_date value;

public:
	xs_date_value(xqp_date const& _value) : value(_value) {}
	xs_date_value() {}
	~xs_date_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_dateTime_value : public atomic_value
{
protected:
	xqp_dateTime value;

public:
	xs_dateTime_value(xqp_dateTime const& _value) : value(_value) {}
	xs_dateTime_value() {}
	~xs_dateTime_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_double_value : public atomic_value
{
protected:
	xqp_double value;

public:
	xs_double_value(xqp_double const& _value) : value(_value) {}
	xs_double_value() {}
	~xs_double_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_duration_value : public atomic_value
{
protected:
	xqp_duration value;

public:
	xs_duration_value(xqp_duration const& _value) : value(_value) {}
	xs_duration_value() {}
	~xs_duration_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_ENTITIES_value : public atomic_value
{
protected:
	xqp_ENTITIES value;

public:
	xs_ENTITIES_value(xqp_ENTITIES const& _value) : value(_value) {}
	xs_ENTITIES_value() {}
	~xs_ENTITIES_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_ENTITY_value : public atomic_value
{
protected:
	xqp_ENTITY value;

public:
	xs_ENTITY_value(xqp_ENTITY const& _value) : value(_value) {}
	xs_ENTITY_value() {}
	~xs_ENTITY_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_float_value : public atomic_value
{
protected:
	xqp_float value;

public:
	xs_float_value(xqp_float const& _value) : value(_value) {}
	xs_float_value() {}
	~xs_float_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_gDay_value : public atomic_value
{
protected:
	xqp_gDay value;

public:
	xs_gDay_value(xqp_gDay const& _value) : value(_value) {}
	xs_gDay_value() {}
	~xs_gDay_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_gMonth_value : public atomic_value
{
protected:
	xqp_gMonth value;

public:
	xs_gMonth_value(xqp_gMonth const& _value) : value(_value) {}
	xs_gMonth_value() {}
	~xs_gMonth_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_gMonthDay_value : public atomic_value
{
protected:
	xqp_gMonthDay value;

public:
	xs_gMonthDay_value(xqp_gMonthDay const& _value) : value(_value) {}
	xs_gMonthDay_value() {}
	~xs_gMonthDay_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_gYear_value : public atomic_value
{
protected:
	xqp_gYear value;

public:
	xs_gYear_value(xqp_gYear const& _value) : value(_value) {}
	xs_gYear_value() {}
	~xs_gYear_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_gYearMonth_value : public atomic_value
{
protected:
	xqp_gYearMonth value;

public:
	xs_gYearMonth_value(xqp_gYearMonth const& _value) : value(_value) {}
	xs_gYearMonth_value() {}
	~xs_gYearMonth_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_hexBinary_value : public atomic_value
{
protected:
	xqp_hexBinary value;

public:
	xs_hexBinary_value(xqp_hexBinary const& _value) : value(_value) {}
	xs_hexBinary_value() {}
	~xs_hexBinary_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_ID_value : public atomic_value
{
protected:
	xqp_id value;

public:
	xs_ID_value(xqp_id const& _value) : value(_value) {}
	xs_ID_value() {}
	~xs_ID_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_IDREF_value : public atomic_value
{
protected:
	xqp_IDREF value;

public:
	xs_IDREF_value(xqp_IDREF const& _value) : value(_value) {}
	xs_IDREF_value() {}
	~xs_IDREF_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_IDREFS_value : public atomic_value
{
protected:
	xqp_IDREFS value;

public:
	xs_IDREFS_value(xqp_IDREFS const& _value) : value(_value) {}
	xs_IDREFS_value() {}
	~xs_IDREFS_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_language_value : public atomic_value
{
protected:
	xqp_language value;

public:
	xs_language_value(xqp_language const& _value) : value(_value) {}
	xs_language_value() {}
	~xs_language_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_NCName_value : public atomic_value
{
protected:
	xqp_NCName value;

public:
	xs_NCName_value(xqp_NCName const& _value) : value(_value) {}
	xs_NCName_value() {}
	~xs_NCName_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_NMTOKEN_value : public atomic_value
{
protected:
	xqp_NMTOKEN value;

public:
	xs_NMTOKEN_value(xqp_NMTOKEN const& _value) : value(_value) {}
	xs_NMTOKEN_value() {}
	~xs_NMTOKEN_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_NMTOKENS_value : public atomic_value
{
protected:
	xqp_NMTOKENS value;

public:
	xs_NMTOKENS_value(xqp_NMTOKENS const& _value) : value(_value) {}
	xs_NMTOKENS_value() {}
	~xs_NMTOKENS_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_NOTATION_value : public atomic_value
{
protected:
	xqp_NOTATION value;

public:
	xs_NOTATION_value(xqp_NOTATION const& _value) : value(_value) {}
	xs_NOTATION_value() {}
	~xs_NOTATION_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_Name_value : public atomic_value
{
protected:
	xqp_Name value;

public:
	xs_Name_value(xqp_name const& _value) : value(_value) {}
	xs_Name_value() {}
	~xs_Name_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_negativeInteger_value : public atomic_value
{
protected:
	xqp_negativeInteger value;

public:
	xs_negativeInteger_value(xqp_negativeInteger const& _value) : value(_value) {}
	xs_negativeInteger_value() {}
	~xs_negativeInteger_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class non_negativeInteger_value : public atomic_value
{
protected:
	xqp_nonNegativeInteger value;

public:
	xs_nonNegativeInteger_value(xqp_nonNegativeInteger const& _value) : value(_value) {}
	xs_nonNegativeInteger_value() {}
	~xs_nonNegativeInteger_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_nonPositiveInteger_value : public atomic_value
{
protected:
	xqp_nonPositiveInteger value;

public:
	xs_nonPositiveInteger_value(xqp_nonPositiveInteger const& _value) : value(_value) {}
	xs_nonPositiveInteger_value() {}
	~xs_nonPositiveInteger_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_normalizedString_value : public atomic_value
{
protected:
	xqp_normalizedString value;

public:
	xs_normalizedString_value(xqp_normalizedString const& _value) : value(_value) {}
	xs_normalizedString_value() {}
	~xs_normalizedString_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_positiveInteger_value : public atomic_value
{
protected:
	xqp_positiveInteger value;

public:
	xs_positiveInteger_value(xqp_positiveInteger const& _value) : value(_value) {}
	xs_positiveInteger_value() {}
	~xs_positiveInteger_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_string_value : public atomic_value
{
protected:
	xqp_string value;

public:
	xs_string_value(xqp_string const& _value) : value(_value) {}
	xs_string_value() {}
	~xs_string_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_time_value : public atomic_value
{
protected:
	xqp_time value;

public:
	xs_time_value(xqp_time const& _value) : value(_value) {}
	xs_time_value() {}
	~xs_time_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_token_value : public atomic_value
{
protected:
	xqp_token value;

public:
	xs_token_value(xqp_token const& _value) : value(_value) {}
	xs_token_value() {}
	~xs_token_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_unsignedByte_value : public atomic_value
{
protected:
	xqp_unsignedByte value;

public:
	xs_unsignedByte_value(xqp_unsignedByte const& _value) : value(_value) {}
	xs_unsignedByte_value() {}
	~xs_unsignedByte_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_unsignedInt_value : public atomic_value
{
protected:
	xqp_unsignedInt value;

public:
	xs_unsignedInt_value(xqp_unsignedInt const& _value) : value(_value) {}
	xs_unsignedInt_value() {}
	~xs_unsignedInt_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_unsignedLong_value : public atomic_value
{
protected:
	xqp_unsignedLong value;

public:
	xs_unsignedLong_value(xqp_unsignedLong const& _value) : value(_value) {}
	xs_unsignedLong_value() {}
	~xs_unsignedLong_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};



class xs_unsignedShort_value : public atomic_value
{
protected:
	xqp_unsignedShort value;

public:
	xs_unsignedShort_value(xqp_unsignedShort const& _value) : value(_value) {}
	xs_unsignedShort_value() {}
	~xs_unsignedShort_value() {}

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe() const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	ostream& operator<<(ostream&);

};


}	/* namespace xqp */
#endif	/* XQP_XS_PRIMITIVE_VALUES_H */
