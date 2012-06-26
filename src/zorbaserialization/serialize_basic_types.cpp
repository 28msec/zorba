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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/assert.h"


namespace zorba
{

namespace serialization
{


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, int64_t& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_INT64, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_INT64, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, uint64_t& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_UINT64, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_UINT64, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, int32_t& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_INT32, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_INT32, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, uint32_t& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_UINT32, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_UINT32, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, int16_t& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_INT16, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_INT16, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, uint16_t& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_UINT16, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_UINT16, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, long& obj)
{
  if (ar.is_serializing_out())
  {
    int64_t int64v = obj;
    ar.add_simple_temp_field(TYPE_INT64, &int64v);
  }
  else
  {
    int64_t int64v;
    ar.read_next_simple_temp_field(TYPE_INT64, &int64v);

    obj = static_cast<long>(int64v);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, ulong& obj)
{
  if (ar.is_serializing_out())
  {
    uint64_t uint64v = obj;
    ar.add_simple_temp_field(TYPE_UINT64, &uint64v);
  }
  else
  {
    uint64_t uint64v;
    ar.read_next_simple_temp_field(TYPE_UINT64, &uint64v);

    obj = static_cast<ulong>(uint64v);
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_long_long(Archiver& ar, long long& obj)
{
  assert(sizeof(long long) == 8);

  if (ar.is_serializing_out())
  {
    int64_t int64v = obj;
    ar.add_simple_temp_field(TYPE_INT64, &int64v);
  }
  else
  {
    int64_t int64v;
    ar.read_next_simple_temp_field(TYPE_INT64, &int64v);

    obj = static_cast<long long>(int64v);
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_ulong_long(Archiver& ar, unsigned long long& obj)
{
  assert(sizeof(unsigned long long) == 8);

  if (ar.is_serializing_out())
  {
    uint64_t uint64v = obj;
    ar.add_simple_temp_field(TYPE_UINT64, &uint64v);
  }
  else
  {
    uint64_t uint64v;
    ar.read_next_simple_temp_field(TYPE_UINT64, &uint64v);

    obj = static_cast<unsigned long long>(uint64v);
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_csize(Archiver& ar, csize& obj)
{
  assert(sizeof(csize) <= 8);

  if (ar.is_serializing_out())
  {
    uint64_t uint64v = obj;
    ar.add_simple_temp_field(TYPE_UINT64, &uint64v);
  }
  else
  {
    uint64_t uint64v;
    ar.read_next_simple_temp_field(TYPE_UINT64, &uint64v);

    obj = static_cast<csize>(uint64v);
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_enum(Archiver& ar, uint32_t& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_ENUM, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_ENUM, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, char& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_CHAR, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_CHAR, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, unsigned char& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_UCHAR, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_UCHAR, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, float& obj)
{
  if (ar.is_serializing_out())
  {
     FloatImpl<float> zorba_float(obj);
    zstring float_str = zorba_float.toString();

    if (isdigit(float_str.c_str()[0]))
    {
      char strtemp[100];
      sprintf(strtemp, "%.7e", (double)obj);
      float_str = strtemp;
    }

    ar.add_simple_temp_field(TYPE_ZSTRING, &float_str);
  }
  else
  {
    zstring float_str;

    ar.read_next_simple_temp_field(TYPE_ZSTRING, &float_str);

    FloatImpl<float> zorba_float(float_str.c_str());
    obj = zorba_float.getNumber();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, double& obj)
{
  if (ar.is_serializing_out())
  {
    FloatImpl<double> zorba_double(obj);
    zstring double_str = zorba_double.toString();

    if (isdigit(double_str.c_str()[0]))
    {
      char strtemp[100];
      sprintf(strtemp, "%.16e", obj);
      double_str = strtemp;
    }

    ar.add_simple_temp_field(TYPE_ZSTRING, &double_str);
  }
  else
  {
    zstring double_str;

    ar.read_next_simple_temp_field(TYPE_ZSTRING, &double_str);

    FloatImpl<double> zorba_double(double_str.c_str());
    obj = zorba_double.getNumber();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, bool& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_BOOL, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_BOOL, &obj);
  }
}



/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, zstring& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_ZSTRING, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_ZSTRING, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, std::string& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field(TYPE_STD_STRING, &obj);
  }
  else
  {
    ar.read_next_simple_temp_field(TYPE_STD_STRING, &obj);
  }
}


/*******************************************************************************
  This is needed for theDefaultCollation in the static context
********************************************************************************/
void operator&(Archiver& ar, std::string*& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_ptr_field(TYPE_STD_STRING, obj); 
  }
  else
  {
    ar.read_next_simple_ptr_field(TYPE_STD_STRING, (void**)&obj);
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
      ar.add_simple_ptr_field(TYPE_NULL, NULL);
      return;
    }

    ar.add_simple_ptr_field(TYPE_COLLATOR, obj);
  }
  else
  {
    ar.read_next_simple_ptr_field(TYPE_COLLATOR, (void**)&obj);
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

    obj.toString(lBuffer, nr_digits);

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

    zstring value = lBuffer;

    ar.add_simple_temp_field(TYPE_ZSTRING, &value);

    free(lBuffer);
  }
  else
  {
    zstring value;

    ar.read_next_simple_temp_field(TYPE_ZSTRING, &value);

    obj = value.c_str();
  }
}


}
}
