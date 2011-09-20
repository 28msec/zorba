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

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "zorbatypes/URI.h"

#include "system/globalenv.h"

#include "runtime/store/documents.h"

#include "context/static_context.h"

#include "store/api/pul.h"
#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"

namespace zorba {

/*******************************************************************************
  declare updating function
  put($uri as xs:string, $doc as xs:document-node()) as empty-sequence()
********************************************************************************/
bool PutDocumentIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  zstring       lRetrievedUriString;
  zstring       lResolvedUriString;
  store::Item_t lUri;
  store::Item_t lDoc;
  store::Item_t lResolvedUriItem;
  std::auto_ptr<store::PUL> lPul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lUri, theChildren[0].getp(), aPlanState);

  // absolutize retrieved uri
  try {
    lUri->getStringValue2(lRetrievedUriString);
    lResolvedUriString = theSctx->resolve_relative_uri(lRetrievedUriString, true);
  } catch (ZorbaException const&) {
    throw XQUERY_EXCEPTION(
      err::FODC0004,
      ERROR_PARAMS( lResolvedUriString, ZED( NoResolveRelativeURI ) ),
      ERROR_LOC( loc )
    );
  }

  // check if document already exists in the store
  if (GENV_STORE.getDocument(lResolvedUriString) != NULL) {
    throw XQUERY_EXCEPTION(
      zerr::ZAPI0020_DOCUMENT_ALREADY_EXISTS,
      ERROR_PARAMS( lResolvedUriString ),
      ERROR_LOC( loc )
    );
  }

  // create the pul and add the primitive
  GENV_ITEMFACTORY->createAnyURI(lResolvedUriItem, lResolvedUriString);

  lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  consumeNext(lDoc, theChildren[1].getp(), aPlanState);
  lPul->addCreateDocument(&loc, lResolvedUriItem, lDoc);

  result = lPul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

/*******************************************************************************
  declare updating function
  remove($uri as xs:string) as empty-sequence()
********************************************************************************/
bool RemoveDocumentIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  zstring       lRetrievedUriString;
  zstring       lResolvedUriString;
  store::Item_t lUri;
  store::Item_t lResolvedUriItem;
  std::auto_ptr<store::PUL> lPul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lUri, theChildren[0].getp(), aPlanState);

  // absolutize retrieved uri
  try {
    lUri->getStringValue2(lRetrievedUriString);
    lResolvedUriString = theSctx->resolve_relative_uri(lRetrievedUriString, true);
  } catch (ZorbaException const&) {
    throw XQUERY_EXCEPTION(
      err::FODC0004,
      ERROR_PARAMS( lResolvedUriString, ZED( NoResolveRelativeURI ) ),
      ERROR_LOC( loc )
    );
  }

  // check if document exists in the store
  if (GENV_STORE.getDocument(lResolvedUriString) == NULL) {
    throw XQUERY_EXCEPTION(
      zerr::ZXQD0002_DOCUMENT_NOT_VALID,
      ERROR_PARAMS( lResolvedUriString, ZED( NoURIInStore ) ),
      ERROR_LOC( loc )
    );
  }

  // create the pul and add the primitive
  GENV_ITEMFACTORY->createAnyURI(lResolvedUriItem, lResolvedUriString);

  lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  lPul->addDeleteDocument(&loc, lResolvedUriItem);

  result = lPul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

/*******************************************************************************
  declare function
  document($uri as xs:string) as document-node()
********************************************************************************/
bool RetrieveDocumentIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  zstring       lRetrievedUriString;
  zstring       lResolvedUriString;
  store::Item_t lUri;
  store::Item_t lResolvedUriItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lUri, theChildren[0].getp(), aPlanState);

  // absolutize retrieved uri
  try {
    lUri->getStringValue2(lRetrievedUriString);
    lResolvedUriString = theSctx->resolve_relative_uri(lRetrievedUriString, true);
  } catch (ZorbaException const&) {
    throw XQUERY_EXCEPTION(
      err::FODC0004,
      ERROR_PARAMS( lResolvedUriString, ZED( NoResolveRelativeURI ) ),
      ERROR_LOC( loc )
    );
  }

  // check if document exists in the store
  if ((result = GENV_STORE.getDocument(lResolvedUriString)) == NULL) {
    throw XQUERY_EXCEPTION(
      zerr::ZXQD0002_DOCUMENT_NOT_VALID,
      ERROR_PARAMS( lResolvedUriString, ZED( NoURIInStore ) ),
      ERROR_LOC( loc )
    );
  }

  STACK_PUSH(true, state);

  STACK_END(state);
}

/*******************************************************************************
  declare function
  available-documents() as xs:string*
********************************************************************************/
AvailableDocumentsIteratorState::~AvailableDocumentsIteratorState()
{
  if ( theNameIterator != NULL ) 
  {
    theNameIterator->close();
    theNameIterator = NULL;
  }
}


void AvailableDocumentsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theNameIterator = NULL;
}


void AvailableDocumentsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( theNameIterator != NULL ) {
    theNameIterator->close();
    theNameIterator = NULL;
  }
}


bool AvailableDocumentsIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  AvailableDocumentsIteratorState* state;
  DEFAULT_STACK_INIT(AvailableDocumentsIteratorState, state, aPlanState);

  state->theNameIterator = GENV_STORE.getDocumentNames();
  state->theNameIterator->open ();
  while (state->theNameIterator->next(result)) 
  {
    STACK_PUSH( true, state);
  }

  STACK_PUSH(false, state);

  STACK_END(state);
}

/*******************************************************************************
  declare function
  is-available-document() as xs:boolean
********************************************************************************/
bool IsAvailableDocumentIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  zstring       lRetrievedUriString;
  zstring       lResolvedUriString;
  store::Item_t lUri;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lUri, theChildren[0].getp(), aPlanState);

  // absolutize retrieved uri
  try {
    lUri->getStringValue2(lRetrievedUriString);
    lResolvedUriString = theSctx->resolve_relative_uri(lRetrievedUriString, true);
  } catch (ZorbaException const&) {
    throw XQUERY_EXCEPTION(
      err::FODC0004,
      ERROR_PARAMS( lResolvedUriString, ZED( NoResolveRelativeURI ) ),
      ERROR_LOC( loc )
    );
  }

  // check if document exists in the store
  GENV_ITEMFACTORY->createBoolean(
      result, GENV_STORE.getDocument(lResolvedUriString) != NULL);

  STACK_PUSH(true, state);

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
