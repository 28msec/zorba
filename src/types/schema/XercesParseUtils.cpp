/*
 *  Copyright 2006-2008 FLWOR Foundation.
 *  Author: Cezar Andrei (cezar dot andrei at gmail dot com)
 *
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
#include "errors/error_manager.h"
#include <zorbatypes/numconversions.h>
#include "util/XmlWhitespace.h"
#include "system/globalenv.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"

using namespace std;

namespace zorba
{

// Parse Atomic Schema Types
bool XercesParseUtils::parseXSBoolean(xqpString textValue, store::Item_t &result)
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
    result = factory->createBoolean(value);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to boolean");
    return false;
  }
}

//numeric types
bool XercesParseUtils::parseXSInteger(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_integer;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createInteger(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to integer");
    return false;
  }
}

bool XercesParseUtils::parseXSPositiveInteger(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_positiveInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createPositiveInteger(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to positiveInteger");
    return false;
  }
}

bool XercesParseUtils::parseXSNonPositiveInteger(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_nonPositiveInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createNonPositiveInteger(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to nonPositiveInteger");
    return false;
  }
}

bool XercesParseUtils::parseXSNegativeInteger(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_negativeInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createNegativeInteger(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to negativeInteger");
    return false;
  }
}

bool XercesParseUtils::parseXSNonNegativeInteger(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_nonNegativeInteger;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_integer tvalue = Integer::parseLong(value);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createNonNegativeInteger(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to nonNegativeInteger");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedByte(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedByte;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_uchar;

    xqp_ubyte tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createUnsignedByte(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to unsignedByte");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedShort(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedShort;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_ushort;

    xqp_ushort tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createUnsignedShort(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to unignedShort");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedInt(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedInt;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    ulong value = xsval->fData.fValue.f_uint;

    xqp_uint tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createUnsignedInt(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to unsignedInt");
    return false;
  }
}

bool XercesParseUtils::parseXSUnsignedLong(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_unsignedLong;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    ulong value = xsval->fData.fValue.f_ulong;

    xqp_ulong tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createUnsignedLong(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to unsignedLong");
    return false;
  }
}

bool XercesParseUtils::parseXSByte(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_byte;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_char;

    xqp_byte tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createByte(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to byte");
    return false;
  }
}

bool XercesParseUtils::parseXSShort(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_short;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    short value = xsval->fData.fValue.f_short;

    xqp_short tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createShort(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to short");
    return false;
  }
}

bool XercesParseUtils::parseXSInt(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_int;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    int value = xsval->fData.fValue.f_int;

    xqp_int tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createInt(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to int");
    return false;
  }
}

bool XercesParseUtils::parseXSLong(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_long;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    long value = xsval->fData.fValue.f_long;

    xqp_long tvalue = value;

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createLong(tvalue);
    return true;
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to long");
    return false;
  }
}

bool XercesParseUtils::parseXSFloat(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_float;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //float value = xsval->fData.fValue.f_float;

    //xqp_float tvalue = value;

    //store::ItemFactory* factory = GENV_ITEMFACTORY;
    //result = factory->createFloat(tvalue);

    // remove following if xs:float will be represented by a C float
    //textValue = textValue.trim(" \n\r\t",4);
    textValue = xmlWhitespaceCollapse(textValue);
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_float n;
    if (NumConversions::strToFloat(textValue, n))
    {
      result = factory->createFloat(n);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to float");
  return false;
}

bool XercesParseUtils::parseXSDouble(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_double;
  XSValue::Status status = XSValue::st_Init;;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_Init )
  {
    //double value = xsval->fData.fValue.f_double;

    //xqp_double tvalue = value;
    //store::ItemFactory* factory = GENV_ITEMFACTORY;
    //result = factory->createDouble(tvalue);

    // remove following if xs:float will be represented by a C float
    //textValue = textValue.trim(" \n\r\t",4);
    textValue = xmlWhitespaceCollapse(textValue);
    store::ItemFactory* factory = GENV_ITEMFACTORY;
    xqp_double n;
    if (NumConversions::strToDouble(textValue, n))
    {
      result = factory->createDouble(n);
      return true;    
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to double");
  return false;
}

bool XercesParseUtils::parseXSDecimal(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
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
    result = factory->createDecimal(tvalue);
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to decimal");
    return false;
  }
}

// string types
bool XercesParseUtils::parseXSString(xqpString textValue, store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  textValue = xmlWhitespacePreserve(textValue);
  store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createString(textValue.getStore());
  return true;  

  //XMLCh* content = XMLString::transcode(textValue.c_str());    
  //XSValue::DataType datatype = XSValue::dt_string;
  //XSValue::Status status = XSValue::st_Init;;

 //   XSValue* xsval = XSValue::getActualValue(content, datatype, status);
  //XMLString::release(&content);

  //if ( status==XSValue::st_NoActVal )
  //{
  //  delete xsval;

  //  store::ItemFactory* factory = GENV_ITEMFACTORY;
  //  result = factory->createString(textValue.getStore());
  //}
  //else
  //{
  //  delete xsval;
  //  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
  //    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to string");
  //  return false;
  //}
}

bool XercesParseUtils::parseXSNormalizedString(xqpString textValue, store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  textValue = xmlWhitespaceReplace(textValue);
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  result = factory->createNormalizedString(textValue);
  return true;  
}

bool XercesParseUtils::parseXSToken(xqpString textValue, store::Item_t &result)
{
  // optimization posible since there is no pattern to be checked
  //textValue = xmlWhitespaceCollapse(textValue);
  //store::ItemFactory* factory = GENV_ITEMFACTORY;
  //result = factory->createToken(textValue.getStore());
  //return true;  

  textValue = xmlWhitespaceCollapse(textValue);
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_token;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createToken(textValue);
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to NMToken");
    return false;
  }
}

bool XercesParseUtils::parseXSNMToken(xqpString textValue, store::Item_t &result)
{
  textValue = xmlWhitespaceCollapse(textValue);

  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_NMTOKEN;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createNMTOKEN(textValue.getStore());
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to NMToken");
    return false;
  }
}

bool XercesParseUtils::parseXSName(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_Name;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createName(textValue.getStore());
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to Name");
    return false;
  }
}

bool XercesParseUtils::parseXSNCName(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_NCName;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createNCName(textValue.getStore());
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to NCName");
    return false;
  }
}

bool XercesParseUtils::parseXSID(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_ID;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createID(textValue.getStore());
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to ID");
    return false;
  }
}

bool XercesParseUtils::parseXSIDRef(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_IDREF;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createIDREF(textValue.getStore());
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to IDREF");
    return false;
  }
}

bool XercesParseUtils::parseXSEntity(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_ENTITY;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createENTITY(textValue.getStore());
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to ENTITY");
    return false;
  }
}

bool XercesParseUtils::parseXSNotation(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_NOTATION;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    result = factory->createNOTATION(textValue.getStore());
    return true;  
  }
  else
  {
    ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
      "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to NOTATION");
    return false;
  }
}

// date types
bool XercesParseUtils::parseXSDateTime(xqpString textValue, store::Item_t &result)
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
    //xqp_dateTime tValue;
    //DateTime::createDateTime( year<0 ? true : false , year, month, day, hour, min, sec,
    //  milisec , tz, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //result = factory->createDateTime(tValue);
    //result = factory->createDateTime(year, month, day, hour, minute, sec);
    xqp_dateTime dt;
    textValue = xmlWhitespaceCollapse(textValue);
    if (0 == DateTime::parseDateTime(textValue, dt))  // Warning: parsing code is not using Xerces
    {
      result = factory->createDateTime(dt);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to dateTime");
  return false;
}

bool XercesParseUtils::parseXSDate(xqpString textValue, store::Item_t &result)
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


    //xqp_date tValue;
    //Date::createDate( year, month, day, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //result = factory->createDate(tValue);
    xqp_date d;
    textValue = xmlWhitespaceCollapse(textValue);
    if (0 == DateTime::parseDate(textValue, d))  // Warning: parsing code is not using Xerces
    {
      result = factory->createDate(d);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to date");
  return false;
}

bool XercesParseUtils::parseXSTime(xqpString textValue, store::Item_t &result)
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
    //xqp_time tValue;
    //Time::createTime( hour, min, doubleSec , (const TimeZone)*tz, tValue);

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //result = factory->createTime(tValue);
    xqp_time t;
    textValue = xmlWhitespaceCollapse(textValue);
    if (0 == DateTime::parseTime(textValue, t))  // Warning: parsing code is not using Xerces
    {
      result = factory->createTime(t);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to time");
  return false;
}

bool XercesParseUtils::parseXSGYearMonth(xqpString textValue, store::Item_t &result)
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
    xqp_gYearMonth tValue;
    
    textValue = xmlWhitespaceCollapse(textValue);
    if (DateTime::parseGYearMonth(textValue, tValue)) // Warning: parsing code is not using Xerces
    {
      result = factory->createGYearMonth(tValue);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to gYearMonth");
  return false;
}

bool XercesParseUtils::parseXSGYear(xqpString textValue, store::Item_t &result)
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
    xqp_gYear tValue;
    
    textValue = xmlWhitespaceCollapse(textValue);
    if (DateTime::parseGYear(textValue, tValue))    // Warning: parsing code is not using Xerces
    {
      result = factory->createGYear(tValue);
      return true;  
    }
  }
  else
  {
  }
  
  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to gYear");
  return false;
}

bool XercesParseUtils::parseXSGMonthDay(xqpString textValue, store::Item_t &result)
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
    xqp_gMonthDay tValue;
    textValue = xmlWhitespaceCollapse(textValue);
    if (DateTime::parseGMonthDay(textValue, tValue))    // Warning: parsing code is not using Xerces
    {
      result = factory->createGMonthDay(tValue);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to gMonthDay");
  return false;
}

bool XercesParseUtils::parseXSGDay(xqpString textValue, store::Item_t &result)
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
    xqp_gDay tValue;
    textValue = xmlWhitespaceCollapse(textValue);
    if (DateTime::parseGDay(textValue, tValue))   // Warning: parsing code is not using Xerces
    {
      result = factory->createGDay(tValue);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to gDay");
  return false;
}

bool XercesParseUtils::parseXSGMonth(xqpString textValue, store::Item_t &result)
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
    xqp_gMonth tValue;
    textValue = xmlWhitespaceCollapse(textValue);
    if (DateTime::parseGMonth(textValue, tValue))   // Warning: parsing code is not using Xerces
    {
      result = factory->createGMonth(tValue);
      return true;  
    }
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to gDay");
  return false;
}

bool XercesParseUtils::parseXSDuration(xqpString textValue, store::Item_t &result)
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
    Duration_t tValue;
    textValue = xmlWhitespaceCollapse(textValue);
    if (Duration::parse_string(textValue, tValue))    // Warning: parsing code is not using Xerces
    {
      xqp_duration tValue_duration = &*tValue;
      result = factory->createDuration(tValue_duration);
      return true;  
    }
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to duration");
  return false;
}

bool XercesParseUtils::parseXSYearMonthDuration(xqpString textValue, store::Item_t &result)
{
  YearMonthDuration_t ymd_t;

  if (YearMonthDuration::parse_string(textValue, ymd_t))
  {
    xqp_duration d = ymd_t;
    store::ItemFactory* factory = GENV_ITEMFACTORY;

    result = factory->createDuration(d);
    return true;
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to yearMonthDuration");
  return false;
}

bool XercesParseUtils::parseXSDayTimeDuration(xqpString textValue, store::Item_t &result)
{
  DayTimeDuration_t dtd_t;

  if (DayTimeDuration::parse_string(textValue, dtd_t))
  {
    xqp_duration d = dtd_t;
    store::ItemFactory* factory = GENV_ITEMFACTORY;

    result = factory->createDuration(d);
    return true;
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to dayTimeDuration");
  return false;
}

bool XercesParseUtils::parseXSAnyAtomicType(xqpString textValue, store::Item_t &result)
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  result = factory->createUntypedAtomic(textValue.getStore());
  return true;  
}

bool XercesParseUtils::parseXSUntypedAtomic(xqpString textValue, store::Item_t &result)
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  result = factory->createUntypedAtomic(textValue.getStore());
  return true;  
}

bool XercesParseUtils::parseXSBase64Binary(xqpString textValue, store::Item_t &result)
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
    xqp_base64Binary tValue;// = static_cast<xqp_base64Binary>(textValue.c_str());
    

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    //textValue = xmlWhitespaceCollapse(textValue);
    result = factory->createBase64Binary(tValue);
    return true;  
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to base64Binary");
  return false;
}

bool XercesParseUtils::parseXSHexBinary(xqpString textValue, store::Item_t &result)
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
    xqp_hexBinary tValue;// = static_cast<xqp_hexBinary>(textValue.c_str());

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    textValue = xmlWhitespaceCollapse(textValue);
    result = factory->createHexBinary(tValue);
    return true;  
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to hexBinary");
  return false;
}

bool XercesParseUtils::parseXSAnyUri(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_anyURI;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    textValue = xmlWhitespaceCollapse(textValue);
    result = factory->createAnyURI(textValue.getStore());
    return true;  
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::FORG0001, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to anyUri");
  return false;
}

bool XercesParseUtils::parseXSQName(xqpString textValue, store::Item_t &result)
{
  XMLCh* content = XMLString::transcode(textValue.c_str());    
  XSValue::DataType datatype = XSValue::dt_QName;
  XSValue::Status status = XSValue::st_Init;

  auto_ptr<XSValue> xsval (XSValue::getActualValue(content, datatype, status));
  XMLString::release(&content);

  if ( status==XSValue::st_NoActVal )
  {

    store::ItemFactory* factory = GENV_ITEMFACTORY;
    textValue = xmlWhitespaceCollapse(textValue);
    
    // todo: get the right namespace from the current context
    xqpString lNamespace = "";
    xqpString lPrefix = "";
    xqpString lLocal = textValue;

    int32_t lIndex = textValue.indexOf(":");
    
    if (lIndex == 0) 
    {
      ZORBA_ERROR_DESC( ZorbaError::XQDY0074, 
        "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to QName");
    }
    else if ( lIndex>0 )
    {
      lPrefix = textValue.substr(0, lIndex);
      lLocal = textValue.substr(lIndex + 1);
    } 
    
    result = factory->createQName(lNamespace.getStore(), lPrefix.getStore(), lLocal.getStore());
    return true;  
  }
  else
  {
  }

  ZORBA_ERROR_DESC( ZorbaError::XQDY0074, 
    "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to QName");
  return false;
}

} // namespace zorba

#endif //#ifndef ZORBA_NO_XMLSCHEMA
