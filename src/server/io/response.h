#ifndef ZORBA_SERVER_IO_RESPONSE_H_
#define ZORBA_SERVER_IO_RESPONSE_H_

#include <map>

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

    static std::string JSON_UTF8_CT;
    static std::string TEXT_UTF8_CT;
    static std::string XML_UTF8_CT;
    static std::string BINARY_UTF8_CT;
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
    std::string& theContentType;
    std::ostream& theResponseStream;
    std::map<std::string, std::string> theHeaders;
  };
}
}
}

#endif
