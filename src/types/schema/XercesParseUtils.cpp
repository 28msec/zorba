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
#include "stdafx.h"

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include "xercesIncludes.h"
#include <xercesc/util/XMLString.hpp>
#include "XercesParseUtils.h"
#ifdef CYGWIN
#undef WIN32
#endif
#include "StrX.h"
#include "LoadSchemaErrorHandler.h"
#include "PrintSchema.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "types/typeimpl.h"
#include "diagnostics/xquery_diagnostics.h"
#include <zorbatypes/numconversions.h>
#include "system/globalenv.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "util/utf8_util.h"

using namespace std;
XERCES_CPP_NAMESPACE_USE;

namespace zorba
{

// Parse Atomic Schema Types
bool XercesParseUtils::parseXSBoolean(
    const zstring& textValue,
    store::Item_t& result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_boolean;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    bool value = xsval->fData.fValue.f_bool;

    //store::ItemFactory* factory = Zorba::getItemFactory();
    //RootTypeManager& ts = GENV_TYPESYSTEM;
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createBoolean(result, value);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "boolean" )
    );
  }
}

//numeric types
bool XercesParseUtils::parseXSInteger(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_integer;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xs_integer tvalue(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createInteger(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "integer" )
    );
  }
}


bool XercesParseUtils::parseXSPositiveInteger(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_positiveInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xs_integer tvalue(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createPositiveInteger(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001,
      ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "positiveInteger" )
    );
  }
}


bool XercesParseUtils::parseXSNonPositiveInteger(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_nonPositiveInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xs_integer tvalue(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createNonPositiveInteger(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001,
      ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "nonPositiveInteger" )
    );
  }
}


bool XercesParseUtils::parseXSNegativeInteger(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_negativeInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xs_integer tvalue (value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createNegativeInteger(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001,
      ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "negativeInteger" )
    );
  }
}

bool XercesParseUtils::parseXSNonNegativeInteger(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_nonNegativeInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xs_integer tvalue(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createNonNegativeInteger(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001,
      ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "nonNegativeInteger" )
    );
  }
}

bool XercesParseUtils::parseXSUnsignedByte(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedByte;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_uchar;

    xs_unsignedByte tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedByte(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, 
      ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "unsignedByte" )
    );
  }
}

bool XercesParseUtils::parseXSUnsignedShort(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedShort;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_ushort;

    xs_unsignedShort tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedShort(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "unsignedShort" )
    );
  }
}

bool XercesParseUtils::parseXSUnsignedInt(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedInt;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    ulong value = xsval->fData.fValue.f_uint;

    xs_unsignedInt tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedInt(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "unsignedInt" )
    );
  }
}

bool XercesParseUtils::parseXSUnsignedLong(
    const zstring& textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedLong;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    ulong value = xsval->fData.fValue.f_ulong;

    xs_unsignedLong tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedLong(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, 
      ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "unsignedLong" )
    );
  }
}

bool XercesParseUtils::parseXSByte(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_byte;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_char;

    xs_byte tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createByte(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "byte" )
    );
  }
}

bool XercesParseUtils::parseXSShort(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_short;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    short value = xsval->fData.fValue.f_short;

    xs_short tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createShort(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "short" )
    );
  }
}

bool XercesParseUtils::parseXSInt(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_int;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_int;

    xs_int tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createInt(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "int" )
    );
  }
}

bool XercesParseUtils::parseXSLong(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_long;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xs_long tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createLong(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "long" )
    );
  }
}

bool XercesParseUtils::parseXSFloat(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_float;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //float value = xsval->fData.fValue.f_float;

    //xs_float tvalue = value;

    //store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createFloat(result, tvalue);

    // remove following if xs:float will be represented by a C float
    //textValue = textValue.trim(" \n\r\t",4);
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);
    try {
      xs_float const n(textValue2.c_str());
      return GENV_ITEMFACTORY->createFloat(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "float" )
  );
}

bool XercesParseUtils::parseXSDouble(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_double;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //double value = xsval->fData.fValue.f_double;

    //xs_double tvalue = value;
    //store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createDouble(result, tvalue);

    // remove following if xs:float will be represented by a C float
    //textValue = textValue.trim(" \n\r\t",4);
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    try {
      xs_double const n(textValue2.c_str());
      return factory->createDouble(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "double" )
  );
}

bool XercesParseUtils::parseXSDecimal(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_decimal;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    double value = xsval->fData.fValue.f_decimal.f_dvalue;
    xs_decimal const tvalue(value);
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createDecimal(result, tvalue);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "decimal" )
    );
  }
}

// string types
bool XercesParseUtils::parseXSString(
    const zstring& textValue,
    store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  return factory->createString(result, textValue2);
}

bool XercesParseUtils::parseXSNormalizedString(
    const zstring& textValue,
    store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  
  return factory->createNormalizedString(result, textValue2);
}


bool XercesParseUtils::parseXSToken(
    const zstring& textValue,
    store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  //textValue = xmlWhitespaceCollapse(textValue);
  //store::ItemFactory* factory = GENV_ITEMFACTORY;
  //return factory->createToken(result, textValue.getStore());
  //return true;  

  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);
  XMLCh* content = XMLString::transcode(textValue2.c_str());    
  XSValue::DataType datatype = XSValue::dt_token;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;

return factory->createToken(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "NMToken" )
    );
  }
}


bool XercesParseUtils::parseXSNMToken(
    const zstring& textValue,
    store::Item_t &result)
{
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);

  XMLCh* content = XMLString::transcode(textValue2.c_str());    
  XSValue::DataType datatype = XSValue::dt_NMTOKEN;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    
    return factory->createNMTOKEN(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "NMToken" )
    );
  }
}


bool XercesParseUtils::parseXSName(
    const zstring& textValue,
    store::Item_t &result)
{
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);

  XMLCh* content = XMLString::transcode(textValue2.c_str());    
  XSValue::DataType datatype = XSValue::dt_Name;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;

    return factory->createName(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "Name" )
    );
  }
}


bool XercesParseUtils::parseXSNCName(
    const zstring& textValue,
    store::Item_t &result)
{
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);

  XMLCh* content = XMLString::transcode(textValue2.c_str());    
  XSValue::DataType datatype = XSValue::dt_NCName;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;

    return factory->createNCName(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "NCName" )
    );
  }
}


bool XercesParseUtils::parseXSID(
    const zstring& textValue,
    store::Item_t &result)
{
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);

  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_ID;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;

    return factory->createID(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "ID" )
    );
  }
}


bool XercesParseUtils::parseXSIDRef(
    const zstring& textValue, 
    store::Item_t &result)
{
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);

  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_IDREF;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    
    return factory->createIDREF(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "IDREF" )
    );
  }
}


bool XercesParseUtils::parseXSEntity(
    const zstring& textValue,
    store::Item_t &result)
{
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);

  XMLCh* content = XMLString::transcode(textValue2.c_str());    
  XSValue::DataType datatype = XSValue::dt_ENTITY;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    
    return factory->createENTITY(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "ENTITY" )
    );
  }
}


bool XercesParseUtils::parseXSNotation(
    const zstring& textValue,
    store::Item_t &result)
{
  zstring textValue2;
  utf8::normalize_whitespace(textValue, &textValue2);

  XMLCh* content = XMLString::transcode(textValue2.c_str());    
  XSValue::DataType datatype = XSValue::dt_NOTATION;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;

    return factory->createNOTATION(result, textValue2);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "NOTATION" )
    );
  }
}

// date types
bool XercesParseUtils::parseXSDateTime(
    const zstring& textValue,
    store::Item_t &result)
{
  // Warning: timezones are automaticaly normalized to Z
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_dateTime;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    //int month   = xsval->fData.fValue.f_datetime.f_month;
    //int day     = xsval->fData.fValue.f_datetime.f_day;
    //int hour    = xsval->fData.fValue.f_datetime.f_hour;
    //int min     = xsval->fData.fValue.f_datetime.f_min;
    //int sec     = xsval->fData.fValue.f_datetime.f_second;
    //double msec = xsval->fData.fValue.f_datetime.f_milisec;
    //int milisec = (int)(msec*1000000);


    //TimeZone_t tz;
    //TimeZone::createTimeZone(0,0,0, tz);
    //xs_dateTime tValue;
    //DateTime::createDateTime( year<0 ? true : false , year, month, day, hour, min, sec,
    //  milisec , tz, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createDateTime(result, tValue);
    //return factory->createDateTime(result, year, month, day, hour, minute, sec);
    xs_dateTime dt;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (0 == DateTime::parseDateTime(textValue2.c_str(), textValue2.size(), dt))  
    {
      return factory->createDateTime(result, &dt);
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "dateTime" )
  );
}


bool XercesParseUtils::parseXSDate(
    const zstring& textValue,
    store::Item_t &result)
{
  // Warning: timezones are automaticaly normalized to Z
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_date;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    //int month   = xsval->fData.fValue.f_datetime.f_month;
    //int day     = xsval->fData.fValue.f_datetime.f_day;


    //xs_date tValue;
    //Date::createDate( year, month, day, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createDate(result, tValue);
    xs_date d;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (0 == DateTime::parseDate(textValue2.c_str(), textValue2.size(), d))  
    {
      return factory->createDate(result, &d);
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "date" )
  );
}


bool XercesParseUtils::parseXSTime(
    const zstring& textValue,
    store::Item_t &result)
{
  // Warning: timezones are automaticaly normalized to Z
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_time;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int hour    = xsval->fData.fValue.f_datetime.f_hour;
    //int min     = xsval->fData.fValue.f_datetime.f_min;
    //int sec     = xsval->fData.fValue.f_datetime.f_second;
    //double msec = xsval->fData.fValue.f_datetime.f_milisec;
    //
    //double doubleSec = msec + sec;


    //TimeZone_t tz;
    //TimeZone::createTimeZone(0,0,0, tz);
    //xs_time tValue;
    //Time::createTime( hour, min, doubleSec , (const TimeZone)*tz, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createTime(result, tValue);
    xs_time t;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (0 == DateTime::parseTime(textValue2.c_str(), textValue2.size(), t))
    {
      return factory->createTime(result, &t);
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "time" )
  );
}


bool XercesParseUtils::parseXSGYearMonth(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_gYearMonth;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    //int month   = xsval->fData.fValue.f_datetime.f_month;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xs_gYearMonth tValue;
    
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (DateTime::parseGYearMonth(textValue2.c_str(), textValue2.size(), tValue))
    {
      return factory->createGYearMonth(result, &tValue);
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "gYearMonth" )
  );
}


bool XercesParseUtils::parseXSGYear(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_gYear;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xs_gYear tValue;
    
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (DateTime::parseGYear(textValue2.c_str(), textValue2.size(), tValue))
    {
      return factory->createGYear(result, &tValue);
    }
  }
  
  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "gYear" )
  );
}


bool XercesParseUtils::parseXSGMonthDay(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_gMonthDay;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int month   = xsval->fData.fValue.f_datetime.f_month;
    //int day     = xsval->fData.fValue.f_datetime.f_day;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xs_gMonthDay tValue;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (DateTime::parseGMonthDay(textValue2.c_str(), textValue2.size(), tValue))
    {
      return factory->createGMonthDay(result, &tValue);
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "gMonthDay" )
  );
}


bool XercesParseUtils::parseXSGDay(
   const zstring& textValue,
   store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_gDay;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int day     = xsval->fData.fValue.f_datetime.f_day;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xs_gDay tValue;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (DateTime::parseGDay(textValue2.c_str(), textValue2.size(), tValue))
    {
      return factory->createGDay(result, &tValue);
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "gDay" )
  );
}


bool XercesParseUtils::parseXSGMonth(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_gMonth;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int month   = xsval->fData.fValue.f_datetime.f_month;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xs_gMonth tValue;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (DateTime::parseGMonth(textValue2.c_str(), textValue2.size(), tValue))
    {
      return factory->createGMonth(result, &tValue);
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "gDay" )
  );
}


bool XercesParseUtils::parseXSDuration(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_duration;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    //int month   = xsval->fData.fValue.f_datetime.f_month;
    //int day     = xsval->fData.fValue.f_datetime.f_day;
    //int hour    = xsval->fData.fValue.f_datetime.f_hour;
    //int min     = xsval->fData.fValue.f_datetime.f_min;
    //int sec     = xsval->fData.fValue.f_datetime.f_second;
    //double msec = xsval->fData.fValue.f_datetime.f_milisec;
    //int milisec = (int)(msec*1000000);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    Duration tValue;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    // Warning: parsing code is not using Xerces
    if (0 == Duration::parseDuration(textValue2.c_str(), textValue2.size(), tValue))
      return factory->createDuration(result, &tValue);
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "duration" )
  );
}


bool XercesParseUtils::parseXSYearMonthDuration(
    const zstring& textValue,
    store::Item_t &result)
{
  Duration d;

  if (0 == Duration::parseYearMonthDuration(textValue.c_str(), textValue.size(), d))
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createYearMonthDuration(result, &d);
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001,
    ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "yearMonthDuration" )
  );
}


bool XercesParseUtils::parseXSDayTimeDuration(
    const zstring& textValue,
    store::Item_t &result)
{
  Duration d;

  if (0 == Duration::parseDayTimeDuration(textValue.c_str(), textValue.size(), d))
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createDayTimeDuration(result, &d);
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001,
    ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "dayTimeDuration" )
  );
}


bool XercesParseUtils::parseXSAnyAtomicType(
    const zstring& textValue,
    store::Item_t &result)
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  zstring tmp = textValue.str();
  return factory->createUntypedAtomic(result, tmp);
}


bool XercesParseUtils::parseXSUntypedAtomic(
    const zstring& textValue,
    store::Item_t &result)
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  zstring tmp = textValue.str();
  return factory->createUntypedAtomic(result, tmp);
}


bool XercesParseUtils::parseXSBase64Binary(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_base64Binary;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //char* textValue = xsval->fData.fValue.f_byteVal;
    //todo set tValue
    xs_base64Binary tValue;// = static_cast<xs_base64Binary>(textValue.c_str());
    

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //textValue = xmlWhitespaceCollapse(textValue);
    return factory->createBase64Binary(result, tValue);
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001,
    ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "base64Binary" )
  );
}


bool XercesParseUtils::parseXSHexBinary(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_hexBinary;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //char* textValue = xsval->fData.fValue.f_byteVal;
    //todo set tValue
    xs_hexBinary tValue;// = static_cast<xs_hexBinary>(textValue.c_str());

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createHexBinary(result, tValue);
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "hexBinary" )
  );
}


bool XercesParseUtils::parseXSAnyUri(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_anyURI;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);

    return factory->createAnyURI(result, textValue2);
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001, ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), "anyURI" )
  );
}


bool XercesParseUtils::parseXSQName(
    const zstring& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_QName;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    zstring textValue2;
    utf8::normalize_whitespace(textValue, &textValue2);
    
    // todo: get the right namespace from the current context
    zstring lNamespace;
    zstring lPrefix;
    zstring lLocal;

    size_t lIndex = textValue2.find_first_of(":");
    
    if (lIndex == 0) 
    {
      throw XQUERY_EXCEPTION(
        err::XQDY0074, ERROR_PARAMS( textValue.str() )
      );
    }
    else if ( lIndex > 0 )
    {
      lPrefix = textValue2.substr(0, lIndex);
      lLocal = textValue2.substr(lIndex + 1, textValue2.size());
    } 
    
    return factory->createQName(result, lNamespace, lPrefix, lLocal);
  }

  throw XQUERY_EXCEPTION( err::XQDY0074, ERROR_PARAMS( textValue.str() ) );
}

} // namespace zorba

#endif /* ZORBA_NO_XMLSCHEMA */
/* vim:set et sw=2 ts=2: */
