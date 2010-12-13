#pragma once
#include <zorba/zorba.h>
#include <curl/curl.h>

namespace zorba {

  namespace http_client {

    class ErrorThrower {
      private:
        const ExternalFunctionData* theFunctionData;
        ItemFactory* theFactory;
        struct curl_slist** theHeaderList;
      public:
        ErrorThrower(const ExternalFunctionData* aFunctionData,
            ItemFactory* aFactory, struct curl_slist** aHeaderList)
          : theFunctionData(aFunctionData), theFactory(aFactory),
          theHeaderList(aHeaderList)
        {
        }

        void raiseException(String aNamespace, String aLocalName, String aDescription) {
          if (*theHeaderList) {
            curl_slist_free_all(*theHeaderList);
          }
          Item lError = theFactory->createQName(aNamespace, aLocalName);
          theFunctionData->error(lError, aDescription);
        }
    };

}} //namespace zorba, http_client
    
