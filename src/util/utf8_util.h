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
#ifndef ZORBA_UTF8_UTIL_H
#define ZORBA_UTF8_UTIL_H

#include <algorithm>
#include <cwchar>
#include <string>

#include <zorba/config.h>

#include "ascii_util.h"
#include "cxx_util.h"
#include "unicode_util.h"
#include "utf8_string.h"
#include "utf8_util_base.h"

#include "zorbatypes/collation_manager.h"
#include "zorbautils/hashfun.h"

#ifdef ZORBA_NO_UNICODE
# include "diagnostics/assert.h"
#else
# include "zorbatypes/libicu.h"
#endif /* ZORBA_NO_UNICODE */

namespace zorba {
namespace utf8 {

using ascii::begins_with;
using ascii::ends_with;
using ascii::is_whitespace;
using ascii::normalize_whitespace;
using ascii::trim_whitespace;

////////// begins/ends_with ///////////////////////////////////////////////////

/**
 * Checks whether a string begins with a given prefix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param c The prefix character.
 * @param n The number of bytes to compare.
 * @return Returns \c true only if \a s begins with \a c.
 */
template<class StringType> inline
bool begins_with( utf8_string<StringType> const &s, char c ) {
  return ascii::begins_with( *s.get(), c );
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
bool begins_with( utf8_string<StringType> const &s, char const *ps,
                  typename StringType::size_type n ) {
  return ascii::begins_with( *s.get(), ps, n );
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
bool begins_with( utf8_string<StringType> const &s, char const *ps ) {
  return ascii::begins_with( *s.get(), ps );
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
bool begins_with( utf8_string<StringType> const &s,
                  PrefixStringType const &ps ) {
  return ascii::begins_with( *s.get(), ps.data(), ps.size() );
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
bool begins_with( StringType const &s,
                  utf8_string<PrefixStringType> const &ps ) {
  return ascii::begins_with( s, *ps.get() );
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
bool begins_with( utf8_string<StringType> const &s,
                  utf8_string<PrefixStringType> const &ps ) {
  return ascii::begins_with( *s.get(), *ps.get() );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param c The suffix character.
 * @param n The number of bytes to compare.
 * @return Returns \c true only if \a s ends with \a c.
 */
template<class StringType> inline
bool ends_with( utf8_string<StringType> const &s, char c ) {
  return ascii::ends_with( *s.get(), c );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param ps The suffix string.
 * @param n The number of bytes to compare.
 * @return Returns \c true only if \a s ends with \a ps.
 */
template<class StringType> inline
bool ends_with( utf8_string<StringType> const &s, char const *ps,
                typename StringType::size_type n ) {
  return ascii::ends_with( *s.get(), ps, n );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @param s The string to check.
 * @param ps The suffix string.
 * @return Returns \c true only if \a s ends with \a ps.
 */
template<class StringType> inline
bool ends_with( utf8_string<StringType> const &s, char const *ps ) {
  return ascii::ends_with( *s.get(), ps );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @tparam SuffixStringType The suffix string type.
 * @param s The string to check.
 * @param ps The suffix string.
 * @return Returns \c true only if \a s ends with \a ps.
 */
template<class StringType,class SuffixStringType> inline
bool ends_with( utf8_string<StringType> const &s,
                SuffixStringType const &ps ) {
  return ascii::ends_with( *s.get(), ps.data(), ps.size() );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @tparam SuffixStringType The suffix string type.
 * @param s The string to check.
 * @param ps The suffix string.
 * @return Returns \c true only if \a s ends with \a ps.
 */
template<class StringType,class SuffixStringType> inline
bool ends_with( StringType const &s,
                utf8_string<SuffixStringType> const &ps ) {
  return ascii::ends_with( s, *ps.get() );
}

/**
 * Checks whether a string ends with a given suffix.
 *
 * @tparam StringType The string type.
 * @tparam SuffixStringType The suffix string type.
 * @param s The string to check.
 * @param ps The suffix string.
 * @return Returns \c true only if \a s ends with \a ps.
 */
template<class StringType,class SuffixStringType> inline
bool ends_with( utf8_string<StringType> const &s,
                utf8_string<SuffixStringType> const &ps ) {
  return ascii::ends_with( *s.get(), *ps.get() );
}

////////// Case conversion ////////////////////////////////////////////////////

/**
 * Converts a string to lower-case.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are overwritten.
 */
template<class InputStringType,class OutputStringType>
void to_lower( InputStringType const &in, OutputStringType *out );

/**
 * Converts a string to lower-case.
 *
 * @tparam StringType The input string type.
 * @param s The string.
 */
template<class StringType> inline
void to_lower( StringType &s ) {
  StringType temp;
  to_lower( s, &temp );
  s = temp;
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
template<class InputStringType,class OutputStringType>
void to_upper( InputStringType const &in, OutputStringType *out );

/**
 * Converts a string to upper-case.
 *
 * @tparam StringType The input string type.
 * @param s The string.
 */
template<class StringType> inline
void to_upper( StringType &s ) {
  StringType temp;
  to_upper( s, &temp );
  s = temp;
}

////////// Code-point functions ///////////////////////////////////////////////

/**
 * Appends a sequence of Unicode code-points to a string.
 *
 * @tparam InputIterator The iterator type.
 * @param i The begining iterator.
 * @param j The ending iterator.
 * @param s A pointer to the string to be appended to.
 */
template<class InputIterator,class StringType> inline
void append_codepoints( InputIterator i, InputIterator j, StringType *s ) {
  typename utf8_stringify<StringType>::type u( *s );
  std::copy( i, j, std::back_inserter( u ) );
}

/**
 * Converts a string to a sequence of Uncode code-points.
 *
 * @tparam StringType The type of string.
 * @tparam ContainerType The type of STL container to put the codepoint values.
 * @param s The string to get the codepoints for.
 * @param c A pointer to the container to put the codepoint values.  The
 * containers contents are overwritten.
 */
template<class StringType,class ContainerType> inline
void to_codepoints( StringType const &s, ContainerType *c ) {
  typename utf8_stringify<StringType const>::type const u( s );
  std::copy( u.begin(), u.end(), std::back_inserter( *c ) );
}

////////// Encoding conversion ////////////////////////////////////////////////

#ifndef ZORBA_NO_UNICODE

/**
 * Converts a unicode::char_type array into a UTF-8 encoded string.
 *
 * @param in The Unicode characters to convert.
 * @param in_len The number of unicode characters (not bytes) to convert.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of bytes (not characters) of
 * the UTF-8 string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
ZORBA_DLL_PUBLIC
bool to_string( unicode::char_type const *in, unicode::size_type in_len,
                storage_type **out, size_type *out_len = nullptr );

/**
 * Converts a unicode::char_type array into a UTF-8 encoded string.
 *
 * @param in The Unicode characters to convert.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of bytes (not characters) of
 * the UTF-8 string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool to_string( unicode::char_type const *in, storage_type **out,
                       size_type *out_len = nullptr ) {
  return to_string( in, u_strlen( in ), out, out_len );
}

/**
 * Converts a unicode::string into a UTF-8 encoded string.
 *
 * @param in The unicode::string to convert.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of bytes (not characters) of
 * the UTF-8 string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool to_string( unicode::string const &in, storage_type **out,
                       size_type *out_len = nullptr ) {
  return to_string( in.getBuffer(), in.length(), out, out_len );
}

/**
 * Converts a unicode::char_type array into a UTF-8 encoded string.
 *
 * @param in The Unicode characters to convert.
 * @param in_len The number of unicode characters to convert.
 * @param out A pointer to the result string.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType>
bool to_string( unicode::char_type const *in, size_type in_len,
                StringType *out );

/**
 * Converts a unicode::char_type array into a UTF-8 encoded string.
 *
 * @param in The Unicode characters to convert.
 * @param out A pointer to the result string.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType> inline
bool to_string( unicode::char_type const *in, StringType *out ) {
  return to_string( in, u_strlen( in ), out );
}

#endif /* ZORBA_NO_UNICODE */

/**
 * Converts a unicode::string into a UTF-8 encoded string.
 *
 * @param in The unicode::string to convert.
 * @param out A pointer to the result string.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType> inline
bool to_string( unicode::string const &in, StringType *out ) {
#ifndef ZORBA_NO_UNICODE
  return to_string( in.getBuffer(), in.length(), out );
#else
  *out = in.c_str();
  return true;
#endif /* ZORBA_NO_UNICODE */
}

#ifndef ZORBA_NO_UNICODE

//
// On Windows, UChar == wchar_t, so these functions would multiply define those
// previously.
//
#ifndef WIN32

/**
 * Converts a wide-character string into a UTF-8 encoded string.
 *
 * @param in The wide-character string to convert.
 * @param in_len The length of the unicode::string.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of bytes (not characters) of
 * the UTF-8 string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
ZORBA_DLL_PUBLIC
bool to_string( wchar_t const *in, size_type in_len, storage_type **out,
                size_type *out_len = nullptr );

/**
 * Converts a wide-character string into a UTF-8 encoded string.
 *
 * @param in The wide-character string to convert.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of bytes (not characters) of
 * the UTF-8 string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool to_string( wchar_t const *in, storage_type **out,
                       size_type *out_len = nullptr ) {
  return to_string( in, std::wcslen( in ), out, out_len );
}

/**
 * Converts a wide-character string into a UTF-8 encoded string.
 *
 * @tparam StringType The type of the result string.
 * @param in The wide-character string to convert.
 * @param in_len The length of the unicode::string.
 * @param out A pointer to the result string.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType>
bool to_string( wchar_t const *in, size_type in_len, StringType *out );

/**
 * Converts a wide-character string into a UTF-8 encoded string.
 *
 * @tparam StringType The type of the result string.
 * @param in The wide-character string to convert.
 * @param out A pointer to the result string.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType> inline
bool to_string( wchar_t const *in, StringType *out ) {
  return to_string( in, std::wcslen( in ), out );
}

#endif /* WIN32 */

/**
 * Converts a wide-character string into a UTF-8 encoded string.
 *
 * @tparam StringType The type of the result string.
 * @param in The wide-character string to convert.
 * @param out A pointer to the result string.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType> inline
bool to_string( std::wstring const &in, StringType *out ) {
  return to_string( in.data(), in.size(), out );
}

/**
 * Converts a UTF-8 encoded string to a wchar_t array.
 *
 * @param in The UTF-8 encoded string to convert.
 * @param in_len The number of bytes (not characters) of \a in.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of characters (not bytes) of
 * the wchar_t string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
ZORBA_DLL_PUBLIC
bool to_wchar_t( storage_type const *in, size_type in_len, wchar_t **out,
                 unicode::size_type *out_len );

/**
 * Converts a UTF-8 encoded string to a wchar_t array.
 *
 * @param in The UTF-8 encoded string to convert.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of characters (not bytes) of
 * the \c wchar_t string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool to_wchar_t( storage_type const *in, wchar_t **out,
                        unicode::size_type *out_len ) {
  return to_wchar_t( in, std::strlen( in ), out, out_len );
}

/**
 * Converts a UTF-8 encoded string to a wchar_t array.
 *
 * @tparam StringType The string type.
 * @param in The UTF-8 encoded string to convert.
 * @param out A pointer to a pointer to the starting location for the result.
 * It is the caller's responsibility to deallocate this.
 * @param out_len If not \c nullptr, the number of characters (not bytes) of
 * the \c wchar_t string are put here.
 * @return Returns \c true only if the conversion succeeded.
 */
template<class StringType> inline
bool to_wchar_t( StringType const &in, wchar_t **out,
                 unicode::size_type *out_len ) {
  return to_wchar_t( in.data(), in.size(), out, out_len );
}

#endif /* ZORBA_NO_UNICODE */

////////// HTML URI ///////////////////////////////////////////////////////////

/**
 * A %back_html_uri_insert_iterator can be used to append characters to a string
 * escaping all non-printing ASCII characters.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_html_uri_insert_iterator :
  public
    ztd::back_insert_iterator_base<
      StringType, back_html_uri_insert_iterator<StringType>
    >
{
  typedef ztd::back_insert_iterator_base<
    StringType, back_html_uri_insert_iterator<StringType>
  > base_type;
public:
  typedef typename base_type::container_type container_type;
  typedef typename StringType::value_type value_type;

  /**
   * Constructs a %back_html_uri_insert_iterator.
   *
   * @param s The string to append to.
   */
  explicit back_html_uri_insert_iterator( StringType &s ) : base_type( s ) {
    buf_[0] = '%';
  }

  back_html_uri_insert_iterator& operator=( value_type c );

private:
  char buf_[3]; // %xx -- no need for null at end
};

/**
 * This is a convenience function to create a back_html_uri_insert_iterator.
 *
 * @tparam StringType The string type.
 * @param out The output string.
 */
template<class StringType> inline back_html_uri_insert_iterator<StringType>
back_html_uri_inserter( StringType &out ) {
  return back_html_uri_insert_iterator<StringType>( out );
}

/**
 * Escapes all non-printable ASCII characters
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output String type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).
 */
template<class InputStringType,class OutputStringType> inline
void to_html_uri( InputStringType const &in, OutputStringType *out ) {
  typename utf8_stringify<InputStringType const>::type const u_in( in );
  typename utf8_stringify<OutputStringType>::type u_out( *out );
  std::copy( u_in.begin(), u_in.end(), back_html_uri_inserter( u_out ) );
}

/**
 * Escapes all non-printable ASCII characters
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void to_html_uri( StringType &s ) {
  StringType temp;
  to_html_uri( s, &temp );
  s = temp;
}

////////// IRI ////////////////////////////////////////////////////////////////

/**
 * A %back_iri_insert_iterator can be used to append characters to a string
 * ensuring that illegal characters in an IRI.  See RFC 3987.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_iri_insert_iterator :
  public
    ztd::back_insert_iterator_base<
      StringType, back_iri_insert_iterator<StringType>
    >
{
  typedef ztd::back_insert_iterator_base<
    StringType, back_iri_insert_iterator<StringType>
  > base_type;
public:
  typedef typename base_type::container_type container_type;
  typedef typename StringType::value_type value_type;

  /**
   * Constructs a %back_iri_insert_iterator.
   *
   * @param s The string to append to.
   */
  explicit back_iri_insert_iterator( StringType &s ) : base_type( s ) {
    buf_[0] = '%';
  }

  back_iri_insert_iterator& operator=( value_type c );

private:
  char buf_[3]; // %xx -- no need for null at end
};

/**
 * This is a convenience function to create a back_iri_insert_iterator.
 *
 * @tparam StringType The string type.
 * @param out The output string.
 */
template<class StringType> inline back_iri_insert_iterator<StringType>
back_iri_inserter( StringType &out ) {
  return back_iri_insert_iterator<StringType>( out );
}

/**
 * Converts an IRI to a URI.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output String type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).
 * See RFC 3987.
 */
template<class InputStringType,class OutputStringType> inline
void iri_to_uri( InputStringType const &in, OutputStringType *out ) {
  typename utf8_stringify<InputStringType const>::type const u_in( in );
  typename utf8_stringify<OutputStringType>::type u_out( *out );
  std::copy( u_in.begin(), u_in.end(), back_iri_inserter( u_out ) );
}

/**
 * Converts an IRI to a URI.
 *
 * @tparam StringType The string type.
 * @param s The string.
 * See RFC 3987.
 */
template<class StringType> inline
void iri_to_uri( StringType &s ) {
  StringType temp;
  iri_to_uri( s, &temp );
  s = temp;
}

////////// Unicode normalization //////////////////////////////////////////////

#ifndef ZORBA_NO_UNICODE
/**
 * Normalizes the Unicode characters in the string.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output String type.
 * @param in The input string.
 * @param out The output String (which may be the same as \a in).
 */
template<class InputStringType,class OutputStringType>
bool normalize( InputStringType const &in, unicode::normalization::type n,
                OutputStringType *out );
#endif /* ZORBA_NO_UNICODE */

////////// Whitespace /////////////////////////////////////////////////////////

/**
 * Converts sequences of one or more whitespace characters to a single space.
 * Additionally, all leading and trailing whitespace is removed.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string.
 */
template<class InputStringType,class OutputStringType> inline
void normalize_whitespace( utf8_string<InputStringType> const &in,
                           utf8_string<OutputStringType> *out ) {
  ascii::normalize_whitespace( *in.get(), out->get() );
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
void trim_whitespace( utf8_string<InputStringType> const &in,
                      utf8_string<OutputStringType> *out ) {
  ascii::trim_whitespace( *in.get(), out->get() );
}

/**
 * Removes all leading and trailing whitespace.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void trim_whitespace( utf8_string<StringType> &s ) {
  ascii::trim_whitespace( *s.get() );
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
  typename utf8_stringify<InputStringType const>::type const u_in( in );
  typename utf8_stringify<OutputStringType>::type u_out( *out );
  std::reverse_copy( u_in.begin(), u_in.end(), std::back_inserter( u_out ) );
}

/**
 * Strips all diacritical marks from all characters converting them to their
 * closest ASCII equivalents.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string.
 */
template<class InputStringType,class OutputStringType>
void strip_diacritics( InputStringType const &in, OutputStringType *out );

/**
 *
 */
template<class StringType1,class StringType2> inline
int compare(const StringType1 &s1, const StringType2 &s2,
            const XQPCollator* collation)
{
#ifndef ZORBA_NO_UNICODE
  if (collation == NULL || collation->doMemCmp())
    return s1.compare(s2);

  unicode::string us1;
  unicode::string us2;

  unicode::to_string(s1, &us1);
  unicode::to_string(s2, &us2);

  return static_cast<Collator*>( collation->getCollator() )->compare(us1, us2);
#else
  return s1.compare(s2);
#endif /* ZORBA_NO_UNICODE */
}


/**
 *
 */
template<class StringType> inline
uint32_t hash(const StringType& s, const XQPCollator* collation = NULL) {
#ifndef ZORBA_NO_UNICODE
  if (!collation || collation->doMemCmp()) {
#endif /* ZORBA_NO_UNICODE */
    const char* str = s.data();
    ulong len = (ulong)s.size();
    uint32_t hash = 5381;
    ulong i = 0;
    int c;
    while (i < len && (c = *str++))
    {
      hash = ((hash << 5) + hash) + c;
      ++i;
    }
    return hash;
#ifndef ZORBA_NO_UNICODE
  }
#endif /* ZORBA_NO_UNICODE */

#ifndef ZORBA_NO_UNICODE
  CollationKey collKey;
  UErrorCode status = U_ZERO_ERROR;

  unicode::string uni_s;
  unicode::to_string(s, &uni_s);

  static_cast<Collator*>(collation->getCollator())->
  getCollationKey(uni_s, collKey, status);

  if(U_FAILURE(status))
  {
    assert(false);
  }

  return collKey.hashCode();
#else
  ZORBA_ASSERT(false);
#endif /* ZORBA_NO_UNICODE */
}

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba

#include "utf8_util.tcc"

#endif /* ZORBA_UTF8_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
