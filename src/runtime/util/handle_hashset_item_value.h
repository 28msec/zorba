#ifndef ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H
#define ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H

#include "util/hashfun.h"

#include "store/util/handle_hashset.h"
#include "runtime/booleans/BooleanImpl.h"


namespace zorba { namespace store {

class ValueCompareParam
{
public:
  ValueCompareParam(RuntimeCB* aRuntimeCB)
    : theRuntimeCB(aRuntimeCB) {}
  RuntimeCB* theRuntimeCB;
};

class ValueCollCompareParam
{
public:
  ValueCollCompareParam(RuntimeCB* aRuntimeCB)
    : theRuntimeCB(aRuntimeCB) {}

  RuntimeCB* theRuntimeCB;
  xqp_string theCollation;
};

template <class T, class E>
class Externals<T, E, ValueCompareParam>
{
public:
  static bool equal(const T* t1, const T* t2, ValueCompareParam* aCompareParam)
  {
    return E::equal(t1, t2, aCompareParam);
  }
  static uint32_t hash(const T* t1, ValueCompareParam* aCompareParam)
  {
    return E::hash(t1, aCompareParam);
  }
};

template <class T, class E>
class Externals<T, E, ValueCollCompareParam>
{
public:
  static bool equal(const T* t1, const T* t2, ValueCollCompareParam* aCompareParam)
  {
    return E::equal(t1, t2, aCompareParam);
  }
  static uint32_t hash(const T* t1, ValueCollCompareParam* aCompareParam)
  {
    return E::hash(t1, aCompareParam);
  }
};

class ItemValueHandleHashSet : public HandleSet<Item, ItemValueHandleHashSet, ValueCompareParam>
{
public:
  ItemValueHandleHashSet(ValueCompareParam* lValueCompareParam, long size = 1024)
  : HandleSet<Item, ItemValueHandleHashSet, ValueCompareParam>(lValueCompareParam, size)
  {}

  static bool equal(const Item* t1, const Item* t2, ValueCompareParam* aCompareParam)
  {
    const store::Item_t l1 = const_cast<Item*>(t1);
    const store::Item_t l2 = const_cast<Item*>(t2);
    return CompareIterator::valueEqual(aCompareParam->theRuntimeCB, l1, l2) == 0; 
  }

  static uint32_t hash(const Item* t, ValueCompareParam* aCompareParam)
  {
    return t->hash(NULL);
  }
};

class ItemValueCollHandleHashSet : public HandleSet<Item, ItemValueCollHandleHashSet, ValueCollCompareParam>
{
public:
  ItemValueCollHandleHashSet(ValueCollCompareParam* lValueCompareParamColl, long size = 1024)
  : HandleSet<Item, ItemValueCollHandleHashSet, ValueCollCompareParam>(lValueCompareParamColl, size)
  {}

  static bool equal(const Item* t1, const Item* t2, ValueCollCompareParam* aCompareParam)
  {
    const store::Item_t l1 = const_cast<Item*>(t1);
    const store::Item_t l2 = const_cast<Item*>(t2);
    return CompareIterator::valueEqual(aCompareParam->theRuntimeCB, l1, l2, &(aCompareParam->theCollation)) == 0; 
  }

  static uint32_t hash(const Item* t, ValueCollCompareParam* aCompareParam)
  {
    return t->hash(NULL);
  }
};
} // namespace store
} // namespace zorba

#endif
