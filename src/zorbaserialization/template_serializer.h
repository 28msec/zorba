
#ifndef TEMPLATE_SERIALIZATION_OPERATORS
#define TEMPLATE_SERIALIZATION_OPERATORS

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"
#include "zorbaerrors/error_manager.h"

namespace zorba{
  namespace serialization{
/////////////////////////////templates

template<class T>
void operator&(Archiver &ar, std::list<T> &obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
    sprintf(strtemp, "%d", obj.size());
    bool is_ref;
    is_ref = ar.add_compound_field("std::list<T>", 0, !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      std::list<T>::iterator  it;
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
    char  *value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    ar.check_nonclass_field(retval, type, "std::list<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, &obj);

    int i;
    int size;
    sscanf(value, "%d", &size);
    obj.resize(size);
    std::list<T>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}

template<class T>
void operator&(Archiver &ar, std::vector<T> &obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
    sprintf(strtemp, "%d", obj.size());
    bool is_ref;
    is_ref = ar.add_compound_field("std::vector<T>", 0, !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      std::vector<T>::iterator  it;
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
    char  *value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    ar.check_nonclass_field(retval, type, "std::vector<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, &obj);

    int i;
    int size;
    sscanf(value, "%d", &size);
    obj.resize(size);
    std::vector<T>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}


template<class T>
void operator&(Archiver &ar, T &obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
    sprintf(strtemp, "%d", 0);
    bool is_ref;
    
    is_ref = ar.add_compound_field(typeid(obj).name()+6, 
                                    T::class_versions[T::class_versions_count-1].class_version, 
                                    FIELD_IS_CLASS, strtemp, 
                                    (SerializeBaseClass*)&obj, 
                                    ar.is_serialize_base_class() ? ARCHIVE_FIELD_IS_BASECLASS : ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      obj.serialize_internal(ar);
      ar.add_end_compound_field();
    }
  }
  else
  {
    int prev_class_version = ar.get_class_version();
    char  *type;
    char  *value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    ar.check_class_field(retval, type, typeid(obj).name()+6, is_simple, is_class, field_treat, 
                          ar.is_serialize_base_class() ? ARCHIVE_FIELD_IS_BASECLASS : ARCHIVE_FIELD_NORMAL, 
                          id);
    ar.set_class_version(version);
    ar.register_reference(id, (SerializeBaseClass*)&obj);

    //check the version
    int v;
    if(version > T::class_versions[T::class_versions_count-1].class_version)
    {
      ZORBA_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << typeid(obj).name()+6 << " is " << version  << "while the version supported is " << T::class_versions[T::class_versions_count-1].class_version);
    }
    for(v = T::class_versions_count-1; v >= 0; v--)
    {
      if(version == T::class_versions[v].class_version)
        break;//supported version
      else if((version < T::class_versions[v].class_version) && !T::class_versions[v].is_backward_compatible)
      {
        int   oldv;
        for(oldv = v; oldv >= 0; oldv--)
        {
          if(version == T::class_versions[oldv].class_version)
            break;
        }
        if(oldv < 0)
          oldv = 0;
        
        ZORBA_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
                        "Class version for " << typeid(obj).name()+6 << " is " << version 
                        << " while the minimal supported version is " << T::class_versions[v].class_version 
                        << ". Use Zorba 0x" << std::hex << T::class_versions[oldv].zorba_version << "instead.");
      }
              
    }

    obj.serialize_internal(ar);

    ar.read_end_current_level();

    ar.set_class_version(prev_class_version);
  }
}

template<class T>
void operator&(Archiver &ar, T *&obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
    sprintf(strtemp, "%d", 0);
    bool is_ref;
    
    is_ref = ar.add_compound_field(ar.is_serialize_base_class() ? typeid(T).name()+6 : typeid(*obj).name()+6, 
                                    ar.is_serialize_base_class() ? T::class_versions[T::class_versions_count-1].class_version : obj->get_classversion(obj->get_version_count()-1).class_version , 
                                    FIELD_IS_CLASS, strtemp, 
                                    (SerializeBaseClass*)obj, 
                                    ar.is_serialize_base_class() ? ARCHIVE_FIELD_IS_BASECLASS : ARCHIVE_FIELD_IS_PTR);
    if(!is_ref)
    {
      if(!ar.is_serialize_base_class())
      {
        obj->serialize_internal(ar);
      }
      else
      {
        obj->T::serialize_internal(ar);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    int prev_class_version = ar.get_class_version();
    char  *type;
    char  *value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    ar.check_class_field(retval, "", "", is_simple, is_class, (ArchiveFieldTreat)0, (ArchiveFieldTreat)0, id);
    ar.set_class_version(version);



    if(ar.is_serialize_base_class())
    {
      if(strcmp(type, typeid(T).name()+6))
      {
        ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
      if(field_treat != ARCHIVE_FIELD_IS_BASECLASS)
      {
        ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
    {
      if((field_treat != ARCHIVE_FIELD_IS_PTR) && (field_treat != ARCHIVE_FIELD_IS_REFERENCING))
      {
        ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }

    SerializeBaseClass  *new_obj = NULL;
    if(field_treat == ARCHIVE_FIELD_IS_PTR)
    {
      class_deserializer  *cls_factory;
      cls_factory = g_class_serializer->get_class_factory(type);
      if(cls_factory == NULL)
      {
         ZORBA_ERROR_DESC_OSS(SRL0003_UNRECOGNIZED_CLASS_FIELD, id);
      }
      new_obj = cls_factory->create_new(ar);
      obj = dynamic_cast<T*>(new_obj);
      if(!obj)
      {
        ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }

      //check the version
      int v;
      if(version > obj->get_classversion(obj->get_version_count()-1).class_version)
      {
        ZORBA_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << typeid(*obj).name()+6 << " is " << version  << "while the version supported is " << obj->get_classversion(obj->get_version_count()-1).class_version);
      }
      for(v = obj->get_version_count()-1; v >= 0; v--)
      {
        ClassVersion  &ver = obj->get_classversion(v);
        if(version == ver.class_version)
          break;//supported version
        else if((version < ver.class_version) && !ver.is_backward_compatible)
        {
          int oldv;
          for(oldv = v; oldv >= 0; oldv--)
          {
            if(version == obj->get_classversion(oldv).class_version)
              break;
          }
          if(oldv < 0)
            oldv = 0;
          
          ZORBA_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
                          "Class version for " << typeid(*obj).name()+6 << " is " << version 
                          << " while the minimal supported version is " << ver.class_version 
                          << ". Use Zorba 0x" << std::hex << obj->get_classversion(oldv).zorba_version << "instead.");
        }
                
      }


      ar.register_reference(id, new_obj);
      new_obj->serialize_internal(ar);
      ar.read_end_current_level();
    }
    else if(field_treat == ARCHIVE_FIELD_IS_BASECLASS)
    {
      //check the version
      int v;
      if(version > T::class_versions[T::class_versions_count-1].class_version)
      {
        ZORBA_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << typeid(T).name()+6 << " is " << version  << "while the version supported is " << T::class_versions[T::class_versions_count-1].class_version);
      }
      for(v = T::class_versions_count-1; v >= 0; v--)
      {
        if(version == T::class_versions[v].class_version)
          break;//supported version
        else if((version < T::class_versions[v].class_version) && !T::class_versions[v].is_backward_compatible)
        {
          int oldv;
          for(oldv = v; oldv >= 0; oldv--)
          {
            if(version == T::class_versions[oldv].class_version)
              break;
          }
          if(oldv < 0)
            oldv = 0;
          
          ZORBA_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
                          "Class version for " << typeid(T).name()+6 << " is " << version 
                          << " while the minimal supported version is " << T::class_versions[v].class_version 
                          << ". Use Zorba 0x" << std::hex << T::class_versions[oldv].zorba_version << "instead.");
        }
                
      }

      obj->T::serialize_internal(ar);
      ar.read_end_current_level();
    }
    else if((id > referencing) && (new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      obj = dynamic_cast<T*>(new_obj);
      if(!obj)
      {
        ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
      ar.register_delay_reference((void**)&obj, FIELD_IS_CLASS, typeid(T).name()+6, referencing);
    ar.set_class_version(prev_class_version);
  }
}


template<class T>
void serialize_baseclass(Archiver &ar, T *obj)
{
  ar.set_serialize_base_class(true);

  ar & obj;

  ar.set_serialize_base_class(false);
}

}}
#endif

