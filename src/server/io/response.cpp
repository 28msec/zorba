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
#include "zorba/item.h"
#include "zorba/singleton_item_sequence.h"

#include "exceptions/server_exceptions.h"
#include "exceptions/formatter.h"
#include "debug/quick-debug.h"
#include "response.h"

namespace zorba
{
namespace server
{
namespace io
{

const std::string& HTTPStatusCodes::getCodeDescription(int aStatusCode)
{
  if (theStatusMap.size() == 0)
    init();

  std::map<int, std::string>::const_iterator lIt = theStatusMap.find(aStatusCode);
  if (lIt != theStatusMap.end())
    return lIt->second;
  return theEmptyDescription;
}

void HTTPStatusCodes::init()
{
  theStatusMap[100] = "Continue";
  theStatusMap[101] = "Switching Protocols";
  theStatusMap[102] = "Processing";

  theStatusMap[200] = "OK";
  theStatusMap[201] = "Created";
  theStatusMap[202] = "Accepted";
  theStatusMap[203] = "Non-Authoritative Information";
  theStatusMap[204] = "No Content";
  theStatusMap[205] = "Reset Content";
  theStatusMap[206] = "Partial Content";
  theStatusMap[207] = "Multi-Status";
  theStatusMap[208] = "Already Reported";
  theStatusMap[226] = "IM used";

  theStatusMap[300] = "Multiple Choices";
  theStatusMap[301] = "Moved Permanently";
  theStatusMap[302] = "Found";
  theStatusMap[303] = "See Other";
  theStatusMap[304] = "Not Modified";
  theStatusMap[305] = "Use Proxy";
  theStatusMap[306] = "Switch Proxy";
  theStatusMap[307] = "Temporary Redirect";
  theStatusMap[308] = "Permanent Redirect";

  theStatusMap[400] = "Bad Request";
  theStatusMap[401] = "Unauthorized";
  theStatusMap[402] = "Payment Required";
  theStatusMap[403] = "Forbidden";
  theStatusMap[404] = "Not Found";
  theStatusMap[405] = "Method Not Allowed";
  theStatusMap[406] = "Not Acceptable";
  theStatusMap[407] = "Proxy Authentication Required";
  theStatusMap[408] = "Request Timeout";
  theStatusMap[409] = "Conflict";
  theStatusMap[410] = "Gone";
  theStatusMap[411] = "Length Required";
  theStatusMap[412] = "Precondition Failed";
  theStatusMap[413] = "Payload Too Large";
  theStatusMap[414] = "Request-URI Too Long";
  theStatusMap[415] = "Unsupported Media Type";
  theStatusMap[416] = "Requested Range Not Satisfiable";
  theStatusMap[417] = "Expectation Failed";
  theStatusMap[418] = "I'm a teapot";
  theStatusMap[419] = "Authentication Timeout";
  theStatusMap[420] = "Method Failure";
  theStatusMap[421] = "Misdirected Request";
  theStatusMap[422] = "Unprocessable Entity";
  theStatusMap[423] = "Locked";
  theStatusMap[424] = "Failed Dependency";
  theStatusMap[426] = "Upgrade Required";
  theStatusMap[428] = "Precondition Required";
  theStatusMap[429] = "Too Many Requests";

  theStatusMap[500] = "Internal Server Error";

  theStatusMap[501] = "Not Implemented";
  theStatusMap[502] = "Bad Gateway";
  theStatusMap[503] = "Service Unavailable";
  theStatusMap[504] = "Gateway Timeout";
  theStatusMap[505] = "HTTP Version Not Supported";
  theStatusMap[506] = "Variant Also Negotiates";
  theStatusMap[507] = "Insufficient Storage";
  theStatusMap[508] = "Loop Detected";
  theStatusMap[509] = "Bandwidth Limit Exceeded";
  theStatusMap[510] = "Not Extended";
  theStatusMap[511] = "Network Authentication Required";
  theStatusMap[520] = "Unknown Error";
}

std::map<int, std::string> HTTPStatusCodes::theStatusMap;
std::string HTTPStatusCodes::theEmptyDescription;

std::string ContentTypes::JSON_UTF8_CT = "application/json;charset=UTF-8";
std::string ContentTypes::TEXT_UTF8_CT = "text/plain;charset=UTF-8";
std::string ContentTypes::XML_UTF8_CT = "application/xml;charset=UTF-8";
std::string ContentTypes::BINARY_UTF8_CT = "application/octet-stream";

const std::string& ContentTypes::getContentTypeForItem(const zorba::Item& aItem)
{
  if (aItem.isAtomic())
    return ContentTypes::TEXT_UTF8_CT;
  else if (aItem.isJSONItem()) //Object or Array
    return ContentTypes::JSON_UTF8_CT;
  else if (aItem.isNode())
    return ContentTypes::XML_UTF8_CT;
  else
    return ContentTypes::BINARY_UTF8_CT;
}

bool ContentTypes::isX_WWW_FORM_URLENCODED(const std::string& aContentType)
{
  std::string lContentType(aContentType);
  std::transform(lContentType.begin(), lContentType.end(), lContentType.begin(), ::tolower);
  return lContentType.find("application/x-www-form-urlencoded") == 0;
}

Response::Response(std::ostream& aResponseStream):
    theHeadersSent(false),
    theStatusCode(200),
    theContentType(ContentTypes::JSON_UTF8_CT),
    theResponseStream(aResponseStream)
{
}

Response::~Response()
{
  if (!theHeadersSent)
  {
    sendException(exceptions::ServerException("No response was produced"));
  }
}

void Response::setStatus(int aStatus)
{
  theStatusCode = aStatus;
}

void Response::setContentType(const std::string& aContentType)
{
  theContentType = aContentType;
}

void Response::addHeader(const std::string& aName, const std::string& aValue)
{
  theHeaders[aName] = aValue;
}

void Response::sendHeaders()
{
  theResponseStream
      << "Status: " << theStatusCode << " " << HTTPStatusCodes::getCodeDescription(theStatusCode) << "\r\n"
      << "Content-Type: " << theContentType << "\r\n";

  for (std::map<std::string, std::string>::const_iterator lIt = theHeaders.begin();
       lIt != theHeaders.end();
       ++lIt)
  {
    theResponseStream
        << lIt->first << ": " << lIt->second << "\r\n";
  }

  theResponseStream << "\r\n";
  theHeadersSent = true;
}

void Response::sendException(const std::exception& aException)
{
  zorba::Item lFormattedException;
  int lStatus;
  exceptions::Formatter::formatException(aException, lFormattedException, lStatus);
  zorba::SingletonItemSequence lErrorSequence(lFormattedException);
  std::stringstream lExceptionResponse;
  RequestHandler::getInstance().getSerializer()->serialize(&lErrorSequence, lExceptionResponse);
  sendError(lExceptionResponse.str(), lStatus);
}

void Response::sendError(const std::string& aResponse, int aStatusCode, const std::string& aContentType)
{
  setStatus(aStatusCode);
  setContentType(aContentType);
  sendHeaders();
  theResponseStream << aResponse << std::endl;
}

std::ostream & operator<<(std::ostream &aOs, const Response& aRequest)
{
  return aOs;
}

}
}
}
