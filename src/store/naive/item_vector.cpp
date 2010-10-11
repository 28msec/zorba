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

  if (numItems > 0)
  {
    ostr << theItems[0]->getStringValue()->c_str();

    for (ulong i = 1; i < numItems; ++i)
    {
      ostr << " " << theItems[i]->getStringValue()->c_str();
    }
  }

  return new xqpStringStore(ostr.str());
}


void ItemVector::getStringValue(xqpStringStore_t& strval) const
{
  strval = new xqpStringStore("");
  getStringValue(strval->str());
}


void ItemVector::getStringValue(std::string& buf) const
{
  ulong numItems = theItems.size();

  if (numItems > 0)
  {
    theItems[0]->getStringValue(buf);

    for (ulong i = 1; i < numItems; i++)
    {
      buf += " ";
      theItems[i]->getStringValue(buf);
    }
  }
}

xqp_string ItemVector::show() const
{
	std::string res = "ItemVector size:";
	res += size() + " [";
	for ( ulong i=0; i<size(); i++)
		res += getItem(i)->show() + ", ";
	return res + "]"; 
}


} // namespace store
} // namespace zorba
