#include <curl/curl.h>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/singleton_item_sequence.h>

#include "http_request_handler.h"
#include "request_parser.h"
#include "http_response_handler.h"
#include "http_response_parser.h"

namespace zorba {
namespace http_client {
  class HttpSendFunction : public StatelessExternalFunction {
  protected:
    const ExternalModule*     theModule;
    ItemFactory*              theFactory;


  public:
    HttpSendFunction(const ExternalModule* aModule) 
      : 
        theModule(aModule),
        theFactory(Zorba::getInstance(0)->getItemFactory()) {}
    
    virtual ~HttpSendFunction() {}

  public:
    virtual String
    getURI() const { return theModule->getURI(); }

    virtual String
    getLocalName() const { return "http-send-request-impl"; }

    virtual bool
      isDeterministic() const { return true; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const 
    {
      CURL* lCURL = curl_easy_init();
      
      Item lRequest;
      Item lHref;
      Item lContent;
      Item lSerial;

      bool lReqSet = args[0]->next(lRequest);
      bool lHrefSet = args[1]->next(lHref);
      args[2]->next(lContent);
      bool lSerialSet = args[3]->next(lSerial);

      std::string lData;

      if (lReqSet) {
        String lSerialString = lSerialSet ? lSerial.getStringValue() : "";
        HttpRequestHandler lHandler(lCURL, args[2], lSerialString);
        RequestParser lParser(&lHandler);
        lParser.parse(lRequest);
      } else {
        std::stringstream lSerStream;
        if (lSerialSet && lSerial.getStringValue() == "text") {
          lSerStream << lContent.getStringValue();
        } else {
          lContent.serialize(lSerStream);
        }
        lData = lSerStream.str();
        curl_easy_setopt(lCURL, CURLOPT_POSTFIELDSIZE, lData.length());
        curl_easy_setopt(lCURL, CURLOPT_POSTFIELDS, lData.c_str());
      }
      if (lHrefSet) {
        curl_easy_setopt(lCURL, CURLOPT_URL, lHref.getStringValue().c_str());
      }
      curl_easy_setopt(lCURL, CURLOPT_USERAGENT, "libcurl-agent/1.0");
      HttpResponseHandler lRespHandler(theFactory);
      //This gives the ownership of lCurl to the HttpResponseParser
      HttpResponseParser lRespParser(lRespHandler, lCURL);
      lRespParser.parse();
      return ItemSequence_t(lRespHandler.getResult());
    }
  }; // class http_request

  class HttpClientModule : public ExternalModule {
  protected:
    HttpSendFunction* theFunction;

  public:
    virtual ~HttpClientModule() { delete theFunction; }
    HttpClientModule() 
    {
      theFunction = new HttpSendFunction(this);
    }

    virtual String
    getURI() const { return "http://www.expath.org/mod/httpclientimpl"; }

    virtual StatelessExternalFunction*
    getExternalFunction(String aLocalname) const
    {
      if (aLocalname != "send-request") {
        return 0;
      }
      return theFunction;
    }

    virtual void
    destroy()
    {
      if (!dynamic_cast<HttpClientModule*>(this)) {
        return;
      }
      delete this;
    }
  };
} // namespace http_request
} // namespace zorba


#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::http_client::HttpClientModule();
}
