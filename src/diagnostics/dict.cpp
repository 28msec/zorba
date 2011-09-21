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
#include <algorithm>
#include <cstring>
#include <functional>
#include <utility>                      /* for pair */

#include "zorbautils/locale.h"

#include "dict.h"
#include "dict_impl.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {
namespace diagnostic {
namespace dict {

///////////////////////////////////////////////////////////////////////////////

struct less_entry : binary_function<entry const&,entry const&,bool> {
  less_entry() { }
  result_type operator()( first_argument_type i, second_argument_type j ) {
    return ::strcmp( i.key, j.key ) < 0;
  }
};

#define SET_DICT(CODE,BEGIN,END)                                \
  do {                                                          \
    extern entry const dict_##CODE[], *const dict_##CODE##_end; \
    BEGIN = dict_##CODE, END = dict_##CODE##_end;               \
  } while (0)

#define LANG(CODE)              \
  iso639_1::CODE:               \
    SET_DICT(CODE,*begin,*end); \
    return true

static bool get_dict( iso639_1::type lang, entry const **begin,
                      entry const **end ) {
  switch ( lang ) {
    case LANG(en);
    // more languages go here
    default:
      return false;
  }
}

///////////////////////////////////////////////////////////////////////////////

char const* lookup( char const *key ) {
  typedef pair<entry const*,entry const*> range_type;

  static entry const *begin, *end;
  if ( !begin && !get_dict( get_host_lang(), &begin, &end ) )
    SET_DICT( en, begin, end );

  entry entry_to_find;
  entry_to_find.key = key;

  range_type const result =
    ::equal_range( begin, end, entry_to_find, less_entry() );

  return result.first == result.second ? key : result.first->value;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace dict
} // namespace diagnostic
} // namespace zorba
/* vim:set et sw=2 ts=2: */
