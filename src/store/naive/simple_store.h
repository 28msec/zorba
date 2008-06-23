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

#include "zorbautils/mutex.h"
#include "zorbautils/latch.h"

#include "common/shared_types.h"

#include "store/api/store.h"
#include "store/api/collection.h"

#include "store/util/hashmap_stringp.h"

#include "store/naive/shared_types.h"
#include "store/naive/node_items.h"


namespace zorba { 

class GlobalEnvironment;

namespace error 
{
  class ErrorManager;
}


namespace simplestore 
{

class SimpleStoreManager;
class StringPool;
class QNamePool;
class XmlLoader;


typedef rchandle<XmlNode> XmlNode_t;
typedef store::StringHashMap<XmlNode_t> DocumentSet;
typedef store::StringHashMap<store::Collection_t> CollectionSet;



/*******************************************************************************

********************************************************************************/
class SimpleStore : public store::Store
{
  friend class zorba::GlobalEnvironment;
  friend class simplestore::SimpleStoreManager;
 
public:
  static const char* XS_URI;
  static const char* XML_URI;

protected:
  static const ulong DEFAULT_COLLECTION_MAP_SIZE;
  static const ulong NAMESPACE_POOL_SIZE;

public:
  xqpStringStore_t              theEmptyNs;
  xqpStringStore_t              theXmlSchemaNs;

  checked_vector<store::Item_t> theSchemaTypeNames;

protected:
  bool                          theIsInitialized;

  ulong                         theUriCounter;
  SYNC_CODE(Mutex               theUriCounterMutex;)

  ulong                         theTreeCounter;
  SYNC_CODE(Mutex               theTreeCounterMutex;)

  StringPool                  * theNamespacePool;
  QNamePool                   * theQNamePool;

  store::ItemFactory          * theItemFactory;

  DocumentSet                   theDocuments;
  CollectionSet                 theCollections;

  Latch                         theGlobalLock;

  long                          theTraceLevel;

private:
  SimpleStore();

  virtual ~SimpleStore();

  void init();
  void initTypeNames();

public:
  void shutdown();
  store::ItemFactory* getItemFactory() const { return theItemFactory; }

  StringPool& getNamespacePool() const    { return *theNamespacePool; }
  QNamePool& getQNamePool() const         { return *theQNamePool; }

  Latch& getGlobalLock()                  { return theGlobalLock; }

  long getTraceLevel() const              { return theTraceLevel; }

  XmlLoader* getXmlLoader(error::ErrorManager*);

  ulong getTreeId();

  store::Item_t createUri();

  store::Collection_t createCollection(xqpStringStore_t& uri);
  store::Collection_t createCollection();
  store::Collection_t getCollection(const xqpStringStore_t& uri);
  void deleteCollection(const xqpStringStore_t& uri);

  store::Item_t loadDocument(xqpStringStore_t& uri, std::istream& stream);
  store::Item_t loadDocument(xqpStringStore_t& uri, std::istream* stream);
  void addNode(const xqpStringStore* uri, const store::Item_t& node);
  store::Item_t getDocument(const xqpStringStore_t& uri);
  void deleteDocument(const xqpStringStore_t& uri);

  long compareNodes(store::Item* node1, store::Item* node2) const;

  store::Iterator_t sortNodes(
        store::Iterator* iterator,
        bool             ascendent,
        bool             duplicateElemination,
        bool             aAllowAtomics = false);

  store::Iterator_t distinctNodes(store::Iterator*, bool aAllowAtomics = false);

  bool getReference(store::Item_t& result, const store::Item* node);
  bool getNodeByReference(store::Item_t& result, const store::Item* uri);

  store::TempSeq_t createTempSeq();

  store::TempSeq_t createTempSeq(
        store::Iterator* iterator,
        bool copyNodes = false,
        bool lazy = true);
};



} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */
