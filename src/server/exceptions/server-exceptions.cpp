#include "server-exceptions.h"

namespace zorba {
namespace server {
namespace exceptions {

ServerException::ServerException(const std::string& aMessage) :
    std::runtime_error(aMessage),
    theStatusCode(500)
{
}

ServerException::ServerException(const std::string& aMessage, const int aStatusCode) :
    std::runtime_error(aMessage),
    theStatusCode(aStatusCode)
{
}


}
}
}
