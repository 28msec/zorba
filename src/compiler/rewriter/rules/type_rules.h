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
#pragma once
#ifndef ZORBA_REWRITER_TYPE_RULES
#define ZORBA_REWRITER_TYPE_RULES


#include "common/shared_types.h"

// TODO: the code below is not used. Should probably be deleted.
/*
#include <set>
#include "zorbautils/hashset.h"

namespace zorba
{
class user_function;


class UDFNode
{
 public:
  user_function      * theUDF;
  std::set<UDFNode*>   theParents;
  std::set<UDFNode*>   theChildren;

 public:

  UDFNode(user_function* udf) : theUDF(udf) {}
};


class UDFHashMapCmp
{
public:

  static bool equal(const user_function* n1, const user_function* n2)
  {
    return n1 == n2;
  }

  static uint32_t hash(const user_function* n)
  {
    return hashfun::h32((void*)(&n), sizeof(user_function*));
  }
};



class UDFGraph : public HashMap<user_function*, UDFNode*, UDFHashMapCmp>
{
public:
  UDFGraph() : HashMap<user_function*, UDFNode*, UDFHashMapCmp>(32, false) {}

  ~UDFGraph();

  void addEdge(user_function* caller, user_function* callee);
};


}
*/

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
