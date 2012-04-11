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
#include "tree_id.h"

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
class TreeIdGeneratorFactory;
class TreeIdGenerator;

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

  theNumUsers:
  ------------

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

  theTreeIdGeneratorFactory:
  --------------------------
  Factory to create ID generators (Each collection can have its own ID generator in
  addition to the default one).

  theTreeIdGenerator:
  -------------------
  The tree-id generator used by the store for trees that are not in collections.

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

********************************************************************************/
class Store : public zorba::store::Store
{
public:
  static const char* XS_URI;
  static const char* XML_URI;
  static const char* ZXSE_URI;
  static const char* JDM_URI;

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

#ifdef ZORBA_WITH_JSON
  store::Item_t                 JDM_OBJECT_QNAME;
  store::Item_t                 JDM_ARRAY_QNAME;
  store::Item_t                 JDM_NULL_QNAME;
#endif

protected:
  ulong                         theNumUsers;

  StringPool                  * theNamespacePool;
  QNamePool                   * theQNamePool;

  store::ItemFactory          * theItemFactory;
  store::IteratorFactory      * theIteratorFactory;
  NodeFactory                 * theNodeFactory;
  PULPrimitiveFactory         * thePULFactory;
  TreeIdGeneratorFactory      * theTreeIdGeneratorFactory;
  
  TreeIdGenerator             * theTreeIdGenerator;

  DocumentSet                   theDocuments;
  CollectionSet*                theCollections;
  IndexSet                      theIndices;
  ICSet                         theICs;
  IndexSet                      theHashMaps;

  SYNC_CODE(Lock                theGlobalLock;)

  long                          theTraceLevel;

#ifndef ZORBA_NO_FULL_TEXT
  const internal::StemmerProvider * theStemmerProvider;
  const TokenizerProvider         * theTokenizerProvider;
#endif /* ZORBA_NO_FULL_TEXT */

/*----------------------- Initialization, shutdown ---------------------------*/
protected:
  Store();

  virtual ~Store();

  virtual void init();

  void initTypeNames();

public:
  virtual void shutdown(bool soft = true);

  SYNC_CODE(Lock& getGlobalLock() { return theGlobalLock; })

  long getTraceLevel() const { return theTraceLevel; }

  XmlLoader* getXmlLoader(
      XQueryDiagnostics*,
      const store::LoadProperties& loadProperties);
      
/*------------------------------ Factories -----------------------------------*/
public:
  store::ItemFactory* getItemFactory() const { return theItemFactory; }

  store::IteratorFactory* getIteratorFactory() const
  {
    return theIteratorFactory; 
  }

  NodeFactory& getNodeFactory() const { return *theNodeFactory; }

  PULPrimitiveFactory& getPULFactory() const { return *thePULFactory; }

  TreeIdGeneratorFactory& getTreeIdGeneratorFactory() const
  {
    return *theTreeIdGeneratorFactory;
  }

  StringPool& getNamespacePool() const { return *theNamespacePool; }

  QNamePool& getQNamePool() const { return *theQNamePool; }

protected:
  // Functions to create/destory the node and item factories. These functions
  // are called from init and shutdown, respectively. Having this functionality
  // factorized allows others to derive from the SimpleStore and provide their
  // own factories.

  virtual NodeFactory* createNodeFactory() const = 0;

  virtual void destroyNodeFactory(NodeFactory*) const = 0;

  virtual store::ItemFactory* createItemFactory() const = 0;

  virtual void destroyItemFactory(store::ItemFactory*) const = 0;

  virtual store::IteratorFactory* createIteratorFactory() const = 0;

  virtual void destroyIteratorFactory(store::IteratorFactory*) const = 0;

  virtual PULPrimitiveFactory* createPULFactory() const = 0;

  virtual void destroyPULFactory(PULPrimitiveFactory*) const = 0;

  virtual CollectionSet* createCollectionSet() const = 0;

  virtual void destroyCollectionSet(CollectionSet*) const = 0;

  virtual TreeIdGeneratorFactory* createTreeIdGeneratorFactory() const = 0;

  virtual void destroyTreeIdGeneratorFactory(TreeIdGeneratorFactory*) const = 0;

/*---------------------------- Collections -----------------------------------*/
public:
  virtual ulong createCollectionId() = 0;

  virtual TreeId createTreeId();

  virtual store::Collection_t createCollection(
      const store::Item_t& aName,
      const std::vector<store::Annotation_t>& annotations,
      const store::Item_t& aNodeType,
      bool isDynamic) = 0;

  virtual void addCollection(store::Collection_t& collection);

  virtual void deleteCollection(const store::Item* name, bool isDynamic);

  virtual store::Collection_t getCollection(const store::Item* name, bool isDynamic);

  virtual store::Iterator_t listCollectionNames(bool dynamic);

/*-------------------------------- Indices -----------------------------------*/
public:
  virtual store::Index_t createIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec,
      store::Iterator* sourceIter);

  virtual store::Index_t refreshIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec,
      store::Iterator* sourceIter);

  virtual void addIndex(store::Index_t& index);

  virtual void deleteIndex(const store::Item* qname);

  virtual store::Index* getIndex(const store::Item* qname);

  virtual store::Iterator_t listIndexNames();

  const IndexSet& getIndices() const { return theIndices; }

protected:
  virtual void populateValueIndex(
      const store::Index_t& index,
      store::Iterator* sourceIter,
      ulong numColumns);

  virtual void populateGeneralIndex(
      const store::Index_t& index,
      store::Iterator* sourceIter,
      ulong numColumns);

/*------------------------- Integrity constraints ----------------------------*/
public:
  virtual store::IC_t activateIC(
      const store::Item_t& icQName,
      const store::Item_t& collectionQName,
      bool& isApplied);
  
  virtual store::IC_t activateForeignKeyIC(
      const store::Item_t& icQName,
      const store::Item_t& fromCollectionQName,
      const store::Item_t& toCollectionQName,
      bool& isApplied);

  virtual store::IC_t deactivateIC(
      const store::Item_t& icQName,
      bool& isApplied);

  virtual store::Iterator_t listActiveICNames();

  virtual store::IC* getIC(const store::Item* icQName);

/*------------------------------------- Maps ---------------------------------*/
public:
  virtual store::Index_t createHashMap(
      const store::Item_t& aQName,
      const store::IndexSpecification& aSpec);

  virtual store::Index_t destroyHashMap(const store::Item_t& aQName);

  virtual store::Index* getMap(const store::Item* aQName) const;

  virtual store::Index_t getHashMap(const store::Item_t& aQName) const;

  virtual void addHashMap(const store::Index_t& aMap);

  virtual store::Iterator_t listMapNames();

/*-------------------------------- Documents ---------------------------------*/
public:
  virtual store::Item_t loadDocument(
      const zstring& baseUri,
      const zstring& docUri,
      std::istream& stream,
      const store::LoadProperties& loadProperties);

  virtual store::Item_t loadDocument(
      const zstring& baseUri,
      const zstring& docUri,
      std::istream* stream,
      const store::LoadProperties& loadProperties);

  virtual void addNode(const zstring& uri, const store::Item_t& node);

  virtual store::Iterator_t getDocumentNames() const;

  virtual store::Item_t getDocument(const zstring& uri);

  virtual void deleteDocument(const zstring& uri);

  virtual void deleteAllDocuments();

/*----------------------------- Node operations ------------------------------*/
public:
  virtual short compareNodes(
      store::Item* node1,
      store::Item* node2) const;

  virtual store::Iterator_t sortNodes(
      store::Iterator* iterator,
      bool ascendent,
      bool duplicateElemination,
      bool aAllowAtomics = false);
  
  virtual store::Iterator_t distinctNodes(
      store::Iterator* input,
      bool aAllowAtomics);

  virtual store::Iterator_t checkDistinctNodes(store::Iterator* input);

  virtual bool getStructuralInformation(
      store::Item_t& result,
      const store::Item* node);

  virtual bool getPathInfo(
      const store::Item* docUri,
      std::vector<const store::Item*>& contextPath,
      std::vector<const store::Item*>& relativePath,
      bool isAttrPath,
      bool& found,
      bool& unique);

/*---------------------- Node Reference Management ---------------------------*/
public:
  virtual bool getNodeReference(store::Item_t& result, const store::Item* node) = 0;

  virtual bool hasReference(const store::Item* node) = 0;

  virtual bool getNodeByReference(store::Item_t& result, const zstring& ref) = 0;

  virtual bool unregisterNode(XmlNode* node) = 0;

/*----------------------- Temp Sequence Management ---------------------------*/
public:
  virtual store::TempSeq_t createTempSeq(bool lazy);

  virtual store::TempSeq_t createTempSeq(const store::Iterator_t& iterator, bool lazy);

  virtual store::TempSeq_t createTempSeq(std::vector<store::Item_t>& item_v);

  virtual store::TempSeq_t createTempSeq(store::Item_t& item);

/*--------------------------- Full Text Management ---------------------------*/
public:
#ifndef ZORBA_NO_FULL_TEXT
  virtual internal::StemmerProvider const* getStemmerProvider() const;

  virtual void setStemmerProvider(internal::StemmerProvider const*);

protected:
  virtual TokenizerProvider const* getTokenizerProvider() const;

  virtual void setTokenizerProvider(TokenizerProvider const*);
#endif /* ZORBA_NO_FULL_TEXT */
};

} // namespace simplestore
} // namespace zorba

#endif /* ZORBA_SIMPLESTORE_STORE_H */

