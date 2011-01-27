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

#include <map>

#include <zorba/config.h>

#include "util/fs_util.h"
#include "util/less.h"
#include "util/string_util.h"
#include "util/uri_util.h"
#ifndef ZORBA_WITH_FILE_ACCESS
#include "zorbaerrors/error_manager.h"
#endif

#include "ft_thesaurus.h"
#include "thesauri/wn_thesaurus.h"
#include "thesauri/xqftts_thesaurus.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * The "statically known thesauri" implementations.
 */
namespace thesaurus_impl {

  enum type {
    unknown,
    wordnet,
    xqftts
  };
  type const DEFAULT = wordnet;

  /**
   * Given a thesaurus implementation name, finds its corresponding type.
   *
   * @param name The thesaurus implementation's name.
   * @return Returns the implementation's type or \c unknown.
   */
  static type find( zstring const &name ) {
    typedef map<char const*,type> impl_map_t;
    static impl_map_t impl_map;
    if ( impl_map.empty() ) {
      impl_map[ "default" ] = wordnet;
      impl_map[ "wordnet" ] = wordnet;
      impl_map[ "xqftts"  ] = xqftts;
    }
    impl_map_t::const_iterator const result = impl_map.find( name.c_str() );
    return result != impl_map.end() ? result->second : unknown;
  }

} // namespace thesaurus_impl

///////////////////////////////////////////////////////////////////////////////

/**
 * Parses a thesaurus mapping string.  A mapping string is of the form:
 *
 *  [implementation_name|]URI
 *
 * @param mapping The mapping to parse.
 * @param t A pointer to receive the implementation type.
 * @param uri A pointer to the string to receive the URI.
 */
static void parse_mapping( zstring const &mapping, thesaurus_impl::type *t,
                           zstring *uri ) {
  zstring impl_name;
  if ( split( mapping, '|', &impl_name, uri ) ) {
    *t = thesaurus_impl::find( impl_name );
  } else {
    *t = thesaurus_impl::DEFAULT;
    *uri = mapping;
  }
}

///////////////////////////////////////////////////////////////////////////////

ft_thesaurus::~ft_thesaurus() {
  // do nothing
}

ft_thesaurus* ft_thesaurus::get( zstring const &mapping, iso639_1::type lang,
                                 zstring const &phrase,
                                 zstring const &relationship,
                                 ft_int at_least, ft_int at_most ) {
  thesaurus_impl::type th_impl;
  zstring uri;
  parse_mapping( mapping, &th_impl, &uri );

  zstring th_path;
  switch ( uri::get_scheme( uri ) ) {
    case uri::file:
    case uri::none:
#     ifdef ZORBA_WITH_FILE_ACCESS
      th_path = fs::get_normalized_path( uri );
      break;
#     else
      ZORBA_ERROR( XQP0017_FILE_ACCESS_DISABLED );
#     endif /* ZORBA_WITH_FILE_ACCESS */
    default:
      ZORBA_ERROR_DESC(
        XQP0015_SYSTEM_NOT_YET_IMPLEMENTED, "non-file thesaurus URI"
      );
  }

  switch ( th_impl ) {
    case thesaurus_impl::wordnet:
      return new wordnet::thesaurus(
        th_path, lang, phrase, relationship, at_least, at_most
      );
    case thesaurus_impl::xqftts:
      return new xqftts::thesaurus(
        th_path, lang, phrase, relationship, at_least, at_most
      );
    default:
      return NULL;
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
