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

#ifndef REQUEST_STRUCTURES_H
#define REQUEST_STRUCTURES_H

#include <zorba/item.h>

namespace zorba
{
namespace http_client
{

typedef std::vector<std::pair<String, String> > Headers;

struct RetrySpecification
{
  bool theRetry;
  bool theRetryOnConnectionError;
  std::vector<int> theRetryStatuses;
  std::vector<int> theRetryDelays;
  RetrySpecification():
    theRetry(false),
    theRetryOnConnectionError(false)
  {
  }
};

struct Options
{
  bool theStatusOnly;
  String theOverrideContentType;
  bool theFollowRedirect;
  bool theUserDefinedFollowRedirect;
  String theUserAgent;
  int theTimeout;
  RetrySpecification theRetrySpec;
  Options() :
    theStatusOnly(false),
    theFollowRedirect(false),
    theUserDefinedFollowRedirect(false),
    theTimeout(-1)
  {
  }
};

struct Body
{
  String theMediaType;
  std::string theCharset;
  String theSrc;
  Item theContent;
  Body()
  {
  }

  int getSize()
  {
    if (!theContent.isNull())
    {
      theContent.ensureSeekable();
      return theContent.getStringValue().size();
    }
    return 0;
  }
};

struct Part
{
  Headers theHeaders;
  Body theBody;

  Part()
  {
  }

  int getSize()
  {
    return theBody.getSize();
  }
};

struct MultiPart
{
  String theMediaType;
  std::string theCharset;
  String theBoundary;
  std::vector<Part> theParts;

  MultiPart()
  {
  }

  int getSize()
  {
    int lSize = 0;
    for (std::vector<Part>::iterator lIt = theParts.begin();
         lIt != theParts.end();
         ++lIt)
      lSize += lIt->getSize();
    return lSize;
  }
};

struct Authentication
{
  bool theSendAuthentication;
  String theUserName;
  String thePassword;
  String theAuthMethod;

  Authentication():
    theSendAuthentication(false)
  {
  }
};

struct Request
{
  String theMethod;
  String theHref;
  Authentication theAuthentication;

  Headers theHeaders;

  bool theHaveBody;
  Body theBody;

  bool theHaveMultiPart;
  MultiPart theMultiPart;

  Options theOptions;

  Request() :
    theHaveBody(false),
    theHaveMultiPart(false)
  {
  }

  int getBodySize()
  {
    if (theHaveBody)
      return theBody.getSize();
    else if (theHaveMultiPart)
      return theMultiPart.getSize();
    else
      return 0;
  }
};

}
}
#endif
