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
#include "stdafx.h"

#include <iostream>
#include <climits>
#include <memory>

#include <libxml/parser.h>

#include "zorbautils/hashfun.h"
#include "zorbautils/fatal.h"
#include "zorbatypes/rchandle.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "store/api/pul.h"
#include "store/api/xs_type_codes.h"

#include "store/naive/properties.h"
#include "store/naive/string_pool.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_lazy_temp_seq.h"
#include "store/naive/simple_collection.h"
#include "store/naive/collection_set.h"
#include "store/naive/simple_index.h"
#include "store/naive/simple_index_value.h"
#include "store/naive/simple_index_general.h"
#include "store/naive/simple_ic.h"
#include "store/naive/qname_pool.h"
#include "store/naive/loader.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"
#include "store/naive/dataguide.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_item_factory.h"
#include "store/naive/simple_iterator_factory.h"
#include "store/naive/query_context.h"
#include "store/naive/item_iterator.h"
#include "store/naive/node_factory.h"
#include "store/naive/name_iterator.h"
#include "store/naive/document_name_iterator.h"
#include "store/naive/pul_primitive_factory.h"

#include "util/cxx_util.h"
#include "util/uuid/uuid.h"
#include "zorbautils/string_util.h"

#ifndef ZORBA_NO_FULL_TEXT
#include "runtime/full_text/default_tokenizer.h"
#include "runtime/full_text/stemmer.h"
#endif /* ZORBA_NO_FULL_TEXT */

namespace zorba
{

namespace simplestore
{

typedef rchandle<store::TempSeq> TempSeq_t;


/*******************************************************************************
  SimpleStore static data
********************************************************************************/
const ulong SimpleStore::NAMESPACE_POOL_SIZE = 128;

const char* SimpleStore::XS_URI = "http://www.w3.org/2001/XMLSchema";
const char* SimpleStore::XML_URI = "http://www.w3.org/2001/XML/1998/namespace";
const char* SimpleStore::ZXSE_URI = "http://www.zorba-xquery.com/zorba/schema-extensions";

const ulong SimpleStore::XML_URI_LEN = sizeof(SimpleStore::XML_URI);


/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
  :
  theNumUsers(0),
  theUriCounter(0),
  theCollectionCounter(1),
  theTreeCounter(1),
  theNamespacePool(NULL),
  theQNamePool(NULL),
  theItemFactory(NULL),
  theIteratorFactory(NULL),
  theNodeFactory(NULL),
  thePULFactory(NULL),
  theDocuments(CollectionSet::DEFAULT_COLLECTION_MAP_SIZE, true),
  theCollections(0),
  theIndices(0, NULL, CollectionSet::DEFAULT_COLLECTION_MAP_SIZE, true),
  theICs(0, NULL, CollectionSet::DEFAULT_COLLECTION_MAP_SIZE, true),
  theHashMaps(0, NULL, CollectionSet::DEFAULT_COLLECTION_MAP_SIZE, true),
  theTraceLevel(0),
  theNodeToReferencesMap(128, true)
#ifndef ZORBA_NO_FULL_TEXT
  , theStemmerProvider( nullptr )
  , theTokenizerProvider( nullptr )
#endif /* ZORBA_NO_FULL_TEXT */
{
}


/*******************************************************************************

********************************************************************************/
SimpleStore::~SimpleStore()
{
  shutdown(false);
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::init()
{
  SYNC_CODE(AutoLock lock(getGlobalLock(), Lock::WRITE);)

  //zorba::zstring zstr("foo");
  //zorba::zstring_p pstr;
  //zorba::zstring_b bstr;

  if (theNumUsers == 0)
  {
    // This initializes the libxml2 library and checks potential ABI mismatches
    // between the version it was compiled for and the actual  shared library used.
    // Calling its init is done here because we also want to free it at the end,
    // i.e. when the store is shutdown
    LIBXML_TEST_VERSION

    store::Properties::load(0, NULL);

    theUriCounter = 0;
    theCollectionCounter = 1;
    theTreeCounter = 1;

    theNamespacePool = new StringPool(NAMESPACE_POOL_SIZE);

    theNamespacePool->insertc("", theEmptyNs);
    theNamespacePool->insertc(XS_URI, theXmlSchemaNs);

    theQNamePool = new QNamePool(QNamePool::MAX_CACHE_SIZE, theNamespacePool);

    // createItemFactory uses theNamespacePool and theQNamePool
    // they have to be created before this function is called
    theItemFactory = createItemFactory();

    initTypeNames();

    theIteratorFactory = new SimpleIteratorFactory();

    theNodeFactory = createNodeFactory();

    thePULFactory = createPULPrimitiveFactory();

    theTraceLevel = store::Properties::instance()->storeTraceLevel();

    theCollections = createCollectionSet();

    StoreManagerImpl::theStore = this;
  }

  ++theNumUsers;
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::initTypeNames()
{
  const char* ns = XS_URI;
  BasicItemFactory* f = theItemFactory;

  theSchemaTypeNames.resize(store::XS_LAST);

  f->createQName(XS_UNTYPED_QNAME, ns, "xs", "untyped");

  f->createQName(XS_ANY_QNAME, ns, "xs", "anyType");

  f->createQName(XS_ANY_SIMPLE_QNAME, ns, "xs", "anySimpleType");

  f->createQName(theSchemaTypeNames[store::XS_ANY_ATOMIC],     ns, "xs", "anyAtomicType");

  f->createQName(theSchemaTypeNames[store::XS_UNTYPED_ATOMIC], ns, "xs", "untypedAtomic");

  f->createQName(theSchemaTypeNames[store::XS_ANY_URI],        ns, "xs", "anyURI");

  f->createQName(theSchemaTypeNames[store::XS_QNAME],          ns, "xs", "QName");

  f->createQName(theSchemaTypeNames[store::XS_NOTATION],       ns, "xs", "NOTATION");

  f->createQName(theSchemaTypeNames[store::XS_STRING],         ns, "xs", "string");
  f->createQName(theSchemaTypeNames[store::XS_NORMALIZED_STRING], ns, "xs", "normalizedString");
  f->createQName(theSchemaTypeNames[store::XS_TOKEN],          ns, "xs", "token");
  f->createQName(theSchemaTypeNames[store::XS_NMTOKEN],        ns, "xs", "NMTOKEN");
  f->createQName(theSchemaTypeNames[store::XS_LANGUAGE],       ns, "xs", "language");
  f->createQName(theSchemaTypeNames[store::XS_NAME],           ns, "xs", "Name");
  f->createQName(theSchemaTypeNames[store::XS_NCNAME],         ns, "xs", "NCName");
  f->createQName(theSchemaTypeNames[store::XS_ID],             ns, "xs", "ID");
  f->createQName(theSchemaTypeNames[store::XS_IDREF],          ns, "xs", "IDREF");
  f->createQName(theSchemaTypeNames[store::XS_ENTITY],         ns, "xs", "ENTITY");

  f->createQName(theSchemaTypeNames[store::XS_DATETIME],       ns, "xs", "dateTime");
  f->createQName(theSchemaTypeNames[store::XS_DATE],           ns, "xs", "date");
  f->createQName(theSchemaTypeNames[store::XS_TIME],           ns, "xs", "time");
  f->createQName(theSchemaTypeNames[store::XS_GYEAR_MONTH],    ns, "xs", "gYearMonth");
  f->createQName(theSchemaTypeNames[store::XS_GYEAR],          ns, "xs", "gYear");
  f->createQName(theSchemaTypeNames[store::XS_GMONTH_DAY],     ns, "xs", "gMonthDay");
  f->createQName(theSchemaTypeNames[store::XS_GDAY],           ns, "xs", "gDay");
  f->createQName(theSchemaTypeNames[store::XS_GMONTH],         ns, "xs", "gMonth");

  f->createQName(theSchemaTypeNames[store::XS_DURATION],       ns, "xs", "duration");
  f->createQName(theSchemaTypeNames[store::XS_DT_DURATION],    ns, "xs", "dayTimeDuration");
  f->createQName(theSchemaTypeNames[store::XS_YM_DURATION],    ns, "xs", "yearMonthDuration");

  f->createQName(theSchemaTypeNames[store::XS_FLOAT],          ns, "xs", "float");
  f->createQName(theSchemaTypeNames[store::XS_DOUBLE],         ns, "xs", "double");
  f->createQName(theSchemaTypeNames[store::XS_DECIMAL],        ns, "xs", "decimal");
  f->createQName(theSchemaTypeNames[store::XS_INTEGER],        ns, "xs", "integer");
  f->createQName(theSchemaTypeNames[store::XS_NON_POSITIVE_INTEGER], ns, "xs", "nonPositiveInteger");
  f->createQName(theSchemaTypeNames[store::XS_NON_NEGATIVE_INTEGER], ns, "xs", "nonNegativeInteger");
  f->createQName(theSchemaTypeNames[store::XS_NEGATIVE_INTEGER], ns, "xs", "negativeInteger");
  f->createQName(theSchemaTypeNames[store::XS_POSITIVE_INTEGER], ns, "xs", "positiveInteger");

  f->createQName(theSchemaTypeNames[store::XS_LONG],           ns, "xs", "long");
  f->createQName(theSchemaTypeNames[store::XS_INT],            ns, "xs", "int");
  f->createQName(theSchemaTypeNames[store::XS_SHORT],          ns, "xs", "short");
  f->createQName(theSchemaTypeNames[store::XS_BYTE],           ns, "xs", "byte");
  f->createQName(theSchemaTypeNames[store::XS_UNSIGNED_LONG],  ns, "xs", "unsignedLong");
  f->createQName(theSchemaTypeNames[store::XS_UNSIGNED_INT],   ns, "xs", "unsignedInt");
  f->createQName(theSchemaTypeNames[store::XS_UNSIGNED_SHORT], ns, "xs", "unsignedShort");
  f->createQName(theSchemaTypeNames[store::XS_UNSIGNED_BYTE],  ns, "xs", "unsignedByte");

  f->createQName(theSchemaTypeNames[store::XS_BASE64BINARY],   ns, "xs", "base64Binary");
  f->createQName(theSchemaTypeNames[store::XS_HEXBINARY],      ns, "xs", "hexBinary");
  f->createQName(theSchemaTypeNames[store::XS_BOOLEAN],        ns, "xs", "boolean");

  for (ulong i = 0; i < store::XS_LAST; ++i)
  {
    theSchemaTypeCodes[theSchemaTypeNames[i].getp()] = 
    static_cast<store::SchemaTypeCode>(i);
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::shutdown(bool soft)
{
  SYNC_CODE(AutoLock lock(getGlobalLock(), Lock::WRITE);)

  if (theNumUsers == 0)
    return;

  --theNumUsers;

  if (theNumUsers == 0 || soft == false)
  {
    theIndices.clear();
    theICs.clear();
    theHashMaps.clear();

    if (theCollections != NULL)
    {
      theCollections->clear();
      destroyCollectionSet(theCollections);
      theCollections = NULL;
    }

    theDocuments.clear();

    if (thePULFactory != NULL)
    {
      destroyPULPrimitiveFactory(thePULFactory);
      thePULFactory = NULL;
    }

    if (theNodeFactory != NULL)
    {
      destroyNodeFactory(theNodeFactory);
      theNodeFactory = NULL;
    }

    if (theItemFactory != NULL)
    {
      destroyItemFactory(theItemFactory);
      theItemFactory = NULL;
    }

    if (theQNamePool != NULL)
    {
      csize numTypes = theSchemaTypeNames.size();
      for (csize i = 0; i < numTypes; ++i)
        theSchemaTypeNames[i] = NULL;

      XS_UNTYPED_QNAME = NULL;
      XS_ANY_QNAME = NULL;
      XS_ANY_SIMPLE_QNAME = NULL;

      delete theQNamePool;
      theQNamePool = NULL;
    }

    if (theNamespacePool != NULL)
    {
      theEmptyNs.~zstring();
      theXmlSchemaNs.~zstring();

      delete theNamespacePool;
      theNamespacePool = NULL;
    }

    if (theIteratorFactory != NULL)
    {
      delete theIteratorFactory;
      theIteratorFactory = NULL;
    }

    if (theNodeFactory != NULL)
    {
      delete theNodeFactory;
      theNodeFactory = NULL;
    }

    if (theNodeToReferencesMap.size() > 0)
    {
      NodeRefMap::iterator iter = theNodeToReferencesMap.begin();
      NodeRefMap::iterator end = theNodeToReferencesMap.end();
      for (; iter != end; ++iter)
      {
        std::cerr << "Reference: " << (*iter).second
                  << "is still in the nodes to references map" << std::endl;
      }
      ZORBA_FATAL(0, theNodeToReferencesMap.size() + 
                     " node references still in the nodes to references map");
    }

    if (theReferencesToNodeMap.size() > 0)
    {
      RefNodeMap::iterator iter = theReferencesToNodeMap.begin();
      RefNodeMap::iterator end = theReferencesToNodeMap.end();
      for (; iter != end; ++iter)
      {
        std::cerr << "Reference: " << (*iter).first 
                  << "is still in the references to nodes map" << std::endl;
      }
      ZORBA_FATAL(0, theReferencesToNodeMap.size() +
                     " node references still in the references to nodes map");
    }

    // do cleanup of the libxml2 library
    // however, after that, a user will have to call
    // LIBXML_TEST_VERSION if he wants to use libxml2
    // beyond the lifecycle of zorba
    xmlCleanupParser();

    StoreManagerImpl::theStore = NULL;
  }
}


/*******************************************************************************

*******************************************************************************/
PULPrimitiveFactory*
SimpleStore::createPULPrimitiveFactory() const
{
  return new PULPrimitiveFactory();
}


/*******************************************************************************

*******************************************************************************/
void
SimpleStore::destroyPULPrimitiveFactory(PULPrimitiveFactory* f) const
{
  delete f;
}

/*******************************************************************************

*******************************************************************************/
CollectionSet* SimpleStore::createCollectionSet() const
{
  return new CollectionSet();
}


/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyCollectionSet(CollectionSet* c) const
{
  delete c;
}


/*******************************************************************************

*******************************************************************************/
NodeFactory* SimpleStore::createNodeFactory() const
{
  return new NodeFactory();
}


/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyNodeFactory(NodeFactory* f) const
{
  delete f;
}


/*******************************************************************************

*******************************************************************************/
BasicItemFactory* SimpleStore::createItemFactory() const
{
  return new BasicItemFactory(theNamespacePool, theQNamePool);
}


/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyItemFactory(BasicItemFactory* f) const
{
  delete f;
}


/*******************************************************************************

********************************************************************************/
store::ItemFactory* SimpleStore::getItemFactory() const
{
  return theItemFactory;
}


/*******************************************************************************
  Create an id for a new collection
********************************************************************************/
ulong SimpleStore::createCollectionId()
{
  SYNC_CODE(AutoMutex lock(&theCollectionCounterMutex);)
  return theCollectionCounter++;
}


/*******************************************************************************
  create a tree id for a new tree that does not belong to any collection.
********************************************************************************/
ulong SimpleStore::createTreeId()
{
  SYNC_CODE(AutoMutex lock(&theTreeCounterMutex);)
  return theTreeCounter++;
}


/*******************************************************************************

********************************************************************************/
XmlLoader* SimpleStore::getXmlLoader(XQueryDiagnostics* aXQueryDiagnostics,
    const store::LoadProperties& loadProperties)
{
  if (loadProperties.getEnableExtParsedEntity())
    return new FragmentXmlLoader(theItemFactory,
                                 aXQueryDiagnostics,
                                 store::Properties::instance()->buildDataguide());
  else if (loadProperties.getEnableDtd())
    return new DtdXmlLoader(theItemFactory,
                            aXQueryDiagnostics,
                            store::Properties::instance()->buildDataguide(),
                            loadProperties.getEnableExtParsedEntity());
  else
    return new FastXmlLoader(theItemFactory,
                             aXQueryDiagnostics,
                             store::Properties::instance()->buildDataguide());
}


/*******************************************************************************
  Create an index with a given URI and return an rchandle to the index object.
  If an index with the given URI exists already and the index we want to create
  is not a temporary one, raise an error.
********************************************************************************/
store::Index_t SimpleStore::createIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec,
    store::Iterator* sourceIter)
{
  store::Item* qname2 = const_cast<store::Item*>(qname.getp());
  store::Index_t index;

  if (!spec.theIsTemp && theIndices.get(qname.getp(), index))
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0001_INDEX_ALREADY_EXISTS,
    ERROR_PARAMS(qname->getStringValue()));
  }

  if (spec.theIsGeneral && spec.theIsSorted)
  {
    index = new GeneralTreeIndex(qname, spec);
    populateGeneralIndex(index, sourceIter, spec.getNumColumns());
  }
  else if (spec.theIsSorted)
  {
    index = new ValueTreeIndex(qname, spec);
    populateValueIndex(index, sourceIter, spec.getNumColumns());
  }
  else if (spec.theIsGeneral)
  {
    index = new GeneralHashIndex(qname, spec);
    populateGeneralIndex(index, sourceIter, spec.getNumColumns());
  }
  else
  {
    index = new ValueHashIndex(qname, spec);
    populateValueIndex(index, sourceIter, spec.getNumColumns());
  }

  if (!spec.theIsTemp)
  {
    theIndices.insert(qname2, index);
  }

  return index;
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::populateValueIndex(
    const store::Index_t& aIndex,
    store::Iterator* aSourceIter,
    ulong aNumColumns)
{
  if (!aSourceIter)
    return;

  store::Item_t domainItem;
  store::IndexKey* key = NULL;

  ValueIndex* index = static_cast<ValueIndex*>(aIndex.getp());

  aSourceIter->open();

  try
  {
    while (aSourceIter->next(domainItem))
    {
      if (domainItem->isNode() &&
          domainItem->getCollection() == NULL &&
          !index->isTemporary())
      {
        RAISE_ERROR_NO_LOC(zerr::ZDDY0020_INDEX_DOMAIN_NODE_NOT_IN_COLLECTION,
        ERROR_PARAMS(index->getName()->getStringValue()));
      }

      if (key == NULL)
        key = new store::IndexKey(aNumColumns);

      for (ulong i = 0; i < aNumColumns; ++i)
      {
        if (!aSourceIter->next((*key)[i]))
        {
          // The source iter is a ValueIndexEntryBuilderIterator, whose next()
          // method is guaranteed to return true exactly once. The result from
          // this single successful next() may be a NULL item.
          RAISE_ERROR_NO_LOC(zerr::ZXQP0003_INTERNAL_ERROR,
          ERROR_PARAMS(ZED(IncompleteKeyInIndexBuild)));
        }
      }

      index->insert(key, domainItem);
    }
  }
  catch(...)
  {
    if (key != NULL)
      delete key;

    aSourceIter->close();
    throw;
  }

  if (key != NULL)
    delete key;

  aSourceIter->close();
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::populateGeneralIndex(
    const store::Index_t& idx,
    store::Iterator* sourceIter,
    ulong numColumns)
{
  store::Item_t domainNode;
  store::Item_t firstKeyItem;
  store::Item_t keyItem;

  GeneralIndex* index = static_cast<GeneralIndex*>(idx.getp());

  sourceIter->open();

  try
  {
    if (sourceIter->next(domainNode))
    {
      bool more = true;

      assert(domainNode->isNode());
      assert(keyItem == NULL);

      // Compute the keys associated with the current domain node. Note: We
      // must check whether the domain node has more than one key, before we
      // do any insertions in the index.
      while (more)
      {
        if (domainNode->getCollection() == NULL && !index->isTemporary())
        {
          RAISE_ERROR_NO_LOC(zerr::ZDDY0020_INDEX_DOMAIN_NODE_NOT_IN_COLLECTION,
          ERROR_PARAMS(index->getName()->getStringValue()));
        }

        // Compute 1st key, or next domain node
        more = sourceIter->next(firstKeyItem);

        // If current node has no keys, put it in the "null" entry and continue
        // with the next domain node, if nay.
        if (!more || firstKeyItem->isNode())
        {
          index->insert(keyItem, domainNode);

          domainNode.transfer(firstKeyItem);
          continue;
        }

        // Compute 2nd key, or next domain node
        more = sourceIter->next(keyItem);

        // If current domain node has exactly 1 key, insert it in the index
        // and continue with next domain node, if any.
        if (!more || keyItem->isNode())
        {
          index->insert(firstKeyItem, domainNode);

          domainNode.transfer(keyItem);
          continue;
        }

        // Current domain node has at least 2 keys. So insert them in the index.
        // Note: we have to copy the domainNode rchandle because index->insert()
        // will transfer the given node.
        index->setMultiKey();

        store::Item_t node = domainNode;
        index->insert(firstKeyItem, node);
        node = domainNode;
        index->insert(keyItem, node);

        // Compute next keys or next domain node.
        while ((more = sourceIter->next(keyItem)))
        {
          if (keyItem->isNode())
          {
            domainNode.transfer(keyItem);
            break;
          }

          node = domainNode;
          index->insert(keyItem, node);
        }
      }
    }
  }
  catch(...)
  {
    sourceIter->close();

    throw;
  }

  sourceIter->close();
}


/*******************************************************************************
  Refreshes an index with a given URI and return an rchandle to the index object.
  If an index with the given URI exists already and the index we want to create
  is not a temporary one, raise an error.
********************************************************************************/
store::Index_t SimpleStore::refreshIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec,
    store::Iterator* sourceIter)
{
  store::Index_t index;
  store::Item* non_const_items = const_cast<store::Item*>(qname.getp());

  if (!theIndices.get(non_const_items, index))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0002_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( qname->getStringValue() )
    );
  }

  deleteIndex(qname);

  try
  {
    createIndex(qname, index->getSpecification(), sourceIter);
  }
  catch (...)
  {
    addIndex(index);
    throw;
  }

  return index;
}

/*******************************************************************************

********************************************************************************/
void SimpleStore::addIndex(store::Index_t& index)
{
  if (index == NULL)
    return;

  store::Item* qname = const_cast<store::Item*>(index->getName());

  theIndices.insert(qname, index);
}


/*******************************************************************************

********************************************************************************/
store::Index* SimpleStore::getIndex(const store::Item* qname)
{
  if (qname == NULL)
    return NULL;

  store::Item* qname2 = const_cast<store::Item*>(qname);
  store::Index_t index;

  if (theIndices.get(qname2, index))
    return index.getp();

  return NULL;
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::deleteIndex(const store::Item* qname)
{
  if (qname == NULL)
    return;

  store::Item* qname2 = const_cast<store::Item*>(qname);

  theIndices.erase(qname2);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleStore::listIndexNames()
{
  return new NameIterator<IndexSet>(theIndices);
}


/*******************************************************************************

********************************************************************************/
store::IC_t SimpleStore::activateIC(
    const store::Item_t& icQName,
    const store::Item_t& collectionQName,
    bool& isApplied)
{
  ZORBA_ASSERT(icQName != NULL);

  store::Item* qname = icQName.getp();

  store::IC_t ic;

  if (theICs.get(qname, ic))
  {
    return ic; // already activated => noop
  }

  ic = new ICCollectionImpl(icQName, collectionQName);

  theICs.insert(qname, ic);

  isApplied=true;
  return ic;
}


/*******************************************************************************

********************************************************************************/
store::IC_t SimpleStore::activateForeignKeyIC(
    const store::Item_t& icQName,
    const store::Item_t& fromCollectionQName,
    const store::Item_t& toCollectionQName,
    bool& isApplied)
{
  ZORBA_ASSERT(icQName != NULL);

  store::Item* qname = const_cast<store::Item*>(icQName.getp());

  store::IC_t ic;

  if (theICs.get(qname, ic))
  {
    return ic; // already activated => noop
  }

  ic = new ICForeignKeyImpl(qname, fromCollectionQName, toCollectionQName);

  theICs.insert(qname, ic);

  isApplied=true;
  return ic;
}


store::IC_t
SimpleStore::deactivateIC(const store::Item_t& icQName,
    bool& isApplied)
{
  ZORBA_ASSERT(icQName != NULL);

  store::IC_t ic;

  if (!theICs.get(icQName.getp(), ic))
  {
    return ic; // already deactivated in the same PUL => noop
  }

  theICs.erase(icQName.getp());
  isApplied=true;
  return ic;
}


store::Iterator_t SimpleStore::listActiveICNames()
{
  return new NameIterator<ICSet>(theICs);
}


store::IC* SimpleStore::getIC(const store::Item* icQName)
{
  store::Item* qname = const_cast<store::Item*>(icQName);
  store::IC_t ic;
  theICs.get(qname, ic);

  return ic.getp();
}


/*******************************************************************************

********************************************************************************/
store::Index*
SimpleStore::getMap(const store::Item* aQName) const
{
  store::Item* lQName = const_cast<store::Item*>(aQName);
  store::Index_t lIndex;
  const_cast<IndexSet*>(&theHashMaps)->get(lQName, lIndex);

  return lIndex.getp();
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleStore::listMapNames()
{
  return new NameIterator<IndexSet>(theHashMaps);
}


/*******************************************************************************
  Create a collection with a given QName and return an rchandle to the new
  collection object. If a collection with the given QName exists already, raise
  an error.
********************************************************************************/
store::Collection_t SimpleStore::createCollection(
    const store::Item_t& aName,
    const std::vector<store::Annotation_t>& annotations,
    const store::Item_t& aNodeType,
    bool aDynamicCollection)
{
  if (aName == NULL)
    return NULL;

  store::Collection_t collection(
      new SimpleCollection(
        aName,
        annotations,
        aNodeType,
        aDynamicCollection));

  const store::Item* lName = collection->getName();

  bool inserted = theCollections->insert(lName, collection);

  if (!inserted)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0008_COLLECTION_ALREADY_EXISTS,
    ERROR_PARAMS(lName->getStringValue()));
  }

  return collection;
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::addCollection(store::Collection_t& collection)
{
  const store::Item* lName = collection->getName();

  bool inserted = theCollections->insert(lName, collection);

  if (!inserted)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0008_COLLECTION_ALREADY_EXISTS,
    ERROR_PARAMS(lName->getStringValue()));
  }
}


/*******************************************************************************
  Return an rchandle to the Collection object corresponding to the given QName,
  or NULL if there is no collection with that QName.
********************************************************************************/
store::Collection_t SimpleStore::getCollection(
    const store::Item* aName,
    bool aDynamicCollection)
{
  if (aName == NULL)
    return NULL;

  store::Collection_t collection;
  if (theCollections->get(aName, collection, aDynamicCollection)) 
  {
    return collection;
  }
  else
  {
    return NULL;
  }
}


/*******************************************************************************
  Delete the collection with the given QName. If there is no collection with
  that QName, this method is a NOOP.
********************************************************************************/
void SimpleStore::deleteCollection(
    const store::Item* aName,
    bool aDynamicCollection)
{
  if (aName == NULL)
    return;

  if (!theCollections->remove(aName, aDynamicCollection))
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0009_COLLECTION_NOT_FOUND,
    ERROR_PARAMS(aName->getStringValue()));
  }
}


/*******************************************************************************
  Returns an iterator that lists the QName's of all the available collections.
********************************************************************************/
store::Iterator_t SimpleStore::listCollectionNames(bool aDynamicCollections)
{
  return theCollections->names(aDynamicCollections);
}


/*******************************************************************************

********************************************************************************/
store::Item_t SimpleStore::loadDocument(
    const zstring& baseUri,
    const zstring& docUri,
    std::istream& stream,
    const store::LoadProperties& loadProperties)
{
  zstring_b urib;

  if (!docUri.empty())
    urib.wrap_memory(docUri.data(), docUri.size());

  XmlNode_t root;
  bool found = theDocuments.get(urib, root);

  if (found)
  {
    return root.getp();
  }

  XQueryDiagnostics lXQueryDiagnostics;
  std::auto_ptr<XmlLoader> loader(getXmlLoader(&lXQueryDiagnostics, loadProperties));

  root = loader->loadXml(baseUri, docUri, stream);

  if (!lXQueryDiagnostics.errors().empty())
  {
    lXQueryDiagnostics.errors().front()->polymorphic_throw();
  }

  if (root != NULL && loadProperties.getStoreDocument())
    theDocuments.insert(urib, root);

  return root.getp();
}


/*******************************************************************************
  For lazy loading...
  Param stream is a heap pointer to an input stream. This is to be deallocated
  by Zorba.
********************************************************************************/
store::Item_t SimpleStore::loadDocument(
    const zstring& baseUri,
    const zstring& docUri,
    std::istream* stream,
    const store::LoadProperties& loadProperties)
{
  store::Item_t docitem;
  try
  {
    //do full loading for now
    docitem = loadDocument(baseUri, docUri, *stream, loadProperties);
    delete stream;
  }
  catch(...)
  {
    delete stream;
  }
  return docitem;
}


/*******************************************************************************
  Add the given node with the given uri to the store. Essentially, this method
  establishes an association between a uri and a node. If the given uri is
  already associated to another node, the method raises an error. If the given
  uri is already associated to the given node, this method is a noop.
********************************************************************************/
void SimpleStore::addNode(const zstring& uri, const store::Item_t& node)
{
  ZORBA_ASSERT(!uri.empty());

  if (node == NULL || !node->isNode())
  {
    RAISE_ERROR_NO_LOC(zerr::ZAPI0021_ITEM_TO_LOAD_IS_NOT_NODE, ERROR_PARAMS(uri));
  }

  XmlNode_t root = reinterpret_cast<XmlNode*>(node.getp());

  bool inserted = theDocuments.insert(uri, root);

  if (!inserted && node.getp() != root.getp())
  {
    RAISE_ERROR_NO_LOC(zerr::ZAPI0020_DOCUMENT_ALREADY_EXISTS, ERROR_PARAMS(uri));
  }

  ZORBA_FATAL(node.getp() == root.getp(), "");
}


/*******************************************************************************
  Return an rchandle to an iterator over the set of documents in the store
********************************************************************************/
store::Iterator_t SimpleStore::getDocumentNames() const
{
  return new DocumentNameIterator<DocumentSet>(theDocuments);
}


/*******************************************************************************
  Return an rchandle to the root node of the document corresponding to the given
  URI, or NULL if there is no document with that URI.
********************************************************************************/
store::Item_t SimpleStore::getDocument(const zstring& uri)
{
  if (uri.empty())
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
void SimpleStore::deleteDocument(const zstring& uri)
{
  if (uri.empty())
    return;

  theDocuments.erase(uri);
}


/*******************************************************************************
  Delete all the documents.
********************************************************************************/
void SimpleStore::deleteAllDocuments()
{
  theDocuments.clear();
}


/*******************************************************************************

********************************************************************************/
store::Index_t
SimpleStore::createHashMap(
    const store::Item_t& aQName,
    const store::IndexSpecification& aSpec)
{
  store::Index_t lIndex;

  if (theHashMaps.get(aQName.getp(), lIndex))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0001_INDEX_ALREADY_EXISTS,
      ERROR_PARAMS( aQName->getStringValue() )
    );
  }

  lIndex = new ValueHashIndex(aQName, aSpec);

  addHashMap(lIndex);

  return lIndex;
}


/*******************************************************************************

********************************************************************************/
store::Index_t
SimpleStore::destroyHashMap(const store::Item_t& aQName)
{
  store::Index_t lIndex;
  if (!theHashMaps.get(aQName.getp(), lIndex))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( aQName->getStringValue() )
    );
  }
  theHashMaps.erase(aQName.getp());
  return lIndex;
}


/*******************************************************************************

********************************************************************************/
store::Index_t
SimpleStore::getHashMap(const store::Item_t& aQName) const
{
  store::Index_t lIndex;
  if (const_cast<IndexSet*>(&theHashMaps)->get(aQName.getp(), lIndex))
  {
    return lIndex;
  }
  else
  {
    return 0;
  }
}


/*******************************************************************************

********************************************************************************/
void
SimpleStore::addHashMap(const store::Index_t& aIndex)
{
  store::Item* lName = aIndex->getName();
  store::Index_t lIndex = aIndex;
  theHashMaps.insert(lName, lIndex);
}

/*******************************************************************************
  Compare two nodes, based on their node id. Return -1 if node1 < node2, 0, if
  node1 == node2, or 1 if node1 > node2.
********************************************************************************/
short SimpleStore::compareNodes(store::Item* node1, store::Item* node2) const
{
  ZORBA_FATAL(node1->isNode(), "");
  ZORBA_FATAL(node2->isNode(), "");

  if (node1 == node2)
    return 0;

  XmlNode* n1 = static_cast<XmlNode*>(node1);
  XmlNode* n2 = static_cast<XmlNode*>(node2);

  return (short)n1->compare2(n2);
}


/*******************************************************************************
  Sorts the items of the passed iterator

  @param iterator to sort
  @param ascendent true for ascendent and false for descendant
  @param duplicate duplicate elemination should be applied
  @return iterator which produces the sorted items
********************************************************************************/
store::Iterator_t SimpleStore::sortNodes(
    store::Iterator* input,
    bool ascendent,
    bool duplicateElemination,
    bool aAllowAtomics)
{
  if (aAllowAtomics)
    return new StoreNodeSortOrAtomicIterator(input, ascendent, duplicateElemination);
  else
    return new StoreNodeSortIterator(input, ascendent, duplicateElemination);
}


/*******************************************************************************
  Create an iterator that eliminates the duplicate nodes in the set of items
  which is produced by the passed iterator
********************************************************************************/
store::Iterator_t SimpleStore::distinctNodes(
    store::Iterator* input,
    bool aAllowAtomics)
{
  if (aAllowAtomics)
    return new StoreNodeDistinctOrAtomicIterator(input);
  else
    return new StoreNodeDistinctIterator(input, false);
}


/*******************************************************************************
  Create an iterator that checks for duplicate nodes in the set of nodes which
  is produced by the passed iterator, and raises an error if any duplicates
  are found. If no duplicates are found, the iterator simply passes on the
  input nodes to its consumer.
********************************************************************************/
store::Iterator_t SimpleStore::checkDistinctNodes(store::Iterator* input)
{
  return new StoreNodeDistinctIterator(input, true);
}


/*******************************************************************************
  Computes the Structural Reference for the given node.
********************************************************************************/
bool SimpleStore::getStructuralInformation(
    store::Item_t& result, 
    const store::Item* node)
{
#ifdef TEXT_ORDPATH
  const OrdPathNode* n = static_cast<const OrdPathNode*>(node);

  return theItemFactory->createStructuralAnyURI(result,
                                                n->getCollectionId(),
                                                n->getTreeId(),
                                                n->getNodeKind(),
                                                n->getOrdPath());
#else
  if (node->getNodeKind() == store::StoreConsts::textNode)
  {
    OrdPath ordPath;
    const TextNode* n = static_cast<const TextNode*>(node);
    n->getOrdPath(ordPath);

    return theItemFactory->createStructuralAnyURI(result,
                                                  n->getCollectionId(),
                                                  n->getTreeId(),
                                                  store::StoreConsts::textNode,
                                                  ordPath);
  }
  else
  {
    const OrdPathNode* n = static_cast<const OrdPathNode*>(node);

    return theItemFactory->createStructuralAnyURI(result,
                                                  n->getCollectionId(),
                                                  n->getTreeId(),
                                                  n->getNodeKind(),
                                                  n->getOrdPath());
  }
#endif
}


/*******************************************************************************
 Computes the reference of the given node.
 
 @param node XDM node
 @return the identifier as an item of type xs:anyURI
********************************************************************************/
bool SimpleStore::getNodeReference(store::Item_t& result, store::Item* node)
{
  XmlNode* xmlNode = static_cast<XmlNode*>(node);

  if (xmlNode->haveReference())
  {
    NodeRefMap::iterator resIt = theNodeToReferencesMap.find(xmlNode);

    ZORBA_FATAL(resIt != theNodeToReferencesMap.end(),"Node reference cannot be found");

    zstring id = (*resIt).second;
    return theItemFactory->createAnyURI(result, id);
  }

  uuid_t uuid;
  uuid_create(&uuid);
  zstring uuidStr = uuidToURI(uuid);

  xmlNode->setHaveReference();

  theNodeToReferencesMap.insert(xmlNode, uuidStr);
  theReferencesToNodeMap[uuidStr] = node;

  return theItemFactory->createAnyURI(result, uuidStr);
}


/*******************************************************************************
  Returns the node which is identified by the given reference.
 
  @param reference an xs:anyURI item
  @result the node identified by the reference, or NULL if no node with the given
          reference exists
  @return false if no node with the given reference exists; true otherwise.
********************************************************************************/
bool SimpleStore::getNodeByReference(store::Item_t& result, const zstring& reference)
{
  if (reference.length() != 45 ||
      !utf8::match_whole(reference, "urn:uuid:[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}"))
  {
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI, ERROR_PARAMS(reference));
  }

  RefNodeMap::iterator resIt;

  if ((resIt = theReferencesToNodeMap.find(reference)) != theReferencesToNodeMap.end())
  {
    result = resIt->second;
    return true;
  }

  result = NULL;
  return false;
}


/*******************************************************************************
  Returns whether a reference has already been generated for the given node.
 
  @param item XDM node
  @return whether a reference has already been generated for the given node.
********************************************************************************/
bool SimpleStore::hasReference(const store::Item* node)
{
  return static_cast<const XmlNode*>(node)->haveReference();
}


/*******************************************************************************
  Removes a node from the reference-to-nodes and nodes-to-references maps.
 
  @param node XDM node
  @return whether the node was registered or not.
********************************************************************************/
bool SimpleStore::unregisterNode(XmlNode* node)
{
  if (!node->haveReference())
    return false;

  NodeRefMap::iterator resIt;

  if ((resIt = theNodeToReferencesMap.find(node)) != theNodeToReferencesMap.end())
  {
    zstring value = (*resIt).second;
    theNodeToReferencesMap.erase(resIt);
    node->resetHaveReference();

    theReferencesToNodeMap.erase(value);

    return true;
  }
  else
  {
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
bool SimpleStore::getPathInfo(
    const store::Item*               docUriItem,
    std::vector<const store::Item*>& contextPath,
    std::vector<const store::Item*>& relativePath,
    bool                             isAttrPath,
    bool&                            found,
    bool&                            unique)
{
  zstring docUri;
  docUriItem->getStringValue2(docUri);

  XmlNode_t docRoot = BASE_NODE(getDocument(docUri));

  if (docRoot == NULL)
    return false;

#ifdef DATAGUIDE
  GuideNode* guideRoot = docRoot->getDataGuide();

  if (!guideRoot)
    return false;

  guideRoot->getPathInfo(contextPath, relativePath, isAttrPath, found, unique);
#endif
  return true;
}


/*******************************************************************************
  Creates a new TempSeq. The instance can be used, e.g. for variable bindings

  @param iterator   The source for the XMDInstance
  @param lazy       Hint for the store. If possible a XMDInstance should be
                    evaluated lazily. For XQueryP it might be necassary to set
                    this to false.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(const store::Iterator_t& iterator, bool lazy)
{
  if(lazy)
  {
    //tempSeq = new SimpleTempSeq(iterator, copyNodes);
    return new SimpleLazyTempSeq(iterator);
  }
  else
  {
    return new SimpleTempSeq(iterator);
  }
}


/*******************************************************************************
  Creates an empty TempSeq.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(bool lazy)
{
  if (lazy)
  {
    return new SimpleLazyTempSeq();
  }
  else
  {
    return new SimpleTempSeq();
  }
}


/*******************************************************************************
  Creates a temp seq initialized by the given vector.
  @param item_v - The vector to use to initialize the seq.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(std::vector<store::Item_t>& items)
{
  return new SimpleTempSeq(items);
}


/*******************************************************************************
  Creates a temp seq initialized by the given item.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(store::Item_t& item)
{
  return new SimpleTempSeq(item);
}


#ifndef ZORBA_NO_FULL_TEXT
void SimpleStore::setStemmerProvider( internal::StemmerProvider const *p ) 
{
  theStemmerProvider = p;
}


void SimpleStore::setTokenizerProvider( TokenizerProvider const *p ) 
{
  theTokenizerProvider = p;
}


internal::StemmerProvider const* SimpleStore::getStemmerProvider() const 
{
  return theStemmerProvider ?
    theStemmerProvider : &internal::StemmerProvider::get_default();
}


TokenizerProvider const* SimpleStore::getTokenizerProvider() const 
{
  return theTokenizerProvider ?
    theTokenizerProvider : &default_tokenizer_provider();
}
#endif /* ZORBA_NO_FULL_TEXT */

} // namespace store
} // namespace zorba
/* vim:set et sw=2 ts=2: */
