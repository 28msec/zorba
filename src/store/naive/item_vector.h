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
#ifndef ZORBA_SIMPLE_STORE_ITEM_VECTOR
#define ZORBA_SIMPLE_STORE_ITEM_VECTOR

#include <vector>
#include "store/api/item.h"

namespace zorba { namespace simplestore {

/***************************************************************************//**
  ItemVector is just internal to the store and implements a list/sequence of 
  Items. It doesn't have a type assigned to it, the type is on the element
  or attribute parent node.
********************************************************************************/
class ItemVector : public store::Item
{
private:
  SYNC_CODE(mutable RCLock   theRCLock;)

  std::vector<store::Item_t> theItems;

public:
  ItemVector() : Item(LIST) {}

  ItemVector(std::vector<store::Item_t>& items);

  ~ItemVector() {}

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  ulong size() const { return (ulong)theItems.size(); }

  bool empty() const { return theItems.empty(); }

  const std::vector<store::Item_t>& getItems() const { return theItems; }

  std::vector<store::Item_t>& getItems() { return theItems; }

  store::Item* getItem(ulong pos) const { return theItems[pos].getp(); }
	
  zstring show() const;
};

} // namespace simplestore
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
