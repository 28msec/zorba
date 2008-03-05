#ifndef ZORBA_DEFAULT_STORE_H
#define ZORBA_DEFAULT_STORE_H


#include "zorba/common/api_shared_types.h"

#include "store/api/store.h"
#include "store/util/string_hashset.h"
#include "store/util/string_hashmap.h"
#include "store/util/mutex.h"


namespace zorba { 

class GlobalEnvironment;

namespace store {

template <class V> class StringHashMap;
typedef StringHashMap<Collection_t> CollectionSet;
typedef StringHashMap<XmlNode_t> DocumentSet;


/*******************************************************************************

********************************************************************************/
class SimpleStore : public Store
{
  friend class zorba::GlobalEnvironment;
 
  typedef StringPool  NamespacePool;

public:
  static const char* XS_URI;

protected:
  static const float DEFAULT_HASH_LOAD_FACTOR;
  static const ulong DEFAULT_COLLECTION_MAP_SIZE;

public:
  xqpStringStore_t         theEmptyNs;
  xqpStringStore_t         theXmlSchemaNs;
  store::Item_t                   theUntypedType;
  store::Item_t                   theAnyType;
  store::Item_t                   theUntypedAtomicType;
  store::Item_t                   theQNameType;

protected:
  bool                     theIsInitialized;

  ulong                    theUriCounter;
  Mutex                    theUriCounterMutex;

  ulong                    theTreeCounter;
  Mutex                    theTreeCounterMutex;

  NamespacePool          * theNamespacePool;
  QNamePool              * theQNamePool;

  ItemFactory            * theItemFactory;

  DocumentSet              theDocuments;
  CollectionSet            theCollections;

  QueryContextContainer  * theQueryContextContainer; 

private:
  SimpleStore();

  virtual ~SimpleStore();

  void init();
  void shutdown();

public:
  store::ItemFactory* getItemFactory() const     { return theItemFactory; }

  NamespacePool& getNamespacePool() const { return *theNamespacePool; }
  QNamePool& getQNamePool() const         { return *theQNamePool; }

  XmlLoader* getXmlLoader();

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

  int32_t compare(Item* item1, Item* item2) const;

  Iterator_t sortNodes(
        Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  Iterator_t distinctNodes(Iterator*, bool aAllowAtomics = false);

  TempSeq_t createTempSeq();
  TempSeq_t createTempSeq(Iterator* iterator, bool lazy = true);

  store::Item_t getReference(store::Item_t);

  store::Item_t getFixedReference(
        store::Item_t,
        Requester requester,
        Timetravel timetravel);

  store::Item_t getNodeByReference(store::Item_t);

  store::Item_t getNodeByReference(
        store::Item_t,
        Requester requester,
        Timetravel timetravel);

  void apply(PUL_t pendingUpdateList);
  void apply(PUL_t pendingUpdateList, Requester requester);
};



} // namespace store
} // namespace zorba

#endif /* ZORBA_SIMPLE_STORE_H */
