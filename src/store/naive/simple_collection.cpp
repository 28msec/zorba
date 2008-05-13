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
#include "util/rchandle.h"

#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "store/naive/simple_collection.h"
#include "store/naive/simple_loader.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"

namespace zorba { namespace store {

/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(Item_t& uri)
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
Iterator_t SimpleCollection::getIterator(bool idsNeeded)
{
  return new CollectionIter(this);
}


/*******************************************************************************
  Insert into the collection an xml document or fragment given as text via an
  input stream. Return the root node of the new xml document or fragment.
********************************************************************************/
Item_t SimpleCollection::addToCollection(std::istream& stream)
{
  error::ErrorManager lErrorManager;
  std::auto_ptr<XmlLoader> loader(GET_STORE().getXmlLoader(&lErrorManager));
  xqpStringStore_t docUri;

  XmlNode* root = loader->loadXml(docUri, stream);

  if (lErrorManager.hasErrors()) 
  {
    throw lErrorManager.getErrors().front();
  }

  if (root != NULL)
  {
    SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)
    theXmlTrees.insert(root);
  }

  return root;
}

Item_t SimpleCollection::addToCollection(std::istream* stream)
{
  Item_t    docitem;
  //do full loading for now
  docitem = addToCollection(*stream);
  delete stream;
  return docitem;
}

/*******************************************************************************
  Insert the given node to the collection. If the node is in the collection
  already, this method is a noop.
********************************************************************************/
void SimpleCollection::addToCollection(const Item* node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)
  theXmlTrees.insert(const_cast<Item*>(node));
}


/*******************************************************************************
  Insert into the collection the set of nodes returned by the given iterator.
********************************************************************************/
void SimpleCollection::addToCollection(Iterator* nodeIter)
{
  Item_t node = nodeIter->next();

  while (node != NULL)
  {
    addToCollection(node);
    node = nodeIter->next();
  }
}


/*******************************************************************************
  Delete the given node from the collection.
********************************************************************************/
void SimpleCollection::removeFromCollection(const Item* node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR( API0007_COLLECTION_ITEM_MUST_BE_A_NODE);
  }

  SYNC_CODE(AutoLatch(theLatch, Latch::WRITE);)
  theXmlTrees.erase(const_cast<Item*>(node));
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::CollectionIter::CollectionIter(
    SimpleCollection* collection)
  :
  theCollection(collection)
  SYNC_PARAM2(theLatch(collection->theLatch, Latch::READ))
{
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::open()
{
  theIterator = theCollection->theXmlTrees.begin();
}


/*******************************************************************************

********************************************************************************/
Item_t SimpleCollection::CollectionIter::next()
{

  if (theIterator == theCollection->theXmlTrees.end())
    return NULL;

  Item* node = (*theIterator).getp();
  theIterator++;

  return node;
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
}
} // namespace store
} // namespace zorba

