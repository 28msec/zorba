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

#include "stdafx.h"
#include "mem_manager.h"

#include <iostream>
#include <new>

namespace zorba
{

/*******************************************************************************

********************************************************************************/
MemoryManager::MemoryManager()
{
  thePages.reserve(1024);

  thePageStart = new char[thePageSize];

  if (thePageStart == NULL)
    throw std::bad_alloc();

  thePageEnd = thePageStart + thePageSize;
  theFreeSize = thePageSize;
  thePages.push_back(thePageStart);
}


/*******************************************************************************

********************************************************************************/
MemoryManager::~MemoryManager()
{
  for(std::vector<char*>::iterator iter = thePages.begin();
      iter != thePages.end();
      ++iter)
  {
    delete [] (*iter);
  }
}


} // namespace zorba
