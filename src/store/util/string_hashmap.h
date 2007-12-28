#ifndef XQP_STRING_HASHMAP_H
#define XQP_STRING_HASHMAP_H

#include "store/api/item.h"

namespace xqp
{
/*******************************************************************************

  theNumEntries  : The total number of (string, value) pairs stored in the pool.

  theHashTab     : The hash table. Implemented as a vector of hash entries,
                   where each hash entry contains a (xqpStringStore_t, V) pair.
                   Each entry between 0 and theHashTabSize - 1 is the head of
                   a hash bucket (i.e., a list of hash entries whose values
                   have the same hash value). 
  theHashTabSize : The number of hash buckets in theHashTab. 
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

    ~HashEntry()
    {

    }
  };

public:
  static const unsigned long DEFAULT_MAP_SIZE = 128;

protected:
  unsigned long           theNumEntries;

  std::vector<HashEntry>  theHashTab;
  unsigned long           theHashTabSize;
  float                   theLoadFactor;

public:
  StringHashMap(unsigned long size, float loadFactor);

  ~StringHashMap() { }

  bool insert(const xqp_string& str, const V& value);
  bool remove(const xqp_string& str);

  bool find(const xqp_string& str) const;
  bool get(const xqp_string& str, V& value) const;

  void clear();

protected:
  void expand();
};


/*******************************************************************************

********************************************************************************/
template <class V>
StringHashMap<V>::StringHashMap(unsigned long size, float loadFactor) 
  :
  theNumEntries(0),
  theHashTabSize(size),
  theLoadFactor(loadFactor)
{
  // Allocate the hash table. Its initial size is the given size, plus an inital
  // 32 overflow entries. Then, format the overflow area of theHashTab as a list
  // of free entries.
  theHashTab.resize(theHashTabSize + 32);

  HashEntry* lastentry = &theHashTab[theHashTabSize + 31];
  for (HashEntry* entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
}


/*******************************************************************************
  Check if the given string is already in the map. If so, update its associated
  value with the new given value and return true. If not make a copy of the
  string and the value and place the new pair in the map. Then, return false.
********************************************************************************/
template <class V>
bool StringHashMap<V>::insert(const xqp_string& str, const V& value)
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given uri
  entry = &theHashTab[str.hash() % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new uri.
  if (entry->theString == NULL)
  {
    theNumEntries++;
    entry->theString = str.getStore();
    entry->theValue = value;
    return false;
  }

  // Search the hash bucket looking for the given uri.
  while (entry != NULL)
  {
    if (entry->theString->byteEqual(*str.getStore()))
    {
      entry->theValue = value;
      return true;
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

    entry = &theHashTab[str.hash() % theHashTabSize];

    if (entry->theString == NULL)
    {
      entry->theString = str.getStore();
      entry->theValue = value;
      return false;
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

  entry->theString = str.getStore();
  entry->theValue = value;
  return false;
}


/*******************************************************************************

********************************************************************************/
template <class V>
bool StringHashMap<V>::remove(const xqp_string& str)
{
  HashEntry* entry;
  HashEntry* prevEntry;

  entry = &theHashTab[str.hash() % theHashTabSize];

  if (entry->theString == NULL)
    return false;

  if (entry->theString->byteEqual(*str.getStore()))
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
    if (entry->theString->byteEqual(*str.getStore()))
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
  Return true if the given string is already in the pool; otherwise return false.
********************************************************************************/
template <class V>
bool StringHashMap<V>::find(const xqp_string& str) const
{
  const HashEntry* entry;

  entry = &theHashTab[str.hash() % theHashTabSize];

  if (entry->theString == NULL)
    return false;

  while (entry != NULL)
  {
    if (entry->theString->byteEqual(*str.getStore()))
      return true;

    entry = entry->theNext;
  }

  return false;
}


/*******************************************************************************
  If the given string is already in the pool, return true and the value
   associated with the string; otherwise return false.
********************************************************************************/
template <class V>
bool StringHashMap<V>::get(const xqp_string& str, V& value) const
{
  const HashEntry* entry;

  entry = &theHashTab[str.hash() % theHashTabSize];

  if (entry->theString == NULL)
    return false;

  while (entry != NULL)
  {
    if (entry->theString->byteEqual(*str.getStore()))
    {
      value = entry->theValue;
      return true;
    }

    entry = entry->theNext;
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
  unsigned long oldsize = oldTab.size();

  theHashTabSize <<= 1;

  theHashTab.clear();
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  lastentry = &theHashTab[theHashTabSize + 31];
  for (entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
 
  // Now rehash every entry
  for (unsigned long i = 0; i < oldsize; i++)
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


/*******************************************************************************

********************************************************************************/
template <class V>
void StringHashMap<V>::clear()
{
  HashEntry* entry;

  unsigned long n = theHashTab.size();

  for (unsigned long i = 0; i < n; i++)
  {
    entry = &theHashTab[i];

    if (entry->theString != NULL)
    {
      entry->theString = NULL;
      entry->theValue.~V();
    }
  }
}

}
#endif
