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

#include <cctype>
#include <cstring>

#include <zorba/error.h>

#include "util/stl_util.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/dict.h"

#include "ft_wildcard.h"

#define DEBUG_MATCHER 0

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * Parses digits up to the given stop character.  If a non-digit other than the
 * stop character is encountered, an exception is thrown.
 *
 * @param ws_pat  The XQuery full-text "wildcard syntax" pattern string.
 * @param ws_c    The iterator over ws_pat.
 * @param stop    The stop character.
 * @param icu_pat A pointer to the ICU pattern string.
 */
static void parse_digits( zstring const &ws_pat, zstring::const_iterator &ws_c,
                          char stop, zstring *icu_pat ) {
  while ( ++ws_c != ws_pat.end() ) {
    *icu_pat += *ws_c;
    if ( *ws_c == stop )
      break;
    if ( !isdigit( *ws_c ) )
      throw XQUERY_EXCEPTION(
        err::FTDY0020, ERROR_PARAMS( ws_pat, ZED( BadDecDigit_3 ), *ws_c )
      );
  }
}

/**
 * Converts an XQuery full-text "wildcard syntax" pattern into an ICU regular
 * expression.
 *
 * @param ws_pat  The XQuery full-text "wildcard syntax" pattern string.
 * @param icu_pat A pointer to the ICU pattern string.
 */
static void wildcard_to_icu_pattern( zstring const &ws_pat, zstring *icu_pat ) {
  icu_pat->clear();
  icu_pat->reserve( ws_pat.length() );

  bool got_backslash = false, got_dot = false;

  FOR_EACH( zstring, ws_c, ws_pat ) {
    if ( got_backslash ) {
      *icu_pat += '\\';
      *icu_pat += *ws_c;
      got_backslash = false;
      continue;
    }
    if ( got_dot ) {
      switch ( *ws_c ) {
        case '.':
          *icu_pat += '.';
          continue;
        case '{':
          *icu_pat += '{';
          parse_digits( ws_pat, ws_c, ',', icu_pat );
          parse_digits( ws_pat, ws_c, '}', icu_pat );
          break;
        default:
          *icu_pat += *ws_c;
          break;
      }
      got_dot = false;
      continue;
    }
    switch ( *ws_c ) {
      case '.':
        got_dot = true;
        *icu_pat += *ws_c;
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
        *icu_pat += *ws_c;
        break;
    }
  }

  if ( got_backslash )
    throw XQUERY_EXCEPTION(
      err::FTDY0020, ERROR_PARAMS( ws_pat, ZED( TrailingChar_3 ), '\\' )
    );
}

///////////////////////////////////////////////////////////////////////////////

ft_wildcard::ft_wildcard( zstring const &ws_pat ) {
  zstring icu_pat;
  wildcard_to_icu_pattern( ws_pat, &icu_pat );
#if DEBUG_MATCHER
  cout << "xq : " << ws_pat << endl;
  cout << "icu: " << icu_pat << endl;
#endif
  try {
    regex_.compile( icu_pat );
  }
  catch ( XQueryException &xe ) {
    if ( xe.diagnostic() == err::FORX0002 )
      xe.set_diagnostic( err::FTDY0020 );
    throw;
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
