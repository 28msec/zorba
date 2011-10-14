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
#ifndef ZORBA_SIMPLE_STORE
#define ZORBA_SIMPLE_STORE

#include "store/naive/shared_types.h"
#include "store/naive/store_defs.h"
#include "store/naive/hashmap_nodep.h"

#if (defined (WIN32) || defined (WINCE))
#include "store/naive/node_items.h"
#include "store/api/collection.h"
#include "store/api/index.h"
#include "store/api/ic.h"
#endif

#include "store/api/store.h"

#include "store/util/hashmap_stringbuf.h"

#include "zorbautils/mutex.h"
#include "zorbautils/lock.h"
#include "zorbautils/hashmap_itemp.h"

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

typedef store::StringBufHashMap<XmlNode_t> DocumentSet;
typedef store::StringBufHashMap<store::Collection_t> UriCollectionSet;
typedef ItemPointerHashMap<store::Index_t> IndexSet;
typedef ItemPointerHashMap<store::IC_t> ICSet;



/*******************************************************************************
  theSchemaTypeNames     : Maps each enum value from SchemaTypeNames (see
                           store_defs.h) to its associated QName item.

  theCollectionCounter   : Incremented every time a new collection is created. The
                           current value of the counter is then assigned as the
                           id of the new collection.

  theNamespacePool       :
  theQNamePool           :

  theItemFactory         : Factory to create items.
  theIteratorFactory     : Factory to create iterators.
  theNodeFactory         : Factory to create node items.

  theDocuments           : A hashmap that for each xml tree that does not belong
                           to any collection, maps the URI of the tree to the root
                           node of the tree.
  theCollections         : Container which contains the collections of the store.
                           It includes a map that maps the qname of each collection
                           to the collection's container object.
  theIndices             : A hashmap that for each index, maps the qname of the
                           index to the index container object.
  theICs                 : A hashmap the for each integrity constraint, maps the
                           qname of the ic to the ic's container object.
  theReferencesToNodeMap : A hashmap that maps node references to the referenced
                           nodes
  theNodeToReferencesMap : A hashmap that maps nodes into their references

********************************************************************************/
class SimpleStore : public store::Store
{
  friend class zorba::StoreManager;

  typedef std::map<const zstring, const store::Item*> RefNodeMap;
  typedef NodePointerHashMap<zstring> NodeRefMap;

public:
  static const char* XS_URI;
  static const char* XML_URI;
  static const char* ZXSE_URI;

  static const ulong XML_URI_LEN;

protected:
  static const ulong NAMESPACE_POOL_SIZE;

public:
  zstring                       theEmptyNs;
  zstring                       theXmlSchemaNs;

  std::vector<store::Item_t>    theSchemaTypeNames;
  std::map<store::Item*, SchemaTypeCode> theSchemaTypeCodes;

protected:
  ulong                         theNumUsers;

  ulong                         theUriCounter;
  SYNC_CODE(Mutex               theUriCounterMutex;)

  ulong                         theCollectionCounter;
  SYNC_CODE(Mutex               theCollectionCounterMutex;)

  ulong                         theTreeCounter;
  SYNC_CODE(Mutex               theTreeCounterMutex;)

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

  RefNodeMap                    theReferencesToNodeMap;
  NodeRefMap                    theNodeToReferencesMap;

#ifndef ZORBA_NO_FULL_TEXT
  internal::StemmerProvider const * theStemmerProvider;
  TokenizerProvider const     * theTokenizerProvider;
#endif /* ZORBA_NO_FULL_TEXT */

public:
  void shutdown(bool soft = true);

  store::ItemFactory* getItemFactory() const;

  store::IteratorFactory* getIteratorFactory() const { return theIteratorFactory; }

  NodeFactory& getNodeFactory() const { return *theNodeFactory; }

  PULPrimitiveFactory& getPULFactory() const { return *thePULFactory; }

  StringPool& getNamespacePool() const { return *theNamespacePool; }

  QNamePool& getQNamePool() const { return *theQNamePool; }

  SYNC_CODE(Lock& getGlobalLock() { return theGlobalLock; })

  long getTraceLevel() const { return theTraceLevel; }

  XmlLoader* getXmlLoader(
      XQueryDiagnostics*,
      const store::LoadProperties& loadProperties);

  ulong createCollectionId();

  ulong createTreeId();

  store::Collection_t createCollection(
      const store::Item_t& aName,
      const std::vector<store::Annotation_t>& annotations,
      const store::Item_t& aNodeType,
      bool aDynamicCollection = false);

  void deleteCollection(
      const store::Item* aName,
      bool aDynamicCollection = false);

  store::Collection_t getCollection(
      const store::Item* aName,
      bool aDynamicCollection = false);

  void addCollection(store::Collection_t& collection);

  store::Iterator_t listCollectionNames(bool aDynamicCollections = false);

  store::Index_t createIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec,
      store::Iterator* sourceIter);
  
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

  // needs to be virtual to allow implementation of additional stores
  virtual const IndexSet& getIndices() const { return theIndices; }

  void addIndex(store::Index_t& index);

  store::Index* getIndex(const store::Item* qname);

  void deleteIndex(const store::Item* qname);

  store::Iterator_t listIndexNames();

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

  store::Iterator_t listActiveICNames();

  store::IC* getIC(const store::Item* icQName);

  /*****************************************************************************
  
  *****************************************************************************/
  virtual store::Index* getMap(const store::Item* aQName) const;

  virtual store::Iterator_t listMapNames();

  /*****************************************************************************
  
  *****************************************************************************/
  store::Item_t loadDocument(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream& stream,
        bool storeDocument);

  store::Item_t loadDocument(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream* stream,
        bool storeDocument);

  store::Item_t loadDocument(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream& stream,
        const store::LoadProperties& loadProperties);

  store::Item_t loadDocument(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream* stream,
        const store::LoadProperties& loadProperties);

  /*****************************************************************************
  
  *****************************************************************************/
  void addNode(const zstring& uri, const store::Item_t& node);

  store::Iterator_t getDocumentNames() const;

  store::Item_t getDocument(const zstring& uri);

  void deleteDocument(const zstring& uri);

  void deleteAllDocuments();

  /*****************************************************************************
  
  *****************************************************************************/
  store::Index_t createHashMap(
      const store::Item_t& aQName,
      const store::IndexSpecification& aSpec);

  store::Index_t destroyHashMap(const store::Item_t& aQName);

  store::Index_t getHashMap(const store::Item_t& aQName) const;

  void addHashMap(const store::Index_t& aMap);

  /*****************************************************************************
  
  *****************************************************************************/
  short compareNodes(store::Item* node1, store::Item* node2) const;

  store::Iterator_t sortNodes(
        store::Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  store::Iterator_t distinctNodes(store::Iterator* input, bool aAllowAtomics);

  store::Iterator_t checkDistinctNodes(store::Iterator* input);

  bool getStructuralInformation(store::Item_t& result, const store::Item* node);

  bool getPathInfo(
        const store::Item* docUri,
        std::vector<const store::Item*>& contextPath,
        std::vector<const store::Item*>& relativePath,
        bool isAttrPath,
        bool& found,
        bool& unique);

  /* ------------------------ Node Reference Management ---------------------------*/

  bool getNodeReference(store::Item_t& result, store::Item* node);

  bool hasReference(const store::Item* node);

  bool getNodeByReference(store::Item_t& result, const zstring& reference);

  bool unregisterNode(XmlNode* node);

  /* ------------------------ Temp Sequence Management ---------------------------*/

  store::TempSeq_t createTempSeq(bool lazy);

  store::TempSeq_t createTempSeq(
        store::Iterator_t& iterator,
        bool copyNodes ,
        bool lazy);

  store::TempSeq_t createTempSeq(const std::vector<store::Item_t>& item_v);

#ifndef ZORBA_NO_FULL_TEXT
  internal::StemmerProvider const* getStemmerProvider() const;

  void setStemmerProvider(internal::StemmerProvider const*);
#endif /* ZORBA_NO_FULL_TEXT */

protected:
  SimpleStore();

  virtual ~SimpleStore();

  void init();

  void initTypeNames();

  // Functions to create/destory the node and item factories. These functions
  // are called from init and shutdown, respectively. Having this functionality
  // factorized allows others to derive from the SimpleStore and provide their
  // own factories.

  virtual NodeFactory* createNodeFactory() const;

  virtual void destroyNodeFactory(NodeFactory*) const;

  virtual BasicItemFactory* createItemFactory() const;

  virtual void destroyItemFactory(BasicItemFactory*) const;

  virtual PULPrimitiveFactory* createPULPrimitiveFactory() const;

  virtual void destroyPULPrimitiveFactory(PULPrimitiveFactory*) const;

  virtual CollectionSet* createCollectionSet() const;

  virtual void destroyCollectionSet(CollectionSet*) const;

#ifndef ZORBA_NO_FULL_TEXT
  TokenizerProvider const* getTokenizerProvider() const;

  void setTokenizerProvider(TokenizerProvider const*);
#endif /* ZORBA_NO_FULL_TEXT */
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
