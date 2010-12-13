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
#include <zorba/exception.h>
#include <zorba/item.h>
#include <zorba/item_factory.h>

#include "http_response_handler.h"

namespace zorba { namespace http_client {

  //////////////////////////////////////////////////////////////////////////
  // HttpResponseIterator
  //////////////////////////////////////////////////////////////////////////

  const char* theNamespace = "http://expath.org/ns/http-client";

  HttpResponseIterator::HttpResponseIterator()
    : theIndex(0), theResponseSet(false)
  {
    // Set an empty item as the response item
    theItems.push_back(Item());
  }

  HttpResponseIterator::~HttpResponseIterator()
  {
  }

  bool HttpResponseIterator::next( Item& aItem )
  {
    if (!theResponseSet) {
      return false;
    }
    if (theIndex < theItems.size()) {
      aItem = theItems[theIndex];
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
  //////////////////////////////////////////////////////////////////////////
  // HttpResponseHandler
  //////////////////////////////////////////////////////////////////////////

  HttpResponseHandler::HttpResponseHandler(ItemFactory* aFactory)
    :
  theResult(new HttpResponseIterator()),
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
      theUntypedQName, false, false, std::vector<std::pair<String, String> >());
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
      theFactory->createQName(theNamespace, "header"), theUntypedQName, false,
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
      theFactory->createQName(theNamespace, "body"), theUntypedQName, false,
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
      theFactory->createQName(theNamespace, "body"), theUntypedQName, false,
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

  ItemSequence* HttpResponseHandler::getResult()
  {
    theDeleteResponse = false;
    return theResult;
  }
}} //namespace zorba, namespace http_client
