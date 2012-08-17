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
    bool isDynamic)
  : 
  theName(aName),
  theIsDynamic(isDynamic),
  theAnnotations(aAnnotations),
  theNodeType(aNodeType)
{
  theId = GET_STORE().createCollectionId();
  theTreeIdGenerator = GET_STORE().getTreeIdGeneratorFactory().createTreeGenerator();
}


/*******************************************************************************
  Default constructor added in order to allow subclasses to instantiate a
  collection without name.
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
  delete theTreeIdGenerator;
}


/*******************************************************************************
  Return an iterator over the nodes of this collection.

  Note: it is allowed to have several concurrent iterators on the same collection
  but each iterator should be used by a single thread only.
********************************************************************************/
store::Iterator_t SimpleCollection::getIterator(const xs_integer& aSkip,
                                                const zstring& aStart)
{
  store::Item_t lReferencedNode;
  xs_integer lReferencedPosition = xs_integer::zero();
  if (aStart.size() != 0
   && (!GET_STORE().getNodeByReference(lReferencedNode, aStart)
    || !findNode(lReferencedNode.getp(), lReferencedPosition)))
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0066_REFERENCED_NODE_NOT_IN_COLLECTION,
    ERROR_PARAMS(aStart, theName->getStringValue()));
  }

  return new CollectionIter(
               this, 
               aSkip + lReferencedPosition);
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
#endif

  if (item->isNode())
  {
    node = static_cast<XmlNode*>(item);
    
    if (node->getParent() != NULL)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }
#ifdef ZORBA_WITH_JSON
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
#else
  else
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
    ERROR_PARAMS(getName()->getStringValue()));
  }
#endif
  if (item->getCollection() != NULL)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
    ERROR_PARAMS(getName()->getStringValue(),
                 item->getCollection()->getName()->getStringValue()));
  }

  xs_long lPosition = to_xs_long(position);
  xs_integer pos = xs_integer(0);

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE););

  if (lPosition < 0 || to_xs_unsignedLong(position) >= theXmlTrees.size())
  {
    pos = theXmlTrees.size();
    theXmlTrees.push_back(item);
  }
  else
  {
    theXmlTrees.insert(theXmlTrees.begin() + lPosition, item);
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

  csize numNodes = theXmlTrees.size();
  csize numNewNodes = items.size();
  
  for (csize i = 0; i < numNewNodes; ++i)
  {
    store::Item* item = items[i].getp();

    XmlNode* node = NULL;
#ifdef ZORBA_WITH_JSON
    json::SimpleJSONArray* array = NULL;
    json::SimpleJSONObject* object = NULL;
#endif

    if (item->isNode())
    {
      node = static_cast<XmlNode*>(item);
      
      if (node->getParent() != NULL)
      {
        throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
        ERROR_PARAMS(getName()->getStringValue()));
      }
    }
#ifdef ZORBA_WITH_JSON
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
#else
    else
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }
#endif

    if (item->getCollection() != NULL)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION,
      ERROR_PARAMS(getName()->getStringValue(),
                   node->getCollection()->getName()->getStringValue()));
    }

    pos = targetPos + i;

#ifdef ZORBA_WITH_JSON
    if (object)
      object->setCollection(this, pos);
    else if (array)
      array->setCollection(this, pos);
    else
#endif
      node->setCollection(this, pos);
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

  return xs_integer(targetPos);
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
#endif

  if (item->isNode())
  {
    node = static_cast<XmlNode*>(item);
  }
#ifdef ZORBA_WITH_JSON
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
#else
  else
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
    ERROR_PARAMS(getName()->getStringValue()));
  }
#endif

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  bool found = findNode(item, position);

  if (found)
  {
    ZORBA_ASSERT(item->getCollection() == this);

    xs_integer const &zero = xs_integer::zero();

#ifdef ZORBA_WITH_JSON
    if (object)
      object->setCollection(NULL, zero);
    else if (array)
      array->setCollection(NULL, zero);
    else
#endif
      node->setCollection(NULL, zero);

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

    xs_integer const &zero = xs_integer::zero();

    if (item->isNode())
    {
      XmlNode* node = static_cast<XmlNode*>(item);
      node->setCollection(NULL, zero);
    }
#ifdef ZORBA_WITH_JSON
    else if (item->isJSONObject())
    {
      json::SimpleJSONObject* object = static_cast<json::SimpleJSONObject*>(item);
      object->setCollection(NULL, zero);
    }
    else if (item->isJSONArray())
    {
      json::SimpleJSONArray* array = static_cast<json::SimpleJSONArray*>(item);
      array->setCollection(NULL, zero);
    }
#endif
    else
    {
      ZORBA_ASSERT(false);
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
    return xs_integer::zero();
  }
  else
  {
    uint64_t last = pos + num;
    if (last > theXmlTrees.size())
    {
      last = theXmlTrees.size();
    }

    xs_integer const &zero = xs_integer::zero();

    for (csize i = pos; i < last; ++i)
    { 
      store::Item* item = theXmlTrees[pos].getp();

      ZORBA_ASSERT(item->getCollection() == this);

      if (item->isNode())
      {
        XmlNode* node = static_cast<XmlNode*>(item);
        node->setCollection(NULL, zero);
      }
#ifdef ZORBA_WITH_JSON
      else if (item->isJSONObject())
      {
        json::SimpleJSONObject* object = static_cast<json::SimpleJSONObject*>(item);
        object->setCollection(NULL, zero);
      }
      else if (item->isJSONArray())
      {
        json::SimpleJSONArray* array = static_cast<json::SimpleJSONArray*>(item);
        array->setCollection(NULL, zero);
      }
#endif
      else
      {
        ZORBA_ASSERT(false);
      }

      theXmlTrees.erase(theXmlTrees.begin() + pos);
    }

    return xs_integer(last - pos);
  }
}


/*******************************************************************************
 * Remove all the nodes from the collection
********************************************************************************/
void SimpleCollection::removeAll()
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  theXmlTrees.clear();
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

  if (item->isNode())
  {
    node = static_cast<const XmlNode*>(item);
    
    if (node->getParent() != NULL)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0011_COLLECTION_NON_ROOT_NODE,
      ERROR_PARAMS(getName()->getStringValue()));
    }
  }
#ifdef ZORBA_WITH_JSON
  else if (item->isJSONObject())
  {
  }
  else if (item->isJSONArray())
  {
  }
  else
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0013_COLLECTION_ITEM_MUST_BE_STRUCTURED,
    ERROR_PARAMS(getName()->getStringValue()));
  }
#else
  else
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE,
    ERROR_PARAMS(getName()->getStringValue()));
  }
#endif

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
      BASE_NODE(theXmlTrees[i])->getTree()->setPosition(xs_integer(i));
#else
    BASE_NODE(theXmlTrees[i])->getTree()->setPosition(xs_integer(i));
#endif
  }
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
    SimpleCollection* collection,
    const xs_integer& aSkip)
  :
  theCollection(collection),
  theHaveLock(false),
  theSkip(aSkip)
{
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::CollectionIter::~CollectionIter() 
{
  SYNC_CODE(if (theHaveLock) \
    theCollection->theLatch.unlock();)
}

void SimpleCollection::CollectionIter::skip()
{
  // skip by position
  long lToSkip = to_xs_long(theSkip);
  if (theSkip >= theCollection->size())
  {
    // we need to skip more then possible -> jump to the end
    theIterator = theEnd;
  }
  else
  {
    theIterator += to_xs_long(theSkip);
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::open()
{
  SYNC_CODE(theCollection->theLatch.rlock();)
  theHaveLock = true;

  theIterator = theCollection->theXmlTrees.begin();
  theEnd = theCollection->theXmlTrees.end();
  skip();
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
