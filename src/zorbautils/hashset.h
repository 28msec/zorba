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
#pragma once
#ifndef ZORBA_STORE_UTIL_HASHSET
#define ZORBA_STORE_UTIL_HASHSET

#include <zorba/config.h>
#include "zorbautils/checked_vector.h"
#include "zorbautils/hashmap.h"
#include "zorbautils/mutex.h"

#include "zorbamisc/config/platform.h"


namespace zorba 
{ 


class DummyHashValue
{
};


/*******************************************************************************

********************************************************************************/
template <class T, class C>  
class HashSet : public HashMap<T, DummyHashValue, C>
{
public:

typedef typename HashMap<T, DummyHashValue, C>::iterator iterator;


HashSet(const C& compFunction, ulong size, bool sync, bool useTransfer = false)
  :
  HashMap<T, DummyHashValue, C>(compFunction, size, sync, useTransfer) 
{
}


HashSet(ulong size, bool sync)
  :
  HashMap<T, DummyHashValue, C>(size, sync, false) 
{
}


virtual ~HashSet()
{
}


/*******************************************************************************

********************************************************************************/
void clear() 
{
  HashMap<T, DummyHashValue, C>::clear();
}


/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool exists(const T& item) const
{
  return HashMap<T, DummyHashValue, C>::exists(item);
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
  entry = this->hashInsert(item, this->hash(item), found);

  if (!found)
  {
    /*
    if (this->theUseTransfer)
      entry->theItem.transfer(item);
    else
    */
      entry->theItem = item;
  }

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, insert the given item to the set and return true. Otherwise, return
  false and a copy of the found item I.
********************************************************************************/
bool insert(T& item, T& outItem)
{
  bool found;

  SYNC_CODE(AutoMutex lock(this->theMutexp);)

  //assert(item != 0);

  HashEntry<T, DummyHashValue>* entry;
  entry = this->hashInsert(item, this->hash(item), found);
  if (!found)
  {
    /*
    if (this->theUseTransfer)
      entry->theItem.transfer(item);
    else
    */
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


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, insert the given item to the set and return true. Otherwise, return
  false and a copy of the found item I.
********************************************************************************/
bool insert(const T& item, T& outItem)
{
  bool found;

  SYNC_CODE(AutoMutex lock(this->theMutexp);)

  //assert(item != 0);

  HashEntry<T, DummyHashValue>* entry;
  entry = this->hashInsert(item, this->hash(item), found);
  if (!found)
  {
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
bool erase(const T& item)
{
  return HashMap<T, DummyHashValue, C>::erase(item);
}

};



} // namespace zorba

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
