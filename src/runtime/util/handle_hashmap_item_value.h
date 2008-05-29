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
#ifndef ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H
#define ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H

#include "zorbautils/hashmap.h"
#include "runtime/booleans/BooleanImpl.h"


namespace zorba
{

//TODO Do this nice when refactoring the FLWOR
class GroupKey
{
 public:
  std::vector<store::Item_t> theKey;
  std::vector<store::Item_t> theTypedKey;    
};


class GroupCompareParam
{
 public:
  GroupCompareParam(RuntimeCB* aRuntimeCB, std::vector<XQPCollator*> aCollators)
    :
    theRuntimeCB ( aRuntimeCB ),
    theCollators(aCollators)
    {
    }

  RuntimeCB                 * theRuntimeCB;
  std::vector<XQPCollator*>   theCollators;
};


template <class T, class E>
class Externals<T, E, GroupCompareParam>
{
 public:
  static bool equal(const T& t1, const T& t2, GroupCompareParam* aCompareParam)
  {
    return E::equal(t1, t2, aCompareParam);
  }

  static uint32_t hash(const T& t1, GroupCompareParam* aCompareParam)
  {
    return E::hash(t1, aCompareParam);
  }
};



template <class V>
class ItemValuesCollHandleHashMap : public HashMap<GroupKey*,
                                                   V,
                                                   ItemValuesCollHandleHashMap<V>,
                                                   GroupCompareParam>
{
 public:
  ItemValuesCollHandleHashMap (
        GroupCompareParam* aCompareParam,
        long size = 1024 )
    :
    HashMap<GroupKey*,
            V,
            ItemValuesCollHandleHashMap,
            GroupCompareParam>( aCompareParam, size, false)
  {
  }

  static bool equal(
        const GroupKey* t1,
        const GroupKey* t2,
        GroupCompareParam* aCompareParam )
  {
    assert(aCompareParam->theCollators.size() == t1->theTypedKey.size());
    assert(t2->theTypedKey.size() == t1->theTypedKey.size());
    std::vector<store::Item_t>::const_iterator iter1 = t1->theTypedKey.begin();
    std::vector<store::Item_t>::const_iterator iter2 = t2->theTypedKey.begin();
    std::vector<XQPCollator*>::iterator lCollIter = aCompareParam->theCollators.begin();
    while(iter1 != t1->theTypedKey.end()){
      if(CompareIterator::valueEqual ( aCompareParam->theRuntimeCB,
                                       *iter1, *iter2,
                                       ( *lCollIter ) ) != 0){
        return false;                                 
      }
      ++lCollIter;
      ++iter1;
      ++iter2;
    }
    return true;
  }

  static uint32_t hash (GroupKey* t, GroupCompareParam* aCompareParam )
  {
    uint32_t hash=0;
    assert(aCompareParam->theCollators.size() == t->theTypedKey.size());
    std::vector<store::Item_t>::iterator lItemIter = t->theTypedKey.begin();
    std::vector<XQPCollator*>::iterator lCollIter = aCompareParam->theCollators.begin();
    while(lItemIter != t->theTypedKey.end()){
      hash += (*lItemIter)->hash ( aCompareParam->theRuntimeCB, *lCollIter );
      ++lCollIter;
      ++lItemIter;
    }
    return hash;
  }

};


} // namespace zorba

#endif
