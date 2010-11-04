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

#ifndef ZORBA_STRING_UTIL_ASCII_UTIL_H
#define ZORBA_STRING_UTIL_ASCII_UTIL_H

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstring>

#include <zorba/config.h>

#include "stl_util.h"

namespace zorba {
namespace ascii {

////////// types //////////////////////////////////////////////////////////////

/**
 * The size type.
 */
typedef std::size_t size_type;


ZORBA_DLL_PUBLIC extern char const uri_safe[];


////////// classes ////////////////////////////////////////////////////////////

/**
 * A %back_uri_insert_iterator can be used to append characters to a string
 * ensuring that illegal characters in a URI are escaped.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_uri_insert_iterator :
  public
    back_insert_iterator_base<
      StringType, back_uri_insert_iterator<StringType>
    >
{
  typedef back_insert_iterator_base<
    StringType, back_uri_insert_iterator<StringType>
  > base_type;
public:
  typedef typename base_type::container_type container_type;
  typedef typename StringType::value_type value_type;

  /**
   * Constructs a %back_uri_insert_iterator.
   *
   * @param s The string to append to.
   * @param encode_slash If \c true, encodes the '/' character also.
   */
  explicit back_uri_insert_iterator( StringType &s, bool encode_slash = false )
    : base_type( s ), encode_slash_(  encode_slash )
  {
    buf_[0] = '%';
  }

  back_uri_insert_iterator& operator=( value_type c );

private:
  char buf_[3]; // %xx -- no need for null at end
  bool encode_slash_;
};

/**
 * A %back_xml_insert_iterator can be used to append characters to a string
 * ensuring that illegal characters in XML ('"', '&', '\'', '<', and '>') are
 * replace by their respective character entity references.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_xml_insert_iterator :
  public
    back_insert_iterator_base<
      StringType, back_xml_insert_iterator<StringType>
    >
{
  typedef back_insert_iterator_base<
    StringType, back_xml_insert_iterator<StringType>
  > base_type;
public:
  typedef typename base_type::container_type container_type;
  typedef typename StringType::value_type value_type;

  /**
   * Constructs a %back_xml_insert_iterator.
   *
   * @param s The string to append to.
   */
  explicit back_xml_insert_iterator( StringType &s ) : base_type( s ) {
    buf_[0] = '&';
    buf_[1] = '#';
  }

  back_xml_insert_iterator& operator=( value_type c );

private:
  char buf_[5]; // &#xx; -- no need for null at end
};

////////// functions //////////////////////////////////////////////////////////

/**
 * This is a convenience function to create a back_uri_insert_iterator.
 *
 * @tparam StringType The string type.
 * @param out The output string.
 * @param encode_slash If \c true, encodes the '/' character also.
 */
template<class StringType> inline back_uri_insert_iterator<StringType>
back_uri_inserter( StringType &out, bool encode_slash = false ) {
  return back_uri_insert_iterator<StringType>( out, encode_slash );
}

/**
 * This is a convenience function to create a back_xml_insert_iterator.
 *
 * @tparam StringType The string type.
 * @param out The output string.
 */
template<class StringType> inline back_xml_insert_iterator<StringType>
back_xml_inserter( StringType &out ) {
  return back_xml_insert_iterator<StringType>( out );
}

/**
 * Checks whether a string begins with a given prefix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param ps The prefix string.
 * @param n The number of characters to compare.
 * @return Returns \c true only if \a s begins with \a ps.
 */
template<class StringType> inline
bool begins_with( StringType const &s, char const *ps,
                  typename StringType::size_type n ) {
  typedef typename StringType::traits_type traits_type;
  return n <= s.size() && traits_type::compare( s.data(), ps, n ) == 0;
}

/**
 * Checks whether a string begins with a given prefix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param ps The prefix string.
 * @return Returns \c true only if \a s begins with \a ps.
 */
template<class StringType> inline
bool begins_with( StringType const &s, char const *ps ) {
  return begins_with( s, ps, std::strlen( ps ) );
}

/**
 * Checks whether a string begins with a given prefix.
 *
 * @tparam StringType The string type.
 * @tparam PrefixStringType The suffix string type.
 * @param s The string to check.
 * @param ps The suffix string.
 * @return Returns \c true only if \a s ends with \a ps.
 */
template<class StringType,class PrefixStringType> inline
bool begins_with( StringType const &s, PrefixStringType const &ps ) {
  return begins_with( s, ps.data(), ps.size() );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param c The suffix character.
 * @return Returns \c true only if \a s ends with \a c.
 */
template<class StringType> inline
bool ends_with( StringType const &s, char c ) {
  return !s.empty() && s[ s.size() - 1 ] == c;
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param ss The suffix string.
 * @param ss_len The length of the suffix string.
 * @return Returns \c true only if \a s ends with \a ss.
 */
template<class StringType> inline
bool ends_with( StringType const &s, char const *ss,
                typename StringType::size_type ss_len ) {
  typename StringType::size_type const result = s.rfind( ss );
  return result != StringType::npos && result + ss_len == s.size();
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param ss The suffix string.
 * @return Returns \c true only if \a s ends with \a ss.
 */
template<class StringType> inline
bool ends_with( StringType const &s, char const *ss ) {
  return ends_with( s, ss, std::strlen( ss ) );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @tparam SuffixStringType The suffix string type.
 * @param s The string to check.
 * @param ss The suffix string.
 * @return Returns \c true only if \a s ends with \a ss.
 */
template<class StringType,class SuffixStringType> inline
bool ends_with( StringType const &s, SuffixStringType const &ss ) {
  return ends_with( s, ss.data(), ss.size() );
}

/**
 * Converts a \c long to a C string.
 *
 * @param n The \c long to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
ZORBA_DLL_PUBLIC char* ltoa( long n, char *buf );

/**
 * Converts an \c int to a C string.
 *
 * @param n The \c int to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( int n, char *buf ) {
  return ltoa( n, buf );
}

/**
 * Checks whether an entire string is whitespace.
 *
 * @param s The NULL-terminated C string to check.
 * @return Returns \c true only if the entire string is whitespace.
 */
ZORBA_DLL_PUBLIC bool is_whitespace( char const *s );

/**
 * Converts sequences of one or more whitespace characters to a single space.
 * Additionally, all leading and trailing whitespace is removed.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType>
void normalize_whitespace( InputStringType const &in, OutputStringType *out );

/**
 * Converts sequences of one or more whitespace characters to a single space.
 * Additionally, all leading and trailing whitespace is removed.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void normalize_whitespace( StringType &s ) {
  StringType temp;
  normalize_whitespace( s, &temp );
  s = temp;
}

/**
 * Removes all leading and trailing specified characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param chars The characters to trim.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType>
void trim( InputStringType const &in, char const *chars,
           OutputStringType *out );

/**
 * Removes all leading and trailing specified characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void trim( StringType &s, char const *chars ) {
  StringType temp;
  trim( s, chars, &temp );
  s = temp;
}

/**
 * Removes all leading and trailing whitespace.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType> inline
void trim_whitespace( InputStringType const &in, OutputStringType *out ) {
  trim( in, " \n\r\t", out );
}

/**
 * Removes all leading and trailing whitespace.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void trim_whitespace( StringType &s ) {
  StringType temp;
  trim_whitespace( s, &temp );
  s = temp;
}

/**
 * Skips any consecutive whitespace chars that are found at a given starting
 * position within a given C string.
 *
 * @param str The input C string
 * @param str_len The length of the input C string
 * @param pos The position within str where to start looking for whitespace.
 *        On return, pos is stores the posoition of the 1st non-whitespace 
 *        char.
 */
void skip_whitespace(const char* str, size_type str_len, size_type *pos);

/**
 * Skips any consecutive whitespace chars that are found at a given starting
 * position within a given C string.
 *
 * @param s The input string.
 * @param pos The position within str where to start looking for whitespace.
 *        On return, pos is stores the posoition of the 1st non-whitespace 
 *        char.
 */
template<class StringType> inline
void skip_whitespace( StringType const &s,
                      typename StringType::size_type *pos ) {
  skip_whitespace( s.data(), s.size(), pos );
}

/**
 * Replaces all occurrences of one character with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The character to replace.
 * @param to The character to replace with.
 */
template<class StringType>
void replace_all( StringType &s, char from, char to );

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param from_len The length of <code>from</code>.
 * @param to The substring to replace with.
 * @param to_len The length of <code>to</code>.
 */
template<class StringType>
void replace_all( StringType &s,
                  char const *from, typename StringType::size_type from_len,
                  char const *to, typename StringType::size_type to_len );

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param to The substring to replace with.
 */
template<class StringType> inline
void replace_all( StringType &s, char const *from, char const *to ) {
  replace_all( s, from, std::strlen( from ), to, std::strlen( to ) );
}

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param to The substring to replace with.
 */
template<class StringType,class ToStringType> inline
void replace_all( StringType &s, char const *from, ToStringType const &to ) {
  replace_all( s, from, std::strlen( from ), to.data(), to.size() );
}

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param to The substring to replace with.
 */
template<class StringType,class FromStringType,class ToStringType> inline
void replace_all( StringType &s, FromStringType const &from,
                                 ToStringType const &to ) {
  replace_all( s, from.data(), from.size(), to.data(), to.size() );
}

/**
 * Reverses the characters in a string.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string.
 */
template<class InputStringType,class OutputStringType> inline
void reverse( InputStringType const &in, OutputStringType *out ) {
  std::reverse_copy( in.begin(), in.end(), std::back_inserter( *out ) );
}

/**
 * Converts the given character to lower-case.  This function exists to make a
 * proper function out of the standard tolower(3) that may be implemented as a
 * macro.
 *
 * @param c The character to convert.
 * @return Returns the character converted to lower-case (if it was upper-case)
 * or the original character if either it already is lower-case or if it is not
 * a letter.
 */
inline char to_lower( char c ) {
  return tolower( c );
}

/**
 * Converts a string to lower-case in-place.
 *
 * @tparam StringType The string type.
 * @param s The string to convert.
 */
template<class StringType> inline
void to_lower( StringType &s ) {
  std::transform(
    s.begin(), s.end(), s.begin(), static_cast<char (*)(char)>( to_lower )
  );
}

/**
 * Converts a string to lower-case.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are overwritten.
 */
template<class InputStringType,class OutputStringType> inline
void to_lower( InputStringType const &in, OutputStringType *out ) {
  std::transform(
    in.begin(), in.end(), std::back_inserter( *out ),
    static_cast<char (*)(char)>( to_lower )
  );
}

/**
 * Converts the given character to upper-case.  This function exists to make a
 * proper function out of the standard toupper(3) that may be implemented as a
 * macro.
 *
 * @param c The character to convert.
 * @return Returns the character converted to upper-case (if it was lower-case)
 * or the original character if either it already is upper-case or if it is not
 * a letter.
 */
inline char to_upper( char c ) {
  return toupper( c );
}

/**
 * Converts a string to upper-case in-place.
 *
 * @tparam StringType The string type.
 * @param s The string to convert.
 */
template<class StringType> inline
void to_upper( StringType &s ) {
  std::transform(
    s.begin(), s.end(), s.begin(), static_cast<char (*)(char)>( to_upper )
  );
}

/**
 * Converts a string to upper-case.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are overwritten.
 */
template<class InputStringType,class OutputStringType> inline
void to_upper( InputStringType const &in, OutputStringType *out ) {
  std::transform(
    in.begin(), in.end(), std::back_inserter( *out ),
    static_cast<char (*)(char)>( to_upper )
  );
}

/**
 * Escapes characters in the string for XML, specfically '"', '&', '\'', '<',
 * and '>'.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are appended to.
 */
template<class InputStringType,class OutputStringType> inline
void to_xml( InputStringType const &in, OutputStringType *out ) {
  std::copy( in.begin(), in.end(), back_xml_inserter( *out ) );
}

/**
 * Percent-encodes (%xx) illegal URI characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are appended to.
 * @param encode_slash Encodes the slash character ("/") only if \c true.
 */
template<class InputStringType,class OutputStringType> inline
void uri_encode( InputStringType const &in, OutputStringType *out,
                 bool encode_slash = true ) {
  std::copy( in.begin(), in.end(), back_uri_inserter( *out, encode_slash ) );
}

/**
 * Percent-encodes (%xx) illegal URI characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 * @param encode_slash Encodes the slash character ("/") only if \c true.
 */
template<class StringType> inline
void uri_encode( StringType &s, bool encode_slash = true ) {
  StringType temp;
  uri_encode( s, &temp, encode_slash );
  s = temp;
}

/**
 * Percent-decodes (%xx) illegal URI characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are appended to.
 */
template<class InputStringType,class OutputStringType>
void uri_decode( InputStringType const &in, OutputStringType *out );

/**
 * Percent-decodes (%xx) illegal URI characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void uri_decode( StringType &s ) {
  StringType temp;
  uri_decode( s, &temp );
  s = temp;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ascii
} // namespace zorba

#include "util/ascii_util.tcc"

#endif /* ZORBA_STRING_UTIL_ASCII_UTIL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set et sw=2 ts=2: */
