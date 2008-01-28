/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf (david.graf@28msec.com), Markos Zaharioudakis
 *
 */

#ifndef XQP_DEFAULT_STORE_H
#define XQP_DEFAULT_STORE_H

#include "store/api/store.h"
#include "store/util/string_pool.h"
#include "store/util/string_hashmap.h"
#include "store/naive/basic_item_factory.h"

namespace xqp
{

class QNamePool;
class StringPool;
class XmlLoader;
class Timetravel;
class Requester;

template <class V> class StringHashMap;

template <class Object> class rchandle;

typedef rchandle<class Iterator> Iterator_t;
typedef rchandle<class Item> Item_t;
typedef rchandle<class XmlTree> XmlTree_t;
typedef rchandle<class AnyUriItem> AnyUriItem_t;
typedef rchandle<class Collection> Collection_t;
typedef rchandle<class TempSeq> TempSeq_t;
typedef rchandle<class PUL> PUL_t;

typedef StringHashMap<Collection_t> CollectionSet;
typedef StringHashMap<XmlTree_t> DocumentSet;


/*******************************************************************************

********************************************************************************/
class SimpleStore : public Store
{
  friend class Store;
 
  typedef StringPool  NamespacePool;

public:
  static const char* XS_URI;

protected:
  static const float DEFAULT_HASH_LOAD_FACTOR;
  static const xqp_ulong DEFAULT_COLLECTION_MAP_SIZE;

  static unsigned long theUriCounter;
  static unsigned long theTreeCounter;

public:
  xqpStringStore_t     theEmptyNs;
  xqpStringStore_t     theXmlSchemaNs;
  Item_t               theUntypedType;
  Item_t               theAnyType;
  Item_t               theUntypedAtomicType;
  Item_t               theQNameType;

protected:
  bool                 theIsInitialized;

  NamespacePool      * theNamespacePool;
  QNamePool          * theQNamePool;

  BasicItemFactory   * theItemFactory;

  CollectionSet        theCollections;
  DocumentSet          theDocuments;

  XmlLoader          * theXmlLoader;

private:
  SimpleStore();

  virtual ~SimpleStore();

  void init();

public:
  ItemFactory& getItemFactory() const     { return *theItemFactory; }

  NamespacePool& getNamespacePool() const { return *theNamespacePool; }
  QNamePool& getQNamePool() const         { return *theQNamePool; }

  XmlLoader& getXmlLoader();

  unsigned long getTreeId()               { return theTreeCounter++; }

  void setGarbageCollectionStrategy(const xqp_string& strategy);

  Item_t createUri();

  Item_t loadDocument(const xqp_string& uri, std::istream& stream);
  Item_t loadDocument(const xqp_string& uri, Item_t	 doc_item);
  Item_t getDocument(const xqp_string& uri);
  void deleteDocument(const xqp_string& uri);

  Collection_t createCollection(const xqp_string& uri);
  Collection_t createCollection();
  Collection_t getCollection(const xqp_string& uri);
  void deleteCollection(const xqp_string& uri);

  int32_t compare(Item* item1, Item* item2) const;

  Iterator_t sortNodes(
        Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAllowAtomics = false);

  Iterator_t distinctNodes(Iterator*, bool aAllowAtomics = false);

  TempSeq_t createTempSeq();
  TempSeq_t createTempSeq(Iterator* iterator, bool lazy = true);

  Item_t getReference(Item_t);

  Item_t getFixedReference(
        Item_t,
        Requester requester,
        Timetravel timetravel);

  Item_t getNodeByReference(Item_t);

  Item_t getNodeByReference(
        Item_t,
        Requester requester,
        Timetravel timetravel);

  void apply(PUL_t pendingUpdateList);
  void apply(PUL_t pendingUpdateList, Requester requester);
};

} /* namespace xqp */

#endif /* XQP_SIMPLE_STORE_H */
