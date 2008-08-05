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

#include <fstream>
#include <sstream>

#include "util/web/web.h"

#include "store/api/item.h"
#include "store/api/collection.h"

#include "store/api/store.h"
#include "system/globalenv.h"
#include "zorbatypes/URI.h"
#include "zorbaerrors/error_manager.h"
#include "context/static_context.h"

namespace zorba {

  store::Item_t
  StandardDocumentURIResolver::resolve(const store::Item_t& aURI,
                                     static_context* aStaticContext)
  {
    store::Item_t lResultDoc;

    if (aURI == NULL)
      return NULL;
    
    xqpStringStore_t lUriString = aURI->getStringValue();

    store::Store& lStore = GENV.getStore();

    xqpString lURIString = xqpString(&*aURI->getStringValue());
    URI lURI(lURIString);

    lResultDoc = lStore.getDocument(lURI.get_uri_text().getStore());
    if (lResultDoc != NULL)
      return lResultDoc;


    if (lURI.get_scheme() == "file") {
#ifdef ZORBA_WITH_FILE_ACCESS // maybe we don't want to allow file access for security reasons (e.g. in a webapp)
      std::ifstream lInStream;
      xqpStringStore_t decodedURI = URI::decode_file_URI(lURI.get_uri_text().getStore());
      lInStream.open(decodedURI->c_str(), std::ios::in);
      if (lInStream.is_open() == false) {
        ZORBA_ERROR_DESC_OSS(FODC0002, "File not found or accessible " << decodedURI);
      }
      
      // parse exception must be caught by the caller
      lResultDoc = lStore.loadDocument(lURI.get_uri_text().getStore(), lInStream);

      // result can't be null, because we already asked the store if he has it
      ZORBA_ASSERT(lResultDoc != NULL);
#else
      ZORBA_ERROR_DESC_OSS(FODC0002, "Can't retrieve a file:// URI " << lURI.get_uri_text());
#endif
    } 
    if (lURI.get_scheme() == "http") {
#ifdef ZORBA_HAVE_CURL_H
      // retrieve web file
      xqp_string xmlString;
      int result = http_get(lURI.get_uri_text().c_str(), xmlString);
      if (result != 0) {
        ZORBA_ERROR_DESC_OSS(FODC0002, "File not found or accessible. Could not make HTTP call");
      }

      std::istringstream iss(xmlString.c_str());

      // parse exception must be caught by the caller
      lResultDoc = lStore.loadDocument(lURI.get_uri_text().getStore(), iss);

      // result can't be null, because we already asked the store if he has it
      ZORBA_ASSERT(lResultDoc != NULL);
#else
      ZORBA_ERROR_DESC_OSS(FODC0002, "Can't retrieve a http:// URI " << lURI.get_uri_text());
#endif
    } 

    if (lResultDoc == NULL) {
      ZORBA_ERROR_DESC_OSS(FODC0002, "Couldn't retrieve document with URI " << lURI.get_uri_text());
    }

    return lResultDoc;
  }

  store::Collection_t 
  StandardCollectionURIResolver::resolve(const store::Item_t& aURI,
          static_context* aStaticContext)
  {
    store::Collection_t lResultCol;

    xqpStringStore_t lUriString = aURI->getStringValue();

    store::Store& lStore = GENV.getStore();

    // maybe the document is stored with the uri that is given by the user
    lResultCol = lStore.getCollection(lUriString);
    if (lResultCol != NULL)
      return lResultCol;

    // check and eventually resolve URI
    // throw FODC0004 if the URI is not valid
    URI lURI;
    try {
      lURI = URI(&*lUriString);
      if (!lURI.is_absolute()) {
        URI lBaseURI(aStaticContext->final_baseuri());
        lURI = URI(lBaseURI, &*lUriString); 
      }
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_DESC_OSS(FODC0004, "URI " << lUriString << " is not valid or could not be resolved. Reason: " 
                           << e.theDescription);
    }

    // try to get it from the store again
    lResultCol = lStore.getCollection(lURI.get_uri_text().getStore());
    return lResultCol;
  }

  std::istream*
  StandardSchemaURIResolver::resolve(const store::Item_t& aURI,
          const std::vector<store::Item_t>& aLocationHints,
          static_context* aStaticContext)
  {
    xqpStringStore_t lResolvedURI = aURI->getStringValue();
    std::auto_ptr<std::istream> schemafile(
      new std::ifstream(URI::decode_file_URI (lResolvedURI)->c_str()));

    // we transfer ownership to the caller
    return schemafile.release();
  }

  std::istream*
  StandardModuleURIResolver::resolve(const store::Item_t& aURI,
          static_context* aStaticContext)
  {
    xqpStringStore_t lResolvedURI = aURI->getStringValue();
    std::auto_ptr<std::istream> modfile(
      new std::ifstream(URI::decode_file_URI (lResolvedURI)->c_str()));

    // we transfer ownership to the caller
    return modfile.release();
  }

} /* namespace zorba */
