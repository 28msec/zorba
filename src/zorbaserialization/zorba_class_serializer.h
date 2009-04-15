
#ifndef ZORBA_SPECIFIC_CLASS_SERIALIZATION
#define ZORBA_SPECIFIC_CLASS_SERIALIZATION

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"
//#include "zorbaerrors/error_manager.h"

#include "zorbatypes/rchandle.h"
#include "zorbautils/checked_vector.h"
#include "store/api/shared_types.h"
#include "zorbatypes/m_apm.h"

namespace zorba{
  class XQType;

  namespace serialization{
void operator&(Archiver &ar, XQType *&obj);
void operator&(Archiver &ar, const XQType *&obj);
void operator&(Archiver &ar, MAPM &obj);

void operator&(Archiver &ar, XQPCollator *&obj);

//void serialize_qname(Archiver &ar, store::Item_t &qname);

#define SERIALIZE_TYPEMANAGER(type_mgr_type, type_mgr)                             \
  bool is_root_type_mgr = (type_mgr == (TypeManager*)&GENV_TYPESYSTEM);            \
  ar.set_is_temp_field(true);                                       \
  ar & is_root_type_mgr;                                            \
  ar.set_is_temp_field(false);                                      \
  if(is_root_type_mgr)                                              \
  {                                                                 \
    if(!ar.is_serializing_out())                                    \
     type_mgr = (type_mgr_type*)&GENV_TYPESYSTEM;                   \
  }                                                                 \
  else                                                              \
  {                                                                 \
    ar & type_mgr;                                                  \
  }

template<class T>
void operator&(Archiver &ar, checked_vector<T> &obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
    sprintf(strtemp, "%d", obj.size());
    bool is_ref;
    is_ref = ar.add_compound_field("checked_vector<T>", 0, !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      checked_vector<T>::iterator  it;
      for(it=obj.begin(); it != obj.end(); it++)
      {
        ar & (*it);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "checked_vector<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    int size;
    sscanf(value.c_str(), "%d", &size);
    obj.resize(size);
    checked_vector<T>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}

template<class T>
void operator&(Archiver &ar, zorba::rchandle<T> &obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("rchandle<T>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      T *p = obj.getp();
      ar & p;
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "rchandle<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    T *p;
    ar & p;
    obj = p;
    ar.read_end_current_level();

  }
}

template<class T>
void operator&(Archiver &ar, zorba::const_rchandle<T> &obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("const_rchandle<T>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      T *p = (T*)obj.getp();
      ar & p;
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "const_rchandle<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    T *p;
    ar & p;
    obj = p;
    ar.read_end_current_level();

  }
}



}}
#endif
