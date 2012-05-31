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

#include <zorba/thesaurus.h>

#include "runtime/full_text/thesaurus.h"

#include "thesaurus_wrappers.h"
#include "unmarshaller.h"
#include "uri_resolver_wrappers.h"
#include "uriresolverimpl.h"

namespace zorba
{
  // "Convenience" class for passing an internal EntityData object to
  // external mappers/resolvers.
  class EntityDataWrapper : public EntityData
  {
  public:
    static EntityDataWrapper const* create(internal::EntityData const* aData) {
      // More ugly: Create a public-API EntityData with the same Entity Kind,
      // but only if it's one of the publicly-supported kinds
      switch (aData->getKind()) {
      case internal::EntityData::MODULE:
        return new EntityDataWrapper(EntityData::MODULE);
      case internal::EntityData::SCHEMA:
        return new EntityDataWrapper(EntityData::SCHEMA);
#ifndef ZORBA_NO_FULL_TEXT
      case internal::EntityData::THESAURUS:
        return new EntityDataWrapper(EntityData::THESAURUS);
      case internal::EntityData::STOP_WORDS:
        return new EntityDataWrapper(EntityData::STOP_WORDS);
#endif /* ZORBA_NO_FULL_TEXT */
      case internal::EntityData::COLLECTION:
        return new EntityDataWrapper(EntityData::COLLECTION);
      case internal::EntityData::DOCUMENT:
        return new EntityDataWrapper(EntityData::DOCUMENT);
      case internal::EntityData::SOME_CONTENT:
        return new EntityDataWrapper(EntityData::SOME_CONTENT);
      default:
        return NULL;
      }
    }

    virtual EntityData::Kind getKind() const {
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
    internal::EntityData const* aEntityData,
    static_context const& aSctx,
    std::vector<zstring>& oUris)
  {
    std::auto_ptr<const EntityDataWrapper> lDataWrap
        (EntityDataWrapper::create(aEntityData));
    if (lDataWrap.get() == NULL) {
      return;
    }

    std::vector<zorba::String> lUserUris;
    // QQQ should public API have a StaticContext on it?
    theUserMapper.mapURI(zorba::String(aUri.c_str()), lDataWrap.get(),
                         lUserUris);
    std::vector<zorba::String>::iterator iter;
    for (iter = lUserUris.begin(); iter != lUserUris.end(); iter++) {
      oUris.push_back(Unmarshaller::getInternalString(*iter));
    }
  }

  internal::URIMapper::Kind
  URIMapperWrapper::mapperKind()
  {
    // Still so ugly.
    switch (theUserMapper.mapperKind()) {
      case URIMapper::COMPONENT:
        return internal::URIMapper::COMPONENT;
      case URIMapper::CANDIDATE:
        return internal::URIMapper::CANDIDATE;
    }

    assert(false);
    // dummy return
    return internal::URIMapper::COMPONENT;
  }


  URLResolverWrapper::URLResolverWrapper(zorba::URLResolver& aUserResolver)
    : theUserResolver(aUserResolver)
  {}

  URLResolverWrapper::~URLResolverWrapper()
  {}

  internal::Resource*
  URLResolverWrapper::resolveURL
  (const zstring& aUrl,
    internal::EntityData const* aEntityData)
  {
    std::auto_ptr<const EntityDataWrapper> lDataWrap
        (EntityDataWrapper::create(aEntityData));
    if (lDataWrap.get() == NULL) {
      return NULL;
    }

    internal::Resource* lRetval = nullptr;
    // Get the user's Resource.
    Resource::ptr lUserPtr
      (theUserResolver.resolveURL(zorba::String(aUrl.c_str()),
                                  lDataWrap.get()));
    if (lUserPtr.get() != NULL) {
      // Sooo ugly... have to try down-casting to each subclass in turn to
      // figure out what kind of Resource we've got.
      StreamResourceImpl* lUserStream =
          dynamic_cast<StreamResourceImpl*>(lUserPtr.get());
      if (lUserStream != NULL) {
        // Here we pass memory ownership of the std::istream to the internal
        // StreamResource, by passing the StreamReleaser to it and setting the
        // user's StreamResource's StreamReleaser to nullptr.
        lRetval = new internal::StreamResource(lUserStream->getStream(),
                                           lUserStream->getStreamReleaser(),
                                           "",
                                           lUserStream->isStreamSeekable());
        lUserStream->setStreamReleaser(nullptr);
      }
#ifndef ZORBA_NO_FULL_TEXT
      else {
        ThesaurusProvider* lUserThesaurusProvider =
          dynamic_cast<ThesaurusProvider*>(lUserPtr.get());
        if (lUserThesaurusProvider) {
          // Here we pass memory ownership of the actual ThesaurusProvider to
          // the internal ThesaurusWrapper.
          lRetval = new internal::ThesaurusProviderWrapper
              (lUserThesaurusProvider);
        }
        else {
          assert(false);
        }
      }
#endif /* ZORBA_NO_FULL_TEXT */
    }
    return lRetval;
  }
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
