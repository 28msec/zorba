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

#pragma once
#include <zorba/zorba.h>
#include <zorba/user_exception.h>
#include <curl/curl.h>

namespace zorba {

namespace http_client {

class ErrorThrower 
{
private:
  ItemFactory* theFactory;
  struct curl_slist** theHeaderList;

public:
  ErrorThrower(ItemFactory* aFactory, struct curl_slist** aHeaderList)
    :
    theFactory(aFactory),
    theHeaderList(aHeaderList)
  {
  }
  
  void raiseException(String aNamespace, String aLocalName, String aDescription) 
  {
    if (*theHeaderList) 
    {
      curl_slist_free_all(*theHeaderList);
    }

    UserException ex = USER_EXCEPTION(theFactory->createQName(aNamespace, aLocalName), aDescription);
    throw ex;
  }
};
  
}} //namespace zorba, http_client
    
