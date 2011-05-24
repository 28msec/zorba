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

#ifndef ZORBA_XQUERY_FUNCTIONS_API_H
#define ZORBA_XQUERY_FUNCTIONS_API_H

#include <zorba/config.h>

namespace zorba {

class String;

namespace fn {

////////// 5.4 Functions on string values /////////////////////////////////////

/**
 * Translates every character to its upper-case correspondent as defined in the
 * appropriate case mappings section in the Unicode standard The Unicode
 * Standard.
 * 
 * Every lower-case character that does not have an upper-case correspondent,
 * as well as every upper-case character, is included in the returned value in
 * its original form.
 *
 * @param arg The string to translate.
 * @return \a arg translated to upper-case.
 */
ZORBA_DLL_PUBLIC
String upper_case( String const &arg );

/**
 * Translates every character to its lower-case correspondent as defined in the
 * appropriate case mappings section in the Unicode standard The Unicode
 * Standard.
 * 
 * Every upper-case character that does not have a lower-case correspondent, as
 * well as every lower-case character, is included in the returned value in its
 * original form.
 *
 * @param arg The string to translate.
 * @return \a arg translated to lower-case.
 */
ZORBA_DLL_PUBLIC
String lower_case( String const &arg );

////////// 5.5 Functions based on substring matching //////////////////////////

/**
 * Tests whether or not the value of \a arg1 ends with a sequence of
 * collation units that provides a match to the collation units of \a arg2.
 *
 * @param arg1 The string to test.
 * @param arg2 The substring.
 * @return \c true only if \a arg1 ends with \a arg2 or \a arg2 is the
 * zero-length string.
 */
ZORBA_DLL_PUBLIC
bool ends_with( String const &arg1, String const &arg2 );

/**
 * Tests whether or not the value of \a arg1 ends with a sequence of
 * collation units that provides a match to the collation units of \a arg2.
 *
 * @param arg1 The string to test.
 * @param arg2 The substring.
 * @return \c true only if \a arg1 ends with \a arg2 or \a arg2 is the
 * zero-length string.
 */
ZORBA_DLL_PUBLIC
bool ends_with( String const &arg1, char const *arg2 );

/**
 * Tests whether or not the value of \a arg1 starts with a sequence of
 * collation units that provides a match to the collation units of \a arg2.
 *
 * @param arg1 The string to test.
 * @param arg2 The substring.
 * @return \c true only if \a arg1 starts with \a arg2 or \a arg2 is the
 * zero-length string.
 */
ZORBA_DLL_PUBLIC
bool starts_with( String const &arg1, String const &arg2 );

/**
 * Tests whether or not the value of \a arg1 starts with a sequence of
 * collation units that provides a match to the collation units of \a arg2.
 *
 * @param arg1 The string to test.
 * @param arg2 The substring.
 * @return \c true only if \a arg1 starts with \a arg2 or \a arg2 is the
 * zero-length string.
 */
ZORBA_DLL_PUBLIC
bool starts_with( String const &arg1, char const *arg2 );

//////// 6 Functions that manipulate URIs /////////////////////////////////////

/**
 * Encodes reserved characters in an xs:string that is intended to be used in
 * the path segment of a URI.  It is invertible but not idempotent.
 * 
 * This function applies the URI escaping rules defined in section 2 of [RFC
 * 3986] to the xs:string supplied as \a uri_part.  The effect of the function
 * is to escape reserved characters. Each such character in the string is
 * replaced with its percent-encoded form as described in [RFC 3986].
 *
 * All characters are escaped except those identified as "unreserved" by [RFC
 * 3986], that is the upper- and lower-case letters A-Z, the digits 0-9,
 * HYPHEN-MINUS ("-"), LOW LINE ("_"), FULL STOP ".", and TILDE "~".
 *
 * @param uri_part The URI to be encoded.
 * @return the encoded string.
 */
ZORBA_DLL_PUBLIC
String encode_for_uri( String const &uri_part );

///////////////////////////////////////////////////////////////////////////////

} // namespace fn
} // namespace zorba

#endif /* ZORBA_XQUERY_FUNCTIONS_API_H */
/* vim:set et sw=2 ts=2: */
