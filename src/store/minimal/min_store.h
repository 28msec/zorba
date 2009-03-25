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
#ifndef ZORBA_MINIMAL_STORE___
#define ZORBA_MINIMAL_STORE___


#include <zorba/config.h>
#include "zorbautils/mutex.h"
#include "zorbautils/lock.h"

#include "common/shared_types.h"

#include "store/api/store.h"
#include "store/api/collection.h"
#include "store/api/index.h"

#include "store/util/hashmap_stringp.h"

#include "store/minimal/shared_types.h"
#include "store/minimal/min_node_items.h"


namespace zorba { 

class GlobalEnvironment;

namespace error 
{
  class ErrorManager;
}

namespace store
{
  class IteratorFactory;
  class ValueIndexSpecification;
}

namespace storeminimal 
{

class QueryContextContainer;
class QueryContext;

class StringPool;
class QNamePool;
class XmlLoader;


typedef rchandle<XmlNode> XmlNode_t;
typedef store::StringHashMap<XmlNode_t> DocumentSet;
typedef store::StringHashMap<store::Collection_t> CollectionSet;


/*******************************************************************************
  theSchemaTypeNames : Maps each enum value from SchemaTypeNames (see 
                       store_defs.h) to its associated QName item.
********************************************************************************/
class SimpleStore : public store::Store
{
  friend class zorba::GlobalEnvironment;
 
public:
  static const char* XS_URI;
  static const char* XML_URI;
  static const char* ZXSE_URI;

  static const ulong XML_URI_LEN;

protected:
  static const ulong DEFAULT_COLLECTION_MAP_SIZE;
  static const ulong NAMESPACE_POOL_SIZE;

public:
  xqpStringStore_t         theEmptyNs;
  xqpStringStore_t         theXmlSchemaNs;

  checked_vector<store::Item_t>   theSchemaTypeNames;

protected:
  bool                     theIsInitialized;

  ulong                    theUriCounter;
  SYNC_CODE(Mutex          theUriCounterMutex;)

  ulong                    theTreeCounter;
  SYNC_CODE(Mutex          theTreeCounterMutex;)

  StringPool             * theNamespacePool;
  QNamePool              * theQNamePool;

  store::ItemFactory          * theItemFactory;
  store::IteratorFactory      * theIteratorFactory;

  DocumentSet              theDocuments;
  CollectionSet            theCollections;
  checked_vector<store::Item_t> theItemUris;

  QueryContextContainer  * theQueryContextContainer; 

  SYNC_CODE(Lock                   theGlobalLock;)

  long                     theTraceLevel;
public:
  static ZORBA_DLL_PUBLIC SimpleStore*      getInstance();
private:
  SimpleStore();

  virtual ~SimpleStore();

  void init();
  void initTypeNames();
public:
  void shutdown();

//  store::Item *getTypeQName(store::Item *item);

  store::ItemFactory* getItemFactory() const     { return theItemFactory; }
  store::IteratorFactory* getIteratorFactory() const { return theIteratorFactory; }

  StringPool& getNamespacePool() const    { return *theNamespacePool; }
  QNamePool& getQNamePool() const         { return *theQNamePool; }
  SYNC_CODE(Lock&    getGlobalLock()                 { return theGlobalLock; })
  long getTraceLevel() const              { return theTraceLevel; }

  XmlLoader* getXmlLoader(error::ErrorManager*);

  ulong getTreeId();

  QueryContext& getQueryContext(ulong queryId);
  void deleteQueryContext(ulong queryId);

  store::Item_t createUri();

  store::Index_t createIndex(
        const xqpStringStore_t& uri,
        const store::IndexSpecification& spec);

  void deleteIndex(const xqpStringStore_t& uri);

  store::Index_t getIndex(const xqpStringStore_t& uri);

  store::Collection_t createCollection(const xqpStringStore_t& uri);
  store::Collection_t createCollection();
  store::Collection_t getCollection(const xqpStringStore_t& uri);
  void deleteCollection(const xqpStringStore_t& uri);
  store::Iterator_t listCollectionUris();

  store::Item_t loadDocument(
          const xqpStringStore_t& uri, 
          std::istream& stream, 
          bool storeDocument);
  store::Item_t loadDocument(
          const xqpStringStore_t& uri, 
          std::istream* stream, 
          bool storeDocument);
  void addNode(const xqpStringStore* uri, const store::Item_t&	 node);
  store::Item_t getDocument(const xqpStringStore_t& uri);
  void deleteDocument(const xqpStringStore_t& uri);

  short compareNodes(store::Item* node1, store::Item* node2) const;

  store::Iterator_t sortNodes(
        store::Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  store::Iterator_t distinctNodes(store::Iterator*, bool aAllowAtomics = false);

  bool getPathInfo(
    const store::Item*               docUri,
    std::vector<const store::Item*>& contextPath,
    std::vector<const store::Item*>& relativePath,
    bool                             isAttrPath,
    bool&                            found,
    bool&                            unique);

  bool getReference(store::Item_t& result, const store::Item* node);
  bool getNodeByReference(store::Item_t& result, const store::Item* uri);

  store::TempSeq_t createTempSeq();
  store::TempSeq_t createTempSeq(
                                store::Iterator* iterator, 
                                bool copyNodes = false, 
                                bool lazy = true);

  store::TempSeq_t createTempSeq(const std::vector<store::Item_t>& item_v);
};



} // namespace storeminimal
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */
