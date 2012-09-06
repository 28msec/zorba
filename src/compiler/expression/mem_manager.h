/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#pragma once
#ifndef ZORBA_COMPILER_MEMMANAGER_H
#define ZORBA_COMPILER_MEMMANAGER_H

#include <cassert>
#include <stdlib.h>
#include <vector>

namespace zorba
{


/******************************************************************************
                                 Memory Manager                               
*******************************************************************************/
class MemoryManager
{
private:
  static const size_t  thePageSize = 16384;

  std::vector<char*>   thePages;

  char               * thePageStart;
  char               * thePageEnd;
  size_t               theFreeSize;

public:
  MemoryManager();

  ~MemoryManager();

  void* allocate(size_t size)
  {
    assert(size > 0 && size <= thePageSize);

    if (theFreeSize < size)
    {
      thePageStart = new char[thePageSize];

      if (thePageStart == NULL)
        throw std::bad_alloc();

      thePageEnd = thePageStart + thePageSize;
      theFreeSize = thePageSize;
      thePages.push_back(thePageStart);
    }

    void* allocation = (void*)(thePageEnd - theFreeSize);
    theFreeSize -= size;

    return allocation;
  }

private:
  // A memory manager is the only existing object handling memory
  // Since it's all data that it contains, there is no sense in copying it.
  MemoryManager(const MemoryManager&);
  MemoryManager& operator=(const MemoryManager&);
};

} // namespace zorba



/*******************************************************************************
  This handles the creation of data within the memory pool using the format
  new (MemPool) constructor

  For more information see
  http://www.parashift.com/c++-faq-lite/dtors.html#faq-11.14
********************************************************************************/
inline void* operator new(size_t size, zorba::MemoryManager& mem)
{
  return mem.allocate(size);
}


inline void operator delete(void* p, zorba::MemoryManager& mem)
{
  // Memory is freed when MemoryManager is destroyed 
}

#endif /*ZORBA_COMPILER_MEMMANAGER_H*/
