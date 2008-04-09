#ifndef ZORBA_STORE_UTIL_STRING_POINTER_HASHMAP
#define ZORBA_STORE_UTIL_STRING_POINTER_HASHMAP

#include "common/common.h"
#include "zorbatypes/xqpstring.h"

#include "store/util/hashmap.h"


namespace zorba { namespace store {

/*******************************************************************************
  A hash-based map container, mapping xqpStringStore pointers to values of type
  V. String equality is based on string value. Class V must have a destructor.
********************************************************************************/
template <class V>
class StringHashMap : public HashMap<xqpStringStore*, V, StringHashMap<V> >
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
 StringHashMap(ulong size)
   :
  HashMap<xqpStringStore*, V, StringHashMap>(size) {};

  ~StringHashMap() { };
};


} // namespace store
} // namespace zorba

#endif
