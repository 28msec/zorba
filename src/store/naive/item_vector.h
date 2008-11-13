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


class ItemVector : public store::Item
{
private:
  std::vector<store::Item_t> theItems;

public:
  ItemVector() {}

  ItemVector(std::vector<store::Item_t>& items);

  ~ItemVector() {}

  bool isNode() const   { return false; }
  bool isAtomic() const { return false; }
  bool isPul() const    { return false; }
  bool isTuple() const  { return false; }

  xqpStringStore_t getStringValue() const;

  ulong size() const { return theItems.size(); }

  bool empty() const { return theItems.empty(); }

  const std::vector<store::Item_t>& getItems() const { return theItems; }
  std::vector<store::Item_t>& getItems()             { return theItems; }
};

} // namespace store
} // namespace zorba

#endif
