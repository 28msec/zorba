#ifndef SERVER_EXCEPTIONS_H
#define SERVER_EXCEPTIONS_H

#include <stdexcept>
namespace zorba
{
namespace server
{
namespace exceptions
{

class ServerException : public std::runtime_error
{
public:
  ServerException(const std::string& aMessage);

  ServerException(const std::string& aMessage, const int aStatusCode);

  int getStatusCode() const { return theStatusCode; };

private:
  int theStatusCode;
};

}
}
}
#endif
