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

#include "xqdb_client.h"

#include <iostream>

#ifdef ZORBA_HAVE_PTHREAD_H
# include <cassert>
#endif


namespace zorba { namespace debugger {

XqdbClient::XqdbClient(unsigned int aPort)
{
  theIdQueue = new LockFreeQueue<std::size_t>();
  theQuitQueue = new LockFreeQueue<bool>();
  theEventHandler = new EventHandler(*theIdQueue, *theQuitQueue);
  theEventHandler->init();

  theCommandPrompt = new CommandPrompt();
  theCommandLineHandler = new CommandLineHandler(aPort, *theIdQueue, *theQuitQueue, theEventHandler, theCommandPrompt);
}

XqdbClient::~XqdbClient()
{
  if (theCommandLineHandler) {
    delete theCommandLineHandler;
  }
  if (theCommandPrompt) {
    delete theCommandPrompt;
  }
  if (theEventHandler) {
    delete theEventHandler;
  }

  delete theIdQueue;
  delete theQuitQueue;
}

void
XqdbClient::start()
{
  theCommandLineHandler->execute();
}


} // namespace zorba
} // namespace debugger
