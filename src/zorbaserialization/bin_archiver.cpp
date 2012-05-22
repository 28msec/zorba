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
#include "zorbaserialization/archiver_field.h"

#include "diagnostics/xquery_diagnostics.h"
#include <fstream>

namespace zorba
{

namespace serialization
{

#define ZORBA_BIN_SERIALIZED_PLAN_STRING    "ZORBA-XQUERY BINARY SERIALIZED PLAN"
#define BUFFER_SEGMENT_SIZE  2*1024*1024


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
  if (!type || !*type)
  {
    os << "unknown";
    return;
  }

  while (*type)
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

  if ((!parent->theIsSimple) && (parent->theKind != ARCHIVE_FIELD_REFERENCING))
  {
    os << ">" << std::endl;
    archive_field   *current_field = parent->first_child;

    while (current_field)
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
BinArchiver::~BinArchiver()
{
  if (theBuffer)
    free(theBuffer);
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  writing archive                                                           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Open archiver for output
********************************************************************************/
BinArchiver::BinArchiver(std::ostream* os)
  :
  Archiver(true),
  theStringPool(false, false)
{
  this->is = NULL;
  this->os = os;
  this->last_id = 0;
  theCurrentByte = 0;
  theBitfill = 0;
  
  theBuffer = NULL;
}


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
  write_uint32(theArchiveVersion);

  write_uint32(theFieldCounter);

#ifndef NDEBUG
  write_uint32(0);//for debug
#else
  write_uint32(1);//for release
#endif

  //first gather all strings in a string pool
  collect_strings(theRootField);

  //now serialize the string pool
  serialize_out_string_pool();

  //now serialize the fields
  serialize_compound_fields(theRootField);

  if (theBitfill)
  {
    theCurrentByte <<= (8-theBitfill);
    os->write((char*)&theCurrentByte, 1);
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
void BinArchiver::collect_strings(archive_field* parent_field)
{
  archive_field* field = parent_field->theFirstChild;

  while (field)
  {
    if (field->theKind != ARCHIVE_FIELD_NULL)
    {
      if (field->theKind != ARCHIVE_FIELD_REFERENCING)
      {
        switch (field->theType)
        {
        case TYPE_INT64:
        case TYPE_UINT64:
        case TYPE_INT32:
        case TYPE_UINT32:
        case TYPE_ENUM:
        case TYPE_INT16:
        case TYPE_UINT16:
        case TYPE_CHAR:
        case TYPE_UCHAR:
        case TYPE_BOOL:
        {
          break;
        }
        default:
        {
          field->theValuePosInPool = add_to_string_pool(field->theValue.cstrv);
        }
        }
      }
    }

    if (!field->theIsSimple)
    {
      if (field->theKind != ARCHIVE_FIELD_REFERENCING)
      {
        collect_strings(field);
      }
    }

    field = field->theNextSibling;
  }
}


/*******************************************************************************

********************************************************************************/
int BinArchiver::add_to_string_pool(const char* str)
{
  if (!str)
    return 0;

  csize strPos = 0;

  if (theStringPool.get(str, strPos))
  {
    StringInfo& str_struct = theStrings.at(strPos-1);
    str_struct.count++;
    return strPos;
  }

  StringInfo  str_struct;
  str_struct.str = str;
  str_struct.count = 1;
  str_struct.theDiskPos = theStrings.size()+1;

  theStrings.push_back(str_struct);

  strPos = theStrings.size();

  theOrderedStrings.push_back(strPos-1);

  theStringPool.insert(str, strPos);

  return strPos;
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::serialize_out_string_pool()
{
  //td::cout << "String pool size = " << theStrings.size() << std::endl;

#if 1
  //sort strings based on use count
  csize i, j;
  for (i = 0; i < theOrderedStrings.size(); ++i)
  {
    for (j = i+1; j < theOrderedStrings.size(); ++j)
    {
      if (theStrings.at(theOrderedStrings[i]).count <
          theStrings.at(theOrderedStrings[j]).count)
      {
        unsigned int temp;
        temp = theOrderedStrings[i];
        theOrderedStrings[i] = theOrderedStrings[j];
        theOrderedStrings[j] = temp;
      }
    }
  }

  //std::cout << std::endl;

  for (i = 0; i < theOrderedStrings.size(); ++i)
  {
    theStrings.at(theOrderedStrings[i]).theDiskPos = i+1;

    //std::cout << i << ": " << theStrings.at(theOrderedStrings[i]).str << std::endl;
  }
#endif

  write_uint32((uint32_t)theStrings.size());

  if (theBitfill)
  {
    theCurrentByte <<= (8-theBitfill);
    os->write((char*)&theCurrentByte, 1);
    theBitfill = 0;
    theCurrentByte = 0;
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
    bytes_saved++;
#endif
  }

  std::vector<csize>::const_iterator ite = theOrderedStrings.begin();
  std::vector<csize>::const_iterator end = theOrderedStrings.end();
  for (; ite != end; ++ite)
  {
    const StringInfo& strInfo = theStrings.at(*ite);

    write_string(strInfo.str, strlen(strInfo.str) + 1);
  }
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_string(const char* str, csize len)
{
  os->write(str, (std::streamsize)len);
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  strings_saved += len;
#endif
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::serialize_compound_fields(archive_field* parent_field)
{
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  unsigned int bytes_saved1 = bytes_saved;
  unsigned int objects_saved1 = objects_saved;
#endif
  archive_field* field = parent_field->theFirstChild;

  while (field)
  {
    if (field->theId == 0)
    {
      switch (field->theType)
      {
      case TYPE_INT64:
      {
        write_int64(field->theValue.int64v);
        break;
      }
      case TYPE_UINT64:
      {
        write_uint64(field->theValue.uint64v);
        break;
      }
      case TYPE_INT32:
      {
        write_uint32(field->theValue.int32v);
        break;
      }
      case TYPE_UINT32:
      {
        write_uint32(field->theValue.uint32v);
        break;
      }
      case TYPE_ENUM:
      {
        write_enum(field->theValue.uint32v);
        break;
      }
      case TYPE_INT16:
      {
        write_uint32(field->theValue.int16v);
        break;
      }
      case TYPE_UINT16:
      {
        write_uint32(field->theValue.uint16v);
        break;
      }
      case TYPE_CHAR:
      {
        write_bits(field->theValue.charv, 8);
        break;
      }
      case TYPE_UCHAR:
      {
        write_bits(field->theValue.ucharv, 8);
        break;
      }
      case TYPE_BOOL:
      {
        write_bit(field->theValue.boolv ? 1 : 0);
        break;
      }
      default:
      {
        if (field->theValuePosInPool)
        {
          write_int_exp2(theStrings.at(field->theValuePosInPool-1).theDiskPos);
        }
      }
      }
    }
    else
    {
      unsigned char small_treat = 0;
      switch (field->theKind)
      {
      case ARCHIVE_FIELD_NULL:          small_treat = 1; break;
      case ARCHIVE_FIELD_REFERENCING:   small_treat = 2; break;
      case ARCHIVE_FIELD_BASECLASS:     small_treat = 3; break;//??
      default: break;
      }

      write_bits(small_treat, 2);

      if (field->theKind != ARCHIVE_FIELD_NULL)
      {
        if (field->theIsClass && field->theKind == ARCHIVE_FIELD_PTR)
        {
          assert(field->theType != TYPE_LAST);

          write_enum(field->theType);
        }

        if (field->theId)
          write_int_exp(field->theId - this->last_id);

        last_id = field->theId;

        if (field->theKind != ARCHIVE_FIELD_REFERENCING)
        {
          if (field->theValuePosInPool)
            write_int_exp2(theStrings.at(field->theValuePosInPool-1).theDiskPos);
        }
        else
        {
          //write_int_exp2(field->referencing);
          write_uint32(field->referencing);
        }
      }
    }

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
    objects_saved++;
    if (field->theKind == ARCHIVE_FIELD_PTR)
      nr_ptrs++;
#endif

    if (!field->theIsSimple)
    {
      if (field->theKind != ARCHIVE_FIELD_REFERENCING)
      {
        serialize_compound_fields(field);
#ifndef NDEBUG
        unsigned char tempbyte;
        tempbyte = 0xFF;
        write_bits(tempbyte, 8);
#endif
      }
    }

    field = field->theNextSibling;
  }

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  parent_field->thebytesSaved = bytes_saved - bytes_saved1;
  parent_field->theObjectsSaved = objects_saved - objects_saved1;
#endif
}


/*******************************************************************************
  Pack 7 bits of the intval into a byte, and set the high-order bit of that
  byte to 0, unless it is the last byte to be written, in which case its
  high-order bit is set to 1, signifying the end of the number.
********************************************************************************/
void BinArchiver::write_int64(int64_t intval)
{
  if (intval < 0)
  {
    write_bit(1);
    uint64_t absval = -intval;

    write_uint64(absval);
  }
  else
  {
    write_bit(0);
    write_uint64((uint64_t)intval);
  }
}


void BinArchiver::write_uint64(uint64_t intval)
{
  uint64_t shifted_int = (intval >> 7);
  unsigned char tmp;

  while (shifted_int)
  {
    tmp = intval & 0x7F;

    write_bits(tmp, 8);

    intval = shifted_int;
    shifted_int = (intval >> 7);
  }

  tmp = (intval & 0x7F) | 0x80;

  write_bits(tmp, 8);
}


void BinArchiver::write_uint32(uint32_t intval)
{
  uint32_t shifted_int = (intval >> 7);
  unsigned char tmp;

  while (shifted_int)
  {
    tmp = intval & 0x7F;

    write_bits(tmp, 8);

    intval = shifted_int;
    shifted_int = (intval >> 7);
  }

  tmp = (intval & 0x7F) | 0x80;

  write_bits(tmp, 8);
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_int_exp(unsigned int intval)
{
  if (intval == 1)
  {
    write_bit(0);
  }
  else if (intval < (1<<4))
  {
    write_bit(1);
    write_bit(0);
    write_bits(intval, 4);
  }
  else if (intval < (1<<13))
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
  if (intval < (1<<4))
  {
    write_bit(0);
    write_bits(intval, 4);
  }
  else if (intval < (1<<12))
  {
    write_bit(1);
    write_bit(0);
    write_bits(intval, 12);
  }
  else if (intval < (1<<20))
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


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_enum(unsigned int intval)
{
  if (intval < (1 << 5))
  {
    write_bit(0);
    write_bits(intval, 5);
  }
  else if (intval < (1 << 8))
  {
    write_bit(1);
    write_bit(0);
    write_bits(intval, 8);
  }
  else if (intval < (1 << 13))
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
void BinArchiver::write_bits(unsigned int value, unsigned int bits)
{
  while (bits)
  {
    write_bit((value >> (bits-1)));
    --bits;
  }
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::write_bit(unsigned char bit)
{
  theCurrentByte <<= 1;
  theCurrentByte |= (bit & 0x01);
  ++theBitfill;

  if (theBitfill == 8)
  {
    os->write((char*)&theCurrentByte, 1);
    theCurrentByte = 0;
    theBitfill = 0;
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
    bytes_saved++;
#endif
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  reading archive                                                           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Open archiver for input
********************************************************************************/
BinArchiver::BinArchiver(std::istream* is) 
  :
  Archiver(false),
  theStringPool(false, false)
{
  this->is = is;
  this->os = NULL;
  this->last_id = 0;
  theCurrentByte = 0;
  theBitfill = 8;

  //read the plan serializer info
  char	preface_string[200];
  unsigned int	preface_len = 0;

  while (preface_len < sizeof(preface_string))
  {
	  is->read(preface_string + preface_len, 1);
	  if (is->gcount() < 1)
	  {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
	  }

    if (preface_string[preface_len] == 0)
      break;

    preface_len++;
  }

  if (strcmp(preface_string, ZORBA_BIN_SERIALIZED_PLAN_STRING))
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
  }

  theBuffer = (unsigned char*)malloc(BUFFER_SEGMENT_SIZE);
  size_read = 0;

  while (1)
  {
    is->read((char*)theBuffer + size_read, BUFFER_SEGMENT_SIZE);
    size_read += (size_t)is->gcount();

    if (is->gcount() == BUFFER_SEGMENT_SIZE)
    {
      theBuffer = (unsigned char*)realloc(theBuffer, size_read + BUFFER_SEGMENT_SIZE);
    }
    else
    {
      break;
    }
  }

  theCurrentBytePtr = theBuffer;

  read_string(theArchiveName);
  read_string(theArchiveInfo);
  theArchiveVersion = read_uint32();
  theFieldCounter = read_uint32();
  unsigned int is_release = read_uint32();
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

********************************************************************************/
void BinArchiver::read_string_pool()
{
  theStrings.clear();

  csize count = read_uint32();

  if (theBitfill != 8)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }

  StringInfo str_pos;

  for (csize i = 0; i < count; ++i)
  {
    read_string(str_pos.str);

    theStrings.push_back(str_pos);
  }

  theBitfill = 8;
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::read_string(const char*& str)
{
  str = (char*)theCurrentBytePtr;

  while(*theCurrentBytePtr)
  {
    ++theCurrentBytePtr;
  }

  ++theCurrentBytePtr;
}


/*******************************************************************************

********************************************************************************/
void BinArchiver::read_string(std::string& str)
{
  str = (char*)theCurrentBytePtr;

  while (*theCurrentBytePtr)
    ++theCurrentBytePtr;

  theCurrentBytePtr++;
}


/*******************************************************************************

********************************************************************************/
int64_t BinArchiver::read_int64()
{
  unsigned char sign = read_bit();

  if (sign == 0)
  {
    return static_cast<int64_t>(read_uint64());
  }
  else
  {
    uint64_t absval = read_uint64();
    return -static_cast<int64_t>(absval);
  }
}


uint64_t BinArchiver::read_uint64()
{
  uint64_t outval = 0;
  unsigned char tmp;
  int i = 0;
  
  do
  {
    tmp = read_bits(8);
    outval |= ((uint64_t)(tmp & 0x7F) << (7*i));
    ++i;
  }
  while(!(tmp & 0x80));

  return outval;
}


/*******************************************************************************
  used for reading a referring id
********************************************************************************/
uint32_t BinArchiver::read_uint32()
{
  uint32_t outval = 0;
  unsigned char tmp;
  int i = 0;
  
  do
  {
    tmp = read_bits(8);
    outval |= ((unsigned int)(tmp & 0x7F) << (7*i));
    ++i;
  }
  while(!(tmp & 0x80));

  return outval;
}


/*******************************************************************************

********************************************************************************/
unsigned char BinArchiver::read_bit()
{
  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }

  --theBitfill;
  unsigned char result = (*theCurrentBytePtr & 0x80) ? 1 : 0;
  *theCurrentBytePtr <<= 1;
  return result;
}


/*******************************************************************************

********************************************************************************/
unsigned int BinArchiver::read_bits(unsigned int bits)
{
  unsigned int result = 0;

  while (bits)
  {
    if (!theBitfill)
    {
      ++theCurrentBytePtr;
      theBitfill = 8;
    }

    if (theBitfill <= bits)
    {
      result <<= theBitfill;
      result |= *theCurrentBytePtr >> (8-theBitfill);
      bits -= theBitfill;
      theBitfill = 0;
    }
    else
    {
      result <<= bits;
      result |= *theCurrentBytePtr >> (8 - bits);
      theBitfill -= bits;
      *theCurrentBytePtr <<= bits;
      bits = 0;
    }
  }
  return result;
}


/*******************************************************************************
  used for reading the field id. Optimized for the numer 1
********************************************************************************/
unsigned int BinArchiver::read_int_exp()
{
  unsigned char bit;

  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }

  // read bit
  bit = (*theCurrentBytePtr & 0x80);

  --theBitfill;
  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }
  else
  {
    *theCurrentBytePtr <<= 1;
  }

  if (!bit)
    return 1;

  // read bit
  bit = (*theCurrentBytePtr & 0x80);

  --theBitfill;
  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }
  else
  {
    *theCurrentBytePtr <<= 1;
  }

  if (!bit)
    return read_bits(4);

  // read bit
  bit = (*theCurrentBytePtr & 0x80);

  --theBitfill;
  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }
  else
  {
    *theCurrentBytePtr <<= 1;
  }

  if (!bit)
    return read_bits(13);
  else
    return read_bits(32);
}


/*******************************************************************************
  used for reading the position of the field value
********************************************************************************/
unsigned int BinArchiver::read_int_exp2()
{
  unsigned char bit;

  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }

  // read bit
  bit = (*theCurrentBytePtr & 0x80);

  --theBitfill;
  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }
  else
  {
    *theCurrentBytePtr <<= 1;
  }

  if (!bit)
    return read_bits(4);

  // read bit
  bit = (*theCurrentBytePtr & 0x80);

  --theBitfill;
  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }
  else
  {
    *theCurrentBytePtr <<= 1;
  }

  if (!bit)
    return read_bits(12);

  // read bit
  bit = (*theCurrentBytePtr & 0x80);

  --theBitfill;
  if (theBitfill == 0)
  {
    ++theCurrentBytePtr;
    theBitfill = 8;
  }
  else
  {
    *theCurrentBytePtr <<= 1;
  }

  if (!bit)
    return read_bits(20);
  else
    return read_bits(32);
}


/*******************************************************************************

********************************************************************************/
unsigned int BinArchiver::read_enum()
{
  unsigned char bit;

  bit = read_bit();

  if (!bit)
    return read_bits(5);

  bit = read_bit();

  if (!bit)
    return read_bits(8);

  bit = read_bit();

  if(!bit)
    return read_bits(13);
  else
    return read_bits(32);
}


/*******************************************************************************

********************************************************************************/
bool BinArchiver::read_next_simple_temp_field(SimpleValue& value, TypeCode type)
{
  if (!is)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION);
  }

  switch (type)
  {
  case TYPE_INT64:
  {
    value.int64v = read_int64();
    break;
  }
  case TYPE_UINT64:
  {
    value.uint64v = read_uint64();
    break;
  }
  case TYPE_INT32:
  {
    value.int32v = read_uint32();
    break;
  }
  case TYPE_UINT32:
  {
    value.uint32v = read_uint32();
    break;
  }
  case TYPE_ENUM:
  {
    value.uint32v = read_enum();
    break;
  }
  case TYPE_INT16:
  {
    value.int16v = read_uint32();
    break;
  }
  case TYPE_UINT16:
  {
    value.uint16v = read_uint32();
    break;
  }
  case TYPE_CHAR:
  {
    value.charv = read_bits(8);
    break;
  }
  case TYPE_UCHAR:
  {
    value.ucharv = read_bits(8);
    break;
  }
  case TYPE_BOOL:
  {
    value.boolv = (char*)read_bit();
    break;
  }
  default:
  {
    unsigned int value_pos = read_int_exp2();
    assert(value_pos);
    value.cstrv = (char*)theStrings.at(value_pos-1).str;
  }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool BinArchiver::read_next_field_impl(
    TypeCode& type, 
    char** value,
    int* id,
    bool is_simple,
    bool is_class,
    bool have_value,
    ArchiveFieldKind* field_treat,
    int* referencing)
{
  if (!is)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION);
  }

  type = TYPE_LAST;
  *value = NULL;
  *id = -1;
  *referencing = -1; 

  unsigned char small_treat = read_bits(2);

  switch (small_treat)
  {
  case 1: *field_treat = ARCHIVE_FIELD_NULL; break;
  case 2: *field_treat = ARCHIVE_FIELD_REFERENCING; break;
  case 3: *field_treat = ARCHIVE_FIELD_BASECLASS; break;//??
  }

  assert(*field_treat <= ARCHIVE_FIELD_REFERENCING);

  if (*field_treat != ARCHIVE_FIELD_NULL)
  {
    if (is_class && (*field_treat == ARCHIVE_FIELD_PTR))
    {
      unsigned int tmp = read_enum();
      assert(tmp <= TYPE_LAST);

      type = static_cast<TypeCode>(tmp);
    }

    *id = read_int_exp() + this->last_id;
    this->last_id = *id;

    if (*field_treat != ARCHIVE_FIELD_REFERENCING)
    {
      if (have_value)
      {
        unsigned int value_pos = read_int_exp2();
        assert(value_pos);
        *value = (char*)theStrings.at(value_pos-1).str;
      }
    }
    else
    {
      //*referencing = read_int_exp2();
      *referencing = read_uint32();
    }
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
  if (tempbyte != 0xFF)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, 
    ERROR_PARAMS(last_id));
  }
#endif
}


} // namespace serialization
} // namespace zorba
/* vim:set et sw=2 ts=2: */
