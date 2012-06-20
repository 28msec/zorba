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

#include <iostream>
#include <vector>

#include <zorba/config.h>
#include <zorba/store_consts.h>
#include <zorba/streams.h>

#include "zorbatypes/rclock.h"
#include "zorbatypes/schema_types.h"

#include <zorba/store_consts.h>
#include "store/api/shared_types.h"

#ifndef ZORBA_NO_FULL_TEXT
#include <zorba/locale.h>
#include <zorba/tokenizer.h>
#include "store/api/ft_token_iterator.h"
#endif /* ZORBA_NO_FULL_TEXT */

namespace zorba 
{

class ZorbaException;

namespace store
{

typedef StoreConsts::NodeKind NodeKind;

/**
 *  Class Item represents an "item" as defined by the XQuery Data Model (XDM)
 *  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
 */
class ZORBA_DLL_PUBLIC Item
{
public:
  enum ItemKind
  {
    NODE       = 0x10,
    ATOMIC     = 0x21,
    PUL        = 0x41, 
    FUNCTION   = 0x81,
    LIST       = 0x101,
#ifdef ZORBA_WITH_JSON
    JSONIQ     = 0x201,
#endif
    ERROR_     = 0x401
  };

protected:
  typedef union 
  {
    long    * treeRCPtr;
    long      itemKind;
  }
  ItemUnion;


protected:
  mutable long      theRefCount;
  mutable ItemUnion theUnion;

protected:

  Item() : theRefCount(0)
  {
    theUnion.treeRCPtr = 0;
  }

  Item(ItemKind k) : theRefCount(0)
  {
    theUnion.itemKind = k;
  }

public:

  virtual ~Item() {}

  virtual void free() { delete this; }

  long getRefCount() const { return theRefCount; }

  long* getSharedRefCounter() const { return theUnion.treeRCPtr; }

  void addReference() const;

  void removeReference();


  /* -------------------   General Methods for Items ------------------------- */

  /**
   * @return the kind of the item
   */
  ItemKind getKind() const;

  /**
   *  @return  "true" if the item is a node
   */
  bool 
  isNode() const;

#ifdef ZORBA_WITH_JSON
  /**
   *  @return  "true" if the item is a JSON item
   */
  bool
  isJSONItem() const;
#endif

  /**
   *  @return  "true" if the item is an atomic value
   */
  bool 
  isAtomic() const;

  /**
   * @return  "true" if the item is an list of atomic values
   */
  bool 
  isList() const;

  /**
   *  @return  "true" if the item is a pending update list
   */
  bool 
  isPul() const;

  /**
   * @return "true" if the item is an error.
   */
  bool
  isError() const;

  /**
   * @return "true" if the item is a function.
   */
  bool
  isFunction() const;

  /**
   * @return a string representation of the item's kind
   */
  zstring printKind() const;

#ifdef ZORBA_WITH_JSON
  /**
   *  @return  "true" if the item is a JSON pair item
   */
  virtual bool 
  isJSONPair() const;

  /**
   *  @return  "true" if the item is a JSON object item
   */
  virtual bool 
  isJSONObject() const;

  /**
   *  @return  "true" if the item is a JSON array item
   */
  virtual bool 
  isJSONArray() const;
#endif

  /**
   *  @return  (dynamic) XQuery type of the item
   */
  virtual Item*
  getType() const;

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
  hash(long timezone = 0, const XQPCollator* aCollation = 0) const;
  
  /**
   * Compares (by value) two items for equality. 
   *
   * @param  An optional XQPCollator that is used for comparing string items
   * @return true, if the two items are the "same"
   * @throws ZSTR0040_TYPE_ERROR if the items are not equality-comparable. For two
   *         items to be equality-comparable, one has to be a subtype of the other
   *         and they must also be comparable by the eq operator as specified in
   *         the table of http://www.w3.org/TR/xquery/#mapping.  
   */
  virtual bool 
  equals(const Item*, long timezone = 0, const XQPCollator* aCollation = 0) const;

  /**
   *  Compares (by value) two items, returning < 0 if "this" is less than "other",
   *  0 if "this" and "other" are equal, and > 0 if "this" is greater than "other".
   *
   * @param  aCollation An optional XQPCollator that is used for comparing string items
   * @return < 0 if "this" is less than "other", 0 if "this" and "other" are
   *         equal, and > 0 if "this" is greater than "other".
   * @throws ZSTR0040_TYPE_ERROR if the items are not order-comparable. For two
   *         items to be order-comparable, one has to be a subtype of the other
   *         and they must also be comparable by the gt operator as specified in
   *         the table of http://www.w3.org/TR/xquery/#mapping.  
   * @throws ZSTR0041_NAN_COMPARISON if both "this" and "other" are xs:double
   *         or xs:float and at leat one of the items is NaN.
   */
  virtual long
  compare(const Item* other, long timezone = 0, const XQPCollator* aCollation = 0) const;
  
  /**
   *  Computes the Effective Boolean Value for that item as specified in the
   *  XQuery Functions & Operators specification (Section 15.1.1).
   *
   *  @return  result of Effective Boolean Value
   */
  virtual bool 
  getEBV() const;

  /**
   *  @return string value of the item as defined in XQuery data model
   *          specification (Section 2.6.5).
   */
  virtual zstring 
  getStringValue() const;

  virtual void
  getStringValue2(zstring& result) const;

  /**
   *  Append the string value of this item to the given string.
   *
   * @param buf The string at the end of which the string value of this item
   *            will be appended.
   */
  virtual void
  appendStringValue(zstring& buf) const;


  /**
   * Get the typed value of an item. If the item is an atomic item, its typed
   * value is the item itself. If it is a node, its typed value is defined
   * according to the XDM.
   *
   * @param val If the typed value consists of a single atomic value, it is 
   *        returned in val. Otherwise, val is set to NULL.
   * @param iter If the typed value is a sequence of atomic values, an iterator
   *        is created to iterate over the values of the sequence. Otherwise,
   *        iter is set to NULL.
   */
  virtual void
  getTypedValue(Item_t& val, Iterator_t& iter) const;

  /** Method to print to content of the Item
   */
  virtual zstring
  show() const;

  /* -------------------  Methods for AtomicValues ------------------------------ */

  /**
   * @return The numeric code coresponding to the data type of this item.
   */
  virtual SchemaTypeCode getTypeCode() const;

  /**
   * @return If this is an atomic item with a user-defined data type UT, return
   *         the underlying atomic item that stores the actual value and whose
   *         data type is a builtin atomic supertype of UT. Otherwise, return NULL.
   */
  virtual store::Item* getBaseItem() const;

  /**
   *  getXValue functions:
   *  @return  value of type X
   *
   * Assuming that the item is an AtomicValue of a particular kind X, return the
   * value of the item. Implementations of X, e.g., a specific DoubleValue
   * implementation, will override its specific getXValue method (i.e., 
   * getDoubleValue) and not change any of the other methods. Implementations of
   * the seven kinds of nodes should not override the definition of these methods.
   */

  /** Accessor for xs:string and its subtypes
   */
  virtual const zstring& getString() const;

  /** Accessor for xs:base64Binary
   */
  virtual const char* getBase64BinaryValue(size_t& size) const;

  /**
   * Checks whether a base64 item's content is already encoded
   *
   * @return true only if it is.
   */
  virtual bool isEncoded() const;

  /** Accessor for xs:boolean
   */
  virtual bool getBooleanValue() const;

  /** Accessor for xs:double
   */
  virtual xs_double getDoubleValue() const;

  /** 
   * Accessor for xs:float
   */
  virtual xs_float getFloatValue() const;

  /** 
   * Accessor for xs:decimal, xs:nonPositiveInteger, negativeInteger,
   * nonNegativeInteger, positive)integer, xs:long, xs:unsignedLong,
   * xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
   */
  virtual xs_decimal getDecimalValue() const;

  /** Accessor for xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
   * xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
   */
  virtual xs_integer 
  getIntegerValue() const;

  /** Accessor for xs:nonNegativeInteager, xs:positiveInteger
   */
  virtual xs_nonNegativeInteger
  getUnsignedIntegerValue() const;

  /** Accessor for xs:long
   */
  virtual xs_long 
  getLongValue() const;

  /** Accessor for xs:int
   */
  virtual xs_int 
  getIntValue() const;

  /** Accessor for xs:short
   */
  virtual xs_short
  getShortValue() const;

  /** Accessor for xs:byte
   */
  virtual xs_byte
  getByteValue() const;

  /** Accessor for xs:unsignedLong
   */
  virtual xs_unsignedLong
  getUnsignedLongValue() const;

  /** Accessor for xs:nonNegativeIntegerValue, xs:positiveInteger, xs:unsignedInt
   */
  virtual xs_unsignedInt
  getUnsignedIntValue() const;

  /** Accessor for xs:unsignedShort
   */
  virtual xs_unsignedShort
  getUnsignedShortValue() const;

  /** Accessor for xs:unsignedChar, xs:unsignedByte
   */
  virtual xs_unsignedByte
  getUnsignedByteValue() const;


  /** Accessor for xs:dateTime
   */
  virtual const xs_dateTime&
  getDateTimeValue() const;

  /** Accessor for xs:date
   */
  virtual const xs_date&
  getDateValue() const;

  /** Accessor for xs:time
   */
  virtual const xs_time&
  getTimeValue() const;

  /** Accessor for xs:gYearMonth
   */
  virtual const xs_gYearMonth&
  getGYearMonthValue() const;

  /** Accessor for xs:gYear
   */
  virtual const xs_gYear&
  getGYearValue() const;

  /** Accessor for xs:gMonth
   */
  virtual const xs_gMonth&
  getGMonthValue() const;

  /** Accessor for xs:gMonthDay
   */
  virtual const xs_gMonthDay&
  getGMonthDayValue() const;

  /** Accessor for xs:gDay
   */
  virtual const xs_gDay&
  getGDayValue() const;

  /** Accessor for xs:duration
   */
  virtual const xs_duration&
  getDurationValue() const;


  /** Accessor for xs:dayTimeDuration
   */
  virtual const xs_dayTimeDuration&
  getDayTimeDurationValue() const;


  /** Accessor for xs:yearMonthDuration
   */
  virtual const xs_yearMonthDuration&
  getYearMonthDurationValue() const;


  /** Accessor for xs:hexBinary
   */
  virtual xs_hexBinary
  getHexBinaryValue() const;


  /**
   * Helper method for numeric atomic items
   * @return true, if containing number is not-a-number (possible for
   *         floating-point numbers)
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
   *
   * Assuming that the item is a node, return the properties of that particular
   * node. Since all these properties are defined on all seven kinds of nodes
   * (documents, elements, attributes, etc.), the implementations of all seven
   * kinds of nodes must override these methods. Implementations of atomic values
   * should keep the default (error) implementation of these methods.
   */

  /**
   * If isValidated() is invoked on some item, it returns true if markValidated()
   * has been called before on the root of the tree where the item belongs to,
   * otherwise it returns false. Notice that validation is not done by the store, 
   * so the store itself cannot invoke the markValidated() method; it has to be
   * invoked by the "user" of the store.
   */
  virtual bool
  isValidated() const;

  /**
   * Mark the item as validated.
   */
  virtual void
  markValidated();

  /**
   *  @return True if this is an element node with name N and it has at least one
   *          descendant whose name is also N.
   *
   * Note: This function is used purely for enabling certain optimizations in the
   *       query processor. As a result, it is not necessary that a store actually
   *       provides info about the recursivity of a node; such a store should
   *       provide a dummy implementation of this method that simply returns true.
   */
  virtual bool
  isRecursive() const;

  /** Accessor for document node
   *  @return  uri?
   */
  virtual void
  getDocumentURI(zstring& uri) const;

  /** Accessor for document node, element node, attribute node,
   * processing instruction node, comment node, text node
   *  @return  uri?
   */
  virtual void
  getBaseURI(zstring& uri) const;

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
   *  @return true if this element node belongs to a substition group
   */
  virtual bool
  isInSubstitutionGroup() const;
  
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
   * If this item is a node and it belongs to a collection, return that
   * collection. Otherwise, return 0.
   *
   * @return The collection this item belongs to, or NULL if item does not
   *         belong to any collection.
   */
  virtual const Collection*
  getCollection() const;

  /**
   * Accessor for element, attribute, processing instruction, comment, text nodes
   * @return node?
   */
  virtual Item*
  getParent() const;

  /** Accessor for xs:qname, namespace node
   * @return namespace uri
   */
  virtual const zstring&
  getNamespace() const;

  /** Accessor for xs:qname, namespace node
   * @return namespace prefix
   */
  virtual const zstring&
  getPrefix() const;

  /** Accessor for xs:qname
   * @return namespace local name
   */
  virtual const zstring&
  getLocalName() const;

  /** Accessor for document node
   * @return unparsed entity public id
   */
  virtual void
  getUnparsedEntityPublicId(zstring& val) const;

  /** Accessor for document node
   * @return unparsed entity system id
   */
  virtual void
  getUnparsedEntitySystemId(zstring& val) const;

  /**
   *  Accessor for processing instruction node
   * @return target of the PI
   */
  virtual const zstring&
  getTarget() const;

  /**
   *  Accessor for the name of the function item.
   *  Returns null for anonymous functions.
   */
  virtual const Item_t
  getFunctionName() const;

  /**
   * Make a copy of the xml tree rooted at this node and place the copied
   * tree as the last child of a given node.
   *
   * @param parent   The node P under which the copied tree is to be placed.
   *                 P may be NULL, in which case the copied tree becomes a
   *                 new standalone xml tree.
   * @param copymode Encapsulates the construction-mode and copy-namespace-mode
   *                 components of the query's static context. 
   * @return         A pointer to the root node of the copied tree, or to this
   *                 node if no copy was actually done. 
   */
  virtual Item* 
  copy(Item* parent, const CopyMode& copymode) const;

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

  /* - Methods for computing relationship and properties of a node - */

  /**
   *
   */
  virtual bool
  isAncestor(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isFollowingSibling(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isFollowing(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isInSubtreeOf(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isDescendant(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isPrecedingSibling(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isPreceding(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isChild(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isAttribute(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isParent(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isPrecedingInDocumentOrder(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isFollowingInDocumentOrder(const store::Item_t&) const;

  /**
   *
   */
  virtual store::Item_t
  getLevel() const;

  /**
   *
   */
  virtual bool
  isSibling(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  isAttribute() const;

  /**
   *
   */
  virtual bool
  isComment() const;

  /**
   *
   */
  virtual bool
  isDocument() const;

  /**
   *
   */
  virtual bool
  isElement() const;

  /**
   *
   */
  virtual bool
  isProcessingInstruction() const;

  /**
   *
   */
  virtual bool
  isText() const;

  /**
   *
   */
  virtual bool
  inSameTree(const store::Item_t&) const;

  /**
   *
   */
  virtual bool
  inCollection() const;

  /**
   *
   */
  virtual bool
  inSameCollection(const store::Item_t&) const;

  /**
   *
   */
  virtual store::Item_t
  leastCommonAncestor(const store::Item_t&) const;


#ifdef ZORBA_WITH_JSON
  /* -------------------- Methods for JSON items --------------------- */

  /**
   * @return the kind of the json item
   */
  virtual store::StoreConsts::JSONItemKind 
  getJSONItemKind() const;

  /**
   * (jdm:pairs accessor)
   * @return the pairs of a json object or json array
   */
  virtual Iterator_t
  getPairs() const;

  /**
   * (jdm:members accessor)
   * @return the values of a json array
   */
  virtual Iterator_t
  getMembers() const;

  /**
   * defined on JSONObject
   * (is not an accessor)
   * @return the pair with given name
   */
  virtual store::Item*
  getPair(const store::Item_t& name) const;

  /**
   * defined on JSONArray
   * (is not an accessor)
   * @return the value at the given position
   */
  virtual store::Item*
  getMember(const store::Item_t& aPosition) const;

  /**
   * defined on JSONObjectPair (jdm:name accessor)
   * @return the name of the json pair
   */
  virtual store::Item*
  getName() const;

  /**
   * defined on JSONObjectPair JSONArrayPair (jdm:value accessor)
   * @return the value of the json pair
   */
  virtual store::Item*
  getValue() const;

  /**
   * defined on JSONObject JSONArray
   * @return the number of pairs or values in the object or array, resp.
   */
  virtual xs_integer
  getSize() const;

#endif // ZORBA_WITH_JSON


  /* -------------------- Methods for ErrorItem --------------------- */

  virtual ZorbaException* getError() const;

  /* -------------------- Methods for streamability ----------------- */

  /**
   * Checks whether the item's content is streamable.
   *
   * @return true only if it is.
   */
  virtual bool isStreamable() const;

  /**
   * Checks whether the item's content is streamable
   * and the underlying stream is seekable
   *
   * @return true only if it is.
   */
  virtual bool isSeekable() const;

  /**
   * Gets an istream for the item's content.
   *
   * @return the stream.
   * @throw ZorbaException if the item is not streamable.
   */
  virtual std::istream& getStream();

  /**
   * Gets the StreamReleaser associated with this item.
   *
   * @return the StreamReleaser.
   * @throw ZorbaException if the item is not streamable.
   */
  virtual StreamReleaser getStreamReleaser();

  /**
   * Sets the StreamReleaser associated with this item.
   *
   * @throw ZorbaException if the item is not streamable.
   */
  virtual void setStreamReleaser(StreamReleaser aReleaser);

  /* -------------------- Methods for Full-Text --------------------- */

#ifndef ZORBA_NO_FULL_TEXT
  /**
   * Gets the tokens for this item.
   *
   * @param provider The TokenizerProvider to use.
   * @param state The Tokenizer::State to use.
   * @param lang The language to use for tokenization.
   * @param wildcards If \c true, allow XQuery wildcard syntax.
   * @return Returns an iterator over the tokens.
   */
  virtual FTTokenIterator_t
  getTokens(TokenizerProvider const &provider, Tokenizer::State &state,
            locale::iso639_1::type lang, bool wildcards = false) const;
#endif /* ZORBA_NO_FULL_TEXT */


private:
  Item(const Item& other);
  Item& operator=(const Item&);
}; 

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_ITEM_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
