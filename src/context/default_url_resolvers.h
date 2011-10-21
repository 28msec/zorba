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
#pragma once
#ifndef ZORBA_DEFAULT_URL_RESOLVERS_H
#define ZORBA_DEFAULT_URL_RESOLVERS_H


/**
 * This file contains the Zorba built-in URI Mappers and URL
 * Resolvers.  This comprises the file: and http: URLResolvers and the
 * module-versioning and automatic filesystem URIMappers.
 */

#include <memory>
#include <istream>
#include <zorbatypes/zstring.h>
#include "context/uri_resolver.h"

namespace zorba {

namespace internal {

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief http: URL Resolver.
 */
class HTTPURLResolver : public internal::URLResolver
{
public:

  virtual Resource* resolveURL(zstring const& aUrl,
    EntityData const* aEntityData);
};

/**
 * @brief file: URL Resolver.
 */
class FileURLResolver : public internal::URLResolver
{
public:

  virtual Resource* resolveURL(zstring const& aUrl,
    EntityData const* aEntityData);
};

/**
 */
class ZorbaCollectionURLResolver : public internal::URLResolver
{
public:

  virtual ~ZorbaCollectionURLResolver();

  virtual Resource* resolveURL(zstring const& aUrl,
    EntityData const* aEntityData);
};

#ifndef ZORBA_NO_FULL_TEXT

class ThesaurusURLResolver : public URLResolver
{
public:
  // inherited
  Resource* resolveURL( zstring const &aUrl, EntityData const* );
};

#endif /* ZORBA_NO_FULL_TEXT */

///////////////////////////////////////////////////////////////////////////////

} /* namespace zorba::impl */

} /* namespace zorba */

#endif /* ZORBA_DEFAULT_URL_RESOLVERS_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
