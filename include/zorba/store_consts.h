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
#ifndef ZORBA_STORE_STORE_CONSTS_H
#define ZORBA_STORE_STORE_CONSTS_H

#include <string>
#include <zorba/config.h>

namespace zorba { namespace store {

/*******************************************************************************
  !!! ATTENTION: The order of the enum values within SchemaTypeCode is important.
  !!! DO NOT change this order!!!!
********************************************************************************/
enum SchemaTypeCode
{
  XS_ANY_ATOMIC            = 0,

  XS_STRING                = 1,
  XS_NORMALIZED_STRING     = 2,
  XS_TOKEN                 = 3,
  XS_LANGUAGE              = 4,
  XS_NMTOKEN               = 5,
  XS_NAME                  = 6,
  XS_NCNAME                = 7,
  XS_ID                    = 8,
  XS_IDREF                 = 9,
  XS_ENTITY                = 10,

  XS_UNTYPED_ATOMIC        = 11,

  XS_DATETIME              = 12,
  XS_DATE                  = 13,
  XS_TIME                  = 14,

  XS_DURATION              = 15,
  XS_DT_DURATION           = 16,
  XS_YM_DURATION           = 17,

  XS_FLOAT                 = 18,
  XS_DOUBLE                = 19,

  XS_DECIMAL               = 20,
  XS_INTEGER               = 21,
  XS_NON_POSITIVE_INTEGER  = 22,
  XS_NEGATIVE_INTEGER      = 23,
  XS_LONG                  = 24,
  XS_INT                   = 25,
  XS_SHORT                 = 26,
  XS_BYTE                  = 27,
  XS_NON_NEGATIVE_INTEGER  = 28,
  XS_UNSIGNED_LONG         = 29,
  XS_UNSIGNED_INT          = 30,
  XS_UNSIGNED_SHORT        = 31,
  XS_UNSIGNED_BYTE         = 32,
  XS_POSITIVE_INTEGER      = 33,

  XS_GYEAR_MONTH           = 34,
  XS_GYEAR                 = 35,
  XS_GMONTH_DAY            = 36,
  XS_GDAY                  = 37,
  XS_GMONTH                = 38,

  XS_BOOLEAN               = 39,

  XS_BASE64BINARY          = 40,
  XS_HEXBINARY             = 41,

  XS_ANY_URI               = 42,

  XS_QNAME                 = 43,
  XS_NOTATION              = 44,
  
  JDM_NULL                 = 45,

  XS_LAST
};


class ZORBA_DLL_PUBLIC StoreConsts
{
 public:

  enum NsScoping 
  {
    ALL_NAMESPACES,
    ONLY_LOCAL_NAMESPACES,
    ONLY_PARENT_NAMESPACES
  };

  enum NodeKind
  {
    anyNode        = 0,
    documentNode   = 1,
    elementNode    = 2,
    attributeNode  = 3,
    textNode       = 4,
    piNode         = 5,
    commentNode    = 6
  };

  static std::string toString(NodeKind k)
  {
    switch(k) 
    {
    case anyNode:
      return "anyNode";

    case documentNode:
      return "documentNode";

    case elementNode:
      return "elementNode";

    case attributeNode:
      return "attributeNode";

    case textNode:
      return "textNode";

    case piNode:
      return "piNode";

    case commentNode:
      return "commentNode";

    default:
      return "<unknown NodeKind>";
    }
  }

  static std::string toSchemaString(NodeKind k)
  {
    switch(k) 
    {
    case anyNode:
      return "node";

    case documentNode:
      return "document-node";

    case elementNode:
      return "element";

    case attributeNode:
      return "attribute";

    case textNode:
      return "text";

    case piNode:
      return "processing-instruction";

    case commentNode:
      return "comment";

    default:
      return "<unknown NodeKind>";
    }
  }


  /* ATTENTION: the ordering of the enum values is important. Do NOT change it! */
  enum JSONItemKind
  {
    jsonItem       = 0,
    jsonObject     = 1,
    jsonArray      = 2,
    jsonPair       = 3
  };


  static std::string toString(JSONItemKind k)
  {
    switch(k) 
    {
      case jsonItem:
        return "json-item";

      case jsonObject:
        return "object";

      case jsonArray:
        return "array";

      case jsonPair:
        return "pair";

      default:
        return "<unknown JSONItemKind>";
    }
  }
};

} // namespace store
} // namespace zorba
#endif
/* vim:set et sw=2 ts=2: */
