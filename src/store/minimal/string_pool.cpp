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

#include "errors/fatal.h"
#include "store/minimal/string_pool.h"

namespace zorba { namespace store {

/*******************************************************************************

********************************************************************************/
StringPool::~StringPool() 
{
	ulong count = 0;
  ulong n = theHashTab.size();
  for (ulong i = 0; i < n; i++)
  {
    if (theHashTab[i].theItem != NULL &&
        theHashTab[i].theItem->getRefCount() != 1)
    {
      std::cout << "i = " << i << " String " << theHashTab[i].theItem->c_str()
                << " is still in the pool" << std::endl;
      //delete theHashTab[i].theString.getp();
      count++;
    }
  }

  ZORBA_FATAL(count == 0, count << " strings remain in the string pool");
}


/*******************************************************************************
  Check if the given string is already in the pool and if not, make a copy of it
  and place the copy in the pool. Return true if the string was already in the
  pool, and false otherwise. Also return an rchandle to the string copy.
********************************************************************************/
bool StringPool::insertc(const char* str, xqpStringStore_t& outStr)
{
  bool found = false;

  ulong len = strlen(str);
  ulong hval = xqpStringStore::hash(str) % theHashTabSize;

  {
    SYNC_CODE(AutoMutex lock(&theMutex);)

    HashEntry<xqpStringStore_t, DummyHashValue>* entry = &theHashTab[hval];

    if (!entry->isFree())
    {
      while (entry != NULL)
      {
        if (entry->theItem->byteEqual(str, len))
        {
          found = true;
          break;
        }
        entry = entry->getNext();
      }
    }

    if (found)
    {
      outStr = entry->theItem;
      return false;
    }
  }

  xqpStringStore_t tmp(new xqpStringStore(str));
  insert(tmp, outStr);

  return true;
}

/*******************************************************************************
  Check if the given string is already in the pool and if not, make a copy of it
  and place the copy in the pool. Return true if the string was already in the
  pool, and false otherwise. Also return an rchandle to the string copy.
********************************************************************************/
bool StringPool::insertc(xqpStringStore* str, xqpStringStore_t& outStr)
{
  bool found = false;

//  ulong len = strlen(str);
  ulong hval = str->hash() % theHashTabSize;

  {
    SYNC_CODE(AutoMutex lock(&theMutex);)

    HashEntry<xqpStringStore_t, DummyHashValue>* entry = &theHashTab[hval];

    if (!entry->isFree())
    {
      while (entry != NULL)
      {
        if (entry->theItem->byteEqual(*str))
        {
          found = true;
          break;
        }
        entry = entry->getNext();
      }
    }

    if (found)
    {
      outStr = entry->theItem;
      return false;
    }
  }

  xqpStringStore_t tmp(str);
  insert(tmp, outStr);

  return true;
}



/*******************************************************************************
  Look for strings that are not used by anybody outside the pool. Delete each
  such string and place its entry in the free list.
********************************************************************************/
void StringPool::garbageCollect()
{
  HashEntry<xqpStringStore_t, DummyHashValue>* entry;

  HashEntry<xqpStringStore_t, DummyHashValue>* freeList = NULL;

  ulong size = theHashTabSize;

  for (ulong i = 0; i < size; i++)
  {
    entry = &theHashTab[i];

    // If the current hash bucket is empty, move to the next one
    if (entry->theItem == NULL)
    {
      ZORBA_FATAL(entry->theNext == 0, "");
      continue;
    }

    // Handle the 1st hash entry of the current hash bucket
    while(entry->theItem->getRefCount() == 1)
    {
      if (entry->theNext == 0)
      {
        entry->theItem = NULL;
        theNumEntries--;
        break;
      }
      else
      {
        HashEntry<xqpStringStore_t, DummyHashValue>* nextEntry = entry->getNext();
        *entry = *nextEntry;
        entry->setNext(nextEntry->getNext());
        nextEntry->theItem = NULL;
        nextEntry->setNext(freeList);
        freeList = nextEntry;
        theNumEntries--;
      }
    }

    // Handle the overflow entries of the current hash bucket.
    HashEntry<xqpStringStore_t, DummyHashValue>* prevEntry = entry;
    entry = entry->getNext();

    while (entry != NULL)
    {
      if (entry->theItem->getRefCount() == 1)
      {
        prevEntry->setNext(entry->getNext());
        entry->theItem = NULL;
        entry->setNext(freeList);
        freeList = entry;
        theNumEntries--;
      }

      prevEntry = entry;
      entry = entry->getNext();
    }
  }

  if (freeList != NULL)
  {
    entry = freeList;
    while (entry->theNext != 0)
      entry = entry->getNext();

    entry->setNext(theHashTab[theHashTabSize].getNext());
    theHashTab[theHashTabSize].setNext(freeList);
  }
}

} // namespace store
} // namespace zorba
