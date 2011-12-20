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
#ifndef ZORBA_STORE_UTIL_ITEM_VECTOR
#define ZORBA_STORE_UTIL_ITEM_VECTOR

#include "store/api/shared_types.h"
#include "zorbaserialization/template_serializer.h"


namespace zorba { namespace store {


/***************************************************************************//**

********************************************************************************/
class ItemVector : public zorba::serialization::SerializeBaseClass
{
public:
  typedef std::vector<Item_t>::const_iterator const_iterator;
  typedef std::vector<Item_t>::iterator iterator;

public:
  std::vector<Item_t> theItems;

public:
  SERIALIZABLE_CLASS(ItemVector)
  SERIALIZABLE_CLASS_CONSTRUCTOR(ItemVector);
  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & theItems;
  }
public:
  ItemVector(ulong size = 0) : theItems(size) {}

  bool empty() const { return theItems.empty(); }

  ulong size() const { return (ulong)theItems.size(); }

  void resize(ulong newSize) { theItems.resize(newSize); }

  void clear() { theItems.clear(); }

  const Item_t& operator[](ulong i) const { return theItems[i]; }

  Item_t& operator[](ulong i) { return theItems[i]; }

  void push_back(const Item_t& item) { theItems.push_back(item); }

  void transfer_back(Item_t& item) 
  {
    ulong size_ = size();
    theItems.resize(size_+1);
    theItems[size_].transfer(item);
  }

  iterator begin() { return theItems.begin(); }
  iterator end()   { return theItems.end(); }

  const_iterator begin() const { return theItems.begin(); }
  const_iterator end() const   { return theItems.end(); }

  std::string toString() const;
};


std::ostream& operator<<(std::ostream& os, const ItemVector& key);

}
}
#endif
/* vim:set et sw=2 ts=2: */
