#ifndef ZORBA_STORE_UTIL_NODE_HANDLE_HASHSET
#define ZORBA_STORE_UTIL_NODE_HANDLE_HASHSET

#include "store/util/handle_hashset.h"


namespace zorba { namespace store {


/*******************************************************************************
  A hash-based set container of node rchandles, where equality is based on
  node identity (i.e.  ordpath).
********************************************************************************/
class NodeHashSet : public HandleSet<Item, NodeHashSet>
{
public:

  static bool equal(const Item* t1, const Item* t2);

  static uint32_t hash(const Item* t);

public:
  NodeHashSet(ulong size = 1024) : HandleSet<Item, NodeHashSet>(size) {}
};

} // namespace store
} // namespace zorba

#endif
