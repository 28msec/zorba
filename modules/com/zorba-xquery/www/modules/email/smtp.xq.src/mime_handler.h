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

#ifndef ZORBA_MODULES_EMAIL_MIME_HANDLER_H
#define ZORBA_MODULES_EMAIL_MIME_HANDLER_H

#include <istream>

#include <zorba/item.h>

#include "zorba/api_shared_types.h"
#ifdef WIN32
#include <windows.h>
#endif

#include "c-client.h"

namespace zorba
{
  namespace emailmodule
  {
    class MimeHandler
    {
    public:
      virtual void begin(const Item& aMimeItem) = 0;
      virtual bool envelope(std::string& aDiagnostics) = 0;
      virtual bool body(std::string& aDiagnostics) = 0;
      virtual void end() = 0;
    };



    class CClientMimeHandler : public MimeHandler
    {
    private:
      //BODY and ENVELOPE structures are described in
      //http://www.washington.edu/imap/documentation/internal.txt.html
      BODY*         theBody;
      ENVELOPE*     theEnvelope;
      zorba::Item   theEnvelopeItem;
      zorba::Item   theBodyItem;

      //assign a certain message string to the given BODY
      //TODO implement a streaming mechanism for large attachments
      void
      set_text_body(BODY* aBody,
                    const char* aMessage);

      //set the encoding to the given BODY
      void
      set_encoding(BODY* aBody,
                   zorba::String& aEncoding);

      //set the content Type and content Subtype of the given BODY
      bool
      set_content_type_value(BODY* aBody,
                             zorba::String& aValue);

      //helper function
      PARAMETER *
      create_param(const char* aAttribute,
                   const char * aValue,
                   PARAMETER * aPrevious = NIL);

      //parse non multipart message
      bool
      parse_content(BODY* aBody,
                    const Item aItemContent);

      //parse multipart message
      bool
      parse_multipart(BODY* aBody,
                      const Item aItemMultipart);

      // set contentType, charset and TranferEncoding
      void
      set_contentTypeCharsetCTF(BODY* aBody,
                                const Item& aContentOrMultipartItem);


      // parse a xml dateTime string to something cclient will like
      void 
      parseXmlDateTime(String& aXmlDateTime, char* aCDateTime);


    public:
      void begin(const Item& aMimeItem);
      bool envelope(std::string& aDiagnostics);
      bool body(std::string& aDiagnostics);
      void end();

      BODY*     getBody()     {  return theBody; };
      ENVELOPE* getEnvelope() {  return theEnvelope; };

      //destroy theBody and theEnvelope
      ~CClientMimeHandler();
    };
  }//namespace email
}//namespace zorba

#endif // ZORBA_MODULES_EMAIL_MIME_HANDLER_H
