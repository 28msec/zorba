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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"


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

    ar.add_simple_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type,
                                &value,
                                &id,
                                &version,
                                &is_simple,
                                &is_class,
                                &field_treat,
                                &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval,
                          type,
                          "number",
                          is_simple,
                          field_treat,
                          ARCHIVE_FIELD_NORMAL,
                          id);

    sscanf(value.c_str(), "%d", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type,
                                &value,
                                &id,
                                &version,
                                &is_simple,
                                &is_class,
                                &field_treat,
                                &referencing);

    if(!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval,
                          type,
                          "unsigned number",
                          is_simple,
                          field_treat,
                          ARCHIVE_FIELD_NORMAL,
                          id);

    sscanf(value.c_str(), "%u", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type,
                                &value,
                                &id,
                                &version,
                                &is_simple,
                                &is_class,
                                &field_treat,
                                &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval,
                          type,
                          "number",
                          is_simple,
                          field_treat,
                          ARCHIVE_FIELD_NORMAL, 
                          id);

    sscanf(value.c_str(), "%ld", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type,
                                &value,
                                &id,
                                &version,
                                &is_simple,
                                &is_class,
                                &field_treat,
                                &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval,
                          type,
                          "unsigned number",
                          is_simple,
                          field_treat,
                          ARCHIVE_FIELD_NORMAL,
                          id);

    sscanf(value.c_str(), "%lu", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type,
                                &value,
                                &id,
                                &version,
                                &is_simple,
                                &is_class,
                                &field_treat,
                                &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval,
                          type,
                          "number",
                          is_simple, 
                          field_treat,
                          ARCHIVE_FIELD_NORMAL,
                          id);

    sscanf(value.c_str(), "%lld", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "unsigned number", 
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    sscanf(value.c_str(), "%llu", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "number", 
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    sscanf(value.c_str(), "%hd", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("unsigned number", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "unsigned number",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    sscanf(value.c_str(), "%hu", &obj);

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("char", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "char",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    int   int_obj;
    sscanf(value.c_str(), "%d", &int_obj);
    obj = (char)int_obj;

    ar.register_reference(id, field_treat, &obj);
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
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "char*",
                          is_simple, field_treat, (ArchiveFieldKind)-1, id);

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
      obj = strdup(value.c_str());
      ar.register_reference(id, field_treat, obj);
    }
    else if ((obj = (char*)ar.get_reference_value(referencing)) == NULL)// ARCHIVE_FIELD_IS_REFERENCING
    {
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, NULL, referencing);
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

    ar.add_simple_field("char", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "char",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    int int_obj;
    sscanf(value.c_str(), "%d", &int_obj);
    obj = (signed char)int_obj;

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("unsigned char", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "unsigned char",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    unsigned int int_obj;
    sscanf(value.c_str(), "%u", &int_obj);
    obj = (unsigned char)int_obj;

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("float", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "float",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    FloatImpl<float> zorba_float(value.c_str());
    obj = zorba_float.getNumber();

    ar.register_reference(id, field_treat, &obj);
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

    ar.add_simple_field("double", strtemp, &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "double", 
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    FloatImpl<double> zorba_double(value.c_str());
    obj = zorba_double.getNumber();

    ar.register_reference(id, field_treat, &obj);
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, bool& obj)
{
  if (ar.is_serializing_out())
  {
    ar.add_simple_field("bool", obj ? "true" : "false", &obj, ARCHIVE_FIELD_NORMAL);
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "bool",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    if (value == "true")
    {
      obj = true;
    }
    else if (value == "false")
    {
      obj = false;
    }
    else
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
    }

    ar.register_reference(id, field_treat, &obj);
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
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "string",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);
    obj = value;

    ar.register_reference(id, field_treat, &obj);
  }
}


/*******************************************************************************

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
    char  *type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if(!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "std::string*",
                          is_simple, field_treat, (ArchiveFieldKind)-1, id);

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
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, NULL, referencing);
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
    std::string value;
    int   id;
    int   version;
    bool  is_simple = true;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id, &version,
                                &is_simple, &is_class, &field_treat, &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_simple_field(retval, type, "char[]",
                          is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    Base64Impl::Decode((const unsigned char*)value.c_str(), value.length(), obj);

    ar.register_reference(id, field_treat, &obj);
  }
}


}
}
