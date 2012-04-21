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
private:
  zorba::Item theItem;

public: 
  Item() {}
  Item(const Item& aItem) : theItem(aItem.theItem) {}
  Item(const zorba::Item& aZItem) : theItem(aZItem) {}

  static Item createEmptyItem();
  std::string getStringValue() const;
  std::string serialize() const;
  std::string serialize(SerializationOptions serOptions) const;
  Iterator getAtomizationValue () const;
  Iterator getAttributes () const;
  bool getBooleanValue () const;
  Iterator getChildren () const;
  Item getEBV () const;
  int getIntValue () const;
  double 	getDoubleValue () const;
  long long getLongValue () const;
  std::string getLocalName () const;
  std::string getNamespace () const;

  std::vector< std::pair< std::string, std::string > > getNamespaceBindings ();
  
  bool getNodeName (Item &aNodeName) const;
  Item 	getParent () const;
  std::string getPrefix () const;
  Item getType () const;
  unsigned int getUnsignedIntValue () const;

  int getNodeKind() const;
  bool isAtomic () const;
  bool isNaN () const;
  bool isNode () const;
  bool isNull () const;
  bool isPosOrNegInf () const;
  
  void close();
}; // class Item

#endif
