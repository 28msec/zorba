#include "io/request.h"

#include "request-handler.h"

namespace zorba
{
namespace server
{

RequestHandler::RequestHandler()
{

}

void RequestHandler::handleRequest(const FCGX_Request& aRequest) const
{
  io::Request lRequest(aRequest);

  std::cout << "Content-type: text/html\r\n"
            << "\r\n"
            << lRequest;
}

}
}

