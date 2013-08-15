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
#ifndef ZORBA_SPECIFIC_CLASS_SERIALIZATION
#define ZORBA_SPECIFIC_CLASS_SERIALIZATION

#include <zorba/item.h>
#include <zorba/xquery_exception.h>

#include "zorbatypes/rchandle.h"
#include "zorbatypes/float.h"
#include "zorbatypes/zorbatypes_decl.h"

#include "zorbautils/checked_vector.h"

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"

#include "store/api/shared_types.h"
#include "diagnostics/assert.h"

#include <stdio.h>
#include <map>

namespace zorba
{
  class Base16;
  class Base64;
  class Diagnostic;
  class function;
  class HashMapItemPointerCmp;
  class HashMapZStringCmp;
  class QueryLoc;
  class Timezone;
  class XQType;
  class ZorbaException;

namespace serialization
{

void operator&(Archiver& ar, HashMapZStringCmp& obj);

void operator&(Archiver& ar, HashMapItemPointerCmp& obj);

void operator&(Archiver& ar, const XQType*& obj);

template<class C>
void operator&(Archiver& ar, IntegerImpl<C>& obj);

void operator&(Archiver& ar, Decimal& obj);

void operator&(Archiver& ar, DateTime& obj);

void operator&(Archiver& ar, Duration& obj);

void operator&(Archiver& ar, Timezone& obj);

void operator&(Archiver& ar, Base64& obj);

void operator&(Archiver& ar, Base16& obj);

void operator&(Archiver& ar, store::Item*& obj);

void operator&(Archiver& ar, QueryLoc& obj);

void operator&(Archiver& ar, const Diagnostic*& obj);


#define SERIALIZE_TYPEMANAGER(type_mgr_type, type_mgr)                  \
  bool is_root_type_mgr =                                               \
    ar.is_serializing_out() &&                                          \
    (!GENV.isRootStaticContextInitialized() ||                          \
     ((TypeManager*)type_mgr == (TypeManager*)&GENV_TYPESYSTEM)) ;      \
                                                                        \
  ar & is_root_type_mgr;                                                \
                                                                        \
  if (is_root_type_mgr)                                                 \
  {                                                                     \
    if (!ar.is_serializing_out())                                       \
    {                                                                   \
      type_mgr = (type_mgr_type*)&GENV_TYPESYSTEM;                      \
    }                                                                   \
  }                                                                     \
  else                                                                  \
  {                                                                     \
    ar & type_mgr;                                                      \
  }


#define SERIALIZE_TYPEMANAGER_RCHANDLE(type_mgr_type, type_mgr)         \
  bool is_root_type_mgr =                                               \
  (!GENV.isRootStaticContextInitialized() ||                            \
   ((TypeManager*)type_mgr.getp() == (TypeManager*)&GENV_TYPESYSTEM));  \
                                                                        \
  ar & is_root_type_mgr;                                                \
                                                                        \
  if (is_root_type_mgr)                                                 \
  {                                                                     \
    if (!ar.is_serializing_out())                                       \
      type_mgr = (type_mgr_type*)&GENV_TYPESYSTEM;                      \
  }                                                                     \
  else                                                                  \
  {                                                                     \
    ar & type_mgr;                                                      \
  }


/*******************************************************************************

********************************************************************************/
template<typename StringType>
void operator&(Archiver& ar, zorba::internal::VariableQName<StringType>& obj)
{
  if (ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field(TYPE_LAST,
                                   !FIELD_IS_CLASS,
                                   &obj,
                                   ARCHIVE_FIELD_NORMAL);
    if (!is_ref)
    {
      ar & obj.ns_;
      ar & obj.prefix_;
      ar & obj.localname_;
      ar.add_end_compound_field();
    }
    else
    {
      assert(false);
    }
  }
  else
  {
    TypeCode type;
    int id;
    ArchiveFieldKind field_kind = ARCHIVE_FIELD_NORMAL;
    int referencing;

    ar.read_next_compound_field(false, field_kind, type, id, referencing);

    ar.check_nonclass_field(field_kind, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.ns_;
    ar & obj.prefix_;
    ar & obj.localname_;
    ar.read_end_current_level();
  }
}


} // namespace serialization
} // namespae zorba
#endif
/* vim:set et sw=2 ts=2: */
