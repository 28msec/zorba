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
#ifndef ZORBA_DEBUGGER_HANDLER_H
#define ZORBA_DEBUGGER_HANDLER_H

#include <vector>
#include <map>
#include <list>
#include <cassert>
#include <csignal>

#include <zorba/debugger_default_event_handler.h>

namespace zorba{

class Zorba;
class ZorbaDebuggerClient;

#ifdef SIGINT /* not all system have SIGINT */
void setDebugClient(ZorbaDebuggerClient* lClient);

void suspend(int aSignum);
#endif

class DebuggerHandler: public DefaultDebuggerEventHandler
{
  private:
    //the zorba instance
    Zorba* theZorba;

    //debugger client
    ZorbaDebuggerClient* theClient;
    
    //the filename of the main query
    std::string theFileName;

    //Split a string into an array using space as delimiter
    std::vector<std::string> getArgs(const std::string& str) const;
    
    //Concat arguments in order to get a full XQuery expression: e.g. 1 + 1
    std::string getExpression(const std::vector<std::string>& args) const;

    //Add a breakpoint
    void addBreakpoint(const std::vector<std::string>& args) const;

    //Add a watchpoint
    void addWatchpoint(const std::vector<std::string>& args) const;
   
    //Resume the query execution
    void resume() const;

    //Run the query
    void run() const;

    //Display the query execution status
    void status() const;

    //List module source code
    void list(const std::vector<std::string>& args) const;

    //List a query file
    void list(const zorba::String& aNamespace) const;

    //List a query file and highlight the current location
    void list(const zorba::QueryLocation& aLocation) const;

    //Clear a breakpoint
    void clear(const std::vector<std::string>& args);

    //Execution steps
    void stepIn() const;
    void stepOut() const;
    void stepOver() const;

    //List all scoped variables
    void variables() const;

    //Evaluate an expression
    void eval(const std::vector<std::string>& args);

    //Print the stack frame
    void where() const;

    //Display the help
    void help() const;

    //Deals with the input stream
    void handle();

    //Resolve the namespace
    std::istream* resolve(const String& aNamespace) const;
  
  public:
    DebuggerHandler(Zorba* aZorba, ZorbaDebuggerClient* aClient, std::string aFileName);
    
    virtual ~DebuggerHandler();
 
    void started();

    void idle();

    void suspended(zorba::QueryLocation &aLocation, zorba::SuspendedBy aCause);

    void resumed();

    void terminated();

    void evaluated(zorba::String &anExpr, std::map<zorba::String, zorba::String> &aValuesAndTypes);

    void evaluated(zorba::String &anExpr, zorba::String &anError);
};
}//end of namespace
#endif
