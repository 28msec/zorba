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
const zorba::zstring zorba::internal::URIMapper::DENY_ACCESS("[~~Deny Access~~]");
const zorba::String zorba::URIMapper::DENY_ACCESS(zorba::internal::URIMapper::DENY_ACCESS.c_str());


namespace zorba {

namespace internal {

/*************
 * Implementation of the Resource class hierarchy.
 *************/

  Resource::Resource()
  {}

  Resource::~Resource()
  {}

  StreamResource::StreamResource
  (std::istream* aStream, StreamReleaser aStreamReleaser,
   zstring aStreamUrl /* = "" */)
    : Resource(),
      theStream(aStream),
      theStreamReleaser(aStreamReleaser),
      theStreamUrl(aStreamUrl)
  {}
  
  StreamResource::~StreamResource()
  {
    if (theStreamReleaser)
      theStreamReleaser(theStream);
  }
  
  std::istream*
  StreamResource::getStream()
  {
    return theStream;
  }

  StreamReleaser
  StreamResource::getStreamReleaser()
  {
    return theStreamReleaser;
  }

  void
  StreamResource::setStreamReleaser(StreamReleaser aStreamReleaser)
  {
    theStreamReleaser = aStreamReleaser;
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
 * Implementation of EntityData hierarchy.
 *************/
  EntityData::EntityData(EntityData::Kind aKind)
    : theKind(aKind)
  {
  }

  EntityData::Kind EntityData::getKind() const
  {
    return theKind;
  }

  EntityData::~EntityData()
  {
  }

  ThesaurusEntityData::ThesaurusEntityData(locale::iso639_1::type aLang)
    : EntityData(EntityData::THESAURUS),
      theLang(aLang)
  {
  }

  locale::iso639_1::type ThesaurusEntityData::getLanguage() const
  {
    return theLang;
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

} /* namespace zorba::impl */

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
