/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#include <curl/curl.h>

#include "http_request_handler.h"
#include "request_parser.h"
#include "http_response_handler.h"
#include "http_response_parser.h"

namespace zorba {

  namespace http_client {

    ItemSequence_t
    general_evaluate(const StatelessExternalFunction::Arguments_t& args,
      const StaticContext* aStaticContext, const DynamicContext* aDynamicContext,
      ItemFactory* aFactory)
    {
      CURL* lCURL = curl_easy_init();
      CURLM* lCURLM = curl_multi_init();
      
      Item lRequest;
      Item lHref;
      Item lContent;

      bool lReqSet = args[0]->next(lRequest);
      bool lHrefSet = args[1]->next(lHref);

      std::string lData;

      std::auto_ptr<HttpRequestHandler> lHandler;
      std::auto_ptr<RequestParser> lParser;
      struct curl_slist* lHeaderList = 0;

      if (lReqSet) {
        lHandler.reset(new HttpRequestHandler(lCURL, args[2]));
        lParser.reset(new RequestParser(lHandler.get()));
        lParser->parse(lRequest);
      }
      if (lHrefSet) {
        curl_easy_setopt(lCURL, CURLOPT_URL, lHref.getStringValue().c_str());
      }
      curl_easy_setopt(lCURL, CURLOPT_USERAGENT, "libcurl-agent/1.0");
      HttpResponseHandler lRespHandler(aFactory);
      //This gives the ownership of lCurl to the HttpResponseParser
      String lOverrideContentType;
      if (lHandler.get())
        lHandler->getOverrideContentType(lOverrideContentType);
      HttpResponseParser lRespParser(lRespHandler, lCURL, lCURLM,
        lOverrideContentType.c_str());
      lRespParser.parse();

      if (lHeaderList) {
        curl_slist_free_all(lHeaderList);
      }

      return ItemSequence_t(lRespHandler.getResult());
    }

    ItemSequence_t 
    HttpSendFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
      const StaticContext* aStaticContext, const DynamicContext* aDynamicContext) const 
    {
      return general_evaluate(args, aStaticContext, aDynamicContext, theFactory);
    }

    HttpClientModule::~HttpClientModule()
    {
      for (FuncMap_t::const_iterator lIter = theFunctions.begin();
           lIter != theFunctions.end(); ++lIter) {
        delete lIter->second;
      }
      theFunctions.clear();
    }

  } // namespace http_request
} // namespace zorba
