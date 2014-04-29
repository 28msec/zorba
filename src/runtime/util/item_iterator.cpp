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
#include "stdafx.h"

#include "runtime/util/item_iterator.h"
#include "store/api/item.h"

namespace zorba { 

ItemIterator::ItemIterator(const std::vector<store::Item_t>& aItems) 
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

void ItemIterator::init(const std::vector<store::Item_t>& aItems)
{
  theItems = aItems;
  reset();
}


bool
ItemIterator::next(store::Item_t& result) 
{
  if (theIterator == theItems.end()) 
  {
    result = NULL;
    return false;
  }
  else
  {
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

#ifndef NDEBUG
std::string ItemIterator::toString() const
{
  std::stringstream ss;
  ss << this << " = ItemIterator items count: " << theItems.size();
  return ss.str();
}
#endif    

} // namespace zorba
/* vim:set et sw=2 ts=2: */
