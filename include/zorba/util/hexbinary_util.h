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
#ifndef ZORBA_HEXBINARY_API_H
#define ZORBA_HEXBINARY_API_H

// standard
#include <iostream>
#include <stdexcept>
#include <sys/types.h>                  /* for size_t */
#include <vector>

// Zorba
#include <zorba/internal/cxx_util.h>
#include <zorba/internal/type_traits.h>
#include <zorba/internal/ztd.h>
#include <zorba/util/stream_util.h>

namespace zorba {
namespace hexbinary {

////////// Types //////////////////////////////////////////////////////////////

typedef size_t size_type;

/**
 * Options to use for decoding.
 */
enum decode_options {
  dopt_none       = 0x00, ///< No options.
  dopt_ignore_ws  = 0x01, ///< Ignore all whitespace.
};

////////// Exception //////////////////////////////////////////////////////////

/**
 * A %hexbinary::exception is-an invalid_argument that contains additional
 * details about the exception such as the invalid character and its offset.
 */
class exception : public std::invalid_argument {
public:
  exception( char c, size_type offset, std::string const &msg ) :
    std::invalid_argument( msg ), char_( c ), offset_( offset ) { }

  char invalid_char() const {
    return char_;
  }

  size_type char_offset() const {
    return offset_;
  }

private:
  char char_;
  size_type offset_;
};

////////// Decoding ///////////////////////////////////////////////////////////

/**
 * Calculates the number of bytes required to decode \a n hexBinary-encoded
 * bytes.
 *
 * @param n The number of bytes to decode.
 * @return Returns the number of bytes needed for hexBinary decoding.
 */
inline size_type decoded_size( size_type n ) {
  return n / 2;
}

/**
 * Decodes a hexBinary-encoded buffer.
 *
 * @param from A pointer to the hexBinary buffer to be decoded.
 * @param from_len The number of bytes to decode.
 * @paran to A pointer to the buffer to receive the decoded bytes.  The buffer
 * must be large enough to contain them.  Note that the buffer is \e not null
 * terminated.
 * @param options The decoding options to use.
 * @return Returns the number of decoded bytes.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 * @see decoded_size()
 */
size_type decode( char const *from, size_type from_len, char *to,
                  int options = dopt_none );

/**
 * Decodes a hexBinary-encoded buffer and appends the decoded bytes onto a
 * vector&lt;char&gt;.
 *
 * @param from A pointer to the buffer to be encoded.
 * @param from_len The number of bytes to encode.
 * @param to A pointer to the vector to append the encoded bytes appended onto.
 * The vector is made large enough to contain the additional bytes.
 * @param options The decoding options to use.
 * @return Returns the number of decoded bytes.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 */
size_type decode( char const *from, size_type from_len, std::vector<char> *to,
                  int options = dopt_none );

/**
 * Decodes a hexBinary-encoded buffer and writes the decoded bytes to the given
 * stream.
 *
 * @param from A pointer to the hexBinary buffer to be decoded.
 * @param from_len The number of bytes to decode.
 * @param to The ostream to write the decoded bytes to.
 * @param options The options to use.
 * @return Returns the number of decoded bytes.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 */
ZORBA_DLL_PUBLIC
size_type decode( char const *from, size_type from_len, std::ostream &to,
                  int options = dopt_none );
/**
 * Decodes a hexBinary-encoded buffer and appends the decoded bytes onto a
 * string.
 *
 * @tparam ToStringType The string type.
 * @param from A pointer to the hexBinary buffer to be decoded.
 * @param from_len The number of bytes to decode.
 * @param to The string to append the decoded bytes to.
 * @param options The decoding options to use.
 * @return Returns the number of decoded bytes.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 */
template<class ToStringType>
typename std::enable_if<ZORBA_IS_STRING(ToStringType),size_type>::type
decode( char const *from, size_type from_len, ToStringType *to,
        int options = dopt_none ) {
  size_type decoded = 0;
  if ( from_len ) {
    typename ToStringType::size_type const orig_size = to->size();
    to->resize( orig_size + decoded_size( from_len ) );
    decoded = decode( from, from_len, &to->at( orig_size ), options );
    to->resize( orig_size + decoded );
  }
  return decoded;
}

/**
 * Decodes a hexBinary-encoded istream.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The ostream to write the decoded bytes to.
 * @param options The decoding options to use.
 * @return Returns the number of decoded bytes.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 */
size_type decode( std::istream &from, std::ostream &to,
                  int options = dopt_none );

/**
 * Decodes a hexBinary-encoded istream and appends the decoded bytes to a
 * string.
 *
 * @tparam ToStringType The string type.
 * @param from The istream to read from until EOF is reached.
 * @param to The string to append the decoded bytes to.
 * @param options The decoding options to use.
 * @return Returns the number of decoded bytes.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 */
template<class ToStringType>
typename std::enable_if<ZORBA_IS_STRING(ToStringType),size_type>::type
decode( std::istream &from, ToStringType *to, int options = dopt_none ) {
  bool const ignore_ws = !!(options & dopt_ignore_ws);
  size_type total_decoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 2 ], to_buf[ 1024 ];
    std::streamsize gcount;
    if ( ignore_ws )
      gcount = read_without_whitespace( from, from_buf, sizeof from_buf );
    else {
      from.read( from_buf, sizeof from_buf );
      gcount = from.gcount();
    }
    if ( gcount ) {
      size_type const decoded =
        decode( from_buf, static_cast<size_type>( gcount ), to_buf, options );
      to->append( to_buf, decoded );
      total_decoded += decoded;
    } else
      break;
  }
  return total_decoded;
}

/**
 * Decodes a hexBinary-encoded stream and appends the decoded bytes onto a
 * vector&lt;char;&gt;.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The string to append the decoded bytes to.
 * @param options The decoding options to use.
 * @param Returns the number of decoded bytes.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 */
size_type decode( std::istream &from, std::vector<char> *to,
                  int options = dopt_none );

/**
 * Validates a hexBinary-encoded buffer.
 *
 * @param buf A pointer to the hexBinary buffer to be validated.
 * @param buf_len The number of bytes to validate.
 * @param options The decoding options to use.
 * @throws invalid_argument if \a from_len (minus the amount of whitespace if
 * \a options contains \c dopt_ignore_ws) is not a multiple of 2.
 * @throws hexbinary::exception if an invalid byte is encountered.
 * @see decoded_size()
 */
inline void validate( char const *buf, size_type buf_len,
                      int options = dopt_none ) {
  decode( buf, buf_len, static_cast<char*>( nullptr ), options );
}

////////// Encoding ///////////////////////////////////////////////////////////

/**
 * Calculates the number of bytes required to hexBinary-encode \a n bytes.
 *
 * @param n The number of bytes to encode.
 * @return Returns the number of bytes needed for hexBinary encoding.
 */
inline size_type encoded_size( size_type n ) {
  return n * 2;
}

/**
 * HexBinary-encodes a buffer.
 *
 * @param from A pointer to the buffer to be encoded.
 * @param from_len The number of bytes to encode.
 * @param to A pointer to the buffer to receive the encoded bytes.  The buffer
 * must be large enough to contain them.  Note that the buffer is \e not null
 * terminated.
 * @return Returns the number of encoded bytes.
 * @see encoded_size()
 */
size_type encode( char const *from, size_type from_len, char *to );

/**
 * HexBinary-encodes a buffer and appends the encoded bytes onto a
 * vector&lt;char&gt;.
 *
 * @param from A pointer to the buffer to be encoded.
 * @param from_len The number of bytes to encode.
 * @param to A pointer to the vector to append the encoded bytes appended onto.
 * The vector is made large enough to contain the additional bytes.
 */
size_type encode( char const *from, size_type from_len, std::vector<char> *to );

/**
 * HexBinary-encodes a buffer and writes the encoded bytes to the given stream.
 *
 * @param from A pointer to the buffer to be encoded.
 * @param from_len The number of bytes to encode.
 * @param to The ostream to write the encoded bytes to.
 * @return Returns the number of encoded bytes.
 */
ZORBA_DLL_PUBLIC
size_type encode( char const *from, size_type from_len, std::ostream &to );

/**
 * HexBinary-encodes a buffer and appends the encoded bytes onto a string.
 *
 * @tparam ToStringType The string type.
 * @param from A pointer to the buffer to be encoded.
 * @param from_len The number of bytes to encode.
 * @param to A pointer to the string to append the encoded bytes onto.
 * @return Returns the number of encoded bytes.
 */
template<class ToStringType>
typename std::enable_if<ZORBA_IS_STRING(ToStringType),size_type>::type
encode( char const *from, size_type from_len, ToStringType *to ) {
  size_type encoded = 0;
  if ( from_len ) {
    typename ToStringType::size_type const orig_size = to->size();
    to->resize( orig_size + encoded_size( from_len ) );
    encoded = encode( from, from_len, &to->at( orig_size ) );
  }
  return encoded;
}

/**
 * HexBinary-encodes one stream and write the encoded bytes to another.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The ostream to write the encoded bytes to.
 */
size_type encode( std::istream &from, std::ostream &to );

/**
 * Encodes a stream to hexBinary and appends the encoded bytes to a string.
 *
 * @tparam ToStringType The string type.
 * @param from The istream to read from until EOF is reached.
 * @param to The string to append the encoded bytes to.
 * @return Returns the number of encoded bytes.
 */
template<class ToStringType>
typename std::enable_if<ZORBA_IS_STRING(ToStringType),size_type>::type
encode( std::istream &from, ToStringType *to ) {
  size_type total_encoded = 0;
  while ( !from.eof() ) {
    char from_buf[ 1024 * 2 ], to_buf[ 1024 ];
    from.read( from_buf, sizeof from_buf );
    if ( std::streamsize const gcount = from.gcount() ) {
      size_type const encoded =
        encode( from_buf, static_cast<size_type>( gcount ), to_buf );
      to->append( to_buf, encoded );
      total_encoded += encoded;
    } else
      break;
  }
  return total_encoded;
}

/**
 * HexBinary-encodes a stream and appends the encoded bytes onto a
 * vector&lt;char;&gt;.
 *
 * @param from The istream to read from until EOF is reached.
 * @param to The vector to append the encoded bytes to.
 * @param Returns the number of encoded bytes.
 */
size_type encode( std::istream &from, std::vector<char> *to );

///////////////////////////////////////////////////////////////////////////////

} // namespace hexbinary
} // namespace zorba

#endif /* ZORBA_HEXBINARY_API_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
