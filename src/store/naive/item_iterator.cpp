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
#include "store/api/item.h"
#include "store/api/item_iterator.h"

namespace zorba { namespace store {

ItemIterator::ItemIterator(std::vector<Item_t> aItems) 
: theItems(aItems)
{}

ItemIterator::ItemIterator(Item_t aItem) 
{
  theItems.push_back(aItem);
}

ItemIterator::ItemIterator() {}

void
ItemIterator::open() 
{
  theIterator = theItems.begin();
}

Item_t
ItemIterator::next() 
{
  if (theIterator == theItems.end()) {
    return 0;
  } else {
    return *(theIterator++);
  }
}

void
ItemIterator::reset() 
{
  theIterator = theItems.begin();
}

void
ItemIterator::close() 
{}

} // namespace store
} // namespace zorba
