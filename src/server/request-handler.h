#ifndef ZORBA_SERVER_REQUEST_HANDLER_H_
#define ZORBA_SERVER_REQUEST_HANDLER_H_

#include <fcgio.h>

namespace zorba
{
namespace server
{
  class RequestHandler
  {
  public:
    RequestHandler();
    void handleRequest(const FCGX_Request& aRequest) const;
  };
}
}

#endif
