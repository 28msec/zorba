/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "types.h"
#include "data_interface.h"

using namespace std;
namespace xqp {


////////////////////////////////
//	type (static)
////////////////////////////////

bool types_initialized = false;

void type::init_types()
{
	xs_anyAtomicType UNTYPED_ATOMIC_TYPE = SchemaFactory.make_type(_UNTYPEDATOMIC);
	xs_anyAtomicType ANY_ATOMIC_TYPE = SchemaFactory.make_type(_ANYATOMICTYPE);
	xs_anyAtomicType YEAR_MONTH_DURATION_TYPE = SchemaFactory.make_type(_YEARMONTHDURATION);
	xs_anyAtomicType DAY_TIME_DURATION_TYPE = SchemaFactory.make_type(_DAYTIMEDURATION);
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
}

bool is_node_type(
	item_type& t)
{
}

item_type type::get_item_type(
	item const& m)
{
}

std::string type::display_typename(
	item const& m)
{
}

int type::schema_type_relationship(
	schema_type const& stype1,
	schema_type const& stype2)
{
}

ItemType type::getCommonSuperType(
	item_type const& itype1,
	item_type const& itype2)
{
}

bool type::is_primitive(
	enum typecode t)
{
}

bool type::is_comparable(
	enum typecode t1,
	enum typecode t2,
	bool ordered_b)
{
}

bool type::is_ordered(
	enum typecode t)
{
}

bool type::is_numeric_primitive(
	item_type const& itype)
{
}

bool type::is_subtype(
	item_type const& itype1,
	item_type const& itype2)
{
}

enum type_relation type::relationship(
	item_type const& itype1,
	item_type const& itype2)
{
}

bool type::is_ID(
	enum typecode t)
{
}

bool type::is_IDREFS(
	enum typecode t)
{
}



////////////////////////////////
//	item_type
////////////////////////////////

bool item_type::is_atomic_type() const
{
}

bool item_type::matches_item(
	item const& item,
	bool allow_URI_promotion,
	config& config) const
{
}

rchandle<item_type> item_type::get_supertype() const
{
}

rchandle<item_type> item_type::get_primitive_type() const
{
}

type::typecode item_type::get_primitive_typecode() const
{
}

std::string item_type::describe() const
{
}

rchandle<xs_anyAtomicType> item_type::get_atomized_type() const
{
}




////////////////////////////////
//	any_item_type
////////////////////////////////

static any_item_typerchandle<any_item_type> get_instance()
{
}

bool any_item_typeis_atomic_type() const 
{
	return false;
}

rchandle<item_type> any_item_typeget_supertype() 
{
	return NULL;
}

rchandle<item_type> any_item_typeget_primitive_type() const
{
}

int any_item_typeget_primitive_typecode() const
{
}
	
rchandle<xs_anyAtomicType> any_item_typeget_atomized_type() const
{
}

std::string any_item_typedescribe()
{
}



////////////////////////////////
//	schema_component
////////////////////////////////

type::validation_status schema_componenet::get_validation_status() const
{
}




////////////////////////////////
//	schema_type
////////////////////////////////

type::typecode schema_type::get_type() const
{
}

bool schema_type::operator==(schema_type const& other)
{
}

bool schema_type::is_complex() const
{
}

bool schema_type::is_simple() const
{
}

bool schema_type::is_atomic() const
{
}

bool schema_type::is_anonymous() const
{
}

rchandle<schema_type> schema_type::get_base_type() const
throws schema_type::xqp_exception
{
}

type::derivation_method schema_type::get_derivation_method() const
{
}

bool schema_type::allows_derivation(
	enum schema_type::derivation_method derivation) const
{
}

void schema_type::analyze_expression(
	rchandle<expr> expr_h,
	int kind,
	context const& ctx) const
throw (xqp_exception)
{
}

rchandle<item_iterator> schema_type::get_typed_value(node const&) const
throw (xqp_exception)
{
}

rchandle<item_iterator> schema_type::atomize(node const&) const
throw (xqp_xception)
{
}

std::string schema_type::describe() const
{
}




////////////////////////////////
//	simple_type
////////////////////////////////

boolsimple_type::is_atomic() const
{
}

boolsimple_type::is_list() const
{
}

boolsimple_type::is_union() const
{
}

rchandle<atomic_type>simple_type::get_common_atomic_type() const
{
}

rchandle<schema_type>simple_type::get_builtin_base_type() const
{
}

rchandle<item_iterator>simple_type::get_typed_value(
	char const* value,
	rchandle<NamespaceResolver>)
throw (xqp_exception)
{
}

rchandle<validation_error>simple_type::validate_content(
	char const* value,
	rchandle<namespace_resolver>)
throw (xqp_exception)
{
}

boolsimple_type::is_namespace_sensitive() const
{
}





////////////////////////////////
//	complex_type
////////////////////////////////

bool complex_type::is_abstract() const
{
}

bool complex_type::is_complex_content() const
{
}

bool complex_type::is_simple_content() const
{
}

bool complex_type::is_all_content() const
{
}

rchandle<simple_type> complex_type::get_simple_content_type() const
{
}

bool complex_type::is_restricted() const
{
}

bool complex_type::is_empty_content() const
{
}

bool complex_type::allows_empty() const
{
}

bool complex_type::allows_mixed_content() const
{
}

bool complex_type::subsumes(
	rchandle<complex_type>)
{
}



////////////////////////////////
//	xs_anySimpleType
////////////////////////////////

rchandle<xs_anySimpleType> xs_anySimpeType::get_instance()
{
}

bool xs_anySimpeType::is_external() const
{
}

bool xs_anySimpeType::is_complex() const
{
}

bool xs_anySimpeType::is_xs_anySimpleType() const
{
}

bool xs_anySimpeType::is_same_type(schema_type const& other) const
{
}

bool xs_anySimpeType::is_atomic() const
{
}

bool xs_anySimpeType::is_anonymous() const
{
}

bool xs_anySimpeType::is_list() const
{
}

bool xs_anySimpeType::is_namespace_sensitive() const
{
}

int xs_anySimpeType::get_namecode() const
{
}

type::validation_status xs_anySimpeType::get_validation_status() const
{
}

type::derivation_method xs_anySimpeType::get_derivation_method() const
{
}

rchandle<schema_type> xs_anySimpeType::get_base_type() const
{
}

rchandle<schema_type> xs_anySimpeType::get_known_base_type() const
{
}

rchandle<schema_type> xs_anySimpeType::get_builtin_base_type() const
{
}

rchandle<atomic_type> xs_anySimpeType::get_common_atomic_type() const
{
}

std::string xs_anySimpeType::describe() const
{
}

rchandle<item_iterator> xs_anySimpeType::get_typed_value(
	node&)
{
}

rchandle<item_iterator> xs_anySimpeType::atomize(
	node&)
{
}

bool xs_anySimpeType::allows_derivation(
	enum derivation_method) const
{
}

void xs_anySimpleType::check_type_derivation(
	schema_type const& type,
	enum derivation_method)
throw (xqp_exception)
{
}

rchandle<item_iterator> xs_anySimpleType::get_typed_value(
	char const* value,
	rchandle<namespace_resolver>)
{
}

rchandle<validation_error> xs_anySimpleType::validate_content(
	char const* value,
	rchandle<namespace_resolver>)
{
}

void xs_anySimpleType::analyze_content_expression(
	rchandle<expr>, 
	int kind,
	context const&)
{
}




////////////////////////////////
//	xs_anyType
////////////////////////////////

xs_anyType theInstance = new xs_anyType()


rchandle<xs_anyType> xs_anyType::get_instance() const
{
}

int xs_anyType::get_namecode() const
{
}

rchandle<schema_type> xs_anyType::get_base_type() const
{
}

rchandle<schema_type> xs_anyType::get_known_base_type() const
{
}

rchandle<xs_anySimpleType> xs_anyType::get_simple_content_type() const
{
}

bool xs_anyType::is_abstract() const
{
}

bool xs_anyType::is_complex() const
{
}

bool xs_anyType::is_anonymous() const
{
}

bool xs_anyType::is_xs_anySimpleType() const
{
}

bool xs_anyType::is_atomic() const
{
}

bool xs_anyType::is_complex() const
{
}

bool xs_anyType::is_simple_content() const
{
}

bool xs_anyType::is_all_content() const
{
}

bool xs_anyType::is_restricted() const
{
}

bool xs_anyType::is_empty_content() const
{
}

bool xs_anyType::allows_derivation(
	enum type::derivation_method) const
{
}

bool xs_anyType::allows_empty() const
{
}

bool xs_anyType::allows_mixed_content() const
{
}

bool xs_anyType::operator==(schema_type const&) const
{
}

std::string xs_anyType::describe() const
{
}

std::string xs_anyType::subsumes(
	complex_type const&) const
{
}

rchandle<item_iterator> xs_anyType::get_typed_value(
	node&) const
{
}

rchandle<item_iterator> xs_anyType::atomize(
	node&) const
{
}

void xs_anyType::analyze_content_expression(
	rchandle<expr>,
	int kind,
	context&) const
{
}

void check_type_derivation(
	schema_type const&,
	enum derivation_method)
throw (xqp_exception)
{
}

enum derivation_method get_derivation_method() const
{
}



////////////////////////////////
//	xs_untyped
////////////////////////////////

xs_untyped the_instance


xs_untyped xs_untyped::get_instance() const
{
}

type::validation_status xs_untyped::get_validation_status() const
{
}

type::derivation_method xs_untyped::get_derivation_method() const
{
}

type::typecode xs_untyped::get_type() const
{
}

rchandle<simple_type> xs_untyped::get_simple_content_type() const
{
}

rchandle<schema_type> xs_untyped::get_known_base_type() const
{
}

rchandle<schema_type> xs_untyped::get_base_type() const
{
}

bool xs_untyped::is_complex() const
{
}

bool xs_untyped::is_anonymous() const
{
}

bool xs_untyped::is_abstract() const
{
}

bool xs_untyped::is_simple() const
{
}

bool xs_untyped::is_atomic() const
{
}

bool xs_untyped::is_restricted() const
{
}

bool xs_untyped::is_complex_content() const
{
}

bool xs_untyped::is_simple_content() const
{
}

bool xs_untyped::is_all_content() const
{
}

bool xs_untyped::is_empty_content() const
{
}

bool xs_untyped::allows_derivation(
	enum type::derivation_method) const
{
}

bool xs_untyped::allows_empty() const
{
}

bool xs_untyped::allows_mixedContent() const
{
}

std::string xs_untyped::describe() const
{
}

std::string xs_untyped::subsumes(
	complex_type const&)
{
}

void xs_untyped::analyze_expression(
	rchandle<expr> expr,
	int kind,
	context &)
{
}

rchandle<item_iterator> xs_untyped::get_typed_value(
	node&)
{
}

rchandle<item_iteraor> xs_untyped::atomize(
	node &)
{
}




////////////////////////////////
//	atomic_type
////////////////////////////////

rchandle<atomic_value> atomic_type::make_derived_value(
	atomic_value& primValue,
	char const* lexicalValue,
	bool validate)
{
}


////////////////////////////////
//	xs_anyAtomicType
////////////////////////////////

 xs_anyAtoicType::xs_anyAtomicType()
{
}

type::typecode xs_anyAtoicType::get_type() const
{
}

type::typecode xs_anyAtoicType::get_primitive_type() const
{
}

type::validation_status xs_anyAtoicType::get_validation_status() const
{
}

type::derivation_method xs_anyAtoicType::get_derivation_method() const
{
}

bool xs_anyAtoicType::operator==(schema_type const&) const
{
}

bool xs_anyAtoicType::is_complex() const
{
}

bool xs_anyAtoicType::is_anonymous() const
{
}

bool xs_anyAtoicType::is_simple() const
{
}

bool xs_anyAtoicType::is_atomic() const
{
}

bool xs_anyAtoicType::is_list() const
{
}

bool xs_anyAtoicType::is_union() const
{
}

bool xs_anyAtoicType::is_namespace_sensitive() const
{
}

rchandle<item_type> xs_anyAtoicType::get_super_type() const
{
}

rchandle<item_type> xs_anyAtoicType::get_primitive_item_type() const
{
}

rchandle<atomic_type> xs_anyAtoicType::get_common_atomic_type() const
{
}

rchandle<atomic_type> xs_anyAtoicType::get_atomized_item_type() const
{
}

rchandle<schema_type> xs_anyAtoicType::get_known_base_type() const
{
}

rchandle<schema_type> xs_anyAtoicType::get_base_type() const
{
}

std::string xs_anyAtoicType::describe() const
{
}

void xs_anyAtomicType::check_type_derivation(
	schema_type const& type,
	enum derivation_method)
throw (xqp_exception)
{
}

rchandle<item_iterator> xs_anyAtomicType::get_typed_value(node&)
throw (xqp_exception)
{
}

rchandle<item_iterator> xs_anyAtomicType::get_typed_value(
	char const* value,
	rchandle<namespace_resolver> xs_anyAtomicType::resolver)
throw (xqp_exception)
{
}

rchandle<item_iterator> xs_anyAtomicType::atomize(node&)
throw (xqp_exception)
{
}

rchandle<atomic_value> xs_anyAtomicType::make_derived_value(
	atomic_value const&,
	char const* lexicalValue,
	bool validate)
throw (xqp_exception)
{
}

void xs_anyAtomicType::analyze_content_expression(
	rchandle<expr>,
	int kind,
	context&)
throw (xqp_exception)
{
}



////////////////////////////////
//	list_type
////////////////////////////////

rchandle<xs_simple_type> list_type::get_item_type() const
{
}



////////////////////////////////
//	builtin_list_type
////////////////////////////////

enum type::typecode builtin_list_type::get_type() const
{
}

enum type::typecode builtin_list_type::get_primitive_type() const
{
}

enum type::validation_status builtin_list_type::get_validation_status() const
{
}

enum type::derivation_method builtin_list_type::get_derivation_method() const
{
}

bool builtin_list_type::operator==(schema_type const&) const
{
}

bool builtin_list_type::is_complex() const
{
}

bool builtin_list_type::is_anonymous() const
{
}

bool builtin_list_type::is_simple() const
{
}

bool builtin_list_type::is_atomic() const
{
}

bool builtin_list_type::is_list() const
{
}

bool builtin_list_type::is_union() const
{
}

bool builtin_list_type::is_namespace_sensitive() const
{
}


rchandle<item_type> builtin_list_type::get_super_type() const
{
}

rchandle<item_type> builtin_list_type::get_primitive_item_type() const
{
}

rchandle<atomic_type> builtin_list_type::get_common_atomic_type() const
{
}

rchandle<atomic_type> builtin_list_type::get_atomized_item_type() const
{
}

rchandle<schema_type> builtin_list_type::get_known_base_type() const
{
}

rchandle<schema_type> builtin_list_type::get_base_type() const
{
}

std::string builtin_list_type::describe() const
{
}

void builtin_list_type::check_type_derivation(
	schema_type const& type,
	enum derivation_method)
throw (xqp_exception)
{
}

rchandle<item_iterator> builtin_list_type::get_typed_value(node&)
throw (xqp_exception)
{
}

rchandle<item_iterator> builtin_list_type::get_typed_value(
	char const* value,
	rchandle<namespace_resolver> resolver)
throw (xqp_exception)
{
}

rchandle<item_iterator> builtin_list_type::atomize(node&)
throw (xqp_exception)
{
}

rchandle<atomic_value> builtin_list_type::make_derived_value(
	atomic_value const&,
	char const* lexicalValue,
	bool validate)
throw (xqp_exception)
{
}

void builtin_list_type::analyze_content_expression(
	rchandle<expr>,
	int kind,
	context&)
throw (xqp_exception)
{
}

std::string builtin_list_type::get_localname() const
{
}



} /* namespace xqp */

