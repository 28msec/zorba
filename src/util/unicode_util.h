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

#ifdef ZORBA_NO_UNICODE
# include "zorbamisc/config/stdint.h"
# include "zorbatypes/zstring.h"
#else
# include <unicode/unistr.h>
#endif /* ZORBA_NO_UNICODE */

#include "stl_util.h"

namespace zorba {
namespace unicode {

////////// types //////////////////////////////////////////////////////////////

/**
 * The character type that can hold a Unicode character encoded in UTF-16.  Do
 * not assume that this is an unsigned type.
 */
#ifdef ZORBA_NO_UNICODE
  typedef char char_type;
#else
  typedef /* ICU's */ UChar char_type;
#endif /* ZORBA_NO_UNICODE */

/**
 * The type type that can hold a Unicode code-point.  Do not assume that this
 * is an unsigned type.
 */
#ifdef ZORBA_NO_UNICODE
typedef uint32_t code_point;
#else
typedef /* ICU's */ UChar32 code_point;
#endif /* ZORBA_NO_UNICODE */

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

#ifndef ZORBA_NO_UNICODE
/**
 * A Unicode string.
 */
typedef U_NAMESPACE_QUALIFIER UnicodeString string;
#else
/**
 * Since there is no ICU, just use a zstring as a "Unicode" string.
 */
typedef zstring string;
#endif /* ZORBA_NO_UNICODE */

////////// code-point checking ////////////////////////////////////////////////

/**
 * Test whether the given character is invalid in an IRI.
 *
 * @param c The character.
 * @return Returns \c true only if the character is invalid in an IRI.
 * See RFC 3987.
 */
ZORBA_DLL_PUBLIC
bool is_invalid_in_iri( code_point c );

/**
 * Test whether the given character is a "iprivate".
 *
 * @param c The character.
 * @return Returns \c true only if the character is a "iprivate".
 * See RFC 3987.
 */
ZORBA_DLL_PUBLIC
bool is_iprivate( code_point c );

/**
 * Unicode version is isspace(3).
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
#endif
}

/**
 * Test whether the given character is a "ucschar".
 *
 * @param c The character.
 * @return Returns \c true only if the character is a "ucschar".
 * See RFC 3987.
 */
ZORBA_DLL_PUBLIC
bool is_ucschar( code_point c );

/**
 * Checks whether the given code-point is valid.
 *
 * @param c The code-point to check.
 * @return Returns \c true only if the code-point is valid.
 */
template<class CodePointType>
inline bool is_valid( CodePointType c ) {
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
ZORBA_DLL_PUBLIC
bool is_lower( code_point c );

/**
 * Tests whether the given character is upper-case.
 *
 * @param c The character.
 * @return Returns \c true only if the character is upper-case.
 */
ZORBA_DLL_PUBLIC
bool is_upper( code_point c );

/**
 * Converts the given character to lower-case.
 *
 * @param c The character to convert.
 * @return Returns the given character converted to lower-case or the original
 * character if either it was already lower-case or not a letter.
 */
ZORBA_DLL_PUBLIC
code_point to_lower( code_point c );

/**
 * Converts the given character to upper-case.
 *
 * @param c The character to convert.
 * @return Returns the given character converted to upper-case or the original
 * character if either it was already upper-case or not a letter.
 */
ZORBA_DLL_PUBLIC
code_point to_upper( code_point c );

////////// normalization //////////////////////////////////////////////////////

#ifndef ZORBA_NO_UNICODE
/**
 * Normalizes the given string.
 *
 * @param in The string to normalize.
 * @param out The normalized string.  It is overwritten.
 * @return Returns \c true only if the normalization succeeded.
 */
ZORBA_DLL_PUBLIC
bool normalize( string const &in, normalization::type n, string *out );
#endif /* ZORBA_NO_UNICODE */

////////// string conversion //////////////////////////////////////////////////

#ifndef ZORBA_NO_UNICODE
/**
 * Converts a single UTF-8 encoded character into a single Unicode character.
 *
 * @param in The UTF-8 encoded character.
 * @param out The address of the result.
 * @return Returns \c true only if the conversion succeeded.
 */
bool to_char( char const *in, char_type *out );
#endif /* ZORBA_NO_UNICODE */

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
#ifndef ZORBA_NO_UNICODE
ZORBA_DLL_PUBLIC
bool to_string( char const *in, size_type in_len, string *out );
#else
inline bool to_string( char const *in, size_type in_len, string *out ) {
  out->assign( in, in_len );
  return true;
}
#endif /* ZORBA_NO_UNICODE */

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

#ifndef ZORBA_NO_UNICODE

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

#endif /* ZORBA_NO_UNICODE */

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
