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
|      xs_untyped
|      xs_anySimpleType
|        list_type [user-defined]
|        xs_IDREFS
|        xs_NMTOKENS
|        xs_ENTITIES
|        xs_anyAtomicType                 C++ type              type code
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

}



/*______________________________________________________________________
|  
|	An implementation of item_type that matches any
|	item (node or atomic value).
|_______________________________________________________________________*/

class any_item_type : public item_type
{
protected:
	any_item_type(){};
	static any_item_type the_instance;

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
	rchandle<atomic_type> get_atomized_type() const;
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
|		simple_type 
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
	 * Get the namecode of the name of this type. This includes the prefix 
	 * from the original type declaration: in the case of built-in types, 
	 * there may be a conventional prefix or there may be no prefix. 
	 */
	int get_namecode() const;

	/**
	 * Get the fingerprint of the name of this type
	 * @return - fingerprint
	 */
	uint32_t get_fingerprint() const;

	/**
	 * Get the lexical QName for this type.
	 * @return - lexical QName identifying the type
	 */
	std::string get_displayname() const;

	/**
	 * Test whether this schema_type is a complex type
	 * @return - true, if this schema_type is a complex type
	 */
	bool is_complex_type() const;

	/**
	 * Test whether this schema_type is a simple type
	 * @return - true, if this schema_type is a simple type
	 */
	bool is_simple_type() const;

	/**
	 * Test whether this schema_type is an atomic type
	 * @return - true, if this schema_type is an atomic type
	 */
	bool is_atomic_type() const;

	/**
	 * Test whether this is an anonymous type
	 * @return true if this schema_type is an anonymous type
	 */
	bool is_anonymous_type() const;

	/**
	 * Returns the value of the 'block' attribute for this type,
	 * with fields such as 
	 *   schema_type::DERIVATION_LIST,
	 *   schema_type::DERIVATION_EXTENSION 
	 * @return - value of the 'block' attribute for this type
	 */
	enum derivation_method get_block() const;

	/**
	 * Returns the base type that this type inherits from. This method can be 
	 * used to get the base type of a type that is known to be valid. If this 
	 * type is a simple_type that is a built in primitive type then NULL is 
	 * returned. 
	 * @return - base type.
	 * @throws - xqp_exception, if this type is not valid.
	*/
	rchandle<schema_type> get_base_type() const
	throws xqp_exception;

	/**
	 * Get the integer code of the derivation method used to derive this 
	 * type from its parent. Return zero for primitive types. 
	 * @return - numeric code representing the derivation method
	 */
	enum derivation_method get_derivation_method() const;

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 *
	 * @param derivation - the kind of derivation
	 * @return - true if this kind of derivation is allowed
	 */
	bool allows_derivation(
		enum derivation_method derivation) const;

	/**
	 * Analyze an expression to see whether the expression is capable of 
	 * delivering a value of this type. 
	 *
	 * @param expression - expression that delivers the content
	 * @param kind - node kind whose content is being delivered: 
	 *               Type::ELEMENT, Type::ATTRIBUTE, or Type::DOCUMENT 
	 * @param env - static evaluation context for the query or stylesheet
	 * @throw xqp_exception - if the expression will never deliver a value of 
	 *            the correct type 
	 */
	void analyze_expression(
		rchandle<expr> expr,
		int kind,
		context const& env) const
	throw (xqp_exception);

	/**
	 * Get the typed value of a node that is annotated with this schema type. 
	 * The results of this method are consistent with the {@link #atomize} 
	 * method, but this version returns a SequenceIterator which may be more 
	 * efficient when handling long lists. 
	 *
	 * @param node - node whose typed value is required
	 * @return - item_iterator over the atomic values making up the typed 
	 *               value of the specified node. The objects returned by this
	 *               iterator are of type atomicValue
	 */
	rchandle<item_iterator> get_typed_value(node const&) const
	throw (xqp_exception);

	/**
	 * Get the typed value of a node that is annotated with this schema type. 
	 * The result of this method will always be consistent with the method 
	 * getTypedValue.
	 *
	 * @param node - node whose typed value is required
	 * @return - typed value. 
	 */
	rchandle<item_iterator> atomize(node const&) const
	throw (xqp_xception);

	/**
	 * Test whether this is the same type as another type. They are 
	 * considered to be the same type if they are derived from the same type 
	 * definition in the original XML representation (which can happen when 
	 * there are multiple includes of the same file) 
	 */
	bool operator==(schema_type const& other);

	/**
	 * Get a description of this type. This is the 
	 * same as the display name in the case of named types; for anonymous 
	 * types it identifies the type by its position in a source schema 
	 * document. 
	 * @return - text identifing the type
	 */
	std::string describe() const;

};



/*______________________________________________________________________
|  
|	The class 'simple_type' represents a simple type, which may be a
|	built-in simple type, or a user-defined simple type. 
|_______________________________________________________________________*/

class simple_type : public schema_type
{
	/**
	 * Test whether this Simple Type is an atomic type
	 * @return true if this is an atomic type
	 */
	bool is_atomic_type() const;

	/**
	 * Test whether this Simple Type is a list type
	 * @return true if this is a list type
	 */
	bool is_list_type() const;

	/**
	 * Test whether this Simple Type is a union type
	 * @return true if this is a union type
	 */
	bool is_union_type() const;

	/**
	 * Return true if this is an external object type
	 */
	bool is_external_type() const;

	/**
	 * Get the most specific possible atomic type that all items in this 
	 * SimpleType belong to 
	 * @return the lowest common supertype of all member types
	 */
	rchandle<atomic_type> get_common_atomic_type() const;

	/**
	 * Get the built-in type from which this type is derived by restriction
	 * @return the built-in type from which this type is derived by 
	 *     restriction. This will not necessarily be a primitive type.
	 */
	rchandle<schema_type> get_builtin_base_type() const;

	/**
	 * Get the typed value corresponding to a given string value, assuming it is
	 * valid against this type.
	 * @param value - string value
	 * @param resolver - namespace resolver used to resolve any namespace
	 *    prefixes appearing in the content of values. Can supply NULL, in
	 *    which case any namespace-sensitive content will be rejected.
	 * @param nameChecker - NameChecker used in the case of types that are
	 *    defined in terms of the XML NCName syntax: this is used to check
	 *    conformance to XML 1.0 or XML 1.1 naming rules, as appropriate
	 * @return - an iterator over the atomic sequence comprising the typed value.
	 *    The objects returned by this iterator will all be of type atomic_value
	 * @throws xqp_exception - if the supplied value is not in the lexical space
	 *    of the data type
	 */
	rchandle<item_iterator> get_typed_value(
		char const* value,
		rchandle<NamespaceResolver>)
		//NameChecker nameChecker)
	throw (xqp_exception);

	/**
	 * Check whether a given input string is valid according to this simple_type
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
		//NameChecker nameChecker);
	throw (xqp_exception);

	/**
	 * Test whether this type is namespace sensitive, that is, if a namespace
	 * context is needed to translate between the lexical space and the value
	 * space. This is true for types derived from, or containing, QNames and
	 * NOTATIONs.
	 * @return true if the type is namespace-sensitive
	 */
	bool is_namespace_sensitive() const;

	/**
	 * Determine how values of this simple type are whitespace-normalized.
	 * @return one of Whitespace::COLLAPSE, ..
	 */
	int get_whitespace_action() const;

};





/*______________________________________________________________________
|  
|	A complex type as defined in XML Schema: either a user-defined
|	complex type, or xs:anyType. In the non-schema-aware version of XQP,
|	the only complex type encountered is xs:anyType.
|_______________________________________________________________________*/

class complex_type : public schema_type
{
	/**
	 * Test whether this complex type has been marked as abstract.
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
	bool allows_empty() const
	throw (xqp_exception);

	/**
	 * Test whether this complex type allows mixed content
	 * @return true if mixed content is allowed
	 */
	bool allows_mixed_content() const;

	/**
	 * Test whether this complex type subsumes another complex type. The 
	 * algorithm used is as published by Thompson and Tobin, XML Europe 2003. 
	 *
	 * @param sub the other type (the type that is derived by restriction, 
	 *         validly or otherwise) 
	 * @return NULL indicating that this type does indeed subsume the other; 
	 *         or a string indicating why it doesn't. 
	 */
	bool subsumes(rchandle<complex_type> sub)
	throw (xqp_excpetion);

	/**
	 * Find an element particle within this complex type definition having a 
	 * given element name (identified by fingerprint), and return the schema 
	 * type associated with that element particle. If there is no such 
	 * particle, return NULL. If the fingerprint matches an element wildcard, 
	 * return the type of the global element declaration with the given name 
	 * if one exists, or any_type if none exists and lax validation is 
	 * permitted by the wildcard. 
	 *
	 * @param fingerprint - identifies the name of the child element within
	 *        this content model
	 */
	rchandle<schema_type> get_element_particle(uint32_t fingerprint)
	throw (xqp_exception);

	/**
	 * Find an element particle within this complex type definition having a 
	 * given element name (identified by fingerprint), and return the 
	 * cardinality associated with that element particle, that is, the number 
	 * of times the element can occur within this complex type. The value is 
	 * one of ALLOWS_ZERO_OR_ONE, ALLOWS_ONE_OR_MORE, etc.
	 * If there is no such particle, return ..
	 * @param fingerprint Identifies the name of the child element within 
	 *          this content model 
	 */
	uint32_t get_element_particle_cardinality(uint32_t fingerprint)
	throw (xqp_exception);

	/**
	 * Find an attribute use within this complex type definition having a 
	 * given attribute name (identified by fingerprint), and return the 
	 * schema type associated with that attribute. If there is no such 
	 * attribute use, return null. If the fingerprint matches an attribute 
	 * wildcard, return the type of the global attribute declaration with the 
	 * given name if one exists, or AnySimpleType if none exists and lax 
	 * validation is permitted by the wildcard. If there are types derived 
	 * from this type by extension, search those too. 
	 *
	 * @param fingerprint Identifies the name of the child element within 
	 *                    this content model 
	 */
	rchandle<schema_type> get_attribute_use_type(uint32_t fingerprint)
	throw (xqp_exception);

}




/*______________________________________________________________________
|  
|	This class has a singleton instance which represents the XML Schema
|	built-in type xs:anySimpleType
|_______________________________________________________________________*/

class xs_anySimpleType : public simple_type
{
private:
	static xs_anySimpleType the_instance;

	xs_anySimpleType();
	~xs_anySimpleType();

public:
	static rchandle<xs_anySimpleType> get_instance();

	bool is_external_type() const;
	bool is_complex_type() const;
	bool is_simple_type() const;
	bool is_Same_type(SchemaType other) const;
	bool is_atomic_type() const;
	bool is_anonymous_type() const;
	bool is_list_type() const;
	bool is_namespace_sensitive() const;
	bool allows_derivation(enum derivation_method) const;

	int get_validation_status() const;
	int get_fingerprint() const;
	int get_namecode() const;
	int get_block() const;
	int get_derivation_method() const;
	int get_whitespace_action() const;

	rchandle<schema_type> get_base_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<schema_type> get_builtin_base_type() const;
	rchandle<atomic_type> get_common_atomic_type() const;

	std::string describe() const;

	rchandle<item_iterator> get_typed_value(node&);
	rchandle<item_iterator> atomize(node&);

	void check_type_derivation(
		schema_type const& type,
		enum derivation_method)
	throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(
		char const* value,
		rchandle<namespace_resolver>);

	rchandle<validation_error> validateContent(
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

class any_type : public complex_type
{
private:
	static any_type theInstance = new any_type();
	private any_type();

public:
	static rchandle<any_type> get_instance() const;

	rchandle<schema_type> get_base_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<schema_type> get_attribute_use_type(uint32_t fingerprint) const;
	rchandle<simple_type> get_simple_content_type() const;

	bool is_abstract() const;
	bool is_complex_type() const;
	bool is_anonymous_type() const;
	bool is_simple_type() const;
	bool is_atomic_type() const;
	bool is_complex_content() const;
	bool is_simple_content() const;
	bool is_all_content() const;
	bool is_restricted() const;
	bool is_empty_content() const;

	bool allows_derivation(int derivation) const;
	bool allows_empty() const;
	bool allows_mixed_content() const;

	bool operator==(schema_type const&) const;

	std::string describe() const;
	std::string subsumes(complex_type const& sub) const;

	rchandle<item_iterator> get_typed_value(node&) const;
	rchandle<item_iterator> atomize(node&) const;

	void analyze_content_expression(
		rchandle<expr>, int kind, context& env) const;

	void check_type_derivation(
		schema_type const&,
		enum derivation_method)
	throw (xqp_exception);

	int get_validation_status() const;
	uint32_t get_fingerprint() const;
	int get_namecode() const;
	enum derivation_method get_derivation_method() const;
	enum derivation_method get_block() const;
	rchandle<schema_type> get_element_particle_type(uint32_t fingerprint) const;
	uint32_t get_element_particle_cardinality(uint32_t fingerprint) const;

};





/*______________________________________________________________________
|  
| This class has a singleton instance which represents the complex type 
| dt:untyped, used for elements that have not been validated. 
|_______________________________________________________________________*/

class untyped : public complex_type
{
private:
	static untyped the_instance;
	untyped();

public:
	static untyped get_instance();

	int getValidationStatus();
	int getBlock();
	int getDerivationMethod();
	int getFingerprint();
	int getNameCode();

	SimpleType getSimpleContentType();
	SchemaType getKnownBaseType();
	SchemaType getBaseType();
	SchemaType getAttributeUseType(int fingerprint);

	bool allowsDerivation(int derivation) {
	bool isComplexType();
	bool isAnonymousType();
	bool isSameType(SchemaType other) {
	bool isAbstract();
	bool isSimpleType();
	bool isAtomicType();
	bool isComplexContent();
	bool isSimpleContent();
	bool isAllContent();
	bool isRestricted();
	bool isEmptyContent();
	bool isEmptiable();
	bool isMixedContent();

	std::string getDisplayName();
	std::string getDescription();
	std::string subsumes(ComplexType sub);

	void checkTypeDerivationIsOK(
		SchemaType type,
		int block);

	void analyzeContentExpression(
		Expression expression,
		int kind,
		StaticContext env);

	SequenceIterator getTypedValue(node);
	Value atomize(node);

	SchemaType getElementParticleType(int fingerprint);
	int getElementParticleCardinality(int fingerprint);

};







/*______________________________________________________________________
|  
| Stub interface for atomic types (these are either built-in atomic 
| types or user-defined atomic types). An atomic_type is both an
|   item_type   (a possible type for items in a sequence) and a
|   schema_type (a possible type for validating and annotating nodes). 
|_______________________________________________________________________*/

class atomic_type : public simple_type, item_type
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

class builtin_atomic_type : public atomic_type
{
	uint32_t fingerprint;
	uint32_t base_fingerprint;

public:
	builtin_atomic_type();
	builtin_atomic_type(uint32_t fingerprint) {

public:

	rchandle<atomic_type> get_common_atomic_type() const;
	rchandle<atomic_type> get_atomized_item_type() const;
	rchandle<item_type> get_super_type() const;
	rchandle<item_type> get_primitive_item_type() const;
	rchandle<schema_type> get_known_base_type() const;
	rchandle<schema_type> get_built_in_base_type() const;
	rchandle<schema_type> get_base_type() const;

	int get_validation_status() const;
	uint32_t get_fingerprint() const;
	int get_name_code() const;
	int get_primitive_type() const;
	int get_whitespace_action() const;
	enum derivation_method get_block() const;
	enum derivation_method get_derivation_method() const;

	void set_base_type_fingerprint(uint32_t base_fingerprint) const;

	bool is_external_type() const;
	bool is_complex_type() const;
	bool is_anonymous_type() const;
	bool is_simple_type() const;
	bool is_atomic_type() const;
	bool is_list_type() const;
	bool is_union_type() const;
	bool is_namespace_sensitive() const;

	bool matches_item(item const&, bool allow_URI_promotion, config& config) const;
	bool operator==(schema_type const&) const;

	std::string Describe() const;

	void check_type_derivation(
		schema_type const& type,
		enum derivation_method)
	throw (xqp_exception);

	rchandle<validation_error> validate_content(
		char const* value,
		rchandle<namespace_resolver>);

	rchandle<item_iterator> get_typed_value(node&)
	throw (xqp_exception);

	rchandle<item_iterator> atomize(node&)
	throw (xqp_exception);

	rchandle<item_iterator> get_typed_value(
		char const* value,
		rchandle<namespace_resolver> resolver)
	throw (xqp_exception);

	rchandle<atomic_value> make_derived_value(
		atomic_value const&,
		char const* lexicalValue,
		bool validate)
	throw (xqp_exception);

	void analyze_content_expression(
		rchandle<expr>,
		int kind,
		context& env)
	throw (xqp_exception);

	static void analyze_content_expression(
		simple_type const&,
		rchandle<expr>,
		context& env,
		int kind)
	throw (xqp_exception);

};





/*______________________________________________________________________
|  
| Interface representing a simple type List
|_______________________________________________________________________*/

class list_type : public simple_type
{
	/**
	 * Return the simple_type of the items in this list_type.
	 * This method assumes that the item type has been fully resolved.
	 * @return - simple_type of the items in this list-type.
	 * @throw - xqp_exception, if the item type has not been fully resolved
	*/
	rchandle<simple_type> get_item_type();

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
	uint32_t fingerprint;
	private BuiltInAtomicType itemType = null;

public:
	BuiltInListType(int fingerprint) {

public:

	int getWhitespaceAction();
	int getValidationStatus();
	int getFingerprint();
	int getBlock();
	int getNameCode();
	int getDerivationMethod();

	AtomicType getCommonAtomicType();
	SimpleType getItemType();
	SchemaType getBaseType();
	SchemaType getKnownBaseType();
	SchemaType getBuiltInBaseType();

	bool isExternalType();
	bool isAtomicType();
	bool isListType();
	bool isUnionType();
	bool isAnonymousType();
	bool isComplexType();
	bool isSimpleType();
	bool isNamespaceSensitive();
	bool allowsDerivation(int derivation);
	bool isSameType(SchemaType other);

	std::string getDisplayName();
	std::string getDescription();
	std::string getLocalName();
	std::string applyWhitespaceNormalization(std::string value);

	Value atomize(node)
	throws XPathException;

	SequenceIterator getTypedValue(node)
	throws XPathException;

	void checkTypeDerivationIsOK(
		SchemaType type,
		int block)
	throws SchemaException;

	void analyzeContentExpression(
		Expression expression,
		int kind,
		StaticContext env)
	throws XPathException;

	ValidationException validateContent(
		CharSequence value,
		NamespaceResolver nsResolver,
		NameChecker nameChecker);

	SequenceIterator getTypedValue(
		CharSequence value,
		NamespaceResolver resolver,
		NameChecker nameChecker)
	throws ValidationException;

private:
	static class ListTypeMappingFunction : public MappingFunction;

};





/*______________________________________________________________________
|  
| This class is used to construct Schema objects containing all
| the built-in types defined in the "xs" and "xdt" namespaces.
|_______________________________________________________________________*/

class builtin_schema_factory
{
	private static HashMap lookup = new HashMap(100);

	private BuiltInSchemaFactory() {}

	static {
		std::string XS = NamespaceConstant.SCHEMA;
		std::string XDT = NamespaceConstant.XDT;
		std::string XSI = NamespaceConstant.SCHEMA_INSTANCE;

		AnySimpleType anySimpleType = AnySimpleType.getInstance();
		lookup.put(new Integer(StandardNames.XS_ANY_SIMPLE_TYPE), anySimpleType);

		BuiltInAtomicType anyAtomicType =
		        makeAtomicType(XDT, "anyAtomicType", anySimpleType);
		BuiltInAtomicType numeric =
		        makeAtomicType(XDT, "_numeric_", anyAtomicType);
		BuiltInAtomicType string =
		        makeAtomicType(XS, "string", anyAtomicType);
		BuiltInAtomicType xsbool =
		        makeAtomicType(XS, "bool", anyAtomicType);
		BuiltInAtomicType duration =
		        makeAtomicType(XS, "duration", anyAtomicType);
		BuiltInAtomicType dateTime =
		        makeAtomicType(XS, "dateTime", anyAtomicType);
		BuiltInAtomicType date =
		        makeAtomicType(XS, "date", anyAtomicType);
	  BuiltInAtomicType time =
	          makeAtomicType(XS, "time", anyAtomicType);
	  BuiltInAtomicType gYearMonth =
	          makeAtomicType(XS, "gYearMonth", anyAtomicType);
	  BuiltInAtomicType gMonth =
	          makeAtomicType(XS, "gMonth", anyAtomicType);
	  BuiltInAtomicType gMonthDay =
	          makeAtomicType(XS, "gMonthDay", anyAtomicType);
	  BuiltInAtomicType gYear =
	          makeAtomicType(XS, "gYear", anyAtomicType);
	  BuiltInAtomicType gDay =
	          makeAtomicType(XS, "gDay", anyAtomicType);
	  BuiltInAtomicType hexBinary =
	          makeAtomicType(XS, "hexBinary", anyAtomicType);
	  BuiltInAtomicType base64Binary =
	          makeAtomicType(XS, "base64Binary", anyAtomicType);
	  BuiltInAtomicType anyURI =
	          makeAtomicType(XS, "anyURI", anyAtomicType);
	  BuiltInAtomicType qName =
	          makeAtomicType(XS, "QName", anyAtomicType);
	  BuiltInAtomicType notation =
	          makeAtomicType(XS, "NOTATION", anyAtomicType);
	  BuiltInAtomicType untypedAtomic =
	          makeAtomicType(XDT, "untypedAtomic", anyAtomicType);
	  BuiltInAtomicType decimal =
	          makeAtomicType(XS, "decimal", numeric);
	  BuiltInAtomicType xsfloat =
	          makeAtomicType(XS, "float", numeric);
	  BuiltInAtomicType xsdouble =
	          makeAtomicType(XS, "double", numeric);
	  BuiltInAtomicType xsinteger =
	          makeAtomicType(XS, "integer", decimal);
	  BuiltInAtomicType nonPositiveInteger =
	          makeAtomicType(XS, "nonPositiveInteger", xsinteger);
	  BuiltInAtomicType negativeInteger =
	          makeAtomicType(XS, "negativeInteger", nonPositiveInteger);
	  BuiltInAtomicType xslong =
	          makeAtomicType(XS, "long", xsinteger);
	  BuiltInAtomicType xsint =
	          makeAtomicType(XS, "int", xslong);
	  BuiltInAtomicType xsshort =
	          makeAtomicType(XS, "short", xsint);
	  BuiltInAtomicType xsbyte =
	          makeAtomicType(XS, "byte", xsshort);
	  BuiltInAtomicType nonNegativeInteger =
	          makeAtomicType(XS, "nonNegativeInteger", xsinteger);
	  BuiltInAtomicType positiveInteger =
	          makeAtomicType(XS, "positiveInteger", nonNegativeInteger);
	  BuiltInAtomicType unsignedLong =
	          makeAtomicType(XS, "unsignedLong", nonNegativeInteger);
	  BuiltInAtomicType unsignedInt =
	          makeAtomicType(XS, "unsignedInt", unsignedLong);
	  BuiltInAtomicType unsignedShort =
	          makeAtomicType(XS, "unsignedShort", unsignedInt);
	  BuiltInAtomicType unsignedByte =
	          makeAtomicType(XS, "unsignedByte", unsignedShort);
	  BuiltInAtomicType ymd =
	          makeAtomicType(XDT, "yearMonthDuration", duration);
	  BuiltInAtomicType dtd =
	          makeAtomicType(XDT, "dayTimeDuration", duration);
	  BuiltInAtomicType normalizedstd::string =
	          makeAtomicType(XS, "normalizedstd::string", string);
	  BuiltInAtomicType token =
	          makeAtomicType(XS, "token", normalizedstd::string);
	  BuiltInAtomicType language =
	          makeAtomicType(XS, "language", token);
	  BuiltInAtomicType name =
	          makeAtomicType(XS, "Name", token);
	  BuiltInAtomicType nmtoken =
	          makeAtomicType(XS, "NMTOKEN", token);
	  BuiltInAtomicType ncname =
	          makeAtomicType(XS, "NCName", name);
	  BuiltInAtomicType id =
	          makeAtomicType(XS, "ID", ncname);
	  BuiltInAtomicType idref =
	          makeAtomicType(XS, "IDREF", ncname);
	  BuiltInAtomicType entity =
	          makeAtomicType(XS, "ENTITY", ncname);

	  makeListType(XS, "NMTOKENS");
	  makeListType(XS, "IDREFS");
	  makeListType(XS, "ENTITIES");
	  makeListType(XSI, "anonymous_schemaLocationType");

	  lookup.put(new Integer(StandardNames.XS_ANY_TYPE), AnyType.getInstance());
	  lookup.put(new Integer(StandardNames.XDT_UNTYPED), Untyped.getInstance());
	}


private:
	static BuiltInAtomicType makeAtomicType(
		std::string namespace,
		td::string lname,
		SimpleType baseType);

	static BuiltInListType makeListType(
		std::string namespace,
		std::string lname);

	static SchemaType getSchemaType(
		int fingerprint);

};




/*______________________________________________________________________
|  
| This class represents the type of an external Java object returned by
| an extension function, or supplied as an external variable/parameter.
|_______________________________________________________________________*/

class external_type : public atomic_type
{
protected:
	config cfg;
	uint32_t fingerprint;
	uint32_t baseFingerprint = -1;

public:
	external_type(config);

public:

	int getValidationStatus();
	int getBlock();
	int getDerivationMethod();
	int getNameCode();
	int getPrimitiveType();
	int getRelationship(ExternalObjectType other);
	int getWhitespaceAction(TypeHierarchy th);
	int getFingerprint();

	bool isExternalType();
	bool isComplexType();
	bool isSimpleType();
	bool isAtomicType();
	bool isListType();
	bool isUnionType();
	bool isNamespaceSensitive();
	bool isAnonymousType();
	bool isBuiltIn();
	bool allowsDerivation(int derivation);

	bool matchesItem(Item item, bool allowURIPromotion, Configuration config);
	bool isSameType(SchemaType other);

	AtomicType getCommonAtomicType();
	AtomicType getAtomizedItemType();
	ItemType getPrimitiveItemType();
	ItemType getSuperType(TypeHierarchy th);
	SchemaType getBaseType();
	SchemaType getKnownBaseType();
	SchemaType getBuiltInBaseType();

	std::string describe();
	std::string get_displayname();

	void checkTypeDerivation(SchemaType type, int block)
	throw (xqp_exception);

	CharSequence applyWhitespaceNormalization(CharSequence value)
	throw (xqp_exception);

	SequenceIterator getTypedValue(NodeInfo node)
	throw (xqp_exception);

	Value atomize(NodeInfo node)
	throw (xqp_exception);

	SequenceIterator getTypedValue(
		CharSequence value,
		NamespaceResolver resolver)
	throw (xqp_exception);

	AtomicValue makeDerivedValue(
		AtomicValue primValue,
		CharSequence lexicalValue,
		bool validate) {
	throw (xqp_exception);

	void analyzeContentExpression(
		Expression expression,
		int kind,
		StaticContext env)
	throw (xqp_exception);

	static void analyzeContentExpression(
		SimpleType simpleType,
		Expression expression,
		StaticContext env,
		int kind)
	throw (xqp_exception);

	ValidationException validateContent(
		CharSequence value,
		NamespaceResolver nsResolver)
	throw (xqp_exception);

};





/*______________________________________________________________________
|  
| A stub interface representing a global element or attribute
| declaration.
|_______________________________________________________________________*/

class SchemaDeclaration
{
	/**
	 * Get the simple or complex type associated with the element or
	 * attribute declaration
	 *
	 * @return - simple or complex type
	 */
	SchemaType getType();

	/**
	 * Create a NodeTest that implements the semantics of schema-element(name) or
	 * schema-attribute(name) applied to this element or attribute declaration.
	 */
	NodeTest makeSchemaNodeTest();

};





/*______________________________________________________________________
|  
| This class contains static information about types and methods
| for constructing type codes. The class is never instantiated.
|_______________________________________________________________________*/

class type
{
	// Note that the integer codes representing node kinds are the same as
	// the codes allocated in the DOM interface, while the codes for built-in
	// atomic types are fingerprints allocated in StandardNames. These two sets of
	// codes must not overlap!

	static short ELEMENT = 1;
	static short ATTRIBUTE = 2;
	static short TEXT = 3;
	static short WHITESPACE_TEXT = 4;
	static short PROCESSING_INSTRUCTION = 7;
	static short COMMENT = 8;
	static short DOCUMENT = 9;
	static short NAMESPACE = 13;
	static short STOPPER = 11;
	static short PARENT_POINTER = 12;

	static short NODE = 0;
	static ItemType NODE_TYPE = AnyNodeTest.getInstance();
	static short ITEM = 88;
	static ItemType ITEM_TYPE = AnyItemType.getInstance();
	static short MAX_NODE_TYPE = 13;
	static short EMPTY = 15;    // a test for this type will never be satisfied


private :
	type() {}

public:
	/**
	 * Test whether a given type is (some subtype of) node()
	 * @param type The type to be tested
	 * @return true if the item type is node() or a subtype of node()
	 */
	static bool isNodeType(ItemType type) {
	    return type instanceof NodeTest;
	}


	/**
	 * Constant denoting any atomic type (the union of all primitive
	 * types and types derived from primitive types by restriction
	 * or by union)
	 */
	static int ANY_ATOMIC      = StandardNames.XDT_ANY_ATOMIC_TYPE;

	/**
	 * Constant denoting any numeric type (the union of
	 * float, double, and decimal)
	 */
	static int NUMBER          = StandardNames.XDT_NUMERIC;


	static int STRING = StandardNames.XS_STRING;
	static int BOOLEAN = StandardNames.XS_BOOLEAN;
	static int DECIMAL = StandardNames.XS_DECIMAL;
	static int FLOAT = StandardNames.XS_FLOAT;
	static int DOUBLE = StandardNames.XS_DOUBLE;
	static int DURATION = StandardNames.XS_DURATION;
	static int DATE_TIME = StandardNames.XS_DATE_TIME;
	static int TIME = StandardNames.XS_TIME;
	static int DATE = StandardNames.XS_DATE;
	static int G_YEAR_MONTH = StandardNames.XS_G_YEAR_MONTH;
	static int G_YEAR = StandardNames.XS_G_YEAR;
	static int G_MONTH_DAY = StandardNames.XS_G_MONTH_DAY;
	static int G_DAY = StandardNames.XS_G_DAY;
	static int G_MONTH = StandardNames.XS_G_MONTH;
	static int HEX_BINARY = StandardNames.XS_HEX_BINARY;
	static int BASE64_BINARY   = StandardNames.XS_BASE64_BINARY;
	static int ANY_URI = StandardNames.XS_ANY_URI;
	static int QNAME = StandardNames.XS_QNAME;
	static int NOTATION = StandardNames.XS_NOTATION;
	static int UNTYPED_ATOMIC = StandardNames.XDT_UNTYPED_ATOMIC;
	static int ANY_SIMPLE_TYPE = StandardNames.XS_ANY_SIMPLE_TYPE;
	static int OBJECT = StandardNames.SAXON_JAVA_LANG_OBJECT;
	static int INTEGER = StandardNames.XS_INTEGER;
	static int NON_POSITIVE_INTEGER = StandardNames.XS_NON_POSITIVE_INTEGER;
	static int NEGATIVE_INTEGER = StandardNames.XS_NEGATIVE_INTEGER;
	static int LONG = StandardNames.XS_LONG;
	static int INT = StandardNames.XS_INT;
	static int SHORT = StandardNames.XS_SHORT;
	static int BYTE = StandardNames.XS_BYTE;
	static int NON_NEGATIVE_INTEGER = StandardNames.XS_NON_NEGATIVE_INTEGER;
	static int POSITIVE_INTEGER = StandardNames.XS_POSITIVE_INTEGER;
	static int UNSIGNED_LONG = StandardNames.XS_UNSIGNED_LONG;
	static int UNSIGNED_INT = StandardNames.XS_UNSIGNED_INT;
	static int UNSIGNED_SHORT = StandardNames.XS_UNSIGNED_SHORT;
	static int UNSIGNED_BYTE = StandardNames.XS_UNSIGNED_BYTE;
	static int NORMALIZED_STRING = StandardNames.XS_NORMALIZED_STRING;
	static int TOKEN = StandardNames.XS_TOKEN;
	static int LANGUAGE = StandardNames.XS_LANGUAGE;
	static int NMTOKEN = StandardNames.XS_NMTOKEN;
	static int NMTOKENS = StandardNames.XS_NMTOKENS; 
	static int NAME = StandardNames.XS_NAME;
	static int NCNAME = StandardNames.XS_NCNAME;
	static int ID = StandardNames.XS_ID;
	static int IDREF = StandardNames.XS_IDREF;
	static int IDREFS = StandardNames.XS_IDREFS; 
	static int ENTITY = StandardNames.XS_ENTITY;
	static int YEAR_MONTH_DURATION = StandardNames.XDT_YEAR_MONTH_DURATION;
	static int DAY_TIME_DURATION = StandardNames.XDT_DAY_TIME_DURATION;


	static BuiltInAtomicType UNTYPED_ATOMIC_TYPE =  (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XDT_UNTYPED_ATOMIC);

	static BuiltInAtomicType ANY_ATOMIC_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XDT_ANY_ATOMIC_TYPE);

	static BuiltInAtomicType YEAR_MONTH_DURATION_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XDT_YEAR_MONTH_DURATION);

	static BuiltInAtomicType DAY_TIME_DURATION_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XDT_DAY_TIME_DURATION);

	static BuiltInAtomicType STRING_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_STRING);

	static BuiltInAtomicType BOOLEAN_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_BOOLEAN);

	static BuiltInAtomicType DECIMAL_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_DECIMAL);

	static BuiltInAtomicType FLOAT_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_FLOAT);

	static BuiltInAtomicType DOUBLE_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_DOUBLE);

	static BuiltInAtomicType DURATION_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_DURATION);

	static BuiltInAtomicType DATE_TIME_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_DATE_TIME);

	static BuiltInAtomicType TIME_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_TIME);

	static BuiltInAtomicType DATE_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_DATE);

	static BuiltInAtomicType G_YEAR_MONTH_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_G_YEAR_MONTH);

	static BuiltInAtomicType G_YEAR_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_G_YEAR);

	static BuiltInAtomicType G_MONTH_DAY_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_G_MONTH_DAY);

	static BuiltInAtomicType G_DAY_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_G_DAY);

	static BuiltInAtomicType G_MONTH_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_G_MONTH);

	static BuiltInAtomicType HEX_BINARY_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_HEX_BINARY);

	static BuiltInAtomicType BASE64_BINARY_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_BASE64_BINARY);

	static BuiltInAtomicType ANY_URI_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_ANY_URI);

	static BuiltInAtomicType QNAME_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_QNAME);

	static BuiltInAtomicType NOTATION_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_NOTATION);

	static BuiltInAtomicType INTEGER_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_INTEGER);

	static BuiltInAtomicType ID_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_ID);

	static BuiltInAtomicType IDREF_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_IDREF);

	static BuiltInAtomicType NCNAME_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XS_NCNAME);

	static BuiltInAtomicType NUMBER_TYPE = (BuiltInAtomicType)
	    BuiltInSchemaFactory.getSchemaType(StandardNames.XDT_NUMERIC);



	/**
	 * Get the ItemType of an Item
	 */
	static ItemType getItemType(Item item);

	/**
	 * Output (for diagnostics) a representation of the type of an item. This
	 * does not have to be the most specific type
	 */
	static std::string displayTypeName(Item item);

	/**
	 * Get the SimpleType object for a built-in simple type code
	 * @return the SimpleType, or null if not found
	 */
	static ItemType getBuiltInItemType(
		std::string namespace,
		std::string localName);

	/**
	 * Get the relationship of two schema types to each other
	 */
	static int schemaTypeRelationship(
		SchemaType s1,
		SchemaType s2);

	/**
	 * Get a type that is a common supertype of two given types
	 *
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @param th
	 * @return the item type that is a supertype of both
	 *     the supplied item types
	 */
	static ItemType getCommonSuperType(
		ItemType t1,
		ItemType t2);

	/**
	 * Determine whether this type is a primitive type. The primitive
	 * types are:
	 *   19 primitive types of XML Schema,
	 *   xs:integer, 
	 *   xdt:dayTimeDuration,
	 *   xdt:yearMonthDuration,
	 *   xdt:untypedAtomic,
	 *   the 7 node kindas,
	 *   all supertypes of these (item(), node(), xdt:anyAtomicType, xdt:number, ...) 
	 *
	 * @param code the item type code to be tested
	 * @return true if the type is considered primitive under the above rules
	 */
	static bool isPrimitiveType(int code);

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
	static bool isComparable(int t1, int t2, bool ordered);

	/**
	 * Determine whether a primitive type is ordered. Note that the rules for
	 * this differ between XPath and XML Schema: these are the XPath rules.
	 * @param type - the primitive item type being tested
	 * @return true - if the types are potentially comparable. For abstract
	 *    types (type=ATOMIC) we give the benefit of the doubt and return true.
	 */
	static bool isOrdered(int type);

	/**
	 * Test whether the supplied type, which must be a primitive type, is one of
	 * the numeric primitive types
	 * @param t - the type being tested
	 * @return true - if the type is integer, double, float, decimal, or
	 *    the abstract type "numeric"
	 */
	static bool isNumericPrimitiveType(ItemType t);

	/**
	 * Test whether the supplied type, which must be a primitive type, is one of
	 * the numeric primitive types
	 * @param fp - the fingerprint of the type being tested
	 * @return true - if the type is integer, double, float, decimal, or
	 *    the abstract type "numeric"
	 */
	static bool isNumericPrimitiveType(int fp);

};




/*______________________________________________________________________
|  
| This class exists to provide answers to questions about the type 
| hierarchy. Because such questions are potentially expensive, it caches 
| the answers. 
|_______________________________________________________________________*/

class TypeHierarchy
{
protected:
	Map map;
	config cfg;

	TypeHierarchy(Configuration config){
	Configuration getConfiguration();

public:
	enum type_relation {
		SAME_TYPE,		// A is the same type as B
		SUBSUMES,			// A subsumes B         (all B are A)
		SUBSUMED_BY,	// A is subsumed by B   (all A are B)
		OVERLAPS,			// A overlaps B         (some A are B)
		DISJOINT			// A is disjoint from B (no A are B)
	};

	/**
	 * Determine whether type A is type B or one of its subtypes,
	 * recursively
	 *
	 * @param subtype identifies the first type
	 * @param supertype identifies the second type
	 * @return - true, if the first type is the second type or a
	 *    (direct or indirect) subtype of the second type
	 */
	static bool isSubType(ItemType subtype, ItemType supertype) {

	/**
	 * Determine the relationship of one item type to another.
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @return type_relation
	 */
	static int relationship(ItemType t1, ItemType t2) {

	/**
	 * Determine the relationship of one item type to another.
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @return type_relation
	 */
	static int computeRelationship(ItemType t1, ItemType t2);

	/**
	 * Test whether a type annotation code represents the type xs:ID or
	 * one of its subtypes
 	 */
	static bool isIdCode(int typeCode) 

	/**
	 * Test whether a type annotation code represents the type 
	 * xs:IDREF, xs:IDREFS or one of their subtypes 
	 */
	static bool isIdrefsCode(int typeCode);

private:
	class ItemTypePair 
	{
		ItemType s;
		ItemType t;

		ItemTypePair(ItemType s, ItemType t) {
	    this.s = s;
	    this.t = t;
		}

		/**
		 * Returns a hash code value for the object.
		 * @return a hash code value for this object.
		 */
		int hashCode() { return s.hashCode() ^ t.hashCode(); }

		/**
		 * Indicates whether some other object is "equal to" this one.
		 */
		bool equals(Object obj) {
			ItemTypePair pair = (ItemTypePair)obj;
			return s.equals(pair.s) && t.equals(pair.t);
		}
	};


};


} /* namespace xqp */
#endif /* XQP_[MODULE]_H */

