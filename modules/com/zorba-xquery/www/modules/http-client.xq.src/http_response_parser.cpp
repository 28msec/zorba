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
#include <zorba/exception.h>
#include <zorba/external_function_data.h>

#include <tidy.h>
#include <buffio.h>

#include "http_response_parser.h"
#include "http_request_handler.h"
#include "curl_stream_buffer.h"

namespace zorba { namespace http_client {

  class TidyReader {
  private:
    std::istream* theStream;
    // We need a buffer to support the unget function
    std::vector<unsigned int> theBuffer;
  public:
    TidyReader(std::istream* aStream) : theStream(aStream) {}
    TidyInputSource getInputSource()
    {
      TidyInputSource lResult;
      lResult.sourceData = this;
      lResult.getByte = &getByte;
      lResult.ungetByte = &ungetByte;
      lResult.eof = &isEof;
      return lResult;
    }

  public: // callback functions
    static int TIDY_CALL getByte(void* aData)
    {
      TidyReader* lReader = static_cast<TidyReader*>(aData);
      if (lReader->theBuffer.empty())
        return lReader->theStream->get();
      else {
        int lResult = lReader->theBuffer.back();
        lReader->theBuffer.pop_back();
        return lResult;
      }
    }

    static void TIDY_CALL ungetByte(void* aData, byte aByte)
    {
      TidyReader* lReader = static_cast<TidyReader*>(aData);
      lReader->theBuffer.push_back(aByte);
    }

    static Bool TIDY_CALL isEof(void* aData)
    {
      TidyReader* lReader = static_cast<TidyReader*>(aData);
      return lReader->theStream->eof() ? yes : no;
    }
  };

  HttpResponseParser::HttpResponseParser(RequestHandler& aHandler, CURL* aCurl,
    CURLM* aCurlM, std::string aOverridenContentType, bool aStatusOnly)
    : 
  theHandler(aHandler), theCurl(aCurl), theMulti(aCurlM), theStatus(-1),
    theStreamBuffer(0), theInsideRead(false),
    theOverridenContentType(aOverridenContentType),
    theStatusOnly(aStatusOnly)
  {
    curl_multi_add_handle(theMulti, theCurl);
    theStreamBuffer = new CurlStreamBuffer(theMulti, theCurl, aStatusOnly);
    registerHandler();
  }

  HttpResponseParser::~HttpResponseParser()
  {
    delete theStreamBuffer;
    curl_multi_remove_handle(theMulti, theCurl);
    curl_easy_cleanup(theCurl);
    curl_multi_cleanup(theMulti);
  }

  int HttpResponseParser::parse()
  {
    theStreamBuffer->setInformer(this);
    theHandler.begin();
    int lCode = theStreamBuffer->multi_perform();
    if (!theStatusOnly) {
      std::istream lStream(theStreamBuffer);
      Item lItem;
      if (theOverridenContentType != "") {
        theCurrentContentType = theOverridenContentType;
      }
      if (theCurrentContentType == "text/xml" ||
          theCurrentContentType == "application/xml" ||
          theCurrentContentType == "text/xml-external-parsed-entity" ||
          theCurrentContentType == "application/xml-external-parsed-entity" ||
          theCurrentContentType.find("+xml") == theCurrentContentType.size()-4) {
        lItem = createXmlItem(lStream);
      } else if (theCurrentContentType.find("text/html") == 0) {
        lItem = createTextItem(lStream);
      } else if (theCurrentContentType.find("text/") == 0) {
        lItem = createTextItem(lStream);
      } else {
        lItem = createBase64Item(lStream);
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
    if (!theInsideRead)
      theHandler.beginResponse(theStatus, theMessage);
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
    String lNameS = lName.c_str();
    lNameS.lowercase();
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
  }

  zorba::Item HttpResponseParser::createTextItem(std::istream& aStream)
  {
    std::string lData;
    {
      std::stringstream lOut;
      bool lFirst = true;
      while (aStream.good()) {
        if (!lFirst) {
          lOut << " ";
        }
        lFirst = false;
        std::string lTmp;
        aStream >> lTmp;
        lOut << lTmp;
      }
      lData = lOut.str();
    }
    aStream >> lData;
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    return lFactory->createString(lData);
  }

  zorba::Item HttpResponseParser::createBase64Item( std::istream& aStream )
  {
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    // TODO: once a proper streaming implementation is in place this can be
    // changed. This required a Base64 encoding stream since the item factory
    // work only builds base64binary and assumes the data is already encoded.
    String lEncoded = encoding::Base64::encode(aStream);
    return lFactory->createBase64Binary(lEncoded.c_str(), lEncoded.bytes());
  }

  zorba::Item HttpResponseParser::createXmlItem( std::istream& aStream )
  {
    XmlDataManager* lDM = Zorba::getInstance(0)->getXmlDataManager();
    return lDM->parseDocument(aStream);
  }
}}
