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

#ifndef HASHMAP_ITEMH_CACHE_H
#define HASHMAP_ITEMH_CACHE_H

#include "context/static_context.h"
#include "runtime/sequences/deep_equality.h"
#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"

#include "store/api/item.h"
#include "store/naive/item_vector.h"

#include "system/globalenv.h"

#include <vector>

namespace zorba 
{ 

class ItemHandleCacheHashMapCmp
{
protected:
  zorba::QueryLoc theEmptyLoc;
  long theTimeZone;
  XQPCollator* theCollator;
  static_context* theSctx;
  std::vector<bool> theExcludeFromCacheKey;
  std::vector<bool> theCompareWithDeepEqual;

public:
  ItemHandleCacheHashMapCmp(
      static_context* aSctx,
      std::vector<bool>& aExcludeFromCacheKey,
      std::vector<bool>& aCompareWithDeepEqual)
    :
    theTimeZone(0),
    theCollator(NULL),
    theSctx(aSctx),
    theExcludeFromCacheKey(aExcludeFromCacheKey),
    theCompareWithDeepEqual(aCompareWithDeepEqual)
  {
  }

  ItemHandleCacheHashMapCmp(
      static_context* aSctx,
      std::vector<bool>& aExcludeFromCacheKey,
      std::vector<bool>& aCompareWithDeepEqual,
      long aTimezone,
      XQPCollator* aCollator)
    :
    theTimeZone(aTimezone),
    theCollator(aCollator),
    theSctx(aSctx),
    theExcludeFromCacheKey(aExcludeFromCacheKey),
    theCompareWithDeepEqual(aCompareWithDeepEqual)
  {
  }

  bool id_equal(const store::Item* t1, const store::Item* t2) const
  {
    if (t1 == NULL && t2 ==NULL)
      return true;

    if (t1 == NULL || t2 ==NULL)
      return false;

    store::Item::ItemKind lKind1 = t1->getKind();
    store::Item::ItemKind lKind2 = t2->getKind();
    if (lKind1 != lKind2)
      return false;

    const simplestore::ItemVector* lVector1;
    const simplestore::ItemVector* lVector2;
    switch (lKind1)
    {
      case store::Item::NODE:
      case store::Item::OBJECT:
      case store::Item::ARRAY:
      {
        return t1 == t2;
      }
      case store::Item::ATOMIC:
      {
        if (t1->getTypeCode() != t2->getTypeCode())
          return false;
        return t1->equals(t2, theTimeZone, theCollator);
      }
      case store::Item::LIST:
      {
        lVector1 = static_cast<const simplestore::ItemVector*>(t1);
        lVector2 = static_cast<const simplestore::ItemVector*>(t2);

        if (lVector1->size() != lVector2->size())
          return false;

        for (unsigned int i=0; i<lVector1->size(); ++i)
        {
          if (!id_equal(lVector1->getItem(i), lVector2->getItem(i)))
            return false;
        }
        return true;
      }
      default:
      {
        /*
         * The type of the item is one of:
         * PUL, FUNCTION, ERROR_
         */
        return false;
      }
    }
  }

  bool deep_equal(const store::Item* t1, const store::Item* t2) const
  {
    if (t1 == NULL && t2 == NULL)
      return true;

    if (t1 == NULL || t2 ==NULL)
      return false;

    store::Item::ItemKind lKind1 = t1->getKind();
    store::Item::ItemKind lKind2 = t2->getKind();
    if (lKind1 != lKind2)
      return false;

    const simplestore::ItemVector* lVector1;
    const simplestore::ItemVector* lVector2;
    switch (lKind1)
    {
      case store::Item::NODE:
      {
        return equality::deepEqualNodes(theEmptyLoc, theSctx, t1, t2, theCollator, theTimeZone, false);
      }
      case store::Item::OBJECT:
      {
        return equality::deepEqualObjects(theEmptyLoc, theSctx, t1, t2, theCollator, theTimeZone, false);
      }
      case store::Item::ARRAY:
      {
        return equality::deepEqualArrays(theEmptyLoc, theSctx, t1, t2, theCollator, theTimeZone, false);
      }
      case store::Item::ATOMIC:
      {
        if (t1->getTypeCode() != t2->getTypeCode())
          return false;
        return t1->equals(t2, theTimeZone, theCollator);
      }
      case store::Item::LIST:
      {
        lVector1 = static_cast<const simplestore::ItemVector*>(t1);
        lVector2 = static_cast<const simplestore::ItemVector*>(t2);

        if (lVector1->size() != lVector2->size())
          return false;

        for (unsigned int i=0; i<lVector1->size(); ++i)
        {
          if (!deep_equal(lVector1->getItem(i), lVector2->getItem(i)))
            return false;
        }
        return true;
      }
      default:
      {
        /*
         * The type of the item is one of:
         * PUL, FUNCTION, ERROR_
         */
        return false;
      }
    }
  }

  bool equal(const store::Item* t1, const store::Item* t2) const
  {
    const simplestore::ItemVector* lVector1 =
        static_cast<const simplestore::ItemVector*>(t1);
    const simplestore::ItemVector* lVector2 =
        static_cast<const simplestore::ItemVector*>(t2);

    for (unsigned int i=0; i<lVector1->size(); ++i)
    {
      if (!theExcludeFromCacheKey.size() || !theExcludeFromCacheKey[i])
      {
        if (!theCompareWithDeepEqual.size() || !theCompareWithDeepEqual[i])
        {
          if (!id_equal(lVector1->getItem(i), lVector2->getItem(i)))
            return false;
        }
        else
        {
          if (!deep_equal(lVector1->getItem(i), lVector2->getItem(i)))
            return false;
        }
      }
    }
    return true;
  }

  uint32_t id_hash(const store::Item* t) const
  {
    if (t == NULL)
      return FNV_32_INIT;

    store::SchemaTypeCode lTypeCode;
    uint32_t lInnerHash;
    const simplestore::ItemVector* lVector;
    store::Item::ItemKind lKind = t->getKind();
    uint32_t lHash = hashfun::h32(&lKind, sizeof(store::Item::ItemKind), FNV_32_INIT);
    switch (lKind)
    {
      case store::Item::NODE:
      case store::Item::OBJECT:
      case store::Item::ARRAY:
      {
        return hashfun::h32((void*)(&t), sizeof(t), lHash);
      }
      case store::Item::ATOMIC:
      {
        lTypeCode = t->getTypeCode();
        lHash = hashfun::h32(&lTypeCode, sizeof(lTypeCode), lHash);
        lInnerHash = t->hash(theTimeZone, theCollator);
        return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
      case store::Item::LIST:
      {
        lVector = static_cast<const simplestore::ItemVector*>(t);
        for (unsigned int i=0; i<lVector->size(); ++i)
        {
          lInnerHash = id_hash(lVector->getItem(i));
          lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
        }
        return lHash;
      }
      default:
      {
        /*
         * The type of the item is one of:
         * PUL, FUNCTION, ERROR_
         */
        return FNV_32_INIT;
      }
    }
  }

  uint32_t deep_hash(const store::Item* t) const
  {
    if (t == NULL)
      return FNV_32_INIT;

    store::SchemaTypeCode lTypeCode;
    uint32_t lInnerHash;
    const simplestore::ItemVector* lVector;
    store::Item::ItemKind lKind = t->getKind();
    uint32_t lHash = hashfun::h32(&lKind, sizeof(store::Item::ItemKind), FNV_32_INIT);
    switch (lKind)
    {
      case store::Item::NODE:
      {
        lInnerHash = equality::deHashNode(theEmptyLoc, theSctx, t, theCollator, theTimeZone);
        return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
      case store::Item::OBJECT:
      {
        lInnerHash = equality::deHashObject(theEmptyLoc, theSctx, t, theCollator, theTimeZone);
        return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
      case store::Item::ARRAY:
      {
        lInnerHash = equality::deHashArray(theEmptyLoc, theSctx, t, theCollator, theTimeZone);
        return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
      case store::Item::ATOMIC:
      {
        lTypeCode = t->getTypeCode();
        lHash = hashfun::h32(&lTypeCode, sizeof(lTypeCode), lHash);
        lInnerHash = t->hash(theTimeZone, theCollator);
        return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
      case store::Item::LIST:
      {
        lVector = static_cast<const simplestore::ItemVector*>(t);
        for (unsigned int i=0; i<lVector->size(); ++i)
        {
          lInnerHash = equality::deHash(theEmptyLoc, theSctx, lVector->getItem(i), theCollator, theTimeZone);
          lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
        }
        return lHash;
      }
      default:
      {
        /*
         * The type of the item is one of:
         * PUL, FUNCTION, ERROR_
         */
        return FNV_32_INIT;
      }
    }
  }

  uint32_t hash(const store::Item* t) const
  {
    const simplestore::ItemVector* lVector =
      static_cast<const simplestore::ItemVector*>(t);
    uint32_t lHash = FNV_32_INIT;
    uint32_t lInnerHash;

    for (unsigned int i=0; i<lVector->size(); ++i)
    {
      if (!theExcludeFromCacheKey.size() || !theExcludeFromCacheKey[i])
      {
        if (!theCompareWithDeepEqual.size() || !theCompareWithDeepEqual[i])
          lInnerHash = id_hash(lVector->getItem(i));
        else
          lInnerHash = deep_hash(lVector->getItem(i));

        lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
    }
    return lHash;
  }


  long get_timezone() const { return theTimeZone; }

  const XQPCollator* get_collator() const { return theCollator; }
};


/*******************************************************************************
  A hash-based map mapping item handles to data items of type V. Equality is
  based on pointer equality for Nodes, Arrays and Objects and on the
  store::Item::equals() method for atomic. PULs, Function Items, and Error_s are
  not supported and are always considered different.

  NOTE: Although the map uses raw item pointers instead of rchandles, reference
        counting is still done, but done manually (see insert, clear and erase
        methods)
 ********************************************************************************/
template <class V>
class ItemHandleCacheHashMap
{
public:
  typedef typename HashMap<store::Item*, V, ItemHandleCacheHashMapCmp>::iterator iterator;

private:
  HashMap<store::Item*, V, ItemHandleCacheHashMapCmp> theMap;

public:
  ItemHandleCacheHashMap(
      static_context* aSctx,
      std::vector<bool>& aExcludeFromCacheKey,
      std::vector<bool>& aCompareWithDeepEqual)
:
  theMap(
    ItemHandleCacheHashMapCmp(aSctx, aExcludeFromCacheKey, aCompareWithDeepEqual),
    8,
    false)
{
}

  ItemHandleCacheHashMap(
      static_context* aSctx,
      std::vector<bool>& aExcludeFromCacheKey,
      std::vector<bool>& aCompareWithDeepEqual,
      ulong aSize,
      bool aSync)
  :
    theMap(
      ItemHandleCacheHashMapCmp(aSctx, aExcludeFromCacheKey, aCompareWithDeepEqual),
      aSize,
      aSync)
  {
  }

  ItemHandleCacheHashMap(
      static_context* aSctx,
      std::vector<bool>& aExcludeFromCacheKey,
      std::vector<bool>& aCompareWithDeepEqual,
      long aTimezone,
      XQPCollator* aCollation,
      ulong aSize,
      bool aSync)
  :
    theMap(
      ItemHandleCacheHashMapCmp(aSctx, aExcludeFromCacheKey, aCompareWithDeepEqual, aTimezone, aCollation),
      aSize,
      aSync)
  {
  }

  ~ItemHandleCacheHashMap()
  {
    clear();
  }

  void clear()
  {
    SYNC_CODE(AutoMutex lock(theMap.get_mutex());)

    iterator ite = this->begin();
    iterator end = this->end();

    for (; ite != end; ++ite)
    {
      (*ite).first->removeReference();
    }

    theMap.clearNoSync();
  }

  iterator begin() const { return theMap.begin(); }

  iterator end() const { return theMap.end(); }

  iterator find(const store::Item_t& item)
  {
    return theMap.find(item.getp());
  }

  bool insert(const store::Item_t& item, V& value)
  {
    bool inserted = theMap.insert(item.getp(), value);

    if (inserted)
      item->addReference();

    return inserted;
  }

  bool erase(const store::Item_t& key)
  {
    bool found = theMap.erase(key.getp());

    if (found)
      key->removeReference();

    return found;
  }

  csize size() const
  {
    return theMap.size();
  }

  bool empty() const
  {
    return theMap.size() == 0;
  }

};

}

#endif
