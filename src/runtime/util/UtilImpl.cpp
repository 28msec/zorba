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

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/binary.h"
#include "zorbatypes/numconversions.h"

#include "runtime/util/UtilImpl.h"
#include "runtime/api/runtimecb.h"

#include "context/static_context.h"
#include "context/internal_uri_resolvers.h"

#include "util/web/web.h"
#include "util/uuid/uuid.h"
#include "util/mail/uw-imap.h"

#include <stdlib.h>
#include <time.h>

namespace zorba {

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
  xqpStringStore_t    buf, options;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    if((theChildren.size() > 1) &&
      consumeNext(itemOpt, theChildren[1].getp(), planState))
      options = itemOpt->getStringValue();

    if( tidy(item->getStringValue()->c_str(), xmlString, diag, (theChildren.size() > 1?options->c_str():NULL)) >= 0)
    {
      buf = xqpStringStore_t(xmlString.getStore());
      //if tidy returns a value >0 a warning should be raised
      STACK_PUSH(GENV_ITEMFACTORY->createString(result, buf), state );
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
        resolvedURIString = planState.sctx()->resolve_relative_uri(uriString, xqp_string(), false).getStore();
        GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
      } catch (error::ZorbaError& e) {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }
      try {
        result = planState.sctx()->get_document_uri_resolver()->resolve(resolvedURIItem,
                                                                        planState.sctx(),
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
  xqpStringStore_t  uuidStr;

  uuid_create(&u);
  uuidStr = new xqpStringStore(uuidToString(u));

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  GENV_ITEMFACTORY->createString(result, uuidStr);
  STACK_PUSH (true, state);

  STACK_END (state);
}

#ifdef ZORBA_WITH_EMAIL
bool
ZorbaMailIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t   itemTo, itemSubj, itemMsg;
  bool            res = false;
  xqp_string      SMTPServer, SMTPUser, SMTPPwd, diagnostics;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  planState.theRuntimeCB->theStaticContext->set_SMTP_server("smtp.gmail.com:587/tls/novalidate-cert");
  planState.theRuntimeCB->theStaticContext->set_SMTP_uname("zorbaro");
  planState.theRuntimeCB->theStaticContext->set_SMTP_upwd("zorbaisgreat");

  SMTPServer = planState.theRuntimeCB->theStaticContext->SMTP_server();
  SMTPUser = planState.theRuntimeCB->theStaticContext->SMTP_uname();
  SMTPPwd = planState.theRuntimeCB->theStaticContext->SMTP_upwd();

  if(SMTPServer.empty())
    ZORBA_ERROR_LOC(API0038_SMTP_SEVER_ERROR_SET_OPTION, loc);
  else if (consumeNext(itemTo, theChildren[0].getp(), planState) &&
      consumeNext(itemSubj, theChildren[1].getp(), planState) &&
      consumeNext(itemMsg, theChildren[2].getp(), planState))
      {
        if(itemTo->getStringValue()->empty())
          ZORBA_ERROR_LOC(API0039_TO_SET_OPTION, loc);

        res = mail(itemTo->getStringValue()->c_str(),
                   itemSubj->getStringValue()->c_str(),
                   itemMsg->getStringValue()->c_str(),
                   SMTPServer.c_str(),
                   SMTPUser.c_str(),
                   SMTPPwd.c_str(),
                   diagnostics);

        if(!res)
          ZORBA_ERROR_LOC_PARAM(API0040_MAIL_NOT_SENT, loc, diagnostics.c_str() , "");
      }

  STACK_END (state);
}
#endif  /* ZORBA_WITH_EMAIL */
} /* namespace zorba */
