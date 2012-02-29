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
#ifndef ZORBA_SPECIFIC_CLASS_SERIALIZATION
#define ZORBA_SPECIFIC_CLASS_SERIALIZATION

#include <zorba/item.h>
#include <zorba/xquery_exception.h>
#include "zorbatypes/rchandle.h"
#include "zorbatypes/m_apm.h"
#include "zorbatypes/floatimpl.h"
#include "zorbautils/checked_vector.h"

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"

#include "store/api/shared_types.h"
#include "diagnostics/assert.h"

#include <stdio.h>
#include <map>

namespace zorba{
  class XQType;
  class function;
  class Diagnostic;
  class ZorbaException;
#ifdef ZORBA_WITH_BIG_INTEGER
  class IntegerImpl;
#else
  template<typename IntType> class IntegerImpl;
#endif /* ZORBA_WITH_BIG_INTEGER */

  namespace serialization{
//void operator&(Archiver &ar, XQType *&obj);
void operator&(Archiver &ar, const XQType *&obj);
void operator&(Archiver &ar, MAPM &obj);
#ifdef ZORBA_WITH_BIG_INTEGER
void operator&(Archiver &ar, IntegerImpl &obj);
#else
template<typename IntType>
void operator&(Archiver &ar, IntegerImpl<IntType> &obj);
#endif /* ZORBA_WITH_BIG_INTEGER */

void operator&(Archiver &ar, XQPCollator *&obj);
void operator&(Archiver &ar, store::Item* &obj);
//void operator&(Archiver &ar, std::vector<rchandle<function> >*& obj);
void operator&(Archiver &ar, const Diagnostic *&obj);
void operator&(Archiver &ar, ZorbaException *&obj);
void operator&(Archiver &ar, zorba::internal::diagnostic::location &obj);
void operator&(Archiver &ar, zorba::Item &obj);
void operator&(Archiver &ar, zorba::XQueryStackTrace &obj);
void operator&(Archiver &ar, zorba::XQueryStackTrace::Entry &obj);

//void serialize_qname(Archiver &ar, store::Item_t &qname);

#define SERIALIZE_TYPEMANAGER(type_mgr_type, type_mgr)                             \
  bool is_root_type_mgr = ar.is_serializing_out() && (!GENV.isRootStaticContextInitialized() || ((TypeManager*)type_mgr == (TypeManager*)&GENV_TYPESYSTEM)) && ar.is_serializing_out();            \
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
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldTreat field_treat = ARCHIVE_FIELD_NORMAL;
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
void operator&(Archiver &ar, store::ItemHandle<T>& obj)
{ 
  if(ar.is_serializing_out())
  {
    bool is_ref;
    ENUM_ALLOW_DELAY allow_delay = ar.get_allow_delay();
    is_ref = ar.add_compound_field("ItemHandle<T>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
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
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldTreat field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "ItemHandle<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
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
void operator&(Archiver &ar, zorba::rchandle<T> &obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    ENUM_ALLOW_DELAY allow_delay = ar.get_allow_delay();
    is_ref = ar.add_compound_field("rchandle<T>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    assert(!is_ref);
    ZORBA_ASSERT(!is_ref);
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
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldTreat field_treat = ARCHIVE_FIELD_NORMAL;
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
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldTreat field_treat = ARCHIVE_FIELD_NORMAL;
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
/*
template<class T>
void operator&(Archiver &ar, rchandle<T> *&obj)
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
    //char  strtemp[20];
    //sprintf(strtemp, "%d", 0);
    bool is_ref;
    ENUM_ALLOW_DELAY allow_delay = ar.get_allow_delay();
    
    is_ref = ar.add_compound_field("rchandle<T>", 
                                    1, 
                                    !FIELD_IS_CLASS, "0",//strtemp, 
                                    obj, 
                                    ar.is_serialize_base_class() ? ARCHIVE_FIELD_IS_BASECLASS : ARCHIVE_FIELD_IS_PTR);
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                
    if(!is_ref)
    {
      T *p = obj->getp();
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
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldTreat field_treat = ARCHIVE_FIELD_IS_PTR;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "rchandle<T>", is_simple, is_class, field_treat, (ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                

    if(ar.is_serialize_base_class())
    {
      if(field_treat != ARCHIVE_FIELD_IS_BASECLASS)
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
        );
      }
    }
    else
    {
      if((field_treat != ARCHIVE_FIELD_IS_PTR) && (field_treat != ARCHIVE_FIELD_IS_REFERENCING))
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
        );
      }
    }

    SerializeBaseClass  *new_obj = NULL;
    if((field_treat == ARCHIVE_FIELD_IS_PTR) ||
      (field_treat == ARCHIVE_FIELD_IS_BASECLASS))
    {
      throw ZORBA_EXCEPTION(
        zerr::ZCSE0009_CLASS_NOT_SERIALIZABLE, ERROR_PARAMS( "rchandle<T>*" )
      );

      bool is_temp = false;
      if(ar.get_is_temp_field_one_level())
      {
        is_temp = true;
        ar.set_is_temp_field_one_level(true, ar.get_is_temp_field_also_for_ptr());
      }
      T *p;
      ar & p;
      if(field_treat == ARCHIVE_FIELD_IS_PTR)
      {
        obj = new rchandle<T>(p);
        ar.register_reference(id, field_treat, new_obj);
      }
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
        ar.reconf_last_delayed_rcobject(u_p.v, obj->getp_ref().v, true);
      }
      ar.read_end_current_level();
    }
    else if((new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      try{
        obj = dynamic_cast<rchandle<T>*>(new_obj);
      }catch(...)
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0004_UNRESOLVED_FIELD_REFERENCE, ERROR_PARAMS( id )
        );
      }
      if(!obj)
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
        );
      }
    }
    else
    {
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "rchandle<T>", referencing);
    }
  }
}
*/

template<typename StringType>
void operator&(Archiver &ar, zorba::internal::VariableQName<StringType> &obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("VariableQName<StringType>", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar & obj.ns_;
      ar & obj.prefix_;
      ar & obj.localname_;
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
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldTreat field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "VariableQName<StringType>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.ns_;
    ar & obj.prefix_;
    ar & obj.localname_;
    ar.read_end_current_level();
  }
}

template<typename FloatType>
void operator&(Archiver &ar, FloatImpl<FloatType> &obj)
{
  ar & obj.value_;
  ar & obj.precision_;
}

} // namespace serialization
} // namespae zorba
#endif
/* vim:set et sw=2 ts=2: */
