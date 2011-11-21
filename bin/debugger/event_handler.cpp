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

#include "event_handler.h"

#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/iterator.h>

namespace zorba { namespace debugger {
  
EventHandler::EventHandler(LockFreeProducer<std::size_t>& aQueue, LockFreeProducer<bool>& aContProducer)
  : theIdQueue(aQueue), theContinueProducer(aContProducer),
    theStore(StoreManager::getStore()),
    theZorbaInstance(Zorba::getInstance(theStore)),
    theStaticContext(theZorbaInstance->createStaticContext())
{
}

EventHandler::~EventHandler()
{
  theStaticContext = 0;
  theZorbaInstance->shutdown();
  StoreManager::shutdownStore(theStore);
}

void
EventHandler::init()
{
  try {
    Zorba_CompilerHints_t lHints;
    lHints.opt_level = ZORBA_OPT_LEVEL_O1;
    zorba::String lProlog("import module namespace dmh = 'http://www.zorba-xquery.com/modules/debugger/dbgp-message-handler';");
    theStaticContext->loadProlog(lProlog, lHints);
  } catch (zorba::ZorbaException& e) {
    std::cerr << "Exception: I was not able to load the query file:" << std::endl;
    std::cerr << e.what() << std::endl;
    throw;
  }
}

void
EventHandler::parseMessage(const std::string &aMessage)
{
  try {
#ifndef NDEBUG
    std::cout << "Processing response: " << aMessage << std::endl;
#endif
    // the query to process the response
    std::stringstream lQueryStream;
    lQueryStream << "dmh:process(" << aMessage << ")";
    XQuery_t lQuery = theZorbaInstance->compileQuery(lQueryStream.str(), theStaticContext);

    // get the query result sequrence:
    //   1. transaction id
    Iterator_t lIter = lQuery->iterator();
    Item lItem;
    lIter->open();
    lIter->next(lItem);
    std::size_t lId;
    std::stringstream lStream(lItem.getStringValue().c_str());
    lStream >> lId;

    //   2. A message
    bool lCanQuit = false;
    if (lIter->next(lItem)) {
      String lMessage = lItem.getStringValue();
      lCanQuit = lMessage == "stopping";
      std::cout << lItem.getStringValue() << std::endl;
    }

    // go and solve the event with this id
    theContinueProducer.produce(lCanQuit);
    theIdQueue.produce(lId);
  } catch (ZorbaException& e) {
    std::cerr << "FATAL: could not execute query: " << std::endl;
    std::cerr << e << std::endl;
    std::cerr << "This is a bug, please report to zorba-users@lists.sourceforge.net" << std::endl;
    //theContinueProducer.produce(false);
  }
}
  
void
EventHandler::error(unsigned int errcode, const std::string &msg)
{
  std::cerr << "Error " << errcode << ": " << msg << std::endl;
}

} // namespace zorba
} // namespace debugger
