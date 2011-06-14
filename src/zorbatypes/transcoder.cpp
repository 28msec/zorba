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

#include <stdexcept>

#include "diagnostics/assert.h"
#include "util/unicode_util.h"
#include "util/utf8_util.h"

#include "transcoder.h"

namespace zorba {

transcoder::transcoder( std::ostream& output_stream, bool in_utf16 ) :
  os( output_stream ),
  utf16( in_utf16 )
{
#ifndef ZORBA_NO_UNICODE
  utf8_buf_len_ = 0;
  utf8_char_len_ = 1;
#endif /* ZORBA_NO_UNICODE */
}

#ifndef ZORBA_NO_UNICODE

void transcoder::write_utf16( char const *s, std::streamsize len ) {
  unicode::char_type *u_s;
  unicode::size_type u_len;
  if ( !unicode::to_string( s, len, &u_s, &u_len ) )
    throw std::runtime_error( "unicode::to_string() failed" );

  char const *const byte = reinterpret_cast<char const*>( u_s );
  for ( int i = 0; i < u_len * (int)sizeof( unicode::char_type ); ++i )
    os << byte[i];

  delete[] u_s;
}

void transcoder::write_utf16_char( char ch ) {
  if ( utf8::is_start_byte( ch ) ) {
    if ( utf8_char_len_ > 1 )
      throw std::runtime_error( "incomplete UTF-8 character" );
    utf8_char_len_ = utf8::char_length( ch );
  } else if ( utf8::is_continuation_byte( ch ) ) {
    if ( !utf8_buf_len_ )
      throw std::runtime_error( "invalid UTF-8 byte" );
  }

  utf8_buf_[ utf8_buf_len_++ ] = ch;

  if ( utf8_buf_len_ == utf8_char_len_ ) {
    unicode::char_type u_ch;
    if ( !unicode::to_char( utf8_buf_, &u_ch ) )
      throw std::runtime_error( "unicode::to_char() failed" );

    char const *const byte = reinterpret_cast<char const*>( &u_ch );
    for ( int i = 0; i < (int)sizeof( unicode::char_type ); ++i )
      os << byte[i];

    utf8_buf_len_ = 0;
    utf8_char_len_ = 1;
  }
}

#endif /* ZORBA_NO_UNICODE */

} // namespace zorba
/* vim:set et sw=2 ts=2: */
