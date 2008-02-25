#ifndef __WEB_H_INCLUDED__
#define __WEB_H_INCLUDED__

#include <zorba/representations.h>

namespace xqp
{
  int http_get(const char* url, xqp_string& result);
}

#endif 
