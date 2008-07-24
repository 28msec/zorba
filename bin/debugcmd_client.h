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
#include <vector>
#include <string>
#include <memory>
#include <simplestore/simplestore.h>
#include <zorba/zorba.h>
#include <zorba/debugger_client.h>
#include <zorba/debugger_event_handler.h>

using namespace zorba;

void suspend( int aSignum );

class CommandLineEventHandler: public DebuggerEventHandler
{
  private:
    simplestore::SimpleStore *theStore;

    Zorba *theZorba;

    static ZorbaDebuggerClient * theClient;
    
    std::auto_ptr<std::istream> &theQueryFile;
    
    std::ostream &theOutput;
    
    std::istream &theInput;

    std::vector<std::string> theHistory;

    std::vector<std::string> get_args( const std::string& str );
   
    void handle_cmd();

    void handle_cmd( std::string aCommand );

    void handle_cmd( unsigned int aCommandNo );
        
    void help();

    void history();

    void version();

    void listMore();

    void list();

    void list( unsigned int aLineNo );

    void list( unsigned int aBegin, unsigned int anEnd, bool listAll = false );

    void suspend( int aSignum );

  public:
    CommandLineEventHandler( std::auto_ptr<std::istream> &aQueryFile,
                             std::istream &anInput,
                             std::ostream &anOutput,
                             ZorbaDebuggerClient * aClient );

    virtual ~CommandLineEventHandler()
    {
      theZorba->shutdown();
      simplestore::SimpleStoreManager::shutdownStore( theStore );
    }

    static ZorbaDebuggerClient * getClient();

    //debugger events
    void started();

    void idle();

    void suspended( zorba::QueryLocation & aLocation, zorba::SuspendedBy aCause );

    void resumed();

    void terminated();

    void evaluated( String &anExpr, String &aResult );
};
#endif
