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

#include "uri_resolver_wrappers.h"
#include "unmarshaller.h"

namespace zorba
{

  URIMapperWrapper::URIMapperWrapper(zorba::URIMapper& aUserMapper)
    : theUserMapper(aUserMapper)
  {}

  URIMapperWrapper::~URIMapperWrapper()
  {}

  void
  URIMapperWrapper::mapURI
  (const zstring& aUri,
    impl::Resource::EntityType aEntityType,
    static_context const& aSctx,
    std::vector<zstring>& oUris) throw ()
  {
    std::vector<zorba::String> lUserUris;
    // QQQ should public API have a StaticContext on it?
    theUserMapper.mapURI(zorba::String(aUri.c_str()),
      static_cast<Resource::EntityType>(aEntityType),
      lUserUris);
    std::vector<zorba::String>::iterator iter;
    for (iter = lUserUris.begin(); iter != lUserUris.end(); iter++) {
      oUris.push_back(Unmarshaller::getInternalString(*iter));
    }
  }

  impl::URIMapper::Kind
  URIMapperWrapper::mapperKind() throw ()
  {
    // Still so ugly.
    switch (theUserMapper.mapperKind()) {
      case URIMapper::COMPONENT:
        return impl::URIMapper::COMPONENT;
      case URIMapper::CANDIDATE:
        return impl::URIMapper::CANDIDATE;
    }

    assert(false);
    // dummy return
    return impl::URIMapper::COMPONENT;
  }


  URLResolverWrapper::URLResolverWrapper(zorba::URLResolver& aUserResolver)
    : theUserResolver(aUserResolver)
  {}

  URLResolverWrapper::~URLResolverWrapper()
  {}

  impl::Resource*
  URLResolverWrapper::resolveURL
  (const zstring& aUrl,
    impl::Resource::EntityType aEntityType)
  {
    // Take memory ownership of the user's Resource
    std::auto_ptr<Resource> lUserResourcePtr
      (theUserResolver.resolveURL(zorba::String(aUrl.c_str()),
        static_cast<Resource::EntityType>(aEntityType)));
    Resource* lUserResource = lUserResourcePtr.get();
    if (lUserResource != NULL) {
      // This is just so ugly.
      switch (lUserResource->getKind()) {
        case Resource::STREAM:
          return new impl::StreamResource
            (static_cast<StreamResource*>(lUserResource)->getStream());
        default:
          assert(false);
      }
    }
    return NULL;
  }
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
