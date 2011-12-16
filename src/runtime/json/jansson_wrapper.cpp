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

#include <sstream>
#include <cstring>

#include <zorba/zorba.h>
#include <zorba/iterator.h>
#include <zorba/store_consts.h>

#include <jansson.h>

#include "jansson_wrapper.h"

namespace zorba
{
namespace jsonmodule
{
static void serialize_child(
  const zorba::Item& aElement,
  std::stringstream& aResultSs,
  std::stringstream& aErrorLogSs,
  const std::string& aParentType);

bool replace_all( std::string &s, char from, char to ) {
  bool replaced_any = false;
  for ( std::string::size_type pos = 0; pos < s.size(); ++pos ) {
    if ( (pos = s.find( from, pos )) == std::string::npos )
      break;
    s.replace( pos, 1, 1, to );
    replaced_any = true;
  }
  return replaced_any;
}

bool replace_all( std::string &s,
                  char const *from, std::string::size_type from_len,
                  char const *to, std::string::size_type to_len ) {
  bool replaced_any = false;
  for ( std::string::size_type pos = 0;
        pos + from_len <= s.size(); pos += to_len ) {
    if ( (pos = s.find( from, pos, from_len )) == std::string::npos )
      break;
    s.replace( pos, from_len, to, to_len );
    replaced_any = true;
  }
  return replaced_any;
}

bool replace_all( std::string &s, char const *from, char const *to )
{
  return replace_all( s, from, std::strlen( from ), to, std::strlen( to ) );
}

void replace_special_chars(
     std::string &aValue)
{
  replace_all(aValue, "\"", "\\\"");  //quotation mark
  replace_all(aValue, "\\", "\\\\");  //reverse solidus
  replace_all(aValue, "/", "\\/");    //solidus
  replace_all(aValue, "\b", "\\b" );  //backspace
  replace_all(aValue, "\f", "\\f" );  //formfeed
  replace_all(aValue, "\n", "\\n" );  //new line
  replace_all(aValue, "\r", "\\r" );  //carriage return
  replace_all(aValue, "\t", "\\t" );  //horizontal tab
}

static void parse_Json_value(
    const char *aKey,
    json_t *aValue,
    const char* aParentType,
    std::stringstream& aSs,
    std::stringstream& aErrorLogSs)
{
  if(!aValue)
    return;

  switch(json_typeof(aValue))
  {
    case JSON_OBJECT:
    {
      const char *lKey;
      json_t *lValue;
      std::string lTmp(aKey);

      //<pair name=\"[...]\" type=\"object\">[...]</pair>
      aSs << "<pair";
      if(!lTmp.empty())
        aSs << " name=\"" << lTmp << "\"";
      aSs << " type=\"object\">";

      void *lIter = json_object_iter(aValue);
      while(lIter)
      {
        lKey = json_object_iter_key(lIter);
        lValue = json_object_iter_value(lIter);

        parse_Json_value(lKey, lValue, "object", aSs, aErrorLogSs);

        lIter = json_object_iter_next(aValue, lIter);
      }

      aSs << "</pair>";
      break;
    }
    case JSON_ARRAY:
    {
      json_t *lValue;
      zorba::String lName(aKey), lEmptyStr("");

      //<pair name=\"[...]\" type=\"array\">[...]</pair>
      aSs << "<pair name=\"" << lName << "\" type=\"array\">";

      for(size_t i = 0; i < json_array_size(aValue); i++)
      {
        lValue = json_array_get(aValue, i);

        parse_Json_value(lEmptyStr.c_str(), lValue, "array", aSs, aErrorLogSs);
      }

      aSs << "</pair>";
      break;
    }
    default:
    {
      //only NULL does not have a value
      bool lHaveVal = !(json_is_null(aValue));

      std::string lType, lValue;
      if(json_is_null(aValue))
      {
        lType  = "null";
        lValue = "null";
      }
      else if(json_is_string(aValue))
      {
        lType  = "string";
        lValue = json_string_value(aValue);
      }
      else if(json_is_number(aValue))
      {
        lType  = "number";

        //json_string_value works just for STRING items so we have to use
        //json_number_value that returns a double
        std::ostringstream lOss;
        lOss << json_number_value(aValue);
        lValue = lOss.str();
      }
      else if(json_is_boolean(aValue))
      {
        lType  = "boolean";
        lValue = json_is_true(aValue)?"true":"false";
      }

      zorba::String lName(aKey);
      std::string lParent(aParentType);
      std::string lItemName = (lParent.compare("object") == 0)?"pair":"item";


      aSs << "<" << lItemName;
      if(!lName.empty())
      {
        aSs <<" name=\"" << lName << "\"";
      }
      aSs << " type=\"" << lType;
      if(lHaveVal)
      {
        replace_special_chars(lValue);
        aSs << "\">" << lValue << "</" << lItemName << ">";
      }
      else
        aSs << "\"/>";

      break;
    }
  }
}


void JSON_parse(
  const char* aJsonString,
  std::stringstream& aSs,
  std::stringstream& aErrorLogSs)
{
  json_error_t lerror;
  json_t *ljson;

  #if JANSSON_MAJOR_VERSION < 2
    ljson = json_loads(aJsonString, &lerror);
  #else
    ljson = json_loads(aJsonString, 0, &lerror);
  #endif

  if(!ljson)
  {
    #if JANSSON_MAJOR_VERSION < 2
      aErrorLogSs << "Error at line: " << lerror.line << std::endl;
      aErrorLogSs << lerror.text << std::endl;
    #else
      aErrorLogSs << "Error at line: " << lerror.line << " column: " << lerror.column << " position: " << lerror.position << std::endl;
      aErrorLogSs << lerror.text << std::endl;
    #endif
    return;
  }

  const char *lKey;
  json_t *lValue;
  lKey = json_object_iter_key(ljson);

  if(json_is_object(ljson))
  {
    aSs << "<json type=\"object\">";
    void *lIter = json_object_iter(ljson);
    while(lIter)
    {
      lKey = json_object_iter_key(lIter);
      lValue = json_object_iter_value(lIter);

      parse_Json_value(lKey, lValue, "object", aSs, aErrorLogSs);

      lIter = json_object_iter_next(ljson, lIter);
    }
    aSs << "</json>";
  }
  else if(json_is_array(ljson))
  {
    std::string lEmptyStr("");
    aSs << "<json type=\"array\">";
    for(size_t i = 0; i < json_array_size(ljson); i++)
    {
      lValue = json_array_get(ljson, i);

      parse_Json_value(lEmptyStr.c_str(), lValue, "array", aSs, aErrorLogSs);
    }
    aSs << "</json>";
  }
  else
    aErrorLogSs << "Either one of ARRAY and OBJECT are considered valid JSON." << std::endl;

}

void get_text_value(
  const zorba::Item&  aElement,
  zorba::String&      aValue)
{
  zorba::Iterator_t lChildrenIt;
  zorba::Item       lChild;

  lChildrenIt = aElement.getChildren();
  lChildrenIt->open();
  while (lChildrenIt->next(lChild))
  {
    if (lChild.getNodeKind() == store::StoreConsts::textNode)
      aValue = lChild.getStringValue();
  }
  lChildrenIt->close();
}

void serialize_element(
    const zorba::Item& aElement,
    std::stringstream& aResultSs,
    std::stringstream& aErrorLogSs,
    const std::string& aParentType)
{
  zorba::Iterator_t lAttrIt, lChildrenIt;
  zorba::Item       lAttr, lChild;
  zorba::String     lName, lType;

  Item lNodeNameItem;
  aElement.getNodeName(lNodeNameItem);

  if(((aParentType.compare("object") == 0) &&
       !(lNodeNameItem.getStringValue() == "pair" || lNodeNameItem.getStringValue() == "json")) ||
     ((aParentType.compare("array")  == 0) && lNodeNameItem.getStringValue() != "item"))
  {
    aErrorLogSs << "'Object' should have only 'pair' children and 'array' should have only 'item' children." << std::endl;
    return;
  }

  lAttrIt = aElement.getAttributes();
  lAttrIt->open();
  while (lAttrIt->next(lAttr))
  {
    if(lAttr.getNodeKind() == store::StoreConsts::attributeNode)
    {
      Item lNodeNameItem;
      lAttr.getNodeName(lNodeNameItem);
      if(lNodeNameItem.getStringValue() == "type")
        lType = lAttr.getStringValue();
      else if(lNodeNameItem.getStringValue() == "name")
        lName = lAttr.getStringValue();
    }
  }
  lAttrIt->close();

  if(lType.empty())
  {
    aErrorLogSs << "Element does not have a 'type' attribute defined." << std::endl;
    return;
  }

  if(lType == "object")
  {
    if(!lName.empty())
      aResultSs << "\"" << lName.c_str() << "\": ";

    //serialize every children
    aResultSs << "{";
    serialize_child(aElement, aResultSs, aErrorLogSs, "object");
    aResultSs << "}";
  }
  else if(lType == "array")
  {
    if(!lName.empty())
      aResultSs << "\"" << lName.c_str() << "\": ";

    //serialize every children
    aResultSs << "[";
    serialize_child(aElement, aResultSs, aErrorLogSs, "array");
    aResultSs << "]";
  }
  else if(lType == "string")
  {
    zorba::String lValue;
    get_text_value(aElement, lValue);
    zorba::Item lNodeNameItem;
    aElement.getNodeName(lNodeNameItem);
    if(lNodeNameItem.getStringValue() == "pair")
    {
      if(lName.empty())
      {
        aErrorLogSs << "Element does not have a 'name' attribute defined." << std::endl;
        return;
      }
      if(aParentType.compare("object") != 0)
      {
        aErrorLogSs << "'Pair' is allowed only as part of an object." << std::endl;
        return;
      }
      aResultSs << "\"" << lName.c_str() << "\": ";
    }
    aResultSs << "\"" << lValue.c_str() << "\"";
  }
  else if(lType == "null")
  {
    zorba::Item lNodeNameItem;
    aElement.getNodeName(lNodeNameItem);
    if(lNodeNameItem.getStringValue() == "pair")
    {
      aResultSs << "\"" << lName.c_str() << "\": ";
    }
    aResultSs << "null";
  }
  else if(lType == "number" ||
          lType == "boolean")
  {
    zorba::String lValue;
    get_text_value(aElement, lValue);
    zorba::Item lNodeNameItem;
    aElement.getNodeName(lNodeNameItem);
    if(lNodeNameItem.getStringValue() == "pair")
    {
      aResultSs << "\"" << lName.c_str() << "\": ";
    }
    aResultSs << lValue.c_str();
  }
  else
  {
    aErrorLogSs << "Type '" << lType.c_str() << "' not recognized." << std::endl;
    return;
  }
}

void serialize_child(
  const zorba::Item& aElement,
  std::stringstream& aResultSs,
  std::stringstream& aErrorLogSs,
  const std::string& aParentType)
{
  bool lFirst = true;
  zorba::Iterator_t lChildrenIt;
  zorba::Item       lChild;

  lChildrenIt = aElement.getChildren();
  lChildrenIt->open();
  while (lChildrenIt->next(lChild))
  {
    if(lChild.getNodeKind() == store::StoreConsts::elementNode)
    {
      if(!lFirst)
        aResultSs << ", ";

      serialize_element(lChild, aResultSs, aErrorLogSs, aParentType);
      lFirst = false;
    }
  }
  lChildrenIt->close();
}

void JSON_serialize(
  const zorba::Item& aElement,
  std::stringstream& aResultSs,
  std::stringstream& aErrorLogSs)
{
  if (aElement.isNull())
  {
    aErrorLogSs << "Passed a NULL element to the JSON serializer." << std::endl;
    return;
  }

  if(!(aElement.getNodeKind() == store::StoreConsts::documentNode ||
       aElement.getNodeKind() == store::StoreConsts::elementNode))
  {
    aErrorLogSs << "Passed an incorrect Item to the JSON serializer." << std::endl;
    return;
  }

  Item lNodeNameItem;
  aElement.getNodeName(lNodeNameItem);

  if(!lNodeNameItem.isNull() && lNodeNameItem.getStringValue() != "json")
  {
    aErrorLogSs << "This is not a JSON element." << std::endl;
    return;
  }

  if(aElement.getNodeKind() == store::StoreConsts::documentNode)
  {
    serialize_child(aElement, aResultSs, aErrorLogSs, "object");
    return;
  }

  zorba::Iterator_t lAttrIt;
  zorba::Item       lAttr;
  zorba::String     lType;
  lAttrIt = aElement.getAttributes();
  lAttrIt->open();
  while (lAttrIt->next(lAttr))
  {
    if(lAttr.getNodeKind() == store::StoreConsts::attributeNode)
    {
      Item lNodeNameItem;
      lAttr.getNodeName(lNodeNameItem);
      if(lNodeNameItem.getStringValue() == "type")
        lType = lAttr.getStringValue();
      else
      {
        aErrorLogSs << "Could not retrieve the type of the Json root." << std::endl;
        return;
      }
    }
  }
  lAttrIt->close();


  if(lType == "object")
    aResultSs << "{";
  else
    aResultSs << "[";

  serialize_child(aElement, aResultSs, aErrorLogSs, "object");

  if(!aErrorLogSs.str().empty())
  {
    if(lType == "object")
      aResultSs << "}";
    else
      aResultSs << "]";
  }
}

static void parse_JSON_ML_value(
    const char *aKey,
    json_t *aValue,
    const char* aParentType,
    std::stringstream& aSs,
    std::stringstream& aErrorLogSs,
    bool               aShouldClose = false)
{
  if(!aValue)
    return;

  switch(json_typeof(aValue))
  {
    case JSON_OBJECT:
    {
      const char *lKey;
      json_t *lValue;
      std::string lTmp(aKey);

      void *lIter = json_object_iter(aValue);
      while(lIter)
      {
        lKey = json_object_iter_key(lIter);
        lValue = json_object_iter_value(lIter);

        parse_JSON_ML_value(lKey, lValue, "object", aSs, aErrorLogSs);

        lIter = json_object_iter_next(aValue, lIter);
      }
      aSs << ">";
      break;
    }
    case JSON_ARRAY:
    {
      json_t *lValue;
      zorba::String lName(""), lEmptyStr("");
      bool    lShouldClose = true;

      std::string lParent(aParentType);
      if(lParent.compare("array") == 0)
      {
        for(size_t i = 0; i < json_array_size(aValue); i++)
        {
          lValue = json_array_get(aValue, i);

          if(json_is_object(lValue))
            lShouldClose = false;
        }

        aSs << "<";
      }

      std::string lTmp;
      for(size_t i = 0; i < json_array_size(aValue); i++)
      {
        lValue = json_array_get(aValue, i);

        parse_JSON_ML_value(lEmptyStr.c_str(), lValue, "array", aSs, aErrorLogSs, lShouldClose);

        if(lShouldClose)
          lShouldClose = false;
      }

      lValue = json_array_get(aValue, 0);
      if(json_is_string(lValue))
        lName = json_string_value(lValue);

      if(lParent.compare("array") == 0)
        aSs << "</" << lName << ">";

      break;
    }
    default:
    {
      zorba::String lType, lValue;
      if(json_is_string(aValue))
      {
        lType  = "string";
        lValue = json_string_value(aValue);
      }
      else if(json_is_boolean(aValue))
      {
        lType = json_is_true(aValue)?"true":"false";
        lValue = lType;
      }
      else if(json_is_number(aValue))
      {
        lType = "number";

        //json_string_value works just for STRING items so we have to use
        //json_number_value that returns a double
        std::ostringstream lOss;
        lOss << json_number_value(aValue);
        lValue = lOss.str();
      }
      else if(json_is_null(aValue))
      {
        lType = lValue = "null";
      }

      zorba::String lName(aKey);
      std::string lParent(aParentType);

      if(lParent.compare("array") == 0)
        aSs << lValue;
      else if(lParent.compare("object") == 0)
      {
        aSs << " " << lName << "=";
        if(lType.compare("string") == 0)
          aSs << "\"" << lValue << "\"";
        else
          aSs << lValue;
      }

      if(aShouldClose)
        aSs << ">";

      break;
    }
  }
}

void JSON_ML_parse(
  const char* aJsonString,
  std::stringstream& aSs,
  std::stringstream& aErrorLogSs)
{
  json_error_t lerror;
  json_t *ljson;
  zorba::String lEmptyStr("");

  #if JANSSON_MAJOR_VERSION < 2
    ljson = json_loads(aJsonString, &lerror);
  #else
    ljson = json_loads(aJsonString, 0, &lerror);
  #endif
  if(!ljson)
  {
    #if JANSSON_MAJOR_VERSION < 2
      aErrorLogSs << "Error at line: " << lerror.line << std::endl;
      aErrorLogSs << lerror.text << std::endl;
    #else
      aErrorLogSs << "Error at line: " << lerror.line << " column: " << lerror.column << " position: " << lerror.position << std::endl;
      aErrorLogSs << lerror.text << std::endl;
    #endif
    return;
  }

  if(!json_is_array(ljson))
    aErrorLogSs << "ARRAY is the only accepted root for the Json-ML mapping." << std::endl;

  parse_JSON_ML_value(lEmptyStr.c_str(), ljson, "array", aSs, aErrorLogSs);
}

void JSON_ML_serialize(
  const zorba::Item& aElement,
  std::stringstream& aResultSs,
  std::stringstream& aErrorLogSs)
{
  if (aElement.isNull())
  {
    aErrorLogSs << "Passed a NULL element to the JSON serializer." << std::endl;
    return;
  }

  if(!(aElement.getNodeKind() == store::StoreConsts::documentNode ||
       aElement.getNodeKind() == store::StoreConsts::elementNode ||
       aElement.getNodeKind() == store::StoreConsts::textNode))
  {
    aErrorLogSs << "Passed an incorrect Item to the JSON serializer." << std::endl;
    return;
  }

  if(aElement.getNodeKind() == store::StoreConsts::textNode)
  {
    aResultSs << "\"" << aElement.getStringValue().c_str() << "\"";
    return;
  }

  Item lNodeNameItem;
  aElement.getNodeName(lNodeNameItem);

  aResultSs << "[\"" << lNodeNameItem.getStringValue().c_str() << "\"";

  zorba::Iterator_t lAttrIt;
  zorba::Item       lAttr;
  zorba::String     lType;
  bool lHasAttributes = false;

  lAttrIt = aElement.getAttributes();
  lAttrIt->open();
  while (lAttrIt->next(lAttr))
  {
    if(lAttr.getNodeKind() == store::StoreConsts::attributeNode)
    {
      lHasAttributes = true;
      break;
    }
  }
  lAttrIt->close();

  if(lHasAttributes)
    aResultSs << ",{";

  bool lFirst = true;
  lAttrIt = aElement.getAttributes();
  lAttrIt->open();
  while (lAttrIt->next(lAttr))
  {
    if(lAttr.getNodeKind() == store::StoreConsts::attributeNode)
    {
      Item lNodeNameItem;
      lAttr.getNodeName(lNodeNameItem);
      if(!lFirst)
        aResultSs << ",";

      aResultSs << "\"" << lNodeNameItem.getStringValue().c_str() << "\":";
      aResultSs << "\"" << lAttr.getStringValue().c_str() << "\"";
      lFirst = false;
    }
  }
  lAttrIt->close();
  if(lHasAttributes)
    aResultSs << "}";

  zorba::Iterator_t lChildrenIt;
  zorba::Item       lChild;

  lChildrenIt = aElement.getChildren();
  lChildrenIt->open();
  while (lChildrenIt->next(lChild))
  {
    aResultSs << ",";
    if (lChild.getNodeKind() == store::StoreConsts::elementNode ||
        lChild.getNodeKind() == store::StoreConsts::textNode)
      JSON_ML_serialize(lChild, aResultSs, aErrorLogSs);
  }
  lChildrenIt->close();

  aResultSs << "]";
}

  } /* namespace jsonmodule */
} /* namespace zorba */
