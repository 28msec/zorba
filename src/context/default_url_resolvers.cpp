/*
 * Copyright 2006-2010 The FLWOR Foundation.
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


#include "context/default_url_resolvers.h"
#include "util/uri_util.h"
#include "util/http_util.h"
#include "util/fs_util.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/collection.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace zorba {

namespace impl {

/******
 * http: (and https: and ftp:) URL resolver.
 ******/

Resource*
HTTPURLResolver::resolveURL
(zstring const& aUrl, EntityData const* aEntityData)
{
  uri::scheme lScheme = uri::get_scheme(aUrl);
  switch (lScheme) {
    case uri::http:
    case uri::https:
    case uri::ftp:
      // Fall through to actual implementation
      break;
    default:
      // We don't implement other schemes
      return NULL;
  }
  try {
    std::auto_ptr<HttpStream> lStream(new HttpStream(aUrl));
    lStream->init();
    // Take ownership of the istream and pass it to the StreamResource
    StreamResource* lResource =
        new StreamResource(&(lStream->getStream()), lStream->getStreamReleaser());
    lStream->setStreamReleaser(nullptr);
    return lResource;
  } catch (...) {
    throw os_error::exception("", aUrl.c_str(), "Could not create stream resource");
  }
}


/******
 * file: URL resolver.
 ******/

static void fileStreamReleaser(std::istream* aStream)
{
  delete aStream;
}

Resource*
FileURLResolver::resolveURL
(zstring const& aUrl, EntityData const* aEntityData)
{
  uri::scheme lScheme = uri::get_scheme(aUrl);
  if (lScheme != uri::file) {
    return NULL;
  }
  zstring lPath = fs::get_normalized_path(aUrl);
  if (fs::get_type(lPath) == fs::file) {
    std::ifstream* lStream = new std::ifstream(lPath.c_str());
    return new StreamResource(lStream, &fileStreamReleaser);
  }
  return NULL;
}

/******
 * collection: URL resolver.
 ******/

ZorbaCollectionURLResolver::~ZorbaCollectionURLResolver()
{
}

Resource*
ZorbaCollectionURLResolver::resolveURL
(zstring const& aUrl, EntityData const* aEntityData)
{
  if (aEntityData->getKind() != impl::EntityData::COLLECTION)
    return NULL;

  store::Item_t lName;
  GENV_STORE.getItemFactory()->createQName(lName, aUrl.c_str(), "", "zorba-internal-name-for-w3c-collections");
  store::Collection_t lColl = GENV_STORE.getCollection(lName.getp(), true);
  if ( lColl == NULL ) {
    return NULL;
  } else {
    return new CollectionResource(lColl);
  }
}

} /* namespace zorba::impl */

} /* namespace zorba */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
