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

#include <algorithm>
#include <functional>                   /* for binary_function */
#include <utility>                      /* for pair */

#include "util/ascii_util.h"

#include "ft_thesaurus.h"
#include "thesauri/wordnet.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace thesaurus {

  enum type {
    none,
    moby,
    wordnet
  };

  struct table_entry {
    char const *th_uri;
    type th_type;
  };

  struct less_table_entry :
    binary_function<table_entry const&,table_entry const&,bool>
  {
    less_table_entry() { }
    result_type operator()( first_argument_type i, second_argument_type j ) {
      return ::strcmp( i.th_uri, j.th_uri ) < 0;
    }
  };

  static table_entry const table[] = {
    //
    // 1. Entries *must* be sorted by URI.
    // 2. URIs *must* *not* have a trailing '/'.
    //
    { "default"                               , wordnet },
    { "http://icon.shef.ac.uk/Moby/mthes.html", moby    },
    { "http://wordnet.princeton.edu"          , wordnet },
  };

  static type get_type( zstring const &uri ) {
    static table_entry const *const table_end =
      table + sizeof( table ) / sizeof( table[0] );
    table_entry entry_to_find;
    entry_to_find.th_uri = uri.c_str();
    pair<table_entry const*,table_entry const*> const result =
      ::equal_range( table, table_end, entry_to_find, less_table_entry() );
    return result.first == result.second ? none : result.first->th_type;
  }

} // namespace thesaurus

///////////////////////////////////////////////////////////////////////////////

ft_thesaurus::~ft_thesaurus() {
  // do nothing
}

ft_thesaurus* ft_thesaurus::get( zstring const &uri, zstring const &phrase,
                                 zstring const &relationship,
                                 ft_int at_least, ft_int at_most ) {
  zstring const uri_no_slash(
    ascii::ends_with( uri, '/' ) ? uri.substr( 0, uri.size() - 1 ) : uri
  );

  if ( thesaurus::type const th_type = thesaurus::get_type( uri_no_slash ) ) {
    switch ( th_type ) {
      case thesaurus::moby:
        // TODO
        break;
      case thesaurus::wordnet:
        return new wordnet( phrase, relationship, at_least, at_most );
        break;
      case thesaurus::none:
        break;
    }
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
