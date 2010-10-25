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

#define ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap.h"
#undef ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION

#include "zorbatypes/xqpstring.h"


namespace zorba
{

/***************************************************************************//**
  Class to privide the equality and hash functions for the HashMapStrHandle
  class defined below.
*******************************************************************************/
class HashMapStrHandleCmp : public ::zorba::serialization::SerializeBaseClass
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

public:
  SERIALIZABLE_CLASS(HashMapStrHandleCmp);

  HashMapStrHandleCmp(::zorba::serialization::Archiver& ar)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar)
  {
  }

  HashMapStrHandleCmp()
  {
  }
};


/*******************************************************************************
  A hash-based map container mapping xqpStringStore rchandles to values of type
  V. Equality is based on the xqpStringStore::byteEqual() method.
*******************************************************************************/
template<class V>
class serializable_HashMapStrHandle : public serializable_HashMap<xqpStringStore_t,
                                                                  V,
                                                                  HashMapStrHandleCmp>
{
public:
  SERIALIZABLE_TEMPLATE_CLASS(serializable_HashMapStrHandle)

  serializable_HashMapStrHandle(::zorba::serialization::Archiver& ar)
    :
    serializable_HashMap<xqpStringStore_t, V, HashMapStrHandleCmp>(ar)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (serializable_HashMap<xqpStringStore_t, V, HashMapStrHandleCmp>*)this);
  }

public:
  serializable_HashMapStrHandle(ulong size, bool sync)
    :
    serializable_HashMap<xqpStringStore_t, V, HashMapStrHandleCmp>(size, sync)
  {
  }

  virtual ~serializable_HashMapStrHandle() {  }
};


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
