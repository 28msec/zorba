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
#ifdef WIN32
#include <windows.h>
#endif

#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>

#include "smtp.h"
#include "uw_imap.h"
#include "email_module.h"

namespace zorba
{
  namespace email
  {
  //SendFunction
  SendFunction::SendFunction(const SMTPModule* aModule)
  : SMTPFunction(aModule)
  {
  }

  ItemSequence_t
  SendFunction::evaluate(
    const StatelessExternalFunction::Arguments_t& args,
    const StaticContext* aSctxCtx,
    const DynamicContext* aDynCtx) const
  {
    zorba::Item   itemMessage;
    bool          res = false, lSMTPServerFound = false;
    zorba::String SMTPServer, SMTPUser, SMTPPwd, diagnostics;

    lSMTPServerFound = theModule->getOption(aSctxCtx,"SMTPServer",SMTPServer);
    theModule->getOption(aSctxCtx,"SMTPUser",SMTPUser);
    theModule->getOption(aSctxCtx,"SMTPPwd",SMTPPwd);

    if( !lSMTPServerFound || SMTPServer.empty() )
    {
      //TODO implement excenption handling via external_function_data
      std::stringstream lErrorMessage;
      lErrorMessage << "The SMTP server was not set. Please set SMTP username and password also if needed.";
      throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);
    }
    else
    {
      //TODO implement check for empty or sequence params
      args[0]->next(itemMessage);

      res = CClient::Instance().send( itemMessage,
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

  } // namespace email
} // namespace zorba

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

  extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
    return new zorba::email::SMTPModule();
  }
