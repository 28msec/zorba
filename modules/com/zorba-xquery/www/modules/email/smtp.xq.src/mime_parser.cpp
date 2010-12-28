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

#include "mime_parser.h"

namespace zorba
{
  namespace emailmodule
  {
    bool MimeParser::parse(const Item& aMimeItem, std::string& aDiagnostics)
    {
      theHandler->begin(aMimeItem);

      bool lRes = theHandler->envelope(aDiagnostics);

      if(lRes)
        lRes = theHandler->body(aDiagnostics);

      theHandler->end();

      return lRes;
    }

  }//namespace email
}//namespace zorba
