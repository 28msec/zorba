/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */
#include "errors/Error.h"
#include "util/rchandle.h"
#include "store/naive/simple_collection.h"
#include "store/naive/simple_loader.h"
#include "store/naive/simple_store.h"
#include "store/naive/node_items.h"

namespace xqp
{
typedef rchandle<Iterator> Iterator_t;


/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection(const AnyUriItem_t& uri)
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
  Reads the whole Collection from beginning to end; it is allowed to have several 
	concurrent iterators on the same Collection.

  IN idsNeeded: whether the returned items contain ids, e.g. for sorting
  RET Iterator: which iterates over the complete Collection

  Ids == false is likely to be faster. 'idsNeeded' should only be set to true
  if clients wants to sort or compare the items or sub-items generated from the
  returned iterator.
********************************************************************************/
Iterator_t SimpleCollection::getIterator(bool idsNeeded)
{
  return rchandle<Iterator> ( NULL );
}


/*******************************************************************************
  Inserts data into the collection

  IN item: to insert
  IN position: Where to insert the item. Default -1, which means it is attached
               to the end. 
********************************************************************************/
void SimpleCollection::addToCollection(Item_t item, int32_t position)
{
  if (!item->isNode())
  {
    ZORBA_ERROR_ALERT(error_messages::API0007_COLLECTION_ITEM_MUST_BE_A_NODE,
                      error_messages::USER_ERROR,
                      NULL,
                      true);
  }

  if (position >= static_cast<long>(theNodes.size()))
    theNodes.resize(position);

  theNodes[position] = static_cast<NodeItem*>(item.get_ptr());
}


/*******************************************************************************
  Inserts data into the collection

  IN iterator: which produces the items to insert
  IN position: Where to insert the item. Default -1, which means it is
               attached to the end.
********************************************************************************/
void SimpleCollection::addToCollection(Iterator_t& items, int32_t position)
{
}


/*******************************************************************************
  Inserts data into the collection
	TODO loading from SAX & DOM

  IN stream: which streams the data to insert (e.g. from a file)
	IN position: Where to insert the item. Default -1, which means it is
               attached to the end.
********************************************************************************/
void SimpleCollection::addToCollection(std::iostream& stream, int32_t position)
{
  XmlLoader& loader = reinterpret_cast<SimpleStore*>(&Store::getInstance())->
                      getXmlLoader();

  NodeItem_t root = loader.loadXml(stream);

  if (position < 0)
  {
    theNodes.push_back(root);
  }
  else
  {
    if (position >= static_cast<long>(theNodes.size()))
      theNodes.resize(position);

    theNodes[position] = root;
  }
}


/*******************************************************************************
  Deletes an item of the collection.

  IN position: of the items which will be deleted
********************************************************************************/
void SimpleCollection::deleteFromCollection(int32_t position)
{
  if (position < static_cast<long>(theNodes.size()))
    theNodes[position] = NULL;
}

} /* namespace xqp */
