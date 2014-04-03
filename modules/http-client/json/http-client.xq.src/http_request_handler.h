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
#pragma once
#ifndef HTTP_REQUEST_HANDLER_H
#define HTTP_REQUEST_HANDLER_H

#include <sstream>
#include <vector>
#include <string>

#include <curl/curl.h>
#include <zorba/zorba.h>

namespace zorba { namespace http_client {

  class HttpRequestHandler
  {
  private:
    CURL* theCurl;
    bool theStatusOnly;
    String theOverrideContentType;
    bool theInsideMultipart;
    std::vector<struct curl_slist*> theHeaderLists;
    bool theLastBodyHadContent;
    std::ostringstream* theSerStream;
    struct curl_httppost* thePost;
    struct curl_httppost* theLast;
    String theCurrentContentType;
    ItemSequence* theLastSerializerOptions;
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
    bool theIsHeadRequest;

  public: //Constructions
    HttpRequestHandler(CURL* aCurl);
    virtual ~HttpRequestHandler();

  public: //Interfaces
    /**
     * @brief Get the override-content-type option.
     *
     * If the user set the override-content-type option, this method will
     * set the result to the user specified value and will return true.
     * Otherwise it will return false.
     *
     * @param aResult The override-content-type option, if set.
     * @return A boolean indicating if the override-content-type is set.
     */
    bool getOverrideContentType(String& aResult);

  public: //Implementation of parent interface
    virtual void begin();
    virtual void beginResponse(int aStatus, String aMessage);
    virtual void endResponse();
    virtual void beginRequest(
      String aMethod,
      String href,
      bool aStatusOnly,
      String aUsername,
      String aPassword,
      String aAuthMethod,
      bool aSendAuthorization,
      String aOverrideContentType,
      bool aFollowRedirect,
      String aUserAgent,
      int aTimeout = -1);
    virtual void endRequest();
    virtual void header(String aName, String aValue);
    virtual void beginBody(
      String aContentType,
      String aSrc,
      ItemSequence* aSerializerOptions);
    virtual void any(Item aItem, std::string& charset);

    virtual void emitStreamableString(Item aItem);
    virtual void emitString(Item aItem);
    virtual void emitStreamableBase64Binary(Item aItem);
    virtual void emitBase64Binary(Item aItem);
    virtual void emitStreamableHexBinary(Item aItem);
    virtual void emitHexBinary(Item aItem);


    void serializeItem( Item aItem );
    virtual void endBody();
    virtual void beginMultipart(String aContentType, String aBoundary);
    virtual void endMultipart();
    virtual void end();

    bool isStatusOnly() const { return theStatusOnly; }
    virtual bool isHeadRequest() const { return theIsHeadRequest; }

  private: //Helper functions
    void cleanUpBody();
    static std::pair<String, String> twinSplit(const String& aStr);
  };

}}

#endif //HTTP_REQUEST_HANDLER_H
/* vim:set et sw=2 ts=2: */
