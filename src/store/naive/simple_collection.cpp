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
#include "store/naive/simple_loader.h"
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
store::Item_t SimpleCollection::addToCollection(std::istream& stream)
{
  error::ErrorManager lErrorManager;
  std::auto_ptr<XmlLoader> loader(GET_STORE().getXmlLoader(&lErrorManager));
  xqpStringStore_t docUri;

  XmlNode_t root = static_cast<XmlNode*>(loader->loadXml(docUri, stream).getp());

  if (lErrorManager.hasErrors()) 
  {
    throw lErrorManager.getErrors().front();
  }

  if (root != NULL)
  {
    SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)
    theXmlTrees.insert(root.getp());
  }

  return root.getp();
}

store::Item_t SimpleCollection::addToCollection(std::istream* stream)
{
  store::Item_t    docitem;
  //do full loading for now
  docitem = addToCollection(*stream);
  delete stream;
  return docitem;
}

/*******************************************************************************
  Insert the given node to the collection. If the node is in the collection
  already, this method is a noop.
********************************************************************************/
void SimpleCollection::addToCollection(const store::Item* node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)
  theXmlTrees.insert(const_cast<store::Item*>(node));
}


/*******************************************************************************
  Insert into the collection the set of nodes returned by the given iterator.
********************************************************************************/
void SimpleCollection::addToCollection(store::Iterator* nodeIter)
{
  store::Item_t node;
  while (nodeIter->next(node))
  {
    addToCollection(node);
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

  SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)
  theXmlTrees.erase(const_cast<store::Item*>(node));
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
  if (theIterator == theCollection->theXmlTrees.end()) {
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


} // namespace store
} // namespace zorba

