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
#include "curl_stream_buffer.h"
#include "inform_data_read.h"
#include <cstring>
#include <stdlib.h>

namespace zorba { namespace http_client {
  CurlStreamBuffer::CurlStreamBuffer(CURLM* aMultiHandle, CURL* aEasyHandle)
    : std::streambuf(), MultiHandle(aMultiHandle), EasyHandle(aEasyHandle),
    theInformer(0)
  {
    CurlErrorBuffer = new char[CURLOPT_ERRORBUFFER];
    memset(CurlErrorBuffer, 0, CURLOPT_ERRORBUFFER);

    curl_easy_setopt(EasyHandle, CURLOPT_ERRORBUFFER, CurlErrorBuffer);
    curl_easy_setopt(EasyHandle, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(EasyHandle, CURLOPT_WRITEFUNCTION, CurlStreamBuffer::write_callback);
    curl_easy_setopt(EasyHandle, CURLOPT_BUFFERSIZE, INITIAL_BUFFER_SIZE);
  }

  int CurlStreamBuffer::multi_perform()
  {
    CURLMsg* msg;
    int MsgsInQueue;
    int StillRunning = 0;
    bool done = false;
    int error = 0;

    while (!done)
    {
      while (CURLM_CALL_MULTI_PERFORM == curl_multi_perform(MultiHandle, &StillRunning))
        ;

      while ((msg = curl_multi_info_read(MultiHandle, &MsgsInQueue)))
        if (msg->msg == CURLMSG_DONE)
        {
          error = msg->data.result;
          done = true;
        }
    }

    return error;
  }

  CurlStreamBuffer::~CurlStreamBuffer()
  {
    delete[] CurlErrorBuffer;
    ::free(eback());
  }

  size_t CurlStreamBuffer::write_callback(char* buffer, size_t size, size_t nitems, void* userp)
  {
    CurlStreamBuffer* sbuffer = static_cast<CurlStreamBuffer*>(userp);
    if (sbuffer->theInformer != 0) {
      sbuffer->theInformer->beforeRead();
    }
    size_t result = sbuffer->sputn(buffer, size*nitems);
    sbuffer->setg(sbuffer->eback(), sbuffer->gptr(), sbuffer->pptr());
    if (sbuffer->theInformer != 0) {
      sbuffer->theInformer->afterRead();
    }
    return result;
  }

  int CurlStreamBuffer::overflow(int c)
  {
    char* _pptr = pptr();
    char* _gptr = gptr();
    char* _eback = eback();

    int new_size = 2 * (epptr() - _eback);
    if (new_size == 0)
      new_size = INITIAL_BUFFER_SIZE;

    char* new_buffer = (char*)realloc(_eback, new_size);

    if (new_buffer != _eback)
    {
      _pptr = new_buffer + (_pptr - _eback);
      _gptr = new_buffer + (_gptr - _eback);
      _eback = new_buffer;
    }
    setp(_pptr, new_buffer + new_size);
    sputc(c);
    setg(_eback, _gptr, pptr());

    return 0;
  }

  int CurlStreamBuffer::underflow()
  {
    return EOF;
  }

  const char* CurlStreamBuffer::getErrorBuffer() const
  {
    return CurlErrorBuffer;
  }

  void CurlStreamBuffer::setInformer( InformDataRead* aInformer )
  {
    theInformer = aInformer;
  }
}} //namespace zorba, http_client
