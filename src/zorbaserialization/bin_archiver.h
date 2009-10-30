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

#ifndef ZORBA_BINARY_SERIALIZATION_BINARY_ARCHIVER
#define ZORBA_BINARY_SERIALIZATION_BINARY_ARCHIVER

#include <iostream>
#include "zorbaserialization/archiver.h"
#include "zorbautils/hashmap_str_obj.h"

namespace zorba{
  namespace serialization{

class BinArchiver : public Archiver
{
  std::istream *is;
  std::ostream *os;

//  int   read_tag_level;
//  char  field_type[1000];
  bool  has_attributes;
  bool  is_compound_field_without_children;

  HashCharPtrObj<int>    string_pool;
  std::vector<std::string>    strings;
public:
  BinArchiver(std::istream *is);
  BinArchiver(std::ostream *os);
  virtual ~BinArchiver();

  virtual bool read_next_field_impl( char **type, 
                                std::string *value,
                                int *id, 
                                int *version, 
                                bool *is_simple, 
                                bool *is_class,
                                enum ArchiveFieldTreat *field_treat,
                                int *referencing);

  virtual void read_end_current_level_impl();


///////////////////////////////////
  virtual void serialize_out();


protected:
  //writing
  int add_to_string_pool(const char *str);
  void collect_strings(archive_field   *parent_field);
  void serialize_out_string_pool();
  void serialize_compound_fields(archive_field   *parent_field);
  //void encode_string(const char *value);
  //const char *get_field_treat_string(enum ArchiveFieldTreat field_treat);
  void write_string(const char *str);
  void write_int(unsigned int intval);

  //reading
  void read_string(std::string &str);
  void read_string(char* str);
  unsigned int  read_int();
  void read_string_pool();
  //bool match_string(char c, const char *match);
  bool read_root_tag(char c);
  //bool read_attrib_name(char *attrib_name);
  //void read_attrib_value(char *attrib_value);
  //void read_attrib_value(std::string *attrib_value);

  //void skip_tag();
  //void skip_comment_tag();
};

}}

#endif
