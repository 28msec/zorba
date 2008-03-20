#include "store/util/handle_hashset_node.h"

#include "store/api/store.h"
#include "system/globalenv.h"
#include "store/api/item.h"

namespace zorba { namespace store {

  bool 
  NodeHashSet::equal(const Item* t1, const Item* t2)
  {
    return GENV_STORE.equalNodes(t1, t2);
  }

  uint32_t 
  NodeHashSet::hash(const Item* t)
  {
    return GENV_STORE.hashNode(t);
  }

  } /* namespace store */
} /* namespace zorba */
