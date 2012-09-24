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
#pragma once
#ifndef ZORBA_UTILS_HASHMAP_CSTRING
#define ZORBA_UTILS_HASHMAP_CSTRING

#include "zorbautils/hashmap.h"
#include "zorbautils/hashfun.h"


namespace zorba
{

/***************************************************************************//**
  Class to privide the equality and hash functions for the HashMapZString
  class defined below.
*******************************************************************************/
class HashMapCStringCmp
{
public:
  static uint32_t hash(const char* str)
  {
    return hashfun::h32(str, FNV_32_INIT);
  }

  static bool equal(const char* s1, const char* s2)
  {
    return strcmp(s1, s2) == 0;
  }
};


#define CSTRING_HASH_MAP(ValueType, MapType) \
typedef HashMap<const char*, ValueType, HashMapCStringCmp> MapType;


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
