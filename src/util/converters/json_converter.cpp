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

#include "util/converters/json_converter.h"

#include "json/parser.h"
#include "json/value.h"

namespace zorba {

  bool parse(const xqp_string json_string, store::Item_t& element, xqp_string& error_log)
  {
    return true;
  }

  bool serialize(store::Item_t element, xqp_string& json_string, xqp_string& error_log)
  {
    return true;
  }
} /*namespace Zorba */
