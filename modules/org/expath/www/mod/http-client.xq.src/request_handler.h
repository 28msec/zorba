#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

namespace zorba {
class String;
class Item;

namespace http_client {
  class RequestHandler {
  public:
    virtual ~RequestHandler();
  public:
    virtual void begin() = 0;
    virtual void beginResponse(int aStatus, String aMessage) = 0;
    virtual void endResponse() = 0;
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
      int aTimeout = -1) = 0;
    virtual void endRequest() = 0;
    virtual void header(String aName, String aValue) = 0;
    virtual void beginBody(
      String aContentType,
      String aEncoding,
      String aId,
      String aDescription,
      String aSrc) = 0;
    virtual void any(Item aItem) = 0;
    virtual void endBody() = 0;
    virtual void beginMultipart(String aContentType, String aBoundary) = 0;
    virtual void endMultipart() = 0;
    virtual void end() = 0;
  };
}
}

#endif //REQUEST_HANDLER_H
