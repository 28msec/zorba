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

#include "zorbamisc/config/platform.h"

namespace zorba
{

namespace serialization
{

class Archiver;


void operator&(Archiver& ar, int& obj);

void operator&(Archiver& ar, uint32_t& obj);

void operator&(Archiver& ar, long& obj);

void operator&(Archiver& ar, unsigned long& obj);

void operator&(Archiver& ar, long long& obj);

void operator&(Archiver& ar, unsigned long long& obj);

void operator&(Archiver& ar, short& obj);

void operator&(Archiver& ar, unsigned short& obj);

void operator&(Archiver& ar, char& obj);

void operator&(Archiver& ar, signed char& obj);

void operator&(Archiver& ar, unsigned char& obj);

void operator&(Archiver& ar, float& obj);

void operator&(Archiver& ar, double& obj);

void operator&(Archiver& ar, bool& obj);

void operator&(Archiver& ar, std::string& obj);

void operator&(Archiver& ar, std::string*& obj);

void operator&(Archiver& ar, char*& obj);//like char *p=strdup("io");

void serialize_array(Archiver& ar, unsigned char* obj, int len);

#define  SERIALIZE_ENUM(enum_type, obj)           \
  {                                               \
    ar.set_is_temp_field(true);                   \
                                                  \
    int int_enum = (int)obj;                      \
    ar & int_enum;                                \
                                                  \
    if (!ar.is_serializing_out())                 \
      obj = (enum_type)int_enum;                  \
                                                  \
    ar.set_is_temp_field(false);                  \
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
