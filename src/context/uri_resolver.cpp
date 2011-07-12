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

#include "uri_resolver.h"
#include <zorba/uri_resolvers.h>

#include <store/api/collection.h>

/***********
 * Constants
 ***********/
// We avoid the "static initialization order fiasco" by initializing both of
// these constants here in the same file. This also makes it easy to ensure
// both strings have the same value.
const zorba::zstring zorba::impl::URIMapper::DENY_ACCESS("[~~Deny Access~~]");
const zorba::String zorba::URIMapper::DENY_ACCESS(zorba::impl::URIMapper::DENY_ACCESS.c_str());


namespace zorba {

namespace impl {

/*************
 * Implementation of the Resource class hierarchy.
 *************/

  Resource::Resource()
  {}

  Resource::~Resource()
  {}

  StreamResource::StreamResource
  (std::auto_ptr<std::istream> aStream, zstring aStreamUrl /* = "" */)
    : Resource(),
      theStream(aStream),
      theStreamUrl(aStreamUrl),
      theHttpStream(0)
  {}
  
  StreamResource::StreamResource
  (HttpStream* aHttpStream, const zstring& aUrl)
  : Resource(),
  theStream(0),
  theStreamUrl(aUrl),
  theHttpStream(aHttpStream)
  {
  }

  StreamResource::~StreamResource()
  {
    if (theHttpStream)
      delete theHttpStream;
  }
  
  std::auto_ptr<std::istream>
  StreamResource::getStream()
  {
    if (theStream.get())
      return theStream;
    else {
      std::auto_ptr<std::istream> res(new std::istream(theHttpStream->getStream().rdbuf()));
      return res;
    }
  }

  zstring
  StreamResource::getStreamUrl()
  {
    if (theStreamUrl == "") {
      return getUrl();
    }
    else {
      return theStreamUrl;
    }
  }

  CollectionResource::CollectionResource
  (const store::Collection_t& aCollection)
    : Resource(),
      theCollection(aCollection)
  {}

  store::Collection_t
  CollectionResource::getCollection()
  {
    return theCollection;
  }


/*************
 * URIMapper is an abstract class, but we have to define its vtbl and
 * base destructor somewhere.
 *************/

  URIMapper::~URIMapper()
  {}

/*************
 * URIResolver is an abstract class, but we have to define its vtbl
 * and base destructor somewhere.
 *************/

  URLResolver::~URLResolver()
  {}

  /*************
   * EntityData is an abstract class, but we have to define its vtbl
   * and base destructor somewhere.
   *************/

  EntityData::~EntityData()
  {}


} /* namespace zorba::impl */

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
