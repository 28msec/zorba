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
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/api_shared_types.h>
#include <zorba/base64.h>

#include "http_request_handler.h"

namespace zorba { namespace http_client {

  HttpRequestHandler::HttpRequestHandler(CURL* aCurl,
                                         ItemSequence* aContent)
    : theCurl(aCurl),
      theStatusOnly(false),
      theInsideMultipart(false),
      theLastBodyHadContent(false),
      theContent(aContent),
      theSerStream(NULL),
      thePost(NULL),
      theLast(NULL)
  {
    theHeaderLists.push_back(NULL);
  }

  HttpRequestHandler::~HttpRequestHandler()
  {
    std::vector<struct curl_slist*>::iterator lIter;
    for (lIter = theHeaderLists.begin(); lIter != theHeaderLists.end(); ++lIter)
    {
      if (*lIter) {
        curl_slist_free_all(*lIter);
      }
    }

    if (thePost != NULL) {
      curl_formfree(thePost);
    }
  }

  void HttpRequestHandler::begin()
  {
  }

  void HttpRequestHandler::beginResponse(int aStatus, String aMessage)
  {
  }

  void HttpRequestHandler::endResponse()
  {
  }

  void HttpRequestHandler::beginRequest(String aMethod,
                                        String href,
                                        bool aStatusOnly,
                                        String aUsername,
                                        String aPassword,
                                        String aAuthMethod,
                                        bool aSendAuthorization,
                                        String aOverrideContentType,
                                        bool aFollowRedirect,
                                        int aTimeout /*= -1*/ )
  {
    aMethod.uppercase();
    curl_easy_setopt(theCurl, CURLOPT_CUSTOMREQUEST, aMethod.c_str());
    if (href != "") {
      curl_easy_setopt(theCurl, CURLOPT_URL, href.c_str());
    }
    if (aFollowRedirect) {
      curl_easy_setopt(theCurl, CURLOPT_FOLLOWLOCATION, 1);
    }
    theStatusOnly = aStatusOnly;
    theOverrideContentType = aOverrideContentType;
    if (aTimeout != -1) {
      curl_easy_setopt(theCurl, CURLOPT_TIMEOUT, aTimeout);
    }
    if (aUsername != "" && !aSendAuthorization) {
      String lUserPw = aUsername + ":" + aPassword;
      curl_easy_setopt(theCurl, CURLOPT_USERPWD, lUserPw.c_str());
      if (aAuthMethod.lowercase() == "basic") {
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      } else if (aAuthMethod.lowercase() == "digest") {
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_DIGEST);
      }
    }
    if (aUsername != "" && aSendAuthorization) {
      if (aAuthMethod.lowercase() == "basic") {
        String lAuthString = aUsername + ":" + aPassword;
        String lAuth = "Authorization: Basic ";
        lAuth += encoding::Base64::encode(lAuthString);
        theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lAuth.c_str());
      } else if (aAuthMethod.lowercase() == "digest") {
        String lUserPw = aUsername + ":" + aPassword;
        curl_easy_setopt(theCurl, CURLOPT_USERPWD, lUserPw.c_str());
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_DIGEST);
      }
    }
  }

  void HttpRequestHandler::endRequest()
  {
  }

  void HttpRequestHandler::header(String aName, String aValue)
  {
    std::string lValue = aName.c_str();
    lValue += ":";
    lValue += aValue.c_str();
    if (!theInsideMultipart) {
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lValue.c_str());
    } else {
      if (aName == "Content-Disposition") {
        int32_t lPos = 0;
        bool lHasMatched;
        do {
          String lNextToken = aValue.tokenize(String(";"), String(""),
                                              &lPos, &lHasMatched);
          std::pair<String, String> lKeyValue = twinSplit(lNextToken);
          if (lKeyValue.first == "name") {
            theMultipartName = lKeyValue.second;
            theMultipartName.trim("\"\'", 1);
          }
          else if (lKeyValue.first == "filename") {
            theMultiPartFileName = lKeyValue.second;
            theMultiPartFileName.trim("\"\'", 1);
          }
        } while (lHasMatched);
      } else {
        theHeaderLists.back() = curl_slist_append(theHeaderLists.back(), (lValue).c_str());
      }
    }
  }

  void HttpRequestHandler::beginBody(String aContentType,
                                     String aSrc,
                                     ItemSequence* aSerializerOptions)
  {
    theLastSerializerOptions = aSerializerOptions;
    theSerStream = new std::ostringstream();
    theCurrentContentType = aContentType;
    std::string lContentType = "Content-Type: ";
    lContentType += aContentType.c_str();
    if (!theInsideMultipart) {
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lContentType.c_str());
    } else {
      theHeaderLists.back() = curl_slist_append(theHeaderLists.back(), lContentType.c_str());
    }
  }

  void HttpRequestHandler::any(Item aItem)
  {
    serializeItem(aItem);
  }

  void HttpRequestHandler::endBody()
  {
    if (!theLastBodyHadContent) {
      if (theContent == NULL) {
        cleanUpBody();
        return;
      }
      Item lItem;
      while (theContent->next(lItem)) {
        serializeItem(lItem);
      }
    }
    thePostDataString = theSerStream->str();
    thePostData = thePostDataString.c_str();
    if (!theInsideMultipart) {
      curl_easy_setopt(theCurl, CURLOPT_POSTFIELDSIZE, thePostDataString.length());
      curl_easy_setopt(theCurl, CURLOPT_POSTFIELDS, thePostData);
    } else {
      if (theMultiPartFileName == "")
        curl_formadd(&thePost, &theLast,
                     CURLFORM_COPYNAME, theMultipartName.c_str(),
                     CURLFORM_COPYCONTENTS, thePostData,
                     CURLFORM_CONTENTSLENGTH, thePostDataString.length(),
                     CURLFORM_CONTENTHEADER, theHeaderLists.back(),
                     CURLFORM_END);
      else
        curl_formadd(&thePost, &theLast,
                     CURLFORM_COPYNAME, theMultipartName.c_str(),
                     CURLFORM_BUFFER, theMultiPartFileName.c_str(),
                     CURLFORM_BUFFERPTR, thePostData,
                     CURLFORM_BUFFERLENGTH, thePostDataString.length(),
                     CURLFORM_CONTENTHEADER, theHeaderLists.back(),
                     CURLFORM_END);
    }
  }

  void HttpRequestHandler::beginMultipart(String aContentType, String aBoundary)
  {
    theMultiPartFileName = "";
    theMultipartName = "blubb";
    theInsideMultipart = true;
    std::string lValue = "Content-Type: ";
    lValue += aContentType.c_str();
    theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lValue.c_str());
    theHeaderLists.push_back(NULL);
  }

  void HttpRequestHandler::endMultipart()
  {
    theInsideMultipart = false;
    curl_easy_setopt(theCurl, CURLOPT_HTTPPOST, thePost);
  }

  void HttpRequestHandler::end()
  {
    if (theHeaderLists[0]) {
      curl_easy_setopt(theCurl, CURLOPT_HTTPHEADER, theHeaderLists[0]);
    }
  }

  bool HttpRequestHandler::getOverrideContentType( String& aResult )
  {
    if (theOverrideContentType == "") {
      return false;
    }
    aResult = theOverrideContentType;
    return true;
  }

  void HttpRequestHandler::cleanUpBody()
  {
    delete theSerStream;
    theLastBodyHadContent = false;
  }

  void HttpRequestHandler::serializeItem( Item aItem )
  {
    theLastBodyHadContent = true;
    Serializer_t lSerializer =
      Serializer::createSerializer(theLastSerializerOptions);
    SingletonItemSequence lSequence(aItem);
    lSerializer->serialize(&lSequence, *theSerStream);
  }

  std::pair<String, String>
  HttpRequestHandler::twinSplit(const String& aStr)
  {
    int32_t lkeyPos = 0;
    bool lHasValue;
    String lKey = aStr.tokenize(String("="), String(""),
                                      &lkeyPos, &lHasValue);
    String lValue;
    if (lHasValue) {
      lValue = aStr.tokenize(String("="), String(""),
                                          &lkeyPos, &lHasValue);
    }
    lKey.trim();
    lValue.trim();
    return std::pair<String, String>(lKey, lValue);
  }
}}
