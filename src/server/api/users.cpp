#include "exceptions/server-exceptions.h"

#include "users.h"

namespace zorba
{
namespace server
{
namespace api
{

void Users::handleRequest(const io::Request& aRequest, io::Response& aResponse)
{
  throw exceptions::ServerException("Invalid request URI <" + aRequest.getRequestURI() + ">: " +
      "not implemented.");
}

}
}
}
