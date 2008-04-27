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
#include "runtime/rest/rest.h"

#include <curl/curl.h>

#include "runtime/util/iterator_impl.h"
#include "errors/error_manager.h"

namespace zorba {

ZorbaRestGetIteratorState::ZorbaRestGetIteratorState() 
  : theCurlHandle(0),
    theCurlErrorBuffer(0)
{
  theCurlHandle = curl_easy_init();

  theCurlErrorBuffer = new char[CURLOPT_ERRORBUFFER];
  curl_easy_setopt(theCurlHandle, CURLOPT_ERRORBUFFER, theCurlErrorBuffer);

  curl_easy_setopt(theCurlHandle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_setopt(theCurlHandle, CURLOPT_HTTPGET, 1);
}

ZorbaRestGetIteratorState::~ZorbaRestGetIteratorState()
{
  delete[] theCurlErrorBuffer; theCurlErrorBuffer = 0;

  curl_easy_cleanup(theCurlHandle);
}

void
ZorbaRestGetIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
}

void
ZorbaRestGetIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
}

store::Item_t
ZorbaRestGetIterator::nextImpl(PlanState& planState) const
{
  store::Item_t   lUri;
  xqpStringStore* lUriString;
  int             lCurlResultCode;

  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);

  std::cout << "test" << std::endl;

  if ( (lUri = CONSUME(0) ) == NULL ) {
    // todo raise an error
  }

  lUriString = lUri->getStringValue();
  std::cout << *lUriString << std::endl;

  curl_easy_setopt(state->theCurlHandle, CURLOPT_URL, lUriString->c_str());

  lCurlResultCode = curl_easy_perform(state->theCurlHandle);

  if ( lCurlResultCode != 0 ) {
    std::cout << state->theCurlErrorBuffer << std::endl;
  }


  STACK_END (state)
}

} /* namespace zorba */
