/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_SIMPLE_STORE_STRING_POOL
#define ZORBA_SIMPLE_STORE_STRING_POOL

#include "common/common.h"
#include "zorbatypes/zstring.h"

#include "zorbautils/hashset.h"
#include "zorbautils/hashfun.h"


namespace zorba { namespace simplestore {


class StringPoolCompareFunction
{
public:
  static bool equal(const zstring& s1, const zstring& s2)
  {
    return s1 == s2;
  }

  static uint32_t hash(const zstring& s)
  {
    return hashfun::h32(s.data(), s.size(), FNV_32_INIT);
  }
};


/*******************************************************************************
  A hash-based set container of zstrings.

  It is used to implement a pool of URI strings.
********************************************************************************/
class StringPool : public HashSet<zstring, StringPoolCompareFunction>
{
public:
 StringPool(ulong size) 
    :
    HashSet<zstring, StringPoolCompareFunction>(size, true) {}

  ~StringPool();

  bool insertc(const char* str, zstring& outStr);

protected:
  void garbageCollect();
};


} // namespace store
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
