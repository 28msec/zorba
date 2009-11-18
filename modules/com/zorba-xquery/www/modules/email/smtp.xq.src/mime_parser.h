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

#ifndef ZORBA_MODULES_EMAIL_MIME_PARSER_H
#define ZORBA_MODULES_EMAIL_MIME_PARSER_H

#include "mime_handler.h"

#include "zorba/api_shared_types.h"

namespace zorba
{
  namespace email
  {
    class MimeParser
    {
    protected:
      MimeHandler* theHandler;
    public:
      MimeParser(MimeHandler* aHandler) : theHandler(aHandler) {};

      bool parse(const Item& aMimeItem, zorba::String& aDiagnostics);
    };
  }//namespace email
}//namespace zorba

#endif // ZORBA_MODULES_EMAIL_MIME_PARSER_H