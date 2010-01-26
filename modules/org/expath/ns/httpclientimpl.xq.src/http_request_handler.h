#ifndef HTTP_REQUEST_HANDLER_H
#define HTTP_REQUEST_HANDLER_H

#include <sstream>
#include <vector>

#include <curl/curl.h>
#include <zorba/zorba.h>

#include "request_handler.h"

namespace zorba { namespace http_client {

  class HttpRequestHandler : public RequestHandler {
  private:
    CURL* theCurl;
    bool theStatusOnly;
    String theOverrideContentType;
    bool theInsideMultipart;
    std::vector<struct curl_slist*> theHeaderLists;
    bool theLastBodyHadContent;
    ItemSequence* theContent;
    std::ostringstream* theSerStream;
    struct curl_httppost* thePost;
    struct curl_httppost* theLast;
    String theCurrentContentType;

  public: //Constructions
    HttpRequestHandler(CURL* aCurl,
                       ItemSequence* aContent);
    virtual ~HttpRequestHandler();

  public: //Interfaces
    /**
     * @brief Get the override-content-type option.
     *
     * If the user set the override-content-type option, this method will
     * set the result to the user specified value and will return true.
     * Otherwise it will return false.
     *
     * @param aResult The override-content-type option, if set.
     * @return A boolean indicating if the override-content-type is set.
     */
    bool getOverrideContentType(String& aResult);

  public: //Implementation of parent interface
    virtual void begin();
    virtual void beginResponse(int aStatus, String aMessage);
    virtual void endResponse();
    virtual void beginRequest(
      String aMethod,
      String href,
      bool aStatusOnly,
      String aUsername,
      String aPassword,
      String aAuthMethod,
      bool aSendAuthorization,
      String aOverrideContentType,
      bool aFollowRedirect,
      int aTimeout = -1);
    virtual void endRequest();
    virtual void header(String aName, String aValue);
    virtual void beginBody(
      String aContentType,
      String aEncoding,
      String aId,
      String aDescription,
      String aSrc);
    virtual void any(Item aItem);

    void serializeItem( Item aItem );
    virtual void endBody();
    virtual void beginMultipart(String aContentType, String aBoundary);
    virtual void endMultipart();
    virtual void end();

  private: //Helper functions
    void cleanUpBody();
  };

}}

#endif //HTTP_REQUEST_HANDLER_H
