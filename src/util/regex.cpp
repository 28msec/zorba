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
#include "stdafx.h"

#include "regex.h"

#include <cstring>
#include <vector>

#include <zorba/diagnostic_list.h>
#include "diagnostics/xquery_exception.h"

#include "diagnostics/assert.h"
#include "diagnostics/dict.h"

#include "ascii_util.h"
#include "cxx_util.h"
#include "stl_util.h"

#ifndef ZORBA_NO_UNICODE
# include <unicode/uversion.h>
#endif /* ZORBA_NO_UNICODE */

using namespace std;
U_NAMESPACE_USE

#define bs_c "\\p{L}\\d.:\\p{M}-"       /* \c equivalent contents */
#define bs_i "\\p{L}_:"                 /* \i equivalent contents */

#ifndef U_ICU_VERSION_MAJOR_NUM
# error "U_ICU_VERSION_MAJOR_NUM not defined"
#endif /* U_ICU_VERSION_MAJOR_NUM */

#if U_ICU_VERSION_MAJOR_NUM < 4
//
// UREGEX_LITERAL is only in ICU since 4.0.  For earlier versions, we define it
// ourselves.  Of course it won't have any effect since it's not implemented in
// ICU, but we implement it ourselves anyway since, even though the constant is
// defined in 4.0, it's not actually implemented as of 4.4.
//
# define UREGEX_LITERAL 16
#endif /* U_ICU_VERSION_MAJOR_NUM */

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

typedef uint32_t icu_flags_t;

static icu_flags_t convert_xquery_flags( char const *xq_flags ) {
  icu_flags_t icu_flags = 0;
  if ( xq_flags ) {
    for ( char const *f = xq_flags; *f; ++f ) {
      switch ( *f ) {
        case 'i': icu_flags |= UREGEX_CASE_INSENSITIVE; break;
        case 'm': icu_flags |= UREGEX_MULTILINE       ; break;
        case 'q': icu_flags |= UREGEX_LITERAL         ; break;
        case 's': icu_flags |= UREGEX_DOTALL          ; break;
        case 'x': icu_flags |= UREGEX_COMMENTS        ; break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0001, ERROR_PARAMS( *f ) );
      }
    }
    if ( icu_flags & UREGEX_LITERAL ) {
      //
      // XQuery 3.0 F&O: 5.6.1.1: If [the 'q' flag] is used together with the
      // m, s, or x flag, that flag has no effect.
      //
      icu_flags &= ~(
        UREGEX_MULTILINE  | // 'm'
        UREGEX_DOTALL     | // 's'
        UREGEX_COMMENTS     // 'x'
      );
    }
  }
  return icu_flags;
}

#define INVALID_RE_EXCEPTION(...) \
  XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS( __VA_ARGS__ ) )

void convert_xquery_re( zstring const &xq_re, zstring *icu_re,
                        char const *xq_flags ) {
  icu_flags_t const icu_flags = convert_xquery_flags( xq_flags );
  bool const i_flag = (icu_flags & UREGEX_CASE_INSENSITIVE) != 0;
  bool const q_flag = (icu_flags & UREGEX_LITERAL) != 0;
  bool const x_flag = (icu_flags & UREGEX_COMMENTS) != 0;

  icu_re->clear();
  icu_re->reserve( xq_re.length() );    // approximate

  bool got_backslash = false;
  bool in_char_class = false;           // within [...]

  bool in_backref = false;              // '\'[1-9][0-9]*
  unsigned backref_no = 0;              // 1-based
  unsigned cur_cap_sub = 0;             // 1-based
  unsigned open_cap_subs = 0;

  // capture subgroup: true = open; false = closed
  vector<bool> cap_sub;                 // 0-based

  FOR_EACH( zstring, xq_c, xq_re ) {
    if ( got_backslash ) {
      if ( x_flag && !in_char_class && ascii::is_space( *xq_c ) ) {
        //
        // XQuery 3.0 F&O 5.6.1.1: If [the 'x' flag is] present, whitespace
        // characters ... in the regular expression are removed prior to
        // matching with one exception: whitespace characters within character
        // class expressions ... are not removed.
        //
        continue;
      }
      got_backslash = false;
      switch ( *xq_c ) {
        case 'c': // NameChar
          *icu_re += "[" bs_c "]";
          continue;
        case 'C': // ^\c
          *icu_re += "[^" bs_c "]";
          continue;
        case 'i': // initial NameChar
          *icu_re += "[" bs_i "]";
          continue;
        case 'I': // ^\i
          *icu_re += "[^" bs_i "]";
          continue;
        default:
          if ( ascii::is_digit( *xq_c ) ) {
            backref_no = *xq_c - '0';
            if ( !backref_no )          // \0 is illegal
              throw INVALID_RE_EXCEPTION( xq_re, ZED( BackRef0Illegal ) );
            if ( in_char_class ) {
              //
              // XQuery 3.0 F&O 5.6.1: Within a character class expression,
              // \ followed by a digit is invalid.
              //
              throw INVALID_RE_EXCEPTION(
                xq_re, ZED( BackRefIllegalInCharClass )
              );
            }
            in_backref = true;
          }
          *icu_re += '\\';
          break;
      }
    } else {
      if ( in_backref ) {
        //
        // XQuery 3.0 F&O 5.6.1: The construct \N where N is a single digit is
        // always recognized as a back-reference; if this is followed by
        // further digits, these digits are taken to be part of the back-
        // reference if and only if the resulting number NN is such that the
        // back-reference is preceded by NN or more unescaped opening
        // parentheses.
        //
        if ( cap_sub.size() > 9 && ascii::is_digit( *xq_c ) )
          backref_no = backref_no * 10 + (*xq_c - '0');
        else
          in_backref = false;
        //
        // XQuery 3.0 F&O 5.6.1: The regular expression is invalid if a back-
        // reference refers to a subexpression that does not exist or whose
        // closing right parenthesis occurs after the back-reference.
        //
        if ( backref_no > cap_sub.size() )
          throw INVALID_RE_EXCEPTION(
            xq_re, ZED( NonexistentBackRef_3 ), backref_no
          );
        if ( cap_sub[ backref_no - 1 ] )
          throw INVALID_RE_EXCEPTION(
            xq_re, ZED( NonClosedBackRef_3 ), backref_no
          );
      }
      switch ( *xq_c ) {
        case '\\':
          got_backslash = true;
          continue;
        case '(':
          if ( q_flag )
            *icu_re += '\\';
          else {
            ++open_cap_subs;
            cap_sub.push_back( true );
            cur_cap_sub = cap_sub.size();
          }
          break;
        case ')':
          if ( q_flag )
            *icu_re += '\\';
          else {
            if ( !open_cap_subs )
              throw INVALID_RE_EXCEPTION( xq_re, ZED( UnbalancedChar ), ')' );
            cap_sub[ --cur_cap_sub ] = false;
          }
          break;
        case '[':
          if ( q_flag )
            *icu_re += '\\';
          else
            in_char_class = true;
          break;
        case ']':
          if ( q_flag )
            *icu_re += '\\';
          else
            in_char_class = false;
          break;
        default:
          if ( x_flag && ascii::is_space( *xq_c ) ) {
            if ( !in_char_class )
              continue;
            //
            // This is similar to the above case for removing whitespace except
            // ICU removes *all* whitespace (even within character classes)
            // unless the whitespace is escaped; hence we have to escape it.
            //
            *icu_re += '\\';
          }
      }
    }
    *icu_re += *xq_c;
  } // FOR_EACH

  if ( i_flag ) {
    //
    // XQuery 3.0 F&O 5.6.1.1: All other constructs are unaffected by the "i"
    // flag.  For example, "\p{Lu}" continues to match upper-case letters only.
    //
    // However, ICU lower-cases everything for the 'i' flag; hence we have to
    // turn off the 'i' flag for just the \p{Lu}.
    //
    // Note that the "6" and "12" below are correct since "\\" represents a
    // single '\'.
    //
    ascii::replace_all( *icu_re, "\\p{Lu}", 6, "(?-i:\\p{Lu})", 12 );
  }

  //
  // XML Schema Part 2 F.1.1: [Unicode Database] groups code points into a
  // number of blocks such as Basic Latin (i.e., ASCII), Latin-1 Supplement,
  // Hangul Jamo, CJK Compatibility, etc. The set containing all characters
  // that have block name X (with all white space stripped out), can be
  // identified with a block escape \p{IsX}.
  //
  // However, ICU uses \p{InX} rather than \p{IsX}.
  //
  // Note that the "5" below is correct since "\\" represents a single '\'.
  //
  ascii::replace_all( *icu_re, "\\p{Is", 5, "\\p{In", 5 );
}

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_NO_UNICODE

namespace unicode {

void regex::compile( string const &u_pattern, char const *flags,
                     char const *pattern ) {
  icu_flags_t const icu_flags = convert_xquery_flags( flags ) & ~UREGEX_LITERAL;
  delete matcher_;
  UErrorCode status = U_ZERO_ERROR;
  matcher_ = new RegexMatcher( u_pattern, icu_flags, status );
  if ( U_FAILURE( status ) ) {
    delete matcher_;
    matcher_ = nullptr;

    zstring icu_error_key;
    if ( status > U_REGEX_ERROR_START && status < U_REGEX_ERROR_LIMIT ) {
      icu_error_key = ZED_PREFIX;
      icu_error_key += u_errorName( status );
    }
    throw XQUERY_EXCEPTION(
      err::FORX0002, ERROR_PARAMS( pattern, icu_error_key )
    );
  }
}

bool regex::match_part( string const &s ) {
  ZORBA_ASSERT( matcher_ );
  matcher_->reset( s );
  return matcher_->find() != 0;
}

bool regex::match_whole( string const &s ) {
  ZORBA_ASSERT( matcher_ );
  matcher_->reset( s );
  UErrorCode status = U_ZERO_ERROR;
  return matcher_->matches( status ) && U_SUCCESS( status );
}

bool regex::next( re_type_t re_type, string const &s, size_type *pos,
                  string *substring, bool *matched ) {
  ZORBA_ASSERT( matcher_ );
  ZORBA_ASSERT( pos );
  unicode::size_type const s_len = s.length();
  if ( *pos < s_len ) {
    matcher_->reset( s );
    UErrorCode status = U_ZERO_ERROR;
    if ( matcher_->find( *pos, status ) ) {
      size_type const end = matcher_->end( status );
      if ( substring ) {
        size_type const start = matcher_->start( status );
        switch ( re_type ) {
          case re_is_match:
            substring->setTo( s, start, end - start );
            break;
          case re_is_separator:
            substring->setTo( s, *pos, start - *pos );
            break;
        }
      }
      *pos = end;
      if ( matched )
        *matched = true;
      return true;
    }
    if ( re_type == re_is_separator ) {
      //
      // Special case: the RE did not match starting at pos, but there *is* a
      // last token.  For example, given the RE of "," and:
      //
      //    s   = "a,b,c"
      //    pos =  01234
      //
      // then calling next_token() with a pos of 4 will not match another ","
      // but we should return the final token after the last "," (the "c").
      //
      if ( substring )
        substring->setTo( s, *pos, s_len - *pos );
      *pos = s_len;
      if ( matched )
        *matched = false;
      return true;
    }
  }
  if ( matched )
    *matched = false;
  return false;
}

bool regex::replace_all( string const &in, string const &replacement,
                         string *out ) {
  ZORBA_ASSERT( matcher_ );
  ZORBA_ASSERT( out );
  matcher_->reset( in );
  UErrorCode status = U_ZERO_ERROR;
  *out = matcher_->replaceAll( replacement, status );
  return U_SUCCESS( status ) == TRUE;
}

bool regex::replace_all( char const *in, char const *replacement,
                         string *out ) {
  string u_in, u_replacement;
  return  to_string( in, &u_in ) &&
          to_string( replacement, &u_replacement ) &&
          replace_all( u_in, u_replacement, out );
}



void regex::set_string(const char* in, size_type len, size_type *utf8len)
{
  ZORBA_ASSERT( matcher_ );
  to_string( in, len, &s_in );
  if(utf8len)
    *utf8len = s_in.length();
  matcher_->reset( s_in );
}

bool regex::find_next_match(bool *reachedEnd)
{
  ZORBA_ASSERT( matcher_ );
  UBool retfind = matcher_->find();
  if(reachedEnd)
  {
#if U_ICU_VERSION_MAJOR_NUM >= 4
  *reachedEnd = matcher_->hitEnd() != 0;
#else
  *reachedEnd = true;
#endif
  }
return retfind != 0;
}

int regex::get_pattern_group_count()
{
  ZORBA_ASSERT( matcher_ );
  return matcher_->groupCount();
}

int regex::get_match_start(int groupId)
{
  UErrorCode  errcode = U_ZERO_ERROR;
  ZORBA_ASSERT( matcher_ );
  return matcher_->start(groupId, errcode);
}

int regex::get_match_end(int groupId)
{
  UErrorCode  errcode = U_ZERO_ERROR;
  ZORBA_ASSERT( matcher_ );
  return matcher_->end(groupId, errcode);
}

} // namespace unicode

#endif /* ZORBA_NO_UNICODE */

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
