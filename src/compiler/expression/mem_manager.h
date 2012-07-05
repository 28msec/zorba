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

#include <stdlib.h>

#include <list>

namespace zorba
{

/*******************************************************************************
 *                                Memory Page                                  *
 ******************************************************************************/

/*
 * A memory page handles a piece of memory of a certain size. It will also
 * manage allocation of memory.
 */

class MemPage 
{
public:
  static const size_t DEFAULT_PAGE_SIZE = 16384;

private:
  size_t    thePageSize;
  size_t    theFreeSize;

  char    * thePageStart;
  char    * thePageEnd;

public:

  MemPage(size_t page_size = DEFAULT_PAGE_SIZE);

  ~MemPage();

  size_t space() const { return theFreeSize; }

  void* allocate(size_t size);

private:
  // Pages are unique, there is no sense in copying them
  MemPage (const MemPage&);
  MemPage& operator= (const MemPage&);
};


/*******************************************************************************
 *                                Memory Manager                               *
 ******************************************************************************/
class MemoryManager
{
private:
  std::list<MemPage*>   thePages;
  MemPage             * theCurrentPage;

public:
  MemoryManager();

  ~MemoryManager();

  void* allocate(size_t size);

private:
  // A memory manager is the only existing object handling memory
  // Since it's all data that it contains, there is no sense in copying it.
  MemoryManager(const MemoryManager&);
  MemoryManager& operator=(const MemoryManager&);
};

} // namespace zorba


//This handles the creation of data within the memory pool using the format
//new (MemPool) constructor
//for more information see
//http://www.parashift.com/c++-faq-lite/dtors.html#faq-11.14
inline void* operator new(size_t size, zorba::MemoryManager& mem)
{
  return mem.allocate(size);
}


inline void operator delete(void* p, zorba::MemoryManager& mem)
{
  /*Memory is freed when MemoryManager is destroyed */ 
}

#endif /*ZORBA_COMPILER_MEMMANAGER_H*/
