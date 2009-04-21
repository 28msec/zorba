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

#ifndef ZORBA_UTIL_CONVERTERS_JSON_H
#define ZORBA_UTIL_CONVERTERS_JSON_H

#include "zorbatypes/representations.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

namespace zorba {

  bool JSON_parse(const char* aJSON_string,
                  const unsigned int aLength,
                  store::Item_t& element,
                  xqpStringStore_t baseUri,
                  xqp_string& error_log);

  bool JSON_serialize(const store::Item* element,
                      xqpStringStore_t& json_string,
                      xqpStringStore_t& error_log);

}/*namespace zorba*/

#endif /* ZORBA_UTIL_CONVERTERS_JSON_H */
