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

#include "store/util/item_vector.h"
#include "store/api/item.h"

namespace zorba
{

namespace store
{

SERIALIZABLE_CLASS_VERSIONS(ItemVector)
END_SERIALIZABLE_CLASS_VERSIONS(ItemVector)


/******************************************************************************

********************************************************************************/
std::string ItemVector::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}


/******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const ItemVector& key)
{
  ulong size = (ulong)key.theItems.size();

  os << "[";

  for (ulong i = 0; i < size; i++)
  {
    if (key.theItems[i] == NULL)
      os << "NULL";
    else
      os << key.theItems[i]->getStringValue();
  }

  os << "]";

  return os;
}


}
}
/* vim:set et sw=2 ts=2: */
