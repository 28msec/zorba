#include <curl/curl.h>

#include <zorba/zorba.h>
#include <zorba/serializer.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/singleton_item_sequence.h>

#include "http_request_handler.h"
#include "request_parser.h"
#include "http_response_handler.h"
#include "http_response_parser.h"

namespace zorba {
namespace http_client {
  class HttpSendFunction : public NonePureStatelessExternalFunction {
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

    virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args,
      const StaticContext* aStaticContext, const DynamicContext* aDynamicContext)
      const 
    {
      CURL* lCURL = curl_easy_init();
      
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
      HttpResponseHandler lRespHandler(theFactory);
      //This gives the ownership of lCurl to the HttpResponseParser
      String lOverrideContentType;
      if (lHandler.get())
        lHandler->getOverrideContentType(lOverrideContentType);
      HttpResponseParser lRespParser(lRespHandler, lCURL,
        lOverrideContentType.c_str());
      lRespParser.parse();

      if (lHeaderList) {
        curl_slist_free_all(lHeaderList);
      }

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
    getURI() const { return "http://expath.org/ns/httpclientimpl"; }

    virtual StatelessExternalFunction*
    getExternalFunction(String aLocalname) const
    {
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
