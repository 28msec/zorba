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

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>

#include <zorba/debugger_server.h>

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

    ZorbaDebuggerImpl():
      theZorba(0),
      theDebugMode( false ),
      theRequestServerSocket(0), 
      theEventSocket(0), 
      theStatus( QUERY_IDLE  ),
      theFileName(""),
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

    std::vector<QueryLoc> theBreakpoints;

    boost::thread* theRuntimeThread;

    boost::mutex theRuntimeMutex;
    
    boost::condition theRuntimeSuspendedCV;

    friend bool FnDebugIterator::nextImpl( store::Item_t& result, PlanState &  planState ) const;

    friend FnDebugIterator::FnDebugIterator( const QueryLoc& loc,
                                             std::vector<PlanIter_t>& args,
                                             const static_context * aStaticContext );

    bool hasToSuspend();
    
    void setStatus( ExecutionStatus aStatus, SuspensionCause aCause = CAUSE_USER );

    void run();

    void handleTcpClient( TCPSocket * aSock );

    void handshake( TCPSocket * aSock );

    void processMessage( AbstractCommandMessage * );

    void runQuery();

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

    //void processMessage( StepExecutionMessage * );

    //void executeQuery( std::string aQuery );

/*    ZorbaDebuggerReplyPacket processCommand( const ZorbaDebuggerCommandPacket aPacket );
Select: All, None, Read, Unread, Starred, 
    ZorbaDebuggerReplyPacket processExecutionCommand( const ZorbaDebuggerCommandPacket aPacket );

    ZorbaDebuggerReplyPacket processBreakpointCommand( const ZorbaDebuggerCommandPacket aPacket );

    ZorbaDebuggerReplyPacket processStaticCommand( const ZorbaDebuggerCommandPacket aPacket );

    ZorbaDebuggerReplyPacket processDynamicCommand( const ZorbaDebuggerCommandPacket aPacket );

    int step( int type );*/

};
}//end of namespace xqp
#endif
