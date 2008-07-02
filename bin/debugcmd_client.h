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
#ifndef DEBUGCMD_CLIENT_H
#define DEBUGCMD_CLIEND_H

#include <iostream>
#include <boost/thread/thread.hpp>
#include <zorba/debugger_client.h>
#include <zorba/debugger_event_handler.h>

using namespace zorba;

class CommandLineEventHandler: public DebuggerEventHandler
{
  private:
    std::ostream & theOutput;
    
    std::istream & theInput;
    
    ZorbaDebuggerClient * theClient;

    std::vector<std::string> get_args( const std::string& str );
    
    void handle_cmd();

    void help();

  public:
    CommandLineEventHandler( std::istream & anInput,
                             std::ostream & anOutput,
                             ZorbaDebuggerClient * aClient );

    virtual ~CommandLineEventHandler(){}

    //debugger events
    void started();

    void idle();

    void suspended( zorba::QueryLocation & aLocation, zorba::SuspendedBy aCause );

    void resumed();

    void terminated();
};
#endif
