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

    throw USER_EXCEPTION(theFactory->createQName(aNamespace, aLocalName), aDescription);
  }
};
  
}} //namespace zorba, http_client
    
