#ifndef ZORBA_STORE_STRING_HASHMAP_H
#define ZORBA_STORE_STRING_HASHMAP_H

#include <zorba/common/common.h>
#include <zorbatypes/xqpstring.h>

#include "store/util/pointer_hashmap.h"


namespace zorba { namespace store {

template <class V>
class StringHashMap : public PointerHashMap<xqpStringStore, StringHashMap<V>, V>
{
public:
  static const ulong DEFAULT_POOL_SIZE = 128;
  static const double DEFAULT_LOAD_FACTOR = 0.6;

  static bool equal(const xqpStringStore* s1, const xqpStringStore* s2)
  {
    return s1->byteEqual(*s2);
  }

  static uint32_t hash(const xqpStringStore* s)
  {
    return s->hash();
  }

public:
 StringHashMap(ulong size, double lf = DEFAULT_LOAD_FACTOR)
   :
  PointerHashMap<xqpStringStore, StringHashMap, V>(size, lf) {};

  ~StringHashMap() { };
};


} // namespace store
} // namespace zorba

#endif
