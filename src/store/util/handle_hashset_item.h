#ifndef ZORBA_STORE_UTIL_ITEM_HANDLE_HASHSET
#define ZORBA_STORE_UTIL_ITEM_HANDLE_HASHSET

#include "util/hashfun.h"

#include "store/util/handle_hashset.h"


namespace zorba { namespace store {


/*******************************************************************************
  A hash-based set container of item rchandles, where equality is based on
  object identity (i.e. pointer equality) rather than object value.
********************************************************************************/
class ItemHandleHashSet : public HandleSet<Item, ItemHandleHashSet>
{
public:

  static bool equal(const Item* t1, const Item* t2)
  {
    return t1 == t2;
  }

  static uint32_t hash(const Item* t)
  {
    return hashfun::h32((void*)(&t), sizeof(void*), FNV_32_INIT);
  }

public:
  ItemHandleHashSet(ulong size = 1024) : HandleSet<Item, ItemHandleHashSet>(size) {}
};

} // namespace store
} // namespace zorba

#endif
