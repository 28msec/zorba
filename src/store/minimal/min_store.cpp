/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: 
 *
 */

#include <iostream>

#include "util/rchandle.h"

#include "errors/error_manager.h"
#include "errors/fatal.h"
#include "util/hashfun.h"
#include "util/properties.h"

#include "store/util/pointer_hashmap_string.h"

//#include "store/naive/string_pool.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_temp_seq.h"
#include "store/minimal/min_collection.h"
//#include "store/naive/qname_pool.h"
#include "store/minimal/min_loader.h"
#include "store/minimal/min_store_defs.h"
#include "store/minimal/min_node_items.h"
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_node_iterators.h"
#include "store/minimal/min_item_factory.h"
#include "store/minimal/min_query_context.h"

#include "store/api/pul.h"

#include "system/globalenv.h"
#include "types/root_typemanager.h"

namespace zorba { namespace store {

typedef rchandle<TempSeq> TempSeq_t;

const ulong SimpleStore::NAMESPACE_POOL_SIZE = 128;
const ulong SimpleStore::DEFAULT_COLLECTION_MAP_SIZE = 32;

const char* SimpleStore::XS_URI = "http://www.w3.org/2001/XMLSchema";
const char* SimpleStore::XML_URI = "http://www.w3.org/2001/XML/1998/namespace";


/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
  :
  theIsInitialized(0),
  theUriCounter(0),
  theTreeCounter(1),
//  theNamespacePool(new StringPool(NAMESPACE_POOL_SIZE)),
//  theQNamePool(new QNamePool(QNamePool::MAX_CACHE_SIZE)),
  theItemFactory(new BasicItemFactory),
  theDocuments(DEFAULT_COLLECTION_MAP_SIZE),
  theCollections(DEFAULT_COLLECTION_MAP_SIZE),
  theQueryContextContainer(new QueryContextContainer)
#ifndef NDEBUG
  ,theTraceLevel(0)
#endif
{
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::init()
{
  if (!theIsInitialized)
  {
    theUriCounter = 0;
    theTreeCounter = 1;

//    theNamespacePool->insertc("", theEmptyNs);
//    theNamespacePool->insertc(XS_URI, theXmlSchemaNs);

    //initTypeNames();

#ifndef NDEBUG
    theTraceLevel = Properties::instance()->storeTraceLevel();
#endif
  } else if(theIsInitialized == 1)
  {
    initTypeNames();
  }
  theIsInitialized++;
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::initTypeNames()
{
  theSchemaTypeNames.resize(XS_LAST);

  RootTypeManager   &typemanager = GENV_TYPESYSTEM;

  theSchemaTypeNames[XS_UNTYPED]  = typemanager.XS_UNTYPED_QNAME;//new QNameItemImpl(XS_URI, "xs", "untyped");
  theSchemaTypeNames[XS_UNTYPED_ATOMIC]  = typemanager.XS_UNTYPED_ATOMIC_QNAME;//new QNameItemImpl(XS_URI, "xs", "untypedAtomic");
  theSchemaTypeNames[XS_ANY]  = typemanager.XS_ANY_TYPE_QNAME;//new QNameItemImpl(XS_URI, "xs", "anyType");
  theSchemaTypeNames[XS_ANY_SIMPLE]  = typemanager.XS_ANY_SIMPLE_TYPE_QNAME;//new QNameItemImpl(XS_URI, "xs", "anySimpleType");
  theSchemaTypeNames[XS_ANY_ATOMIC]  = typemanager.XS_ANY_ATOMIC_QNAME;//new QNameItemImpl(XS_URI, "xs", "anyAtomicType");

  theSchemaTypeNames[XS_STRING]  = typemanager.XS_STRING_QNAME;//new QNameItemImpl(XS_URI, "xs", "string");
  theSchemaTypeNames[XS_NORMALIZED_STRING]  = typemanager.XS_NORMALIZED_STRING_QNAME;//new QNameItemImpl(XS_URI, "xs", "normalizedString");
  theSchemaTypeNames[XS_LANGUAGE]  = typemanager.XS_LANGUAGE_QNAME;//new QNameItemImpl(XS_URI, "xs", "language");
  theSchemaTypeNames[XS_TOKEN]  = typemanager.XS_TOKEN_QNAME;//new QNameItemImpl(XS_URI, "xs", "token");
  theSchemaTypeNames[XS_NMTOKEN]  = typemanager.XS_NMTOKEN_QNAME;//new QNameItemImpl(XS_URI, "xs", "NMTOKEN");

  theSchemaTypeNames[XS_ANY_URI] = typemanager.XS_ANY_URI_QNAME;//new QNameItemImpl(XS_URI, "xs", "anyURI");
  theSchemaTypeNames[XS_NAME] = typemanager.XS_NAME_QNAME;//new QNameItemImpl(XS_URI, "xs", "Name");
  theSchemaTypeNames[XS_NCNAME] = typemanager.XS_NCNAME_QNAME;//new QNameItemImpl(XS_URI, "xs", "NCName");
  theSchemaTypeNames[XS_QNAME] = typemanager.XS_QNAME_QNAME;//new QNameItemImpl(XS_URI, "xs", "QName");
  theSchemaTypeNames[XS_NOTATION] = typemanager.XS_NOTATION_QNAME;//new QNameItemImpl(XS_URI, "xs", "notation");

  theSchemaTypeNames[XS_ID] = typemanager.XS_ID_QNAME;//new QNameItemImpl(XS_URI, "xs", "ID");
  theSchemaTypeNames[XS_IDREF] = typemanager.XS_IDREF_QNAME;//new QNameItemImpl(XS_URI, "xs", "IDREF");

  theSchemaTypeNames[XS_ENTITY] = typemanager.XS_ENTITY_QNAME;//new QNameItemImpl(XS_URI, "xs", "ENTITY");

  theSchemaTypeNames[XS_DATETIME] = typemanager.XS_DATETIME_QNAME;//new QNameItemImpl(XS_URI, "xs", "dateTime");
  theSchemaTypeNames[XS_DATE] = typemanager.XS_DATE_QNAME;//new QNameItemImpl(XS_URI, "xs", "date");
  theSchemaTypeNames[XS_TIME] = typemanager.XS_TIME_QNAME;//new QNameItemImpl(XS_URI, "xs", "time");
  theSchemaTypeNames[XS_DURATION] = typemanager.XS_DURATION_QNAME;//new QNameItemImpl(XS_URI, "xs", "duration");
  theSchemaTypeNames[XS_DT_DURATION] = typemanager.XS_DT_DURATION_QNAME;//new QNameItemImpl(XS_URI, "xs", "dayTimeDuration");
  theSchemaTypeNames[XS_YM_DURATION] = typemanager.XS_YM_DURATION_QNAME;//new QNameItemImpl(XS_URI, "xs", "yearMonthDuration");

  theSchemaTypeNames[XS_FLOAT] = typemanager.XS_FLOAT_QNAME;//new QNameItemImpl(XS_URI, "xs", "float");
  theSchemaTypeNames[XS_DOUBLE] = typemanager.XS_DOUBLE_QNAME;//new QNameItemImpl(XS_URI, "xs", "double");
  theSchemaTypeNames[XS_DECIMAL] = typemanager.XS_DECIMAL_QNAME;//new QNameItemImpl(XS_URI, "xs", "decimal");
  theSchemaTypeNames[XS_INTEGER] = typemanager.XS_INTEGER_QNAME;//new QNameItemImpl(XS_URI, "xs", "integer");
  theSchemaTypeNames[XS_NON_POSITIVE_INTEGER] = typemanager.XS_NON_POSITIVE_INTEGER_QNAME;//new QNameItemImpl(XS_URI, "xs", "nonPositiveInteger");
  theSchemaTypeNames[XS_NON_NEGATIVE_INTEGER] = typemanager.XS_NON_NEGATIVE_INTEGER_QNAME;//new QNameItemImpl(XS_URI, "xs", "nonNegativeInteger");
  theSchemaTypeNames[XS_NEGATIVE_INTEGER] = typemanager.XS_NEGATIVE_INTEGER_QNAME;//new QNameItemImpl(XS_URI, "xs", "negativeInteger");
  theSchemaTypeNames[XS_POSITIVE_INTEGER] = typemanager.XS_POSITIVE_INTEGER_QNAME;//new QNameItemImpl(XS_URI, "xs", "positiveInteger");

  theSchemaTypeNames[XS_LONG] = typemanager.XS_LONG_QNAME;//new QNameItemImpl(XS_URI, "xs", "long");
  theSchemaTypeNames[XS_INT] = typemanager.XS_INT_QNAME;//new QNameItemImpl(XS_URI, "xs", "int");
  theSchemaTypeNames[XS_SHORT] = typemanager.XS_SHORT_QNAME;//new QNameItemImpl(XS_URI, "xs", "short");
  theSchemaTypeNames[XS_BYTE] = typemanager.XS_BYTE_QNAME;//new QNameItemImpl(XS_URI, "xs", "byte");
  theSchemaTypeNames[XS_UNSIGNED_LONG] = typemanager.XS_UNSIGNED_LONG_QNAME;//new QNameItemImpl(XS_URI, "xs", "unsignedLong");
  theSchemaTypeNames[XS_UNSIGNED_INT] = typemanager.XS_UNSIGNED_INT_QNAME;//new QNameItemImpl(XS_URI, "xs", "unsignedInt");
  theSchemaTypeNames[XS_UNSIGNED_SHORT] = typemanager.XS_UNSIGNED_SHORT_QNAME;//new QNameItemImpl(XS_URI, "xs", "unsignedShort");
  theSchemaTypeNames[XS_UNSIGNED_BYTE] = typemanager.XS_UNSIGNED_BYTE_QNAME;//new QNameItemImpl(XS_URI, "xs", "unsignedByte");

  theSchemaTypeNames[XS_GYEAR_MONTH] = typemanager.XS_GYEAR_MONTH_QNAME;//new QNameItemImpl(XS_URI, "xs", "gYearMonth");
  theSchemaTypeNames[XS_GYEAR] = typemanager.XS_GYEAR_QNAME;//new QNameItemImpl(XS_URI, "xs", "gYear");
  theSchemaTypeNames[XS_GMONTH_DAY] = typemanager.XS_GMONTH_DAY_QNAME;//new QNameItemImpl(XS_URI, "xs", "gMonthDay");
  theSchemaTypeNames[XS_GDAY] = typemanager.XS_GDAY_QNAME;//new QNameItemImpl(XS_URI, "xs", "gDay");
  theSchemaTypeNames[XS_GMONTH] = typemanager.XS_GMONTH_QNAME;//new QNameItemImpl(XS_URI, "xs", "gMonth");

  theSchemaTypeNames[XS_BASE64BINARY] = typemanager.XS_BASE64BINARY_QNAME;//new QNameItemImpl(XS_URI, "xs", "base64Binary");
  theSchemaTypeNames[XS_HEXBINARY] = typemanager.XS_HEXBINARY_QNAME;//new QNameItemImpl(XS_URI, "xs", "hexBinary");
  theSchemaTypeNames[XS_BOOLEAN] = typemanager.XS_BOOLEAN_QNAME;//new QNameItemImpl(XS_URI, "xs", "boolean");
}

Item *SimpleStore::getTypeQName(Item *item)
{
  QNameItemImpl *qname = dynamic_cast<QNameItemImpl*>(item);
  if(!qname)
    return item;

  checked_vector<Item_t>::const_iterator  i;
  const xqpStringStore  *ln = qname->getLocalName();
  for(i=theSchemaTypeNames.begin(); i != theSchemaTypeNames.end(); i++)
  {
    if((*i)->getLocalName()->byteEqual(*ln))
      return &*(*i);
  }

  return item;
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

//  if (theQNamePool != NULL)
//  {
//    ulong numTypes = theSchemaTypeNames.size();
//    for (ulong i = 0; i < numTypes; i++)
//      theSchemaTypeNames[i] = NULL;
//
//    delete theQNamePool;
//    theQNamePool = NULL;
//  }
//
//  if (theNamespacePool != NULL)
//  {
//    theEmptyNs = NULL;
//    theXmlSchemaNs = NULL;
//
//    delete theNamespacePool;
//    theNamespacePool = NULL;
//  }
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
XmlLoader* SimpleStore::getXmlLoader(error::ErrorManager* aErrorManager)
{
  return new XmlLoader(aErrorManager);
}


/*******************************************************************************

********************************************************************************/
QueryContext& SimpleStore::getQueryContext(ulong queryId)
{
  return theQueryContextContainer->getContext(queryId);
}


void SimpleStore::deleteQueryContext(ulong queryId)
{
  theQueryContextContainer->removeContext(queryId);
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

  XmlNode_t root;
  bool found = theDocuments.get(uri, root);

  if (found)
    return root.getp();

  error::ErrorManager lErrorManager;
  std::auto_ptr<XmlLoader> loader(getXmlLoader(&lErrorManager));

  root = loader->loadXml(uri, stream);
  if (lErrorManager.hasErrors()) 
  {
    throw lErrorManager.getErrors().front();
  }

  if (root != NULL)
    theDocuments.insert(uri, root);

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
    ZORBA_ERROR_PARAM( ZorbaError::API0021_ITEM_TO_LOAD_IS_NOT_NODE, uri, "");
		return NULL;
  }

  XmlNode_t root = reinterpret_cast<XmlNode*>(docItem.getp());
  bool inserted = theDocuments.insert(uri, root);

  if (!inserted && docItem.getp() != root.getp())
  {
    ZORBA_ERROR_PARAM(ZorbaError::API0020_DOCUMENT_ALREADY_EXISTS, uri, "");
    return NULL; 
  }

  ZORBA_FATAL(docItem.getp() == root.getp(), "");

	return root;
}


/*******************************************************************************
  Return an rchandle to the root node of the document corresponding to the given
  URI, or NULL if there is no document with that URI.
********************************************************************************/
Item_t SimpleStore::getDocument(xqpStringStore* uri)
{
  if (uri == NULL)
    return NULL;

  XmlNode_t root;
  bool found = theDocuments.get(uri, root);
  if (found)
    return root.getp();

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

  bool inserted = theCollections.insert(uri, collection);

  if (!inserted)
  {
    ZORBA_ERROR_PARAM(ZorbaError::API0005_COLLECTION_ALREADY_EXISTS, uri->c_str(), "");
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

  Collection_t collection;
  if (theCollections.get(uri, collection) )
    return collection.getp();
  else
    return NULL;
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
  ZORBA_FATAL(node1->isNode(), "");
  ZORBA_FATAL(node2->isNode(), "");

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
    TimeTravel timetravel)
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
    TimeTravel timetravel)
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

  @param iterator   The source for the XMDInstance
  @param copyNodes  If true, all nodes are copied before they are saved in the
                    temp sequence.
  @param lazy		    Hint for the store. If possible a XMDInstance should be
                    evaluated lazily. For XQueryP it might be necassary to set
                    this to false.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(Iterator* iterator, bool copyNodes, bool lazy)
{
  TempSeq_t tempSeq = new SimpleTempSeq(iterator, copyNodes, lazy);
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
