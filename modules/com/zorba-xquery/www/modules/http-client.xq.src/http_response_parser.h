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
#ifndef HTTP_RESPONSE_PARSER_H
#define HTTP_RESPONSE_PARSER_H
#include <vector>
#include <string>
#include <map>

#include <curl/curl.h>

#include "inform_data_read.h"
#include "error_thrower.h"
#include "http_response_handler.h"

namespace zorba {
class Item;

namespace curl {
  class streambuf;
}
namespace http_client {
  class RequestHandler;

  class HttpResponseParser : public InformDataRead {
  private:
    RequestHandler& theHandler;
    CURL* theCurl;
    ErrorThrower& theErrorThrower;
    std::string theCurrentContentType;
    std::vector<std::pair<std::string, std::string> > theHeaders;
    int theStatus;
    std::string theMessage;
    zorba::curl::streambuf* theStreamBuffer;
    std::string theId;
    std::string theDescription;
    bool theInsideRead;
    std::map<std::string, std::string> theCodeMap;
    std::string theOverridenContentType;
    bool theStatusOnly;
    bool theSelfContained;
  public:
    HttpResponseParser(
      RequestHandler& aHandler,
      CURL* aCurl,
      ErrorThrower& aErrorThrower,
      std::string aOverridenContentType = "",
      bool aStatusOnly = false);
    virtual ~HttpResponseParser();
    int parse();
    /**
     * After calling parse(), it is possible that HttpResponseParser will have
     * created some long-lived objects that depend on it. In that case, it will
     * also have arranged for itself to be de-allocated at some future time
     * when it is appropriate to do so. Therefore, in this case, the code which
     * created the HttpResponseParser should NOT free it. HttpResponseParser
     * refers to itself as "not self-contained" in this case, and this method
     * will return false.
     */
    bool selfContained() { return theSelfContained; }
    virtual void beforeRead();
    virtual void afterRead();
  private:
    void registerHandler();
    void parseStatusAndMessage(std::string aHeader);
    Item createXmlItem(std::istream& aStream);
    Item createHtmlItem(std::istream& aStream);
    Item createTextItem(std::istream* aStream);
    Item createBase64Item(std::istream& aStream);
  public: //Handler
    static size_t headerfunction( void *ptr, size_t size, size_t nmemb,
      void *stream);
  };
}} // namespace zorba, http_client

#endif //HTTP_RESPONSE_PARSER_H
