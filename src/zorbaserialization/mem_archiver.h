
#ifndef TEST_ZORBA_SERIALIZATION_ARCHIVER
#define TEST_ZORBA_SERIALIZATION_ARCHIVER

#include "zorbaserialization/archiver.h"
#include "zorbatypes/rchandle.h"
namespace zorba{
  namespace serialization{

class MemArchiver : public Archiver
{
  archive_field *current_field;
  bool  is_after_last;
  archive_field   temp_field;
public:
  MemArchiver(bool is_serializing_out, bool internal_archive=false) : 
        Archiver(is_serializing_out, internal_archive) , temp_field("", false, false, NULL, NULL, 0, ARCHIVE_FIELD_NORMAL, 0)
  {
    current_field = NULL;
    is_after_last = false;
  }

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
  virtual void serialize_out() {}

public:
  void reset_serialize_in();

};

/*
class RCClassSerializer : public SimpleRCObject, public ClassSerializer
{
};
extern rchandle<RCClassSerializer>  g_rc_class_serializer;
*/

}}
#endif
