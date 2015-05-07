/*
 * Copyright 2006-2013 The FLWOR Foundation.
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
#include <string>
#include <map>
#include <curl/curl.h>

#include <zorba/item_sequence.h>
#include <zorba/iterator.h>

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

      void open();
      bool next(Item& aItem);
      void close();
      bool isOpen() const;
    };
  private:
    std::vector<Item> theItems;
    bool theResponseSet;
  public:
    HttpResponseIterator(curl_slist* aHeaderList);
    virtual ~HttpResponseIterator();

  public:
    Iterator_t getIterator();

  public: //Implementation specific functions
    void addItem(const Item& aItem);
    void setResponseItem(const Item& aItem);
    
  public:
    static void streamReleaser(std::istream* aStream);
    
  private:
    curl_slist* theHeaderList;
  };

  class HttpResponseHandler
  {
  private:
    HttpResponseIterator* theResult;
    std::vector<std::pair<Item, Item> > theResponsePairs;

    std::map<String, String> theResponseHeaderMap;
    std::map<String, String> theMultipartHeaderMap;

    std::vector<std::pair<Item, Item> > theMultipartPairs;

    std::vector<std::pair<Item, Item> > theBodyPairs;
    std::vector<std::pair<Item, Item> > theMultipartBodyPairs;

    std::vector<Item> theMultipartBodyVector;

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
    void begin();
    void beginResponse(int aStatus, String aMessage);
    void endResponse();
    void header(String aName, String aValue);
    void beginBody(
      String aContentType,
      String aSrc,
      ItemSequence* aSerializerOptions);
    void any(Item aItem, std::string& charset);
    void endBody();
    void beginMultipart(String aContentType, String aBoundary);
    void endMultipart();
    void end();
    bool isHeadRequest() const { return false; }
  };
}} //namespace zorba, namespace http_client

#endif //HTTP_RESPONSE_HANDLER_H
/* vim:set et sw=2 ts=2: */
