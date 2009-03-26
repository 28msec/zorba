
#ifndef TEST_ZORBA_SERIALIZATION_ARCHIVER
#define TEST_ZORBA_SERIALIZATION_ARCHIVER

#include "zorbaserialization/archiver.h"

namespace zorba{
  namespace serialization{

class MemArchiver : public Archiver
{
  archive_field *current_field;
  bool  is_after_last;
  archive_field   temp_field;
public:
  MemArchiver(bool is_serializing_out) : 
        Archiver(is_serializing_out) , temp_field("", false, false, NULL, NULL, 0, ARCHIVE_FIELD_NORMAL, 0)
  {
    current_field = NULL;
    is_after_last = false;
  }

  virtual bool read_next_field( char **type, 
                                char **value,
                                int *id, 
                                int *version, 
                                bool *is_simple, 
                                bool *is_class,
                                enum ArchiveFieldTreat *field_treat,
                                int *referencing);

  virtual void read_end_current_level();


///////////////////////////////////
  virtual void serialize_out() {}

  virtual bool read_archive_description(char **archive_name,
                                        char **archive_info,
                                        int *archive_version, 
                                        int *nr_ids) 
  {
    return false;
  }
  virtual void close_archive() {}
public:
  void reset_serialize_in();

};

}}
#endif
