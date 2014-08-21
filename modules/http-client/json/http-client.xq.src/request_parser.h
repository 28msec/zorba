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
#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

#include <string>
#include <vector>
#include "zorba/zorba_string.h"

#include "structures.h"

namespace zorba {
class Item;
class String;
class ItemFactory;

namespace http_client {
class HttpRequestHandler;
class ErrorThrower;
struct Options;

class RequestParser {
protected:
  ErrorThrower* theThrower;
  ItemFactory* theFactory;

public:
  RequestParser(ErrorThrower& aThrower, ItemFactory* aFactory) : theThrower(&aThrower), theFactory(aFactory) {}
  void parseRequest(const Item& aItem, Request& aRequest);

private:
  void parseHeaders(const Item& aItem, Headers& aHeaders);
  void parseOptions(const Item& aItem, Options& aOptions);
  void parseRetrySpecification(const Item& aItem, RetrySpecification& aRetrySpec);
  void parseBody(const Item& aItem, Body& aBody);
  void parsePart(const Item& aItem, Part& aPart);
  void parseMultipart(const Item& aItem, MultiPart& aMultiPart);
  void parseAuthentication(const Item& aItem, Authentication& aRequest);

  bool getString(const Item& aItem, const String& aName, const bool aMandatory, String& aResult);
  bool getInteger(const Item& aItem, const String& aName, const bool aMandatory, int& aResult);
  bool getBoolean(const Item& aItem, const String& aName, const bool aMandatory, bool& aResult);
  bool getObject(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult);
  bool getItem(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult);
  bool getArray(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult);
  bool getBody(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult);

  int parseInteger(const Item& aItem, const String& aName);

  void getCharset(const String& aMediaType, std::string& charset);

  void raiseTypeError(const String& aName, const String& aGot, const String& aExpected);
  void raiseMissingError(const String& aName);
};
} //namespace zorba
} //namespace http_request

#endif // REQUEST_PARSER_H
/* vim:set et sw=2 ts=2: */
