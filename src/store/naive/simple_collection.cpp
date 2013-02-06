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

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "simple_collection.h"
#include "simple_index.h"
#include "store/api/ic.h"
#include "store/api/annotation.h"
#include "loader.h"
#include "simple_store.h"
#include "store_defs.h"
#include "node_items.h"
#ifdef ZORBA_WITH_JSON
#  include "json_items.h"
#endif

#include "zorbatypes/numconversions.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(
    const store::Item_t& name,
    const std::vector<store::Annotation_t>& annotations,
    bool isDynamic)
  : 
  Collection(name),
  theIsDynamic(isDynamic),
  theAnnotations(annotations)
{
  theId = GET_STORE().createCollectionId();
  theTreeIdGenerator = GET_STORE().getTreeIdGeneratorFactory().createTreeGenerator(0);
}


/*******************************************************************************
  Default constructor added in order to allow subclasses to instantiate a
  collection without name.
********************************************************************************/
SimpleCollection::SimpleCollection()
  : 
  theIsDynamic(false)
{
  theTreeIdGenerator = GET_STORE().getTreeIdGeneratorFactory().createTreeGenerator(0);
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::~SimpleCollection()
{
  delete theTreeIdGenerator;
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::getAnnotations(
    std::vector<store::Annotation_t>& annotations) const
{
  annotations = theAnnotations;
}


/*******************************************************************************
  Return an iterator over the nodes of this collection.

  Note: it is allowed to have several concurrent iterators on the same collection
  but each iterator should be used by a single thread only.
********************************************************************************/
store::Iterator_t SimpleCollection::getIterator(
    const xs_integer& skip,
    const zstring& startRef)
{
  store::Item_t startNode;
  xs_integer startPos = xs_integer::zero();

  if (startRef.size() != 0 &&
      (!GET_STORE().getNodeByReference(startNode, startRef) ||
       !findNode(startNode.getp(), startPos)))
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0066_REFERENCED_NODE_NOT_IN_COLLECTION,
    ERROR_PARAMS(startRef, theName->getStringValue()));
  }

  return new CollectionIter(this, skip + startPos);
}


/*******************************************************************************
  Check if the tree rooted at the given node belongs to this collection. If yes,
  return true and the position of the tree within the collection. Otherwise, 
  return false.
********************************************************************************/
bool SimpleCollection::findNode(const store::Item* item, xs_integer& position) const
{
  if (!(item->isStructuredItem()))
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
    ERROR_PARAMS(getName()->getStringValue()));
  }

  const StructuredItem* structuredItem = static_cast<const StructuredItem*>(item);
  
  if (structuredItem->isNode())
  {
    const XmlNode* node = static_cast<const XmlNode*>(item);
    if (node->getTree()->getRoot() != node)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }

  if (theTrees.empty())
    return false;

  if (item->getCollection() != this)
    return false;

  position = structuredItem->getPosition();

  csize pos = to_xs_unsignedInt(position);

  StructuredItem* collectionItem = 
  static_cast<StructuredItem*>(theTrees[pos].getp());

  if (pos < theTrees.size() &&
      collectionItem->getTreeId() == structuredItem->getTreeId())
  {
    return true;
  }

  csize numTrees = theTrees.size();

  for (csize i = 0; i < numTrees; ++i)
  {
    // check if the nodes are the same
    if (item->equals(theTrees[i]))
    {
      ZORBA_ASSERT(theTrees[i]->getCollection() == this);
      position = i;
      return true;
    }
  }

  return false;
}


/*******************************************************************************
  Return the node at the given position within the collection, or NULL if the
  given position is >= than the number of nodes in the collection.
********************************************************************************/
store::Item_t SimpleCollection::nodeAt(xs_integer position)
{
  csize pos = to_xs_unsignedInt(position);
  if (pos >= theTrees.size())
  {
    return NULL;
  }

  return theTrees[pos];
}


/*******************************************************************************

********************************************************************************/
TreeId SimpleCollection::createTreeId()
{
  return theTreeIdGenerator->create();
}


/*******************************************************************************
  Insert the given node to the collection. If the node is in any collection
  already or if the node is an xml node with a parent, this method raises an
  error. Otherwise, the node is inserted into the given position.
********************************************************************************/
void SimpleCollection::addNode(store::Item* item, xs_integer position)
{
  if (!(item->isStructuredItem()))
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
    ERROR_PARAMS(getName()->getStringValue()));
  }

  if (item->getCollection() != NULL)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
    ERROR_PARAMS(getName()->getStringValue(),
                 item->getCollection()->getName()->getStringValue()));
  }

  StructuredItem* structuredItem = static_cast<StructuredItem*>(item);
  
  if (structuredItem->isNode())
  {
    XmlNode* node = static_cast<XmlNode*>(item);
    if (node->getRoot() != node)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }

  xs_long pos = to_xs_long(position);

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE););

  if (pos < 0 || to_xs_unsignedLong(position) >= theTrees.size())
  {
    theTrees.push_back(item);

    structuredItem->attachToCollection(this,
                                       createTreeId(),
                                       xs_integer(theTrees.size()));
  }
  else
  {
    theTrees.insert(theTrees.begin() + pos, item);

    structuredItem->attachToCollection(this, createTreeId(), position);
  }
}


/*******************************************************************************
  Insert the given nodes to the collection before or after the given target node.
  If any of the nodes is a non root xml node or is in any collection already,
  this method raises an error. The moethod returns the position occupied by the
  first new node after the insertion is done.
********************************************************************************/
xs_integer SimpleCollection::addNodes(
    std::vector<store::Item_t>& items,
    const store::Item* targetNode,
    bool before)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  xs_integer pos;
  bool found = findNode(targetNode, pos);

  if (!found)
  {
    throw ZORBA_EXCEPTION(zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND,
    ERROR_PARAMS(theName->getStringValue()));
  }

  csize targetPos = to_xs_unsignedInt(pos);

  if (!before)
  {
    ++targetPos;
  }

  csize numNodes = theTrees.size();
  csize numNewNodes = items.size();
  
  for (csize i = 0; i < numNewNodes; ++i)
  {
    store::Item* item = items[i].getp();

    if (!(item->isStructuredItem()))
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
      ERROR_PARAMS(getName()->getStringValue()));
    }

    if (item->getCollection() != NULL)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
      ERROR_PARAMS(getName()->getStringValue(),
                   item->getCollection()->getName()->getStringValue()));
    }

    StructuredItem* structuredItem = static_cast<StructuredItem*>(item);
  
    if (structuredItem->isNode())
    {
      XmlNode* node = static_cast<XmlNode*>(item);

      if (node->getRoot() != node)
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
        ERROR_PARAMS(getName()->getStringValue()));
      }
    }

    pos = targetPos + i;

    structuredItem->attachToCollection(this, createTreeId(), pos);
  } // for each new node

  theTrees.resize(numNodes + numNewNodes);

  if (targetPos < numNodes)
  {
    memmove(&theTrees[targetPos + numNewNodes], 
            &theTrees[targetPos],
            (numNodes-targetPos) * sizeof(store::Item_t));
  }

  for (csize i = targetPos; i < targetPos + numNewNodes; ++i)
  {
    theTrees[i].setNull();
  }

  for (csize i = 0; i < numNewNodes; ++i)
  {
    theTrees[targetPos + i].transfer(items[i]);
  }

  return xs_integer(targetPos);
}


/*******************************************************************************
  Remove the tree rooted at the given node, if the tree actually belongs to the
  collection. If the tree was found return true and the position of the tree;
  otherwise, return false.
********************************************************************************/
bool SimpleCollection::removeNode(store::Item* item, xs_integer& position)
{
  if (!(item->isStructuredItem()))
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
    ERROR_PARAMS(getName()->getStringValue()));
  }

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  bool found = findNode(item, position);

  if (found)
  {
    ZORBA_ASSERT(item->getCollection() == this);

    StructuredItem* structuredItem = static_cast<StructuredItem*>(item);

    structuredItem->detachFromCollection();

    csize pos = to_xs_unsignedInt(position);
    theTrees.erase(theTrees.begin() + pos);
    return true;
  }
  else
  {
    return false;
  }
}


/*******************************************************************************
  Remove the tree at the given position. If the position is >= than the number
  of trees in the collection, this mothod is a noop. The method returns true if
  a tree is actually deleted, otherwise it returns false.
********************************************************************************/
bool SimpleCollection::removeNode(xs_integer position)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  std::size_t pos = to_xs_unsignedInt(position);

  if (pos >= theTrees.size()) 
  {
    return false;
  }
  else
  {
    store::Item* item = theTrees[pos].getp();

    ZORBA_ASSERT(item->getCollection() == this);
    ZORBA_ASSERT(item->isStructuredItem());

    StructuredItem* structuredItem = static_cast<StructuredItem*>(item);
    structuredItem->detachFromCollection();

    theTrees.erase(theTrees.begin() + pos);
    return true;
  }
}


/*******************************************************************************
  Remove a given number of trees starting with the tree at the given position.
  If the given number is 0 or the given position is >= than the number of trees
  in the collection, this method is a noop. The method returns the number of 
  trees that are actually deleted.
********************************************************************************/
xs_integer SimpleCollection::removeNodes(xs_integer position, xs_integer numNodes)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  csize pos = to_xs_unsignedInt(position);
  csize num = to_xs_unsignedInt(numNodes);

  if (num == 0 || pos >= theTrees.size())
  {
    return xs_integer::zero();
  }
  else
  {
    csize last = pos + num;

    if (last > theTrees.size())
    {
      last = theTrees.size();
    }

    for (csize i = pos; i < last; ++i)
    {
      store::Item* item = theTrees[pos].getp();

      ZORBA_ASSERT(item->getCollection() == this);
      ZORBA_ASSERT(item->isStructuredItem());

      StructuredItem* structuredItem = static_cast<StructuredItem*>(item);
      structuredItem->detachFromCollection();

      theTrees.erase(theTrees.begin() + pos);
    }

    return xs_integer(last - pos);
  }
}


/*******************************************************************************
  Remove all the nodes from the collection
********************************************************************************/
void SimpleCollection::removeAll()
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  csize numTrees = theTrees.size();

  for (csize i = 0; i < numTrees; ++i)
  {
    store::Item* item = theTrees[i].getp();

    ZORBA_ASSERT(item->getCollection() == this);
    ZORBA_ASSERT(item->isStructuredItem());

    StructuredItem* structuredItem = static_cast<StructuredItem*>(item);
    structuredItem->detachFromCollection();
  }

  theTrees.clear();
}


/*******************************************************************************
  For each tree in the collection, set its current position within the collection.
********************************************************************************/
void SimpleCollection::adjustTreePositions()
{
  csize numTrees = theTrees.size();

  for (csize i = 0; i < numTrees; ++i)
  {
    static_cast<StructuredItem*>(theTrees[i].getp())->setPosition(xs_integer(i));
  }
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::CollectionIter::CollectionIter(
    SimpleCollection* collection,
    const xs_integer& skip)
  :
  theCollection(collection),
  theHaveLock(false),
  theSkip(to_xs_unsignedLong(skip))
{
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::CollectionIter::~CollectionIter() 
{
  SYNC_CODE(if (theHaveLock) \
    theCollection->theLatch.unlock();)
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::skip()
{
  // skip by position
  if (theSkip >= theCollection->size())
  {
    // we need to skip more then possible -> jump to the end
    theIterator = theEnd;
  }
  else
  {
    theIterator += theSkip;
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::open()
{
  SYNC_CODE(theCollection->theLatch.rlock();)
  theHaveLock = true;

  theIterator = theCollection->theTrees.begin();
  theEnd = theCollection->theTrees.end();
  skip();
}


/*******************************************************************************

********************************************************************************/
bool SimpleCollection::CollectionIter::next(store::Item_t& result)
{
  if (!theHaveLock) 
  {
    throw ZORBA_EXCEPTION(zerr::ZDDY0019_COLLECTION_ITERATOR_NOT_OPEN,
    ERROR_PARAMS(theCollection->getName()->getStringValue()));
  }

  if (theIterator == theEnd) 
  {
    result = NULL;
    return false;
  }

  result = *theIterator;
  ++theIterator;

  return true;
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::reset()
{
  theIterator = theCollection->theTrees.begin();
  theEnd = theCollection->theTrees.end();
  skip();
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::close() 
{
  assert(theHaveLock);
  theHaveLock = false;
  SYNC_CODE(theCollection->theLatch.unlock();)
}

} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
