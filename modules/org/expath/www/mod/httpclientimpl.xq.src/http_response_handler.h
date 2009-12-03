#ifndef HTTP_RESPONSE_HANDLER_H
#define HTTP_RESPONSE_HANDLER_H

#include <vector>

#include <zorba/item_sequence.h>

#include "request_handler.h"

namespace zorba {
class Item;
class ItemFactory;
namespace http_client {
  class HttpResponseIterator : public ItemSequence {
  private:
    std::vector<Item> theItems;
    std::vector<Item>::size_type theIndex;
    bool theResponseSet;
  public:
    HttpResponseIterator();
    virtual ~HttpResponseIterator();

  public:
    virtual bool next(Item& aItem);

  public: //Implementation specific functions
    void addItem(const Item& aItem);
    void setResponseItem(const Item& aItem);
  };

  class HttpResponseHandler : public RequestHandler {
  private:
    HttpResponseIterator* theResult;
    Item theResponse;
    Item theMultipart;
    ItemFactory* theFactory;
    bool theIsInsideMultipart;
    String theNamespace;
  public:
    HttpResponseHandler(ItemFactory* aFactory);
  public:
    ItemSequence* getResult();
  public: //Interface implementation
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
    virtual void endBody();
    virtual void beginMultipart(String aContentType, String aBoundary);
    virtual void endMultipart();
    virtual void end();
  };
}} //namespace zorba, namespace http_client

#endif //HTTP_RESPONSE_HANDLER_H
