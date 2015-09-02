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
#include "zorba/module_info.h"

#include "exceptions/server_exceptions.h"
#include "debug/quick-debug.h"
#include "io/response_iterator.h"
#include "request_handler.h"
#include "vector"
#include "string"

#include "evaluation.h"

namespace zorba
{
namespace server
{
namespace api
{

void Evaluation::handleRequest(const io::Request& aRequest, io::Response& aResponse)
{
  const std::vector<std::string>& lRequestSegments = aRequest.getRequestURISegments();
  if (lRequestSegments.size() == 2)
  {
    /*
     * Request to /v1/evaluate
     */
    evaluate(aRequest, aResponse);
  }
  else
  {
    RequestHandler::throwInvalidEndpoint(aRequest, "Valid request to the evaluate API are </v1/evaluate>.");
  }
}

void Evaluation::evaluate(const io::Request& aRequest, io::Response& aResponse)
{
  RequestHandler& lRequestHandler = RequestHandler::getInstance();
  StaticContext_t lContext = lRequestHandler.getZorba().createStaticContext();
  MapModuleURLResolver lResolver;
  lContext->registerURLResolver(&lResolver);
  std::string lSource;
  if (aRequest.getContentType() && io::ContentTypes::isX_WWW_FORM_URLENCODED(*aRequest.getContentType()))
  {
    lSource = (*aRequest.getQueryParameter("query"))[0];
    const std::vector<std::string>* lModules = aRequest.getQueryParameter("module");
    if (lModules)
    {
      for (std::vector<std::string>::const_iterator lIt = lModules->begin();
          lIt != lModules->end();
          ++lIt)
      {
        lResolver.addModule(*lIt);
      }
    }
    //DEBUG_SS(lSource);
  }
  else
    lSource = aRequest.getBody();

  XQuery_t lQuery = lRequestHandler.getZorba().compileQuery(lSource, lContext);

  io::ResponseIterator* lRespIterator = new io::ResponseIterator(lQuery);
  zorba::Iterator_t lZorbaIterator(lRespIterator);

  if (lRespIterator->isEmpty())
  {
    aResponse.setStatus(204);
    aResponse.sendHeaders();
  }
  else
  {
    aResponse.setContentType(lRespIterator->getContentType());
    aResponse.sendHeaders();
    lRequestHandler.getSerializer()->serialize(lZorbaIterator, aResponse.getRawStream());
    if (!lRespIterator->isBinary())
      aResponse.getRawStream() << "\n";
  }
}

void MapModuleURLResolver::addModule(const std::string& aSource)
{
  RequestHandler& lRequestHandler = RequestHandler::getInstance();
  XQuery_t lQuery = lRequestHandler.getZorba().createQuery();
  zorba::ModuleInfo_t lInfo;
  std::istringstream lModuleStream(aSource);
  lQuery->parse(lModuleStream, lInfo);
  std::string lNamespace = lInfo->getTargetNamespace().c_str();
  theModules[lNamespace] = aSource;
}

void MapModuleURLResolver::releaseStream(std::istream* aStream)
{
  delete aStream;
}

Resource* MapModuleURLResolver::resolveURL(
    const String& aUrl,
    EntityData const* aEntityData)
{
  if (aEntityData->getKind() != EntityData::MODULE)
    return NULL;
  std::map<std::string, std::string>::const_iterator lIt =
      theModules.find(aUrl.str());
  if (lIt != theModules.end())
  {
    std::unique_ptr<std::istream> lModule(new std::istringstream(lIt->second));
    return StreamResource::create(lModule.release(), &releaseStream);
  }
  else {
    return NULL;
  }
}

}
}
}
