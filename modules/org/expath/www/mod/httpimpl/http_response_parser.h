#ifndef HTTP_RESPONSE_PARSER_H
#define HTTP_RESPONSE_PARSER_H
#include <vector>
#include <string>

#include <curl/curl.h>

namespace zorba {namespace http_client {
  class RequestHandler;
  class CurlStreamBuffer;

  class HttpResponseParser {
  private:
    RequestHandler& theHandler;
    CURL* theCurl;
    CURLM* theMulti;
    std::string theCurrentContentType;
    std::vector<std::pair<std::string, std::string> > theHeaders;
    long theStatus;
    std::string theMessage;
    CurlStreamBuffer* theStreamBuffer;
  public:
    HttpResponseParser(RequestHandler& aHandler, CURL* aCurl);
    virtual ~HttpResponseParser();
    void parse();
  private:
    void registerHandler();
  public: //Handler
    static size_t writefunction(void* ptr, size_t size, size_t nmemb,
      void* stream);
    static size_t headerfunction( void *ptr, size_t size, size_t nmemb,
      void *stream);
  };
}} // namespace zorba, http_client

#endif //HTTP_RESPONSE_PARSER_H
