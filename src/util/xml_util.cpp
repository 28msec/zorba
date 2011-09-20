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
#include "stdafx.h"

#include <cstdlib>                      /* for strtoul(3) */
#include <cstring>

#include "xml_util.h"

using namespace std;

namespace zorba {
namespace xml {

///////////////////////////////////////////////////////////////////////////////

char const *const version_string_of[] = {
  "1.0",
  "1.1"
};

///////////////////////////////////////////////////////////////////////////////

int parse_entity( char const *s, unicode::code_point *c ) {
  char const *const s0 = s;
  if ( *s == '&' && !*++s )
    return -1;
  unsigned long n = 0;
  if ( *s == '#' ) {
    if ( !*++s )
      return -1;
    int base = 10;
    if ( *s == 'x' ) {
      if ( !*++s )
        return -1;
      base = 16;
    }

    //
    // Disallow things that strtoul() normally allows:
    // * leading '0' (for octal)
    // * leading '+' or '-'
    //
    while ( *s == '0' )
      ++s;
    if ( !*s || *s == '+' || *s == '-' )
      return -1;

    n = ::strtoul( s, const_cast<char**>( &s ), base );
    if ( !unicode::is_valid( n ) || *s != ';' )
      return -1;
    ++s;
  } else {
    static char const amp [] = "amp;";
    static char const apos[] = "apos;";
    static char const gt  [] = "gt;";
    static char const lt  [] = "lt;";
    static char const quot[] = "quot;";

    struct entity {
      char const *name;
      int len;
      char equiv;
    };
    static entity const entities[] = {
      { amp , sizeof( amp  ) - 1, '&'  },
      { lt  , sizeof( lt   ) - 1, '<'  },
      { gt  , sizeof( gt   ) - 1, '>'  },
      { apos, sizeof( apos ) - 1, '\'' },
      { quot, sizeof( quot ) - 1, '"'  },
      { 0, 0, 0 }
    };

    for ( entity const *e = entities; e->name; ++e )
      if ( ::strncmp( s, e->name, e->len ) == 0 ) {
        n = e->equiv;
        s += e->len;
        break;
      }

    if ( !n )
      return -1;
  }
  *c = n;
  return s - s0;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace xml
} // namespace zorba
/* vim:set et sw=2 ts=2: */
