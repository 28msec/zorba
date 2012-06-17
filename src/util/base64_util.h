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

#pragma once
#ifndef ZORBA_BASE64_UTIL_H
#define ZORBA_BASE64_UTIL_H

#include <iostream>
#include <sys/types.h>

namespace zorba {
namespace base64 {

///////////////////////////////////////////////////////////////////////////////

typedef size_t size_type;

/**
 * Calculates the number of bytes required to Base64-decode \a n bytes.
 *
 * @param n The number of bytes to decode.
 * @return Returns the number of bytes needed for Base64 decoding.
 */
inline size_type decoded_size( size_type n ) {
  return ((n / 4) + !!(n % 4)) * 3;
}

/**
 * Calculates the number of bytes required to Base64-encode \a n bytes.
 *
 * @param n The number of bytes to encode.
 * @return Returns the number of bytes needed for Base64 encoding.
 */
inline size_type encoded_size( size_type n ) {
  return (n + 2) / 3 * 4;
}

/**
 * Decodes a Base64-encoded buffer.  Embedded newlines and carriage-returns are
 * skipped.
 *
 * @param from A pointer to the Base64 buffer to be decoded.
 * @param from_len The number of bytes to decode.
 * @paran to A pointer to the buffer to receive the decoded bytes.  The buffer
 * must be large enough to contain them.  Note that the buffer is \e not null
 * terminated.
 * @return Returns the number of decoded bytes.
 * @throws invalid_argument if more than two trailing \c = characters are
 * encountered or necessary, \c = is encountered anywhere in the buffer except
 * at the end, or an invalid byte in encountered.
 * @see decoded_size()
 */
size_type decode( char const *from, size_type from_len, char *to );

/**
 * Decodes a Base64-encoded istream.  Embedded newlines and carriage-returns
 * are skipped.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The ostream to write the decoded bytes to.
 * @throws invalid_argument if more than two trailing \c = characters are
 * encountered or necessary, \c = is encountered anywhere in the stream except
 * at the end, or an invalid byte in encountered.
 */
void decode( std::istream &from, std::ostream &to );

/**
 * Decodes a Base64-encoded istream.  Embedded newlines and carriage-returns
 * are skipped.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The string to append the decoded bytes to.
 * @throws invalid_argument if more than two trailing \c = characters are
 * encountered or necessary, \c = is encountered anywhere in the stream except
 * at the end, or an invalid byte in encountered.
 */
template<typename CharType,class TraitsType,class StringType> inline
void decode( std::basic_istream<CharType,TraitsType> &from, StringType *to ) {
  char from_buf[ 1024 * 4 ], to_buf[ 1024 * 3 ];
  while ( !from.eof() ) {
    from.read( from_buf, sizeof from_buf );
    if ( std::streamsize const gcount = from.gcount() )
      to->append( to_buf, decode( from_buf, gcount, to_buf ) );
    else
      break;
  }
}

/**
 * Base64-encodes a buffer.
 *
 * @param from A pointer to the bugger to be encoded.
 * @param from_len The number of bytes to encode.
 * @param to A pointer to the buffer to receive the encoded bytes.  The buffer
 * must be large enough to contain them.  Note that the buffer is \e not null
 * terminated.
 * @return Returns the number of encoded bytes.
 * @see encoded_size()
 */
size_type encode( char const *from, size_type from_len, char *to );

/**
 * Encodes a stream to Base64.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The ostream to write the encoded bytes to.
 */
void encode( std::istream &from, std::ostream &to );

/**
 * Encodes a stream to Base64.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The string to append the encoded bytes to.
 */
template<typename CharType,class TraitsType,class StringType> inline
void encode( std::basic_istream<CharType,TraitsType> &from, StringType *to ) {
  char from_buf[ 1024 * 3 ], to_buf[ 1024 * 4 ];
  while ( !from.eof() ) {
    from.read( from_buf, sizeof from_buf );
    if ( std::streamsize const gcount = from.gcount() )
      to->append( to_buf, encode( from_buf, gcount, to_buf ) );
    else
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace base64
} // namespace zorba

#endif /* ZORBA_BASE64_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
