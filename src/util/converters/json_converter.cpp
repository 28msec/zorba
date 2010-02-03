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

#include "util/converters/json_converter.h"

#include "json/parser.h"
#include "json/value.h"

#include "context/namespace_context.h"
#include "context/static_context.h"

#include "system/globalenv.h"


namespace zorba 
{

  json::value* getValue(const char* aJSON, const unsigned int aLen, xqp_string& error_log);
  std::string  WStringToString(const std::wstring& s);

  bool create_Node_Helper(store::Item_t aParent,
                          xqpStringStore_t aBaseUri,
                          xqpStringStore_t aName,
                          store::Item_t* aResult = NULL);

  bool create_Attribute_Helper( store::Item_t aParent,
                                xqpStringStore_t aName,
                                xqpStringStore_t aValue,
                                store::Item_t* aResult = NULL);

  bool create_Pair_Helper(store::Item_t aParent,
                          xqpStringStore_t aBaseUri,
                          store::Item_t* aResult,
                          xqpStringStore_t aName,
                          xqpStringStore_t aType,
                          xqpStringStore_t aValue = NULL);

  void parse_Json_value(json::value** aValue,
                        store::Item_t aParent,
                        xqpStringStore_t aBaseUri,
                        store::Item_t* aResult);

  void parse_Json_ML_value( json::value** aValue,
                            store::Item_t aParent,
                            xqpStringStore_t aBaseUri,
                            store::Item_t* aResult);

  bool parse_element( const store::Item* aElement,
                      xqpStringStore_t& aJsonString,
                      xqpStringStore_t& aErrorLog);

  bool parse_child( const store::Item* aElement,
                    xqpStringStore_t& aJsonString,
                    xqpStringStore_t& aErrorLog);

  bool get_value( const store::Item* aElement,
                  xqpStringStore_t& aValue);

  bool JSON_parse(const char* aJsonString,
                  const unsigned int aLength,
                  store::Item_t& aElement,
                  xqpStringStore_t aBaseUri,
                  xqp_string& aErrorLog)
  {
    std::auto_ptr<json::value> lValue(getValue(aJsonString, aLength, aErrorLog));
    if( !aErrorLog.empty() )
      return false;

    json::vector_list_t::iterator lVectIter;
    json::vector_list_t * lVect = lValue->getchildrenlist();

    create_Node_Helper(NULL, aBaseUri, new xqpStringStore("json"), &aElement);
    create_Attribute_Helper(aElement, new xqpStringStore("type"),
                            new xqpStringStore("object"));

    if( lVect != 0 )
    {
      for ( lVectIter=lVect->begin(); lVectIter != lVect->end(); ++lVectIter )
      {
        store::Item_t lNewNode = NULL;
        parse_Json_value(&*lVectIter, aElement, aBaseUri, &lNewNode);
      }
    }

    return true;
  }

  bool JSON_serialize(const store::Item* aElement,
                      xqpStringStore_t& aJsonString,
                      xqpStringStore_t& aErrorLog)
  {
    aJsonString = new xqpStringStore("");
    bool lResult = true;

    if ( aElement == NULL )
    {
      aErrorLog = new xqpStringStore("Passed a NULL element to the JSON serializer.");
      return false;
    }

    xqpStringStore_t lName = aElement->getNodeName()->getStringValue();

    if( lName->byteCompare("json") != 0 )
    {
      aErrorLog = new xqpStringStore("This is not a JSON element.");
      return false;
    }

    aJsonString->append_in_place('{');

    lResult = parse_child(aElement, aJsonString, aErrorLog);

    if( lResult )
      aJsonString->append_in_place('}');

    return lResult;
  }


  //helper functions
  bool create_Type_Helper(store::Item_t& result, xqpStringStore_t type_name)
  {
    xqpStringStore_t xs_ns = new xqpStringStore("http://www.w3.org/2001/XMLSchema");
    xqpStringStore_t xs_pre = new xqpStringStore("xs");
    return GENV_ITEMFACTORY->createQName(result, xs_ns, xs_pre, type_name);
  }

  bool create_QName_Helper(store::Item_t& result, xqpStringStore_t name)
  {
    xqpStringStore_t ns = new xqpStringStore("");//ZORBA_JSON_FN_NS);
    xqpStringStore_t pre = new xqpStringStore("");//zorba-json");
    return GENV_ITEMFACTORY->createQName(result, ns, pre, name);
  }

  bool create_Node_Helper(store::Item_t aParent,
                          xqpStringStore_t aBaseUri,
                          xqpStringStore_t aName,
                          store::Item_t* aResult)
  {
    store::Item_t lQname, lTempResult, lTypeQname;
    store::NsBindings lBindings;

    create_QName_Helper(lQname, aName);
    create_Type_Helper(lTypeQname, new xqpStringStore("untyped"));

    bool lStatus = GENV_ITEMFACTORY->createElementNode(lTempResult,
                                                      aParent,
                                                      -1,
                                                      lQname,
                                                      lTypeQname,
                                                      true,
                                                      false,
                                                      lBindings,
                                                      aBaseUri);

    if ( aResult != NULL )
      *aResult = lTempResult;

    return lStatus;
  }

  bool create_Attribute_Helper( store::Item_t aParent,
                                xqpStringStore_t aName,
                                xqpStringStore_t aValue,
                                store::Item_t* aResult)
  {
    store::Item_t lQname, lTempResult, lStrItem;
    store::Item_t lTypeQname;

    create_QName_Helper(lQname, aName);
    create_Type_Helper(lTypeQname, new xqpStringStore("string"));

    GENV_ITEMFACTORY->createString(lStrItem, aValue);
    GENV_ITEMFACTORY->createAttributeNode(lTempResult,
                                          aParent,
                                          -1,
                                          lQname,
                                          lTypeQname,
                                          lStrItem);
    if ( aResult != NULL )
      *aResult = lTempResult;

    return true;
  }

  bool create_Pair_Helper(store::Item_t aParent,
                          xqpStringStore_t aBaseUri,
                          store::Item_t* aResult,
                          xqpStringStore_t aName,
                          xqpStringStore_t aType,
                          xqpStringStore_t aValue)
  {
    bool lRet = true;
    if( !aName->empty() )
    {
      lRet = create_Node_Helper(aParent, aBaseUri, new xqpStringStore("pair"), aResult);
      if( lRet )
        lRet = create_Attribute_Helper(*aResult, new xqpStringStore("name"), aName, NULL);
    }
    else
      lRet = create_Node_Helper(aParent, aBaseUri, new xqpStringStore("item"), aResult);

    if( lRet )
      lRet = create_Attribute_Helper(*aResult, new xqpStringStore("type"), aType, NULL);

    if( aValue != NULL )
    {
      store::Item_t lTextValue;
      GENV_ITEMFACTORY->createTextNode(lTextValue, *aResult, -1, aValue);
    }

    return lRet;
  }

  json::value* getValue(const char* aJSON, const unsigned int aLen, xqp_string& aErrorLog)
  {
    //transforn from UTF-8 to UCS-4 using ICU
    int32_t lUCS4Len;
    wchar_t * lUCS4 = xqpString::getWCS(aJSON, aLen, &lUCS4Len);

    json::parser lParser;
    json::value* lValue = lParser.parse(lUCS4, lUCS4Len);
    std::wstring lErr = lParser.printerrors();
    delete[] lUCS4;

    //transform from UCS-4 to UTF-8
    aErrorLog = xqpString(lErr.c_str()).getStore();
    return lValue;
  }

  void parse_Json_value(json::value** aValue,
                        store::Item_t aParent,
                        xqpStringStore_t aBaseUri,
                        store::Item_t* aResult)
  {
    json::vector_list_t::iterator lVectIter;
    json::vector_list_t * lVect;

    json::array_list_t::iterator lArrtIter;
    json::array_list_t * lArr;

    store::Item_t lItemObj, lItemArr;

    if( aValue!=0 )
    {
      xqpStringStore_t lName = xqpString((*aValue)->getname().c_str()).getStore();
      switch((*aValue)->getdatatype()){
        case json::datatype::_array:
          create_Pair_Helper(aParent, aBaseUri, aResult, lName, new xqpStringStore("array"), NULL);
          lArr = (*aValue)->getarraylist();
          if( lArr != 0 )
            for ( lArrtIter = lArr->begin(); lArrtIter != lArr->end(); ++lArrtIter )
              parse_Json_value(&*lArrtIter, *aResult, aBaseUri, &lItemArr);
          break;
        case json::datatype::_object:
          create_Pair_Helper(aParent, aBaseUri, aResult, lName, new xqpStringStore("object"), NULL);
          lVect = (*aValue)->getchildrenlist();
          if( lVect != 0 )
            for ( lVectIter = lVect->begin(); lVectIter != lVect->end(); ++lVectIter )
              parse_Json_value(&*lVectIter, *aResult, aBaseUri, &lItemObj);
          break;
        default:
          std::wstring * lWtmp = (*aValue)->getstring();

          //transform from UCS-4 to UTF-8
          xqpStringStore_t lVal = xqpString((*lWtmp).c_str()).getStore();
          delete lWtmp;

          xqpStringStore_t lType;
          if ((*aValue)->getdatatype() == json::datatype::_string)
            lType = new xqpStringStore("string");
          else if ((*aValue)->getdatatype() == json::datatype::_literal)
          {
            if( lVal->byteCompare("null")==0 )
            {
              lVal = NULL;
              lType = new xqpStringStore("null");
            }
            else
              lType = new xqpStringStore("boolean");
          }
          else if (((*aValue)->getdatatype() == json::datatype::_number) ||
                   ((*aValue)->getdatatype() == json::datatype::_fixed_number))
            lType = new xqpStringStore("number");

          create_Pair_Helper(aParent, aBaseUri, aResult, lName, lType, lVal);
          break;
      }
    }
  }

  void parse_Json_ML_value( json::value** aValue,
                            store::Item_t aParent,
                            xqpStringStore_t aBaseUri,
                            store::Item_t* aResult)
  {
    json::vector_list_t::iterator lVectIter;
    json::vector_list_t * lVect;

    json::array_list_t::iterator lArrIter;
    json::array_list_t * lArr;

    store::Item_t lItemObj, lTextValue;

    if( aValue != 0 )
    {
      switch((*aValue)->getdatatype())
      {
        case json::datatype::_array:
          lArr = (*aValue)->getarraylist();
          lArrIter = lArr->begin();
          if((*lArrIter)->getdatatype() == json::datatype::_string)
          {
            std::wstring * lWtmp = (*lArrIter)->getstring();

            //transform from UCS-4 to UTF-8
            xqpStringStore_t lName = xqpString((*lWtmp).c_str()).getStore();
            delete lWtmp;

            create_Node_Helper(aParent, aBaseUri, lName, aResult);
            ++lArrIter;

            for ( ; lArrIter != lArr->end(); ++lArrIter )
              parse_Json_ML_value(&*lArrIter, *aResult, aBaseUri, &lItemObj);
          }
          break;
        case json::datatype::_object:
          lVect = (*aValue)->getchildrenlist();
          if( lVect != 0 )
          {
            for ( lVectIter = lVect->begin(); lVectIter != lVect->end(); ++lVectIter )
            {
              xqpStringStore_t lName = xqpString((*lVectIter)->getname().c_str()).getStore();
              std::wstring * lWtmp = (*lVectIter)->getstring();

              //transform from UCS-4 to UTF-8
              xqpStringStore_t lText = xqpString((*lWtmp).c_str()).getStore();
              delete lWtmp;

              create_Attribute_Helper(aParent, lName, lText, NULL);
            }
          }
          break;
        default:
          std::wstring * lWtmp = (*aValue)->getstring();

          //transform from UCS-4 to UTF-8
          xqpStringStore_t lText = xqpString((*lWtmp).c_str()).getStore();
          delete lWtmp;

          if( lText->byteCompare("null") != 0 )
            GENV_ITEMFACTORY->createTextNode(lTextValue, aParent, -1, lText);
          break;
      }
    }
  }

  bool parse_element( const store::Item* aElement,
                      xqpStringStore_t& aJsonString,
                      xqpStringStore_t& aErrorLog)
  {
    store::Iterator_t lAttrIt, lChildrenIt;
    store::Item_t     lAttr, lChild;

    bool lResult = true;
    xqpStringStore_t lName, lType;

    lAttrIt = aElement->getAttributes();
    lAttrIt->open();
    while (lAttrIt->next(lAttr))
    {
      if (lAttr->getNodeKind() == store::StoreConsts::attributeNode)
      {
        if(lAttr->getNodeName()->getStringValue()->byteCompare("type") == 0)
          lType = lAttr->getStringValue();
        else if(lAttr->getNodeName()->getStringValue()->byteCompare("name") == 0)
          lName = lAttr->getStringValue();
      }
    }
    lAttrIt->close();

    if(lType->byteCompare("object") == 0)
    {
      aJsonString->append_in_place('"');
      aJsonString->append_in_place(lName->c_str());
      aJsonString->append_in_place("\": {");
      //parse every children
      lResult = parse_child(aElement, aJsonString, aErrorLog);
      aJsonString->append_in_place('}');
    }
    else if(lType->byteCompare("array") == 0)
    {
      aJsonString->append_in_place('"');
      aJsonString->append_in_place(lName->c_str());
      aJsonString->append_in_place("\": [");
      //parse every children
      lResult = parse_child(aElement, aJsonString, aErrorLog);
      aJsonString->append_in_place(']');
    }
    else if(lType->byteCompare("string") == 0)
    {
      xqpStringStore_t lValue;
      get_value(aElement, lValue);
      if(aElement->getNodeName()->getStringValue()->byteCompare("pair") == 0)
      {
        aJsonString->append_in_place('"');
        aJsonString->append_in_place(lName->c_str());
        aJsonString->append_in_place("\": ");
      }
      aJsonString->append_in_place('"');
      aJsonString->append_in_place(lValue->c_str());
      aJsonString->append_in_place('"');
    }
    else if(lType->byteCompare("null") == 0)
    {
      if(aElement->getNodeName()->getStringValue()->byteCompare("pair") == 0)
      {
        aJsonString->append_in_place('"');
        aJsonString->append_in_place(lName->c_str());
        aJsonString->append_in_place("\": ");
      }
      aJsonString->append_in_place("null");
    }
    else //number,boolean
    {
      xqpStringStore_t lValue;
      get_value(aElement, lValue);
      if(aElement->getNodeName()->getStringValue()->byteCompare("pair") == 0)
      {
        aJsonString->append_in_place('"');
        aJsonString->append_in_place(lName->c_str());
        aJsonString->append_in_place("\": ");
      }
      aJsonString->append_in_place(lValue->c_str());
    }

    return lResult;
  }

  bool get_value( const store::Item* aElement,
                  xqpStringStore_t& aValue)
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

    if ( lRes )
    {
      xqpString lStringHolder(aValue.getp());

      if (lStringHolder.indexOf("\"") != -1)
        lStringHolder = lStringHolder.replace("\"", "'", "");

      aValue = lStringHolder.getStore();
      return lRes;
    }

    return false;
  }

  bool parse_child( const store::Item* aElement,
                    xqpStringStore_t& aJsonString,
                    xqpStringStore_t& aErrorLog)
  {
    bool lResult = true, lFirst = true;
    store::Iterator_t lChildrenIt;
    store::Item_t     lChild;
    lChildrenIt = aElement->getChildren();
    lChildrenIt->open();
    while (lChildrenIt->next(lChild) && lResult)
    {
      if( !lFirst )
        aJsonString->append_in_place(',');

      if (lChild->getNodeKind() == store::StoreConsts::elementNode)
        lResult = parse_element(&*lChild, aJsonString, aErrorLog);
      lFirst = false;
    }
    lChildrenIt->close();
    return lResult;
  }

  bool parse_Json_ML_child(const store::Item* element, xqpStringStore_t& json_string, xqpStringStore_t& error_log)
  {
    bool result = true;
    store::Iterator_t childrenIt, attrIt;
    store::Item_t     child, attr;
    xqpStringStore_t  name, value;

    childrenIt = element->getChildren();
    childrenIt->open();

    json_string->append_in_place('[');
    name = element->getNodeName()->getStringValue();
    json_string->append_in_place('"');
    json_string->append_in_place(name->c_str());
    json_string->append_in_place("\"");

    attrIt = element->getAttributes();
    attrIt->open();
    while (attrIt->next(attr))
    {
      if (attr->getNodeKind() == store::StoreConsts::attributeNode)
      {
        name = attr->getNodeName()->getStringValue();
        value = attr->getStringValue();

        json_string->append_in_place(", {\"");
        json_string->append_in_place(name->c_str());
        json_string->append_in_place("\":\"");
        json_string->append_in_place(value->c_str());
        json_string->append_in_place("\"}");
      }
    }
    attrIt->close();

    while (childrenIt->next(child) && result)
    {
      if (child->getNodeKind() == store::StoreConsts::elementNode)
      {
        json_string->append_in_place(", ");
        result = parse_Json_ML_child(&*child, json_string, error_log);
      }
    }
    childrenIt->close();

    if(get_value(element, value))
    {
      json_string->append_in_place(", \"");
      json_string->append_in_place(value->c_str());
      json_string->append_in_place("\"");
    }

    json_string->append_in_place(']');

    return result;
  }

  bool JSON_ML_parse( const char* aJsonString,
                      const unsigned int aLength,
                      store::Item_t& aElement,
                      xqpStringStore_t aBaseUri,
                      xqp_string& aErrorLog)
  {
    std::auto_ptr<json::value> lValue(getValue(aJsonString, aLength, aErrorLog));
    if( !aErrorLog.empty() )
      return false;

    json::array_list_t::iterator lArrIter;
    json::array_list_t * lArr = lValue->getarraylist();
    if( lArr != 0 )
    {
      lArrIter = lArr->begin();
      if((*lArrIter)->getdatatype() == json::datatype::_string)
      {
        std::wstring * lWtmp = (*lArrIter)->getstring();

        //transform from UCS-4 to UTF-8
        xqpStringStore_t lName = xqpString((*lWtmp).c_str()).getStore();
        delete lWtmp;

        create_Node_Helper(NULL, aBaseUri, lName, &aElement);

        ++lArrIter;

        for ( ; lArrIter != lArr->end(); ++lArrIter )
        {
          store::Item_t lNewNode = NULL;
          parse_Json_ML_value(&*lArrIter, aElement, aBaseUri, &lNewNode);
        }
      }
    }

    return true;
  }

  bool JSON_ML_serialize( const store::Item* aElement,
                          xqpStringStore_t& aJsonString,
                          xqpStringStore_t& aErrorLog)
  {
    aJsonString = new xqpStringStore("");
    bool lResult = true;

    if (aElement == NULL)
    {
      aErrorLog = new xqpStringStore("Passed a NULL element to the JsonML serializer.");
      return false;
    }

    xqpStringStore_t lName = aElement->getNodeName()->getStringValue();

    if( lName->byteCompare("json") == 0 )
    {
      aErrorLog = new xqpStringStore("This is not a Json ML element.");
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
