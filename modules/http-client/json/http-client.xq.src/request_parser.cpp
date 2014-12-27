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
#include "http_response_parser.h"
#include "http_request_handler.h"
#include "error_thrower.h"

#include <cassert>
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/zorba_string.h>
#include <zorba/iterator.h>
#include <zorba/store_consts.h>
#include <zorba/xquery_functions.h>
#include <zorba/util/transcode_stream.h>
#include <zorba/internal/unique_ptr.h>

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
    if (lOption.isJSONItem() ||
         (
           lOption.getTypeCode() != store::XS_STRING &&
           lOption.getTypeCode() != store::XS_NORMALIZED_STRING &&
           lOption.getTypeCode() != store::XS_NAME &&
           lOption.getTypeCode() != store::XS_NCNAME &&
           lOption.getTypeCode() != store::XS_ANY_URI
         )
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
    aResult = parseInteger(lOption, aName);
    return true;
  }
}

int RequestParser::parseInteger(const Item& aItem, const String& aName)
{
  if (aItem.isJSONItem() ||
       (
         aItem.getTypeCode() != store::XS_INTEGER &&
         aItem.getTypeCode() != store::XS_INT &&
         aItem.getTypeCode() != store::XS_NON_NEGATIVE_INTEGER &&
         aItem.getTypeCode() != store::XS_POSITIVE_INTEGER
       )
     )
  {
     raiseTypeError(aName, aItem.getType().getLocalName(), "integer");
  }
  return atoi(aItem.getStringValue().c_str());
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
    if (lOption.isJSONItem() || lOption.getTypeCode() != store::XS_BOOLEAN)
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
      raiseTypeError(aName, aResult.getType().getLocalName(), "object");
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

bool RequestParser::getBody(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult)
{
  if (!getItem(aItem, aName, aMandatory, aResult))
    return false;

  if (aResult.isAtomic())
  {
    store::SchemaTypeCode lTypeCode = aResult.getTypeCode();
    switch (lTypeCode)
    {
      case store::XS_STRING:
      case store::XS_BASE64BINARY:
      case store::XS_HEXBINARY:
        break;
      default:
        raiseTypeError("content", aResult.getType().getLocalName(), "string, base64Binary or hexBinary");
    }
  }
  else if (aResult.isJSONItem())
    raiseTypeError("content", "JSON item", "string, base64Binary or hexBinary");
  else
    raiseTypeError("content", "XML node", "string, base64Binary or hexBinary");

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
      raiseTypeError(aName, aResult.getType().getLocalName(), "array");
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

void RequestParser::parseHeaders(const Item& aItem, Headers& aHeaders)
{
  Item lKey;
  String lName;
  String lValue;

  zorba::Iterator_t lIterator = aItem.getObjectKeys();
  lIterator->open();

  while (lIterator->next(lKey))
  {
    lName = lKey.getStringValue();
    getString(aItem, lName, true, lValue);
    aHeaders.push_back(std::pair<String, String>(lName, lValue));
  }
  lIterator->close();
}

void RequestParser::parseOptions(const Item& aItem, Options& aOptions)
{
  getBoolean(aItem, "status-only", false, aOptions.theStatusOnly);
  getString(aItem, "override-media-type", false, aOptions.theOverrideContentType);
  aOptions.theUserDefinedFollowRedirect = getBoolean(aItem, "follow-redirect", false, aOptions.theFollowRedirect);
  getInteger(aItem, "timeout", false, aOptions.theTimeout);
  getString(aItem, "user-agent", false, aOptions.theUserAgent);

  Item lRetry;
  if (getObject(aItem, "retry", false, lRetry))
    parseRetrySpecification(lRetry, aOptions.theRetrySpec);
}

void RequestParser::parseRetrySpecification(const Item& aItem, RetrySpecification& aRetrySpec)
{
  Item lDelay;
  Item lStatuses;

  aRetrySpec.theRetry = true;

  getArray(aItem, "delay", true, lDelay);
  uint64_t lDelaySize = lDelay.getArraySize();
  if (lDelaySize == 0)
    theThrower->raiseException("REQUEST", "The specified request is not valid. The delay array is empty.");
  for(uint32_t i = 1; i <= lDelaySize; ++i)
  {
    Item lMember = lDelay.getArrayValue(i);
    int lValue = parseInteger(lMember, "entry of delay");
    if (lValue <= 0)
      theThrower->raiseException("REQUEST", "The specified delays are not valid: they must all be greater than 0.");
    aRetrySpec.theRetryDelays.push_back(lValue);
  }

  getBoolean(aItem, "on-connection-error", false, aRetrySpec.theRetryOnConnectionError);
  getArray(aItem, "on-statuses", true, lDelay);
  uint64_t lStatusesSize = lDelay.getArraySize();
  if (!aRetrySpec.theRetryOnConnectionError && lStatusesSize == 0)
    theThrower->raiseException("REQUEST", "The specified request is not valid. Retry on connection error is false, and the on-status array is empty.");
  for(uint32_t i = 1; i <= lStatusesSize; ++i)
  {
    Item lMember = lDelay.getArrayValue(i);
    aRetrySpec.theRetryStatuses.push_back(parseInteger(lMember, "entry of statuses"));
  }
}

void RequestParser::parseBody(const Item& aItem, Body& aBody)
{
  getString(aItem, "media-type", true, aBody.theMediaType);
  getCharset(aBody.theMediaType, aBody.theCharset);
  getString(aItem, "src", false, aBody.theSrc);
  getBody(aItem, "content", true, aBody.theContent);
}

void RequestParser::parsePart(const Item& aItem, Part& aPart)
{
  Item lHeaders;
  Item lBody;

  bool lHaveHeaders = getObject(aItem, "headers", false, lHeaders);
  if (lHaveHeaders)
    parseHeaders(lHeaders, aPart.theHeaders);

  getObject(aItem, "body", true, lBody);
  parseBody(lBody, aPart.theBody);
}

void RequestParser::parseMultipart(const Item& aItem, MultiPart& aMultiPart)
{
  getString(aItem, "media-type", true, aMultiPart.theMediaType);
  getCharset(aMultiPart.theMediaType, aMultiPart.theCharset);
  getString(aItem, "boundary", false, aMultiPart.theBoundary);


  Item lParts = aItem.getObjectValue("parts");
  if (!lParts.isNull())
  {
    if (lParts.isAtomic() || !lParts.isJSONItem() || lParts.getJSONItemKind() != store::StoreConsts::jsonArray)
      raiseTypeError("parts", lParts.getType().getLocalName(), "array");
    else
    {
      uint64_t lSize = lParts.getArraySize();
      for(uint32_t i = 1; i <= lSize; ++i)
      {
        Item lMember = lParts.getArrayValue(i);
        if (lMember.isAtomic() || !lMember.isJSONItem() || lMember.getJSONItemKind() != store::StoreConsts::jsonObject)
          raiseTypeError("part",lMember.getType().getLocalName(), "object");

        Part lPart;
        parsePart(lMember, lPart);
        aMultiPart.theParts.push_back(lPart);
      }
    }
  }
}

void RequestParser::parseAuthentication(const Item& aItem, Authentication& aAuthentication)
{
  getString(aItem, "username", true, aAuthentication.theUserName);
  getString(aItem, "password", true, aAuthentication.thePassword);
  getString(aItem, "auth-method", true, aAuthentication.theAuthMethod);
}

void RequestParser::parseRequest(const Item& aItem, Request& aRequest)
{
  if (!getString(aItem, "method", false, aRequest.theMethod))
    aRequest.theMethod = "GET";
  else
    aRequest.theMethod = fn::upper_case(aRequest.theMethod);

  getString(aItem, "href", true, aRequest.theHref);

  Item lAuthentication;
  if ((aRequest.theAuthentication.theSendAuthentication = getObject(aItem, "authentication", false, lAuthentication)))
    parseAuthentication(lAuthentication, aRequest.theAuthentication);

  Item lOptions;
  if (getObject(aItem, "options", false, lOptions))
    parseOptions(lOptions, aRequest.theOptions);

  // follow-redirect: take care of the default (if the user didn't provide one)
  if (aRequest.theMethod == "GET" || aRequest.theMethod == "HEAD" || aRequest.theMethod == "OPTIONS")
  {
    if (!aRequest.theOptions.theUserDefinedFollowRedirect)
      aRequest.theOptions.theFollowRedirect = true;
  }
  else
  {
    if (aRequest.theOptions.theFollowRedirect)
    {
      std::ostringstream lMsg;
      lMsg << "cannot follow redirect, request method: " << aRequest.theMethod;
      theThrower->raiseException("FOLLOW", lMsg.str());
    }
  }

  Item lHeaders;
  bool lHaveHeaders = getObject(aItem, "headers", false, lHeaders);
  if (lHaveHeaders)
    parseHeaders(lHeaders, aRequest.theHeaders);

  Item lBody;
  Item lMultipart;
  aRequest.theHaveBody = getObject(aItem, "body", false, lBody);
  aRequest.theHaveMultiPart = getObject(aItem, "multipart", false, lMultipart);
  if (aRequest.theHaveBody && aRequest.theHaveMultiPart)
    theThrower->raiseException("REQUEST","The specified request is not valid. HTTP request cannot contain both body and multipart");

  if (aRequest.theHaveBody)
    parseBody(lBody, aRequest.theBody);

  if (aRequest.theHaveMultiPart)
    parseMultipart(lMultipart, aRequest.theMultiPart);
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
/* vim:set et sw=2 ts=2: */
