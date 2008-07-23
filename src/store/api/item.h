/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_STORE_ITEM_H
#define ZORBA_STORE_ITEM_H

#include <vector>
#include <zorba/store_consts.h>

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"

#include "common/shared_types.h"


namespace zorba 
{
class serializer;

namespace store
{

typedef std::vector<std::pair<xqpString, xqpString> > NsBindings;
typedef StoreConsts::NodeKind NodeKind;


/**
 *
 *  'item' - top of the XQuery value hierarchy,
 *         union of node types and atomic types
 *  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
 */
class Item : public RCObject
{
#ifdef ZORBA_FOR_ONE_THREAD_ONLY

protected:
  mutable long  * theTreeRCPtr;

  Item() : theTreeRCPtr(0) { }

public:

  long* 
  getSharedRefCounter() const { return theTreeRCPtr; }

  SYNC_CODE(RCLock* getRCLock() const { return NULL; })

#else

protected:
  mutable long             * theTreeRCPtr;
  SYNC_CODE(mutable RCLock * theRCLockPtr;)

  Item() : theTreeRCPtr(0), theRCLockPtr(0) { }

public:
  long*
  getSharedRefCounter() const { return theTreeRCPtr; }

  SYNC_CODE(RCLock* getRCLock() const { return theRCLockPtr; })

#endif

  virtual ~Item() {}

  /* -------------------   General Methods for Items ------------------------- */

  /**
   *  @return  "true" if the item is a node
   */
  virtual bool 
  isNode() const = 0;

  /**
   *  @return  "true" if the item is an atomic value
   */
  virtual bool 
  isAtomic() const = 0;

  /**
   *  @return  "true" if the item is a pending update list
   */
  virtual bool 
  isPul() const = 0;

  /**
   *  @return  (dynamic) XQuery type of the item
   */
  virtual Item*
  getType( ) const;

  /**
   * @return true if items contains a numeric value
   */
  //virtual bool
  //isNumeric() const;

  /**
   * Get a hash value computed from the value of this item.
   *
   * @param RuntimeCB the runtime control block that contains the
   *        dynamic and static context
   *
   * @param An optional XQPCollator that is used for hasing string
   *        items
   *
   * @return The hash value
   */
  virtual uint32_t 
  hash(long timezone = 0, XQPCollator* aCollation = 0) const;
  
  /**
   *  Compares (by value) two items. All comparisons must be done by this
   *  method. A store may carry out pooling and implement the value comparison
   *  using "pointer identity".
   *
   *  @param RuntimeCB the runtime control block that contains
   *                   the dynamic and static context
   *
   *  @param An optional XQPCollator that is used for comparing string items
   *
   *  @return  true, if the two items are the "same"
   */
  virtual bool 
  equals(const Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  
  /**
   *  Computes the Effective Boolean Value for that item as specified in the
   *  XQuery Functions & Operators specification (Section 15.1.1).
   *
   *  @return  result of Effective Boolean Value
   */
  virtual Item_t 
  getEBV( ) const;

  /**
   *  Carries out Atomization on the item. Although atomization can be carried
   *  out in a generic way, atomization is pushed down to the item level for
   *  performance reasons. Atomization is defined in the XQuery data model
   *  specification (Section 2.6.4).
   *
   *  @return  result of atomization
   */
  virtual Item_t 
  getAtomizationValue( ) const;

  /**
   *  @return  string value of the item as defined in XQuery data model
   *           specification (Section 2.6.5).
   */
  virtual xqpStringStore_t 
  getStringValue( ) const;

  /**
   * Helper method with is used to return a StringValue of an Item
   * by pointer instead of rchandle
   */
  virtual xqpStringStore*
  getStringValueP() const;


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
  
  /** Accessor for xs:base64Binary
   */
  virtual xqp_base64Binary 
  getBase64BinaryValue() const;

  /** Accessor for xs:boolean
   */
  virtual bool 
  getBooleanValue() const;

  /** Accessor for xs:decimal, xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
   * xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
   */
  virtual xqp_decimal 
  getDecimalValue() const;

  /** Accessor for xs:int
   */
  virtual xqp_int 
  getIntValue() const;
  
  /** Accessor for xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
   * xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
   */
  virtual xqp_integer 
  getIntegerValue() const;

  /** Accessor for xs:long
   */
  virtual xqp_long 
  getLongValue() const;

  /** Accessor for xs:short
   */
  virtual xqp_short
  getShortValue() const;

  /** Accessor for xs:nonNegativeInteager, xs:positiveInteger
   */
  virtual xqp_uinteger
  getUnsignedIntegerValue() const;

  /** Accessor for xs:unsignedChar, xs:unsignedByte
   */
  virtual xqp_ubyte
  getUnsignedByteValue() const;


  virtual xqp_byte
  getByteValue() const;


  /** Accessor for xs:dateTime
   */
  virtual const xqp_dateTime&
  getDateTimeValue() const;

  /** Accessor for xs:date
   */
  virtual const xqp_date&
  getDateValue() const;

  /** Accessor for xs:time
   */
  virtual const xqp_time&
  getTimeValue() const;

  /** Accessor for xs:gYearMonth
   */
  virtual const xqp_gYearMonth&
  getGYearMonthValue() const;

  /** Accessor for xs:gYear
   */
  virtual const xqp_gYear&
  getGYearValue() const;

  /** Accessor for xs:gMonth
   */
  virtual const xqp_gMonth&
  getGMonthValue() const;

  /** Accessor for xs:gMonthDay
   */
  virtual const xqp_gMonthDay&
  getGMonthDayValue() const;

  /** Accessor for xs:gDay
   */
  virtual const xqp_gDay&
  getGDayValue() const;


  /** Accessor for xs:double
   */
  virtual const xqp_double&
  getDoubleValue() const;


  /** Accessor for xs:duration
   */
  virtual const xqp_duration&
  getDurationValue() const;


  /** Accessor for xs:dayTimeDuration
   */
  virtual const xqp_dayTimeDuration&
  getDayTimeDurationValue() const;


  /** Accessor for xs:yearMonthDuration
   */
  virtual const xqp_yearMonthDuration&
  getYearMonthDurationValue() const;


  /** Accessor for xs:ENTITIES, xs:IDREFS, xs:NMTOKENS
   */
  virtual std::vector<xqp_string>
  getStringVectorValue() const;


  /** Accessor for xs:float
   */
  virtual xqp_float
  getFloatValue() const;


  /** Accessor for xs:hexBinary
   */
  virtual xqp_hexBinary
  getHexBinaryValue() const;


  /** Accessor for xs:nonNegativeIntegerValue, xs:positiveInteger, xs:unsignedInt
   */
  virtual xqp_uint
  getUnsignedIntValue() const;
  

  /** Accessor for xs:unsignedLong
   */
  virtual xqp_ulong
  getUnsignedLongValue() const;


  /** Accessor for xs:unsignedShort
   */
  virtual xqp_ushort
  getUnsignedShortValue() const;


  /**
   * Helper method for numeric atomic items
   * @return true, if containing number is not-a-number (possible for floating-point numbers)
   */
  virtual bool
  isNaN() const;


  /**
   * Helper method for numeric atomic items
   * @return true, if containing numbers represents -INF or +INF
   */
  virtual bool
  isPosOrNegInf() const;
  
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
  
  /** Accessor for document node
   *  @return  uri?
   */
  virtual xqpStringStore*
  getDocumentURI() const;

  /** Accessor for document node, element node, attribute node,
   * processing instruction node, comment node, text node
   *  @return  uri?
   */
  virtual xqpStringStore_t
  getBaseURI() const;

  /** Accessor for element node
   *  @return  attribute*
   */
  virtual Iterator_t
  getAttributes() const;
  
  /** Accessor for document node, element node
   *  @return  node*
   */
  virtual Iterator_t
  getChildren() const;

  /** Accessor for attribute node
   * @return isId: Used for attribute items (defines the attribute an id?)
   */
  virtual bool
  isId() const;

  /** Accessor for attribute node
   * @return isIdRefs Used for attribute (defines the attribute an idref?))
   */
  virtual bool
  isIdRefs() const;
  
  /** Accessor for element node
   *  @return  returns prefix namespace pairs
   */
  virtual void
  getNamespaceBindings(
        NsBindings& bindings,
        StoreConsts::NsScoping ns_scoping = StoreConsts::ALL_NAMESPACES) const;

  /** Accessor for element node
   *  @return  boolean?
   */
  virtual Item_t
  getNilled() const;

  /** Accessor for document node, element node, attribute node, namespace node,
   *  processing instruction node, comment node, text node
   *  @return  TypeCode of the current node
   */
  virtual NodeKind
  getNodeKind() const;

  /** Accessor for element node, attribute node
   *  @return qname?
   */
  virtual Item*
  getNodeName() const;

  /**
   * Accessor for element, attribute, processing instruction, comment, text nodes
   * @return node?
   */
  virtual Item*
  getParent() const;

  /** Accessor for document node, element node, attribute node, namespace node,
   * processing instruction node, comment node, text node
   *
   * @return typedValue?
   */
  virtual void
  getTypedValue(Item_t& val, Iterator_t& iter) const;

  /** Accessor for xs:qname, namespace node
   * @return namespace uri
   */
  virtual xqpStringStore*
  getNamespace() const;

  /** Accessor for xs:qname, namespace node
   * @return namespace prefix
   */
  virtual xqpStringStore*
  getPrefix() const;

  /** Accessor for xs:qname
   * @return namespace local name
   */
  virtual xqpStringStore*
  getLocalName() const;

  /** Accessor for document node
   * @return unparsed entity public id
   */
  virtual xqpStringStore*
  getUnparsedEntityPublicId() const;

  /** Accessor for document node
   * @return unparsed entity system id
   */
  virtual xqpStringStore*
  getUnparsedEntitySystemId() const;

  /**
   *  Accessor for processing instruction node
   * @return target of the PI
   */
  virtual xqpStringStore*
  getTarget() const;

  /**
   * Make a copy of the xml tree rooted at this node and place the copied
   * tree at a given position under a given node.
   *
   * @param parent   The node P under which the copied tree is to be placed.
   *                 P may be NULL, in which case the copied tree becomes a
   *                 new standalone xml tree.
   * @param pos      The position under P where the copied tree is to be placed.
   *                 If "this" is an attribute node, pos is a position among the
   *                 attributes of P; otherwise it is a position among the 
   *                 children of P. If pos is negative or greater or equal to
   *                 the current number of attributes/children in P, then the
   *                 copied tree is appended to P's attributes/children.
   * @param copymode Encapsulates the construction-mode and copy-namespace-mode
   *                 components of the query's static context. To optimize
   *                 node-construction expressions, copymode also says whether
   *                 a copy can actually be avoided by simply placing this node
   *                 among P's children/attributes. In this case, the node 
   *                 becomes a "shared" child among P and its current parent.
   *                 (P must have been created with the "allowSharing" paremeter
   *                 set to true; see ItemFactory::createDocumentNode() and
   *                 ItemFactory::createElementNode() methods).
   * @return         A pointer to the root node of the copied tree, or to this
   *                 node if no copy was actually done. 
   */
  virtual Item* copy(
        Item*           parent,
        long            pos,
        const CopyMode& copymode) const;

  /**
   * An optimization method used to indicate to the store that the construction
   * of this node (including its children and attributes) is complete. Some 
   * stores may benefit from this information to do internal cleanup, memory
   * management, or other optimizations when they know that a node has reached a
   * "stable" state (e.g. after the initial creation of this node or after a
   * set of updates). Other stores may just provide an empty implementation of
   * this method.
   */
  virtual void finalizeNode();

  /** Method to print to content of the Item
   */
  virtual xqp_string
  show() const;

  //virtual void
  //serializeXML(serializer& ser, std::ostream& os) const;

  virtual void
  applyUpdates();
}; 


} // namespace store
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
