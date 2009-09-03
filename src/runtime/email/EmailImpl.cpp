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

#include "runtime/email/EmailImpl.h"

#include "compiler/api/compilercb.h"

#include "runtime/api/runtimecb.h"

#include "context/static_context.h"

#include "util/mail/uw-imap.h"

#include "runtime/visitors/planitervisitor.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(ZorbaMailIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaMailIterator)

NARY_ACCEPT(ZorbaMailIterator);

bool
ZorbaMailIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t   itemTo, itemCc, itemBcc, itemSubj, itemMsg, itemMessage;
  bool            res = false, lSMTPServerFound = false, hasRecipient = false;
  xqp_string      SMTPServer, SMTPUser, SMTPPwd, diagnostics;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lSMTPServerFound = theSctx->lookup_option("http://www.zorba-xquery.org/options", "SMTPServer", SMTPServer);
  theSctx->lookup_option("http://www.zorba-xquery.org/options", "SMTPUser", SMTPUser);
  theSctx->lookup_option("http://www.zorba-xquery.org/options", "SMTPPwd", SMTPPwd);

  if( !lSMTPServerFound ||
       (lSMTPServerFound && SMTPServer.empty()) )
    ZORBA_ERROR_LOC(API0038_SMTP_SEVER_ERROR_SET_OPTION, loc);
  else if ( theChildren.size() == 5 )
  {
    if(consumeNext(itemTo, theChildren[0].getp(), planState ) &&
          consumeNext(itemCc, theChildren[1].getp(), planState ) &&
          consumeNext(itemBcc, theChildren[2].getp(), planState ) &&
          consumeNext(itemSubj, theChildren[3].getp(), planState) &&
          consumeNext(itemMsg, theChildren[4].getp(), planState))
      {
        hasRecipient = (!itemTo->getStringValue()->empty() ||
                        !itemCc->getStringValue()->empty() ||
                        !itemBcc->getStringValue()->empty());

        if( !hasRecipient )
          ZORBA_ERROR_LOC(API0039_RECIPIENT_SET_OPTION, loc);

        res = mail((!itemTo->getStringValue()->empty()?itemTo->getStringValue()->c_str():NULL),
                   (!itemCc->getStringValue()->empty()?itemCc->getStringValue()->c_str():NULL),
                   (!itemBcc->getStringValue()->empty()?itemBcc->getStringValue()->c_str():NULL),
                   itemSubj->getStringValue()->c_str(),
                   itemMsg->getStringValue()->c_str(),
                   SMTPServer.c_str(),
                   SMTPUser.c_str(),
                   SMTPPwd.c_str(),
                   diagnostics);

        if( !res )
          ZORBA_ERROR_LOC_PARAM(API0040_MAIL_NOT_SENT, loc, diagnostics.c_str() , "");
      }
  }
  else if ( theChildren.size() == 1 )
  {
    if( consumeNext(itemMessage, theChildren[0].getp(), planState ) )
    {
      res = mail( itemMessage,
                  SMTPServer.c_str(),
                  SMTPUser.c_str(),
                  SMTPPwd.c_str(),
                  diagnostics);

      if( !res )
        ZORBA_ERROR_LOC_PARAM(API0040_MAIL_NOT_SENT, loc, diagnostics.c_str() , "");
    }
  }

  STACK_END (state);
}

} /* namespace zorba */
