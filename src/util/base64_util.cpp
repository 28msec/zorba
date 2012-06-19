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

#include "base64_util.h"
#include "string_util.h"

using namespace std;

namespace zorba {
namespace base64 {

///////////////////////////////////////////////////////////////////////////////

static char const alphabet[] =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz"
  "0123456789+/";

/**
 * Base64 decoding table.  A value of -1 means "invalid"; a value of -2 means
 * "skip" (for newlines and carriage returns).
 */
static signed char const decode_table[] = {
  /* 00-07 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 08-0F */ -1, -1, -2, -1, -1, -2, -1, -1, // . .\n . .\r . .
  /* 10-17 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 18-1F */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 20-27 */ -1, -1, -1, -1, -1, -1, -1, -1,
  /* 28-2F */ -1, -1, -1, 62, -1, -1, -1, 63, // . . . + . . . /
  /* 30-37 */ 52, 53, 54, 55, 56, 57, 58, 59, // 0 1 2 3 4 5 6 7
  /* 38-3F */ 60, 61, -1, -1, -1, -1, -1, -1, // 8 9 . . . . . .
  /* 40-47 */ -1,  0,  1,  2,  3,  4,  5,  6, // . A B C D E F G
  /* 48-4F */  7,  8,  9, 10, 11, 12, 13, 14, // H I J K L M N O
  /* 50-57 */ 15, 16, 17, 18, 19, 20, 21, 22, // P Q R S T U V W
  /* 58-5F */ 23, 24, 25, -1, -1, -1, -1, -1, // X Y Z . . . . .
  /* 60-67 */ -1, 26, 27, 28, 29, 30, 31, 32, // . a b c d e f g
  /* 68-6F */ 33, 34, 35, 36, 37, 38, 39, 40, // h i j k l m n o
  /* 70-77 */ 41, 42, 43, 44, 45, 46, 47, 48, // p q r s t u v w
  /* 78-7F */ 49, 50, 51, -1, -1, -1, -1, -1, // x y z . . . . .
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

inline void decode_chunk( char const *from, char *to ) {
  //
  //  | INPUT BYTES
  //  +-----------+-----------+-----------+-----------+
  //  |     0     |     1     |     2     |     3     |
  //  +-----------+-----------+-----------+-----------+
  //  |           |           |           |           |
  //  | | | | | | | | | | | | | | | | | | | | | | | | |
  //  |               |               |               |
  //  +---------------+---------------+---------------+
  //  |       0       |       1       |       2       |
  //  +---------------+---------------+---------------+
  //  | OUTPUT BYTES
  //
  unsigned char const *const u = reinterpret_cast<unsigned char const*>( from );
  to[0] =  (u[0] << 2)         | (u[1] >> 4);
  to[1] =  (u[1] << 4)         | (u[2] >> 2);
  to[2] = ((u[2] << 6) & 0xC0) |  u[3]      ;
}

inline void encode_chunk( char const *from, char *to ) {
  //
  //  | INPUT BYTES
  //  +---------------+---------------+---------------+
  //  |       0       |       1       |       2       |
  //  +---------------+---------------+---------------+
  //  |               |               |               |
  //  | | | | | | | | | | | | | | | | | | | | | | | | |
  //  |           |           |           |           |
  //  +-----------+-----------+-----------+-----------+
  //  |     0     |     1     |     2     |     3     |
  //  +-----------+-----------+-----------+-----------+
  //  | OUTPUT BYTES
  //
  unsigned char const *const u = reinterpret_cast<unsigned char const*>( from );
  to[0] = alphabet[   u[0]         >> 2                ];
  to[1] = alphabet[ ((u[0] & 0x03) << 4) | (u[1] >> 4) ];
  to[2] = alphabet[ ((u[1] & 0x0F) << 2) | (u[2] >> 6) ];
  to[3] = alphabet[   u[2] & 0x3F                      ];
}

///////////////////////////////////////////////////////////////////////////////

size_type decode( char const *from, size_type from_len, char *to,
                  bool multiple_4 ) {
  if ( multiple_4 && from_len % 4 )
    throw invalid_argument( BUILD_STRING( from_len, ": not a multiple of 4" ) );

  char chunk[4];
  int chunk_len = 0;
  int pads = 0;
  char const *const to_orig = to;

  for ( size_type pos = 0; pos < from_len; ++pos, ++from ) {
    char const c = *from;
    signed char value;
    if ( c == '=' ) {
      switch ( pos % 4 ) {
        //
        // Ensure '=' occurs only in the 3rd or 4th bytes of a 4-byte chunk
        // and that the byte preceding '=' is valid.
        //
        case 2:
          if ( !strchr( "AQgw", from[-1] ) )
            throw base64::exception(
              c, pos, BUILD_STRING( '\'', c, "': invalid character before '='" )
            );
          break;
        case 3:
          if ( !strchr( "=048AEIMQUYcgkosw", from[-1] ) )
            throw base64::exception(
              c, pos, BUILD_STRING( '\'', c, "': invalid character before '='" )
            );
          break;
        default:
          throw base64::exception( c, pos, "'=' encountered unexpectedly" );
      }
      ++pads;
      value = '\0';
    } else {
      if ( pads )
        throw base64::exception(
          c, pos, BUILD_STRING( '\'', c, "': invalid character after '='" )
        );
      value = decode_table[ static_cast<unsigned char>( c ) ];
    }
    switch ( value ) {
      case -1:
        throw base64::exception(
          c, pos, BUILD_STRING( '\'', c, "': invalid character" )
        );
      case -2: // \n or \r
        continue;
      default:
        if ( to ) {
          if ( chunk_len == 4 )
            chunk_len = 0;
          chunk[ chunk_len ] = value;
          if ( ++chunk_len == 4 ) {
            decode_chunk( chunk, to );
            to += 3;
          }
        }
    }
  } // for

  if ( !to )
    return 0;

  if ( chunk_len > 1 && chunk_len < 4 ) {
    //
    // from_len was not a multiple of 4, hence the Base64 encoding is
    // incomplete: salvage 1 or 2 characters.
    //
    int const salvageable = chunk_len - 1;
    chunk[3] = '\0';
    if ( salvageable == 1 )
      chunk[2] = '\0';
    decode_chunk( chunk, to );
    to += salvageable;
  }

  return to - to_orig - pads;
}

size_type decode( istream &from, ostream &to ) {
  size_type total_decoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 4 ], to_buf[ 1024 * 3 ];
    from.read( from_buf, sizeof from_buf );
    if ( streamsize const gcount = from.gcount() ) {
      size_type const decoded = decode( from_buf, gcount, to_buf );
      to.write( to_buf, decoded );
      total_decoded += decoded;
    } else
      break;
  }
  return total_decoded;
}

size_type decode( istream &from, vector<char> *to ) {
  size_type total_decoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 4 ];
    from.read( from_buf, sizeof from_buf );
    if ( streamsize const gcount = from.gcount() ) {
      to->reserve( to->size() + decoded_size( gcount ) );
      total_decoded += decode( from_buf, gcount, &(*to)[ total_decoded ] );
    } else
      break;
  }
  return total_decoded;
}

///////////////////////////////////////////////////////////////////////////////

size_type encode( char const *from, size_type from_len, char *to ) {
  char const *const to_orig = to;
  int chunk_len = 0;

  while ( from_len-- ) {
    if ( ++chunk_len == 3 ) {
      encode_chunk( from, to );
      from += 3, to += 4;
      chunk_len = 0;
    }
  }

  if ( chunk_len ) {                    // must be either 1 or 2
    //
    // Handle the special-case of from_len not being a multiple of 3.  First,
    // copy what's left over from "from" to a temporary buffer that's 3 bytes
    // long and encode that buffer so encode_chunk() remains special-case-free
    // (and thus faster) for most of the encoding.
    //
    char from_temp[3];
    from_temp[1] = from_temp[2] = '\0';
    std::copy( from, from + chunk_len, from_temp );
    encode_chunk( from_temp, to );
    //
    // Second, overwrite the trailing byte(s) with Base64 padding characters.
    //
    to[3] = '=';
    if ( chunk_len == 1 )
      to[2] = '=';
    to += 4;
  }

  return to - to_orig;
}

size_type encode( istream &from, ostream &to ) {
  size_type total_encoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 3 ], to_buf[ 1024 * 4 ];
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
  size_type total_encoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 3 ];
    from.read( from_buf, sizeof from_buf );
    if ( streamsize const gcount = from.gcount() ) {
      to->reserve( to->size() + encoded_size( gcount ) );
      total_encoded += encode( from_buf, gcount, &(*to)[ total_encoded ] );
    } else
      break;
  }
  return total_encoded;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace base64
} // namespace zorba
/* vim:set et sw=2 ts=2: */
