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
