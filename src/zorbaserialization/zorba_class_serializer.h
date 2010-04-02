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

#ifndef ZORBA_SPECIFIC_CLASS_SERIALIZATION
#define ZORBA_SPECIFIC_CLASS_SERIALIZATION

#include "zorbatypes/rchandle.h"
#include "zorbatypes/m_apm.h"
#include "zorbautils/checked_vector.h"

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"

#include "store/api/shared_types.h"

#include <stdio.h>
#include <map>

namespace zorba{
  class XQType;
  class function;

  namespace serialization{
//void operator&(Archiver &ar, XQType *&obj);
void operator&(Archiver &ar, const XQType *&obj);
#ifndef ZORBA_NO_BIGNUMBERS
void operator&(Archiver &ar, MAPM &obj);
#endif

void operator&(Archiver &ar, XQPCollator *&obj);
void operator&(Archiver &ar, store::Item* &obj);
//void operator&(Archiver &ar, std::vector<rchandle<function> >*& obj);

//void serialize_qname(Archiver &ar, store::Item_t &qname);

#define SERIALIZE_TYPEMANAGER(type_mgr_type, type_mgr)                             \
  bool is_root_type_mgr = ar.is_serializing_out() && (!GENV.isRootStaticContextInitialized() || ((TypeManager*)type_mgr == (TypeManager*)&GENV_TYPESYSTEM));            \
  ar.set_is_temp_field_one_level(true);                             \
  ar & is_root_type_mgr;                                            \
  ar.set_is_temp_field_one_level(false);                            \
  if(is_root_type_mgr)                                              \
  {                                                                 \
    if(!ar.is_serializing_out())                                    \
    {                                                               \
      type_mgr = (type_mgr_type*)&GENV_TYPESYSTEM;                  \
      /*RCHelper::addReference(type_mgr);*/                         \
    }                                                               \
  }                                                                 \
  else                                                              \
  {                                                                 \
    ar & type_mgr;                                                  \
  }

#define SERIALIZE_TYPEMANAGER_RCHANDLE(type_mgr_type, type_mgr)                             \
  bool is_root_type_mgr = (!GENV.isRootStaticContextInitialized() || ((TypeManager*)type_mgr.getp() == (TypeManager*)&GENV_TYPESYSTEM));            \
  ar.set_is_temp_field_one_level(true);                             \
  ar & is_root_type_mgr;                                            \
  ar.set_is_temp_field_one_level(false);                            \
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
    sprintf(strtemp, "%d", (int)obj.size());
    bool is_ref;
    is_ref = ar.add_compound_field("checked_vector<T>", 0, !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      typename checked_vector<T>::iterator  it;
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
    typename checked_vector<T>::iterator  it;
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
    ENUM_ALLOW_DELAY allow_delay = ar.get_allow_delay();
    is_ref = ar.add_compound_field("rchandle<T>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      T *p = obj.getp();
      if(allow_delay != ALLOW_DELAY)
        ar.dont_allow_delay(allow_delay);
      bool is_temp = false;
      if(ar.get_is_temp_field_one_level())
      {
        is_temp = true;
        ar.set_is_temp_field_one_level(true, ar.get_is_temp_field_also_for_ptr());
        if(!ar.get_is_temp_field_also_for_ptr() && (allow_delay == ALLOW_DELAY))
          ar.dont_allow_delay();
      }
      ar & p;
      if(is_temp)
        ar.set_is_temp_field_one_level(false);
      ar.add_end_compound_field();
    }
    else
    {
      assert(false);
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
    //ar.register_reference(id, field_treat, &obj);

    bool is_temp = false;
    if(ar.get_is_temp_field_one_level())
    {
      is_temp = true;
      ar.set_is_temp_field_one_level(true, ar.get_is_temp_field_also_for_ptr());
    }
    T *p;
    ar & p;
    if(is_temp)
      ar.set_is_temp_field_one_level(false);
    obj = p;
    if(p == NULL)
    {
      //workaround for the strict_aliasing warning in gcc
      union 
      {
        T **t;
        void **v;
      }u_p;
      u_p.t = &p;
      ar.reconf_last_delayed_rcobject(u_p.v, obj.getp_ref().v, true);
    }
    ar.read_end_current_level();

  }
}

template<class T>
void operator&(Archiver &ar, zorba::const_rchandle<T> &obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    ENUM_ALLOW_DELAY allow_delay = ar.get_allow_delay();
    is_ref = ar.add_compound_field("const_rchandle<T>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      T *p = (T*)obj.getp();
      if(allow_delay != ALLOW_DELAY)
        ar.dont_allow_delay(allow_delay);
      bool is_temp = false;
      if(ar.get_is_temp_field_one_level())
      {
        is_temp = true;
        ar.set_is_temp_field_one_level(true, ar.get_is_temp_field_also_for_ptr());
        if(!ar.get_is_temp_field_also_for_ptr() && (allow_delay == ALLOW_DELAY))
          ar.dont_allow_delay();
      }
      ar & p;
      if(is_temp)
        ar.set_is_temp_field_one_level(false);
      ar.add_end_compound_field();
    }
    else
    {
      assert(false);
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
    //ar.register_reference(id, field_treat, &obj);

    bool is_temp = false;
    if(ar.get_is_temp_field_one_level())
    {
      is_temp = true;
      ar.set_is_temp_field_one_level(true, ar.get_is_temp_field_also_for_ptr());
    }
    T *p;
    ar & p;
    obj = p;
    if(is_temp)
      ar.set_is_temp_field_one_level(false);
    if(p == NULL)
    {
      //workaround for the strict_aliasing warning in gcc
      union 
      {
        T **t;
        void **v;
      }u_p;
      u_p.t = &p;
      ar.reconf_last_delayed_rcobject(u_p.v, obj.getp_ref().v, true);
    }
    ar.read_end_current_level();

  }
}


}}
#endif
