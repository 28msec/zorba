/*
 * Copyright 2015 Federico Cavalieri.
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
#ifndef ZORBA_SERVER_REQUEST_HANDLER_H_
#define ZORBA_SERVER_REQUEST_HANDLER_H_

#include <fcgio.h>

#include "zorba/zorba.h"
#include "zorba/serializer.h"

#include "exceptions/server_exceptions.h"
#include "io/request.h"
#include "io/response.h"

#include "utils/JSONObject.h"

namespace zorba
{
namespace server
{
  class RequestHandler
  {
  public:
    static RequestHandler& getInstance();
    void handleRequest(const FCGX_Request& aRequest) const;

    static void throwInvalidMethod(const io::Request& aRequest, const std::string& aAllowedMethods);
    static void throwInvalidEndpoint(const io::Request& aRequest, const std::string& aAllowedEndpoints);

    Zorba& getZorba() { return *theZorba; }
    Serializer_t getSerializer() { return theSerializer; }
    ItemFactory& getItemFactory() { return *theItemFactory; }

  private:
    RequestHandler();
    ~RequestHandler();

    void * theStore;
    Zorba* theZorba;
    Zorba_SerializerOptions_t theOptions;
    Serializer_t theSerializer;
    ItemFactory* theItemFactory;
  };
}
}

#endif
