#ifndef ZORBA_STORE_UTIL_NODE_HANDLE_HASHSET
#define ZORBA_STORE_UTIL_NODE_HANDLE_HASHSET

#include "store/util/hashset.h"
#include "store/naive/node_items.h"

namespace zorba { namespace store {


/*******************************************************************************
  A hash-based set container of node rchandles, where equality is based on
  node identity (i.e.  ordpath).
********************************************************************************/
class NodeHashSet : public HashSet<rchandle<Item>, NodeHashSet>
{
public:

  static bool equal(const Item_t& t1, const Item_t& t2)
  {
    return t1->equals(t2, 0);
  }

  static uint32_t hash(const Item_t& t)
  {
    return t->hash(0);
  }

public:
  NodeHashSet(ulong size = 1024) : HashSet<rchandle<Item>, NodeHashSet>(size) {}
};

} // namespace store
} // namespace zorba

#endif
