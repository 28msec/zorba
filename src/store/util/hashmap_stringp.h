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
#include "zorbautils/hashmap.h"


namespace zorba { namespace store {

/*******************************************************************************

  A hash-based map container, mapping xqpStringStore pointers to values of type
  V. String equality is based on string value, using byte-by-byte comparison.

  It is used to map document/collection/index uris to document nodes/collection
  objs/index objs.
 
********************************************************************************/
template <class V>
class StringHashMap
{
public:
  class CompareFunction
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
  };


  typedef typename HashMap<const xqpStringStore*, V, CompareFunction>::iterator iterator;

private:
  HashMap<const xqpStringStore*, V, CompareFunction> theMap;

public:
 StringHashMap(ulong size, bool sync) : theMap(size, sync) {};

  ~StringHashMap() { };

  iterator begin() { return theMap.begin(); }

  iterator end() { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  void clear() { theMap.clear(); }

  bool get(const xqpStringStore* key, V& value) { return theMap.get(key, value); }

  bool insert(const xqpStringStore* key, V& value) { return theMap.insert(key, value); }

  bool remove(const xqpStringStore* key) { return theMap.remove(key); }

  bool find(const xqpStringStore* key) { return theMap.find(key); } 
};


} // namespace store
} // namespace zorba

#endif
