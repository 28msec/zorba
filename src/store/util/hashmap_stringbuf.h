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
#ifndef ZORBA_STORE_UTIL_STRING_BUF_HASHMAP
#define ZORBA_STORE_UTIL_STRING_BUF_HASHMAP

#include "common/common.h"

#include "zorbatypes/zstring.h"

#include "util/utf8_util.h"

#include "zorbautils/hashmap.h"

namespace zorba { namespace store {

/*******************************************************************************

  A hash-based map container, mapping string pointers (wrapped by zstring_b) to
  values of type V. String equality is based on string value, using byte-by-byte
  comparison.

  It is used to map document/collection/index uris to document nodes/collection
  objs/index objs.
 
********************************************************************************/
template <class V>
class StringBufHashMap
{
public:
  class CompareFunction
  {
  public:
    static bool equal(const zstring_b& s1, const zstring_b& s2)
    {
      return s1 == s2;
    }

    static uint32_t hash(const zstring_b& s)
    {
      return utf8::hash(s);
    }
  };


  typedef typename HashMap<zstring_b, V, CompareFunction>::iterator iterator;

private:
  HashMap<zstring_b, V, CompareFunction> theMap;

public:
  StringBufHashMap(ulong size, bool sync) : theMap(size, sync) {};

  ~StringBufHashMap() { };

  iterator begin() { return theMap.begin(); }

  iterator end() { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  void clear() { theMap.clear(); }

  bool get(const zstring_b& key, V& value) { return theMap.get(key, value); }

  bool find(const zstring_b& key) { return theMap.find(key); } 

  bool insert(zstring_b& key, V& value) { return theMap.insert(key, value); }

  bool remove(const zstring_b& key) { return theMap.remove(key); }
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
