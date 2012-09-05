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

#include "collection_tree_info.h"

namespace zorba
{
namespace simplestore
{

class Collection;

class StructuredItem : public store::Item
{
public:
  StructuredItem(ItemKind k)
  : Item(k)
  {}
  StructuredItem()
  : Item()
  {}
  
  // Attaches a root to a collection (populates collection info).
  virtual void attachToCollection(
      simplestore::Collection* aCollection,
      const TreeId& aTreeId,
      const xs_integer& aPosition) = 0;

  // Detaches a root from a collection (populates collection info).
  virtual void detachFromCollection() = 0;
  
  // Propagates collection tree info to descendants
  // (not to be called on a root - use functions above if root).
  virtual void setCollectionTreeInfo(CollectionTreeInfo* lTreeInfo) = 0;

  // Accesses collection tree info for any structured item in a tree.
  virtual CollectionTreeInfo* getCollectionTreeInfo() const = 0;

  // Returns total number of outstanding pointers to the tree (for garbage
  // collection purposes).
  virtual long getCollectionTreeRefCount() const = 0;
  
  // Tells if supplied item is in the subtree starting at this item.
  virtual bool isInSubTree(const StructuredItem* anotherItem) const = 0;
  
};

} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_SIMPLE_STORE_NODE_ITEMS */

