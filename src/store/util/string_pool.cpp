
#include "util/utf8/xqpString.h"
#include "util/Assert.h"
#include "store/util/string_pool.h"

namespace xqp
{

const xqp_ulong StringPool::DEFAULT_POOL_SIZE = 1024;
const float StringPool::DEFAULT_LOAD_FACTOR = 0.6;


/*******************************************************************************

********************************************************************************/
StringPool::StringPool(xqp_ulong size) 
  :
  theNumEntries(0),
  theHashTabSize(size),
  theLoadFactor(DEFAULT_LOAD_FACTOR)
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

********************************************************************************/
StringPool::~StringPool() 
{
#ifndef NDEBUG
  xqp_ulong n = theHashTab.size();
  for (xqp_ulong i = 0; i < n; i++)
  {
    if (theHashTab[i].theString != NULL &&
        theHashTab[i].theString->getRefCount() != 1)
      Assert(0);
  }
#endif
}


/*******************************************************************************
  Check if the given string is already in the pool and if not, make a copy of it
  and place the copy in the pool. Return true if the string was already in the
  pool, and false otherwise.
********************************************************************************/
bool StringPool::insert(const char* str, xqpStringStore_t& outStr)
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given str.
  entry = &theHashTab[xqpStringStore::hash(str) % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new string.
  if (entry->theString == NULL)
  {
    theNumEntries++;
    entry->theString = outStr = new xqpStringStore(str);
    return false;
  }

  // Search the hash bucket looking for the given string.
  while (entry != NULL)
  {
    if (entry->theString->byteEqual(str, strlen(str)))
    {
      outStr = entry->theString;
      return true;
    }
    lastentry = entry;
    entry =  entry->theNext;
  }

  // The string was not found.
  theNumEntries++;

  // Double the size of hash table if it is more than 60% full. 
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    expandHashTab();

    entry = &theHashTab[xqpStringStore::hash(str) % theHashTabSize];

    if (entry->theString == NULL)
    {
      entry->theString = outStr = new xqpStringStore(str);
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

  entry->theString = outStr = new xqpStringStore(str);
  return false;
}


/*******************************************************************************
  Check if the given string is already in the pool and if not, make a copy of it
  and place the copy in the pool. Return true if the string was already in the
  pool, and false otherwise.
********************************************************************************/
bool StringPool::insert(const xqpStringStore& str)
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given str.
  entry = &theHashTab[str.hash() % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new string.
  if (entry->theString == NULL)
  {
    theNumEntries++;
    entry->theString = const_cast<xqpStringStore*>(&str);
    return false;
  }

  // Search the hash bucket looking for the given string.
  while (entry != NULL)
  {
    if (entry->theString->byteEqual(str))
      return true;

    lastentry = entry;
    entry =  entry->theNext;
  }

  // The string was not found.
  theNumEntries++;

  // Do garbag collection if the hash table if it is more than 60% full.
  if (theNumEntries > theHashTabSize * theLoadFactor)
    garbageCollect();

  // Double the size of hash table if it is more than 60% full.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    expandHashTab();

    entry = &theHashTab[str.hash() % theHashTabSize];

    if (entry->theString == NULL)
    {
      entry->theString = const_cast<xqpStringStore*>(&str);
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

  entry->theString = const_cast<xqpStringStore*>(&str);
  return false;
}


/*******************************************************************************
  Return true if the given string is already in the pool; otherwise return false.
********************************************************************************/
bool StringPool::find(const xqp_string& str)
{
  HashEntry* entry;

  entry = &theHashTab[str.hash() % theHashTabSize];

  if (entry->theString == NULL)
    return false;

  while (entry != NULL)
  {
    if (entry->theString->byteEqual(str.getStore()))
      return true;

    entry = entry->theNext;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
void StringPool::expandHashTab()
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Make a copy of theHashTab, and then resize it to double theHashTabSize
  std::vector<HashEntry> oldTab = theHashTab;
  xqp_ulong oldsize = oldTab.size();

  theHashTabSize <<= 1;

  theHashTab.clear();
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  lastentry = &theHashTab[theHashTabSize + 31];
  for (entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
 
  // Now rehash every entry
  for (xqp_ulong i = 0; i < oldsize; i++)
  {
    xqpStringStore_t str = oldTab[i].theString;

    entry = &theHashTab[str->hash() % theHashTabSize];

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

    entry->theString = str;
  }
}


/*******************************************************************************

********************************************************************************/
void StringPool::garbageCollect()
{
  HashEntry* entry;

  HashEntry* freeList = NULL;

  xqp_ulong size = theHashTabSize;

  for (xqp_ulong i = 0; i < size; i++)
  {
    entry = &theHashTab[i];

    // If the current hash bucket is empty, move to the next one
    if (entry->theString == NULL)
    {
      Assert(entry->theNext == NULL);
      continue;
    }

    // Handle the 1st hash entry of the current hash bucket
    while(entry->theString->getRefCount() == 1)
    {
      if (entry->theNext == NULL)
      {
        entry->theString = NULL;
        theNumEntries--;
        break;
      }
      else
      {
        HashEntry* nextEntry = entry->theNext;
        *entry = *nextEntry;
        nextEntry->theString = NULL;
        nextEntry->theNext = freeList;
        freeList = nextEntry;
        theNumEntries--;
      }
    }

    // Handle the overflow entries of the current hash bucket.
    HashEntry* prevEntry = entry;
    entry = entry->theNext;

    while (entry != NULL)
    {
      if (entry->theString->getRefCount() == 1)
      {
        prevEntry->theNext = entry->theNext;
        entry->theString = NULL;
        entry->theNext = freeList;
        freeList = entry;
        theNumEntries--;
      }

      prevEntry = entry;
      entry = entry->theNext;
    }
  }

  if (freeList != NULL)
  {
    entry = freeList;
    while (entry->theNext != NULL)
      entry = entry->theNext;

    entry->theNext = theHashTab[theHashTabSize].theNext;
    theHashTab[theHashTabSize].theNext = freeList;
  }
}

}
