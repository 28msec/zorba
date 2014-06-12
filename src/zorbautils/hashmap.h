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

#include <cassert>
#include <cstddef>
#include <vector>

#include <zorba/config.h>

#include "common/common.h"

#include "zorbautils/checked_vector.h"
#include "zorbautils/fatal.h"
#include "zorbautils/mutex.h"

#include "store/api/shared_types.h"


namespace zorba
{

namespace serialiazation
{
  class Archiver;
}


/*******************************************************************************

********************************************************************************/
template <class K, class V>
class HashEntry
{
  template<typename T>
  struct mem_buf {
    char buf[ sizeof(T) ];
  };

public:
  mem_buf<K>   theKey;
  mem_buf<V>   theValue;
  ptrdiff_t    theNext;  // offset from "this" to the next entry.
  bool         theIsFree;

  HashEntry() 
    :
    theNext(0),
    theIsFree(true)
  {
  }

  HashEntry(const HashEntry<K, V>& other)
  {
    theIsFree = other.theIsFree;
    theNext = other.theNext;
    if (!theIsFree)
    {
      new (&theKey) K(other.key());
      new (&theValue) V(other.value());
    }
  }

  ~HashEntry()
  {
    if (!theIsFree)
    {
      key().~K();
      value().~V();
    }
  }

  HashEntry<K, V>& operator = (const HashEntry<K, V>& other)
  {
    if (theIsFree)
    {
      assert(false);

      if (!other.theIsFree)
      {
        new (&theKey) K(other.key());
        new (&theValue) V(other.value());
      }
    }
    else
    {
      if (!other.theIsFree)
      {
        key() = other.key();
        value() = other.value();
      }
      else
      {
        assert(false);

        key().~K();
        value().~V();
      }
    }

    theIsFree = other.theIsFree;
    theNext = other.theNext;

    return *this;
  }

  bool isFree() const
  {
    return theIsFree;
  }

  void setFree()
  {
    key().~K();
    value().~V();
    theIsFree = true;
    theNext = 0;
  }

  void unsetFree()
  {
    new (&theKey) K;
    new (&theValue) V;
    theIsFree = false;
  }

  K& key()
  {
    return *reinterpret_cast<K*>(&theKey);
  }

  const K& key() const
  {
    return *reinterpret_cast<const K*>(&theKey);
  }

  const V& value() const
  {
    return *reinterpret_cast<const V*>(&theValue);
  }

  V& value()
  {
    return *reinterpret_cast<V*>(&theValue);
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

  This template class implements a hash-based map from items of type K to items
  of type V.

  C is the template parameter that implements the hashing and equality functions.

  C must have two methods with the following signatures:
    uint32_t hash(const K&);
    bool equal(const K&, const K&);

  theNumEntries  : The total number of mappings stored in the map.

  theHashTab     : The hash table. The table is implemented as a vector of hash
                   entries and is devided in 2 areas: Each entry between 0 and
                   theNumBuckets - 1 is the head of a hash bucket. Each entry
                   between theNumBuckets+1 and theHashTab.size()-1 is either
                   a "collision" entry (i.e., it belongs to a hash bucket with
                   more than one entries) or a "free" entry (i.e. it does not
                   currently belong to any bucket, but is available for
                   allocation as a collision entry when needed). Free entries
                   in the collision area are linked in a free list. Entry
                   theHashTab[theNumBuckets] is reserved as the head of this
                   free list.
  theNumBuckets : The current number of hash buckets in theHashTab.

  theLoadFactor  : The max fraction of non-empty hash buckets after which the
                   hash table is doubled in size.

********************************************************************************/
template <class K, class V, class C>
class HashMap
{
  HashMap( HashMap const& );
  HashMap& operator=( HashMap const& );
public:
  typedef K key_type;
  typedef V value_type;
  typedef C key_equal;

  class iterator
  {
    friend class HashMap;

  protected:
    std::vector<HashEntry<K, V> >*  theHashTab;
    csize                           thePos;

  protected:
    iterator(std::vector<HashEntry<K, V> >* ht, csize pos)
      :
      theHashTab(ht),
      thePos(pos)
    {
      while (thePos < theHashTab->size() &&
             (*theHashTab)[thePos].isFree())
        thePos++;
    }

    K& getKeyNonConst() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<K, V>& entry = (*theHashTab)[thePos];

      return entry.key();
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

    std::pair<K, V> operator*() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      const HashEntry<K, V>& entry = (*theHashTab)[thePos];

      return std::pair<K, V>(entry.key(), entry.value());
    }

    const K& getKey() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      const HashEntry<K, V>& entry = (*theHashTab)[thePos];

      return entry.key();
    }

    const V& getValue() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<K, V>& entry = (*theHashTab)[thePos];

      return entry.value();
    }

    V& getValue()
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<K, V>& entry = (*theHashTab)[thePos];

      return entry.value();
    }

    void setValue(const V& val)
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<K, V>& entry = (*theHashTab)[thePos];

      entry.value() = val;
    }
  };

  class const_iterator
  {
    friend class HashMap;

  protected:
    checked_vector<HashEntry<K, V> > const* theHashTab;
    size_t                                  thePos;

  protected:
    const_iterator(checked_vector<HashEntry<K, V> > const* ht, size_t pos)
      :
      theHashTab(ht),
      thePos(pos)
    {
      while (thePos < theHashTab->size() &&
             (*theHashTab)[thePos].isFree())
        thePos++;
    }

  public:
    const_iterator() : theHashTab(NULL), thePos(-1) {}

    const_iterator& operator = (const iterator& it)
    {
      if(&it != this)
      {
        theHashTab = it.theHashTab;
        thePos = it.thePos;
      }
      return *this;
    }

    bool operator==(const const_iterator& other) const
    {
      return theHashTab == other.theHashTab && thePos == other.thePos;
    }

    bool operator!=(const const_iterator& it) const
    {
      return theHashTab != it.theHashTab || thePos != it.thePos;
    }

    const_iterator& operator++()
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

    std::pair<K, V> operator*() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      const HashEntry<K, V>& entry = (*theHashTab)[thePos];

      return std::pair<K, V>(entry.theItem, entry.theValue);
    }

    const K& getKey() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      const HashEntry<K, V>& entry = (*theHashTab)[thePos];

      return entry.theItem;
    }

    V const& getValue() const
    {
      ZORBA_FATAL(thePos < theHashTab->size(), "");

      HashEntry<K, V> const& entry = (*theHashTab)[thePos];

      return entry.theValue;
    }
  };


public:
  static const double DEFAULT_LOAD_FACTOR;

protected:
  std::vector<HashEntry<K, V> >  theHashTab;

  csize                          theNumBuckets;

  csize                          theNumEntries;

  double                         theLoadFactor;

  double                         theMaxLoad;

  C                              theCompareFunction;

  SYNC_CODE(mutable Mutex        theMutex;)
  SYNC_CODE(Mutex              * theMutexp;)

  csize                          theNumCollisions;

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
HashMap(const C& compFunction, csize size, bool sync)
  :
  theNumBuckets(size),
  theNumEntries(0),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareFunction(compFunction),
  theNumCollisions(0)
{
  theHashTab.resize(computeCapacity(size));

  formatCollisionArea();

  theMaxLoad = theNumBuckets * theLoadFactor;

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
HashMap(csize size, bool sync)
  :
  theNumBuckets(size),
  theNumEntries(0),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theNumCollisions(0)
{
  theHashTab.resize(computeCapacity(size));

  formatCollisionArea();

  theMaxLoad = theNumBuckets * theLoadFactor;

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
csize size() const
{
  return theNumEntries;
}


/*******************************************************************************

********************************************************************************/
csize capacity() const
{
  return theHashTab.size();
}


/*******************************************************************************

********************************************************************************/
csize bucket_count() const
{
  return theNumBuckets;
}


/*******************************************************************************

********************************************************************************/
csize collisions() const
{
  return theNumCollisions;
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
  theNumCollisions = 0;

  csize n = theHashTab.size();

  HashEntry<K, V>* entry = &theHashTab[0];
  HashEntry<K, V>* lastentry = &theHashTab[n-1];

  for (; entry <= lastentry; ++entry)
  {
    if (!entry->isFree())
      entry->setFree();
  }

  formatCollisionArea();
}


/*******************************************************************************

********************************************************************************/
iterator begin() const
{
  return iterator(const_cast<std::vector<HashEntry<K, V> >*>(&theHashTab), 0);
}


iterator end() const
{
  return iterator(const_cast<std::vector<HashEntry<K, V> >*>(&theHashTab),
                  theHashTab.size());
}

const_iterator cbegin() const
{
  return const_iterator(&theHashTab, 0);
}


const_iterator cend() const
{
  return const_iterator(&theHashTab, theHashTab.size());
}



/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool exists(const K& item) const
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  if (empty())
    return false;

  const HashEntry<K, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (equal(entry->key(), item))
      return true;

    entry = entry->getNext();
  }

  return false;
}



/*******************************************************************************
  If the given item is already in the set, return an iterator positioned at the
  associated hash entry; otherwise return the end iterator.
********************************************************************************/
iterator find(const K& item)
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  if (empty())
    return end();

  const HashEntry<K, V>* entry = bucket(hval);

  if (entry->isFree())
    return end();

  while (entry != NULL)
  {
    if (equal(entry->key(), item))
      return iterator(&theHashTab, entry - &theHashTab[0]);

    entry = entry->getNext();
  }

  return end();
}


/*******************************************************************************
  If the given item is already in the set, return true and a copy of the value
  associated with the item; otherwise return false.
********************************************************************************/
bool get(const K& item, V& value) const
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  if (empty())
    return false;

  const HashEntry<K, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (equal(entry->key(), item))
    {
      value = entry->value();
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
bool insert(const std::pair<const K, V>& pair)
{
  bool found;
  ulong hval = hash(pair.first);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<K, V>* entry = hashInsert(pair.first, hval, found);

  if (!found)
  {
    entry->key() = pair.first;
    entry->value() = pair.second;
  }

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, make a copy of the given item and its associated value and place the
  new (item, value) pair in the map; then return true. Otherwise, return false,
  as well as a copy of the value associated with the found item I.
********************************************************************************/
bool insert(const K& item, V& value)
{
  bool found;
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<K, V>* entry = hashInsert(item, hval, found);

  if (!found)
  {
    entry->key() = item;
    entry->value() = value;
  }
  else
  {
    value = entry->value();
  }

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, return false. Otherwise, set the value associated with I to the given
  value and return true,
********************************************************************************/
bool update(const K& item, const V& value)
{
  bool found = false;
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<K, V>* headEntry = bucket(hval);
  HashEntry<K, V>* entry;

  if (! headEntry->isFree())
  {
    // Search the hash bucket looking for the given item.
    entry = headEntry;

    while (entry != NULL)
    {
      if (equal(entry->key(), item))
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
    entry->value() = value;
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

  if (ite.thePos < theNumBuckets)
  {
    eraseEntry(&theHashTab[ite.thePos], NULL);
  }
  else
  {
    const K& item = theHashTab[ite.thePos].key();

    ulong hval = hash(item);

    eraseNoSync(item, hval);
  }

  ++ite;
}


/*******************************************************************************
  If the set contains an item that is "equal" to the given item, remove that
  item from the set and return true. Otherwise, return false.
********************************************************************************/
bool erase(const K& item)
{
  ulong hval = hash(item);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  return eraseNoSync(item, hval);
}


bool eraseNoSync(const K& item)
{
  ulong hval = hash(item);

  return eraseNoSync(item, hval);
}


bool eraseNoSync(const K& item, ulong hval)
{
  HashEntry<K, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  // If the item to remove is in the 1st entry of a bucket, then if the
  // bucket has no other entries, just call the destructor on that entry,
  // else copy the 2nd entry to the 1st entry and freeup the 2nd entry.
  if (equal(entry->key(), item))
  {
    eraseEntry(entry, NULL);
    return true;
  }

  // The item to remove is not in the 1st entry of a bucket.

  HashEntry<K, V>* preventry = entry;
  entry = entry->getNext();

  while (entry != NULL)
  {
    if (equal(entry->key(), item))
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
csize computeCapacity(csize size) const
{
  return size + 32 + static_cast<csize>(size / (5 - 10 * (theLoadFactor - 0.7)));
}


/*******************************************************************************

********************************************************************************/
ulong hash(const K& item) const
{
  return theCompareFunction.hash(item);
}


bool equal(const K& item1, const K& item2) const
{
  return theCompareFunction.equal(item1, item2);
}


/*******************************************************************************

********************************************************************************/
HashEntry<K, V>* bucket(ulong hvalue)
{
  return &theHashTab[hvalue % theNumBuckets];
}


/*******************************************************************************

********************************************************************************/
const HashEntry<K, V>* bucket(ulong hvalue) const
{
  return &theHashTab[hvalue % theNumBuckets];
}


/*******************************************************************************

********************************************************************************/
HashEntry<K, V>* freelist()
{
  return &theHashTab[theNumBuckets];
}


/*******************************************************************************

********************************************************************************/
void eraseEntry(HashEntry<K, V>* entry, HashEntry<K, V>* preventry)
{
  if (preventry == NULL)
  {
    if (entry->theNext == 0)
    {
      entry->setFree();
    }
    else
    {
      HashEntry<K, V>* nextEntry = entry->getNext();
      *entry = *nextEntry;
      entry->setNext(nextEntry->getNext());
      nextEntry->setFree();
      nextEntry->setNext(freelist()->getNext());
      freelist()->setNext(nextEntry);
    }

    --theNumEntries;

    if (theNumEntries < theMaxLoad / 2)
    {
      resizeHashTab(theNumBuckets / 2);
    }

  }
  else
  {
    preventry->setNext(entry->getNext());
    entry->setFree();
    entry->setNext(freelist()->getNext());
    freelist()->setNext(entry);

    --theNumEntries;

    if (theNumEntries < theMaxLoad / 2)
    {
      resizeHashTab(theNumBuckets / 2);
    }
  }
}


/*******************************************************************************

********************************************************************************/
HashEntry<K, V>* hashInsert(
    const K&   item,
    ulong      hvalue,
    bool&      found)
{
retry:
  found = false;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given item.
  HashEntry<K, V>* headEntry = bucket(hvalue);

  // If the hash bucket is empty, its 1st entry is used to store the new string.
  if (headEntry->isFree())
  {
    ++theNumEntries;
    headEntry->unsetFree();
    return headEntry;
  }

  // Search the hash bucket looking for the given item.
  HashEntry<K, V>* currEntry = headEntry;

  while (currEntry != NULL)
  {
    if (equal(currEntry->key(), item))
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
  if (theNumEntries > theMaxLoad)
  {
    garbageCollect();

    if (headEntry->isFree())
    {
      ++theNumEntries;
      headEntry->unsetFree();
      return headEntry;
    }
  }

  // Double the size of the hash table if it is more than 60% full.
  if (theNumEntries > theMaxLoad)
  {
    resizeHashTab(theNumBuckets * 2);
    goto retry;
  }

  // We are having a collision, and are going to place the new item in the
  // collision list for its bucket. We place the new item right after the
  // headEntry for the bucket.

  ++theNumEntries;
  ++theNumCollisions;

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
  csize oldSize = theHashTab.size();
  csize numCollisionEntries = oldSize - theNumBuckets;
  csize newSize = theNumBuckets + 2 * numCollisionEntries;

  /*
  std::cout << "Extending collision area" << std::endl
            << "numBuckets = " << theNumBuckets << " numCollisionEntries = "
            << numCollisionEntries << std::endl << std::endl;
  */
  //foo();  for setting a breakpoint

  theHashTab.resize(newSize);

  freelist()->setNext(&theHashTab[oldSize]);

  formatCollisionArea(freelist()->getNext());
}


/*******************************************************************************

********************************************************************************/
void formatCollisionArea(HashEntry<K, V>* firstentry = NULL)
{
  if (firstentry == NULL)
    firstentry = freelist();

  HashEntry<K, V>* lastentry = &theHashTab[theHashTab.size() - 1];

  for (HashEntry<K, V>* entry = firstentry; entry < lastentry; ++entry)
    entry->theNext = 1;

  lastentry->theNext = 0;
}


/*******************************************************************************

********************************************************************************/
void resizeHashTab(csize newSize)
{
  if (newSize == 0)
    newSize = 3;

  csize oldcap = theHashTab.size();
  csize newcap = computeCapacity(newSize);

  // Create a new vector of new size and swap theHashTab with this new vector
  std::vector<HashEntry<K, V> > oldTab(newcap);
  theHashTab.swap(oldTab);

  theNumBuckets = newSize;
  theMaxLoad = theNumBuckets * theLoadFactor;

  formatCollisionArea();

  HashEntry<K, V>* entry;
  HashEntry<K, V>* oldentry = &oldTab[0];
  HashEntry<K, V>* lastentry = &oldTab[oldcap-1];

  // Now rehash every entry
  for (; oldentry <= lastentry; ++oldentry)
  {
    if (oldentry->isFree())
      continue;

    entry = bucket(hash(oldentry->key()));

    if (!entry->isFree())
    {
      HashEntry<K, V>* headEntry = entry;

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
    }

    entry->unsetFree();
    entry->key() = oldentry->key();
    entry->value() = oldentry->value();
  }
}


/*******************************************************************************

********************************************************************************/
virtual void garbageCollect()
{
}


};

template <class K, class V, class C>
const double HashMap<K, V, C>::DEFAULT_LOAD_FACTOR = 0.7;

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
