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
#include <iostream>
#include <sstream>

#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>

#include "smtp.h"
#include "uw-imap.h"
#include "email_module.h"

namespace zorba
{
  namespace smtpmodule
  {
  //MailFunction
  MailFunction::MailFunction(const EmailModule* aModule)
  : EmailFunction(aModule)
  {
  }

  ItemSequence_t
  MailFunction::evaluate(
    const StatelessExternalFunction::Arguments_t& args,
    const StaticContext* aSctxCtx,
    const DynamicContext* aDynCtx) const
  {
    zorba::Item   itemTo, itemCc, itemBcc, itemSubj, itemMsg;
    bool          res = false, lSMTPServerFound = false, hasRecipient = false;
    zorba::String SMTPServer, SMTPUser, SMTPPwd, diagnostics;

    lSMTPServerFound = aSctxCtx->getOption(theModule->getItemFactory()->
        createQName("http://www.zorba-xquery.org/options","SMTPServer"),SMTPServer);

    aSctxCtx->getOption(theModule->getItemFactory()->
        createQName("http://www.zorba-xquery.org/options","SMTPUser"),SMTPUser);

    aSctxCtx->getOption(theModule->getItemFactory()->
        createQName("http://www.zorba-xquery.org/options","SMTPPwd"),SMTPPwd);


    if( !lSMTPServerFound ||
         (lSMTPServerFound && SMTPServer.empty()) )
    {
      //TODO implement excenption handling via external_function_data
      std::stringstream lErrorMessage;
      lErrorMessage << "The SMTP server was not set in the static context. Please set SMTP username and password also if needed.";
      throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);
    }
    else
    {
      //TODO implement check for empty or sequence params
      args[0]->next(itemTo);
      args[1]->next(itemCc);
      args[2]->next(itemBcc);
      args[3]->next(itemSubj);
      args[4]->next(itemMsg);

      hasRecipient = (!itemTo.getStringValue().empty() ||
            !itemCc.getStringValue().empty() ||
            !itemBcc.getStringValue().empty());

      if( !hasRecipient )
      {
        //TODO implement excenption handling via external_function_data
        std::stringstream lErrorMessage;
        lErrorMessage << "Recipient was not set; please set either one of To, Cc or Bcc.";
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);
      }

      res = mail((!itemTo.getStringValue().empty()?itemTo.getStringValue().c_str():NULL),
                 (!itemCc.getStringValue().empty()?itemCc.getStringValue().c_str():NULL),
                 (!itemBcc.getStringValue().empty()?itemBcc.getStringValue().c_str():NULL),
                 itemSubj.getStringValue().c_str(),
                 itemMsg.getStringValue().c_str(),
                 SMTPServer.c_str(),
                 SMTPUser.c_str(),
                 SMTPPwd.c_str(),
                 diagnostics);

      if( !res )
      {
        //TODO implement excenption handling via external_function_data
        std::stringstream lErrorMessage;
        lErrorMessage << "Mail could not be sent. Here is the log:" << std::endl;
        lErrorMessage << diagnostics.c_str();
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);
      }
    }

    return ItemSequence_t(new SingletonItemSequence(
                          theModule->getItemFactory()->createBoolean(res)));
  }

  //MultipartFunction
  MultipartFunction::MultipartFunction(const EmailModule* aModule)
  : EmailFunction(aModule)
  {
  }

  ItemSequence_t
  MultipartFunction::evaluate(
    const StatelessExternalFunction::Arguments_t& args,
    const StaticContext* aSctxCtx,
    const DynamicContext* aDynCtx) const
  {
    zorba::Item   itemMessage;
    bool          res = false, lSMTPServerFound = false;
    zorba::String SMTPServer, SMTPUser, SMTPPwd, diagnostics;

    lSMTPServerFound = aSctxCtx->getOption(theModule->getItemFactory()->
        createQName("http://www.zorba-xquery.org/options","SMTPServer"),SMTPServer);

    aSctxCtx->getOption(theModule->getItemFactory()->
        createQName("http://www.zorba-xquery.org/options","SMTPUser"),SMTPUser);

    aSctxCtx->getOption(theModule->getItemFactory()->
        createQName("http://www.zorba-xquery.org/options","SMTPPwd"),SMTPPwd);


    if( !lSMTPServerFound ||
         (lSMTPServerFound && SMTPServer.empty()) )
    {
      //TODO implement excenption handling via external_function_data
      std::stringstream lErrorMessage;
      lErrorMessage << "The SMTP server was not set in the static context. Please set SMTP username and password also if needed.";
      throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);
    }
    else
    {
      //TODO implement check for empty or sequence params
      args[0]->next(itemMessage);

      res = mail( itemMessage,
                  SMTPServer.c_str(),
                  SMTPUser.c_str(),
                  SMTPPwd.c_str(),
                  diagnostics);

      if( !res )
      {
        //TODO implement excenption handling via external_function_data
        std::stringstream lErrorMessage;
        lErrorMessage << "Mail could not be sent. Here is the log:" << std::endl;
        lErrorMessage << diagnostics.c_str();
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);
      }
    }

    return ItemSequence_t(new SingletonItemSequence(
                          theModule->getItemFactory()->createBoolean(res)));
  }

  } // namespace smtpmodule
} // namespace zorba

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

  extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
    return new zorba::smtpmodule::EmailModule();
  }
