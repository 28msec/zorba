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
#include "stdafx.h"

#include <zorba/transcode_stream.h>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "runtime/fetch/fetch.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"

#include "context/static_context.h"
#include "context/uri_resolver.h"


namespace zorba {

/*******************************************************************************
********************************************************************************/
std::auto_ptr<internal::Resource>
getFetchResource(
    const store::Item_t& aUri,
    const store::Item_t& aKind,
    const static_context* aSctx,
    const QueryLoc& aLoc)
{
  internal::EntityData::Kind lKind;
  zstring lKindStr = aKind->getStringValue();

  // Figure out the EntityKind (any better way to do this?)
  if ( ! lKindStr.compare("SOME_CONTENT")) {
    lKind = internal::EntityData::SOME_CONTENT;
  }
  else if ( ! lKindStr.compare("SCHEMA")) {
    lKind = internal::EntityData::SCHEMA;
  }
  else if ( ! lKindStr.compare("MODULE")) {
    lKind = internal::EntityData::MODULE;
  }
#ifndef ZORBA_NO_FULL_TEXT
  else if ( ! lKindStr.compare("THESAURUS")) {
    lKind = internal::EntityData::THESAURUS;
  }
  else if ( ! lKindStr.compare("STOP_WORDS")) {
    lKind = internal::EntityData::STOP_WORDS;
  }
#endif /* ZORBA_NO_FULL_TEXT */
  else {
    throw XQUERY_EXCEPTION(
          zerr::ZXQP0026_INVALID_ENUM_VALUE,
          ERROR_PARAMS(lKindStr, "entityKind"),
          ERROR_LOC(aLoc));
  }

  try {
    // ask the uri mappers and resolvers to give
    // me a resource of specified kind
    zstring lErrorMessage;
    return aSctx->resolve_uri(
      aUri->getStringValue(),
      lKind,
      lErrorMessage);

  } catch (ZorbaException const& e) {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0025_ITEM_CREATION_FAILED,
      ERROR_PARAMS( e.what() ),
      ERROR_LOC( aLoc )
    );
  }
}

/*******************************************************************************
********************************************************************************/
void
FetchContentIterator::destroyStream(std::istream& aStream)
{
  delete &aStream;
}

bool
FetchContentIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t lUri;
  store::Item_t lEntityKind;
  store::Item_t lEncoding;
  zstring lEncodingStr("UTF-8");
  std::auto_ptr<internal::Resource> lRes;
  internal::StreamResource* lStreamRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lUri, theChildren[0].getp(), aPlanState);
  consumeNext(lEntityKind, theChildren[1].getp(), aPlanState);
  consumeNext(lEncoding, theChildren[2].getp(), aPlanState);

  lEncodingStr = lEncoding->getStringValue();

  lRes = getFetchResource(lUri, lEntityKind, theSctx, loc);

  lStreamRes = dynamic_cast<internal::StreamResource*>(lRes.get());
  if ( !lStreamRes ) {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0025_ITEM_CREATION_FAILED,
      ERROR_PARAMS( "Resource not available." ),
      ERROR_LOC( loc )
    );
  }

  if (transcode::is_necessary(lEncodingStr.c_str()))
  {
    if (!transcode::is_supported(lEncodingStr.c_str()))
    {
      throw XQUERY_EXCEPTION(
          zerr::ZXQP0006_UNKNOWN_ENCODING,
          ERROR_PARAMS( lEncodingStr.c_str() ),
          ERROR_LOC( loc )
        );
    }
    transcode::attach(*lStreamRes->getStream(), lEncodingStr.c_str());
  }

  // return the resource in a streamable string. This transfers memory
  // ownership of the istream (via its StreamReleaser) to the StreamableString
  // object, so we then remove the StreamReleaser from the StreamResource.
  GENV_ITEMFACTORY->createStreamableString(
        result,
        *lStreamRes->getStream(),
        lStreamRes->getStreamReleaser(),
        lStreamRes->isStreamSeekable()
  );
  lStreamRes->setStreamReleaser(nullptr);

  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
void
FetchContentBinaryIterator::destroyStream(std::istream& aStream)
{
  delete &aStream;
}

bool
FetchContentBinaryIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t lUri;
  store::Item_t lEntityKind;
  std::auto_ptr<internal::Resource> lRes;
  internal::StreamResource* lStreamRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lUri, theChildren[0].getp(), aPlanState);
  consumeNext(lEntityKind, theChildren[1].getp(), aPlanState);

  lRes = getFetchResource(lUri, lEntityKind, theSctx, loc);

  lStreamRes = dynamic_cast<internal::StreamResource*>(lRes.get());
  if ( !lStreamRes ) {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0025_ITEM_CREATION_FAILED,
      ERROR_PARAMS( "Resource not available." ),
      ERROR_LOC( loc )
    );
  }

  // return the resource in a streamable base64. This transfers memory
  // ownership of the istream (via its StreamReleaser) to the StreamableBase64BinaryItem
  // object, so we then remove the StreamReleaser from the StreamResource.
  GENV_ITEMFACTORY->createStreamableBase64Binary(
        result,
        *lStreamRes->getStream(),
        lStreamRes->getStreamReleaser(),
        lStreamRes->isStreamSeekable(),
        false
  );
  lStreamRes->setStreamReleaser(nullptr);

  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
FetchContentTypeIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  STACK_PUSH(false, state);

  STACK_END(state);
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
