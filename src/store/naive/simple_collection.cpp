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

#include "zorbaerrors/error_manager.h"
#include "system/globalenv.h"
#include "store/naive/simple_collection.h"
#include "store/naive/sax_loader.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(store::Item_t& uri)
{
 theUri.transfer(uri);
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::~SimpleCollection()
{
}


/*******************************************************************************
  Return an iterator over the nodes of this collection.

  Note: it is allowed to have several concurrent iterators on the same
        collection.

  The "idsNeeded" param tell whether the returned nodes should contain node
  ids (e.g. for document-order sorting) or not. idsNeeded == false is likely
  to be faster. 'idsNeeded' should only be set to true if clients wants to
  sort or compare the items or sub-items generated from the returned iterator.
********************************************************************************/
store::Iterator_t SimpleCollection::getIterator(bool idsNeeded)
{
  return new CollectionIter(this);
}


/*******************************************************************************
  Insert into the collection an xml document or fragment given as text via an
  input stream. Return the root node of the new xml document or fragment.
********************************************************************************/
store::Item_t SimpleCollection::addToCollection(
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
    SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)

    if(position == -1)
      theXmlTrees.insert(theXmlTrees.end(), root);
    else
      theXmlTrees.insert(theXmlTrees.begin() + position, root);
  }

  return root;
}


store::Item_t SimpleCollection::addToCollection(std::istream* stream, long position)
{
  store::Item_t    docitem;
  //do full loading for now
  docitem = addToCollection(*stream, position);
  delete stream;
  return docitem;
}


/*******************************************************************************
  Insert the given node to the collection. If the node is in the collection
  already, this method is a noop.
********************************************************************************/
void SimpleCollection::addToCollection(const store::Item* node, long position)
{
  if (!node->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)

  if( nodePositionInCollection((store::Item*)node) == -1)
  {
    if(position == -1)
      theXmlTrees.insert(theXmlTrees.end(), const_cast<store::Item*>(node));
    else
      theXmlTrees.insert(theXmlTrees.begin() + position, const_cast<store::Item*>(node));
  }
  else
  {
    ZORBA_ERROR(API0031_NODE_ALREADY_IN_COLLECTION);
  }
}


/*******************************************************************************
  Insert the given node to the collection before the aTargetNode. 
********************************************************************************/
void SimpleCollection::addNode(
    const store::Item* node,
    const store::Item* aTargetNode,
    bool aOrder)
{
  if (!node->isNode() || !aTargetNode->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  if( nodePositionInCollection((store::Item*)aTargetNode)  == -1)
  {
    ZORBA_ERROR(API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION);
  }

  SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)

  checked_vector<store::Item_t>::iterator it = theXmlTrees.begin();
  checked_vector<store::Item_t>::iterator end = theXmlTrees.end();
  const XmlNode* rTargetNode = reinterpret_cast<const XmlNode*>(aTargetNode);

  if( nodePositionInCollection((store::Item*)node) == -1)
  {
    for (; it != end; ++it)
    {
      //check if the nodes have the same ID
      if((reinterpret_cast<XmlNode*>(it->getp()))->getTreeId() == rTargetNode->getTreeId() &&
         (reinterpret_cast<XmlNode*>(it->getp()))->getOrdPath() == rTargetNode->getOrdPath())
      {
        if(aOrder)
          theXmlTrees.insert(it, const_cast<store::Item*>(node));
        else
          theXmlTrees.insert(++it,const_cast<store::Item*>(node));

        break;
      }
    }
  }
  else
  {
    ZORBA_ERROR(API0031_NODE_ALREADY_IN_COLLECTION);
  }

}


/*******************************************************************************
  Insert into the collection the set of nodes returned by the given iterator.
********************************************************************************/
void SimpleCollection::addToCollection(store::Iterator* nodeIter, long position)
{
  store::Item_t node;
  while (nodeIter->next(node))
  {
    addToCollection(node, position);
  }
}


/*******************************************************************************
  Delete the given node from the collection.
********************************************************************************/
void SimpleCollection::removeFromCollection(const store::Item* node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  int position = nodePositionInCollection((store::Item*) node);

  if(position != -1)
  {
    if( theXmlTrees.erase(theXmlTrees.begin() + position) == theXmlTrees.end() )
      ZORBA_ERROR(API0030_NO_NODE_AT_GIVEN_POSITION);
  }
  else
  {
    ZORBA_ERROR(API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION);
  }
}

/*******************************************************************************
  Delete the node at the given position from the collection.
********************************************************************************/
void SimpleCollection::removeFromCollection(long position)
{
  if(position == -1)
  {
    if( theXmlTrees.erase(theXmlTrees.end()) == theXmlTrees.end() )
    {
      ZORBA_ERROR(API0030_NO_NODE_AT_GIVEN_POSITION);
    }
  }
  else
  {
    if( theXmlTrees.erase(theXmlTrees.begin() + position) == theXmlTrees.end() )
    {
      ZORBA_ERROR(API0030_NO_NODE_AT_GIVEN_POSITION);
    }
  }
}

/*******************************************************************************
  Return the node at the given position from the collection.
********************************************************************************/
store::Item_t SimpleCollection::nodeAt(long position)
{
  if( position < 0 || ((ulong)position) >= theXmlTrees.size() )
  {
    ZORBA_ERROR(API0030_NO_NODE_AT_GIVEN_POSITION);
  }

  return theXmlTrees[position];
}

/*******************************************************************************
  Return position of the given node in the collection.
********************************************************************************/
long SimpleCollection::indexOf(const store::Item* node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  return nodePositionInCollection((store::Item*) node);
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
  if (theIterator == theCollection->theXmlTrees.end()) 
  {
    result = NULL;
    return false;
  }

  result = (*theIterator).getp();
  theIterator++;

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
  theHaveLock = false;
  SYNC_CODE(theCollection->theLatch.unlock();)
}


/*******************************************************************************

********************************************************************************/
int
SimpleCollection::nodePositionInCollection(store::Item* newNode)
{
  if( theXmlTrees.empty() )
    return -1;
  else
  {
    checked_vector<store::Item_t>::iterator it = theXmlTrees.begin();
    checked_vector<store::Item_t>::iterator end = theXmlTrees.end();
    const XmlNode* rNewNode = reinterpret_cast<const XmlNode*>(newNode);

    for (; it != end; ++it)
      //check if the nodes have the same ID
      if((reinterpret_cast<XmlNode*>(it->getp()))->getTreeId() == rNewNode->getTreeId() &&
         (reinterpret_cast<XmlNode*>(it->getp()))->getOrdPath() == rNewNode->getOrdPath())
        return (it - theXmlTrees.begin());
    return -1;
  }
}

} // namespace store
} // namespace zorba

