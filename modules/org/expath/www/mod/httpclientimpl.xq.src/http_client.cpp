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
      Item lSerial;

      bool lReqSet = args[0]->next(lRequest);
      bool lHrefSet = args[1]->next(lHref);
      bool lContentSet = args[2]->next(lContent);
      bool lSerialSet = args[3]->next(lSerial);

      std::string lData;

      std::auto_ptr<HttpRequestHandler> lHandler;
      std::auto_ptr<RequestParser> lParser;

      if (lReqSet) {
        String lSerialString = lSerialSet ? lSerial.getStringValue() : "";
        lHandler.reset(new HttpRequestHandler(lCURL, args[2], lSerialString));
        lParser.reset(new RequestParser(lHandler.get()));
        lParser->parse(lRequest);
      } else if (lContentSet) {
        std::stringstream lSerStream;
        if (lSerialSet && lSerial.getStringValue() == "text") {
          lSerStream << lContent.getStringValue();
        } else {
          Zorba_SerializerOptions_t lOptions;
          Serializer_t lSerializer = Serializer::createSerializer(lOptions);

          // Build a singleton item sequence which is also a Serializable.
          // The new serializer interface only accepts Serializable objects.
          SingletonItemSequence lSequence(lContent);
          lSerializer->serialize((Serializable*)&lSequence, lSerStream);
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
      String lOverrideContentType;
      if (lHandler.get())
        lHandler->getOverrideContentType(lOverrideContentType);
      HttpResponseParser lRespParser(lRespHandler, lCURL,
        lOverrideContentType.c_str());
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
