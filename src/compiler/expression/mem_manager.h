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

class MemPage {
public:
  static const size_t DEFAULT_PAGE_SIZE = 128;

  MemPage(size_t page_size = DEFAULT_PAGE_SIZE,
                void* (*allocate_func)(size_t) = &malloc,
                void (*deallocate_func)(void*) = &free);
  ~MemPage();

  size_t space() const;

  /*
   * Reserves a space of memory within the page.
   * @param alloc_size the amount of memory to reserve in bytes.
   * @returns if there is alloc_size space and alloc_size is not 0 returns a
   *          pointer to a space of memory of the size of allocate. Otherwise
   *          NULL.
   */
  void* allocate(size_t alloc_size);

private:
  const size_t thePageSize;
  void* (*theAllocator)(size_t);
  void (*theDeallocator)(void*);

  char* thePageStart;
  char* theFreeStart;
};

/*******************************************************************************
 *                                Memory Manager                               *
 ******************************************************************************/
class MemoryManager
{
public:
  MemoryManager();
  ~MemoryManager();

  void* allocate(size_t size);

private:
  std::list<MemPage> pages;
};

//This handles the creation of data within the memory pool using the format
//new (MemPool) constructor
//for more information see
//http://www.parashift.com/c++-faq-lite/dtors.html#faq-11.14
//Moreover the delete operator has not been added since deleting data does
//nothing we haven't added a delete operator yet.
inline void* operator new(size_t size, MemoryManager& mem)
{
    return mem.allocate(size);
}

} // namespace zorba
#endif /*ZORBA_COMPILER_MEMMANAGER_H*/
