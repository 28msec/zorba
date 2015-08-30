#ifndef SERVER_EXCEPTIONS_FORMATTER_H
#define SERVER_EXCEPTIONS_FORMATTER_H

#include "utils/JSONObject.h"

namespace zorba
{
namespace server
{
namespace exceptions
{

class Formatter
{
public:
  static void formatException(const std::exception& aException, zorba::Item& aFormattedException, int& aStatusCode);
  static void formatZorbaException(const zorba::ZorbaException& aZorbaException, utils::JSONObject& aFormattedException, int& aStatusCode);
  static void formatServerException(const exceptions::ServerException& aServerException, utils::JSONObject& aFormattedException, int& aStatusCode);
};

}
}
}
#endif



