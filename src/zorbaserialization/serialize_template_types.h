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
#ifndef TEMPLATE_SERIALIZATION_OPERATORS
#define TEMPLATE_SERIALIZATION_OPERATORS

#include <list>
#include <vector>
#include <map>
#include <stdio.h>

#include <zorba/diagnostic_list.h>
#include <zorba/internal/unique_ptr.h>

#include "util/string_util.h"
#include "util/stl_util.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "zorbatypes/zstring.h"

#include "archiver.h"
#include "class_serializer.h"
#include "serialize_basic_types.h"

namespace zorba
{

template<class V> class serializable_ItemPointerHashMap;


class ser_ItemPointerHashMapCmp;

namespace serialization
{
/////////////////////////////templates

#define ZORBA_SER_ERROR_DESC_OSS(QNAME,MSG)                     \
  do {                                                          \
    std::ostringstream oss;                                     \
    oss << MSG;                                                 \
    throw XQUERY_EXCEPTION( QNAME, ERROR_PARAMS( oss.str() ) ); \
  } while (0)


/*******************************************************************************

********************************************************************************/
template<class T>
void serialize_baseclass(Archiver& ar, T* obj)
{
  ar.set_serialize_base_class(true);

  ar & obj;
}


/*******************************************************************************

********************************************************************************/
template<class T>
void operator&(Archiver& ar, T& obj)
{
  if (ar.is_serializing_out())
  {
    bool is_ref = ar.add_compound_field(obj.get_serializer_type_code(),
                                        true,
                                        (SerializeBaseClass*)&obj, 
                                        ARCHIVE_FIELD_NORMAL);
    if (!is_ref)
    {
      obj.serialize_internal(ar);

      ar.add_end_compound_field();
    }
  }
  else
  {
    TypeCode type;
    char* value;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int referencing;

    bool retval = ar.read_next_field(type, &value, &id, false, true, false,
                                     &field_treat, &referencing);

    ar.check_class_field(retval, type, obj.get_serializer_type_code(),
                         field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar.register_reference(id, field_treat, (SerializeBaseClass*)&obj);

    obj.serialize_internal(ar);

    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
template<class T>
void operator&(Archiver& ar, T*& obj)
{
  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, true, NULL, ARCHIVE_FIELD_NULL);
      return;
    }

    bool is_ref = ar.add_compound_field((ar.is_serialize_base_class() ?
                                         TYPE_LAST :
                                         obj->get_serializer_type_code()), 
                                        true,
                                        (SerializeBaseClass*)obj, 
                                        (ar.is_serialize_base_class() ?
                                         ARCHIVE_FIELD_BASECLASS :
                                         ARCHIVE_FIELD_PTR));
    if (!is_ref)
    {
      if (!ar.is_serialize_base_class())
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
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;

    bool  retval = ar.read_next_field(type, &value, &id, false, true, false,
                                      &field_treat, &referencing);

    ar.check_class_field(retval, TYPE_NULL, TYPE_NULL,
                         field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    if (ar.is_serialize_base_class())
    {
      if (field_treat != ARCHIVE_FIELD_BASECLASS)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
      }
    }
    else
    {
      if (field_treat != ARCHIVE_FIELD_PTR && field_treat != ARCHIVE_FIELD_REFERENCING)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
      }
    }

    SerializeBaseClass* new_obj = NULL;

    if (field_treat == ARCHIVE_FIELD_PTR)
    {
      assert(type > 0 && type < TYPE_LAST);

      ClassDeserializer* cls_factory;
      cls_factory = ClassSerializer::getInstance()->get_class_factory(type);

      if (cls_factory == NULL)
      {
         throw ZORBA_EXCEPTION(zerr::ZCSE0003_UNRECOGNIZED_CLASS_FIELD, 
         ERROR_PARAMS(BUILD_STRING((ulong)type)));
      }

      new_obj = cls_factory->create_new(ar);

      obj = dynamic_cast<T*>(new_obj);

      if (!obj)
      {
        delete new_obj; 
        obj = NULL;

        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD,
        ERROR_PARAMS(id, BUILD_STRING((ulong)type), typeid(T).name()));
      }

      ar.register_reference(id, field_treat, new_obj);

      try
      {
        obj->serialize_internal(ar);
      }
      catch(...)
      {
        delete new_obj;
        obj = NULL;
        throw;
      }

      ar.read_end_current_level();
    }
    else if (field_treat == ARCHIVE_FIELD_BASECLASS)
    {
      obj->T::serialize_internal(ar);

      ar.read_end_current_level();
    }
    // ARCHIVE_FIELD_REFERENCING
    else if ((new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))
    {
      try
      {
        obj = dynamic_cast<T*>(new_obj);
      }
      catch(...)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0004_UNRESOLVED_FIELD_REFERENCE,
        ERROR_PARAMS(id));
      }

      if (!obj)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD,
        ERROR_PARAMS(id));
      }
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }
}


template<class T>
void operator&(Archiver& ar, zorba::rchandle<T>& obj)
{
  if (ar.is_serializing_out())
  {
    T* p = obj.getp();
    ar & p;
  }
  else
  {
    T* p;
    ar & p;
    obj = p;
  }
}


template<class T>
void operator&(Archiver& ar, zorba::const_rchandle<T>& obj)
{
  if (ar.is_serializing_out())
  {
    T* p = (T*)obj.getp();
    ar & p;
  }
  else
  {
    T* p;
    ar & p;
    obj = p;
  }
}


template<class T>
void operator&(Archiver& ar, store::ItemHandle<T>& obj)
{ 
  if (ar.is_serializing_out())
  {
    T* p = obj.getp();
    ar & p;
  }
  else
  {
    T* p;
    ar & p;
    obj = p;
  }
}


/*******************************************************************************

********************************************************************************/
template<class T>
void operator&(Archiver& ar, checked_vector<T>& obj)
{
  if (ar.is_serializing_out())
  {
    csize size = obj.size();
    ar & size;

    typename checked_vector<T>::iterator it = obj.begin();
    typename checked_vector<T>::iterator end = obj.end();
    for(; it != end; ++it)
    {
      ar & (*it);
    }
  }
  else
  {
    csize size;
    ar & size;

    obj.resize(size);

    typename checked_vector<T>::iterator it = obj.begin();
    typename checked_vector<T>::iterator end = obj.end();
 
    for(; it != end; ++it)
    {
      ar & (*it);
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::vector<T>& obj)
{
  if (ar.is_serializing_out())
  {
    csize size = obj.size();
    ar & size;

    typename std::vector<T>::iterator it = obj.begin();
    typename std::vector<T>::iterator end = obj.end();
    for(; it != end; ++it)
    {
      ar & (*it);
    }
  }
  else
  {
    csize size;
    ar & size;

    obj.resize(size);

    typename std::vector<T>::iterator it = obj.begin();
    typename std::vector<T>::iterator end = obj.end();
    for(; it != end; ++it)
    {
      ar & (*it);
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::vector<T*>& obj)
{
  if (ar.is_serializing_out())
  {
    csize size = obj.size();
    ar & size;

    typename std::vector<T*>::iterator it = obj.begin();
    typename std::vector<T*>::iterator end = obj.end();
    for(; it != end; ++it)
    {
      ar & (*it);
    }
  }
  else
  {
    csize size;
    ar & size;

    obj.resize(size);

    typename std::vector<T*>::iterator it = obj.begin();
    typename std::vector<T*>::iterator end = obj.end();

    for(; it != end; ++it)
    {
      ar & (*it);
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::vector<T>*& obj)
{
  assert(!ar.is_serialize_base_class());

  csize size = 0;

  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, false, NULL, ARCHIVE_FIELD_NULL);
      return;
    }

    bool is_ref = ar.add_compound_field(TYPE_LAST, false, obj, ARCHIVE_FIELD_PTR);
    assert(!is_ref);
    (void)is_ref;

    size = obj->size();
    ar & size;

    typename std::vector<T>::iterator it = obj->begin();
    typename std::vector<T>::iterator end = obj->end();
    for(; it != end; ++it)
    {
      ar & (*it);
    }

    ar.add_end_compound_field();
  }
  else
  {
    TypeCode type;
    char* value;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int referencing;

    bool  retval = ar.read_next_field(type, &value, &id, false, false, false,
                                      &field_treat, &referencing);

    ar.check_nonclass_field(retval, field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    ZORBA_ASSERT(field_treat == ARCHIVE_FIELD_PTR);

    obj = new std::vector<T>;

    ar & size;

    obj->resize(size);

    typename std::vector<T>::iterator it = obj->begin();
    typename std::vector<T>::iterator end = obj->end();
    for(; it != end; ++it)
    {
      ar & (*it);
    }

    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::list<T>& obj)
{
  if (ar.is_serializing_out())
  {
    csize size = obj.size();
    ar & size;

    typename std::list<T>::iterator it = obj.begin();
    typename std::list<T>::iterator end = obj.end();
    for (; it != end; ++it)
    {
      ar & (*it);
    }
  }
  else
  {
    csize size;
    ar & size;
    obj.resize(size);

    typename std::list<T>::iterator it = obj.begin();
    typename std::list<T>::iterator end = obj.end();
    for (; it != end; ++it)
    {
      ar & (*it);
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T1, typename T2>
void operator&(Archiver& ar, std::pair<T1, T2>& obj)
{
  ar & obj.first;
  ar & obj.second;
}


/*******************************************************************************

********************************************************************************/
template<typename T1, typename T2>
void operator&(Archiver& ar, std::map<T1, T2>*& obj)
{
  assert(!ar.is_serialize_base_class());

  csize size = 0;

  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, false, NULL, ARCHIVE_FIELD_NULL);
      return;
    }

    bool is_ref = ar.add_compound_field(TYPE_LAST, false, obj, ARCHIVE_FIELD_PTR);

    assert(!is_ref);
    (void)is_ref;

    size = obj->size();
    ar & size;

    typename std::map<T1, T2>::iterator it = obj->begin();
    typename std::map<T1, T2>::iterator end = obj->end();

    for (; it != end; ++it)
    {
      T1 key = (*it).first;
      ar & key;
      ar & (*it).second;
    }

    ar.add_end_compound_field();
  }
  else
  {
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;

    bool  retval = ar.read_next_field(type, &value, &id, false, false, false,
                                      &field_treat, &referencing);

    ar.check_nonclass_field(retval, field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    ZORBA_ASSERT(field_treat == ARCHIVE_FIELD_PTR);

    obj = new std::map<T1, T2>;

    ar & size;

    std::pair<T1, T2> p;

    for (csize i = 0; i < size; ++i)
    {
      ar & p.first;
      ar & p.second;

      obj->insert(p);
    }

    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T1, typename T2, class Tcomp>
void operator&(Archiver& ar, std::map<T1, T2, Tcomp>& obj)
{
  if (ar.is_serializing_out())
  {
    csize s = obj.size();
    ar & s;

    typename std::map<T1, T2, Tcomp>::iterator it = obj.begin();
    typename std::map<T1, T2, Tcomp>::iterator end = obj.end();

    for (; it != end; ++it)
    {
      T1 key = (*it).first;
      ar & key;
      ar & (*it).second;
    }
  }
  else
  {
    csize s;
    ar & s;

    std::pair<T1, T2> p;

    for (csize i = 0; i < s; ++i)
    {
      ar & p.first;
      ar & p.second;

      obj.insert(p);
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T, typename V, class Tcomp>
void operator&(Archiver& ar, HashMap<T, V, Tcomp>& obj)
{
  ar & obj.theHashTabSize;
  ar & obj.theCompareFunction;

  bool sync = false;
  csize size;

  if (ar.is_serializing_out())
  {
    sync = obj.get_sync();
    size = obj.size();

    ar & sync;
    ar & size;

    typename HashMap<T, V, Tcomp>::iterator it = obj.begin();
    typename HashMap<T, V, Tcomp>::iterator end = obj.end();

    for (; it != end; ++it)
    {
      T key = it.getKey();
      ar & key;
      ar & it.getValue();
    }
  }
  else
  {
    ar & sync;
    ar & size;

    obj.theNumEntries = 0;
    obj.theInitialSize = obj.theHashTabSize;
    obj.theHashTab = computeTabSize(obj.theHashTabSize);
    obj.theLoadFactor = HashMap<T, V, Tcomp>::DEFAULT_LOAD_FACTOR;
    obj.numCollisions = 0;
    
    obj.formatCollisionArea();

    SYNC_CODE(obj.theMutexp = (sync ? &obj.theMutex : NULL);)

    for (csize i = 0; i < size; ++i)
    {
      T t;
      V v;
      ar & t;
      ar & v;
      bool insert_ret = obj.insert(t, v);
      assert(insert_ret);
      (void)insert_ret;
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T, typename V, class Tcomp>
void operator&(Archiver& ar, HashMap<T, V, Tcomp>*& obj)
{
  assert(!ar.is_serialize_base_class());

  bool sync = false;
  csize size;
  csize capacity;
  Tcomp comp;

  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, false, NULL, ARCHIVE_FIELD_NULL);
      return;
    }

    bool is_ref = ar.add_compound_field(TYPE_LAST, false, obj, ARCHIVE_FIELD_PTR);

    assert(!is_ref);
    (void)is_ref;

    sync = obj->get_sync();
    capacity = obj->capacity();
    comp = obj->get_compare_function();
    size = obj->size();

    ar.set_is_temp_field(true);

    ar & capacity;
    ar & sync;
    ar & comp;
    ar & size;

    ar.set_is_temp_field(false);

    typename HashMap<T, V, Tcomp>::iterator it = obj->begin();
    typename HashMap<T, V, Tcomp>::iterator end = obj->end();

    for (; it != end; ++it)
    {
      T key = it.getKey();
      ar & key;
      ar & it.getValue();
    }

    ar.add_end_compound_field();
  }
  else
  {
    TypeCode type;
    char* value;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int referencing;

    bool  retval = ar.read_next_field(type, &value, &id, false, false, false,
                                      &field_treat, &referencing);

    ar.check_nonclass_field(retval, field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    assert(field_treat == ARCHIVE_FIELD_PTR);

    ar.set_is_temp_field(true);

    ar & capacity;
    ar & sync;
    ar & comp;
    ar & size;

    ar.set_is_temp_field(false);

    obj = new HashMap<T, V, Tcomp>(comp, capacity, sync);

    for (csize i = 0; i < size; ++i)
    {
      T key;
      V value;
      ar & key;
      ar & value;
      bool insert_ret = obj->insert(key, value);
      assert(insert_ret);
      (void)insert_ret;
    }

    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
template<class RepType>
void operator&(Archiver& ar, zorba::rstring<RepType>& obj)
{
  bool is_normal_str = true;

  if (ar.is_serializing_out())
  {
    if (obj.size() != strlen(obj.c_str()))
      is_normal_str = false;
  }

  ar & is_normal_str;

  if (is_normal_str)
  {
    if (ar.is_serializing_out())
    {
      SimpleValue v;
      v.cstrv = obj.c_str();
      ar.add_simple_temp_field(TYPE_ZSTRING, v, &obj, ARCHIVE_FIELD_NORMAL);
    }
    else
    {
      SimpleValue value;
      ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

      bool retval = ar.read_next_simple_temp_field(value, TYPE_ZSTRING);

      ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

      obj = value.cstrv;
    }
  }
  else
  {
    //for strings which contain '\0' inside
    if (ar.is_serializing_out())
    {
      const char* cstr = obj.c_str();
      zorba::zstring::size_type s = obj.size();

      ar.set_is_temp_field(true);
      ar & s;
      serialize_array(ar, (unsigned char*)cstr, s);
      ar.set_is_temp_field(false);
    }
    else
    {
      std::unique_ptr<unsigned char[]> cstr;
      zorba::zstring::size_type s;

      ar.set_is_temp_field(true);

      ar & s;
      cstr.reset(new unsigned char[s]);
      serialize_array(ar, (unsigned char*)cstr.get(), s);

      obj.assign((const char*)cstr.get(), s);

      ar.set_is_temp_field(false);
    }
  }
}


template<typename FloatType>
void operator&(Archiver& ar, FloatImpl<FloatType>& obj)
{
  ar & obj.value_;
  ar & obj.precision_;
}


} // namespace serialization
} // namespace zorba

#endif /* TEMPLATE_SERIALIZATION_OPERATORS */
/* vim:set et sw=2 ts=2: */
