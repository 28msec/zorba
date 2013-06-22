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
#ifndef ZORBA_RUNTIME_UTIL_ITEM_ITERATOR
#define ZORBA_RUNTIME_UTIL_ITEM_ITERATOR

#include <vector>
#include "store/api/iterator.h"
#include "common/shared_types.h"

namespace zorba { 

class ItemIterator : public store::Iterator
{
private:
  std::vector<store::Item_t>           theItems;
  std::vector<store::Item_t>::iterator theIterator;

public:
  ItemIterator(const std::vector<store::Item_t>& aItems);

  ItemIterator(store::Item_t aItem);

  ItemIterator(); // construct the empty sequence

  virtual ~ItemIterator(){}

  virtual void open();
  virtual bool next(store::Item_t&);
  virtual void reset();
  virtual void close();
#ifndef NDEBUG
  // toString() debugging method.
  virtual std::string toString() const;
#endif      
};

} // namespace zorba

#endif
/* vim:set et sw=2 ts=2: */
