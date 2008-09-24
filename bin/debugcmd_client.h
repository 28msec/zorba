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
#include <zorba/debugger_client.h>
#include <zorba/debugger_default_event_handler.h>

using namespace zorba;

void suspend( int aSignum );

class CommandLineEventHandler: public DefaultDebuggerEventHandler
{
  private:
    static ZorbaDebuggerClient * theClient;

    std::string theFileName;

    std::auto_ptr<std::istream> &theQueryFile;

    std::auto_ptr<QueryLocation> theLocation;
    
    std::ostream &theOutput;
    
    std::istream &theInput;

    std::vector<std::string> get_args( const std::string& str );

    std::string get_expression( const std::vector<std::string> arr );
  
    void update_location();
    
    void handle_cmd();

    void help();

    void version();

    void listMore();

    void list();

    void list( unsigned int aLineNo );

    void list( unsigned int aBegin, unsigned int anEnd, bool listAll = false );

    void list( std::string &aFileName );

    void suspend( int aSignum );

    bool colors;
  public:
    CommandLineEventHandler( std::string aFileName,
                             std::auto_ptr<std::istream> &aQueryFile,
                             std::istream &anInput,
                             std::ostream &anOutput,
                             ZorbaDebuggerClient * aClient,
                             bool aColor = true);

    virtual ~CommandLineEventHandler(){}

    void started();

    void idle();

    void suspended( QueryLocation &aLocation, SuspendedBy aCause );

    void resumed();

    void terminated();

    void evaluated(String &anExpr, std::map<String, String> &aValuesAndTypes);
  
    void evaluated(String &anExpr, String &anError);

    static ZorbaDebuggerClient * getClient();
};
#endif
