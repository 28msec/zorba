#ifndef ZORBA_SIMPLE_STORE_QNAME_POOL
#define ZORBA_SIMPLE_STORE_QNAME_POOL

#include <vector>
#include "common/shared_types.h"
#include "common/common.h"
#include "util/hashfun.h"
#include "store/util/hashset.h"
#include "store/naive/atomic_items.h"

namespace zorba { namespace store {


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

  class QNamePoolHashSet : public HashSet<QNameItemImpl*, QNamePoolHashSet>
  {
    friend class QNamePool;

  public:
    static bool equal(const QNameItemImpl* t1, const QNameItemImpl* t2)
    {
      return (t1->theLocal->byteEqual(*t2->theLocal) &&
              t1->theNamespace->byteEqual(*t2->theNamespace) &&
              t1->thePrefix->byteEqual(*t2->thePrefix));
    }

    static uint32_t hash(const QNameItemImpl* t)
    {
      return  hashfun::h32(t->thePrefix->c_str(),
                           hashfun::h32(t->theNamespace->c_str(),
                                        hashfun::h32(t->theLocal->c_str())));
    }

  public:
    QNamePoolHashSet(ulong size) : HashSet<QNameItemImpl*, QNamePoolHashSet>(size) {}
  };


 typedef HashEntry<QNameItemImpl*, DummyHashValue> QNHashEntry;

public:
  static const ulong MAX_CACHE_SIZE = 65536;

protected:
  QNameItemImpl     * theCache;
  ulong               theCacheSize;
	ulong               theFirstFree;
  ulong               theNumFree;

  QNamePoolHashSet    theHashSet;

public:
  QNamePool(ulong size);

  ~QNamePool();

  Item_t insert(
        const char* ns,
        const char* pre,
        const char* ln);

  Item_t insert(
        xqpStringStore* ns,
        xqpStringStore* pre,
        xqpStringStore* ln,
        bool*           inserted);

  void remove(QNameItemImpl* qn);

protected:
  QNameItemImpl* cacheInsert(ulong hval);

  void cachePin(QNameItemImpl* qn);

  QNHashEntry* hashFind(
        const char* ns,
        const char* pre,
        const char* ln,
        ulong       nslen,
        ulong       prelen,
        ulong       lnlen,
        ulong       hval);
};


} // namespace store
} // namespace zorba

#endif
