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
#include "representations.h"

namespace zorba {

class URI
{
 public:

  typedef enum {
    INVALID_URI,
    RESOLUTION_ERROR,
    MAX_ERROR_CODE
  } error_t;

  static bool is_valid (const xqpStringStore_t& uri, bool has_base_uri = true);

  // Has semantics of fn:resolve-uri (uri, base):
  // * if @p rel is absolute OR if @p base is relative, result is @p rel
  // * otherwise attempts relative URI resolution
  // @return error code, or URI::MAX_ERROR_CODE if no error
  static error_t resolve_relative(
        const xqpStringStore_t& base,
        const xqpStringStore_t& rel,
        xqpStringStore_t&       result);

  static xqpStringStore_t  decode_file_URI(const xqpStringStore_t& uri);
  };
}
/*
 * Local variables:
 * mode: c++
 * End:
 */
