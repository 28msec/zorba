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
#include "http_client.h"

#ifdef WIN32
  #include <windows.h>
#else
  #include <time.h>
#endif

#include <curl/curl.h>
#include <map>
#include <zorba/serializer.h>
#include <zorba/external_module.h>
#include <zorba/empty_sequence.h>
#include <zorba/user_exception.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/vector_item_sequence.h>

#include "http_request_handler.h"
#include "request_parser.h"
#include "http_response_handler.h"
#include "http_response_parser.h"

namespace zorba {

namespace http_client {
#ifdef WIN32
static void set_cacert(CURL* lCurl, std::string aPath)
{
  TCHAR path[MAX_BUF_SIZE];
  int r = GetModuleFileName(NULL, path, 2048);
  if (r == -1)
    return;
#ifdef UNICODE
  char buf[MAX_BUF_SIZE];
  memset(buf, 0, MAX_BUF_SIZE);
  for (int i = 0; i <= r; ++i)
  {
    buf[i] = (char) path[i];
  }
  std::string lPath(buf);
#else
  std::string lPath(path);
#endif
  aPath = lPath.substr(0, lPath.rfind('\\'));
  aPath += "\\cacert.pem";
  if(GetFileAttributesA(aPath.c_str()) != INVALID_FILE_ATTRIBUTES)
    curl_easy_setopt(lCurl, CURLOPT_CAINFO, aPath.c_str());
  else
    curl_easy_setopt(lCurl, CURLOPT_SSL_VERIFYPEER, 0L);
}
#endif //WIN32


ExternalFunction*
HttpClientModule::getExternalFunction(const String& aLocalname)
{
  ExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname == "http-sequential-impl") {
      lFunc = new HttpSendFunction(this);
    } else if (aLocalname == "http-nondeterministic-impl") {
      lFunc = new HttpNondeterministicFunction(this);
    } else if (aLocalname == "http-deterministic-impl") {
      lFunc = new HttpDeterministicFunction(this);
    }
  }
  return lFunc;
}

int HttpSendFunction::doRequest(Request& aRequest, ItemSequence_t& aResult) const
{
  ProfileWrapper lProfileWrapper(aRequest, theJSONProfileData, theXMLProfileData);
  CURL* lCURL = curl::create();

  std::unique_ptr<HttpRequestHandler> lHandler;
  struct curl_slist* lHeaderList = 0;
  zorba::String lUri = getURI();
  ErrorThrower lThrower(theFactory, &lHeaderList, lUri);

  lHandler.reset(new HttpRequestHandler(lCURL));

  lHandler->sendRequest(aRequest);

#ifdef WIN32
  std::string caCertPath;
  set_cacert(lCURL, caCertPath);
#endif

  HttpResponseHandler lRespHandler(theFactory, lHeaderList);
  bool lStatusOnly =
      lHandler.get() == NULL ? false : (aRequest.theOptions.theStatusOnly || aRequest.theMethod == "HEAD");

  // This gives the ownership of lCurl to the HttpResponseParser
  std::unique_ptr<HttpResponseParser> lRespParser(new HttpResponseParser(lRespHandler, lCURL, lThrower,
      aRequest.theOptions.theOverrideContentType.c_str(), lStatusOnly));
  CURLcode lRetCode = lRespParser->parse();

  if (lRetCode == CURLE_OPERATION_TIMEDOUT)
    lThrower.raiseException("TIMEOUT", "A timeout occurred waiting for the response");
  else if (lRetCode)
  {
    std::string lErrorStr(curl_easy_strerror(lRetCode));
    lThrower.raiseException("HTTP", "An HTTP error occurred: " + lErrorStr);
  }

  int lStatus = lRespParser->getStatus();

  // If the Parser is "self contained", that means it didn't create any
  // objects with a lifecycle longer than itself; therefore we should free
  // it (by letting unique_ptr delete it). If the Parser is not self contained,
  // then it will have arranged for some other memory manager to free it
  // later when appropriate; therefore we should NOT let unique_ptr delete it
  // now.
  if ( ! lRespParser->selfContained())
    lRespParser.release();

  aResult = lRespHandler.releaseResult();
  return lStatus;
}

ItemSequence_t
HttpSendFunction::evaluate(const ExternalFunction::Arguments_t& args,
    const StaticContext* aStaticContext, const DynamicContext* aDynamicContext) const
{
  Item lRequestItem;
  Iterator_t arg0_iter = args[0]->getIterator();
  arg0_iter->open();
  arg0_iter->next(lRequestItem);
  arg0_iter->close();

  zorba::String lUri = getURI();
  ErrorThrower lThrower(theFactory, NULL, lUri);
  RequestParser lParser = RequestParser(lThrower, theFactory);
  Request lRequest;

  lParser.parseRequest(lRequestItem, lRequest);

  RetrySpecification& lRetrySpec = lRequest.theOptions.theRetrySpec;

  if (lRetrySpec.theRetry)
  {
    std::vector<int>& lDelays = lRetrySpec.theRetryDelays;
    ItemSequence_t lResult;
    for (unsigned int i = 0; i<lDelays.size(); ++i)
    {
      try
      {
        int lStatus = doRequest(lRequest, lResult);

        if (std::find(lRetrySpec.theRetryStatuses.begin(), lRetrySpec.theRetryStatuses.end(), lStatus) == lRetrySpec.theRetryStatuses.end())
          return lResult;
      }
      catch (ZorbaException& ex)
      {
        if (!lRetrySpec.theRetryOnConnectionError)
          throw ex;
      }

      int lMillis = lDelays[i];
#ifdef WIN32
      Sleep(lMillis);
#else
      const int32_t lFactor = 1000000;
      struct timespec lTs;
      lTs.tv_sec = lMillis / 1000;
      lTs.tv_nsec = (lMillis % 1000) * lFactor;
      nanosleep(&lTs, 0);
#endif
    }
    doRequest(lRequest, lResult);
    return lResult;
  }
  else
  {
    ItemSequence_t lResult;
    doRequest(lRequest, lResult);
    return lResult;
  }
}


} // namespace http_request
} // namespace zorba
/* vim:set et sw=2 ts=2: */
