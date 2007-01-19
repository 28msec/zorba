/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: types.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */
 
/*
 *  This code module is derived from the Saxon project.
 *  The Saxon Java code has been reworked for the C++
 *  framework, but the design is inherited from Saxon.
 *
 *  Michael Kay is the original author.
 *  [http://saxon.sourceforge.net/]
 *
 */

#ifndef XQP_TYPES_H
#define XQP_TYPES_H

#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

namespace xqp {


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
/*______________________________________________________________________
|  
|	 XQuery "item type" hierarchy
|
|  The two type hierarchies intersect at 'anyAtomicType'.
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
|	XQuery "sequence types" are composed from these item types and
|	a cardinality indicator: *, +, ?
|_______________________________________________________________________*/
	
	enum typecode {
		ITEM_TYPE,
			XS_ANYATOMICTYPE,				//*
			NODE_TYPE,
				BINARY_NODE,
				COMMENT_NODE,
				DOCUMENT_NODE,
				ELEMENT_NODE,
				ATTRIBUTE_NODE,
				NS_NODE,
				PI_NODE,
				TEXT_NODE,
		XS_ANYTYPE,
			XS_UNTYPED, 
			XS_ANY_ATOMIC,
			XS_ANYSIMPLETYPE,
				XS_NMTOKENS,
				XS_IDREFS,
				XS_ENTITIES,
			//XS_ANYATOMICTYPE,			//*
					XS_UNTYPED_ATOMIC,
					XS_DATETIME,
					XS_DATE,
					XS_TIME,
					XS_GYEARMONTH,
					XS_GYEAR,
					XS_GMONTHDAY,
					XS_GDAY,
					XS_GMONTH,
					XS_DURATION,
						XS_YEARMONTH_DURATION,
						XS_DAYTIME_DURATION,
					NUMERIC,
						XS_FLOAT,
						XS_DOUBLE,
						XS_DECIMAL,
							XS_INTEGER,
								XS_NON_POSITIVE_INTEGER,
									XS_NEGATIVE_INTEGER,
								XS_LONG,
									XS_INT,
										XS_SHORT,
											XS_BYTE,
								XS_NON_NEGATIVE_INTEGER,
									XS_UNSIGNED_LONG,
										XS_UNSIGNED_INT,
											XS_UNSIGNED_SHORT,
												XS_UNSIGNED_BYTE,
									XS_POSITIVE_INTEGER,
					XS_STRING,
						XS_NORMALIZED_STRING,
							XS_TOKEN,
								XS_LANGUAGE,
								XS_NMTOKEN,
								XS_NAME,
									XS_NCNAME,
										XS_ID,
										XS_IDREF,
										XS_ENTITY,
					XS_BOOLEAN,
					XS_ANYURI,
					XS_QNAME,
					XS_NOTATION,
					XS_BASE64BINARY,
					XS_HEXBINARY,
					BUILTIN_LIST 
	};

	enum type_relation {	
		SAME_TYPE,		// A = B, A is the same type as B
		SUBTYPE, 			// A < B, all A are B
		SUPERTYPE,  	// A > B, all B are A
		OVERLAPS,			// A overlaps B, some A are B
		DISJOINT			// A is disjoint from B, no A are B
	};


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

class schema_type : public schema_component, public type
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
	virtual std::string describe() const { return "atomic_type"; }

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
	xs_anyAtomicType() {}
	virtual ~xs_anyAtomicType() {}

public:
	// return const reference to the singleton instance
	static xs_anyAtomicType const& get_instance();

	// return a name for this atomic type
	virtual enum type::typecode get_typecode() const;

	// check type identity
	virtual bool operator==(schema_type const&) const;

	// check subtype
	virtual bool operator<(schema_type const&) const;

	// return parent type
	virtual item_type const* get_super_type() const;

	// return a string representing the type
	std::string describe() const;


	// stub methods
	item_type const* get_primitive_type() const;
	schema_type::derivation_method get_derivation_method() const;
	
	bool is_complex() const;
	bool is_anonymous() const;
	bool is_simple() const;
	bool is_atomic() const;
	bool is_list() const;
	bool is_union() const;
	
	item_type   const* get_primitive_item_type() const;
	atomic_type const* get_common_atomic_type() const;
	atomic_type const* get_atomized_item_type() const;
	schema_type const* get_known_base_type() const;
	schema_type const* get_base_type() const;


	void check_type_derivation(
		schema_type const& type,
		enum derivation_method)
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

