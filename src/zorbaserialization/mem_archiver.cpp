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
#include "stdafx.h"

#include "zorbaserialization/mem_archiver.h"

namespace zorba
{

namespace serialization
{

void MemArchiver::reset_serialize_in()
{
  theSerializingOut = false;
  theCurrentLevel = 0;

  current_field = theRootField->theFirstChild;
  root_tag_is_read();
}


bool MemArchiver::read_next_simple_temp_field(SimpleValue& value, TypeCode type)
{
  if (current_field == NULL || is_after_last)
    return false;

  switch (type)
  {
  case TYPE_INT64:
  {
    value.int64v = current_field->theValue.int64v;
    break;
  }
  case TYPE_UINT64:
  {
    value.uint64v = current_field->theValue.uint64v;
    break;
  }
  case TYPE_INT32:
  {
    value.int32v = current_field->theValue.int32v;
    break;
  }
  case TYPE_UINT32:
  {
    value.uint32v = current_field->theValue.uint32v;
    break;
  }
  case TYPE_INT16:
  {
    value.int16v = current_field->theValue.int16v;
    break;
  }
  case TYPE_UINT16:
  {
    value.uint16v = current_field->theValue.uint16v;
    break;
  }
  case TYPE_CHAR:
  {
    value.charv = current_field->theValue.charv;
    break;
  }
  case TYPE_UCHAR:
  {
    value.ucharv = current_field->theValue.ucharv;
    break;
  }
  case TYPE_BOOL:
  {
    value.boolv = current_field->theValue.boolv;
    break;
  }
  default:
    value.cstrv = current_field->theValue.cstrv;
  }

  is_after_last = false;

  if (current_field->theFirstChild)
  {
    current_field = current_field->theFirstChild;
  }
  else if (current_field->theNextSibling)
  {
    current_field = current_field->theNextSibling;
  }
  else
  {
    is_after_last = true;
  }

  return true;
}


bool MemArchiver::read_next_field_impl( 
    char** type, 
    char** value,
    int* id, 
    bool is_simple,
    bool is_class,
    bool have_value,
    enum ArchiveFieldKind* field_treat,
    int* referencing)
{
  if (current_field == NULL || is_after_last)
    return false;

  *type = current_field->theTypeName;
  *value = (char*)current_field->theValue.cstrv;
  *id = current_field->theId;
  *field_treat = current_field->theKind;
  *referencing = current_field->referencing;

  is_after_last = false;

  if (current_field->theFirstChild)
  {
    current_field = current_field->theFirstChild;
  }
  else if (!current_field->theIsSimple &&
           (*field_treat == ARCHIVE_FIELD_BASECLASS || 
            *field_treat == ARCHIVE_FIELD_PTR))
  {
    //class without childs
    temp_field.theParent = current_field;
    current_field = &temp_field;//prepare for read_end_current_level()
  }
  else if (current_field->theNextSibling)
  {
    current_field = current_field->theNextSibling;
  }
  else
  {
    is_after_last = true;
  }
  return true;
}


void MemArchiver::read_end_current_level_impl()
{
  is_after_last = false;
  current_field = current_field->theParent;

  if(current_field->theNextSibling)
    current_field = current_field->theNextSibling;
  else
    is_after_last = true;
}

}}
/* vim:set et sw=2 ts=2: */
