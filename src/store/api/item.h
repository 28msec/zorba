/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#include "types/sequence_type.h"
#include "types/representations.h"
#include "runtime/base/iterator.h"


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>


#ifndef XQP_ITEM_H
#define XQP_ITEM_H


namespace xqp
{
	template <class Object> class rchandle;
	
	typedef rchandle<class Item> Item_t;
  typedef rchandle<class QNameItem> QNameItem_t;

	typedef rchandle<class Iterator> Iterator_t;
	
	/**
	 * General iterator interface. Used to program iterators which return a
	 * sequence of items, wrapped into a rchandle object for garbage collection
	 */
	class Iterator : public rcobject
	{
		public:
			virtual ~Iterator() {}
			virtual Item_t next() = 0;
			virtual void reset() = 0;
	};
	
	
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
			~Item();
			/* -------------------   General Methods for Items ------------------------------ */
			/**
			 *  @return  (dynamic) XQuery type of the item
			 */
			virtual TypeCode getType( ) const = 0;

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
			 *  Compares (by value) two items. All comparisons must be done by this
			 *  method. A store may carry out pooling and implement the value comparison
			 *  using "pointer identity".
			 *
			 *  @return  true, if the two items are the "same"
			 */
			virtual xqp_boolean equals ( Item_t ) const = 0;

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
			virtual xqp_boolean isNode() const = 0;

			/**
			 *  @return  "true" if the item is an atomic value; false if the item is a node
			 */
			virtual xqp_boolean isAtomic() const = 0;


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
			virtual xqp_string getStringValue() const
			{
				this->showError();
				return NULL;
			}


			/** Accessor for xs:base64Binary
				*/
			virtual xqp_base64Binary getBase64Binary() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for xs:boolean
				*/
			virtual xqp_boolean getBooleanValue() const
			{
				this->showError();
				return false;
			}

			/** Accessor for xs:decimal, xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
				* xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
				*/
			virtual xqp_decimal getDecimalValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:int
				*/
			virtual xqp_int getIntValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
				* xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
				*/
			virtual xqp_integer getIntegerValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:long
				*/
			virtual xqp_long getLongValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:short
				*/
			virtual xqp_short getShortValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:unsignedChar, xs:unsignedByte
				*/
			virtual xqp_unsignedByte getUnsignedByteValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:date
				*/
			virtual xqp_date getDateValue() const
			{
				this->showError();
				return xqp_date();
			}

			/** Accessor for xs:dateTime
				*/
			virtual xqp_dateTime getDateTimeValue() const
			{
				this->showError();
				return xqp_dateTime();
			}

			/** Accessor for xs:double
				*/
			virtual xqp_double getDoubleValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:duration
				*/
			virtual xqp_duration getDurationValue() const
			{
				this->showError();
				return xqp_duration();
			}

			/** Accessor for xs:ENTITIES, xs:IDREFS, xs:NMTOKENS
				*/
			virtual std::vector<xqp_string> getStringVectorValue() const
			{
				this->showError();
				return std::vector<xqp_string>();
			}

			/** Accessor for xs:float
				*/
			virtual xqp_float getFloatValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:gDay
				*/
			virtual xqp_gDay getGDayValue() const
			{
				this->showError();
				return xqp_gDay();
			}

			/** Accessor for xs:gMonth
				*/
			virtual xqp_gMonth getGMonthValue() const
			{
				this->showError();
				return xqp_gMonth();
			}

			/** Accessor for xs:gMonthDay
				*/
			virtual xqp_gMonthDay getGMonthDayValue() const
			{
				this->showError();
				return xqp_gMonthDay();
			}

			/** Accessor for xs:gYear
				*/
			virtual xqp_gYear getGYearValue() const
			{
				this->showError();
				return xqp_gYear();
			}

			/** Accessor for xs:gYearMonth
				*/
			virtual xqp_gYearMonth getGYearMonthValue() const
			{
				this->showError();
				return xqp_gYearMonth();
			}

			/** Accessor for xs:hexBinary
				*/
			virtual xqp_hexBinary getHexBinaryValue() const
			{
				this->showError();
				return xqp_hexBinary();
			}

			/** Accessor for xs:nonNegativeIntegerValue, xs:positiveInteger, xs:unsignedInt
				*/
			virtual uint32_t getUnsignedIntValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:time
				*/
			virtual xqp_time getTimeValue() const
			{
				this->showError();
				return xqp_time();
			}

			/** Accessor for xs:unsignedLong
				*/
			virtual xqp_unsignedLong getUnsignedLongValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:unsignedShort
				*/
			virtual xqp_unsignedShort getUnsignedShortValue() const
			{
				this->showError();
				return 0;
			}

			/** Accessor for xs:qname
				*/
			virtual qnamekey_t getQNameKey() const
			{
				this->showError();
				return 0;
			}

			/**
			 * Computes the Hash of a QName
			 *
			 * @param _namespace
			 * @param prefix
			 * @param localName
			 * @return
			 */
			static qnamekey_t createQNameKey ( xqp_string _namespace, xqp_string prefix, xqp_string localName );

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
			virtual Iterator_t getAttributes() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for document node, element node, attribute node,
				* processing instruction node, comment node, text node
			 	*  @return  uri?
			 	*/
			virtual xqp_string getBaseURI() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for document node, element node
			 	*  @return  node*
			 	*/
			virtual Iterator_t getChildren() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for document node
			 *  @return  uri?
			 */
			virtual xqp_string getDocumentURI() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for attribute node
			  * @return isId: Used for attribute items (defines the attribute an id?)
			  */
			virtual xqp_boolean isId() const
			{
				this->showError();
				return false;
			}

			/** Accessor for attribute node
			  * @return isIdrefs Used for attribute (defines the attribute an idref?))
			  */
			virtual xqp_boolean isIdrefs() const
			{
				this->showError();
				return false;
			}

			/** Accessor for element node
			 *  @return  returns prefix namespace pairs
			 */
			virtual std::set<std::pair<xqp_string, xqp_string> > getNamespaceBindings() const
			{
				this->showError();
				std::set<std::pair<xqp_string, xqp_string> > set;
				return set;
			}

			/** Accessor for element node
			 *  @return  boolean?
			 */
			virtual xqp_boolean getNilled() const
			{
				this->showError();
				return false;
			}

			/** Accessor for document node, element node, attribute node, namespace node,
			 *	processing instruction node, comment node, text node
			 *  @return  TypeCode of the current node
			 */
			virtual TypeCode getNodeKind() const
			{
				this->showError();
				return xs_anyType;
			}

			/** Accessor for element node, attribute node
			 *  @return qname?
			 */
			virtual QNameItem_t getNodeName() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for element node, attribute node, namespace node, processing instruction node,
				* comment node, text node
			 	* @return node?
			 	*/
			virtual Item_t getParent() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for document node, element node, attribute node, namespace node,
				* processing instruction node, comment node, text node
				*
			  * @return typedValue?
			  */
			virtual Iterator_t getTypedValue() const
			{
				this->showError();
				return NULL;
			}

			/**
				* Accessor for element node, attribute node
				*
			  * @return type name as qname
			  */
			virtual Item_t getTypeName() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for xs:qname, namespace node
				* @return namespace uri
				*/
			virtual xqp_string getNamespace() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for xs:qname, namespace node
				* @return namespace prefix
				*/
			virtual xqp_string getPrefix() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for xs:qname
				* @return namespace local name
				*/
			virtual xqp_string getLocalName() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for document node
				* @return unparsed entity public id
				*/
			virtual xqp_string getUnparsedEntityPublicId() const
			{
				this->showError();
				return NULL;
			}

			/** Accessor for document node
				* @return unparsed entity system id
				*/
			virtual xqp_string getUnparsedEntitySystemId() const
			{
				this->showError();
				return NULL;
			}

			/**
			 *  Accessor for processing instruction node
			 * @return target of the PI
			 */
			virtual xqp_string getTarget() const
			{
				this->showError();
				return NULL;
			}

			/** Method to print to content of the Item
				*/
			virtual xqp_string show() const;
	};   /* Item */
  
  class AtomicItem : public Item
  {
    public:
      virtual ~AtomicItem();
      bool isNode() const;
      bool isAtomic() const;

      virtual Iterator_t getTypedValue() const;
  }; /* class AtomicItem */
  
  class NodeItem : public Item
  {
    protected:
      // Pointer to avoid cyclic smart pointers
      Item* theParent;

    public:
      explicit NodeItem(const Item_t& aParent);
      NodeItem();
      virtual ~NodeItem();

      virtual bool isNode() const;
      virtual bool isAtomic() const;
      virtual Item_t getEBV() const;
      virtual bool equals ( Item_t ) const;

      // Must be overwritten from every node implementation when zorba is schema-aware
      virtual TypeCode getType() const;
      virtual Item_t getParent() const;
      virtual xqp_string getBaseURI() const;
      virtual xqp_string getDocumentURI() const;
  }; /* class Node */

  class QNameItem : public AtomicItem {};
  class UntypedAtomicItem : public AtomicItem {};
  class StringItem : public UntypedAtomicItem {};
  class DecimalItem : public AtomicItem {};
  class IntItem : public AtomicItem {};
  class IntegerItem : public AtomicItem {};
  class DoubleItem : public AtomicItem {};
  class FloatItem : public AtomicItem {};
  class BooleanItem : public AtomicItem {};
  
  class DocumentNode : public NodeItem {};
  class ElementNode : public NodeItem {
    public:
      ElementNode(){}
      ElementNode(const Item_t& aParent) : NodeItem(aParent) {}
  };
  class AttributeNode : public NodeItem {
    public:
      AttributeNode(){}
      AttributeNode(const Item_t& aParent) : NodeItem(aParent) {}
  };
  class NamespaceNode : public NodeItem {
    public:
      NamespaceNode(){}
      NamespaceNode(const Item_t& aParent) : NodeItem(aParent) {}
  };
  class PiNode : public NodeItem {
    public:
      PiNode(){}
      PiNode(const Item_t& aParent) : NodeItem(aParent) {}
  };
  class CommentNode : public NodeItem {
    public:
      CommentNode(){}
      CommentNode(const Item_t& aParent) : NodeItem(aParent) {}
  };
  class TextNode : public NodeItem {
    public:
      TextNode(){}
      TextNode(const Item_t& aParent) : NodeItem(aParent) {}
  };

} /* namespace xqp */
#endif /* XQP_VALUES_H */

