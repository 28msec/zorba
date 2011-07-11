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

  class EntityDataWrapper : public EntityData
  {
  public:
    static EntityDataWrapper const* create(impl::EntityData::Kind aKind) {
      // More ugly: Create a public-API EntityData with the same Entity Kind,
      // but only if it's one of the publicly-supported kinds
      switch (aKind) {
      case impl::EntityData::MODULE:
        return new EntityDataWrapper(EntityData::MODULE);
      case impl::EntityData::SCHEMA:
        return new EntityDataWrapper(EntityData::SCHEMA);
      case impl::EntityData::THESAURUS:
        return new EntityDataWrapper(EntityData::THESAURUS);
      case impl::EntityData::STOP_WORDS:
        return new EntityDataWrapper(EntityData::STOP_WORDS);
      case impl::EntityData::COLLECTION:
        return new EntityDataWrapper(EntityData::COLLECTION);
      case impl::EntityData::DOCUMENT:
        return new EntityDataWrapper(EntityData::DOCUMENT);
      default:
        return NULL;
      }
    }

    virtual EntityData::Kind getKind() const throw() {
      return theKind;
    }

  private:
    EntityDataWrapper(EntityData::Kind aKind)
      : theKind(aKind)
    {}

    EntityData::Kind const theKind;
  };

  URIMapperWrapper::URIMapperWrapper(zorba::URIMapper& aUserMapper)
    : theUserMapper(aUserMapper)
  {}

  URIMapperWrapper::~URIMapperWrapper()
  {}

  void
  URIMapperWrapper::mapURI
  (const zstring& aUri,
    impl::EntityData const* aEntityData,
    static_context const& aSctx,
    std::vector<zstring>& oUris) throw ()
  {
    std::auto_ptr<const EntityDataWrapper> lDataWrap
        (EntityDataWrapper::create(aEntityData->getKind()));
    if (lDataWrap.get() == NULL) {
      return;
    }

    std::vector<zorba::String> lUserUris;
    // QQQ should public API have a StaticContext on it?
    theUserMapper.mapURI(zorba::String(aUri.c_str()),
      lDataWrap.get(), lUserUris);
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
    impl::EntityData const* aEntityData)
  {
    std::auto_ptr<const EntityDataWrapper> lDataWrap
        (EntityDataWrapper::create(aEntityData->getKind()));
    if (lDataWrap.get() == NULL) {
      return NULL;
    }

    // Take memory ownership of the user's Resource
    std::auto_ptr<Resource> lUserPtr
      (theUserResolver.resolveURL(zorba::String(aUrl.c_str()), lDataWrap.get()));
    if (lUserPtr.get() != NULL) {
      // This will get a bit more complicated when we publicly support more than
      // one kind of Resource subclass.
      StreamResource* lUserStream = dynamic_cast<StreamResource*>(lUserPtr.get());
      if (lUserStream != NULL) {
        return new impl::StreamResource(lUserStream->getStream());
      }
      else {
        assert(false);
      }
    }
    return NULL;
  }
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
