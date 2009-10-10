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

  read_string_pool();

  root_tag_is_read();

}

BinArchiver::BinArchiver(std::ostream *os) : Archiver(true)
{
  //open archiver for output
  this->is = NULL;
  this->os = os;
}

BinArchiver::~BinArchiver()
{
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

  //first gather all strings in a string pool
  collect_strings(out_fields);
  //now serialize the string pool
  serialize_out_string_pool();
  //now serialize the fields
  serialize_compound_fields(out_fields);

}

int BinArchiver::add_to_string_pool(const char *str)
{
  if(!str)
    return 0;
  int   str_pos;
  if(string_pool.get(str, str_pos))
    return str_pos;
  strings.push_back(str);
  str_pos = strings.size();
  const char *str_dup = strdup(str);
  string_pool.insert(str_dup, str_pos);
  return str_pos;
}

void BinArchiver::collect_strings(archive_field   *parent_field)
{
  archive_field   *current_field = parent_field->first_child;
  while(current_field)
  {
    if(current_field->field_treat != ARCHIVE_FIELD_IS_NULL)
    {
      current_field->type_str_pos_in_pool = add_to_string_pool(current_field->type);
      if(current_field->field_treat != ARCHIVE_FIELD_IS_REFERENCING)
      {
        current_field->value_str_pos_in_pool = add_to_string_pool(current_field->value);
      }
    }
    if(!current_field->is_simple)
    {
      if(current_field->field_treat != ARCHIVE_FIELD_IS_REFERENCING)
      {
        collect_strings(current_field);
      }
    }
    current_field = current_field->next;
  }
}

void   BinArchiver::serialize_out_string_pool()
{
  write_int(strings.size());
  std::vector<std::string>::iterator  strings_it;
  for(strings_it = strings.begin(); strings_it != strings.end(); strings_it++)
  {
    write_string((*strings_it).c_str());
  }
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
      write_int(current_field->type_str_pos_in_pool);
      write_int(current_field->id);
      if(current_field->field_treat != ARCHIVE_FIELD_IS_REFERENCING)
      {
        write_int(current_field->version);
        write_int(current_field->value_str_pos_in_pool);
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

void BinArchiver::write_int(unsigned int intval)
{
  //write 7 bits per byte, only significant bits
  unsigned int   shifted_int = (intval >> 7);
  unsigned char tmp;
  while(shifted_int)
  {//little endian
    tmp = intval & 0x7F;
    os->write((char*)&tmp, 1);
    intval = shifted_int;
    shifted_int = (intval >> 7);
  }
  tmp = (intval & 0x7F) | 0x80;
  os->write((char*)&tmp, 1);

/*  
  //big endian
  tmp = (intval>>24) & 0xFF;
  os->write((char*)&tmp, 1);
  tmp = (intval>>16) & 0xFF;
  os->write((char*)&tmp, 1);
  tmp = (intval>>8) & 0xFF;
  os->write((char*)&tmp, 1);
  tmp = intval & 0xFF;
  os->write((char*)&tmp, 1);
*/
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

unsigned int BinArchiver::read_int()
{
  unsigned int outval = 0;
  unsigned char tmp;
  int   i = 0;
  
  do{
    is->read((char*)&tmp, 1);
    outval |= ((unsigned int)(tmp&0x7F) << (7*i));
    i++;
  }while(!(tmp & 0x80));

/*  //big endian
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;
  is->read((char*)&tmp, 1);
  outval = (outval<<8) + tmp;
*/
  return outval;
}

void BinArchiver::read_string_pool()
{
  strings.clear();
  std::string   str;
  int   count;
  count = read_int();
  for(int i=0;i<count;i++)
  {
    str.clear();
    read_string(str);
    strings.push_back(str);
  }
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
    unsigned int field_type_pos;
    //read_string(field_type);
    field_type_pos = read_int();
    if(field_type_pos)
      *type = (char*)strings[field_type_pos-1].c_str();
    else
      *type = NULL;
    *id = read_int();
    if(*field_treat != ARCHIVE_FIELD_IS_REFERENCING)
    {
      *version = read_int();
    //  read_string(*value);
      unsigned int value_pos;
      value_pos = read_int();
      if(value_pos)
       *value = strings[value_pos-1];
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
