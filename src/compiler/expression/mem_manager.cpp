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

#include "mem_manager.h"

#include <new>

namespace zorba
{

MemPage::MemPage(size_t page_size,
            void* (*allocate_func)(size_t), void (*deallocate_func)(void*)
        )
: thePageSize(page_size),
  theAllocator(allocate_func),
  theDeallocator(deallocate_func)
{
  thePageStart = static_cast<char*>((*theAllocator)(thePageSize));

  if (thePageStart == NULL)
    throw std::bad_alloc();

  theFreeStart = thePageStart;
}

MemPage::~MemPage()
{
  (*theDeallocator)(thePageStart);
}

size_t MemPage::space() const
{
  return thePageSize + thePageStart - theFreeStart;
}

void* MemPage::allocate(size_t alloc_size)
{
  if (alloc_size == 0 ||
      alloc_size + theFreeStart > thePageSize + thePageStart)
      return NULL;

  void* allocation = (void*)theFreeStart;

  theFreeStart += alloc_size;

  return allocation;
}

MemoryManager::MemoryManager()
{
  pages.push_front(MemPage());
}

MemoryManager::~MemoryManager() {}

void* MemoryManager::allocate(size_t size)
{
  if(size > MemPage::DEFAULT_PAGE_SIZE)
  {
    pages.push_back(MemPage(size));
    return pages.back().allocate(size);
  }

  if(pages.front().space() < size)
    pages.push_front(MemPage());

  return pages.front().allocate(size);
}

} // namespace zorba
