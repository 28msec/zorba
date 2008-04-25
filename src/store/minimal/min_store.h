#ifndef ZORBA_MINIMAL_STORE___
#define ZORBA_MINIMAL_STORE___


#include "common/shared_types.h"

#include "store/api/store.h"
#include "store/util/pointer_hashmap_string.h"
#include "store/util/mutex.h"
#include "store/api/collection.h"
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
  int                      theIsInitialized;

  ulong                    theUriCounter;
  SYNC_CODE(Mutex          theUriCounterMutex;)

  ulong                    theTreeCounter;
  SYNC_CODE(Mutex          theTreeCounterMutex;)

//  StringPool             * theNamespacePool;
//  QNamePool              * theQNamePool;

  ItemFactory            * theItemFactory;

  DocumentSet              theDocuments;
  CollectionSet            theCollections;

  QueryContextContainer  * theQueryContextContainer; 

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
  Item *getTypeQName(Item *item);

  store::ItemFactory* getItemFactory() const     { return theItemFactory; }

//  StringPool& getNamespacePool() const    { return *theNamespacePool; }
//  QNamePool& getQNamePool() const         { return *theQNamePool; }
#ifndef NDEBUG
  long getTraceLevel() const              { return theTraceLevel; }
#endif

  XmlLoader* getXmlLoader(error::ErrorManager*);

  ulong getTreeId();

  QueryContext& getQueryContext(ulong queryId);
  void deleteQueryContext(ulong queryId);

  void setGarbageCollectionStrategy(xqpStringStore* strategy);

  store::Item_t createUri();

  store::Item_t loadDocument(xqpStringStore* uri, std::istream& stream);
  store::Item_t loadDocument(xqpStringStore* uri, store::Item_t	 doc_item);
  store::Item_t getDocument(xqpStringStore* uri);
  void deleteDocument(xqpStringStore* uri);

  Collection_t createCollection(xqpStringStore* uri);
  Collection_t createCollection();
  Collection_t getCollection(xqpStringStore* uri);
  void deleteCollection(xqpStringStore* uri);

  long compareNodes(Item* node1, Item* node2) const;
  bool equalNodes(const Item* node1, const Item* node2) const;
  uint32_t hashNode(const Item* node) const;

  Iterator_t sortNodes(
        Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  Iterator_t distinctNodes(Iterator*, bool aAllowAtomics = false);

  TempSeq_t createTempSeq();
  TempSeq_t createTempSeq(Iterator* iterator, bool copyNodes = false, bool lazy = true);

  store::Item_t getReference(store::Item_t);

  store::Item_t getFixedReference(
        store::Item_t,
        Requester requester,
        TimeTravel timetravel);

  store::Item_t getNodeByReference(store::Item_t);

  store::Item_t getNodeByReference(
        store::Item_t,
        Requester requester,
        TimeTravel timetravel);

  void apply(PUL_t pendingUpdateList);
  void apply(PUL_t pendingUpdateList, Requester requester);
};



} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */
