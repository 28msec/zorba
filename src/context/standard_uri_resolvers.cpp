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

#include "context/standard_uri_resolvers.h"

#include <istream>
#include <fstream>
#include <sstream>

#include <zorba/external_module.h>
#include <zorba/module_import_checker.h>
#include <zorba/util/file.h>
#include <zorba/zorbastring.h>

#include "util/string_util.h"
#include "util/uri_util.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/collection.h"

#include "store/api/store.h"
#include "system/globalenv.h"
#include "zorbatypes/URI.h"
#include "zorbaerrors/error_manager.h"
#include "zorbamisc/ns_consts.h"
#include "context/static_context.h"

#include "zorbaerrors/assert.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
store::Item_t StandardDocumentURIResolver::resolve(
    const store::Item_t& aURI,
    static_context* aStaticContext,
    bool validateUri,
    bool replaceDoc)
{
  store::LoadProperties loadProperties;
  loadProperties.setStoreDocument(true);

  store::Item_t lResultDoc;

  if (aURI == NULL)
    return NULL;

  zstring lUriString;
  aURI->getStringValue2(lUriString);

  store::Store& lStore = GENV.getStore();

  zstring lEnableDtdOptionValue;
  store::Item_t lEnDtdQName;
  lStore.getItemFactory()->createQName(lEnDtdQName, ZORBA_OPTIONS_NS, "", ZORBA_OPTION_ENABLE_DTD);
  aStaticContext->lookup_option(lEnDtdQName, lEnableDtdOptionValue);
  loadProperties.setEnableDtd( lEnableDtdOptionValue.compare("true")==0 );

  zstring baseUri = aStaticContext->get_base_uri();

  URI lURI(lUriString, validateUri);

  if (replaceDoc)
    lStore.deleteDocument(lURI.toString());
  else
    lResultDoc = lStore.getDocument(lURI.toString());

  if (lResultDoc != NULL)
    return lResultDoc;

  if (ZSTREQ(lURI.get_scheme(), "file"))
  {
#ifdef ZORBA_WITH_FILE_ACCESS // maybe we don't want to allow file access for security reasons (e.g. in a webapp)
    std::ifstream lInStream;
    zstring decodedURI;
    URI::decode_file_URI(lURI.toString(), decodedURI);

#ifndef WIN32
    lInStream.open(decodedURI.c_str(), std::ios::in);
#else
    WCHAR *wdecodedURI;
    wdecodedURI = new WCHAR[decodedURI.length() + 10];
    if(MultiByteToWideChar(CP_UTF8, 0, decodedURI.c_str(), -1, wdecodedURI, decodedURI.length()+10) == 0)
    {
      MultiByteToWideChar(CP_ACP, 0, decodedURI.c_str(), -1, wdecodedURI, decodedURI.length()+10);
    }
    lInStream.open(wdecodedURI, std::ios::in);
    delete[] wdecodedURI;
#endif
    if (lInStream.is_open() == false)
    {
      throw XQUERY_EXCEPTION(
        err::FODC0002, ERROR_PARAMS( decodedURI, ZED( FileNotFoundOrReadable ) )
      );
    }

    // parse exception must be caught by the caller
    lResultDoc = lStore.loadDocument(baseUri, lURI.toString(), lInStream, loadProperties);

    // result can't be null, because we already asked the store if he has it
    ZORBA_ASSERT(lResultDoc != NULL);
#else
    throw XQUERY_EXCEPTION( err::FODC0002, ERROR_PARAMS( lURI ) );
#endif
  }
  else if (ZSTREQ(lURI.get_scheme(), "http") ||
           ZSTREQ(lURI.get_scheme(), "https"))
  {
#ifdef ZORBA_WITH_REST
    // retrieve web file
    std::stringstream iss;
    try {
      uri::fetch(lURI.toString(), iss);
    }
    catch ( uri::exception const &e ) {
      throw XQUERY_EXCEPTION(
        err::FODC0002, ERROR_PARAMS( lURI, e.what() )
      );
    }

    // parse exception must be caught by the caller
    lResultDoc = lStore.loadDocument(baseUri, lURI.toString(), iss, loadProperties);

    // result can't be null, because we already asked the store if he has it
    ZORBA_ASSERT(lResultDoc != NULL);
#else
    throw XQUERY_EXCEPTION( err::FODC0002, ERROR_PARAMS( lURI ) );
#endif
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FODC0002,
      ERROR_PARAMS( lURI, ZED( BadURIScheme_3 ), lURI.get_scheme() )
    );
  }

  if (lResultDoc == NULL)
  {
    throw XQUERY_EXCEPTION( err::FODC0002, ERROR_PARAMS( lURI ) );
  }

  return lResultDoc;
}


/*******************************************************************************

********************************************************************************/
store::Collection_t
StandardCollectionURIResolver::resolve(
    const store::Item_t& aURI,
    static_context* aStaticContext)
{
  store::Collection_t lResultCol;

  zstring lUriString = aURI->getStringValue();

  store::Store& lStore = GENV.getStore();

  // check and eventually resolve URI
  // throw FODC0004 if the URI is not valid
  URI lURI;

  try
  {
    lURI = URI(lUriString);

    if (!lURI.is_absolute())
    {
      URI lBaseURI(aStaticContext->get_base_uri());
      lURI = URI(lBaseURI, lUriString);
    }
  }
  catch (ZorbaException const& e)
  {
    throw XQUERY_EXCEPTION(
      err::FODC0004, ERROR_PARAMS( lUriString, e.what() )
    );
  }

  // try to get it from the store again
  lResultCol = lStore.getUriCollection(lURI.toString());
  return lResultCol;
}


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
