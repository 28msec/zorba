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


#include "common/shared_types.h"

#include "store/api/store.h"
#include "store/api/collection.h"

#include "store/util/hashmap_stringp.h"
#include "store/util/mutex.h"
#include "store/util/latch.h"

#include "store/naive/shared_types.h"
#include "store/naive/node_items.h"


namespace zorba { 

class GlobalEnvironment;

namespace error {
  class ErrorManager;
}

namespace store {

typedef StringHashMap<Collection_t> CollectionSet;
typedef StringHashMap<XmlNode_t> DocumentSet;


/*******************************************************************************

********************************************************************************/
class SimpleStore : public Store
{
  friend class zorba::GlobalEnvironment;
 
public:
  static const char* XS_URI;
  static const char* XML_URI;

protected:
  static const ulong DEFAULT_COLLECTION_MAP_SIZE;
  static const ulong NAMESPACE_POOL_SIZE;

public:
  xqpStringStore_t         theEmptyNs;
  xqpStringStore_t         theXmlSchemaNs;

  checked_vector<Item_t>   theSchemaTypeNames;

protected:
  bool                     theIsInitialized;

  ulong                    theUriCounter;
  SYNC_CODE(Mutex          theUriCounterMutex;)

  ulong                    theTreeCounter;
  SYNC_CODE(Mutex          theTreeCounterMutex;)

  StringPool             * theNamespacePool;
  QNamePool              * theQNamePool;

  ItemFactory            * theItemFactory;

  DocumentSet              theDocuments;
  CollectionSet            theCollections;

  QueryContextContainer  * theQueryContextContainer; 

  Latch          theGlobalLock;

#ifndef NDEBUG
  long                     theTraceLevel;
#endif

private:
  SimpleStore();

  virtual ~SimpleStore();

  void init();
  void initTypeNames();
  void shutdown();

public:
  store::ItemFactory* getItemFactory() const { return theItemFactory; }

  StringPool& getNamespacePool() const    { return *theNamespacePool; }
  QNamePool& getQNamePool() const         { return *theQNamePool; }

  Latch& getGlobalLock()                  { return theGlobalLock; }

#ifndef NDEBUG
  long getTraceLevel() const              { return theTraceLevel; }
#endif

  XmlLoader* getXmlLoader(error::ErrorManager*);

  ulong getTreeId();

  QueryContext& getQueryContext(ulong queryId);
  void deleteQueryContext(ulong queryId);

  store::Item_t createUri();

  store::Item_t loadDocument(xqpStringStore_t& uri, std::istream& stream);
  store::Item_t loadDocument(xqpStringStore_t& uri, std::istream* stream);
  store::Item_t loadDocument(const xqpStringStore_t& uri, store::Item_t	 doc_item);
  store::Item_t getDocument(const xqpStringStore_t& uri);
  void deleteDocument(const xqpStringStore_t& uri);

  Collection_t createCollection(xqpStringStore_t& uri);
  Collection_t createCollection();
  Collection_t getCollection(const xqpStringStore_t& uri);
  void deleteCollection(const xqpStringStore_t& uri);

  long compareNodes(Item* node1, Item* node2) const;

  Iterator_t sortNodes(
        Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  Iterator_t distinctNodes(Iterator*, bool aAllowAtomics = false);

  TempSeq_t createTempSeq();
  TempSeq_t createTempSeq(Iterator* iterator, bool copyNodes = false, bool lazy = true);

  store::Item_t getReference(store::Item_t);

  store::Item_t getNodeByReference(store::Item_t);
};



} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */
