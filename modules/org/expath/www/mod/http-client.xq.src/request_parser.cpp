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
    String lLocalName = aItem.getLocalName();
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
    theHandler->end();
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
    bool lFollowRedirect = false;
    int lTimeout = -1;

    Iterator_t lIter = aItem.getAttributes();
    Item lItem;
    while (lIter->next(lItem)) {
      if (lItem.getLocalName() == "method") {
        lMethod = lItem.getStringValue();
      } else if (lItem.getLocalName() == "href") {
        lHref = lItem.getStringValue();
      } else if (lItem.getLocalName() == "status-only") {
        lStatusOnly = lItem.getBooleanValue();
      } else if (lItem.getLocalName() == "username") {
        lUsername = lItem.getStringValue();
      } else if (lItem.getLocalName() == "password") {
        lPassword = lItem.getLocalName();
      } else if (lItem.getLocalName() == "auth-method") {
        lAuthMethod = lItem.getStringValue();
      } else if (lItem.getLocalName() == "send-authorization") {
        lSendAuthorization = lItem.getBooleanValue();
      } else if (lItem.getLocalName() == "override-content-type") {
        lOverrideContentType = lItem.getStringValue();
      } else if (lItem.getLocalName() == "follow-redirect") {
        lFollowRedirect = lItem.getBooleanValue();
      } else if (lItem.getLocalName() == "timeout") {
        lTimeout = lItem.getIntValue();
      }
    }
    theHandler->beginRequest(lMethod, lHref, lStatusOnly, lUsername,
      lPassword, lAuthMethod, lSendAuthorization, lOverrideContentType,
      lFollowRedirect, lTimeout);
    lIter = aItem.getChildren();
    while (lIter->next(lItem)) {
      if (!parse(lItem)) {
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
    Item lItem;
    while (lIter->next(lItem)) {
      if (lItem.getLocalName() == "status") {
        lStatus = lItem.getIntValue();
      } else if (lItem.getLocalName() == "message") {
        lMessage = lItem.getStringValue();
      }
    }

    theHandler->beginResponse(lStatus, lMessage);
    lIter = aItem.getChildren();
    while (lIter->next(lItem)) {
      if (!parse(lItem)) return false;
    }
    theHandler->endResponse();
    return true;
  }

  bool RequestParser::handleHeader( const Item& aItem )
  {
    String lName;
    String lValue;
    Iterator_t lIter = aItem.getAttributes();
    Item lItem;
    while (lIter->next(lItem)) {
      if (lItem.getLocalName() == "name") {
        lName = lItem.getStringValue();
      } else if (lItem.getLocalName() == "value") {
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
    Item lItem;
    while (lIter->next(lItem)) {
      if (lItem.getLocalName() == "content-type") {
        lContentType = lItem.getStringValue();
      } else if (lItem.getLocalName() == "encoding") {
        lEncoding = lItem.getStringValue();
      } else if (lItem.getLocalName() == "id") {
        lId = lItem.getStringValue();
      } else if (lItem.getLocalName() == "src") {
        lSrc = lItem.getStringValue();
      }
    }
    theHandler->beginBody(lContentType, lEncoding, lId, lDescription, lSrc);
    lIter = aItem.getChildren();
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
    Item lItem;
    while (lIter->next(lItem)) {
      if (lItem.getLocalName() == "content-type") {
        lContentType = lItem.getStringValue();
      } else if (lItem.getLocalName() == "boundary") {
        lBoundary = lItem.getStringValue();
      }
    }
    theHandler->beginMultipart(lContentType, lBoundary);
    lIter = aItem.getChildren();
    while (lIter->next(lItem)) {
      if (!parse(lItem)) return false;
    }
    theHandler->endMultipart();
    return true;
  }
}}
