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

#include <cstdio>

#include "stdafx.h"

#include "zorbaserialization/serialize_basic_types.h"
#include "zorbaserialization/archiver.h"
#include "zorbaserialization/base64impl.h"

#include "zorbatypes/floatimpl.h"
#include "zorbatypes/collation_manager.h"
#include "zorbatypes/integer.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/assert.h"


namespace zorba
{

namespace serialization
{


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, long& obj)
{
  if (sizeof(long) == sizeof(int32_t))
  {
    ar & reinterpret_cast<int32_t&>(obj);
  }
  else
  {
    ar & reinterpret_cast<int64_t&>(obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, ulong& obj)
{
  if (sizeof(ulong) == sizeof(uint32_t))
  {
    ar & reinterpret_cast<uint32_t&>(obj);
  }
  else
  {
    ar & reinterpret_cast<uint64_t&>(obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, int64_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.int64v = obj;
    ar.add_simple_temp_field(TYPE_INT64, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_INT64);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.int64v;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, uint64_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.uint64v = obj;
    ar.add_simple_temp_field(TYPE_UINT64, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_UINT64);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.uint64v;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, const uint64_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.uint64v = obj;
    ar.add_simple_temp_field(TYPE_UINT64, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, int32_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.int32v = obj;
    ar.add_simple_temp_field(TYPE_INT32, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_INT32);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.int32v;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, uint32_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.uint32v = obj;
    ar.add_simple_temp_field(TYPE_UINT32, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_UINT32);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.uint32v;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, const uint32_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.uint32v = obj;
    ar.add_simple_temp_field(TYPE_UINT32, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, int16_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.int16v = obj;
    ar.add_simple_temp_field(TYPE_INT16, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_INT16);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.int16v;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, uint16_t& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.uint16v = obj;
    ar.add_simple_temp_field(TYPE_UINT16, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_UINT16);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.uint16v;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, char& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.charv = obj;
    ar.add_simple_temp_field(TYPE_CHAR, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_CHAR);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.charv;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, unsigned char& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.ucharv = obj;
    ar.add_simple_temp_field(TYPE_UCHAR, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_UCHAR);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.ucharv;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, float& obj)
{
  if (ar.is_serializing_out())
  {
    char strtemp[100];

    FloatImpl<float> zorba_float(obj);
    zstring float_str = zorba_float.toString();

    if (isdigit(float_str.c_str()[0]))
      sprintf(strtemp, "%.7e", (double)obj);
    else
      strcpy(strtemp, float_str.c_str());

    SimpleValue v;
    v.cstrv = strtemp;
    ar.add_simple_temp_field(TYPE_FLOAT, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_FLOAT);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    FloatImpl<float> zorba_float(value.cstrv);
    obj = zorba_float.getNumber();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, double& obj)
{
  if (ar.is_serializing_out())
  {
    char strtemp[100];
    FloatImpl<double> zorba_double(obj);
    zstring double_str = zorba_double.toString();

    if (isdigit(double_str.c_str()[0]))
      sprintf(strtemp, "%.16e", obj);
    else
      strcpy(strtemp, double_str.c_str());

    SimpleValue v;
    v.cstrv = strtemp;
    ar.add_simple_temp_field(TYPE_DOUBLE, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_DOUBLE);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    FloatImpl<double> zorba_double(value.cstrv);
    obj = zorba_double.getNumber();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, bool& obj)
{
  if (ar.is_serializing_out())
  {
    SimpleValue v;
    v.boolv = obj;
    ar.add_simple_temp_field(TYPE_BOOL, v, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    SimpleValue value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(value, TYPE_BOOL);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    obj = value.boolv;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, char*& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_field(TYPE_LAST,
                        obj,
                        obj,
                        obj ? ARCHIVE_FIELD_PTR : ARCHIVE_FIELD_NULL);
  }
  else
  {
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(type, &value, &id, true,  false, true,
                                &field_treat, &referencing);

    ar.check_simple_field(retval, field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      return;
    }

    if (field_treat != ARCHIVE_FIELD_PTR &&
        field_treat != ARCHIVE_FIELD_REFERENCING)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
    }

    if (field_treat == ARCHIVE_FIELD_PTR)
    {
      obj = strdup(value);
      ar.register_reference(id, field_treat, obj);
    }
    else if ((obj = (char*)ar.get_reference_value(referencing)) == NULL)
    {
      ZORBA_ASSERT(false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, std::string& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_field(TYPE_STD_STRING, obj.c_str(), &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(type, &value, &id, true, false, true,
                                &field_treat, &referencing);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, id);
    obj = value;

    ar.register_reference(id, field_treat, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, const std::string& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_field(TYPE_STD_STRING, obj.c_str(), &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************
  This is needed for theDefaultCollation in the static context
********************************************************************************/
void operator&(Archiver& ar, std::string*& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_field(TYPE_STD_STRING, obj ? obj->c_str() : NULL, 
                        obj, 
                        obj ? ARCHIVE_FIELD_PTR : ARCHIVE_FIELD_NULL);
  }
  else
  {
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(type, &value, &id, true, false, true,
                                &field_treat, &referencing);

    ar.check_simple_field(retval, field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      return;
    }

    if (field_treat != ARCHIVE_FIELD_PTR && 
        field_treat != ARCHIVE_FIELD_REFERENCING)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
    }

    if (field_treat == ARCHIVE_FIELD_PTR)
    {
      obj = new std::string(value);
      ar.register_reference(id, field_treat, obj);
    }
    else if ((obj = (std::string*)ar.get_reference_value(referencing)) == NULL)
    {
      ZORBA_ASSERT(false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_array(Archiver& ar, unsigned char* obj, int len)
{
  if (ar.is_serializing_out())
  {
    char* base64string;
    base64string = (char*)malloc(8*len/6 + 8 + 1);
    Base64Impl::Encode(obj, len, base64string);
    ar.add_simple_field(TYPE_LAST, base64string, obj, ARCHIVE_FIELD_NORMAL);
    free(base64string);
  }
  else
  {
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(type, &value, &id, true, false, true,
                                &field_treat, &referencing);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, id);

    Base64Impl::Decode((const unsigned char*)value, strlen(value), obj);

    ar.register_reference(id, field_treat, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, XQPCollator*& obj)
{
  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_simple_field(TYPE_NULL, 
                          NULL, 
                          NULL,
                          ARCHIVE_FIELD_NULL);
      return;
    }

    ar.add_simple_field(TYPE_LAST, obj->getURI().c_str(), obj, ARCHIVE_FIELD_PTR);
  }
  else
  {
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;

    bool retval = ar.read_next_field(type, &value, &id, true, false, true,
                                     &field_treat, &referencing);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_PTR, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      return;
    }

    if (strlen(value) > 0)
      obj = CollationFactory::createCollator(value);
    else
      obj = CollationFactory::createCollator();

    ar.register_reference(id, field_treat, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, MAPM& obj)
{
  if (ar.is_serializing_out())
  {
    int nr_digits = obj.significant_digits();
    char* lBuffer = (char*)malloc(nr_digits + 20);
    obj.toString(lBuffer, nr_digits);//ZORBA_FLOAT_POINT_PRECISION);

    if (strchr(lBuffer, '.'))
    {
      //save only necessary decimals
      char* e_ptr = strrchr(lBuffer, 'E');
      char* tail = e_ptr ? e_ptr-1 : lBuffer+strlen(lBuffer)-1;

      while (*tail == '0')
        tail--;

      if (*tail == '.')
        tail++;

      if (e_ptr)
      {
        int i;
        for(i = 0; e_ptr[i]; ++i)
          tail[i+1] = e_ptr[i];
        tail[i+1] = 0;
      }
      else
        tail[1] = 0;
    }

    ar.add_simple_field(TYPE_LAST, lBuffer, &obj, ARCHIVE_FIELD_NORMAL);
    free(lBuffer);
  }
  else
  {
    TypeCode type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;

    bool  retval = ar.read_next_field(type, &value, &id, true, false, true,
                                      &field_treat, &referencing);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, id);

    obj = value;

    ar.register_reference(id, field_treat, &obj);
  }
}


}
}
