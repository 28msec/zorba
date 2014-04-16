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
#ifndef HTTP_REQUEST_HANDLER_H
#define HTTP_REQUEST_HANDLER_H

#include <sstream>
#include <vector>
#include <string>

#include <curl/curl.h>
#include <zorba/zorba.h>
#include "structures.h"

namespace zorba
{
namespace http_client
{

class HttpRequestHandler
{
private:
  CURL* theCurl;
  bool theInsideMultipart;
  std::vector<struct curl_slist*> theHeaderLists;
  bool theLastBodyHadContent;
  std::ostringstream* theSerStream;
  struct curl_httppost* thePost;
  struct curl_httppost* theLast;
  String theCurrentContentType;
  std::string thePostDataString;
  const char* thePostData;
  String theMultipartName;
  String theMultiPartFileName;
  // saved strings which won't be copied by curl
  std::string theMethodString;
  std::string theUserPW;
  std::string theAuthMethod;
  std::vector<std::string> theHeaderStrings;
  std::string theContentType;
  Options theOptions;
public: //Constructions
  HttpRequestHandler(CURL* aCurl);
  virtual ~HttpRequestHandler();

public:
  void sendRequest(Request& aRequest);

private:
  void begin();
  void beginResponse(int aStatus, String aMessage);
  void endResponse();
  void beginRequest(
      String aMethod,
      String href,
      String aUsername,
      String aPassword,
      String aAuthMethod,
      bool aSendAuthorization,
      Options aOptions
  );
  void endRequest();
  void header(String aName, String aValue);
  void beginBody(String aContentType, String aSrc);
  void any(Item aItem, std::string& charset);
  void endBody();
  void beginMultipart(String aContentType, String aBoundary);
  void endMultipart();
  void end();

  void emitStreamableString(Item aItem);
  void emitString(Item aItem);
  void emitStreamableBase64Binary(Item aItem);
  void emitBase64Binary(Item aItem);
  void emitStreamableHexBinary(Item aItem);
  void emitHexBinary(Item aItem);

  void serializeItem( Item aItem );

  void cleanUpBody();
  static std::pair<String, String> twinSplit(const String& aStr);
};

}}

#endif //HTTP_REQUEST_HANDLER_H
/* vim:set et sw=2 ts=2: */
