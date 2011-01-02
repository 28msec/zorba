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

#ifndef ZORBA_REGEX_H
#define ZORBA_REGEX_H

#ifndef ZORBA_NO_UNICODE
#include <unicode/regex.h>
#endif

#include "unicode_util.h"
#include "zorbatypes/zstring.h"

namespace zorba {

/**
 * Converts an XQuery regular expression to the form used by the regular
 * expression library Zorba is using (currently ICU).
 *
 * @param xq_re The XQuery regular expression.
 * @param lib_re A pointer to the resuling library regular expression.
 * @param flags The flags to use.
 */
void convert_xquery_re( zstring const &xq_re, zstring *lib_re,
                        char const *flags );

////////// classes ////////////////////////////////////////////////////////////

namespace unicode {

#ifndef ZORBA_NO_UNICODE

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

#endif /* ZORBA_NO_UNICODE */

} // namespace unicode

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_REGEX_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
