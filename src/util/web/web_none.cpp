#include "util/web/web.h"
#include "errors/error_factory.h"

namespace zorba
{
  
int http_get(const char* url, xqp_string& result)
{
  ZORBA_ERROR_ALERT(
    ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED,
    NULL
    );

  return 0;
}

} // namespace zorba
