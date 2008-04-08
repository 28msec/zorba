#ifndef ZORBA_STORE_UTIL_HANDLE_HASHSET
#define ZORBA_STORE_UTIL_HANDLE_HASHSET

#include <vector>

#include "common/shared_types.h"

#include "store/util/mutex.h"


namespace zorba { namespace store {

class CompareParam
{};

class StringCompareParam
{};

template <class T, class E, class C>
class Externals
{
public:
  static bool equal(const T* t1, const T* t2, C* aCompareParam)
  {
    return E::equal(t1, t2);
  }
  static uint32_t hash(const T* t1, C* aCompareParam)
  {
    return E::hash(t1);
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
template <class T, class E, class C = CompareParam>
class HandleSet
{
protected:

  class HashEntry
  {
  public:
    rchandle<T>   theItem;
    HashEntry   * theNext;

    HashEntry() : theItem(NULL), theNext(NULL) { }

    ~HashEntry() { theItem = NULL; }
  };

public:
  static const double DEFAULT_LOAD_FACTOR;

protected:
  ulong                   theNumEntries;

  std::vector<HashEntry>  theHashTab;
  ulong                   theHashTabSize;
  ulong                   theInitialSize;
  double                  theLoadFactor;
  C*                      theCompareParam;

  SYNC_CODE(Mutex         theMutex;)


public:

/*******************************************************************************
  Constructor: Allocates the hash table. Its initial size is the given size,
  plus an initial 32 free entries. These free entries are placed in a free list.
********************************************************************************/
HandleSet(ulong size) 
  :
  theNumEntries(0),
  theHashTabSize(size),
  theInitialSize(size),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareParam(0)
{
  theHashTab.resize(theHashTabSize + 32);

  HashEntry* lastentry = &theHashTab[theHashTabSize + 31];
  for (HashEntry* entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
}

HandleSet(C* aCompareParam, ulong size) 
  :
  theNumEntries(0),
  theHashTabSize(size),
  theInitialSize(size),
  theLoadFactor(DEFAULT_LOAD_FACTOR),
  theCompareParam(aCompareParam)
{
  theHashTab.resize(theHashTabSize + 32);

  HashEntry* lastentry = &theHashTab[theHashTabSize + 31];
  for (HashEntry* entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
}


/*******************************************************************************

********************************************************************************/
virtual ~HandleSet()
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

  theHashTab.clear();
  theNumEntries = 0;
  resizeHashTab (theHashTabSize);
}


/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool find(const T* item)
{
  SYNC_CODE(AutoMutex lock(theMutex);)

  HashEntry* entry = &theHashTab[Externals<T,E,C>::hash(item, theCompareParam) % theHashTabSize];

  if (entry->theItem == NULL)
    return false;

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item, theCompareParam))
      return true;

    entry = entry->theNext;
  }

  return false;
}


/******************************************************************************
  If the set does not already contain an item that is "equal" to the given item,
  insert the given item to the set and return true. Otherwise, return false.
********************************************************************************/
bool insert(T* item)
{
  bool found;

  SYNC_CODE(AutoMutex lock(theMutex);)

  HashEntry* entry = hashInsert(item, Externals<T,E,C>::hash(item, theCompareParam), found);

  if (!found)
    entry->theItem = (item);

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, insert the given item to the set and return true as well as an rchandle
  to the given item. Otherwise, return false and an rchandle to item I.
********************************************************************************/
bool insert(T* item,  rchandle<T>& outItem)
{
  bool found;

  SYNC_CODE(AutoMutex lock(theMutex);)

  HashEntry* entry = hashInsert(item, Externals<T,E,C>::hash(item, theCompareParam), found);

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
bool remove(const T* item)
{
  SYNC_CODE(AutoMutex lock(theMutex);)

  HashEntry* entry = &theHashTab[Externals<T,E,C>::hash(item) % theHashTabSize];

  if (entry->theItem == NULL)
    return false;

  HashEntry* preventry = NULL;

  while (entry != NULL)
  {
    if (Externals<T,E,C>::equal(entry->theItem, item))
    {
      theNumEntries--;

      if (preventry == NULL)
      {
        preventry = entry;
        entry = entry->theNext;
        *preventry = *entry;
      }
      else
      {
        preventry->theNext = entry->theNext;
      }

      entry->theItem = NULL;
      entry->theNext = theHashTab[theHashTabSize].theNext;
      theHashTab[theHashTabSize].theNext = entry;

      if (theHashTabSize > theInitialSize &&
          theNumEntries < (theHashTabSize /2) * theLoadFactor)
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
HashEntry* hashInsert(
    T*         item,
    ulong      hvalue,
    bool&      found)
{
  HashEntry* lastentry = NULL;

  found = false;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given item.
  HashEntry* entry = &theHashTab[hvalue % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new string.
  if (entry->theItem == NULL)
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
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    garbageCollect();

    if (lastentry->theItem == NULL)
    {
      entry = &theHashTab[hvalue % theHashTabSize];

      while (entry != NULL)
      {
        lastentry = entry;
        entry =  entry->theNext;
      }
    }
  }

  // Double the size of the hash table if it is more than 60% full.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    resizeHashTab(theHashTabSize * 2);

    entry = &theHashTab[hvalue % theHashTabSize];

    if (entry->theItem == NULL)
      return entry;

    while (entry != NULL)
    {
      lastentry = entry;
      entry =  entry->theNext;
    }
  }

  // Get an entry from the free list in the overflow section of the hash teble
  // If no free entry exists, a new entry is appended into the hash table. 
  if (theHashTab[theHashTabSize].theNext == 0)
  {
    theHashTab.push_back(HashEntry());
    entry = &theHashTab[theHashTab.size() - 1];
    lastentry->theNext = entry;
  }
  else
  {
    entry = theHashTab[theHashTabSize].theNext;
    theHashTab[theHashTabSize].theNext = entry->theNext;
    lastentry->theNext = entry;
    entry->theNext = NULL;
  }

  return entry;
}


/*******************************************************************************

********************************************************************************/
void resizeHashTab(ulong newSize)
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Make a copy of theHashTab, and then resize it to the given new size.
  std::vector<HashEntry> oldTab = theHashTab;
  ulong oldsize = oldTab.size();

  theHashTabSize = newSize;

  theHashTab.clear();
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  lastentry = &theHashTab[theHashTabSize + 31];
  for (entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
 
  // Now rehash every entry
  for (ulong i = 0; i < oldsize; i++)
  {
    T* item = oldTab[i].theItem;

    if (item == NULL)
      continue;

    entry = &theHashTab[Externals<T,E,C>::hash(item, theCompareParam) % theHashTabSize];

    if (entry->theItem != NULL)
    {
      // Go to the last entry of the current bucket
      HashEntry* lastentry = entry;
      while (lastentry->theNext != NULL)
        lastentry = lastentry->theNext;

      // Get an entry from the free list in the collision section of the hash
      // table. If no free entry exists, a new entry is appended into the table.
      if (theHashTab[theHashTabSize].theNext == 0)
      {
        theHashTab.push_back(HashEntry());
        entry = &theHashTab[theHashTab.size() - 1];
        lastentry->theNext = entry;
      }
      else
      {
        entry = theHashTab[theHashTabSize].theNext;
        theHashTab[theHashTabSize].theNext = entry->theNext;
        lastentry->theNext = entry;
        entry->theNext = NULL;
      }
    }

    entry->theItem = item;
  }
}


/*******************************************************************************

********************************************************************************/
virtual void garbageCollect() 
{ 
}


};

template <class T, class E, class C>
const double HandleSet<T, E, C>::DEFAULT_LOAD_FACTOR = 0.6;


} // namespace store
} // namespace zorba

#endif
