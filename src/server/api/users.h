#ifndef ZORBA_SERVER_API_USERS_H_
#define ZORBA_SERVER_API_USERS_H_

#include "io/request.h"
#include "io/response.h"

namespace zorba
{
namespace server
{
namespace api
{
  class Users
  {
    public:
    static void handleRequest(const io::Request& aRequest, io::Response& aResponse);
  };
}
}
}

#endif
