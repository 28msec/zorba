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
#ifndef TEST_ZORBA_SERIALIZATION_ARCHIVER
#define TEST_ZORBA_SERIALIZATION_ARCHIVER

#include "zorbaserialization/archiver.h"
#include "zorbaserialization/archiver_field.h"
#include "zorbatypes/rchandle.h"

namespace zorba
{
namespace serialization
{


class MemArchiver : public Archiver
{
protected:
  archive_field  * current_field;
  bool             is_after_last;
  archive_field    temp_field;

public:
  MemArchiver(bool is_serializing_out, bool internal_archive = false)
    : 
    Archiver(is_serializing_out, internal_archive),
    temp_field(TYPE_LAST, false, false, NULL, NULL,
               ARCHIVE_FIELD_NORMAL, NULL, false, ALLOW_DELAY, 0)
  {
    current_field = NULL;
    is_after_last = false;
  }

  bool read_next_simple_temp_field(SimpleValue& value, TypeCode type);

  bool read_next_field_impl( 
      TypeCode& type, 
      char** value,
      int* id,
      bool is_simple,
      bool is_class,
      bool have_value,
      enum ArchiveFieldKind* field_treat,
      int* referencing);

  void read_end_current_level_impl();

  void serialize_out() {}

  void reset_serialize_in();
};


}
}
#endif
/* vim:set et sw=2 ts=2: */
