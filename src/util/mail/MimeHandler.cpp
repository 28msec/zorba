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

#include "util/mail/MimeHandler.h"



namespace zorba {

  void CClientMimeHandler::begin ()
  {
    env = mail_newenvelope ();
  }

  xqpString     CClientMimeHandler::contentType   (const xqpString& aType) {}
  xqpString     CClientMimeHandler::boundary      (const xqpString& aBoundary) {}
  xqpString     CClientMimeHandler::nonMime       (const xqpString& aNonMime) {}
  xqpString     CClientMimeHandler::charset       (const xqpString& aCharset) {}
  xqpString     CClientMimeHandler::contentTransferEncoding(const xqpString& aTransferEncoding) {}
  xqpString     CClientMimeHandler::serialization (const xqpString& aSerialization) {}
  std::istream& CClientMimeHandler::body          (std::istream& aBody) {}

  void CClientMimeHandler::end ()
  {
    if( env )
      mail_free_envelope( &env );
  }

}/*namespace Zorba */
