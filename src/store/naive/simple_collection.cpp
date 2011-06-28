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

#include "store/naive/simple_collection.h"
#include "store/naive/simple_index.h"
#include "store/api/ic.h"
#include "store/naive/loader.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(
    store::Item_t& aName,
    uint32_t aFlags,
    const store::Item_t& aNodeType,
    bool aDynamicCollection)
  : 
  theIsDynamic(aDynamicCollection),
  theTreeCounter(1),
  theFlags(aFlags),
  theNodeType(aNodeType)
{
  theId = GET_STORE().createCollectionId();

  theName.transfer(aName);
}

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection()
  : 
  theIsDynamic(false),
  theTreeCounter(1),
  theFlags(
      Collection::coll_mutable |
      Collection::coll_ordered |
      Collection::node_mutable),
  theNodeType(NULL)
{
}

/*******************************************************************************

********************************************************************************/
SimpleCollection::~SimpleCollection()
{
}


/*******************************************************************************
  Return an iterator over the nodes of this collection.

  Note: it is allowed to have several concurrent iterators on the same collection
  but each iterator should be used by a single thread only.
********************************************************************************/
store::Iterator_t SimpleCollection::getIterator()
{
  return new CollectionIter(this);
}


/*******************************************************************************
  Insert the given node to the collection. If the node is in any collection
  already or if the node has a parent, this method raises an error. Otherwise,
  the node is inserted into the given position.
********************************************************************************/
void SimpleCollection::addNode(
    store::Item* nodeItem,
    long position)
{
  if (!nodeItem->isNode())
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
      ERROR_PARAMS( getName()->getStringValue() )
    );
  }

  XmlNode* node = static_cast<XmlNode*>(nodeItem);

  if (node->getCollection() != NULL)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
      ERROR_PARAMS(
        getName()->getStringValue(),
        node->getCollection()->getName()->getStringValue()
      )
    );
  }

  if (node->getParent() != NULL)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
      ERROR_PARAMS( getName()->getStringValue() )
    );
  }

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE););

  if (position < 0 || position >= static_cast<long>(theXmlTrees.size()))
  {
    theXmlTrees.push_back(nodeItem);
    node->setCollection(this, (ulong)theXmlTrees.size() - 1);
  }
  else
  {
    theXmlTrees.insert(theXmlTrees.begin() + position, nodeItem);
    node->setCollection(this, position);
  }
}


/*******************************************************************************
  Insert the given nodes to the collection before or after the given target node.
  If any of the nodes is not a root node or is in any collection already, this
  method raises an error. The moethod returns the position occupied by the first
  new node after the insertion is done.
********************************************************************************/
ulong SimpleCollection::addNodes(
    std::vector<store::Item_t>& nodes,
    const store::Item* targetNode,
    bool before)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  ulong targetPos;
  bool found = findNode(targetNode, targetPos);
  if (!found)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND,
      ERROR_PARAMS( theName->getStringValue() )
    );
  }

  if (!before)
    ++targetPos;

  ulong numNodes = (ulong)theXmlTrees.size();
  ulong numNewNodes = (ulong)nodes.size();
  
  for (ulong i = 0; i < numNewNodes; ++i)
  {
    if (!nodes[i]->isNode())
    {
      throw ZORBA_EXCEPTION(
        zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
        ERROR_PARAMS( getName()->getStringValue() )
      );
    }

    XmlNode* node = static_cast<XmlNode*>(nodes[i].getp());

    if (node->getCollection() != NULL)
    {
      throw ZORBA_EXCEPTION(
        zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
        ERROR_PARAMS(
          getName()->getStringValue(),
          node->getCollection()->getName()->getStringValue()
        )
      );
    }

    if (node->getParent() != NULL)
    {
      throw ZORBA_EXCEPTION(
        zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
        ERROR_PARAMS( getName()->getStringValue() )
      );
    }
    
    node->setCollection(this, targetPos + i);
  }

  theXmlTrees.resize(numNodes + numNewNodes);

#if 1
  memmove(&theXmlTrees[targetPos + numNewNodes], 
          &theXmlTrees[targetPos],
          (numNodes-targetPos) * sizeof(store::Item_t));

  for (ulong i = targetPos; i < targetPos + numNewNodes; ++i)
    theXmlTrees[i].setNull();
#else
  for (long j = numNodes-1, i = theXmlTrees.size()-1; j >= targetPos; --j, --i)
  {
    theXmlTrees[i].transfer(theXmlTrees[j]);
  }
#endif

  for (ulong i = 0; i < numNewNodes; ++i)
  {
    theXmlTrees[targetPos + i].transfer(nodes[i]);
  }

  return targetPos;
}


/*******************************************************************************
  Remove the tree rooted at the given node, if the tree actually belongs to the
  collection. If the tree was found return true and the position of the tree;
  otherwise, return false.
********************************************************************************/
bool SimpleCollection::removeNode(store::Item* nodeItem, ulong& position)
{
  if (!nodeItem->isNode())
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
      ERROR_PARAMS( getName()->getStringValue() )
    );
  }

  XmlNode* node = static_cast<XmlNode*>(nodeItem);

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  bool found = findNode(nodeItem, position);

  if (found)
  {
    ZORBA_ASSERT(node->getCollection() == this);

    node->setCollection(NULL, 0);
    theXmlTrees.erase(theXmlTrees.begin() + position);
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
bool SimpleCollection::removeNode(ulong position)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  if (position >= theXmlTrees.size())
  {
    return false;
  }
  else 
  {
    XmlNode* node = static_cast<XmlNode*>(theXmlTrees[position].getp());
    ZORBA_ASSERT(node->getCollection() == this);

    node->setCollection(NULL, 0);
    theXmlTrees.erase(theXmlTrees.begin() + position);
    return true;
  }
}


/*******************************************************************************
  Remove a given number of trees starting with the tree at the given position.
  If the given number is 0 or the given position is >= than the number of trees
  in the collection, this mothod is a noop. The method returns the number of 
  trees that are actually deleted.
********************************************************************************/
ulong SimpleCollection::removeNodes(ulong position, ulong num)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  if (num == 0 || position >= theXmlTrees.size())
  {
    return 0;
  }
  else 
  {
    ulong last = position + num;
    if (last > theXmlTrees.size())
      last = (ulong)theXmlTrees.size();

    for (ulong i = position; i < last; ++i)
    { 
      XmlNode* node = static_cast<XmlNode*>(theXmlTrees[position].getp());
      ZORBA_ASSERT(node->getCollection() == this);
      node->setCollection(NULL, 0);

      theXmlTrees.erase(theXmlTrees.begin() + position);
    }

    return last-position;
  }
}


/*******************************************************************************
  Return the node at the given position within the collection, or NULL if the
  given position is >= than the number of nodes in the collection.
********************************************************************************/
store::Item_t SimpleCollection::nodeAt(ulong position)
{
  if(position >= theXmlTrees.size())
  {
    return NULL;
  }

  return theXmlTrees[position];
}


/*******************************************************************************
  Check if the tree rooted at the given node belongs to this collection. If yes,
  return true and the position of the tree within the collection. Otherwise, 
  return false.
********************************************************************************/
bool SimpleCollection::findNode(const store::Item* node, ulong& position) const
{
  if (!node->isNode())
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
      ERROR_PARAMS( getName()->getStringValue() )
    );
  }

  if( theXmlTrees.empty() )
    return false;

  if (node->getCollection() != this)
    return false;

  const XmlNode* n = static_cast<const XmlNode*>(node);

  position = n->getTree()->getPosition();

  if (position < theXmlTrees.size() &&
      BASE_NODE(theXmlTrees[position])->getTreeId() == n->getTreeId())
  {
    return true;
  }

  ulong numTrees = (ulong)theXmlTrees.size();

  for (ulong i = 0; i < numTrees; ++i)
  {
    // check if the nodes are the same
    if (node->equals(theXmlTrees[i]))
    {
      ZORBA_ASSERT(BASE_NODE(theXmlTrees[i])->getCollection() == this);
      position = i;
      return true;
    }
  }

  return false;
}


/*******************************************************************************
  For each tree in the collection, set its current position within the collection.
********************************************************************************/
void SimpleCollection::adjustTreePositions()
{
  ulong numTrees = (ulong)theXmlTrees.size();

  for (ulong i = 0; i < numTrees; ++i)
  {
    BASE_NODE(theXmlTrees[i])->getTree()->setPosition(i);
  }
}



/*******************************************************************************

********************************************************************************/
void SimpleCollection::getIndexes(std::vector<store::Index*>& indexes)
{
  const IndexSet& availableIndexes = GET_STORE().getIndices();

  IndexSet::iterator idxIte = availableIndexes.begin();
  IndexSet::iterator idxEnd = availableIndexes.end();

  for (; idxIte != idxEnd; ++idxIte)
  {
    IndexImpl* index = static_cast<IndexImpl*>((*idxIte).second.getp());
    const store::IndexSpecification& indexSpec = index->getSpecification();

    const std::vector<store::Item_t>& indexSources = indexSpec.theSources;
    ulong numIndexSources = (ulong)indexSources.size();

    for (ulong i = 0; i < numIndexSources; ++i)
    {
      if (indexSources[i]->equals(getName()))
      {
        indexes.push_back(index);
        break;
      }
    }
  }
}

/*******************************************************************************

*******************************************************************************/
void SimpleCollection::getActiveICs(std::vector<store::IC*>& ics)
{
  store::Iterator_t activeICNames = GET_STORE().listActiveICNames();

  store::Item_t activeICName;
  activeICNames->open();

  while ( activeICNames->next(activeICName) )
  {

    store::IC* activeIC = GET_STORE().getIC(activeICName);

    switch( activeIC->getICKind() )
    {
    case store::IC::ic_collection:
      if ( activeIC->getCollectionName()->equals(getName()) )
        ics.push_back(activeIC);
      break;

    case store::IC::ic_foreignkey:
      if ( activeIC->getToCollectionName()->equals(getName()) )
        ics.push_back(activeIC);

      if ( activeIC->getFromCollectionName()->equals(getName()) )
        ics.push_back(activeIC);
      break;

    default:
      ZORBA_ASSERT(false);
    }
  }

  activeICNames->close();
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::CollectionIter::CollectionIter(
    SimpleCollection* collection)
  :
  theCollection(collection),
  theHaveLock(false)
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
void SimpleCollection::CollectionIter::open()
{
  SYNC_CODE(theCollection->theLatch.rlock();)
  theHaveLock = true;

  theIterator = theCollection->theXmlTrees.begin();
}


/*******************************************************************************

********************************************************************************/
bool SimpleCollection::CollectionIter::next(store::Item_t& result)
{
  if (!theHaveLock) 
  {
    throw ZORBA_EXCEPTION(
      zerr::ZXQP0001_DYNAMIC_RUNTIME_ERROR,
      ERROR_PARAMS( ZED( CollectionIteratorNotOpen ) )
    );
  }

  if (theIterator == theCollection->theXmlTrees.end()) 
  {
    result = NULL;
    return false;
  }

  result = (*theIterator).getp();
  ++theIterator;

  return true;
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::reset()
{
  theIterator = theCollection->theXmlTrees.begin();
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
