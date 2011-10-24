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
#ifndef ZORBA_STORE_UTIL_NODE_HANDLE_HASHSET
#define ZORBA_STORE_UTIL_NODE_HANDLE_HASHSET

#include "common/common.h"
#include "zorbautils/hashset.h"

namespace zorba { namespace store {


/*******************************************************************************
  A hash-based set container of node rchandles, where equality is based on
  node identity
********************************************************************************/
class NodeHashSet
{
public:

  class CompareFunction
  {
  public:
    bool equal(const Item_t& t1, const Item_t& t2) const
    {
      return t1->equals(t2, 0);
    }

    uint32_t hash(const Item_t& t) const
    {
      return t->hash(0);
    }
  };

private:
  HashSet<Item_t, CompareFunction>  theSet;

public:
  NodeHashSet(ulong size = 1024) : theSet(size, false) 
  {
  }

  void clear() { theSet.clear(); }

  bool empty() const { return theSet.empty(); }

  bool exists(const Item_t& key) { return theSet.exists(key); }

  bool insert(Item_t& key) { return theSet.insert(key); }

  bool erase(const Item_t& key) { return theSet.erase(key); }
};

} // namespace store
} // namespace zorba

#endif
/* vim:set et sw=2 ts=2: */
