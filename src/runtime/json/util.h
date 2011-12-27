/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#ifndef ZORBA_RUNTIME_JSON_UTIL_H
#define ZORBA_RUNTIME_JSON_UTIL_H

#include "store/api/item_factory.h"
#include "zorbatypes/zstring.h"

namespace zorba {

namespace whitespace {
  enum type {
    none,
    some,
    indent
  };
}

namespace json_util {

///////////////////////////////////////////////////////////////////////////////

bool get_attribute_value( store::Item_t const &element, char const *att_name,
                          zstring *att_value );

///////////////////////////////////////////////////////////////////////////////

} // namespace json_util
} // namespace zorba
#endif /* ZORBA_RUNTIME_JSON_UTIL_H */
/* vim:set et sw=2 ts=2: */
