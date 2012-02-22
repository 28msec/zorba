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

#include <sstream>

#include "store/api/item.h"
#include "item_vector.h"

namespace zorba { namespace simplestore {

ItemVector::ItemVector(std::vector<store::Item_t>& items) 
  :
  store::Item(LIST)
{
  size_t numItems = items.size();

  theItems.resize(numItems);

  for (size_t i = 0; i < numItems; i++)
    theItems[i].transfer(items[i]);
}


zstring ItemVector::getStringValue() const
{
  size_t numItems = theItems.size();

  if (numItems == 1)
  {
    return theItems[0]->getStringValue();
  }
  else if (numItems > 0)
  {
    zstring val;

    theItems[0]->appendStringValue(val);

    for (size_t i = 1; i < numItems; ++i)
    {
      val += " ";
      theItems[i]->appendStringValue(val);
    }

    return val;
  }

  return zstring();
}


void ItemVector::getStringValue2(zstring& val) const
{
  size_t numItems = theItems.size();

  if (numItems == 1)
  {
    theItems[0]->getStringValue2(val);
    return;
  }
  else if (numItems > 0)
  {
    theItems[0]->appendStringValue(val);

    for (size_t i = 1; i < numItems; ++i)
    {
      val += " ";
      theItems[i]->appendStringValue(val);
    }
  }
}


void ItemVector::appendStringValue(zstring& buf) const
{
  size_t numItems = theItems.size();

  if (numItems > 0)
  {
    theItems[0]->appendStringValue(buf);

    for (size_t i = 1; i < numItems; ++i)
    {
      buf += " ";
      theItems[i]->appendStringValue(buf);
    }
  }
}

zstring ItemVector::show() const
{
  std::ostringstream res;
  res << "ItemVector size: " << size() + " [";
	for ( ulong i = 0; i < size(); i++)
		res << getItem(i)->show() << ", ";
	res << "]";

  return res.str();
}

} // namespace store
} // namespace zorba
/* vim:set et sw=2 ts=2: */
