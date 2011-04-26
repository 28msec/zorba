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


#include "context/default_url_resolvers.h"
#include "util/uri_util.h"
#include "util/fs_util.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace zorba {

namespace impl {

/******
 * http: (and https: and ftp:) URL resolver.
 ******/

ZorbaHTTPURLResolver::~ZorbaHTTPURLResolver()
{
}


Resource*
ZorbaHTTPURLResolver::resolveURL
(zstring const& aUrl, Resource::EntityType aEntityType)
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
  // QQQ This is a horrible hack, but I can't figure out a way around
  // it. Several W3C tests attempt to access schema URIs on
  // example.com. Those URIs redirect to a page on iana.org which has
  // DTD references, which Xerces also tries to load - but they're
  // extremely slow. I do not know why the old code (which used
  // Xerces's own URLInputSource) did not have the same problem.
  if (ascii::begins_with(aUrl, "http://example.com") ||
    ascii::begins_with(aUrl, "http://www.example.com"))
  {
    throw uri::fetch_exception("illegal host");
  }
  std::auto_ptr<std::stringstream> lStream(new std::stringstream());
  uri::fetch(aUrl.c_str(), (*lStream.get()));
  return new StreamResource(static_cast<std::auto_ptr<std::istream> >(lStream));
}


/******
 * file: URL resolver.
 ******/

ZorbaFileURLResolver::~ZorbaFileURLResolver()
{
}

Resource*
ZorbaFileURLResolver::resolveURL
(zstring const& aUrl, Resource::EntityType aEntityType)
{
  uri::scheme lScheme = uri::get_scheme(aUrl);
  if (lScheme != uri::file) {
    return NULL;
  }
  zstring lPath = fs::get_normalized_path(aUrl);
  if (fs::get_type(lPath) != fs::non_existent) {
    std::auto_ptr<std::ifstream> lStream(new std::ifstream());
    lStream->open(lPath.c_str());
    return new StreamResource
      (static_cast<std::auto_ptr<std::istream> >(lStream));
  }
  return NULL;
}

} /* namespace zorba::impl */

} /* namespace zorba */

/*
 * Local variables:
 * mode: c++
 * End:
 */
