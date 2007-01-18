/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
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
	xqp_anyURI val;

public:
	xs_anyURI_value(xqp_anyURI const&);
	xs_anyURI_value();
	~xs_anyURI_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);
    
	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_base64Binary_value : public atomic_value
{
protected:
	xqp_base64Binary val;

public:
	xs_base64Binary_value(xqp_base64Binary const&);
	xs_base64Binary_value();
	~xs_base64Binary_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_boolean_value : public atomic_value
{
protected:
	xqp_boolean val;
	
public:
	xs_boolean_value(xqp_boolean const&);
	xs_boolean_value();
	~xs_boolean_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);
    
	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_decimal_value : public atomic_value
{
protected:
	xqp_decimal val;

public:
	xs_decimal_value(xqp_decimal const&);
	xs_decimal_value();
	~xs_decimal_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_integer_value : public atomic_value
{
protected:
	xqp_integer val;

public:
	xs_integer_value(xqp_integer const&);
	xs_integer_value();
	~xs_integer_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_long_value : public atomic_value
{
protected:
	xqp_long val;

public:
	xs_long_value(xqp_long const&);
	xs_long_value();
	~xs_long_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_int_value : public atomic_value
{
protected:
	xqp_int val;

public:
	xs_int_value(xqp_int const&);
	xs_int_value();
	~xs_int_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_short_value : public atomic_value
{
protected:
	xqp_short val;

public:
	xs_short_value(xqp_short const&);
	xs_short_value();
	~xs_short_value();

public:
	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_byte_value : public atomic_value
{
protected:
	xqp_byte val;

public:
	xs_byte_value(xqp_byte const&);
	xs_byte_value();
	~xs_byte_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_date_value : public atomic_value
{
protected:
	xqp_date val;

public:
	xs_date_value(xqp_date const&);
	xs_date_value();
	~xs_date_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_dateTime_value : public atomic_value
{
protected:
	xqp_dateTime val;

public:
	xs_dateTime_value(xqp_dateTime const&);
	xs_dateTime_value();
	~xs_dateTime_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_double_value : public atomic_value
{
protected:
	xqp_double val;

public:
	xs_double_value(xqp_double const&);
	xs_double_value();
	~xs_double_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_duration_value : public atomic_value
{
protected:
	xqp_duration val;

public:
	xs_duration_value(xqp_duration const&);
	xs_duration_value();
	~xs_duration_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_ENTITIES_value : public atomic_value
{
protected:
	xqp_ENTITIES val;

public:
	xs_ENTITIES_value(xqp_ENTITIES const&);
	xs_ENTITIES_value();
	~xs_ENTITIES_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_ENTITY_value : public atomic_value
{
protected:
	xqp_ENTITY val;

public:
	xs_ENTITY_value(xqp_ENTITY const&);
	xs_ENTITY_value();
	~xs_ENTITY_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_float_value : public atomic_value
{
protected:
	xqp_float val;

public:
	xs_float_value(xqp_float const&);
	xs_float_value();
	~xs_float_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_gDay_value : public atomic_value
{
protected:
	xqp_gDay val;

public:
	xs_gDay_value(xqp_gDay const&);
	xs_gDay_value();
	~xs_gDay_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_gMonth_value : public atomic_value
{
protected:
	xqp_gMonth val;

public:
	xs_gMonth_value(xqp_gMonth const&);
	xs_gMonth_value();
	~xs_gMonth_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_gMonthDay_value : public atomic_value
{
protected:
	xqp_gMonthDay val;

public:
	xs_gMonthDay_value(xqp_gMonthDay const&);
	xs_gMonthDay_value();
	~xs_gMonthDay_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_gYear_value : public atomic_value
{
protected:
	xqp_gYear val;

public:
	xs_gYear_value(xqp_gYear const&);
	xs_gYear_value();
	~xs_gYear_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_gYearMonth_value : public atomic_value
{
protected:
	xqp_gYearMonth val;

public:
	xs_gYearMonth_value(xqp_gYearMonth const&);
	xs_gYearMonth_value();
	~xs_gYearMonth_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_hexBinary_value : public atomic_value
{
protected:
	xqp_hexBinary val;

public:
	xs_hexBinary_value(xqp_hexBinary const&);
	xs_hexBinary_value();
	~xs_hexBinary_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_ID_value : public atomic_value
{
protected:
	xqp_ID val;

public:
	xs_ID_value(xqp_ID const&);
	xs_ID_value();
	~xs_ID_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_IDREF_value : public atomic_value
{
protected:
	xqp_IDREF val;

public:
	xs_IDREF_value(xqp_IDREF const&);
	xs_IDREF_value();
	~xs_IDREF_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_IDREFS_value : public atomic_value
{
protected:
	xqp_IDREFS val;

public:
	xs_IDREFS_value(xqp_IDREFS const&);
	xs_IDREFS_value();
	~xs_IDREFS_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_language_value : public atomic_value
{
protected:
	xqp_language val;

public:
	xs_language_value(xqp_language const&);
	xs_language_value();
	~xs_language_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_NCName_value : public atomic_value
{
protected:
	xqp_NCName val;

public:
	xs_NCName_value(xqp_NCName const&);
	xs_NCName_value();
	~xs_NCName_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_NMTOKEN_value : public atomic_value
{
protected:
	xqp_NMTOKEN val;

public:
	xs_NMTOKEN_value(xqp_NMTOKEN const&);
	xs_NMTOKEN_value();
	~xs_NMTOKEN_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_NMTOKENS_value : public atomic_value
{
protected:
	xqp_NMTOKENS val;

public:
	xs_NMTOKENS_value(xqp_NMTOKENS const&);
	xs_NMTOKENS_value();
	~xs_NMTOKENS_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_NOTATION_value : public atomic_value
{
protected:
	xqp_NOTATION val;

public:
	xs_NOTATION_value(xqp_NOTATION const&);
	xs_NOTATION_value();
	~xs_NOTATION_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_Name_value : public atomic_value
{
protected:
	xqp_Name val;

public:
	xs_Name_value(xqp_Name const&);
	xs_Name_value();
	~xs_Name_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_negativeInteger_value : public atomic_value
{
protected:
	xqp_negativeInteger val;

public:
	xs_negativeInteger_value(xqp_negativeInteger const&);
	xs_negativeInteger_value();
	~xs_negativeInteger_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_nonNegativeInteger_value : public atomic_value
{
protected:
	xqp_nonNegativeInteger val;

public:
	xs_nonNegativeInteger_value(xqp_nonNegativeInteger const&);
	xs_nonNegativeInteger_value();
	~xs_nonNegativeInteger_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_nonPositiveInteger_value : public atomic_value
{
protected:
	xqp_nonPositiveInteger val;

public:
	xs_nonPositiveInteger_value(xqp_nonPositiveInteger const&);
	xs_nonPositiveInteger_value();
	~xs_nonPositiveInteger_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_normalizedString_value : public atomic_value
{
protected:
	xqp_normalizedString val;

public:
	xs_normalizedString_value(xqp_normalizedString const&);
	xs_normalizedString_value();
	~xs_normalizedString_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_positiveInteger_value : public atomic_value
{
protected:
	xqp_positiveInteger val;

public:
	xs_positiveInteger_value(xqp_positiveInteger const&);
	xs_positiveInteger_value();
	~xs_positiveInteger_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_string_value : public atomic_value
{
protected:
	xqp_string val;

public:
	xs_string_value(xqp_string const&);
	xs_string_value();
	~xs_string_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_time_value : public atomic_value
{
protected:
	xqp_time val;

public:
	xs_time_value(xqp_time const&);
	xs_time_value();
	~xs_time_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_token_value : public atomic_value
{
protected:
	xqp_token val;

public:
	xs_token_value(xqp_token const&);
	xs_token_value();
	~xs_token_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_unsignedByte_value : public atomic_value
{
protected:
	xqp_unsignedByte val;

public:
	xs_unsignedByte_value(xqp_unsignedByte const&);
	xs_unsignedByte_value();
	~xs_unsignedByte_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_unsignedInt_value : public atomic_value
{
protected:
	xqp_unsignedInt val;

public:
	xs_unsignedInt_value(xqp_unsignedInt const&);
	xs_unsignedInt_value();
	~xs_unsignedInt_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_unsignedLong_value : public atomic_value
{
protected:
	xqp_unsignedLong val;

public:
	xs_unsignedLong_value(xqp_unsignedLong const&);
	xs_unsignedLong_value();
	~xs_unsignedLong_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};



class xs_unsignedShort_value : public atomic_value
{
protected:
	xqp_unsignedShort val;

public:
	xs_unsignedShort_value(xqp_unsignedShort const&);
	xs_unsignedShort_value();
	~xs_unsignedShort_value();

public:

	void encode(xml_ostream* xos)
	throw (xqp_exception);

	void decode(xml_istream& xis)
	throw (xqp_exception);

public:
	std::string describe(context const&) const;
	type::typecode get_typecode() const;
	bool operator==(schema_type const&);
	std::ostream& put(std::ostream&, context const&) const;

};


}	/* namespace xqp */
#endif	/* XQP_XS_PRIMITIVE_VALUES_H */
