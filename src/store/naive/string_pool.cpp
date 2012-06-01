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
#include "stdafx.h"

#include "util/string_util.h"
#include "string_pool.h"
#include "zorba/zorba_exception.h"
#include "diagnostics/xquery_diagnostics.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
StringPool::~StringPool() 
{
  ulong count = 0;
  ulong n = (ulong)theHashTab.size();
  for (ulong i = 0; i < n; i++)
  {
    if (theHashTab[i].theItem.is_shared())
    {
      //std::cerr << "ID: " << i << "   Referenced URI: " << theHashTab[i].theItem << std::endl;
      //delete theHashTab[i].theString.getp();
      count ++;
    }
  }
  if (count>0) {
      throw ZORBA_EXCEPTION(zerr::ZSTR0065_STRINGS_IN_POOL, ERROR_PARAMS(count));
  }
}


/*******************************************************************************
  Check if the given string is already in the pool and if not, make a copy of it
  and place the copy in the pool. Return true if the string was already in the
  pool, and false otherwise. Also return an rchandle to the string copy.
********************************************************************************/
bool StringPool::insertc(const char* str, zstring& outStr)
{
  bool found = false;

  zstring::size_type len = strlen(str);
  ulong hval = hashfun::h32(str, len, FNV_32_INIT) % theHashTabSize;

  {
    SYNC_CODE(AutoMutex lock(&theMutex);)

    HashEntry<zstring, DummyHashValue>* entry = &theHashTab[hval];

    if (!entry->isFree())
    {
      while (entry != NULL)
      {
        if (ztd::equals(entry->theItem, str, len))
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

  zstring tmp(str, len);
  insert(tmp, outStr);

  return true;
}


/*******************************************************************************
  Look for strings that are not used by anybody outside the pool. Delete each
  such string and place its entry in the free list.
********************************************************************************/
void StringPool::garbageCollect()
{
  HashEntry<zstring, DummyHashValue>* entry;

  HashEntry<zstring, DummyHashValue>* freeList = NULL;

  zstring::size_type size = theHashTabSize;

  for (ulong i = 0; i < size; ++i)
  {
    entry = &theHashTab[i];

    // If the current hash bucket is empty, move to the next one
    if (entry->isFree())
    {
      ZORBA_FATAL(entry->theNext == 0, "");
      continue;
    }

    // Handle the 1st hash entry of the current hash bucket
    while (!entry->theItem.is_shared())
    {
      if (entry->theNext == 0)
      {
        entry->setFree();
        theNumEntries--;
        break;
      }
      else
      {
        HashEntry<zstring, DummyHashValue>* nextEntry = entry->getNext();
        *entry = *nextEntry;
        entry->setNext(nextEntry->getNext());
        nextEntry->setFree();
        nextEntry->setNext(freeList);
        freeList = nextEntry;
        theNumEntries--;
      }
    }

    // Handle the overflow entries of the current hash bucket.
    HashEntry<zstring, DummyHashValue>* prevEntry = entry;
    entry = entry->getNext();

    while (entry != NULL)
    {
      if (!entry->theItem.is_shared())
      {
        prevEntry->setNext(entry->getNext());
        entry->setFree();
        entry->setNext(freeList);
        freeList = entry;
        theNumEntries--;

        entry = prevEntry->getNext();
      }
      else
      {
        prevEntry = entry;
        entry = entry->getNext();
      }
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

} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
