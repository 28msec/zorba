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
#ifndef ZORBA_UTILS_HASHMAP_H
#define ZORBA_UTILS_HASHMAP_H


#include <cstddef>
#include <zorba/config.h>

#include "common/common.h"

#include "zorbautils/fatal.h"
#include "zorbautils/checked_vector.h"
#include "zorbautils/mutex.h"


namespace zorba
{

namespace serialiazation
{
  class Archiver;
}


/*******************************************************************************

********************************************************************************/
template <class T, class V>
class HashEntry
{
public:
  bool         theIsFree;
  T            theItem;
  V            theValue;
  ptrdiff_t    theNext;  // offset from "this" to the next entry.

  HashEntry() : theIsFree(true), theNext(0) { }

  ~HashEntry()
  {
    theIsFree = true;
    theNext = 0;
  }

  bool isFree() const
  {
    return theIsFree;
  }

  void setFree()
  {
    theItem.~T();
    theIsFree = true;
  }

  void unsetFree()
  {
    theIsFree = false;
  }

  void setNext(HashEntry* nextEntry)
  {
    theNext = (nextEntry == NULL ? 0 : nextEntry - this);
  }

  HashEntry* getNext()
  {
    return (theNext == 0 ? NULL : this + theNext);
  }

  const HashEntry* getNext() const
  {
    return (theNext == 0 ? NULL : this + theNext);
  }
};



/*******************************************************************************

  This template class implements a hash-based map from items of type T to items
  of type V.

  C is the template parameter that implements the hashing and equality functions.

  C must have two methods with the following signatures:
    uint32_t hash(const T&);
    bool equal(const T&, const T&);

  theNumEntries  : The total number of mappings stored in the map.

  theHashTab     : The hash table. The table is implemented as a vector of hash
                   entries and is devided in 2 areas: Each entry between 0 and
                   theHashTabSize - 1 is the head of a hash bucket. Each entry
                   between theHashTabSize+1 and theHashTab.size()-1 is either
                   a "collision" entry (i.e., it belongs to a hash bucket with
                   more than one entries) or a "free" entry (i.e. it does not
                   currently belong to any bucket, but is available for
                   allocation as a collision entry when needed). Free entries
                   in the collision area are linked in a free list. Entry
                   theHashTab[theHashTabSize] is reserved as the head of this
                   free list.
  theHashTabSize : The current number of hash buckets in theHashTab.
  theInitialSize : The initial number of hash buckets.
  theLoadFactor  : The max fraction of non-empty hash buckets after which the
                   hash table is doubled in size.

********************************************************************************/
template <class T, class V, class C>
class HashMap
{
public:

  class iterator
  {
    friend class HashMap;

  protected:
    checked_vector<HashEntry<T, V> >*  theHashTab;
    size_t                             thePos;

  protected:
    iterator(checked_vector<HashEntry<T, V> >* ht, size_t pos)
      :
      theHashTab(ht),
      thePos(pos)
    {
      while (thePos < theHashTab->size() &&
             (*theHashTab)[thePos].isFree())
        thePos++;
    }

    T& getKeyNonConst() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<T, V>& entry = (*theHashTab)[thePos];

      return entry.theItem;
    }

  public:
    iterator() : theHashTab(NULL), thePos(-1) {}

    iterator& operator = (const iterator& it)
    {
      if(&it != this)
      {
        theHashTab = it.theHashTab;
        thePos = it.thePos;
      }
      return *this;
    }

    bool operator==(const iterator& other) const
    {
      return theHashTab == other.theHashTab && thePos == other.thePos;
    }

    bool operator!=(const iterator& it) const
    {
      return theHashTab != it.theHashTab || thePos != it.thePos;
    }

    iterator& operator++()
    {
      if (thePos < theHashTab->size())
      {
        thePos++;
        while (thePos < theHashTab->size() &&
               (*theHashTab)[thePos].isFree())
          thePos++;
      }
      return *this;
    }

    std::pair<T, V> operator*() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      const HashEntry<T, V>& entry = (*theHashTab)[thePos];

      return std::pair<T, V>(entry.theItem, entry.theValue);
    }

    const T& getKey() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      const HashEntry<T, V>& entry = (*theHashTab)[thePos];

      return entry.theItem;
    }

    V& getValue() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<T, V>& entry = (*theHashTab)[thePos];

      return entry.theValue;
    }

    void setValue(const V& val)
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<T, V>& entry = (*theHashTab)[thePos];

      entry.theValue = val;
    }
  };


public:
  static const double DEFAULT_LOAD_FACTOR;

protected:
  ulong                             theNumEntries;

  size_t                            theHashTabSize;
  size_t                            theInitialSize;
  checked_vector<HashEntry<T, V> >  theHashTab;
  double                            theLoadFactor;
  C                                 theCompareFunction;

  bool                              theUseTransfer;

  SYNC_CODE(mutable Mutex           theMutex;)
  SYNC_CODE(Mutex                 * theMutexp;)

  int                               numCollisions;

public:

/***************************************************************************//**
  Constructor: Allocates the hash table. Its initial size is the given size,
  plus an initial number of free entries (= 32 + 10% of the given size). These
  free entries are placed in a free list.

  This constructor takes as input a comparison-function obj. This is needed
  when the C::hash() and C::equal() methods are not static, i.e., their operation
  depends on some parametrs (e.g. the collation or timezone). These parameters
  are provided as data members of the given comparison-function obj.
********************************************************************************/
HashMap(const C& compFunction, size_t size, bool sync, bool useTransfer = false)
  :
  theNumEntries(0),
  theHashTabSize(size),
  theInitialSize(size),
  theHashTab(computeTabSize(size)),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareFunction(compFunction),
  theUseTransfer(useTransfer),
  numCollisions(0)
{
  formatCollisionArea();

  SYNC_CODE(theMutexp = (sync ? &theMutex : NULL);)
}


/***************************************************************************//**
  Constructor: Allocates the hash table. Its initial size is the given size,
  plus an initial number of free entries (= 32 + 10% of the given size). These
  free entries are placed in a free list.

  This constructor does not take a comparison-function obj as input. It should
  be used when the C::hash() and C::equal() methods are static. In this case,
  theCompareFunction data member is initialized with the default constructor
  of the C class.
********************************************************************************/
HashMap(size_t size, bool sync, bool useTransfer = false)
  :
  theNumEntries(0),
  theHashTabSize(size),
  theInitialSize(size),
  theHashTab(computeTabSize(size)),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theUseTransfer(useTransfer),
  numCollisions(0)
{
  formatCollisionArea();

  SYNC_CODE(theMutexp = (sync ? &theMutex : NULL);)
}


/*******************************************************************************

********************************************************************************/
virtual ~HashMap()
{
}


/*******************************************************************************

********************************************************************************/
SYNC_CODE(                 \
Mutex* get_mutex() const   \
{                          \
  return theMutexp;        \
}                          \
)


/*******************************************************************************

********************************************************************************/
void set_load_factor(double v)
{
  theLoadFactor = v;
}


/*******************************************************************************

********************************************************************************/
bool empty() const
{
  return (theNumEntries == 0);
}


/*******************************************************************************

********************************************************************************/
ulong size() const
{
  return theNumEntries;
}


/*******************************************************************************

********************************************************************************/
size_t capacity() const
{
  return theHashTab.size();
}


/*******************************************************************************

********************************************************************************/
C get_compare_function()
{
  return theCompareFunction;
}


bool get_sync() const
{
  bool sync = false;
  SYNC_CODE(sync = (theMutexp == &theMutex));
  return sync;
}

/*******************************************************************************

********************************************************************************/
void clear()
{
  SYNC_CODE(AutoMutex lock(theMutexp);)

  clearNoSync();  
}


/*******************************************************************************

********************************************************************************/
void clearNoSync()
{
  theNumEntries = 0;
  numCollisions = 0;

  size_t n = theHashTab.size();

  for (size_t i = 0; i < n; ++i)
  {
    theHashTab[i].~HashEntry<T, V>();
  }

  formatCollisionArea();
}


/*******************************************************************************

********************************************************************************/
iterator begin() const
{
  return iterator(const_cast<checked_vector<HashEntry<T, V> >*>(&theHashTab), 0);
}


iterator end() const
{
  return iterator(const_cast<checked_vector<HashEntry<T, V> >*>(&theHashTab),
                  theHashTab.size());
}


/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool exists(const T& item) const
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  if (empty())
    return false;

  const HashEntry<T, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (equal(entry->theItem, item))
      return true;

    entry = entry->getNext();
  }

  return false;
}



/*******************************************************************************
  If the given item is already in the set, return an iterator positioned at the
  associated hash entry; otherwise return the end iterator.
********************************************************************************/
iterator find(const T& item)
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  if (empty())
    return end();

  const HashEntry<T, V>* entry = bucket(hval);

  if (entry->isFree())
    return end();

  while (entry != NULL)
  {
    if (equal(entry->theItem, item))
      return iterator(&theHashTab, entry - &theHashTab[0]);

    entry = entry->getNext();
  }

  return end();
}


/*******************************************************************************
  If the given item is already in the set, return true and a copy of the value
  associated with the item; otherwise return false.
********************************************************************************/
bool get(const T& item, V& value) const
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  if (empty())
    return false;

  const HashEntry<T, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (equal(entry->theItem, item))
    {
      value = entry->theValue;
      return true;
    }

    entry = entry->getNext();
  }

  return false;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, make a copy of the given item and its associated value and place the
  new (item, value) pair in the map; then return true. Otherwise, return false.
********************************************************************************/
bool insert(const std::pair<const T, V>& pair)
{
  bool found;
  ulong hval = hash(pair.first);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<T, V>* entry = hashInsert(pair.first, hval, found);

  if (!found)
  {
    entry->theItem = pair.first;
    entry->theValue = pair.second;
  }

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, make a copy of the given item and its associated value and place the
  new (item, value) pair in the map; then return true. Otherwise, return false,
  as well as a copy of the value associated with the found item I.
********************************************************************************/
bool insert(const T& item, V& value)
{
  bool found;
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<T, V>* entry = hashInsert(item, hval, found);

  if (!found)
  {
    entry->theItem = item;
    entry->theValue = value;
  }
  else
  {
    value = entry->theValue;
  }

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, return false. Otherwise, set the value associated with I to the given
  value and return true,
********************************************************************************/
bool update(const T& item, const V& value)
{
  bool found = false;
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<T, V>* headEntry = bucket(hval);
  HashEntry<T, V>* entry;

  if (! headEntry->isFree())
  {
    // Search the hash bucket looking for the given item.
    entry = headEntry;

    while (entry != NULL)
    {
      if (equal(entry->theItem, item))
      {
        found = true;
        break;
      }

      entry = entry->getNext();
    }
  }

  if (!found)
  {
    return false;
  }
  else
  {
    entry->theValue = value;
    return true;
  }
}


/*******************************************************************************
  Remove the item that is pointed to by the given iterator and move the iterator
  to the next item.
********************************************************************************/
void erase(iterator& ite)
{
  SYNC_CODE(AutoMutex lock(theMutexp);)

  if (ite.thePos < theHashTabSize)
  {
    eraseEntry(&theHashTab[ite.thePos], NULL);
  }
  else
  {
    const T& item = theHashTab[ite.thePos].theItem;

    ulong hval = hash(item);

    eraseNoSync(item, hval);
  }

  ++ite;
}


/*******************************************************************************
  If the set contains an item that is "equal" to the given item, remove that
  item from the set and return true. Otherwise, return false.
********************************************************************************/
bool erase(const T& item)
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  return eraseNoSync(item, hval);
}


bool eraseNoSync(const T& item)
{
  ulong hval = hash(item);

  return eraseNoSync(item, hval);
}


bool eraseNoSync(const T& item, ulong hval)
{
  HashEntry<T, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  // If the item to remove is in the 1st entry of a bucket, then if the
  // bucket has no other entries, just call the destructor on that entry,
  // else copy the 2nd entry to the 1st entry and freeup the 2nd entry.
  if (equal(entry->theItem, item))
  {
    eraseEntry(entry, NULL);
    return true;
  }

  // The item to remove is not in the 1st entry of a bucket.

  HashEntry<T, V>* preventry = entry;
  entry = entry->getNext();

  while (entry != NULL)
  {
    if (equal(entry->theItem, item))
    {
      eraseEntry(entry, preventry);
      return true;
    }

    preventry = entry;
    entry = entry->getNext();
  }

  return false;
}


protected:


/*******************************************************************************

********************************************************************************/
size_t computeTabSize(size_t size) const
{
  return size + 32 + size/5;
}


/*******************************************************************************

********************************************************************************/
ulong hash(const T& item) const
{
  return theCompareFunction.hash(item);
}


bool equal(const T& item1, const T& item2) const
{
  return theCompareFunction.equal(item1, item2);
}


/*******************************************************************************

********************************************************************************/
HashEntry<T, V>* bucket(ulong hvalue)
{
  return &theHashTab[hvalue % theHashTabSize];
}


/*******************************************************************************

********************************************************************************/
const HashEntry<T, V>* bucket(ulong hvalue) const
{
  return &theHashTab[hvalue % theHashTabSize];
}


/*******************************************************************************

********************************************************************************/
HashEntry<T, V>* freelist()
{
  return &theHashTab[theHashTabSize];
}


/*******************************************************************************

********************************************************************************/
void eraseEntry(HashEntry<T, V>* entry, HashEntry<T, V>* preventry)
{
  if (preventry == NULL)
  {
    if (entry->theNext == 0)
    {
      entry->~HashEntry<T, V>();
    }
    else
    {
      HashEntry<T, V>* nextEntry = entry->getNext();
      *entry = *nextEntry;
      entry->setNext(nextEntry->getNext());
      nextEntry->~HashEntry<T, V>();
      nextEntry->setNext(freelist()->getNext());
      freelist()->setNext(nextEntry);
    }

    theNumEntries--;

    if (theHashTabSize > theInitialSize &&
        theNumEntries < (theHashTabSize / 2) * theLoadFactor)
    {
      resizeHashTab(theHashTabSize / 2);
    }

  }
  else
  {
    preventry->setNext(entry->getNext());
    entry->~HashEntry<T, V>();
    entry->setNext(freelist()->getNext());
    freelist()->setNext(entry);

    theNumEntries--;
    numCollisions--;

    if (theHashTabSize > theInitialSize &&
        theNumEntries < (theHashTabSize / 2) * theLoadFactor)
    {
      resizeHashTab(theHashTabSize / 2);
    }
  }
}


/*******************************************************************************

********************************************************************************/
HashEntry<T, V>* hashInsert(
    const T&   item,
    ulong      hvalue,
    bool&      found)
{
retry:
  found = false;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given item.
  HashEntry<T, V>* headEntry = bucket(hvalue);

  // If the hash bucket is empty, its 1st entry is used to store the new string.
  if (headEntry->isFree())
  {
    theNumEntries++;
    headEntry->unsetFree();
    return headEntry;
  }

  // Search the hash bucket looking for the given item.
  HashEntry<T, V>* currEntry = headEntry;

  while (currEntry != NULL)
  {
    if (equal(currEntry->theItem, item))
    {
      found = true;
      return currEntry;
    }

    currEntry = currEntry->getNext();
  }

  // The item was not found.

  // Do garbage collection if the hash table is more than 60% full. Note that
  // gc does NOT resize theHashTab, so after gc, the item still belongs to the
  // same bucket as before gc.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    garbageCollect();

    if (headEntry->isFree())
    {
      theNumEntries++;
      headEntry->unsetFree();
      return headEntry;
    }
  }

  // Double the size of the hash table if it is more than 60% full.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    resizeHashTab(theHashTabSize * 2);
    goto retry;
  }

  // We are having a collision, and are going to place the new item in the
  // collision list for its bucket. We place the new item right after the
  // headEntry for the bucket.

  theNumEntries++;
  numCollisions++;

  // If no free entry exists, we extend the collision area of the hash table.
  if (freelist()->getNext() == 0)
  {
    ptrdiff_t offset = headEntry - &theHashTab[0];
    extendCollisionArea();
    headEntry = &theHashTab[0] + offset;
  }

  currEntry = freelist()->getNext();
  freelist()->setNext(currEntry->getNext());
  currEntry->setNext(headEntry->getNext());
  headEntry->setNext(currEntry);

  currEntry->unsetFree();

  return currEntry;
}


/*******************************************************************************

********************************************************************************/
void extendCollisionArea()
{
  size_t oldSize = theHashTab.size();
  size_t numCollisionEntries = oldSize - theHashTabSize;
  size_t newSize = theHashTabSize + 2 * numCollisionEntries;

  //foo();  for setting a breakpoint

  theHashTab.resize(newSize);

  freelist()->setNext(&theHashTab[oldSize]);

  formatCollisionArea(freelist()->getNext());
}


/*******************************************************************************

********************************************************************************/
void formatCollisionArea(HashEntry<T, V>* firstentry = NULL)
{
  if (firstentry == NULL)
    firstentry = freelist();

  HashEntry<T, V>* lastentry = &theHashTab[theHashTab.size() - 1];
  for (HashEntry<T, V>* entry = firstentry; entry < lastentry; entry++)
    entry->theNext = 1;

  lastentry->theNext = 0;
}


/*******************************************************************************

********************************************************************************/
void resizeHashTab(size_t newSize)
{
  HashEntry<T, V>* entry;
  HashEntry<T, V>* oldentry;

  // Create a new vector of new size and swap theHashTab with this new vector
  checked_vector<HashEntry<T, V> > oldTab(computeTabSize(newSize));
  theHashTab.swap(oldTab);

  size_t oldsize = oldTab.size();
  theHashTabSize = newSize;

  formatCollisionArea();

  numCollisions = 0;

  // Now rehash every entry
  for (size_t i = 0; i < oldsize; i++)
  {
    oldentry = &oldTab[i];

    if (oldentry->isFree())
      continue;

    entry = bucket (hash(oldentry->theItem));

    if (!entry->isFree())
    {
      HashEntry<T, V>* headEntry = entry;

      // Get an entry from the free list in the collision section of the hash
      // table. If no free entry exists, extend the collision area.
      if (freelist()->getNext() == NULL)
      {
        ptrdiff_t offset = headEntry - &theHashTab[0];
        extendCollisionArea();
        headEntry = &theHashTab[0] + offset;
      }

      entry = freelist()->getNext();
      freelist()->setNext(entry->getNext());
      entry->setNext(headEntry->getNext());
      headEntry->setNext(entry);
      numCollisions++;
    }

    entry->theItem = oldentry->theItem;
    entry->theValue = oldentry->theValue;
    entry->unsetFree();
  }
}


/*******************************************************************************

********************************************************************************/
virtual void garbageCollect()
{
}


};

template <class T, class V, class C>
const double HashMap<T, V, C>::DEFAULT_LOAD_FACTOR = 0.7;

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
