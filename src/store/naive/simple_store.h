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
typedef rchandle<class AnyUriItem> AnyUriItem_t;
typedef rchandle<class Collection> Collection_t;
typedef rchandle<class TempSeq> TempSeq_t;
typedef rchandle<class PUL> PUL_t;

typedef StringHashMap<Collection_t> CollectionSet;
typedef StringHashMap<Item_t> DocumentSet;


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
  static const unsigned long DEFAULT_COLLECTION_MAP_SIZE;

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

  virtual void setGarbageCollectionStrategy(const xqp_string& strategy);

  virtual Item_t createUri();

  Item_t loadDocument(const xqp_string& uri, std::istream& stream);
  Item_t getDocument(const xqp_string& uri);
  void deleteDocument(const xqp_string& uri);

  virtual Collection_t createCollection(const xqp_string& uri);
  virtual Collection_t createCollection();
  virtual Collection_t getCollection(const xqp_string& uri);
  virtual void deleteCollection(const xqp_string& uri);

  virtual int32_t compare(Item_t item1, Item_t item2) const;

  virtual Iterator_t sortNodes(
        Iterator_t iterator,
        bool ascendent,
        bool duplicateElemination);

  virtual Iterator_t distinctNodes(Iterator_t);

  virtual TempSeq_t createTempSeq();
  virtual TempSeq_t createTempSeq(Iterator_t iterator, bool lazy = true);

  virtual Item_t getReference(Item_t);

  virtual Item_t getFixedReference(
        Item_t,
        Requester requester,
        Timetravel timetravel);

  virtual Item_t getNodeByReference(Item_t);

  virtual Item_t getNodeByReference(
        Item_t,
        Requester requester,
        Timetravel timetravel);

  virtual void apply(PUL_t pendingUpdateList);
  virtual void apply(PUL_t pendingUpdateList, Requester requester);
};

} /* namespace xqp */

#endif /* XQP_SIMPLE_STORE_H */
