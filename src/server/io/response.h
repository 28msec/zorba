/*
 * Copyright 2015 Federico Cavalieri.
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
#ifndef ZORBA_SERVER_IO_RESPONSE_H_
#define ZORBA_SERVER_IO_RESPONSE_H_

#include <map>

#include "utils/debug.h"
#include "zorba/item.h"

namespace zorba
{
namespace server
{
namespace io
{
  class HTTPStatusCodes
  {
    public:
    static const std::string& getCodeDescription(int aStatusCode);

    private:
    static void init();
    static std::map<int, std::string> theStatusMap;
    static std::string theEmptyDescription;
  };

  class ContentTypes
  {
  public:
    static const std::string& getContentTypeForItem(const zorba::Item& aItem);

    static bool isX_WWW_FORM_URLENCODED(const std::string& aContentType);

  public:

    static const std::string JSON_UTF8_CT;
    static const std::string TEXT_UTF8_CT;
    static const std::string XML_UTF8_CT;
    static const std::string BINARY_UTF8_CT;
  };


  class Response
  {
    friend std::ostream & operator<<(std::ostream &aOs, const Response& aReq);

  public:
    Response(std::ostream& aResponseStream);
    ~Response();

    void setStatus(int aStatus);
    void setContentType(const std::string& aContentType);
    void addHeader(const std::string& aName, const std::string& aValue);

    void sendHeaders();
    void sendException(const std::exception& aException);
    void sendError(const std::string& aResponse, int aStatusCode = 200, const std::string& aContentType = ContentTypes::JSON_UTF8_CT);

    std::ostream& getRawStream() { return theResponseStream; }

  private:
    bool theHeadersSent;
    int theStatusCode;
    std::string theContentType;
    std::ostream& theResponseStream;
    std::map<std::string, std::string> theHeaders;
  };
}
}
}

#endif
