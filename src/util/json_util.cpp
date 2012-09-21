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
#include <iomanip>
#include <iostream>

//#define ZORBA_JSON_EMIT_SURROGATES

#include "util/stl_util.h"
#ifdef ZORBA_JSON_EMIT_SURROGATES
#include "util/unicode_util.h"
#endif /* ZORBA_JSON_EMIT_SURROGATES */
#include "util/utf8_util.h"

using namespace std;

namespace zorba {
namespace json {

///////////////////////////////////////////////////////////////////////////////

ostream& serialize( ostream &os, char const *s ) {
  while ( true ) {
    unicode::code_point const cp = utf8::next_char( s );
    if ( !cp )
      break;
    if ( ascii::is_cntrl( cp ) ) {
      switch ( cp ) {
        case '\b': os << "\\b"; break;
        case '\f': os << "\\f"; break;
        case '\n': os << "\\n"; break;
        case '\r': os << "\\r"; break;
        case '\t': os << "\\t"; break;
        default: {
          std::ostringstream oss;
          oss << std::hex << std::setfill('0') << "\\u" << std::setw(4) << cp;
          os << oss.str();
        }
      }
      continue;
    }
#ifdef ZORBA_JSON_EMIT_SURROGATES
    if ( unicode::is_supplementary_plane( cp ) ) {
      unsigned high, low;
      unicode::convert_surrogate( cp, &high, &low );
      std::ostringstream oss;
      oss << std::hex << std::setfill('0')
          << "\\u" << std::setw(4) << high
          << "\\u" << std::setw(4) << low;
      os << oss.str();
      continue;
    }
#endif /* ZORBA_JSON_EMIT_SURROGATES */
    switch ( cp ) {
      case '\\':
      case '"':
        os << '\\';
        // no break;
      default: {
        utf8::encoded_char_type ec;
        os.write( ec, utf8::encode( cp, ec ) );
      }
    }
  }
  return os;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba
/* vim:set et sw=2 ts=2: */
