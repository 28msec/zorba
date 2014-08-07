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
  // millions of calls to os.write(char) are quite expensive
  // we do manual buffering here which gives approx. 30% performance
  // improvement when writing out big json strings
  const unsigned int length = 8192;
  char buffer[length];
  unsigned int i = 0;

  while ( true ) {
    unicode::code_point const cp = utf8::next_char( s );
    if ( !cp )
      break;
    if ( ascii::is_cntrl( cp ) ) {
      if (i > 0) {
        os.rdbuf()->sputn(buffer, i);
        i = 0;
      }
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
      if (i > 0) {
        os.rdbuf()->sputn(buffer, i);
        i = 0;
      }
      os << oss.str();
      continue;
    }
#endif /* ZORBA_JSON_EMIT_SURROGATES */
    switch ( cp ) {
      case '\\':
      case '"':
        if (i > 0) {
          os.rdbuf()->sputn(buffer, i);
          i = 0;
        }
        os << '\\';
        // no break;
      default: {
        if (i + 6 >= length) { // 6 is max length of ec
          os.rdbuf()->sputn(buffer, i);
          i = 0;
        }
        utf8::size_type len = utf8::encode( cp, *reinterpret_cast<utf8::encoded_char_type*>(&buffer[i]) );
        i += len;
      }
    }
  }
  if (i > 0) {
    os.rdbuf()->sputn(buffer, i);
    i = 0;
  }
  return os;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba
/* vim:set et sw=2 ts=2: */
