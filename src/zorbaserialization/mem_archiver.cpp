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


bool MemArchiver::read_next_field_impl( 
    char** type, 
    std::string* value,
    int* id, 
    int* version, 
    bool* is_simple, 
    bool* is_class,
    enum ArchiveFieldKind* field_treat,
    int* referencing)
{
  if (current_field == NULL || is_after_last)
    return false;

  *type = current_field->theTypeName;
  *value = current_field->theValue;
  *id = current_field->theId;
  *version = current_field->theClassVersion;
  *is_simple = current_field->theIsSimple;
  *is_class = current_field->theIsClass;
  *field_treat = current_field->theKind;
  *referencing = current_field->referencing;

  is_after_last = false;
  if(current_field->theFirstChild)
    current_field = current_field->theFirstChild;
  else if(!*is_simple && ((*field_treat == ARCHIVE_FIELD_IS_BASECLASS) || (*field_treat == ARCHIVE_FIELD_IS_PTR)))
  {
    //class without childs
    temp_field.theParent = current_field;
    current_field = &temp_field;//prepare for read_end_current_level()
  }
  else if(current_field->theNextSibling)
    current_field = current_field->theNextSibling;
  else
    is_after_last = true;
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
