#include <string>
#include <assert.h>

#include "http_response_parser.h"
#include "http_request_handler.h"

namespace zorba { namespace http_client {
  

  HttpResponseParser::HttpResponseParser(RequestHandler& aHandler, CURL* aCurl)
    : theHandler(aHandler), theCurl(aCurl), theStatus(-1)
  {
  }

  void HttpResponseParser::parse()
  {
  }

  void HttpResponseParser::registerHandler()
  {
    curl_easy_setopt(theCurl, CURLOPT_WRITEFUNCTION,
      &HttpResponseParser::writefunction);
    curl_easy_setopt(theCurl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(theCurl, CURLOPT_HEADERFUNCTION,
      &HttpResponseParser::headerfunction);
    curl_easy_setopt(theCurl, CURLOPT_HEADERDATA, this);
  }

  size_t HttpResponseParser::writefunction(void* ptr,
                                           size_t size,
                                           size_t nmemb,
                                           void* stream)
  {
    size_t lSize = size*nmemb;
    HttpResponseParser* lParser = static_cast<HttpResponseParser*>(stream);
    return lSize;
  }

  size_t HttpResponseParser::headerfunction(void *ptr,
                                            size_t size,
                                            size_t nmemb,
                                            void *stream)
  {
    size_t lSize = size*nmemb;
    HttpResponseParser* lParser = static_cast<HttpResponseParser*>(stream);
    const char* lDataChar = (const char*) ptr;
    std::string lData(lDataChar, lSize);

    if (lData.find("HTTP") == 0) {
    }
    std::string::size_type lPos = lData.find(':');
    assert(lPos != std::string::npos);
    std::string lName = lData.substr(0, lPos);
    std::string lValue = lData.substr(lPos + 1);
    if (lName == "Content-Type") {
      lParser->theCurrentContentType = lName;
    }
    if (lParser->theIsInsideMultipart) {
      lParser->theHandler.header(lName, lValue);
    } else {
      lParser->theHeaders.push_back(std::pair<std::string, std::string>(lName,
        lValue));
    }
    return lSize;
  }
}}
