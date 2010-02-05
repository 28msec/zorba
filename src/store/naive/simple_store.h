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

#include "store/naive/store_config.h"
#include "store/naive/shared_types.h"
#include "store/naive/collections.h"

#if (defined (WIN32) || defined (WINCE))
#include "store/naive/node_items.h"
#include "store/api/collection.h"
#include "store/api/index.h"
#include "store/api/ic.h"
#endif

#include "store/api/store.h"

#include "store/util/hashmap_stringp.h"

#include "zorbautils/mutex.h"
#include "zorbautils/lock.h"
#include "zorbautils/hashmap_itemp.h"

namespace zorba
{

namespace error
{
  class ErrorManager;
}

namespace store
{
  class IteratorFactory;
  class ValueIndexSpecification;
}

namespace simplestore
{

class SimpleStoreManager;
class StringPool;
class QNamePool;
class XmlLoader;
class FastXmlLoader;
class Index;
class BasicItemFactory;
class NodeFactory;

typedef rchandle<XmlNode> XmlNode_t;

typedef store::StringHashMap<XmlNode_t> DocumentSet;
typedef store::StringHashMap<store::Collection_t> UriCollectionSet;
typedef ItemPointerHashMap<store::Index_t> IndexSet;
typedef ItemPointerHashMap<store::IC_t> ICSet;



/*******************************************************************************
  theSchemaTypeNames   : Maps each enum value from SchemaTypeNames (see
                         store_defs.h) to its associated QName item.

  theCollectionCounter : Incremented every time a new collection is created. The
                         current value of the counter is then assigned as the
                         id of the new collection.

  theNamespacePool     :
  theQNamePool         :

  theItemFactory       : Factory to create items.
  theIteratorFactory   : Factory to create iterators.
  theNodeFactory       : Factory to create node items.

  theDocuments         : A hashmap that for each xml tree that does not belong
                         to any collection, maps the URI of the tree to the root
                         node of the tree.
  theCollections       : Container which contains the collections of the store.
                         It includes a map that maps the qname of each collection
                         to the collection's container object.
  theUriCollections    : A hashmap that for each W3C collection, maps the URI
                         of the collection to the collection container object.
  theIndices           : A hashmap that for each index, maps the qname of the
                         index to the index container object.
  theICs               :
********************************************************************************/
class SimpleStore : public store::Store
{
  friend class simplestore::SimpleStoreManager;

public:
  static const char* XS_URI;
  static const char* XML_URI;
  static const char* ZXSE_URI;

  static const ulong XML_URI_LEN;

protected:
  static const ulong NAMESPACE_POOL_SIZE;

public:
  xqpStringStore_t              theEmptyNs;
  xqpStringStore_t              theXmlSchemaNs;

  checked_vector<store::Item_t> theSchemaTypeNames;

protected:
  bool                          theIsInitialized;

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

  DocumentSet                   theDocuments;
  Collections                   theCollections;
  UriCollectionSet              theUriCollections;
  IndexSet                      theIndices;
  ICSet                         theICs;

  SYNC_CODE(Lock                theGlobalLock;)

  long                          theTraceLevel;

protected:
  SimpleStore();

  virtual ~SimpleStore();

  void init();
  void initTypeNames();

  // function to create the node and item factory
  // those functions are called from init and 
  // shutdown, respectively.
  // Having this functionality factorized allows
  // other to derive from the SimpleStore and
  // provide their own factories
  virtual NodeFactory* createNodeFactory() const;

  virtual void destroyNodeFactory(NodeFactory*) const;

  virtual BasicItemFactory* createItemFactory() const;

  virtual void destroyItemFactory(BasicItemFactory*) const;

public:
  void shutdown();

  store::ItemFactory* getItemFactory() const;

  store::IteratorFactory* getIteratorFactory() const { return theIteratorFactory; }

  NodeFactory& getNodeFactory() const { return *theNodeFactory; }

  StringPool& getNamespacePool() const { return *theNamespacePool; }

  QNamePool& getQNamePool() const { return *theQNamePool; }

  SYNC_CODE(Lock& getGlobalLock() { return theGlobalLock; })

  long getTraceLevel() const { return theTraceLevel; }

  XmlLoader* getXmlLoader(error::ErrorManager*);

  ulong createCollectionId();

  ulong createTreeId();

  store::Collection_t createUriCollection(const xqpStringStore_t& uri);

  store::Collection_t getUriCollection(const xqpStringStore_t& uri);

  void deleteUriCollection(const xqpStringStore_t& uri);

  store::Collection_t createCollection(store::Item_t& aName);

  void deleteCollection(const store::Item* aName);

  store::Collection_t getCollection(const store::Item* aName);

  void addCollection(store::Collection_t& collection);

  store::Iterator_t listCollectionNames();

  static void populateIndex(
      const store::Index_t& aIndex,
      store::Iterator* aSourceIter,
      ulong aNumColumns);

  store::Index_t createIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec,
        store::Iterator* sourceIter);

  void addIndex(store::Index_t& index);

  store::Index* getIndex(const store::Item* qname);

  void deleteIndex(const store::Item* qname);

  store::Iterator_t listIndexNames();

  const IndexSet& getIndices() const { return theIndices; }

  store::IC_t activateIC(
        const store::Item_t& icQName,
        const store::Item_t& collectionQName);

  store::IC_t activateForeignKeyIC(
        const store::Item_t& icQName,
        const store::Item_t& fromCollectionQName,
        const store::Item_t& toCollectionQName);

  store::IC_t deactivateIC(const store::Item_t& icQName);

  store::Iterator_t listActiveICNames();

  store::IC* getIC(const store::Item* icQName);

  store::Item_t loadDocument(
        const xqpStringStore_t& uri,
        std::istream& stream,
        bool storeDocument);

  store::Item_t loadDocument(
        const xqpStringStore_t& uri,
        std::istream* stream,
        bool storeDocument);

  void addNode(const xqpStringStore_t& uri, const store::Item_t& node);

  store::Item_t getDocument(const xqpStringStore_t& uri);

  void deleteDocument(const xqpStringStore_t& uri);

  void deleteAllDocuments();

  short compareNodes(store::Item* node1, store::Item* node2) const;

  store::Iterator_t sortNodes(
        store::Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  store::Iterator_t distinctNodes(store::Iterator*, bool aAllowAtomics = false);

  bool getPathInfo(
        const store::Item* docUri,
        std::vector<const store::Item*>& contextPath,
        std::vector<const store::Item*>& relativePath,
        bool isAttrPath,
        bool& found,
        bool& unique);

  bool getReference(store::Item_t& result, const store::Item* node);

  bool getNodeByReference(store::Item_t& result, const store::Item* uri);

  store::TempSeq_t createTempSeq();

  store::TempSeq_t createTempSeq(
        store::Iterator* iterator,
        bool copyNodes ,
        bool lazy);

  store::TempSeq_t createTempSeq(const std::vector<store::Item_t>& item_v);

#ifdef ZORBA_STORE_MSDOM
  IXMLDOMNode* exportItemAsMSDOM(store::Item_t it);

  store::Item_t importMSDOM(
        IXMLDOMNode* domNode,
        xqpStringStore_t docUri,
        xqpStringStore_t baseUri);
#endif
};



} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
