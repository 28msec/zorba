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

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "store/naive/simple_collection.h"
#include "store/naive/loader.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(store::Item_t& aName)
  : 
  theTreeCounter(1)
{
  theId = GET_STORE().createCollectionId();

  theName.transfer(aName);
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
  Insert into the collection an xml document or fragment given as text via an
  input stream. The xml text is parsed into an xml tree and the root node of 
  this tree is inserted at a given position inside this collection, or at the
  end of the collection if the position is <= 0. Return the root node of
  the new xml document or fragment.
********************************************************************************/
store::Item_t SimpleCollection::loadDocument(
    std::istream& stream,
    long position)
{
  error::ErrorManager lErrorManager;
  std::auto_ptr<XmlLoader> loader(GET_STORE().getXmlLoader(&lErrorManager));
  xqpStringStore_t docUri;

  store::Item_t root = loader->loadXml(docUri, stream);

  if (lErrorManager.hasErrors()) 
  {
    throw lErrorManager.getErrors().front();
  }

  if (root != NULL)
  {
    SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

    if(position <= 0 || position > static_cast<long>(theXmlTrees.size()))
      theXmlTrees.push_back(root);
    else
      theXmlTrees.insert(theXmlTrees.begin() + (position - 1), root);

    BASE_NODE(root)->setCollection(this);
  }

  return root;
}


store::Item_t SimpleCollection::loadDocument(
    std::istream* stream,
    long position)
{
  store::Item_t    docitem;
  std::auto_ptr<std::istream> theStream(stream); // we take the ownership
  //do full loading for now
  docitem = loadDocument(*stream, position);
  return docitem;
}


/*******************************************************************************
  Insert the given node to the collection. If the node is in any collection
  already or if the node has a parent, this method raises an error.
********************************************************************************/
void SimpleCollection::addNode(
    store::Item* nodeItem,
    long position)
{
  if (!nodeItem->isNode())
  {
    ZORBA_ERROR(API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  XmlNode* node = static_cast<XmlNode*>(nodeItem);

  if (node->getCollection() != NULL)
  {
    ZORBA_ERROR_PARAM(API0031_NODE_ALREADY_IN_COLLECTION, 
                      node->getCollection()->getName()->getStringValue()->c_str(), "");
  }

  if (node->getParent() != NULL)
  {
    ZORBA_ERROR_PARAM(API0032_NON_ROOT_NODE_IN_COLLECTION,
                      getName()->getStringValue()->c_str(), "");
  }

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE););

  if (position <= 0 || position > static_cast<long>(theXmlTrees.size()))
    theXmlTrees.push_back(nodeItem);
  else
    theXmlTrees.insert(theXmlTrees.begin() + (position - 1), nodeItem);

  node->setCollection(this);
}


/*******************************************************************************
  Insert the given node to the collection before or after the aTargetNode. If
  the node is in any collection already, this method raises an error.
********************************************************************************/
void SimpleCollection::addNode(
    store::Item* nodeItem,
    const store::Item* aTargetNode,
    bool before)
{
  if (!nodeItem->isNode() || !aTargetNode->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  XmlNode* node = static_cast<XmlNode*>(nodeItem);

  if (node->getCollection() != NULL)
  {
    ZORBA_ERROR_PARAM(API0031_NODE_ALREADY_IN_COLLECTION, 
                      node->getCollection()->getName()->getStringValue()->c_str(), "");
  }

  if (node->getParent() != NULL)
  {
    ZORBA_ERROR_PARAM(API0032_NON_ROOT_NODE_IN_COLLECTION,
                      getName()->getStringValue()->c_str(), "");
  }

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  long targetPos = nodePositionInCollection((store::Item*)aTargetNode);
  if(targetPos == -1)
  {
    ZORBA_ERROR(API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION);
  }

  if(before) 
  {
    ZORBA_ASSERT(targetPos != 0);
    theXmlTrees.insert(theXmlTrees.begin() + (targetPos-1), nodeItem);
  }
  else
  {
    theXmlTrees.insert(theXmlTrees.begin() + targetPos, nodeItem);
  }

  node->setCollection(this);
}


/*******************************************************************************
  Delete the given node from the collection.
********************************************************************************/
bool SimpleCollection::removeNode(store::Item* nodeItem)
{
  if (!nodeItem->isNode())
  {
    ZORBA_ERROR(API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  XmlNode* node = static_cast<XmlNode*>(nodeItem);

  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  long position = nodePositionInCollection(nodeItem);

  if (position != -1)
  {
    ZORBA_ASSERT(position > 0);
    ZORBA_ASSERT(node->getCollection() == this);

    theXmlTrees.erase(theXmlTrees.begin() + (position - 1));
    node->setCollection(NULL);
    return true;
  }
  else
  {
    return false;
  }
}


/*******************************************************************************
  Delete the node at the given position from the collection.
********************************************************************************/
bool SimpleCollection::removeNode(long position)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  if (position <= 0) 
  {
    if (theXmlTrees.size() == 0)
      return false;

    XmlNode* node = static_cast<XmlNode*>(theXmlTrees.back().getp());
    ZORBA_ASSERT(node->getCollection() == this);
    node->setCollection(NULL);

    theXmlTrees.erase(theXmlTrees.end() - 1);
    return true;
  }
  else if (static_cast<ulong>(position) > theXmlTrees.size())
  {
    return false;
  }
  else 
  {
    XmlNode* node = static_cast<XmlNode*>(theXmlTrees[position - 1].getp());
    ZORBA_ASSERT(node->getCollection() == this);
    node->setCollection(NULL);

    theXmlTrees.erase(theXmlTrees.begin() + (position - 1));
    return true;
  }
}


/*******************************************************************************
  Return the node at the given position from the collection.
********************************************************************************/
store::Item_t SimpleCollection::nodeAt(long position)
{
  if( position <= 0 || ((ulong)position) > theXmlTrees.size() )
  {
    return NULL;
  }

  return theXmlTrees[position - 1];
}


/*******************************************************************************
  Return position of the given node in the collection.
********************************************************************************/
long SimpleCollection::indexOf(const store::Item* node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR(API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  return nodePositionInCollection(node);
}


/*******************************************************************************

********************************************************************************/
int SimpleCollection::nodePositionInCollection(const store::Item* newNode)
{
  if( theXmlTrees.empty() )
    return -1;

  checked_vector<store::Item_t>::const_iterator it = theXmlTrees.begin();
  checked_vector<store::Item_t>::const_iterator end = theXmlTrees.end();

  for (; it != end; ++it)
  {
    //check if the nodes are the same
    if (newNode->equals(*it))
    {
      ZORBA_ASSERT(BASE_NODE(*it)->getCollection() == this);
      return (it - theXmlTrees.begin() + 1);
    }
  }

  return -1;
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
    ZORBA_ERROR_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR,
                     "Collection iterator has not been opened");
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

