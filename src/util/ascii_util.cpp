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

#include <cstring>

#include "ascii_util.h"

namespace zorba {
namespace ascii {

///////////////////////////////////////////////////////////////////////////////

bool is_whitespace( char const *s ) {
  for ( ; *s; ++s ) {
    if ( !is_space( *s ) )
      return false;
  }
  return true;
}

size_type remove_chars( char *s, size_type s_len, char const *chars ) {
  char *end = s + s_len;
  char *c;

  // remove trailing chars first
  for ( c = end - 1; c >= s; --c )
    if ( !std::strchr( chars, *c ) ) {
      end = c + 1;
      break;
    }
  if ( c < s )                          // it was all chars
    return 0;

  // remove all other chars
  char *first_char = nullptr;
  for ( c = s; c < end; ++c ) { 
    if ( std::strchr( chars, *c ) ) { 
      if ( !first_char ) 
        first_char = c;
    } else { 
      if ( first_char ) { 
        std::memmove( first_char, c, end - c );
        end -= c - first_char;
        c = first_char;
        first_char = nullptr;
      } 
    } 
  } 

  return end - s;
}

char const* trim_start( char const *s, char const *chars ) {
  for ( ; *s; ++s ) {
    if ( !std::strchr( chars, *s ) )
      break;
  }
  return s;
}

char const* trim_start( char const *s, size_type s_len, char const *chars ) {
  for ( ; s_len-- > 0; ++s ) {
    if ( !std::strchr( chars, *s ) )
      break;
  }
  return s;
}

size_type trim_end( char const *s, size_type s_len, char const *chars ) {
  s += s_len - 1;
  for ( ; s_len > 0; --s, --s_len ) {
    if ( !std::strchr( chars, *s ) )
      break;
  }
  return s_len;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ascii
} // namespace zorba
/* vim:set et sw=2 ts=2: */
