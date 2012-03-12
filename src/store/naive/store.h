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
#ifndef ZORBA_SIMPLESTORE_STORE_H
#define ZORBA_SIMPLESTORE_STORE_H

#include "shared_types.h"
#include "store_defs.h"
#include "hashmap_nodep.h"

#if (defined (WIN32) || defined (WINCE))
#include "node_items.h"
#include "store/api/collection.h"
#include "store/api/index.h"
#include "store/api/ic.h"
#endif

#include "store/api/store.h"

#include "store/util/hashmap_stringbuf.h"

#include "zorbautils/mutex.h"
#include "zorbautils/lock.h"
#include "zorbautils/hashmap_itemp.h"
#include "zorbautils/hashmap_zstring_nonserializable.h"

namespace zorba
{
  class StoreManager;

class XQueryDiagnostics;

namespace store
{
  class IteratorFactory;
  class ValueIndexSpecification;
}

namespace simplestore
{

class StringPool;
class QNamePool;
class XmlLoader;
class FastXmlLoader;
class Index;
class BasicItemFactory;
class NodeFactory;
class PULPrimitiveFactory;

typedef zorba::HashMapZString<XmlNode_t> DocumentSet;
typedef ItemPointerHashMap<store::Index_t> IndexSet;
typedef ItemPointerHashMap<store::IC_t> ICSet;



/*******************************************************************************
  theSchemaTypeNames:
  -------------------
  Maps each enum value from SchemaTypeNames (see store/api/xs_types_enum.h) to 
  its associated QName item.

  theSchemaTypeCodes:
  -------------------

  theCollectionCounter:
  ---------------------
  Incremented every time a new collection is created. The current value of the  
  counter is then assigned as the id of the new collection.

  theNamespacePool:
  -----------------

  theQNamePool:
  -------------

  theItemFactory:
  ---------------
  Factory to create items.

  theIteratorFactory:
  -------------------
  Factory to create iterators.

  theNodeFactory:
  ---------------
  Factory to create node items.

  theDocuments:
  -------------
  A hashmap that for each xml tree that does not belong to any collection, maps
  the URI of the tree to the root node of the tree.

  theCollections:
  ---------------
  Container which contains the collections of the store. It includes a map that
  maps the qname of each collection to the collection's container object.

  theIndices:  
  -----------
  A hashmap that for each index, maps the qname of the index to the index 
  container object.
  
  theICs:
  -------
  A hashmap the for each integrity constraint, maps the qname of the ic to the
  ic's container object.

  theReferencesToNodeMap:
  -----------------------
  A hashmap that maps node references to the referenced nodes

  theNodeToReferencesMap:
  -----------------------
  A hashmap that maps nodes into their references

********************************************************************************/
class Store : public zorba::store::Store
{
public:
  static const char* XS_URI;
  static const char* XML_URI;
  static const char* ZXSE_URI;

  static const ulong XML_URI_LEN;

protected:
  static const ulong NAMESPACE_POOL_SIZE;
  static const ulong DEFAULT_DOCUMENT_SET_SIZE;
  static const ulong DEFAULT_URI_COLLECTION_SET_SIZE;
  static const ulong DEFAULT_INDICES_SET_SIZE;
  static const ulong DEFAULT_INTEGRITY_CONSTRAINT_SET_SIZE;

public:
  zstring                       theEmptyNs;
  zstring                       theXmlSchemaNs;

  std::vector<store::Item_t>    theSchemaTypeNames;
  std::map<store::Item*, store::SchemaTypeCode> theSchemaTypeCodes;
  store::Item_t                 XS_UNTYPED_QNAME;
  store::Item_t                 XS_ANY_QNAME;
  store::Item_t                 XS_ANY_SIMPLE_QNAME;

protected:
  ulong                         theNumUsers;

  StringPool                  * theNamespacePool;
  QNamePool                   * theQNamePool;

  BasicItemFactory            * theItemFactory;
  store::IteratorFactory      * theIteratorFactory;
  NodeFactory                 * theNodeFactory;
  PULPrimitiveFactory         * thePULFactory;

  DocumentSet                   theDocuments;
  CollectionSet*                theCollections;
  IndexSet                      theIndices;
  ICSet                         theICs;
  IndexSet                      theHashMaps;

  SYNC_CODE(Lock                theGlobalLock;)

  long                          theTraceLevel;

#ifndef ZORBA_NO_FULL_TEXT
  internal::StemmerProvider const * theStemmerProvider;
  TokenizerProvider const     * theTokenizerProvider;
#endif /* ZORBA_NO_FULL_TEXT */

/*----------------------- Initialization, shutdown ---------------------------*/
protected:
  virtual void init();

  void initTypeNames();

public:
  virtual void shutdown(bool soft = true);

  /* store API */ SYNC_CODE(Lock& getGlobalLock() { return theGlobalLock; })

  long getTraceLevel() const { return theTraceLevel; }

  XmlLoader* getXmlLoader(
      XQueryDiagnostics*,
      const store::LoadProperties& loadProperties);
      
/*------------------------------ Factories -----------------------------------*/
public:
  /* store API */ store::ItemFactory* getItemFactory() const;

  /* store API */ store::IteratorFactory* getIteratorFactory() const
  { return theIteratorFactory; }

  NodeFactory& getNodeFactory() const { return *theNodeFactory; }

  PULPrimitiveFactory& getPULFactory() const { return *thePULFactory; }

  StringPool& getNamespacePool() const { return *theNamespacePool; }

  QNamePool& getQNamePool() const { return *theQNamePool; }
  
protected:
  // Functions to create/destory the node and item factories. These functions
  // are called from init and shutdown, respectively. Having this functionality
  // factorized allows others to derive from the SimpleStore and provide their
  // own factories.

  virtual NodeFactory* createNodeFactory() const = 0;

  virtual void destroyNodeFactory(NodeFactory*) const = 0;

  virtual BasicItemFactory* createItemFactory() const = 0;

  virtual void destroyItemFactory(BasicItemFactory*) const = 0;

  virtual store::IteratorFactory* createIteratorFactory() const = 0;

  virtual void destroyIteratorFactory(store::IteratorFactory*) const = 0;

  virtual PULPrimitiveFactory* createPULFactory() const = 0;

  virtual void destroyPULFactory(PULPrimitiveFactory*) const = 0;

  virtual CollectionSet* createCollectionSet() const = 0;

  virtual void destroyCollectionSet(CollectionSet*) const = 0;

/*---------------------------- Collections -----------------------------------*/
public:
  /* store API */ store::Collection_t getCollection(
      const store::Item* aName,
      bool aDynamicCollection = false);

  /* store API */ store::Iterator_t listCollectionNames(
      bool aDynamicCollections = false);

  virtual ulong createCollectionId() = 0;

  virtual ulong createTreeId() = 0;

  virtual store::Collection_t createCollection(
      const store::Item_t& aName,
      const std::vector<store::Annotation_t>& annotations,
      const store::Item_t& aNodeType,
      bool aDynamicCollection = false) = 0;

  void deleteCollection(
      const store::Item* aName,
      bool aDynamicCollection = false);

  void addCollection(store::Collection_t& collection);

/*-------------------------------- Indices -----------------------------------*/
public:
  /* store API */ store::Index_t createIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec,
      store::Iterator* sourceIter);
  
  /* store API */ store::Index* getIndex(const store::Item* qname);

  /* store API */ store::Iterator_t listIndexNames();

  // needs to be virtual to allow implementation of additional stores
  virtual const IndexSet& getIndices() const { return theIndices; }

  // needs to be virtual to allow implementation of additional stores
  virtual void populateValueIndex(
      const store::Index_t& index,
      store::Iterator* sourceIter,
      ulong numColumns);

  // needs to be virtual to allow implementation of additional stores
  virtual void populateGeneralIndex(
      const store::Index_t& index,
      store::Iterator* sourceIter,
      ulong numColumns);

  // needs to be virtual to allow implementation of additional stores
  virtual store::Index_t refreshIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec,
      store::Iterator* sourceIter);

  virtual void addIndex(store::Index_t& index);

  virtual void deleteIndex(const store::Item* qname);

/*------------------------- Integrity constraints ----------------------------*/
public:
  /* store API */ store::Iterator_t listActiveICNames();

  /* store API */ store::IC* getIC(const store::Item* icQName);

  store::IC_t activateIC(
      const store::Item_t& icQName,
      const store::Item_t& collectionQName,
      bool& isApplied);
  
  store::IC_t activateForeignKeyIC(
      const store::Item_t& icQName,
      const store::Item_t& fromCollectionQName,
      const store::Item_t& toCollectionQName,
      bool& isApplied);

  store::IC_t deactivateIC(
      const store::Item_t& icQName,
      bool& isApplied);

/*------------------------------------- Maps ---------------------------------*/
public:
  /* store API */ virtual store::Index* getMap(const store::Item* aQName) const;

  /* store API */ virtual store::Iterator_t listMapNames();

/*-------------------------------- Documents ---------------------------------*/
public:
  /* store API */ store::Item_t loadDocument(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream& stream,
        const store::LoadProperties& loadProperties);

  /* store API */ store::Item_t loadDocument(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream* stream,
        const store::LoadProperties& loadProperties);

  /* store API */ void addNode(const zstring& uri, const store::Item_t& node);

  /* store API */ store::Iterator_t getDocumentNames() const;

  /* store API */ store::Item_t getDocument(const zstring& uri);

  void deleteDocument(const zstring& uri);

  void deleteAllDocuments();

/*-------------------------------- Hasp Maps ---------------------------------*/
public:
  store::Index_t createHashMap(
      const store::Item_t& aQName,
      const store::IndexSpecification& aSpec);

  store::Index_t destroyHashMap(const store::Item_t& aQName);

  store::Index_t getHashMap(const store::Item_t& aQName) const;

  void addHashMap(const store::Index_t& aMap);

/*----------------------------- Node operations ------------------------------*/
public:
  /* store API */ short compareNodes(
      store::Item* node1,
      store::Item* node2) const;

  /* store API */ store::Iterator_t sortNodes(
        store::Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  /* store API */ store::Iterator_t distinctNodes(
      store::Iterator* input,
      bool aAllowAtomics);

  /* store API */ store::Iterator_t checkDistinctNodes(store::Iterator* input);

  /* store API */ bool getStructuralInformation(
      store::Item_t& result,
      const store::Item* node);

  /* store API */ bool getPathInfo(
        const store::Item* docUri,
        std::vector<const store::Item*>& contextPath,
        std::vector<const store::Item*>& relativePath,
        bool isAttrPath,
        bool& found,
        bool& unique);

/*---------------------- Node Reference Management ---------------------------*/
public:
  /* store API */ virtual bool getNodeReference(
      store::Item_t& result,
      store::Item* node) = 0;

  /* store API */ virtual bool hasReference(const store::Item* node) = 0;

  /* store API */ virtual bool getNodeByReference(
      store::Item_t& result,
      const zstring& reference) = 0;

  virtual bool unregisterNode(XmlNode* node) = 0;

/*----------------------- Temp Sequence Management ---------------------------*/
public:
  /* store API */ store::TempSeq_t createTempSeq(bool lazy);

  /* store API */ store::TempSeq_t createTempSeq(
      const store::Iterator_t& iterator,
      bool lazy);

  /* store API */ store::TempSeq_t createTempSeq(
      std::vector<store::Item_t>& item_v);

  /* store API */ store::TempSeq_t createTempSeq(store::Item_t& item);

/*--------------------------- Full Text Management ---------------------------*/
public:
#ifndef ZORBA_NO_FULL_TEXT
  /* store API */ internal::StemmerProvider const* getStemmerProvider() const;

  /* store API */ void setStemmerProvider(internal::StemmerProvider const*);
#endif /* ZORBA_NO_FULL_TEXT */

protected:
#ifndef ZORBA_NO_FULL_TEXT
  /* store API */ TokenizerProvider const* getTokenizerProvider() const;

  /* store API */ void setTokenizerProvider(TokenizerProvider const*);
#endif /* ZORBA_NO_FULL_TEXT */

/*---------------------- Construction, destruction ---------------------------*/
protected:
  Store();

  virtual ~Store();
};

} // namespace simplestore
} // namespace zorba

#endif /* ZORBA_SIMPLESTORE_STORE_H */

