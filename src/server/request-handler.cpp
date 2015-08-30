#include <boost/algorithm/string.hpp>

#include "zorba/store_manager.h"
#include "zorba/zorba.h"

#include "api/users.h"
#include "api/projects.h"
#include "api/evaluation.h"

#include "io/request.h"
#include "io/response.h"


#include "request-handler.h"

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

void RequestHandler::handleRequest(const FCGX_Request& aRequest) const
{
  io::Request lRequest(aRequest);
  io::Response lResponse(std::cout);

  try
  {
    const std::vector<std::string>& lURISegments = lRequest.getRequestURISegments();

    if (lURISegments.size() == 0 || lURISegments[0] != "v1")
    {
      throw exceptions::ServerException("Invalid request <" + lRequest.getRequestURI() + ">, valid requests start with </v1>");
    }

    if (lURISegments.size() == 1)
    {
      // Request to /v1
      lResponse.setContentType(io::ContentTypes::TEXT_UTF8_CT);
      lResponse.sendHeaders();
      lResponse.getRawStream() << "Zorba Server 3.1.0" << std::endl;
    }
    else
    {
      if (lURISegments[1] == "users")
      {
        api::Users::handleRequest(lRequest, lResponse);
      }
      else if (lURISegments[1] == "projects")
      {
        api::Projects::handleRequest(lRequest, lResponse);
      }
      else if (lURISegments[1] == "evaluate")
      {
        api::Evaluation::handleRequest(lRequest, lResponse);
      }
      else
      {
        throw exceptions::ServerException("Invalid request <" + lRequest.getRequestURI() + ">, "
            "valid requests start with </v1/users>, </v1/projects>, </v1/evaluate>");
      }
    }
  }
  catch (const std::exception& lException)
  {
    lResponse.sendException(lException);
  }

}

}
}

