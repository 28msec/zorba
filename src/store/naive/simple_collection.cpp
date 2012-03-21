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
#include "zorbatypes/numconversions.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(
    const store::Item_t& aName,
    const std::vector<store::Annotation_t>& aAnnotations,
    const store::Item_t& aNodeType,
    bool aDynamicCollection)
  : 
  theName(aName),
  theIsDynamic(aDynamicCollection),
  theAnnotations(aAnnotations),
  theNodeType(aNodeType)
{
  theId = GET_STORE().createCollectionId();
  theTreeIdGenerator = GET_STORE().getTreeIdGeneratorFactory().createTreeGenerator();
}

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection()
  : 
  theIsDynamic(false),
  theNodeType(NULL)
{
  theTreeIdGenerator = GET_STORE().getTreeIdGeneratorFactory().createTreeGenerator();
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
    xs_integer position)
{
  xs_long lPosition = to_xs_long(position);

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

  if (lPosition < 0 || to_xs_unsignedLong(lPosition) >= theXmlTrees.size())
  {
    theXmlTrees.push_back(nodeItem);
    node->setCollection(this, (uint64_t)theXmlTrees.size() - 1);
  }
  else
  {

    theXmlTrees.insert(theXmlTrees.begin() + (std::size_t)lPosition, nodeItem);
    node->setCollection(this, to_xs_unsignedInt(lPosition));
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

  xs_integer targetPos;
  bool found = findNode(targetNode, targetPos);

  if (!found)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND,
      ERROR_PARAMS( theName->getStringValue() )
    );
  }

  std::size_t lTargetPos = to_xs_unsignedInt(targetPos);

  if (!before)
  {
    ++lTargetPos;
  }

  std::size_t numNodes = theXmlTrees.size();
  std::size_t numNewNodes = nodes.size();
  
  for (std::size_t i = 0; i < numNewNodes; ++i)
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
    
    node->setCollection(this, lTargetPos + i);
  }

  theXmlTrees.resize(numNodes + numNewNodes);

#if 1
  if (lTargetPos < numNodes)
  {
    memmove(&theXmlTrees[lTargetPos + numNewNodes], 
            &theXmlTrees[lTargetPos],
            (numNodes-lTargetPos) * sizeof(store::Item_t));
  }

  for (std::size_t i = lTargetPos; i < lTargetPos + numNewNodes; ++i)
  {
    theXmlTrees[i].setNull();
  }
#else
  for (long j = numNodes-1, i = theXmlTrees.size()-1; j >= lTargetPos; --j, --i)
  {
    theXmlTrees[i].transfer(theXmlTrees[j]);
  }
#endif

  for (std::size_t i = 0; i < numNewNodes; ++i)
  {
    theXmlTrees[lTargetPos + i].transfer(nodes[i]);
  }

  return lTargetPos;
}


/*******************************************************************************
  Remove the tree rooted at the given node, if the tree actually belongs to the
  collection. If the tree was found return true and the position of the tree;
  otherwise, return false.
********************************************************************************/
bool SimpleCollection::removeNode(store::Item* nodeItem, xs_integer& position)
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
    std::size_t lPosition = to_xs_unsignedInt(position);
    theXmlTrees.erase(theXmlTrees.begin() + lPosition);
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

  std::size_t lPosition = to_xs_unsignedInt(position);

  if (lPosition >= theXmlTrees.size()) {
    return false;
  }
  else
  {
    XmlNode* node = static_cast<XmlNode*>(theXmlTrees[lPosition].getp());
    ZORBA_ASSERT(node->getCollection() == this);

    node->setCollection(NULL, 0);
    theXmlTrees.erase(theXmlTrees.begin() + lPosition);
    return true;
  }
}


/*******************************************************************************
  Remove a given number of trees starting with the tree at the given position.
  If the given number is 0 or the given position is >= than the number of trees
  in the collection, this mothod is a noop. The method returns the number of 
  trees that are actually deleted.
********************************************************************************/
xs_integer SimpleCollection::removeNodes(xs_integer position, xs_integer num)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  std::size_t lPosition = to_xs_unsignedInt(position);
  std::size_t lNum = to_xs_unsignedInt(num);

  if (lNum == 0 || lPosition >= theXmlTrees.size())
  {
    return 0;
  }
  else
  {
    uint64_t last = lPosition + lNum;
    if (last > theXmlTrees.size())
    {
      last = theXmlTrees.size();
    }

    for (std::size_t i = lPosition; i < last; ++i)
    { 
      XmlNode* node = static_cast<XmlNode*>(theXmlTrees[lPosition].getp());
      ZORBA_ASSERT(node->getCollection() == this);
      node->setCollection(NULL, 0);

      theXmlTrees.erase(theXmlTrees.begin() + lPosition);
    }

    return last-lPosition;
  }
}


/*******************************************************************************
  Return the node at the given position within the collection, or NULL if the
  given position is >= than the number of nodes in the collection.
********************************************************************************/
store::Item_t SimpleCollection::nodeAt(xs_integer position)
{
  std::size_t lPosition = to_xs_unsignedInt(position);
  if (lPosition >= theXmlTrees.size())
  {
    return NULL;
  }

  return theXmlTrees[lPosition];
}


/*******************************************************************************
  Check if the tree rooted at the given node belongs to this collection. If yes,
  return true and the position of the tree within the collection. Otherwise, 
  return false.
********************************************************************************/
bool SimpleCollection::findNode(const store::Item* node, xs_integer& position) const
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

  std::size_t lPosition = to_xs_unsignedInt(position);

  if (lPosition < theXmlTrees.size() &&
      BASE_NODE(theXmlTrees[lPosition])->getTreeId() == n->getTreeId())
  {
    return true;
  }

  std::size_t numTrees = theXmlTrees.size();

  for (std::size_t i = 0; i < numTrees; ++i)
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
********************************************************************************/
void SimpleCollection::getAnnotations(
    std::vector<store::Annotation_t>& annotations
) const
{
  annotations = theAnnotations;
}

/*******************************************************************************
  For each tree in the collection, set its current position within the collection.
********************************************************************************/
void SimpleCollection::adjustTreePositions()
{
  std::size_t numTrees = (uint64_t)theXmlTrees.size();

  for (std::size_t i = 0; i < numTrees; ++i)
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
    uint64_t numIndexSources = (uint64_t)indexSources.size();

    for (std::size_t i = 0; i < numIndexSources; ++i)
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
TreeId SimpleCollection::createTreeId()
{
  return theTreeIdGenerator->create();
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
  theEnd = theCollection->theXmlTrees.end();
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
  theIterator = theCollection->theXmlTrees.begin();
  theEnd = theCollection->theXmlTrees.end();
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
