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

#include <algorithm>
#include <cstring>

#include "util/less.h"
#include "iso2788.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A less-verbose way to use std::lower_bound.
 */
inline int find_index( char const *const *begin, char const *const *end,
                       char const *s ) {
  char const *const *const entry =
    ::lower_bound( begin, end, s, less<char const*>() );
  return entry != end && ::strcmp( s, *entry ) == 0 ? entry - begin : 0;
}

#define DEF_END(CHAR_ARRAY)                             \
  static char const *const *const end =                 \
    CHAR_ARRAY + sizeof( CHAR_ARRAY ) / sizeof( char* );

#define FIND(what) \
  static_cast<rel_type>( find_index( string_of, end, what ) )

///////////////////////////////////////////////////////////////////////////////

namespace iso2788 {
  char const *const string_of[] = {
    "#UNKNOWN",
    "bt",
    "btg",
    "btp",
    "nt",
    "ntg",
    "ntp",
    "rt",
    "tt",
    "uf",
    "use",
  };

  rel_type find_rel( char const *relationship ) {
    DEF_END( string_of );
    return FIND( relationship );
  }
} // namespace iso2788

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
