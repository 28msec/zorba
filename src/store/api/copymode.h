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
#ifndef ZORBA_STORE_API_COPYMODE
#define ZORBA_STORE_API_COPYMODE

#include <string>
#include "context/static_context_consts.h"

namespace zorba { namespace store {

class CopyMode
{
public:
  bool  theAssignIds;
  bool  theTypePreserve;
  bool  theNsPreserve;
  bool  theNsInherit;

  CopyMode(
    StaticContextConsts::construction_mode_t aConstrMode,
    StaticContextConsts::preserve_mode_t aPreserveMode,
    StaticContextConsts::inherit_mode_t aInheritMode)
  :
    theAssignIds(true),
    theTypePreserve(aConstrMode == StaticContextConsts::cons_preserve ? true : false),
    theNsPreserve(aPreserveMode == StaticContextConsts::preserve_ns ? true : false),
    theNsInherit(aInheritMode == StaticContextConsts::inherit_ns ? true : false)
  {}

  CopyMode()
    :
    theAssignIds(true),
    theTypePreserve(true),
    theNsPreserve(true),
    theNsInherit(true)
  {
  }

  CopyMode(const CopyMode& aCopyMode)
  :
    theAssignIds(aCopyMode.theAssignIds),
    theTypePreserve(aCopyMode.theTypePreserve),
    theNsPreserve(aCopyMode.theNsPreserve),
    theNsInherit(aCopyMode.theNsInherit)
  {}

  void set(bool assignIds, bool typePreserve, bool nsPreserve, bool nsInherit)
  {
    theAssignIds = assignIds;
    theTypePreserve = typePreserve;
    theNsPreserve = nsPreserve;
    theNsInherit = nsInherit;
  }

  std::string toString() const
  {
    std::string s;
    s = "[";
    s += (theAssignIds ? "T" : "F");
    s += " ";
    s += (theTypePreserve ? "T" : "F");
    s += " ";
    s += (theNsPreserve ? "T" : "F");
    s += " ";
    s += (theNsInherit ? "T" : "F");
    s += "]";
    return s;
  }
};

} // namespace store
} // namespace zorba
#endif
