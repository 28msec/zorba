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

#include "runtime/parsing_and_serializing/parsing_and_serializing.h"

#include <iostream>

#include "zorbatypes/URI.h"
#include "zorbaerrors/xquery_diagnostics.h"
#include "context/static_context.h"
#include "api/serialization/serializer.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "compiler/api/compilercb.h"

#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "system/globalenv.h"

namespace zorba 
{

/*******************************************************************************
  14.9.1 fn:parse-xml
********************************************************************************/
bool FnParseXmlIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Store& lStore = GENV.getStore();
  zstring docString;
  zstring baseUri;
  URI lValidatedBaseUri;
  zstring docUri;
  std::auto_ptr<std::istringstream> iss;
  std::istream *is;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext (result, theChildren [0].getp (), planState);

  if (result->isStreamable()) {
    // The "iss" auto_ptr can NOT be used since it will delete the stream that,
    // in this case, is a data member inside another object and not dynamically
    // allocated.
    //
    // We can't replace "iss" with "is" since we still need the auto_ptr for
    // the case when the result is not streamable.
    is = &result->getStream();
  } else {
    result->getStringValue2(docString);
    iss.reset (new std::istringstream(docString.c_str()));
    is = iss.get();
  }

  // optional base URI argument
  if (theChildren.size() == 2) {
    consumeNext(result, theChildren[1].getp(), planState);
    ZORBA_ASSERT(result);

    try {
      lValidatedBaseUri = URI(result->getStringValue());
    } catch (ZorbaException const& /* e */) {
      throw XQUERY_EXCEPTION(
        err::FODC0007,
        ERROR_PARAMS( result->getStringValue() ),
        ERROR_LOC( loc )
      );
    }

    if (!lValidatedBaseUri.is_absolute()) {
      throw XQUERY_EXCEPTION(
        err::FODC0007,
        ERROR_PARAMS( lValidatedBaseUri.toString() ),
        ERROR_LOC( loc )
      );
    }

    result->getStringValue2(baseUri);
  } else {
    baseUri = theSctx->get_base_uri();
  }

  try {
    store::LoadProperties loadProps;
    loadProps.setStoreDocument(false);
    result = lStore.loadDocument(baseUri, docUri, *is, loadProps);
  } catch (ZorbaException const& e) {
    throw XQUERY_EXCEPTION(
      err::FODC0006, ERROR_PARAMS( e.what() ), ERROR_LOC( loc )
    );
  }
  STACK_PUSH(true, state);
  STACK_END (state);
}

/*******************************************************************************
  14.9.2 fn:serialize
********************************************************************************/
bool
FnSerializeIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  store::Item_t lParams;
  std::stringstream lResultStream;
  zstring lResult;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  {
    store::Iterator_t lIterWrapper = new PlanIteratorWrapper(theChildren[0], aPlanState);
    zorba::serializer lSerializer(aPlanState.theCompilerCB->theXQueryDiagnostics);

    // defaults
    lSerializer.setParameter("omit-xml-declaration", "yes");

    // if have serialization parameters
    if (theChildren.size() == 2 && consumeNext(lParams, theChildren[1].getp(), aPlanState)) {
      // get the children iterator
      store::Iterator_t lElemIter = lParams->getChildren();
      lElemIter->open();
      store::Item_t lChildElem;

      // iterate over the children
      while (lElemIter->next(lChildElem)) {
        // consider only the elements (this should be taken care of by the schema)
        if (lParams->isNode() && lParams->getNodeKind() == store::StoreConsts::elementNode) {
          store::Item_t lChildName = lChildElem->getNodeName();
          if (lChildName->getLocalName() == "use-character-maps") {
            // TODO: once zorba the serializer supports character maps
          } else {
            store::Iterator_t lAttrIter = lChildElem->getAttributes();
            lAttrIter->open();
            store::Item_t lAttribute;
            // iterate over the attributes
            while (lAttrIter->next(lAttribute)) {
              store::Item_t lAttributeQName = lAttribute->getNodeName();

              // the attribute must have the local name "value" (this should be taken care of by the schema)
              if (lAttributeQName->getLocalName() == "value") {
                store::Item_t lChildElemQName = lChildElem->getNodeName();
                lSerializer.setParameter(lChildElemQName->getLocalName().c_str(), lAttribute->getStringValue().c_str());
                break;
              }
            }
            lAttrIter->close();
          }
        }
      }
      lElemIter->close();
    }

    // and now serialize
    lSerializer.serialize(lIterWrapper, lResultStream);
    lResult = lResultStream.str();
  }

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, lResult), lState);
  STACK_END (lState);
}

} /* namespace zorba */


///*******************************************************************************
//  Zorba-defined parse function
//********************************************************************************/
//bool UtilsParseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
//{
//  store::Store& lStore = GENV.getStore();
//  zstring docString;
//  zstring baseUri = theSctx->get_base_uri();
//  zstring docUri;
//  std::auto_ptr<std::istringstream> iss;
//
//  PlanIteratorState* state;
//  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
//
//  consumeNext(result, theChildren[0].getp(), planState);
//
//  result->getStringValue2(docString);
//  iss.reset(new std::istringstream(docString.c_str()));
//
//  try 
//  {
//    store::LoadProperties loadProps;
//    loadProps.setStoreDocument(false);
//    result = lStore.loadDocument(baseUri, docUri, *iss, loadProps);
//  }
//  catch (error::ZorbaError& e)
//  {
//    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
//  }
//
//  STACK_PUSH(true, state);
//  STACK_END (state);
//}

/* vim:set et sw=2 ts=2: */
