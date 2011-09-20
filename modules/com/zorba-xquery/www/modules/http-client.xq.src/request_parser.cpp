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
#include "request_parser.h"
#include "request_handler.h"

#include <cassert>
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/zorba_string.h>
#include <zorba/iterator.h>
#include <zorba/store_consts.h>
#include <zorba/vector_item_sequence.h>

namespace zorba { namespace http_client {
  /*class AttributesSequence : public ItemSequence {
    std::vector<Item>& theItems;
    unsigned thePosition;
    unsigned theSize;
  public:
    AttributesSequence(std::vector<Item>& aItems)
      : theItems(aItems), thePosition(0), theSize((unsigned)aItems.size()) {}
    virtual bool next(Item& aItem)
    {
      if (thePosition < theSize) {
        aItem = theItems[thePosition++];
        return true;
      }
      return false;
    }
    virtual bool
    nextSerializableItem(Item& item) { return next(item); }
  };
  */
  bool RequestParser::parse(const Item& aItem)
  {
    theHandler->begin();
    bool lResult = parseItem(aItem);
    theHandler->end();
    return lResult;
  }

  bool RequestParser::parseItem(const Item& aItem)
  {
    if (aItem.getNodeKind() == store::StoreConsts::commentNode)
      return true;
    Item lQName;
    aItem.getNodeName(lQName);
    String lLocalName = lQName.getLocalName();
    if (lLocalName == "request") {
      if (!handleRequest(aItem)) return false;
    } else if (lLocalName == "response") {
      if (!handleResponse(aItem)) return false;
    } else if (lLocalName == "header") {
      if (!handleHeader(aItem)) return false;
    } else if (lLocalName == "multipart") {
      if (!handleMultipart(aItem)) return false;
    } else if (lLocalName == "body") {
      if (!handleBody(aItem)) return false;
    }
    return true;
  }

  bool RequestParser::handleRequest( const Item& aItem )
  {
    String lMethod;
    String lHref;
    bool lStatusOnly = false;
    String lUsername;
    String lPassword;
    String lAuthMethod;
    bool lSendAuthorization = false;
    String lOverrideContentType;
    bool lFollowRedirect = true;
    int lTimeout = -1;

    Iterator_t lIter = aItem.getAttributes();
    lIter->open();
    Item lItem;
    while (lIter->next(lItem)) {
      Item lQName;
      lItem.getNodeName(lQName);
      String lLocalName = lQName.getLocalName();
      std::string lLocalNameString = lLocalName.c_str();
      if (lLocalName == "method") {
        lMethod = lItem.getStringValue();
      } else if (lLocalName == "href") {
        lHref = lItem.getStringValue();
      } else if (lLocalName == "status-only") {
        lStatusOnly = lItem.getStringValue() == "true";
      } else if (lLocalName == "username") {
        lUsername = lItem.getStringValue();
      } else if (lLocalName == "password") {
        lPassword = lItem.getStringValue();
      } else if (lLocalName == "auth-method") {
        lAuthMethod = lItem.getStringValue();
      } else if (lLocalName == "send-authorization") {
        String lString = lItem.getStringValue();
        lSendAuthorization = lString == "true";
      } else if (lLocalName == "override-media-type") {
        lOverrideContentType = lItem.getStringValue();
      } else if (lLocalName == "follow-redirect") {
        String lString = lItem.getStringValue();
        lFollowRedirect = lString == "true";
      } else if (lLocalName == "timeout") {
        lTimeout = lItem.getIntValue();
      }
    }
    theHandler->beginRequest(lMethod, lHref, lStatusOnly, lUsername,
      lPassword, lAuthMethod, lSendAuthorization, lOverrideContentType,
      lFollowRedirect, lTimeout);
    lIter = aItem.getChildren();
    lIter->open();
    while (lIter->next(lItem)) {
      if (!parseItem(lItem)) {
        return false;
      }
    }
    theHandler->endRequest();
    return true;
  }

  bool RequestParser::handleResponse( const Item aItem )
  {
    int lStatus = 0;
    String lMessage;

    Iterator_t lIter = aItem.getAttributes();
    lIter->open();
    Item lItem;
    while (lIter->next(lItem)) {
      Item lQName;
      lItem.getNodeName(lQName);
      String lLocalName = lQName.getLocalName();
      if (lLocalName == "status") {
        lStatus = lItem.getIntValue();
      } else if (lLocalName == "message") {
        lMessage = lItem.getStringValue();
      }
    }

    theHandler->beginResponse(lStatus, lMessage);
    lIter = aItem.getChildren();
    lIter->open();
    while (lIter->next(lItem)) {
      if (!parseItem(lItem)) return false;
    }
    theHandler->endResponse();
    return true;
  }

  bool RequestParser::handleHeader( const Item& aItem )
  {
    String lName;
    String lValue;
    Iterator_t lIter = aItem.getAttributes();
    lIter->open();
    Item lItem;
    while (lIter->next(lItem)) {
      Item lQName;
      lItem.getNodeName(lQName);
      String lLocalName = lQName.getLocalName();
      if (lLocalName == "name") {
        lName = lItem.getStringValue();
      } else if (lLocalName == "value") {
        lValue = lItem.getStringValue();
      }
    }
    theHandler->header(lName, lValue);
    return true;
  }

  bool RequestParser::handleBody( const Item& aItem )
  {
    String lContentType;
    String lEncoding;
    String lId;
    String lDescription;
    String lSrc;

    Iterator_t lIter = aItem.getAttributes();
    lIter->open();
    Item lItem;
    std::vector<Item> lItems;
    while (lIter->next(lItem)) {
      Item lQName;
      lItem.getNodeName(lQName);
      String lLocalName = lQName.getLocalName();
      if (lLocalName == "media-type") {
        lContentType = lItem.getStringValue();
      } else if (lLocalName == "src") {
        lSrc = lItem.getStringValue();
      } else {
        lItems.push_back(lItem);
      }
    }
    std::auto_ptr<VectorItemSequence> lSequence(new VectorItemSequence(lItems));
    theHandler->beginBody(lContentType, lSrc, lSequence.get());
    lIter = aItem.getChildren();
    lIter->open();
    while (lIter->next(lItem)) {
      theHandler->any(lItem);
    }
    theHandler->endBody();
    return true;
  }

  bool RequestParser::handleMultipart( const Item& aItem )
  {
    String lContentType;
    String lBoundary;

    Iterator_t lIter = aItem.getAttributes();
    lIter->open();
    Item lItem;
    while (lIter->next(lItem)) {
      Item lQName;
      lItem.getNodeName(lQName);
      String lLocalName = lQName.getLocalName();
      if (lLocalName == "media-type") {
        lContentType = lItem.getStringValue();
      } else if (lLocalName == "boundary") {
        lBoundary = lItem.getStringValue();
      }
    }
    theHandler->beginMultipart(lContentType, lBoundary);
    lIter = aItem.getChildren();
    lIter->open();
    while (lIter->next(lItem)) {
      if (!parseItem(lItem)) return false;
    }
    theHandler->endMultipart();
    return true;
  }
}}
