#ifndef ZORBA_STORE_UTIL_ITEM_HASHSET
#define ZORBA_STORE_UTIL_ITEM_HASHSET

#include "store/util/handle_hashset.h"


namespace zorba
{

class ItemHashSet : public HandleSet<Item, ItemHashSet>
{
public:

  static bool equal(const Item* t1, const Item* t2)
  {
    return t1 == t2;
  }

  static uint32_t hash(const Item* t)
  {
    return t->hash();
  }

public:
 ItemHashSet(ulong size = 1024) : HandleSet<Item, ItemHashSet>(size) {}
};

}

#endif
