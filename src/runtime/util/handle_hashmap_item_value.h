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
#include "runtime/api/runtimecb.h"
#include "context/dynamic_context.h"


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
    theRuntimeCB(aRuntimeCB),
    theTypeManager(theRuntimeCB->theStaticContext->get_typemanager()),
    theTimezone(theRuntimeCB->theDynamicContext->get_implicit_timezone()),
    theCollators(aCollators)
  {
  }

  RuntimeCB                 * theRuntimeCB;
  TypeManager               * theTypeManager;
  long                        theTimezone;
  std::vector<XQPCollator*>   theCollators;
};



template <class V>
class ItemValuesCollHandleHashMap
{
 public:
  class CompareFunction
  {
  private:
    GroupCompareParam * theCompareParam;

  public:
    CompareFunction(GroupCompareParam* comp) : theCompareParam(comp) { }

    bool equal(const GroupKey* t1, const GroupKey* t2)
    {
      assert(theCompareParam->theCollators.size() == t1->theTypedKey.size());
      assert(t2->theTypedKey.size() == t1->theTypedKey.size());

      std::vector<store::Item_t>::const_iterator iter1 = t1->theTypedKey.begin();
      std::vector<store::Item_t>::const_iterator iter2 = t2->theTypedKey.begin();
      std::vector<XQPCollator*>::iterator lCollIter = theCompareParam->theCollators.begin();

      while(iter1 != t1->theTypedKey.end())
      {
        if(*iter1 == NULL)
        {      
          if(*iter2 != NULL)
          {
            return false;
          }
        }
        else if(*iter2 == NULL)
        {
          return false;
        }
        else
        {
          store::Item_t item1 = *iter1;
          store::Item_t item2 = *iter2;
          if(CompareIterator::valueEqual(item1,
                                         item2,
                                         theCompareParam->theTypeManager,
                                         theCompareParam->theTimezone,
                                         (*lCollIter)) != 1)
          {
            return false;                                 
          }
        }

        ++lCollIter;
        ++iter1;
        ++iter2;
      }
      return true;
    }

    uint32_t hash (GroupKey* t)
    {
      uint32_t hash = 0;
      assert(theCompareParam->theCollators.size() == t->theTypedKey.size());
      std::vector<store::Item_t>::iterator lItemIter = t->theTypedKey.begin();
      std::vector<XQPCollator*>::iterator lCollIter = theCompareParam->theCollators.begin();
      while(lItemIter != t->theTypedKey.end())
      {
        store::Item_t lCurItem = (*lItemIter);
        if(lCurItem != NULL)
        {
          hash += (*lItemIter)->hash(theCompareParam->theTimezone, *lCollIter);
        }
        ++lCollIter;
        ++lItemIter;
      }
      return hash;
    }

  };


  typedef typename HashMap<GroupKey*, V, CompareFunction>::iterator iterator;

private:
  GroupCompareParam                     * theCompareParam;
  CompareFunction                         theCompareFunction;
  HashMap<GroupKey*, V, CompareFunction>  theMap;

public:
  ItemValuesCollHandleHashMap(
        GroupCompareParam* compParam,
        long size = 1024)
    :
    theCompareParam(compParam),
    theCompareFunction(compParam),
    theMap(theCompareFunction, size, false)
  {
  }

  ~ItemValuesCollHandleHashMap() 
  {
    if (theCompareParam)
      delete theCompareParam; 
  }
 
  iterator begin() { return theMap.begin(); }
  iterator end() { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  bool get(GroupKey* key, V& value) { return theMap.get(key, value); }

  bool insert(GroupKey* key, V& value) { return theMap.insert(key, value); }

  bool remove(GroupKey* key) { return theMap.remove(key); }

  void clear() { theMap.clear(); }
};


} // namespace zorba

#endif
