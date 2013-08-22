/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#include <zorba/config.h>

#include "doc_uri_heuristics.h"

#include <context/static_context.h>
#include <diagnostics/xquery_exception.h>
#include <util/uri_util.h>
#include <zorbatypes/URI.h>


namespace zorba {

void normalizeInputUri(
    zstring const& aUri,
    static_context* aSctx,
    QueryLoc const& aLoc,
    zstring* aResult)
{
  zstring const lBaseUri = aSctx->get_base_uri();

  try
  {
    // To support the very common (if technically incorrect) use
    // case of users passing local filesystem paths to fn:doc(),
    // we use the following heuristic: IF the base URI has a file:
    // scheme AND the incoming URI has no scheme, we will assume
    // the incoming URI is actually a filesystem path.  QQQ For
    // the moment, we assume any "unknown" schemes are probably
    // Windows drive letters.
    if ((uri::get_scheme(aUri) == uri::none ||
         uri::get_scheme(aUri) == uri::unknown) &&
        uri::get_scheme(lBaseUri) == uri::file)
    {
      try
      {
        // Ok, we assume it's a filesystem path. First normalize it.
        zstring lNormalizedPath = fs::normalize_path(
            aUri,
            zstring(""));
        // QQQ For now, normalize_path() doesn't do what we
        // want when base URI represents a file. So, when the
        // normalized path is relative, we pretend it's a relative
        // URI and resolve it as such.
        if (fs::is_absolute(lNormalizedPath))
        {
          URI::encode_file_URI(lNormalizedPath, *aResult);
        }
        else
        {
  #ifdef WIN32
          ascii::replace_all(lNormalizedPath, '\\', '/');
  #endif
          *aResult = aSctx->resolve_relative_uri(lNormalizedPath, true);
        }
      }
      catch ( std::invalid_argument const &e )
      {
        throw XQUERY_EXCEPTION( err::XPTY0004, ERROR_PARAMS( e.what() ) );
      }
    }
    else
    {
      // We do NOT assume it's a filesystem path; just resolve it.
      *aResult = aSctx->resolve_relative_uri(aUri, true);
    }
  }
  catch (ZorbaException& e)
  {
    if (e.diagnostic() == err::XQST0046)
      // the value of a URILiteral is of nonzero length and is not in the
      // lexical space of xs:anyURI.
      e.set_diagnostic(err::FODC0005);
    else
      e.set_diagnostic(err::FODC0002);

    set_source(e, aLoc);
    throw;
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
