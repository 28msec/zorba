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
#ifndef ZORBA_ICU_REGEX_H
#define ZORBA_ICU_REGEX_H

#include <zorba/util/cxx_util.h>

#include "unicode_util.h"
#include "zorbatypes/zstring.h"

#ifndef ZORBA_NO_ICU

#include <unicode/regex.h>

namespace zorba {

/**
 * Converts an XQuery regular expression to the form used by the regular
 * expression library Zorba is using (currently ICU).
 *
 * @param xq_re The XQuery regular expression.
 * @param lib_re A pointer to the resuling library regular expression.
 * @param flags The flags to use, if any.
 */
void convert_xquery_re( zstring const &xq_re, zstring *lib_re,
                        char const *flags = "" );

////////// classes ////////////////////////////////////////////////////////////

namespace unicode {

/**
 * The %regex class wraps the underlying Unicode regular expression library.
 */
class regex {
public:
  /**
   * Constructs a %regex.
   */
  regex() : matcher_( nullptr ) { }

  /**
   * Destroys a %regex.
   */
  ~regex() {
    delete matcher_;
  }

  ////////// compile pattern //////////////////////////////////////////////////

  /**
   * Compiles a regular expression.  One of the compile functions must be
   * called prior to calling one of the match functions.
   *
   * @param pattern The regular expression pattern to compile.
   * @param flags The regular expression flags, if any.
   * @param throws err:FORX0002 if the regular expression is invalid.
   */
  void compile( char const *pattern, char const *flags = "" ) {
    string u_pattern;
    to_string( pattern, &u_pattern );
    compile( u_pattern, flags, pattern );
  }

  /**
   * Compiles a regular expression.  One of the compile functions must be
   * called prior to calling one of the match functions.
   *
   * @tparam StringType The pattern string type.
   * @param pattern The regular expression pattern to compile.
   * @param flags The regular expression flags, if any.
   * @param throws err:FORX0002 if the regular expression is invalid.
   */
  template<class StringType>
  void compile( StringType const &pattern, char const *flags = "" ) {
    string u_pattern;
    to_string( pattern, &u_pattern );
    compile( u_pattern, flags, pattern.c_str() );
  }

  /**
   * Compiles a regular expression.  One of the compile functions must be
   * called prior to calling one of the match functions.
   *
   * @tparam PatternStringType The pattern string type.
   * @tparam FlagsStringType The flags string type.
   * @param pattern The regular expression pattern to compile.
   * @param flags The regular expression flags, if any.
   * @param throws err:FORX0002 if the regular expression is invalid.
   */
  template<class PatternStringType,class FlagsStringType>
  void compile( PatternStringType const &pattern,
                FlagsStringType const &flags ) {
    compile( pattern, flags.c_str() );
  }

  ////////// partial match ////////////////////////////////////////////////////

  /**
   * Checks whether the given string partially patches the previosuly compiled
   * regular expression.  A "partial match" means that at least part of the
   * string matches, e.g., "b" matches the regular expression "aba".
   *
   * @param s The Unicode string to attempt to match.
   * @return Returns \c true only if the string partially matches.
   */
  bool match_part( string const &s );

  /**
   * Checks whether the given string partially patches the previosuly compiled
   * regular expression.  A "partial match" means that at least part of the
   * string matches, e.g., "b" matches the regular expression "aba".
   *
   * @param s The null-terminated UTF-8 C string to attempt to match.
   * @return Returns \c true only if the string partially matches.
   */
  bool match_part( char const *s ) {
    string u_s;
    return to_string( s, &u_s ) && match_part( u_s );
  }

  /**
   * Checks whether the given string partially patches the previosuly compiled
   * regular expression.  A "partial match" means that at least part of the
   * string matches, e.g., "b" matches the regular expression "aba".
   *
   * @param s The UTF-8 C string to attempt to match.
   * @param s_len The length of the string in bytes.
   * @return Returns \c true only if the string partially matches.
   */
  bool match_part( char const *s, size_type s_len ) {
    string u_s;
    return to_string( s, s_len, &u_s ) && match_part( u_s );
  }

  /**
   * Checks whether the given string partially patches the previosuly compiled
   * regular expression.  A "partial match" means that at least part of the
   * string matches, e.g., "b" matches the regular expression "aba".
   *
   * @tparam StringType The string type.
   * @param s The UTF-8 string to attempt to match.
   * @return Returns \c true only if the string partially matches.
   */
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
   * matching the pattern or \c nullptr if the substring is not needed.
   * @return Returns \c true only if there is a match.
   */
  bool next_match( string const &s, size_type *pos, string *match ) {
    return next( re_is_match, s, pos, match, nullptr );
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
   * matching the pattern or \c nullptr if the substring is not needed.
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
   * matching the pattern or \c nullptr if the substring is not needed.
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
   * matching the pattern or \c nullptr if the substring is not needed.
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
   * separated by the pattern or \c nullptr if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or \c nullptr if this is not needed.  If not \c
   * nullptr, it is set to \c false either if there is no token or the token is
   * the final token after the last separator; it is set to \c true only for
   * non-last tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( string const &s, size_type *pos, string *token,
                   bool *matched = nullptr ) {
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
   * separated by the pattern or \c nullptr if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or \c nullptr if this is not needed.  If not \c
   * nullptr, it is set to \c false either if there is no token or the token is
   * the final token after the last separator; it is set to \c true only for
   * non-last tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( char const *s, size_type *pos, string *token,
                   bool *matched = nullptr ) {
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
   * separated by the pattern or \c nullptr if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or \c nullptr if this is not needed.  If not \c
   * nullptr, it is set to \c false either if there is no token or the token is
   * the final token after the last separator; it is set to \c true only for
   * non-last tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( char const *s, size_type s_len, size_type *pos,
                   string *token, bool *matched = nullptr ) {
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
   * separated by the pattern or \c nullptr if the substring is not needed.
   * @return Returns \c true only if there is a token.
   */
  template<class StringType>
  bool next_token( StringType const &s, size_type *pos, string *token,
                   bool *matched = nullptr ) {
    string u_s;
    return to_string( s, &u_s ) && next_token( u_s, pos, token, matched );
  }

  ////////// whole match //////////////////////////////////////////////////////

  /**
   * Checks whether the given string completely patches the previosuly compiled
   * regular expression.  A "complete match" means that the entire string must
   * match the regular expression as if the pattern were "^pattern$".
   *
   * @param s The Unicode string to attempt to match.
   * @return Returns \c true only if the string completely matches.
   */
  bool match_whole( string const &s );

  /**
   * Checks whether the given string completely patches the previosuly compiled
   * regular expression.  A "complete match" means that the entire string must
   * match the regular expression as if the pattern were "^pattern$".
   *
   * @param s The null-terminated UTF-8 C string to attempt to match.
   * @return Returns \c true only if the string completely matches.
   */
  bool match_whole( char const *s ) {
    string u_s;
    return to_string( s, &u_s ) && match_whole( u_s );
  }

  /**
   * Checks whether the given string completely patches the previosuly compiled
   * regular expression.  A "complete match" means that the entire string must
   * match the regular expression as if the pattern were "^pattern$".
   *
   * @param s The UTF-8 C string to attempt to match.
   * @param s_len The length of the string in bytes.
   * @return Returns \c true only if the string completely matches.
   */
  bool match_whole( char const *s, size_type s_len ) {
    string u_s;
    return to_string( s, s_len, &u_s ) && match_whole( u_s );
  }

  /**
   * Checks whether the given string completely patches the previosuly compiled
   * regular expression.  A "complete match" means that the entire string must
   * match the regular expression as if the pattern were "^pattern$".
   *
   * @tparam StringType The string type.
   * @param s The UTF-8 string to attempt to match.
   * @return Returns \c true only if the string completely matches.
   */
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
   * @param in The Unicode input string.
   * @param replacement The replacement string.
   * @param out The Unicode output string.
   * @param Returns \c true only if at least one replacement was made.
   */
  bool replace_all( string const &in, string const &replacement, string *out );

  /**
   * Replaces all occurrences of substrings that match the pattern this %regex
   * was compiled with.
   *
   * @param in The UTF-8 input string.
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

  ////////// capturing subgroups //////////////////////////////////////////////

  /**
   * Gets the number of capturing subgroups in the regular expression.
   *
   * @return Returns said number.
   */
  int get_group_count();

  /**
   * Gets the start character position of the matched capturing subgroup.
   *
   * @param group The ID of the capturing subgroup [1-N] where N is the result
   * of get_group_count(), or 0 for the whole match.
   * @return Returns the start position (zero-based) or -1 if \a group didn't
   * match.
   */
  int get_group_start( int group = 0 );

  /**
   * Gets the end character position of the matched group.
   *
   * @param group The ID of the capturing subgroup [1-N] where N is the result
   * of get_group_count(), or 0 for the whole match.
   * @return Returns the end position (zero-based) or -1 if \a group didn't
   * match.
   */
  int get_group_end( int group = 0 );

  /**
   * Sets the string to work on, without doing matching yet.
   *
   * @param s The UTF-8 input string.
   * @param s_len The length of \a s in bytes.
   */
  void set_string( char const *s, size_type s_len );

  /**
   * Finds the next match in the string set by set_string().  After finding a
   * match, call get_group_start() and get_group_end() to get the position in
   * the string.
   *
   * @param reached_end If not \c nullptr, set to \c true only if the end of
   * string has been reached while doing the match.  (This works only for ICU
   * version 4.0 or later; for earlier versions, this is always set to
   * <code>true</code>.)
   * @return Returns \c true only if the next match was found.
   */
  bool next_match( bool *reached_end );

  /////////////////////////////////////////////////////////////////////////////

private:
  U_NAMESPACE_QUALIFIER RegexMatcher *matcher_;
  string s_;

  enum re_type_t {
    re_is_match,                        // RE specifies what to match
    re_is_separator                     // RE specifies what separates matches
  };

  void compile( string const &u_pattern, char const *flags,
                char const *pattern );

  bool next( re_type_t re_type, string const &s, size_type *pos,
             string *substring, bool *matched );

  // forbid
  regex( regex const& );
  regex& operator=( regex const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace unicode
} // namespace zorba

#endif /* ZORBA_NO_ICU */
#endif /* ZORBA_ICU_REGEX_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
