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
#ifndef ZORBA_STORE_UTIL_HASHMAP
#define ZORBA_STORE_UTIL_HASHMAP

#include "zorbamisc/config/platform.h"
#include "zorbautils/fatal.h"
#include "zorbautils/checked_vector.h"
#include "zorbautils/mutex.h"


namespace zorba { 


class DummyCompareParam
{
};


/*******************************************************************************

********************************************************************************/
template <class T, class E, class C>
class Externals
{
public:
  static bool equal(const T& t1, const T& t2, C* aCompareParam)
  {
    return E::equal(t1, t2);
  }

  static uint32_t hash(const T& t1, C* aCompareParam)
  {
    return E::hash(t1);
  }
};


/*******************************************************************************

********************************************************************************/
template <class T, class V>
class HashEntry
{
public:
  T            theItem;
  V            theValue;
  long         theNext;  // offset from "this" to the next entry.

  HashEntry() : theItem(NULL), theNext(0) { }

  ~HashEntry() 
  { 
    theItem = NULL; 
    theNext = 0;
  }

  bool isFree() const  { return theItem == NULL; }

  void setNext(HashEntry* nextEntry) 
  {
    theNext = (nextEntry == NULL ? 0 : nextEntry - this); 
  }

  HashEntry* getNext()       
  {
    return (theNext == 0 ? NULL : this + theNext);
  }
};



/*******************************************************************************

  This template class implements a set container for rchandles. 

  theNumEntries  : The total number of items stored in the set.

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
template <class T, class V, class E, class C = DummyCompareParam>
class HashMap
{
public:

  class iterator
  {
    friend class HashMap;

  protected:
    const checked_vector<HashEntry<T, V> >*  theHashTab;
    ulong                                    thePos;

  protected:
    iterator(const checked_vector<HashEntry<T, V> >* ht, ulong pos) 
      :
      theHashTab(ht),
      thePos(pos)
    {
      while (thePos < theHashTab->size() &&
             (*theHashTab)[thePos].theItem == NULL)
        thePos++;
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
               (*theHashTab)[thePos].theItem == NULL)
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
  };


public:
  static const double DEFAULT_LOAD_FACTOR;

protected:
  ulong                             theNumEntries;

  ulong                             theHashTabSize;
  ulong                             theInitialSize;
  checked_vector<HashEntry<T, V> >  theHashTab;
  double                            theLoadFactor;
  C*                                theCompareParam;

  bool                              theUseTransfer;

  SYNC_CODE(Mutex                   theMutex;)
  SYNC_CODE(Mutex                 * theMutexp;)

  int                               numCollisions;

protected:

ulong computeTabSize(ulong size)
{
  return size + 32 + size/5; //theInitialSize / 10;
}


public:

/*******************************************************************************
  Constructor: Allocates the hash table. Its initial size is the given size,
  plus an initial number of free entries (= 32 + 10% of the given size). These
  free entries are placed in a free list.
********************************************************************************/
HashMap(ulong size, bool sync, bool useTransfer = false) 
  :
  theNumEntries(0),
  theHashTabSize(size),
  theInitialSize(size),
  theHashTab(computeTabSize(size)),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareParam(0),
  theUseTransfer(useTransfer),
  numCollisions(0)
{
  formatCollisionArea();

  SYNC_CODE(theMutexp = (sync ? &theMutex : NULL);)
}


 HashMap(C* aCompareParam, ulong size, bool sync, bool useTransfer = false) 
  :
  theNumEntries(0),
  theHashTabSize(size),
  theInitialSize(size),
  theHashTab(computeTabSize(size)),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareParam(aCompareParam),
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
  if (theCompareParam != 0)
  {
    delete theCompareParam;
    theCompareParam = 0;
  }
}


/*******************************************************************************

********************************************************************************/
void clear() 
{
  SYNC_CODE(AutoMutex lock(theMutexp);)

  theNumEntries = 0;
  numCollisions = 0;

  ulong n = theHashTab.size();

  for (ulong i = 0; i < n; i++)
  {
    theHashTab[i].~HashEntry<T, V>();
  }

  formatCollisionArea();
}


/*******************************************************************************

********************************************************************************/
iterator begin() const
{
  return iterator(&theHashTab, 0);
}


iterator end() const
{
  return iterator(&theHashTab, theHashTab.size());
}


/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool find(const T& item)
{
  ulong hval = Externals<T,E,C>::hash(item, theCompareParam);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<T, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
      return true;

    entry = entry->getNext();
  }

  return false;
}


/*******************************************************************************
  If the given item is already in the set, return true and a copy of the value
  associated with the item; otherwise return false.
********************************************************************************/
bool get(const T& item, V& value)
{
  ulong hval = Externals<T,E,C>::hash(item, theCompareParam);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  HashEntry<T, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
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
  new (item, value) pair in the map; then return true. Otherwise, return false,
  as well as a copy of the value associated with the found item I.
********************************************************************************/
bool insert(T& item, V& value)
{
  bool found;
  ulong hval = Externals<T,E,C>::hash(item, theCompareParam);

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


/*******************************************************************************
  If the set contains an item that is "equal" to the given item, remove that
  item from the set and return true. Otherwise, return false.
********************************************************************************/
bool remove(const T& item)
{
  ulong hval = Externals<T,E,C>::hash(item, theCompareParam);

  SYNC_CODE(AutoMutex lock(theMutexp);)

  return removeNoSync(item, hval);
}


bool removeNoSync(const T& item, ulong hval)
{
  HashEntry<T, V>* entry = bucket(hval);

  if (entry->isFree())
    return false;

  // If the item to remove is in the 1st entry of a bucket, then if the
  // bucket has no other entries, just call the destructor on that entry,
  // else copy the 2nd entry to the 1st entry and freeup the 2nd entry.
  if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
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

    return true;
  }

  // The item to remove is not in the 1st entry of a bucket.

  HashEntry<T, V>* preventry = entry;
  entry = entry->getNext();

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
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
HashEntry<T, V>* freelist()
{
  return &theHashTab[theHashTabSize];
}


HashEntry<T, V>* bucket(ulong hvalue)
{
  return &theHashTab[hvalue % theHashTabSize];
}

/*
HashEntry<T, V>* gotoLast(HashEntry<T, V>* entry)
{
  for (;;) 
  {
    theHashTab[entry - &theHashTab[0]];  // assertion
    HashEntry<T, V>* next = entry->getNext();
    if (next == NULL)
      return entry;
    else
      entry = next;
  }
}
*/

/*******************************************************************************

********************************************************************************/
HashEntry<T, V>* hashInsert(
    T&         item,
    ulong      hvalue,
    bool&      found)
{
doHashInsert:
  HashEntry<T, V>* lastentry = NULL;

  found = false;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given item.
  HashEntry<T, V>* entry = bucket(hvalue);

  // If the hash bucket is empty, its 1st entry is used to store the new string.
  if (entry->isFree())
  {
    theNumEntries++;
    return entry;
  }

//debug
//  int   nr_colisions = 0;
//end debug

  // Search the hash bucket looking for the given item.
  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
    {
      found = true;
      return entry;
    }

    //nr_colisions++;
    lastentry = entry;
    entry = entry->getNext();
  }
//+debug
  //std::cout << "Entry collision " << std::hex << hvalue << " " << Externals<T,E,C>::hash(lastentry->theItem, theCompareParam) 
  //          << std::dec
  //          << " nr colisions " << nr_colisions 
  //          << " (" << numCollisions << "/" << theNumEntries << ")"
  //          << std::endl;
//end debug


  // The item was not found.
  theNumEntries++;
  numCollisions++;

  // Do garbage collection if the hash table is more than 60% full.
  // Note: gc does NOT resize theHashTab.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    garbageCollect();

    // If gc freed the lastentry, find the current last entry of the bucket.
    if (lastentry->theItem == NULL)
    {
      entry = bucket(hvalue);

      //daniel: why go to the last item?
      lastentry = entry;//gotoLast(entry);
    }
  }

  // Double the size of the hash table if it is more than 60% full.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    resizeHashTab(theHashTabSize * 2);

    theNumEntries--;
    numCollisions--;
    goto doHashInsert;//look again if the item is in the collision list
//    entry = bucket(hvalue);
//
//    if (entry->theItem == NULL)
//      return entry;
//
//    lastentry = gotoLast(entry);
  }

  // Get an entry from the free list in the overflow section of the hash teble
  // If no free entry exists, a new entry is appended into the hash table.
  if (freelist()->getNext() == 0)
  {
    long lastOffset = lastentry - &theHashTab[0];
    extendCollisionArea();
    lastentry = &theHashTab[0] + lastOffset;
  }

  entry = freelist()->getNext();
  freelist()->setNext(entry->getNext());
  entry->setNext(lastentry->getNext());
  lastentry->setNext(entry);
  //entry->setNext(NULL);

  return entry;
}


/*******************************************************************************

********************************************************************************/
void extendCollisionArea() 
{
  ulong oldSize = theHashTab.size();
  ulong numCollisionEntries = oldSize - theHashTabSize;
  ulong newSize = theHashTabSize + 2 * numCollisionEntries;

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
void resizeHashTab(ulong newSize)
{
  HashEntry<T, V>* entry;
  HashEntry<T, V>* oldentry;

  // Allocate a new vector of new size and fill it with old items
  checked_vector<HashEntry<T, V> > oldTab(computeTabSize(newSize));// = theHashTab;
  theHashTab.swap(oldTab);

  ulong oldsize = oldTab.size();
  theHashTabSize = newSize;
  //theHashTab.clear();
  //theHashTab.resize(computeTabSize(newSize));
  formatCollisionArea();
 
  numCollisions = 0;
  // Now rehash every entry
  for (ulong i = 0; i < oldsize; i++)
  {
    oldentry = &oldTab[i];

    if (oldentry->isFree())
      continue;

    oldentry->theNext = 0;

    entry = bucket (Externals<T,E,C>::hash(oldentry->theItem, theCompareParam));

    if (!entry->isFree())
    {
      // Go to the last entry of the current bucket
      //daniel: why go to last? better insert after the first entry
      HashEntry<T, V>* lastentry = entry;//gotoLast(entry);

      // Get an entry from the free list in the collision section of the hash
      // table. If no free entry exists, a new entry is appended into the table.
      if (freelist()->getNext() == NULL)
      {
        long lastOffset = lastentry - &theHashTab[0];
        extendCollisionArea();
        lastentry = &theHashTab[0] + lastOffset;
      }

      entry = freelist()->getNext();
      freelist()->setNext(entry->getNext());
      entry->setNext(lastentry->getNext());
      lastentry->setNext(entry);
      numCollisions++;
    }

    //*entry = *oldentry;
    entry->theItem = oldentry->theItem;
    entry->theValue = oldentry->theValue;
  }
}


/*******************************************************************************

********************************************************************************/
virtual void garbageCollect() 
{ 
}


};

template <class T, class E, class C, class V>
const double HashMap<T, E, C, V>::DEFAULT_LOAD_FACTOR = 0.6;



} // namespace zorba

#endif
