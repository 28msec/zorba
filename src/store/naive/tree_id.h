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
#ifndef ZORBA_TREE_ID_H
#define ZORBA_TREE_ID_H

#include "store/naive/shared_types.h"
#include "store/naive/store_defs.h"
#include "zorbatypes/zstring.h"

namespace zorba {

namespace simplestore {

/*
This file (typedef, traits) can be changed to implement a different kind of tree ID
*/

typedef ulong TreeId;

class TreeIdTraits {
public:
  static bool equals(const TreeId& id1, const TreeId& id2)
  {
    return id1 == id2;
  }
  static bool isBefore(const TreeId& id1, const TreeId& id2)
  {
    return id1 < id2;
  }
  static unsigned long int decode(const char* str, char** endptr)
  {
    return strtoul(str, endptr, 10);
  }
  static zstring toString(const TreeId& id)
  {
    std::ostringstream oss;
    oss << std::dec << id;
    return oss.str();
  }
};

} // simplestore
} // zorba

#endif /* ZORBA_TREE_ID_H */
