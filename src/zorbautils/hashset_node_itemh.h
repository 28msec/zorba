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
#pragma once
#ifndef ZORBA_ZORBAUTILS_HASHSET_NODE_ITEMH
#define ZORBA_ZORBAUTILS_HASHSET_NODE_ITEMH

#include "zorbautils/hashfun.h"
#include "zorbautils/hashset.h"

#include "zorbatypes/collation_manager.h"

#include "store/api/item.h"

namespace zorba 
{ 

/*******************************************************************************
  A hash-based set container of item handles, where equality is based on
  object identity (i.e. pointer equality) rather than object value.

  It is used by the NodeDistinctIterator and for the population of a general
  index. 

  NOTE: Although the set uses raw item pointers instead of rchandles, reference
        counting is still done, but done manually (see insert and clear methods)
********************************************************************************/
class NodeHandleHashSet
{
public:

  class CompareFunction
  {
  public:
    static bool equal(const store::Item* t1, const store::Item* t2)
    {
      return t1 == t2;
    }

    static uint32_t hash(const store::Item* t)
    {
      return (uint32_t)(t);
    }
  };

private:
  HashSet<store::Item*, CompareFunction>  theSet;

public:
  NodeHandleHashSet(csize size, bool sync) : theSet(size, sync) { }

  ~NodeHandleHashSet() { clear(); }

  void clear();

  bool exists(store::Item* const key) 
  {
    return theSet.exists(key); 
  }

  bool insert(store::Item* key) 
  {
    assert(key->isNode());

    bool inserted = theSet.insert(key);

    if (inserted) 
    {
      key->addReference();
    }
    return inserted;
  }
};


} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
