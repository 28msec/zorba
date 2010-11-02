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
    // Entries MUST be sorted by URI.
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
    pair<table_entry const *const,table_entry const *const> result =
      ::equal_range( table, table_end, entry_to_find, less_table_entry() );
    return result.first == result.second ? none : result.first->th_type;
  }

} // namespace thesaurus

///////////////////////////////////////////////////////////////////////////////

ft_thesaurus::~ft_thesaurus() {
  // do nothing
}

// TODO: deal with 'lang'

ft_thesaurus const* ft_thesaurus::get( zstring const &uri,
                                       iso639_1::type lang ) {
  if ( thesaurus::type const th_type = thesaurus::get_type( uri ) ) {
    typedef map<thesaurus::type,ft_thesaurus const*> th_impl_map_t;
    static th_impl_map_t th_impl_map;
    ft_thesaurus const *&th_impl = th_impl_map[ th_type ];
    if ( !th_impl ) {
      switch ( th_type ) {
        case thesaurus::moby:
          // TODO
          break;
        case thesaurus::wordnet:
          th_impl = new wordnet;
          break;
        case thesaurus::none:
          break;
      }
    }
    return th_impl;
  }
  return 0;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
