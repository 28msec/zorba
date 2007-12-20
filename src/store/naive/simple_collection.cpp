/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: David Graf, Markos Zaharioudakis
 */
#include "errors/Error.h"
#include "util/rchandle.h"
#include "store/naive/simple_collection.h"
#include "store/naive/simple_loader.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"

namespace xqp
{
typedef rchandle<Iterator> Iterator_t;


/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(const Item_t& uri)
  :
  theUri(uri)
{
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
Item_t SimpleCollection::addToCollection(std::iostream& stream)
{
  XmlLoader& loader = GET_STORE().getXmlLoader();

  Item_t root = loader.loadXml(stream);
  theNodes.insert(root);
  return root;
}


/*******************************************************************************
  Insert the given node to the collection. If the node is in the collection
  already, this method is a noop.
********************************************************************************/
void SimpleCollection::addToCollection(const Item_t& node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR_ALERT(error_messages::API0007_COLLECTION_ITEM_MUST_BE_A_NODE,
                      NULL, true);
    return;
  }

  theNodes.insert(node);
}


/*******************************************************************************
  Insert into the collection the set of nodes returned by the given iterator.
********************************************************************************/
void SimpleCollection::addToCollection(Iterator_t& nodeIter)
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
void SimpleCollection::removeFromCollection(const Item_t& node)
{
  if (!node->isNode())
  {
    ZORBA_ERROR_ALERT(error_messages::API0007_COLLECTION_ITEM_MUST_BE_A_NODE,
                      NULL, true);
    return;
  }

  theNodes.erase(node);
}


/*******************************************************************************

********************************************************************************/
SimpleCollection::CollectionIter::CollectionIter(
    const SimpleCollection_t& collection)
  :
  theCollection(collection),
  theIterator(collection->theNodes.begin())
{
}


/*******************************************************************************

********************************************************************************/
Item_t SimpleCollection::CollectionIter::next()
{

  if (theIterator == theCollection->theNodes.end())
    return NULL;

  Item_t node = *theIterator;
  theIterator++;

  return node;
}


/*******************************************************************************

********************************************************************************/
void SimpleCollection::CollectionIter::reset()
{
  theIterator = theCollection->theNodes.begin();
}

void SimpleCollection::CollectionIter::close() { 
}

} /* namespace xqp */
