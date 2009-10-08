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

#include "zorbaserialization/bin_archiver.h"
#include "zorbaerrors/error_manager.h"

namespace zorba{
  namespace serialization{

#define ZORBA_BIN_SERIALIZED_PLAN_STRING    "ZORBA-XQUERY BINARY SERIALIZED PLAN"

BinArchiver::BinArchiver(std::istream *is) : Archiver(false)
{
  //open archiver for input
  this->is = is;
  this->os = NULL;

  //read the plan serializer info
  char	preface_string[200];
  unsigned int	preface_len = 0;
  while(preface_len < sizeof(preface_string))
  {
	  is->read(preface_string + preface_len, 1);
	  if(is->gcount() < 1)
	  {
      ZORBA_ERROR(SRL0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
	  }
    if(preface_string[preface_len] == 0)
      break;
    preface_len++;
  }
  if(strcmp(preface_string, ZORBA_BIN_SERIALIZED_PLAN_STRING))
  {
    ZORBA_ERROR(SRL0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
  }

  read_string(archive_name);
  read_string(archive_info);
  archive_version = read_int();
  nr_ids = read_int();

  root_tag_is_read();

}

BinArchiver::BinArchiver(std::ostream *os) : Archiver(true)
{
  //open archiver for output
  this->is = NULL;
  this->os = os;
}

void BinArchiver::serialize_out()
{
  if(!os)
  {
    ZORBA_ERROR(SRL0007_INPUT_ARCHIVE_USED_FOR_OUT_SERIALIZATION);
  }

  prepare_serialize_out();

  os->write(ZORBA_BIN_SERIALIZED_PLAN_STRING, sizeof(ZORBA_BIN_SERIALIZED_PLAN_STRING));

  os->write(archive_name.c_str(), archive_name.length()+1);
  os->write(archive_info.c_str(), archive_info.length()+1);
  write_int(archive_version);
  write_int(nr_ids);
  serialize_compound_fields(out_fields);

}

void BinArchiver::serialize_compound_fields(archive_field   *parent_field)
{
  archive_field   *current_field = parent_field->first_child;
  unsigned char tempbyte;
  while(current_field)
  {
    tempbyte = 0;
    tempbyte |= current_field->is_simple ? 1 : 0;
    tempbyte |= current_field->is_class ? 1<<1 : 0;
    tempbyte |= (current_field->field_treat&0x0F)<<4;
    os->write((char*)&tempbyte, 1);
    if(current_field->field_treat != ARCHIVE_FIELD_IS_NULL)
    {
      write_string(current_field->type);
      write_int(current_field->id);
      if(current_field->field_treat != ARCHIVE_FIELD_IS_REFERENCING)
      {
        write_int(current_field->version);
        write_string(current_field->value);
      }
      else
        write_int(current_field->referencing);
    }

    if(!current_field->is_simple)
    {
      if(current_field->field_treat != ARCHIVE_FIELD_IS_REFERENCING)
      {
        serialize_compound_fields(current_field);
        tempbyte = 0xFF;
        os->write((char*)&tempbyte, 1);
      }
    }
    current_field = current_field->next;
  }
}

void BinArchiver::write_string(const char *str)
{
  os->write(str, strlen(str)+1);
}

void BinArchiver::write_int(const int intval)
{//big endian
  unsigned char tmp;
  tmp = (intval>>24) & 0xFF;
  os->write((char*)&tmp, 1);
  tmp = (intval>>16) & 0xFF;
  os->write((char*)&tmp, 1);
  tmp = (intval>>8) & 0xFF;
  os->write((char*)&tmp, 1);
  tmp = intval & 0xFF;
  os->write((char*)&tmp, 1);
}


////////////reading archive

void BinArchiver::read_string(std::string &str)
{
  char c;
  while(1)
  {
    is->read(&c, 1);
    if(is->gcount() < 1)
    {
      ZORBA_ERROR(SRL0002_INCOMPATIBLE_INPUT_FIELD);
    }
    if(c)
      str += c;
    else
      break;
  }
}

void BinArchiver::read_string(char* str)
{
  char c;
  while(1)
  {
    is->read(&c, 1);
    if(is->gcount() < 1)
    {
      ZORBA_ERROR(SRL0002_INCOMPATIBLE_INPUT_FIELD);
    }
    *str = c;
    if(!c)
      break;
    str++;
  }
}

int BinArchiver::read_int()
{//big endian
  int outval = 0;
  unsigned char tmp;
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;

  return outval;
}

bool BinArchiver::read_next_field_impl( char **type, 
                              std::string *value,
                              int *id, 
                              int *version, 
                              bool *is_simple, 
                              bool *is_class,
                              enum ArchiveFieldTreat *field_treat,
                              int *referencing)
{
  if(!is)
  {
    ZORBA_ERROR(SRL0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION);
  }

  *type = NULL;
  *id = -1; 
  *version = -1; 
  *is_simple = false; 
  *is_class = false,
  *field_treat = (enum ArchiveFieldTreat)-1;
  *referencing = -1;

  unsigned char  tempbyte;

  is->read((char*)&tempbyte, 1);
  if(tempbyte == 0xFF)
    return false;
  *is_simple = tempbyte & 0x01 ? true : false;
  *is_class = tempbyte & 0x02 ? true : false;
  *field_treat = (enum ArchiveFieldTreat)((tempbyte>>4)&0x0F);

  assert(*field_treat <= ARCHIVE_FIELD_IS_REFERENCING);
  if(*field_treat != ARCHIVE_FIELD_IS_NULL)
  {
    read_string(field_type);
    *type = field_type;
    *id = read_int();
    if(*field_treat != ARCHIVE_FIELD_IS_REFERENCING)
    {
      *version = read_int();
      read_string(*value);
    }
    else
     *referencing = read_int();
  }

  return true;
}




void BinArchiver::read_end_current_level_impl()
{
  unsigned char  tempbyte = 0;

  is->read((char*)&tempbyte, 1);
  if(tempbyte != 0xFF)
  {
    ZORBA_ERROR(SRL0002_INCOMPATIBLE_INPUT_FIELD);
  }
}


}}
