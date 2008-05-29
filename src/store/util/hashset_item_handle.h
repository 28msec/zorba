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
#ifndef ZORBA_STORE_UTIL_ITEM_HANDLE_HASHSET
#define ZORBA_STORE_UTIL_ITEM_HANDLE_HASHSET

#include "zorbautils/hashfun.h"
#include "zorbautils/hashset.h"


namespace zorba { namespace store {


/*******************************************************************************

  A hash-based set container of item rchandles, where equality is based on
  object identity (i.e. pointer equality) rather than object value.

  It is used by the NodeDistinctIterator. 

********************************************************************************/
class ItemHandleHashSet : public HashSet<rchandle<Item>, ItemHandleHashSet>
{
public:

  static bool equal(const Item_t& t1, const Item_t& t2)
  {
    return t1 == t2;
  }

  static uint32_t hash(const Item_t& t)
  {
    return hashfun::h32((void*)(&t), sizeof(void*), FNV_32_INIT);
  }

public:
 ItemHandleHashSet(ulong size, bool sync) 
    :
  HashSet<rchandle<Item>, ItemHandleHashSet>(size, sync, false)
  {
  }
};

} // namespace store
} // namespace zorba

#endif
