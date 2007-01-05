/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: types.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_TYPES_H
#define XQP_TYPES_H

#include "data_interface.h"

namespace xqp {

/*______________________________________________________________________
|  
|	 XQuery "sequence type" (class) hierarchy
|  ---------------------------------------
|    item_type
|      xs_anyAtomicType
|      node
|        comment_node
|        document_node
|          [user-defined document types]
|        element_node
|          [user-defined element types]
|        attribute_node
|          [user-defined attribute types]
|        ns_node
|        pi_node
|        text_node
|    
|
|  Schema type (class) hierarchy
|  -----------------------------
|    xs_anyType
|      schema_type [user-defined]
|      xs_xs_untyped
|      xs_anySimpleType
|        list_type [user-defined]
|        xs_IDREFS
|        xs_NMTOKENS
|        xs_ENTITIES
|        xs_anyAtomicType                 C++ type              type code
|          xs_xs_untypedAtomic               --------              ---------
|
|          xs_dateTime                    struct tm             XSD_DATETIME
|          xs_date                        struct tm             XSD_DATE
|          xs_time                        struct tm             XSD_TIME
|          xs_gYearMonth                  struct tm             XSD_GYEARMONTH
|          xs_gYear                       struct tm             XSD_GYEAR
|          xs_gMonthDay                   struct tm             XSD_GMONTHDAY
|          xs_gDay                        struct tm             XSD_GDAY
|          xs_gMonth                      struct tm             XSD_GMONTH
|
|          xs_duration                    long                  XSD_DURATION
|            xs_yearMonthDuration         **                    **
|            xs_dayTimeDuration           **                    **
|
|          xs_float                       float                 XSD_FLOAT
|          xs_double                      double                XSD_DOUBLE
|          xs_decimal                     double                XSD_DECIMAL
|            xs_integer                   long long             XSD_INTEGER
|              xs_nonPositiveInteger      long long             XSD_NONPOSITIVEINTEGER
|                xs_negativeInteger       long long             XSD_NEGATIVEINTEGER
|              xs_long                    long long             XSD_LONG
|                xs_int                   int                   XSD_INT
|                  xs_short               short                 XSD_SHORT
|                    xs_byte              signed char           XSD_BYTE
|              xs_nonNegativeInteger      unsigned long long    XSD_NONNEGATIVEINTEGER
|                xs_unsignedLong          unsigned long long    XSD_UNSIGNEDLONG
|                  xs_unsignedInt         unsigned int          XSD_UNSIGNEDINT
|                    xs_unsignedShort     unsigned short        XSD_UNSIGNEDSHORT
|                      xs_unsignedByte    unsigned char         XSD_UNSIGNEDBYTE
|                xs_positiveInteger       unsigned long long    XSD_POSITIVEINTEGER
|
|          xs_string                      std::string           XSD_STRING
|            xs_normalizedString          std::string           XSD_NORMALIZEDSTRING
|              xs_token                   std::string           XSD_TOKEN
|                xs_language              std::string           XSD_LANGUAGE
|                xs_NMTOKEN               std::string           XSD_NMTOKEN
|                xs_Name                  std::string           XSD_NAME
|                  xs_NCName              std::string           XSD_NCNAME
|                    xs_ID                std::string           XSD_ID
|                    xs_IDREF             std::string           XSD_IDREF
|                    xs_ENTITY            std::string           XSD_ENTITY
|
|          xs_boolean                     bool                  XSD_BOOLEAN
|          xs_base64Binary                struct xsd_base64Binary XSD_BASE64BINARY
|          xs_hexBinary                   struct xsd_hexBinary  XSD_HEXBINARY
|          xs_anyURI                      std::string           XSD_ANYURI
|          xs_QName                       std::string           XSD_QNAME
|          xs_NOTATION                    std::string           XSD_NOTATION
|
|
|  The two type hierarchies intersect at 'anyAtomicType'.
|  The two hierarchies overlap at (Schema):
|    'user-defined complex types',
|  versus (XQuery):
|    'user-defined attribute types'
|    'user-defined element types'.
|
|  XQuery SequenceType syntax distinguishes these cases with:
|    element(elem-name,type-name)
|    attribute(attr-name,type-name)
|  versus
|    schema-element(elem-name)
|    schema-attribute(attr-name).
|		
|_______________________________________________________________________*/




/*______________________________________________________________________
|  
| This class contains static information about types.
|_______________________________________________________________________*/

class type
{
private :
	type() {}

public:
	static bool is_node_type(item_type&);

	enum typecode {
		ANY_ATOMIC,
		YEAR_MONTH_DURATION,
		DAY_TIME_DURATION,
		BINARY,

		ANYTYPE,
		UNTYPED,
		ANY_SIMPLE_TYPE,
		ANY_ATOMIC_TYPE,
		UNTYPED_ATOMIC,

		BOOLEAN,
		HEX_BINARY,
		BASE64_BINARY,

		DATE_TIME,
		TIME,
		DATE,

		G_YEAR_MONTH,
		G_YEAR,
		G_MONTH_DAY,
		G_DAY,
		G_MONTH,

		DURATION,
		YEAR_MONTH_DURATION,
		DAY_TIME_DURATION

		NUMERIC,
		INTEGER,
		DECIMAL,
		FLOAT,
		DOUBLE,
		NON_POSITIVE_INTEGER,
		NEGATIVE_INTEGER,
		LONG,
		INT,
		SHORT,
		BYTE,
		NON_NEGATIVE_INTEGER,
		POSITIVE_INTEGER,
		UNSIGNED_LONG,
		UNSIGNED_INT,
		UNSIGNED_SHORT,
		UNSIGNED_BYTE,

		STRING,
		ANY_URI,
		QNAME,
		NOTATION,
		NORMALIZED_STRING,
		TOKEN,
		LANGUAGE,
		NMTOKEN,
		NMTOKENS,
		NAME,
		NCNAME,
		ID,
		IDREF,
		IDREFS,
		ENTITY,
		ENTITIES
	};


	static BuiltInAtomicType UNTYPED_ATOMIC_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XDT_UNTYPED_ATOMIC);

	static BuiltInAtomicType ANY_ATOMIC_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XDT_ANY_ATOMIC_TYPE);

	static BuiltInAtomicType YEAR_MONTH_DURATION_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XDT_YEAR_MONTH_DURATION);

	static BuiltInAtomicType DAY_TIME_DURATION_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XDT_DAY_TIME_DURATION);


	static BuiltInAtomicType STRING_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_STRING);

	static BuiltInAtomicType BOOLEAN_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_BOOLEAN);

	static BuiltInAtomicType DECIMAL_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_DECIMAL);

	static BuiltInAtomicType FLOAT_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_FLOAT);

	static BuiltInAtomicType DOUBLE_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_DOUBLE);

	static BuiltInAtomicType DURATION_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_DURATION);

	static BuiltInAtomicType DATE_TIME_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_DATE_TIME);

	static BuiltInAtomicType TIME_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_TIME);

	static BuiltInAtomicType DATE_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_DATE);

	static BuiltInAtomicType G_YEAR_MONTH_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_G_YEAR_MONTH);

	static BuiltInAtomicType G_YEAR_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_G_YEAR);

	static BuiltInAtomicType G_MONTH_DAY_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_G_MONTH_DAY);

	static BuiltInAtomicType G_DAY_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_G_DAY);

	static BuiltInAtomicType G_MONTH_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_G_MONTH);

	static BuiltInAtomicType HEX_BINARY_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_HEX_BINARY);

	static BuiltInAtomicType BASE64_BINARY_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_BASE64_BINARY);

	static BuiltInAtomicType ANY_URI_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_ANY_URI);

	static BuiltInAtomicType QNAME_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_QNAME);

	static BuiltInAtomicType NOTATION_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_NOTATION);

	static BuiltInAtomicType INTEGER_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_INTEGER);

	static BuiltInAtomicType ID_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_ID);

	static BuiltInAtomicType IDREF_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_IDREF);

	static BuiltInAtomicType NCNAME_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XS_NCNAME);

	static BuiltInAtomicType NUMBER_TYPE =
	    BuiltInSchemaFactory.getSchemaType(XDT_NUMERIC);



	/**
	 * Get the item_type of an item
	 */
	static item_type get_item_type(item const&);

	/**
	 * Output (for diagnostics) a representation of the type of an item. This
	 * does not have to be the most specific type
	 */
	static std::string display_typename(item const&);

	/**
	 * Get the relationship of two schema types to each other
	 */
	static int schema_type_relationship(
		schema_type const& s1,
		schema_type const& s2);

	/**
	 * Get a type that is a common supertype of two given types
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @return the item type that is a supertype of both item types
	 */
	static ItemType getCommonSuperType(
		item_type const& t1,
		item_type const& t2);

	/**
	 * Determine whether this type is a primitive type. The primitive
	 * types are:
	 *   19 primitive types of XML Schema,
	 *   xs:integer, 
	 *   xdt:dayTimeDuration,
	 *   xdt:yearMonthDuration,
	 *   xdt:xs_untypedAtomic,
	 *   the 7 node kindas,
	 *   all supertypes of these (item(), node(), xdt:anyAtomicType, xdt:number, ...) 
	 *
	 * @param code the item type code to be tested
	 * @return true if the type is considered primitive under the above rules
	 */
	static bool is_primitive(enum typecode);

	/**
	 * Determine whether two primitive atomic types are comparable
	 * @param t1 - the first type to compared.  This must be a primitive
	 *    atomic type as defined by ItemType::getPrimitiveType
	 * @param t2 - the second type to compared.  This must be a primitive
	 *    atomic type as defined by ItemType::getPrimitiveType
	 * @param ordered - true, if testing for an ordering comparison (lt, gt, le, ge)
	 *                  false, if testing for an equality comparison (eq, ne)
	 * @return true - if the types are comparable, as defined by the rules of
	 *    the "eq" operator
	 */
	static bool is_comparable(
		enum typecode t1,
		enum typecode t2,
		bool ordered);

	/**
	 * Determine whether a primitive type is ordered. Note that the rules for
	 * this differ between XPath and XML Schema: these are the XPath rules.
	 * @param type - the primitive item type being tested
	 * @return - true, if the types are potentially comparable. For abstract
	 *    types (type=ATOMIC) we give the benefit of the doubt and return true.
	 */
	static bool is_ordered(enum typecode);

	/**
	 * Test whether the supplied type, which must be a primitive type, is one of
	 * the numeric primitive types
	 * @param t - the type being tested
	 * @return - true, if the type is integer, double, float, decimal, or
	 *    the abstract type "numeric"
	 */
	static bool is_numeric_primitive(item_type const& t);


	enum type_relation {
		SAME_TYPE,		// A is the same type as B
		SUBSUMES,			// A subsumes B         (all B are A)
		SUBSUMED_BY,	// A is subsumed by B   (all A are B)
		OVERLAPS,			// A overlaps B         (some A are B)
		DISJOINT			// A is disjoint from B (no A are B)
	};

	/**
	 * Determine whether type A is type B or one of its subtypes.
	 * @param subtype identifies the first type
	 * @param supertype identifies the second type
	 * @return - true, if t1 = t2, or t1 is a direct or indirect subtype of t2
	 */
	static bool is_subtype(
		item_type const& t1,
		item_type const& t2);

	/**
	 * Determine the relationship of one item type to another.
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @return type_relation
	 */
	static enum type_relation relationship(
		item_type const& t1,
		item_type const& t2);

	/**
	 * Test whether a type annotation code represents the type xs:ID or
	 * one of its subtypes
 	 */
	static bool is_ID(enum typecode);

	/**
	 * Test whether a type annotation code represents the type 
	 * xs:IDREF, xs:IDREFS or one of their subtypes 
	 */
	static bool is_IDREFS(enum typecode);

};





/*______________________________________________________________________
|  
|	Base class for the XQuery type hierarchy.
|
|	item_type represents the XQuery types:
|		item()			- matches everything
|		node()			- matches nodes
|		atomicType	- matches atomic values
|		empty()			- matches nothing.
|
|	Atomic types descend from the class atomicType; they are
|	also instances of simpleType in the Schema type heirarchy.
|_______________________________________________________________________*/

class item_type
{
	/**
	 * Determine whether this item type is atomic.
	 * @return - true, if this is ANY_ATOMIC_TYPE or a subtype
	 */
	bool is_atomic_type() const;

	/**
	 * Test whether a given item conforms to this type
	 * @param item - The item to be tested
	 * @param allowURIPromotion -
	 * @param config -
	 * @return - true, if the item is an instance of this types
	 *					 false, otherwise
	*/
	bool matches_item(
		item const& item,
		bool allow_URI_promotion,
		config& config) const;

	/**
	 * Get the type from which this item type is derived by restriction.
	 * This is the supertype in the XQuery type heirarchy.
	 * The concept of "supertype" is not really well-defined, because 
	 * the types form a lattice rather than a hierarchy. The only real 
	 * requirement on this function is that it returns a type that strictly 
	 * subsumes this type, ideally as narrowly as possible. 
	 *
	 * @return -- the supertype, or NULL if this type is item()
	 */
	rchandle<item_type> get_supertype() const;

	/**
	 * Get the primitive item type corresponding to this item type.
	 */
	rchandle<item_type> get_primitive_type() const;

	/**
	 * Get the primitive type corresponding to this item type.
	 *	item() 							- Type.ITEM
	 *	node()							- Type.NODE
	 *	specific node kinds - the value representing the node kind,
	 *	anyAtomicValue			- Type.ATOMIC_VALUE,
	 *	numeric							- Type.NUMBER,
	 *	other atomic types	-  the primitive Schema type 
	 */
	int get_primitive_typecode() const;

	/**
	 * Produce a representation of this type name for use in error messages.
	 * Where this is a QName, it will use conventional prefixes
	 */
	std::string describe() const;

	/**
	 * Get the item type of the atomic values that will be produced when 
	 * an item of this type is atomized
	 */
	rchandle<xs_anyAtomicType> get_atomized_type() const;

};



/*______________________________________________________________________
|  
|	An implementation of item_type that matches any
|	item (node or atomic value).
|_______________________________________________________________________*/

class any_item_type : public item_type
{
protected:
	static any_item_type the_instance;

private:
	any_item_type() {}
	~any_item_type() {}

public:
	static rchandle<any_item_type> get_instance();
	bool is_atomic_type() const { return false; }

	bool matches_item(
		item const& item,
		bool allow_URI_promotion,
		config const& config)
	{
	    return true;
	}

	rchandle<item_type> get_supertype() { return NULL; }
	rchandle<item_type> get_primitive_type() const;
	int get_primitive_typecode() const;
	rchandle<xs_anyAtomicType> get_atomized_type() const;
	std::string describe();

};



/*______________________________________________________________________
|  
| A stub interface that represents any "schema component" as defined
| in the XML Schema specification. This may be a user-defined schema
| component or a built-in schema component.
|_______________________________________________________________________*/

class schema_component
{
public:
	enum validation_status
	{
		UNVALIDATED,		// not yet validated
		FIXED_UP,				// all references to other components resolved
		VALIDATING,			// currently being validated
		VALIDATED,			// successfully validated
		INVALID,				// validation failed with fatal errors
		INCOMPLETE,			// validation stopped with unresolved components
	};

	/**
	 * Get the validation status of this component.
	 * @return - validation status
	 */
	enum validation_status get_validation_status() const;

};



/*______________________________________________________________________
|  
|	Base class for the Schema hierarchy: simple and complex types,
|	built-in, and user-defined types. 
| 
| There is a hierarchy of interfaces that extend schema_type, 
| representing the top levels of the schema type system:
|
|		xs_anySimpleType 
|			Lists and Unions
|			complexType
| 	atomic types. 
| 
| The implementations of these interfaces are organized into a different 
| hierarchy: on the one side, built-in types such as anyType, 
| anySimpleType, and the built-in atomic types and list types; on the 
| other side, user-defined types defined in a schema.
|_______________________________________________________________________*/

class schema_type : public schema_component
{
	enum derivation_method {
	/**
	 * If the document's schema is an XML Schema this constant represents the 
	 * derivation by type restriction if complex types are involved, or a 
	 * element restriction if simple types are involved. 
	 *
	 * T1 is derived by restriction from T2 if:
	 *   T1 is the same as T2, or
	 *   T1 can be reached recursively following the base type
	 *      definition property from T2, and all the derivation
	 *      methods involved are restriction. 
	 */
		DERIVATION_RESTRICTION			= 0x01,

	/**
	 * If the document's schema is an XML Schema this constant represents
	 * the derivation by type extension.
	 *
	 * T1 is derived by extension from T2 if:
	 *   T1 is the same as T2, or
	 *   T1 can be reached recursively following the base type
	 *      definition property from T2, and at least one derivation
	 *      methods involved is extension. 
	 */
		DERIVATION_EXTENSION				= 0x02,

	/**
	 * If the document's schema is an XML Schema this constant represents
	 * the union, if simple types are involved.
	 *
	 * T1 is derived by union from T2 if:
	 *   there exists two type definitions T1' and T2' such that
	 *   T1' is derived from T1 by DERIVATION_RESTRICTION  or DERIVATION_EXTENSION,
	 *   T2' is derived from T2 by DERIVATION_RESTRICTION,
	 *   T1' has variety union, and one of the member type definitions is T2.
	 * Note that T1' could be the same as T1, and T2' could be the same as T2.
	 */
		DERIVATION_UNION						= 0x04,

	/**
	 * If the document's schema is an XML Schema this constant represents
	 * the list.
	 *
	 * T1 is derived by list from T2 if:
	 *   there exists two type definitions T1' and T2' such that
	 *   T1' is derived from T1 by DERIVATION_RESTRICTION or DERIVATION_EXTENSION,
	 *   T2' is derived from T2 by DERIVATION_RESTRICTION,
	 *   T1' has variety list, and T2' is the item type definition.
	 * Note that T1' could be the same as T1, and T2' could be the same as T2.
	 */
		DERIVATION_LIST							= 0x08,

	/**
	 * Derivation by substitution.
	 * This constant, unlike the others, is NOT defined in the DOM level 3 
	 * TypeInfo interface. 
	 */
		DERIVE_BY_SUBSTITUTION			= 0x10
	};



	/**
	 * Get the type code of this type.
	 */
	enum type::typecode get_type() const;

	/**
	 * Test this schema_type for equality
	 */
	bool operator==(schema_type const& other);

	/**
	 * Test if this schema_type is complex 
	 * @return - true, if this schema_type is a complex type
	 */
	bool is_complex() const;

	/**
	 * Test fi this schema_type simple
	 * @return - true, if this schema_type is a simple type
	 */
	bool is_simple() const;

	/**
	 * Test if schema_type is atomic 
	 * @return - true, if this schema_type is an atomic type
	 */
	bool is_atomic() const;

	/**
	 * Test if this schema_type is anonymous
	 * @return true if this schema_type is an anonymous type
	 */
	bool is_anonymous() const;

	/**
	 * Return the base type that this type inherits from;
	 * return NULL for xs_ primitive types. 
	 * @return - base type
	 * @throws - xqp_exception, if this type is not valid
	*/
	rchandle<schema_type> get_base_type() const
	throws xqp_exception;

	/**
	 * Get the integer code of the derivation method used to derive this type.
	 * @return - derivation method
	 */
	enum derivation_method get_derivation_method() const;

	/**
	 * Determine whether a specific derivation from this type is allowed.
	 * @param derivation - the kind of derivation
	 * @return - true, if this kind of derivation is allowed
	 */
	bool allows_derivation(
		enum derivation_method derivation) const;

	/**
	 * Analyze an expression to see if it can deliver a value of this type. 
	 * @param expr - expression that delivers the content
	 * @param kind - node kind whose content is being delivered
	 * @param ctx  - evaluation context for the query
	 * @throw xqp_exception - if the expression will never deliver a value of 
	 *            the correct type 
	 */
	void analyze_expression(
		rchandle<expr> expr,
		int kind,
		context const& ctx) const
	throw (xqp_exception);

	/**
	 * Get the typed value of a node annotated with this schema type. 
	 * @param node - node whose typed value is required
	 * @return - item_iterator over atomic values
	 */
	rchandle<item_iterator> get_typed_value(node const&) const
	throw (xqp_exception);

	/**
	 * Get the typed value of a node annotated with this schema type. 
	 * @param node - node whose typed value is required
	 * @return - iterator for typed value. 
	 */
	rchandle<item_iterator> atomize(node const&) const
	throw (xqp_xception);

	/**
	 * Get a description of this type.
	 * @return - text identifing the type
	 */
	std::string describe() const;

};



/*______________________________________________________________________
|  
|	The class 'simple_type' represents a simple type, which may be
| a	built-in simple type (xs:anySimpleType), or a user-defined
| simple type. 
|_______________________________________________________________________*/

class simple_type : public schema_type
{
	/**
	 * Test whether this simple_type is an atomic type
	 * @return - true, if this is an atomic type
	 */
	bool is_atomic() const;

	/**
	 * Test whether this simple_type is a list type
	 * @return - true, if this is a list type
	 */
	bool is_list() const;

	/**
	 * Test whether this simple_type is a union type
	 * @return - true, if this is a union type
	 */
	bool is_union() const;

	/**
	 * Get the most specific atomic type for the items in this simple_type
	 * @return - lowest common supertype of all member types
	 */
	rchandle<atomic_type> get_common_atomic_type() const;

	/**
	 * Get the built-in type from which this type is derived by restriction
	 * @return - built-in type from which this type is derived by restriction
	 */
	rchandle<schema_type> get_builtin_base_type() const;

	/**
	 * Get the typed value corresponding to a given string value, assuming it is
	 * valid against this type.
	 * @param value - string value
	 * @param resolver - namespace resolver used to resolve any namespace
	 *    prefixes appearing in the content of values. Can supply NULL, in
	 *    which case any namespace-sensitive content will be rejected.
	 * @return - iterator over the atomic sequence comprising the typed value.
	 *    The objects returned by this iterator will all be of type atomic_value
	 * @throws xqp_exception - if the supplied value is not in the lexical space
	 *    of the data type
	 */
	rchandle<item_iterator> get_typed_value(
		char const* value,
		rchandle<NamespaceResolver>)
	throw (xqp_exception);

	/**
	 * Check whether a given input string is valid according for this simple_type
	 * @param value - input string to be checked
	 * @param resolver - namespace resolver used to resolve namespace prefixes
	 *    if the type is namespace sensitive. The value supplied may be NULL;
	 *    in this case any namespace-sensitive content will throw an exception.
	 * @return - NULL, if validation succeeds,
	 *           ValidationError, if validation fails
	 * @throw xqp_exception - if the type is namespace-sensitive
	 *    and no namespace resolver is supplied
	 */
	rchandle<validation_error> validate_content(
		char const* value,
		rchandle<namespace_resolver>)
	throw (xqp_exception);

	/**
	 * Test whether this type is namespace sensitive, that is, if a namespace
	 * context is needed to translate between the lexical space and the value
	 * space. This is true for types derived from, or containing, QNames and
	 * NOTATIONs.
	 * @return true if the type is namespace-sensitive
	 */
	bool is_namespace_sensitive() const;

};




/*______________________________________________________________________
|  
|	A complex type as defined in XML Schema: either a user-defined
|	complex type, or xs:anyType.
|_______________________________________________________________________*/

class complex_type : public schema_type
{
	/**
	 * Test if this complex type has been marked abstract.
	 * @return true if this complex type is abstract.
	 */
	bool is_abstract() const;

	/**
	 * Test whether this complex type has complex content
	 * @return - true, if this complex type has a complex content model,
	 *           false, if it has a simple content model 
	 */
	bool is_complex_content() const;

	/**
	 * Test whether this complex type has simple content
	 * @return true if this complex type has a simple content model,
	 *         false if it has a complex content model
	 */
	bool is_simple_content() const;

	/**
	 * Test whether this complex type has "all" content, that is,
	 * a content model using an xs:all compositor
	 */
	bool is_all_content() const;

	/**
	 * Get the simple content type
	 * @return For complex type with simple content, return the content 
	 * simple type, otherwise, return NULL. 
	 */
	rchandle<simple_type> get_simple_content_type() const;

	/**
	 * Test whether this complex type is derived by restriction
	 * @return true if this complex type is derived by restriction
	 */
	bool is_restricted() const;

	/**
	 * Test whether the content model of this complex type is empty
	 * @return true if the content model is defined as empty
	 */
	bool is_empty_content() const;

	/**
	 * Test whether the content model of this complex type allows empty 
	 * content 
	 * @return true if empty content is valid
	 */
	bool allows_empty() const;

	/**
	 * Test whether this complex type allows mixed content
	 * @return true if mixed content is allowed
	 */
	bool allows_mixed_content() const;

	/**
	 * Test whether this complex type subsumes another complex type.
	 * @param sub - the other type (the type that is derived by restriction, 
	 *         validly or otherwise) 
	 * @return - true, if this type does subsume the other
	 *           false, if not
	 */
	bool subsumes(rchandle<complex_type>);

};



/*______________________________________________________________________
|  
|	This class has a singleton instance which represents the XML Schema
|	built-in type xs:anySimpleType
|_______________________________________________________________________*/

class xs_anySimpleType : public simple_type, xs_anyType
{
protected:
	static xs_anySimpleType the_instance;

private:
	xs_anySimpleType() {}
	~xs_anySimpleType() {}

public:
	static rchandle<xs_anySimpleType> get_instance();

	bool is_external() const;
	bool is_complex() const;
	bool is_xs_anySimpleType() const;

	bool is_same_type(schema_type const& other) const;

	bool is_atomic() const;
	bool is_anonymous() const;
	bool is_list() const;
	bool is_namespace_sensitive() const;

	int get_namecode() const;
	enum validation_status get_validation_status() const;
	enum derivation_method get_derivation_method() const;
	enum whitespace_action get_whitespace_action() const;

	rchandle<schema_type> get_base_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<schema_type> get_builtin_base_type() const;
	rchandle<atomic_type> get_common_atomic_type() const;

	std::string describe() const;

	rchandle<item_iterator> get_typed_value(node&);
	rchandle<item_iterator> atomize(node&);

	bool allows_derivation(
		enum derivation_method) const;

	void check_type_derivation(
		schema_type const& type,
		enum derivation_method)
	throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(
		char const* value,
		rchandle<namespace_resolver>);

	rchandle<validation_error> validate_content(
		char const* value,
		rchandle<namespace_resolver>);

	void analyze_content_expression(
		rchandle<expr>, int kind, context const&);

};



/*______________________________________________________________________
|  
|	This class has a singleton instance which represents the XML Schema
|	built-in type xs:anyType, also known as the UR-type.
|_______________________________________________________________________*/

class xs_anyType : public complex_type
{
private:
	static xs_anyType theInstance = new xs_anyType();
	xs_anyType() {}

public:
	static rchandle<xs_anyType> get_instance() const;

	int get_namecode() const;

	rchandle<schema_type> get_base_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<xs_anySimpleType> get_simple_content_type() const;

	bool is_abstract() const;
	bool is_complex() const;
	bool is_anonymous() const;
	bool is_xs_anySimpleType() const;
	bool is_atomic() const;
	bool is_complex() const;
	bool is_simple_content() const;
	bool is_all_content() const;
	bool is_restricted() const;
	bool is_empty_content() const;

	bool allows_derivation(enum type::derivation_method) const;
	bool allows_empty() const;
	bool allows_mixed_content() const;

	bool operator==(schema_type const&) const;

	std::string describe() const;
	std::string subsumes(complex_type const&) const;
	rchandle<item_iterator> get_typed_value(node&) const;
	rchandle<item_iterator> atomize(node&) const;

	void analyze_content_expression(
		rchandle<expr>, int kind, context&) const;

	void check_type_derivation(
		schema_type const&,
		enum derivation_method)
	throw (xqp_exception);

	enum derivation_method get_derivation_method() const;

};




/*______________________________________________________________________
|  
| This class has a singleton instance which represents the complex type 
| dt:xs_untyped, used for elements that have not been validated. 
|_______________________________________________________________________*/

class xs_untyped : public xs_anyType
{
private:
	static xs_untyped the_instance;
	xs_untyped() {}

public:
	static xs_untyped get_instance() const;

	enum type::validation_status get_validation_status() const;
	enum type::derivation_method get_derivation_method() const;
	enum type::typecode get_type() const;

	rchandle<simple_type> get_simple_content_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<schema_type> get_base_type() const;

	bool is_complex() const;
	bool is_anonymous() const;
	bool is_abstract() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_restricted() const;
	bool is_complex_content() const;
	bool is_simple_content() const;
	bool is_all_content() const;
	bool is_empty_content() const;

	bool allows_derivation(enum type::derivation_method) const;
	bool allows_empty() const;
	bool allows_mixedContent() const;

	std::string describe() const;
	std::string subsumes(complex_type const&);

	void analyze_expression(
		rchandle<expr> expr,
		int kind,
		context &);

	rchandle<item_iterator> get_typed_value(node&);
	rchandle<item_iteraor> atomize(node &);

};



/*______________________________________________________________________
|  
| Stub interface for atomic types (these are either built-in atomic 
| types or user-defined atomic types). An atomic_type is both an
|   item_type   (a possible type for items in a sequence) and a
|   schema_type (a possible type for validating and annotating nodes). 
|_______________________________________________________________________*/

class atomic_type : public xs_anySimpleType, item_type
{
	/**
	 * Factory method to create values of a derived atomic type. This method
	 * is not used to create values of a built-in type, even one that is not
	 * primitive.
	 * @param primValue the value in the value space of the primitive type
	 * @param lexicalValue the value in the lexical space. If NULL, the
	 *    string value of primValue is used. This value is checked against
	 *    the pattern facet (if any)
	 * @param validate - true, if the value is to be validated against the
	 *                     facets of the derived type;
	 *                   false, if the caller knows that the value is already valid.
	 *
	 * @return - derived atomic value if validation succeeds, or an ErrorValue
	 *    otherwise. The ErrorValue encapsulates the exception that occurred;
	 *    it is the caller's responsibility to check for this.
	 */
	rchandle<atomic_value> make_derived_value(
		atomic_value& primValue,
		char const* lexicalValue,
		bool validate);

};




/*______________________________________________________________________
|  
| This class represents a built-in atomic type, which may be either a 
| primitive type (such as xs:decimal or xs:anyURI) or a derived type 
| (such as xs:ID or xdt:dayTimeDuration).
|_______________________________________________________________________*/

class xs_anyAtomicType : public atomic_type
{
public:
	xs_anyAtomicType();

public:
	enum type::typecode get_type() const;
	enum type::typecode get_primitive_type() const;
	enum type::validation_status get_validation_status() const;
	enum type::derivation_method get_derivation_method() const;

	bool operator==(schema_type const&) const;

	bool is_complex() const;
	bool is_anonymous() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_list() const;
	bool is_union() const;
	bool is_namespace_sensitive() const;

	rchandle<item_type> get_super_type() const;
	rchandle<item_type> get_primitive_item_type() const;
	rchandle<atomic_type> get_common_atomic_type() const;
	rchandle<atomic_type> get_atomized_item_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<schema_type> get_base_type() const;

	std::string describe() const;

	void check_type_derivation(
		schema_type const& type,
		enum derivation_method)
	throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(node&)
	throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(
		char const* value,
		rchandle<namespace_resolver> resolver)
	throw (xqp_exception);

	rchandle<item_iterator> atomize(node&)
	throw (xqp_exception);

	rchandle<atomic_value> make_derived_value(
		atomic_value const&,
		char const* lexicalValue,
		bool validate)
	throw (xqp_exception);

	void analyze_content_expression(
		rchandle<expr>,
		int kind,
		context&)
	throw (xqp_exception);

};



/*______________________________________________________________________
|  
| Interface representing a simple type List
|_______________________________________________________________________*/

class list_type : public simple_type
{
	/**
	 * Return the xs_anySimpleType of the items in this list_type.
	 * This method assumes that the item type has been fully resolved.
	 * @return - xs_anySimpleType of the items in this list-type.
	 * @throw - xqp_exception, if the item type has not been fully resolved
	*/
	rchandle<xs_simple_type> get_item_type();

};



/*______________________________________________________________________
|  
| Class implementing built-in list types NMTOKENS, ENTITIES, IDREFS.
| Also represents the anonymous type of the xsi:schemaLocation attribute
| a list of xs:anyURI values).
|_______________________________________________________________________*/

class builtin_list_type : public list_type
{
protected:
	private BuiltInAtomicType itemType = null;

public:
	enum type::typecode get_type() const;
	enum type::typecode get_primitive_type() const;
	enum type::validation_status get_validation_status() const;
	enum type::derivation_method get_derivation_method() const;

	bool operator==(schema_type const&) const;

	bool is_complex() const;
	bool is_anonymous() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_list() const;
	bool is_union() const;
	bool is_namespace_sensitive() const;

	rchandle<item_type> get_super_type() const;
	rchandle<item_type> get_primitive_item_type() const;
	rchandle<atomic_type> get_common_atomic_type() const;
	rchandle<atomic_type> get_atomized_item_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<schema_type> get_base_type() const;

	std::string describe() const;

	void check_type_derivation(
		schema_type const& type,
		enum derivation_method)
	throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(node&)
	throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(
		char const* value,
		rchandle<namespace_resolver> resolver)
	throw (xqp_exception);

	rchandle<item_iterator> atomize(node&)
	throw (xqp_exception);

	rchandle<atomic_value> make_derived_value(
		atomic_value const&,
		char const* lexicalValue,
		bool validate)
	throw (xqp_exception);

	void analyze_content_expression(
		rchandle<expr>,
		int kind,
		context&)
	throw (xqp_exception);

	std::string get_localname() const;

};


} /* namespace xqp */
#endif /* XQP_TYPES_H */

