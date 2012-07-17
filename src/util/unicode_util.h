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
#ifndef ZORBA_UNICODE_UTIL_H
#define ZORBA_UNICODE_UTIL_H

#include <zorba/config.h>

#include <cctype>
#include <cstring>
#include <cwchar>

#include <zorba/internal/ztd.h>

#ifdef ZORBA_NO_ICU
# include "zorbamisc/config/stdint.h"
# include "zorbatypes/zstring.h"
#else
# include <unicode/unistr.h>
#endif /* ZORBA_NO_ICU */

#include "stl_util.h"

namespace zorba {
namespace unicode {

////////// types //////////////////////////////////////////////////////////////

/**
 * The character type that can hold a Unicode character encoded in UTF-16.  Do
 * not assume that this is an unsigned type.
 */
#ifdef ZORBA_NO_ICU
  typedef char char_type;
#else
  typedef /* ICU's */ UChar char_type;
#endif /* ZORBA_NO_ICU */

/**
 * The type type that can hold a Unicode code-point.  Do not assume that this
 * is an unsigned type.
 */
#ifdef ZORBA_NO_ICU
typedef uint32_t code_point;
#else
typedef /* ICU's */ UChar32 code_point;
#endif /* ZORBA_NO_ICU */

/**
 * The type that represents the size of a string.  Do not assume that this is
 * an unsigned type.
 */
typedef int32_t size_type;

/**
 * Unicode normalization modes.
 */
namespace normalization {
  enum type {
    none, ///< No decomposition/composition.
    NFC,  ///< Canonical decomposition followed by canonical composition.
    NFD,  ///< Canonical decomposition.
    NFKC, ///< Compatibility decomposition followed by canonical composition.
    NFKD  ///< Compatibility decomposition.
  };
}

#ifndef ZORBA_NO_ICU
/**
 * A Unicode string.
 */
typedef U_NAMESPACE_QUALIFIER UnicodeString string;
#else
/**
 * Since there is no ICU, just use a zstring as a "Unicode" string.
 */
typedef zstring string;
#endif /* ZORBA_NO_ICU */

////////// code-point checking ////////////////////////////////////////////////

/**
 * Checks whether the given character is invalid in an IRI.
 *
 * @param c The character.
 * @return Returns \c true only if the character is invalid in an IRI.
 * See RFC 3987.
 */
bool is_invalid_in_iri( code_point c );

/**
 * Checks whether the given character is a "iprivate".
 *
 * @param c The character.
 * @return Returns \c true only if the character is a "iprivate".
 * See RFC 3987.
 */
bool is_iprivate( code_point c );

/**
 * Unicode version of isspace(3).
 *
 * @param c The code-point to check.
 * @return Returns \c true only if \a c is a whitespace character.
 */
inline bool is_space( code_point c ) {
#ifdef WIN32
  // Windows' isspace() implementation crashes for non-ASCII characters.
  char const ascii_c = static_cast<char>( c & 0x7F );
  return ascii_c == c && isspace( ascii_c );
#else
  return isspace( c );
#endif /* WIN32 */
}

/**
 * Checks whether the given character is a "ucschar".
 *
 * @param c The character.
 * @return Returns \c true only if the character is a "ucschar".
 * See RFC 3987.
 */
bool is_ucschar( code_point c );

/**
 * Checks whether the given code-point is valid.
 *
 * @param c The code-point to check.
 * @return Returns \c true only if the code-point is valid.
 */
template<typename CodePointType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<CodePointType>::value,
                        bool>::type
is_valid( CodePointType c ) {
  return  (ztd::ge0( c ) && c <= 0x00D7FF)
      ||  (c >= 0x00E000 && c <= 0x00FFFD)
      ||  (c >= 0x010000 && c <= 0x10FFFF);
}

////////// case checking & conversion /////////////////////////////////////////

/**
 * Tests whether the given character is lower-case.
 *
 * @param c The character.
 * @return Returns \c true only if the character is lower-case.
 */
bool is_lower( code_point c );

/**
 * Tests whether the given character is upper-case.
 *
 * @param c The character.
 * @return Returns \c true only if the character is upper-case.
 */
bool is_upper( code_point c );

/**
 * Converts the given character to lower-case.
 *
 * @param c The character to convert.
 * @return Returns the given character converted to lower-case or the original
 * character if either it was already lower-case or not a letter.
 */
code_point to_lower( code_point c );

/**
 * Converts the given character to upper-case.
 *
 * @param c The character to convert.
 * @return Returns the given character converted to upper-case or the original
 * character if either it was already upper-case or not a letter.
 */
code_point to_upper( code_point c );

////////// normalization //////////////////////////////////////////////////////

#ifndef ZORBA_NO_ICU

/**
 * Normalizes the given string.
 *
 * @param in The string to normalize.
 * @param out The normalized string.  It is overwritten.
 * @return Returns \c true only if the normalization succeeded.
 */
bool normalize( string const &in, normalization::type n, string *out );

/**
 * Strips all diacritical marks from all characters converting them to their
 * closest non-diacritical equivalents.
 *
 * @param in The input string.
 * @param out The output string.
 * @return Returns \c true only if the strip succeeded.
 */
bool strip_diacritics( string const &in, string *out );

#endif /* ZORBA_NO_ICU */

////////// string conversion //////////////////////////////////////////////////

#ifndef ZORBA_NO_ICU
/**
 * Converts a single UTF-8 encoded character into a single Unicode character.
 *
 * @param in The UTF-8 encoded character.
 * @param out The address of the result.
 * @return Returns \c true only if the conversion succeeded.
 */
bool to_char( char const *in, char_type *out );
#endif /* ZORBA_NO_ICU */

/**
 * Converts a UTF-8 encoded string into a sequence of Unicode characters.
 *
 * @param in The UTF-8 encoded C string.
 * @param in_len The number of bytes (not characters) in the string.
 * @param out The address of the pointer to set to the result.  It is the
 * caller's responsibility to deallocate this (using <code>delete[]</code>).
 * @param out_len The number of characters (not bytes) of the result.
 * @return Returns \c true only if the conversion succeeded.
 */
bool to_string( char const *in, size_type in_len, char_type **out,
                size_type *out_len );

/**
 * Converts a C string to a Unicode string.
 *
 * @param in The UTF-8 encoded C string.
 * @param in_len The number of bytes (not characters) in the string.
 * @param out The Unicode string result.
 * @return Returns \c true only if the conversion succeeded.
 */
#ifndef ZORBA_NO_ICU
ZORBA_DLL_PUBLIC
bool to_string( char const *in, size_type in_len, string *out );
#else
inline bool to_string( char const *in, size_type in_len, string *out ) {
  out->assign( in, in_len );
  return true;
}
#endif /* ZORBA_NO_ICU */

/**
 * Converts a C string to a Unicode string.
 *
 * @param in The UTF-8 encoded C string.
 * @param out The Unicode string result.
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool to_string( char const *in, string *out ) {
  return to_string( in, (size_type)std::strlen( in ), out );
}

#ifndef ZORBA_NO_ICU

/**
 * Converts a wide-character string to a Unicode string.
 *
 * @param in The wide-character string.
 * @param in_len The number of characters (not bytes) of \a in.
 * @param out The Unicode string result.
 * @return Returns \c true only if the conversion succeeded.
 */
bool to_string( wchar_t const *in, size_type in_len, string *out );

/**
 * Converts a wide-character string to a Unicode string.
 *
 * @param in The wide-character string.
 * @param out The Unicode string result.
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool to_string( wchar_t const *in, string *out ) {
  return to_string( in, static_cast<size_type>( std::wcslen( in ) ), out );
}

#endif /* ZORBA_NO_ICU */

/**
 * Converts a string to a Unicode string.
 *
 * @tparam StringType The string type.
 * @param in The input string.
 * @param out The Unicode string result.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType>
inline bool to_string( StringType const &in, string *out ) {
  return to_string( in.data(), static_cast<size_type>( in.size() ), out );
}

////////// UTF-16 surrogate pairs /////////////////////////////////////////////

/**
 * Converts the given high and low surrogate values into the code-point they
 * represent.  Note that no checking is done on the parameters.
 *
 * @param high The high surrogate value.
 * @param low The low surrogate value.
 * @return Returns the represented code-point.
 * @see is_high_surrogate()
 * @see is_low_surrogate()
 */
inline code_point convert_surrogate( unsigned high, unsigned low ) {
  return 0x10000 + ((high - 0xD800) << 10) + (low - 0xDC00);
}

/**
 * Converts the given code-point into the high and low surrogate values that
 * represent it.  Note that no checking is done on the parameters.
 *
 * @tparam ResultType The integer type for the results.
 * @param c The code-point to convert.
 * @param high A pointer to where to put the high surrogate.
 * @param low A pointer to where to put the low surrogate.
 */
template<typename ResultType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<ResultType>::value,
                        void>::type
covert_surrogate( code_point c, ResultType *high, ResultType *low ) {
  code_point const n = c - 0x10000;
  *high = 0xD800 + (static_cast<unsigned>(n) >> 10);
  *low  = 0xDC00 + (n & 0x3FF);
}

/**
 * Checks whether the given value is a "high surrogate."
 *
 * @param n The value to check.
 * @return Returns \c true only if \a n is a high surrogate.
 */
inline bool is_high_surrogate( unsigned long n ) {
  return n >= 0xD800 && n <= 0xDBFF;
}

/**
 * Checks whether the given value is a "low surrogate."
 *
 * @param n The value to check.
 * @return Returns \c true only if \a n is a low surrogate.
 */
inline bool is_low_surrogate( unsigned long n ) {
  return n >= 0xDC00 && n <= 0xDFFF;
}

/**
 * Checks whether the given code-point is in the "supplementary plane" and
 * therefore would need a surrogate pair to be encoded in UTF-16.
 *
 * @param c The code-point to check.
 * @return Returns \c true only if \a c is within the supplementary plane.
 */
inline bool is_supplementary_plane( code_point c ) {
  return c >= 0x10000 && c <= 0x10FFFF;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace unicode
} // namespace zorba

#endif /* ZORBA_UNICODE_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
