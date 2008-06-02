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

namespace zorba { namespace store {

class StoreConsts
{
 public:

  enum NodeKind
  {
    anyNode,
    documentNode,
    elementNode,
    attributeNode,
    textNode,
    piNode,
    commentNode
  };

  enum NsScoping 
  {
    ALL_NAMESPACES,
    ONLY_LOCAL_NAMESPACES,
    ONLY_PARENT_NAMESPACES
  };

  static std::string toString(NodeKind k)
  {
    switch(k) {
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
};

} // namespace store
} // namespace zorba
#endif
