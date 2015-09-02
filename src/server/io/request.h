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
#ifndef ZORBA_SERVER_IO_REQUEST_H_
#define ZORBA_SERVER_IO_REQUEST_H_

#include <vector>
#include <map>

#include <fcgio.h>

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
    const std::map<std::string, std::vector<std::string> >& getQueryParameters() const;
    const std::vector<std::string>* getQueryParameter(const std::string& aName) const;

    const std::string& getRequestMethod() const;
    const std::string& getRequestURI() const;
    const std::vector<std::string> getRequestURISegments() const;
    const std::string* getContentType() const;

    const std::string* getHeader(const std::string& aHeaderName) const;

    const std::string& getBody() const;
    void readBody() const;

  private:
    void initEnvironment(const FCGX_Request& aRequest);
    void initParameters() const;
    void parseParameters(const std::string& aString) const;
    void parseParameter(const std::string& aString, std::string::size_type lStart, std::string::size_type lEnd) const;
    void addParameter(const std::string& aName, const std::string& aValue) const;


    std::map<std::string, std::string> theEnvironment;

    std::string theURI;
    std::vector<std::string> theURISegments;
    std::string theQueryString;

    std::string theRequestMethod;

    mutable std::string theBody;
    mutable bool theBodyRead;

    mutable std::map<std::string, std::vector<std::string> > theParameters;
    mutable bool theParametersRead;

  };
}
}
}

#endif
