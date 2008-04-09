#ifndef ZORBA_STORE_UTIL_HASHMAP
#define ZORBA_STORE_UTIL_HASHMAP

#include "errors/fatal.h"
#include "util/checked_vector.h"

#include "common/shared_types.h"

#include "store/util/mutex.h"


namespace zorba { namespace store {


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
  HashEntry*   theNext;

  HashEntry() : theItem(NULL), theNext(NULL) { }

  ~HashEntry() { theItem = NULL; theNext = NULL; }

  bool isFree() const { return theItem == NULL; }
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
    checked_vector<HashEntry<T, V> >*  theHashTab;
    ulong                              thePos;

  protected:
  iterator(checked_vector<HashEntry<T, V> >* ht, ulong pos) 
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
      
      HashEntry<T, V>& entry = (*theHashTab)[thePos];

      return std::pair<T, V>(entry.theItem, entry.theValue);
    }
  };


public:
  static const double DEFAULT_LOAD_FACTOR;

protected:
  ulong                             theNumEntries;

  checked_vector<HashEntry<T, V> >  theHashTab;
  ulong                             theHashTabSize;
  ulong                             theInitialSize;
  double                            theLoadFactor;
  C*                                theCompareParam;

  SYNC_CODE(Mutex                   theMutex;)


public:

/*******************************************************************************
  Constructor: Allocates the hash table. Its initial size is the given size,
  plus an initial 32 free entries. These free entries are placed in a free list.
********************************************************************************/
HashMap(ulong size) 
  :
  theNumEntries(0),
  theHashTab(size + 32),
  theHashTabSize(size),
  theInitialSize(size),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareParam(0)
{
  formatCollisionArea();
}


HashMap(C* aCompareParam, ulong size) 
  :
  theNumEntries(0),
  theHashTab(size + 32),
  theHashTabSize(size),
  theInitialSize(size),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareParam(aCompareParam)
{
  formatCollisionArea();
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
  SYNC_CODE(AutoMutex lock(theMutex);)

  theNumEntries = 0;

  ulong n = theHashTab.size();

  for (ulong i = 0; i < n; i++)
  {
    theHashTab[i].~HashEntry<T, V>();
  }

  formatCollisionArea();
}


/*******************************************************************************

********************************************************************************/
iterator begin()
{
  return iterator(&theHashTab, 0);
}


iterator end()
{
  return iterator(&theHashTab, theHashTab.size());
}


/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool find(const T& item)
{
  SYNC_CODE(AutoMutex lock(theMutex);)

  HashEntry<T, V>* entry = bucket(Externals<T,E,C>::hash(item, theCompareParam));

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
      return true;

    entry = entry->theNext;
  }

  return false;
}


/*******************************************************************************
  If the given item is already in the set, return true and a pointer to the value
  associated with the item; otherwise return false.
********************************************************************************/
bool get(const T& item, V*& value)
{
  SYNC_CODE(AutoMutex lock(this->theMutex);)

  HashEntry<T, V>* entry = bucket(Externals<T,E,C>::hash(item, theCompareParam));

  if (entry->isFree())
    return false;

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
    {
      value = &entry->theValue;
      return true;
    }

    entry = entry->theNext;
  }

  return false;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, make a copy of the given item and its associated value and place the
  new (item, value) pair in the map; then return true. Otherwise, return false,
  as well as a pointer to the value associated with the found item I.
********************************************************************************/
bool insert(T& item, V*& value)
{
  bool found;

  SYNC_CODE(AutoMutex lock(theMutex);)

  HashEntry<T, V>* entry = hashInsert(item,
                                      Externals<T,E,C>::hash(item, theCompareParam),
                                      found);

  if (!found)
  {
    entry->theItem = item;
    entry->theValue = *value;
  }
  else
  {
    value = &entry->theValue;
  }

  return !found;
}


/*******************************************************************************
  If the set contains an item that is "equal" to the given item, remove that
  item from the set and return true. Otherwise, return false.
********************************************************************************/
bool remove(const T& item)
{
  SYNC_CODE(AutoMutex lock(theMutex);)

  HashEntry<T, V>* entry = bucket(Externals<T,E,C>::hash(item, theCompareParam));

  if (entry->isFree())
    return false;

  if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
  {
    if (entry->theNext == NULL)
    {
      entry->~HashEntry<T, V>();
    }
    else
    {
      HashEntry<T, V>* nextEntry = entry->theNext;
      *entry = *nextEntry;
      nextEntry->~HashEntry<T, V>();
      nextEntry->theNext = freelist()->theNext;
      freelist()->theNext = nextEntry;
    }

    theNumEntries--;

    if (theHashTabSize > theInitialSize &&
        theNumEntries < (theHashTabSize / 2) * theLoadFactor)
    {
      resizeHashTab(theHashTabSize / 2);
    }

    return true;
  }

  HashEntry<T, V>* preventry = entry;
  entry = entry->theNext;

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
    {
      preventry->theNext = entry->theNext;
      entry->~HashEntry<T, V>();
      entry->theNext = freelist()->theNext;
      freelist()->theNext = entry;

      theNumEntries--;

      if (theHashTabSize > theInitialSize &&
          theNumEntries < (theHashTabSize / 2) * theLoadFactor)
      {
        resizeHashTab(theHashTabSize / 2);
      }

      return true;
    }

    preventry = entry;
    entry = entry->theNext;
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


HashEntry<T, V>* gotoLast(HashEntry<T, V>* entry)
{
  for (;;) 
  {
    theHashTab[entry - &theHashTab[0]];  // assertion
    HashEntry<T, V>* next = entry->theNext;
    if (next == NULL)
      return entry;
    else
      entry = next;
  }
}


/*******************************************************************************

********************************************************************************/
HashEntry<T, V>* hashInsert(
    T&         item,
    ulong      hvalue,
    bool&      found)
{
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

  // Search the hash bucket looking for the given item.
  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
    {
      found = true;
      return entry;
    }

    lastentry = entry;
    entry = entry->theNext;
  }

  // The item was not found.
  theNumEntries++;

  // Do garbage collection if the hash table is more than 60% full.
  // Note: gc does NOT resize theHashTab.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    garbageCollect();

    // If gc freed the lastentry, find the current last entry of the bucket.
    if (lastentry->theItem == NULL)
    {
      entry = bucket(hvalue);

      lastentry = gotoLast(entry);
    }
  }

  // Double the size of the hash table if it is more than 60% full.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    resizeHashTab(theHashTabSize * 2);

    entry = bucket(hvalue);

    if (entry->theItem == NULL)
      return entry;

    lastentry = gotoLast(entry);
  }

  // Get an entry from the free list in the overflow section of the hash teble
  // If no free entry exists, a new entry is appended into the hash table.
  if (freelist()->theNext == 0)
    extendCollisionArea(lastentry);

  entry = freelist()->theNext;
  freelist()->theNext = entry->theNext;
  lastentry->theNext = entry;
  entry->theNext = NULL;

  return entry;
}


/*******************************************************************************

********************************************************************************/
void extendCollisionArea(HashEntry<T, V>*& lastentry) 
{
  checked_vector<HashEntry<T, V> > newTab(theHashTab.size() + 32);

  HashEntry<T, V>* oldbase = &theHashTab[0];
  HashEntry<T, V>* newbase = &newTab[0];
  int delta = (newbase - oldbase);

  lastentry += delta;

  for (ulong i = 0; i < theHashTab.size(); i++)
  {
    HashEntry<T, V>* e = oldbase + i;
    if (!e->isFree() && e->theNext != NULL) 
    {
      newbase[i].theItem = e->theItem;
      newbase[i].theNext = e->theNext + delta;
    }
  }
  newTab.swap(theHashTab);

  formatCollisionArea();
}


/*******************************************************************************

********************************************************************************/
void formatCollisionArea() 
{
  HashEntry<T, V>* lastentry = &theHashTab[theHashTab.size() - 1];
  for (HashEntry<T, V>* entry = freelist(); entry < lastentry; entry++)
    entry->theNext = entry + 1;

  lastentry->theNext = NULL;
}


/*******************************************************************************

********************************************************************************/
void resizeHashTab(ulong newSize)
{
  HashEntry<T, V>* entry;
  HashEntry<T, V>* oldentry;

  // Make a copy of theHashTab, and then resize it to the given new size.
  checked_vector<HashEntry<T, V> > oldTab = theHashTab;
  ulong oldsize = oldTab.size();

  theHashTabSize = newSize;
  theHashTab.clear();
  theHashTab.resize(newSize + 32);
  formatCollisionArea();
 
  // Now rehash every entry
  for (ulong i = 0; i < oldsize; i++)
  {
    oldentry = &oldTab[i];

    if (oldentry->isFree())
      continue;

    oldentry->theNext = NULL;

    entry = bucket (Externals<T,E,C>::hash(oldentry->theItem, theCompareParam));

    if (!entry->isFree())
    {
      // Go to the last entry of the current bucket
      HashEntry<T, V>* lastentry = gotoLast(entry);

      // Get an entry from the free list in the collision section of the hash
      // table. If no free entry exists, a new entry is appended into the table.
      if (freelist()->theNext == 0)
        extendCollisionArea(lastentry);

      entry = freelist ()->theNext;
      freelist ()->theNext = entry->theNext;
      lastentry->theNext = entry;
    }

    *entry = *oldentry;
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


} // namespace store
} // namespace zorba

#endif
