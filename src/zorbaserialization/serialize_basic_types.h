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
#ifndef ZORBA_PLAN_SERIALIZER_BASIC_TYPES
#define ZORBA_PLAN_SERIALIZER_BASIC_TYPES

#include <string>

#include "zorbatypes/zstring.h"

#include "zorbamisc/config/platform.h"

#include "store/api/shared_types.h"


class MAPM;

namespace zorba
{

class XQPCollator;

namespace serialization
{

class Archiver;


void operator&(Archiver& ar, short& obj);

void operator&(Archiver& ar, unsigned short& obj);

void operator&(Archiver& ar, int& obj);

void operator&(Archiver& ar, unsigned int& obj);

void operator&(Archiver& ar, long& obj);

void operator&(Archiver& ar, ulong& obj);

void operator&(Archiver& ar, long long& obj);

void operator&(Archiver& ar, unsigned long long& obj);

void serialize_enum(Archiver& ar, uint32_t& obj);

void operator&(Archiver& ar, char& obj);

void operator&(Archiver& ar, unsigned char& obj);

void operator&(Archiver& ar, float& obj);

void operator&(Archiver& ar, double& obj);

void operator&(Archiver& ar, bool& obj);

void operator&(Archiver& ar, zorba::zstring& obj);

void operator&(Archiver& ar, std::string& obj);

void operator&(Archiver& ar, std::string*& obj);

void operator&(Archiver& ar, XQPCollator*& obj);

void operator&(Archiver& ar, MAPM& obj);

#define SERIALIZE_ENUM(enum_type, obj)              \
{                                                   \
  uint32_t int_enum = static_cast<uint32_t>(obj);   \
  serialize_enum(ar, int_enum);                     \
                                                    \
  if (!ar.is_serializing_out())                     \
    obj = (enum_type)int_enum;                      \
}

#define SERIALIZE_BOOL_VEC(vec)                   \
  {                                               \
    ar.set_is_temp_field_one_level(true);         \
    csize lSize = 0;                              \
    if (ar.is_serializing_out())                  \
    {                                             \
      lSize = vec.size();                         \
      serialize_csize(ar, lSize);                 \
      for (csize i = 0; i < lSize; ++i)           \
      {                                           \
        bool b = vec[i];                          \
        ar & b;                                   \
      }                                           \
    }                                             \
    else                                          \
    {                                             \
      serialize_csize(ar, lSize);                 \
      vec.reserve(lSize);                         \
      for (csize i = 0; i < lSize; ++i)           \
      {                                           \
        bool b;                                   \
        ar & b;                                   \
        vec.push_back(b);                         \
      }                                           \
    }                                             \
    ar.set_is_temp_field_one_level(false);        \
  }


} // namespace serialization
} // namespace zorba

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
