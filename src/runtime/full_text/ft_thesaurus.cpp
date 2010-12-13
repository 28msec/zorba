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

#include <algorithm>                    /* for equal_range */
#include <cassert>
#include <cstring>
#include <functional>                   /* for binary_function */
#include <utility>                      /* for pair */

#include "util/ascii_util.h"
#include "util/less.h"

#include "ft_thesaurus.h"
#include "thesauri/wn_thesaurus.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * The "statically known thesauri" implementations.
 */
namespace thesauri_impl {

  enum type {
    none,
    wordnet
  };

  struct table_entry {
    char const *te_uri;
    type te_type;
  };

  struct less_table_entry :
    binary_function<table_entry const&,table_entry const&,bool>
  {
    less_table_entry() { }
    result_type operator()( first_argument_type i, second_argument_type j ) {
      return ::strcmp( i.te_uri, j.te_uri ) < 0;
    }
  };

#define ZORBA_W3C_TEST_SUITE_THESAURUS_URIS 1

  static table_entry const table[] = {
    //
    // 1. Entries *must* be sorted by URI.
    // 2. URIs *must* *not* have a trailing '/'.
    //
    { "default"                                           , wordnet },
#if ZORBA_W3C_TEST_SUITE_THESAURUS_URIS
    { "http://bstore1.example.com/TechnicalThesaurus.xml" , wordnet },
    { "http://bstore1.example.com/UsabilityThesaurus.xml" , wordnet },
#endif
    { "http://wordnet.princeton.edu"                      , wordnet },
  };

  /**
   * Given a thesaurus URI, finds its corresponding thesaurus implementation.
   *
   * @param uri The thesaurus' URI.
   * @return Returns the implementation's type or \c none.
   */
  static type find( zstring const &uri ) {
    static table_entry const *const table_end =
      table + sizeof( table ) / sizeof( table[0] );
    table_entry entry_to_find;
    entry_to_find.te_uri = uri.c_str();
    pair<table_entry const*,table_entry const*> const result =
      ::equal_range( table, table_end, entry_to_find, less_table_entry() );
    return result.first == result.second ? none : result.first->te_type;
  }

} // namespace thesauri_impl

///////////////////////////////////////////////////////////////////////////////

zstring ft_thesaurus::thesauri_directory_;

ft_thesaurus::~ft_thesaurus() {
  // do nothing
}

ft_thesaurus* ft_thesaurus::get( zstring const &uri, iso639_1::type lang,
                                 zstring const &phrase,
                                 zstring const &relationship,
                                 ft_int at_least, ft_int at_most ) {
  zstring const uri_no_slash(
    ascii::ends_with( uri, '/' ) ? uri.substr( 0, uri.size() - 1 ) : uri
  );

  switch ( thesauri_impl::find( uri_no_slash ) ) {
    case thesauri_impl::wordnet:
      return new wordnet::thesaurus(
        phrase, relationship, lang, at_least, at_most
      );
    default:
      return NULL;
  }
}

void ft_thesaurus::set_directory( zstring const &path ) {
  assert( !path.empty() );
  thesauri_directory_ = path;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
