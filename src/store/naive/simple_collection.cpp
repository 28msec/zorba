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
    const store::Item_t& aName,
    const std::vector<store::Annotation_t>& aAnnotations,
    const store::Item_t& aNodeType,
    bool isDynamic,
    bool isJSONIQ)
  : 
  theName(aName),
  theIsDynamic(isDynamic),
  theIsJSONIQ(isJSONIQ),
  theTreeCounter(1),
  theAnnotations(aAnnotations),
  theNodeType(aNodeType)
{
  theId = GET_STORE().createCollectionId();
}


/*******************************************************************************
  Default constructor added in order to allow subclasses to instantiate a
  collection without name.
********************************************************************************/
SimpleCollection::SimpleCollection()
  : 
  theIsDynamic(false),
  theIsJSONIQ(false),
  theTreeCounter(1),
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
void SimpleCollection::addNode(store::Item* item, xs_integer position)
{
  XmlNode* node = NULL;
#ifdef ZORBA_WITH_JSON
  json::SimpleJSONArray* array = NULL;
  json::SimpleJSONObject* object = NULL;

  if (theIsJSONIQ)
  {
    if (item->isNode())
    {
      node = static_cast<XmlNode*>(item);

      if (node->getParent() != NULL)
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
        ERROR_PARAMS(getName()->getStringValue()));
      }
    }
    else if (item->isJSONObject())
    {
      object = static_cast<json::SimpleJSONObject*>(item);
    }
    else if (item->isJSONArray())
    {
      array = static_cast<json::SimpleJSONArray*>(item);
    }
    else
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }
  else
#endif
  {
    if (!item->isNode())
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }

    node = static_cast<XmlNode*>(item);

    if (node->getParent() != NULL)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }

  if (item->getCollection() != NULL)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
    ERROR_PARAMS(getName()->getStringValue(),
                 item->getCollection()->getName()->getStringValue()));
  }

  csize pos;

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE););

  if (position < xs_integer(0) ||  position >= xs_integer(theXmlTrees.size()))
  {
    pos = theXmlTrees.size();
    theXmlTrees.push_back(item);
  }
  else
  {
    pos = to_xs_unsignedInt(position);
    theXmlTrees.insert(theXmlTrees.begin() + pos, item);
  }

#ifdef ZORBA_WITH_JSON
  if (object)
    object->setCollection(this, pos);
  else if (array)
    array->setCollection(this, pos);
  else
#endif
    node->setCollection(this, pos);
}


/*******************************************************************************
  Insert the given nodes to the collection before or after the given target node.
  If any of the nodes is not a root node or is in any collection already, this
  method raises an error. The moethod returns the position occupied by the first
  new node after the insertion is done.
********************************************************************************/
ulong SimpleCollection::addNodes(
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

  csize numNodes = theXmlTrees.size();
  csize numNewNodes = items.size();
  
  for (csize i = 0; i < numNewNodes; ++i)
  {
    store::Item* item = items[i].getp();

    XmlNode* node = NULL;
#ifdef ZORBA_WITH_JSON
    json::SimpleJSONArray* array = NULL;
    json::SimpleJSONObject* object = NULL;

    if (theIsJSONIQ)
    {
      if (item->isNode())
      {
        node = static_cast<XmlNode*>(item);

        if (node->getParent() != NULL)
        {
          throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
          ERROR_PARAMS(getName()->getStringValue()));
        }
      }
      else if (item->isJSONObject())
      {
        object = static_cast<json::SimpleJSONObject*>(item);
      }
      else if (item->isJSONArray())
      {
        array = static_cast<json::SimpleJSONArray*>(item);
      }
      else
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
        ERROR_PARAMS(getName()->getStringValue()));
      }

      if (item->getCollection() != NULL)
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
        ERROR_PARAMS(getName()->getStringValue(),
                     node->getCollection()->getName()->getStringValue()));
      }

      if (object)
        object->setCollection(this, targetPos + i);
      else if (array)
        array->setCollection(this, targetPos + i);
      else
        node->setCollection(this, targetPos + i);
    }
    else
#endif
    {
      if (!item->isNode())
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
        ERROR_PARAMS(getName()->getStringValue()));
      }

      node = static_cast<XmlNode*>(item);

      if (node->getCollection() != NULL)
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
        ERROR_PARAMS(getName()->getStringValue(),
                     node->getCollection()->getName()->getStringValue()));
      }

      if (node->getParent() != NULL)
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
        ERROR_PARAMS(getName()->getStringValue()));
      }
    
      node->setCollection(this, targetPos + i);
    }
  } // for each new node

  theXmlTrees.resize(numNodes + numNewNodes);

  if (targetPos < numNodes)
  {
    memmove(&theXmlTrees[targetPos + numNewNodes], 
            &theXmlTrees[targetPos],
            (numNodes-targetPos) * sizeof(store::Item_t));
  }

  for (csize i = targetPos; i < targetPos + numNewNodes; ++i)
  {
    theXmlTrees[i].setNull();
  }

  for (csize i = 0; i < numNewNodes; ++i)
  {
    theXmlTrees[targetPos + i].transfer(items[i]);
  }

  return targetPos;
}


/*******************************************************************************
  Remove the tree rooted at the given node, if the tree actually belongs to the
  collection. If the tree was found return true and the position of the tree;
  otherwise, return false.
********************************************************************************/
bool SimpleCollection::removeNode(store::Item* item, xs_integer& position)
{
  XmlNode* node = NULL;
#ifdef ZORBA_WITH_JSON
  json::SimpleJSONArray* array = NULL;
  json::SimpleJSONObject* object = NULL;

  if (theIsJSONIQ)
  {
    if (item->isNode())
    {
      node = static_cast<XmlNode*>(item);
    }
    else if (item->isJSONObject())
    {
      object = static_cast<json::SimpleJSONObject*>(item);
    }
    else if (item->isJSONArray())
    {
      array = static_cast<json::SimpleJSONArray*>(item);
    }
    else
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }
  else
#endif
  {
    if (!item->isNode())
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }

    node = static_cast<XmlNode*>(item);
  }

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  bool found = findNode(item, position);

  if (found)
  {
    ZORBA_ASSERT(item->getCollection() == this);

#ifdef ZORBA_WITH_JSON
    if (object)
      object->setCollection(NULL, 0);
    else if (array)
      array->setCollection(NULL, 0);
    else
#endif
      node->setCollection(NULL, 0);

    csize pos = to_xs_unsignedInt(position);
    theXmlTrees.erase(theXmlTrees.begin() + pos);
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

  if (pos >= theXmlTrees.size()) 
  {
    return false;
  }
  else
  {
    store::Item* item = theXmlTrees[pos].getp();

    ZORBA_ASSERT(item->getCollection() == this);

#ifdef ZORBA_WITH_JSON
    if (theIsJSONIQ)
    {
      if (item->isNode())
      {
        XmlNode* node = static_cast<XmlNode*>(item);
        node->setCollection(NULL, 0);
      }
      else if (item->isJSONObject())
      {
        json::SimpleJSONObject* object = static_cast<json::SimpleJSONObject*>(item);
        object->setCollection(NULL, 0);
      }
      else if (item->isJSONArray())
      {
        json::SimpleJSONArray* array = static_cast<json::SimpleJSONArray*>(item);
        array->setCollection(NULL, 0);
      }
      else
      {
        ZORBA_ASSERT(false);
      }
    }
    else
#endif
    {
      assert(item->isNode());
      XmlNode* node = static_cast<XmlNode*>(item);
      node->setCollection(NULL, 0);
    }

    theXmlTrees.erase(theXmlTrees.begin() + pos);
    return true;
  }
}


/*******************************************************************************
  Remove a given number of trees starting with the tree at the given position.
  If the given number is 0 or the given position is >= than the number of trees
  in the collection, this mothod is a noop. The method returns the number of 
  trees that are actually deleted.
********************************************************************************/
xs_integer SimpleCollection::removeNodes(xs_integer position, xs_integer numNodes)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  csize pos = to_xs_unsignedInt(position);
  csize num = to_xs_unsignedInt(numNodes);

  if (num == 0 || pos >= theXmlTrees.size())
  {
    return 0;
  }
  else
  {
    uint64_t last = pos + num;
    if (last > theXmlTrees.size())
    {
      last = theXmlTrees.size();
    }

    for (csize i = pos; i < last; ++i)
    { 
      store::Item* item = theXmlTrees[pos].getp();

      ZORBA_ASSERT(item->getCollection() == this);

#ifdef ZORBA_WITH_JSON
      if (theIsJSONIQ)
      {
        if (item->isNode())
        {
          XmlNode* node = static_cast<XmlNode*>(item);
          node->setCollection(NULL, 0);
        }
        else if (item->isJSONObject())
        {
          json::SimpleJSONObject* object = static_cast<json::SimpleJSONObject*>(item);
          object->setCollection(NULL, 0);
        }
        else if (item->isJSONArray())
        {
          json::SimpleJSONArray* array = static_cast<json::SimpleJSONArray*>(item);
          array->setCollection(NULL, 0);
        }
        else
        {
          ZORBA_ASSERT(false);
        }
      }
      else
#endif
      {
        assert(item->isNode());
        XmlNode* node = static_cast<XmlNode*>(item);
        node->setCollection(NULL, 0);
      }

      theXmlTrees.erase(theXmlTrees.begin() + pos);
    }

    return last - pos;
  }
}


/*******************************************************************************
  Return the node at the given position within the collection, or NULL if the
  given position is >= than the number of nodes in the collection.
********************************************************************************/
store::Item_t SimpleCollection::nodeAt(xs_integer position)
{
  csize pos = to_xs_unsignedInt(position);
  if (pos >= theXmlTrees.size())
  {
    return NULL;
  }

  return theXmlTrees[pos];
}


/*******************************************************************************
  Check if the tree rooted at the given node belongs to this collection. If yes,
  return true and the position of the tree within the collection. Otherwise, 
  return false.
********************************************************************************/
bool SimpleCollection::findNode(const store::Item* item, xs_integer& position) const
{
  const XmlNode* node = NULL;
#ifdef ZORBA_WITH_JSON
  const json::SimpleJSONArray* array = NULL;
  const json::SimpleJSONObject* object = NULL;

  if (theIsJSONIQ)
  {
    if (item->isNode())
    {
      node = static_cast<const XmlNode*>(item);

      if (node->getParent() != NULL)
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
        ERROR_PARAMS(getName()->getStringValue()));
      }
    }
    else if (item->isJSONObject())
    {
      object = static_cast<const json::SimpleJSONObject*>(item);
    }
    else if (item->isJSONArray())
    {
      array = static_cast<const json::SimpleJSONArray*>(item);
    }
    else
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }
  else
#endif
  {
    if (!item->isNode())
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
                            ERROR_PARAMS(getName()->getStringValue()));
    }

    node = static_cast<const XmlNode*>(item);

    if (node->getParent() != NULL)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }

  if (theXmlTrees.empty())
    return false;

  if (item->getCollection() != this)
    return false;

  if (node)
  {
    position = node->getTree()->getPosition();

    csize pos = to_xs_unsignedInt(position);

    if (pos < theXmlTrees.size() &&
        theXmlTrees[pos]->isNode() &&
        BASE_NODE(theXmlTrees[pos])->getTreeId() == node->getTreeId())
    {
      return true;
    }
  }

  csize numTrees = theXmlTrees.size();

  for (csize i = 0; i < numTrees; ++i)
  {
    // check if the nodes are the same
    if (item->equals(theXmlTrees[i]))
    {
      ZORBA_ASSERT(theXmlTrees[i]->getCollection() == this);
      position = i;
      return true;
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::getAnnotations(
    std::vector<store::Annotation_t>& annotations) const
{
  annotations = theAnnotations;
}


/*******************************************************************************
  For each tree in the collection, set its current position within the collection.
********************************************************************************/
void SimpleCollection::adjustTreePositions()
{
  csize numTrees = theXmlTrees.size();

  for (csize i = 0; i < numTrees; ++i)
  {
#ifdef ZORBA_WITH_JSON
    if (theXmlTrees[i]->isNode())
      BASE_NODE(theXmlTrees[i])->getTree()->setPosition(i);
#else
    BASE_NODE(theXmlTrees[i])->getTree()->setPosition(i);
#endif
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
    csize numIndexSources = indexSources.size();

    for (csize i = 0; i < numIndexSources; ++i)
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
  theEnd = theCollection->theXmlTrees.end();
}


/*******************************************************************************

********************************************************************************/
bool SimpleCollection::CollectionIter::next(store::Item_t& result)
{
  if (!theHaveLock) 
  {
    throw ZORBA_EXCEPTION(zerr::ZXQP0001_DYNAMIC_RUNTIME_ERROR,
    ERROR_PARAMS(ZED(CollectionIteratorNotOpen)));
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
