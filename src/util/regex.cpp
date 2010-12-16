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

#include "zorbatypes/zorbatypesError.h"

#include "regex.h"
#include "stl_util.h"

using namespace std;
U_NAMESPACE_USE

#define bs_c "\\p{L}\\d.:\\p{M}-"       /* \c equivalent contents */
#define bs_i "\\p{L}_:"                 /* \i equivalent contents */

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void convert_xquery_re( zstring const &xq_re, zstring *lib_re ) {
  lib_re->clear();
  lib_re->reserve( xq_re.length() );

  bool got_backslash = false;

  FOR_EACH( zstring, xq_c, xq_re ) {
    if ( got_backslash ) {
      switch ( *xq_c ) {
        case 'c':
          *lib_re += "[" bs_c "]";
          break;
        case 'C':
          *lib_re += "[^" bs_c "]";
          break;
        case 'i':
          *lib_re += "[" bs_i "]";
          break;
        case 'I':
          *lib_re += "[^" bs_i "]";
          break;
        default:
          *lib_re += '\\';
          *lib_re += *xq_c;
          break;
      }
      got_backslash = false;
      continue;
    }
    switch ( *xq_c ) {
      case '\\':
        got_backslash = true;
        break;
      default:
        *lib_re += *xq_c;
        break;
    }
  }
}

static uint32_t parse_regex_flags( char const *flags ) {
  uint32_t icu_flags = 0;
  for ( char const *f = flags; *f; ++f ) {
    switch ( *f ) {
      case 'i': icu_flags |= UREGEX_CASE_INSENSITIVE; break;
      case 'm': icu_flags |= UREGEX_MULTILINE       ; break;
      case 's': icu_flags |= UREGEX_DOTALL          ; break;
      case 'x': icu_flags |= UREGEX_COMMENTS        ; break;
      default:
        throw zorbatypesException( flags, ZorbatypesError::FORX0001 );
    }
  }
  return icu_flags;
}

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_NO_UNICODE

namespace unicode {

bool regex::compile( string const &pattern, char const *flags ) {
  UErrorCode status = U_ZERO_ERROR;
  delete matcher_;
  matcher_ = new RegexMatcher( pattern, parse_regex_flags( flags ), status );
  if ( U_FAILURE( status ) ) {
    delete matcher_;
    matcher_ = 0;
    return false;
  }
  return true;
}

bool regex::match_part( string const &s ) {
  assert( matcher_ );
  matcher_->reset( s );
  return matcher_->find() != 0;
}

bool regex::match_whole( string const &s ) {
  assert( matcher_ );
  matcher_->reset( s );
  UErrorCode status = U_ZERO_ERROR;
  return matcher_->matches( status ) && U_SUCCESS( status );
}

bool regex::next( re_type_t re_type, string const &s, size_type *pos,
                  string *substring, bool *matched ) {
  assert( matcher_ );
  assert( pos );
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
  assert( matcher_ );
  assert( out );
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

} // namespace unicode

#endif /* ZORBA_NO_UNICODE */

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
