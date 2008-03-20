#include "util/web/web.h"
#include "errors/error_manager.h"

namespace zorba
{
  
int http_get(const char* url, xqp_string& result)
{
  ZORBA_ERROR(  ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED );

  return 0;
}

} // namespace zorba
