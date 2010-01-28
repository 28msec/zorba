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
#ifndef CURL_STREAM_BUFFER_H
#define CURL_STREAM_BUFFER_H

#include <streambuf>

#include <curl/curl.h>

namespace zorba { namespace http_client {
  class InformDataRead;
  class CurlStreamBuffer : public std::streambuf
  {
  public:
    CurlStreamBuffer(CURLM* aMultiHandle, CURL* aEasyHandle);
    virtual ~CurlStreamBuffer();

    virtual int overflow(int c);
    virtual int underflow();
    int multi_perform();
    void setInformer(InformDataRead* aInformer);

    const char* getErrorBuffer() const;

  protected:
    char* CurlErrorBuffer;
    CURLM* MultiHandle;
    CURL* EasyHandle;
    InformDataRead *theInformer;

    // callback called by curl
    static size_t
      write_callback(char *buffer, size_t size, size_t nitems, void *userp);

    static const int INITIAL_BUFFER_SIZE = 1024;
  };
}} //namespace zorba, http_client
#endif //CURL_STREAM_BUFFER_H
