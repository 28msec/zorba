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
#ifndef ZORBA_ITEM_API_H
#define ZORBA_ITEM_API_H

#include <iostream>
#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/store_consts.h>
#include <vector>

namespace zorba {

class Item;
namespace store { class Item; }

namespace serialization
{
  class Archiver;
  void operator&(zorba::serialization::Archiver &ar, zorba::Item &obj);
}

/**
 * Used for Item::getNamespaceBindings() and ItemFactory::createElementNode().
 */
typedef std::vector<std::pair<String, String> > NsBindings;

/** \brief The Zorba Item interface.
 *
 * This class is the Zorba representation of an Item as defined in the
 * XQuery 1.0 and XPath 2.0 Data Model (XDM); see http://www.w3.org/TR/xpath-datamodel/. 
 * 
 * Instances of the XDM are a sequence, i.e. an ordered collection of zero or more items.
 * In the Zorba API, a sequence is represented by the ItemSequence class.
 *
 * The Item class is the union of all XQuery node and atomic types.
 * The class provides functions to access the information of an Item. Note that not
 * all functions are defined on every Item kind. If a function is called on an Item that
 * does not provide the called function, an ZXQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE error
 * is raised.
 *
 * Instances of the Item class are always passed by copy. To check whether a given Item is valid
 * isNull() can be called which returns true if the given Item is not valid and false otherwise.
 * A new atomic Item can be created using the ItemFactory. A new node Item should be created
 * by the result of a query.
 */
class ZORBA_DLL_PUBLIC Item
{
public:
  /** \brief Default constructor
   */
  Item();

  /** \brief Copy constructor
   */
  Item(const Item& other);

  /** \brief Constructor that is used to construct Items in the Zorba engine itself.
   *
   * This constructor is for internal use only.
   */
  Item(const store::Item* item);

  /** \brief Assingment operator
   */
  const Item& operator =(const Item& rhs);

  /** \brief Assingment operator that is used in the Zorba engine itself.
   *
   * This operator is for internal use only.
   */
  const Item& operator =(const store::Item* rhs);

  bool operator ==(const Item& rhs) { return m_item == rhs.m_item; }

  /** \brief Destructor
   */
  ~Item();

  /** \brief Check if the Item is null.
   *
   * If this function returns true, the Item is not valid.
   * Note that this function is available for all types of Items.
   *
   * @return true if the Item is null, false otherwise.
   */
  bool
  isNull() const;

  /** \brief Free all resources aquired by this Item.
   *
   * After calling close() on an Item the Item is invalidated, i.e. a subsequent
   * call to isNull() will return true. 
   *
   * Note that calling this function is usually not necessary because close() is
   * implicitly called by the destructor. Calling close() is only necessary if
   * the resources aquired by an Item should be released before the Item goes out
   * of scope, i.e. the destructor is called.
   *
   * Also note that this function is available for all types of Items.
   */
  void
  close();

  /** \brief Check if the Item is a node Item.
   *
   * Note that this function is available for all types of Items.
   *
   * @return true if the Item is of type node, false otherwise.
   */
  bool
  isNode() const;

  /** \brief Check if the Item is an atomic Item.
   *
   * Note that this function is available for all types of Items.
   *
   * @return true if the Item is an atomic Item, false otherwise.
   */
  bool
  isAtomic() const;

  /**
   * @return the type of this item based on the enum values in store_const.h
   */
  store::SchemaTypeCode getTypeCode() const;

  /** \brief Get the type of the Item.
   *
   * See http://www.w3.org/TR/xpath-datamodel/#types.
   * Note that this function is available for all types of Items.
   *
   * @return Item the type of the Item as a QName Item 
   * @throw ZorbaException if an error occured.
   */
  Item
  getType() const;

  /**
   * \brief Check if the Item is a JSON Item, that is, part of the JSONiq
   * data model.
   *
   * Note that this function is available for all types of Items.
   *
   * @return true if the Item is a JSON Item, false otherwise.
   */
  bool
  isJSONItem() const;

  /** \brief Get the atomization value of the Item.
   *
   * The atomization value is the value that is returned by atomization 
   * (see http://www.w3.org/TR/xquery/#id-atomization).
   * Note that this function is available for all types of Items.
   *
   * @return Item the atomization value of the Item.
   * @throw ZorbaException if an error occured.
   */
  Iterator_t
  getAtomizationValue() const;

  /** \brief Get the string value of the Item.
   *
   * The string value is the string that is extracted by calling the fn:string function
   * on the Item (see http://www.w3.org/TR/xpath-functions/#func-string).
   * Note that this function is available for all types of Items.
   *
   * @return Item the string value of the Item.
   * @throw ZorbaException if an error occured.
   */
  String
  getStringValue() const;

  /** \brief Get the int value of the Item.
   *
   * @return Item the int value of the Item.
   * @throw ZorbaException if an error occured.
   */
  int32_t
  getIntValue() const;

  /** \brief Get the unsigned int value of the Item.
   *
   * @return Item the unsigned int value of the Item.
   * @throw ZorbaException if an error occured.
   */
  uint32_t
  getUnsignedIntValue() const;

  /** \brief Get the int value of the Item.
   *
   * @return Item the int value of the Item.
   * @throw ZorbaException if an error occured.
   */
  double
  getDoubleValue() const;

  /** \brief Get the long value of the Item.
   *
   * @return Item the long value of the Item.
   * @throw ZorbaException if an error occured.
   */
  int64_t  
  getLongValue() const;

  /** \brief Get the effective boolean value of the Item.
   *
   * The effective boolean value is the result of applying the fn:boolean function on 
   * the Item (see http://www.w3.org/TR/xpath-functions/#func-boolean).
   * Note that this function is available for all types of Items.
   *
   * @return Item the effective boolean value of the Item
   * @throw ZorbaException if an error occured.
   */
  Item
  getEBV() const;

  /** \brief Get the (optional) value of a QName's prefix.
   *
   * Note that this function is only available for Items of type QName.
   *
   * @return String the prefix of the QName.
   * @throw ZorbaException if an error occured, e.g. the Item is not a QName.
   */
  String
  getPrefix() const;

  /** \brief Get the (optional) value of a QName's namespace.
   *
   * Note that this function is only available for Items of type QName.
   *
   * @return String the namespace URI of the QName.
   * @throw ZorbaException if an error occured, e.g. the Item is not a QName.
   */
  String
  getNamespace() const;

  /** \brief Get the value of a QName's local name.
   *
   * Note that this function is only available for Items of type QName.
   *
   * @return String the local name of the QName.
   * @throw ZorbaException if an error occured, e.g. the Item is not a QName.
   */
  String
  getLocalName() const;

  /** \brief Check if the value of the Item is not a number (NaN).
   *
   * Note that this function is only available for numeric Items (e.g. Double or Float).
   * 
   * @return true if the Item is NaN, false otherwise.
   * @throw ZorbaException if an error occured, e.g. the Item is not a numeric type.
   */
  bool
  isNaN() const;

  /** \brief Check if the value of the Item is positive or negative infinity.
   *
   * Note that this function is only available for numeric Items (e.g. Double or Float).
   * 
   * @return true if the Item is +/-INF, false otherwise.
   * @throw ZorbaException if an error occured, e.g. the Item is not a numeric type.
   */
  bool
  isPosOrNegInf() const;

  /** \brief Get the bool value of the boolean Item.
   *
   * Note that this function is only available for Items of type boolean.
   *
   * @return true if the boolean value is true, false otherwise.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type boolean.
   */
  bool
  getBooleanValue() const;

  /** \brief Get an iterator for the children of this (node) Item.
   *
   * Note that this function is only available for node Items.
   * The file \link simple.cpp \endlink contains some basic examples that demonstrate
   * the use of this function.
   *
   * @return Iterator over the children of this node.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type node.
   */
  Iterator_t
  getChildren() const;

  /** \brief Get an iterator for the attributes of this (node) Item.
   *
   * Note that this function is only available for node Items.
   * The file \link simple.cpp \endlink contains some basic examples that demonstrate
   * the use of this function.
   *
   * @return Iterator over the attributes of this node.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type node.
   */
  Iterator_t
  getAttributes() const;

  /** \brief Get an iterator for the namespace bindings of this (element) Item.
    *
    * Note that this function is only available for element Items.
    * The file \link simple.cpp \endlink contains some basic examples that demonstrate
    * the use of this function.
    *
    * @param aBindings An std::vector to receive the namespace bindings of this
    *        node (each represented as a std::pair<zorba::String,zorba::String>
    *        where the first string is the namespace prefix and the second is the
    *        namespace URI).
    * @param scope A value to specify which bindings to return: all bindings (the
    *        default); only those that are specified by the namespace declaration
    *        attributes of the node (if any); or those that are implied by the
    *        qnames of the node and its attributes plus those that are specified
    *        by the namespace declaration attributes of the node (if any)
    * @throw ZorbaException if an error occured, e.g. the Item is not of type element.
    */
  void
  getNamespaceBindings(
      NsBindings& aBindings,
      store::StoreConsts::NsScoping scope = store::StoreConsts::ALL_BINDINGS) const;

  /** \brief Get parent of this (node) Item.
   *
   * Note that this function is only available for node Items.
   *
   * @return element or document parent node of this node.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type node.
   */
  Item
  getParent() const;

  /** \brief Get the name of this (node) Item.
   *
   * Note that this function is only available for node Items.
   * The file \link simple.cpp \endlink contains some basic examples that demonstrate
   * the use of this function.
   *
   * @return bool if the name of the node was retrieved successfully
   * @return aNodeName the name of the node
   * @throw ZorbaException if an error occured (e.g. the Item is not of type node).
   */
  bool
  getNodeName(Item& aNodeName) const;

  /** \brief Get the type of this (node) Item.
   *
   * Note that this function is only available for node Items.
   *
   * @return int the kind of this node (the avaialble kinds can be found in the store::StoreConsts class)
   * @throw ZorbaException if an error occured (e.g. the Item is not of type node).
   */
  int
  getNodeKind() const;

  /** \brief Get the kind of this (JSON) Item.
   *
   * Note that this function is only available for JSON Items, that is, Items
   * which return true from isJSONItem().
   *
   * @return the kind of this JSON item
   * @throw ZorbaException if an error occured (e.g. the Item is not of type JSON).
   */
  store::StoreConsts::JSONItemKind
  getJSONItemKind() const;

  /** \brief Get the size of a JSON Array.
   *
   * Note that this function is only available for JSON Arrays.
   *
   * @return Item the size of the array.
   * @throw ZorbaException if an error occured (e.g. the Item is not of type JSON Array).
   */
  uint64_t
  getArraySize() const;

  /** \brief Returns the item in the JSON array at the specified index.
   *
   * Note that this function is only available for JSON Arrays.
   *
   * @param aIndex the index in the array.
   * @return Item the indexed Item.
   * @throw ZorbaException if an error occured (e.g. the Item is not of type JSON Array).
   */
  Item
  getArrayValue(uint32_t aIndex) const;

  /** \brief Get the keys of a JSON Object.
   *
   * Note that this function is only available for JSON Objects.
   *
   * @return Iterator_t an iterator on the keys of the object.
   * @throw ZorbaException if an error occured (e.g. the Item is not of type JSON Object).
   */
  Iterator_t
  getObjectKeys() const;

  /** \brief Returns the value with the given name from a JSON Object.
   *
   * Note that this function is only available for JSON Objects.
   *
   * @param aName the name of the value in the Object to return.
   * @return Item the named value from the Object.
   * @throw ZorbaException if an error occured (e.g. the Item is not of type JSON Object).
   */
  Item
  getObjectValue(String const &aName) const;

  /**
   * Checks whether the item's content is streamable.
   *
   * @return true only if it is.
   */
  bool
  isStreamable() const;

  /**
   * Checks whether the item's streamable content is arbitrarily
   * (forward and backward) seekable.
   *
   * @return true only if it is.
   */
  bool
  isSeekable() const;

  /**
   * Makes the item's streamable content arbitrarily
   * (forward and backward) seekable.
   *
   * If the item is not streamable, the function has
   * no effect.
   * If the item is streamable, but has already been
   * consumed, an error is raised.
   *
   */
  void
  ensureSeekable();

  /**
   * Gets an istream for the item's content.
   *
   * @return the stream.
   * @throw ZorbaException if the item is not streamable.
   */
  std::istream&
  getStream();

  /**
   * Returns true if the contents of a binary item is already encoded
   * 
   * @return true if the content is already encoded, false otherwise
   */
  bool
  isEncoded() const;

  /**
   * Returns the value and size of the given base64Binary item
   *
   * The value is a string which is base64 encoded if isEncoded()
   * returns true. Otherwise, it is the original unencoded binary
   * data.
   *
   * If the given item is streamable (i.e. isStreamable() returns true),
   * the stream returned by getStream() should to be used to retrieve
   * the value. Otherwise, the contents of the stream will be materialized
   * in main memory.
   */
  const char*
  getBase64BinaryValue(size_t& s) const;

  /** \brief Returns the name of the collection this node is stored in.
   *
   * @return The name of the collection or 0 if the given item is not
   *   a node or not stored in a collection.
   */
  Item
  getCollectionName() const;

  /**
   * Gets the total amount of memory this Item and all its child Items are
   * using.
   *
   * @return said total amount of memory.
   */
  size_t
  mem_size() const;

  /**
   * Returns the value and size of the given hexBinary item
   *
   * The value is a string which is hexBinary encoded if isEncoded()
   * returns true. Otherwise, it is the original unencoded binary
   * data.
   *
   * If the given item is streamable (i.e. isStreamable() returns true),
   * the stream returned by getStream() should to be used to retrieve
   * the value. Otherwise, the contents of the stream will be materialized
   * in main memory.
   */
  const char*
  getHexBinaryValue(size_t& s) const;

  /*
   * Returns a deep copy of the given item.
   * Types are preserved. Namespaces are preserved and inherited.
   *
   * Note that this function is only available for XML nodes, JSON objects and
   * arrays.
   *
   * @return  A deep copy of the XML node, JSON object or array.
   */
  Item
  copy() const;

private:
  friend class Unmarshaller;

  store::Item * m_item;
private:
  //for plan serialization
  friend void zorba::serialization::operator&(zorba::serialization::Archiver& ar, Item& obj);
};

} // namespace zorba

#endif
/* vim:set et sw=2 ts=2: */
