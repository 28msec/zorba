#include <vector>
#include <string>

#include "exceptions/server-exceptions.h"

#include "io/response-iterator.h"
#include "request-handler.h"

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
    // Request to /v1/evaluate
    evaluate(aRequest, aResponse);
  }
  else
  {
    throw exceptions::ServerException("Invalid request URI <" + aRequest.getRequestURI() + ">. " +
      "Allowed requests URI to this endpoint are </v1/evaluate>");
  }
}

void Evaluation::evaluate(const io::Request& aRequest, io::Response& aResponse)
{
  RequestHandler& lRequestHandler = RequestHandler::getInstance();
  XQuery_t lQuery = lRequestHandler.getZorba().createQuery();
  lQuery->compile(aRequest.getBody());
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

}
}
}
