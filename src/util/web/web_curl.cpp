#include <curl/curl.h>
#include "util/web/web.h"

namespace xqp
{

static size_t
WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void* data)
{
  size_t realsize = size * nmemb;
  std::string* str = (std::string*)data;
  str->append((char*)ptr, realsize);
  return realsize;
}

int http_get(const char* url, xqp_string& result)
{
  int result_code;
  CURL* curl_handle;
  std::string temp;

  curl_global_init(CURL_GLOBAL_ALL);
  curl_handle = curl_easy_init();                                             /* init the curl session */
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);                            /* specify URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&temp);            /* we pass our 'result' struct to the callback function */

  /* some servers don't like requests that are made without a user-agent
    field, so we provide one */
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  
  result_code = curl_easy_perform(curl_handle);
  curl_easy_cleanup(curl_handle);
  curl_global_cleanup();

  temp.push_back(0);
  result = temp;
  return result_code;
}

} // namespace xqp
