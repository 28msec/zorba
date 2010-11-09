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

#ifndef ZORBA_NO_UNICODE
#include <unicode/ustring.h>
#endif /* ZORBA_NO_UNICODE */

#include "utf8_util.h"
#include "zorbatypes/zorbatypesError.h"

#ifndef ZORBA_NO_UNICODE
U_NAMESPACE_USE
#endif /* ZORBA_NO_UNICODE */

unsigned const Mask1Byte   = 0x80;
unsigned const Mask2Bytes  = 0xC0;
unsigned const Mask3Bytes  = 0xE0;
unsigned const Mask4Bytes  = 0xF0;
unsigned const Mask5Bytes  = 0xF8;
unsigned const Mask6Bytes  = 0xFC;

namespace zorba {
namespace utf8 {

ZORBA_DLL_PUBLIC extern char const char_length_table [] = {
/*      0 1 2 3 4 5 6 7 8 9 A B C D E F */
/* 0 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 1 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 2 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 3 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 4 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 5 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 6 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 7 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 8 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* 9 */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* A */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* B */ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/* C */ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
/* D */ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
/* E */ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
/* F */ 4,4,4,4,4,4,4,4,5,5,5,5,6,6,1,1
};

unicode::code_point const SubChar = 0xFFFD;

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

size_type byte_pos( storage_type const *s, size_type s_size,
                    size_type char_pos ) {
  if ( char_pos == npos )
    return npos;
  storage_type const *p = s;
  storage_type const *const end = s + s_size;
  for ( ; char_pos > 0; --char_pos ) {
    if ( p >= end )
      return npos;
    p += char_length( *p );
  }
  return p - s;
}

size_type char_pos( storage_type const *s, storage_type const *p ) {
  size_type pos = 0;
  while ( s < p ) {
    s += char_length( *s );
    ++pos;
  }
  return pos;
}

size_type encode( unicode::code_point c, storage_type **ps ) {
  if ( !unicode::is_valid( c ) )
    throw zorbatypesException( "", ZorbatypesError::FOCH0001 );
  unsigned const n = c & 0xFFFFFFFF;
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

size_type length( storage_type const *s ) {
  size_type len = 0;
  while ( *s ) {
    s += char_length( *s );
    ++len;
  }
  return len;
}

size_type length( storage_type const *begin, storage_type const *end ) {
  size_type len = 0;
  while ( begin < end && *begin ) {
    begin += char_length( *begin );
    ++len;
  }
  return len;
}

#ifndef ZORBA_NO_UNICODE

bool to_string( unicode::char_type const *in, size_type in_len,
                storage_type **out, size_type *out_len ) {
  UErrorCode err = U_ZERO_ERROR;
  unicode::size_type utf8_len;
  u_strToUTF8WithSub(                   // pre-flight to get utf8_len
    NULL, 0, &utf8_len, in, in_len, SubChar, NULL, &err
  );
  // must not check "err" here since ICU always returns "buffer overflow"

  storage_type *const utf8_buf = new storage_type[ utf8_len ];
  err = U_ZERO_ERROR;
  u_strToUTF8WithSub(
    utf8_buf, utf8_len, NULL, in, in_len, SubChar, NULL, &err
  );
  if ( U_FAILURE( err ) ) {
    delete[] utf8_buf;
    return false;
  }
  *out = utf8_buf;
  *out_len = utf8_len;
  return true;
}

#ifndef WIN32
bool to_string( wchar_t const *in, size_type in_len, storage_type **out,
                size_type *out_len ) {
  bool result = false;
  unicode::string temp;
  if ( unicode::to_string( in, in_len, &temp ) ) {
    size_type const temp_len = temp.length();
    unicode::char_type *const buf = temp.getBuffer( -1 );
    result = utf8::to_string( buf, temp_len, out, out_len );
    temp.releaseBuffer();
  }
  return result;
}
#endif /* WIN32 */

#endif /* ZORBA_NO_UNICODE */

} // namespace utf8
} // namespace zorba

/* vim:set et sw=2 ts=2: */
