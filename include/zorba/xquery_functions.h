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

#include <memory>                       /* for auto_ptr */

#include <zorba/config.h>
#include <zorba/zorba_string.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * Provides a way for a function to return a sequence of some type \c T that
 * can be iterated over.
 *
 * @tparam T The type of sequence.
 */
template<typename T>
class Sequence {
public:
  typedef T value_type;

  struct iterator {
    virtual ~iterator() { }
    virtual bool next( value_type *result ) = 0;
  };

  /**
   * Constructs a new %Sequence.
   * This constructor is intended only for function implementors.
   *
   * @param i The iterator that provides the elements of the sequence.
   * Ownership of the iterator is taken.
   */
  Sequence( iterator *i ) : i_( i ) { } 

  /**
   * Copy constructs a %Sequence.
   *
   * @param s The %Sequence to copy from.  Note that it is a destructive copy
   * in that the sequence of \a s is 'i' moved.
   */
  Sequence( Sequence const &s ) : i_( s.i_ ) { }

  /**
   * Gets the next element in the sequence.
   *
   * @param result A pointer to the variable to receive the next element.
   * @return \c true only if there is a next element.
   */
  bool next( value_type *result ) {
    return i_->next( result );
  }

private:
  mutable std::auto_ptr<iterator> i_;

  // forbid
  Sequence& operator=( Sequence const& );
};

///////////////////////////////////////////////////////////////////////////////

namespace fn {

////////// 5.4 Functions on string values /////////////////////////////////////

/**
 * Translates every character to its upper-case correspondent as defined in the
 * appropriate case mappings section in the Unicode standard.
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
 * appropriate case mappings section in the Unicode standard.
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

////////// 7.6 String Functions that Use Pattern Matching /////////////////////

/**
 * This function breaks the \a input string into a sequence of strings,
 * treating any substring that matches \a pattern as a separator.  The
 * separators themselves are not returned.
 *
 * Performance note: if \a pattern is a simple string (not a regular expression
 * with meta-characers), it is more efficient to use String::find().
 *
 * @param input The string to be split into tokens.  If \a input is the empty
 * sequence, or if \a input is the zero-length string, the result is the empty
 * sequence.
 * @param pattern The regular expression.  If it matches a zero-length string,
 * then an error is raised: [err:FORX0003].
 * @param flags The regular expression flags, if any.
 * @return a sequence of strings for the tokens.
 */
ZORBA_DLL_PUBLIC
Sequence<String> tokenize( String const &input, char const *pattern,
                           char const *flags = "" );

/**
 * This function breaks the \a input string into a sequence of strings,
 * treating any substring that matches \a pattern as a separator.  The
 * separators themselves are not returned.
 *
 * Performance note: if \a pattern is a simple string (not a regular expression
 * with meta-characers), it is more efficient to use String::find().
 *
 * @param input The string to be split into tokens.  If \a input is the empty
 * sequence, or if \a input is the zero-length string, the result is the empty
 * sequence.
 * @param pattern The regular expression.  If it matches a zero-length string,
 * then an error is raised: [err:FORX0003].
 * @param flags The regular expression flags, if any.
 * @return a sequence of strings for the tokens.
 */
inline
Sequence<String> tokenize( String const &input, String const &pattern,
                           char const *flags = "" ) {
  return tokenize( input, pattern.c_str(), flags );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace fn
} // namespace zorba

#endif /* ZORBA_XQUERY_FUNCTIONS_API_H */
/* vim:set et sw=2 ts=2: */
