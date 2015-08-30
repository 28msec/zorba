#ifndef ZORBA_SERVER_IO_REQUEST_H_
#define ZORBA_SERVER_IO_REQUEST_H_

#include <fcgio.h>
#include <vector>
#include <map>

namespace zorba
{
namespace server
{
namespace io
{
  class Request
  {
    friend std::ostream & operator<<(std::ostream &aOs, const Request& aReq);

  public:
    Request(const FCGX_Request& aFCGIRequest);

    const std::string* getEnvironmentVariable(const std::string& aName) const;
    const std::string& getRequestMethod() const;
    const std::string& getRequestURI() const;
    const std::vector<std::string> getRequestURISegments() const;

    const std::string* getHeader(const std::string& aHeaderName) const;

    const std::string& getBody() const;
    void readBody() const;

  private:
    void initEnvironment(const FCGX_Request& aRequest);
    std::map<std::string, std::string> theEnvironment;

    std::string theRequestURI;
    std::vector<std::string> theRequestURISegments;
    std::string theRequestMethod;
    mutable std::string theBody;
    mutable bool theBodyRead;

  };
}
}
}

#endif
