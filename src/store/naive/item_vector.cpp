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

#include <sstream>

#include "store/api/item.h"
#include "store/naive/item_vector.h"

namespace zorba { namespace simplestore {

ItemVector::ItemVector(std::vector<store::Item_t>& items)
{
  ulong numItems = items.size();

  theItems.resize(numItems);

  for (ulong i = 0; i < numItems; i++)
    theItems[i].transfer(items[i]);
}


xqpStringStore_t ItemVector::getStringValue() const
{
  std::ostringstream ostr;
  ulong numItems = theItems.size();

  for (ulong i = 0; i < numItems; i++)
  {
    ostr << theItems[i]->getStringValue()->c_str() << " ";
  }

  ostr << std::endl;

  return new xqpStringStore(ostr.str());
}

} // namespace store
} // namespace zorba
