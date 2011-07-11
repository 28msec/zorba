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

#include <map>

#include <zorba/config.h>

#include <util/cxx_util.h>
#include <util/fs_util.h>
#include <util/less.h>
#include <util/string_util.h>
#include <util/uri_util.h>
#include <diagnostics/xquery_diagnostics.h>
#include <diagnostics/dict.h>
#include <context/static_context.h>

#include "ft_thesaurus.h"
#ifdef ZORBA_WITH_FILE_ACCESS
#include "thesauri/wn_thesaurus.h"
#endif
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
      impl_map[ "default" ] = DEFAULT;
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
  if ( ztd::split( mapping, '|', &impl_name, uri ) ) {
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

ft_thesaurus::ptr ft_thesaurus::get( zstring const &in_uri,
                                     iso639_1::type lang,
                                     static_context const& sctx ) {
  std::vector<zstring> components;
  // QQQ For now, we use a component URI mapper to return the mapping string.
  // I believe we can eliminate the need for this string, and hence we should
  // be able to call the normal resolve_uri() here in future.
  sctx.get_component_uris(in_uri, impl::EntityData::THESAURUS, components);
  if (components.size() != 1) {
    throw XQUERY_EXCEPTION( err::FTST0018, ERROR_PARAMS( in_uri ) );
  }
  zstring uri;
  thesaurus_impl::type th_impl;
  parse_mapping( components[0], &th_impl, &uri );

  zstring th_path;
  switch ( uri::get_scheme( uri ) ) {
    case uri::file:
    case uri::none:
      th_path = fs::get_normalized_path( uri );
      break;
    default:
      throw XQUERY_EXCEPTION(
        zerr::ZXQP0004_NOT_IMPLEMENTED,
        ERROR_PARAMS( ZED( NonFileThesaurusURI ) )
      );
  }

  ft_thesaurus *result;
  switch ( th_impl ) {
#   ifdef ZORBA_WITH_FILE_ACCESS
    case thesaurus_impl::wordnet:
      result = new wordnet::thesaurus( th_path, lang );
      break;
#   endif /* ZORBA_WITH_FILE_ACCESS */
    case thesaurus_impl::xqftts:
      result = new xqftts::thesaurus( th_path, lang );
      break;
    default:
      throw XQUERY_EXCEPTION( err::FTST0018, ERROR_PARAMS( components[0] ) );
  }
  return ptr( result );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
