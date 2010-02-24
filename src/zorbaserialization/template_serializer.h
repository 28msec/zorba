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

#ifndef TEMPLATE_SERIALIZATION_OPERATORS
#define TEMPLATE_SERIALIZATION_OPERATORS

#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <stdio.h>

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"


namespace zorba
{
namespace serialization
{
/////////////////////////////templates

#define ZORBA_SER_ERROR_DESC_OSS(code, desc)                            \
  do                                                                    \
  {                                                                     \
    std::ostringstream lOStringStream;                                  \
    lOStringStream << desc;                                             \
    ::zorba::serialization::report_error(code, lOStringStream.str(),    \
                 __FILE__, __LINE__);                                   \
  }while(0);

template<typename T>
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
      typename std::list<T>::iterator  it;
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
    ar.check_nonclass_field(retval, type, "std::list<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    int size;
    sscanf(value.c_str(), "%d", &size);
    obj.resize(size);
    typename std::list<T>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}

template<typename T>
void operator&(Archiver &ar, std::vector<T> &obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
    sprintf(strtemp, "%d", (int)obj.size());
    bool is_ref;
    is_ref = ar.add_compound_field("std::vector<T>", 0, !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      typename std::vector<T>::iterator  it;
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
    ar.check_nonclass_field(retval, type, "std::vector<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    int size;
    sscanf(value.c_str(), "%d", &size);
    obj.resize(size);
    typename std::vector<T>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}

template<typename T>
void operator&(Archiver &ar, std::vector<T> *&obj)
{
  if(ar.is_serializing_out())
  {
    if((obj == NULL))
    {
      ar.add_compound_field("NULL", 
                            1 ,//class_version
                            !FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_IS_NULL);
      return;
    }
    char  strtemp[20];
    sprintf(strtemp, "%d", (int)obj->size());
    bool is_ref;
    is_ref = ar.add_compound_field("std::vector<T>*", 0, !FIELD_IS_CLASS, strtemp, obj, ARCHIVE_FIELD_IS_PTR);
    if(!is_ref)
    {
      typename std::vector<T>::iterator  it;
      for(it=obj->begin(); it != obj->end(); it++)
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
    ar.check_nonclass_field(retval, type, "std::vector<T>*", is_simple, is_class, field_treat, (ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    void *new_obj;
    if(field_treat == ARCHIVE_FIELD_IS_PTR)
    {
      obj = new std::vector<T>;
      ar.register_reference(id, field_treat, obj);

      int size;
      sscanf(value.c_str(), "%d", &size);
      obj->resize(size);
      typename std::vector<T>::iterator  it;
      for(it=obj->begin(); it != obj->end(); it++)
      {
        ar & (*it);
      }
      ar.read_end_current_level();
    }
    else if((new_obj = ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      obj = (std::vector<T>*)new_obj;
      if(!obj)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "std::vector<T>*", referencing);
  }
}

template<typename T>
void operator&(Archiver &ar, std::vector<T*> &obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
    sprintf(strtemp, "%d", (int)obj.size());
    bool is_ref;
    is_ref = ar.add_compound_field("std::vector<T*>", 0, !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      typename std::vector<T*>::iterator  it;
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
    ar.check_nonclass_field(retval, type, "std::vector<T*>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    int size;
    sscanf(value.c_str(), "%d", &size);
    obj.resize(size);
    typename std::vector<T*>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}

template<typename T1, typename T2>
void operator&(Archiver &ar, std::pair<T1, T2> &obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("std::pair<T1, T2>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar & obj.first;
      ar & obj.second;
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
    ar.check_nonclass_field(retval, type, "std::pair<T1, T2>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    ar & obj.first;
    ar & obj.second;
    ar.read_end_current_level();

  }
}

template<typename T1, typename T2>
void operator&(Archiver &ar, std::map<T1, T2> *&obj)
{
  if(ar.is_serializing_out())
  {
    if((obj == NULL))
    {
      ar.add_compound_field("NULL", 
                            1 ,//class_version
                            !FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_IS_NULL);
      return;
    }
    bool is_ref;
    is_ref = ar.add_compound_field("std::map<T1, T2>", 0, !FIELD_IS_CLASS, "", obj, ARCHIVE_FIELD_IS_PTR);
    if(!is_ref)
    {
      ar.set_is_temp_field_one_level(true);
      int s = (int)obj->size();
      ar & s;
      typename std::map<T1, T2>::iterator  it;
      for(it=obj->begin(); it != obj->end(); it++)
      {
        ar.dont_allow_delay();
        T1  t1 = (*it).first;
        ar & t1;
        ar.dont_allow_delay();
        ar & (*it).second;
      }
      ar.set_is_temp_field_one_level(true);
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
    ar.check_nonclass_field(retval, type, "std::map<T1, T2>", is_simple, is_class, field_treat, (ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    void *new_obj;
    if(field_treat == ARCHIVE_FIELD_IS_PTR)
    {
      obj = new std::map<T1, T2>;
      ar.register_reference(id, field_treat, obj);

      ar.set_is_temp_field_one_level(true);
      int s;
      ar & s;
      typename std::map<T1, T2>::iterator  it;
      std::pair<T1, T2>   p;
      for(int i=0;i<s;i++)
      {
        ar & p.first;
        ar & p.second;
        obj->insert(p);
      }
      ar.set_is_temp_field_one_level(false);
      ar.read_end_current_level();
    }
    else if((new_obj = ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      obj = (std::map<T1, T2>*)new_obj;
      if(!obj)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "std::map<T1, T2>", referencing);
  }
}

void operator&(Archiver &ar, short &obj);

template<typename T1, typename T2>
void operator&(Archiver &ar, std::map<T1, T2> &obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("std::map<T1, T2>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar.set_is_temp_field_one_level(true);
      int s = (int)obj.size();
      ar & s;
      typename std::map<T1, T2>::iterator  it;
      for(it=obj.begin(); it != obj.end(); it++)
      {
        T1  t1 = (*it).first;
        ar.dont_allow_delay();
        ar & t1;
        ar.dont_allow_delay();
        ar & (*it).second;
      }
      ar.set_is_temp_field_one_level(false);
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
    ar.check_nonclass_field(retval, type, "std::map<T1, T2>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar.register_reference(id, field_treat, &obj);

    ar.set_is_temp_field_one_level(true);
    int s;
    ar & s;
    typename std::map<T1, T2>::iterator  it;
    std::pair<T1, T2>   p;
    for(int i=0;i<s;i++)
    {
      ar & p.first;
      ar & p.second;
      obj.insert(p);
    }
    ar.set_is_temp_field_one_level(false);
    ar.read_end_current_level();
  }
}

template<class T>
void operator&(Archiver &ar, T &obj)
{
  if(ar.is_serializing_out())
  {
    //char  strtemp[20];
    //sprintf(strtemp, "%d", 0);
    bool is_ref;
    
    is_ref = ar.add_compound_field(obj.get_class_name_str(),//typeid(obj).name()+6, 
                                    T::class_versions[T::class_versions_count-1].class_version, 
                                    FIELD_IS_CLASS, "0",//strtemp, 
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
    ar.check_class_field(retval, type, obj.get_class_name_str(), is_simple, is_class, field_treat, 
                          ar.is_serialize_base_class() ? ARCHIVE_FIELD_IS_BASECLASS : ARCHIVE_FIELD_NORMAL, 
                          id);
    ar.set_class_version(version);
    ar.register_reference(id, field_treat, (SerializeBaseClass*)&obj);

    //check the version
    int v;
    if(version > T::class_versions[T::class_versions_count-1].class_version)
    {
      ZORBA_SER_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << obj.get_class_name_str() << " is " << version  << "while the version supported is " << T::class_versions[T::class_versions_count-1].class_version);
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
        
        ZORBA_SER_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
                        "Class version for " << obj.get_class_name_str() << " is " << version 
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
    if((obj == NULL))
    {
      ar.add_compound_field("NULL", 
                            1 ,//class_version
                            FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_IS_NULL);
      return;
    }
    //char  strtemp[20];
    //sprintf(strtemp, "%d", 0);
    bool is_ref;
    
    is_ref = ar.add_compound_field((ar.is_serialize_base_class() ?
                                    obj->T::get_class_name_str() :
                                    obj->get_class_name_str()), 
                                   (ar.is_serialize_base_class() ?
                                    T::class_versions[T::class_versions_count-1].class_version :
                                    obj->get_classversion(obj->get_version_count()-1).class_version), 
                                    FIELD_IS_CLASS, "0",//strtemp, 
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
    ar.check_class_field(retval, "", "", is_simple, is_class, field_treat, (ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    ar.set_class_version(version);



    if(ar.is_serialize_base_class())
    {
      if(strcmp(type, T::get_class_name_str_static()))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
      if(field_treat != ARCHIVE_FIELD_IS_BASECLASS)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
    {
      if((field_treat != ARCHIVE_FIELD_IS_PTR) && (field_treat != ARCHIVE_FIELD_IS_REFERENCING))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }

    SerializeBaseClass  *new_obj = NULL;
    if(field_treat == ARCHIVE_FIELD_IS_PTR)
    {
      class_deserializer  *cls_factory;
      cls_factory = ClassSerializer::getInstance()->get_class_factory(type);
      if(cls_factory == NULL)
      {
         ZORBA_SER_ERROR_DESC_OSS(SRL0003_UNRECOGNIZED_CLASS_FIELD, type);
      }
      new_obj = cls_factory->create_new(ar);
      obj = dynamic_cast<T*>(new_obj);
      if(!obj)
      {
        delete new_obj;obj=NULL;
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id << " type " << type << " class " << typeid(T).name());
      }

      //check the version
      int v;
      if(version > obj->get_classversion(obj->get_version_count()-1).class_version)
      {
        delete new_obj;obj=NULL;
        ZORBA_SER_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << obj->get_class_name_str() << " is " << version  << "while the version supported is " << obj->get_classversion(obj->get_version_count()-1).class_version);
      }
      for(v = obj->get_version_count()-1; v >= 0; v--)
      {
        const ClassVersion  &ver = obj->get_classversion(v);
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
          
          delete new_obj;obj=NULL;
          ZORBA_SER_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
                          "Class version for " << obj->get_class_name_str() << " is " << version 
                          << " while the minimal supported version is " << ver.class_version 
                          << ". Use Zorba 0x" << std::hex << obj->get_classversion(oldv).zorba_version << "instead.");
        }
                
      }


      ar.register_reference(id, field_treat, new_obj);
      try{
      new_obj->serialize_internal(ar);
      }catch(...)
      {
        delete new_obj;obj=NULL;
        throw;
      }
      ar.read_end_current_level();
    }
    else if(field_treat == ARCHIVE_FIELD_IS_BASECLASS)
    {
      //check the version
      int v;
      if(version > obj->T::get_classversion(obj->T::get_version_count()-1).class_version)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << obj->T::get_class_name_str() << " is " << version  << "while the version supported is " << obj->T::get_classversion(obj->T::get_version_count()-1).class_version);
      }
      for(v = obj->T::get_version_count()-1; v >= 0; v--)
      {
        if(version == obj->T::get_classversion(v).class_version)
          break;//supported version
        else if((version < obj->T::get_classversion(v).class_version) && !obj->T::get_classversion(v).is_backward_compatible)
        {
          int oldv;
          for(oldv = v; oldv >= 0; oldv--)
          {
            if(version == obj->T::get_classversion(oldv).class_version)
              break;
          }
          if(oldv < 0)
            oldv = 0;
          
          ZORBA_SER_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
            "Class version for " << obj->T::get_class_name_str() << " is " << version 
                          << " while the minimal supported version is " << obj->T::get_classversion(v).class_version 
                          << ". Use Zorba 0x" << std::hex << obj->T::get_classversion(oldv).zorba_version << "instead.");
        }
                
      }

      obj->T::serialize_internal(ar);
      ar.read_end_current_level();
    }
    else if((new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      try{
        obj = dynamic_cast<T*>(new_obj);
      }catch(...)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0004_UNRESOLVED_FIELD_REFERENCE, id);
      }
      if(!obj)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
    {
      ar.register_delay_reference((void**)&obj, FIELD_IS_CLASS, obj->T::get_class_name_str(), referencing);
    }
    ar.set_class_version(prev_class_version);
  }
}



template<class T>
void serialize_baseclass(Archiver &ar, T *obj)
{
  ar.set_serialize_base_class(true);

  ar & obj;

  //ar.set_serialize_base_class(false);
}

template<class T>
void read_optional_field(Archiver &ar, T &obj)
{
  ar.set_read_optional_field(true);
  ar & obj;
  ar.set_read_optional_field(false);
}

}}
#endif

