/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_value_factory.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_ZORBA_VALUE_FACTORY_H
#define XQP_ZORBA_VALUE_FACTORY_H

#include "context/common.h"
//#include "types/sequence_type.h"
#include "util/rchandle.h"
#include "values/values.h"
#include "values/value_factory.h"

namespace xqp {

class atomic_value;

class zorba_value_factory
{

public:
	zorba_value_factory() {}
	virtual ~zorba_value_factory() {}

public:
	rchandle<atomic_value> make_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

	rchandle<atomic_value> make_xs_anyURI(const std::string&);
	rchandle<atomic_value> make_xs_base64Binary(const void*,uint32_t);
	rchandle<atomic_value> make_xs_boolean(bool);
	rchandle<atomic_value> make_xs_decimal(long double);
	rchandle<atomic_value> make_xs_integer(int);
	rchandle<atomic_value> make_xs_long(long);
	rchandle<atomic_value> make_xs_int(int);
	rchandle<atomic_value> make_xs_short(short);
	rchandle<atomic_value> make_xs_byte(char);
	rchandle<atomic_value> make_xs_date();
	rchandle<atomic_value> make_xs_dateTime();
	rchandle<atomic_value> make_xs_double(double);
	rchandle<atomic_value> make_xs_duration();
	rchandle<atomic_value> make_xs_ENTITIES(const std::string&);
	rchandle<atomic_value> make_xs_ENTITY(const std::string&);
	rchandle<atomic_value> make_xs_float(float);
	rchandle<atomic_value> make_xs_gDay();
	rchandle<atomic_value> make_xs_gMonth();
	rchandle<atomic_value> make_xs_gMonthDay();
	rchandle<atomic_value> make_xs_gYear();
	rchandle<atomic_value> make_xs_gYearMonth();
	rchandle<atomic_value> make_xs_hexBinary(const void*,uint32_t);
	rchandle<atomic_value> make_xs_ID(const std::string&);
	rchandle<atomic_value> make_xs_IDREF(const std::string&);
	rchandle<atomic_value> make_xs_IDREFS(const std::string&);
	rchandle<atomic_value> make_xs_language(const std::string&);
	rchandle<atomic_value> make_xs_NCName(const std::string&);
	rchandle<atomic_value> make_xs_NMTOKEN(const std::string&);
	rchandle<atomic_value> make_xs_NMTOKENS(const std::string&);
	rchandle<atomic_value> make_xs_NOTATION(const std::string&);
	rchandle<atomic_value> make_xs_Name(const std::string&);
	rchandle<atomic_value> make_xs_negativeInteger(int);
	rchandle<atomic_value> make_xs_nonNegativeInteger(int);
	rchandle<atomic_value> make_xs_nonPositiveInteger(int);
	rchandle<atomic_value> make_xs_normalizedString(const std::string&);
	rchandle<atomic_value> make_xs_positiveInteger(unsigned int);
	rchandle<atomic_value> make_xs_string(const std::string&);
	rchandle<atomic_value> make_xs_time();
	rchandle<atomic_value> make_xs_token(const std::string&);
	rchandle<atomic_value> make_xs_unsignedByte(unsigned char);
	rchandle<atomic_value> make_xs_unsignedInt(unsigned int);
	rchandle<atomic_value> make_xs_unsignedLong(unsigned long);
	rchandle<atomic_value> make_xs_unsignedShort(uint16_t);

	//static atomic_value* cast_as(iterator_t,sequence_type_t);

};


} /* namespace xqp */
#endif /* XQP_ZORBA_VALUE_FACTORY_H */

