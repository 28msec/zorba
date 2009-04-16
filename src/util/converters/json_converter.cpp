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

#include "util/converters/json_converter.h"

#include "json/parser.h"
#include "json/value.h"

#include "system/globalenv.h"
#include "context/namespace_context.h"

namespace zorba {
  json::value* getValue(const char* aJSON, const unsigned int aLen);

  bool create_Node_Helper(store::Item_t parent, xqpStringStore_t baseUri, xqpStringStore_t name, store::Item_t* result = NULL);
  bool create_Attribute_Helper(store::Item_t parent, xqpStringStore_t name, xqpStringStore_t value, store::Item_t* result = NULL);
  bool create_Pair_Helper(store::Item_t parent, xqpStringStore_t baseUri, store::Item_t* result,
                          xqpStringStore_t name, xqpStringStore_t type, xqpStringStore_t value = NULL);

  void print_type(json::value** value, store::Item_t parent, xqpStringStore_t baseUri, store::Item_t* result);

  bool JSON_parse(const char* aJSON_string, const unsigned int aLength,
                  store::Item_t& element, xqpStringStore_t baseUri,
                  xqp_string& error_log)
  {
    std::auto_ptr<json::value> lValue(getValue(aJSON_string, aLength));

    json::vector_list_t::iterator vectIter;
    json::vector_list_t *vect = lValue->getchildrenlist();
    if(vect != 0)
    {
      create_Node_Helper(NULL, baseUri, new xqpStringStore("json"), &element);
      create_Attribute_Helper(element, new xqpStringStore("type"), new xqpStringStore("object"));

      for ( vectIter=vect->begin(); vectIter != vect->end(); ++vectIter )
      {
        store::Item_t new_node = NULL;
        print_type(&*vectIter, element, baseUri, &new_node);
      }
    }

    return true;
  }

  void print_type(json::value** value, store::Item_t parent, xqpStringStore_t baseUri, store::Item_t* result)
  {
    json::vector_list_t::iterator vectIter;
    json::vector_list_t *vect;

    json::array_list_t::iterator arrtIter;
    json::array_list_t *arr;

    int size;
    xqpStringStore_t name, type, val;
    store::Item_t itemObj, itemArr;

    if(value!=0)
    {
      name = xqpString((*value)->getname().c_str()).getStore();
      switch((*value)->getdatatype()){
        case json::datatype::_array:
          create_Pair_Helper(parent, baseUri, result, name, new xqpStringStore("array"), NULL);
          arr = (*value)->getarraylist();
          size = arr->size();
          if(arr != 0)
            for ( arrtIter=arr->begin(); arrtIter != arr->end(); ++arrtIter )
              print_type(&*arrtIter, *result, baseUri, &itemArr);
          break;
        case json::datatype::_object:
          create_Pair_Helper(parent, baseUri, result, name, new xqpStringStore("object"), NULL);
          vect = (*value)->getchildrenlist();
          if(vect != 0)
            for ( vectIter=vect->begin(); vectIter != vect->end(); ++vectIter )
              print_type(&*vectIter, *result, baseUri, &itemObj);
          break;
        default:
          val = xqpString((*((*value)->getstring())).c_str()).getStore();
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

  bool JSON_serialize(store::Item_t element, xqpStringStore_t& json_string, xqp_string& error_log)
  {
    json_string = new xqpStringStore("NOT implemented yet");
    return true;
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
                                                      false,
                                                      false,
                                                      bindings,
                                                      baseUri,
                                                      true);

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
                                          str_item,
                                          false,
                                          false);

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

  json::value* getValue(const char* aJSON, const unsigned int aLen)
  {
    json::parser lParser;
    json::value* lValue = lParser.parse(aJSON, aLen);
    lParser.printerrors();
    return lValue;
  }

} /*namespace Zorba */
