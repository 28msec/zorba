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

#include <iostream>
#include <cassert>
#include <new>

namespace zorba
{

/*******************************************************************************

********************************************************************************/
MemPage::MemPage(size_t size)
  :
  thePageSize(size),
  theFreeSize(size)
{
  thePageStart = new char[thePageSize];

  if (thePageStart == NULL)
    throw std::bad_alloc();

  thePageEnd = thePageStart + thePageSize;
}


/*******************************************************************************

********************************************************************************/
MemPage::~MemPage()
{
  delete [] thePageStart;
}


/*******************************************************************************

********************************************************************************/
void* MemPage::allocate(size_t size)
{
  assert(size > 0 && size <= theFreeSize);

  void* allocation = (void*)(thePageEnd - theFreeSize);

  theFreeSize -= size;

  return allocation;
}


/*******************************************************************************

********************************************************************************/
MemoryManager::MemoryManager()
{
  theCurrentPage = new MemPage();
  thePages.push_front(theCurrentPage);
}


/*******************************************************************************

********************************************************************************/
MemoryManager::~MemoryManager()
{
  for(std::list<MemPage*>::iterator iter = thePages.begin();
      iter != thePages.end();
      ++iter)
  {
    delete *iter;
  }
}


/*******************************************************************************

********************************************************************************/
void* MemoryManager::allocate(size_t size)
{
  assert(size <= MemPage::DEFAULT_PAGE_SIZE);

  if (theCurrentPage->space() < size)
  {
    theCurrentPage = new MemPage();
    thePages.push_front(theCurrentPage);
    
#ifndef NDEBUG
    //std::cout << "allocated new mem page of size " << MemPage::DEFAULT_PAGE_SIZE
    //          << " num pages = " << thePages.size() << std::endl;
#endif
  }

  return theCurrentPage->allocate(size);
}


} // namespace zorba
