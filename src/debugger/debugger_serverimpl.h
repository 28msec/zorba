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
#include <pthread.h>
#include <zorba/debugger_server.h>

#include "runtime/base/plan_iterator.h"
#include "debugger/debugger_common.h"
#include "runtime/debug/zorba_debugger_iterators.h"

namespace zorba{
/**
 * The debug protocol is defined in Gabriel's slides: "XQuery Debug in Practice"
 * @link https://fifthelement.inf.ethz.ch/trac/xqpeclipse/attachment/wiki/Documents/2008.01.22%20-%20XQuery%20Debug%20In%20Practice.ppt
 */
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

void * runQuery( void * aQuery );

/**
 * @
 */
class ZorbaDebuggerImpl: public ZorbaDebugger
{

  public:

    virtual ~ZorbaDebuggerImpl();

    void runQuery();
    
    ExecutionStatus getStatus() const { return theStatus; }

    const QueryLoc getLocation() const { return theLocation; }

    bool isEnabled() const;

    void start( void * aStore,
                std::istream * aQuery,
                const String & aFileName,
                unsigned short aRequestPort = 8000,
                unsigned short aEventPort = 9000 );

  protected:
    
    friend class ZorbaDebugger;
    friend class FnDebugIterator;

    ZorbaDebuggerImpl():
      theZorba(0),
      theDebugMode( false ),
      theRequestServerSocket(0), 
      theEventSocket(0), 
      theStatus( QUERY_IDLE  ),
      theFileName(""),
      thePlanState(0),
      theRuntimeThread(0){}

    Zorba* theZorba;

    bool theDebugMode;
    
    TCPServerSocket* theRequestServerSocket;

    TCPSocket* theEventSocket;

    unsigned short theEventPortno;

    ExecutionStatus theStatus;

    std::istream* theQuery;

    String theFileName;

    QueryLoc theLocation;

    PlanState * thePlanState;

    checked_vector<PlanIter_t>    theVariables;
    checked_vector<store::Item_t> theVariableNames;
    checked_vector<xqtref_t>      theVariableTypes;

    std::vector<QueryLoc> theBreakpoints;

    pthread_t theRuntimeThread;

    pthread_mutex_t theRuntimeMutex;
    
    pthread_cond_t theRuntimeSuspendedCV;

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

    xqpString fetchValue( const QueryLoc& loc, xqpString anExpr, PlanState& planState );
};
}//end of namespace xqp
#endif
