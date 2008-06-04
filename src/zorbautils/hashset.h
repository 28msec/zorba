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
#ifndef ZORBA_STORE_UTIL_HASHSET
#define ZORBA_STORE_UTIL_HASHSET

#include "zorbautils/checked_vector.h"
#include "zorbautils/hashmap.h"
#include "zorbautils/mutex.h"

#include "zorbamisc/config/platform.h"


namespace zorba { 


class DummyHashValue
{
};


/*******************************************************************************

********************************************************************************/
template <class T, class E, class C = DummyCompareParam>
class HashSet : public HashMap<T, DummyHashValue, E, C>
{
public:

HashSet(ulong size, bool sync, bool useTransfer = false)
  :
  HashMap<T, DummyHashValue, E, C>(size, sync, useTransfer)
{
}


HashSet(C* compParam, ulong size, bool sync, bool useTransfer = false)
  :
  HashMap<T, DummyHashValue, E, C>(compParam, size, sync, useTransfer) 
{
}


virtual ~HashSet()
{
}


/*******************************************************************************

********************************************************************************/
void clear() 
{
  HashMap<T, DummyHashValue, E, C>::clear();
}


/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool find(const T& item)
{
  return HashMap<T, DummyHashValue, E, C>::find(item);
}


/******************************************************************************
  If the set does not already contain an item that is "equal" to the given item,
  insert the given item to the set and return true. Otherwise, return false.
********************************************************************************/
bool insert(T& item)
{
  bool found;

  SYNC_CODE(AutoMutex lock(this->theMutexp);)

  //assert(item != 0);

  HashEntry<T, DummyHashValue>* entry;
  entry = hashInsert(item,
                     Externals<T,E,C>::hash(item, this->theCompareParam),
                     found);

  if (!found)
  {
    if (this->theUseTransfer)
      entry->theItem.transfer(item);
    else
      entry->theItem = item;
  }

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, insert the given item to the set and return true. Otherwise, return
  false and a copy of the found item I.
********************************************************************************/
bool insert(T& item,  T& outItem)
{
  bool found;

  SYNC_CODE(AutoMutex lock(this->theMutexp);)

  //assert(item != 0);

  HashEntry<T, DummyHashValue>* entry;
  entry = hashInsert(item,
                     Externals<T,E,C>::hash(item, this->theCompareParam),
                     found);
  if (!found)
  {
    if (this->theUseTransfer)
      entry->theItem.transfer(item);
    else
      entry->theItem = item;

    outItem = entry->theItem;
    return true;
  }
  else
  {
    outItem = entry->theItem;
    return false;
  }
}


/*******************************************************************************
  If the set contains an item that is "equal" to the given item, remove that
  item from the set and return true. Otherwise, return false.
********************************************************************************/
bool remove(const T& item)
{
  return HashMap<T, DummyHashValue, E, C>::remove(item);
}

};



} // namespace zorba

#endif
