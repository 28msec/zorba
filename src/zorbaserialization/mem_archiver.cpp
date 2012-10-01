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

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"


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


void MemArchiver::read_next_simple_temp_field_impl(TypeCode type, void* obj)
{
  if (current_field == NULL || is_after_last)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS(0));
  }

  assert(type == current_field->theType);

  switch (type)
  {
  case TYPE_INT64:
  {
    *static_cast<int64_t*>(obj) = current_field->theValue.int64v;
    break;
  }
  case TYPE_UINT64:
  {
    *static_cast<uint64_t*>(obj) = current_field->theValue.uint64v;
    break;
  }
  case TYPE_INT32:
  {
    *static_cast<int32_t*>(obj) = current_field->theValue.int32v;
    break;
  }
  case TYPE_UINT32:
  {
    *static_cast<uint32_t*>(obj) = current_field->theValue.uint32v;
    break;
  }
  case TYPE_ENUM:
  {
    *static_cast<uint32_t*>(obj) = current_field->theValue.uint32v;
    break;
  }
  case TYPE_INT16:
  {
    *static_cast<int16_t*>(obj) = current_field->theValue.int16v;
    break;
  }
  case TYPE_UINT16:
  {
    *static_cast<uint16_t*>(obj) = current_field->theValue.uint16v;
    break;
  }
  case TYPE_CHAR:
  {
    *static_cast<char*>(obj) = current_field->theValue.charv;
    break;
  }
  case TYPE_UCHAR:
  {
    *static_cast<unsigned char*>(obj) = current_field->theValue.ucharv;
    break;
  }
  case TYPE_BOOL:
  {
    *static_cast<bool*>(obj) = current_field->theValue.boolv;
    break;
  }
  case TYPE_ZSTRING:
  {
    *static_cast<zstring*>(obj) = current_field->theStringValue;
    break;
  }
  case TYPE_STD_STRING:
  {
    *static_cast<std::string*>(obj) = current_field->theStringValue.str();
    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
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
}


void MemArchiver::read_next_simple_ptr_field_impl(TypeCode type, void** obj)
{
  if (current_field == NULL || is_after_last)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS(0));
  }

  assert(type == current_field->theType);

  switch (type)
  {
  case TYPE_STD_STRING:
  {
    *reinterpret_cast<std::string**>(obj) = 
    new std::string(current_field->theStringValue.str());
    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
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
}


void MemArchiver::read_next_compound_field_impl( 
    bool is_class,
    ArchiveFieldKind& field_treat,
    TypeCode& type, 
    int& id, 
    int& referencing)
{
  if (current_field == NULL || is_after_last)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS(0));
  }

  type = current_field->theType;

  id = current_field->theId;

  field_treat = current_field->theKind;

  referencing = (current_field->theReferredField ? 
                 current_field->theReferredField->theId : 0);

  is_after_last = false;

  if (current_field->theFirstChild)
  {
    current_field = current_field->theFirstChild;
  }
  else if (!current_field->theIsSimple &&
           (field_treat == ARCHIVE_FIELD_BASECLASS || 
            field_treat == ARCHIVE_FIELD_PTR))
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
}


void MemArchiver::read_end_current_level_impl()
{
  is_after_last = false;
  current_field = current_field->theParent;

  if (current_field->theNextSibling)
    current_field = current_field->theNextSibling;
  else
    is_after_last = true;
}

}}
/* vim:set et sw=2 ts=2: */
