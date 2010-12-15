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

#define DEBUG_MATCHER 0
#define STANDALONE_TEST 0

#if !STANDALONE_TEST
# include <zorba/error.h>
# include "util/stl_util.h"
# include "zorbaerrors/error_manager.h"

# include "ft_wildcard.h"

using namespace std;

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
static void parse_digits( zstring const &xq_pat, zstring::const_iterator &xq_c,
                          char stop, zstring *icu_pat ) {
  while ( ++xq_c != xq_pat.end() ) {
    *icu_pat += *xq_c;
    if ( *xq_c == stop )
      break;
    if ( !isdigit( *xq_c ) )
      ZORBA_ERROR( FTDY0020 );
  }
}

/**
 * Converts an XQuery full-text "wildcard syntax" pattern into an ICU regular
 * expression.
 */
static void wildcard_to_icu_pattern( zstring const &xq_pat, zstring *icu_pat ) {
  icu_pat->clear();
  icu_pat->reserve( xq_pat.length() );

  bool got_backslash = false, got_dot = false;

  FOR_EACH( zstring, xq_c, xq_pat ) {
    if ( got_backslash ) {
      *icu_pat += '\\';
      *icu_pat += *xq_c;
      got_backslash = false;
      continue;
    }
    if ( got_dot ) {
      switch ( *xq_c ) {
        case '.':
          *icu_pat += '.';
          continue;
        case '{':
          *icu_pat += '{';
          parse_digits( xq_pat, xq_c, ',', icu_pat );
          parse_digits( xq_pat, xq_c, '}', icu_pat );
          break;
        default:
          *icu_pat += *xq_c;
          break;
      }
      got_dot = false;
      continue;
    }
    switch ( *xq_c ) {
      case '.':
        got_dot = true;
        *icu_pat += *xq_c;
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
        *icu_pat += '\\';
        // no break;
      default:
        *icu_pat += *xq_c;
        break;
    }
  }

  if ( got_backslash )
    ZORBA_ERROR( FTDY0020 );
}

///////////////////////////////////////////////////////////////////////////////

#if !STANDALONE_TEST

ft_wildcard::ft_wildcard( zstring const &xq_pat ) {
  zstring icu_pat;
  wildcard_to_icu_pattern( xq_pat, &icu_pat );
#if DEBUG_MATCHER
  cout << "xq : " << xq_pat << endl;
  cout << "icu: " << icu_pat << endl;
#endif
  if ( !regex_.compile( icu_pat ) )
    ZORBA_ERROR( FTDY0020 );
}

} // namespace zorba

#else /* STANDALONE_TEST */

////////// Stand-alone testing ////////////////////////////////////////////////

static char const *const xq_patterns[] = {
  "hello",
  "hello.",
  "hello*",
  "hello+",
  "hello?",
  "hello\\.",
  "hello\\*",
  "hello\\+",
  "hello\\?",
  "hello.world",
  "hello.*world",
  "hello.+world",
  "hello.?world",
  "hello.{2,15}world",
  "he..o",
  "\\h\\e\\l\\l\\o",
  0
};

int main() {
  for ( char const *const *xq_pat = xq_patterns; *xq_pat; ++xq_pat ) {
    zstring icu_pat;
    wildcard_to_icu_pattern( *xq_pat, icu_pat );
    cout << *xq_pat << '\n' << icu_pat << "\n\n";
  }
}
#endif /* STANDALONE_TEST */
/* vim:set et sw=2 ts=2: */
