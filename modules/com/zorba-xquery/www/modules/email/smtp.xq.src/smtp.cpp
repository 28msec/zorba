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
#include <zorba/error_list.h>
#include <zorba/singleton_item_sequence.h>

#include "email_module.h"
#include "imap_client.h"
#include "mime_parser.h"
#include "smtp.h"

namespace zorba
{
  namespace emailmodule
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
      try {
        bool res = false; 
        
        // getting host, username and password 
        std::string lHostName;
        std::string lUserName;
        std::string lPassword;
        SMTPFunction::getHostUserPassword(args, 0, lHostName, lUserName, lPassword);      
        
        std::stringstream lDiagnostics; 
        // getting message as item
        Item messageItem;
        Iterator_t arg1_iter = args[1]->getIterator();
        arg1_iter->open();
        arg1_iter->next(messageItem);
        arg1_iter->close();
        
        CClientMimeHandler lHandler;
        MimeParser lParser(&lHandler);
        bool lParseOK = lParser.parse(messageItem, lDiagnostics);
        bool lHasRecipient = (lHandler.getEnvelope()->to ||
                              lHandler.getEnvelope()->cc ||
                              lHandler.getEnvelope()->bcc);
        
        
        // if we can't parse the message, then we've got problems
        if (!lParseOK) { 
          lDiagnostics <<  "Message could not be parsed." << std::endl;
          res = false; 
        } else if (!lHasRecipient) {
          lDiagnostics <<  "Message has no recipient." << std::endl;
          res = false;
        } else {
          res = ImapClient::Instance().send(lHostName.c_str(),
                                            lUserName.c_str(),
                                            lPassword.c_str(),
                                            lHandler.getEnvelope(),
                                            lHandler.getBody(),
                                            lDiagnostics);
        }
        if( !res )
        {
          //TODO implement excenption handling via external_function_data
          std::stringstream lErrorMessage;
          lErrorMessage << "Mail could not be sent. Here is the log:" << std::endl;
          lErrorMessage << lDiagnostics.str();
          throwError(lErrorMessage.str(), err::XQP0019_INTERNAL_ERROR);
        }
        
        
        return ItemSequence_t(new EmptySequence());
      } catch (ImapException& e) {
        std::string lErrorMessage = e.get_message();
        Item lQName = SMTPModule::getItemFactory()->createQName(SMTPModule::getURIString(), "imap", e.get_localname());
        error(lQName, lErrorMessage);
      }
      return ItemSequence_t(NULL);
    }
    
  } // namespace emailmodule
} // namespace zorba

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::emailmodule::SMTPModule();
}
