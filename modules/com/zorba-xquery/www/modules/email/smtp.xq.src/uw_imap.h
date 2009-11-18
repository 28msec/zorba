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

#ifndef ZORBA_MODULES_EMAIL_UW_IMAP_H
#define ZORBA_MODULES_EMAIL_UW_IMAP_H

#include "zorba/api_shared_types.h"

#include "c-client.h"

namespace zorba
{
  namespace email
  {
    class CClient
    {
    public:
      static CClient& Instance()
      {
        static CClient lInstance;
        return lInstance;
      }

      bool send(const Item& aMessage,
      const char* aSMTPServer, const char* aSMTPUser, const char* aSMTPPwd,
      zorba::String& aDiagnostics);

      void setSMTPUser (const char* aSMTPUser);
      void setSMTPPwd (const char* aSMTPPwd);

      std::string getSMTPUser();
      std::string getSMTPPwd();

    private:
      //ctor, dtor, copy ctor are all hidden
      CClient() {};
      ~CClient() {};
      CClient(CClient const&) {};

      std::string lSMTPUser;
      std::string lSMTPPwd;
    };

  }//namespace email
}//namespace zorba

#endif // ZORBA_MODULES_EMAIL_UW_IMAP_H