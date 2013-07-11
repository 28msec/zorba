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
#include "request_parser.h"
#include "request_handler.h"
#include "http_response_parser.h"
#include "error_thrower.h"

#include <cassert>
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/zorba_string.h>
#include <zorba/iterator.h>
#include <zorba/store_consts.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/xquery_functions.h>
#include <zorba/util/transcode_stream.h>

namespace zorba
{
namespace http_client
{

bool RequestParser::getString(const Item& aItem, const String& aName, const bool aMandatory, String& aResult)
{
  Item lOption = aItem.getObjectValue(aName);
  if (lOption.isNull())
  {
    if (aMandatory)
      raiseMissingError(aName);
    return false;
  }
  else
  {
    if (lOption.getTypeCode() != store::XS_STRING &&
        lOption.getTypeCode() != store::XS_NORMALIZED_STRING &&
        lOption.getTypeCode() != store::XS_NAME &&
        lOption.getTypeCode() != store::XS_NCNAME &&
        lOption.getTypeCode() != store::XS_ANY_URI
        )
      raiseTypeError(aName,lOption.getType().getLocalName(), "string");
    aResult = lOption.getStringValue();
    return true;
  }
}

bool RequestParser::getInteger(const Item& aItem, const String& aName, const bool aMandatory, int& aResult)
{
  Item lOption = aItem.getObjectValue(aName);
  if (lOption.isNull())
  {
    if (aMandatory)
      raiseMissingError(aName);
    return false;
  }
  else
  {
    if (lOption.getTypeCode() != store::XS_INTEGER &&
        lOption.getTypeCode() != store::XS_INT &&
        lOption.getTypeCode() != store::XS_NON_NEGATIVE_INTEGER &&
        lOption.getTypeCode() != store::XS_POSITIVE_INTEGER
        )
      raiseTypeError(aName,lOption.getType().getLocalName(), "integer");
    aResult = atoi(lOption.getStringValue().c_str());
    return true;
  }
}

bool RequestParser::getBoolean(const Item& aItem, const String& aName, const bool aMandatory, bool& aResult)
{
  Item lOption = aItem.getObjectValue(aName);
  if (lOption.isNull())
  {
    if (aMandatory)
      raiseMissingError(aName);
    return false;
  }
  else
  {
    if (lOption.getTypeCode() != store::XS_BOOLEAN)
      raiseTypeError(aName, lOption.getType().getLocalName(), "boolean");
    aResult = lOption.getBooleanValue();
    return true;
  }
}

bool RequestParser::getObject(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult)
{
  aResult = aItem.getObjectValue(aName);
  if (aResult.isNull())
  {
    if (aMandatory)
      raiseMissingError(aName);
    return false;
  }
  else
  {
    if (aResult.isAtomic() || !aResult.isJSONItem() || aResult.getJSONItemKind() != store::StoreConsts::jsonObject)
      raiseTypeError(aName, aResult.getType().getLocalName(), store::StoreConsts::toString(store::StoreConsts::jsonObject));
    return true;
  }
}

bool RequestParser::getItem(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult)
{
  aResult = aItem.getObjectValue(aName);
  if (aResult.isNull())
  {
    if (aMandatory)
      raiseMissingError(aName);
    return false;
  }
  return true;
}

bool RequestParser::getArray(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult)
{
  aResult = aItem.getObjectValue(aName);
  if (aResult.isNull())
  {
    if (aMandatory)
      raiseMissingError(aName);
    return false;
  }
  else
  {
    if (aResult.isAtomic() || !aResult.isJSONItem() || aResult.getJSONItemKind() != store::StoreConsts::jsonArray)
      raiseTypeError(aName, store::StoreConsts::toString(aResult.getJSONItemKind()), store::StoreConsts::toString(store::StoreConsts::jsonArray));
    return true;
  }
}

void RequestParser::raiseTypeError(const String& aName, const String& aGot, const String& aExpected)
{
  std::ostringstream lMsg;
  lMsg << "The specified request is not valid. " << aGot << ": invalid type for field "
    << aName << " (got " << aGot << ", expected " << aExpected << ")";
  theThrower->raiseException("REQUEST", lMsg.str());
}

void RequestParser::raiseMissingError(const String& aName)
{
  std::ostringstream lMsg;
  lMsg << "The specified request is not valid. " << "The required field " << aName << " has not been specified";
  theThrower->raiseException("REQUEST", lMsg.str());
}

void RequestParser::parseHeaders(const Item& aItem)
{
  Item lKey;
  String lName;
  String lValue;

  zorba::Iterator_t lIterator = aItem.getObjectKeys();
  lIterator->open();

  while (lIterator->next(lKey))
  {
    lName = lKey.getStringValue();
    getString(aItem,lName,true,lValue);
    theHandler->header(lName, lValue);
  }

  lIterator->close();
}

void RequestParser::parseOptions(const Item& aItem, bool& aStatusOnly, String& aOverrideContentType,bool& aFollowRedirect, bool& aUserDefinedFollowRedirect, String& aUserAgent, int& aTimeout)
{
  getBoolean(aItem,"status-only",false,aStatusOnly);
  getString(aItem,"override-media-type", false,aOverrideContentType);
  aUserDefinedFollowRedirect = getBoolean(aItem,"follow-redirect", false,aFollowRedirect);
  getInteger(aItem,"timeout",false,aTimeout);
  getString(aItem,"user-agent",false,aUserAgent);
}

void RequestParser::parseBody(const Item& aItem)
{
  String lMediaType;
  String lSrc;

  getString(aItem,"media-type",true,lMediaType);
  std::string charset;
  getCharset(lMediaType, charset);
  getString(aItem,"src",false,lSrc);

  std::vector<Item> lItems;
  std::auto_ptr<VectorItemSequence> lSequence(new VectorItemSequence(lItems));
  theHandler->beginBody(lMediaType, lSrc, lSequence.get());

  Item lContentI;
  getItem(aItem,"content",true,lContentI);
  theHandler->any(lContentI,charset);
  theHandler->endBody();
}

void RequestParser::parsePart(const Item& aItem)
{
  Item lHeaders;
  Item lBody;

  bool lHaveHeaders = getObject(aItem,"headers",false,lHeaders);
  if (lHaveHeaders)
    parseHeaders(lHeaders);

  getObject(aItem,"body",true,lBody);
  parseBody(lBody);
}

void RequestParser::parseMultipart(const Item& aItem)
{
  String lMediaType;
  String lBoundary;

  std::string charset;
  getString(aItem,"media-type",true,lMediaType);
  getCharset(lMediaType,charset);
  getString(aItem,"boundary",false,lBoundary);

  theHandler->beginMultipart(lMediaType, lBoundary);
  Item lParts = aItem.getObjectValue("parts");
  if (!lParts.isNull())
  {
    if (lParts.isAtomic() || !lParts.isJSONItem() || lParts.getJSONItemKind() != store::StoreConsts::jsonArray)
      raiseTypeError("parts", store::StoreConsts::toString(lParts.getJSONItemKind()), store::StoreConsts::toString(store::StoreConsts::jsonArray));
    else
    {
      uint64_t lSize = lParts.getArraySize();
      for(uint64_t i = 1; i <= lSize; ++i)
      {
        Item lMember = lParts.getArrayValue(i);
        if (lMember.isAtomic() || !lMember.isJSONItem() || lMember.getJSONItemKind() != store::StoreConsts::jsonObject)
          raiseTypeError("part",store::StoreConsts::toString(lMember.getJSONItemKind()),store::StoreConsts::toString(store::StoreConsts::jsonObject));
        parsePart(lMember);
      }
    }
  }
  theHandler->endMultipart();
}

void RequestParser::parseAuthentication(const Item& aItem, String& aUserName, String& aPassword, String& aAuthMethod)
{
  getString(aItem,"username",true,aUserName);
  getString(aItem,"password",true,aPassword);
  getString(aItem,"auth-method",true,aAuthMethod);
}

void RequestParser::parseRequest(const Item& aItem)
{
  theHandler->begin();
  String lMethod;
  String lHref;
  bool lStatusOnly = false;
  String lUsername;
  String lPassword;
  String lAuthMethod;
  bool lSendAuthentication = false;
  String lOverrideContentType;
  bool lFollowRedirect = false;
  bool lUserDefinedFollowRedirect = false;
  int lTimeout = -1;
  String lUserAgent;

  if(!getString(aItem,"method",false,lMethod))
    lMethod ="GET";
  getString(aItem,"href",true,lHref);

  Item lAuthentication;
  if ((lSendAuthentication = getObject(aItem,"authentication",false,lAuthentication)))
    parseAuthentication(lAuthentication,lUsername,lPassword,lAuthMethod);

  Item lOptions;
  if (getObject(aItem,"options",false,lOptions))
    parseOptions(lOptions,lStatusOnly,lOverrideContentType,lFollowRedirect,lUserDefinedFollowRedirect,lUserAgent,lTimeout);

  lMethod = fn::upper_case(lMethod);

  // follow-redirect: take care of the default (if the user didn't provide one)
  if (lMethod == "GET" || lMethod == "HEAD" || lMethod == "OPTIONS")
  {
    if (!lUserDefinedFollowRedirect)
      lFollowRedirect = "true";
  }
  else
  {
    if (lFollowRedirect)
    {
      std::ostringstream lMsg;
      lMsg << "cannot follow redirect, request method: " << lMethod;
      theThrower->raiseException("FOLLOW", lMsg.str());
    }
  }

  theHandler->beginRequest(lMethod, lHref, lStatusOnly, lUsername, lPassword,
      lAuthMethod, lSendAuthentication, lOverrideContentType, lFollowRedirect,
      lUserAgent, lTimeout);

  Item lHeaders;
  bool haveHeaders = getObject(aItem,"headers",false,lHeaders);
  if (haveHeaders)
    parseHeaders(lHeaders);

  Item lBody;
  Item lMultipart;
  bool haveBody = getObject(aItem,"body",false,lBody);
  bool haveMultipart = getObject(aItem,"multipart",false,lMultipart);
  if (haveBody && haveMultipart)
    theThrower->raiseException("REQUEST","The specified request is not valid. HTTP request cannot contain both body and multipart");

  if (haveBody)
    parseBody(lBody);

  if (haveMultipart)
    parseMultipart(lMultipart);

  theHandler->endRequest();
  theHandler->end();
}

void RequestParser::getCharset(const String& aMediaType, std::string& charset)
{
  std::string mime_type;
  parse_content_type(aMediaType.c_str(),&mime_type,&charset);
  if (!charset.empty() && transcode::is_necessary(charset.c_str()) && !transcode::is_supported(charset.c_str()))
  {
    std::ostringstream lMsg;
    lMsg << charset << ": unsupported encoding charset";
    theThrower->raiseException("CHARSET", lMsg.str());
  }
}

}
}
