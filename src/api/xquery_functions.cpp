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

#include <zorba/xquery_functions.h>
#include <zorba/zorba_string.h>

#include "util/uri_util.h"
#include "util/utf8_util.h"
#include "zorbatypes/zstring.h"

using namespace std;

namespace zorba {
namespace fn {

String encode_for_uri( String const &s ) {
  String result;
  uri::encode( s, &result );
  return result;
}

bool ends_with( String const &s, String const &sub ) {
  return sub.empty() || utf8::ends_with( s, sub );
}

bool ends_with( String const &s, char const *sub ) {
  return !*sub || utf8::ends_with( s, sub );
}

String lower_case( String const &s ) {
  String result;
  utf8::to_lower( s, &result );
  return result;
}

bool starts_with( String const &s, String const &sub ) {
  return sub.empty() || utf8::begins_with( s, sub );
}

bool starts_with( String const &s, char const *sub ) {
  return !*sub || utf8::begins_with( s, sub );
}

String upper_case( String const &s ) {
  String result;
  utf8::to_upper( s, &result );
  return result;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace fn
} // namespace zorba
/* vim:set et sw=2 ts=2: */
