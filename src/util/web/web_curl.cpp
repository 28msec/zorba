/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <curl/curl.h>
#include "util/web/web.h"

namespace zorba
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

  curl_handle = curl_easy_init();                                             /* init the curl session */
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);                            /* specify URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&temp);            /* we pass our 'result' struct to the callback function */

  /* some servers don't like requests that are made without a user-agent
    field, so we provide one */
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  
  result_code = curl_easy_perform(curl_handle);
  curl_easy_cleanup(curl_handle);

  temp.push_back(0);
  result = temp;
  return result_code;
}

} // namespace zorba
