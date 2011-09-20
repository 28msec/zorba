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

////////// constants //////////////////////////////////////////////////////////

char const whitespace[] = " \f\n\r\t\v";

////////// Non-ASCII character stripping //////////////////////////////////////

/**
 * A %back_ascii_insert_iterator can be used to append characters to a string
 * ensuring that non-ASCII characters are excluded.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_ascii_insert_iterator :
  public
    ztd::back_insert_iterator_base<
      StringType, back_ascii_insert_iterator<StringType>
    >
{
  typedef ztd::back_insert_iterator_base<
    StringType, back_ascii_insert_iterator<StringType>
  > base_type;
public:
  typedef typename base_type::container_type container_type;
  typedef typename StringType::value_type value_type;

  /**
   * Constructs a %back_ascii_insert_iterator.
   *
   * @param s The string to append to.
   */
  explicit back_ascii_insert_iterator( StringType &s ) : base_type( s ) {
  }

  back_ascii_insert_iterator& operator=( value_type c );
};

/**
 * This is a convenience function to create a back_ascii_insert_iterator.
 *
 * @tparam StringType The string type.
 * @param out The output string.
 */
template<class StringType> inline back_ascii_insert_iterator<StringType>
back_ascii_inserter( StringType &out ) {
  return back_ascii_insert_iterator<StringType>( out );
}

////////// Character testing //////////////////////////////////////////////////

/**
 * Checks whether the given character is an ASCII character.  This
 * function exists to make a proper function out of the standard isascii(3)
 * that may be implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is an ASCII character.
 */
template<typename CharType> inline
bool is_ascii( CharType c ) {
#ifdef WIN32
  return __isascii( c );
#else
  return isascii( c );
#endif
}

/**
 * Checks whether the given character is an alphabetic character.  This
 * function exists to make a proper function out of the standard isalpha(3)
 * that may be implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is an alphabetic character.
 */
template<typename CharType> inline
bool is_alpha( CharType c ) {
#ifdef WIN32
  // Windows' isalpha() implementation crashes for non-ASCII characters.
  return __isascii( c ) && isalpha( c );
#else
  return isalpha( c );
#endif
}

/**
 * Checks whether the given character is an alpha-numeric character.  This
 * function exists to make a proper function out of the standard isalnum(3)
 * that may be implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is an alpha-numeric character.
 */
template<typename CharType> inline
bool is_alnum( CharType c ) {
#ifdef WIN32
  // Windows' isalpha() implementation crashes for non-ASCII characters.
  return __isascii( c ) && isalnum( c );
#else
  return isalnum( c );
#endif
}

/**
 * Checks whether the given character is a decimal digit.  This function exists
 * to make a proper function out of the standard isdigit(3) that may be
 * implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is a decimal digit.
 */
template<typename CharType> inline
bool is_digit( CharType c ) {
#ifdef WIN32
  // Windows' isdigit() implementation crashes for non-ASCII characters.
  return __isascii( c ) && isdigit( c );
#else
  return isdigit( c );
#endif
}

/**
 * Checks whether the given character is a punctuation character.  This function
 * exists to make a proper function out of the standard ispunct(3) that may be
 * implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is a punctuation character.
 */
template<typename CharType> inline
bool is_punct( CharType c ) {
#ifdef WIN32
  // Windows' ispunct() implementation crashes for non-ASCII characters.
  return __isascii( c ) && ispunct( c );
#else
  return ispunct( c );
#endif
}

/**
 * Checks whether the given character is a whitespace character.  This function
 * exists to make a proper function out of the standard isspace(3) that may be
 * implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is a whitespace character.
 */
template<typename CharType> inline
bool is_space( CharType c ) {
#ifdef WIN32
  // Windows' isspace() implementation crashes for non-ASCII characters.
  return __isascii( c ) && isspace( c );
#else
  return isspace( c );
#endif
}

/**
 * Checks whether an entire string is whitespace.
 *
 * @param s The NULL-terminated C string to check.
 * @return Returns \c true only if the entire string is whitespace.
 */
ZORBA_DLL_PUBLIC bool is_whitespace( char const *s );

/**
 * Checks whether an entire string is whitespace.
 *
 * @param s The string to check.
 * @return Returns \c true only if the entire string is whitespace.
 */
template<class StringType> inline
bool is_whitespace( StringType const &s ) {
  return is_whitespace( s.c_str() );
}

/**
 * Checks whether the given character is a hexadecimal decimal digit.  This
 * function exists to make a proper function out of the standard isxdigit(3)
 * that may be implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is a hexadecimal digit.
 */
template<typename CharType> inline
bool is_xdigit( CharType c ) {
#ifdef WIN32
  // Windows' isxdigit() implementation crashes for non-ASCII characters.
  return __isascii( c ) && isxdigit( c );
#else
  return isxdigit( c );
#endif
}

////////// begins/ends_with ///////////////////////////////////////////////////

/**
 * Checks whether a string begins with a given prefix.
 *
 * @param s The string to check.
 * @param c The prefix character.
 * @return Returns \c true only if \a s begins with \a c.
 */
inline bool begins_with( char const *s, char c ) {
  return s[0] == c;
}

/**
 * Checks whether a string begins with a given prefix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param c The prefix character.
 * @return Returns \c true only if \a s begins with \a c.
 */
template<class StringType> inline
bool begins_with( StringType const &s, char c ) {
  return !s.empty() && s[0] == c;
}

/**
 * Checks whether a string begins with a given prefix.
 *
 * @param s The string to check.
 * @param ps The prefix string.
 * @param n The number of bytes to compare.
 * @return Returns \c true only if \a s begins with \a ps.
 */
inline bool begins_with( char const *s, char const *ps, size_type n ) {
  return std::strncmp( s, ps, n ) == 0;
}

/**
 * Checks whether a string begins with a given prefix.
 *
 * @param s The string to check.
 * @param ps The prefix string.
 * @return Returns \c true only if \a s begins with \a ps.
 */
inline bool begins_with( char const *s, char const *ps ) {
  return begins_with( s, ps, std::strlen( ps ) );
}

/**
 * Checks whether a string begins with a given prefix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param ps The prefix string.
 * @param n The number of bytes to compare.
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
 * @param s The string to check.
 * @param c The suffix character.
 * @return Returns \c true only if \a s ends with \a c.
 */
inline bool ends_with( char const *s, char c ) {
  size_type const len = std::strlen( s );
  return len > 0 && s[ len - 1 ] == c;
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
 * @param s The string to check.
 * @param ss The suffix string.
 * @param ss_len The length of the suffix string.
 * @return Returns \c true only if \a s ends with \a ss.
 */
inline bool ends_with( char const *s, char const *ss, size_type ss_len ) {
  size_type const len = std::strlen( s );
  return ss_len <= len && std::strncmp( s + len - ss_len, ss, ss_len ) == 0;
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @param s The string to check.
 * @param ss The suffix string.
 * @return Returns \c true only if \a s ends with \a ss.
 */
inline bool ends_with( char const *s, char const *ss ) {
  return ends_with( s, ss, std::strlen( ss ) );
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

////////// Case conversion ////////////////////////////////////////////////////

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
 * @param begin A pointer to the first character of the string.
 * @param end A pointer to one past the last character of the string.
 */
inline void to_lower( char *begin, char *end ) {
  std::transform( begin, end, begin, static_cast<char (*)(char)>( to_lower ) );
}

/**
 * Converts a string to lower-case in-place.
 *
 * @param s The string to convert.
 */
inline void to_lower( char *s ) {
  to_lower( s, s + std::strlen( s ) );
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
 * @param begin A pointer to the first character of the string.
 * @param end A pointer to one past the last character of the string.
 */
inline void to_upper( char *begin, char *end ) {
  std::transform( begin, end, begin, static_cast<char (*)(char)>( to_upper ) );
}

/**
 * Converts a string to upper-case in-place.
 *
 * @param s The string to convert.
 */
inline void to_upper( char *s ) {
  to_upper( s, s + std::strlen( s ) );
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

////////// Replacement ////////////////////////////////////////////////////////

/**
 * Replaces all occurrences of one character with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The character to replace.
 * @param to The character to replace with.
 * @return Returns \c true only if at least one replacement is performed.
 */
template<class StringType>
bool replace_all( StringType &s, char from, char to );

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param from_len The length of \a from.
 * @param to The substring to replace with.
 * @param to_len The length of \a to.
 * @return Returns \c true only if at least one replacement is performed.
 */
template<class StringType>
bool replace_all( StringType &s,
                  char const *from, typename StringType::size_type from_len,
                  char const *to, typename StringType::size_type to_len );

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param to The substring to replace with.
 * @return Returns \c true only if at least one replacement is performed.
 */
template<class StringType> inline
bool replace_all( StringType &s, char const *from, char const *to ) {
  return replace_all( s, from, std::strlen( from ), to, std::strlen( to ) );
}

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param to The substring to replace with.
 * @return Returns \c true only if at least one replacement is performed.
 */
template<class StringType,class ToStringType> inline
bool replace_all( StringType &s, char const *from, ToStringType const &to ) {
  return replace_all( s, from, std::strlen( from ), to.data(), to.size() );
}

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param to The substring to replace with.
 * @return Returns \c true only if at least one replacement is performed.
 */
template<class StringType,class FromStringType,class ToStringType> inline
bool replace_all( StringType &s, FromStringType const &from,
                                 ToStringType const &to ) {
  return replace_all( s, from.data(), from.size(), to.data(), to.size() );
}

////////// Whitespace /////////////////////////////////////////////////////////

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
 * Skips leading specified characters.
 *
 * @param s The string to trim.
 * @param chars The characters to trim.
 * @return Returns a pointer to the first character in \a s that is not among
 * the characters in \a chars.
 */
ZORBA_DLL_PUBLIC
char const* trim_start( char const *s, char const *chars );

/**
 * Skips leading specified characters.
 *
 * @param s The string to trim.
 * @param s_len The length of \a s.
 * @param chars The characters to trim.
 * @return Returns a pointer to the first character in \a s that is not among
 * the characters in \a chars.
 */
ZORBA_DLL_PUBLIC
char const* trim_start( char const *s, size_type s_len, char const *chars );

/**
 * Removes all leading specified characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param chars The characters to trim.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType>
void trim_start( InputStringType const &in, char const *chars,
                 OutputStringType *out );

/**
 * Removes all leading specified characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void trim_start( StringType &s, char const *chars ) {
  StringType temp;
  trim_start( s, chars, &temp );
  s = temp;
}

/**
 * Skips leading whitespace chracters.
 *
 * @param s The string to trim.
 * @return Returns a pointer to the first character in \a s that is not a
 * whitespace character.
 */
inline char const* trim_start_whitespace( char const *s ) {
  return trim_start( s, whitespace );
}

/**
 * Skips leading whitespace characters.
 *
 * @param s The string to trim.
 * @param s_len The length of \a s.
 * @return Returns a pointer to the first character in \a s that is not a
 * whitespace character.
 */
inline char const* trim_start_whitespace( char const *s, size_type s_len ) {
  return trim_start( s, s_len, whitespace );
}

/**
 * Removes all leading whitespace characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType> inline
void trim_start_whitespace( InputStringType const &in, OutputStringType *out ) {
  trim_start( in, whitespace, out );
}

/**
 * Removes all leading whitespace characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void trim_start_whitespace( StringType &s ) {
  StringType temp;
  trim_start_whitespace( s, &temp );
  s = temp;
}

/**
 * Skips trailing specified characters.
 *
 * @param s The string to trim.
 * @param s_len The length of \a s.
 * @param chars The characters to trim.
 * @return Returns the new length of \a s.
 */
ZORBA_DLL_PUBLIC
size_type trim_end( char const *s, size_type s_len, char const *chars );

/**
 * Skips trailing specified characters.
 *
 * @param s The string to trim.
 * @param chars The characters to trim.
 * @return Returns the new length of \a s.
 */
inline size_type trim_end( char const *s, char const *chars ) {
  return trim_end( s, std::strlen( s ), chars );
}

/**
 * Removes all trailing specified characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param chars The characters to trim.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType>
void trim_end( InputStringType const &in, char const *chars,
               OutputStringType *out );

/**
 * Removes all trailing specified characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void trim_end( StringType &s, char const *chars ) {
  StringType temp;
  trim_end( s, chars, &temp );
  s = temp;
}

/**
 * Skips trailing whitespace characters.
 *
 * @param s The string to trim.
 * @param s_len The length of \a s.
 * @return Returns the new length of \a s.
 */
inline size_type trim_end_whitespace( char const *s, size_type s_len ) {
  return trim_end( s, s_len, whitespace );
}

/**
 * Skips trailing whitespace characters.
 *
 * @param s The string to trim.
 * @return Returns the new length of \a s.
 */
inline size_type trim_end_whitespace( char const *s ) {
  return trim_end( s, whitespace );
}

/**
 * Removes all trailing whitespace characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType>
void trim_end_whitespace( InputStringType const &in, OutputStringType *out ) {
  return trim_end( in, whitespace, out );
}

/**
 * Removes all trailing whitespace characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void trim_end_whitespace( StringType &s, char const *chars ) {
  trim_end( s, whitespace );
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
  trim( in, whitespace, out );
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
 * @param s The input C string.
 * @param s_len The length of the string.
 * @param pos The position within \a s where to start looking for whitespace.
 * On return, \a pos is updated with the position of the 1st non-whitespace
 * char.
 * @deprecated Use trim_start_whitespace() instead.
 */
inline void skip_whitespace( char const *s, size_type s_len, size_type *pos ) {
  *pos = trim_start_whitespace( s + *pos, s_len - *pos ) - s;
}

////////// Miscellaneous //////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

} // namespace ascii
} // namespace zorba

#include "ascii_util.tcc"

#endif /* ZORBA_STRING_UTIL_ASCII_UTIL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
