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

#include <cctype>
#include <cstring>

using namespace std;

#define DEBUG_MATCHER 0
#define STANDALONE_TEST 0

#if !STANDALONE_TEST
# include <zorba/error.h>
# include "runtime/full_text/icu_wildcard_matcher.h"
# include "util/stl_util.h"
# include "zorbaerrors/error_manager.h"

namespace zorba {

#else /* STANDALONE_TEST */
# include <cstdlib>
# include <iostream>

#define FOR_EACH(TYPE,IT,SEQ) \
  for ( TYPE::const_iterator IT = (SEQ).begin(); IT != (SEQ).end(); ++IT )

  template<typename T> inline
  void debug_error_helper( T code, int line ) {
    cerr << "line " << line << ": error = " << code << endl;
    ::exit(1);
  }
# define ZORBA_ERROR(CODE) debug_error_helper( CODE, __LINE__ )
# define FTDY0020 20

#endif /* STANDALONE_TEST */

///////////////////////////////////////////////////////////////////////////////

/**
 * Parses digits up to the given stop character.  If a non-digit other than the
 * stop character is encountered, a Zorba exception is thrown.
 *
 * @param xq_pat  The XQuery pattern string.
 * @param xq_c    The iterator over xq_pat.
 * @param stop    The stop character.
 * @param icu_pat The ICU pattern string.
 */
static void parse_digits( string const &xq_pat, string::const_iterator &xq_c,
                          char stop, string &icu_pat ) {
  while ( ++xq_c != xq_pat.end() ) {
    icu_pat += *xq_c;
    if ( *xq_c == stop )
      break;
    if ( !isdigit( *xq_c ) )
      ZORBA_ERROR( FTDY0020 );
  }
}

/**
 * Converts an XQuery pattern ("wildcard syntax") into an ICU regular
 * expression pattern.
 */
static void xquery_to_icu_pattern( string const &xq_pat, string &icu_pat ) {
  icu_pat.clear();
  icu_pat.reserve( xq_pat.length() );

  bool got_backslash = false, got_dot = false;

  FOR_EACH( string, xq_c, xq_pat ) {
    if ( got_backslash ) {
      icu_pat += '\\';
      icu_pat += *xq_c;
      got_backslash = false;
      continue;
    }
    if ( got_dot ) {
      switch ( *xq_c ) {
        case '.':
          icu_pat += '.';
          continue;
        case '{':
          icu_pat += '.';
          icu_pat += '{';
          parse_digits( xq_pat, xq_c, ',', icu_pat );
          parse_digits( xq_pat, xq_c, '}', icu_pat );
          break;
        default:
          icu_pat += '.';
          icu_pat += *xq_c;
          break;
      }
      got_dot = false;
      continue;
    }
    switch ( *xq_c ) {
      case '.':
        got_dot = true;
        break;
      case '\\':
        got_backslash = true;
        break;
      case '$': // Must escape characters that are signficant for ICU regular
      case '(': // expressions.
      case ')':
      case '*':
      case '+':
      case '?':
      case '[':
      case ']':
      case '^':
      case '{':
      case '|':
      case '}':
        icu_pat += '\\';
        // no break;
      default:
        icu_pat += *xq_c;
        break;
    }
  }

  if ( got_backslash )
    ZORBA_ERROR( FTDY0020 );
}

///////////////////////////////////////////////////////////////////////////////

#if !STANDALONE_TEST

U_NAMESPACE_USE

void icu_wildcard_matcher::compile( string const &xq_pat ) {
  string icu_pat;
  xquery_to_icu_pattern( xq_pat, icu_pat );
#if DEBUG_MATCHER
  cout << "xq : " << xq_pat << endl;
  cout << "icu: " << icu_pat << endl;
#endif
  UErrorCode status = U_ZERO_ERROR;
  matcher_.reset( new RegexMatcher( icu_pat.c_str(), 0, status ) );
  if ( U_FAILURE( status ) )
    ZORBA_ERROR( FTDY0020 );
}

bool icu_wildcard_matcher::matches( string const &s ) const {
  UnicodeString const u16_s( s.c_str() );
  matcher_->reset( u16_s );
  UErrorCode status = U_ZERO_ERROR;
  return matcher_->matches( status );
}

} // namespace zorba

#else /* STANDALONE_TEST */

////////// Stand-alone testing ////////////////////////////////////////////////

static char const *const xq_patterns[] = {
  "hello",
  "hello*",
  "hello+",
  "hello?",
  "hello.world",
  "hello.*world",
  "hello.+world",
  "hello.?world",
  "hello.{2,15}world",
  "he..o",
  0
};

int main() {
  for ( char const *const *xq_pat = xq_patterns; *xq_pat; ++xq_pat ) {
    string icu_pat;
    xquery_to_icu_pattern( *xq_pat, icu_pat );
    cout << *xq_pat << '\n' << icu_pat << "\n\n";
  }
}
#endif /* STANDALONE_TEST */
/* vim:set et sw=2 ts=2: */
