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

#include <zorba/xquery_functions.h>
#include <zorba/zorba_string.h>

#include "util/regex.h"
#include "util/uri_util.h"
#include "util/utf8_util.h"
#include "zorbatypes/zstring.h"

using namespace std;

namespace zorba {
namespace fn {

////////// 5.4 Functions on string values /////////////////////////////////////

String upper_case( String const &s ) {
  String result;
  utf8::to_upper( s, &result );
  return result;
}

String lower_case( String const &s ) {
  String result;
  utf8::to_lower( s, &result );
  return result;
}

////////// 5.5 Functions based on substring matching //////////////////////////

bool ends_with( String const &s, String const &sub ) {
  return sub.empty() || utf8::ends_with( s, sub );
}

bool ends_with( String const &s, char const *sub ) {
  return !*sub || utf8::ends_with( s, sub );
}

bool starts_with( String const &s, String const &sub ) {
  return sub.empty() || utf8::begins_with( s, sub );
}

bool starts_with( String const &s, char const *sub ) {
  return !*sub || utf8::begins_with( s, sub );
}

//////// 6 Functions that manipulate URIs /////////////////////////////////////

String encode_for_uri( String const &s ) {
  String result;
  uri::encode( s, &result );
  return result;
}

////////// 7.6 String Functions that Use Pattern Matching /////////////////////

class tokenize_iterator : public Sequence<String>::iterator {
public:
  tokenize_iterator( String const &input, char const *pattern,
                     char const *flags ) {
    re_.compile( pattern, flags );
    unicode::to_string( input, &u_input_ );
    pos_ = 0;
  }

  bool next( String *result ) {
    unicode::string u_token;
    if ( re_.next_token( u_input_, &pos_, &u_token ) ) {
      string token;
      utf8::to_string( u_token, &token );
      *result = String( token );
      return true;
    }
    return false;
  }

private:
  unicode::string u_input_;
  unicode::regex re_;
  unicode::size_type pos_;
};

Sequence<String> tokenize( String const &input, char const *pattern,
                           char const *flags ) {
  return Sequence<String>( new tokenize_iterator( input, pattern, flags ) );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace fn
} // namespace zorba
/* vim:set et sw=2 ts=2: */
