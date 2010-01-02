#include "request_parser.h"
#include "request_handler.h"

#include <zorba/zorba.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/zorbastring.h>
#include <zorba/iterator.h>

namespace zorba { namespace http_client {
  bool RequestParser::parse(const Item& aItem)
  {
    theHandler->begin();
    bool lResult = parseItem(aItem);
    theHandler->end();
    return lResult;
  }

  bool RequestParser::parseItem(const Item& aItem)
  {
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
    bool lFollowRedirect = false;
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
        lStatusOnly = lItem.getBooleanValue();
      } else if (lLocalName == "username") {
        lUsername = lItem.getStringValue();
      } else if (lLocalName == "password") {
        lPassword = lItem.getStringValue();
      } else if (lLocalName == "auth-method") {
        lAuthMethod = lItem.getStringValue();
      } else if (lLocalName == "send-authorization") {
        lSendAuthorization = lItem.getBooleanValue();
      } else if (lLocalName == "override-content-type") {
        lOverrideContentType = lItem.getStringValue();
      } else if (lLocalName == "follow-redirect") {
        lFollowRedirect = lItem.getBooleanValue();
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
    while (lIter->next(lItem)) {
      Item lQName;
      lItem.getNodeName(lQName);
      String lLocalName = lQName.getLocalName();
      if (lLocalName == "content-type") {
        lContentType = lItem.getStringValue();
      } else if (lLocalName == "encoding") {
        lEncoding = lItem.getStringValue();
      } else if (lLocalName == "id") {
        lId = lItem.getStringValue();
      } else if (lLocalName == "src") {
        lSrc = lItem.getStringValue();
      }
    }
    theHandler->beginBody(lContentType, lEncoding, lId, lDescription, lSrc);
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
      if (lLocalName == "content-type") {
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
