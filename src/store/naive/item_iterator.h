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
#ifndef ZORBA_STORE_ITEM_ITERATOR_H
#define ZORBA_STORE_ITEM_ITERATOR_H

#include <vector>
#include "store/api/iterator.h"
#include "common/shared_types.h"

namespace zorba { namespace simplestore {


class ItemIterator : public store::Iterator
{
private:
  std::vector<store::Item_t>           theItems;
  std::vector<store::Item_t>::iterator theIterator;

public:
  ItemIterator(std::vector<store::Item_t> aItems);
  ItemIterator(store::Item_t aItem);
  ItemIterator(); // construct the empty sequence

  virtual ~ItemIterator(){}

  virtual void open();
  virtual bool next(store::Item_t&);
  virtual void reset();
  virtual void close();
};

} // namespace store
} // namespace zorba

#endif
