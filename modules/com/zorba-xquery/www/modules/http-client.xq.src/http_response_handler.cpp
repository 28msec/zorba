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

#include <zorba/xquery_exception.h>
#include <zorba/item.h>
#include <zorba/item_factory.h>
#include <zorba/zorba_string.h>

#include "http_response_handler.h"
#include "http_response_parser.h"

namespace zorba { namespace http_client {

  //////////////////////////////////////////////////////////////////////////
  // HttpResponseIterator
  //////////////////////////////////////////////////////////////////////////

  const char* theNamespace = "http://expath.org/ns/http-client";

  HttpResponseIterator::HttpResponseIterator(curl_slist* aHeaderList)
    : theResponseSet(false), theStream(0), theResponseParser(0), theHeaderList(aHeaderList)
  {
    // Set an empty item as the response item
    theItems.push_back(Item());
  }

  HttpResponseIterator::~HttpResponseIterator()
  {
    if (theStream)
      delete theStream;
    if (theResponseParser)
      delete theResponseParser;
    if (theHeaderList)
      curl_slist_free_all(theHeaderList);
  }

  Iterator_t HttpResponseIterator::getIterator()
  {
    return new InternalIterator(this);
  }

  HttpResponseIterator::InternalIterator::InternalIterator(HttpResponseIterator *item_sequence) : 
    theItemSequence(item_sequence),
    theIndex(0)
  {
    is_open = false;
  }

  void HttpResponseIterator::InternalIterator::open()
  {
     theIndex = 0;
    is_open = true;
  }

  void HttpResponseIterator::InternalIterator::close()
  {
    is_open = false;
  }

  bool HttpResponseIterator::InternalIterator::isOpen() const
  {
    return is_open;
  }

  bool HttpResponseIterator::InternalIterator::next( Item& aItem )
  {
    if (!theItemSequence->theResponseSet) {
      return false;
    }
    if (theIndex < theItemSequence->theItems.size()) {
      aItem = theItemSequence->theItems[theIndex];
      ++theIndex;
      return !aItem.isNull();
    }
    return false;
  }

  void HttpResponseIterator::addItem(const Item& aItem)
  {
    theItems.push_back(aItem);
  }

  void HttpResponseIterator::setResponseItem(const Item& aItem)
  {
    theItems[0] = aItem;
    theResponseSet = true;
  }
  
  void HttpResponseIterator::setStream(std::istream *aStream)
  {
    theStreams.insert(std::make_pair(aStream, this));
    theStream = aStream;
  }
  
  std::map<std::istream*, HttpResponseIterator*> HttpResponseIterator::theStreams;
  
  void HttpResponseIterator::streamDestroyer(std::istream& aStream)
  {
    std::map<std::istream*, HttpResponseIterator*>::iterator lIter;
    lIter = theStreams.find(&aStream);
    if (lIter != theStreams.end())
      theStreams.erase(lIter);
  }
  
  //////////////////////////////////////////////////////////////////////////
  // HttpResponseHandler
  //////////////////////////////////////////////////////////////////////////

  HttpResponseHandler::HttpResponseHandler(ItemFactory* aFactory, curl_slist* aHeaderList)
    :
  theResult(new HttpResponseIterator(aHeaderList)),
  theFactory(aFactory),
  theIsInsideMultipart(false),
  theDeleteResponse(true)
  {
    theUntypedQName = theFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  }

  HttpResponseHandler::~HttpResponseHandler() {
    if (theDeleteResponse) {
      delete theResult;
    }
  }

  void HttpResponseHandler::begin()
  {
  }

  void HttpResponseHandler::beginResponse(int aStatus, String aMessage)
  {
    Item lNullParent;
    Item lNullType;
    String lLocalName = "response";
    Item lNodeName = theFactory->createQName(theNamespace, lLocalName);
    theResponse = theFactory->createElementNode(lNullParent, lNodeName,
      theUntypedQName, true, false, std::vector<std::pair<String, String> >());
    theFactory->createAttributeNode(theResponse,
      theFactory->createQName("", "status"), lNullType,
      theFactory->createInteger(aStatus));
    theFactory->createAttributeNode(theResponse,
      theFactory->createQName("", "message"), lNullType,
      theFactory->createString(aMessage));
    theResult->setResponseItem(theResponse);
  }

  void HttpResponseHandler::endResponse()
  {
  }

  // Since this class is only used to handle responses, beginRequest and
  // endRequest are not implemented.
  void HttpResponseHandler::beginRequest(String aMethod,
                                         String href,
                                         bool aStatusOnly,
                                         String aUsername,
                                         String aPassword,
                                         String aAuthMethod,
                                         bool aSendAuthorization,
                                         String aOverrideContentType,
                                         bool aFollowRedirect,
                                         int aTimeout /*= -1*/)
  {
  }

  void HttpResponseHandler::endRequest()
  {
  }

  void HttpResponseHandler::header(String aName, String aValue)
  {
    Item lParent = theIsInsideMultipart ? theMultipart : theResponse;
    Item lNullType;
    Item lElem = theFactory->createElementNode(lParent,
      theFactory->createQName(theNamespace, "header"), theUntypedQName, true,
      true, std::vector<std::pair<String, String> >());
    theFactory->createAttributeNode(lElem, theFactory->createQName("", "name"),
      lNullType, theFactory->createString(aName));
    theFactory->createAttributeNode(lElem, theFactory->createQName("", "value"),
      lNullType, theFactory->createString(aValue));
  }

  void HttpResponseHandler::beginBody(String aContentType,
                                      String aSrc,
                                      ItemSequence* aSerializerOptions)
  {
    Item lParent = theIsInsideMultipart ? theMultipart : theResponse;
    Item lNullType;
    Item lElem = theFactory->createElementNode(lParent,
      theFactory->createQName(theNamespace, "body"), theUntypedQName, true,
      true, std::vector<std::pair<String, String> >());
    theFactory->createAttributeNode(lElem,
      theFactory->createQName("", "media-type"),
      lNullType, theFactory->createString(aContentType));
  }

  void HttpResponseHandler::any(Item aItem)
  {
    theResult->addItem(aItem);
  }

  void HttpResponseHandler::endBody()
  {
  }

  void HttpResponseHandler::beginMultipart(String aContentType, String aBoundary)
  {
    theIsInsideMultipart = true;
    Item lNullType;
    Item lElem = theFactory->createElementNode(theResponse,
      theFactory->createQName(theNamespace, "body"), theUntypedQName, true,
      true, std::vector<std::pair<String, String> >());
    theFactory->createAttributeNode(lElem,
      theFactory->createQName("", "content-type"),
      lNullType, theFactory->createString(aContentType));
    theFactory->createAttributeNode(lElem,
      theFactory->createQName("", "boundary"),
      lNullType, theFactory->createString(aBoundary));
  }

  void HttpResponseHandler::endMultipart()
  {
    theIsInsideMultipart = false;
  }

  void HttpResponseHandler::end()
  {
  }

  HttpResponseIterator* HttpResponseHandler::getResult()
  {
    return theResult;
  }

  HttpResponseIterator* HttpResponseHandler::releaseResult()
  {
    theDeleteResponse = false;
    return theResult;
  }
}} //namespace zorba, namespace http_client
