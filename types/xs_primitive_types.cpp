/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "xs_primitive_types.h"

using namespace std;
namespace xqp {


///////////////////////////////
//  anyURI
///////////////////////////////

xs_anyURI::xs_anyURI()
{
}
 
xs_anyURI::~xs_anyURI()
{
}

type::typecode xs_anyURI::get_typecode() const
{
	return XS_ANYURI;
}



///////////////////////////////
//  Base64Binary
///////////////////////////////

xs_base64Binary::xs_base64Binary()
{
}
 
xs_base64Binary::~xs_base64Binary()
{
}

type::typecode xs_base64Binary::get_typecode() const
{
	return type::XS_BASE64BINARY;
}

 
 
///////////////////////////////
//  xs_boolean
///////////////////////////////

xs_boolean::xs_boolean()
{
}
 
xs_boolean::~xs_boolean()
{
}

type::typecode xs_boolean::get_typecode() const
{
	return XS_ANYURI;
}


///////////////////////////////
//  xs_byte
///////////////////////////////

xs_byte::xs_byte()
{
}
 
xs_byte::~xs_byte()
{
}

type::typecode xs_byte::get_typecode() const
{
	return XS_ANYURI;
}



///////////////////////////////
//	xs_date
///////////////////////////////

xs_date::xs_date()
{
}
 
xs_date::~xs_date()
{
}

type::typecode xs_date::get_typecode() const
{
	return XS_ANYURI;
}

 

///////////////////////////////
//	xs_dateTime
///////////////////////////////

xs_dateTime::xs_dateTime()
{
}
 
xs_dateTime::~xs_dateTime()
{
}

type::typecode xs_dateTime::get_typecode() const
{
	return XS_DATETIME;
}

 

///////////////////////////////
//	xs_decimal
///////////////////////////////

xs_decimal::xs_decimal()
{
}
 
xs_decimal::~xs_decimal()
{
}

type::typecode xs_decimal::get_typecode() const
{
	return XS_DECIMAL;
}

 

///////////////////////////////
//	xs_double
///////////////////////////////

xs_double::xs_double()
{
}
 
xs_double::~xs_double()
{
}

type::typecode xs_double::get_typecode() const
{
	return XS_DOUBLE;
}

 

///////////////////////////////
//	xs_duration
///////////////////////////////

xs_duration::xs_duration()
{
}
 
xs_duration::~xs_duration()
{
}

type::typecode xs_duration::get_typecode() const
{
	return XS_DURATION;
}

 

///////////////////////////////
//	xs_float
///////////////////////////////
xs_float::xs_float()
{
}
 
xs_float::~xs_float()
{
}

type::typecode xs_float::get_typecode() const
{
	return XS_FLOAT;
}



///////////////////////////////
//	xs_gDay
///////////////////////////////

xs_gDay::xs_gDay()
{
}
 
xs_gDay::~xs_gDay()
{
}

type::typecode xs_gDay::get_typecode() const
{
	return XS_GDAY;
}



///////////////////////////////
//	xs_gMonth
///////////////////////////////

xs_gMonth::xs_gMonth()
{
}
 
xs_gMonth::~xs_gMonth()
{
}

type::typecode xs_gMonth::get_typecode() const
{
	return XS_GMONTH;
}



///////////////////////////////
//	xs_gMonthDay
///////////////////////////////

xs_gMonthDay::xs_gMonthDay()
{
}
 
xs_gMonthDay::~xs_gMonthDay()
{
}

type::typecode xs_gMonthDay::get_typecode() const
{
	return XS_GMONTHDAY;
}



///////////////////////////////
//	xs_gYear
///////////////////////////////

xs_gYear::xs_gYear()
{
}
 
xs_gYear::~xs_gYear()
{
}

type::typecode xs_gYear::get_typecode() const
{
	return XS_GYEAR;
}



///////////////////////////////
//	xs_gYearMonth
///////////////////////////////

xs_gYearMonth::xs_gYearMonth()
{
}
 
xs_gYearMonth::~xs_gYearMonth()
{
}

type::typecode xs_gYearMonth::get_typecode() const
{
	return XS_GYEARMONTH;
}



///////////////////////////////
//	xs_hexBinary
///////////////////////////////

xs_hexBinary::xs_hexBinary()
{
}
 
xs_hexBinary::~xs_hexBinary()
{
}

type::typecode xs_hexBinary::get_typecode() const
{
	return XS_HEXBINARY;
}



///////////////////////////////
//	xs_int
///////////////////////////////

xs_int::xs_int()
{
}
 
xs_int::~xs_int()
{
}

type::typecode xs_int::get_typecode() const
{
	return XS_INT;
}



///////////////////////////////
//	xs_integer
///////////////////////////////

xs_integer::xs_integer()
{
}
 
xs_integer::~xs_integer()
{
}

type::typecode xs_integer::get_typecode() const
{
	return XS_INTEGER;
}



///////////////////////////////
//	xs_language
///////////////////////////////

xs_language::xs_language()
{
}
 
xs_language::~xs_language()
{
}

type::typecode xs_language::get_typecode() const
{
	return XS_LANGUAGE;
}



///////////////////////////////
//	xs_long
///////////////////////////////

xs_long::xs_long()
{
}
 
xs_long::~xs_long()
{
}

type::typecode xs_long::get_typecode() const
{
	return XS_LONG;
}



///////////////////////////////
//	xs_negativeInteger
///////////////////////////////

xs_negativeInteger::xs_negativeInteger()
{
}
 
xs_negativeInteger::~xs_negativeInteger()
{
}

type::typecode xs_negativeInteger::get_typecode() const
{
	return XS_NEGATIVE_INTEGER;
}



///////////////////////////////
//	xs_nonNegativeInteger
///////////////////////////////

xs_nonNegativeInteger::xs_nonNegativeInteger()
{
}
 
xs_nonNegativeInteger::~xs_nonNegativeInteger()
{
}

type::typecode xs_nonNegativeInteger::get_typecode() const
{
	return XS_NON_NEGATIVE_INTEGER;
}


///////////////////////////////
//	xs_nonPositiveInteger
///////////////////////////////

xs_nonPositiveInteger::xs_nonPositiveInteger()
{
}
 
xs_nonPositiveInteger::~xs_nonPositiveInteger()
{
}

type::typecode xs_nonPositiveInteger::get_typecode() const
{
	return XS_NON_POSITIVE_INTEGER;
}



///////////////////////////////
//	xs_normalizedString
///////////////////////////////

xs_normalizedString::xs_normalizedString()
{
}
 
xs_normalizedString::~xs_normalizedString()
{
}

type::typecode xs_normalizedString::get_typecode() const
{
	return XS_NORMALIZED_STRING;
}



///////////////////////////////
//	xs_positiveInteger
///////////////////////////////

xs_positiveInteger::xs_positiveInteger()
{
}
 
xs_positiveInteger::~xs_positiveInteger()
{
}

type::typecode xs_positiveInteger::get_typecode() const
{
	return XS_POSITIVE_INTEGER;
}



///////////////////////////////
//	xs_short
///////////////////////////////

xs_short::xs_short()
{
}
 
xs_short::~xs_short()
{
}

type::typecode xs_short::get_typecode() const
{
	return XS_SHORT;
}


///////////////////////////////
//	xs_string
///////////////////////////////

xs_string::xs_string()
{
}
 
xs_string::~xs_string()
{
}

type::typecode xs_string::get_typecode() const
{
	return XS_STRING;
}



///////////////////////////////
//	xs_time
///////////////////////////////

xs_time::xs_time()
{
}
 
xs_time::~xs_time()
{
}

type::typecode xs_time::get_typecode() const
{
	return XS_TIME;
}



///////////////////////////////
//	xs_token
///////////////////////////////

xs_token::xs_token()
{
}
 
xs_token::~xs_token()
{
}

type::typecode xs_token::get_typecode() const
{
	return XS_TOKEN;
}



///////////////////////////////
//	xs_unsignedByte
///////////////////////////////

xs_unsignedByte::xs_unsignedByte()
{
}
 
xs_unsignedByte::~xs_unsignedByte()
{
}

type::typecode xs_unsignedByte::get_typecode() const
{
	return XS_UNSIGNED_BYTE;
}



///////////////////////////////
//	xs_unsignedInt
///////////////////////////////

xs_unsignedInt::xs_unsignedInt()
{
}
 
xs_unsignedInt::~xs_unsignedInt()
{
}

type::typecode xs_unsignedInt::get_typecode() const
{
	return XS_UNSIGNED_INT;
}



///////////////////////////////
//	xs_unsignedLong
///////////////////////////////

xs_unsignedLong::xs_unsignedLong()
{
}
 
xs_unsignedLong::~xs_unsignedLong()
{
}

type::typecode xs_unsignedLong::get_typecode() const
{
	return XS_UNSIGNED_LONG;
}



///////////////////////////////
//	xs_unsignedShort
///////////////////////////////

xs_unsignedShort::xs_unsignedShort()
{
}
 
xs_unsignedShort::~xs_unsignedShort()
{
}

type::typecode xs_unsignedShort::get_typecode() const
{
	return XS_UNSIGNED_SHORT;
}



///////////////////////////////
//	xs_ENTITIES
///////////////////////////////

xs_ENTITIES::xs_ENTITIES()
{
}
 
xs_ENTITIES::~xs_ENTITIES()
{
}

type::typecode xs_ENTITIES::get_typecode() const
{
	return XS_ENTITIES;
}



///////////////////////////////
//	xs_ENTITY
///////////////////////////////

xs_ENTITY::xs_ENTITY()
{
}
 
xs_ENTITY::~xs_ENTITY()
{
}

type::typecode xs_ENTITY::get_typecode() const
{
	return XS_ENTITY;
}



///////////////////////////////
//	xs_ID
///////////////////////////////

xs_ID::xs_ID()
{
}
 
xs_ID::~xs_ID()
{
}

type::typecode xs_ID::get_typecode() const
{
	return XS_ID;
}



///////////////////////////////
//	xs_IDREF
///////////////////////////////

xs_IDREF::xs_IDREF()
{
}
 
xs_IDREF::~xs_IDREF()
{
}

type::typecode xs_IDREF::get_typecode() const
{
	return XS_IDREF;
}



///////////////////////////////
//	xs_IDREFS
///////////////////////////////

xs_IDREFS::xs_IDREFS()
{
}
 
xs_IDREFS::~xs_IDREFS()
{
}

type::typecode xs_IDREFS::get_typecode() const
{
	return XS_IDREFS;
}



///////////////////////////////
//	xs_NCName
///////////////////////////////

xs_NCName::xs_NCName()
{
}
 
xs_NCName::~xs_NCName()
{
}

type::typecode xs_NCName::get_typecode() const
{
	return XS_NCNAME;
}



///////////////////////////////
//	xs_NMTOKEN
///////////////////////////////

xs_NMTOKEN::xs_NMTOKEN()
{
}
 
xs_NMTOKEN::~xs_NMTOKEN()
{
}

type::typecode xs_NMTOKEN::get_typecode() const
{
	return XS_NMTOKEN;
}



///////////////////////////////
//	xs_NMTOKENS
///////////////////////////////

xs_NMTOKENS::xs_NMTOKENS()
{
}
 
xs_NMTOKENS::~xs_NMTOKENS()
{
}

type::typecode xs_NMTOKENS::get_typecode() const
{
	return XS_NMTOKENS;
}



///////////////////////////////
//	xs_NOTATION
///////////////////////////////

xs_NOTATION::xs_NOTATION()
{
}
 
xs_NOTATION::~xs_NOTATION()
{
}

type::typecode xs_NOTATION::get_typecode() const
{
	return XS_NOTATION;
}



///////////////////////////////
//	xs_Name
///////////////////////////////

xs_Name::xs_Name()
{
}
 
xs_Name::~xs_Name()
{
}

type::typecode xs_Name::get_typecode() const
{
	return XS_NAME;
}



///////////////////////////////
//	xs_QName
///////////////////////////////

xs_QName::xs_QName()
{
}
 
xs_QName::~xs_QName()
{
}

type::typecode xs_QName::get_typecode() const
{
	return XS_QNAME;
}





ostream& operator<<(ostream& os, xqp_base64Binary const& v)
{
	char const* p = (char const*)v.data;
	return os << "base64Binary[" << string(p,0,v.size) << ']';
}

ostream& operator<<(ostream& os, xqp_hexBinary const& v)
{
	char const* p = (char const*)v.data;
	return os << "hexBinary[" << string(p,0,v.size) << ']';
}



}	/* namespace xqp */


