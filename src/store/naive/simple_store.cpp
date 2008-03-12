/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com), Markos Zaharioudakis
 *
 */

#include <iostream>

#include <zorba/rchandle.h>

#include "errors/error_factory.h"
#include "util/Assert.h"
#include "util/hashfun.h"

#include "store/util/handle_hashset_string.h"
#include "store/util/pointer_hashmap_string.h"

#include "store/naive/simple_store.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_loader.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/query_context.h"
#include "store/update/pending_update_list.h"

namespace zorba { namespace store {

typedef rchandle<TempSeq> TempSeq_t;

const float SimpleStore::DEFAULT_HASH_LOAD_FACTOR = 0.6f;

const ulong SimpleStore::DEFAULT_COLLECTION_MAP_SIZE = 32;

const char* SimpleStore::XS_URI = "http://www.w3.org/2001/XMLSchema";


/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
  :
  theIsInitialized(false),
  theUriCounter(0),
  theTreeCounter(1),
  theNamespacePool(new StringPool(StringPool::DEFAULT_POOL_SIZE)),
  theQNamePool(new QNamePool(QNamePool::MAX_CACHE_SIZE)),
  theItemFactory(new BasicItemFactory(theNamespacePool, theQNamePool)),
  theDocuments(DEFAULT_COLLECTION_MAP_SIZE, DEFAULT_HASH_LOAD_FACTOR),
  theCollections(DEFAULT_COLLECTION_MAP_SIZE, DEFAULT_HASH_LOAD_FACTOR),
  theQueryContextContainer(new QueryContextContainer)
{
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::init()
{
  if (!theIsInitialized)
  {
    theIsInitialized = true;

    theUriCounter = 0;
    theTreeCounter = 1;

    theNamespacePool->insertc("", theEmptyNs);
    theNamespacePool->insertc(XS_URI, theXmlSchemaNs);
    theUntypedType = theItemFactory->createQName(XS_URI, "xs", "untyped");
    theAnyType = theItemFactory->createQName(XS_URI, "xs", "anyType");
    theUntypedAtomicType = theItemFactory->createQName(XS_URI, "xs", "untypedAtomic");
    theQNameType = theItemFactory->createQName(XS_URI, "xs", "QName");
  }
}


/*******************************************************************************

********************************************************************************/
SimpleStore::~SimpleStore()
{
  shutdown();
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::shutdown()
{
  theCollections.clear();

  theDocuments.clear();

  if (theQueryContextContainer != NULL)
  {
    delete theQueryContextContainer;
    theQueryContextContainer = NULL;
  }

  if (theItemFactory != NULL)
  {
    delete theItemFactory;
    theItemFactory = NULL;
  }

  if (theQNamePool != NULL)
  {
    theUntypedType = NULL;
    theAnyType = NULL;
    theUntypedAtomicType = NULL;
    theQNameType = NULL;

    delete theQNamePool;
    theQNamePool = NULL;
  }

  if (theNamespacePool != NULL)
  {
    theEmptyNs = NULL;
    theXmlSchemaNs = NULL;

    delete theNamespacePool;
    theNamespacePool = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
ulong SimpleStore::getTreeId()
{
  SYNC_CODE(AutoMutex lock(theTreeCounterMutex);)
  return theTreeCounter++;
}


/*******************************************************************************

********************************************************************************/
XmlLoader* SimpleStore::getXmlLoader()
{
  return new XmlLoader();
}


/*******************************************************************************

********************************************************************************/
QueryContext& SimpleStore::getQueryContext(ulong queryId)
{
  return theQueryContextContainer->getContext(queryId);
}


void SimpleStore::deleteQueryContext(ulong queryId)
{
  theQueryContextContainer->removeContext(queryId, true);
}


/*******************************************************************************
  Possibility to change the Garbage Collection strategy of the store.

  @param garbageCollectionStrategy
********************************************************************************/
void SimpleStore::setGarbageCollectionStrategy(xqpStringStore* strategy)
{

}


/*******************************************************************************
  Create an internal URI and return an rchandle to it. 
********************************************************************************/
Item_t SimpleStore::createUri()
{
  SYNC_CODE(theUriCounterMutex.lock();)
  std::ostringstream uristream;
  uristream << "zorba://internalURI-" << SimpleStore::theUriCounter++;
  SYNC_CODE(theUriCounterMutex.unlock();)

  return theItemFactory->createAnyURI(uristream.str().c_str()).getp();
}


/*******************************************************************************

********************************************************************************/
Item_t SimpleStore::loadDocument(xqpStringStore* uri, std::istream& stream)
{
  if (uri == NULL)
    return NULL;

  XmlNode_t* rootp;
  bool found = theDocuments.get(uri, rootp);

  if (found)
    return rootp->getp();

  std::auto_ptr<XmlLoader> loader(getXmlLoader());

  XmlNode_t root = loader->loadXml(uri, stream);

  if (root != NULL)
  {

    rootp = &root;
    theDocuments.insert(uri, rootp);
  }

  return root;
}


/*******************************************************************************

********************************************************************************/
Item_t SimpleStore::loadDocument(xqpStringStore* uri, Item_t docItem)
{
  if (uri == NULL || docItem == NULL)
    return NULL;

	if(!docItem->isNode())
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::API0021_ITEM_TO_LOAD_IS_NOT_NODE,
                          NULL, CONTINUE_EXECUTION, uri, "");
		return NULL;
  }

  XmlNode_t* rootp = reinterpret_cast<XmlNode_t*>(&docItem);
  bool inserted = theDocuments.insert(uri, rootp);

  if (!inserted && docItem.getp() != rootp->getp())
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::API0020_DOCUMENT_ALREADY_EXISTS,
                          NULL, CONTINUE_EXECUTION, uri, "");
    return NULL; 
  }

  ZORBA_ASSERT(docItem.getp() == rootp->getp());

	return *rootp;
}


/*******************************************************************************
  Return an rchandle to the root node of the document corresponding to the given
  URI, or NULL if there is no document with that URI.
********************************************************************************/
Item_t SimpleStore::getDocument(xqpStringStore* uri)
{
  if (uri == NULL)
    return NULL;

  XmlNode_t* rootp;
  bool found = theDocuments.get(uri, rootp);
  if (found)
    return rootp->getp();

  return NULL;
}


/*******************************************************************************
  Delete the document with the given URI. If there is no document with that
  URI, this method is a NOOP.
********************************************************************************/
void SimpleStore::deleteDocument(xqpStringStore* uri)
{
  if (uri == NULL)
    return;

  theDocuments.remove(uri);
}


/*******************************************************************************
  Create a collection with a given URI and return an rchandle to the new
  collection object. If a collection with the given URI exists already, return
  NULL and register an error.
********************************************************************************/
Collection_t SimpleStore::createCollection(xqpStringStore* uri)
{
  if (uri == NULL)
    return NULL;

  Item_t uriItem = theItemFactory->createAnyURI(uri);

  Collection_t collection(new SimpleCollection(uriItem));

  Collection_t* collp = &collection;

  bool inserted = theCollections.insert(uri, collp);

  if (!inserted)
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::API0005_COLLECTION_ALREADY_EXISTS,
                          NULL, CONTINUE_EXECUTION, uri->c_str(), "");
    return NULL;
  }

  return collection;
}


/*******************************************************************************
  Create a collection in the store. The collection will be assigned an internal
  URI by the store.
********************************************************************************/
Collection_t SimpleStore::createCollection()
{
  Item_t uri = createUri();

  return createCollection(uri->getStringValueP());
}


/*******************************************************************************
  Return an rchandle to the Collection object corresponding to the given URI,
  or NULL if there is no collection with that URI.
********************************************************************************/
Collection_t SimpleStore::getCollection(xqpStringStore* uri)
{
  if (uri == NULL)
    return NULL;

  Collection_t* collectionp;
  theCollections.get(uri, collectionp);
  return collectionp->getp();
}


/*******************************************************************************
  Delete the collection with the given URI. If there is no collection with
  that URI, this method is a NOOP.
********************************************************************************/
void SimpleStore::deleteCollection(xqpStringStore* uri)
{
  if (uri == NULL)
    return;

  theCollections.remove(uri);
}


/*******************************************************************************
  Compare two nodes, based on their node id. Return -1 if node1 < node2, 0, if
  node1 == node2, or 1 if node1 > node2.
********************************************************************************/
long SimpleStore::compareNodes(Item* node1, Item* node2) const
{
  ZORBA_ASSERT(node1->isNode());
  ZORBA_ASSERT(node2->isNode());

  if (node1 == node2)
    return 0;

  XmlNode* n1 = static_cast<XmlNode*>(node1);
  XmlNode* n2 = static_cast<XmlNode*>(node2);

  
  if (n1->getTreeId() < n2->getTreeId() ||
      n1->getTreeId() == n2->getTreeId() && n1->getOrdPath() < n2->getOrdPath())
    return -1;

  return 1;
}


/*******************************************************************************
  Check if two nodes are identical (i.e. have same node id)
********************************************************************************/
bool SimpleStore::equalNodes(const Item* node1, const Item* node2) const
{
  return node1 == node2;
}


/*******************************************************************************
  Return a hash value based on the id of a given node.
********************************************************************************/
uint32_t SimpleStore::hashNode(const Item* node) const
{
  const XmlNode* n = reinterpret_cast<const XmlNode*>(node);
  ulong tid = n->getTree()->getId();

  return hashfun::h32((void*)(&tid), sizeof(ulong), n->getOrdPath().hash());
}


/*******************************************************************************
  Sorts the items of the passed iterator

  @param iterator to sort
  @param ascendent true for ascendent and false for descendant
  @param duplicate duplicate elemination should be applied
  @return iterator which produces the sorted items
********************************************************************************/
Iterator_t SimpleStore::sortNodes(
    Iterator* input,
    bool ascendent,
    bool duplicateElemination,
    bool aAllowAtomics)
{
  if (aAllowAtomics)
    return new StoreNodeSortOrAtomicIterator(input, ascendent, duplicateElemination);
  else
    return  new StoreNodeSortIterator(input, ascendent, duplicateElemination);
}


/*******************************************************************************
  Create an iterator that eliminates the duplicate nodes in the set of items
  which is produced by the passed iterator
********************************************************************************/
Iterator_t SimpleStore::distinctNodes(Iterator* input, bool aAllowAtomics)
{
  if (aAllowAtomics)
    return new StoreNodeDistinctOrAtomicIterator(input);
  else
    return new StoreNodeDistinctIterator(input);
}


/*******************************************************************************
  Computes the URI for the given node.
********************************************************************************/
Item_t SimpleStore::getReference(Item_t node)
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
  Creates a new TempSeq. The instance can be used, e.g. for variable bindings

  @param iterator The source for the XMDInstance
  @param lazy			Hint for the store. If possible a XMDInstance should be
                  evaluated lazily. For XQueryP it might be necassary to set
                  this to false.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(Iterator* iterator, bool lazy)
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


} // namespace store
} // namespace zorba
