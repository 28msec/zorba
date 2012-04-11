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

#include "zorbaserialization/bin_archiver.h"
#include "diagnostics/xquery_diagnostics.h"
#include <fstream>

namespace zorba
{

namespace serialization
{

#define ZORBA_BIN_SERIALIZED_PLAN_STRING    "ZORBA-XQUERY BINARY SERIALIZED PLAN"
#define BUFFER_SEGMENT_SIZE  2*1024*1024

/*******************************************************************************
  Open archiver for input
********************************************************************************/
BinArchiver::BinArchiver(std::istream* is) 
  :
  Archiver(false)
{
  this->is = is;
  this->os = NULL;
  this->last_id = 0;
  current_byte = 0;
  bitfill = 8;

  //read the plan serializer info
  char	preface_string[200];
  unsigned int	preface_len = 0;
  while(preface_len < sizeof(preface_string))
  {
	  is->read(preface_string + preface_len, 1);
	  if(is->gcount() < 1)
	  {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
	  }
    if(preface_string[preface_len] == 0)
      break;
    preface_len++;
  }
  if(strcmp(preface_string, ZORBA_BIN_SERIALIZED_PLAN_STRING))
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
  }

  in_buffer = (unsigned char*)malloc(BUFFER_SEGMENT_SIZE);
  size_read = 0;
  while(1)
  {
    is->read((char*)in_buffer + size_read, BUFFER_SEGMENT_SIZE);
    size_read += (size_t)is->gcount();
    if(is->gcount() == BUFFER_SEGMENT_SIZE)
    {
      in_buffer = (unsigned char*)realloc(in_buffer, size_read + BUFFER_SEGMENT_SIZE);
    }
    else
      break;
  }
  in_current = in_buffer;

  read_string(theArchiveName);
  read_string(theArchiveInfo);
  theArchiveVersion = read_int();
  nr_ids = read_int();
  unsigned int is_release = read_int();
#ifndef NDEBUG
  if(is_release)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0016_CANNOT_LOAD_FROM_RELEASE_TO_DEBUG);
  }
#else
  if(!is_release)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0017_CANNOT_LOAD_FROM_DEBUG_TO_RELEASE);
  }
#endif

  read_string_pool();

  root_tag_is_read();
}


/*******************************************************************************
  Open archiver for output
********************************************************************************/
BinArchiver::BinArchiver(std::ostream* os)
  :
  Archiver(true)
{
  this->is = NULL;
  this->os = os;
  this->last_id = 0;
  current_byte = 0;
  bitfill = 0;
  
  in_buffer = NULL;
}


/*******************************************************************************

********************************************************************************/
BinArchiver::~BinArchiver()
{
  if (in_buffer)
    free(in_buffer);
}


#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
/*******************************************************************************

********************************************************************************/
void add_indentation(std::ostream &os, unsigned int indent)
{
  while(indent--)
  {
    os << " ";
  }
}


/*******************************************************************************

********************************************************************************/
void write_xml_name(std::ostream& os, const char* type)
{
  if(!type || !*type)
  {
    os << "unknown";
    return;
  }
  while(*type)
  {
    if(isalpha(*type))
      os << *type;
    else if(*type == '*')
      os << "_ptr";
    type++;
  }
}


/*******************************************************************************

********************************************************************************/
void output_statistics_archive_field(
    std::ostream& os,
    unsigned int indent,
    archive_field* parent)
{
  add_indentation(os, indent);
  os << "<";
  write_xml_name(os, parent->theTypeName);
  os << " n=\"" << parent->objects_saved << "\"";
  os << " s=\"" << parent->thebytesSaved << "\"";
  if(parent->theKind == ARCHIVE_FIELD_REFERENCING)
      os << " t=\"ref\"";
  else if(parent->theKind == ARCHIVE_FIELD_PTR)
      os << " t=\"ptr\"";
  if((!parent->theIsSimple) && (parent->theKind != ARCHIVE_FIELD_REFERENCING))
  {
    os << ">" << std::endl;
    archive_field   *current_field = parent->first_child;
    while(current_field)
    {
      output_statistics_archive_field(os, indent+2, current_field);
      current_field = current_field->theNextSibling;
    }
    add_indentation(os, indent);
    os << "</";
    write_xml_name(os, parent->theTypeName);
    os << ">" << std::endl;
  }
  else
  {
    os << "/>" << std::endl;
  }
}
#endif


/*******************************************************************************

********************************************************************************/
void BinArchiver::serialize_out()
{
  if (!os)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0007_INPUT_ARCHIVE_USED_FOR_OUT_SERIALIZATION);
  }

  prepare_serialize_out();

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  bytes_saved = 0;
  objects_saved = 0;
  nr_ptrs = 0;
  strings_saved = 0;
#endif

  os->write(ZORBA_BIN_SERIALIZED_PLAN_STRING, sizeof(ZORBA_BIN_SERIALIZED_PLAN_STRING));

  os->write(theArchiveName.c_str(), (std::streamsize)theArchiveName.length()+1);
  os->write(theArchiveInfo.c_str(), (std::streamsize)theArchiveInfo.length()+1);
  write_int(theArchiveVersion);

  write_int(nr_ids);

#ifndef NDEBUG
  write_int(0);//for debug
#else
  write_int(1);//for release
#endif

  //first gather all strings in a string pool
  collect_strings(theRootField);

  //now serialize the string pool
  serialize_out_string_pool();

  //now serialize the fields
  serialize_compound_fields(theRootField);

  if (bitfill)
  {
    current_byte <<= (8-bitfill);
    os->write((char*)&current_byte, 1);
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
    bytes_saved++;
#endif
  }

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  std::ofstream   plan_xml("plan.xml");
  plan_xml << "<plan objects_saved=\"" << objects_saved << "\""
           << " nr_ptrs=\"" << nr_ptrs << "\""
           << " string_count=\"" << strings.size() << "\""
           << " string_pool_size=\"" << strings_saved << "\" >"
           << std::endl;
  output_statistics_archive_field(plan_xml, 2, out_fields);
  plan_xml << "</plan>" << std::endl;
  std::cout << "Plan serialized:" << std::endl
            << "string count = " << strings.size() << std::endl
            << "size occupied by strings = " << strings_saved  << std::endl
            << "obj_count = " << objects_saved << std::endl
            << "objs that are ptr = " << nr_ptrs << std::endl
            << "size occupied by objects = " << bytes_saved << std::endl;
  std::cout << "Get some other details in plan.xml" << std::endl;
#endif
}


/*******************************************************************************

********************************************************************************/
int BinArchiver::add_to_string_pool(const char *str)
{
  if(!str)
    return 0;
  int   str_pos = 0;
  if(string_pool.get(str, str_pos))
  {
    STRING_POS &str_struct = strings.at(str_pos-1);
    str_struct.count++;
    return str_pos;
  }
  STRING_POS  str_struct;
  str_struct.str = str;
  str_struct.count = 1;
  str_struct.final_pos = (unsigned int)strings.size()+1;
  strings.push_back(str_struct);
  str_pos = (int)strings.size();
  strings_pos.push_back(str_pos-1);
  const char *str_dup = strdup(str);
  string_pool.insert(str_dup, str_pos);
  return str_pos;
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::collect_strings(archive_field* parent_field)
{
  archive_field* current_field = parent_field->theFirstChild;
  while (current_field)
  {
    if(current_field->theKind != ARCHIVE_FIELD_NULL)
    {
#ifdef NDEBUG
      if(current_field->theIsClass && (current_field->theKind == ARCHIVE_FIELD_PTR))
#endif
        current_field->theTypeNamePosInPool = add_to_string_pool(current_field->theTypeName);
      if(current_field->theKind != ARCHIVE_FIELD_REFERENCING)
      {
        current_field->theValuePosInPool = add_to_string_pool(current_field->theValue);
      }
    }

    if(!current_field->theIsSimple)
    {
      if(current_field->theKind != ARCHIVE_FIELD_REFERENCING)
      {
        collect_strings(current_field);
      }
    }

    current_field = current_field->theNextSibling;
  }
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::serialize_out_string_pool()
{
  //sort strings based on use count
  unsigned int i,j;
  for (i = 0; i < strings_pos.size(); i++)
  {
    for (j = i+1; j < strings_pos.size(); j++)
    {
      if (strings.at(strings_pos[i]).count < strings.at(strings_pos[j]).count)
      {
        unsigned int temp;
        temp = strings_pos[i];
        strings_pos[i] = strings_pos[j];
        strings_pos[j] = temp;
        strings.at(strings_pos[i]).final_pos = i+1;
        strings.at(strings_pos[j]).final_pos = j+1;
      }
    }
  }

  write_int((unsigned int)strings.size());
  if(bitfill)
  {
    current_byte <<= (8-bitfill);
    os->write((char*)&current_byte, 1);
    bitfill = 0;
    current_byte = 0;
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
    bytes_saved++;
#endif
  }
  std::vector<unsigned int>::iterator  strings_pos_it;
  for(strings_pos_it = strings_pos.begin(); strings_pos_it != strings_pos.end(); strings_pos_it++)
  {
    write_string(strings.at(*strings_pos_it).str.c_str());
  }
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::serialize_compound_fields(archive_field   *parent_field)
{
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  unsigned int    bytes_saved1 = bytes_saved;
  unsigned int    objects_saved1 = objects_saved;
#endif
  archive_field* current_field = parent_field->theFirstChild;

  while(current_field)
  {
#ifndef NDEBUG
    unsigned char tempbyte;
    tempbyte = 0;
    tempbyte |= current_field->theIsSimple ? 1 : 0;
    tempbyte |= current_field->theIsClass ? 1<<1 : 0;
    tempbyte |= (current_field->theKind&0x0F)<<4;
    write_bits(tempbyte, 8);
#else
    unsigned char small_treat = 0;
    switch(current_field->theKind)
    {
    case ARCHIVE_FIELD_NULL:          small_treat = 1;break;
    case ARCHIVE_FIELD_REFERENCING:   small_treat = 2;break;
    case ARCHIVE_FIELD_BASECLASS:     small_treat = 3;break;//??
    default: break;
    }

    write_bits(small_treat, 2);
#endif

    if(current_field->theKind != ARCHIVE_FIELD_NULL)
    {
#ifdef NDEBUG
      if (current_field->theIsClass && (current_field->theKind == ARCHIVE_FIELD_PTR))
#endif
      {
        if (!current_field->theTypeName)
          write_int_exp2(0);
        else
          write_int_exp2(strings.at(current_field->theTypeNamePosInPool-1).final_pos);
      }

      write_int_exp(current_field->theId - this->last_id);

      last_id = current_field->theId;

      if(current_field->theKind != ARCHIVE_FIELD_REFERENCING)
      {
        if(!current_field->theValuePosInPool)
          write_int_exp2(current_field->theValuePosInPool);
        else
          write_int_exp2(strings.at(current_field->theValuePosInPool-1).final_pos);
      }
      else
        write_int(current_field->referencing);
    }

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
    objects_saved++;
    if(current_field->theKind == ARCHIVE_FIELD_PTR)
      nr_ptrs++;
#endif

    if (!current_field->theIsSimple)
    {
      if(current_field->theKind != ARCHIVE_FIELD_REFERENCING)
      {
        serialize_compound_fields(current_field);
#ifndef NDEBUG
        unsigned char tempbyte;
        tempbyte = 0xFF;
        write_bits(tempbyte, 8);
#endif
      }
    }

    current_field = current_field->theNextSibling;
  }

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  //gather statistics for this node
  parent_field->thebytesSaved = bytes_saved - bytes_saved1;
  parent_field->theObjectsSaved = objects_saved - objects_saved1;
#endif
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_string(const char *str)
{
  os->write(str, (std::streamsize)strlen(str)+1);
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  strings_saved += strlen(str)+1;
#endif
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_bit(unsigned char bit)
{
  current_byte <<= 1;
  current_byte |= bit&0x01;
  bitfill++;
  if(bitfill == 8)
  {
    os->write((char*)&current_byte, 1);
    current_byte = 0;
    bitfill = 0;
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
    bytes_saved++;
#endif
  }
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_bits(unsigned int value, unsigned int bits)
{
  while(bits)
  {
    write_bit((value>>(bits-1)) & 0x01);
    bits--;
  }
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_int(unsigned int intval)
{
  //write 7 bits per byte, only significant bits
  unsigned int   shifted_int = (intval >> 7);
  unsigned char tmp;
  while(shifted_int)
  {//little endian
    tmp = intval & 0x7F;
    //os->write((char*)&tmp, 1);
    write_bits(tmp, 8);
    intval = shifted_int;
    shifted_int = (intval >> 7);
  }
  tmp = (intval & 0x7F) | 0x80;
  //os->write((char*)&tmp, 1);
  write_bits(tmp, 8);
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_int_exp(unsigned int intval)
{
  if(intval == 1)
  {
    write_bit(0);
  }
  else if(intval < (1<<4))
  {
    write_bit(1);
    write_bit(0);
    write_bits(intval, 4);
  }
  else if(intval < (1<<13))
  {
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bits(intval, 13);
  }
  else
  {
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bits(intval, 32);
  }
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_int_exp2(unsigned int intval)
{
  if(intval < (1<<4))
  {
    write_bit(0);
    write_bits(intval, 4);
  }
  else if(intval < (1<<12))
  {
    write_bit(1);
    write_bit(0);
    write_bits(intval, 12);
  }
  else if(intval < (1<<20))
  {
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bits(intval, 20);
  }
  else
  {
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bits(intval, 32);
  }
}

////////////reading archive

/*******************************************************************************

********************************************************************************/
void BinArchiver::read_string(std::string &str)
{
  str = (char*)in_current;
  while(*in_current) in_current++;
  in_current++;
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::read_string(char* str)
{
  while(*in_current)
  {
    *str = *in_current;
    in_current++;
    str++;
  }
  *str = 0;
  in_current++;
}


/*******************************************************************************

********************************************************************************/
unsigned char BinArchiver::read_bit()
{
  if(bitfill == 0)
  {
    //is->read((char*)&current_byte, 1);
    in_current++;
    bitfill = 8;
  }
  bitfill--;
  unsigned char result = (*in_current & 0x80) ? 1 : 0;
  *in_current <<= 1;
  return result;
}


/*******************************************************************************

********************************************************************************/
unsigned int BinArchiver::read_bits(unsigned int bits)
{
  unsigned int result = 0;
  while(bits)
  {
  //  result <<= 1;
  //  result |= read_bit();
  //  bits--;
    if(!bitfill)
    {
      //is->read((char*)&current_byte, 1);
      in_current++;
      bitfill = 8;
    }
    if(bitfill <= bits)
    {
      result <<= bitfill;
      result |= *in_current>>(8-bitfill);
      bits -= bitfill;
      bitfill = 0;
    }
    else
    {
      result <<= bits;
      result |= *in_current>>(8-bits);
      bitfill -= bits;
      *in_current <<= bits;
      bits = 0;
    }
  }
  return result;
}


/*******************************************************************************

********************************************************************************/
unsigned int BinArchiver::read_int()
{
  unsigned int outval = 0;
  unsigned char tmp;
  int   i = 0;
  
  do{
    //is->read((char*)&tmp, 1);
    tmp = read_bits(8);
    outval |= ((unsigned int)(tmp&0x7F) << (7*i));
    i++;
  }while(!(tmp & 0x80));

  return outval;
}


/*******************************************************************************

********************************************************************************/
unsigned int BinArchiver::read_int_exp()
{
  unsigned char bit;
  bit = read_bit();
  if(!bit)
  {
    return 1;
  }
  bit = read_bit();
  if(!bit)
    return read_bits(4);
  bit = read_bit();
  if(!bit)
    return read_bits(13);
  else
    return read_bits(32);
}


/*******************************************************************************

********************************************************************************/
unsigned int BinArchiver::read_int_exp2()
{
  unsigned char bit;
  bit = read_bit();
  if(!bit)
  {
    return read_bits(4);
  }
  bit = read_bit();
  if(!bit)
    return read_bits(12);
  bit = read_bit();
  if(!bit)
    return read_bits(20);
  else
    return read_bits(32);

}


/*******************************************************************************

********************************************************************************/
void BinArchiver::read_string_pool()
{
  strings.clear();
  //std::string   str;
  STRING_POS str_pos;
  int   count;
  count = read_int();
  if(bitfill != 8)
  {
    in_current++;
    bitfill = 8;
  }
  for(int i=0;i<count;i++)
  {
    str_pos.str.clear();
    read_string(str_pos.str);
    strings.push_back(str_pos);
  }
  bitfill = 8;
}


/*******************************************************************************

********************************************************************************/
bool BinArchiver::read_next_field_impl(
    char** type, 
    std::string* value,
    int* id, 
    bool* is_simple, 
    bool* is_class,
    enum ArchiveFieldKind* field_treat,
    int* referencing)
{
  if (!is)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION);
  }

  *type = NULL;
  *id = -1; 
#ifndef NDEBUG 
  *is_simple = false; 
  *is_class = false;
  *field_treat = (enum ArchiveFieldKind)-1;
#endif
  *referencing = -1;

#ifndef NDEBUG
  unsigned char  tempbyte;

  tempbyte = read_bits(8);
  if(tempbyte == 0xFF)
    return false;
  *is_simple = tempbyte & 0x01 ? true : false;
  *is_class = tempbyte & 0x02 ? true : false;
  *field_treat = (enum ArchiveFieldKind)((tempbyte>>4)&0x0F);
#else
  //*is_class = read_bit();
  //*field_treat = (enum ArchiveFieldKind)read_bits(3);
  unsigned char small_treat = read_bits(2);

  switch(small_treat)
  {
  case 1: *field_treat = ARCHIVE_FIELD_NULL;break;
  case 2: *field_treat = ARCHIVE_FIELD_REFERENCING;break;
  case 3: *field_treat = ARCHIVE_FIELD_BASECLASS;break;//??
  }
#endif
  assert(*field_treat <= ARCHIVE_FIELD_REFERENCING);

  if(*field_treat != ARCHIVE_FIELD_NULL)
  {
#ifdef NDEBUG
    if(*is_class && (*field_treat == ARCHIVE_FIELD_PTR))
#endif
    {
      unsigned int field_type_pos;
      //read_string(field_type);
      field_type_pos = read_int_exp2();
      if(field_type_pos)
        *type = (char*)strings.at(field_type_pos-1).str.c_str();
      else
        *type = NULL;
    }
    *id = read_int_exp() + this->last_id;
    this->last_id = *id;
    if(*field_treat != ARCHIVE_FIELD_REFERENCING)
    {
      unsigned int value_pos;
      value_pos = read_int_exp2();
      if(value_pos)
       *value = strings.at(value_pos-1).str;
    }
    else
     *referencing = read_int();
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::read_end_current_level_impl()
{
#ifndef NDEBUG
  unsigned char  tempbyte = 0;

  tempbyte = read_bits(8);
  if(tempbyte != 0xFF)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(last_id));
  }
#endif
}


} // namespace serialization
} // namespace zorba
/* vim:set et sw=2 ts=2: */
