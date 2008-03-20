#ifndef ZORBA_STORE_POINTER_HASHMAP_H
#define ZORBA_STORE_POINTER_HASHMAP_H

#include "common/shared_types.h"
#include "zorbatypes/xqpstring.h"

#include "store/util/mutex.h"

namespace zorba { namespace store {

/*******************************************************************************

  StringHashMap implements a set of strings, each of which is associated with
  a value of type V.

  Note: Set-membership is based on the value of the string, not on string object
  identity.

  theNumEntries  : The total number of (string, value) pairs stored in the set.

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
  theLoadFactor  : The max fraction of non-empty hash buckets after which
                   the hash table is doubled in size.

********************************************************************************/
template <class T, class E,  class V>
class PointerHashMap
{
protected:

  class HashEntry
  {
  public:
    const T    * theItem;
    V            theValue;
    HashEntry  * theNext;

    HashEntry() : theItem(NULL), theNext(NULL) { }

    ~HashEntry() { }
  };

protected:
  ulong                   theNumEntries;

  std::vector<HashEntry>  theHashTab;
  ulong                   theHashTabSize;
  float                   theLoadFactor;

  SYNC_CODE(mutable Mutex theMutex;)

public:
  PointerHashMap(ulong size, float loadFactor);

  ~PointerHashMap() { }

  bool insert(const T* item, V*& value);
  bool remove(const T* item);

  bool find(const T* item) const;
  bool get(const T* item, V*& value);

  void clear();

protected:
  void expand();
};


/*******************************************************************************
  Constructor: Allocates the hash table. Its initial size is the given size,
  plus an initial 32 free entries. These free entries are placed in a free list.
********************************************************************************/
template <class T, class E,  class V>
PointerHashMap<T, E, V>::PointerHashMap(ulong size, float loadFactor) 
  :
  theNumEntries(0),
  theHashTabSize(size),
  theLoadFactor(loadFactor)
{
  theHashTab.resize(theHashTabSize + 32);

  HashEntry* lastentry = &theHashTab[theHashTabSize + 31];
  for (HashEntry* entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
}


/*******************************************************************************

********************************************************************************/
template <class T, class E, class V>
void PointerHashMap<T, E, V>::clear()
{
  HashEntry* entry;

  SYNC_CODE(AutoMutex lock(theMutex);)

  ulong n = theHashTab.size();

  for (ulong i = 0; i < n; i++)
  {
    entry = &theHashTab[i];

    if (entry->theItem != NULL)
    {
      entry->theItem = NULL;
      entry->theValue.~V();
    }
  }
}


/*******************************************************************************
  Return true if the given item is already in the set; otherwise return false.
********************************************************************************/
template <class T, class E, class V>
bool PointerHashMap<T, E, V>::find(const T* item) const
{
  const HashEntry* entry;

  SYNC_CODE(AutoMutex lock(theMutex);)

  entry = &theHashTab[E::hash(item) % theHashTabSize];

  if (entry->theItem == NULL)
    return false;

  while (entry != NULL)
  {
    if (E::equal(entry->theItem, item))
      return true;

    entry = entry->theNext;
  }

  return false;
}


/*******************************************************************************
  If the given item is already in the set, return true and a pointer to the value
  associated with the string; otherwise return false.
********************************************************************************/
template <class T, class E, class V>
bool PointerHashMap<T, E, V>::get(const T* item, V*& value)
{
  HashEntry* entry;

  SYNC_CODE(AutoMutex lock(theMutex);)

  entry = &theHashTab[E::hash(item) % theHashTabSize];

  if (entry->theItem == NULL)
    return false;

  while (entry != NULL)
  {
    if (E::equal(entry->theItem, item))
    {
      value = &entry->theValue;
      return true;
    }

    entry = entry->theNext;
  }

  return false;
}


/*******************************************************************************
  Check if the given item is already in the set. If so, return false, as well
  as a pointer to the value associated with the item. If not make a copy of the
  the value and place the new (item, value) pair in the map. Then, return true.
********************************************************************************/
template <class T, class E, class V>
bool PointerHashMap<T, E, V>::insert(const T* item, V*& value)
{
  HashEntry* entry;
  HashEntry* lastentry = NULL;

  SYNC_CODE(AutoMutex lock(theMutex);)

  // Get ptr to the 1st entry of the hash bucket corresponding to the given item
  entry = &theHashTab[E::hash(item) % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new item.
  if (entry->theItem == NULL)
  {
    theNumEntries++;
    entry->theItem = item;
    entry->theValue = *value;
    return true;
  }

  // Search the hash bucket looking for the given item.
  while (entry != NULL)
  {
    if (E::equal(entry->theItem, item))
    {
      value = &entry->theValue;
      return false;
    }

    lastentry = entry;
    entry =  entry->theNext;
  }

  // The item was not found.
  theNumEntries++;

  // Double the size of hash table if it is more than 60% full. 
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    expand();

    entry = &theHashTab[E::hash(item) % theHashTabSize];

    if (entry->theItem == NULL)
    {
      entry->theItem = item;
      entry->theValue = *value;
      return true;
    }

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

  entry->theItem = item;
  entry->theValue = *value;
  return true;
}


/*******************************************************************************

********************************************************************************/
template <class T, class E, class V>
bool PointerHashMap<T, E, V>::remove(const T* item)
{
  HashEntry* entry;
  HashEntry* prevEntry;

  SYNC_CODE(AutoMutex lock(theMutex);)

  entry = &theHashTab[E::hash(item) % theHashTabSize];

  if (entry->theItem == NULL)
    return false;

  if (E::equal(entry->theItem, item))
  {
    if (entry->theNext == NULL)
    {
      entry->theItem = NULL;
      entry->theValue.~V();
      theNumEntries--;
    }
    else
    {
      HashEntry* nextEntry = entry->theNext;
      *entry = *nextEntry;
      nextEntry->theItem = NULL;
      nextEntry->theValue.~V();
      nextEntry->theNext =  theHashTab[theHashTabSize].theNext;
      theHashTab[theHashTabSize].theNext = nextEntry;
    }

    theNumEntries--;
    return true;
  }

  prevEntry = entry;
  entry = entry->theNext;

  while (entry != NULL)
  {
    if (E::equal(entry->theItem, item))
    {
      prevEntry->theNext = entry->theNext;
      entry->theItem = NULL;
      entry->theValue.~V();
      entry->theNext = theHashTab[theHashTabSize].theNext;
      theHashTab[theHashTabSize].theNext = entry;
      theNumEntries--;
      return true;
    }

    prevEntry = entry;
    entry =  entry->theNext;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
template <class T, class E, class V>
void PointerHashMap<T, E, V>::expand()
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Make a copy of theHashTab, and then resize it to double theHashTabSize
  std::vector<HashEntry> oldTab = theHashTab;
  ulong oldsize = oldTab.size();

  theHashTabSize <<= 1;

  theHashTab.clear();
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  lastentry = &theHashTab[theHashTabSize + 31];
  for (entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
 
  // Now rehash every entry
  for (ulong i = 0; i < oldsize; i++)
  {
    entry = &theHashTab[E::hash(oldTab[i].theItem) % theHashTabSize];

    if (entry->theItem != NULL)
    {
      // Go to the last entry of the current bucket
      HashEntry* lastentry = entry;
      while (lastentry->theNext != NULL)
        lastentry = lastentry->theNext;

      // Get an entry from the free list in the overflow section of the hash
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

    *entry = oldTab[i];
  }
}


} // namespace store
} // namespace zorba
#endif
