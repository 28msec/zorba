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

namespace zorba {
class Item;
class String;
class ItemFactory;

namespace http_client {
class HttpRequestHandler;
class ErrorThrower;

class RequestParser {
protected:
  HttpRequestHandler* theHandler;
  ErrorThrower*   theThrower;
  ItemFactory* theFactory;

public:
  RequestParser(HttpRequestHandler* aHandler, ErrorThrower& aThrower, ItemFactory* aFactory) : theHandler(aHandler), theThrower(&aThrower), theFactory(aFactory) {}
  void parseRequest(const Item& aItem);

private:
  void parseHeaders(const Item& aItem);
  void parseOptions(const Item& aItem, bool& aStatusOnly, String& aOverrideContentType,bool& aFollowRedirect, bool& aUserDefinedFollowRedirect, String& aUserAgent, int& aTimeout);
  void parseBody(const Item& aItem);
  void parsePart(const Item& aItem);
  void parseMultipart(const Item& aItem);
  void parseAuthentication(const Item& aItem, String& aUserName, String& aPassword, String& aAuthMethod);

  bool getString(const Item& aItem, const String& aName, const bool aMandatory, String& aResult);
  bool getInteger(const Item& aItem, const String& aName, const bool aMandatory, int& aResult);
  bool getBoolean(const Item& aItem, const String& aName, const bool aMandatory, bool& aResult);
  bool getObject(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult);
  bool getItem(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult);
  bool getArray(const Item& aItem, const String& aName, const bool aMandatory, Item& aResult);

  void getCharset(const String& aMediaType, std::string& charset);

  void raiseTypeError(const String& aName, const String& aGot, const String& aExpected);
  void raiseMissingError(const String& aName);
};
} //namespace zorba
} //namespace http_request

#endif // REQUEST_PARSER_H
/* vim:set et sw=2 ts=2: */
