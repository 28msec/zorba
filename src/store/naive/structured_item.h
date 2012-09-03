/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#ifndef ZORBA_SIMPLE_STORE_STRUCTURED_ITEMS
#define ZORBA_SIMPLE_STORE_STRUCTURED_ITEMS

#include "store/api/item.h"
namespace zorba
{
namespace simplestore
{

namespace json
{
  class JSONItem;
}

class StructuredItem : public store::Item
{
public:
  StructuredItem(ItemKind k)
  : Item(k)
  {}
  virtual void attachToCollection(
      Collection* aCollection,
      const TreeId& aTreeId,
      const xs_integer& aPosition) = 0;

  virtual void detachFromCollection() = 0;

  virtual void setStructuredItemRoot(json::JSONItem* aRoot) = 0;

  virtual json::JSONItem* getStructuredItemRoot() const = 0;

  virtual long getStructuredItemRefCount() const = 0;
  
  virtual bool isInSameTree(const StructuredItem* anotherItem) const = 0;
  
};

} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_SIMPLE_STORE_NODE_ITEMS */

