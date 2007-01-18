/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */
 
 /*
 *  This code module is derived from the Saxon project.
 *  Michael Kay is the original author of the Saxon code base.
 *  [http://saxon.sourceforge.net/]
 *  
 *  The Saxon Java code has been completely
 *  reworked for the C++ framework, but the
 *  design is clearly inherited from Saxon.
 *
 */

#include "base_types.h"

using namespace std;
namespace xqp {


////////////////////////////////
//	type (static)
////////////////////////////////

/*
xs_anyAtomicType UNTYPED_ATOMIC_TYPE = SchemaFactory.make_type(_UNTYPED_ATOMIC);
xs_anyAtomicType ANY_ATOMIC_TYPE = SchemaFactory.make_type(_ANY_ATOMIC_TYPE);
xs_anyAtomicType YEAR_MONTH_DURATION_TYPE = SchemaFactory.make_type(_YEARMONTH_DURATION);
xs_anyAtomicType DAY_TIME_DURATION_TYPE = SchemaFactory.make_type(_DAYTIME_DURATION);
xs_anyAtomicType STRING_TYPE = SchemaFactory.make_type(_STRING);
xs_anyAtomicType BOOLEAN_TYPE = SchemaFactory.make_type(_BOOLEAN);
xs_anyAtomicType DECIMAL_TYPE = SchemaFactory.make_type(_DECIMAL);
xs_anyAtomicType FLOAT_TYPE = SchemaFactory.make_type(_FLOAT);
xs_anyAtomicType DOUBLE_TYPE = SchemaFactory.make_type(_DOUBLE);
xs_anyAtomicType DURATION_TYPE = SchemaFactory.make_type(_DURATION);
xs_anyAtomicType DATE_TIME_TYPE = SchemaFactory.make_type(_DATETIME);
xs_anyAtomicType TIME_TYPE = SchemaFactory.make_type(_TIME);
xs_anyAtomicType DATE_TYPE = SchemaFactory.make_type(_DATE);
xs_anyAtomicType G_YEAR_MONTH_TYPE = SchemaFactory.make_type(_GYEARMONTH);
xs_anyAtomicType G_YEAR_TYPE = SchemaFactory.make_type(_GYEAR);
xs_anyAtomicType G_MONTH_DAY_TYPE = SchemaFactory.make_type(_GMONTHDAY);
xs_anyAtomicType G_DAY_TYPE = SchemaFactory.make_type(_GDAY);
xs_anyAtomicType G_MONTH_TYPE = SchemaFactory.make_type(_GMONTH);
xs_anyAtomicType HEX_BINARY_TYPE = SchemaFactory.make_type(_HEXBINARY);
xs_anyAtomicType BASE64_BINARY_TYPE = SchemaFactory.make_type(_BASE64BINARY);
xs_anyAtomicType ANY_URI_TYPE = SchemaFactory.make_type(_ANYURI);
xs_anyAtomicType QNAME_TYPE = SchemaFactory.make_type(_QNAME);
xs_anyAtomicType NOTATION_TYPE = SchemaFactory.make_type(_NOTATION);
xs_anyAtomicType INTEGER_TYPE = SchemaFactory.make_type(_INTEGER);
xs_anyAtomicType ID_TYPE = SchemaFactory.make_type(_ID);
xs_anyAtomicType IDREF_TYPE = SchemaFactory.make_type(_IDREF);
xs_anyAtomicType NCNAME_TYPE = SchemaFactory.make_type(_NCNAME);
xs_anyAtomicType NUMBER_TYPE = SchemaFactory.make_type(_NUMERIC);
*/


item_type const* type::get_item_type(
	item const* m)
{
	return NULL; 
}

type::typecode type::get_typecode(
	item const* m)
{
	return ITEM_TYPE;
}

string type::describe(item const* i_p)
{
	return "type";
}

enum type::type_relation type::schema_type_relation(
	schema_type const& s1,
	schema_type const& s2)
{
	return DISJOINT;
}

enum type::type_relation type::type_relation(
	item_type const& t1,
	item_type const& t2)
{
	return DISJOINT;
}

bool is_node(
	item_type const& t)
{
	return false;
}

bool type::is_primitive(
	item_type const& t)
{
	return true;
}

bool type::is_ordered(
	enum typecode t)
{
	return true;
}

bool type::is_numeric(
	typecode t)
{
	return false;
}

bool type::is_subtype(
	item_type const& itype1,
	item_type const& itype2)
{
	return false;
}



////////////////////////////////
//	item_type
////////////////////////////////

bool item_type::is_atomic_type() const
{
	return true;
}

bool item_type::matches(
	item const* item,
	context const* ctx) const
{
	return false;
}

item_type const* item_type::get_supertype() const
{
	return NULL;
}

item_type const* item_type::get_primitive_type() const
{
	return NULL;
}

enum type::typecode item_type::get_typecode() const
{
	return ITEM_TYPE;
}

std::string item_type::describe() const
{
	return "item_type";
}

xs_anyAtomicType const* item_type::get_atomized_type() const
{
	return NULL;
}



////////////////////////////////
//	any_item_type
////////////////////////////////

any_item_type const& any_item_type::get_instance()
{
	return the_instance;
}

bool any_item_type::is_atomic_type() const 
{
	return false;
}

bool any_item_type::matches(
	item const* t1,
	context const* ctx) const
{
	return false;
}

item_type const* any_item_type::get_supertype() const
{
	return NULL;
}

item_type const* any_item_type::get_primitive_type() const
{
	return NULL;
}

enum type::typecode any_item_type::get_primitive_typecode() const
{
	return ITEM_TYPE;
}
	
xs_anyAtomicType const* any_item_type::get_atomized_type() const
{
	return NULL;
}

std::string any_item_type::describe() const
{
	return "any_item_type";
}



////////////////////////////////
//	schema_component
////////////////////////////////




////////////////////////////////
//	schema_type
////////////////////////////////

type::typecode schema_type::get_typecode() const
{
	return type::ITEM_TYPE;
}

bool schema_type::operator==(schema_type const& other)
{
	return false;
}

bool schema_type::is_complex() const
{
	return false;
}

bool schema_type::is_simple() const
{
	return true;
}

bool schema_type::is_atomic() const
{
	return true;
}

bool schema_type::is_anonymous() const
{
	return false;
}

schema_type const* schema_type::get_base_type() const
{
	return NULL;
}

enum schema_type::derivation_method schema_type::get_derivation_method() const
{
	return schema_type::DERIV_ALL;
}

bool schema_type::allows_derivation(
	enum schema_type::derivation_method derivation) const
{
	return true;
}

std::string schema_type::describe() const
{
	return "schema_type";
}



////////////////////////////////
//	simple_type
////////////////////////////////

bool simple_type::is_atomic() const
{
	return true;
}

bool simple_type::is_list() const
{
	return false;
}

bool simple_type::is_union() const
{
	return false;
}

atomic_type const* simple_type::get_common_atomic_type() const
{
	return NULL;
}

schema_type const* simple_type::get_builtin_base_type() const
{
	return NULL;
}

int simple_type::validate_content(
	char const* src)
throw (xqp_exception)
{
	return 0;
}



////////////////////////////////
//	complex_type
////////////////////////////////

bool complex_type::is_abstract() const
{
	return false;
}

bool complex_type::complex_content() const
{
	return false;
}

bool complex_type::simple_content() const
{
	return true;
}

bool complex_type::all_content() const
{
	return true;
}

simple_type const* complex_type::get_simple_content_type() const
{
	return NULL;
}

bool complex_type::is_restricted() const
{
	return false;
}

bool complex_type::is_empty_content() const
{
	return false;
}

bool complex_type::allows_empty() const
{
	return true;
}

bool complex_type::allows_mixed_content() const
{
	return true;
}

bool complex_type::subsumes(
	complex_type const& c)
{
	return false;
}



////////////////////////////////
//	xs_anyType
////////////////////////////////

xs_anyType const& xs_anyType::get_instance()
{
	return the_instance;
}

enum type::typecode xs_anyType::get_typecode() const
{
	return type::XS_ANYTYPE;
}

schema_type const* xs_anyType::get_base_type() const
{
	return NULL;
}

schema_type const* xs_anyType::get_known_base_type() const
{
	return NULL;
}

bool xs_anyType::is_abstract() const
{
	return false;
}

bool xs_anyType::is_complex() const
{
	return true;
}

bool xs_anyType::is_anonymous() const
{
	return false;
}

bool xs_anyType::is_xs_anySimpleType() const
{
	return true;
}

bool xs_anyType::is_atomic() const
{
	return true;
}

bool xs_anyType::is_simple_content() const
{
	return true;
}

bool xs_anyType::is_all_content() const
{
	return true;
}

bool xs_anyType::is_restricted() const
{
	return false;
}

bool xs_anyType::is_empty_content() const
{
	return false;
}

bool xs_anyType::allows_derivation(
	enum schema_type::derivation_method) const
{
	return true;
}

bool xs_anyType::allows_empty() const
{
	return true;
}

bool xs_anyType::allows_mixed_content() const
{
	return true;
}

bool xs_anyType::operator==(schema_type const&) const
{
	return false;
}

std::string xs_anyType::describe() const
{
	return "xs_anyType";
}

std::string xs_anyType::subsumes(
	complex_type const&) const
{
	return false;
}

void xs_anyType::check_type_derivation(
	schema_type const&,
	enum schema_type::derivation_method)
throw (xqp_exception)
{
}

enum schema_type::derivation_method
xs_anyType::get_derivation_method() const
{
	return schema_type::DERIV_ALL;
}



////////////////////////////////
//	xs_anySimpleType
////////////////////////////////

xs_anySimpleType const& xs_anySimpleType::get_instance()
{
	return the_instance;
}

bool xs_anySimpleType::matches(schema_type const& other) const
{
	return false;
}

bool xs_anySimpleType::is_complex() const
{
	return true;
}

bool xs_anySimpleType::is_atomic() const
{
	return true;
}

bool xs_anySimpleType::is_anonymous() const
{
	return false;
}

bool xs_anySimpleType::is_list() const
{
	return false;
}

enum type::typecode xs_anySimpleType::get_typecode() const
{
	return type::XS_ANYSIMPLETYPE;
}

schema_type::derivation_method xs_anySimpleType::get_derivation_method() const
{
	return schema_type::DERIV_ALL;
}

schema_type const* xs_anySimpleType::get_base_type() const
{
	return NULL;
}

schema_type const* xs_anySimpleType::get_known_base_type() const
{
	return NULL;
}

schema_type const* xs_anySimpleType::get_builtin_base_type() const
{
	return NULL;
}

atomic_type const* xs_anySimpleType::get_common_atomic_type() const
{
	return NULL;
}

std::string xs_anySimpleType::describe() const
{
	return "xs_anySimpleType";
}

bool xs_anySimpleType::allows_derivation(
	enum schema_type::derivation_method m) const
{
	return true;
}

void xs_anySimpleType::check_type_derivation(
	schema_type const& type,
	enum derivation_method)
throw (xqp_exception)
{
}

int xs_anySimpleType::validate_content(
	char const* value)
throw (xqp_exception)
{
	return 0;
}



////////////////////////////////
//	xs_untyped
////////////////////////////////

xs_untyped const& xs_untyped::get_instance()
{
	return the_instance;
}

schema_type::derivation_method xs_untyped::get_derivation_method() const
{
	return schema_type::DERIV_ALL;
}

type::typecode xs_untyped::get_typecode() const
{
	return type::XS_UNTYPED;
}

simple_type const* xs_untyped::get_simple_content_type() const
{
	return NULL;
}

schema_type const* xs_untyped::get_known_base_type() const
{
	return NULL;
}

schema_type const* xs_untyped::get_base_type() const
{
	return NULL;
}

bool xs_untyped::is_complex() const
{
	return true;
}

bool xs_untyped::is_anonymous() const
{
	return false;
}

bool xs_untyped::is_abstract() const
{
	return false;
}

bool xs_untyped::is_simple() const
{
	return true;
}

bool xs_untyped::is_atomic() const
{
	return true;
}

bool xs_untyped::is_restricted() const
{
	return false;
}

bool xs_untyped::is_complex_content() const
{
	return true;
}

bool xs_untyped::is_simple_content() const
{
	return true;
}

bool xs_untyped::is_all_content() const
{
	return true;
}

bool xs_untyped::is_empty_content() const
{
	return false;
}

bool xs_untyped::allows_derivation(
	enum schema_type::derivation_method) const
{
	return true;
}

bool xs_untyped::allows_empty() const
{
	return true;
}

bool xs_untyped::allows_mixedContent() const
{
	return true;
}

std::string xs_untyped::describe() const
{
	return "xs_untyped";
}

bool xs_untyped::subsumes(
	complex_type const&)
{
	return false;
}



////////////////////////////////
//	atomic_type
////////////////////////////////



////////////////////////////////
//	xs_anyAtomicType
////////////////////////////////

xs_anyAtomicType const& xs_anyAtomicType::get_instance()
{
	return the_instance;
}

type::typecode xs_anyAtomicType::get_typecode() const
{
	return type::XS_ANYATOMICTYPE;
}

item_type const* xs_anyAtomicType::get_primitive_type() const
{
	return NULL;
}

schema_type::derivation_method xs_anyAtomicType::get_derivation_method() const
{
	return schema_type::DERIV_ALL;
}

bool xs_anyAtomicType::operator==(schema_type const&) const
{
	return false;
}

bool xs_anyAtomicType::is_complex() const
{
	return true;
}

bool xs_anyAtomicType::is_anonymous() const
{
	return false;
}

bool xs_anyAtomicType::is_simple() const
{
	return true;
}

bool xs_anyAtomicType::is_atomic() const
{
	return true;
}

bool xs_anyAtomicType::is_list() const
{
	return false;
}

bool xs_anyAtomicType::is_union() const
{
	return true;
}

item_type const* xs_anyAtomicType::get_super_type() const
{
	return NULL;
}

item_type const* xs_anyAtomicType::get_primitive_item_type() const
{
	return NULL;
}

atomic_type const* xs_anyAtomicType::get_common_atomic_type() const
{
	return NULL;
}

atomic_type const* xs_anyAtomicType::get_atomized_item_type() const
{
	return NULL;
}

schema_type const* xs_anyAtomicType::get_known_base_type() const
{
	return NULL;
}

schema_type const* xs_anyAtomicType::get_base_type() const
{
	return NULL;
}

std::string xs_anyAtomicType::describe() const
{
	return "xs_anyAtomicType";
}

void xs_anyAtomicType::check_type_derivation(
	schema_type const& type,
	enum derivation_method)
throw (xqp_exception)
{
}



////////////////////////////////
//	list_type
////////////////////////////////

xs_anySimpleType const* list_type::get_item_type() const
{
	return NULL;
}



////////////////////////////////
//	builtin_list_type
////////////////////////////////

type::typecode builtin_list_type::get_typecode() const
{
	return type::BUILTIN_LIST;
}

item_type const* builtin_list_type::get_primitive_type() const
{
	return NULL;
}

schema_type::derivation_method builtin_list_type::get_derivation_method() const
{
	return schema_type::DERIV_ALL;
}

bool builtin_list_type::operator==(schema_type const&) const
{
	return false;
}

bool builtin_list_type::is_complex() const
{
	return true;
}

bool builtin_list_type::is_anonymous() const
{
	return false;
}

bool builtin_list_type::is_simple() const
{
	return true;
}

bool builtin_list_type::is_atomic() const
{
	return true;
}

bool builtin_list_type::is_list() const
{
	return false;
}

bool builtin_list_type::is_union() const
{
	return true;
}

item_type const* builtin_list_type::get_super_type() const
{
	return NULL;
}

item_type const* builtin_list_type::get_primitive_item_type() const
{
	return NULL;
}

atomic_type const* builtin_list_type::get_common_atomic_type() const
{
	return NULL;
}

atomic_type const* builtin_list_type::get_atomized_item_type() const
{
	return NULL;
}

schema_type const* builtin_list_type::get_known_base_type() const
{
	return NULL;
}

schema_type const* builtin_list_type::get_base_type() const
{
	return NULL;
}

std::string builtin_list_type::describe() const
{
	return "builtin_list_type";
}

void builtin_list_type::check_type_derivation(
	schema_type const& type,
	enum derivation_method)
throw (xqp_exception)
{
}


} /* namespace xqp */

