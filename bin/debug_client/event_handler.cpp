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
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/iterator.h>
#include <sstream>
#include "debug_client/event_handler.h"

namespace zorba { namespace debugclient {
  
  EventHandler::EventHandler(LockFreeProducer<std::size_t>& aQueue, LockFreeProducer<bool>& aContProducer)
  : theIdQueue(aQueue), theContinueProducer(aContProducer),
    theStore(StoreManager::getStore()),
    theZorbaInstance(Zorba::getInstance(theStore)),
    theStaticContext(theZorbaInstance->createStaticContext())
    
  {
    try {
      Zorba_CompilerHints_t lHints;
      lHints.opt_level = ZORBA_OPT_LEVEL_O1;
      std::auto_ptr<std::istream> stream(getCurrentDirectory());
      zorba::String query;
      char buffer[1024];
      std::string::size_type s;
      while ((s = stream->readsome(buffer, 1024))) {
        query.append(std::string(buffer, s));
      }
      theStaticContext->loadProlog(query, lHints);
    } catch (zorba::ZorbaException& e) {
      std::cerr << "Exception: I was not able to load the query file:" << std::endl;
      std::cerr << e.what() << std::endl;
      throw;
    }
  }
  
  EventHandler::~EventHandler()
  {
    theStaticContext = 0;
    theZorbaInstance->shutdown();
    StoreManager::shutdownStore(theStore);
  }
  
  void EventHandler::parseMessage(const std::string &aMessage)
  {
    try {
      zorba::String queryString = "local:main(";
      queryString += aMessage + ")";
      XQuery_t query = theZorbaInstance->compileQuery(queryString, theStaticContext);
      Iterator_t lIter = query->iterator();
      Item item;
      lIter->open();
      bool doContinue = false;
      lIter->next(item);
      {
        const std::string& continueString = item.getStringValue().str();
        if (continueString == "true") {
          doContinue = true;
        } else if (continueString == "false") {
          doContinue = false;
        } else {
          std::stringstream stream(continueString);
          stream >> doContinue;
        }
      }
      lIter->next(item);
      std::size_t lId;
      {
        std::stringstream stream(item.getStringValue().c_str());
        stream >> lId;
      }
      lIter->next(item);
      std::cout << item.getStringValue() << std::endl;
      theContinueProducer.produce(doContinue);
      theIdQueue.produce(lId);
    } catch (ZorbaException& e) {
      std::cerr << "FATAL: could not execute query: " << std::endl;
      std::cerr << e << std::endl;
      std::cerr << "This is a bug, please report to zorba-users@lists.sourceforge.net" << std::endl;
      theContinueProducer.produce(false);
    }
  }
  
  void EventHandler::error(unsigned int errcode, const std::string &msg)
  {
    std::cerr << "Error " << errcode << ": " << msg << std::endl;
  }
}}
