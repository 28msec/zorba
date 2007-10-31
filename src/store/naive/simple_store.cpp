/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include "util/rchandle.h"

#include "store/naive/simple_store.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_collection.h"

namespace xqp
{

typedef rchandle<TempSeq> TempSeq_t;


/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
{
}


/*******************************************************************************

********************************************************************************/
SimpleStore::~SimpleStore()
{
}


/*******************************************************************************
  Creates a new TempSeq. The instance can be used, e.g. for variable bindings

  @param iterator The source for the XMDInstance
  @param lazy			Hint for the store. If possible a XMDInstance should be
                  evaluated lazily. For XQueryP it might be necassary to set
                  this to false.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(Iterator_t& iterator, bool lazy)
{
  TempSeq_t tempSeq = new SimpleTempSeq ( iterator );
  return tempSeq;
}

/*******************************************************************************
  Possibility to change the Garbage Collection strategy of the store.

  @param garbageCollectionStrategy
********************************************************************************/
void SimpleStore::setGarbageCollectionStrategy(const xqp_string& strategy)
{

}

/*******************************************************************************
  Applies a pending update list on this store

  @param pendingUpdateList
********************************************************************************/
void SimpleStore::apply(PUL_t pendingUpdateList)
{

}

/*******************************************************************************
  Applies the pending update list on the specified branch. Potentially, 
  creates a new branch if no branch for that requester exists yet.

  @param pendingUpdateList
  @param requester
  @throws NotSupportedException Throws an exception if the store does not
          support branching
********************************************************************************/
void SimpleStore::apply(PUL_t pendingUpdateList, Requester requester)
{

}

/*******************************************************************************
  Computes the URI of the passed item.

  @param item XDM item
  @return Returns an item of type xs:uri 
********************************************************************************/
Item_t SimpleStore::getReference(Item_t)
{
  return rchandle<Item> ( NULL );
}

/*******************************************************************************
  Returns a fixed reference of an item, dependent on a requester (defines branch)
  and a timetravel (defines version)

  @param Item 
  @param requester
  @param timetravel
  @throws NotSupportedException Throws an exception if the store does not
          support branching or versioning
********************************************************************************/
Item_t SimpleStore::getFixedReference(Item_t, Requester requester, Timetravel timetravel)
{
  return rchandle<Item> ( NULL );
}

/*******************************************************************************
  Returns Item which is identified by a reference

  @param uri Has to be an xs:URI item
  @returns referenced item if it exists, otherwise NULL
********************************************************************************/
Item_t SimpleStore::getNodeByReference(Item_t)
{
  return rchandle<Item> ( NULL );
}

/*******************************************************************************
  Returns Item wich is identified by a referenced, dependent on a requester
  (defines branch) and a timetravel (defines version)

  @param Item_t Has to be an xs:URI item (no correctness check is applied!!!)
  @param requester
  @param timetravel
  @returns referenced item if it exists, otherwise NULL
  @throws NotSupportedException Throws an exception if the store does not
          support branching or versioning
  @throws IllegalReferenceException Throws an exception if the reference is fixed.
********************************************************************************/
Item_t SimpleStore::getNodeByReference(Item_t, Requester requester, Timetravel timetravel)
{
  return rchandle<Item> ( NULL );
}

/*******************************************************************************
  Compares two items, based on their id.

  @param item1
  @param item2
  @return  -1, if item1.id &lt; item2.id
            0, if item1.id == item2.id
           +1, if item1.id &gt; item2.id
********************************************************************************/
int32_t SimpleStore::compare(Item_t item1, Item_t item2)
{
  return 2;
}

/*******************************************************************************
  Sorts the items of the passed iterator

  @param iterator to sort
  @param ascendent true for ascendent and false for descendant
  @param duplicate duplicate elemination should be applied
  @return iterator which produces the sorted items
********************************************************************************/
Iterator_t SimpleStore::sort(Iterator_t iterator, bool ascendent, bool duplicateElemination)
{
  return rchandle<Iterator> ( NULL );
}

/*******************************************************************************
  Eliminates the duplicates in collection of items which is produced by the
  passed iterator

  @param iterator
********************************************************************************/
Iterator_t SimpleStore::distinctNodeStable(Iterator_t)
{
  return rchandle<Iterator> ( NULL );
}

/*******************************************************************************
  Returns an XDM instance which is saved in the store (corresponds to the
  opening of a connection to a database)

  @param URI of the colleciton
  @return handle object of the collection. Returns NULL if the collection does
          not exist
********************************************************************************/
Collection_t SimpleStore::getCollection(Item_t uri)
{
  return rchandle<Collection> ( NULL );
}

/*******************************************************************************
  Creates a collection in the store.

  @param URI The URI of the collection to create.
  @return handle object of the newly created collection
  @throws CollectionAlreadyExistsException If a collection with the passed uri
          already exists in the store.
********************************************************************************/
Collection_t SimpleStore::createCollection(Item_t uri)
{
  return rchandle<Collection> ( NULL );
}

/*******************************************************************************
  Creates a collection in the store (without given URI).

  @return handle object of the newly created collection
********************************************************************************/
Collection_t SimpleStore::createCollection()
{
  return rchandle<Collection> ( NULL );
}

/*******************************************************************************
  Deletes a collection.

  @param URI to identify the collection to delete.
********************************************************************************/
void SimpleStore::deleteCollection(Item_t uri)
{

}

/*******************************************************************************
  Creates a new unique URI which can be used as an ID for a collection.

  @return URI
********************************************************************************/
Item_t SimpleStore::createURI()
{
  return Item_t( NULL );
}
/* end class SimpleStore */

} /* namespace xqp */
