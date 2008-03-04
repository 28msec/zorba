#ifndef __WEB_H_INCLUDED__
#define __WEB_H_INCLUDED__

#include <zorbatypes/representations.h>

namespace zorba
{
  int http_get(const char* url, xqp_string& result);
}

#endif 
