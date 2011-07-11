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
#ifndef ZORBA_URI_RESOLVER_WRAPPERS_H
#define ZORBA_URI_RESOLVER_WRAPPERS_H

// The public API header.
#include <zorba/uri_resolvers.h>

// The internal API header.
#include <context/uri_resolver.h>

#include <zorbatypes/zstring.h>
#include <vector>

/*************
 * Wrapper classes. Because URIMapper and URIResolver are implemented
 * by users, we have to have a separate class which extends the
 * *internal* URIMapper and URLResolver interfaces and delegates back
 * to the user class. This is the reverse of the normal
 * internal/external class delegation split. These are created and
 * managed by the API StaticContext class.
 **************/

namespace zorba {

class URIMapperWrapper : public zorba::impl::URIMapper
{
  public:

  URIMapperWrapper(zorba::URIMapper& aUserMapper);

  virtual ~URIMapperWrapper();

  virtual void mapURI(const zstring& aUri,
    zorba::impl::EntityData const* aEntityData,
    static_context const& aSctx,
    std::vector<zstring>& oUris) throw ();

  virtual zorba::impl::URIMapper::Kind mapperKind() throw ();

  private:

  zorba::URIMapper& theUserMapper;
};

class URLResolverWrapper : public zorba::impl::URLResolver
{
  public:

  URLResolverWrapper(zorba::URLResolver& aUserResolver);

  virtual ~URLResolverWrapper();

  virtual zorba::impl::Resource* resolveURL(const zstring& aUrl,
    zorba::impl::EntityData const* aEntityData);

  private:

  zorba::URLResolver& theUserResolver;
};

} /* namespace zorba */

#endif /* ZORBA_URI_RESOLVER_WRAPPERS_H */
/* vim:set et sw=2 ts=2: */
