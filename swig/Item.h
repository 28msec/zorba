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

#ifndef API_ITEM_H
#define API_ITEM_H

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
class Item 
{
  friend class Iterator;
  friend class StaticContext;
  friend class DocumentManager; 
  friend class SingletonIterator;
  friend class DynamicContext;
  friend class ItemFactory;
  friend class Collection;
  friend class CollectionManager;
  friend class StaticCollectionManager;
  friend class ItemSequence;
private:
  zorba::Item theItem;

public: 
  /** \brief Default constructor
   */
  Item() {}
  /** \brief Copy constructor
   */
  Item(const Item& aItem) : theItem(aItem.theItem) {}
  /** \brief Constructor that is used to construct Items in the Zorba engine itself.
   *
   * This constructor is for internal use only.
   */
  Item(const zorba::Item& aZItem) : theItem(aZItem) {}

  /** \brief Static constructor
   */
  static Item createEmptyItem();

  /** \brief Get the string value of the Item.
   *
   * The string value is the string that is extracted by calling the fn:string function
   * on the Item (see http://www.w3.org/TR/xpath-functions/#func-string).
   * Note that this function is available for all types of Items.
   *
   * @return Item the string value of the Item.
   * @throw ZorbaException if an error occured.
   */
  std::string getStringValue() const;

  /** \brief Serializes the object
   *
   * Returns a string with the value of the object serialized
   *
   * @return The string value of the Item.
   * @throw ZorbaException if an error occured.
   */
  std::string serialize() const;

  /** \brief Serializes the object
   *
   * Returns a string with the value of the object serialized
   *
   * @param serOptions The serialization options for this Item
   * @return The string value of the Item.
   * @throw ZorbaException if an error occured.
   */
  std::string serialize(SerializationOptions serOptions) const;

  /** \brief Get the atomization value of the Item.
   *
   * The atomization value is the value that is returned by atomization 
   * (see http://www.w3.org/TR/xquery/#id-atomization).
   * Note that this function is available for all types of Items.
   *
   * @return Item the atomization value of the Item.
   * @throw ZorbaException if an error occured.
   */
  Iterator getAtomizationValue () const;

  /** \brief Get an iterator for the attributes of this (node) Item.
   *
   * Note that this function is only available for node Items.
   *
   * @return Iterator over the attributes of this node.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type node.
   */
  Iterator getAttributes () const;

  /** \brief Get the bool value of the boolean Item.
   *
   * Note that this function is only available for Items of type boolean.
   *
   * @return true if the boolean value is true, false otherwise.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type boolean.
   */
  bool getBooleanValue () const;

  /** \brief Get an iterator for the children of this (node) Item.
   *
   * Note that this function is only available for node Items.
   *
   * @return Iterator over the children of this node.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type node.
   */
  Iterator getChildren () const;

  /** \brief Get the effective boolean value of the Item.
   *
   * The effective boolean value is the result of applying the fn:boolean function on 
   * the Item (see http://www.w3.org/TR/xpath-functions/#func-boolean).
   * Note that this function is available for all types of Items.
   *
   * @return Item the effective boolean value of the Item
   * @throw ZorbaException if an error occured.
   */
  Item getEBV () const;

  /** \brief Get the int value of the Item.
   *
   * @return Item the int value of the Item.
   * @throw ZorbaException if an error occured.
   */
  int getIntValue () const;

  /** \brief Get the int value of the Item.
   *
   * @return Item the int value of the Item.
   * @throw ZorbaException if an error occured.
   */
  double 	getDoubleValue () const;

  /** \brief Get the long value of the Item.
   *
   * @return Item the long value of the Item.
   * @throw ZorbaException if an error occured.
   */
  long long getLongValue () const;

  /** \brief Get the value of a QName's local name.
   *
   * Note that this function is only available for Items of type QName.
   *
   * @return String the local name of the QName.
   * @throw ZorbaException if an error occured, e.g. the Item is not a QName.
   */
  std::string getLocalName () const;

  /** \brief Get the (optional) value of a QName's namespace.
   *
   * Note that this function is only available for Items of type QName.
   *
   * @return String the namespace URI of the QName.
   * @throw ZorbaException if an error occured, e.g. the Item is not a QName.
   */
  std::string getNamespace () const;

  /** \brief Get a vector for the namespace bindings of this (element) Item.
    *
    * Note that this function is only available for element Items.
    *
    * @throw ZorbaException if an error occured, e.g. the Item is not of type element.
    */
  std::vector< std::pair< std::string, std::string > > getNamespaceBindings ();
  
  /** \brief Get the name of this (node) Item.
   *
   * Note that this function is only available for node Items.
   *
   * @return bool if the name of the node was retrieved successfully
   * @return aNodeName the name of the node
   * @throw ZorbaException if an error occured (e.g. the Item is not of type node).
   */
  bool getNodeName (Item &aNodeName) const;

  /** \brief Get parent of this (node) Item.
   *
   * Note that this function is only available for node Items.
   *
   * @return element or document parent node of this node.
   * @throw ZorbaException if an error occured, e.g. the Item is not of type node.
   */
  Item 	getParent () const;

  /** \brief Get the (optional) value of a QName's prefix.
   *
   * Note that this function is only available for Items of type QName.
   *
   * @return String the prefix of the QName.
   * @throw ZorbaException if an error occured, e.g. the Item is not a QName.
   */
  std::string getPrefix () const;

  /** \brief Get the type of the Item.
   *
   * See http://www.w3.org/TR/xpath-datamodel/#types.
   * Note that this function is available for all types of Items.
   *
   * @return Item the type of the Item as a QName Item 
   * @throw ZorbaException if an error occured.
   */
  Item getType () const;
  unsigned int getUnsignedIntValue () const;

  /** \brief Get the type of this (node) Item.
   *
   * Note that this function is only available for node Items.
   *
   * @return int the kind of this node (the avaialble kinds can be found in the store::StoreConsts class)
   * @throw ZorbaException if an error occured (e.g. the Item is not of type node).
   */
  int getNodeKind() const;

  /** \brief Check if the Item is an atomic Item.
   *
   * Note that this function is available for all types of Items.
   *
   * @return true if the Item is an atomic Item, false otherwise.
   */
  bool isAtomic () const;

  /** \brief Check if the value of the Item is not a number (NaN).
   *
   * Note that this function is only available for numeric Items (e.g. Double or Float).
   * 
   * @return true if the Item is NaN, false otherwise.
   * @throw ZorbaException if an error occured, e.g. the Item is not a numeric type.
   */
  bool isNaN () const;

  /** \brief Check if the Item is a node Item.
   *
   * Note that this function is available for all types of Items.
   *
   * @return true if the Item is of type node, false otherwise.
   */
  bool isNode () const;

  /** \brief Check if the Item is null.
   *
   * If this function returns true, the Item is not valid.
   * Note that this function is available for all types of Items.
   *
   * @return true if the Item is null, false otherwise.
   */
  bool isNull () const;

  /** \brief Check if the value of the Item is positive or negative infinity.
   *
   * Note that this function is only available for numeric Items (e.g. Double or Float).
   * 
   * @return true if the Item is +/-INF, false otherwise.
   * @throw ZorbaException if an error occured, e.g. the Item is not a numeric type.
   */
  bool isPosOrNegInf () const;
  
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
  void close();
}; // class Item

#endif
