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
#ifndef ZORBA_HASHMAP_STRING_HANDLE
#define ZORBA_HASHMAP_STRING_HANDLE

#include "zorbautils/hashmap.h"
#include "zorbatypes/xqpstring.h"

namespace zorba
{

class HashMapStrHandleCmp
{
public:
  static uint32_t hash(const xqpStringStore_t& str)
  {
    return str->hash();
  }

  static bool equal(const xqpStringStore_t& s1, const xqpStringStore_t& s2)
  {
    return s1->byteEqual(s2.getp());
  }
};


template<class V>
class HashMapStrHandle : public HashMap<xqpStringStore_t, V, HashMapStrHandleCmp>
{
public:
  HashMapStrHandle(ulong size, bool sync)
    :
    HashMap<xqpStringStore_t, V, HashMapStrHandleCmp>(size, sync)
  {
  }

  virtual ~HashMapStrHandle() {  }
};


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
