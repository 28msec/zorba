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

#include <cstring>
#include <vector>

#include <zorba/diagnostic_list.h>
#include "diagnostics/xquery_exception.h"

#include "diagnostics/assert.h"
#include "diagnostics/dict.h"

#include "ascii_util.h"
#include "cxx_util.h"
#include "regex.h"
#include "stl_util.h"

#define INVALID_RE_EXCEPTION(...) \
  XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS( __VA_ARGS__ ) )

#ifndef ZORBA_NO_ICU
# include <unicode/uversion.h>
U_NAMESPACE_USE

# ifndef U_ICU_VERSION_MAJOR_NUM
#   error "U_ICU_VERSION_MAJOR_NUM not defined"
# elif U_ICU_VERSION_MAJOR_NUM < 4
    //
    // UREGEX_LITERAL is only in ICU since 4.0.  For earlier versions, we
    // define it ourselves.  Of course it won't have any effect since it's not
    // implemented in ICU, but we implement it ourselves anyway since, even
    // though the constant is defined in 4.0, it's not actually implemented as
    // of 4.4.
    //
#   define UREGEX_LITERAL 16
# endif /* U_ICU_VERSION_MAJOR_NUM */

using namespace std;

#define bs_c "\\p{L}_\\d.:\\p{M}-"      /* \c equivalent contents */
#define bs_i "\\p{L}_:"                 /* \i equivalent contents */
#define bs_W "\\p{P}\\p{Z}\\p{C}"       /* \W equivalent contents */

template<typename IntegralType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<IntegralType>::value,
                        void>::type
dec_limit( IntegralType *i, IntegralType limit = 0 ) {
  if ( *i > limit )
    --*i;
}

static unsigned digits( long n ) {
  unsigned d = 0;
  do {
    ++d;
  } while ( n /= 10 );
  return d;
}

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

typedef uint32_t icu_flags_type;

static icu_flags_type convert_xquery_flags( char const *xq_flags ) {
  icu_flags_type icu_flags = 0;
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

inline bool is_char_range_begin( zstring const &s,
                                 zstring::const_iterator const &i ) {
  zstring::const_iterator j( i );
  return ztd::peek( s, &j ) == '-' && ztd::peek( s, &j ) != '[';
}

inline bool is_non_capturing_begin( zstring const &s,
                                    zstring::const_iterator const &i ) {
  zstring::const_iterator j( i );
  return ztd::peek_behind( s, &j ) == '?' && ztd::peek_behind( s, &j ) == '(';
}

#define IS_CHAR_RANGE_BEGIN (in_char_class && is_char_range_begin( xq_re, i ))
#define PEEK_C              ztd::peek( xq_re, i )

void convert_xquery_re( zstring const &xq_re, zstring *icu_re,
                        char const *xq_flags ) {
  icu_flags_type const icu_flags = convert_xquery_flags( xq_flags );
  bool const i_flag = (icu_flags & UREGEX_CASE_INSENSITIVE) != 0;
  bool const m_flag = (icu_flags & UREGEX_MULTILINE) != 0;
  bool const q_flag = (icu_flags & UREGEX_LITERAL) != 0;
  bool const x_flag = (icu_flags & UREGEX_COMMENTS) != 0;

  icu_re->clear();
  icu_re->reserve( xq_re.length() );    // approximate

  char c;                               // current (raw) XQuery char
  char c_cooked;                        // current cooked XQuery char
  char prev_c_cooked = 0;               // previous c_cooked
  char char_range_begin_cooked = 0;     // the 'a' in [a-b]

  bool got_backslash = false;
  int  got_quantifier = 0;
  int  in_char_class = 0;               // within [...]
  int  in_char_range = 0;               // within a-b within [...]
  int  is_first_char = 1;               // to check ^ placement

  bool in_backref = false;              // '\'[1-9][0-9]*
  unsigned backref_no = 0;              // 1-based

  // capture subgroup: true = open; false = closed
  vector<bool> cap_sub;                 // 0-based
  unsigned cur_cap_sub = 0;             // 1-based
  unsigned open_cap_subs = 0;

  // parentheses balancing: true = is capture subgroup; false = non-capturing
  vector<bool> paren;                   // 0-based
  unsigned cur_paren = 0;               // 1-based

  FOR_EACH( zstring, i, xq_re ) {
    c = c_cooked = *i;
    if ( got_backslash ) {
      if ( x_flag && !in_char_class && ascii::is_space( c ) ) {
        //
        // XQuery 3.0 F&O 5.6.1.1: If [the 'x' flag is] present, whitespace
        // characters ... in the regular expression are removed prior to
        // matching with one exception: whitespace characters within character
        // class expressions ... are not removed.
        //
        goto next;
      }
      got_backslash = false;

      switch ( c ) {

        ////////// Back-References ////////////////////////////////////////////

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          backref_no = c - '0';
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
          // no break;

        ////////// Single Character Escapes ///////////////////////////////////

        case '$': // added in XQuery 3.0 F&O 5.6.1
        case '(':
        case ')':
        case '*':
        case '+':
        case '-':
        case '.':
        case '?':
        case '[':
        case '\\':
        case ']':
        case '^':
        case '{':
        case '|':
        case '}':
          *icu_re += '\\';
          break;

        ////////// Multi-Character & Category Escapes /////////////////////////

        case 'n': // newline
          *icu_re += '\\';
          c_cooked = '\n';
          break;
        case 'r': // carriage return
          *icu_re += '\\';
          c_cooked = '\r';
          break;
        case 't': // tab
          *icu_re += '\\';
          c_cooked = '\t';
          break;
        case 'd': // [0-9]
        case 'D': // [^\d]
        case 'p': // category escape
        case 'P': // [^\p]
        case 's': // whitespace
        case 'S': // [^\s]
          if ( in_char_range || IS_CHAR_RANGE_BEGIN )
            goto not_single_char_esc;
          *icu_re += '\\';
          break;
        case 'w': // word char
          if ( in_char_range || IS_CHAR_RANGE_BEGIN )
            goto not_single_char_esc;
          //
          // Note that we can't simply pass \w through to ICU because what it
          // considers a "word character" is different from what XQuery does.
          //
          *icu_re += "[^" bs_W "]";
          goto next;
        case 'W': // [^\w]
          if ( in_char_range || IS_CHAR_RANGE_BEGIN )
            goto not_single_char_esc;
          *icu_re += "[" bs_W "]";
          goto next;
        case 'c': // NameChar
          if ( in_char_range || IS_CHAR_RANGE_BEGIN )
            goto not_single_char_esc;
          *icu_re += "[" bs_c "]";
          goto next;
        case 'C': // [^\c]
          if ( in_char_range || IS_CHAR_RANGE_BEGIN )
            goto not_single_char_esc;
          *icu_re += "[^" bs_c "]";
          goto next;
        case 'i': // initial NameChar
          if ( in_char_range || IS_CHAR_RANGE_BEGIN )
            goto not_single_char_esc;
          *icu_re += "[" bs_i "]";
          goto next;
        case 'I': // [^\i]
          if ( in_char_range || IS_CHAR_RANGE_BEGIN )
            goto not_single_char_esc;
          *icu_re += "[^" bs_i "]";
          goto next;

        default:
          throw INVALID_RE_EXCEPTION( xq_re, ZED( BadRegexEscape_3 ), c );
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
        bool prevent_multidigit_backref = false;
        if ( ascii::is_digit( c ) ) {
          if ( digits( cap_sub.size() ) > digits( backref_no ) )
            backref_no = backref_no * 10 + (c - '0');
          else {
            in_backref = false;
            //
            // Unlike XQuery, ICU always takes further digits to be part of the
            // backreference so we have to prevent ICU from doing that.  One
            // way to do that is by enclosing said digits in a single-character
            // character class, i.e., [N].
            //
            *icu_re += '[';
            *icu_re += c;
            *icu_re += ']';
            prevent_multidigit_backref = true;
          }
        } else
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

        if ( prevent_multidigit_backref )
          goto next;
      }

      switch ( c ) {
        case '$':
          if ( q_flag )
            *icu_re += '\\';
          else if ( !m_flag && i + 1 == xq_re.end() ) {
            //
            // XQuery 3.0 F&O 5.6.1: By default, ... $ matches the end of the
            // entire string.  [Newlines are treated as any other character.]
            //
            // However, in ICU, $ always matches before any trailing newlines.
            //
            // To make ICU work as XQuery needs it to, substitute \z for $ when
            // it is the last character in the regular expression (and multi-
            // line mode is not set).
            //
            icu_re->append( "\\z" );
            goto next;
          }
          break;
        case '(':
          if ( q_flag )
            *icu_re += '\\';
          else {
            cur_paren = paren.size() + 1;
            zstring::const_iterator j = i;
            if ( ++j != xq_re.end() && *j == '?' && ++j != xq_re.end() ) {
              //
              // Got "(?" sequence: potentially start of "(?:", a non-capturing
              // subgroup.  ICU also allows other characters after the "(?"
              // that XQuery does not, so we have to report those as errors.
              //
              if ( *j != ':' )
                throw INVALID_RE_EXCEPTION( xq_re, ZED( BadRegexParen_3 ), *j );
              //
              // Start of non-capturing subgroup.
              //
              paren.push_back( false );
            } else {
              //
              // Start of capturing subgroup.
              //
              paren.push_back( true );
              ++open_cap_subs;
              cap_sub.push_back( true );
              cur_cap_sub = cap_sub.size();
              is_first_char = 2;
            }
          }
          break;
        case ')':
          if ( q_flag )
            *icu_re += '\\';
          else {
            if ( !cur_paren )
              goto unbalanced_char;
            if ( paren[ --cur_paren ] ) {
              if ( !open_cap_subs || !cur_cap_sub )
                goto unbalanced_char;
              cap_sub[ --cur_cap_sub ] = false;
            }
          }
          break;
        case ':':
          if ( is_non_capturing_begin( xq_re, i ) ) {
            //
            // This ':' is part of a "(?:" sequence, i.e., a non-capturing
            // subgroup.  Therefore, the *next* character will be a "first
            // character" for the purposes of '^'.
            //
            is_first_char = 2;
          }
          break;
        case '*':
        case '+':
        case '?':
        case '{':
          if ( q_flag )
            *icu_re += '\\';
          else {
            //
            // ICU allows the multiple quantifiers *+, ++, and ?+, but XQuery
            // does not so we have to check for them.
            //
            if ( got_quantifier && c != '?' )
              throw INVALID_RE_EXCEPTION(
                xq_re, ZED( BadQuantifierHere_3 ), c
              );
            got_quantifier = 2;
          }
          break;
        case '-':
          if ( in_char_class && !in_char_range ) {
            char const next_c = PEEK_C;
            if ( next_c == '[' ) {
              //
              // ICU uses "--" to indicate range subtraction, e.g.,
              // XQuery [A-Z-[OI]] becomes ICU [A-Z--[OI]].
              //
              *icu_re += '-';
            } else if ( prev_c_cooked != '[' && next_c != ']' ) {
              //
              // The '-' is neither the first or last character within a
              // character range (i.e., a literal '-') so therefore it's
              // indicating a character range.
              //
              char_range_begin_cooked = prev_c_cooked;
              in_char_range = 2;
            }
          }
          break;
        case '.':
        case '}':
          if ( q_flag )
            *icu_re += '\\';
          break;
        case '[':
          if ( q_flag )
            *icu_re += '\\';
          else {
            if ( in_char_class && prev_c_cooked != '-' )
              goto unescaped_char;
            ++in_char_class;
            is_first_char = 2;
          }
          break;
        case '\\':
          got_backslash = true;
          if ( in_char_range )
            ++in_char_range;
          goto next;
        case ']':
          if ( q_flag )
            *icu_re += '\\';
          else {
            if ( !in_char_class )
              goto unbalanced_char;
            --in_char_class;
            in_char_range = 0;
          }
          break;
        case '^':
          if ( q_flag )
            *icu_re += '\\';
          else if ( !is_first_char ) {
            if ( in_char_class )
              goto unescaped_char;
            *icu_re += '\\';
          }
          break;
        case '|':
          if ( q_flag )
            *icu_re += '\\';
          else
            is_first_char = 2;
          break;
        default:
          if ( x_flag && ascii::is_space( c ) ) {
            if ( !in_char_class )
              goto next;
            //
            // This is similar to the above case for removing whitespace except
            // ICU removes *all* whitespace (even within character classes)
            // unless the whitespace is escaped; hence we have to escape it.
            //
            *icu_re += '\\';
          }
      } // switch
    } // else

    if ( in_char_range == 1 && c_cooked < char_range_begin_cooked )
      throw INVALID_RE_EXCEPTION(
        xq_re, ZED( BadEndCharInRange_34 ),
        ascii::printable_char( c_cooked ),
        char_range_begin_cooked
      );

    *icu_re += c;

next:
    dec_limit( &in_char_range );
    dec_limit( &got_quantifier );
    dec_limit( &is_first_char );
    prev_c_cooked = c_cooked;
  } // FOR_EACH

  if ( got_backslash )
    throw INVALID_RE_EXCEPTION( xq_re, ZED( TrailingChar_3 ), '\\' );
  if ( in_char_class )
    throw INVALID_RE_EXCEPTION( xq_re, ZED( UnbalancedChar_3 ), '[' );

  if ( !q_flag ) {
    if ( i_flag ) {
      //
      // XQuery 3.0 F&O 5.6.1.1: All other constructs are unaffected by the "i"
      // flag.  For example, "\p{Lu}" continues to match upper-case letters
      // only.
      //
      // However, ICU lower-cases everything for the 'i' flag; hence we have to
      // turn off the 'i' flag for the \p{Lu} and \P{Lu}.
      //
      // Note that the "6" and "12" below are correct since "\\" represents a
      // single '\'.
      //
      ascii::replace_all( *icu_re, "\\p{Lu}", 6, "(?-i:\\p{Lu})", 12 );
      ascii::replace_all( *icu_re, "\\P{Lu}", 6, "(?-i:\\P{Lu})", 12 );
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
    ascii::replace_all( *icu_re, "\\P{Is", 5, "\\P{In", 5 );
  } // q_flag
  return;

not_single_char_esc:
    throw INVALID_RE_EXCEPTION( xq_re, ZED( NotSingleCharEsc_3 ), c );
unbalanced_char:
    throw INVALID_RE_EXCEPTION( xq_re, ZED( UnbalancedChar_3 ), c );
unescaped_char:
    throw INVALID_RE_EXCEPTION( xq_re, ZED( UnescapedChar_3 ), c );
}

///////////////////////////////////////////////////////////////////////////////


namespace unicode {

void regex::compile( string const &u_pattern, char const *flags,
                     char const *pattern ) {
  icu_flags_type const icu_flags =
    convert_xquery_flags( flags ) & ~UREGEX_LITERAL;
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
    throw INVALID_RE_EXCEPTION( pattern, icu_error_key );
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

void regex::set_string( char const *in, size_type len ) {
  ZORBA_ASSERT( matcher_ );
  to_string( in, len, &s_in_ );
  matcher_->reset( s_in_ );
}

bool regex::find_next_match( bool *reachedEnd ) {
  ZORBA_ASSERT( matcher_ );
  UBool retfind = matcher_->find();
  if ( reachedEnd ) {
#if U_ICU_VERSION_MAJOR_NUM >= 4
    *reachedEnd = matcher_->hitEnd() != 0;
#else
    *reachedEnd = true;
#endif
  }
  return retfind != 0;
}

int regex::get_pattern_group_count() {
  ZORBA_ASSERT( matcher_ );
  return matcher_->groupCount();
}

int regex::get_match_start( int groupId ) {
  ZORBA_ASSERT( matcher_ );
  UErrorCode status = U_ZERO_ERROR;
  return matcher_->start( groupId, status );
}

int regex::get_match_end( int groupId ) {
  ZORBA_ASSERT( matcher_ );
  UErrorCode status = U_ZERO_ERROR;
  return matcher_->end( groupId, status );
}

} // namespace unicode
} // namespace zorba

///////////////////////////////////////////////////////////////////////////////

#else /* ZORBA_NO_ICU */

#include "zorbatypes/zstring.h"

namespace zorba {
//no convertion
void convert_xquery_re( zstring const &xq_re, zstring *lib_re,
                        char const *flags)
{
  *lib_re = xq_re;
}

namespace unicode {

uint32_t regex::parse_regex_flags(const char* flag_cstr) 
{
  uint32_t flags = 0;
  for (const char* p = flag_cstr; *p != '\0'; ++p) 
  {
    switch (*p) 
    {
    case 'i': flags |= REGEX_ASCII_CASE_INSENSITIVE; break;
    case 's': flags |= REGEX_ASCII_DOTALL; break;
    case 'm': flags |= REGEX_ASCII_MULTILINE; break;
    case 'x': flags |= REGEX_ASCII_NO_WHITESPACE; break;
    case 'q': flags |= REGEX_ASCII_LITERAL; break;
    default:
      throw XQUERY_EXCEPTION( err::FORX0001, ERROR_PARAMS( *p ) );
      break;
    }
  }
  return flags;
}

void regex::compile( char const *pattern, char const *flags)
{
  parsed_flags = parse_regex_flags(flags);
  regex_xquery::CRegexXQuery_parser regex_parser;
  regex_matcher = regex_parser.parse(pattern, parsed_flags);
  if(!regex_matcher)
    throw INVALID_RE_EXCEPTION(pattern);
}

bool regex::match_part( char const *s )
{
  bool  retval;
  int   match_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s, parsed_flags, &match_pos, &matched_len);

  return retval;
}

bool regex::next_match( char const *s, size_type *pos, zstring *match )
{
  bool  retval;
  int   match_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s+*pos, parsed_flags, &match_pos, &matched_len);
  if(retval)
  {
    match->assign(s+*pos+match_pos, matched_len);
    *pos += match_pos + matched_len;
  }
  return retval;
}

bool regex::next_token( char const *s, size_type *pos, zstring *token,
                  bool *matched)
{
  if(!s[*pos])
    return false;
  bool  retval;
  int   match_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s+*pos, parsed_flags, &match_pos, &matched_len);
  if(retval)
  {
    if(token)
      token->assign(s+*pos, match_pos);
    *pos += match_pos + matched_len;
    if(matched)
      *matched = true;
    return true;
  }
  else
  {
    if(token)
      token->assign(s+*pos);
    *pos += strlen(s+*pos);
    if(matched)
      *matched = false;
    return true;
  }
}

bool regex::match_whole( char const *s )
{
  bool  retval;
  int   matched_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s, parsed_flags|REGEX_ASCII_WHOLE_MATCH, &matched_pos, &matched_len);
  if(!retval)
    return false;
  return true;
}

bool regex::replace_all( char const *in, char const *replacement, zstring *result )
{
  int   match_pos;
  int   matched_len;

  const char  *start_str = in;
  int  subregex_count = regex_matcher->get_indexed_regex_count();
  bool retval = false;

  while(regex_matcher->match_anywhere(start_str, parsed_flags, &match_pos, &matched_len))
  {
    if(match_pos)
      result->append(start_str , match_pos);
    retval = true;
    const char *temprepl = replacement;
    const char *submatched_source;
    int   submatched_len;
    int index;
    while(*temprepl)
    {
      //look for dollars
      if(*temprepl == '\\')
      {
        if(!(parsed_flags & REGEX_ASCII_LITERAL))
        {
          temprepl++;
          if(!*temprepl) 
            temprepl--;
          else if((*temprepl != '\\') && (*temprepl != '$'))//Invalid replacement string.
            throw XQUERY_EXCEPTION( err::FORX0004, ERROR_PARAMS( replacement ) );
        }
        result->append(1, *temprepl);
        temprepl++;
        continue;
      }
      if((*temprepl == '$') && !(parsed_flags & REGEX_ASCII_LITERAL))
      {
        temprepl++;
        index = 0;
        int   nr_digits = 0;
        while(isdigit(*temprepl))
        {
          if(nr_digits && ((index*10 + (*temprepl)-'0') > subregex_count))
            break;
          index = index*10 + (*temprepl)-'0';
          temprepl++;
          nr_digits++;
        }
        if(!nr_digits)//Invalid replacement string.
          throw XQUERY_EXCEPTION( err::FORX0004, ERROR_PARAMS( replacement ) );
        else if(!index)
        {
          result->append(start_str+match_pos, matched_len);
        }
        else if(regex_matcher->get_indexed_match(index, &submatched_source, &submatched_len))
        {
          if(submatched_source && submatched_len)
            result->append(submatched_source, submatched_len);
        }
      }
      else
      {
        result->append(1, *temprepl);
        temprepl++;
      }
    }
    start_str += match_pos + matched_len;
  }
  result->append(start_str);

  return retval;
}

void regex::set_string( const char* in, size_type len )
{
  s_in_.assign(in, len);
  m_pos = 0;
  m_match_pos = 0;
  m_matched_len = 0;
}

bool regex::find_next_match( bool *reachedEnd )
{
  bool  retval;

  retval = regex_matcher->match_anywhere(s_in_.c_str()+m_pos, parsed_flags, &m_match_pos, &m_matched_len);
  if(retval)
  {
    m_match_pos += m_pos;
    m_pos = m_match_pos + m_matched_len;
  }
  else
  {
    m_pos = s_in_.length();
    m_match_pos = 0;
    m_matched_len = 0;
  }
  if(reachedEnd)
    *reachedEnd = regex_matcher->get_reachedEnd();
  return retval;
}

int regex::get_pattern_group_count()
{
  return (int)regex_matcher->get_indexed_regex_count();
}

bool regex::get_match_start_end_bytes( int groupId, int *start, int *end )
{
  *start = -1;
  *end = -1;
  if(groupId == 0)
  {
    *start = m_match_pos;
    *end = m_match_pos + m_matched_len;
    return true;
  }
  if(groupId > (int)regex_matcher->get_indexed_regex_count())
    return false;
  const char *submatched_source;
  int   submatched_len;
  if(!regex_matcher->get_indexed_match(groupId, &submatched_source, &submatched_len))
    return false;
  *start = submatched_source - s_in_.c_str();
  *end = *start + submatched_len;
  return true;
}

} // namespace unicode
} // namespace zorba
#endif /* ZORBA_NO_ICU */

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
