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
#include <string>
#include <sstream>
#include <assert.h>
#include <iostream>

#include <zorba/item_factory.h>
#include <zorba/item.h>
#include <zorba/xmldatamanager.h>
#include <zorba/base64.h>
#include <zorba/config.h>
#include <zorba/error.h>
#include <zorba/xquery_exception.h>
#include <zorba/xquery_functions.h>

#include "http_response_parser.h"
#include "http_request_handler.h"
#include "curl_stream_buffer.h"

namespace zorba { namespace http_client {
  
  HttpResponseParser::HttpResponseParser(RequestHandler& aHandler, CURL* aCurl,
                                         ErrorThrower& aErrorThrower,
                                         std::string aOverridenContentType, bool aStatusOnly)
  : 
  theHandler(aHandler), theCurl(aCurl), theErrorThrower(aErrorThrower),
  theStatus(-1), theStreamBuffer(0), theInsideRead(false),
  theOverridenContentType(aOverridenContentType),
  theStatusOnly(aStatusOnly), theSelfContained(true)
  {
    registerHandler();
    theStreamBuffer = new zorba::curl::streambuf(theCurl);
  }

  HttpResponseParser::~HttpResponseParser()
  {
    delete theStreamBuffer;
  }

  int HttpResponseParser::parse()
  {
    theStreamBuffer->setInformer(this);
    theHandler.begin();
    int lCode = 0;
    lCode = theStreamBuffer->multi_perform();
    if (lCode)
      return lCode; 
    if (!theStatusOnly) {
      std::auto_ptr<std::istream> lStream(new std::istream(theStreamBuffer));
      Item lItem;
      if (theOverridenContentType != "") {
        theCurrentContentType = theOverridenContentType;
      }
      if (theCurrentContentType == "text/xml" ||
          theCurrentContentType == "application/xml" ||
          theCurrentContentType == "text/xml-external-parsed-entity" ||
          theCurrentContentType == "application/xml-external-parsed-entity" ||
          theCurrentContentType.find("+xml") == theCurrentContentType.size()-4) {
        lItem = createXmlItem(*lStream.get());
      } else if (theCurrentContentType.find("text/html") == 0) {
        lItem = createTextItem(lStream.release());
      } else if (theCurrentContentType.find("text/") == 0) {
        lItem = createTextItem(lStream.release());
      } else {
        lItem = createBase64Item(*lStream.get());
      }
      if (!lItem.isNull()) {
        theHandler.any(lItem);
      }
      if (!theInsideRead) {
        theHandler.beginResponse(theStatus, theMessage);
      } else {
        theHandler.endBody();
      }
    }
    if (!theInsideRead) {
      theHandler.beginResponse(theStatus, theMessage);
      for (std::vector<std::pair<std::string, std::string> >::iterator i = theHeaders.begin();
          i != theHeaders.end(); ++i) {
        theHandler.header(i->first, i->second);
      }
    }
    theHandler.endResponse();
    theHandler.end();
    return lCode;
  }

  void HttpResponseParser::beforeRead()
  {
    if (theInsideRead) {
      return;
    }
    theInsideRead = true;
    theHandler.beginResponse(theStatus, theMessage);
    std::vector<std::pair<std::string, std::string> >::iterator lIter;
    for (lIter = theHeaders.begin(); lIter != theHeaders.end(); ++lIter) {
      theHandler.header(lIter->first, lIter->second);
    }
    if (!theStatusOnly)
      theHandler.beginBody(theCurrentContentType, "", NULL);
  }

  void HttpResponseParser::afterRead()
  {
  }

  void HttpResponseParser::registerHandler()
  {
    curl_easy_setopt(theCurl, CURLOPT_HEADERFUNCTION,
      &HttpResponseParser::headerfunction);
    curl_easy_setopt(theCurl, CURLOPT_HEADERDATA, this);
  }

  size_t HttpResponseParser::headerfunction(void *ptr,
                                            size_t size,
                                            size_t nmemb,
                                            void *stream)
  {
    size_t lSize = size*nmemb;
    size_t lResult = lSize;
    HttpResponseParser* lParser = static_cast<HttpResponseParser*>(stream);
    if (lParser->theInsideRead) {
      lParser->theHandler.endBody();
    }
    lParser->theInsideRead = false;
    const char* lDataChar = (const char*) ptr;
    while (lSize != 0 && (lDataChar[lSize - 1] == 10
          || lDataChar[lSize - 1] == 13)) {
      lSize--;
    }
    if (lSize == 0) {
      return lResult;
    }
    std::string lData(lDataChar, lSize);

    if (lData.find("HTTP") == 0) {
      lParser->parseStatusAndMessage(lData);
      return lResult;
    }
    std::string::size_type lPos = lData.find(':');
    if (lPos == std::string::npos) {
      return lResult;
    }
    std::string lName = lData.substr(0, lPos);
    std::string lValue = lData.substr(lPos + 2);
    {
      std::string::size_type lPosition = lValue.size() - 1;
      while (true) {
        if (lPosition != std::string::npos) {
          break;
        }
        if (lValue[lPosition] == '\n' || lValue[lPosition] == '\r') {
          --lPosition;
        } else {
          break;
        }
      }
      lValue = lValue.substr(0, lPosition + 1);
    }
    String lNameS = fn::lower_case( lName );
    if (lNameS == "content-type") {
      lParser->theCurrentContentType = lValue.substr(0, lValue.find(';'));
    } else if (lNameS == "content-id") {
      lParser->theId = lValue;
    } else if (lNameS == "content-description") {
      lParser->theDescription = lValue;
    }
    lParser->theHeaders.push_back(
      std::pair<std::string, std::string>(lName, lValue));
    return lResult;
  }

  void HttpResponseParser::parseStatusAndMessage(std::string aHeader)
  {
    std::string::size_type lPos = aHeader.find(' ');
    assert(lPos != std::string::npos);
    std::string lStatus = aHeader.substr(lPos, aHeader.find(' ', lPos + 1));
    theMessage = aHeader.substr(aHeader.find(' ', lPos + 1) + 1);
    {
      std::string::size_type lPosition = theMessage.size() - 1;
      while (true) {
        if (lPosition != std::string::npos) {
          break;
        }
        if (theMessage[lPosition] == '\n' || theMessage[lPosition] == '\r') {
          --lPosition;
        } else {
          break;
        }
      }
      theMessage = theMessage.substr(0, lPosition + 1);
    }
    std::stringstream lStream(lStatus);
    lStream >> theStatus;
    // everything that is not a valid http status is an error
    if (theStatus < 100) {
      theErrorThrower.raiseException("http://expath.org/ns/error", "HC001", "An HTTP error occurred");
    }
  }

  static void streamReleaser(std::istream* aStream)
  {
    // This istream contains our curl stream buffer, so we have to delete it too
    delete aStream->rdbuf();
    delete aStream;
  }

  zorba::Item HttpResponseParser::createTextItem(std::istream* aStream)
  {
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();

    // When we create a StreamableString, memory ownership gets very convoluted
    // because the StreamableString object has a longer lifecycle than the
    // iterator which creates it. The StreamableString object depends on its
    // istream, which in turn depends on its read buffer. For us, the read
    // buffer in turn depends on the HttpResponseParser (this object) because
    // it is registered as the "informer" (callback object) for
    // theStreamBuffer. Therefore, this HttpResponseParser object is no longer
    // "self-contained". We delegate ownership of ourself to theStreamBuffer
    // and mark ourselves as no longer being self-contained.
    theStreamBuffer->setOwnInformer(true);
    theSelfContained = false;

    // The ownership of theStreamBuffer, in turn, is delegated to the
    // StreamableString object (via streamReleaser, which will free the
    // istream's rdbuf).
    theStreamBuffer = NULL;
    return lFactory->createStreamableString(*aStream, &streamReleaser, false);
  }

  zorba::Item HttpResponseParser::createBase64Item( std::istream& aStream )
  {
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    // TODO: once a proper streaming implementation is in place this can be
    // changed. This required a Base64 encoding stream since the item factory
    // work only builds base64binary and assumes the data is already encoded.
    String lEncoded = encoding::Base64::encode(aStream);
    return lFactory->createBase64Binary(lEncoded.data(), lEncoded.size());
  }

  zorba::Item HttpResponseParser::createXmlItem( std::istream& aStream )
  {
    try {
      XmlDataManager* lDM = Zorba::getInstance(0)->getXmlDataManager();
      return lDM->parseXML(aStream);
    } catch (...) {
      theErrorThrower.raiseException("http://expath.org/ns/error", 
          "HC002", "Error parsing the entity content as XML.");
      //compiler does not recognize, that this function throws an exception, so we just
      // return something
      return Item(); 
    }
  }
}}
