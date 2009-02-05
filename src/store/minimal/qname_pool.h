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
#ifndef ZORBA_SIMPLE_STORE_QNAME_POOL
#define ZORBA_SIMPLE_STORE_QNAME_POOL

#include <vector>
#include "zorbautils/hashfun.h"
#include "zorbautils/hashset.h"
#include "common/shared_types.h"
#include "common/common.h"
#include "store/minimal/min_atomic_items.h"

namespace zorba { namespace storeminimal {

class StringPool;

/*******************************************************************************

  theCache       : An array of QName slots that is managed as a cache. This
                   means that slots that are not used are placed in a free list.
                   When a new qname is inserted in the cache, a slot is taken
                   from the free list and the qname currently in that slot is
                   replaced with the new slot.
  theCacheSize   : The size of theCache (number of slots). This size is given
                   as a param to the QNamePool constructor, and it never changes
                   afterwards. 
  theFirstFree   : The position in theCache of the 1st free slot. NOTE: the 1st
                   slot of theCache (at position 0) is reserved (i.e., never
                   used) so that position 0 can be used to indicate the end of
                   the free list.
  theNumFree     : Number of free slots in theCache.

  theHashSet     : A hash set mapping qnames (i.e. triplets of strings) to
                   QName slots.

********************************************************************************/
class QNamePool
{
protected:

  class CompareFunction
  {
  public:
    static bool equal(const QNameItemImpl* t1, const QNameItemImpl* t2)
    {
      return (t1->getLocalName()->byteEqual(*t2->getLocalName()) &&
              t1->getPrefix()->byteEqual(*t2->getPrefix()) &&
              t1->getNamespace()->byteEqual(*t2->getNamespace()));
    }

    static uint32_t hash(const QNameItemImpl* t)
    {
    //  return  hashfun::h32(t->getPrefix()->c_str(),
    //                       hashfun::h32(t->getNamespace()->c_str(),
    //                               hashfun::h32(t->getLocalName()->c_str())));
        return compute_hash(t->getPrefix()->c_str(),
                            t->getLocalName()->c_str(), 
                            (uint32_t)(uint64_t)t->getNamespace());
    }

    static uint32_t compute_hash(const char *pre, const char *ln, uint32_t ns)
    {
      return hashfun::h32(pre, hashfun::h32(ln, ns));
    }
  };

  class QNamePoolHashSet : public HashSet<QNameItemImpl*, CompareFunction>
  {
    friend class QNamePool;
  public:
    QNamePoolHashSet(ulong size) 
      :
      HashSet<QNameItemImpl*, CompareFunction>(size, true)
    {
    }
  };


 typedef HashEntry<QNameItemImpl*, DummyHashValue> QNHashEntry;

public:
  static const ulong MAX_CACHE_SIZE = 256;//65536;

protected:
  QNameItemImpl     * theCache;
  ulong               theCacheSize;
	ulong               theFirstFree;
  ulong               theNumFree;

  QNamePoolHashSet    theHashSet;

  StringPool        * theNamespacePool;

public:
  QNamePool(ulong size, StringPool* nspool);

  ~QNamePool();

  store::Item_t insert(
        const char* ns,
        const char* pre,
        const char* ln,
        bool        sync = true);

  store::Item_t insert(
        const xqpStringStore_t& ns,
        const xqpStringStore_t& pre,
        const xqpStringStore_t& ln,
        bool                    sync = true);

  void remove(QNameItemImpl* qn);

protected:
  QNameItemImpl* cacheInsert(QNameItemImpl*& normVictim);

  void cachePin(QNameItemImpl* qn);

  QNHashEntry* hashFind(
        const xqpStringStore* ns,
        const char* pre,
        const char* ln,
        ulong       prelen,
        ulong       lnlen,
        ulong       hval);
  QNHashEntry* hashFind(
      const xqpStringStore* ns,
      const xqpStringStore* pre,
      const xqpStringStore* ln,
      ulong       hval);
};


} // namespace storeminimal
} // namespace zorba

#endif
