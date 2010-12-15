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

#include "regex.h"
#include "stl_util.h"

using namespace std;

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

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
