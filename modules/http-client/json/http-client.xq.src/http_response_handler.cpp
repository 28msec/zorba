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

#include <zorba/xquery_exception.h>
#include <zorba/xquery_functions.h>
#include <zorba/item.h>
#include <zorba/item_factory.h>
#include <zorba/zorba_string.h>

#include "http_response_handler.h"
#include "http_response_parser.h"

namespace zorba { namespace http_client {

  //////////////////////////////////////////////////////////////////////////
  // HttpResponseIterator
  //////////////////////////////////////////////////////////////////////////

  const char* theNamespace = "http://expath.org/ns/http-client";

  HttpResponseIterator::HttpResponseIterator(curl_slist* aHeaderList)
    : theResponseSet(false), theHeaderList(aHeaderList)
  {
    // Set an empty item as the response item
    theItems.push_back(Item());
  }

  HttpResponseIterator::~HttpResponseIterator()
  {
    if (theHeaderList)
      curl_slist_free_all(theHeaderList);
  }

  Iterator_t HttpResponseIterator::getIterator()
  {
    return new InternalIterator(this);
  }

  HttpResponseIterator::InternalIterator::InternalIterator(HttpResponseIterator *item_sequence) : 
    theItemSequence(item_sequence),
    theIndex(0)
  {
    is_open = false;
  }

  void HttpResponseIterator::InternalIterator::open()
  {
     theIndex = 0;
    is_open = true;
  }

  void HttpResponseIterator::InternalIterator::close()
  {
    is_open = false;
  }

  bool HttpResponseIterator::InternalIterator::isOpen() const
  {
    return is_open;
  }

  bool HttpResponseIterator::InternalIterator::next( Item& aItem )
  {
    if (!theItemSequence->theResponseSet) {
      return false;
    }
    if (theIndex < theItemSequence->theItems.size()) {
      aItem = theItemSequence->theItems[theIndex];
      ++theIndex;
      return !aItem.isNull();
    }
    return false;
  }

  void HttpResponseIterator::addItem(const Item& aItem)
  {
    theItems.push_back(aItem);
  }

  void HttpResponseIterator::setResponseItem(const Item& aItem)
  {
    theItems[0] = aItem;
    theResponseSet = true;
  }
        
  //////////////////////////////////////////////////////////////////////////
  // HttpResponseHandler
  //////////////////////////////////////////////////////////////////////////

  HttpResponseHandler::HttpResponseHandler(ItemFactory* aFactory, curl_slist* aHeaderList)
    :
  theResult(new HttpResponseIterator(aHeaderList)),
  theFactory(aFactory),
  theIsInsideMultipart(false),
  theIsMultipartBody(false),
  theDeleteResponse(true)
  {
    theUntypedQName = theFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  }

  HttpResponseHandler::~HttpResponseHandler() {
    if (theDeleteResponse) {
      delete theResult;
    }
  }

  void HttpResponseHandler::begin()
  {
    std::cout << "H::begin()" << std::endl;
  }

  void HttpResponseHandler::beginResponse(int aStatus, String aMessage)
  {
    std::cout << "H::beginResponse()" << std::endl;
    Item lStatusName = theFactory->createString("status");
    Item lStatusValue = theFactory->createInteger(aStatus);

    Item lMessageName = theFactory->createString("message");
    Item lMessageValue = theFactory->createString(aMessage);

    theResponsePairs.push_back(std::pair<Item, Item>(lStatusName, lStatusValue));
    theResponsePairs.push_back(std::pair<Item, Item>(lMessageName, lMessageValue));
  }

  void HttpResponseHandler::endResponse()
  {
    std::cout << "H::endResponse()" << std::endl;
    if (theResponseHeaderMap.size()>0)
    {
      Item lHeadersName = theFactory->createString("headers");
      std::vector<std::pair<Item,Item> > lHeadersPairs;

      std::map<String,String>::iterator it = theResponseHeaderMap.begin();
      std::map<String,String>::iterator end = theResponseHeaderMap.end();
      Item lName;
      Item lValue;
      for (;it!=end;++it)
      {
        lName = theFactory->createString(it->first);
        lValue = theFactory->createString(it->second);
        lHeadersPairs.push_back(std::pair<Item,Item>(lName,lValue));
      }
      Item lHeaders = theFactory->createJSONObject(lHeadersPairs);
      theResponsePairs.push_back(std::pair<Item,Item>(lHeadersName,lHeaders));
    }

    Item lResponse = theFactory->createJSONObject(theResponsePairs);
    theResult->setResponseItem(lResponse);
  }

  void HttpResponseHandler::header(String aName, String aValue)
  {
    std::cout << "H::header()" << std::endl;
    std::map<String, String>& lHeaderMap =
      theIsInsideMultipart ? theMultipartHeaderMap : theResponseHeaderMap;

    if (lHeaderMap.find(aName)!=lHeaderMap.end())
      lHeaderMap[aName] = lHeaderMap[aName] + ","  +aValue;
    else
      lHeaderMap[aName] = aValue;
  }

  void HttpResponseHandler::beginBody(String aContentType,
                                      String aSrc,
                                      ItemSequence* aSerializerOptions)
  {
    std::cout << "H::beginBody()" << std::endl;
    std::vector<std::pair<Item, Item> >& lBodyPairs =
      theIsInsideMultipart ? theMultipartBodyPairs : theBodyPairs;

    Item lName = theFactory->createString("media-type");
    Item lValue = theFactory->createString(aContentType);

    lBodyPairs.push_back(std::pair<Item, Item>(lName,lValue));
  }

  void HttpResponseHandler::any(Item aItem, std::string& charset)
  {
    std::cout << "H::any()" << std::endl;
    std::vector<std::pair<Item, Item> >& lBodyPairs =
          theIsInsideMultipart ? theMultipartBodyPairs : theBodyPairs;
      Item lContentName = theFactory->createString("content");
      lBodyPairs.push_back(std::pair<Item,Item>(lContentName,aItem));
  }

  void HttpResponseHandler::getline(std::istream& aStream, std::string& aString)
  {
    std::getline(aStream, aString);
    if (aString[aString.length() - 1] == '\r')
      aString.erase(aString.length() - 1, 1);
  }
  void HttpResponseHandler::parseHeader(const std::string& aHeader, std::string& aContentType, std::string& aCharset)
  {
    std::string::size_type lSeparator = aHeader.find(':');
    std::string::size_type lNameEnd = aHeader.find_last_not_of(" \t", lSeparator);
    std::string::size_type lNameStart = aHeader.find_first_not_of(" \t");
    std::string lName = aHeader.substr( lNameStart, lNameEnd - lNameStart );
    std::string::size_type lValueStart = aHeader.find_first_not_of(" \t", lSeparator + 1);
    std::string lValue = aHeader.substr( lValueStart );
    std::cout << lName << ":" << lValue << std::endl;

    String lNameS = fn::lower_case( lName );
    if (lNameS == "content-type")
      parse_content_type(lValue, &aContentType, &aCharset);

    header(lName, lValue);
  }

  void HttpResponseHandler::parseMultipartBody(Item& aItem, const std::string& aBoundary)
  {
    std::cout << "H::parseMultipartBody()" << std::endl;
    std::istream& lStream = aItem.getStream();

    std::string lMediaType;
    std::string lCharset;

    std::string lLine;
    std::stringstream lBody;
    ParseState lState = START;
    char * buffer = new char [aBoundary.length() + 4];
    while (lState != END)
    {
      switch (lState)
      {
        case START:
          std::cout << "START" << std::endl;
          lStream.read(buffer, aBoundary.length() + 2);
          if (buffer[0] != '-' ||
              buffer[1] != '-' ||
              strncmp(buffer+2, aBoundary.c_str(), aBoundary.length() != 0))
          {
            std::cout << "Cannot parse multipart, invalid start boundary" <<std::endl;
          }
          getline(lStream, lLine);
          if (!lLine.empty())
          {
            std::cout << "Cannot parse multipart, invalid start boundary" <<std::endl;
          }
          lState=HEADERS;
          break;

        case HEADERS:
          std::cout << "HEADERS" << std::endl;
          lMediaType.clear();
          lCharset.clear();
          do
          {
            getline(lStream, lLine);
            std::cout << "RAW:" << lLine << std::endl;
            if (lLine.empty())
              break;
            else
              parseHeader(lLine, lMediaType, lCharset);
          }
          while(true);
          lState=BODY;
          break;
        case BODY:
          std::cout << "BODY" << std::endl;
          beginBody(lMediaType, "", NULL);
          lBody.str("");
          lBody.clear();
          while (true)
          {
            std::getline(lStream, lLine);
            std::cout << "Read: " << lLine << std::endl;
            if (lLine.compare("--" + aBoundary + "\r") == 0 ||
                lLine.compare("--" + aBoundary) == 0)
            {
              any(theFactory->createString(lBody.str()), lCharset);
              endBody();
              //end of this body
              lState=HEADERS;
              break;
            }
            else if (lLine.compare("--" + aBoundary + "--\r") == 0 ||
                lLine.compare("--" + aBoundary + "--") == 0)
            {
              any(theFactory->createString(lBody.str()), lCharset);
              endBody();
              lState=END;
              break;
              //end of multipart
            }
            else
            {
              lBody << lLine << "\n";
            }
          }
          break;
      }
    }

/*

    Item lTestBody = theFactory->createString("dummy");
    header("h1", "v1");
    header("h2", "v2");
    std::string lCharset = "UTF-8";
    beginBody("text/test", "", NULL);
    any(lTestBody, lCharset);
    endBody();

    Item lTestBody2 = theFactory->createString("dummy2");
    header("h3", "v3");
    header("h4", "v4");
    std::string lCharset2 = "UTF-8";
    beginBody("text/test2", "", NULL);
    any(lTestBody2, lCharset2);
    endBody();
*/
  }

  void HttpResponseHandler::endBody()
  {
    std::cout << "H::endBody()" << std::endl;
    std::vector<std::pair<Item, Item> >& lBodyPairs =
      theIsInsideMultipart ? theMultipartBodyPairs : theBodyPairs;

    Item lBody = theFactory->createJSONObject(lBodyPairs);
    if (theIsInsideMultipart)
    {
      std::vector<std::pair<Item,Item> > lPartsPairs;
      if (theMultipartHeaderMap.size()>0)
      {
        Item lHeadersName = theFactory->createString("headers");
        std::vector<std::pair<Item,Item> > lHeadersPairs;

        std::map<String,String>::iterator it = theMultipartHeaderMap.begin();
        std::map<String,String>::iterator end = theMultipartHeaderMap.end();
        Item lName;
        Item lValue;
        for (; it != end; ++it)
        {
          lName = theFactory->createString(it->first);
          lValue = theFactory->createString(it->second);
          lHeadersPairs.push_back(std::pair<Item, Item>(lName, lValue));
        }

        Item lHeaders = theFactory->createJSONObject(lHeadersPairs);
        lPartsPairs.push_back(std::pair<Item,Item>(lHeadersName,lHeaders));
        theMultipartHeaderMap = std::map<String, String>();
      }

      Item lBodyName = theFactory->createString("body");
      lPartsPairs.push_back(std::pair<Item,Item>(lBodyName,lBody));
      Item lPart = theFactory->createJSONObject(lPartsPairs);
      theMultipartBodyVector.push_back(lPart);
      theMultipartBodyPairs.clear();
    }
    else
    {
      Item lName = theFactory->createString("body");
      theResponsePairs.push_back(std::pair<Item,Item>(lName,lBody));
    }
  }

  void HttpResponseHandler::beginMultipart(String aContentType, String aBoundary)
  {
    std::cout << "H::beginMultipart() " << aContentType << aBoundary << std::endl;
    theIsInsideMultipart = true;
    theIsMultipartBody = true;

    Item lContentTypeName = theFactory->createString("content-type");
    Item lContentTypeValue = theFactory->createString(aContentType);

    theMultipartPairs.push_back(std::pair<Item,Item>(lContentTypeName, lContentTypeValue));

    Item lBoundaryName = theFactory->createString("boundary");
    Item lBoundaryValue = theFactory->createString(aBoundary);

    theMultipartPairs.push_back(std::pair<Item,Item>(lBoundaryName, lBoundaryValue));
  }

  void HttpResponseHandler::endMultipart()
  {
    std::cout << "H::endMultipart()" << std::endl;
    theIsInsideMultipart = false;
    Item lBodyName = theFactory->createString("parts");
    Item lBodyArray = theFactory->createJSONArray(theMultipartBodyVector);

    theMultipartPairs.push_back(std::pair<Item,Item>(lBodyName, lBodyArray));

    Item lName = theFactory->createString("multipart");
    Item lMultipart = theFactory->createJSONObject(theMultipartPairs);
    theResponsePairs.push_back(std::pair<Item,Item>(lName, lMultipart));
  }

  void HttpResponseHandler::end()
  {
    std::cout << "H::end()" << std::endl;
  }

  HttpResponseIterator* HttpResponseHandler::getResult()
  {
    return theResult;
  }

  HttpResponseIterator* HttpResponseHandler::releaseResult()
  {
    theDeleteResponse = false;
    return theResult;
  }
}} //namespace zorba, namespace http_client
/* vim:set et sw=2 ts=2: */
