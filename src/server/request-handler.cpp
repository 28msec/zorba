#include <zorba/store_manager.h>
#include <zorba/zorba.h>

#include "io/request.h"

#include "request-handler.h"

namespace zorba
{
namespace server
{

RequestHandler::RequestHandler()
{
  theStore = StoreManager::getStore();
  theZorba = Zorba::getInstance(theStore);
}

void RequestHandler::handleRequest(const FCGX_Request& aRequest) const
{
  io::Request lRequest(aRequest);

  XQuery_t lQuery = theZorba->createQuery();
  lQuery->compile(lRequest.getBody());
  std::cout << "Content-type: text/plain\r\n"
            << "\r\n";
  lQuery->execute(std::cout);
}

}
}

