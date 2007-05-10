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

#include "primitive_values.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

namespace xqp {

class value_factory : public rcobject
{
public:
	virtual ~value_factory() {}

public:
	virtual rchandle<qname> make_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname) = 0;

	// value construtors
	virtual rchandle<atomic_value> make_xs_anyURI(const std::string&) = 0;
	virtual rchandle<atomic_value> make_xs_base64Binary(const void*,uint32_t) = 0;
	virtual rchandle<atomic_value> make_xs_boolean(bool) = 0;
	virtual rchandle<atomic_value> make_xs_decimal(long double) = 0;
	virtual rchandle<atomic_value> make_xs_integer(int) = 0;
	virtual rchandle<atomic_value> make_xs_long(long) = 0;
	virtual rchandle<atomic_value> make_xs_int(int) = 0;
	virtual rchandle<atomic_value> make_xs_short(short) = 0;
	virtual rchandle<atomic_value> make_xs_byte(char) = 0;
	virtual rchandle<atomic_value> make_xs_date() = 0;
	virtual rchandle<atomic_value> make_xs_dateTime() = 0;
	virtual rchandle<atomic_value> make_xs_double(double) = 0;
	virtual rchandle<atomic_value> make_xs_duration() = 0;
	virtual rchandle<atomic_value> make_xs_ENTITIES(const std::string&) = 0;
	virtual rchandle<atomic_value> make_xs_ENTITY(const std::string&) = 0;
	virtual rchandle<atomic_value> make_xs_float(float) = 0;
	virtual rchandle<atomic_value> make_xs_gDay() = 0;
	virtual rchandle<atomic_value> make_xs_gMonth() = 0;
	virtual rchandle<atomic_value> make_xs_gMonthDay() = 0;
	virtual rchandle<atomic_value> make_xs_gYear() = 0;
	virtual rchandle<atomic_value> make_xs_gYearMonth() = 0;
	virtual rchandle<atomic_value> make_xs_hexBinary(const void*,uint32_t) = 0;
	virtual rchandle<atomic_value> make_xs_ID(const std::string&) = 0;
	virtual rchandle<atomic_value> make_xs_IDREF(const std::string&) = 0;
	virtual rchandle<atomic_value> make_xs_IDREFS(const std::string&) = 0;
	virtual rchandle<atomic_value> make_xs_language(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_NCName(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_NMTOKEN(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_NMTOKENS(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_NOTATION(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_Name(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_negativeInteger(int) = 0;
	virtual rchandle<atomic_value> make_xs_nonNegativeInteger(int) = 0;
	virtual rchandle<atomic_value> make_xs_nonPositiveInteger(int) = 0;
	virtual rchandle<atomic_value> make_xs_normalizedString(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_positiveInteger(unsigned int) = 0;
	virtual rchandle<atomic_value> make_xs_string(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_time() = 0;
	virtual rchandle<atomic_value> make_xs_token(const string&) = 0;
	virtual rchandle<atomic_value> make_xs_unsignedByte(unsigned char) = 0;
	virtual rchandle<atomic_value> make_xs_unsignedInt(int) = 0;
	virtual rchandle<atomic_value> make_xs_unsignedLong(unsigned long) = 0;
	virtual rchandle<atomic_value> make_xs_unsignedShort(uint16_t) = 0;
	
	// node constructors
	/*
	virtual rchandle<element_node*> make_element_node(
	  bool transient, ...) = 0;
	virtual rchandle<element_node*> make_attribute_node(
	  bool transient, ...) = 0;
	virtual rchandle<element_node*> make_text_node(
	  bool transient, ...) = 0;
	virtual rchandle<element_node*> make_namespace_node(
	  bool transient, ...) = 0;
	virtual rchandle<element_node*> make_comment_node(
	  bool transient, ...) = 0;
	virtual rchandle<element_node*> make_pi_node(s
	  bool transient, ...) = 0;
	*/

};


} /* namespace xqp */
#endif /* XQP_VALUE_FACTORY_H */

