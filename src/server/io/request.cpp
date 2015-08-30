#include "debug/quick-debug.h"

#include <boost/algorithm/string.hpp>

#include <cstring>
#include <string>
#include <sstream>

#include "exceptions/server-exceptions.h"

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

  const std::string* lRequestURI = getEnvironmentVariable("REQUEST_URI");
  if (!lRequestURI)
    throw new exceptions::ServerException("Invalid request, missing REQUEST_URI", 500);

  const std::string* lRequestMethod = getEnvironmentVariable("REQUEST_METHOD");
  if (!lRequestMethod)
    throw new exceptions::ServerException("Invalid request, missing REQUEST_METHOD", 500);

  theRequestURI = *lRequestURI;
  std::string lTmpRequestURI = boost::algorithm::trim_copy_if(theRequestURI, boost::is_any_of("/"));
  boost::algorithm::split(theRequestURISegments, lTmpRequestURI, boost::is_any_of("/"));
  theRequestMethod = *lRequestMethod;
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

const std::string& Request::getRequestMethod() const
{
  return theRequestMethod;
}

const std::string& Request::getRequestURI() const
{
  return theRequestURI;
}

const std::vector<std::string> Request::getRequestURISegments() const
{
  return theRequestURISegments;
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
