//#include "debug/quick-debug.h"

#include <cstring>
#include <string>
#include <sstream>

#include "request.h"

namespace zorba
{
namespace server
{
namespace io
{

Request::Request(const FCGX_Request& aRequest):
    theBodyRead(false)
{
  initEnvironment(aRequest);
}

void Request::initEnvironment(const FCGX_Request& aRequest)
{
  for (char** lParam = aRequest.envp; *lParam; ++lParam)
  {
    char* lSepPos = strstr(*lParam, "=");
    if (lSepPos)
    {
      theEnvironment[std::string(*lParam, lSepPos - *lParam)] = std::string(lSepPos + 1);
    }
  }
}

const std::string& Request::getBody() const
{
  if (!theBodyRead)
    readBody();

  return theBody;
}

void Request::readBody() const
{
  std::stringstream lBody;
  lBody << std::cin.rdbuf();
  theBody = lBody.str();
  theBodyRead = true;
}

const std::string* Request::getEnvironmentVariable(const std::string& aName) const
{
  std::map<std::string, std::string>::const_iterator lIt = theEnvironment.find(aName);
  if (lIt != theEnvironment.end())
    return &(lIt->second);
  return NULL;
}

const std::string* Request::getRequestMethod() const
{
  return getEnvironmentVariable("REQUEST_METHOD");
}

const std::string* Request::getRequestURI() const
{
  return getEnvironmentVariable("REQUEST_URI");
}

std::ostream & operator<<(std::ostream &aOs, const Request& aRequest)
{
  aOs << "===Environment===" << std::endl;
  for (std::map<std::string, std::string>::const_iterator lIt = aRequest.theEnvironment.begin();
       lIt != aRequest.theEnvironment.end();
       ++lIt)
  {
    aOs << lIt->first << "=" << lIt->second << std::endl;
  }
  aOs << std::endl << "===Body===" << std::endl;
  aOs << aRequest.getBody();
  return aOs;
}

}
}
}
