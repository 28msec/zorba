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
#pragma once
#ifndef ZORBA_DEBUGGER_XQDB_CLIENT_H
#define ZORBA_DEBUGGER_XQDB_CLIENT_H

#include "command_prompt.h"
#include "command_line_handler.h"


namespace zorba { namespace debugger {

class XqdbClient {

  public:

    XqdbClient(unsigned int aPort);

    ~XqdbClient();

    void
    start();

  private:

    LockFreeQueue<std::size_t>* theIdQueue;
    LockFreeQueue<bool>*        theQuitQueue;

    EventHandler*       theEventHandler;
    CommandPrompt*      theCommandPrompt;
    CommandLineHandler* theCommandLineHandler;
};

  
} // namespace zorba
} // namespace debugger

#endif // ZORBA_DEBUGGER_XQDB_CLIENT_H
