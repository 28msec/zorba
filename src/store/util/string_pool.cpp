
#include "util/utf8/xqpString.h"
#include "util/Assert.h"
#include "store/util/string_pool.h"

namespace xqp
{

const unsigned long StringPool::DEFAULT_POOL_SIZE = 1024;
const float StringPool::DEFAULT_LOAD_FACTOR = 0.6f;


/*******************************************************************************

********************************************************************************/
StringPool::StringPool(unsigned long size) 
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
	unsigned long count = 0;
  unsigned long n = theHashTab.size();
  for (unsigned long i = 0; i < n; i++)
  {
    if (theHashTab[i].theString != NULL &&
        theHashTab[i].theString->getRefCount() != 1)
    {
      std::cout << "i = " << i << " String " << theHashTab[i].theString->c_str()
                << " is still in the pool" << std::endl;
      //delete theHashTab[i].theString.getp();
      count++;
    }
  }

  //if (count > 0)
  //  assert(0);
}


/*******************************************************************************
  Check if the given string is already in the pool and if not, make a copy of it
  and place the copy in the pool. Return true if the string was already in the
  pool, and false otherwise. Also return an rchandle to the string copy.
********************************************************************************/
bool StringPool::insert(const char* str, xqpStringStore_t& outStr)
{
  bool found;

  HashEntry* entry = hashInsert(str, strlen(str), xqpStringStore::hash(str), found);

  if (!found)
    entry->theString = outStr = new xqpStringStore(str);
  else
    outStr = entry->theString;

  return found;
}


/*******************************************************************************
  Check if the given string is already in the pool and if not, insert it in the
  pool. Return true if the string was already in the pool, and false otherwise.
********************************************************************************/
bool StringPool::insert(const xqpStringStore* str)
{
  bool found;

  HashEntry* entry = hashInsert(str->c_str(), str->bytes(), str->hash(), found);

  if (!found)
    entry->theString = const_cast<xqpStringStore*>(str);

  return found;
}


/*******************************************************************************
  Check if the given string is already in the pool, and if so, return its hash
  entry. If not, allocate a new hash entry for it, and return it to the caller.
********************************************************************************/
StringPool::HashEntry* StringPool::hashInsert(
    const char* str,
    unsigned long strlen,
    unsigned long strhash,
    bool& found)
{
  HashEntry* lastentry = NULL;

  found = false;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given str.
  HashEntry* entry = &theHashTab[strhash % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new string.
  if (entry->theString == NULL)
  {
    theNumEntries++;
    return entry;
  }

  // Search the hash bucket looking for the given string.
  while (entry != NULL)
  {
    if (entry->theString->byteEqual(str, strlen))
    {
      found = true;
      return entry;
    }
    lastentry = entry;
    entry =  entry->theNext;
  }

  // The string was not found.
  theNumEntries++;

  // Do garbage collection if the hash table is more than 60% full.
  if (theNumEntries > theHashTabSize * theLoadFactor)
  {
    garbageCollect();

    if (lastentry->theString == NULL)
    {
      entry = &theHashTab[strhash % theHashTabSize];

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

    entry = &theHashTab[strhash % theHashTabSize];

    if (entry->theString == NULL)
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
  Return true if the given string is already in the pool; otherwise return false.
********************************************************************************/
bool StringPool::find(const xqp_string& str)
{
  HashEntry* entry = &theHashTab[str.hash() % theHashTabSize];

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

********************************************************************************/
void StringPool::resizeHashTab(unsigned long newSize)
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Make a copy of theHashTab, and then resize it to double theHashTabSize
  std::vector<HashEntry> oldTab = theHashTab;
  unsigned long oldsize = oldTab.size();

  theHashTabSize = newSize;

  theHashTab.clear();
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  lastentry = &theHashTab[theHashTabSize + 31];
  for (entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
 
  // Now rehash every entry
  for (unsigned long i = 0; i < oldsize; i++)
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
  Look for strings that are not used by anybody outside the pool. Delete each
  such string and place its entry in the free list.
********************************************************************************/
void StringPool::garbageCollect()
{
  HashEntry* entry;

  HashEntry* freeList = NULL;

  unsigned long size = theHashTabSize;

  for (unsigned long i = 0; i < size; i++)
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
