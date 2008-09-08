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
#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include "XercesParseUtils.h"
#include "StrX.h"
#include "LoadSchemaErrorHandler.h"
#include "PrintSchema.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "types/typeimpl.h"
#include "zorbaerrors/error_manager.h"
#include <zorbatypes/numconversions.h>
//#include "util/XmlWhitespace.h"
#include "system/globalenv.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"

using namespace std;

namespace zorba
{

// Parse Atomic Schema Types
bool XercesParseUtils::parseXSBoolean(
    const xqpStringStore_t& textValue,
    store::Item_t& result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
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
    ZORBA_ERROR_DESC(FORG0001, 
                     "String '" + textValue->str() + "' cannot be cast to boolean");
    return false;
  }
}

//numeric types
bool XercesParseUtils::parseXSInteger(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_integer;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createInteger(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to integer");
    return false;
  }
}


bool XercesParseUtils::parseXSPositiveInteger(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_positiveInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createPositiveInteger(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to positiveInteger");
    return false;
  }
}


bool XercesParseUtils::parseXSNonPositiveInteger(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_nonPositiveInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createNonPositiveInteger(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to nonPositiveInteger");
    return false;
  }
}


bool XercesParseUtils::parseXSNegativeInteger(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_negativeInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createNegativeInteger(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to negativeInteger");
    return false;
  }
}

bool XercesParseUtils::parseXSNonNegativeInteger(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_nonNegativeInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createNonNegativeInteger(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to nonNegativeInteger");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedByte(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedByte;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_uchar;

    xqp_ubyte tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedByte(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to unsignedByte");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedShort(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedShort;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_ushort;

    xqp_ushort tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedShort(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to unignedShort");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedInt(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedInt;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    ulong value = xsval->fData.fValue.f_uint;

    xqp_uint tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedInt(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to unsignedInt");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedLong(
    const xqpStringStore_t& textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedLong;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    ulong value = xsval->fData.fValue.f_ulong;

    xqp_ulong tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createUnsignedLong(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to unsignedLong");
    return false;
  }
}

bool XercesParseUtils::parseXSByte(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_byte;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_char;

    xqp_byte tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createByte(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to byte");
    return false;
  }
}

bool XercesParseUtils::parseXSShort(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_short;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    short value = xsval->fData.fValue.f_short;

    xqp_short tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createShort(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to short");
    return false;
  }
}

bool XercesParseUtils::parseXSInt(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_int;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_int;

    xqp_int tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createInt(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to int");
    return false;
  }
}

bool XercesParseUtils::parseXSLong(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_long;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_long tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createLong(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to long");
    return false;
  }
}

bool XercesParseUtils::parseXSFloat(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_float;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //float value = xsval->fData.fValue.f_float;

    //xqp_float tvalue = value;

    //store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createFloat(result, tvalue);

    // remove following if xs:float will be represented by a C float
    //textValue = textValue.trim(" \n\r\t",4);
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_float n;
    if (NumConversions::strToFloat(textValue2.getp(), n))
    {
      return factory->createFloat(result, n);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
                    "String '" + textValue->str() + "' cannot be cast to float");
  return false;
}

bool XercesParseUtils::parseXSDouble(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_double;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //double value = xsval->fData.fValue.f_double;

    //xqp_double tvalue = value;
    //store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createDouble(result, tvalue);

    // remove following if xs:float will be represented by a C float
    //textValue = textValue.trim(" \n\r\t",4);
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_double n;
    if (NumConversions::strToDouble(textValue2.getp(), n))
    {
      return factory->createDouble(result, n);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
                    "String '" + textValue->str() + "' cannot be cast to double");
  return false;
}

bool XercesParseUtils::parseXSDecimal(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_decimal;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    double value = xsval->fData.fValue.f_decimal.f_dvalue;

    xqp_decimal tvalue;
    Decimal::parseNativeDouble(value, tvalue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createDecimal(result, tvalue);
  }
  else
  {
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to decimal");
    return false;
  }
}

// string types
bool XercesParseUtils::parseXSString(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  xqpStringStore_t textValue2 = textValue->normalizeSpace();
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  return factory->createString(result, textValue2);

  //XMLCh* content = XMLString::transcode(textValue.c_str());    
  //XSValue::DataType datatype = XSValue::dt_string;
  //XSValue::Status status = XSValue::st_Init;;

 //   XSValue* xsval = XSValue::getActualValue(content, datatype, status);
  //XMLString::release(&content);

  //if ( status==XSValue::st_NoActVal )
  //{
  //  delete xsval;

  //  store::ItemFactory* factory = GENV_ITEMFACTORY;
  //  return factory->createString(result, textValue.getStore());
  //}
  //else
  //{
  //  delete xsval;
  //  ZORBA_ERROR_DESC( FORG0001, 
  //    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to string");
  //  return false;
  //}
}

bool XercesParseUtils::parseXSNormalizedString(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  xqpStringStore_t textValue2 = textValue->normalizeSpace();
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  return factory->createNormalizedString(result, textValue2);
}


bool XercesParseUtils::parseXSToken(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  //textValue = xmlWhitespaceCollapse(textValue);
  //store::ItemFactory* factory = GENV_ITEMFACTORY;
  //return factory->createToken(result, textValue.getStore());
  //return true;  

  xqpStringStore_t textValue2 = textValue->normalizeSpace();
  XMLCh* content = XMLString::transcode(textValue2->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to NMToken");
    return false;
  }
}


bool XercesParseUtils::parseXSNMToken(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue->normalizeSpace();

  XMLCh* content = XMLString::transcode(textValue2->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to NMToken");
    return false;
  }
}


bool XercesParseUtils::parseXSName(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;

  XMLCh* content = XMLString::transcode(textValue2->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to Name");
    return false;
  }
}


bool XercesParseUtils::parseXSNCName(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;

  XMLCh* content = XMLString::transcode(textValue2->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
                      "String '" + textValue->str() + "' cannot be cast to NCName");
    return false;
  }
}


bool XercesParseUtils::parseXSID(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;

  XMLCh* content = XMLString::transcode(textValue->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
      "String '" + textValue->str() + "' cannot be cast to ID");
    return false;
  }
}


bool XercesParseUtils::parseXSIDRef(
    const xqpStringStore_t& textValue, 
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;

  XMLCh* content = XMLString::transcode(textValue->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
      "String '" + textValue->str() + "' cannot be cast to IDREF");
    return false;
  }
}


bool XercesParseUtils::parseXSEntity(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;

  XMLCh* content = XMLString::transcode(textValue2->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
      "String '" + textValue->str() + "' cannot be cast to ENTITY");
    return false;
  }
}


bool XercesParseUtils::parseXSNotation(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;

  XMLCh* content = XMLString::transcode(textValue2->c_str());    
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
    ZORBA_ERROR_DESC( FORG0001, 
      "String '" + textValue->str() + "' cannot be cast to NOTATION");
    return false;
  }
}

// date types
bool XercesParseUtils::parseXSDateTime(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  // Warning: timezones are automaticaly normalized to Z
  XMLCh* content = XMLString::transcode(textValue->c_str());    
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
    //xqp_dateTime tValue;
    //DateTime::createDateTime( year<0 ? true : false , year, month, day, hour, min, sec,
    //  milisec , tz, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createDateTime(result, tValue);
    //return factory->createDateTime(result, year, month, day, hour, minute, sec);
    xqp_dateTime dt;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (0 == DateTime::parseDateTime(textValue2.getp(), dt))  // Warning: parsing code is not using Xerces
    {
      return factory->createDateTime(result, &dt);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to dateTime");
  return false;
}


bool XercesParseUtils::parseXSDate(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  // Warning: timezones are automaticaly normalized to Z
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_date;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    //int month   = xsval->fData.fValue.f_datetime.f_month;
    //int day     = xsval->fData.fValue.f_datetime.f_day;


    //xqp_date tValue;
    //Date::createDate( year, month, day, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createDate(result, tValue);
    xqp_date d;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (0 == DateTime::parseDate(textValue2.getp(), d))  // Warning: parsing code is not using Xerces
    {
      return factory->createDate(result, &d);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to date");
  return false;
}


bool XercesParseUtils::parseXSTime(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  // Warning: timezones are automaticaly normalized to Z
  XMLCh* content = XMLString::transcode(textValue->c_str());    
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
    //xqp_time tValue;
    //Time::createTime( hour, min, doubleSec , (const TimeZone)*tz, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //return factory->createTime(result, tValue);
    xqp_time t;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (0 == DateTime::parseTime(textValue2.getp(), t))  // Warning: parsing code is not using Xerces
    {
      return factory->createTime(result, &t);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to time");
  return false;
}


bool XercesParseUtils::parseXSGYearMonth(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_gYearMonth;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    //int month   = xsval->fData.fValue.f_datetime.f_month;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_gYearMonth tValue;
    
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (DateTime::parseGYearMonth(textValue2.getp(), tValue)) // Warning: parsing code is not using Xerces
    {
      return factory->createGYearMonth(result, &tValue);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to gYearMonth");
  return false;
}


bool XercesParseUtils::parseXSGYear(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_gYear;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int year    = xsval->fData.fValue.f_datetime.f_year;
    

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_gYear tValue;
    
    xqpStringStore_t textValue2 = textValue->normalizeSpace();

    if (DateTime::parseGYear(textValue2.getp(), tValue))    // Warning: parsing code is not using Xerces
    {
      return factory->createGYear(result, &tValue);
    }
  }
  else
  {
  }
  
  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to gYear");
  return false;
}


bool XercesParseUtils::parseXSGMonthDay(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_gMonthDay;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int month   = xsval->fData.fValue.f_datetime.f_month;
    //int day     = xsval->fData.fValue.f_datetime.f_day;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_gMonthDay tValue;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (DateTime::parseGMonthDay(textValue2.getp(), tValue))    // Warning: parsing code is not using Xerces
    {
      return factory->createGMonthDay(result, &tValue);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to gMonthDay");
  return false;
}


bool XercesParseUtils::parseXSGDay(
   const xqpStringStore_t& textValue,
   store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_gDay;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int day     = xsval->fData.fValue.f_datetime.f_day;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_gDay tValue;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (DateTime::parseGDay(textValue2.getp(), tValue))   // Warning: parsing code is not using Xerces
    {
      return factory->createGDay(result, &tValue);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to gDay");
  return false;
}


bool XercesParseUtils::parseXSGMonth(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_gMonth;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //int month   = xsval->fData.fValue.f_datetime.f_month;


    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_gMonth tValue;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (DateTime::parseGMonth(textValue2.getp(), tValue))   // Warning: parsing code is not using Xerces
    {
      return factory->createGMonth(result, &tValue);
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to gDay");
  return false;
}


bool XercesParseUtils::parseXSDuration(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
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
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    if (0 == Duration::parseDuration(textValue2.getp(), tValue))    // Warning: parsing code is not using Xerces
      return factory->createDuration(result, &tValue);
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to duration");
  return false;
}


bool XercesParseUtils::parseXSYearMonthDuration(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  Duration d;

  if (0 == Duration::parseYearMonthDuration(textValue.getp(), d))
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createYearMonthDuration(result, &d);
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to yearMonthDuration");
  return false;
}


bool XercesParseUtils::parseXSDayTimeDuration(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  Duration d;

  if (0 == Duration::parseDayTimeDuration(textValue.getp(), d))
  {
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createDayTimeDuration(result, &d);
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to dayTimeDuration");
  return false;
}


bool XercesParseUtils::parseXSAnyAtomicType(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  return factory->createUntypedAtomic(result, textValue2);
}


bool XercesParseUtils::parseXSUntypedAtomic(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  xqpStringStore_t textValue2 = textValue;
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  return factory->createUntypedAtomic(result, textValue2);
}


bool XercesParseUtils::parseXSBase64Binary(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_base64Binary;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //char* textValue = xsval->fData.fValue.f_byteVal;
    //todo set tValue
    xqp_base64Binary tValue;// = static_cast<xqp_base64Binary>(textValue.c_str());
    

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //textValue = xmlWhitespaceCollapse(textValue);
    return factory->createBase64Binary(result, tValue);
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to base64Binary");
  return false;
}


bool XercesParseUtils::parseXSHexBinary(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_hexBinary;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //char* textValue = xsval->fData.fValue.f_byteVal;
    //todo set tValue
    xqp_hexBinary tValue;// = static_cast<xqp_hexBinary>(textValue.c_str());

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    return factory->createHexBinary(result, tValue);
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to hexBinary");
  return false;
}


bool XercesParseUtils::parseXSAnyUri(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_anyURI;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    return factory->createAnyURI(result, textValue2);
  }
  else
  {
  }

  ZORBA_ERROR_DESC( FORG0001, 
    "String '" + textValue->str() + "' cannot be cast to anyUri");
  return false;
}


bool XercesParseUtils::parseXSQName(
    const xqpStringStore_t& textValue,
    store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue->c_str());    
  XSValue::DataType datatype = XSValue::dt_QName;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqpStringStore_t textValue2 = textValue->normalizeSpace();
    
    // todo: get the right namespace from the current context
    xqpStringStore_t lNamespace = new xqpStringStore("");
    xqpStringStore_t lPrefix;
    xqpStringStore_t lLocal;

    int32_t lIndex = textValue2->indexOf(":");
    
    if (lIndex == 0) 
    {
      ZORBA_ERROR_DESC( XQDY0074, 
        "String '" + textValue->str() + "' cannot be cast to QName");
    }
    else if ( lIndex > 0 )
    {
      lPrefix = textValue2->substr(0, lIndex);
      lLocal = textValue2->substr(lIndex + 1, textValue2->bytes());
    } 
    
    return factory->createQName(result, lNamespace, lPrefix, lLocal);
  }
  else
  {
  }

  ZORBA_ERROR_DESC( XQDY0074, 
    "String '" + textValue->str() + "' cannot be cast to QName");
  return false;
}

} // namespace zorba

#endif //#ifndef ZORBA_NO_XMLSCHEMA
