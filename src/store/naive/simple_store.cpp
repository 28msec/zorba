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
#include <iostream>

#include "util/rchandle.h"

#include "errors/error_manager.h"
#include "errors/fatal.h"
#include "util/hashfun.h"
#include "util/properties.h"

#include "store/util/hashmap_stringp.h"

#include "store/naive/string_pool.h"
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

#include "store/api/pul.h"

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
  theIsInitialized(false),
  theUriCounter(0),
  theTreeCounter(1),
  theNamespacePool(new StringPool(NAMESPACE_POOL_SIZE)),
  theQNamePool(new QNamePool(QNamePool::MAX_CACHE_SIZE, theNamespacePool)),
  theItemFactory(new BasicItemFactory(theNamespacePool, theQNamePool)),
  theDocuments(DEFAULT_COLLECTION_MAP_SIZE, true),
  theCollections(DEFAULT_COLLECTION_MAP_SIZE, true),
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
    theIsInitialized = true;

    theUriCounter = 0;
    theTreeCounter = 1;

    theNamespacePool->insertc("", theEmptyNs);
    theNamespacePool->insertc(XS_URI, theXmlSchemaNs);

    initTypeNames();

#ifndef NDEBUG
    theTraceLevel = Properties::instance()->storeTraceLevel();
#endif
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::initTypeNames()
{
  theSchemaTypeNames.resize(XS_LAST);

  theSchemaTypeNames[0]  = theQNamePool->insert(XS_URI, "xs", "untyped");
  theSchemaTypeNames[1]  = theQNamePool->insert(XS_URI, "xs", "untypedAtomic");
  theSchemaTypeNames[2]  = theQNamePool->insert(XS_URI, "xs", "anyType");
  theSchemaTypeNames[3]  = theQNamePool->insert(XS_URI, "xs", "anySimpleType");
  theSchemaTypeNames[4]  = theQNamePool->insert(XS_URI, "xs", "anyAtomicType");

  theSchemaTypeNames[5]  = theQNamePool->insert(XS_URI, "xs", "string");
  theSchemaTypeNames[6]  = theQNamePool->insert(XS_URI, "xs", "normalizedString");
  theSchemaTypeNames[7]  = theQNamePool->insert(XS_URI, "xs", "language");
  theSchemaTypeNames[8]  = theQNamePool->insert(XS_URI, "xs", "token");
  theSchemaTypeNames[9]  = theQNamePool->insert(XS_URI, "xs", "NMTOKEN");

  theSchemaTypeNames[10] = theQNamePool->insert(XS_URI, "xs", "anyURI");
  theSchemaTypeNames[11] = theQNamePool->insert(XS_URI, "xs", "Name");
  theSchemaTypeNames[12] = theQNamePool->insert(XS_URI, "xs", "NCName");
  theSchemaTypeNames[13] = theQNamePool->insert(XS_URI, "xs", "QName");
  theSchemaTypeNames[14] = theQNamePool->insert(XS_URI, "xs", "notation");

  theSchemaTypeNames[15] = theQNamePool->insert(XS_URI, "xs", "ID");
  theSchemaTypeNames[16] = theQNamePool->insert(XS_URI, "xs", "IDREF");

  theSchemaTypeNames[17] = theQNamePool->insert(XS_URI, "xs", "ENTITY");

  theSchemaTypeNames[18] = theQNamePool->insert(XS_URI, "xs", "dateTime");
  theSchemaTypeNames[19] = theQNamePool->insert(XS_URI, "xs", "date");
  theSchemaTypeNames[20] = theQNamePool->insert(XS_URI, "xs", "time");
  theSchemaTypeNames[21] = theQNamePool->insert(XS_URI, "xs", "duration");
  theSchemaTypeNames[22] = theQNamePool->insert(XS_URI, "xs", "dayTimeDuration");
  theSchemaTypeNames[23] = theQNamePool->insert(XS_URI, "xs", "yearMonthDuration");

  theSchemaTypeNames[24] = theQNamePool->insert(XS_URI, "xs", "float");
  theSchemaTypeNames[25] = theQNamePool->insert(XS_URI, "xs", "double");
  theSchemaTypeNames[26] = theQNamePool->insert(XS_URI, "xs", "decimal");
  theSchemaTypeNames[27] = theQNamePool->insert(XS_URI, "xs", "integer");
  theSchemaTypeNames[28] = theQNamePool->insert(XS_URI, "xs", "nonPositiveInteger");
  theSchemaTypeNames[29] = theQNamePool->insert(XS_URI, "xs", "nonNegativeInteger");
  theSchemaTypeNames[30] = theQNamePool->insert(XS_URI, "xs", "negativeInteger");
  theSchemaTypeNames[31] = theQNamePool->insert(XS_URI, "xs", "positiveInteger");

  theSchemaTypeNames[32] = theQNamePool->insert(XS_URI, "xs", "long");
  theSchemaTypeNames[33] = theQNamePool->insert(XS_URI, "xs", "int");
  theSchemaTypeNames[34] = theQNamePool->insert(XS_URI, "xs", "short");
  theSchemaTypeNames[35] = theQNamePool->insert(XS_URI, "xs", "byte");
  theSchemaTypeNames[36] = theQNamePool->insert(XS_URI, "xs", "unsignedLong");
  theSchemaTypeNames[37] = theQNamePool->insert(XS_URI, "xs", "unsignedInt");
  theSchemaTypeNames[38] = theQNamePool->insert(XS_URI, "xs", "unsignedShort");
  theSchemaTypeNames[39] = theQNamePool->insert(XS_URI, "xs", "unsignedByte");

  theSchemaTypeNames[40] = theQNamePool->insert(XS_URI, "xs", "gYearMonth");
  theSchemaTypeNames[41] = theQNamePool->insert(XS_URI, "xs", "gYear");
  theSchemaTypeNames[42] = theQNamePool->insert(XS_URI, "xs", "gMonthDay");
  theSchemaTypeNames[43] = theQNamePool->insert(XS_URI, "xs", "gDay");
  theSchemaTypeNames[44] = theQNamePool->insert(XS_URI, "xs", "gMonth");

  theSchemaTypeNames[45] = theQNamePool->insert(XS_URI, "xs", "base64Binary");
  theSchemaTypeNames[46] = theQNamePool->insert(XS_URI, "xs", "hexBinary");
  theSchemaTypeNames[47] = theQNamePool->insert(XS_URI, "xs", "boolean");
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
    ulong numTypes = theSchemaTypeNames.size();
    for (ulong i = 0; i < numTypes; i++)
      theSchemaTypeNames[i] = NULL;

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
  SYNC_CODE(AutoMutex lock(&theTreeCounterMutex);)
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
Item_t SimpleStore::loadDocument(xqpStringStore_t& uri, std::istream& stream)
{
  if (uri == NULL)
    return NULL;

  const xqpStringStore* urip = uri.getp();

  XmlNode_t root;
  bool found = theDocuments.get(urip, root);

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
    theDocuments.insert(urip, root);

  return root;
}

/*******************************************************************************
For lazy loading...
********************************************************************************/
Item_t SimpleStore::loadDocument(xqpStringStore_t& uri, std::istream* stream)
{
  Item_t    docitem;
  //do full loading for now
  docitem = loadDocument(uri, *stream);
  delete stream;
  return docitem;
}


/*******************************************************************************

********************************************************************************/
Item_t SimpleStore::loadDocument(const xqpStringStore_t& uri, Item_t docItem)
{
  if (uri == NULL || docItem == NULL)
    return NULL;

	if(!docItem->isNode())
  {
    ZORBA_ERROR_PARAM( API0021_ITEM_TO_LOAD_IS_NOT_NODE, uri, "");
		return NULL;
  }

  const xqpStringStore* urip = uri;
  XmlNode_t root = reinterpret_cast<XmlNode*>(docItem.getp());
  bool inserted = theDocuments.insert(urip, root);

  if (!inserted && docItem.getp() != root.getp())
  {
    ZORBA_ERROR_PARAM(API0020_DOCUMENT_ALREADY_EXISTS, uri, "");
    return NULL; 
  }

  ZORBA_FATAL(docItem.getp() == root.getp(), "");

	return root;
}


/*******************************************************************************
  Return an rchandle to the root node of the document corresponding to the given
  URI, or NULL if there is no document with that URI.
********************************************************************************/
Item_t SimpleStore::getDocument(const xqpStringStore_t& uri)
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
void SimpleStore::deleteDocument(const xqpStringStore_t& uri)
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
Collection_t SimpleStore::createCollection(xqpStringStore_t& uri)
{
  if (uri == NULL)
    return NULL;

  Item_t uriItem = theItemFactory->createAnyURI(uri);

  Collection_t collection(new SimpleCollection(uriItem));

  const xqpStringStore* urip = uri;
  bool inserted = theCollections.insert(urip, collection);

  if (!inserted)
  {
    ZORBA_ERROR_PARAM(API0005_COLLECTION_ALREADY_EXISTS, uri->c_str(), "");
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
  Item_t uriItem = createUri();

  xqpStringStore_t uriStr = uriItem->getStringValue();

  return createCollection(uriStr);
}


/*******************************************************************************
  Return an rchandle to the Collection object corresponding to the given URI,
  or NULL if there is no collection with that URI.
********************************************************************************/
Collection_t SimpleStore::getCollection(const xqpStringStore_t& uri)
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
void SimpleStore::deleteCollection(const xqpStringStore_t& uri)
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
  Returns Item which is identified by a reference

  @param uri Has to be an xs:URI item
  @returns referenced item if it exists, otherwise NULL
********************************************************************************/
Item_t SimpleStore::getNodeByReference(Item_t)
{
  return rchandle<Item> ( NULL );
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
