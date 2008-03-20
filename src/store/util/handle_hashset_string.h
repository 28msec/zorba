#ifndef ZORBA_STORE_STRING_HASHSET_H
#define ZORBA_STORE_STRING_HASHSET_H

#include "common/common.h"
#include "zorbatypes/xqpstring.h"

#include "store/util/handle_hashset.h"


namespace zorba { namespace store {

class StringPool : public HandleSet<xqpStringStore, StringPool>
{
public:
  static const ulong DEFAULT_POOL_SIZE;
  static const float DEFAULT_LOAD_FACTOR;


  static bool equal(const xqpStringStore* s1, const xqpStringStore* s2)
  {
    return s1->byteEqual(*s2);
  }

  static uint32_t hash(const xqpStringStore* s)
  {
    return s->hash();
  }

public:
  StringPool(ulong size) : HandleSet<xqpStringStore, StringPool>(size) {};

  ~StringPool();

  bool insertc(const char* str, xqpStringStore_t& outStr);

protected:
  void garbageCollect();
};


} // namespace store
} // namespace zorba

#endif
