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
#include "zorbautils/latch.h"

#include "common/shared_types.h"

#include "store/api/store.h"
#include "store/api/collection.h"

#include "store/util/hashmap_stringp.h"

#include "store/minimal/shared_types.h"
#include "store/minimal/min_node_items.h"


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

  Latch                   theGlobalLock;

  long                     theTraceLevel;
public:
  static ZORBA_EXTERN_DECL SimpleStore*      getInstance();
private:
  SimpleStore();

  virtual ~SimpleStore();

  void init();
  void initTypeNames();
public:
  void shutdown();

//  Item *getTypeQName(Item *item);

  store::ItemFactory* getItemFactory() const     { return theItemFactory; }

  StringPool& getNamespacePool() const    { return *theNamespacePool; }
  QNamePool& getQNamePool() const         { return *theQNamePool; }
  Latch&    getGlobalLock()                 { return theGlobalLock; }
#ifndef NDEBUG
  long getTraceLevel() const              { return theTraceLevel; }
#endif

  XmlLoader* getXmlLoader(error::ErrorManager*);

  ulong getTreeId();

  QueryContext& getQueryContext(ulong queryId);
  void deleteQueryContext(ulong queryId);

  Item_t createUri();

  Collection_t createCollection(xqpStringStore_t& uri);
  Collection_t createCollection();
  Collection_t getCollection(const xqpStringStore_t& uri);
  void deleteCollection(const xqpStringStore_t& uri);

  Item_t loadDocument(xqpStringStore_t& uri, std::istream& stream);
  Item_t loadDocument(xqpStringStore_t& uri, std::istream* stream);
  void addNode(const xqpStringStore* uri, const Item_t&	 node);
  Item_t getDocument(const xqpStringStore_t& uri);
  void deleteDocument(const xqpStringStore_t& uri);

  long compareNodes(Item* node1, Item* node2) const;

  Iterator_t sortNodes(
        Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  Iterator_t distinctNodes(Iterator*, bool aAllowAtomics = false);

  bool getReference(Item_t& result, const Item* node);
  bool getNodeByReference(Item_t& result, const Item* uri);

  TempSeq_t createTempSeq();
  TempSeq_t createTempSeq(Iterator* iterator, bool copyNodes = false, bool lazy = true);

};



} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */
