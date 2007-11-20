/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include <iostream>

#include "util/rchandle.h"

#include "errors/Error.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_loader.h"
#include "store/naive/basic_item_factory.h"

namespace xqp
{

typedef rchandle<TempSeq> TempSeq_t;

const float SimpleStore::DEFAULT_HASH_LOAD_FACTOR = 0.6;
const xqp_ulong SimpleStore::DEFAULT_COLLECTION_MAP_SIZE = 32;

xqp_ulong SimpleStore::theUriCounter = 0;


/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
  :
  theUriPool(new StringPool(StringPool::DEFAULT_POOL_SIZE)),
  theQNamePool(new QNamePool(QNamePool::MAX_CACHE_SIZE)),
  theItemFactory(new BasicItemFactory(theUriPool, theQNamePool)),
  theCollections(DEFAULT_COLLECTION_MAP_SIZE,
                 DEFAULT_HASH_LOAD_FACTOR),
  theXmlLoader(NULL)
{
}


/*******************************************************************************

********************************************************************************/
SimpleStore::~SimpleStore()
{
  theCollections.clear();

  if (theItemFactory != NULL)
  {
    delete theItemFactory;
    theItemFactory = NULL;
  }

  if (theQNamePool != NULL)
  {
    delete theQNamePool;
    theQNamePool = NULL;
  }

  if (theUriPool != NULL)
  {
    delete theUriPool;
    theUriPool = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
XmlLoader& SimpleStore::getXmlLoader()
{
  if (theXmlLoader == NULL)
    theXmlLoader = new XmlLoader();

  return *theXmlLoader;
}


/*******************************************************************************
  Possibility to change the Garbage Collection strategy of the store.

  @param garbageCollectionStrategy
********************************************************************************/
void SimpleStore::setGarbageCollectionStrategy(const xqp_string& strategy)
{

}


/*******************************************************************************
  Creates a new unique URI which can be used as an ID for a collection.

  @return URI
********************************************************************************/
Item_t SimpleStore::createURI()
{
  std::ostringstream uristream;
  uristream << "zorba://internalURI" << SimpleStore::theUriCounter++;

  return theItemFactory->createAnyURI(uristream.str().c_str()).get_ptr();
}


/*******************************************************************************
  Creates a collection in the store.

  @param URI The URI (given as a string) of the collection to create.
  @return handle object of the newly created collection
  @throws UriInUseException If the passed uri already exists in the store.
********************************************************************************/
Collection_t SimpleStore::createCollection(const xqp_string& uri)
{
  if (theCollections.find(uri))
  {
    ZORBA_ERROR_ALERT_OSS(error_messages::API0005_COLLECTION_ALREADY_EXISTS,
                          error_messages::USER_ERROR,
                          NULL,
                          true,
                          uri, "");
  }

  AnyUriItem_t uriItem = theItemFactory->createAnyURI(uri);

  Collection_t collection(new SimpleCollection(uriItem));

  theCollections.insert(uri, collection);

  return collection;
}


/*******************************************************************************
  Creates a collection in the store.

  @param URI The URI (given as an Item_t) of the collection to create.
  @return handle object of the newly created collection
  @throws UriInUseException If the passed uri already exists in the store.
********************************************************************************/
Collection_t SimpleStore::createCollection(Item_t uri)
{
  if (theCollections.find(uri->getStringValue()))
  {
    ZORBA_ERROR_ALERT_OSS(error_messages::API0005_COLLECTION_ALREADY_EXISTS,
                          error_messages::USER_ERROR,
                          NULL,
                          true,
                          uri->getStringValue(), "");
  }

  AnyUriItem_t uriItem = dynamic_cast<AnyUriItem*>(uri.get_ptr());

  Collection_t collection(new SimpleCollection(uriItem));

  theCollections.insert(uri->getStringValue(), collection);

  return collection;
}


/*******************************************************************************
  Creates a collection in the store (without given URI).

  @return handle object of the newly created collection
********************************************************************************/
Collection_t SimpleStore::createCollection()
{
  Item_t uri = createURI();

  return createCollection(uri);
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
  Collection_t collection;
  bool found = theCollections.get(uri->getStringValue(), collection);
  return (found ? collection : NULL);
}


/*******************************************************************************
  Deletes a collection.

  @param URI to identify the collection to delete.
********************************************************************************/
void SimpleStore::deleteCollection(Item_t uri)
{
  theCollections.remove(uri->getStringValue());
}


/*******************************************************************************
  Creates a new TempSeq. The instance can be used, e.g. for variable bindings

  @param iterator The source for the XMDInstance
  @param lazy			Hint for the store. If possible a XMDInstance should be
                  evaluated lazily. For XQueryP it might be necassary to set
                  this to false.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(Iterator_t iterator, bool lazy)
{
  TempSeq_t tempSeq = new SimpleTempSeq(iterator, lazy);
  return tempSeq;
}


/*******************************************************************************
  Creates an empty TempSeq.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq()
{
  TempSeq_t tempSeq = new SimpleTempSeq();
  return tempSeq;
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
  return rchandle<Item>(NULL);
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
Item_t SimpleStore::getFixedReference(
    Item_t,
    Requester requester,
    Timetravel timetravel)
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
Item_t SimpleStore::getNodeByReference(
    Item_t,
    Requester requester,
    Timetravel timetravel)
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

/* end class SimpleStore */

} /* namespace xqp */
