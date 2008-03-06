#ifndef ZORBA_STORE_STRING_HASHMAP_H
#define ZORBA_STORE_STRING_HASHMAP_H

#include <zorba/common/api_shared_types.h>
#include <zorbatypes/xqpstring.h>

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
template <class V>
class StringHashMap
{
  typedef rchandle<class xqpStringStore> xqpStringStore_t;

protected:

  class HashEntry
  {
  public:
    xqpStringStore_t theString;
    V                theValue;
    HashEntry      * theNext;

    HashEntry() : theString(NULL), theNext(NULL) { }

    ~HashEntry() { }
  };

public:
  static const ulong DEFAULT_MAP_SIZE = 128;

protected:
  ulong                   theNumEntries;

  std::vector<HashEntry>  theHashTab;
  ulong                   theHashTabSize;
  float                   theLoadFactor;

  mutable Mutex           theMutex;

public:
  StringHashMap(ulong size, float loadFactor);

  ~StringHashMap() { }

  bool insert(const xqpStringStore* str, V& value);
  bool remove(const xqpStringStore* str);

  bool find(const xqpStringStore* str) const;
  bool get(const xqpStringStore* str, V& value) const;

  void clear();

protected:
  void expand();
};


/*******************************************************************************
  Constructor: Allocates the hash table. Its initial size is the given size,
  plus an initial 32 free entries. These free entries are placed in a free list.
********************************************************************************/
template <class V>
StringHashMap<V>::StringHashMap(ulong size, float loadFactor) 
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
template <class V>
void StringHashMap<V>::clear()
{
  HashEntry* entry;

  AutoMutex lock(theMutex);

  ulong n = theHashTab.size();

  for (ulong i = 0; i < n; i++)
  {
    entry = &theHashTab[i];

    if (entry->theString != NULL)
    {
      entry->theString = NULL;
      entry->theValue.~V();
    }
  }
}


/*******************************************************************************
  Return true if the given string is already in the set; otherwise return false.
********************************************************************************/
template <class V>
bool StringHashMap<V>::find(const xqpStringStore* str) const
{
  const HashEntry* entry;

  AutoMutex lock(theMutex);

  entry = &theHashTab[str->hash() % theHashTabSize];

  if (entry->theString == NULL)
    return false;

  while (entry != NULL)
  {
    if (entry->theString->byteEqual(*str))
      return true;

    entry = entry->theNext;
  }

  return false;
}


/*******************************************************************************
  If the given string is already in the set, return true and a copy of the value
  associated with the string; otherwise return false.
********************************************************************************/
template <class V>
bool StringHashMap<V>::get(const xqpStringStore* str, V& value) const
{
  const HashEntry* entry;

  AutoMutex lock(theMutex);

  entry = &theHashTab[str->hash() % theHashTabSize];

  if (entry->theString == NULL)
    return false;

  while (entry != NULL)
  {
    if (entry->theString->byteEqual(*str))
    {
      value = entry->theValue;
      return true;
    }

    entry = entry->theNext;
  }

  return false;
}


/*******************************************************************************
  Check if the given string is already in the set. If so, return false, as well
  as a copy of the value associated with the string. If not make a copy of the
  string and the value and place the new pair in the map. Then, return true.
********************************************************************************/
template <class V>
bool StringHashMap<V>::insert(const xqpStringStore* str, V& value)
{
  HashEntry* entry;
  HashEntry* lastentry = NULL;

  AutoMutex lock(theMutex);

  // Get ptr to the 1st entry of the hash bucket corresponding to the given uri
  entry = &theHashTab[str->hash() % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new uri.
  if (entry->theString == NULL)
  {
    theNumEntries++;
    entry->theString = const_cast<xqpStringStore*>(str);
    entry->theValue = value;
    return true;
  }

  // Search the hash bucket looking for the given uri.
  while (entry != NULL)
  {
    if (entry->theString->byteEqual(*str))
    {
      value = entry->theValue;
      return false;
    }

    lastentry = entry;
    entry =  entry->theNext;
  }

  // The uri was not found.
  theNumEntries++;

  // Double the size of hash table if it is more than 60% full. 
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    expand();

    entry = &theHashTab[str->hash() % theHashTabSize];

    if (entry->theString == NULL)
    {
      entry->theString = const_cast<xqpStringStore*>(str);
      entry->theValue = value;
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

  entry->theString = const_cast<xqpStringStore*>(str);
  entry->theValue = value;
  return true;
}


/*******************************************************************************

********************************************************************************/
template <class V>
bool StringHashMap<V>::remove(const xqpStringStore* str)
{
  HashEntry* entry;
  HashEntry* prevEntry;

  AutoMutex lock(theMutex);

  entry = &theHashTab[str->hash() % theHashTabSize];

  if (entry->theString == NULL)
    return false;

  if (entry->theString->byteEqual(*str))
  {
    if (entry->theNext == NULL)
    {
      entry->theString = NULL;
      entry->theValue.~V();
      theNumEntries--;
    }
    else
    {
      HashEntry* nextEntry = entry->theNext;
      *entry = *nextEntry;
      nextEntry->theString = NULL;
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
    if (entry->theString->byteEqual(*str))
    {
      prevEntry->theNext = entry->theNext;
      entry->theString = NULL;
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
template <class V>
void StringHashMap<V>::expand()
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
    entry = &theHashTab[oldTab[i].theString->hash() % theHashTabSize];

    if (entry->theString != NULL)
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
