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

#ifndef ZORBA_UTIL_MIME_HANDLER_H
#define ZORBA_UTIL_MIME_HANDLER_H

#include "zorbatypes/representations.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "c-client.h"

namespace zorba {

  class MimeHandler {
    public:
      virtual void          begin() = 0;
      virtual xqpString     contentType   (const xqpString& aType) = 0;
      virtual xqpString     boundary      (const xqpString& aBoundary) = 0;
      virtual xqpString     nonMime       (const xqpString& aNonMime) = 0;
      virtual xqpString     charset       (const xqpString& aCharset) = 0;
      virtual xqpString     contentTransferEncoding(const xqpString& aTransferEncoding) = 0;
      virtual xqpString     serialization (const xqpString& aSerialization) = 0;
      virtual std::istream& body          (std::istream& aBody) = 0;
      virtual void          end() = 0;
  };

  class CClientMimeHandler : public MimeHandler {
    private:
      ENVELOPE* env;
    public:
      void          begin();
      xqpString     contentType   (const xqpString& aType);
      xqpString     boundary      (const xqpString& aBoundary);
      xqpString     nonMime       (const xqpString& aNonMime);
      xqpString     charset       (const xqpString& aCharset);
      xqpString     contentTransferEncoding(const xqpString& aTransferEncoding);
      xqpString     serialization (const xqpString& aSerialization);
      std::istream& body          (std::istream& aBody);
      void          end();
  };

  class CURLMimeHandler : public MimeHandler {
    public:
      void          begin();
      xqpString     contentType   (const xqpString& aType);
      xqpString     boundary      (const xqpString& aBoundary);
      xqpString     nonMime       (const xqpString& aNonMime);
      xqpString     charset       (const xqpString& aCharset);
      xqpString     contentTransferEncoding(const xqpString& aTransferEncoding);
      xqpString     serialization (const xqpString& aSerialization);
      std::istream& body          (std::istream& aBody);
      void          end();
  };
}/*namespace Zorba */

#endif /* ZORBA_UTIL_MIME_HANDLER_H */
