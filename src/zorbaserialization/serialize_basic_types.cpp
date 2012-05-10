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
void operator&(Archiver& ar, int& obj)
{
  if (ar.is_serializing_out())
  {
    char strtemp[30];
    sprintf(strtemp, "%d", obj);

    ar.add_simple_temp_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%d", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, const int& obj)
{
  if (ar.is_serializing_out())
  {
    char strtemp[30];
    sprintf(strtemp, "%d", obj);

    ar.add_simple_temp_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, uint32_t& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%u", obj);

    ar.add_simple_temp_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool  retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%u", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, long& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%ld", obj);

    ar.add_simple_temp_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%ld", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, unsigned long& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%lu", obj);

    ar.add_simple_temp_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool  retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat,  ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%lu", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, long long& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%lld", obj);

    ar.add_simple_temp_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%lld", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, unsigned long long& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%llu", obj);

    ar.add_simple_temp_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%llu", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, short& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%hd", obj);

    ar.add_simple_temp_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%hd", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, unsigned short& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%hu", obj);

    ar.add_simple_temp_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    sscanf(value, "%hu", &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, char& obj)
{
  if (ar.is_serializing_out())
  {
    char strtemp[30];
    sprintf(strtemp, "%d", (int)obj);

    ar.add_simple_temp_field("char", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    int int_obj;
    sscanf(value, "%d", &int_obj);
    obj = (char)int_obj;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, char*& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_field("char*",
                        obj,
                        obj,
                        obj ? ARCHIVE_FIELD_PTR : ARCHIVE_FIELD_NULL);
  }
  else
  {
    char* type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, true,  false, true,
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
void operator&(Archiver& ar, signed char& obj)
{
  if (ar.is_serializing_out())
  {
    char  strtemp[30];
    sprintf(strtemp, "%d", (int)obj);

    ar.add_simple_temp_field("char", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool  retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    int int_obj;
    sscanf(value, "%d", &int_obj);
    obj = (signed char)int_obj;
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, unsigned char& obj)
{
  if (ar.is_serializing_out())
  {
    char strtemp[30];
    sprintf(strtemp, "%u", (unsigned int)obj);

    ar.add_simple_temp_field("unsigned char", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    unsigned int int_obj;
    sscanf(value, "%u", &int_obj);
    obj = (unsigned char)int_obj;
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

    ar.add_simple_temp_field("float", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    FloatImpl<float> zorba_float(value);
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

    ar.add_simple_temp_field("double", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    FloatImpl<double> zorba_double(value);
    obj = zorba_double.getNumber();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, bool& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_temp_field("bool", obj ? "T" : "F", &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* value;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;

    bool  retval = ar.read_next_simple_temp_field(&value);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, 0);

    if (!strcmp(value, "T"))
    {
      obj = true;
    }
    else if (!strcmp(value, "F"))
    {
      obj = false;
    }
    else
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(0));
    }
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, std::string& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_field("string", obj.c_str(), &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, true, false, true,
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
    ar.add_simple_field("string", obj.c_str(), &obj, ARCHIVE_FIELD_NORMAL);
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
    ar.add_simple_field("std::string*", obj ? obj->c_str() : NULL, 
                        obj, 
                        obj ? ARCHIVE_FIELD_PTR : ARCHIVE_FIELD_NULL);
  }
  else
  {
    char* type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, true, false, true,
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
    ar.add_simple_field("char[]", base64string, obj, ARCHIVE_FIELD_NORMAL);
    free(base64string);
  }
  else
  {
    char* type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, true, false, true,
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
      ar.add_simple_field("XQPCollator*", 
                          NULL, 
                          NULL,
                          ARCHIVE_FIELD_NULL);
      return;
    }

    ar.add_simple_field("XQPCollator*", obj->getURI().c_str(), obj, ARCHIVE_FIELD_PTR);
  }
  else
  {
    char* type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;

    bool retval = ar.read_next_field(&type, &value, &id, true, false, true,
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

    ar.add_simple_field("MAPM", lBuffer, &obj, ARCHIVE_FIELD_NORMAL);
    free(lBuffer);
  }
  else
  {
    char* type;
    char* value;
    int   id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;

    bool  retval = ar.read_next_field(&type, &value, &id, true, false, true,
                                      &field_treat, &referencing);

    ar.check_simple_field(retval, field_treat, ARCHIVE_FIELD_NORMAL, id);

    obj = value;

    ar.register_reference(id, field_treat, &obj);
  }
}


}
}
