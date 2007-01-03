



AnyNodeTest
AtomicValue
DocumentNodeTest
DynamicError
Expression
IntHashSet
Item
Locator
NameChecker
NamePool
NamespaceConstant
NamespaceResolver
NoNodeTest
NodeInfo
NodeKindTest
NodeTest
NormalizeSpace
ObjectValue
SequenceExtent
SequenceIterator
SingletonIterator
StandardNames
StaticContext
StaticProperty
UntypedAtomicValue
Value
ValueOf
Whitespace
XPathException
net.sf.saxon.Configuration
net.sf.saxon.Err




/**
 * An implementation of ItemType that matches any item (node or atomic value)
*/
class AnyItemType : ItemType
{
	private AnyItemType(){};
	private static AnyItemType theInstance = new AnyItemType();

public:
	/**
	 * Factory method to get the singleton instance
	 */
	static AnyItemType getInstance() { return theInstance; }


	/**
	 * Determine whether this item type is atomic (that is, whether it can ONLY match
	 * atomic values)
	 *
	 * @return false: this type can match nodes or atomic values
	 */
	bool isAtomicType() { return false; }


	/**
	 * Test whether a given item conforms to this type
	 * @param item The item to be tested
	 * @param allowURIPromotion
	 * @param config
	 * @return true if the item is an instance of this type; false otherwise
	*/
	bool matchesItem(Item item, boo allowURIPromotion, Configuration config) {
	    return true;
	}

	ItemType getSuperType(TypeHierarchy th) { return null; }

	/**
	 * Get the primitive item type corresponding to this item type. For item(),
	 * this is Type.ITEM. For node(), it is Type.NODE. For specific node kinds,
	 * it is the value representing the node kind, for example Type.ELEMENT.
	 * For anyAtomicValue it is Type.ATOMIC_VALUE. For numeric it is Type.NUMBER.
	 * For other atomic types it is the primitive type as defined in XML Schema,
	 * except that INTEGER is considered to be a primitive type.
	 */
	ItemType getPrimitiveItemType() { return this; }

	int getPrimitiveType() { return Type.ITEM; }

	AtomicType getAtomizedItemType() { return Type.ANY_ATOMIC_TYPE; }

	std::string tostd::string() { return "item()"; }

	std::string tostd::string(NamePool pool) { return "item()"; }

	int hashCode() { return "AnyItemType".hashCode(); }

}




/**
 * This class has a singleton instance which represents the XML Schema
 * built-in type xs:anySimpleType
 */

class AnySimpleType : SimpleType
{
private:
	static AnySimpleType theInstance = new AnySimpleType();
	AnySimpleType() { }
	~AnySimpleType() { }

public:
	/**
	 * Return true if this is an external object type, that is,
		 * a Saxon-defined type for external Java or .NET objects
	 */
	bool isExternalType() { return false; }

	/**
	 * Get the most specific possible atomic type that all items in this SimpleType belong to
	 * @return the lowest common supertype of all member types
	 */
	AtomicType getCommonAtomicType() { return Type.ANY_ATOMIC_TYPE; }

	/**
	 * Get the singular instance of this class
	 * @return the singular object representing xs:anyType
	 */
	static AnySimpleType getInstance() { return theInstance; }

	/**
	 * Get the validation status - always valid
	 */
	int getValidationStatus()  { return VALIDATED; }

	/**
	 * Get the base type
	 * @return AnyType
	 */
	SchemaType getBaseType() { return AnyType.getInstance(); }

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * @return the base type.
	 */
	SchemaType getKnownBaseType() throws IllegalStateException {
	    return getBaseType();
	}

	/**
	 * Test whether this SchemaType is a complex type
	 *
	 * @return true if this SchemaType is a complex type
	 */
	bool isComplexType() { return false; }

	/**
	 * Test whether this SchemaType is a simple type
	 * @return true if this SchemaType is a simple type
	 */
	bool isSimpleType() { return true; }

	/**
	 * Get the fingerprint of the name of this type
	 * @return the fingerprint.
	 */
	int getFingerprint() { return StandardNames.XS_ANY_SIMPLE_TYPE; }

	/**
	 * Get the namecode of the name of this type. This includes the prefix from the original
	 * type declaration: in the case of built-in types, there may be a conventional prefix
	 * or there may be no prefix.
	 */
	int getNameCode() { return StandardNames.XS_ANY_SIMPLE_TYPE; }

	/**
	 * Get a description of this type for use in diagnostics
	 * @return the string "xs:anyType"
	 */
	std::string getDescription() { return "xs:anySimpleType"; }

	/**
	 * Get the display name of the type: that is, a lexical QName with an arbitrary prefix
	 *
	 * @return a lexical QName identifying the type
	 */
	std::string getDisplayName() { return "xs:anySimpleType"; }

	/**
	 * Test whether this is the same type as another type.
		 * They are considered to be the same type
	 * if they are derived from the same type definition in the
		 * original XML representation (which
	 * can happen when there are multiple includes of the same file)
	 */
	bool isSameType(SchemaType other) { return (other instanceof AnySimpleType); }

	/**
	 * Get the typed value of a node that is annotated with this schema type.
		 * This shouldn't happen: nodes are never annotated as xs:anySimpleType;
		 * but if it does happen, we treat it as if it were untypedAtomic.
	 * @param node the node whose typed value is required
	 * @return an iterator returning a single untyped atomic value,
		 *         equivalent to the string value of the node.
	 */
	SequenceIterator getTypedValue(NodeInfo node) {
	    return SingletonIterator.makeIterator(
					new UntypedAtomicValue(node.getstd::stringValueCS()));
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type.
		 * The result of this method will always be consistent with the method
	 * {@link #getTypedValue}. However, this method is often more convenient
		 * and may be more efficient, especially in the common case where the value
		 * is expected to be a singleton.
	 * @param node the node whose typed value is required
	 * @return the typed value.
	 * @since 8.5
	 */
	Value atomize(NodeInfo node) {
	    return new UntypedAtomicValue(node.getstd::stringValueCS());
	}

	 /**
	 * Check that this type is validly derived from a given type
	 *
	 * @param type  the type from which this type is derived
	 * @param block the derivations that are blocked by the relevant element declaration
	 * @throws SchemaException if the derivation is not allowed
	 */
	void checkTypeDerivationIsOK(SchemaType type, int block) throws SchemaException {
	    if (type == this) {
	        return;
	    }
	    throw new SchemaException("Cannot derive xs:anySimpleType from another type");
	}

	/**
	 * Test whether this Simple Type is an atomic type
	 * @return false, this is not (necessarily) an atomic type
	 */
	bool isAtomicType() { return false; } 

	bool isAnonymousType() { return false; }


	/**
	 * Determine whether this is a list type
	 * @return false (it isn't a list type)
	 */
	bool isListType() { return false; }

	/**
	 * Determin whether this is a union type
	 * @return false (it isn't a union type)
	 */
	bool isUnionType() { return false; }

	/**
	 * Get the built-in ancestor of this type in the type hierarchy
	 * @return this type itself
	 */
	SchemaType getBuiltInBaseType() { return this; }

	/**
	 * Get the typed value corresponding to a given string value, assuming it is
	 * valid against this type
	 *
	 * @param value    the string value
	 * @param resolver a namespace resolver used to resolve any namespace prefixes appearing
	 *                 in the content of values. Can supply null, in which case any namespace-sensitive content
	 *                 will be rejected.
	 * @param nameChecker
	 * @return an iterator over the atomic sequence comprising the typed value. The objects
	 *         returned by this SequenceIterator will all be of type {@link AtomicValue}
	 */
	SequenceIterator getTypedValue(CharSequence value, NamespaceResolver resolver, NameChecker nameChecker) {
	    return SingletonIterator.makeIterator(new UntypedAtomicValue(value));
	}

	/**
	 * Check whether a given input string is valid according to this SimpleType
	 * @param value the input string to be checked
	 * @param nsResolver a namespace resolver used to resolve namespace prefixes if the type
	 * is namespace sensitive. The value supplied may be null; in this case any namespace-sensitive
	 * content will throw an UnsupportedOperationException.
	 * @param nameChecker
	 * @return null if validation succeeds (which it always does for this implementation)
	 * @throws UnsupportedOperationException if the type is namespace-sensitive and no namespace
	 * resolver is supplied
	 */
	ValidationException validateContent(CharSequence value, NamespaceResolver nsResolver, NameChecker nameChecker) {
	    return null;
	}

	/**
	 * Test whether this type represents namespace-sensitive content
	 * @return false
	 */
	bool isNamespaceSensitive() {
	    return false;
	}

	/**
	 * Returns the value of the 'block' attribute for this type, as a bit-signnificant
	 * integer with fields such as {@link SchemaType#DERIVATION_LIST} and {@link SchemaType#DERIVATION_EXTENSION}
	 *
	 * @return the value of the 'block' attribute for this type
	 */

	int getBlock() {
	    return 0;
	}

	/**
	 * Gets the integer code of the derivation method used to derive this type from its
	 * parent. Returns zero for primitive types.
	 *
	 * @return a numeric code representing the derivation method, for example {@link SchemaType#DERIVATION_RESTRICTION}
	 */

	int getDerivationMethod() {
	    return SchemaType.DERIVATION_RESTRICTION;
	}

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 *
	 * @param derivation the kind of derivation, for example {@link SchemaType#DERIVATION_LIST}
	 * @return true if this kind of derivation is allowed
	 */

	bool allowsDerivation(int derivation) {
	    return true;
	}

	/**
	 * Determine how values of this simple type are whitespace-normalized.
	 *
	 * @return one of {@link Whitespace#COLLAPSE},
	 *         {@link 
	 * @param th
	 */

	int getWhitespaceAction(TypeHierarchy th) {
	    return Whitespace.COLLAPSE;
	}

	/**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 *
	 * @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	 *                   {@link Type#DOCUMENT}
	 * @param env
	 */

	void analyzeContentExpression(Expression expression, int kind, StaticContext env) {
	    return;
	}
}




/**
 * This class has a singleton instance which represents the XML Schema
 * built-in type xs:anyType, also known as the UR-type.
 */

class AnyType : public ComplexType
{
private:
	static AnyType theInstance = new AnyType();
	private AnyType() { super(); }

public:
	/**
	 * Get the singular instance of this class
	 * @return the singular object representing xs:anyType
	 */
	static AnyType getInstance() { return theInstance; }

	/**
	 * Get the validation status - always valid
	 */
	int getValidationStatus()  { return VALIDATED; }

	/**
	 * Get the base type
	 * @return null (this is the root of the type hierarchy)
	 */
	SchemaType getBaseType() { return null; }

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	 */
	SchemaType getKnownBaseType() throws IllegalStateException { return null; }

	/**
	 * Gets the integer code of the derivation method used to derive this type from its
	 * parent. Returns zero for primitive types.
	 *
	 * @return a numeric code representing the derivation method, for example
	 * {@link SchemaType#DERIVATION_RESTRICTION}
	 */
	int getDerivationMethod() { return 0; } 

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 *
	 * @param derivation the kind of derivation, for example {@link SchemaType#DERIVATION_LIST}
	 * @return true if this kind of derivation is allowed
	 */
	bool allowsDerivation(int derivation) { return true; }

	/**
	 * Test whether this ComplexType has been marked as abstract.
	 * @return false: this class is not abstract.
	 */
	bool isAbstract() { return false; }

	/**
	 * Test whether this SchemaType is a complex type
	 *
	 * @return true if this SchemaType is a complex type
	 */
	bool isComplexType() { return true; }

	/**
	 * Test whether this is an anonymous type
	 * @return true if this SchemaType is an anonymous type
	 */
	bool isAnonymousType() { return false; }

	/**
	 * Test whether this SchemaType is a simple type
	 * @return true if this SchemaType is a simple type
	 */
	bool isSimpleType() { return false; }

	/**
	 * Test whether this SchemaType is an atomic type
	 * @return true if this SchemaType is an atomic type
	 */
	bool isAtomicType() { return false; }

	/**
	 * Returns the value of the 'block' attribute for this type, as a bit-signnificant
	 * integer with fields such as {@link SchemaType#DERIVATION_LIST}
	 * and {@link SchemaType#DERIVATION_EXTENSION}
	 *
	 * @return the value of the 'block' attribute for this type
	 */
	int getBlock() { return 0; }

	/**
	 * Test whether this complex type has complex content
	 * @return true: this complex type has complex content
	 */
	bool isComplexContent() { return true; }

	/**
	 * Test whether this complex type has simple content
	 * @return false: this complex type has complex content
	 */
	bool isSimpleContent() { return false; }

	/**
	 * Test whether this complex type has "all" content, that is, a content model
	 * using an xs:all compositor
	 * @return false: this complex type does not use an "all" compositor
	 */
	bool isAllContent() { return false; }

	/**
	 * For a complex type with simple content, return the simple type of the content.
	 * Otherwise, return null.
	 * @return null: this complex type does not have simple content
	 */
	SimpleType getSimpleContentType() { return null; }

	/**
	 * Test whether this complex type is derived by restriction
	 * @return false: this type is not a restriction
	 */
	bool isRestricted() { return false; }

	/**
	 * Test whether the content type of this complex type is empty
	 * @return false: the content model is not empty
	 */
	bool isEmptyContent() { return false; }

	/**
	 * Test whether the content model of this complexType allows empty content
	 * @return true: the content is allowed to be empty
	 */
	bool isEmptiable() { return true; }

	/**
	 * Test whether this complex type allows mixed content
	 * @return true: mixed content is allowed
	 */
	bool isMixedContent() { return true; }

	/**
	 * Get the fingerprint of the name of this type
	 * @return the fingerprint.
	 */
	int getFingerprint() { return StandardNames.XS_ANY_TYPE; }

	/**
	 * Get the namecode of the name of this type. This includes the prefix from the original
	 * type declaration: in the case of built-in types, there may be a conventional prefix
	 * or there may be no prefix.
	 */
	int getNameCode() { return StandardNames.XS_ANY_TYPE; }

	/**
	 * Get a description of this type for use in diagnostics
	 * @return the string "xs:anyType"
	 */
	std::string getDescription() { return "xs:anyType"; }

	/**
	 * Get the display name of the type: that is, a lexical QName with an arbitrary prefix
	 *
	 * @return a lexical QName identifying the type
	 */
	std::string getDisplayName() { return "xs:anyType"; }

	/**
	 * Test whether this is the same type as another type. They are considered to be the same type
	 * if they are derived from the same type definition in the original XML representation (which
	 * can happen when there are multiple includes of the same file)
	 */

	bool isSameType(SchemaType other) {
	    return (other instanceof AnyType);
	}

	/**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 *
	 @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	      *                   {@link Type#DOCUMENT}
	 * @param env

	 */
	void analyzeContentExpression(Expression expression, int kind, StaticContext env) {
	    return;
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type
	 * @param node the node whose typed value is required
	 * @return an iterator returning a single untyped atomic value, equivalent to the string value of the node. This
	 * follows the standard rules for elements with mixed content.
	 */
	SequenceIterator getTypedValue(NodeInfo node) {
	    return SingletonIterator.makeIterator(new UntypedAtomicValue(node.getstd::stringValue()));
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type. The result of this method will always be consistent with the method
	 * {@link #getTypedValue}. However, this method is often more convenient and may be
	 * more efficient, especially in the common case where the value is expected to be a singleton.
	 *
	 * @param node the node whose typed value is required
	 * @return the typed value.
	 * @since 8.5
	 */

	Value atomize(NodeInfo node) {
	    return new UntypedAtomicValue(node.getstd::stringValue());
	}

	/**
	 * Test whether this complex type subsumes another complex type. The algorithm
	 * used is as published by Thompson and Tobin, XML Europe 2003.
	 * @param sub the other type (the type that is derived by restriction, validly or otherwise)
	 * @return null indicating that this type does indeed subsume the other; or a string indicating
	 * why it doesn't.
	 */

	std::string subsumes(ComplexType sub) {
	    return null;
	}

	/**
	 * Check that this type is validly derived from a given type
	 *
	 * @param type  the type from which this type is derived
	 * @param block the derivations that are blocked by the relevant element declaration
	 * @throws SchemaException
	 *          if the derivation is not allowed
	 */

	void checkTypeDerivationIsOK(SchemaType type, int block) throws SchemaException {
	    throw new SchemaException("Cannot derive xs:anyType from another type");
	}

	/**
	 * Find an element particle within this complex type definition having a given element name
	 * (identified by fingerprint), and return the schema type associated with that element particle.
	 * If there is no such particle, return null. If the fingerprint matches an element wildcard,
	 * return the type of the global element declaration with the given name if one exists, or AnyType
	 * if none exists and lax validation is permitted by the wildcard.
	 *
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	SchemaType getElementParticleType(int fingerprint) {
	    return this;
	}

	/**
	 * Find an element particle within this complex type definition having a given element name
	 * (identified by fingerprint), and return the cardinality associated with that element particle,
	 * that is, the number of times the element can occur within this complex type. The value is one of
	 * {@link StaticProperty#ALLOWS_ZERO_OR_ONE},
	 * {@link StaticProperty#ALLOWS_ONE_OR_MORE},
	 * If there is no such particle, return zero.
	 *
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	int getElementParticleCardinality(int fingerprint) {
	    return StaticProperty.ALLOWS_ZERO_OR_MORE;
	}

	/**
	 * Find an attribute use within this complex type definition having a given attribute name
	 * (identified by fingerprint), and return the schema type associated with that attribute.
	 * If there is no such attribute use, return null. If the fingerprint matches an attribute wildcard,
	 * return the type of the global attribute declaration with the given name if one exists, or AnySimpleType
	 * if none exists and lax validation is permitted by the wildcard.
	 *
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	SchemaType getAttributeUseType(int fingerprint) {
	    return AnySimpleType.getInstance();
	}
}






/**
 * Marker interface for atomic types (these are either built-in atomic types
 * or user-defined atomic types). An AtomicType is both an ItemType (a possible type
 * for items in a sequence) and a SchemaType (a possible type for validating and
 * annotating nodes).
 */
interface AtomicType extends SimpleType, ItemType
{
	/**
	 * Factory method to create values of a derived atomic type. This method
	 * is not used to create values of a built-in type, even one that is not
	 * primitive.
	 * @param primValue the value in the value space of the primitive type
	 * @param lexicalValue the value in the lexical space. If null, the string value of primValue
	 * is used. This value is checked against the pattern facet (if any)
	 * @param validate     true if the value is to be validated against the facets of the derived
	 *                     type; false if the caller knows that the value is already valid.
	 * @return the derived atomic value if validation succeeds, or an ErrorValue otherwise. The ErrorValue
	 * encapsulates the exception that occurred; it is the caller's responsibility to check for this.
	 */

	AtomicValue makeDerivedValue(AtomicValue primValue, CharSequence lexicalValue, bool validate);

}







/**
This class represents a built-in atomic type, which may be either a 
primitive type (such as xs:decimal or xs:anyURI) or a derived type 
(such as xs:ID or xdt:dayTimeDuration).
*/

class BuiltInAtomicType : public AtomicType
{

	int fingerprint;
	int baseFingerprint = -1;

	BuiltInAtomicType() {}

	BuiltInAtomicType(int fingerprint) {
	    this.fingerprint = fingerprint;
	}

	/**
	 * Return true if this is an external object type, that is, a Saxon-defined type for external
	 * Java or .NET objects
	 */
	bool isExternalType() {
	    return false;
	}

	/**
	 * Get the most specific possible atomic type that all items in this SimpleType belong to
	 * @return the lowest common supertype of all member types
	 */
	AtomicType getCommonAtomicType() { return this; }

	/**
	 * Get the validation status - always valid
	 */
	int getValidationStatus()  { return VALIDATED; }

	/**
	 * Returns the value of the 'block' attribute for this type, as a bit-significant
	 * integer with fields such as {@link SchemaType#DERIVATION_LIST} and {@link SchemaType#DERIVATION_EXTENSION}
	 *
	 * @return the value of the 'block' attribute for this type
	 */

	int getBlock() { return 0; }

	/**
	 * Gets the integer code of the derivation method used to derive this type from its
	 * parent. Returns zero for primitive types.
	 *
	 * @return a numeric code representing the derivation method, for example {@link SchemaType#DERIVATION_RESTRICTION}
	 */
	int getDerivationMethod() { return SchemaType.DERIVATION_RESTRICTION; }

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 *
	 * @param derivation the kind of derivation, for example {@link SchemaType#DERIVATION_LIST}
	 * @return true if this kind of derivation is allowed
	 */
	bool allowsDerivation(int derivation) { return true; }

	void setBaseTypeFingerprint(int baseFingerprint) {
	    this.baseFingerprint = baseFingerprint;
	}

	/**
	 * Get the fingerprint of the name of this type
	 *
	 * @return the fingerprint. Returns an invented fingerprint for an anonymous type.
	 */
	int getFingerprint() { return fingerprint; }

	/**
	 * Get the namecode of the name of this type. This includes the prefix from the original
	 * type declaration: in the case of built-in types, there may be a conventional prefix
	 * or there may be no prefix.
	 */

	int getNameCode() { return fingerprint; }

	/**
	 * Get the display name of the type: that is, a lexical QName with an arbitrary prefix
	 *
	 * @return a lexical QName identifying the type
	 */

	std::string getDisplayName() {
	    return StandardNames.getDisplayName(fingerprint);
	}

	/**
	 * Test whether this SchemaType is a complex type
	 *
	 * @return true if this SchemaType is a complex type
	 */

	bool isComplexType() { return false; }

	/**
	 * Test whether this is an anonymous type
	 * @return true if this SchemaType is an anonymous type
	 */

	bool isAnonymousType() { return false; }

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	 */

	SchemaType getBaseType() {
	    if (baseFingerprint == -1) {
	        return null;
	    } else {
	        return BuiltInSchemaFactory.getSchemaType(baseFingerprint);
	    }
	}

	/**
	 * Test whether a given item conforms to this type
	 *
	 * @param item The item to be tested
	 * @param allowURIPromotion
	 * @param config
	 * @return true if the item is an instance of this type; false otherwise
	 */

	bool matchesItem(Item item, bool allowURIPromotion, Configuration config) {
	    if (item instanceof AtomicValue) {
	        AtomicValue value = (AtomicValue)item;
	        AtomicType type = (AtomicType)value.getItemType(config.getTypeHierarchy());
	        if (type.getFingerprint()==this.getFingerprint()) {
	            // note, with compiled stylesheets one can have two objects representing
	            // the same type, so comparing identity is not safe
	            return true;
	        }
	        TypeHierarchy th = config.getTypeHierarchy();
	        bool ok = th.isSubType(type, this);
	        if (ok) {
	            return true;
	        }
	        if (allowURIPromotion && this.getFingerprint() == Type.STRING && th.isSubType(type, Type.ANY_URI_TYPE)) {
	            // allow promotion from anyURI to string
	            return true;
	        }
	    }
	    return false;
	}

	/**
	 * Get the type from which this item type is derived by restriction. This
	 * is the supertype in the XPath type heirarchy, as distinct from the Schema
	 * base type: this means that the supertype of xs:bool is xdt:anyAtomicType,
	 * whose supertype is item() (rather than xs:anySimpleType).
	 *
	 * @return the supertype, or null if this type is item()
	 * @param th
	 */

	ItemType getSuperType(TypeHierarchy th) {
	    SchemaType base = getBaseType();
	    if (base instanceof AnySimpleType) {
	        return AnyItemType.getInstance();
	    } else {
	        return (ItemType)base;
	    }
	}

	/**
	 * Get the primitive item type corresponding to this item type. For item(),
	 * this is Type.ITEM. For node(), it is Type.NODE. For specific node kinds,
	 * it is the value representing the node kind, for example Type.ELEMENT.
	 * For anyAtomicValue it is Type.ATOMIC_VALUE. For numeric it is Type.NUMBER.
	 * For other atomic types it is the primitive type as defined in XML Schema,
	 * except that INTEGER is considered to be a primitive type.
	 */

	ItemType getPrimitiveItemType() {
	    if (Type.isPrimitiveType(getFingerprint())) {
	         return this;
	     } else {
	         ItemType s = (ItemType)getBaseType();
	         if (s.isAtomicType()) {
	             return s.getPrimitiveItemType();
	         } else {
	             return this;
	         }
	     }
	}

	/**
	 * Get the primitive type corresponding to this item type. For item(),
	 * this is Type.ITEM. For node(), it is Type.NODE. For specific node kinds,
	 * it is the value representing the node kind, for example Type.ELEMENT.
	 * For anyAtomicValue it is Type.ATOMIC_VALUE. For numeric it is Type.NUMBER.
	 * For other atomic types it is the primitive type as defined in XML Schema,
	 * except that INTEGER is considered to be a primitive type.
	 */

	int getPrimitiveType() {
	    int x = getFingerprint();
	    if (Type.isPrimitiveType(x)) {
	        return x;
	    } else {
	        SchemaType s = getBaseType();
	        if (s.isAtomicType()) {
	            return ((AtomicType)s).getPrimitiveType();
	        } else {
	            return this.getFingerprint();
	        }
	    }
	}

	/**
	 * Determine whether this type is supported in a basic XSLT processor
	 */

	bool isAllowedInBasicXSLT() {
	    int fp = getFingerprint();
	    return (Type.isPrimitiveType(fp) && fp != StandardNames.XS_NOTATION);
	}

	/**
	 * Produce a representation of this type name for use in error messages.
	 * Where this is a QName, it will use conventional prefixes
	 */

	std::string tostd::string(NamePool pool) {
	    return getDisplayName();
	}

	/**
	 * Get the item type of the atomic values that will be produced when an item
	 * of this type is atomized
	 */

	AtomicType getAtomizedItemType() {
	    return this;
	}

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	 */

	SchemaType getKnownBaseType() {
	    return getBaseType();
	}

	/**
	 * Test whether this is the same type as another type. They are considered to be the same type
	 * if they are derived from the same type definition in the original XML representation (which
	 * can happen when there are multiple includes of the same file)
	 */

	bool isSameType(SchemaType other) {
	    return (other.getFingerprint() == this.getFingerprint());
	}

	std::string getDescription() {
	    return getDisplayName();
	}

	std::string tostd::string() {
	    return getDisplayName();
	}

	/**
	 * Check that this type is validly derived from a given type
	 *
	 * @param type  the type from which this type is derived
	 * @param block the derivations that are blocked by the relevant element declaration
	 * @throws SchemaException if the derivation is not allowed
	 */

	void checkTypeDerivationIsOK(SchemaType type, int block) throws SchemaException, ValidationException {
	    // method not used
	}

	/**
	 * Returns true if this SchemaType is a SimpleType
	 *
	 * @return true (always)
	 */

	bool isSimpleType() {
	    return true;
	}

	/**
	 * Test whether this Simple Type is an atomic type
	 * @return true, this is an atomic type
	 */

	bool isAtomicType() {
	    return true;
	}


	/**
	 * Returns true if this type is derived by list, or if it is derived by restriction
	 * from a list type, or if it is a union that contains a list as one of its members
	 *
	 * @return true if this is a list type
	 */

	bool isListType() {
	    return false;
	}

	/**
	 * Return true if this type is a union type (that is, if its variety is union)
	 *
	 * @return true for a union type
	 */

	bool isUnionType() {
	    return false;
	}

	/**
	 * Determine the whitespace normalization required for values of this type
	 *
	 * @return one of PRESERVE, REPLACE, COLLAPSE
	 * @param th
	 */

	int getWhitespaceAction(TypeHierarchy th) {
	    if (getPrimitiveType() == Type.STRING) {
	        if (th.isSubType(this, (ItemType)BuiltInSchemaFactory.getSchemaType(StandardNames.XS_TOKEN))) {
	            return Whitespace.COLLAPSE;
	        } else if (th.isSubType(this,
	                (ItemType)BuiltInSchemaFactory.getSchemaType(StandardNames.XS_NORMALIZED_STRING))) {
	            return Whitespace.REPLACE;
	        } else {
	            return Whitespace.PRESERVE;
	        }
	    } else {
	        return Whitespace.COLLAPSE;
	    }
	}

	/**
	 * Returns the built-in base type this type is derived from.
	 *
	 * @return the first built-in type found when searching up the type hierarchy
	 */
	SchemaType getBuiltInBaseType() {
	    BuiltInAtomicType base = this;
	    while ((base != null) && (base.getFingerprint() > 1023)) {
	        base = (BuiltInAtomicType)base.getBaseType();
	    }
	    return base;
	}

	/**
	 * Test whether this simple type is namespace-sensitive, that is, whether
	 * it is derived from xs:QName or xs:NOTATION
	 *
	 * @return true if this type is derived from xs:QName or xs:NOTATION
	 */

	bool isNamespaceSensitive() {
	    BuiltInAtomicType base = this;
	    int fp = base.getFingerprint();
	    while (fp > 1023) {
	        base = (BuiltInAtomicType)base.getBaseType();
	        fp = base.getFingerprint();
	    }

	    if (fp == StandardNames.XS_QNAME || fp == StandardNames.XS_NOTATION) {
	        return true;
	    }
	    return false;
	}

	/**
	 * Check whether a given input string is valid according to this SimpleType
	 *
	 * @param value      the input string to be checked
	 * @param nsResolver a namespace resolver used to resolve namespace prefixes if the type
	 *                   is namespace sensitive. The value supplied may be null; in this case any namespace-sensitive
	 *                   content will throw an UnsupportedOperationException.
	 * @param nameChecker
	 * @return XPathException if the value is invalid. Note that the exception is returned rather than being thrown.
	 * Returns null if the value is valid.
	 * @throws UnsupportedOperationException if the type is namespace-sensitive and no namespace
	 *                                       resolver is supplied
	 */

	ValidationException validateContent(CharSequence value, NamespaceResolver nsResolver,
	                                           NameChecker nameChecker) {
	    int f = getFingerprint();
	    if (f==StandardNames.XS_STRING ||
	            f==StandardNames.XS_ANY_SIMPLE_TYPE ||
	            f==StandardNames.XDT_UNTYPED_ATOMIC ||
	            f==StandardNames.XDT_ANY_ATOMIC_TYPE) {
	        return null;
	    }
	    ValidationException result = null;
	    if (isNamespaceSensitive()) {
	        if (nsResolver == null) {
	            throw new UnsupportedOperationException("Cannot validate a QName without a namespace resolver");
	        }
	        try {
	            std::string[] parts = nameChecker.getQNameParts(value.tostd::string());
	            std::string uri = nsResolver.getURIForPrefix(parts[0], true);
	            if (uri == null) {
	                result = new ValidationException("Namespace prefix " + Err.wrap(parts[0]) +
	                        " has not been declared");
	            }
	            new QNameValue(parts[0], uri, parts[1], nameChecker);
	        } catch (QNameException err) {
	            result = new ValidationException("Invalid lexical QName " + Err.wrap(value));
	        } catch (XPathException err) {
	            result = new ValidationException(err.getMessage());
	        }
	    } else {

	        Value v = std::stringValue.convertstd::stringToBuiltInType(value, this, nameChecker);
	        if (v instanceof ValidationErrorValue) {
	            result = ((ValidationErrorValue)v).getException();
//                result = new ValidationException("Value " + Err.wrap(value, Err.VALUE) + " is invalid for type "
//                        + getDisplayName() + ". " + ((ValidationErrorValue)v).getException().getMessage());
	        }
	    }
	    return result;
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type
	 *
	 * @param node the node whose typed value is required
	 * @return an iterator over the items making up the typed value of this node. The objects
	 *         returned by this SequenceIterator will all be of type {@link AtomicValue}
	 */

	SequenceIterator getTypedValue(NodeInfo node)
	        throws XPathException {
	    try {
	        return getTypedValue(node.getstd::stringValue(),
	                new InscopeNamespaceResolver(node),
	                node.getConfiguration().getNameChecker());
	    } catch (ValidationException err) {
	        throw new DynamicError("Internal error: value doesn't match its type annotation. " + err.getMessage());
	    }
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type.
	 * The result of this method will always be consistent with the method
	 * {@link #getTypedValue}. However, this method is often more convenient and may be
	 * more efficient, especially in the common case where the value is expected to be a singleton.
	 *
	 * @param node the node whose typed value is required
	 * @return the typed value.
	 * @since 8.5
	 */

	Value atomize(NodeInfo node) throws XPathException {
	            // Fast path for common cases
	    if (fingerprint == StandardNames.XS_STRING) {
	        return std::stringValue.makestd::stringValue(node.getstd::stringValueCS());
	    } else if (fingerprint == StandardNames.XDT_UNTYPED_ATOMIC) {
	        return new UntypedAtomicValue(node.getstd::stringValueCS());
	    }
	    NameChecker checker = node.getConfiguration().getNameChecker();
	    if (isNamespaceSensitive()) {
	        try {
	            NamespaceResolver resolver = new InscopeNamespaceResolver(node);
	            std::string[] parts = checker.getQNameParts(node.getstd::stringValueCS());
	            std::string uri = resolver.getURIForPrefix(parts[0], true);
	            if (uri == null) {
	                throw new ValidationException("Namespace prefix " + Err.wrap(parts[0]) +
	                        " has not been declared");
	            }
	            return new QNameValue(parts[0], uri, parts[1], checker);
	        } catch (QNameException err) {
	            throw new ValidationException("Invalid lexical QName " + Err.wrap(node.getstd::stringValueCS()));
	        } catch (XPathException err) {
	            throw new ValidationException(err.getMessage());
	        }
	    }
	    AtomicValue val = std::stringValue.convertstd::stringToBuiltInType(node.getstd::stringValueCS(), this, checker);
	    if (val instanceof ValidationErrorValue) {
	        throw ((ValidationErrorValue)val).getException();
	    }
	    return val;
	}

	/**
	 * Get the typed value corresponding to a given string value, assuming it is
	 * valid against this type
	 *
	 * @param value    the string value
	 * @param resolver a namespace resolver used to resolve any namespace prefixes appearing
	 *                 in the content of values. Can supply null, in which case any namespace-sensitive content
	 *                 will be rejected.
	 * @param nameChecker
	 * @return an iterator over the atomic sequence comprising the typed value. The objects
	 *         returned by this SequenceIterator will all be of type {@link AtomicValue}
	 */

	SequenceIterator getTypedValue(CharSequence value, NamespaceResolver resolver, NameChecker nameChecker)
	        throws ValidationException {
	    // Fast path for common cases
	    if (fingerprint == StandardNames.XS_STRING) {
	        return SingletonIterator.makeIterator(std::stringValue.makestd::stringValue(value));
	    } else if (fingerprint == StandardNames.XDT_UNTYPED_ATOMIC) {
	        return SingletonIterator.makeIterator(new UntypedAtomicValue(value));
	    } else if (isNamespaceSensitive()) {
	        try {
	            std::string[] parts = nameChecker.getQNameParts(value.tostd::string());
	            std::string uri = resolver.getURIForPrefix(parts[0], true);
	            if (uri == null) {
	                throw new ValidationException("Namespace prefix " + Err.wrap(parts[0]) +
	                        " has not been declared");
	            }
	            return SingletonIterator.makeIterator(new QNameValue(parts[0], uri, parts[1], nameChecker));
	        } catch (QNameException err) {
	            throw new ValidationException("Invalid lexical QName " + Err.wrap(value));
	        } catch (XPathException err) {
	            throw new ValidationException(err.getMessage());
	        }
	    }
	    // TODO: if we really can assume validity, we should set nameChecker to null in the following call
	    AtomicValue val = std::stringValue.convertstd::stringToBuiltInType(value, this, nameChecker);
	    if (val instanceof ValidationErrorValue) {
	        throw ((ValidationErrorValue)val).getException();
	    }
	    return SingletonIterator.makeIterator(val);
	}


	/**
	 * Factory method to create values of a derived atomic type. This method
	 * is not used to create values of a built-in type, even one that is not
	 * primitive.
	 *
	 * @param primValue    the value in the value space of the primitive type
	 * @param lexicalValue the value in the lexical space. If null, the string value of primValue
	 * @param validate     true if the value is to be validated against the facets of the derived
	 *                     type; false if the caller knows that the value is already valid.
	 */

	AtomicValue makeDerivedValue(AtomicValue primValue, CharSequence lexicalValue, bool validate) {
	    throw new UnsupportedOperationException("makeDerivedValue is not supported for built-in types");
	}

	/**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 *
	 * @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	 *                   {@link Type#ATTRIBUTE}, or {@link Type#DOCUMENT}
	 * @param env
	 * @throws XPathException
	 *          if the expression will never deliver a value of the correct type
	 */

	void analyzeContentExpression(Expression expression, int kind, StaticContext env) throws XPathException {
	    analyzeContentExpression(this, expression, env, kind);
	}

   /**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 * @param simpleType the simple type against which the expression is to be checked
	 * @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	 *                   {@link Type#ATTRIBUTE}, or {@link Type#DOCUMENT}
	 * @throws XPathException
	 *          if the expression will never deliver a value of the correct type
	 */

	static void analyzeContentExpression(SimpleType simpleType, Expression expression, StaticContext env, int kind)
	throws XPathException {
	    if (kind == Type.ELEMENT) {
	        expression.checkPermittedContents(simpleType, env, true);

// if we are building the content of an element or document, no atomization will take
// place, and therefore the presence of any element or attribute nodes in the content will
// cause a validity error, since only simple content is allowed

       if (Type.isSubType(itemType, NodeKindTest.makeNodeKindTest(Type.ELEMENT))) {

//                throw new StaticError("The content of an element with a simple type must not include any element nodes");
//            }
//            if (Type.isSubType(itemType, NodeKindTest.makeNodeKindTest(Type.ATTRIBUTE))) {
//                throw new StaticError("The content of an element with a simple type must not include any attribute nodes");

//            }

	    } else if (kind == Type.ATTRIBUTE) {

// for attributes, do a check only for text nodes and atomic values: anything else gets atomized

	        if (expression instanceof ValueOf || expression instanceof Value) {
	            expression.checkPermittedContents(simpleType, env, true);
	        }
	    }
	}

}










/**
This class is used to implement the built-in list types NMTOKENS, 
ENTITIES, IDREFS. It is also used to represent the anonymous type of 
the xsi:schemaLocation attribute (a list of xs:anyURI values).</p>
*/

class BuiltInListType : public ListType
{
private:
	int fingerprint;

public:
	/**
	 * Return true if this is an external object type, that is, a Saxon-defined type for external
	 * Java or .NET objects
	 */

	bool isExternalType() {
	    return false;
	}


	/**
	 * Determine how values of this simple type are whitespace-normalized.
	 *
	 * @return one of {@link Whitespace#COLLAPSE},
	 *         {@link 
	 * @param th
	 */

	int getWhitespaceAction(TypeHierarchy th) {
	    return Whitespace.COLLAPSE;
	}

	/**
	 *  The SimpleType of the items in the list.
	 */

	private BuiltInAtomicType itemType = null;

	/**
	 * Get the most specific possible atomic type that all items in this SimpleType belong to
	 *
	 * @return the lowest common supertype of all member types
	 */

	AtomicType getCommonAtomicType() {
	    return itemType;
	}

	/**
	 * Create a new ListType.
	 */

	BuiltInListType(int fingerprint) {
	    this.fingerprint = fingerprint;
	    switch (fingerprint) {
	        case StandardNames.XS_ENTITIES:
	            itemType = (BuiltInAtomicType)BuiltInSchemaFactory.getSchemaType(StandardNames.XS_ENTITY);
	            break;
	        case StandardNames.XS_IDREFS:
	            itemType = (BuiltInAtomicType)BuiltInSchemaFactory.getSchemaType(StandardNames.XS_IDREF);
	            break;
	        case StandardNames.XS_NMTOKENS:
	            itemType = (BuiltInAtomicType)BuiltInSchemaFactory.getSchemaType(StandardNames.XS_NMTOKEN);
	            break;
	        case StandardNames.XSI_SCHEMA_LOCATION_TYPE:
	            itemType = (BuiltInAtomicType)BuiltInSchemaFactory.getSchemaType(StandardNames.XS_ANY_URI);
	            break;
	    }
	}

	/**
	 * Get the validation status - always valid
	 */
	int getValidationStatus()  {
	    return VALIDATED;
	}

   /**
	 * Returns the base type that this type inherits from.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 * @return the base type.
	*/

	SchemaType getBaseType() {
	    return AnySimpleType.getInstance();
	}

	/**
	 * Test whether this Simple Type is an atomic type
	 * @return false, this is not an atomic type
	 */

	bool isAtomicType() {
	    return false;
	}


   /**
	 * Returns true if this type is derived by list, or if it is derived by restriction
	 * from a list type, or if it is a union that contains a list as one of its members
	 */

	bool isListType() {
	    return true;
	}

	bool isUnionType() {
	    return false;
	}

	/**
	 * Test whether this is an anonymous type
	 * @return true if this SchemaType is an anonymous type
	 */

	bool isAnonymousType() {
	    return false;
	}

	SchemaType getBuiltInBaseType() {
	    return this;
	}

	bool isNamespaceSensitive() {
	    return false;
	}

	/**
	 * Get the fingerprint of the name of this type
	 * @return the fingerprint. Returns an invented fingerprint for an anonymous type.
	 */

	int getFingerprint() {
	    return fingerprint;
	}

	/**
	 * Get the namecode of the name of this type. Because built-in types don't depend on the namePool,
	 * this actually returns the fingerprint, which contains no information about the namespace prefix
	 */

	int getNameCode() {
	    return fingerprint;
	}

	/**
	 * Get the display name of the type: that is, a lexical QName with an arbitrary prefix
	 *
	 * @return a lexical QName identifying the type
	 */

	std::string getDisplayName() {
	    return StandardNames.getDisplayName(fingerprint);
	}

	/**
	 * Test whether this SchemaType is a complex type
	 *
	 * @return true if this SchemaType is a complex type
	 */

	bool isComplexType() {
	    return false;
	}

	/**
	 * Test whether this SchemaType is a simple type
	 * @return true if this SchemaType is a simple type
	 */

	bool isSimpleType() {
	    return true;
	}

	/**
	 * Returns the value of the 'block' attribute for this type, as a bit-signnificant
	 * integer with fields such as {@link SchemaType#DERIVATION_LIST} and {@link SchemaType#DERIVATION_EXTENSION}
	 *
	 * @return the value of the 'block' attribute for this type
	 */

	int getBlock() {
	    return 0;  //To change body of implemented methods use File | Settings | File Templates.
	}

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	 */

	SchemaType getKnownBaseType() throws IllegalStateException {
	    return AnySimpleType.getInstance();
	}

	/**
	 * Gets the integer code of the derivation method used to derive this type from its
	 * parent. Returns zero for primitive types.
	 *
	 * @return a numeric code representing the derivation method, for example {@link SchemaType#DERIVATION_RESTRICTION}
	 */

	int getDerivationMethod() {
	    return SchemaType.DERIVATION_LIST;
	}

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 *
	 * @param derivation the kind of derivation, for example {@link SchemaType#DERIVATION_LIST}
	 * @return true if this kind of derivation is allowed
	 */

	bool allowsDerivation(int derivation) {
	    return true;
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type. This method must be called
	 * only for a valid type.
	 *
	 * @param node the node whose typed value is required
	 * @return a SequenceIterator over the atomic values making up the typed value of the specified
	 *         node. The objects returned by this iterator are of type {@link AtomicValue}
	 */

	SequenceIterator getTypedValue(NodeInfo node) throws XPathException {
	    try {
	        return getTypedValue(node.getstd::stringValue(),
	                new InscopeNamespaceResolver(node),
	                node.getConfiguration().getNameChecker());
	    } catch (ValidationException err) {
	        throw new DynamicError("Internal error: value doesn't match its type annotation. " + err.getMessage());
	    }
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type. The result of this method will always be consistent with the method
	 * {@link #getTypedValue}. However, this method is often more convenient and may be
	 * more efficient, especially in the common case where the value is expected to be a singleton.
	 *
	 * @param node the node whose typed value is required
	 * @return the typed value.
	 * @since 8.5
	 */

	Value atomize(NodeInfo node) throws XPathException {
	    return new SequenceExtent(getTypedValue(node)).simplify();
	}

	/**
	 * Test whether this is the same type as another type. They are considered to be the same type
	 * if they are derived from the same type definition in the original XML representation (which
	 * can happen when there are multiple includes of the same file)
	 */

	bool isSameType(SchemaType other) {
	    return other.getFingerprint() == this.getFingerprint();
	}

	std::string getDescription() {
	    return getDisplayName();
	}

	/**
	 * Check that this type is validly derived from a given type
	 *
	 * @param type  the type from which this type is derived
	 * @param block the derivations that are blocked by the relevant element declaration
	 * @throws SchemaException
	 *          if the derivation is not allowed
	 */

	void checkTypeDerivationIsOK(SchemaType type, int block) throws SchemaException, ValidationException {
	    //To change body of implemented methods use File | Settings | File Templates.
	}

	/**
	 * Get the local name of this type
	 * @return the local part of the name, or null if the type is anonymous
	 */

	std::string getLocalName() {
	   return getDisplayName().substring(3);
	}

	/**
	 * Returns the simpleType of the items in this ListType.
	 * @return the simpleType of the items in this ListType.
	*/

	SimpleType getItemType() {
	    return itemType;
	}

	/**
	 * Apply the whitespace normalization rules for this simple type
	 * @param value the string before whitespace normalization
	 * @return the string after whitespace normalization
	 */

	std::string applyWhitespaceNormalization(std::string value) {
	    return NormalizeSpace.normalize(value).tostd::string();
	}

	/**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 *
	 * @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	 *                   {@link Type#ATTRIBUTE}, or {@link Type#DOCUMENT}
	 * @param env
	 * @throws XPathException
	 *          if the expression will never deliver a value of the correct type
	 */

	void analyzeContentExpression(Expression expression, int kind, StaticContext env) throws XPathException {
	    BuiltInAtomicType.analyzeContentExpression(this, expression, env, kind);
	}

	/**
	 * Check whether a given input string is valid according to this SimpleType
	 * @param value the input string to be checked
	 * @param nsResolver a namespace resolver used to resolve namespace prefixes if the type
	 * is namespace sensitive. The value supplied may be null; in this case any namespace-sensitive
	 * content will throw an UnsupportedOperationException.
	 * @param nameChecker
	 * @throws UnsupportedOperationException if the type is namespace-sensitive and no namespace
	 * resolver is supplied
	 */

	ValidationException validateContent(CharSequence value, NamespaceResolver nsResolver, NameChecker nameChecker) {
	    SimpleType base = getItemType();
	    SequenceIterator iter = new std::stringTokenIterator(value.tostd::string());
	    ValidationException result = null;
	    int count = 0;
	    try {
	        while (true) {
	            std::stringValue val = (std::stringValue)iter.next();
	            if (val == null) break;
	            count++;
	            ValidationException v = base.validateContent(val.getstd::stringValue(), nsResolver, nameChecker);
	            if (v != null) {
	                return v;
	            }
	        }
	    } catch (ValidationException err) {
	        result = err;
	    } catch (XPathException err) {
	        result = new ValidationException(err);
	    }
	    if (count == 0) {
	        result = new ValidationException("The built-in list type " +
	                StandardNames.getDisplayName(fingerprint) +
	                " does not allow a zero-length list");
	    }
	    return result;
	}

	/**
	 * Get the typed value of a given input string. This method assumes that the input value
	 * is valid according to this SimpleType
	 * @param value the string whose typed value is required
	 * @param resolver
	 * @param nameChecker
	 */

	SequenceIterator getTypedValue(CharSequence value, NamespaceResolver resolver, NameChecker nameChecker) throws ValidationException {
	    SequenceIterator iter = new std::stringTokenIterator(value.tostd::string());
	    ListTypeMappingFunction map = new ListTypeMappingFunction();
	    map.resolver = resolver;
	    map.atomicType = (AtomicType)getItemType();
	    map.nameChecker = nameChecker;
	    return new MappingIterator(iter, map);
	}

	private static class ListTypeMappingFunction implements MappingFunction {

	    NamespaceResolver resolver;
	    AtomicType atomicType;
	    NameChecker nameChecker;

	    /**
	     * The typed value of a list-valued node is obtained by tokenizing the string value and
	     * applying a mapping function to the sequence of tokens.
	     * This method implements the mapping function. It is for internal use only.
	     * For details see {@link MappingFunction}
	    */

	    Object map(Item item) throws XPathException {
	        try {
	            return atomicType.getTypedValue(item.getstd::stringValue(), resolver, nameChecker);
	        } catch (ValidationException err) {
	            return new DynamicError(err);
	        }
	    }
	}

}







/**
 * This class is used to construct Schema objects containing all the built-in types:
 * that is, the types defined in the "xs" and "xdt" namespaces.
 */
class BuiltInSchemaFactory
{
	/**
	* Define the type hierarchy
	*/
	private static HashMap lookup = new HashMap(100);

	private BuiltInSchemaFactory() {
	}

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

	    //SimpleType javaObject =
	    //        makeSimpleType(NamespaceConstant.JAVA_TYPE, "java.lang.Object", anyAtomicType, Type.OBJECT);

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

	private static BuiltInAtomicType makeAtomicType(std::string namespace,
	                                         std::string lname,
	                                         SimpleType baseType) {
	    BuiltInAtomicType t = new BuiltInAtomicType(StandardNames.getFingerprint(namespace, lname));
	    t.setBaseTypeFingerprint(baseType.getFingerprint());
	    lookup.put(new Integer(t.getFingerprint()), t);
	    return t;
	}

	private static BuiltInListType makeListType(std::string namespace,
	                                       std::string lname) {
	    BuiltInListType t = new BuiltInListType(StandardNames.getFingerprint(namespace, lname));
	    lookup.put(new Integer(t.getFingerprint()), t);
	    return t;
	}

	static SchemaType getSchemaType(int fingerprint) {
	    return (SchemaType)lookup.get(new Integer(fingerprint));
	}


}






/**
A complex type as defined in XML Schema: either a user-defined complex 
type, or xs:anyType. In the non-schema-aware version of the Saxon 
product, the only complex type encountered is xs:anyType.
*/

class ComplexType : public SchemaType
{
	/**
	 * Test whether this complex type has been marked as abstract.
	 * @return true if this complex type is abstract.
	**/

	bool isAbstract();

	/**
	 * Test whether this complex type has complex content
	 * @return true if this complex type has a complex content model, false if it has a simple content model
	 */

	bool isComplexContent();

	/**
	 * Test whether this complexType has simple content
	 * @return true if this complex type has a simple content model, false if it has a complex content model
	 */

	bool isSimpleContent();

	/**
	 * Test whether this complex type has "all" content, that is, a content model
	 * using an xs:all compositor
	 */

	bool isAllContent();

	/**
	 * Get the simple content type
	 * @return For a complex type with simple content, returns the simple type of the content.
	 * Otherwise, returns null.
	 */

	SimpleType getSimpleContentType();

	/**
	 * Test whether this complex type is derived by restriction
	 * @return true if this complex type is derived by restriction
	 */

	bool isRestricted();

	/**
	 * Test whether the content model of this complex type is empty
	 * @return true if the content model is defined as empty
	 */

	bool isEmptyContent();

	/**
	 * Test whether the content model of this complex type allows empty content
	 * @return true if empty content is valid
	 */

	bool isEmptiable() throws SchemaException, ValidationException;

	/**
	 * Test whether this complex type allows mixed content
	 * @return true if mixed content is allowed
	 */

	bool isMixedContent();

	/**
	 * Test whether this complex type subsumes another complex type. The algorithm
	 * used is as published by Thompson and Tobin, XML Europe 2003.
	 * @param sub the other type (the type that is derived by restriction, validly or otherwise)
	 * @return null indicating that this type does indeed subsume the other; or a string indicating
	 * why it doesn't.
	 */

	std::string subsumes(ComplexType sub) throws ValidationException;

	/**
	 * Find an element particle within this complex type definition having a given element name
	 * (identified by fingerprint), and return the schema type associated with that element particle.
	 * If there is no such particle, return null. If the fingerprint matches an element wildcard,
	 * return the type of the global element declaration with the given name if one exists, or AnyType
	 * if none exists and lax validation is permitted by the wildcard.
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	SchemaType getElementParticleType(int fingerprint) throws SchemaException, ValidationException;

	/**
	 * Find an element particle within this complex type definition having a given element name
	 * (identified by fingerprint), and return the cardinality associated with that element particle,
	 * that is, the number of times the element can occur within this complex type. The value is one of
	 * {@link StaticProperty#ALLOWS_ZERO_OR_ONE},
	 * {@link StaticProperty#ALLOWS_ONE_OR_MORE},
	 * If there is no such particle, return {@link 
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	int getElementParticleCardinality(int fingerprint) throws SchemaException, ValidationException;

	/**
	 * Find an attribute use within this complex type definition having a given attribute name
	 * (identified by fingerprint), and return the schema type associated with that attribute.
	 * If there is no such attribute use, return null. If the fingerprint matches an attribute wildcard,
	 * return the type of the global attribute declaration with the given name if one exists, or AnySimpleType
	 * if none exists and lax validation is permitted by the wildcard.
	 * <p>
	 * If there are types derived from this type by extension, search those too.
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	SchemaType getAttributeUseType(int fingerprint) throws SchemaException, ValidationException;

}







/**
 * This class represents the type of an external Java object returned by
 * an extension function, or supplied as an external variable/parameter.
 */

class ExternalObjectType : public AtomicType
{
	private Class javaClass;
	private Configuration config;
	int fingerprint;
	int baseFingerprint = -1;

	//static ExternalObjectType GENERAL_EXTERNAL_OBJECT_TYPE = new ExternalObjectType(Object.class, config);


	ExternalObjectType(Class javaClass, Configuration config) {
	    this.javaClass = javaClass;
	    this.config = config;
	    std::string localName = javaClass.getName().replace('$', '_');
	    this.fingerprint = config.getNamePool().allocate("", NamespaceConstant.JAVA_TYPE, localName);
	}

	/**
	 * Return true if this is an external object type, that is, a Saxon-defined type for external
	 * Java or .NET objects
	 */

	bool isExternalType() {
	    return true;
	}

	/**
	 * Get the most specific possible atomic type that all items in this SimpleType belong to
	 * @return the lowest common supertype of all member types
	 */

	AtomicType getCommonAtomicType() {
	    return this;
	}

	/**
	 * Get the validation status - always valid
	 */
	int getValidationStatus()  {
	    return VALIDATED;
	}

	/**
	 * Returns the value of the 'block' attribute for this type, as a bit-signnificant
	 * integer with fields such as {@link SchemaType#DERIVATION_LIST} and {@link SchemaType#DERIVATION_EXTENSION}
	 *
	 * @return the value of the 'block' attribute for this type
	 */

	int getBlock() {
	    return 0;
	}

	/**
	 * Gets the integer code of the derivation method used to derive this type from its
	 * parent. Returns zero for primitive types.
	 *
	 * @return a numeric code representing the derivation method, for example {@link SchemaType#DERIVATION_RESTRICTION}
	 */

	int getDerivationMethod() {
	    return SchemaType.DERIVATION_RESTRICTION;
	}

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 *
	 * @param derivation the kind of derivation, for example {@link SchemaType#DERIVATION_LIST}
	 * @return true if this kind of derivation is allowed
	 */

	bool allowsDerivation(int derivation) {
	    return true;
	}

	/**
	 * Get the namecode of the name of this type. This includes the prefix from the original
	 * type declaration: in the case of built-in types, there may be a conventional prefix
	 * or there may be no prefix.
	 */

	int getNameCode() {
	    return fingerprint;
	}

	/**
	 * Test whether this SchemaType is a complex type
	 *
	 * @return true if this SchemaType is a complex type
	 */

	bool isComplexType() {
	    return false;
	}

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	 */

	SchemaType getBaseType() {
	    return BuiltInSchemaFactory.getSchemaType(StandardNames.XDT_ANY_ATOMIC_TYPE);
	}

	/**
	 * Get the primitive item type corresponding to this item type. For item(),
	 * this is Type.ITEM. For node(), it is Type.NODE. For specific node kinds,
	 * it is the value representing the node kind, for example Type.ELEMENT.
	 * For anyAtomicValue it is Type.ATOMIC_VALUE. For numeric it is Type.NUMBER.
	 * For other atomic types it is the primitive type as defined in XML Schema,
	 * except that INTEGER is considered to be a primitive type.
	 */

	ItemType getPrimitiveItemType() {
	    return this;
	}

	/**
	 * Get the primitive type corresponding to this item type. For item(),
	 * this is Type.ITEM. For node(), it is Type.NODE. For specific node kinds,
	 * it is the value representing the node kind, for example Type.ELEMENT.
	 * For anyAtomicValue it is Type.ATOMIC. For numeric it is Type.NUMBER.
	 * For other atomic types it is the primitive type as defined in XML Schema,
	 * except that INTEGER is considered to be a primitive type.
	 */

	int getPrimitiveType() {
	    return Type.ANY_ATOMIC;
	}

	/**
	 * Produce a representation of this type name for use in error messages.
	 * Where this is a QName, it will use conventional prefixes
	 */

	std::string tostd::string(NamePool pool) {
	    return getDisplayName();
	}

	/**
	 * Get the item type of the atomic values that will be produced when an item
	 * of this type is atomized
	 */

	AtomicType getAtomizedItemType() {
	    return this;
	}

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	 */

	SchemaType getKnownBaseType() {
	    return getBaseType();
	}

	/**
	 * Test whether this is the same type as another type. They are considered to be the same type
	 * if they are derived from the same type definition in the original XML representation (which
	 * can happen when there are multiple includes of the same file)
	 */

	bool isSameType(SchemaType other) {
	    return (other.getFingerprint() == this.getFingerprint());
	}

	/**
	 * Get the relationship of this external object type to another external object type
	 * @return the relationship of this external object type to another external object type,
	 * as one of the constants in class {@link TypeHierarchy}, for example {@link TypeHierarchy#SUBSUMES}
	 */

	int getRelationship(ExternalObjectType other) {
	    Class j2 = other.javaClass;
	    if (javaClass.equals(j2)) {
	        return TypeHierarchy.SAME_TYPE;
	    } else if (javaClass.isAssignableFrom(j2)) {
	        return TypeHierarchy.SUBSUMES;
	    } else if (j2.isAssignableFrom(javaClass)) {
	        return TypeHierarchy.SUBSUMED_BY;
	    } else if (javaClass.isInterface() || j2.isInterface()) {
	        return TypeHierarchy.OVERLAPS; // there may be an overlap, we play safe
	    } else {
	        return TypeHierarchy.DISJOINT;
	    }
	}

	std::string getDescription() {
	    return getDisplayName();
	}

	/**
	 * Check that this type is validly derived from a given type
	 *
	 * @param type  the type from which this type is derived
	 * @param block the derivations that are blocked by the relevant element declaration
	 * @throws SchemaException if the derivation is not allowed
	 */

	void checkTypeDerivationIsOK(SchemaType type, int block) throws SchemaException, ValidationException {
	    return;
	}

	/**
	 * Returns true if this SchemaType is a SimpleType
	 *
	 * @return true (always)
	 */

	bool isSimpleType() {
	    return true;
	}

	/**
	 * Test whether this Simple Type is an atomic type
	 * @return true, this is considered to be an atomic type
	 */

	bool isAtomicType() {
	    return true;
	}


	/**
	 * Returns true if this type is derived by list, or if it is derived by restriction
	 * from a list type, or if it is a union that contains a list as one of its members
	 *
	 * @return true if this is a list type
	 */

	bool isListType() {
	    return false;
	}

	/**
	 * Return true if this type is a union type (that is, if its variety is union)
	 *
	 * @return true for a union type
	 */

	bool isUnionType() {
	    return false;
	}

	/**
	 * Determine the whitespace normalization required for values of this type
	 *
	 * @return one of PRESERVE, REPLACE, COLLAPSE
	 * @param th
	 */

	int getWhitespaceAction(TypeHierarchy th) {
	    return Whitespace.PRESERVE;
	}

	/**
	 * Apply the whitespace normalization rules for this simple type
	 *
	 * @param value the string before whitespace normalization
	 * @return the string after whitespace normalization
	 */

	CharSequence applyWhitespaceNormalization(CharSequence value) throws ValidationException {
	    return value;
	}

	/**
	 * Returns the built-in base type this type is derived from.
	 *
	 * @return the first built-in type found when searching up the type hierarchy
	 */
	SchemaType getBuiltInBaseType() {
	    return this;
	}

	/**
	 * Test whether this simple type is namespace-sensitive, that is, whether
	 * it is derived from xs:QName or xs:NOTATION
	 *
	 * @return true if this type is derived from xs:QName or xs:NOTATION
	 */

	bool isNamespaceSensitive() {
	    return false;
	}

	/**
	 * Test whether this is an anonymous type
	 * @return true if this SchemaType is an anonymous type
	 */

	bool isAnonymousType() {
	    return false;
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type
	 *
	 * @param node the node whose typed value is required
	 * @return an iterator over the items making up the typed value of this node. The objects
	 *         returned by this SequenceIterator will all be of type {@link AtomicValue}
	 */

	SequenceIterator getTypedValue(NodeInfo node) {
	    throw new IllegalStateException("The type annotation of a node cannot be an external object type");
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type. The result of this method will always be consistent with the method
	 * {@link #getTypedValue}. However, this method is often more convenient and may be
	 * more efficient, especially in the common case where the value is expected to be a singleton.
	 *
	 * @param node the node whose typed value is required
	 * @return the typed value.
	 * @since 8.5
	 */

	Value atomize(NodeInfo node) throws XPathException {
	    throw new IllegalStateException("The type annotation of a node cannot be an external object type");
	}

	/**
	 * Get the typed value corresponding to a given string value, assuming it is
	 * valid against this type
	 *
	 * @param value    the string value
	 * @param resolver a namespace resolver used to resolve any namespace prefixes appearing
	 *                 in the content of values. Can supply null, in which case any namespace-sensitive content
	 *                 will be rejected.
	 * @param nameChecker
	 * @return an iterator over the atomic sequence comprising the typed value. The objects
	 *         returned by this SequenceIterator will all be of type {@link AtomicValue}
	 */

	SequenceIterator getTypedValue(CharSequence value, NamespaceResolver resolver, NameChecker nameChecker)
	        throws ValidationException {
	    throw new ValidationException("Cannot validate a string against an external object type");
	}


	/**
	 * Factory method to create values of a derived atomic type. This method
	 * is not used to create values of a built-in type, even one that is not
	 * primitive.
	 *
	 * @param primValue    the value in the value space of the primitive type
	 * @param lexicalValue the value in the lexical space. If null, the string value of primValue
	  * @param validate     true if the value is to be validated against the facets of the derived
	 *                     type; false if the caller knows that the value is already valid.
	 */

	AtomicValue makeDerivedValue(AtomicValue primValue, CharSequence lexicalValue, bool validate) {
	    throw new UnsupportedOperationException("makeDerivedValue is not supported for external object types");
	}

	/**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 *
	 * @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	 *                   {@link Type#ATTRIBUTE}, or {@link Type#DOCUMENT}
	 * @param env
	 * @throws XPathException
	 *          if the expression will never deliver a value of the correct type
	 */

	void analyzeContentExpression(Expression expression, int kind, StaticContext env) throws XPathException {
	    analyzeContentExpression(this, expression, env, kind);
	}

   /**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 * @param simpleType the simple type against which the expression is to be checked
	 * @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	 *                   {@link Type#ATTRIBUTE}, or {@link Type#DOCUMENT}
	 * @throws XPathException
	 *          if the expression will never deliver a value of the correct type
	 */

	static void analyzeContentExpression(SimpleType simpleType, Expression expression, StaticContext env, int kind)
	throws XPathException {
	    if (kind == Type.ELEMENT) {
	        expression.checkPermittedContents(simpleType, env, true);
	    } else if (kind == Type.ATTRIBUTE) {
	        // for attributes, do a check only for text nodes and atomic values: anything else gets atomized
	        if (expression instanceof ValueOf || expression instanceof Value) {
	            expression.checkPermittedContents(simpleType, env, true);
	        }
	    }
	}


	Class getJavaClass() {
	    return javaClass;
	}

	bool isBuiltIn() {
	    return true;
	}

	bool matchesItem(Item item, bool allowURIPromotion, Configuration config) {
	    if (item instanceof ObjectValue) {
	        Object obj = ((ObjectValue)item).getObject();
	        return javaClass.isAssignableFrom(obj.getClass());
	    }
	    return false;
	}

	/**
	 * Check whether a given input string is valid according to this SimpleType
	 * @param value the input string to be checked
	 * @param nsResolver a namespace resolver used to resolve namespace prefixes if the type
	 * is namespace sensitive. The value supplied may be null; in this case any namespace-sensitive
	 * content will throw an UnsupportedOperationException.
	 * @param nameChecker
	 * @return null if validation succeeds; return a ValidationException describing the validation failure
	 * if validation fails, unless throwException is true, in which case the exception is thrown rather than
	 * being returned.
	 * @throws UnsupportedOperationException if the type is namespace-sensitive and no namespace
	 * resolver is supplied
	 */

	ValidationException validateContent(CharSequence value, NamespaceResolver nsResolver, NameChecker nameChecker) {
	    throw new UnsupportedOperationException("Cannot use an external object type for validation");
	}

	ItemType getSuperType(TypeHierarchy th) {
	    if (javaClass == Object.class) {
	        return Type.ANY_ATOMIC_TYPE;
	    }
	    Class javaSuper = javaClass.getSuperclass();
	    if (javaSuper == null) {
	        // this happens for an interface
	        return Type.ANY_ATOMIC_TYPE;
	    }
	    return new ExternalObjectType(javaSuper, config);
	}

	int getFingerprint() {
	    return fingerprint;
	}

	std::string tostd::string() {
	    std::string name = javaClass.getName();
	    name = name.replace('$', '-');
	    return "java:" + name;
	}

	std::string getDisplayName() {
	    return tostd::string();
	}

}








/**
 * ItemType is an interface that allows testing of whether an Item conforms to an
 * expected type. ItemType represents the types in the type hierarchy in the XPath model,
 * as distinct from the schema model: an item type is either item() (matches everything),
 * a node type (matches nodes), an atomic type (matches atomic values), or empty()
 * (matches nothing). Atomic types, represented by the class AtomicType, are also
 * instances of SimpleType in the schema type heirarchy. Node Types, represented by
 * the class NodeTest, are also Patterns as used in XSLT.
 * @see AtomicType
 * @see NodeTest
*/
class ItemType
{
	/**
	 * Determine whether this item type is atomic (that is, whether it can ONLY match
	 * atomic values)
	 * @return true if this is ANY_ATOMIC_TYPE or a subtype thereof
	 */

	bool isAtomicType();

	/**
	 * Test whether a given item conforms to this type
	 * @param item The item to be tested
	 * @param allowURIPromotion
	 * @param config
	 * @return true if the item is an instance of this type; false otherwise
	*/

	bool matchesItem(Item item, bool allowURIPromotion, Configuration config);

	/**
	 * Get the type from which this item type is derived by restriction. This
	 * is the supertype in the XPath type heirarchy, as distinct from the Schema
	 * base type: this means that the supertype of xs:bool is xdt:anyAtomicType,
	 * whose supertype is item() (rather than xs:anySimpleType).
	 * <p>
	 * In fact the concept of "supertype" is not really well-defined, because the types
	 * form a lattice rather than a hierarchy. The only real requirement on this function
	 * is that it returns a type that strictly subsumes this type, ideally as narrowly
	 * as possible.
	 * @return the supertype, or null if this type is item()
	 * @param th
	 */

	ItemType getSuperType(TypeHierarchy th);

	/**
	 * Get the primitive item type corresponding to this item type. For item(),
	 * this is Type.ITEM. For node(), it is Type.NODE. For specific node kinds,
	 * it is the value representing the node kind, for example Type.ELEMENT.
	 * For anyAtomicValue it is Type.ATOMIC_VALUE. For numeric it is Type.NUMBER.
	 * For other atomic types it is the primitive type as defined in XML Schema,
	 * except that INTEGER is considered to be a primitive type.
	 */

	ItemType getPrimitiveItemType();

	/**
	 * Get the primitive type corresponding to this item type. For item(),
	 * this is Type.ITEM. For node(), it is Type.NODE. For specific node kinds,
	 * it is the value representing the node kind, for example Type.ELEMENT.
	 * For anyAtomicValue it is Type.ATOMIC_VALUE. For numeric it is Type.NUMBER.
	 * For other atomic types it is the primitive type as defined in XML Schema,
	 * except that INTEGER is considered to be a primitive type.
	 */

	int getPrimitiveType();

	/**
	 * Produce a representation of this type name for use in error messages.
	 * Where this is a QName, it will use conventional prefixes
	 */

	std::string tostd::string(NamePool pool);

	/**
	 * Get the item type of the atomic values that will be produced when an item
	 * of this type is atomized
	 */

	AtomicType getAtomizedItemType();

}






/**
 * Interface representing a simple type of variety List
 */

class ListType : public SimpleType
{
	/**
	 * Returns the simpleType of the items in this ListType. This method assumes that the
	 * item type has been fully resolved
	 * @return the simpleType of the items in this ListType.
	 * @throws IllegalStateException if the item type has not been fully resolved
	*/

	SimpleType getItemType();
}






/**
This is a marker interface that represents any "schema component" as 
defined in the XML Schema specification. This may be a user-defined 
schema component or a built-in schema component.
*/
class SchemaComponent
{
	/**
	 * Get the validation status of this component.
	 * @return one of the values {@link #UNVALIDATED}, {@link #VALIDATING},
	 * {@link #VALIDATED}, {@link #INVALID}, {@link #INCOMPLETE}
	 */

	int getValidationStatus();

	/**
	 * Validation status: not yet validated
	 */
	static int UNVALIDATED = 0;

	/**
	 * Validation status: fixed up (all references to other components have been resolved)
	 */
	static int FIXED_UP = 1;

	/**
	 * Validation status: currently being validated
	 */
	static int VALIDATING = 2;

	/**
	 * Validation status: successfully validated
	 */
	static int VALIDATED = 3;

	/**
	 * Validation status: validation attempted and failed with fatal errors
	 */
	static int INVALID = 4;

	/**
	 * Validation status: validation attempted, component contains references to
	 * other components that are not (yet) available
	 */
	static int INCOMPLETE = 5;


}






/**
This is a marker interface that acts as a surrogate for an object 
representing a global element or attribute declaration. The real 
implementation of these declarations is available in the schema-aware
version of the Saxon product.
 */
interface SchemaDeclaration {

	/**
	 * Get the simple or complex type associated with the element or attribute declaration
	 * @return the simple or complex type
	 */

	SchemaType getType();

	/**
	 * Create a NodeTest that implements the semantics of schema-element(name) or
	 * schema-attribute(name) applied to this element or attribute declaration.
	 */

	NodeTest makeSchemaNodeTest();

}






/**
 * An exception that identifies an error in reading, parsing, or
 * validating a schema.
 */

class SchemaException
{

	/**
	 * Creates a new XMLException with no message
	 * or nested Exception.
	 */

	SchemaException() {
	    super();
	}

	SchemaException(std::string message, SourceLocator locator) {
	    super(message, locator);
	}

	/**
	 * Creates a new XMLException with the given message.
	 *
	 * @param message the message for this Exception
	 */

	SchemaException(std::string message) {
	    super(message);
	}

	/**
	 * Creates a new XMLException with the given nested
	 * exception.
	 *
	 * @param exception the nested exception
	 */

	SchemaException(Throwable exception) {
	    super(exception);
	}

	/**
	 * Creates a new XMLException with the given message
	 * and nested exception.
	 *
	 * @param message the detail message for this exception
	 * @param exception the nested exception
	 */

	SchemaException(std::string message, Throwable exception) {
	    super(message, exception);
	}

}








/**
SchemaType is an interface implemented by all schema types: simple and 
complex types, built-in and user-defined types.

<p>There is a hierarchy of interfaces that extend SchemaType, 
representing the top levels of the schema type system: SimpleType and 
ComplexType, with SimpleType further subdivided into List, Union, and 
Atomic types.</p>

<p>The implementations of these interfaces are organized into a 
different hierarchy: on the one side, built-in types such as AnyType, 
AnySimpleType, and the built-in atomic types and list types; on the 
other side, user-defined types defined in a schema.</p>
 */

interface SchemaType : public SchemaComponent
{

	// DerivationMethods. These constants are copied from org.w3.dom.TypeInfo. They are redefined here to avoid
	// creating a dependency on the TypeInfo class, which is only available when JAXP 1.3 is available.

	/**
	 *  If the document's schema is an XML Schema [<a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/'>XML Schema Part 1</a>]
	 * , this constant represents the derivation by <a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/#key-typeRestriction'>
	 * restriction</a> if complex types are involved, or a <a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/#element-restriction'>
	 * restriction</a> if simple types are involved.
	 * <br>  The reference type definition is derived by restriction from the
	 * other type definition if the other type definition is the same as the
	 * reference type definition, or if the other type definition can be
	 * reached recursively following the {base type definition} property
	 * from the reference type definition, and all the <em>derivation methods</em> involved are restriction.
	 */
	static int DERIVATION_RESTRICTION    = 0x00000001;

	/**
	 *  If the document's schema is an XML Schema [<a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/'>XML Schema Part 1</a>]
	 * , this constant represents the derivation by <a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/#key-typeExtension'>
	 * extension</a>.
	 * <br>  The reference type definition is derived by extension from the
	 * other type definition if the other type definition can be reached
	 * recursively following the {base type definition} property from the
	 * reference type definition, and at least one of the <em>derivation methods</em> involved is an extension.
	 */
	static int DERIVATION_EXTENSION      = 0x00000002;

	/**
	 *  If the document's schema is an XML Schema [<a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/'>XML Schema Part 1</a>]
	 * , this constant represents the <a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/#element-union'>
	 * union</a> if simple types are involved.
	 * <br> The reference type definition is derived by union from the other
	 * type definition if there exists two type definitions T1 and T2 such
	 * as the reference type definition is derived from T1 by
	 * <code>DERIVATION_RESTRICTION</code> or
	 * <code>DERIVATION_EXTENSION</code>, T2 is derived from the other type
	 * definition by <code>DERIVATION_RESTRICTION</code>, T1 has {variety} <em>union</em>, and one of the {member type definitions} is T2. Note that T1 could be
	 * the same as the reference type definition, and T2 could be the same
	 * as the other type definition.
	 */
	static int DERIVATION_UNION          = 0x00000004;

	/**
	 *  If the document's schema is an XML Schema [<a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/'>XML Schema Part 1</a>]
	 * , this constant represents the <a href='http://www.w3.org/TR/2001/REC-xmlschema-1-20010502/#element-list'>list</a>.
	 * <br> The reference type definition is derived by list from the other
	 * type definition if there exists two type definitions T1 and T2 such
	 * as the reference type definition is derived from T1 by
	 * <code>DERIVATION_RESTRICTION</code> or
	 * <code>DERIVATION_EXTENSION</code>, T2 is derived from the other type
	 * definition by <code>DERIVATION_RESTRICTION</code>, T1 has {variety} <em>list</em>, and T2 is the {item type definition}. Note that T1 could be the same as
	 * the reference type definition, and T2 could be the same as the other
	 * type definition.
	 */
	static int DERIVATION_LIST           = 0x00000008;

	/**
	 * Derivation by substitution.
	 * This constant, unlike the others, is NOT defined in the DOM level 3 TypeInfo interface.
	 */

	static int DERIVE_BY_SUBSTITUTION = 16;

	/**
	 * Get the namecode of the name of this type. This includes the prefix from the original
	 * type declaration: in the case of built-in types, there may be a conventional prefix
	 * or there may be no prefix.
	 */

	int getNameCode();

	/**
	 * Get the fingerprint of the name of this type
	 * @return the fingerprint. Returns an invented fingerprint for an anonymous type.
	 */

	int getFingerprint();

	/**
	 * Get the display name of the type: that is, a lexical QName with an arbitrary prefix
	 * @return a lexical QName identifying the type
	 */

	std::string getDisplayName();

	/**
	 * Test whether this SchemaType is a complex type
	 * @return true if this SchemaType is a complex type
	 */

	bool isComplexType();

	/**
	 * Test whether this SchemaType is a simple type
	 * @return true if this SchemaType is a simple type
	 */

	bool isSimpleType();

	/**
	 * Test whether this SchemaType is an atomic type
	 * @return true if this SchemaType is an atomic type
	 */

	bool isAtomicType();

	/**
	 * Test whether this is an anonymous type
	 * @return true if this SchemaType is an anonymous type
	 */

	bool isAnonymousType();

	/**
	 * Returns the value of the 'block' attribute for this type, as a bit-signnificant
	 * integer with fields such as {@link SchemaType#DERIVATION_LIST} and {@link SchemaType#DERIVATION_EXTENSION}
	 * @return the value of the 'block' attribute for this type
	 */

	int getBlock();

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	*/

	SchemaType getBaseType() throws UnresolvedReferenceException;

	/**
	 * Gets the integer code of the derivation method used to derive this type from its
	 * parent. Returns zero for primitive types.
	 * @return a numeric code representing the derivation method, for example {@link SchemaType#DERIVATION_RESTRICTION}
	 */

	int getDerivationMethod();

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 * @param derivation the kind of derivation, for example {@link SchemaType#DERIVATION_LIST}
	 * @return true if this kind of derivation is allowed
	 */

	bool allowsDerivation(int derivation);

	/**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 * @param expression the expression that delivers the content
	 * @param kind the node kind whose content is being delivered: {@link Type#ELEMENT},
	 * {@link Type#ATTRIBUTE}, or {@link Type#DOCUMENT}
	 * @param env The static evaluation context for the query or stylesheet
	 * @throws XPathException if the expression will never deliver a value of the correct type
	 */

	void analyzeContentExpression(Expression expression, int kind, StaticContext env) throws XPathException;

	/**
	 * Get the typed value of a node that is annotated with this schema type. The results of this method
	 * are consistent with the {@link #atomize} method, but this version returns a SequenceIterator which may
	 * be more efficient when handling long lists.
	 * @param node the node whose typed value is required
	 * @return a SequenceIterator over the atomic values making up the typed value of the specified
	 * node. The objects returned by this iterator are of type {@link AtomicValue}
	 */

	SequenceIterator getTypedValue(NodeInfo node) throws XPathException;

	/**
	 * Get the typed value of a node that is annotated with this schema type. The result of this method will always be consistent with the method
	 * {@link #getTypedValue}. However, this method is often more convenient and may be
	 * more efficient, especially in the common case where the value is expected to be a singleton.
	 * @param node the node whose typed value is required
	 * @return the typed value. 
	 * @since 8.5
	 */

	Value atomize(NodeInfo node) throws XPathException;

	/**
	 * Test whether this is the same type as another type. They are considered to be the same type
	 * if they are derived from the same type definition in the original XML representation (which
	 * can happen when there are multiple includes of the same file)
	 */

	bool isSameType(SchemaType other);

	/**
	 * Get a description of this type for use in error messages. This is the same as the display name
	 * in the case of named types; for anonymous types it identifies the type by its position in a source
	 * schema document.
	 * @return text identifing the type, for use in a phrase such as "the type XXXX".
	 */

	std::string getDescription();

	/**
	 * Check that this type is validly derived from a given type, following the rules for the Schema Component
	 * Constraint "Is Type Derivation OK (Simple)" (3.14.6) or "Is Type Derivation OK (Complex)" (3.4.6) as
	 * appropriate.
	 * @param base the base type; the algorithm tests whether derivation from this type is permitted
	 * @param block the derivations that are blocked by the relevant element declaration
	 * @throws SchemaException if the derivation is not allowed
	 */

	void checkTypeDerivationIsOK(SchemaType base, int block) throws SchemaException, ValidationException;
	// TODO: method no longer used, can delete its implementations once everything is tested

}







/**
 * A SchemaURIResolver is used when resolving references to
 * schema documents. It takes as input the target namespace of the schema to be loaded, and a set of
 * location hints as input, and returns one or more Source obects containing the schema documents
 * to be imported.
* @author Michael H. Kay
*/

interface SchemaURIResolver extends Serializable {

	/**
	 * Resolve a URI identifying a schema document, given the target namespace URI and
	 * a set of associated location hints.
	 * @param targetNamespace the target namespaces of the schema to be imported. The "null namesapce"
	 * is identified by a zero-length string. In the case of an xsd:include directive, where no
	 * target namespace is specified, the parameter is null.
	 * null if no base URI is known
	 * @param locations The set of URIs identified as schema location hints. In most cases (xsd:include, xsd:import,
	 * declaration, however, a list of URIs may be specified.
	 * @return an array of Source objects each identifying a schema document to be loaded.
	 * These need not necessarily correspond one-to-one with the location hints provided.
	 * @throws XPathException if the module cannot be located, and if delegation to the default
	 * module resolver is not required.
	*/

	Source[] resolve(std::string targetNamespace, std::string baseURI, std::string[] locations) throws XPathException;


}







/**
 * This interface represents a simple type, which may be a built-in simple type, or
 * a user-defined simple type.
 */

interface SimpleType extends SchemaType {

	/**
	 * Test whether this Simple Type is an atomic type
	 * @return true if this is an atomic type
	 */

	bool isAtomicType();

	/**
	 * Test whether this Simple Type is a list type
	 * @return true if this is a list type
	 */
	bool isListType();

   /**
	 * Test whether this Simple Type is a union type
	 * @return true if this is a union type
	 */

	bool isUnionType();

	/**
	 * Return true if this is an external object type, that is, a Saxon-defined type for external
	 * Java or .NET objects
	 */

	bool isExternalType();

	/**
	 * Get the most specific possible atomic type that all items in this SimpleType belong to
	 * @return the lowest common supertype of all member types
	 */

	AtomicType getCommonAtomicType();

	/**
	 * Get the built-in type from which this type is derived by restriction
	 * @return the built-in type from which this type is derived by restriction. This will not necessarily
	 * be a primitive type.
	 */

	SchemaType getBuiltInBaseType();

	/**
	 * Get the typed value corresponding to a given string value, assuming it is
	 * valid against this type
	 * @param value the string value
	 * @param resolver a namespace resolver used to resolve any namespace prefixes appearing
	 * in the content of values. Can supply null, in which case any namespace-sensitive content
	 * will be rejected.
	 * @param nameChecker a NameChecker used in the case of types that are defined in terms of the
	 * XML NCName syntax: this is used to check conformance to XML 1.0 or XML 1.1 naming rules, as
	 * appropriate
	 * @return an iterator over the atomic sequence comprising the typed value. The objects
	 * returned by this SequenceIterator will all be of type {@link AtomicValue}
	 * @throws ValidationException if the supplied value is not in the lexical space of the data type
	 */

	SequenceIterator getTypedValue(CharSequence value, NamespaceResolver resolver, NameChecker nameChecker)
	        throws ValidationException;

	/**
	 * Check whether a given input string is valid according to this SimpleType
	 * @param value the input string to be checked
	 * @param nsResolver a namespace resolver used to resolve namespace prefixes if the type
	 * is namespace sensitive. The value supplied may be null; in this case any namespace-sensitive
	 * content will throw an UnsupportedOperationException.
	 * @param nameChecker
	 * @return null if validation succeeds; return a ValidationException describing the validation failure
	 * if validation fails. Note that the exception is returned rather than being thrown.
	 * @throws UnsupportedOperationException if the type is namespace-sensitive and no namespace
	 * resolver is supplied
	 */

	ValidationException validateContent(CharSequence value, NamespaceResolver nsResolver, NameChecker nameChecker);

	/**
	 * Test whether this type is namespace sensitive, that is, if a namespace context is needed
	 * to translate between the lexical space and the value space. This is true for types derived
	 * from, or containing, QNames and NOTATIONs
	 * @return true if the type is namespace-sensitive
	 */

	bool isNamespaceSensitive();

	/**
	 * Determine how values of this simple type are whitespace-normalized.
	 * @return one of {@link Whitespace#COLLAPSE},
	 * {@link 
	 * @param th
	 */

	int getWhitespaceAction(TypeHierarchy th);
}






/**
 * This class contains static information about types and methods
 * for constructing type codes. The class is never instantiated.
 *
 */

abstract class Type
{
	// Note that the integer codes representing node kinds are the same as
	// the codes allocated in the DOM interface, while the codes for built-in
	// atomic types are fingerprints allocated in StandardNames. These two sets of
	// codes must not overlap!

	/**
	 * Type representing an element node - element()
	 */

	static short ELEMENT = 1;
	/**
	 * Item type representing an attribute node - attribute()
	 */
	static short ATTRIBUTE = 2;
	/**
	 * Item type representing a text node - text()
	 */
	static short TEXT = 3;
	/**
	 * Item type representing a text node stored in the tiny tree as compressed whitespace
	 */
	static short WHITESPACE_TEXT = 4;
	/**
	 * Item type representing a processing-instruction node
	 */
	static short PROCESSING_INSTRUCTION = 7;
	/**
	 * Item type representing a comment node
	 */
	static short COMMENT = 8;
	/**
	 * Item type representing a document node
	 */
	static short DOCUMENT = 9;
	/**
	 * Item type representing a namespace node
	 */
	static short NAMESPACE = 13;
	/**
	 * Dummy node kind used in the tiny tree to mark the end of the tree
	 */
	static short STOPPER = 11;
	/**
	 * Dummy node kind used in the tiny tree to contain a parent pointer
	 */
	static short PARENT_POINTER = 12;

	/**
	 * An item type that matches any node
	 */

	static short NODE = 0;

	static ItemType NODE_TYPE = AnyNodeTest.getInstance();

	/**
	 * An item type that matches any item
	 */

	static short ITEM = 88;

	static ItemType ITEM_TYPE = AnyItemType.getInstance();

	static short MAX_NODE_TYPE = 13;
	/**
	 * Item type that matches no items (corresponds to SequenceType empty())
	 */
	static short EMPTY = 15;    // a test for this type will never be satisfied

	private Type() {
	}

	/**
	 * Test whether a given type is (some subtype of) node()
	 *
	 * @param type The type to be tested
	 * @return true if the item type is node() or a subtype of node()
	 */

	static bool isNodeType(ItemType type) {
	    return type instanceof NodeTest;
	}

	/**
	 * Constant denoting any atomic type (the union of all primitive types and types
	 * derived from primitive types by restriction or by union)
	 */

	//static int ATOMIC          = 90;
	static int ANY_ATOMIC      = StandardNames.XDT_ANY_ATOMIC_TYPE;

	/**
	 * Constant denoting any numeric type (the union of float, double, and decimal)
	 */

	//static int NUMBER          = 91;
	static int NUMBER          = StandardNames.XDT_NUMERIC;


	/**
	 * Constants representing primitive data types defined in Schema Part 2
	 */
	static int STRING = StandardNames.XS_STRING;
	/**
	 * Item type representing the type xs:bool
	 */
	static int BOOLEAN = StandardNames.XS_BOOLEAN;
	/**
	 * Item type representing the type xs:decimal
	 */
	static int DECIMAL = StandardNames.XS_DECIMAL;
	/**
	 * Item type representing the type xs:float
	 */
	static int FLOAT = StandardNames.XS_FLOAT;
	/**
	 * Item type representing the type xs:double
	 */
	static int DOUBLE = StandardNames.XS_DOUBLE;
	/**
	 * Item type representing the type xs:duration
	 */
	static int DURATION = StandardNames.XS_DURATION;
	/**
	 * Item type representing the type xs:dateTime
	 */
	static int DATE_TIME = StandardNames.XS_DATE_TIME;
	/**
	 * Item type representing the type xs:time
	 */
	static int TIME = StandardNames.XS_TIME;
	/**
	 * Item type representing the type xs:date
	 */
	static int DATE = StandardNames.XS_DATE;
	/**
	 * Item type representing the type xs:gYearMonth
	 */
	static int G_YEAR_MONTH = StandardNames.XS_G_YEAR_MONTH;
	/**
	 * Item type representing the type xs:gYear
	 */
	static int G_YEAR = StandardNames.XS_G_YEAR;
	/**
	 * Item type representing the type xs:monthDay
	 */
	static int G_MONTH_DAY = StandardNames.XS_G_MONTH_DAY;
	/**
	 * Item type representing the type xs:gDay
	 */
	static int G_DAY = StandardNames.XS_G_DAY;
	/**
	 * Item type representing the type xs:gMonth
	 */
	static int G_MONTH = StandardNames.XS_G_MONTH;
	/**
	 * Item type representing the type xs:hexBinary
	 */
	static int HEX_BINARY = StandardNames.XS_HEX_BINARY;
	/**
	 * Item type representing the type xs:base64Binary
	 */
	static int BASE64_BINARY   = StandardNames.XS_BASE64_BINARY;
	/**
	 * Item type representing the type xs:anyURI
	 */
	static int ANY_URI = StandardNames.XS_ANY_URI;
	/**
	 * Item type representing the type xs:QName
	 */
	static int QNAME = StandardNames.XS_QNAME;
	/**
	 * Item type representing the type xs:NOTATION
	 *
	 */
	static int NOTATION = StandardNames.XS_NOTATION;


	/**
	 * Item type representing the type xdt:untypedAtomic
	 * (the type of the content of a schema-less node)
	 */

	static int UNTYPED_ATOMIC = StandardNames.XDT_UNTYPED_ATOMIC;

	static int ANY_SIMPLE_TYPE = StandardNames.XS_ANY_SIMPLE_TYPE;

	/**
	 * Constant representing the type of an external object (for use by extension functions)
	 */

	static int OBJECT = StandardNames.SAXON_JAVA_LANG_OBJECT;

	/**
	 * Item type representing the type xs:integer
	 */

	static int INTEGER = StandardNames.XS_INTEGER;
	/**
	 * Item type representing the type xs:nonPositiveInteger
	 */
	static int NON_POSITIVE_INTEGER = StandardNames.XS_NON_POSITIVE_INTEGER;
	/**
	 * Item type representing the type xs:negativeInteger
	 */
	static int NEGATIVE_INTEGER = StandardNames.XS_NEGATIVE_INTEGER;
	/**
	 * Item type representing the type xs:long
	 */
	static int LONG = StandardNames.XS_LONG;
	/**
	 * Item type representing the type xs:int
	 */
	static int INT = StandardNames.XS_INT;
	/**
	 * Item type representing the type xs:short
	 */
	static int SHORT = StandardNames.XS_SHORT;
	/**
	 * Item type representing the type xs:byte
	 */
	static int BYTE = StandardNames.XS_BYTE;
	/**
	 * Item type representing the type xs:nonNegativeInteger
	 */
	static int NON_NEGATIVE_INTEGER = StandardNames.XS_NON_NEGATIVE_INTEGER;
	/**
	 * Item type representing the type xs:positiveInteger
	 */
	static int POSITIVE_INTEGER = StandardNames.XS_POSITIVE_INTEGER;
	/**
	 * Item type representing the type xs:unsignedLong
	 */
	static int UNSIGNED_LONG = StandardNames.XS_UNSIGNED_LONG;
	/**
	 * Item type representing the type xs:unsignedInt
	 */
	static int UNSIGNED_INT = StandardNames.XS_UNSIGNED_INT;
	/**
	 * Item type representing the type xs:unsignedShort
	 */
	static int UNSIGNED_SHORT = StandardNames.XS_UNSIGNED_SHORT;
	/**
	 * Item type representing the type xs:unsignedByte
	 */
	static int UNSIGNED_BYTE = StandardNames.XS_UNSIGNED_BYTE;


	/**
	 * Item type representing the type xs:normalizedstd::string
	 */
	static int NORMALIZED_STRING = StandardNames.XS_NORMALIZED_STRING;
	/**
	 * Item type representing the type xs:token
	 */
	static int TOKEN = StandardNames.XS_TOKEN;
	/**
	 * Item type representing the type xs:language
	 */
	static int LANGUAGE = StandardNames.XS_LANGUAGE;
	/**
	 * Item type representing the type xs:NMTOKEN
	 */
	static int NMTOKEN = StandardNames.XS_NMTOKEN;
	/**
	 * Content type representing the complex type xs:NMTOKENS
	 */
	static int NMTOKENS = StandardNames.XS_NMTOKENS;      // NB: list type
	/**
	 * Item type representing the type xs:NAME
	 */
	static int NAME = StandardNames.XS_NAME;
	/**
	 * Item type representing the type xs:NCNAME
	 */
	static int NCNAME = StandardNames.XS_NCNAME;
	/**
	 * Item type representing the type xs:ID
	 */
	static int ID = StandardNames.XS_ID;
	/**
	 * Item type representing the type xs:IDREF
	 */
	static int IDREF = StandardNames.XS_IDREF;
	/**
	 * Content type representing the complex type xs:IDREFS
	 */
	static int IDREFS = StandardNames.XS_IDREFS;      // NB: list type
	/**
	 *
	 * Item type representing the type xs:ENTITY
	 */
	static int ENTITY = StandardNames.XS_ENTITY;


	/**
	 *
	 * Item type representing the type xdt:yearMonthDuration
	 */
	static int YEAR_MONTH_DURATION = StandardNames.XDT_YEAR_MONTH_DURATION;

	/**
	 *
	 * Item type representing the type xdt:dayTimeDuration
	 */
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

	static ItemType getItemType(Item item, TypeHierarchy th) {
	    if (item instanceof AtomicValue) {
	        return ((AtomicValue)item).getItemType(th);
	    } else {
	        return NodeKindTest.makeNodeKindTest(((NodeInfo)item).getNodeKind());
	        // We could return a more precise type than this, for example one that includes
	        // a ContentTypeTest for the type annotation of the nodes. However, given the way in which
	        // this method is used, this wouldn't be very useful
	    }
	}


	/**
	 * Output (for diagnostics) a representation of the type of an item. This
	 * does not have to be the most specific type
	 */

	static std::string displayTypeName(Item item) {
	    if (item instanceof NodeInfo) {
	        NodeInfo node = (NodeInfo)item;
	        switch (node.getNodeKind()) {
	            case DOCUMENT:
	                return "document-node()";
	            case ELEMENT:
	                NamePool pool = node.getNamePool();
	                int annotation = node.getTypeAnnotation();
	                return "element(" +
	                        ((NodeInfo)item).getDisplayName() + ", " +
	                        (annotation == -1 ?
	                            "xdt:untyped)" :
	                            pool.getDisplayName(annotation) + ')');
	            case ATTRIBUTE:
	                NamePool pool2 = node.getNamePool();
	                int annotation2 = node.getTypeAnnotation() & NamePool.FP_MASK;
	                return "attribute(" +
	                        ((NodeInfo)item).getDisplayName()+ ", " +
	                        (annotation2 == -1 ?
	                            "xdt:untypedAtomic)" :
	                            pool2.getDisplayName(annotation2) + ')');
	            case TEXT:      return "text()";
	            case COMMENT:   return "comment()";
	            case PROCESSING_INSTRUCTION:
	                            return "processing-instruction()";
	            case NAMESPACE: return "namespace()";
	            default:        return "";
	        }
	    } else {
	        return ((AtomicValue)item).getItemType(null).tostd::string();
	    }
	}

	/**
	 * Get the SimpleType object for a built-in simple type code
	 * @return the SimpleType, or null if not found
	 */

	static ItemType getBuiltInItemType(std::string namespace, std::string localName) {
	    SchemaType t = BuiltInSchemaFactory.getSchemaType(
	            StandardNames.getFingerprint(namespace, localName));
	    if (t instanceof ItemType) {
	        return (ItemType)t;
	    } else {
	        return null;
	    }
	}

	/**
	 * Get the relationship of two schema types to each other
	 */

	static int schemaTypeRelationship(SchemaType s1, SchemaType s2) {
	    if (s1.isSameType(s2)) {
	        return TypeHierarchy.SAME_TYPE;
	    }
	    if (s1 instanceof AnyType) {
	        return TypeHierarchy.SUBSUMES;
	    }
	    if (s2 instanceof AnyType) {
	        return TypeHierarchy.SUBSUMED_BY;
	    }
	    SchemaType t1 = s1;
	    while (true) {
	        t1 = t1.getBaseType();
	        if (t1 == null) {
	            break;
	        }
	        if (t1.isSameType(s2)) {
	            return TypeHierarchy.SUBSUMED_BY;
	        }
	    }
	    SchemaType t2 = s2;
	    while (true) {
	        t2 = t2.getBaseType();
	        if (t2 == null) {
	            break;
	        }
	        if (t2.isSameType(s1)) {
	            return TypeHierarchy.SUBSUMES;
	        }
	    }
	    return TypeHierarchy.DISJOINT;
	}

	/**
	 * Get a type that is a common supertype of two given types
	 *
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @param th
	 * @return the item type that is a supertype of both
	 *     the supplied item types
	 */

	static ItemType getCommonSuperType(ItemType t1, ItemType t2, TypeHierarchy th) {
	    if (t1 instanceof NoNodeTest) {
	        return t2;
	    }
	    if (t2 instanceof NoNodeTest) {
	        return t1;
	    }
	    int r = th.relationship(t1, t2);
	    if (r == TypeHierarchy.SAME_TYPE) {
	        return t1;
	    } else if (r == TypeHierarchy.SUBSUMED_BY) {
	        return t2;
	    } else if (r == TypeHierarchy.SUBSUMES) {
	        return t1;
	    } else {
	        return getCommonSuperType(t2.getSuperType(th), t1, th);
	        // eventually we will hit a type that is a supertype of t2. We reverse
	        // the arguments so we go up each branch of the tree alternately.
	        // If we hit the root of the tree, one of the earlier conditions will be satisfied,
	        // so the recursion will stop.
	    }
	}


	/**
	 * Determine whether this type is a primitive type. The primitive types are
	 * the 19 primitive types of XML Schema, plus xs:integer, xdt:dayTimeDuration and xdt:yearMonthDuration;
	 * xdt:untypedAtomic; the 7 node kinds; and all supertypes of these (item(), node(), xdt:anyAtomicType,
	 * xdt:number, ...)
	 * @param code the item type code to be tested
	 * @return true if the type is considered primitive under the above rules
	 */
	static bool isPrimitiveType(int code) {
	    return code >= 0 && (code <= INTEGER || code == StandardNames.XDT_NUMERIC ||
	            code == UNTYPED_ATOMIC || code == ANY_ATOMIC ||
	            code == DAY_TIME_DURATION || code == YEAR_MONTH_DURATION ||
	            code == StandardNames.XS_ANY_SIMPLE_TYPE);
	}


	/**
	 * Determine whether two primitive atomic types are comparable
	 * @param t1 the first type to compared.
	 * This must be a primitive atomic type as defined by {@link ItemType#getPrimitiveType}
	 * @param t2 the second type to compared.
	 * This must be a primitive atomic type as defined by {@link ItemType#getPrimitiveType}
	 * @param ordered true if testing for an ordering comparison (lt, gt, le, ge). False
	 * if testing for an equality comparison (eq, ne)
	 * @return true if the types are comparable, as defined by the rules of the "eq" operator
	 */
	static bool isComparable(int t1, int t2, bool ordered) {
	    if (t1 == ANY_ATOMIC || t2 == ANY_ATOMIC) return true; // meaning we don't actually know at this stage
	    if (t1 == UNTYPED_ATOMIC) t1 = STRING;
	    if (t2 == UNTYPED_ATOMIC) t2 = STRING;
	    if (t1 == ANY_URI) t1 = STRING;
	    if (t2 == ANY_URI) t2 = STRING;
	    if (t1 == INTEGER || t1 == DOUBLE || t1 == FLOAT || t1 == DECIMAL) t1 = NUMBER;
	    if (t2 == INTEGER || t2 == DOUBLE || t2 == FLOAT || t2 == DECIMAL) t2 = NUMBER;
	    if (!ordered) {
	        if (t1 == DAY_TIME_DURATION) t1 = DURATION;
	        if (t2 == DAY_TIME_DURATION) t2 = DURATION;
	        if (t1 == YEAR_MONTH_DURATION) t1 = DURATION;
	        if (t2 == YEAR_MONTH_DURATION) t2 = DURATION;
	    }
	    return t1 == t2;
	}

	/**
	 * Determine whether a primitive type is ordered. Note that the rules for this differ
	 * between XPath and XML Schema: these are the XPath rules.
	 * @param type the primitive item type being tested
	 * @return true if the types are potentially comparable. For abstract types (type=ATOMIC)
	 * we give the benefit of the doubt and return true.
	 */

	static bool isOrdered(int type) {
	    switch (type) {
	        case ANY_ATOMIC:
	        case INTEGER:
	        case DOUBLE:
	        case FLOAT:
	        case DECIMAL:
	        case NUMBER:
	        case BOOLEAN:
	        case STRING:
	        case DATE_TIME:
	        case DATE:
	        case TIME:
	        case DAY_TIME_DURATION:
	        case YEAR_MONTH_DURATION:
	        case ANY_URI:       // TODO: check outcome of W3C bug 3433 
	            return true;
	        default:
	            return false;
	    }
	}

	/**
	 * Test whether the supplied type, which must be a primitive type, is one of
	 * the numeric primitive types
	 * @param t the type being tested
	 * @return true if the type is integer, double, float, decimal, or the abstract type "numeric"
	 */
	static bool isNumericPrimitiveType(ItemType t) {
	    if (t.isAtomicType()) {
	        int fp = ((AtomicType)t).getFingerprint();
	        return fp==INTEGER || fp==DOUBLE || fp==FLOAT || fp==DECIMAL || fp==NUMBER;
	    } else {
	        return false;
	    }
	}

	/**
	 * Test whether the supplied type, which must be a primitive type, is one of
	 * the numeric primitive types
	 * @param fp the fingerprint of the type being tested
	 * @return true if the type is integer, double, float, decimal, or the abstract type "numeric"
	 */
	static bool isNumericPrimitiveType(int fp) {
	    return fp==INTEGER || fp==DOUBLE || fp==FLOAT || fp==DECIMAL || fp==NUMBER;
	}

}






/**
 * This class exists to provide answers to questions about the type hierarchy. Because
 * such questions are potentially expensive, it caches the answers.
 */

class TypeHierarchy
{
private:
	Map map;
	Configuration config;

public:
	/**
	 * Constant denoting relationship between two types: A is the same type as B
	 */
	static int SAME_TYPE = 0;
	/**
	 * Constant denoting relationship between two types: A subsumes B
	 */
	static int SUBSUMES = 1;
	/**
	 * Constant denoting relationship between two types: A is subsumed by B
	 */
	static int SUBSUMED_BY = 2;
	/**
	 * Constant denoting relationship between two types: A overlaps B
	 */
	static int OVERLAPS = 3;
	/**
	 * Constant denoting relationship between two types: A is disjoint from B
	 */
	static int DISJOINT = 4;

	//private std::string[] relnames = {"SAME", "SUBSUMES", "SUBSUMED_BY", "OVERLAPS", "DISJOINT"};

	TypeHierarchy(Configuration config){
	    this.config = config;
	    try {
	        // J2SE 5.0 path
	        Class concurrentHashMapClass = config.getClass("java.util.concurrent.ConcurrentHashMap", false, null);
	        map = (Map)concurrentHashMapClass.newInstance();
	    } catch (Exception e) {
	        // JDK 1.4 path
	        map =  Collections.synchronizedMap(new HashMap(100));
	    }
	}

	Configuration getConfiguration() {
	    return config;
	}

	/**
	 * Determine whether type A is type B or one of its subtypes, recursively
	 *
	 * @param subtype identifies the first type
	 * @param supertype identifies the second type
	 * @return true if the first type is the second type or a (direct or
	 *     indirect) subtype of the second type
	 */

	bool isSubType(ItemType subtype, ItemType supertype) {
	    int relation = relationship(subtype, supertype);
	    return (relation==SAME_TYPE || relation==SUBSUMED_BY);
	}

	/**
	 * Determine the relationship of one item type to another.
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @return {@link #SAME_TYPE} if the types are the same; {@link #SUBSUMES} if the first
	 * type subsumes the second (that is, all instances of the second type are also instances
	 * of the first); {@link #SUBSUMED_BY} if the second type subsumes the first;
	 * {@link #OVERLAPS} if the two types overlap (have a non-empty intersection, but neither
	 * subsumes the other); {@link #DISJOINT} if the two types are disjoint (have an empty intersection)
	 */

	int relationship(ItemType t1, ItemType t2) {
	    if (t1 == null) {
	        throw new NullPointerException();
	    }
	    if (t1.equals(t2)) {
	        return SAME_TYPE;
	    }
	    ItemTypePair pair = new ItemTypePair(t1, t2);
	    Integer result = (Integer)map.get(pair);
	    if (result == null) {
	        int r = computeRelationship(t1, t2);
	        result = new Integer(r);
	        map.put(pair, result);
	    }
	    return result.intValue();
	}

	/**
	 * Determine the relationship of one item type to another.
	 * @param t1 the first item type
	 * @param t2 the second item type
	 * @return {@link #SAME_TYPE} if the types are the same; {@link #SUBSUMES} if the first
	 * type subsumes the second (that is, all instances of the second type are also instances
	 * of the first); {@link #SUBSUMED_BY} if the second type subsumes the first;
	 * {@link #OVERLAPS} if the two types overlap (have a non-empty intersection, but neither
	 * subsumes the other); {@link #DISJOINT} if the two types are disjoint (have an empty intersection)
	 */

	private int computeRelationship(ItemType t1, ItemType t2) {
	    //System.err.println("computeRelationship " + t1 + ", " + t2);
	    if (t1 == t2) {
	        return SAME_TYPE;
	    }
	    if (t1 instanceof AnyItemType) {
	        if (t2 instanceof AnyItemType) {
	            return SAME_TYPE;
	        } else {
	            return SUBSUMES;
	        }
	    } else if (t2 instanceof AnyItemType) {
	        return SUBSUMED_BY;
	    } else if (t1.isAtomicType()) {
	        if (t2 instanceof NodeTest) {
	            return DISJOINT;
	        } else if (t1 instanceof ExternalObjectType) {
	            if (t2 instanceof ExternalObjectType) {
	                return ((ExternalObjectType)t1).getRelationship((ExternalObjectType)t2);
	            } else if (((AtomicType)t2).getFingerprint() == StandardNames.XDT_ANY_ATOMIC_TYPE) {
	                return SUBSUMED_BY;
	            } else {
	                return DISJOINT;
	            }
	        } else if (t2 instanceof ExternalObjectType) {
	            if (((AtomicType)t1).getFingerprint() == StandardNames.XDT_ANY_ATOMIC_TYPE) {
	                return SUBSUMES;
	            } else {
	                return DISJOINT;
	            }
	        } else {
	            if (((AtomicType)t1).getFingerprint() == ((AtomicType)t2).getFingerprint()) {
	                return SAME_TYPE;
	            }
	            ItemType t = t2;
	            while (t.isAtomicType()) {
	                if (((AtomicType)t1).getFingerprint() == ((AtomicType)t).getFingerprint()) {
	                    return SUBSUMES;
	                }
	                t = t.getSuperType(this);
	            }
	            t = t1;
	            while (t.isAtomicType()) {
	                if (((AtomicType)t).getFingerprint() == ((AtomicType)t2).getFingerprint()) {
	                    return SUBSUMED_BY;
	                }
	                t = t.getSuperType(this);
	            }
	            return DISJOINT;
	        }
	    } else {
	        // t1 is a NodeTest
	        if (t2.isAtomicType()) {
	            return DISJOINT;
	        } else {
	            // both types are NodeTests
	            if (t1 instanceof AnyNodeTest) {
	                if (t2 instanceof AnyNodeTest) {
	                    return SAME_TYPE;
	                } else {
	                    return SUBSUMES;
	                }
	            } else if (t2 instanceof AnyNodeTest) {
	                return SUBSUMED_BY;
	            } else if (t1 instanceof NoNodeTest) {
	                return DISJOINT;
	            } else if (t2 instanceof NoNodeTest) {
	                return DISJOINT;
	            } else {
	                // first find the relationship between the node kinds allowed
	                int nodeKindRelationship;
	                int m1 = ((NodeTest)t1).getNodeKindMask();
	                int m2 = ((NodeTest)t2).getNodeKindMask();
	                if ((m1 & m2) == 0) {
	                    return DISJOINT;
	                } else if (m1 == m2) {
	                    nodeKindRelationship = SAME_TYPE;
	                } else if ((m1 & m2) == m1) {
	                    nodeKindRelationship = SUBSUMED_BY;
	                } else if ((m1 & m2) == m2) {
	                    nodeKindRelationship = SUBSUMES;
	                } else {
	                    nodeKindRelationship = OVERLAPS;
	                }

	                // now find the relationship between the node names allowed. Note that although
	                // NamespaceTest and LocalNameTest are NodeTests, they do not occur in SequenceTypes,
	                // so we don't need to consider them.
	                int nodeNameRelationship;
	                IntHashSet n1 = ((NodeTest)t1).getRequiredNodeNames(); // null means all names allowed
	                IntHashSet n2 = ((NodeTest)t2).getRequiredNodeNames(); // null means all names allowed
	                if (n1 == null) {
	                    if (n2 == null) {
	                        nodeNameRelationship = SAME_TYPE;
	                    } else {
	                        nodeNameRelationship = SUBSUMES;
	                    }
	                } else if (n2 == null) {
	                    nodeNameRelationship = SUBSUMED_BY;
	                } else if (n1.containsAll(n2)) {
	                    if (n1.size() == n2.size()) {
	                        nodeNameRelationship = SAME_TYPE;
	                    } else {
	                        nodeNameRelationship = SUBSUMES;
	                    }
	                } else if (n2.containsAll(n1)) {
	                    nodeNameRelationship = SUBSUMED_BY;
	                } else if (n1.containsSome(n2)) {
	                    nodeNameRelationship = OVERLAPS;
	                } else {
	                    nodeNameRelationship = DISJOINT;
	                }

	                // now find the relationship between the content types allowed

	                int contentRelationship;

	                if (t1 instanceof DocumentNodeTest) {
	                    if (t2 instanceof DocumentNodeTest) {
	                        contentRelationship = relationship(((DocumentNodeTest)t1).getElementTest(),
	                            ((DocumentNodeTest)t2).getElementTest());
	                    } else {
	                        contentRelationship = SUBSUMED_BY;
	                    }
	                } else if (t2 instanceof DocumentNodeTest) {
	                    contentRelationship = SUBSUMES;
	                } else {
	                    SchemaType s1 = ((NodeTest)t1).getContentType();
	                    SchemaType s2 = ((NodeTest)t2).getContentType();
	                    contentRelationship = Type.schemaTypeRelationship(s1, s2);
	                }

	                // now analyse the three different relationsships

	                if (nodeKindRelationship == SAME_TYPE &&
	                        nodeNameRelationship == SAME_TYPE &&
	                        contentRelationship == SAME_TYPE) {
	                    return SAME_TYPE;
	                } else if ((nodeKindRelationship == SAME_TYPE || nodeKindRelationship == SUBSUMES) &&
	                        (nodeNameRelationship == SAME_TYPE || nodeNameRelationship == SUBSUMES) &&
	                        (contentRelationship == SAME_TYPE || contentRelationship == SUBSUMES)) {
	                    return SUBSUMES;
	                } else if ((nodeKindRelationship == SAME_TYPE || nodeKindRelationship == SUBSUMED_BY) &&
	                        (nodeNameRelationship == SAME_TYPE || nodeNameRelationship == SUBSUMED_BY) &&
	                        (contentRelationship == SAME_TYPE || contentRelationship == SUBSUMED_BY)) {
	                    return SUBSUMED_BY;
	                } else if (nodeKindRelationship == DISJOINT ||
	                        nodeNameRelationship == DISJOINT ||
	                        contentRelationship == DISJOINT) {
	                    return DISJOINT;
	                } else {
	                    return OVERLAPS;
	                }
	            }
	        }
	    }

	}

	/**
	  * Test whether a type annotation code represents the type xs:ID or one of its subtypes
	  */

	 bool isIdCode(int typeCode) {
	     typeCode &= NamePool.FP_MASK;
	     if (typeCode == StandardNames.XS_ID) {
	         return true;
	     } else if (typeCode < 1024) {
	         // No other built-in type is an ID
	         return false;
	     } else {
	         SchemaType type = config.getSchemaType(typeCode);
	         if (type == null) {
	             return false;      // this shouldn't happen, but there's no need to crash right here
	         }
	         if (type.isAtomicType()) {
	             return isSubType((AtomicType)type, Type.ID_TYPE);
	         }
	         if (type instanceof ComplexType && ((ComplexType)type).isSimpleContent()) {
	             SimpleType contentType = ((ComplexType)type).getSimpleContentType();
	             if (contentType.isAtomicType()) {
	                return isSubType((AtomicType)contentType, Type.ID_TYPE);
	             }
	         }
	         return false;
	     }
	 }

	/**
	  * Test whether a type annotation code represents the type xs:IDREF, xs:IDREFS or one of their subtypes
	  */

	 bool isIdrefsCode(int typeCode) {
	     typeCode &= NamePool.FP_MASK;
	     if (typeCode == StandardNames.XS_IDREF || typeCode == StandardNames.XS_IDREFS) {
	         return true;
	     } else if (typeCode < 1024) {
	         // No other built-in type is an IDREF or IDREFS
	         return false;
	     } else {
	         SchemaType type = config.getSchemaType(typeCode);
	         if (type == null) {
	             // shouldn't happen, but we don't need to crash right now
	             return false;
	         }
	         if (type.isAtomicType()) {
	             return isSubType((AtomicType)type, Type.IDREF_TYPE);
	         }
	         if (type instanceof ListType) {
	             return ((ListType)type).getBuiltInBaseType().getFingerprint() == StandardNames.XS_IDREFS;
	         }
	         if (type.isComplexType() && ((ComplexType)type).isSimpleContent()) {
	             SimpleType contentType = ((ComplexType)type).getSimpleContentType();
	             if (contentType.isAtomicType()) {
	                 return isSubType((AtomicType)contentType, Type.IDREF_TYPE);
	             } else if (contentType instanceof ListType) {
	                 return contentType.getBuiltInBaseType().getFingerprint() == StandardNames.XS_IDREFS;
	             }
	         }
	         return false;
	     }
	 }


	private class ItemTypePair implements Serializable {
	    ItemType s;
	    ItemType t;

	    ItemTypePair(ItemType s, ItemType t) {
	        this.s = s;
	        this.t = t;
	    }

	    /**
	     * Returns a hash code value for the object.
	     * @return a hash code value for this object.
	     * @see Object#equals(Object)
	     * @see java.util.Hashtable
	     */
	    int hashCode() {
	        return s.hashCode() ^ t.hashCode();
	    }

	    /**
	     * Indicates whether some other object is "equal to" this one.
	     */

	    bool equals(Object obj) {
	        ItemTypePair pair = (ItemTypePair)obj;
	        return s.equals(pair.s) && t.equals(pair.t);
	    }
	}





//    static void main(std::string[] args) throws Exception {
//        int runs = 10000000;
//        Configuration config = new Configuration();
//        NamePool pool = config.getNamePool();
//        StaticQueryContext sqc = new StaticQueryContext(config);
//        NodeInfo doc = sqc.buildDocument(new StreamSource(new File("c:/MyJava/samples/data/books.xml")));
//        XQueryExpression exp = sqc.compileQuery(
//                "declare variable $x external; count($x//*)");
//        for (int i=1; i < runs; i++) {
//            Configuration config2 = new Configuration();
//            config2.setNamePool(pool);
//            DynamicQueryContext dynamicContext = new DynamicQueryContext(config2);
//            dynamicContext.setParameter("x", doc);
//            Properties props = new Properties();
//            exp.run(dynamicContext, new Sink(), props);
//            if (i % 1000 == 0) {
//                System.out.print(".");
//            }
//            if (i % 10000 == 0) {
//                Runtime.getRuntime().gc();
//                System.out.println("i=" + i + " free memory = " + Runtime.getRuntime().freeMemory());
//            }
//        }
//    }

}

//
// The contents of this file are subject to the Mozilla Public License Version 1.0 (the "License");
// you may not use this file except in compliance with the License. You may obtain a copy of the
// License at http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied.
// See the License for the specific language governing rights and limitations under the License.
//
// The Original Code is: all this file.
//
// The Initial Developer of the Original Code is Michael H. Kay.
//
// Portions created by (your name) are Copyright (C) (your legal entity). All Rights Reserved.
//
// Contributor(s): none.
//

/**
 * This exception occurs when an attempt is made to dereference a reference from one
 * schema component to another, if the target of the reference cannot be found. Note that
 * an unresolved reference is not necessarily an error: a schema containing unresolved
 * references may be used for validation, provided the components containing the
 * unresolved references are not actually used.
 */

abstract class UnresolvedReferenceException extends RuntimeException {

	UnresolvedReferenceException(std::string ref) {
	    super(ref);
	}
}





/**
 * This class has a singleton instance which represents the complex type xdt:untyped,
 * used for elements that have not been validated.
 */

class Untyped :public ComplexType
{
private:
	static Untyped theInstance = new Untyped();

	Untyped() {}

public:
	/**
	 * Get the validation status - always valid
	 */
	int getValidationStatus()  {
	    return VALIDATED;
	}

	/**
	 * Returns the value of the 'block' attribute for this type, as a bit-signnificant
	 * integer with fields such as {@link SchemaType#DERIVATION_LIST} and {@link SchemaType#DERIVATION_EXTENSION}
	 *
	 * @return the value of the 'block' attribute for this type
	 */

	int getBlock() {
	    return 0;
	}

	/**
	 * Gets the integer code of the derivation method used to derive this type from its
	 * parent. Returns zero for primitive types.
	 *
	 * @return a numeric code representing the derivation method, for example {@link SchemaType#DERIVATION_RESTRICTION}
	 */

	int getDerivationMethod() {
	    return 0;
	}

	/**
	 * Determines whether derivation (of a particular kind)
	 * from this type is allowed, based on the "final" property
	 *
	 * @param derivation the kind of derivation, for example {@link SchemaType#DERIVATION_LIST}
	 * @return true if this kind of derivation is allowed
	 */

	bool allowsDerivation(int derivation) {
	    return false;
	}

	/**
	 * Check that this type is validly derived from a given type
	 *
	 * @param type  the type from which this type is derived
	 * @param block the derivations that are blocked by the relevant element declaration
	 */

	void checkTypeDerivationIsOK(SchemaType type, int block)  {

	}

	/**
	 * Get the fingerprint of the name of this type
	 *
	 * @return the fingerprint. Returns an invented fingerprint for an anonymous type.
	 */

	int getFingerprint() {
	    return StandardNames.XDT_UNTYPED;
	}

	/**
	 * Get the namecode of the name of this type. This includes the prefix from the original
	 * type declaration: in the case of built-in types, there may be a conventional prefix
	 * or there may be no prefix.
	 */

	int getNameCode() {
	    return StandardNames.XDT_UNTYPED;
	}

	/**
	 * Get the display name of the type: that is, a lexical QName with an arbitrary prefix
	 *
	 * @return a lexical QName identifying the type
	 */

	std::string getDisplayName() {
	    return "xdt:untyped";
	}

	/**
	 * Test whether this SchemaType is a complex type
	 *
	 * @return true if this SchemaType is a complex type
	 */

	bool isComplexType() {
	    return true;
	}

	/**
	 * Test whether this is an anonymous type
	 *
	 * @return true if this SchemaType is an anonymous type
	 */

	bool isAnonymousType() {
	    return false;
	}

	/**
	 * Returns the base type that this type inherits from. This method can be used to get the
	 * base type of a type that is known to be valid.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 * @throws IllegalStateException if this type is not valid.
	 */

	SchemaType getKnownBaseType() throws IllegalStateException {
	    return AnyType.getInstance();
	}

	/**
	 * Test whether this is the same type as another type. They are considered to be the same type
	 * if they are derived from the same type definition in the original XML representation (which
	 * can happen when there are multiple includes of the same file)
	 */

	bool isSameType(SchemaType other) {
	    return (other instanceof Untyped);
	}

	/**
	 * Returns the base type that this type inherits from.
	 * If this type is a Simpletype that is a built in primitive type then null is returned.
	 *
	 * @return the base type.
	 */

	SchemaType getBaseType() {
	    return AnyType.getInstance();
	}


	/**
	 * Get the singular instance of this class
	 * @return the singular object representing xs:anyType
	 */

	static Untyped getInstance() {
	    return theInstance;
	}

	/**
	 * Test whether this ComplexType has been marked as abstract.
	 * @return false: this class is not abstract.
	 */

	bool isAbstract() {
	    return false;
	}

	/**
	 * Test whether this SchemaType is a simple type
	 * @return true if this SchemaType is a simple type
	 */

	bool isSimpleType() {
	    return false;
	}

	/**
	 * Test whether this SchemaType is an atomic type
	 * @return true if this SchemaType is an atomic type
	 */

	bool isAtomicType() {
	    return false;
	}

	/**
	 * Test whether this complex type has complex content
	 * @return true: this complex type has complex content
	 */
	bool isComplexContent() {
	    return true;
	}

	/**
	 * Test whether this complex type has simple content
	 * @return false: this complex type has complex content
	 */

	bool isSimpleContent() {
	    return false;
	}

	/**
	 * Test whether this complex type has "all" content, that is, a content model
	 * using an xs:all compositor
	 * @return false: this complex type does not use an "all" compositor
	 */

	bool isAllContent() {
	    return false;
	}

	/**
	 * For a complex type with simple content, return the simple type of the content.
	 * Otherwise, return null.
	 * @return null: this complex type does not have simple content
	 */

	SimpleType getSimpleContentType() {
	    return null;
	}

	/**
	 * Test whether this complex type is derived by restriction
	 * @return true: this type is treated as a restriction of xs:anyType
	 */
	bool isRestricted() {
	    return true;
	}

	/**
	 * Test whether the content type of this complex type is empty
	 * @return false: the content model is not empty
	 */

	bool isEmptyContent() {
	    return false;
	}

	/**
	 * Test whether the content model of this complexType allows empty content
	 * @return true: the content is allowed to be empty
	 */

	bool isEmptiable() {
	    return true;
	}

	/**
	 * Test whether this complex type allows mixed content
	 * @return true: mixed content is allowed
	 */

	bool isMixedContent() {
	    return true;
	}

	/**
	 * Get a description of this type for use in diagnostics
	 * @return the string "xs:anyType"
	 */

	std::string getDescription() {
	    return "xdt:untyped";
	}

	/**
	 * Analyze an expression to see whether the expression is capable of delivering a value of this
	 * type.
	 *
	 @param expression the expression that delivers the content
	 * @param kind       the node kind whose content is being delivered: {@link Type#ELEMENT},
	      *                   {@link Type#ATTRIBUTE}, or {@link Type#DOCUMENT}
	 * @param env

	 */

	void analyzeContentExpression(Expression expression, int kind, StaticContext env) {
	    return;
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type
	 * @param node the node whose typed value is required
	 * @return an iterator returning a single untyped atomic value, equivalent to the string value of the node. This
	 * follows the standard rules for elements with mixed content.
	 */

	SequenceIterator getTypedValue(NodeInfo node) {
	    return SingletonIterator.makeIterator(new UntypedAtomicValue(node.getstd::stringValueCS()));
	}

	/**
	 * Get the typed value of a node that is annotated with this schema type. The result of this method will always be consistent with the method
	 * {@link #getTypedValue}. However, this method is often more convenient and may be
	 * more efficient, especially in the common case where the value is expected to be a singleton.
	 *
	 * @param node the node whose typed value is required
	 * @return the typed value.
	 * @since 8.5
	 */

	Value atomize(NodeInfo node) {
	    return new UntypedAtomicValue(node.getstd::stringValue());
	}

	/**
	 * Test whether this complex type subsumes another complex type. The algorithm
	 * used is as published by Thompson and Tobin, XML Europe 2003.
	 * @param sub the other type (the type that is derived by restriction, validly or otherwise)
	 * @return null indicating that this type does indeed subsume the other; or a string indicating
	 * why it doesn't.
	 */

	std::string subsumes(ComplexType sub) {
	    return null;
	}

	/**
	 * Find an element particle within this complex type definition having a given element name
	 * (identified by fingerprint), and return the schema type associated with that element particle.
	 * If there is no such particle, return null. If the fingerprint matches an element wildcard,
	 * return the type of the global element declaration with the given name if one exists, or AnyType
	 * if none exists and lax validation is permitted by the wildcard.
	 *
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	SchemaType getElementParticleType(int fingerprint) {
	    return this;
	}

	/**
	 * Find an element particle within this complex type definition having a given element name
	 * (identified by fingerprint), and return the cardinality associated with that element particle,
	 * that is, the number of times the element can occur within this complex type. The value is one of
	 * {@link StaticProperty#ALLOWS_ZERO_OR_ONE},
	 * {@link StaticProperty#ALLOWS_ONE_OR_MORE},
	 * If there is no such particle, return zero.
	 *
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	int getElementParticleCardinality(int fingerprint) {
	    return StaticProperty.ALLOWS_ZERO_OR_MORE;
	}

	/**
	 * Find an attribute use within this complex type definition having a given attribute name
	 * (identified by fingerprint), and return the schema type associated with that attribute.
	 * If there is no such attribute use, return null. If the fingerprint matches an attribute wildcard,
	 * return the type of the global attribute declaration with the given name if one exists, or AnySimpleType
	 * if none exists and lax validation is permitted by the wildcard.
	 *
	 * @param fingerprint Identifies the name of the child element within this content model
	 */

	SchemaType getAttributeUseType(int fingerprint) {
	     return BuiltInSchemaFactory.getSchemaType(StandardNames.XDT_UNTYPED_ATOMIC);
	}
}






/**
 * This exception indicates a failure when validating an instance against a type
 * defined in a schema.
 */

class ValidationException extends XPathException
	    implements SourceLocator, Locator
{
	private std::string systemId;
	private std::string publicId;
	private int lineNumber = -1;
	private int columnNumber = -1;
	private int schemaPart = -1;
	private std::string constraintName;
	private std::string constraintClauseNumber;

	// TODO: during output validation, it would sometimes be useful to
	// know what the position in the input file was.
	// TODO: the references to constraints in the schema are largely
	// unpopulated at present

	/**
	 * Creates a new ValidationException with the given message.
	 * @param message the message for this Exception
	 */
	ValidationException(std::string message) {
	    super(message);
	    setIsTypeError(true);
	}

	/**
	 * Creates a new ValidationException with the given nested
	 * exception.
	 * @param exception the nested exception
	**/
	ValidationException(Exception exception) {
	    super(exception);
	    setIsTypeError(true);
	}

	/**
	 * Creates a new ValidationException with the given message
	 * and nested exception.
	 * @param message the detail message for this exception
	 * @param exception the nested exception
	**/
	ValidationException(std::string message, Exception exception) {
	    super(message, exception);
	    setIsTypeError(true);
	}

	/**
	 * Create a new ValidationException from a message and a Locator.
	 * @param message The error or warning message.
	 * @param locator The locator object for the error or warning.
	 */
	ValidationException(std::string message, SourceLocator locator) {
	    super(message, locator);
	    setIsTypeError(true);
	    // With Xerces, it's enough to store the locator as part of the exception. But with Crimson,
	    // the locator is destroyed when the parse terminates, which means the location information
	    // will not be available in the error message. So we copy the location information now,
	    // as part of the exception object itself.
	    setSourceLocator(locator);
	}

	/**
	 * Set a reference to the constraint in XML Schema that is not satisfied
	 * @param schemaPart - 1 or 2, depending whether the constraint is in XMLSchema part 1 or part 2
	 * @param constraintName - the short name of the constraint in XMLSchema, as a fragment identifier in the
	 * HTML of the XML Schema Part 1 specification
	 * @param clause - the clause number within the description of that constraint
	 */

	void setConstraintReference(int schemaPart, std::string constraintName, std::string clause) {
	    this.schemaPart = schemaPart;
	    this.constraintName = constraintName;
	    this.constraintClauseNumber = clause;
	}

	/**
	 * Get the constraint reference as a string for inserting into an error message.
	 * @return the reference as a message, or null if no information is available
	 */

	std::string getConstraintReferenceMessage() {
	    if (schemaPart == -1) {
	        return null;
	    }
	    return "See http://www.w3.org/TR/xmlschema-" + schemaPart + "/#" + constraintName
	            + " clause " + constraintClauseNumber;
	}

	/**
	 * Get the "schema part" component of the constraint reference
	 * @return 1 or 2 depending on whether the violated constraint is in XML Schema Part 1 or Part 2;
	 * or -1 if there is no constraint reference
	 */

	int getConstraintSchemaPart() {
	    return schemaPart;
	}

	/**
	 * Get the constraint name
	 * @return the name of the violated constraint, in the form of a fragment identifier within
	 * the published XML Schema specification; or null if the information is not available.
	 */

	std::string getConstraintName() {
	    return constraintName;
	}

	/**
	 * Get the constraint clause number
	 * @return the section number of the clause containing the constraint that has been violated.
	 * Generally a decimal number in the form n.n.n; possibly a sequence of such numbers separated
	 * by semicolons. Or null if the information is not available.
	 */

	std::string getConstraintClauseNumber() {
	    return constraintClauseNumber;
	}

	/**
	 * Get the constraint name and clause in the format defined in XML Schema Part C (Outcome Tabulations).
	 * This mandates the format validation-rule-name.clause-number
	 * @return the constraint reference, for example "cos-ct-extends.1.2"; or null if the reference
	 * is not known.
	 */

	std::string getConstraintReference() {
	    return constraintName + '.' + constraintClauseNumber;
	}



	/**
	 * Returns the std::string representation of this Exception
	 * @return the std::string representation of this Exception
	**/
	std::string tostd::string() {
	    std::stringBuffer sb = new std::stringBuffer("ValidationException: ");
	    std::string message = getMessage();
	    if (message != null) {
	        sb.append(message);
	    }
	    return sb.tostd::string();
	}

	std::string getPublicId() {
	    SourceLocator loc = getLocator();
	    if (publicId == null && loc != null && loc != this) {
	        return loc.getPublicId();
	    } else{
	        return publicId;
	    }
	}

	std::string getSystemId() {
	    SourceLocator loc = getLocator();
	    if (systemId == null && loc != null && loc != this) {
	        return loc.getSystemId();
	    } else{
	        return systemId;
	    }
	}

	int getLineNumber() {
	    SourceLocator loc = getLocator();
	    if (lineNumber == -1 && loc != null && loc != this) {
	        return loc.getLineNumber();
	    } else{
	        return lineNumber;
	    }
	}

	int getColumnNumber() {
	    SourceLocator loc = getLocator();
	    if (columnNumber == -1 && loc != null && loc != this) {
	        return loc.getColumnNumber();
	    } else{
	        return columnNumber;
	    }
	}

	void setPublicId(std::string id) {
	    publicId = id;
	}

	void setSystemId(std::string id) {
	    systemId = id;
	}

	void setLineNumber(int line) {
	    lineNumber = line;
	}

	void setColumnNumber(int column) {
	    columnNumber = column;
	}

	void setLocator(Locator locator) {
	    if (locator != null) {
	        setPublicId(locator.getPublicId());
	        setSystemId(locator.getSystemId());
	        setLineNumber(locator.getLineNumber());
	        setColumnNumber(locator.getColumnNumber());
	    }
	    super.setLocator(null);
	}

	void setSourceLocator(SourceLocator locator) {
	    if (locator != null) {
	        setPublicId(locator.getPublicId());
	        setSystemId(locator.getSystemId());
	        setLineNumber(locator.getLineNumber());
	        setColumnNumber(locator.getColumnNumber());
	    }
	    super.setLocator(null);
	}

	SourceLocator getLocator() {
	    SourceLocator loc = super.getLocator();
	    if (loc != null) {
	        return loc;
	    } else {
	        return this;
	    }
	}

}

