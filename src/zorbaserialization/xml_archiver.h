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
#ifndef ZORBA_BINARY_SERIALIZATION_XML_ARCHIVER
#define ZORBA_BINARY_SERIALIZATION_XML_ARCHIVER

#include <iostream>
#include "zorbaserialization/archiver.h"

namespace zorba{
  namespace serialization{

class XmlArchiver : public Archiver
{
  std::istream *is;
  std::ostream *os;
  char   indent_spaces[101];
  int    indent_off;

  int   read_tag_level;
  char  field_type[1000];
  bool  has_attributes;
  bool  is_compound_field_without_children;
  int   last_id;
public:
  XmlArchiver(std::istream *is);
  XmlArchiver(std::ostream *os);

  virtual bool read_next_field_impl( char **type, 
                                std::string *value,
                                int *id, 
                                bool *is_simple, 
                                bool *is_class,
                                enum ArchiveFieldKind *field_treat,
                                int *referencing);

  virtual void read_end_current_level_impl();


///////////////////////////////////
  virtual void serialize_out();


protected:
  //writing
  void serialize_compound_fields(archive_field   *parent_field);
  void encode_string(const char *value);
  const char *get_field_treat_string(enum ArchiveFieldKind field_treat);
  void write_string(const char *str);

  //reading
  bool match_string(char c, const char *match);
  bool read_root_tag(char c);
  bool read_attrib_name(char *attrib_name);
  void read_attrib_value(char *attrib_value);
  void read_attrib_value(std::string *attrib_value);

  void skip_tag();
  void skip_comment_tag();
};

}}

#endif
/* vim:set et sw=2 ts=2: */
