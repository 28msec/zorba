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
#include <utility>
#include <list>
#include <map>
#include <list>
#include <cassert>
#include <csignal>

#include <zorba/debugger_default_event_handler.h>

namespace zorba{

class Zorba;
class DebuggerClient;

#ifdef SIGINT /* not all system have SIGINT */
void setDebugClient(DebuggerClient* lClient);

void suspend(int aSignum);
#endif

class DebuggerHandler: public DefaultDebuggerEventHandler
{
  private:
    //the zorba instance
    Zorba* theZorba;

    //debugger client
    DebuggerClient* theClient;
    
    //the filename of the main query
    std::string theFileName;

    bool theInterrupt;

    //Split a string into an array using space as delimiter
    std::vector<std::string> getArgs(const std::string& str) const;
    
    //Concat arguments in order to get a full XQuery expression: e.g. 1 + 1
    std::string getExpression(const std::vector<std::string>& args) const;

    //Add a breakpoint
    bool addBreakpoint(const std::vector<std::string>& args) const;

    //Add a watchpoint
    bool addWatchpoint(const std::vector<std::string>& args) const;
   
    //Resume the query execution
    bool resume() const;

    //Run the query
    bool run() const;

    // Terminate the query
    bool terminateQuery() const;

    //Display the query execution status
    bool status() const;

    //List module source code
    bool list(const std::vector<std::string>& args) const;

    //List a query file
    bool list(const zorba::String& aNamespace) const;

    //List the query file arround the current location (+/- 5 lines)
    bool list(const zorba::QueryLocation& aLocation) const;

    //List the query file arround the current location (+/- 5 lines)
    bool list(const zorba::QueryLocation& aLocation, int aLines) const;

    // Try to parse the string value as an integer
    bool
    readInteger(const std::string& stringValue, int& result) const;

    bool
    canStep() const;

    //Clear a breakpoint
    bool clear(const std::vector<std::string>& args);

    //Execution steps
    bool stepIn() const;
    bool stepOut() const;
    bool stepOver() const;

    //List all scoped variables
    bool variables() const;

    //Evaluate an expression
    bool eval(const std::vector<std::string>& args);

    //Print the stack frame
    bool where() const;

    //Display the help
    bool help(const std::vector<std::string>& aArgs) const;
    void printDefaultHelp() const;

    //Deals with the input stream
    void handle();

    //Get the source code corresponding to the given namespace
    std::istream* getSource(const String& aNamespace) const;

  public:
    DebuggerHandler(Zorba* aZorba, DebuggerClient* aClient, std::string aFileName);
    
    virtual ~DebuggerHandler();

    /**
    * @brief Sends a suspend request to the server
    *
    * This function is public, so that it can be used by the signal
    * handler.
    */
    void suspend();
  
 
    void started();

    void idle();

    void suspended(zorba::QueryLocation &aLocation, zorba::SuspendedBy aCause);

    void resumed();

    void terminated();

    void evaluated(zorba::String &anExpr, std::list< std::pair<zorba::String, zorba::String> > &aValuesAndTypes);

    void evaluated(zorba::String &anExpr, zorba::String &anError);
};
}//end of namespace
#endif
