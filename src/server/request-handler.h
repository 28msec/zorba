#ifndef ZORBA_SERVER_REQUEST_HANDLER_H_
#define ZORBA_SERVER_REQUEST_HANDLER_H_

#include <fcgio.h>

#include "zorba/zorba.h"
#include "zorba/serializer.h"

#include "exceptions/server-exceptions.h"
#include "utils/JSONObject.h"

namespace zorba
{
namespace server
{
  class RequestHandler
  {
  public:
    static RequestHandler& getInstance();
    void handleRequest(const FCGX_Request& aRequest) const;


    Zorba& getZorba() { return *theZorba; }
    Serializer_t getSerializer() { return theSerializer; }
    ItemFactory& getItemFactory() { return *theItemFactory; }

  private:
    RequestHandler();

    void * theStore;
    Zorba * theZorba;
    Zorba_SerializerOptions_t theOptions;
    Serializer_t theSerializer;
    ItemFactory * theItemFactory;
  };
}
}

#endif
