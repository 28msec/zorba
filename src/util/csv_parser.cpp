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

// Zorba
#include "util/string_util.h"

// local
#include "csv_parser.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool csv_parser::next_value( zstring *value, bool *eol, bool *quoted ) const {
  ztd::string_appender<zstring,128> appender( value );
  char c;
  bool in_quote = false;
  bool is_quoted = false;

  value->clear();

  while ( is_->get( c ) ) {
    if ( in_quote ) {
      if ( quote_esc_ == quote_ ) {     // ""
        if ( c == quote_ && (c = is_->peek(), is_->good()) ) {
          if ( c != quote_ ) {
            in_quote = false;
            continue;
          }
          is_->get();
        }
      } else {                          // \"
        if ( c == quote_ ) {
          in_quote = false;
          continue;
        }
        if ( c == quote_esc_ && !is_->get( c ) )
          break;
      }
    } else {
      if ( c == quote_ ) {
        in_quote = is_quoted = true;
        continue;
      }
      if ( c == sep_ ) {
        *eol = false;
        goto return_true;
      }
      switch ( c ) {
        case '\r':
          if ( ((c = is_->peek()), is_->good()) && c == '\n' )
            is_->get();
          // no break;
        case '\n':
          *eol = true;
          goto return_true;
      } // switch
    } // else
    appender += c;
  } // while

  appender.flush();
  if ( value->empty() )
    return false;

  *eol = true;
return_true:
  if ( quoted )
    *quoted = is_quoted;
  return true;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
