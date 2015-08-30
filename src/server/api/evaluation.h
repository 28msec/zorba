#ifndef ZORBA_SERVER_API_EVALUATION_H_
#define ZORBA_SERVER_API_EVALUATION_H_

#include "io/request.h"
#include "io/response.h"

namespace zorba
{
namespace server
{
namespace api
{
  class Evaluation
  {
    public:
    static void handleRequest(const io::Request& aRequest, io::Response& aResponse);

    private:
    static void evaluate(const io::Request& aRequest, io::Response& aResponse);
  };
}
}
}

#endif
