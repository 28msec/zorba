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
#include "compiler/api/compiler_api.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/URI.h"
#include "zorbatypes/binary.h"
#include "zorbatypes/numconversions.h"

#include "runtime/util/UtilImpl.h"
#include "runtime/api/runtimecb.h"

#include "context/static_context.h"
#include "context/internal_uri_resolvers.h"
#include "context/dynamic_context.h"

#include "util/web/web.h"
#include "util/uuid/uuid.h"
#include "util/mail/uw-imap.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>

using namespace std;

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(ZorbaSchemaTypeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaSchemaTypeIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaBase64DecodeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaBase64DecodeIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaBase64EncodeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaBase64EncodeIterator)

#ifdef ZORBA_WITH_TIDY
SERIALIZABLE_CLASS_VERSIONS(ZorbaTidyIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaTidyIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaTDocIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaTDocIterator)
#endif

SERIALIZABLE_CLASS_VERSIONS(ZorbaRandomIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRandomIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaUUIDIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaUUIDIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaTimestampIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaTimestampIterator)

SERIALIZABLE_CLASS_VERSIONS(XQDocIterator)
END_SERIALIZABLE_CLASS_VERSIONS(XQDocIterator)

bool
XQDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t lURI;
  xqpString lFileName;
  store::Item_t lItem;
  store::Item_t lURIItem = 0;
  auto_ptr<istream> lFile;
  stringstream lOutput;
  istringstream lInput;
  static_context* lSctx;
  InternalModuleURIResolver* lModuleResolver = 0;

  // setup a new CompilerCB and a new XQueryCompiler 
  CompilerCB     lCompilerCB(*planState.theCompilerCB);
  lCompilerCB.m_sctx = GENV.getRootStaticContext().create_child_context();

  // the XQueryCompiler's constructor destroys the existing type manager 
  // in the static context. Hence, we create a new one
  XQueryCompiler lCompiler(&lCompilerCB);

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // retrieve the URI of the module to generate xqdoc for
  if(consumeNext(lItem, theChildren[0].getp(), planState))
  {
    lFileName = xqpString(lItem->getStringValue());
  }

  // resolve the uri in the surrounding static context and use
  // the URI resolver to retrieve the module
  lSctx = theSctx;
  lURI = lSctx->resolve_relative_uri(lItem->getStringValueP(), xqp_string()).getStore();
  if (!GENV_ITEMFACTORY->createAnyURI(lURIItem, lURI))
      ZORBA_ERROR_LOC_DESC_OSS(XQST0046, loc, "URI is not valid " << lURI);

  lModuleResolver = lSctx->get_module_uri_resolver();
  // we get the ownership of the input stream
  // TODO: we have to find a way to tell user defined resolvers when their input stream
  // can be freed. The current solution might leed to problems on Windows.
  lFile.reset(lModuleResolver->resolve(lURIItem, lSctx));

  // now, do the real work
  if(lFile.get() && lFile->good())
  {
    // retrieve the xqdoc elements as string and parse them
    // TODO: this could be done more efficiently if Items are returned immediately
    lCompiler.xqdoc(*lFile.get(), lFileName.theStrStore->str(), lOutput, planState.dctx()->get_current_date_time());
    lInput.str(lOutput.str());
    result = GENV_STORE.loadDocument(lFileName.theStrStore, lInput, false);
    STACK_PUSH(true, state);
  }
  else
  {
    ZORBA_ERROR_LOC_DESC_OSS(XQST0046, loc, "No module could be found at " << lURI);
  }
  STACK_END(state);
}

bool
ZorbaSchemaTypeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    result = item->getType();
    STACK_PUSH(true, state );
  }

  STACK_END (state);
}

bool
ZorbaBase64DecodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t        lItem;
  Base64               lDecodedData;
  xqpStringStore_t     lResultString;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) {
    lDecodedData = lItem->getBase64BinaryValue();
    lResultString = lDecodedData.decode().getStore();
    GENV_ITEMFACTORY->createString(result, lResultString);
    STACK_PUSH (true, state);
  }

  STACK_END (state);
}

bool
ZorbaBase64EncodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  Base64        lBase64;
  xqpStringStore* lTmpString;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) {
    lTmpString = lItem->getStringValueP();
    Base64::encode(lTmpString, lBase64);
    if (GENV_ITEMFACTORY->createBase64Binary(result, lBase64)) {
      STACK_PUSH (true, state);
    } else {
      ZORBA_ERROR_LOC(XQP0025_COULD_NOT_CREATE_ITEM, loc);
    } 
  }
  STACK_END (state);
}

#ifdef ZORBA_WITH_TIDY
bool
ZorbaTidyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item, itemOpt;
  xqp_string          xmlString, diag;
  xqpStringStore_t    buf(new xqpStringStore(""));
  xqpStringStore_t    options;
  std::istringstream  is(std::istringstream::in);

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    if((theChildren.size() > 1) &&
      consumeNext(itemOpt, theChildren[1].getp(), planState))
      options = itemOpt->getStringValue();

    if( tidy(item->getStringValue()->c_str(), xmlString, diag, (theChildren.size() > 1?options->c_str():NULL)) >= 0)
    {
      //if tidy returns a value >0 a warning should be raised
      is.str(xmlString);
      result = GENV_STORE.loadDocument(buf, is, false);
      STACK_PUSH(result != NULL, state);
    }
    else
    {
      ZORBA_ERROR_LOC_PARAM(API0036_TIDY_ERROR, loc, diag.c_str() , "");
    }
  }

  STACK_END (state);
}

bool
ZorbaTDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     uriItem, itemOpt;
  xqp_string        uriString;
  xqpStringStore_t  resolvedURIString;
  store::Item_t     resolvedURIItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(uriItem, theChildren[0].getp(), planState)) {

    uriString = uriItem->getStringValueP();

    if(theChildren.size() > 1)
      consumeNext(itemOpt, theChildren[1].getp(), planState);

    try {
      // maybe the document is stored with the uri that is given by the user
      result = GENV_STORE.getDocument(uriString.getStore());
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }
    if (result != NULL) {
      STACK_PUSH(true, state);
    } else {
      try {
        resolvedURIString = theSctx->resolve_relative_uri(uriString, xqp_string(), false).getStore();
        GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
      } catch (error::ZorbaError& e) {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }
      try {
        result = theSctx->get_document_uri_resolver()->resolve(resolvedURIItem,
                                                               theSctx,
                                                               false,
                                                               true,
                                                               (theChildren.size() > 1 ? itemOpt : NULL));
      } catch (error::ZorbaError& e) {
        ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
      }

      STACK_PUSH(true, state);
    }

  } // return empty sequence if input is the empty sequence
  STACK_END (state);
}
#endif  /* ZORBA_WITH_TIDY */

bool
ZorbaRandomIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqp_string    seed;
  xqp_uint      seedInt;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if((theChildren.size() == 1) &&
      consumeNext(item, theChildren[0].getp(), planState))
  {
    seed = item->getIntegerValue().toString();
    NumConversions::strToUInt(seed, seedInt);
    std::srand((unsigned int)seedInt);
  }
  else
    std::srand((unsigned int)(time(NULL)));

  GENV_ITEMFACTORY->createInteger(result, Integer::parseInt (std::rand()));
  STACK_PUSH (true, state);

  STACK_END (state);
}

bool
ZorbaUUIDIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item;
  uuid_t            u;
  memset(&u, 0, sizeof(uuid_t));
  xqpStringStore_t  uuidStr;

  uuid_create(&u);
  uuidStr = new xqpStringStore(uuidToString(u));

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  GENV_ITEMFACTORY->createString(result, uuidStr);
  STACK_PUSH (true, state);

  STACK_END (state);
}

bool
ZorbaTimestampIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  result = planState.dctx()->get_current_time_millis();
  STACK_PUSH (true, state);

  STACK_END (state);
}

} /* namespace zorba */
