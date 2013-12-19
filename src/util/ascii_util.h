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

// standard
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstring>
#include <functional>
#include <iterator>

// local
#include "omanip.h"
#include "stl_util.h"

namespace zorba {
namespace ascii {

////////// types //////////////////////////////////////////////////////////////

/**
 * The size type.
 */
typedef std::size_t size_type;

////////// constants //////////////////////////////////////////////////////////

char const alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char const alnum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
char const digit[] = "0123456789";
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
  explicit back_ascii_insert_iterator( StringType *s ) : base_type( s ) {
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
back_ascii_inserter( StringType *out ) {
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
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_ascii( CharType c ) {
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
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_alpha( CharType c ) {
  return is_ascii( c ) && isalpha( c );
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
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_alnum( CharType c ) {
  return is_ascii( c ) && isalnum( c );
}

/**
 * Checks whether the given character is a control character.  This function
 * exists to make a proper function out of the standard iscntrl(3) that may be
 * implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is a control character.
 */
template<typename CharType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_cntrl( CharType c ) {
  return is_ascii( c ) && iscntrl( c );
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
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_digit( CharType c ) {
  return is_ascii( c ) && isdigit( c );
}

/**
 * Checks whether the given character is a printing character.  This function
 * exists to make a proper function out of the standard isprint(3) that may be
 * implemented as a macro.
 *
 * @param CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is a printing character.
 */
template<typename CharType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_print( CharType c ) {
  return is_ascii( c ) && isprint( c );
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
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_punct( CharType c ) {
  return is_ascii( c ) && ispunct( c );
}

/**
 * Checks whether the given character is a whitespace character.  This function
 * exists to make a proper function out of the standard isspace(3) that may be
 * implemented as a macro.
 *
 * @tparam CharType The character type.
 * @param c The character to check.
 * @return Returns \c true only if the character is a whitespace character.
 */
template<typename CharType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_space( CharType c ) {
  return is_ascii( c ) && isspace( c );
}

/**
 * Checks whether an entire string is whitespace.
 *
 * @param s The NULL-terminated C string to check.
 * @return Returns \c true only if the entire string is whitespace.
 */
bool is_space( char const *s );

/**
 * Checks whether an entire string is whitespace.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @return Returns \c true only if the entire string is whitespace.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(StringType),bool>::type
is_space( StringType const &s ) {
  return is_space( s.c_str() );
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
typename std::enable_if<ZORBA_TR1_NS::is_integral<CharType>::value,bool>::type
is_xdigit( CharType c ) {
  return is_ascii( c ) && isxdigit( c );
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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
begins_with( StringType const &s, char c ) {
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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
begins_with( StringType const &s, char const *ps,
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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
begins_with( StringType const &s, char const *ps ) {
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
typename std::enable_if<ZORBA_IS_STRING(StringType)
                     && ZORBA_IS_STRING(PrefixStringType),
                        bool>::type
begins_with( StringType const &s, PrefixStringType const &ps ) {
  return begins_with( s, ps.data(), ps.size() );
}

/**
 * A macro for calling ascii::begins_with() with a second argument of a string
 * literal.
 */
#define ZA_BEGINS_WITH(STRING,LITERAL) \
  ::zorba::ascii::begins_with( STRING, LITERAL, sizeof( LITERAL ) - 1 )

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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
ends_with( StringType const &s, char c ) {
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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
ends_with( StringType const &s, char const *ss,
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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
ends_with( StringType const &s, char const *ss ) {
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
typename std::enable_if<ZORBA_IS_STRING(StringType)
                     && ZORBA_IS_STRING(SuffixStringType),
                        bool>::type
ends_with( StringType const &s, SuffixStringType const &ss ) {
  return ends_with( s, ss.data(), ss.size() );
}

/**
 * A macro for calling ascii::ends_with() with a second argument of a string
 * literal.
 */
#define ZA_ENDS_WITH(STRING,LITERAL) \
  ::zorba::ascii::ends_with( STRING, LITERAL, sizeof( LITERAL ) - 1 )

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
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
to_lower( StringType &s ) {
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_lower( InputStringType const &in, OutputStringType *out ) {
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
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
to_upper( StringType &s ) {
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_upper( InputStringType const &in, OutputStringType *out ) {
  std::transform(
    in.begin(), in.end(), std::back_inserter( *out ),
    static_cast<char (*)(char)>( to_upper )
  );
}

/**
 * A unary_function to convert a (presumed) lower-case string to title-case
 * "Like This."
 */
class to_title : public std::unary_function<char,char> {
public:
  to_title() : capitalize_( true ) { }

  result_type operator()( argument_type c ) {
    if ( is_alpha( c ) ) {
      if ( capitalize_ ) {
        c = to_upper( c );
        capitalize_ = false;
      }
    } else if ( is_space( c ) )
      capitalize_ = true;
    return c;
  };

private:
  bool capitalize_;
};

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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
replace_all( StringType &s, char from, char to );

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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
replace_all( StringType &s,
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
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
replace_all( StringType &s, char const *from, char const *to ) {
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
typename std::enable_if<ZORBA_IS_STRING(StringType)
                     && ZORBA_IS_STRING(ToStringType),
                        bool>::type
replace_all( StringType &s, char const *from, ToStringType const &to ) {
  return replace_all( s, from, std::strlen( from ), to.data(), to.size() );
}

/**
 * Replaces all occurrences of one substring with another.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The substring to replace.
 * @param from_len The length of \a from.
 * @param to The substring to replace with.
 * @return Returns \c true only if at least one replacement is performed.
 */
template<class StringType,class ToStringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType)
                     && ZORBA_IS_STRING(ToStringType),
                        bool>::type
replace_all( StringType &s,
             char const *from, typename StringType::size_type from_len,
             ToStringType const &to ) {
  return replace_all( s, from, from_len, to.data(), to.size() );
}

/**
 * Replaces all occurrences of a character with a string.
 *
 * @tparam StringType The string type.
 * @param s The string to modify.
 * @param from The character to replace.
 * @param to The substring to replace with.
 * @return Returns \c true only if at least one replacement is performed.
 */
template<class StringType,class ToStringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType)
                     && ZORBA_IS_STRING(ToStringType),
                        bool>::type
replace_all( StringType &s, char from, ToStringType const &to ) {
  return replace_all( s, &from, 1, to.data(), to.size() );
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
typename std::enable_if<ZORBA_IS_STRING(StringType)
                     && ZORBA_IS_STRING(FromStringType)
                     && ZORBA_IS_STRING(ToStringType),
                        bool>::type
replace_all( StringType &s, FromStringType const &from,
             ToStringType const &to ) {
  return replace_all( s, from.data(), from.size(), to.data(), to.size() );
}

////////// Integer-to-string conversion ///////////////////////////////////////

/**
 * A type that can hold the largest possible C string equivalent of the largest
 * possible integral value (assuming 8 bytes for a <code>long long</code>).
 */
typedef char itoa_buf_type[ 20 + 1 /* for null */ ];

/**
 * Converts a <code>long long</code> to a C string.
 *
 * @param n The <code>long long</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
char* itoa( long long n, char *buf );

/**
 * Converts a \c char to a C string.
 *
 * @param n The \c char to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( char n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts a <code>signed char</code> to a C string.
 *
 * @param n The <code>signed char</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( signed char n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts a \c short to a C string.
 *
 * @param n The \c short to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( short n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts an \c int to a C string.
 *
 * @param n The \c int to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( int n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts a \c long to a C string.
 *
 * @param n The \c long to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( long n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts an <code>unsigned long long</code> to a C string.
 *
 * @param n The <code>unsigned long long</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
char* itoa( unsigned long long n, char *buf );

/**
 * Converts an <code>unsigned char</code> to a C string.
 *
 * @param n The <code>unsigned char</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned char n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
}

/**
 * Converts an <code>unsigned short</code> to a C string.
 *
 * @param n The <code>unsigned short</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned short n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
}

/**
 * Converts an <code>unsigned int</code> to a C string.
 *
 * @param n The <code>unsigned int</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned int n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
}

/**
 * Converts an <code>unsigned long</code> to a C string.
 *
 * @param n The <code>unsigned long</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned long n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
normalize_space( InputStringType const &in, OutputStringType *out );

/**
 * Converts sequences of one or more whitespace characters to a single space.
 * Additionally, all leading and trailing whitespace is removed.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
normalize_space( StringType &s ) {
  StringType temp;
  normalize_space( s, &temp );
  s = temp;
}

/**
 * Removes all specified characters by shifting the contents of the buffer to
 * the left.
 *
 * @param s The string to remove characters from.
 * @param s_len The length of \a s.
 * @param chars The characters to remove.
 * @return Returns the new length of \a s with all \a chars removed.
 */
size_type remove_chars( char *s, size_type s_len, char const *chars );

/**
 * Removes all characters that are not among the specified characters.
 *
 * @tparam StringType The string type.
 * @param s The string to remove characters from.
 * @param keep_chars The characters to keep.
 */
template<class StringType>
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
remove_not_chars( StringType &s, char const *keep_chars );

/**
 * Removes all whitespace characters by shifting the contents of the buffer to
 * the left.
 *
 * @param s The string.
 * @param s_len The length of \a s.
 * @return Returns the new length of \a s with all whitespace removed.
 */
inline size_type remove_space( char *s, size_type s_len ) {
  return remove_chars( s, s_len, whitespace );
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
trim( InputStringType const &in, char const *chars, OutputStringType *out );

/**
 * Removes all leading and trailing specified characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
trim( StringType &s, char const *chars ) {
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
char const* trim_start( char const *s, char const *chars );

/**
 * Skips leading specified characters.
 *
 * @param s The string to trim.
 * @param s_len A pointer to the length of \a s.  It is updated with the new
 * length.
 * @param chars The characters to trim.
 * @return Returns a pointer to the first character in \a s that is not among
 * the characters in \a chars.
 */
char const* trim_start( char const *s, size_type *s_len, char const *chars );

/**
 * Skips leading specified characters.
 *
 * @param s The string to trim.
 * @param s_len The length of \a s.
 * @param chars The characters to trim.
 * @return Returns a pointer to the first character in \a s that is not among
 * the characters in \a chars.
 */
inline char const* trim_start( char const *s, size_type s_len,
                               char const *chars ) {
  return trim_start( s, &s_len, chars );
}

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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
trim_start( InputStringType const &in, char const *chars,
            OutputStringType *out );

/**
 * Removes all leading specified characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 * @param chars The characters to trim.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
trim_start( StringType &s, char const *chars ) {
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
inline char const* trim_start_space( char const *s ) {
  return trim_start( s, whitespace );
}

/**
 * Skips leading whitespace characters.
 *
 * @param s The string to trim.
 * @param s_len A pointer to the length of \a s.  It is updated with the new
 * length.
 * @return Returns a pointer to the first character in \a s that is not a
 * whitespace character.
 */
inline char const* trim_start_space( char const *s, size_type *s_len ) {
  return trim_start( s, s_len, whitespace );
}

/**
 * Skips leading whitespace characters.
 *
 * @param s The string to trim.
 * @param s_len The length of \a s.
 * @return Returns a pointer to the first character in \a s that is not a
 * whitespace character.
 */
inline char const* trim_start_space( char const *s, size_type s_len ) {
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
trim_start_space( InputStringType const &in, OutputStringType *out ) {
  trim_start( in, whitespace, out );
}

/**
 * Removes all leading whitespace characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
trim_start_space( StringType &s ) {
  StringType temp;
  trim_start_space( s, &temp );
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
trim_end( InputStringType const &in, char const *chars, OutputStringType *out );

/**
 * Removes all trailing specified characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
trim_end( StringType &s, char const *chars ) {
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
inline size_type trim_end_space( char const *s, size_type s_len ) {
  return trim_end( s, s_len, whitespace );
}

/**
 * Skips trailing whitespace characters.
 *
 * @param s The string to trim.
 * @return Returns the new length of \a s.
 */
inline size_type trim_end_space( char const *s ) {
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
trim_end_space( InputStringType const &in, OutputStringType *out ) {
  return trim_end( in, whitespace, out );
}

/**
 * Removes all trailing whitespace characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
trim_end_space( StringType &s ) {
  trim_end( s, whitespace );
}

/**
 * Removes all leading and trailing whitespace.
 *
 * @param s The input C string.
 * @param s_len A pointer to the length of \a s.  It is updated with the new
 * length.
 * @return Returns a pointer to the first character in \a s that is not
 * whitespace.
 */
inline char const* trim_space( char const *s, size_type *s_len ) {
  s = trim_start_space( s, s_len );
  *s_len = trim_end_space( s, *s_len );
  return s;
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
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
trim_space( InputStringType const &in, OutputStringType *out ) {
  trim( in, whitespace, out );
}

/**
 * Removes all leading and trailing whitespace.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
trim_space( StringType &s ) {
  StringType temp;
  trim_space( s, &temp );
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
 * @deprecated Use trim_start_space() instead.
 */
inline void skip_space( char const *s, size_type s_len, size_type *pos ) {
  *pos = trim_start_space( s + *pos, s_len - *pos ) - s;
}

/**
 * Skips any consecutive whitespace chars that are found at a given starting
 * position within a given string.
 *
 * @tparam StringType The string type.
 * @param s The string.
 * @param i A pointer to the iterator to advance past the whitespace.
 * On return, \a *i is updated with the position of the 1st non-whitespace
 * char.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),void>::type
skip_space( StringType const &s, typename StringType::const_iterator *i ) {
  typename StringType::difference_type const d = *i - s.begin();
  char const *const sd = s.data() + d;
  std::advance( *i, trim_start_space( sd, s.size() - d ) - sd );
}

////////// Miscellaneous //////////////////////////////////////////////////////

/**
 * Pads a string to the left with a given character until the string is the
 * given width.
 *
 * @param s The string to pad.
 * @param width The width to pad to.
 * @param c The character to pad with.
 * @return Returns \c *s.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),StringType&>::type
left_pad( StringType *s, typename StringType::size_type width, char c ) {
  typedef typename StringType::size_type size_type;
  if ( s->size() < width )
    s->insert( static_cast<size_type>( 0 ), width - s->size(), c );
  return *s;
}

/**
 * Pads a string to the right with a given character until the string is the
 * given width.
 *
 * @param s The string to pad.
 * @param width The width to pad to.
 * @param c The character to pad with.
 * @return Returns \c *s.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),StringType&>::type
right_pad( StringType *s, typename StringType::size_type width, char c ) {
  if ( s->size() < width )
    s->append( width - s->size(), c );
  return *s;
}

/**
 * Prints the given character in a printable way: if \c is_print(c) is \c true,
 * prints \a c as-is; otherwise prints \c #x followed by the hexadecimal value
 * of the character.
 *
 * @param o The ostream to print to.
 * @param c The \c char to print.
 * @return Returns \a o.
 */
std::ostream& printable_char( std::ostream &o, char c );

// An ostream manipulator version of the above.
DEF_OMANIP1( printable_char, char )

/**
 * Reverses the characters in a string.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string.
 */
template<class InputStringType,class OutputStringType> inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
reverse( InputStringType const &in, OutputStringType *out ) {
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
