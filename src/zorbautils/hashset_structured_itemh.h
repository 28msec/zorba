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
#ifndef ZORBA_ZORBAUTILS_HASHSET_STRUCTURED_ITEMH
#define ZORBA_ZORBAUTILS_HASHSET_STRUCTURED_ITEMH

#include <cassert>

#include "zorbautils/hashfun.h"
#include "zorbautils/hashset.h"

#include "zorbatypes/collation_manager.h"

#include "store/api/item.h"

namespace zorba 
{ 

/*******************************************************************************
  A hash-based set container of item handles, where equality is based on
  node/object/array identity (i.e. pointer equality) rather than object value.

  It is used 
  1. by the NodeDistinctIterator
  2. for the population of a general index. 
  3. by the HashSemiJoinIterator, which implements op:intersect and op:except.

  NOTE: Although the set uses raw item pointers instead of rchandles, reference
        counting is still done, but done manually (see insert and clear methods)
********************************************************************************/
class StructuredItemHandleHashSet
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
      return reinterpret_cast<uint64_t>(t);
    }
  };

private:
  HashSet<store::Item*, CompareFunction>  theSet;

public:
  StructuredItemHandleHashSet(csize size, bool sync) : theSet(size, sync) { }

  ~StructuredItemHandleHashSet() { clear(); }

  void clear();

  bool empty() const { return theSet.empty(); }

  bool exists(const store::Item_t& key) const 
  {
    return theSet.exists(key.getp());
  }

  bool insert(const store::Item_t& key)
  {
    assert(key->isNode() || key->isObject() || key->isArray());

    store::Item* key2 = key.getp();

    bool inserted = theSet.insert(key2);

    if (inserted) 
    {
      key->addReference();
    }
    return inserted;
  }

  bool erase(const store::Item_t& key)
  {
    bool found = theSet.erase(key.getp());

    if (found)
      key->removeReference();

    return found;
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
