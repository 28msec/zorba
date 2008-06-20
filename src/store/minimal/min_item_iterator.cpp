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
#include "store/minimal/min_item_iterator.h"

namespace zorba { namespace storeminimal {

ItemIterator::ItemIterator(std::vector<store::Item_t> aItems) 
: 
theItems(aItems)
{
}

ItemIterator::ItemIterator(store::Item_t aItem) 
{
  theItems.push_back(aItem);
}

ItemIterator::ItemIterator() 
{
}

void
ItemIterator::open() 
{
  theIterator = theItems.begin();
}

bool
ItemIterator::next(store::Item_t& result) 
{
  if (theIterator == theItems.end()) {
    result = NULL;
    return false;
  } else {
    result = *(theIterator++);
    return true;
  }
}

void
ItemIterator::reset() 
{
  theIterator = theItems.begin();
}

void
ItemIterator::close() 
{
}

} // namespace storeminimal
} // namespace zorba
