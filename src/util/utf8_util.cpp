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

// standard
#include <algorithm>
#include <cstring>

// ICU
#ifndef ZORBA_NO_ICU
#include <unicode/ustring.h>
#endif /* ZORBA_NO_ICU */

// Zorba
#include <zorba/internal/cxx_util.h>

// local
#include "ascii_util.h"
#include "utf8_util.h"

using namespace std;
#ifndef ZORBA_NO_ICU
U_NAMESPACE_USE
#endif /* ZORBA_NO_ICU */

unsigned const Mask1Byte   = 0x80;
unsigned const Mask2Bytes  = 0xC0;
unsigned const Mask3Bytes  = 0xE0;
unsigned const Mask4Bytes  = 0xF0;
unsigned const Mask5Bytes  = 0xF8;
unsigned const Mask6Bytes  = 0xFC;

namespace zorba {
namespace utf8 {

///////////////////////////////////////////////////////////////////////////////

invalid_byte::invalid_byte( char byte ) :
  invalid_argument( make_what( byte ) ),
  byte_( byte )
{
}

invalid_byte::~invalid_byte() throw() {
  // out-of-line since it's virtual
}

string invalid_byte::make_what( storage_type byte ) {
  return BUILD_STRING(
    '\'', ascii::printable_char( byte ), "': invalid UTF-8 byte"
  );
}

///////////////////////////////////////////////////////////////////////////////

size_type byte_pos( storage_type const *s, size_type char_pos ) {
  if ( char_pos == npos )
    return npos;
  storage_type const *p = s;
  for ( ; char_pos > 0; --char_pos ) {
    if ( !*p )
      return npos;
    p += char_length( *p );
  }
  return p - s;
}

size_type byte_pos( storage_type const *s, size_type s_len,
                    size_type char_pos ) {
  if ( char_pos == npos )
    return npos;
  storage_type const *p = s;
  storage_type const *const end = s + s_len;
  for ( ; char_pos > 0; --char_pos ) {
    if ( p >= end )
      return npos;
    p += char_length( *p );
  }
  return p - s;
}

size_type char_length( storage_type start ) {
  static char const table[] = {
    /*      0 1 2 3 4 5 6 7 8 9 A B C D E F */
    /* 0 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 1 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 2 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 3 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 4 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 5 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 6 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 7 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    /* 8 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  // continuation bytes
    /* 9 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //        |
    /* A */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //        |
    /* B */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //        |
    /* C */ 0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,  // C0 & C1 are overlong ASCII
    /* D */ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    /* E */ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
    /* F */ 4,4,4,4,4,4,4,4,5,5,5,5,6,6,0,0
  };
  if ( size_type const c_len = table[ static_cast<unsigned char>( start ) ] )
    return c_len;
  throw invalid_byte( start );
}

size_type char_pos( storage_type const *s, storage_type const *p ) {
  size_type pos = 0;
  while ( s < p ) {
    s += char_length( *s );
    ++pos;
  }
  return pos;
}

size_type encode( unicode::code_point cp, storage_type **ps ) {
  if ( !unicode::is_valid( cp ) )
    return 0;
  unsigned const n = cp & 0xFFFFFFFF;
  storage_type *&p = *ps, *const p0 = p;
  if ( n < 0x80 ) {
    // 0xxxxxxx
    *p++ = static_cast<storage_type>( n );
  } else if ( n < 0x800 ) {
    // 110xxxxx 10xxxxxx
    *p++ = static_cast<storage_type>( Mask2Bytes | ( n >> 6 )         );
    *p++ = static_cast<storage_type>( Mask1Byte  | ( n        & 0x3F) );
  } else if ( n < 0x10000 ) {
    // 1110xxxx 10xxxxxx 10xxxxxx
    *p++ = static_cast<storage_type>( Mask3Bytes |  (n >> 12)         );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >>  6) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ( n        & 0x3F) );
  } else if ( n < 0x200000 ) {
    // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    *p++ = static_cast<storage_type>( Mask4Bytes |  (n >> 18)         );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >> 12) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >>  6) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ( n        & 0x3F) );
  } else if ( n < 0x4000000 ) {
    // 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
    *p++ = static_cast<storage_type>( Mask5Bytes |  (n >> 24)         );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >> 18) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >> 12) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >>  6) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ( n        & 0x3F) );
  } else if ( n < 0x8000000 ) {
    // 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
    *p++ = static_cast<storage_type>( Mask6Bytes |  (n >> 30)         );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >> 24) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >> 18) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >> 12) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ((n >>  6) & 0x3F) );
    *p++ = static_cast<storage_type>( Mask1Byte  | ( n        & 0x3F) );
  }
  return p - p0;
}

storage_type* itou( unsigned long long n, storage_type *buf,
                    unicode::code_point zero ) {
  storage_type *s = buf;
  encoded_char_type utf8_digit[10];     // cache of UTF-8 bytes for each digit
  size_type utf8_size[10];              // number of UTF-8 bytes for each digit

  std::fill( utf8_size, utf8_size + 10, 0 );
  do {
    unsigned long long const n_prev = n;
    n /= 10;
    unsigned long long const digit = n_prev - n * 10;
    if ( !utf8_size[ digit ] ) {        // didn't cache previously: cache now
      unicode::code_point const cp = static_cast<unicode::code_point>( digit );
      utf8_size[ digit ] = encode( zero + cp, utf8_digit[ digit ] );
    }
    //
    // Copy the UTF-8 bytes into buf backwards so when we reverse the entire
    // buffer later (to reverse the digit order to put them the right way
    // around), we can treat buf as a simple string and ignore multi-byte UTF-8
    // character boundaries.
    //
    for ( size_type i = utf8_size[ digit ]; i; )
      *s++ = utf8_digit[ digit ][ --i ];

  } while ( n );

  *s = '\0';
  std::reverse( buf, s );
  return buf;
}

size_type length( storage_type const *s ) {
  size_type total_len = 0;
  while ( *s ) {
    s += char_length( *s );
    ++total_len;
  }
  return total_len;
}

size_type length( storage_type const *begin, storage_type const *end ) {
  size_type total_len = 0;
  while ( begin < end && *begin ) {
    begin += char_length( *begin );
    ++total_len;
  }
  return total_len;
}

size_type read( istream &i, storage_type **ps ) {
  char c = i.get();
  if ( !i.good() )
    return 0;
  storage_type *&p = *ps;
  *p++ = c;
  size_type const c_len = char_length( c );
  for ( size_type got = 1; got < c_len; ++got ) {
    c = i.get();
    if ( !i.good() )
      return 0;
    *p++ = c;
    if ( !is_continuation_byte( c ) )
      throw invalid_byte( c );
  }
  return c_len;
}

#ifndef ZORBA_NO_ICU

bool to_string( unicode::char_type const *in, unicode::size_type in_len,
                storage_type **out, size_type *out_len ) {
  unicode::code_point const SubChar = 0xFFFD;

  UErrorCode err = U_ZERO_ERROR;
  unicode::size_type utf8_len;
  u_strToUTF8WithSub(                   // pre-flight to get utf8_len
    nullptr, 0, &utf8_len, in, in_len, SubChar, nullptr, &err
  );
  // must not check "err" here since ICU always returns "buffer overflow"

  storage_type *const utf8_buf = new storage_type[ utf8_len ];
  err = U_ZERO_ERROR;
  u_strToUTF8WithSub(
    utf8_buf, utf8_len, nullptr, in, in_len, SubChar, nullptr, &err
  );
  if ( U_FAILURE( err ) ) {
    delete[] utf8_buf;
    return false;
  }
  *out = utf8_buf;
  if ( out_len )
    *out_len = utf8_len;
  return true;
}

#ifndef WIN32
bool to_string( wchar_t const *in, size_type in_len, storage_type **out,
                size_type *out_len ) {
  unicode::string temp;
  if ( !unicode::to_string( in, in_len, &temp ) )
    return false;
  return utf8::to_string( temp.getBuffer(), temp.length(), out, out_len );
}
#endif /* WIN32 */

bool to_wchar_t( storage_type const *in, size_type in_len, wchar_t **out,
                 unicode::size_type *out_len ) {
  unicode::string u_in;
  if ( !unicode::to_string( in, in_len, &u_in ) )
    return false;
  unicode::size_type const u_len = u_in.length();
  unicode::char_type const *const in_buf = u_in.getBuffer();

  unicode::size_type w_len;
  UErrorCode err = U_ZERO_ERROR;
  u_strToWCS( nullptr, 0, &w_len, in_buf, u_len, &err );
  if ( err == U_BUFFER_OVERFLOW_ERROR ) {
    *out = new wchar_t[ ++w_len ];
    err = U_ZERO_ERROR;
    u_strToWCS( *out, w_len, nullptr, in_buf, u_len, &err );
  }
  u_in.releaseBuffer();
  if ( U_FAILURE( err ) ) {
    delete[] *out;
    return false;
  }
  if ( out_len )
    *out_len = w_len;
  return true;
}

#endif /* ZORBA_NO_ICU */

storage_type const* validate( storage_type const *s ) {
  try {
    for ( ; *s; ++s ) {
      for ( size_type c_len = char_length( *s ); --c_len; )
        if ( !is_continuation_byte( *++s ) )
          return s;
    }
    return nullptr;
  }
  catch ( invalid_byte const& ) {
    return s;
  }
}

storage_type const* validate( storage_type const *s, size_type s_len ) {
  try {
    for ( ; s_len; ++s, --s_len ) {
      for ( size_type c_len = char_length( *s ); --c_len; )
        if ( !--s_len || !is_continuation_byte( *++s ) )
          return s;
    }
    return nullptr;
  }
  catch ( invalid_byte const& ) {
    return s;
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba
/* vim:set et sw=2 ts=2: */
