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

#include "store/api/iterator.h"
#include "store/api/item_factory.h"

#include "util/string_util.h"
#include "util/utf8_util.h"
#include "util/converters/json_converter.h"

#include "jansson.h"

#include "context/namespace_context.h"
#include "context/static_context.h"

#include "system/globalenv.h"


namespace zorba
{

json_t* getValue(
    const char* aJSON,
    const zstring::size_type aLen,
    zstring& error_log);


std::string  WStringToString(const std::wstring& s);


bool create_Node_Helper(
    store::Item_t aParent,
    const zstring& aBaseUri,
    zstring aName,
    store::Item_t* aResult = NULL);


bool create_Attribute_Helper(
    store::Item_t aParent,
    zstring aName,
    zstring aValue,
    store::Item_t* aResult = NULL);


bool create_Pair_Helper(
    store::Item_t aParent,
    zstring& aBaseUri,
    store::Item_t* aResult,
    zstring aName,
    zstring aType,
    zstring& aValue,
    bool haveValue = false);


void parse_Json_value(
    json_t** aValue,
    store::Item_t aParent,
    const zstring& aBaseUri,
    store::Item_t* aResult);


void parse_Json_ML_value(
    json_t** aValue,
    store::Item_t aParent,
    zstring& aBaseUri,
    store::Item_t* aResult);


bool parse_element(
    const store::Item* aElement,
    zstring& aJsonString,
    zstring& aErrorLog,
    const zstring& aParentType);


bool parse_child(
    const store::Item* aElement,
    zstring& aJsonString,
    zstring& aErrorLog,
    const zstring& aParentType);


bool get_value(
    const store::Item* aElement,
    zstring& aValue);

void replace_special_chars(
    zstring& aValue)
{
  zorba::ascii::replace_all(aValue, "\\", "\\\\");  //reverse solidus
  zorba::ascii::replace_all(aValue, "\"", "\\\"");  //quotation mark
  zorba::ascii::replace_all(aValue, "\b", "\\b" );  //backspace
  zorba::ascii::replace_all(aValue, "\f", "\\f" );  //formfeed
  zorba::ascii::replace_all(aValue, "\n", "\\n" );  //new line
  zorba::ascii::replace_all(aValue, "\r", "\\r" );  //carriage return
  zorba::ascii::replace_all(aValue, "\t", "\\t" );  //horizontal tab
}


bool JSON_parse(
    const char* aJsonString,
    const zstring::size_type aLength,
    store::Item_t& aElement,
    const zstring& aBaseUri,
    zstring& aErrorLog)
{
  //std::auto_ptr<json::value> lValue(getValue(aJsonString, aLength, aErrorLog));
  //if( !aErrorLog.empty() )
  //  return false;

  //json::vector_list_t::iterator lVectIter;
  //json::vector_list_t * lVect = lValue->getchildrenlist();

  //create_Node_Helper(NULL, aBaseUri, "json", &aElement);
  //create_Attribute_Helper(aElement, "type", "object");

  //if( lVect != 0 )
  //{
  //  for ( lVectIter=lVect->begin(); lVectIter != lVect->end(); ++lVectIter )
  //  {
  //    store::Item_t lNewNode = NULL;
  //    parse_Json_value(&*lVectIter, aElement, aBaseUri, &lNewNode);
  //  }
  //}

  return true;
}


bool JSON_serialize(
    const store::Item* aElement,
    zstring& aJsonString,
    zstring& aErrorLog)
{
  aJsonString.clear();
  bool lResult = true;

  if ( aElement == NULL )
  {
    aErrorLog = "Passed a NULL element to the JSON serializer.";
    return false;
  }

  zstring lName;
  aElement->getNodeName()->getStringValue2(lName);

  if( ! ZSTREQ(lName, "json") )
  {
    aErrorLog = "This is not a JSON element.";
    return false;
  }

  aJsonString.append("{");

  lResult = parse_child(aElement, aJsonString, aErrorLog, "object");

  if( lResult )
    aJsonString.append("}");

  return lResult;
}


//helper functions
bool create_Type_Helper(store::Item_t& result, zstring type_name)
{
  zstring xs_ns("http://www.w3.org/2001/XMLSchema");
  zstring xs_pre("xs");
  return GENV_ITEMFACTORY->createQName(result, xs_ns, xs_pre, type_name);
}


bool create_QName_Helper(store::Item_t& result, zstring name)
{
  zstring ns;//ZORBA_JSON_FN_NS);
  zstring pre;//zorba-json");
  return GENV_ITEMFACTORY->createQName(result, ns, pre, name);
}


bool create_Node_Helper(
    store::Item_t aParent,
    const zstring& aBaseUri,
    zstring aName,
    store::Item_t* aResult)
{
  store::Item_t lQname, lTempResult, lTypeQname;
  store::NsBindings lBindings;

  create_QName_Helper(lQname, aName);
  create_Type_Helper(lTypeQname, "untyped");

  zstring baseuri = aBaseUri;

  bool lStatus = GENV_ITEMFACTORY->createElementNode(lTempResult,
                                                     aParent,
                                                     lQname,
                                                     lTypeQname,
                                                     true,
                                                     false,
                                                     lBindings,
                                                     baseuri);

  if ( aResult != NULL )
    *aResult = lTempResult;

  return lStatus;
}


bool create_Attribute_Helper(
    store::Item_t aParent,
    zstring aName,
    zstring aValue,
    store::Item_t* aResult)
{
  store::Item_t lQname, lTempResult, lStrItem;
  store::Item_t lTypeQname;

  create_QName_Helper(lQname, aName);
  create_Type_Helper(lTypeQname, "string");

  GENV_ITEMFACTORY->createString(lStrItem, aValue);

  GENV_ITEMFACTORY->createAttributeNode(lTempResult,
                                        aParent,
                                        lQname,
                                        lTypeQname,
                                        lStrItem);
  if ( aResult != NULL )
    *aResult = lTempResult;

  return true;
}


bool create_Pair_Helper(
    store::Item_t aParent,
    const zstring& aBaseUri,
    store::Item_t* aResult,
    zstring aName,
    zstring aType,
    zstring& aValue,
    bool haveValue = false)
{
  bool lRet = true;
  if( !aName.empty() )
  {
    lRet = create_Node_Helper(aParent, aBaseUri, "pair", aResult);
    if( lRet )
      lRet = create_Attribute_Helper(*aResult, "name", aName, NULL);
  }
  else
    lRet = create_Node_Helper(aParent, aBaseUri, "item", aResult);

  if( lRet )
    lRet = create_Attribute_Helper(*aResult, "type", aType, NULL);

  if (haveValue)
  {
    store::Item_t lTextValue;
    GENV_ITEMFACTORY->createTextNode(lTextValue, *aResult, aValue);
  }

  return lRet;
}


json_t* getValue(const char* aJSON, const zstring::size_type aLen, zstring& aErrorLog)
{
  ////transforn from UTF-8 to UCS-4 using ICU
  //wchar_t *lUCS4;
  //unicode::size_type lUCS4Len;
  //utf8::to_wchar_t(
  //  aJSON, static_cast<unicode::size_type>( aLen ), &lUCS4, &lUCS4Len
  //);

  //json::parser lParser;
  //json::value* lValue = lParser.parse(lUCS4, lUCS4Len);
  //std::wstring lErr = lParser.printerrors();
  //delete[] lUCS4;

  ////transform from UCS-4 to UTF-8
  //utf8::to_string(lErr.c_str(), &aErrorLog);
  //return lValue;
  return 0;
}

void parse_Json_value(
    json_t** aValue,
    store::Item_t aParent,
    const zstring& aBaseUri,
    store::Item_t* aResult)
{
  //json::vector_list_t::iterator lVectIter;
  //json::vector_list_t * lVect;

  //json::array_list_t::iterator lArrtIter;
  //json::array_list_t * lArr;

  //store::Item_t lItemObj, lItemArr;

  //if( aValue!=0 )
  //{
  //  zstring lName;
  //  utf8::to_string( (*aValue)->getname(), &lName );

  //  zstring empty;

  //  switch((*aValue)->getdatatype())
  //  {
  //  case json::datatype::_array:
  //  {
  //    create_Pair_Helper(aParent, aBaseUri, aResult, lName,
  //                       "array", empty);

  //    lArr = (*aValue)->getarraylist();
  //    if( lArr != 0 )
  //    {
  //      for ( lArrtIter = lArr->begin(); lArrtIter != lArr->end(); ++lArrtIter )
  //        parse_Json_value(&*lArrtIter, *aResult, aBaseUri, &lItemArr);
  //    }
  //    break;
  //  }
  //  case json::datatype::_object:
  //  {
  //    create_Pair_Helper(aParent, aBaseUri, aResult, lName,
  //                       "object", empty);

  //    lVect = (*aValue)->getchildrenlist();
  //    if( lVect != 0 )
  //    {
  //      for ( lVectIter = lVect->begin(); lVectIter != lVect->end(); ++lVectIter )
  //        parse_Json_value(&*lVectIter, *aResult, aBaseUri, &lItemObj);
  //    }
  //    break;
  //  }
  //  default:
  //    std::wstring * lWtmp = (*aValue)->getstring();

  //    zstring lVal;
  //    utf8::to_string( *lWtmp, &lVal );
  //    replace_special_chars(lVal);

  //    bool haveVal = true;

  //    delete lWtmp;

  //    zstring lType;
  //    if ((*aValue)->getdatatype() == json::datatype::_string)
  //    {
  //      lType = "string";
  //    }
  //    else if ((*aValue)->getdatatype() == json::datatype::_literal)
  //    {
  //      if( ZSTREQ(lVal, "null") )
  //      {
  //        haveVal = false;
  //        lType = "null";
  //      }
  //      else
  //      {
  //        lType = "boolean";
  //      }
  //    }
  //    else if (((*aValue)->getdatatype() == json::datatype::_number) ||
  //             ((*aValue)->getdatatype() == json::datatype::_fixed_number))
  //    {
  //      lType = "number";
  //    }

  //    create_Pair_Helper(aParent, aBaseUri, aResult, lName, lType, lVal, haveVal);
  //    break;
  //  }
  //}
}


void parse_Json_ML_value(
    json_t** aValue,
    store::Item_t aParent,
    const zstring& aBaseUri,
    store::Item_t* aResult)
{
  //json::vector_list_t::iterator lVectIter;
  //json::vector_list_t * lVect;

  //json::array_list_t::iterator lArrIter;
  //json::array_list_t * lArr;

  //store::Item_t lItemObj, lTextValue;

  //if( aValue != 0 )
  //{
  //  switch((*aValue)->getdatatype())
  //  {
  //  case json::datatype::_array:
  //    lArr = (*aValue)->getarraylist();
  //    lArrIter = lArr->begin();
  //    if((*lArrIter)->getdatatype() == json::datatype::_string)
  //    {
  //      std::wstring *lWtmp = (*lArrIter)->getstring();
  //      zstring lName;
  //      utf8::to_string( *lWtmp, &lName );
  //      delete lWtmp;

  //      create_Node_Helper(aParent, aBaseUri, lName, aResult);
  //      ++lArrIter;

  //      for ( ; lArrIter != lArr->end(); ++lArrIter )
  //      {
  //        parse_Json_ML_value(&*lArrIter, *aResult, aBaseUri, &lItemObj);
  //      }
  //    }
  //    break;

  //  case json::datatype::_object:
  //    lVect = (*aValue)->getchildrenlist();
  //    if( lVect != 0 )
  //    {
  //      for ( lVectIter = lVect->begin(); lVectIter != lVect->end(); ++lVectIter )
  //      {
  //        zstring lName;
  //        utf8::to_string( (*lVectIter)->getname(), &lName );
  //        std::wstring * lWtmp = (*lVectIter)->getstring();
  //        zstring lText;
  //        utf8::to_string( *lWtmp, &lText );
  //        delete lWtmp;

  //        create_Attribute_Helper(aParent, lName, lText, NULL);
  //      }
  //    }
  //    break;

  //  default:
  //    std::wstring * lWtmp = (*aValue)->getstring();
  //    zstring lText;
  //    utf8::to_string( *lWtmp, &lText );
  //    replace_special_chars(lText);
  //    delete lWtmp;

  //    if( ! ZSTREQ(lText, "null") )
  //      GENV_ITEMFACTORY->createTextNode(lTextValue, aParent, lText);
  //    break;
  //  }
  //}
}


bool parse_element(
    const store::Item* aElement,
    zstring& aJsonString,
    zstring& aErrorLog,
    const zstring& aParentType)
{
  store::Iterator_t lAttrIt, lChildrenIt;
  store::Item_t     lAttr, lChild;

  bool lResult = true;
  zstring lName;
  zstring lType;

  lAttrIt = aElement->getAttributes();
  lAttrIt->open();
  while (lAttrIt->next(lAttr))
  {
    if (lAttr->getNodeKind() == store::StoreConsts::attributeNode)
    {
      if(ZSTREQ(lAttr->getNodeName()->getStringValue(), "type"))
        lAttr->getStringValue2(lType);
      else if(ZSTREQ(lAttr->getNodeName()->getStringValue(), "name"))
        lAttr->getStringValue2(lName);
    }
  }
  lAttrIt->close();

  if(lType.empty())
  {
    aErrorLog = "Element does not have a 'type' attribute defined.";
    return false;
  }

  if(ZSTREQ(lType, "object"))
  {
    if(!lName.empty())
    {
      aJsonString.append("\"");
      aJsonString.append(lName);
      aJsonString.append("\": ");
    }

    //parse every children
    aJsonString.append("{");
    lResult = parse_child(aElement, aJsonString, aErrorLog, "object");
    aJsonString.append("}");
  }
  else if(ZSTREQ(lType, "array"))
  {
    if(!lName.empty())
    {
      aJsonString.append("\"");
      aJsonString.append(lName);
      aJsonString.append("\": ");
    }

    //parse every children
    aJsonString.append("[");
    lResult = parse_child(aElement, aJsonString, aErrorLog, "array");
    aJsonString.append("]");
  }
  else if(ZSTREQ(lType, "string"))
  {
    zstring lValue;
    get_value(aElement, lValue);

    if(ZSTREQ(aElement->getNodeName()->getStringValue(), "pair"))
    {
      if(lName.empty())
      {
        aErrorLog = "Element does not have a 'name' attribute defined.";
        return false;
      }

      if(!ZSTREQ(aParentType, "object"))
      {
        aErrorLog = "'Pair' is allowed only into as part of an object.";
        return false;
      }

      aJsonString.append("\"");
      aJsonString.append(lName);
      aJsonString.append("\": ");
    }
    aJsonString.append("\"");
    aJsonString.append(lValue);
    aJsonString.append("\"");
  }
  else if(ZSTREQ(lType, "null"))
  {
    if(ZSTREQ(aElement->getNodeName()->getStringValue(), "pair"))
    {
      aJsonString.append("\"");
      aJsonString.append(lName);
      aJsonString.append("\": ");
    }
    aJsonString.append("null");
  }
  else if (ZSTREQ(lType, "number") ||
           ZSTREQ(lType, "boolean"))
  {
    zstring lValue;
    get_value(aElement, lValue);
    if(ZSTREQ(aElement->getNodeName()->getStringValue(), "pair"))
    {
      aJsonString.append("\"");
      aJsonString.append(lName);
      aJsonString.append("\": ");
    }
    aJsonString.append(lValue);
  }
  else
  {
    aErrorLog.append("Type '");
    aErrorLog.append(lType);
    aErrorLog.append("' not recognized.");
    return false;
  }

  return lResult;
}


bool get_value(const store::Item* aElement, zstring& aValue)
{
  store::Iterator_t lChildrenIt;
  store::Item_t     lChild;
  bool              lRes = false;

  lChildrenIt = aElement->getChildren();
  lChildrenIt->open();
  while (lChildrenIt->next(lChild))
  {
    if (lChild->getNodeKind() == store::StoreConsts::textNode)
    {
      aValue = lChild->getStringValue();
      lRes = true;
    }
  }
  lChildrenIt->close();
  return lRes;
}


bool parse_child(
    const store::Item* aElement,
    zstring& aJsonString,
    zstring& aErrorLog,
    const zstring& aParentType)
{
  bool lResult = true, lFirst = true;
  store::Iterator_t lChildrenIt;
  store::Item_t     lChild;

  lChildrenIt = aElement->getChildren();
  lChildrenIt->open();
  while (lChildrenIt->next(lChild) && lResult)
  {
    if (lChild->getNodeKind() == store::StoreConsts::elementNode)
    {
      if( !lFirst )
        aJsonString.append(", ");

      lResult = parse_element(&*lChild, aJsonString, aErrorLog, aParentType);
      lFirst = false;
    }
  }
  lChildrenIt->close();
  return lResult;
}


bool parse_Json_ML_child(
    const store::Item* element,
    zstring& json_string,
    zstring& error_log)
{
  bool result = true;
  store::Iterator_t childrenIt, attrIt;
  store::Item_t child, attr;
  zstring value;

  childrenIt = element->getChildren();
  childrenIt->open();

  json_string.append("[");
  json_string.append("\"");
  element->getNodeName()->appendStringValue(json_string);
  json_string.append("\"");

  attrIt = element->getAttributes();
  attrIt->open();
  while (attrIt->next(attr))
  {
    if (attr->getNodeKind() == store::StoreConsts::attributeNode)
    {
      json_string.append(", {\"");
      attr->getNodeName()->appendStringValue(json_string);
      json_string.append("\":\"");
      attr->appendStringValue(json_string);
      json_string.append("\"}");
    }
  }
  attrIt->close();

  while (childrenIt->next(child) && result)
  {
    if (child->getNodeKind() == store::StoreConsts::elementNode)
    {
      json_string.append(", ");
      result = parse_Json_ML_child(&*child, json_string, error_log);
    }
  }
  childrenIt->close();

  if (get_value(element, value))
  {
    json_string.append(", \"");
    json_string.append(value.c_str());
    json_string.append("\"");
  }

  json_string.append("]");

  return result;
}


bool JSON_ML_parse(
    const char* aJsonString,
    const zstring::size_type aLength,
    store::Item_t& aElement,
    const zstring& aBaseUri,
    zstring& aErrorLog)
{
  //std::auto_ptr<json::value> lValue(getValue(aJsonString, aLength, aErrorLog));
  //if( !aErrorLog.empty() )
  //  return false;

  //json::array_list_t::iterator lArrIter;
  //json::array_list_t * lArr = lValue->getarraylist();
  //if( lArr != 0 )
  //{
  //  lArrIter = lArr->begin();
  //  if((*lArrIter)->getdatatype() == json::datatype::_string)
  //  {
  //    std::wstring * lWtmp = (*lArrIter)->getstring();
  //    zstring lName;
  //    utf8::to_string( *lWtmp, &lName );
  //    delete lWtmp;

  //    create_Node_Helper(NULL, aBaseUri, lName, &aElement);

  //    ++lArrIter;

  //    for ( ; lArrIter != lArr->end(); ++lArrIter )
  //    {
  //      store::Item_t lNewNode = NULL;
  //      parse_Json_ML_value(&*lArrIter, aElement, aBaseUri, &lNewNode);
  //    }
  //  }
  //}

  return true;
}


bool JSON_ML_serialize(
    const store::Item* aElement,
    zstring& aJsonString,
    zstring& aErrorLog)
{
  aJsonString.clear();
  bool lResult = true;

  if (aElement == NULL)
  {
    aErrorLog = "Passed a NULL element to the JsonML serializer.";
    return false;
  }

  zstring lName;
  aElement->getNodeName()->getStringValue2(lName);

  if( ZSTREQ(lName, "json") )
  {
    aErrorLog = "This is not a Json ML element.";
    return false;
  }

  lResult = parse_Json_ML_child(aElement, aJsonString, aErrorLog);

  return lResult;
}


std::string  WStringToString(const std::wstring& aWstr)
{
  std::string lTemp(aWstr.length(), ' ');
  std::copy(aWstr.begin(), aWstr.end(), lTemp.begin());
  return lTemp;
}

} /*namespace Zorba */
/* vim:set et sw=2 ts=2: */
