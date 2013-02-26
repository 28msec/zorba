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
#include "collection_tree_info.h"
#include "collection.h"
#include "node_items.h"
#include "json_items.h"


namespace zorba
{
namespace simplestore
{


/*******************************************************************************
  Get the id of the tree this node belongs to
********************************************************************************/
const TreeId& StructuredItem::getTreeId() const
{
  if (isNode())
  {
    const XmlNode* node = static_cast<const XmlNode*>(this);
    return node->getTree()->getTreeId();
  }
  else
  {
    assert(isJSONItem());

    const json::JSONItem* node = static_cast<const json::JSONItem*>(this);

    CollectionTreeInfoWithTreeId* info = 
    static_cast<CollectionTreeInfoWithTreeId*>(node->getCollectionTreeInfo());

    ZORBA_ASSERT(info);

    return info->getTreeId();
  }
}


/*******************************************************************************

********************************************************************************/
CollectionTreeInfo* StructuredItem::getCollectionTreeInfo() const
{
  if (isNode())
  {
    const XmlNode* node = static_cast<const XmlNode*>(this);
    return node->getTree()->getCollectionTreeInfo();
  }
  else
  {
    assert(isJSONItem());
    const json::JSONItem* node = static_cast<const json::JSONItem*>(this);
    return node->getCollectionTreeInfo();
  }
}


/*******************************************************************************
  Let T be the tree containing this node. If T belongs to a collection directly,
  return the root node of T. If T belongs to a collection indirectly, return the
  root node of the (JSON) tree that points to T and belongs to the collection
  directly. If T does not belong to any collection, return NULL.
********************************************************************************/
StructuredItem* StructuredItem::getCollectionRoot() const
{
  CollectionTreeInfo* info = getCollectionTreeInfo();
  return info ? info->getRoot() : NULL;
}


/*******************************************************************************
  Assuming the tree T this node belongs to is in a collection, return the
  position of T within its containing collection. 
********************************************************************************/
const xs_integer& StructuredItem::getPosition() const
{
  CollectionTreeInfo* info = getCollectionTreeInfo();
  ZORBA_ASSERT(info);
  return info->getPosition();
}


/*******************************************************************************
  Assuming the tree T this node belongs to is in a collection, store the
  position of T within its containing collection. The position is stored
  inside the CollectionTreeInfo object associated with the node.
********************************************************************************/
void StructuredItem::setPosition(const xs_integer& pos)
{
  CollectionTreeInfo* info = getCollectionTreeInfo();
  ZORBA_ASSERT(info);
  info->setPosition(pos);
}


/*******************************************************************************
  Return true if this node is the root node of a tree that belongs to a
  a collection directly.
********************************************************************************/
bool StructuredItem::isCollectionRoot() const
{
  return getCollectionRoot() == this;
}


/*******************************************************************************
  Return true if this node is in the subtree starting at the given item.

  NOTE: for the purposes of this method, XML trees that are pointed-to by a
  JSON tree are considered part of that JSON tree. As a result, an XML node
  may be in the subtree of a JSON node.
********************************************************************************/
bool StructuredItem::isInSubtreeOf(const store::Item_t& anItem) const
{
  if (!anItem->isStructuredItem())
  {
    return false;
  }

  StructuredItem* structuredItem = static_cast<StructuredItem*>(anItem.getp());

  return structuredItem->isInSubtree(this);
};


} // simplestore
} // zorba
