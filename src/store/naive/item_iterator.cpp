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
#include "store/naive/item_iterator.h"

namespace zorba { namespace simplestore {

ItemIterator::ItemIterator(const std::vector<store::Item_t>& items, bool copy)
  :
  theIsOwner(copy)
{
  if (copy)
    theItems = new std::vector<store::Item_t>(items);
  else
    theItems = &items;
}


ItemIterator::ItemIterator() : theItems(NULL)
{
}


void
ItemIterator::open() 
{
  if (theItems)
    theIterator = theItems->begin();
}


bool
ItemIterator::next(store::Item_t& result) 
{
  if (theItems)
  {
    if (theIterator == theItems->end()) 
    {
      result = NULL;
      return false;
    }
    else 
    {
      result = *(theIterator);
      theIterator++;
      return true;
    }
  }
  else
  {
    result = NULL;
    return false;
  }
}


void
ItemIterator::reset() 
{
  if (theItems)
    theIterator = theItems->begin();
}


void
ItemIterator::close() 
{
  if (theItems && theIsOwner)
  {
    delete theItems;
    theItems = NULL;
  }
}

} // namespace store
} // namespace zorba
