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
#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

namespace zorba {
class Item;

namespace http_client {
class RequestHandler;
class ErrorThrower;

class RequestParser {
protected:
  RequestHandler* theHandler;
  ErrorThrower*   theThrower;

public:
  RequestParser(RequestHandler* aHandler, ErrorThrower& aThrower) : theHandler(aHandler), theThrower(&aThrower) {}
  bool parse(const Item& aItem);

private:
  bool parseItem(const Item& aItem);
  bool handleRequest(const Item& aItem);
  bool handleResponse(const Item aItem);
  bool handleHeader(const Item& aItem);
  bool handleBody(const Item& aItem);
  bool handleMultipart(const Item& aItem);
};
} //namespace zorba
} //namespace http_request

#endif // REQUEST_PARSER_H
