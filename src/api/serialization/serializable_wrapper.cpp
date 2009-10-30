/*
 * Copyright 2006-2009 The FLWOR Foundation.
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

#include <zorba/item.h>
#include <zorba/serializable.h>

#include "api/serialization/serializable_wrapper.h"

#include "api/unmarshaller.h"
#include "store/api/item.h"

namespace zorba { namespace intern {


SerializableWrapper::SerializableWrapper(zorba::Serializable* aObject)
  : theApiSerializable(aObject)
{
}

bool
SerializableWrapper::nextSerializableItem(store::Item_t& aItem)
{
  Item lItem;
  if (!theApiSerializable->nextSerializableItem(lItem)) {
    return false;
  }

  aItem = Unmarshaller::getInternalItem(lItem);
  return true;
}


} // namespace intern

} // namespace zorba
