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

  bool create_Node_Helper(store::Item_t parent,
                          xqpStringStore_t baseUri,
                          xqpStringStore_t name,
                          store::Item_t* result = NULL);

  bool create_Attribute_Helper( store::Item_t parent,
                                xqpStringStore_t name,
                                xqpStringStore_t value,
                                store::Item_t* result = NULL);

  bool create_Pair_Helper(store::Item_t parent,
                          xqpStringStore_t baseUri,
                          store::Item_t* result,
                          xqpStringStore_t name,
                          xqpStringStore_t type,
                          xqpStringStore_t value = NULL);

  void parse_Json_value(json::value** value,
                        store::Item_t parent,
                        xqpStringStore_t baseUri,
                        store::Item_t* result);

  void parse_Json_ML_value( json::value** value,
                            store::Item_t parent,
                            xqpStringStore_t baseUri,
                            store::Item_t* result);

  bool parse_element( const store::Item* element,
                      xqpStringStore_t& json_string,
                      xqpStringStore_t& error_log);

  bool parse_child( const store::Item* element,
                    xqpStringStore_t& json_string,
                    xqpStringStore_t& error_log);

  bool get_value( const store::Item* element,
                  xqpStringStore_t& value);

  bool JSON_parse(const char* aJSON_string, const unsigned int aLength,
                  store::Item_t& element, xqpStringStore_t baseUri,
                  xqp_string& error_log)
  {
    std::auto_ptr<json::value> lValue(getValue(aJSON_string, aLength, error_log));
    if( !error_log.empty() )
      return false;

    json::vector_list_t::iterator vectIter;
    json::vector_list_t *vect = lValue->getchildrenlist();

    create_Node_Helper(NULL, baseUri, new xqpStringStore("json"), &element);
    create_Attribute_Helper(element, new xqpStringStore("type"),
                            new xqpStringStore("object"));

    if(vect != 0)
    {
      for ( vectIter=vect->begin(); vectIter != vect->end(); ++vectIter )
      {
        store::Item_t new_node = NULL;
        parse_Json_value(&*vectIter, element, baseUri, &new_node);
      }
    }

    return true;
  }

  bool JSON_serialize(const store::Item* element, xqpStringStore_t& json_string, xqpStringStore_t& error_log)
  {
    json_string = new xqpStringStore("");
    bool result = true;

    if (element == NULL)
    {
      error_log = new xqpStringStore("Passed a NULL element to the JSON serializer.");
      return false;
    }

    xqpStringStore_t name = element->getNodeName()->getStringValue();

    if( name->byteCompare("json") != 0 )
    {
      error_log = new xqpStringStore("This is not a JSON element.");
      return false;
    }

    json_string->append_in_place('{');

    result = parse_child(element, json_string, error_log);

    if(result)
      json_string->append_in_place('}');

    return result;
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

  bool create_Node_Helper(store::Item_t parent, xqpStringStore_t baseUri, xqpStringStore_t name, store::Item_t* result)
  {
    store::Item_t qname, temp_result, type_qname;
    store::NsBindings bindings;

    create_QName_Helper(qname, name);
    create_Type_Helper(type_qname, new xqpStringStore("untyped"));

    bool status = GENV_ITEMFACTORY->createElementNode(temp_result,
                                                      parent,
                                                      -1,
                                                      qname,
                                                      type_qname,
                                                      true,
                                                      false,
                                                      bindings,
                                                      baseUri);

    if (result != NULL)
      *result = temp_result;

    return status;
  }

  bool create_Attribute_Helper(store::Item_t parent, xqpStringStore_t name, xqpStringStore_t value, store::Item_t* result)
  {
    store::Item_t qname, temp_result, str_item;
    store::Item_t type_qname;

    create_QName_Helper(qname, name);
    create_Type_Helper(type_qname, new xqpStringStore("string"));

    GENV_ITEMFACTORY->createString(str_item, value);
    GENV_ITEMFACTORY->createAttributeNode(temp_result,
                                          parent,
                                          -1,
                                          qname,
                                          type_qname,
                                          str_item);
    if (result != NULL)
      *result = temp_result;

    return true;
  }

  bool create_Pair_Helper(store::Item_t parent, xqpStringStore_t baseUri, store::Item_t* result,
                          xqpStringStore_t name, xqpStringStore_t type, xqpStringStore_t value)
  {
    bool ret = true;
    if(!name->empty())
    {
      ret = create_Node_Helper(parent, baseUri, new xqpStringStore("pair"), result);
      if(ret)
        ret = create_Attribute_Helper(*result, new xqpStringStore("name"), name, NULL);
    }
    else
      ret = create_Node_Helper(parent, baseUri, new xqpStringStore("item"), result);

    if(ret)
      ret = create_Attribute_Helper(*result, new xqpStringStore("type"), type, NULL);

    if(value != NULL)
    {
      store::Item_t text_value;
      GENV_ITEMFACTORY->createTextNode(text_value, *result, -1, value);
    }

    return ret;
  }

  json::value* getValue(const char* aJSON, const unsigned int aLen, xqp_string& error_log)
  {
    json::parser lParser;
    json::value* lValue = lParser.parse(aJSON, aLen);
    std::wstring s = lParser.printerrors();
    std::string temp = WStringToString(s);
    error_log = new xqpStringStore(temp);
    return lValue;
  }

  void parse_Json_value(json::value** value, store::Item_t parent, xqpStringStore_t baseUri, store::Item_t* result)
  {
    json::vector_list_t::iterator vectIter;
    json::vector_list_t *vect;

    json::array_list_t::iterator arrtIter;
    json::array_list_t *arr;

    store::Item_t itemObj, itemArr;

    if(value!=0)
    {
      xqpStringStore_t name = xqpString((*value)->getname().c_str()).getStore();
      switch((*value)->getdatatype()){
        case json::datatype::_array:
          create_Pair_Helper(parent, baseUri, result, name, new xqpStringStore("array"), NULL);
          arr = (*value)->getarraylist();
          if(arr != 0)
            for ( arrtIter=arr->begin(); arrtIter != arr->end(); ++arrtIter )
              parse_Json_value(&*arrtIter, *result, baseUri, &itemArr);
          break;
        case json::datatype::_object:
          create_Pair_Helper(parent, baseUri, result, name, new xqpStringStore("object"), NULL);
          vect = (*value)->getchildrenlist();
          if(vect != 0)
            for ( vectIter=vect->begin(); vectIter != vect->end(); ++vectIter )
              parse_Json_value(&*vectIter, *result, baseUri, &itemObj);
          break;
        default:
          std::wstring * wtmp = (*value)->getstring();
          std::string temp = WStringToString(*wtmp);
          delete wtmp;
          xqpStringStore_t val = xqpString(temp).getStore();
          xqpStringStore_t type;
          if ((*value)->getdatatype() == json::datatype::_string)
            type = new xqpStringStore("string");
          else if ((*value)->getdatatype() == json::datatype::_literal)
          {
            if(val->byteCompare("null")==0)
            {
              val = NULL;
              type = new xqpStringStore("null");
            }
            else
              type = new xqpStringStore("boolean");
          }
          else if (((*value)->getdatatype() == json::datatype::_number) ||
                      ((*value)->getdatatype() == json::datatype::_fixed_number))
            type = new xqpStringStore("number");

          create_Pair_Helper(parent, baseUri, result, name, type, val);
          break;
      }
    }
  }

  void parse_Json_ML_value(json::value** value, store::Item_t parent, xqpStringStore_t baseUri, store::Item_t* result)
  {
    json::vector_list_t::iterator vectIter;
    json::vector_list_t *vect;

    json::array_list_t::iterator arrIter;
    json::array_list_t *arr;

    store::Item_t itemObj, text_value;

    if(value != 0)
    {
      switch((*value)->getdatatype())
      {
        case json::datatype::_array:
          arr = (*value)->getarraylist();
          arrIter = arr->begin();
          if((*arrIter)->getdatatype() == json::datatype::_string)
          {
            std::wstring * wtmp = (*arrIter)->getstring();
            std::string tmp = WStringToString(*wtmp);
            delete wtmp;
            xqpStringStore_t name = xqpString(tmp).getStore();
            create_Node_Helper(parent, baseUri, name, result);
            ++arrIter;

            for ( ; arrIter != arr->end(); ++arrIter )
              parse_Json_ML_value(&*arrIter, *result, baseUri, &itemObj);
          }
          break;
        case json::datatype::_object:
          vect = (*value)->getchildrenlist();
          if(vect != 0)
          {
            for ( vectIter=vect->begin(); vectIter != vect->end(); ++vectIter )
            {
              xqpStringStore_t name = xqpString((*vectIter)->getname().c_str()).getStore();
              std::wstring * wtmp = (*vectIter)->getstring();
              std::string tmp = WStringToString(*wtmp);
              delete wtmp;
              xqpStringStore_t text = xqpString(tmp).getStore();
              create_Attribute_Helper(parent, name, text, NULL);
            }
          }
          break;
        default:
          std::wstring * wtmp = (*value)->getstring();
          std::string temp = WStringToString(*wtmp);
          delete wtmp;
          xqpStringStore_t text = xqpString(temp).getStore();
          if(text->byteCompare("null") != 0)
            GENV_ITEMFACTORY->createTextNode(text_value, parent, -1, text);
          break;
      }
    }
  }

  bool parse_element(const store::Item* element, xqpStringStore_t& json_string, xqpStringStore_t& error_log)
  {
    store::Iterator_t attrIt, childrenIt;
    store::Item_t     attr, child;

    bool result = true;
    xqpStringStore_t name, type;

    attrIt = element->getAttributes();
    attrIt->open();
    while (attrIt->next(attr))
    {
      if (attr->getNodeKind() == store::StoreConsts::attributeNode)
      {
        if(attr->getNodeName()->getStringValue()->byteCompare("type") == 0)
          type = attr->getStringValue();
        else if(attr->getNodeName()->getStringValue()->byteCompare("name") == 0)
          name = attr->getStringValue();
      }
    }
    attrIt->close();

    if(type->byteCompare("object") == 0)
    {
      json_string->append_in_place('"');
      json_string->append_in_place(name->c_str());
      json_string->append_in_place("\": {");
      //parse every children
      result = parse_child(element, json_string, error_log);
      json_string->append_in_place('}');
    }
    else if(type->byteCompare("array") == 0)
    {
      json_string->append_in_place('"');
      json_string->append_in_place(name->c_str());
      json_string->append_in_place("\": [");
      //parse every children
      result = parse_child(element, json_string, error_log);
      json_string->append_in_place(']');
    }
    else if(type->byteCompare("string") == 0)
    {
      xqpStringStore_t value;
      get_value(element, value);
      if(element->getNodeName()->getStringValue()->byteCompare("pair") == 0)
      {
        json_string->append_in_place('"');
        json_string->append_in_place(name->c_str());
        json_string->append_in_place("\": ");
      }
      json_string->append_in_place('"');
      json_string->append_in_place(value->c_str());
      json_string->append_in_place('"');
    }
    else if(type->byteCompare("null") == 0)
    {
      if(element->getNodeName()->getStringValue()->byteCompare("pair") == 0)
      {
        json_string->append_in_place('"');
        json_string->append_in_place(name->c_str());
        json_string->append_in_place("\": ");
      }
      json_string->append_in_place("null");
    }
    else //number,boolean
    {
      xqpStringStore_t value;
      get_value(element, value);
      if(element->getNodeName()->getStringValue()->byteCompare("pair") == 0)
      {
        json_string->append_in_place('"');
        json_string->append_in_place(name->c_str());
        json_string->append_in_place("\": ");
      }
      json_string->append_in_place(value->c_str());
    }

    return result;
  }

  bool get_value(const store::Item* element, xqpStringStore_t& value)
  {
    store::Iterator_t childrenIt;
    store::Item_t     child;
    bool              res = false;

    childrenIt = element->getChildren();
    childrenIt->open();
    while (childrenIt->next(child))
    {
      if (child->getNodeKind() == store::StoreConsts::textNode)
      {
        value = child->getStringValue();
        res = true;
      }
    }
    childrenIt->close();
    
    if (res) {
      xqpString lStringHolder(value.getp());
      if (lStringHolder.indexOf("\"") != -1) {
        lStringHolder = lStringHolder.replace("\"", "'", "");
      }
      value = lStringHolder.getStore();
      return res;
    }
     
    return false;
  }

  bool parse_child(const store::Item* element, xqpStringStore_t& json_string, xqpStringStore_t& error_log)
  {
    bool result = true, first = true;
    store::Iterator_t childrenIt;
    store::Item_t     child;
    childrenIt = element->getChildren();
    childrenIt->open();
    while (childrenIt->next(child) && result)
    {
      if(!first)
        json_string->append_in_place(',');

      if (child->getNodeKind() == store::StoreConsts::elementNode)
        result = parse_element(&*child, json_string, error_log);
      first = false;
    }
    childrenIt->close();
    return result;
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

  bool JSON_ML_parse(const char* aJSON_string, const unsigned int aLength,
                     store::Item_t& element, xqpStringStore_t baseUri,
                     xqp_string& error_log)
  {
    std::auto_ptr<json::value> lValue(getValue(aJSON_string, aLength, error_log));
    if( !error_log.empty() )
      return false;

    json::array_list_t::iterator arrIter;
    json::array_list_t *arr = lValue->getarraylist();
    if(arr != 0)
    {
      arrIter = arr->begin();
      if((*arrIter)->getdatatype() == json::datatype::_string)
      {
        std::wstring * wtmp = (*arrIter)->getstring();
        std::string tmp = WStringToString(*wtmp);
        delete wtmp;
        xqpStringStore_t name = xqpString(tmp).getStore();
        create_Node_Helper(NULL, baseUri, name, &element);

        ++arrIter;

        for ( ; arrIter != arr->end(); ++arrIter )
        {
          store::Item_t new_node = NULL;
          parse_Json_ML_value(&*arrIter, element, baseUri, &new_node);
        }
      }
    }

    return true;
  }

  bool JSON_ML_serialize(const store::Item* element,
                         xqpStringStore_t& json_string,
                         xqpStringStore_t& error_log)
  {
    json_string = new xqpStringStore("");
    bool result = true;

    if (element == NULL)
    {
      error_log = new xqpStringStore("Passed a NULL element to the JsonML serializer.");
      return false;
    }

    xqpStringStore_t name = element->getNodeName()->getStringValue();

    if( name->byteCompare("json") == 0 )
    {
      error_log = new xqpStringStore("This is not a Json ML element.");
      return false;
    }

    result = parse_Json_ML_child(element, json_string, error_log);

    return result;
  }

  std::string  WStringToString(const std::wstring& wstr)
  {
    std::string temp(wstr.length(), ' ');
    std::copy(wstr.begin(), wstr.end(), temp.begin());
    return temp;
  }
} /*namespace Zorba */
