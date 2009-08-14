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

#ifndef ZORBA_UTIL_MIME_PARSER_H
#define ZORBA_UTIL_MIME_PARSER_H

#include "zorbatypes/representations.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "util/mail/MimeHandler.h"

namespace zorba {

  class MimeParser {
    protected:
      MimeHandler* theHandler;
    public:
      MimeParser(MimeHandler* aHandler) : theHandler(aHandler) {};
      bool parse(const store::Item&  aMimeItem);
  };

}/*namespace Zorba */

#endif /* ZORBA_UTIL_MIME_PARSER_H */