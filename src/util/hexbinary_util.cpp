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

// local
#include "hexbinary_util.h"
#include "string_util.h"

using namespace std;

namespace zorba {
namespace hexbinary {

///////////////////////////////////////////////////////////////////////////////

/**
 * HexBinary decoding table.  A value of -1 means "invalid".
 */
static signed char const decode_table[] = {
  /* 00-07 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 08-0F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 10-17 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 18-1F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 20-27 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 28-2F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 30-37 */  0,  1,  2,  3,  4,  5,  6,  7, // 0 1 2 3 4 5 6 7
  /* 38-3F */  8,  9, -1, -1, -1, -1, -1, -1, // 8 9 . . . . . .
  /* 40-47 */ -1, 10, 11, 12, 13, 14, 15, -1, // . A B C D E F .
  /* 48-4F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 50-57 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 58-5F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 60-67 */ -1, 10, 11, 12, 13, 14, 15, -1, // . a b c d e f .
  /* 68-6F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 70-77 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 78-7F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 80-87 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 88-8F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 90-97 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 98-9F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* A0-A7 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* A8-AF */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* B0-B7 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* B8-BF */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* C0-C7 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* C8-CF */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* D0-D7 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* D8-DF */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* E0-E7 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* E8-EF */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* F0-F7 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* F8-FF */ -1, -1, -1, -1, -1, -1, -1, -1,
};

///////////////////////////////////////////////////////////////////////////////

size_type decode( char const *from, size_type from_len, char *to,
                  int options ) {
  bool const ignore_ws = !!(options & dopt_ignore_ws);
  if ( ignore_ws )
    from = ascii::trim_whitespace( from, &from_len );
  if ( from_len % 2 )
    throw invalid_argument( "HexBinary length is not a multiple of 2" );

  char const *const from_orig = from;
  char const *const from_end = from + from_len;
  char const *const to_orig = to;
  char c;

  while ( from < from_end ) {
    signed char const high = decode_table[ (unsigned char)(c = *from++) ];
    if ( high == -1 )
      goto bad_char;
    signed char const low  = decode_table[ (unsigned char)(c = *from++) ];
    if ( low == -1 )
      goto bad_char;
    if ( to )
      *to++ = ((unsigned char)high << 4) | ((unsigned char)low);
  }

  return to - to_orig;

bad_char:
  throw hexbinary::exception(
    c, from - from_orig, BUILD_STRING( '\'', c, "': invalid character" )
  );
}

size_type decode( char const *from, size_type from_len,
                  std::vector<char> *to, int options ) {
  bool const ignore_ws = !!(options & dopt_ignore_ws);
  if ( ignore_ws )
    from = ascii::trim_whitespace( from, &from_len );
  if ( from_len % 2 )
    throw invalid_argument( "HexBinary length is not a multiple of 2" );
  if ( from_len ) {
    std::vector<char>::size_type const orig_size = to->size();
    to->resize( orig_size + decoded_size( from_len ) );
    return decode( from, from_len, &(*to)[ orig_size ], options );
  }
  return 0;
}

size_type decode( istream &from, ostream &to, int options ) {
  bool const ignore_ws = !!(options & dopt_ignore_ws);
  size_type total_decoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 2 ], to_buf[ 1024 ];
    streamsize gcount;
    if ( ignore_ws )
      gcount = read_without_whitespace( from, from_buf, sizeof from_buf );
    else {
      from.read( from_buf, sizeof from_buf );
      gcount = from.gcount();
    }
    if ( gcount ) {
      size_type const decoded = decode( from_buf, gcount, to_buf, options );
      to.write( to_buf, decoded );
      total_decoded += decoded;
    } else
      break;
  }
  return total_decoded;
}

size_type decode( istream &from, vector<char> *to, int options ) {
  bool const ignore_ws = !!(options & dopt_ignore_ws);
  vector<char>::size_type const orig_size = to->size();
  size_type total_decoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 4 ];
    streamsize gcount;
    if ( ignore_ws )
      gcount = read_without_whitespace( from, from_buf, sizeof from_buf );
    else {
      from.read( from_buf, sizeof from_buf );
      gcount = from.gcount();
    }
    if ( gcount ) {
      to->resize( to->size() + decoded_size( gcount ) );
      total_decoded +=
        decode( from_buf, gcount, &(*to)[ total_decoded ], options );
    } else
      break;
  }
  return total_decoded;
}

///////////////////////////////////////////////////////////////////////////////

size_type encode( char const *from, size_type from_len, char *to ) {
  static char const encode_table[] = "0123456789ABCDEF";

  char const *const to_orig = to;
  while ( from_len-- ) {
    unsigned char const c = *from++;
    *to++ = encode_table[ c >> 4   ];
    *to++ = encode_table[ c & 0x0F ];
  }
  return to - to_orig;
}

size_type encode( char const *from, size_type from_len,
                  std::vector<char> *to ) {
  size_type encoded = 0;
  if ( from_len ) {
    std::vector<char>::size_type const orig_size = to->size();
    to->resize( orig_size + encoded_size( from_len ) );
    encoded = encode( from, from_len, &(*to)[ orig_size ] );
  }
  return encoded;
}

size_type encode( istream &from, ostream &to ) {
  size_type total_encoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 ], to_buf[ 1024 * 2 ];
    from.read( from_buf, sizeof from_buf );
    if ( streamsize const gcount = from.gcount() ) {
      size_type const encoded = encode( from_buf, gcount, to_buf );
      to.write( to_buf, encoded );
      total_encoded += encoded;
    } else
      break;
  }
  return total_encoded;
}

size_type encode( istream &from, vector<char> *to ) {
  vector<char>::size_type const orig_size = to->size();
  size_type total_encoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 ];
    from.read( from_buf, sizeof from_buf );
    if ( streamsize const gcount = from.gcount() ) {
      to->resize( to->size() + encoded_size( gcount ) );
      total_encoded += encode( from_buf, gcount, &(*to)[ total_encoded ] );
    } else
      break;
  }
  return total_encoded;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace hexbinary
} // namespace zorba
/* vim:set et sw=2 ts=2: */
