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

#ifndef ZORBA_UNICODE_UTIL_H
#define ZORBA_UNICODE_UTIL_H

#include <zorba/config.h>

#ifndef ZORBA_NO_UNICODE

#include <cctype>
#include <cstring>
#include <cwchar>
#include <unicode/regex.h>
#include <unicode/unistr.h>

namespace zorba {
namespace unicode {

////////// types //////////////////////////////////////////////////////////////

/**
 * The character type that can hold a Unicode character encoded in UTF-16.  Do
 * not assume that this is an unsigned type.
 */
typedef UChar char_type;

/**
 * The type type that can hold a Unicode code-point.  Do not assume that this
 * is an unsigned type.
 */
typedef UChar32 code_point;

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

/**
 * A Unicode string.
 */
typedef U_NAMESPACE_QUALIFIER UnicodeString string;

////////// functions //////////////////////////////////////////////////////////

/**
 * Tests whether the given character is lower-case.
 *
 * @param c The character.
 * @return Returns \c true only if the character is lower-case.
 */
ZORBA_DLL_PUBLIC
bool is_lower( code_point c );

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
 * Test whether the given character is invalid in an IRI.
 *
 * @param c The character.
 * @return Returns \c true only if the character is invalid in an IRI.
 * See RFC 3987.
 */
ZORBA_DLL_PUBLIC
bool is_invalid_in_iri( code_point c );

/**
 * Unicode version is isspace(3).
 *
 * @param c The code-point to check.
 * @return Returns \c true only if \a c is a whitespace character.
 */
inline bool is_space( code_point c ) {
  char ascii_c = static_cast<char>( c );
#ifdef WIN32
  // Windows' isspace() implementation crashes for non-ASCII characters.
  ascii_c &= 0x7F;
#endif
  return ascii_c == c && isspace( ascii_c );
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

/**
 * Checks whether the given code-point is valid.
 *
 * @param c The code-point to check.
 * @return Returns \c true only if the code-point is valid.
 */
template<class CodePointType>
inline bool is_valid( CodePointType c ) {
  return  c == 0x09 || c == 0x0A || c == 0x0D ||
          (c >= 0x00020 && c <= 0x00D7FF) ||
          (c >= 0x0E000 && c <= 0x00FFFD) ||
          (c >= 0x10000 && c <= 0x10FFFF);
}

/**
 * Parses an XML entity reference.
 *
 * @param s The C string pointing to the start of the entity reference.
 * @param c A pointer to the code-point result.
 * @return If successful, returns the number of characters parsed; otherwise
 * returns -1.
 */
ZORBA_DLL_PUBLIC
int parse_xml_entity( char const *s, code_point *c );

/**
 * Normalizes the given string.
 *
 * @param in The string to normalize.
 * @param out The normalized string.  It is overwritten.
 * @return Returns \c true only if the normalization succeeded.
 */
ZORBA_DLL_PUBLIC
bool normalize( string const &in, normalization::type n, string *out );

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
ZORBA_DLL_PUBLIC
bool to_string( char const *in, size_type in_len, string *out );

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
  return to_string( in, (size_type)std::wcslen( in ), out );
}

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
  return to_string( in.data(), zorba::unicode::size_type(in.size()), out );
}

////////// classes ////////////////////////////////////////////////////////////

/**
 * The %regex class wraps the underlying Unicode regular expression library.
 */
class ZORBA_DLL_PUBLIC regex {
public:
  regex() : matcher_( 0 ) { }

  ~regex() {
    delete matcher_;
  }

  ////////// compile pattern //////////////////////////////////////////////////

  bool compile( string const &pattern, char const *flags = "" );

  bool compile( char const *pattern, char const *flags = "" ) {
    string u_pattern;
    return to_string( pattern, &u_pattern ) && compile( u_pattern, flags );
  }

  template<class StringType>
  bool compile( StringType const &pattern, char const *flags = "" ) {
    string u_pattern;
    return to_string( pattern, &u_pattern ) && compile( u_pattern, flags );
  }

  template<class PatternStringType,class FlagsStringType>
  bool compile( PatternStringType const &pattern,
                FlagsStringType const &flags ) {
    return compile( pattern, flags.c_str() );
  }

  ////////// partial match ////////////////////////////////////////////////////

  bool match_part( string const &s );

  bool match_part( char const *s ) {
    string u_s;
    return to_string( s, &u_s ) && match_part( u_s );
  }

  bool match_part( char const *s, size_type s_len ) {
    string u_s;
    return to_string( s, s_len, &u_s ) && match_part( u_s );
  }

  template<class StringType>
  bool match_part( StringType const &s ) {
    string u_s;
    return to_string( s, &u_s ) && match_part( u_s );
  }

  ////////// partial match with substrings/tokenization ///////////////////////

  /**
   * Finds the next substring matching the pattern this %regex was compiled
   * with.
   *
   * @param s The Unicode string to attempt to match.
   * @param pos A pointer to the position to start looking for a match.  On
   * successful return, the position is updated to be one past the last
   * character of the match.
   * @param match A pointer to the string that is to be set to the substring
   * matching the pattern or NULL if the substring is not needed.
   * @return Returns \c true only if there is a match.
   */
  bool next_match( string const &s, size_type *pos, string *match ) {
    return next( re_is_match, s, pos, match, NULL );
  }

  /**
   * Finds the next substring matching the pattern this %regex was compiled
   * with.
   *
   * @param s The C string to attempt to match.
   * @param pos A pointer to the position to start looking for a match.  On
   * successful return, the position is updated to be one past the last
   * character of the match.
   * @param match A pointer to the string that is to be set to the substring
   * matching the pattern or NULL if the substring is not needed.
   * @return Returns \c true only if there is a match.
   */
  bool next_match( char const *s, size_type *pos, string *match ) {
    string u_s;
    return to_string( s, &u_s ) && next_match( u_s, pos, match );
  }

  /**
   * Finds the next substring matching the pattern this %regex was compiled
   * with.
   *
   * @param s The C string to attempt to match.
   * @param s_len The length of the C string.
   * @param pos A pointer to the position to start looking for a match.  On
   * successful return, the position is updated to be one past the last
   * character of the match.
   * @param match A pointer to the string that is to be set to the substring
   * matching the pattern or NULL if the substring is not needed.
   * @return Returns \c true only if there is a match.
   */
  bool next_match( char const *s, size_type s_len, size_type *pos,
                   string *match ) {
    string u_s;
    return to_string( s, s_len, &u_s ) && next_match( u_s, pos, match );
  }

  /**
   * Finds the next substring matching the pattern this %regex was compiled
   * with.
   *
   * @tparam StringType The string type.
   * @param s The string to attempt to match.
   * @param pos A pointer to the position to start looking for a match.  On
   * successful return, the position is updated to be one past the last
   * character of the match.
   * @param match A pointer to the string that is to be set to the substring
   * matching the pattern or NULL if the substring is not needed.
   * @return Returns \c true only if there is a match.
   */
  template<class StringType>
  bool next_match( StringType const &s, size_type *pos, string *match ) {
    string u_s;
    return to_string( s, &u_s ) && next_match( u_s, pos, match );
  }

  /**
   * Finds the next substring separated by the pattern this %regex was compiled
   * with (similar to <code>strtok</code>(3)).
   *
   * @param s The Unicode string to attempt to find a token in.
   * @param pos A pointer to the position to start looking for a token.  On
   * successful return, the position is updated to be one past the last
   * character of the token.
   * @param token A pointer to the string that is to be set to the substring
   * separated by the pattern or NULL if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or NULL if this is not needed.  If not NULL, it is
   * set to \c false either if there is no token or the token is the final
   * token after the last separator; it is set to \c true only for non-last
   * tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( string const &s, size_type *pos, string *token,
                   bool *matched = NULL ) {
    return next( re_is_separator, s, pos, token, matched );
  }

  /**
   * Finds the next substring separated by the pattern this %regex was compiled
   * with (similar to <code>strtok</code>(3)).
   *
   * @param s The C string to attempt to find a token in.
   * @param pos A pointer to the position to start looking for a token.  On
   * successful return, the position is updated to be one past the last
   * character of the token.
   * @param token A pointer to the string that is to be set to the substring
   * separated by the pattern or NULL if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or NULL if this is not needed.  If not NULL, it is
   * set to \c false either if there is no token or the token is the final
   * token after the last separator; it is set to \c true only for non-last
   * tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( char const *s, size_type *pos, string *token,
                   bool *matched = NULL ) {
    string u_s;
    return to_string( s, &u_s ) && next_token( u_s, pos, token, matched );
  }

  /**
   * Finds the next substring separated by the pattern this %regex was compiled
   * with (similar to <code>strtok</code>(3)).
   *
   * @param s The C string to attempt to find a token in.
   * @param s_len The length of the C string.
   * @param pos A pointer to the position to start looking for a token.  On
   * successful return, the position is updated to be one past the last
   * character of the token.
   * @param token A pointer to the string that is to be set to the substring
   * separated by the pattern or NULL if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or NULL if this is not needed.  If not NULL, it is
   * set to \c false either if there is no token or the token is the final
   * token after the last separator; it is set to \c true only for non-last
   * tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( char const *s, size_type s_len, size_type *pos,
                   string *token, bool *matched = NULL ) {
    string u_s;
    return  to_string( s, s_len, &u_s ) &&
            next_token( u_s, pos, token, matched );
  }

  /**
   * Finds the next substring separated by the pattern this %regex was compiled
   * with (similar to <code>strtok</code>(3)).
   *
   * @tparam StringType The string type.
   * @param s The string to attempt to find a token in.
   * @param pos A pointer to the position to start looking for a token.  On
   * successful return, the position is updated to be one past the last
   * character of the token.
   * @param token A pointer to the string that is to be set to the substring
   * separated by the pattern or NULL if the substring is not needed.
   * @return Returns \c true only if there is a token.
   */
  template<class StringType>
  bool next_token( StringType const &s, size_type *pos, string *token,
                   bool *matched = NULL ) {
    string u_s;
    return to_string( s, &u_s ) && next_token( u_s, pos, token, matched );
  }

  ////////// whole match //////////////////////////////////////////////////////

  bool match_whole( string const &s );

  bool match_whole( char const *s ) {
    string u_s;
    return to_string( s, &u_s ) && match_whole( u_s );
  }

  bool match_whole( char const *s, size_type s_len ) {
    string u_s;
    return to_string( s, s_len, &u_s ) && match_whole( u_s );
  }

  template<class StringType>
  bool match_whole( StringType const &s ) {
    string u_s;
    return to_string( s, &u_s ) && match_whole( u_s );
  }

  ////////// replacement //////////////////////////////////////////////////////

  /**
   * Replaces all occurrences of substrings that match the pattern this %regex
   * was compiled with.
   *
   * @param in The input string.
   * @param replacement The replacement string.
   * @param out The output string.
   * @param Returns \c true only if at least one replacement was made.
   */
  bool replace_all( string const &in, string const &replacement, string *out );

  /**
   * Replaces all occurrences of substrings that match the pattern this %regex
   * was compiled with.
   *
   * @param in The input string.
   * @param replacement The replacement string.
   * @param out The output string.
   * @param Returns \c true only if at least one replacement was made.
   */
  bool replace_all( char const *in, char const *replacement, string *out );

  /**
   * Replaces all occurrences of substrings that match the pattern this %regex
   * was compiled with.
   *
   * @tparam InputStringType The input string type.
   * @tparam ReplacementStringType The replacement string type.
   * @param in The input string.
   * @param replacement The replacement string.
   * @param out The output string.
   * @param Returns \c true only if at least one replacement was made.
   */
  template<class InputStringType,class ReplacementStringType>
  bool replace_all( InputStringType const &in,
                    ReplacementStringType const &replacement,
                    string *out ) {
    return replace_all( in.c_str(), replacement.c_str(), out );
  }

private:
  U_NAMESPACE_QUALIFIER RegexMatcher *matcher_;

  enum re_type_t {
    re_is_match,                        // RE specifies what to match
    re_is_separator                     // RE specifies what separates matches
  };

  bool next( re_type_t re_type, string const &s, size_type *pos,
             string *substring, bool *matched );

  // forbid
  regex( regex const& );
  regex& operator=( regex const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace unicode
} // namespace zorba

#endif /* ZORBA_NO_UNICODE */

#endif /* ZORBA_UNICODE_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
