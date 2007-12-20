#include "util/web/web.h"
#include "errors/Error.h"

namespace xqp
{
  
int http_get(const char* url, xqp_string& result)
{
  ZORBA_ERROR_ALERT(
    error_messages::XQP0004_SYSTEM_NOT_SUPPORTED,
    NULL
    );

  return 0;
}

} // namespace xqp
