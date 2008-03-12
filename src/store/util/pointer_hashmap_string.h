#ifndef ZORBA_STORE_STRING_HASHMAP_H
#define ZORBA_STORE_STRING_HASHMAP_H

#include <zorba/common/common.h>
#include <zorbatypes/xqpstring.h>

#include "store/util/pointer_hashmap.h"


namespace zorba { namespace store {

/*******************************************************************************
  A hash-based map container, mapping xqpStringStore pointers to values of type
  V. String equality is based on string value. Class V must have a destructor.
********************************************************************************/
template <class V>
class StringHashMap : public PointerHashMap<xqpStringStore, StringHashMap<V>, V>
{
public:
  static bool equal(const xqpStringStore* s1, const xqpStringStore* s2)
  {
    return s1->byteEqual(*s2);
  }

  static uint32_t hash(const xqpStringStore* s)
  {
    return s->hash();
  }

public:
 StringHashMap(ulong size, double lf = 0.6)
   :
  PointerHashMap<xqpStringStore, StringHashMap, V>(size, lf) {};

  ~StringHashMap() { };
};


} // namespace store
} // namespace zorba

#endif
