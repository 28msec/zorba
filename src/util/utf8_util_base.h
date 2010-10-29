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

#ifndef ZORBA_UTF8_UTIL_BASE_H
#define ZORBA_UTF8_UTIL_BASE_H

#include <cstddef>
#include <iterator>
#include <stdexcept>

#include <zorba/config.h>

#include "unicode_util.h"

namespace zorba {
namespace utf8 {

////////// types //////////////////////////////////////////////////////////////

/**
 * The byte type that variable-length encoded UTF-8 characters use for storage.
 */
typedef char storage_type;

/**
 * A type that can hold all the bytes of the largest encoded UTF-8 character.
 */
typedef storage_type encoded_char_type[6];

/**
 * The size type.
 */
typedef std::size_t size_type;

////////// constants //////////////////////////////////////////////////////////

/**
 * The special value used to denote either (a) the maximum possible number as
 * input or (b) "not found" as a result.
 */
size_type const npos = static_cast<size_type>( -1 );


////////// functions //////////////////////////////////////////////////////////

/**
 * Converts a character position into a byte position.
 *
 * @param s A null-terminated UTF-8 encoded C string.
 * @param char_pos The character position.
 * @return Returns the corresponding byte position.
 */
ZORBA_DLL_PUBLIC
size_type byte_pos( storage_type const *s, size_type char_pos );

/**
 * Converts a character position into a byte position.
 *
 * @param s A UTF-8 encoded C string.
 * @param s_size The size of \a s in bytes.
 * @param char_pos The character position.
 * @return Returns the corresponding byte position or \c npos if the result >=
 * \a s_size.
 */
ZORBA_DLL_PUBLIC
size_type byte_pos( storage_type const *s, size_type s_size,
                    size_type char_pos );

/**
 * Gets the number of bytes used by a UTF-8 character.
 *
 * @param lead The lead byte of a UTF-8 byte sequence comprising a Unicode
 * character.
 * @return Return a number in the range [1,6] or 0 for an invalid byte.
 */
#ifdef WIN32
ZORBA_DLL_PUBLIC extern char const char_length_table[];		// Microsoft VS2005 doesn't like externs imported directly inside functions
#endif

inline size_type char_length( storage_type lead ) {
#ifndef WIN32
  ZORBA_DLL_PUBLIC extern char const char_length_table[];
#endif
  return char_length_table[ static_cast<unsigned>( lead ) & 0xFF ];
}

/**
 * Converts a pointer into a character offset.
 *
 * @param s A UTF-8 encoded C string.
 * @param p A pointer to somewhere within \a s.
 * @return Returns said offset.
 */
ZORBA_DLL_PUBLIC
size_type char_pos( storage_type const *s, storage_type const *p );

/**
 * Converts a byte position into a character position.
 *
 * @param s A UTF-8 encoded C string.
 * @param byte_pos The byte position.
 * @return Returns the corresponding character position.
 */
inline size_type char_pos( storage_type const *s, size_type byte_pos ) {
  return byte_pos != npos ? char_pos( s, s + byte_pos ) : npos;
}

/**
 * Encodes a Unicode character into a UTF-8 byte sequence.
 *
 * @param c The Unicode code-point to encode.
 * @param ps A pointer to a pointer to what will be the first byte of a UTF-8
 * byte sequence.  The pointer is advanced to one byte past the newly encoded
 * chacter.
 * @return Returns the number of bytes required to encode the character.
 */
ZORBA_DLL_PUBLIC
size_type encode( unicode::code_point c, storage_type **ps );

/**
 * Encodes a Unicode character into a UTF-8 byte sequence.
 *
 * @param c The Unicode code-point to encode.
 * @param p A pointer to what will be the first byte of a UTF-8 byte sequence.
 * @return Returns the number of bytes required to encode the character.
 */
inline size_type encode( unicode::code_point c, storage_type *p ) {
  return encode( c, &p );
}

/**
 * Encodes a Unicode character into a UTF-8 byte sequence and appends it to the
 * given string.
 *
 * @param c The Unicode code-point to encode.
 * @param out The string to append to.
 */
template<class StringType> inline
void encode( unicode::code_point c, StringType *out ) {
  encoded_char_type ec;
  out->append( ec, encode( c, ec ) );
}

/**
 * Checks whether the given byte is the first byte of a UTF-8 byte sequence
 * comprising an encoded character.
 *
 * @param b The byte to check.
 * @return Returns \a true only if the byte is the first byte of a UTF-8 byte
 * sequence comprising an encoded character.
 */
inline bool is_start_byte( storage_type b ) {
  return (b & 0xC0) != 0x80;
}

/**
 * Gets the number of Unicode characters comprising the NULL-terminated UTF-8
 * string.
 *
 * @param s A pointer to the first byte of a NULL-terminated UTF-8 string.
 * @return Returns said number of characters.
 */
ZORBA_DLL_PUBLIC
size_type length( storage_type const *s );

/**
 * Gets the number of Unicode characters between the given pointers.
 *
 * @param begin A pointer to the first byte of a UTF-8 byte sequence comprising
 * a Unicode character.
 * @param end A pointer to one past the last byte of the same UTF-8 byte
 * sequence.
 * @return Returns said number of characters.
 */
ZORBA_DLL_PUBLIC
size_type length( storage_type const *begin, storage_type const *end );

/**
 * Decodes the next Unicode character.
 *
 * @tparam OctetIterator The iterator to use to iterate over the underlying
 * byte sequence.
 * @param i An iterator pointing to the first byte of a UTF-8 byte sequence
 * comprising a Unicode character.  The iterator is advanced by the number of
 * bytes comprising the UTF-8 byte sequence.
 * @return Returns said character.
 */
template<class OctetIterator>
unicode::code_point next_char( OctetIterator &i );

/**
 * Gets the Unicode character at the given position.
 *
 * @param s A pointer to the first byte of a UTF-8 string.
 * @param char_pos The index of the desired character (not byte).
 * @return Returns said character.
 */
inline unicode::code_point char_at( storage_type const *s,
                                    size_type char_pos ) {
  storage_type const *s2 = s + byte_pos( s, char_pos );
  return next_char( s2 );
}

/**
 * Gets the Unicode character at the given position.
 *
 * @param s A pointer to the first byte of a UTF-8 string.
 * @param s_size The size of \a s in bytes.
 * @param char_pos The index of the desired character (not byte).
 * @return Returns said character.
 * @throws std::out_of_range if \a char_pos >= \a s_size.
 */
inline unicode::code_point char_at( storage_type const *s, size_type s_size,
                                    size_type char_pos ) {
  size_type const b = byte_pos( s, s_size, char_pos );
  if ( b == npos )
    throw std::out_of_range( "char_at" );
  storage_type const *s2 = s + b;
  return next_char( s2 );
}

/**
 * Decodes the previous Unicode character.
 *
 * @tparam OctetIterator The iterator to use to iterate over the underlying
 * byte sequence.
 * @param i An iterator pointing to somewhere within a UTF-8 string.  It is
 * repositioned to the first byte of the UTF-8 byte sequence comprising e
 * previous character.
 * @return Returns said character.
 */
template<class OctetIterator>
unicode::code_point prev_char( OctetIterator &i );

////////// iterator ///////////////////////////////////////////////////////////

/**
 * This iterator "wraps" an existing byte-sequence iterator to iterate over
 * Unicode characters encoded in UTF-8.
 *
 * @tparam OctetIterator The iterator to use to iterate over the underlying
 * byte sequence.
 */
template<class OctetIterator>
class iterator :
  public std::iterator<std::bidirectional_iterator_tag,unicode::code_point>
{
  typedef std::iterator<std::bidirectional_iterator_tag,unicode::code_point>
          base_type;
public:
  typedef base_type::iterator_category iterator_category;
  typedef base_type::difference_type difference_type;
  typedef base_type::value_type value_type;
  typedef base_type::pointer pointer;
  typedef base_type::value_type reference;

  iterator() {
  }

  explicit iterator( OctetIterator const &oi ) : oi_( oi ) {
  }

  OctetIterator base() const {
    return oi_;
  }

  value_type operator*() const {
    OctetIterator temp( oi_ );
    return next_char( temp );
  }

  iterator& operator++() {
    go_forward();
    return *this;
  }

  iterator const operator++(int) {
    iterator const temp( *this );
    go_forward();
    return temp;
  }

  iterator& operator--() {
    go_back();
    return *this;
  }

  iterator const operator--(int) {
    iterator const temp( *this );
    go_back();
    return temp;
  }

  friend bool operator==( iterator const &i, iterator const &j ) {
    return i.oi_ == j.oi_;
  }

  friend bool operator!=( iterator const &i, iterator const &j ) {
    return !(i == j);
  }

private:
  void go_forward() {
    while ( !is_start_byte( *++oi_ ) ) ;
  }

  void go_back() {
    while ( !is_start_byte( *--oi_ ) ) ;
  }

  OctetIterator oi_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba

#endif /* ZORBA_UTF8_UTIL_BASE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
