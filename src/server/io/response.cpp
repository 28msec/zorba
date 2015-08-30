#include "zorba/item.h"
#include "zorba/singleton_item_sequence.h"

#include "debug/quick-debug.h"
#include "exceptions/formatter.h"
#include "exceptions/server-exceptions.h"

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
  theStatusMap[200] = "OK";
  theStatusMap[500] = "Internal Server Error";
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
