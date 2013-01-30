/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#include "structured_item.h"

#include "collection_tree_info_getters.h"

namespace zorba
{
namespace simplestore
{

const store::Collection* StructuredItem::getCollection() const
{
  simplestore::Collection* lSimpleCollection =
      CollectionTreeInfoGetters::getCollection(this);
  return static_cast<store::Collection*>(lSimpleCollection);
};

bool StructuredItem::isInSubtreeOf(const store::Item_t& anItem) const
{
  if (!anItem->isStructuredItem())
  {
    return false;
  }
  assert(static_cast<StructuredItem*>(anItem.getp()));
  StructuredItem* lStructuredItem =
    static_cast<StructuredItem*>(anItem.getp());
  return lStructuredItem->isInSubtree(this);
};


bool StructuredItem::isRoot() const
{
  return CollectionTreeInfoGetters::getRoot(this) == this;
}

} // simplestore
} // zorba