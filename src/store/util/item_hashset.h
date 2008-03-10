#ifndef ZORBA_STORE_UTIL_ITEM_HASHSET
#define ZORBA_STORE_UTIL_ITEM_HASHSET

#include "util/hashfun.h"

#include "store/util/handle_hashset.h"


namespace zorba { namespace store {

class ItemHashSet : public HandleSet<Item, ItemHashSet>
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
  ItemHashSet(ulong size = 1024) : HandleSet<Item, ItemHashSet>(size) {}
};

} // namespace store
} // namespace zorba

#endif
