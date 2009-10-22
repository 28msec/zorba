#include <string>
#include <assert.h>

#include "http_response_parser.h"
#include "http_request_handler.h"
#include "curl_stream_buffer.h"

namespace zorba { namespace http_client {
  

  HttpResponseParser::HttpResponseParser(RequestHandler& aHandler, CURL* aCurl)
    : 
  theHandler(aHandler), theCurl(aCurl), theStatus(-1), theStreamBuffer(0)
  {
    theMulti = curl_multi_init();
    curl_multi_add_handle(theMulti, theCurl);
    theStreamBuffer = new CurlStreamBuffer(theMulti, theCurl);
    registerHandler();
  }

  HttpResponseParser::~HttpResponseParser()
  {
    delete theStreamBuffer;
    curl_multi_remove_handle(theMulti, theCurl);
    curl_easy_cleanup(theCurl);
    curl_multi_cleanup(theMulti);
  }

  void HttpResponseParser::parse()
  {
    int code = theStreamBuffer->multi_perform();
  }

  void HttpResponseParser::registerHandler()
  {
    curl_easy_setopt(theCurl, CURLOPT_HEADERFUNCTION,
      &HttpResponseParser::headerfunction);
    curl_easy_setopt(theCurl, CURLOPT_HEADERDATA, this);
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
      return lSize;
    }
    std::string::size_type lPos = lData.find(':');
    if (lPos == std::string::npos) {
      return lSize;
    }
    std::string lName = lData.substr(0, lPos);
    std::string lValue = lData.substr(lPos + 1);
    if (lName == "Content-Type") {
      lParser->theCurrentContentType = lName;
    }
    lParser->theHandler.header(lName, lValue);
    return lSize;
  }
}}
