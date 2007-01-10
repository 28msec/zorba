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

#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

namespace xqp {

/*______________________________________________________________________
|  
|	 XQuery "sequence type" hierarchy
|  --------------------------------
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
|  Schema type hierarchy
|  ---------------------
|    xs_anyType
|      schema_type [user-defined]
|      xs_untyped
|      xs_anySimpleType
|        list_type [user-defined]
|        xs_IDREFS
|        xs_NMTOKENS
|        xs_ENTITIES
|        xs_anyAtomicType                 C++ type              type name
|          xs_untypedAtomic               --------              ---------
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
|            xs_yearMonthDuration         long                  XSD_YEARMONTH_DURATION
|            xs_dayTimeDuration           long                  XSD_DAYTIME_DURATION
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
|
|  The two hierarchies overlap at
|    (Schema): user-defined complex types,
|    (XQuery): user-defined {attribute,element} types.
|  XQuery SequenceType syntax distinguishes these cases with:
|    element(elem-name,type-name),
|    attribute(attr-name,type-name),
|  versus
|    schema-element(elem-name),
|    schema-attribute(attr-name).
|		
|_______________________________________________________________________*/



// forward references
class item;
class item_type;
class schema_type;
class context;
class xs_anyAtomicType;
class atomic_type;


/*______________________________________________________________________
|  
| This class contains static information about types.
|_______________________________________________________________________*/

class type : public rcobject
{
protected:
	type() {}
	~type() {}

public:
	enum typecode {
		ITEM_TYPE, NODE_TYPE, BINARY, XS_ANY_ATOMIC, XS_ANYTYPE, XS_UNTYPED, 
		XS_ANYSIMPLETYPE, XS_ANYATOMICTYPE, XS_UNTYPED_ATOMIC, XS_BOOLEAN, 
		XS_HEXBINARY, XS_BASE64BINARY, XS_DATETIME, XS_TIME, XS_DATE, 
		XS_GYEARMONTH, XS_GYEAR, XS_GMONTHDAY, XS_GDAY, XS_GMONTH, 
		XS_DURATION, XS_YEARMONTH_DURATION, XS_DAYTIME_DURATION, NUMERIC, 
		XS_INTEGER, XS_DECIMAL, XS_FLOAT, XS_DOUBLE, XS_NON_POSITIVE_INTEGER, 
		XS_NEGATIVE_INTEGER, XS_LONG, XS_INT, XS_SHORT, XS_BYTE, 
		XS_NON_NEGATIVE_INTEGER, XS_POSITIVE_INTEGER, XS_UNSIGNED_LONG, 
		XS_UNSIGNED_INT, XS_UNSIGNED_SHORT, XS_UNSIGNED_BYTE, XS_STRING, 
		XS_ANYURI, XS_QNAME, XS_NOTATION, XS_NORMALIZED_STRING, XS_TOKEN, 
		XS_LANGUAGE, XS_NMTOKEN, XS_NMTOKENS, XS_NAME, XS_NCNAME, XS_ID, 
		XS_IDREF, XS_IDREFS, XS_ENTITY, XS_ENTITIES, BUILTIN_LIST 
	};

	enum type_relation {	
		SAME_TYPE,		// A = B, A is the same type as B
		SUBTYPE, 			// A < B, all A are B
		SUPERTYPE,  	// A > B, all B are A
		OVERLAPS,			// A overlaps B, some A are B
		DISJOINT			// A is disjoint from B, no A are B
	};

	// singleton instances
	/*
	static xs_anyAtomicType UNTYPED_ATOMIC_TYPE;
	static xs_anyAtomicType ANY_ATOMIC_TYPE;
	static xs_anyAtomicType YEAR_MONTH_DURATION_TYPE;
	static xs_anyAtomicType DAY_TIME_DURATION_TYPE;
	static xs_anyAtomicType STRING_TYPE;
	static xs_anyAtomicType BOOLEAN_TYPE;
	static xs_anyAtomicType DECIMAL_TYPE;
	static xs_anyAtomicType FLOAT_TYPE;
	static xs_anyAtomicType DOUBLE_TYPE;
	static xs_anyAtomicType DURATION_TYPE;
	static xs_anyAtomicType DATE_TIME_TYPE;
	static xs_anyAtomicType TIME_TYPE;
	static xs_anyAtomicType DATE_TYPE;
	static xs_anyAtomicType G_YEAR_MONTH_TYPE;
	static xs_anyAtomicType G_YEAR_TYPE;
	static xs_anyAtomicType G_MONTH_DAY_TYPE;
	static xs_anyAtomicType G_DAY_TYPE;
	static xs_anyAtomicType G_MONTH_TYPE;
	static xs_anyAtomicType HEX_BINARY_TYPE;
	static xs_anyAtomicType BASE64_BINARY_TYPE;
	static xs_anyAtomicType ANY_URI_TYPE;
	static xs_anyAtomicType QNAME_TYPE;
	static xs_anyAtomicType NOTATION_TYPE;
	static xs_anyAtomicType INTEGER_TYPE;
	static xs_anyAtomicType ID_TYPE;
	static xs_anyAtomicType IDREF_TYPE;
	static xs_anyAtomicType NCNAME_TYPE;
	static xs_anyAtomicType NUMBER_TYPE;
	static bool types_initialized;
	*/

	// Get the item type of an item.
	static item_type const* get_item_type(item const*);

	// Get the typecode if an item.
	static typecode get_typecode(item const*);

	// Output a string describing the type of an item.
	static std::string describe(item const*);

	// Get the relationship of two schema types.
	static type_relation schema_type_relation(
		schema_type const& s1,
		schema_type const& s2);

	// Get the relationship of two item types.
	static type_relation type_relation(
		item_type const& t1,
		item_type const& t2);

	// Return true if t1 < t2 in the type hierarchy
	static bool is_subtype(
  	item_type const& t1,
	  item_type const& t2);

	// Return true if an item type is one of the node types.
	static bool is_node(item_type const&);

	// Determine whether an item type is primitive.
	static bool is_primitive(item_type const&);

	// Determine whether a primitive type is ordered.
	static bool is_ordered(typecode);

	// Test whether a primitive type is a numeric types
	static bool is_numeric(typecode);

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

class item_type : public type
{
protected:
	type::typecode code;

public:
	item_type() {}
	virtual ~item_type() {}

public:
	// Determine whether this item type is atomic.
	virtual bool is_atomic_type() const;

	// Test whether a given item conforms to this type
	virtual bool matches(item const*, context const*) const;

	// Get the type from which this item type is derived by restriction.
	virtual item_type const* get_supertype() const;

	// Get the primitive item type corresponding to this item type.
	virtual item_type const* get_primitive_type() const;

	// Get the typecode corresponding to this item type.
	virtual type::typecode get_typecode() const;

	// Get the atomic type produced when an item of this type is atomized.
	virtual xs_anyAtomicType const* get_atomized_type() const;

	// Output a string describing this type.
	virtual std::string describe() const;

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

protected:
	any_item_type() {}
	~any_item_type() {}

public:
	static any_item_type const& get_instance();

	bool is_atomic_type() const;
	bool matches(item const*, context const*) const;

	item_type const* get_supertype() const;
	item_type const* get_primitive_type() const;
	xs_anyAtomicType const* get_atomized_type() const;

	type::typecode get_primitive_typecode() const;

	std::string describe() const;

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
public:
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
		DERIV_RESTRICTION				= 0x01,

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
		DERIV_EXTENSION					= 0x02,

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
		DERIV_UNION							= 0x04,

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
		DERIV_LIST							= 0x08,

	/**
	 * Derivation by substitution.
	 * This constant, unlike the others, is NOT defined in the DOM level 3 
	 * TypeInfo interface. 
	 */
		DERIV_SUBSTITUTION			= 0x10,


	/**
	 * Union of all of the above
	 */
		DERIV_ALL								= 0x1f

	};


	// Get the type code of this type.
	virtual type::typecode get_typecode() const;

	// Test this schema_type for equality.
	virtual bool operator==(schema_type const& other);

	// Test if this schema_type is complex.
	virtual bool is_complex() const;

	// Test if this schema_type simple.
	virtual bool is_simple() const;

	// Test if schema_type is atomic.
	virtual bool is_atomic() const;

	// Test if this schema_type is anonymous.
	virtual bool is_anonymous() const;

	// Return the base type that this type inherits from, or NULL for primitive.
	virtual schema_type const* get_base_type() const;

	// Get the derivation method used to derive this type.
	virtual derivation_method get_derivation_method() const;

	// Determine whether a specific derivation from this type is allowed.
	virtual bool allows_derivation(derivation_method derivation) const;

	// Output a string describing this type.
	virtual std::string describe() const;

};



/*______________________________________________________________________
|  
|	The class 'simple_type' represents a simple type, which may be
| a	built-in simple type (xs:anySimpleType), or a user-defined
| simple type. 
|_______________________________________________________________________*/

class simple_type : public schema_type
{
public:
	// Test whether this simple_type is an atomic type.
	virtual bool is_atomic() const;

	// Test whether this simple_type is a list type.
	virtual bool is_list() const;

	// Test whether this simple_type is a union type.
	virtual bool is_union() const;

	// Get the most specific atomic type for the items in this simple_type.
	virtual atomic_type const* get_common_atomic_type() const;

	// Get the built-in type from which this type is derived by restriction.
	virtual schema_type const* get_builtin_base_type() const;

	// Check whether a given input string is valid according for this simple_type.
	virtual int validate_content(char const* src) throw (xqp_exception);

};




/*______________________________________________________________________
|  
|	A complex type as defined in XML Schema: either a user-defined
|	complex type, or xs:anyType.
|_______________________________________________________________________*/

class complex_type : public schema_type
{
public:
	// Test if this complex type has been marked abstract.
	virtual bool is_abstract() const;

	// Test whether this complex type has complex content.
	virtual bool complex_content() const;

	// Test whether this complex type has simple content.
	virtual bool simple_content() const;

	// Test whether this complex type has "all" content.
	virtual bool all_content() const;

	// Get the simple content type.
	virtual simple_type const* get_simple_content_type() const;

	// Test whether this complex type is derived by restriction
	virtual bool is_restricted() const;

	// Test whether the content model of this complex type is empty.
	virtual bool is_empty_content() const;

	// Test whether the content model allows empty content.
	virtual bool allows_empty() const;

	// Test whether this complex type allows mixed content.
	virtual bool allows_mixed_content() const;

	// Test whether this complex type subsumes another complex type.
	virtual bool subsumes(complex_type const&);

};



/*______________________________________________________________________
|  
|	This class has a singleton instance which represents the XML Schema
|	built-in type xs:anyType, also known as the UR-type.
|_______________________________________________________________________*/

class xs_anyType : public complex_type
{
private:
	static xs_anyType the_instance;

protected:
	xs_anyType() {}
	virtual ~xs_anyType() {}

public:
	static xs_anyType const& get_instance();

	type::typecode get_typecode() const;

	schema_type const* get_base_type() const; 
	schema_type const* get_known_base_type() const;

	bool is_abstract() const;
	bool is_complex() const;
	bool is_anonymous() const;
	bool is_xs_anySimpleType() const;
	bool is_atomic() const;
	bool is_simple_content() const;
	bool is_all_content() const;
	bool is_restricted() const;
	bool is_empty_content() const;
	bool allows_derivation(schema_type::derivation_method) const;
	bool allows_empty() const;
	bool allows_mixed_content() const;

	bool operator==(schema_type const&) const;

	std::string describe() const;
	std::string subsumes(complex_type const&) const;

	void check_type_derivation(
		schema_type const&,
		enum schema_type::derivation_method)
	throw (xqp_exception);

	schema_type::derivation_method get_derivation_method() const;

};



/*______________________________________________________________________
|  
|	This class has a singleton instance which represents the XML Schema
|	built-in type xs:anySimpleType
|_______________________________________________________________________*/

class xs_anySimpleType : public simple_type, public xs_anyType
{
protected:
	static xs_anySimpleType the_instance;

protected:
	xs_anySimpleType() {}
	virtual ~xs_anySimpleType() {}

public:
	static xs_anySimpleType const& get_instance();

	bool matches(schema_type const& other) const;
	bool is_complex() const;
	bool is_atomic() const;
	bool is_anonymous() const;
	bool is_list() const;

	type::typecode get_typecode() const;
	schema_type::derivation_method get_derivation_method() const;

	schema_type const* get_base_type() const;
	schema_type const* get_known_base_type() const;
	schema_type const* get_builtin_base_type() const;
	atomic_type const* get_common_atomic_type() const;

	std::string describe() const;

	bool allows_derivation(schema_type::derivation_method) const;

	void check_type_derivation(
		schema_type const& type,
		schema_type::derivation_method)
	throw (xqp_exception);

	int validate_content(char const* src)
	throw (xqp_exception);

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

protected:
	xs_untyped() {}
	virtual ~xs_untyped() {}

public:
	static xs_untyped const& get_instance();

	schema_type::derivation_method get_derivation_method() const;
	type::typecode get_typecode() const;

	simple_type const* get_simple_content_type() const;
	schema_type const* get_known_base_type() const;
	schema_type const* get_base_type() const;

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

	bool allows_derivation(schema_type::derivation_method) const;
	bool allows_empty() const;
	bool allows_mixedContent() const;
	bool subsumes(complex_type const&);

	std::string describe() const;

};



/*______________________________________________________________________
|  
| Stub interface for atomic types (these are either built-in atomic 
| types or user-defined atomic types). An atomic_type is both an
|   item_type   (a possible type for items in a sequence) and a
|   schema_type (a possible type for validating and annotating nodes). 
|_______________________________________________________________________*/

class atomic_type : public xs_anySimpleType, public item_type
{
private:
	static atomic_type the_instance;

public:
	atomic_type() {}
	virtual ~atomic_type() {}

public:
	static atomic_type const& get_instance() { return the_instance; }

};



/*______________________________________________________________________
|  
| This class represents a built-in atomic type, which may be either a 
| primitive type (such as xs:decimal or xs:anyURI) or a derived type 
| (such as xs:ID or xdt:dayTimeDuration).
|_______________________________________________________________________*/

class xs_anyAtomicType : public atomic_type
{
private:
	static xs_anyAtomicType the_instance;

protected:
	xs_anyAtomicType();
	~xs_anyAtomicType();

public:
	static xs_anyAtomicType const& get_instance();

	enum type::typecode get_typecode() const;
	class item_type const* get_primitive_type() const;
	schema_type::derivation_method get_derivation_method() const;

	bool operator==(schema_type const&) const;

	bool is_complex() const;
	bool is_anonymous() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_list() const;
	bool is_union() const;

	class item_type const* get_super_type() const;
	class item_type const* get_primitive_item_type() const;
	atomic_type const* get_common_atomic_type() const;
	atomic_type const* get_atomized_item_type() const;
	schema_type const* get_known_base_type() const;
	schema_type const* get_base_type() const;

	std::string describe() const;

	void check_type_derivation(
		schema_type const& type,
		schema_type::derivation_method)
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
	*/
	xs_anySimpleType const* get_item_type() const;

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
	static builtin_list_type the_instance;

public:
	type::typecode get_typecode() const;
	item_type const* get_primitive_type() const;
	schema_type::derivation_method get_derivation_method() const;

	bool operator==(schema_type const&) const;

	bool is_complex() const;
	bool is_anonymous() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_list() const;
	bool is_union() const;

	item_type const* get_super_type() const;
	item_type const* get_primitive_item_type() const;
	atomic_type const* get_common_atomic_type() const;
	atomic_type const* get_atomized_item_type() const;
	schema_type const* get_known_base_type() const;
	schema_type const* get_base_type() const;

	std::string describe() const;

	void check_type_derivation(
		schema_type const& type,
		schema_type::derivation_method)
	throw (xqp_exception);

};


} /* namespace xqp */
#endif /* XQP_TYPES_H */

