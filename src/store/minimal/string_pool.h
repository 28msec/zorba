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
#include "zorbatypes/xqpstring.h"

#include "zorbautils/hashset.h"


namespace zorba { namespace storeminimal {

/*******************************************************************************
  A hash-based set container of string rchandles, where equality is based on
  string value.

  It is used to implement a pool of URI strings.
********************************************************************************/
class StringPool : public HashSet<xqpStringStore_t, StringPool>
{
public:
  static bool equal(const xqpStringStore_t& s1, const xqpStringStore_t& s2)
  {
    return s1->byteEqual(*s2);
  }

  static uint32_t hash(const xqpStringStore_t& s)
  {
    return s->hash();
  }

public:
 StringPool(ulong size) : HashSet<xqpStringStore_t, StringPool>(size, true) {};

  ~StringPool();

  bool insertc(const char* str, xqpStringStore_t& outStr);
  bool insertc(xqpStringStore* str, xqpStringStore_t& outStr);

protected:
  void garbageCollect();
};


} // namespace storeminimal
} // namespace zorba

#endif
