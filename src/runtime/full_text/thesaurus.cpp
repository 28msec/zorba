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
#include <zorba/internal/cxx_util.h>

#include "context/default_url_resolvers.h"
#include "context/static_context.h"
#include "diagnostics/dict.h"
#include "diagnostics/xquery_diagnostics.h"
#include "util/fs_util.h"
#include "util/less.h"
#include "util/string_util.h"
#include "util/uri_util.h"

#include "thesaurus.h"
#ifdef ZORBA_WITH_FILE_ACCESS
# include "thesauri/wn_thesaurus.h"
# include "zorbatypes/URI.h"
#endif
#include "thesauri/xqftts_thesaurus.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {
namespace internal {

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
   * Given a thesaurus implementation name (as identified by the URI scheme),
   * finds its corresponding type.
   *
   * @param name The thesaurus implementation's name.
   * @return Returns the implementation's type or \c unknown.
   */
  static type find( zstring const &name ) {
    typedef map<char const*,type> impl_map_t;
    static impl_map_t impl_map;
    if ( impl_map.empty() ) {
      impl_map[ "wordnet" ] = wordnet;
      impl_map[ "xqftts"  ] = xqftts;
    }
    impl_map_t::const_iterator const result = impl_map.find( name.c_str() );
    return result != impl_map.end() ? result->second : unknown;
  }

} // namespace thesaurus_impl

///////////////////////////////////////////////////////////////////////////////

Thesaurus::iterator::~iterator() {
  // out-of-line since it's virtual
}

Thesaurus::~Thesaurus() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

Resource*
ThesaurusURLResolver::resolveURL( zstring const &url, EntityData const *data ) {
  // Only resolve thesaurus URLs
  if ( data->getKind() != internal::EntityData::THESAURUS )
    return nullptr;

  zstring const url_copy(
    url == "##default" ? "wordnet://wordnet.princeton.edu/": url
  );

  zstring scheme_name;
  if ( !uri::get_scheme( url_copy, &scheme_name ) )
    return nullptr;

  switch ( thesaurus_impl::find( scheme_name ) ) {
    case thesaurus_impl::xqftts:
#   ifdef ZORBA_WITH_FILE_ACCESS
    {
      // Currently, we presume that an "xqftts:" URL should be used exactly
      // like a "file:" URL.
      //
      zstring t_uri( url_copy );
      t_uri.replace( 0, 6, "file" );    // xqftts -> file
      try {
        zstring const t_path( fs::normalize_path( t_uri ) );
        return new xqftts::provider( t_path );
      }
      catch ( invalid_argument const &e ) {
        throw XQUERY_EXCEPTION( err::XPTY0004, ERROR_PARAMS( e.what() ) );
      }
    }
#   endif /* ZORBA_WITH_FILE_ACCESS */
    case thesaurus_impl::wordnet:
#   ifdef ZORBA_WITH_FILE_ACCESS
    {
      // Wordnet, on the other hand, needs to find its data file in Zorba's
      // library path using the mangled form of the original URI.  So, mangle
      // here for convenience.
      //
      URI const t_uri( url_copy );
      zstring const t_path( t_uri.toPathNotation() );
      return new wordnet::provider( t_path );
    }
#   endif /* ZORBA_WITH_FILE_ACCESS */
#   ifndef ZORBA_WITH_FILE_ACCESS
      throw XQUERY_EXCEPTION( zerr::ZXQP0017_FILE_ACCESS_DISABLED );
#   endif /* ZORBA_WITH_FILE_ACCESS */
    default:
      throw XQUERY_EXCEPTION( err::FTST0018, ERROR_PARAMS( url ) );
  }
  return nullptr;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
