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
#ifndef ZORBA_BINARY_SERIALIZATION_BINARY_ARCHIVER
#define ZORBA_BINARY_SERIALIZATION_BINARY_ARCHIVER

#include <iostream>

#include "zorbaserialization/archiver.h"

#include "zorbautils/hashmap_str_obj.h"

#include "store/api/shared_types.h"

namespace zorba
{

namespace serialization
{

/*******************************************************************************
  theStrings :
  ------------
  Stores the set of distinct strings that are found in theValue data member of
  all the fields. During serialization, theStrings is populated after the full
  tree of fields has been constructed. Then, the order in which the strings are
  going to be written to disk is determined and the strings are written 
  consecutively according to this order. theDiskPos data member reflects this
  order: the 1st string in disk will have theDiskPos == 1, the 2nd string will
  have theDiskPos == 2, etc. 

  theStringPool :
  -------------
  Maps a string to its position within theStrings vector. It is used during
  serialization only, to enforce the uniqueness of the strings in theStrings.
 
  theOrderedStrings :
  -------------------
  This vector stores an ordering of theStrings, based on their use counts. 
  Specifically, theOrderedStrings[0] points to the string with the highest
  string count, theOrderedStrings[1] points to the string with the 2nd highest
  string count, etc. The string are written to disk in this order.

********************************************************************************/
class BinArchiver : public Archiver
{
protected:
  typedef struct
  {
    const char*  str;
    csize        count;
    csize        theDiskPos;//1 based
  } StringInfo;

protected:
  std::istream             * is;

  std::ostream             * os;

  HashCharPtrObj<csize>      theStringPool;

  std::vector<StringInfo>    theStrings;
  std::vector<csize>         theOrderedStrings;

  unsigned int               last_id;
  unsigned char              theCurrentByte;
  unsigned char              theBitfill;

  unsigned char            * theBuffer;
  unsigned char            * theCurrentBytePtr;
  size_t                     size_read;

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  unsigned int               bytes_saved;
  unsigned int               objects_saved;
  unsigned int               nr_ptrs;
  unsigned int               strings_saved;
#endif

public:
  BinArchiver(std::istream* is);

  BinArchiver(std::ostream* os);

  virtual ~BinArchiver();

  bool read_next_simple_temp_field(char** value);

  bool read_next_field_impl( 
      char** type, 
      char** value,
      int* id,
      bool is_simple,
      bool is_class,
      bool have_value,
      enum ArchiveFieldKind* field_treat,
      int* referencing);

  void read_end_current_level_impl();

  void serialize_out();

protected:
  //writing
  void serialize_out_string_pool();

  void collect_strings(archive_field* parent_field);

  int add_to_string_pool(const char* str);

  void write_string(const char* str, csize len);

  void serialize_compound_fields(archive_field* parent_field);

  void write_bit(unsigned char bit);

  void write_bits(unsigned int value, unsigned int bits);

  void write_int(unsigned int intval);

  void write_int_exp(unsigned int intval);

  void write_int_exp2(unsigned int intval);

  //reading
  void read_string_pool();

  void read_string(const char*& str);

  void read_string(std::string& str);

  unsigned char read_bit();

  unsigned int read_bits(unsigned int bits);

  unsigned int read_int();

  unsigned int read_int_exp();

  unsigned int read_int_exp2();
};

}}

#endif
/* vim:set et sw=2 ts=2: */
