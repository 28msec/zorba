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
#ifndef HTTP_RESPONSE_HANDLER_H
#define HTTP_RESPONSE_HANDLER_H

#include <vector>
#include <map>
#include <curl/curl.h>

#include <zorba/item_sequence.h>
#include <zorba/iterator.h>

#include "request_handler.h"

namespace zorba {
class Item;
class ItemFactory;
namespace http_client {
  class HttpResponseParser;

  class HttpResponseIterator : public ItemSequence {
    class InternalIterator : public Iterator
    {
    private:
      HttpResponseIterator*   theItemSequence;
      std::vector<Item>::size_type theIndex;
      bool is_open;
    public:
      InternalIterator(HttpResponseIterator *item_sequence);

      virtual void open();
      virtual bool next(Item& aItem);
      virtual void close();
      virtual bool isOpen() const;
    };
  private:
    std::vector<Item> theItems;
    bool theResponseSet;
  public:
    HttpResponseIterator(curl_slist* aHeaderList);
    virtual ~HttpResponseIterator();

  public:
    virtual Iterator_t getIterator();

  public: //Implementation specific functions
    void addItem(const Item& aItem);
    void setResponseItem(const Item& aItem);
    void setStream(std::istream* aStream);
    HttpResponseIterator* setResponseParser(HttpResponseParser* aResponseParser)
    {
      theResponseParser = aResponseParser;
      return this;
    }
    
  public:
    static void streamDestroyer(std::istream& aStream);
    
  private:
    static std::map<std::istream*, HttpResponseIterator*> theStreams;
    std::istream* theStream;
    HttpResponseParser* theResponseParser;
    curl_slist* theHeaderList;
  };

  class HttpResponseHandler : public RequestHandler {
  private:
    HttpResponseIterator* theResult;
    Item theResponse;
    Item theMultipart;
    ItemFactory* theFactory;
    bool theIsInsideMultipart;
    bool theDeleteResponse;
    Item theUntypedQName;
  public:
    HttpResponseHandler(ItemFactory* aFactory, curl_slist* theHeaderList);
    virtual ~HttpResponseHandler();
  public:
    HttpResponseIterator* getResult();
    HttpResponseIterator* releaseResult();
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
      String aSrc,
      ItemSequence* aSerializerOptions);
    virtual void any(Item aItem);
    virtual void endBody();
    virtual void beginMultipart(String aContentType, String aBoundary);
    virtual void endMultipart();
    virtual void end();
    virtual bool isHeadRequest() const { return false; }
  };
}} //namespace zorba, namespace http_client

#endif //HTTP_RESPONSE_HANDLER_H
