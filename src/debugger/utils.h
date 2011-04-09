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

#ifndef ZORBA_DEBUGGER_UTILS_H
#define ZORBA_DEBUGGER_UTILS_H

#include <functional>

#include <jansson.h>

#include "compiler/parser/query_loc.h"
#include "zorbatypes/zstring.h"

namespace zorba
{
  namespace debugger {
    zstring queryLocToJSON(const QueryLoc& aLoc);
    QueryLoc fromJSONToQueryLoc(json_t* obj);
  }

  template<class T> 
  struct destroyer: public std::unary_function<T, void>
  {
    void operator()(T x){ delete x; }
  };

} // namespace zorba
#endif
/* vim:set et sw=2 ts=2: */
