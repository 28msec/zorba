/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#include "util/curl_streambuf.h"

#include "error_thrower.h"
#include "http_response_handler.h"

namespace zorba {
class Item;

namespace http_client
{
  enum ParseState { START, HEADERS, BODY, END };

  void parse_content_type( std::string const &s, std::string *mime_type, std::string *charset,
                           bool *is_multipart = 0, std::string *boundary = 0);

  class HttpResponseHandler;

  class HttpResponseParser : public curl::listener {
  private:
    HttpResponseHandler& theHandler;
    CURL* theCurl;
    ErrorThrower& theErrorThrower;
    std::string theCurrentContentType;
    std::string theCurrentCharset;
    typedef std::vector<std::pair<std::string, std::string> > headers_type;
    headers_type theHeaders;
    int theStatus;
    std::string theMessage;
    curl::streambuf* theStreamBuffer;
    std::string theId;
    std::string theDescription;
    bool theInsideRead;
    std::map<std::string, std::string> theCodeMap;
    std::string theOverridenContentType;
    bool theStatusOnly;
    bool theSelfContained;

    bool theIsMultipart;
    std::string theBoundary;
  public:
    HttpResponseParser(
      HttpResponseHandler& aHandler,
      CURL* aCurl,
      ErrorThrower& aErrorThrower,
      std::string aOverridenContentType = "",
      bool aStatusOnly = false);
    virtual ~HttpResponseParser();
    CURLcode parse();
    void parseMultipart(std::unique_ptr<std::istream>& aStream);
    void parseMultipartBody(Item& aItem, const std::string& aBoundary);
    void getline(std::istream& aStream, std::string& aString);
    void parseHeader(const std::string& aHeader, std::string& aContentType, std::string& aCharset);

    void parseNonMultipart(std::unique_ptr<std::istream>& aStream);
    int getStatus() { return theStatus; }

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
    bool isMultipart() { return theIsMultipart; }
    const std::string& boundary() { return theBoundary; }
    virtual void curl_read(void*,size_t);
  private:
    void registerHandler();
    void parseStatusAndMessage(std::string const &aHeader);
    Item createTextItem(std::istream* aStream);
    Item createBase64Item(std::istream& aStream);

    static size_t curl_headerfunction( void*, size_t, size_t, void* );
  };

} // namespace http_client
} // namespace zorba

#endif //HTTP_RESPONSE_PARSER_H
/* vim:set et sw=2 ts=2: */
