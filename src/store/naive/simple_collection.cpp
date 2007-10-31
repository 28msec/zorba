/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */
#include "util/rchandle.h"
#include "store/naive/simple_collection.h"
#include "store/naive/node_items.h"

namespace xqp
{
typedef rchandle<Iterator> Iterator_t;


/*******************************************************************************

********************************************************************************/
SimpleCollection::SimpleCollection()
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
Iterator_t SimpleCollection::getIterator ( bool idsNeeded )
{
  return rchandle<Iterator> ( NULL );
}


/*******************************************************************************
  Inserts data into the collection

  IN item: to insert
  IN position: Where to insert the item. Default -1, which means it is attached
               to the end. 
********************************************************************************/
void SimpleCollection::addToCollection ( Item_t item, int32_t position )
{
}


/*******************************************************************************
  Inserts data into the collection

  IN iterator: which produces the items to insert
  IN position: Where to insert the item. Default -1, which means it is
               attached to the end.
********************************************************************************/
void SimpleCollection::addToCollection ( Iterator_t& items, int32_t position )
{
}

/*******************************************************************************
  Inserts data into the collection
	TODO loading from SAX & DOM

  IN stream: which streams the data to insert (e.g. from a file)
	IN position: Where to insert the item. Default -1, which means it is
               attached to the end.
********************************************************************************/
void SimpleCollection::addToCollection ( std::iostream& stream, int32_t position )
{
}

/*******************************************************************************
  Deletes an item of the collection.

  IN position: of the items which will be deleted
********************************************************************************/
void SimpleCollection::deleteFromCollection ( int32_t position )
{

}


/*******************************************************************************
  Returns the URI of the collection

  RET uri
********************************************************************************/
Item_t SimpleCollection::getURI()
{
  return rchandle<Item> ( NULL );
}

} /* namespace xqp */
