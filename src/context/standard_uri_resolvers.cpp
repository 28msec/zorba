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

#include "context/standard_uri_resolvers.h"

#include <istream>
#include <fstream>
#include <sstream>

#include <zorba/external_module.h>
#include <zorba/module_import_checker.h>
#include <zorba/util/file.h>
#include <zorba/zorba_string.h>

#include "util/string_util.h"
#include "util/uri_util.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/collection.h"

#include "store/api/store.h"
#include "system/globalenv.h"
#include "zorbatypes/URI.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbamisc/ns_consts.h"
#include "context/static_context.h"

#include "diagnostics/assert.h"

namespace zorba
{

#ifndef ZORBA_NO_FULL_TEXT
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StandardFullTextURIResolver                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
zstring
StandardFullTextURIResolver::resolve(
    const store::Item_t& aURI,
    static_context* aStaticContext)
{
  // 2. check the user's resolvers
  std::vector<InternalFullTextURIResolver*> lResolvers;
  aStaticContext->get_thesaurus_uri_resolvers(lResolvers);
  for (std::vector<InternalFullTextURIResolver*>::const_iterator lIter =
      lResolvers.begin(); lIter != lResolvers.end(); ++lIter)
  {
    zstring lResult = (*lIter)->resolve(aURI, aStaticContext);
    if (lResult != "")
    {
      return lResult;
    }
  }

  // 3. treat the URI as URL and check if a file is in the
  // filesystem or on the web
  zstring lResolvedURI;
  aURI->getStringValue2(lResolvedURI);

  if (lResolvedURI.compare(0, 7, "file://") == 0)
  {
    // maybe we don't want to allow file access for security reasons (e.g. in a webapp)
#ifdef ZORBA_WITH_FILE_ACCESS
    zstring filepath;
    URI::decode_file_URI(lResolvedURI, filepath);

    File_t lFile = File::createFile(filepath.c_str());
    if (lFile->exists()) {
      return lResolvedURI.str();
    } else {
      throw XQUERY_EXCEPTION(
        err::XQST0059,
        ERROR_PARAMS( aURI->getStringValue(), lResolvedURI )
      );
    }
#endif /* ZORBA_WITH_FILE_ACCESS */
  }

  return aURI->getStringValue().str();
}
#endif /* ZORBA_NO_FULL_TEXT */


} // namespace zorba
/* vim:set et sw=2 ts=2: */
