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
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <sstream>

#include <zorba/singleton_item_sequence.h>
#include <zorba/empty_sequence.h>
#include <api/unmarshaller.h>
#include "http_util.h"
#include "error_util.h"
#include "zorbamisc/ns_consts.h"


namespace zorba {
  
  HttpStream::HttpStream(const zstring& aUri)
    : theUri(aUri)
  {
  }
  
  HttpStream::~HttpStream()
  {
    if (theIterator)
    {
      theIterator->close();
    }
  }
  
  void HttpStream::init()
  {
    bool succeed = false;

#ifdef ZORBA_HAVE_CURL
    Zorba* lInstance = Zorba::getInstance(0);
    theStaticContext = lInstance->createStaticContext();
    ItemFactory* lFactory = lInstance->getItemFactory();
    Item lNodeName = lFactory->createQName("http://expath.org/ns/http-client", "http", "request");
    Item lEmptyItem;
    NsBindings nsPairs;
    nsPairs.push_back(std::make_pair(String(XML_SCHEMA_PREFIX), String(XML_SCHEMA_NS)));
    Item lRequestElement = lFactory->createElementNode(lEmptyItem, lNodeName,
                                                       lFactory->createQName(XML_SCHEMA_NS,
                                                                             XML_SCHEMA_PREFIX, "untyped"),
                                                       true, false, nsPairs);
    lFactory->createAttributeNode(lRequestElement, lFactory->createQName("", "method"), Item(), lFactory->createString("GET"));
    lFactory->createAttributeNode(lRequestElement, lFactory->createQName("", "href"), Item(), lFactory->createString(theUri.c_str()));
    lFactory->createAttributeNode(lRequestElement, lFactory->createQName("", "override-media-type"), Item(), lFactory->createString("text/plain"));
    lFactory->createAttributeNode(lRequestElement, lFactory->createQName("", "follow-redirect"), Item(), lFactory->createString("true"));
    Zorba_CompilerHints_t lHints;
    lHints.opt_level = ZORBA_OPT_LEVEL_O1;
    theStaticContext->loadProlog("import module namespace httpc = \"http://www.zorba-xquery.com/modules/http-client\";",
                                 lHints);
    Item lQName = lFactory->createQName("http://www.zorba-xquery.com/modules/http-client",
                                        "httpc", "send-request");
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(lRequestElement));
    lArgs.push_back(new EmptySequence());
    lArgs.push_back(new EmptySequence());
    theItemSequence = theStaticContext->invoke(lQName, lArgs);
    theIterator = theItemSequence->getIterator();
    theIterator->open();
    Item lItem;
    theIterator->next(lItem);
    Iterator_t lIter = lItem.getAttributes();
    lIter->open();
    Item lAttr;
    succeed = true;
    while (lIter->next(lAttr)) {
      Item lName;
      lAttr.getNodeName(lName);
      String lNameString = lName.getStringValue();
      if (lNameString == "status") {
        std::stringstream lStream(lAttr.getStringValue().c_str());
        int status;
        lStream >> status;
        succeed = status < 400;
        break;
      }
    }
    lIter->close();
#endif /* ZORBA_HAVE_CURL */

    if (!succeed)
      throw os_error::exception("", theUri.c_str(), "Could not create stream resource");
    theIterator->next(theStreamableString);
  }
  
  std::istream& HttpStream::getStream()
  {
    return theStreamableString.getStream();
  }

  StreamReleaser HttpStream::getStreamReleaser()
  {
    store::Item* lItem = Unmarshaller::getInternalItem(theStreamableString);
    return lItem->getStreamReleaser();
  }

  void HttpStream::setStreamReleaser(StreamReleaser aReleaser)
  {
    store::Item* lItem = Unmarshaller::getInternalItem(theStreamableString);
    lItem->setStreamReleaser(aReleaser);
  }
}
