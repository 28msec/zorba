#include "exceptions/server-exceptions.h"

#include "projects.h"

namespace zorba
{
namespace server
{
namespace api
{

void Projects::handleRequest(const io::Request& aRequest, io::Response& aResponse)
{
  throw exceptions::ServerException("Invalid request URI <" + aRequest.getRequestURI() + ">: " +
      "not implemented.");
}

}
}
}
