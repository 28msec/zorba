/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#ifndef XQP_STORE_ITEM_H
#define XQP_STORE_ITEM_H

#include "util/utf8/xqpString.h"
#include "types/representations.h"
#include "store/api/store_consts.h"

#include <iostream>
#include <sstream>
#include <vector>


namespace xqp
{

template <class Object> class rchandle;
  
typedef rchandle<class Item> Item_t;
typedef rchandle<class AnyUriItem> AnyUriItem_t;
typedef rchandle<class NodeItem> NodeItem_t;

typedef rchandle<class Iterator> Iterator_t;

typedef std::vector<std::pair<xqp_string, xqp_string> > NamespaceBindings;

typedef StoreConsts::NodeKind_t NodeKind_t;


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
  virtual void close() = 0;
};
  
  
/**
 *
 *  'item' - top of the XQuery value hierarchy,
 *         union of node types and atomic types
 *  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
 */
class Item : public rcobject
{
private:
  /**
   * Method is used by methods in this class which are not allowed to be invoked.
   * They must be overwritten in specific item implementation.
   */
  void showError() const;

public:
  ~Item();

  /* -------------------   General Methods for Items ------------------------------ */
  /**
   *  @return  (dynamic) XQuery type of the item
   */
  virtual Item_t getType( ) const = 0;

  virtual bool isNumeric() const;

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
   * Get a hash value computed from the value of this item.
   *
   * @return The hash value
   */
  virtual uint32_t hash() const
  {
    this->showError();
    return 0;
  };

  /**
   *  Compares (by value) two items. All comparisons must be done by this
   *  method. A store may carry out pooling and implement the value comparison
   *  using "pointer identity".
   *
   *  @return  true, if the two items are the "same"
   */
  virtual bool equals(Item_t) const = 0;

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
  virtual xqp_string getStringValue() const
  {
    this->showError();
    return "";
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
  virtual bool getBooleanValue() const
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
  
  /** Accessor for xs:nonNegativeInteager, xs:positiveInteger
   */
  virtual xqp_uinteger getUnsignedIntegerValue() const
  {
    this->showError();
    return 0;
  }

  /** Accessor for xs:unsignedChar, xs:unsignedByte
   */
  virtual xqp_ubyte getUnsignedByteValue() const
  {
    this->showError();
    return 0;
  }
  
  virtual xqp_byte getByteValue() const
  {
    showError();
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
  virtual xqp_uint getUnsignedIntValue() const
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
  virtual xqp_ulong getUnsignedLongValue() const
  {
    this->showError();
    return 0;
  }

  /** Accessor for xs:unsignedShort
   */
  virtual xqp_ushort getUnsignedShortValue() const
  {
    this->showError();
    return 0;
  }

  /**
   * Helper method for numeric atomic items
   * @return true, if containing number is not-a-number (possible for floating-point numbers)
   */
  virtual bool isNaN() const
  {
    this->showError();
    return 0;
  }

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
    return "";
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
    return "";
  }

  /** Accessor for attribute node
   * @return isId: Used for attribute items (defines the attribute an id?)
   */
  virtual bool isId() const
  {
    this->showError();
    return false;
  }

  /** Accessor for attribute node
   * @return isIdrefs Used for attribute (defines the attribute an idref?))
   */
  virtual bool isIdrefs() const
  {
    this->showError();
    return false;
  }

  /** Accessor for element node
   *  @return  returns prefix namespace pairs
   */
  virtual NamespaceBindings getNamespaceBindings() const
  {
    this->showError();
    std::vector<std::pair<xqp_string, xqp_string> > vec;
    return vec;
  }
  
  /** Accessor for element node
   *  @return  boolean?
   */
  virtual bool getNilled() const
  {
    this->showError();
    return false;
  }

  /** Accessor for document node, element node, attribute node, namespace node,
   *  processing instruction node, comment node, text node
   *  @return  TypeCode of the current node
   */
  virtual NodeKind_t getNodeKind() const
  {
    this->showError();
    return StoreConsts::elementNode;
  }
  
  /** Accessor for element node, attribute node
   *  @return qname?
   */
  virtual Item_t getNodeName() const
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
  
  /** Accessor for xs:qname, namespace node
   * @return namespace uri
   */
  virtual xqp_string getNamespace() const
  {
    this->showError();
    return "";
  }

  /** Accessor for xs:qname, namespace node
   * @return namespace prefix
   */
  virtual xqp_string getPrefix() const
  {
    this->showError();
    return "";
  }

  /** Accessor for xs:qname
   * @return namespace local name
   */
  virtual xqp_string getLocalName() const
  {
    this->showError();
    return "";
  }

  /** Accessor for document node
   * @return unparsed entity public id
   */
  virtual xqp_string getUnparsedEntityPublicId() const
  {
    this->showError();
    return "";
  }

  /** Accessor for document node
   * @return unparsed entity system id
   */
  virtual xqp_string getUnparsedEntitySystemId() const
  {
    this->showError();
    return "";
  }

  /**
   *  Accessor for processing instruction node
   * @return target of the PI
   */
  virtual xqp_string getTarget() const
  {
    this->showError();
    return "";
  }

  /** Method to print to content of the Item
   */
  virtual xqp_string show() const;

  virtual void serializeXML( std::ostream& os );
};   /* Item */

  
class AtomicItem : public Item
{
public:
  virtual ~AtomicItem();
  bool isNode() const;
  bool isAtomic() const;
  
  virtual Item_t getAtomizationValue() const;
  virtual Iterator_t getTypedValue() const;
}; /* class AtomicItem */
  

} /* namespace xqp */
#endif /* XQP_VALUES_H */

