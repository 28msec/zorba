#ifndef ZORBA_STORE_UTIL_STRING_HANDLE_HASHSET
#define ZORBA_STORE_UTIL_STRING_HANDLE_HASHSET

#include "common/common.h"
#include "zorbatypes/xqpstring.h"

#include "store/util/hashset.h"


namespace zorba { namespace store {

/*******************************************************************************
  A hash-based set container of string rchandles, where equality is based on
  string value.
********************************************************************************/
class StringPool : public HashSet<xqpStringStore_t, StringPool>
{
public:
  static const ulong DEFAULT_POOL_SIZE;
  static const float DEFAULT_LOAD_FACTOR;


  static bool equal(const xqpStringStore_t& s1, const xqpStringStore_t& s2)
  {
    return s1->byteEqual(*s2);
  }

  static uint32_t hash(const xqpStringStore_t& s)
  {
    return s->hash();
  }

public:
  StringPool(ulong size) : HashSet<xqpStringStore_t, StringPool>(size) {};

  ~StringPool();

  bool insertc(const char* str, xqpStringStore_t& outStr);

protected:
  void garbageCollect();
};


} // namespace store
} // namespace zorba

#endif
