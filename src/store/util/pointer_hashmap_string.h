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
