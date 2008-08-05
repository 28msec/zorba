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

#ifndef ZORBA_DEBUGGER_IMPL_H
#define ZORBA_DEBUGGER_IMPL_H

#include <iostream>
#include <memory>
#include <string>
#include <map>

#include "api/xqueryimpl.h"

#include "debugger/debugger_common.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/debug/zorba_debugger_iterators.h"

#include "zorbautils/thread.h"

namespace zorba{

class TCPSocket;
class TCPServerSocket;
class ZorbaDebuggerCommandMessage;
class ZorbaDebuggerReplyMessage;
class AbstractMessage;
class AbstractCommandMessage;
class RunExecutionMessage;
class SuspendExecutionMessage;
class ResumeExecutionMessage;
class TerminateExecutionMessage;
class StepExecutionMessage;

ZORBA_THREAD_RETURN runQuery( void *aQuery );

/**
 * @
 */
class ZorbaDebugger
{
  public:
    ZorbaDebugger():
      theQuery(0),
      theRequestServerSocket(0), 
      theEventSocket(0), 
      theStatus( QUERY_IDLE  ),
      thePlanState(0),
      theRuntimeThread(0){}

    virtual ~ZorbaDebugger();

    void runQuery();
    
    ExecutionStatus getStatus() const { return theStatus; }

    const QueryLoc getLocation() const { return theLocation; }

    void start( XQueryImpl *aQuery,
                unsigned short aRequestPort = 8000,
                unsigned short aEventPort = 9000 );

  protected:
    friend class FnDebugIterator;
   
    XQueryImpl *theQuery;

    TCPServerSocket* theRequestServerSocket;

    TCPSocket* theEventSocket;

    //The event port number
    unsigned short theEventPortno;

    //The execution status
    ExecutionStatus theStatus;

    //Last known location of the query
    QueryLoc theLocation;

    //The following attributes are used for the eval function
    PlanState * thePlanState;
    
    checked_vector<store::Item_t>  theVarnames;
    checked_vector<std::string>    theVarkeys;
    checked_vector<xqtref_t>       theVartypes;
    checked_vector<PlanIter_t>     theChildren;
    checked_vector<global_binding> theGlobals;

    //Map of breakpoints and watchpoints
    std::map<unsigned int, QueryLoc> theBreakpoints;
    std::map<unsigned int, xqpString> theWatchpoints;

    //The runtime thread
    Thread * theRuntimeThread;

    bool hasToSuspend();
    
    void setStatus( ExecutionStatus aStatus, SuspensionCause aCause = CAUSE_USER );

    void run();

    void handleTcpClient( TCPSocket * aSock );

    void handshake( TCPSocket * aSock );

    void processMessage( AbstractCommandMessage * );

    void suspend();

    void resume();

    void terminate();

    void quit();

    void sendEvent( AbstractCommandMessage * aMessage );

    void startedEvent();

    void suspendedEvent( QueryLoc &aLocation, SuspensionCause aCause );

    void resumedEvent();

    void terminatedEvent();

    void addBreakpoint( String & aFileName, unsigned int aLineNo );

    void clearBreakpoint( String & aFileName, unsigned int aLineNo );

    void eval( xqpString anExpr );

    store::Item_t
    fetchItem( const QueryLoc& loc, xqpString anExpr,
                PlanState& planState, xqpString * anError);
    
    xqpString
    fetchValue( const QueryLoc& loc, xqpString anExpr,
                PlanState& planState, xqpString * anError);

};
}//end of namespace xqp
#endif
