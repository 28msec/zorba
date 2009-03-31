
#ifndef ZORBA_BINARY_SERIALIZATION_ARCHIVER
#define ZORBA_BINARY_SERIALIZATION_ARCHIVER

#include "zorbaserialization/class_serializer.h"

namespace zorba{

  namespace serialization{

#define   ARCHIVER_LATEST_VERSION   0x1 //current latest version

#define   FIELD_IS_SIMPLE      true
#define   FIELD_IS_CLASS       true

/*
  Archiver is working with fields. One archive contains a sequence of fields.
  They can be simple fields or combo fields.
  Simple fields: have values of simple types.
  Combo fields: contain a sequence of fields. Are like list, vector, class etc.
  
  Each field has a unique id.

  Special field is a field that points to a previous field. This is to resolve serialization 
  of pointers to the same object.
*/

class ClassSerializer;

struct field_ptr_vs_id
{
  int   field_id;
  //bool  is_class;
  union{
    SerializeBaseClass  *assoc_class_ptr;
    void  *assoc_ptr;
  };
};

struct fwd_ref
{
  int referencing;
  void **ptr;
  bool is_class;
  char *class_name;
};

class archive_field
{
public:
  char  *type;
  bool  is_simple;
  int   version;//for classes
  enum ArchiveFieldTreat  field_treat;
  int   referencing;
  int   id;
  bool  is_class;
  char  *value;//for simple fields
  union{
    SerializeBaseClass  *assoc_class_ptr;
    void  *assoc_ptr;
  };

  class archive_field  *next;
  class archive_field  *first_child;
  class archive_field  *last_child;
  class archive_field  *parent;

public:
  archive_field(const char *type, bool is_simple, bool is_class, 
                void *value, void *assoc_ptr,
                int version, enum ArchiveFieldTreat  field_treat,
                int referencing);
  ~archive_field();
};

enum ArchiveFieldTreat
{
  ARCHIVE_FIELD_NORMAL,
  ARCHIVE_FIELD_IS_PTR,
  ARCHIVE_FIELD_IS_BASECLASS,
  ARCHIVE_FIELD_IS_REFERENCING
};

//base class
class Archiver
{
  friend class ClassSerializer;
protected:
  bool  serializing_out;
  ClassSerializer *ser;

  int  serialize_base_class;

  std::list<struct field_ptr_vs_id>   all_reference_list;
  
  std::list<struct fwd_ref>   fwd_reference_list;

  std::string archive_name;
  std::string archive_info;
  int       archive_version;

  class archive_field  *out_fields;
  class archive_field  *current_compound_field;

  int   nr_ids;
  int   current_class_version;
public:
  Archiver(bool is_serializing_out);
  virtual ~Archiver();

public:

  bool add_simple_field( const char *type, 
                        const char *value,
                        void *orig_ptr,
                        enum ArchiveFieldTreat field_treat);

  bool add_compound_field( const char *type,
                          int version,
                          bool is_class,
                          void *info,
                          void *ptr,//for classes, pointer to SerializeBaseClass
                          enum ArchiveFieldTreat field_treat
                          );

  void add_end_compound_field();

  void set_class_type(const char *class_name);

  //return the id of previous object if it is the same
  archive_field* check_nonclass_pointer(void *ptr);
  archive_field* check_class_pointer(SerializeBaseClass *ptr);
  

  virtual bool read_next_field( char **type, 
                                std::string *value,
                                int *id, 
                                int *version, 
                                bool *is_simple, 
                                bool *is_class,
                                enum ArchiveFieldTreat *field_treat,
                                int *referencing) = 0;

  virtual void read_end_current_level() = 0;


protected:

  virtual void create_archive(const char *archive_name, 
                              const char *archive_info,
                              int archive_version);

  virtual void serialize_out() = 0;

  virtual void read_archive_description(std::string *archive_name,
                                        std::string *archive_info,
                                        int *archive_version, 
                                        int *nr_ids)
  {
    *archive_name = this->archive_name;
    *archive_info = this->archive_info;
    *archive_version = this->archive_version;
    *nr_ids = this->nr_ids;
  }
protected:
  archive_field* check_nonclass_pointer_internal(void *ptr, archive_field *fields);
  archive_field* check_class_pointer_internal(SerializeBaseClass *ptr, archive_field *fields);
  void exchange_fields(archive_field  *new_field, archive_field  *ref_field);

public:
  void check_simple_field(bool retval, 
                                  const char *type,
                                  const char *required_type, 
                                  bool is_simple, 
                                  enum ArchiveFieldTreat  field_treat,
                                  enum ArchiveFieldTreat  required_field_treat,
                                  int id);
  void check_nonclass_field(bool retval, 
                                  const char *type,
                                  const char *required_type, 
                                  bool is_simple, 
                                  bool is_class, 
                                  enum ArchiveFieldTreat  field_treat,
                                  enum ArchiveFieldTreat  required_field_treat,
                                  int id);
  void check_class_field(bool retval, 
                                  const char *type,
                                  const char *required_type, 
                                  bool is_simple, 
                                  bool is_class, 
                                  enum ArchiveFieldTreat  field_treat,
                                  enum ArchiveFieldTreat  required_field_treat,
                                  int id);
  void register_reference(int id, void *ptr);
  void register_delay_reference(void **ptr, bool is_class, const char *class_name, int referencing);
  int Archiver::get_class_version();
  void Archiver::set_class_version(int new_class_version);


  //to help check class name at runtime
  void    set_serialize_base_class(bool serialize_base_class)
  {
    if(serialize_base_class)
      this->serialize_base_class++;
    else
      this->serialize_base_class--;
  }
  bool    is_serialize_base_class()
  {
    return serialize_base_class > 0;
  }
  bool  is_serializing_out()//true out, false in
  {
    return serializing_out;
  }
  ClassSerializer*  get_serializer()
  {
    return ser;
  }
  void *get_reference_value(int refid);
  void finalize_input_serialization();


};

  
}}
#endif
