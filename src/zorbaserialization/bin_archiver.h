
#ifndef ZORBA_BINARY_SERIALIZATION_BINARY_ARCHIVER
#define ZORBA_BINARY_SERIALIZATION_BINARY_ARCHIVER

#include <iostream>
#include "zorbaserialization/archiver.h"

namespace zorba{
  namespace serialization{

class BinArchiver : public Archiver
{
  std::istream *is;
  std::ostream *os;

//  int   read_tag_level;
  char  field_type[1000];
  bool  has_attributes;
  bool  is_compound_field_without_children;
public:
  BinArchiver(std::istream *is);
  BinArchiver(std::ostream *os);

  virtual bool read_next_field( char **type, 
                                std::string *value,
                                int *id, 
                                int *version, 
                                bool *is_simple, 
                                bool *is_class,
                                enum ArchiveFieldTreat *field_treat,
                                int *referencing);

  virtual void read_end_current_level();


///////////////////////////////////
  virtual void serialize_out();


protected:
  //writing
  void serialize_compound_fields(archive_field   *parent_field);
  //void encode_string(const char *value);
  //const char *get_field_treat_string(enum ArchiveFieldTreat field_treat);
  void write_string(const char *str);
  void write_int(const int intval);

  //reading
  void read_string(std::string &str);
  void read_string(char* str);
  int  read_int();
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
