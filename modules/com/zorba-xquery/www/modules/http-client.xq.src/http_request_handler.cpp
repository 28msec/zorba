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
#include <zorba/xquery_functions.h>
#include <zorba/zorba_functions.h>
#include <zorba/base64.h>
#include <zorba/xquery_functions.h>

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
      theLast(NULL),
      theIsHeadRequest(false)
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
    aMethod = fn::upper_case(aMethod);
    const char* lStr = aMethod.c_str();
    theMethodString = lStr;
    String const lAuthMethod = fn::lower_case(aAuthMethod);
    if (theMethodString == "HEAD" || theMethodString == "OPTIONS") {
      curl_easy_setopt(theCurl, CURLOPT_NOBODY, 1L);
      theIsHeadRequest = true;
    }
    curl_easy_setopt(theCurl, CURLOPT_CUSTOMREQUEST, theMethodString.c_str());
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
      theUserPW = lUserPw.c_str();
      curl_easy_setopt(theCurl, CURLOPT_USERPWD, theUserPW.c_str());
      if (lAuthMethod == "basic") {
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      } else if (lAuthMethod == "digest") {
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_DIGEST);
      }
    }
    if (aUsername != "" && aSendAuthorization) {
      if (lAuthMethod == "basic") {
        String lAuthString = aUsername + ":" + aPassword;
        String lAuth = "Authorization: Basic ";
        lAuth += encoding::Base64::encode(lAuthString);
        theAuthMethod = lAuth.c_str();
        theHeaderLists[0] = curl_slist_append(theHeaderLists[0], theAuthMethod.c_str());
      } else if (lAuthMethod == "digest") {
        String lUserPw = aUsername + ":" + aPassword;
        theUserPW = lUserPw.c_str();
        curl_easy_setopt(theCurl, CURLOPT_USERPWD, theUserPW.c_str());
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
    theHeaderStrings.push_back(lValue);
    if (!theInsideMultipart) {
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lValue.c_str());
    } else {
      if (aName == "Content-Disposition") {
        Sequence<String> lTokens(fn::tokenize(aValue, ";"));
        for (String lNextToken; lTokens.next( &lNextToken );) {
          std::pair<String, String> lKeyValue = twinSplit(lNextToken);
          if (lKeyValue.first == "name") {
            theMultipartName = lKeyValue.second;
            zfn::trim(theMultipartName, "\"\'");
          }
          else if (lKeyValue.first == "filename") {
            theMultiPartFileName = lKeyValue.second;
            zfn::trim(theMultiPartFileName, "\"\'");
          }
        }
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
    theContentType = "Content-Type: ";
    theContentType += aContentType.c_str();
    if (!theInsideMultipart) {
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], theContentType.c_str());
    } else {
      theHeaderLists.back() = curl_slist_append(theHeaderLists.back(), theContentType.c_str());
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
      Iterator_t content_iter = theContent->getIterator();
      content_iter->open();
      while (content_iter->next(lItem)) {
        serializeItem(lItem);
      }
      content_iter->close();
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
      theHeaderLists.push_back(NULL);
    }
  }

  void HttpRequestHandler::beginMultipart(String aContentType, String aBoundary)
  {
    theMultiPartFileName = "";
    theMultipartName = "zorba-default";
    theInsideMultipart = true;
    std::string lValue = "Content-Type: ";
    lValue += aContentType.c_str();
    theHeaderStrings.push_back (lValue);
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
    String lKey, lValue;

    String::size_type const equals = aStr.find('=');
    if (equals != String::npos) {
      lKey = aStr.substr(0, equals);
      lValue = aStr.substr(equals + 1);
      zfn::trim(lKey);
      zfn::trim(lValue);
    }

    return std::pair<String, String>(lKey, lValue);
  }

} // namespace http_client
} // namespace zorba
