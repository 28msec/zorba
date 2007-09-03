/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */
 
/* TODO
- Implementation of xqp_string
*/
#include "types/sequence_type.h"
#include "util/rchandle.h"
#include "types/representations.h"
#include "../../runtime/batching.h"


#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifndef XQP_ITEM_H
#define XQP_ITEM_H


namespace xqp {

typedef TypeCode sequence_type_t;
typedef uint64_t qnamekey_t;
class Item;
typedef rchandle<Item> Item_t;
class BasicIterator;
typedef rchandle<BasicIterator> Iterator_t;
/*______________________________________________________________________
|  
|	'item' - top of the XQuery value hierarchy,
|	         union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class Item : virtual public rcobject
{
private:
	/** Method is used by methods in this class which are not allowed to be invoked.
		* They must be overwritten in specific item implementation.
	 	*/
	void showError() const;
	
public:
	/* -------------------   General Methods for Items ------------------------------ */
	/**
	 *  @return  (dynamic) XQuery type of the item
	 */
	virtual sequence_type_t getType( ) const = 0;
	
	/**
	 *  Carries out Atomization on the item. Although atomization can be carried
	 *  out in a generic way, atomization is pushed down to the item level for 
	 *  performance reasons. Atomization is defined in the XQuery data model
	 *  specification (Section 2.6.4).
	 * 
	 *  @return  result of atomization
	 */	
	virtual Item_t getAtomizationValue( ) const = 0;
	
	/**
	 *  Computes the Effective Boolean Value for that item as specified in the
	 *  XQuery Functions & Operators specification (Section 15.1.1).
	 * 
	 *  @return  result of Effective Boolean Value
	 */	
	virtual Item_t getEBV( ) const = 0;
	
	/**
	 *  @return  string value of the item as defined in XQuery data model 
	 *           specification (Section 2.6.5).
	 */
	virtual xqp_string getStringProperty( ) const = 0;
	
	/**
	 *  @return  "true" if the item is a node; false if the item is an atomic value
	 */
	virtual bool isNode() const = 0;
	
	/**
	 *  @return  "true" if the item is an atomic value; false if the item is a node
	 */
	virtual bool isAtomic() const = 0;
	
	
	/* -------------------  Methods for AtomicValues ------------------------------ */
	/**
	 *  getXValue functions:
	 *  @return  value of type X
	 *
	 *  Assuming that the item is an AtomicValue of a particular kind X, return the value
	 *  of the item. Implementations of X, e.g., a specific DoubleValue implementation, will override
	 *  its specific getXValue method (i.e., getDoubleValue) and not change any of the other methods.
	 *  Implementations of the seven kinds of nodes should not override the definition of these 
	 *  methods. 
	 */
	
	/** Accessor for xs:anyUri, xs:ENTITY, xs:ID, xs:IDREF, xs:language, xs:NCName, xs:NMTOKEN,
		* xs:NOTATION, xs:Name, xs:nonPositiveInteger, xs:normalizedString, xs:string, xs:token, 
		* doucment node, element node, attribute node, namespace node, processing instruction node, 
		* comment node, text node
		*/
	virtual xqp_string getStringValue() const { 
		this->showError();
		return NULL;
	}
	
	
	/** Accessor for xs:base64Binary
		*/
	virtual xqp_base64Binary getBase64Binary() const {
		this->showError();
		return NULL;
	}
	
	/** Accessor for xs:boolean
		*/
	virtual bool getBooleanValue() const { 
		this->showError();
		return false;
	}
	
	/** Accessor for xs:decimal, xs:(nonPositive | negative | nonNegativeInteger | positive)integer, 
		* xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
		*/
	virtual long double getDecimalValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:int
		*/
	virtual int32_t getIntValue() const { 
		this->showError(); 
		return 0;
	}
	
	/** Accessor for xs:(nonPositive | negative | nonNegativeInteger | positive)integer, 
		* xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
		*/
	virtual long long getIntegerValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:long
		*/
	virtual long getLongValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:short
		*/
	virtual short getShortValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:unsignedChar, xs:unsignedByte
		*/
	virtual unsigned char getUnsignedCharValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:date
		*/
	virtual xqp_date getDateValue() const {
		this->showError();
		return xqp_date();
	}
	
	/** Accessor for xs:dateTime
		*/
	virtual xqp_dateTime getDateTimeValue() const {
		this->showError();
		return xqp_dateTime();
	}
	
	/** Accessor for xs:double
		*/
	virtual double getDoubleValue() const { 
		this->showError();
		return 0;
	}

	/** Accessor for xs:duration
		*/
	virtual xqp_duration getDurationValue() const {
		this->showError();
		return xqp_duration();
	}
	
	/** Accessor for xs:ENTITIES, xs:IDREFS, xs:NMTOKENS
		*/
	virtual std::vector<xqp_string> getStringVectorValue() const {
		this->showError();
		return std::vector<xqp_string>();
	}
	
	/** Accessor for xs:float
		*/
	virtual float getFloatValue() const {
		this->showError();
		return 0;
	}

	/** Accessor for xs:gDay
		*/
	virtual xqp_gDay getGDayValue() const {
		this->showError();
		return xqp_gDay();
	}
	
	/** Accessor for xs:gMonth
		*/
	virtual xqp_gMonth getGMonthValue() const {
		this->showError();
		return xqp_gMonth();
	}

	/** Accessor for xs:gMonthDay
		*/
	virtual xqp_gMonthDay getGMonthDayValue() const {
		this->showError();
		return xqp_gMonthDay();
	}

	/** Accessor for xs:gYear
		*/
	virtual xqp_gYear getGYearValue() const {
		this->showError();
		return xqp_gYear();
	}
	
	/** Accessor for xs:gYearMonth
		*/
	virtual xqp_gYearMonth getGYearMonthValue() const {
		this->showError();
		return xqp_gYearMonth();
	}
	
	/** Accessor for xs:hexBinary
		*/
	virtual xqp_hexBinary getHexBinaryValue() const {
		this->showError();
		return xqp_hexBinary();
	}
	
	/** Accessor for xs:nonNegativeIntegerValue, xs:positiveInteger, xs:unsignedInt
		*/
	virtual uint32_t getUnsignedIntValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:time
		*/
	virtual xqp_time getTimeValue() const {
		this->showError();
		return xqp_time();
	}
	
	/** Accessor for xs:unsignedLong
		*/
	virtual unsigned long getUnsignedLongValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:unsignedShort
		*/
	virtual unsigned short getUnsignedShortValue() const {
		this->showError();
		return 0;
	}
	
	/** Accessor for xs:qname
		*/
	virtual qnamekey_t getQNameKey() const {
		this->showError();
		return 0;
	}
	
	static qnamekey_t createQNameKey(xqp_string _namespace, xqp_string prefix, xqp_string localName);

	/* -------------------  Methods for Nodes ------------------------------------- */

	/**
	 *  getNodeProperty functions - Accessor of XDM (see XDM specification, Section 5)
	 *  @return  value of node property
	 *
	 *  Assuming that the item is a node, return the properties of that particular node.
	 *  Since all these properties are defined on all seven kinds of nodes (documents, elements,
	 *  attributes, etc.), the implementations of all seven kinds of nodes must override these
	 *  methods. Implementations of atomic values should keep the default (error) implementation
	 *  of these methods.
	 */				
	 	
	/** Accessor for element node
	 	*  @return  attribute*
	 	*/ 	
	virtual Iterator_t getAttributes() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for document node, element node, attribute node, 
		* processing instruction node, comment node, text node
	 	*  @return  uri?
	 	*/ 		 
	virtual Item_t getBaseURI() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for document node, element node
	 	*  @return  node*
	 	*/ 	
	virtual Iterator_t getChildren() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for document node
	 *  @return  uri?
	 */ 	
	virtual Item_t getDocumentURI() const { 
		this->showError();
		return NULL;
	}
	
	/** Accessor for element node, attribute node
	  * @return isId: Used for attribute items (defines the attribute an id?)
	  */
	virtual bool isId() const {
		this->showError();
		return false;
	}
	
	/** Accessor for element node, attribute node
	  * @return isIdrefs Used for attribute (defines the attribute an idref?))
	  */
	virtual bool isIdrefs() const {
		this->showError();
		return false;
	}

	/** Accessor for element node
	 *  @return  node*
	 */   
	virtual Iterator_t getNamespaceBindings() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for element node
	 *  @return  node*
	 */
	virtual Iterator_t getNamespaceNodes() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for element node
	 *  @return  boolean?
	 */
	virtual Item_t getNilled() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for document node, element node, attribute node, namespace node, 
	 *	processing instruction node, comment node, text node
	 *  @return  string
	 */
	virtual Item_t getNodeKind() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for element node, attribute node, namespace node, processing instruction node
	 *  @return qname?
	 */
	virtual Item_t getNodeName() const { 
		this->showError();
		return NULL;
	}

	/** Accessor for element node, attribute node, namespace node, processing instruction node,
		* comment node, text node
	 	* @return node?
	 	*/
	virtual Item_t getParent() const { 
		this->showError();
		return NULL;
	}
	
	/** Accessor for document node, element node, attribute node, namespace node,
		* processing instruction node, comment node, text node
		*
	  * @return typedValue?
	  */
	virtual Iterator_t getTypedValue() const {
		this->showError();
		return NULL;
	}
	
	/**
		* Accessor for element node, attribute node
		*
	  * @return type name as qname
	  */
	virtual Item_t getTypeName() const {
		this->showError();
		return NULL;
	}
	
		/** Accessor for xs:qname
			* @return namespace uri
			*/
	virtual xqp_string getQNameNamespace() const {
		this->showError();
		return NULL;
	}
	
	/** Accessor for xs:qname
		* @return namespace prefix
		*/
	virtual xqp_string getQNamePrefix() const {
		this->showError();
		return NULL;
	}
	
	/** Accessor for xs:qname
		* @return namespace local name
		*/
	virtual xqp_string getQNameLocalName() const {
		this->showError();
		return NULL;
	}
	
	/** Accessor for document node
		* @return unparsed entity public id
		*/
	virtual xqp_string getUnparsedEntityPublicId() const {
		this->showError();
		return NULL;
	}
	
	/** Accessor for document node
		* @return unparsed entity system id
		*/
	virtual xqp_string getUnparsedEntitySystemid() const {
		this->showError();
		return NULL;
	}
	
	/** Method to print to content of the Item
		*/
	virtual xqp_string show() const;
};   /* Item */

} /* namespace xqp */
#endif /* XQP_VALUES_H */

