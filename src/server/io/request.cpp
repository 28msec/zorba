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
#include <cstring>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

#include "exceptions/server_exceptions.h"

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

  const std::string* lRequestURI = getEnvironmentVariable("SCRIPT_NAME");
  if (!lRequestURI)
    throw new exceptions::ServerException("Invalid request, missing REQUEST_URI", 500);
  theRequestURI = *lRequestURI;

  const std::string* lRequestMethod = getEnvironmentVariable("REQUEST_METHOD");
  if (!lRequestMethod)
    throw new exceptions::ServerException("Invalid request, missing REQUEST_METHOD", 500);
  theRequestMethod = *lRequestMethod;

  const std::string* lQueryString = getEnvironmentVariable("QUERY_STRING");
  if (!lQueryString)
    throw new exceptions::ServerException("Invalid request, missing QUERY_STRING", 500);
  theQueryString = *lQueryString;

  initParameters();

  std::string lTmpRequestURI = boost::algorithm::trim_copy_if(theRequestURI, boost::is_any_of("/"));
  boost::algorithm::split(theRequestURISegments, lTmpRequestURI, boost::is_any_of("/"));

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

void Request::initParameters()
{
  std::vector<std::string> lParameters;
  boost::algorithm::split(lParameters, theQueryString, boost::is_any_of("&"));
  for (std::vector<std::string>::const_iterator lIt = lParameters.begin();
       lIt != lParameters.end();
       ++lIt)
  {
    std::vector<std::string> lParameter;
    boost::algorithm::split(lParameter, *lIt, boost::is_any_of("="));
    if (lParameter.size())
    {
      if (lParameter[0] == "")
        continue;
      if (lParameter.size() == 2)
        theRequestParameters[lParameter[0]] = lParameter[1];
      else if (lParameter.size() == 1)
        theRequestParameters[lParameter[0]] = "";
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

const std::string* Request::getQueryParameter(const std::string& aName) const
{
  std::map<std::string, std::string>::const_iterator lIt = theRequestParameters.find(aName);
  if (lIt != theRequestParameters.end())
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
  aOs << std::endl << "===Query Parameters===" << std::endl;
  for (std::map<std::string, std::string>::const_iterator lIt = aRequest.theRequestParameters.begin();
      lIt != aRequest.theRequestParameters.end();
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
