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


#ifdef ZORBA_WITH_JSON

  enum JSONItemKind
  {
    jsonItem,
    jsonObject,
    jsonArray,
    jsonPair,
    jsonObjectPair,
    jsonArrayPair
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

      case jsonObjectPair:
        return "object-pair";

      case jsonArrayPair:
        return "array-pair";

      default:
        return "<unknown JSONItemKind>";
    }
  }

#endif // ZORBA_WITH_JSON
 
};

} // namespace store
} // namespace zorba
#endif
/* vim:set et sw=2 ts=2: */
