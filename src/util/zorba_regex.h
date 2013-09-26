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
#ifndef ZORBA_ZORBA_REGEX_H
#define ZORBA_ZORBA_REGEX_H

#include <zorba/config.h>

#ifdef ZORBA_NO_ICU

#include <zorba/internal/cxx_util.h>

#include "unicode_util.h"
#include "zorba_regex_engine.h"
#include "zorbatypes/zstring.h"

namespace zorba {

/**
 * Converts an XQuery regular expression to the form used by the regular
 * expression library Zorba is using (here regex_engine).
 *
 * @param xq_re The XQuery regular expression.
 * @param lib_re A pointer to the resuling library regular expression.
 * @param flags The flags to use, if any.
 */
inline void convert_xquery_re( zstring const &xq_re, zstring *lib_re,
                               char const *flags = "" ) {
  *lib_re = xq_re;                      // no converseion neeeded
}

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
  regex() : regex_matcher( nullptr ) { }

  /**
   * Destroys a %regex.
   */
  ~regex() {
    delete regex_matcher;
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
  void compile( char const *pattern, char const *flags = "" ) ;

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
    compile( pattern.c_str(), flags );
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
    compile( pattern.c_str(), flags.c_str() );
  }

  ////////// partial match ////////////////////////////////////////////////////

  /**
   * Checks whether the given string partially patches the previosuly compiled
   * regular expression.  A "partial match" means that at least part of the
   * string matches, e.g., "b" matches the regular expression "aba".
   *
   * @param s The null-terminated UTF-8 C string to attempt to match.
   * @return Returns \c true only if the string partially matches.
   */
  bool match_part( char const *s );

  /**
   * Checks whether the given string partially patches the previosuly compiled
   * regular expression.  A "partial match" means that at least part of the
   * string matches, e.g., "b" matches the regular expression "aba".
   *
   * @param s The UTF-8 C string to attempt to match.
   * @param s_len The length of the string in bytes.
   * @return Returns \c true only if the string partially matches.
   */
  bool match_part( char const *s, size_type s_len )
  {
    zstring scut(s, s_len);
    return match_part(scut.c_str());
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
    return match_part(s.c_str());
  }

  ////////// partial match with substrings/tokenization ///////////////////////

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
  bool next_match( char const *s, size_type *pos, zstring *match );

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
                   zstring *match ) 
  {
    zstring scut(s, s_len);
    return next_match(scut.c_str(), pos, match);
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
  bool next_match( StringType const &s, size_type *pos, zstring *match ) {
    return next_match(s.c_str(), pos, match);
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
   * separated by the pattern or \c NULL if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or \c NULL if this is not needed.  If not \c NULL,
   * it is set to \c false either if there is no token or the token is the
   * final token after the last separator; it is set to \c true only for
   * non-last tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( char const *s, size_type *pos, zstring *token,
                   bool *matched = NULL );

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
   * separated by the pattern or \c NULL if the substring is not needed.
   * @param matched A pointer to a \c bool to indicate whether the pattern
   * matched for the token or \c NULL if this is not needed.  If not \c NULL,
   * it is set to \c false either if there is no token or the token is the
   * final token after the last separator; it is set to \c true only for
   * non-last tokens.
   * @return Returns \c true only if there is a token.
   */
  bool next_token( char const *s, size_type s_len, size_type *pos,
                   zstring *token, bool *matched = NULL )
  {
    zstring scut(s, s_len);
    return next_token(scut.c_str(), pos, token, matched);
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
   * separated by the pattern or \c NULL if the substring is not needed.
   * @return Returns \c true only if there is a token.
   */
  template<class StringType>
  bool next_token( StringType const &s, size_type *pos, zstring *token,
                   bool *matched = NULL ) {
    return next_token(s.c_str(), pos, token, matched);
  }

  ////////// whole match //////////////////////////////////////////////////////

  /**
   * Checks whether the given string completely patches the previosuly compiled
   * regular expression.  A "complete match" means that the entire string must
   * match the regular expression as if the pattern were "^pattern$".
   *
   * @param s The null-terminated UTF-8 C string to attempt to match.
   * @return Returns \c true only if the string completely matches.
   */
  bool match_whole( char const *s );

  /**
   * Checks whether the given string completely patches the previosuly compiled
   * regular expression.  A "complete match" means that the entire string must
   * match the regular expression as if the pattern were "^pattern$".
   *
   * @param s The UTF-8 C string to attempt to match.
   * @param s_len The length of the string in bytes.
   * @return Returns \c true only if the string completely matches.
   */
  bool match_whole( char const *s, size_type s_len ) 
  {
    zstring scut(s, s_len);
    return match_whole(scut.c_str());
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
    return match_whole(s.c_str());
  }

  ////////// replacement //////////////////////////////////////////////////////

  /**
   * Replaces all occurrences of substrings that match the pattern this %regex
   * was compiled with.
   *
   * @param in The UTF-8 input string.
   * @param replacement The replacement string.
   * @param out The output string.
   * @param Returns \c true only if at least one replacement was made.
   */
  bool replace_all( char const *in, char const *replacement, zstring *out );

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
                    zstring *out ) {
    return replace_all( in.c_str(), replacement.c_str(), out );
  }


  /**
   * Set the string to work on, without doing matching yet.
   *
   * @param in The UTF-8 input string.
   * @param len the size in bytes.
   */
  void set_string( const char* in, size_type len );

  /**
   * Find the next match in string set by set_string().
   * After finding a match, call get_group_start() and get_group_end() to get the position in the string.
   *
   * @param reachedEnd returns true if the end of string was reached while doing the match.
   */
  bool next_match( bool *reachedEnd );

  /**
   * Get the number of parenthesized groups in the regular expression.
   * This number depends only on regular expression, and not on the working string.
   *
   * @return the number of parenthesized groups in the regular expression
   */
  int get_group_count() const;

  /**
   * Get the start position of the matched group.
   * If groupId is zero, then the start and end position of the whole match is returned.
   * If groupId is non-zero, then the start and end position of that group is returned.
   * If that group has not been matched, false is returned.
   *
   * @param start to return start position in bytes
   * @param end to return end position in bytes
   * @param groupId the id of the group, either zero for the entire regex,
   *  or [1 .. group_count] for that specific group
   * @return true if that group exists and has been matched
   */
  bool get_group_start_end( int *start, int *end, int groupId ) const;

private:
  regex_engine::CRegexXQuery_regex  *regex_matcher;
  uint32_t    parsed_flags;

  zstring s_in_;
  int     m_pos;
  int     m_match_pos;
  int     m_matched_len;

  uint32_t parse_regex_flags(const char* flag_cstr);

  // forbid
  regex( regex const& );
  regex& operator=( regex const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace unicode
} // namespace zorba

#endif /* ZORBA_NO_ICU */
#endif /* ZORBA_ZORBA_REGEX_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
