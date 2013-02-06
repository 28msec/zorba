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
#include "tree_id.h"

namespace zorba
{
namespace simplestore
{

class Collection;
class CollectionTreeInfo;


/******************************************************************************
  StructuredItem represents either an XML node or a JSON node.
*******************************************************************************/
class StructuredItem : public store::Item
{
public:
  StructuredItem(ItemKind k) : Item(k) {}

  StructuredItem() : Item() {}

  //--------------------- Item API ---------------------------------------------
  
  bool isInSubtreeOf(const store::Item_t& anItem) const;
  
  bool isCollectionRoot() const;

  //--------------------- Structured Item API ----------------------------------

  StructuredItem* getCollectionRoot() const;

  // Attaches a root node to a collection (populates collection info).
  virtual void attachToCollection(
      Collection* collection,
      const TreeId& treeId,
      const xs_integer& position) = 0;

  // Detaches a root node from a collection (populates collection info).
  virtual void detachFromCollection() = 0;
  
  // Propagates collection tree info to descendants
  // (not to be called on a root - use functions above if root).
  virtual void setCollectionTreeInfo(CollectionTreeInfo* collectionInfo) = 0;

  // Assuming the tree T this node belongs to is in a collection, return the
  // position of T within its containing collection. 
  virtual const xs_integer& getPosition() const = 0;

  // Assuming the tree T this node belongs to is in a collection, store the
  // position of T within its containing collection. The position is stored
  // inside the CollectionTreeInfo object associated with the node.
  virtual void setPosition(const xs_integer& pos) = 0;

  // Returns total number of outstanding pointers to the tree (for garbage
  // collection purposes).
  virtual long getCollectionTreeRefCount() const = 0;
  
  // Assuming the tree T this node belongs to is in a collection, get the
  // id of T (the id is unique within the containing collection).
  virtual const TreeId& getTreeId() const = 0;

  // Tells if the given item is in the subtree starting at this item.
  // NOTE: for the purposes of this method, XML trees that are pointed-to
  // by a JSON tree are considered part of that JSON tree. As a result,
  // an XML node may be in the subtree of a JSON node.
  virtual bool isInSubtree(const StructuredItem* anotherItem) const = 0;

protected:
  CollectionTreeInfo* getCollectionTreeInfo() const;
};

} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_SIMPLE_STORE_NODE_ITEMS */

