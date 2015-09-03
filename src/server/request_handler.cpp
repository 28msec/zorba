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
#include <boost/algorithm/string.hpp>

#include "zorba/store_manager.h"
#include "zorba/zorba.h"

#include "api/evaluation.h"

#include "request_handler.h"

namespace zorba
{
namespace server
{

RequestHandler& RequestHandler::getInstance()
{
  static RequestHandler lRequestHandler;
  return lRequestHandler;
}

RequestHandler::RequestHandler()
{
  theStore = StoreManager::getStore();
  theZorba = Zorba::getInstance(theStore);
  theItemFactory = theZorba->getItemFactory();
  theOptions.indent = ZORBA_INDENT_YES;
  theSerializer = zorba::Serializer::createSerializer(theOptions);
}

RequestHandler::~RequestHandler()
{

}

void RequestHandler::handleRequest(const FCGX_Request& aRequest) const
{
  io::Request lRequest(aRequest);
  io::Response lResponse(std::cout);

  try
  {
    const std::vector<std::string>& lURISegments = lRequest.getRequestURISegments();

    if (lURISegments.size() == 0 || lURISegments[0] != "v1")
      throwInvalidEndpoint(lRequest, "Valid requests start with </v1>.");

    if (lURISegments.size() == 1)
    {
      /*
       * Request to /v1
       */
      lResponse.sendHeaders();
      lResponse.getRawStream() <<
          "{\n" <<
          "  \"software\": \"Zorba Server\",\n" <<
          "  \"version\": \"" << Zorba::version() << "\"\n" <<
          "}" << std::endl << lRequest << std::endl;
    }
    else
    {
      if (lURISegments[1] == "evaluate")
        api::Evaluation::handleRequest(lRequest, lResponse);
      else
        throwInvalidEndpoint(lRequest, "Valid requests are </v1> and </v1/evaluate>.");
    }
  }
  catch (const std::exception& lException)
  {
    lResponse.sendException(lException);
  }

}

void RequestHandler::throwInvalidMethod(const io::Request& aRequest, const std::string& aAllowedMethods)
{
  throw exceptions::ServerException(
      "Invalid method in request <" + aRequest.getRequestMethod() + " " + aRequest.getRequestURI() + ">. " +
      "Supported methods for this endpoint are: " + aAllowedMethods + ".", 405);
}

void RequestHandler::throwInvalidEndpoint(const io::Request& aRequest, const std::string& aErrorMessage)
{
  throw exceptions::ServerException(
      "Invalid request <" + aRequest.getRequestMethod() + aRequest.getRequestURI() + ">. " +
      aErrorMessage, 400);
}

}
}

