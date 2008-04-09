#ifndef ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H
#define ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H

#include "util/hashfun.h"

#include "store/util/hashset.h"
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
    : theRuntimeCB(aRuntimeCB),
      theCollator(0) {}

  RuntimeCB* theRuntimeCB;
  XQPCollator* theCollator;
};

template <class T, class E>
class Externals<T, E, ValueCompareParam>
{
public:
  static bool equal(const T& t1, const T& t2, ValueCompareParam* aCompareParam)
  {
    return E::equal(t1, t2, aCompareParam);
  }
  static uint32_t hash(const T& t1, ValueCompareParam* aCompareParam)
  {
    return E::hash(t1, aCompareParam);
  }
};

template <class T, class E>
class Externals<T, E, ValueCollCompareParam>
{
public:
  static bool equal(const T& t1, const T& t2, ValueCollCompareParam* aCompareParam)
  {
    return E::equal(t1, t2, aCompareParam);
  }
  static uint32_t hash(const T& t1, ValueCollCompareParam* aCompareParam)
  {
    return E::hash(t1, aCompareParam);
  }
};


class ItemValueHandleHashSet : public HashSet<Item_t,
                                              ItemValueHandleHashSet,
                                              ValueCompareParam>
{
public:
  ItemValueHandleHashSet(ValueCompareParam* lValueCompareParam, long size = 1024)
    :
    HashSet<Item_t, ItemValueHandleHashSet, ValueCompareParam>(lValueCompareParam, size)
  {}

  static bool equal(const Item_t& t1, const Item_t& t2, ValueCompareParam* aCompareParam)
  {
    return CompareIterator::valueEqual(aCompareParam->theRuntimeCB, t1, t2) == 0; 
  }

  static uint32_t hash(const Item_t& t, ValueCompareParam* aCompareParam)
  {
    return t->hash(NULL);
  }
};


class ItemValueCollHandleHashSet : public HashSet<Item_t,
                                                  ItemValueCollHandleHashSet,
                                                  ValueCollCompareParam>
{
public:
  ItemValueCollHandleHashSet(
        ValueCollCompareParam* lValueCompareParamColl,
        long size = 1024)
  :
  HashSet<Item_t, ItemValueCollHandleHashSet, ValueCollCompareParam>(lValueCompareParamColl, size)
  {}

  static bool equal(const Item_t& t1, const Item_t& t2, ValueCollCompareParam* aCompareParam)
  {
    return CompareIterator::valueEqual(aCompareParam->theRuntimeCB,
                                       t1, t2,
                                       (aCompareParam->theCollator)) == 0; 
  }

  static uint32_t hash(const Item_t& t, ValueCollCompareParam* aCompareParam)
  {
    return t->hash(aCompareParam->theRuntimeCB, aCompareParam->theCollator);
  }
};
} // namespace store
} // namespace zorba

#endif
