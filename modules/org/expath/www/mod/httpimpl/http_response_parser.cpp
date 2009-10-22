#include <string>
#include <strstream>
#include <assert.h>

#include <zorba/item_factory.h>

#include "http_response_parser.h"
#include "http_request_handler.h"
#include "curl_stream_buffer.h"

namespace zorba { namespace http_client {
  

  HttpResponseParser::HttpResponseParser(RequestHandler& aHandler, CURL* aCurl)
    : 
  theHandler(aHandler), theCurl(aCurl), theStatus(-1), theStreamBuffer(0),
    theInsideRead(false)
  {
    theMulti = curl_multi_init();
    curl_multi_add_handle(theMulti, theCurl);
    theStreamBuffer = new CurlStreamBuffer(theMulti, theCurl);
    registerHandler();
  }

  HttpResponseParser::~HttpResponseParser()
  {
    delete theStreamBuffer;
    curl_multi_remove_handle(theMulti, theCurl);
    curl_easy_cleanup(theCurl);
    curl_multi_cleanup(theMulti);
  }

  void HttpResponseParser::parse()
  {
    theStreamBuffer->setInformer(this);
    theHandler.begin();
    int code = theStreamBuffer->multi_perform();
    std::istream lStream(theStreamBuffer);
    std::string lData;
    {
      std::stringstream lOut;
      bool lFirst = true;
      while (lStream.good()) {
        if (!lFirst) {
          lOut << " ";
        }
        lFirst = false;
        std::string lTmp;
        lStream >> lTmp;
        lOut << lTmp;
      }
      lData = lOut.str();
    }
    lStream >> lData;
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    Item lString = lFactory->createString(lData);
    theHandler.any(lString);
    if (theInsideRead) {
      theHandler.endBody();
    }
    theHandler.endResponse();
    theHandler.end();
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
    theHandler.beginBody(theCurrentContentType, "", theId, theDescription, "");
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
    HttpResponseParser* lParser = static_cast<HttpResponseParser*>(stream);
    if (lParser->theInsideRead) {
      lParser->theHandler.endBody();
    }
    lParser->theInsideRead = false;
    const char* lDataChar = (const char*) ptr;
    std::string lData(lDataChar, lSize);

    if (lData.find("HTTP") == 0) {
      lParser->parseStatusAndMessage(lData);
      return lSize;
    }
    std::string::size_type lPos = lData.find(':');
    if (lPos == std::string::npos) {
      return lSize;
    }
    std::string lName = lData.substr(0, lPos);
    std::string lValue = lData.substr(lPos + 2);
    {
      std::string::size_type lPosition = lValue.size() - 1;
      while (true) {
        if (lPosition < 0) {
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
    if (lName == "Content-Type") {
      lParser->theCurrentContentType = lValue.substr(0, lValue.find(';'));
    } else if (lName == "Content-ID") {
      lParser->theId = lValue;
    } else if (lName == "Content-Description") {
      lParser->theDescription = lValue;
    }
    lParser->theHeaders.push_back(
      std::pair<std::string, std::string>(lName, lValue));
    return lSize;
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
        if (lPosition < 0) {
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
}}
