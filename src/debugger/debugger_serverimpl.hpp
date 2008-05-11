#ifndef XQP_ZORBA_DEBUGGER_IMPL_H
#define XQP_ZORBA_DEBUGGER_IMPL_H

#include <iostream>

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>

#include <zorba/zorba.h>
#include <zorba/debugger_server.hpp>

#include "debugger/debugger_common.hpp"
#include "runtime/debug/zorba_debugger_iterators.hpp"

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

    void start( std::istream * aQuery, const String & aFileName, unsigned short aRequestPort = 8000,
      unsigned short aEventPort = 9000 );

  protected:
    
    friend class ZorbaDebugger;

    ZorbaDebuggerImpl()
    :
    theDebugMode(true),
    theRequestServerSocket(0), 
    theEventSocket(0), 
    theStatus( QUERY_IDLE  ),
    theFileName("")
    {}
    
    bool theDebugMode;
    
    TCPServerSocket * theRequestServerSocket;

    TCPSocket * theEventSocket;

    unsigned short theEventPortno;

    ExecutionStatus theStatus;

    std::istream * theQuery;

    String theFileName;

    QueryLoc theLocation;

    std::vector<QueryLoc> theBreakpoints;

    boost::thread theRuntimeThread;

    boost::mutex theRuntimeMutex;
    
    boost::condition theRuntimeSuspendedCV;

    friend store::Item_t FnDebugIterator::nextImpl( PlanState &  planState ) const;

    friend FnDebugIterator::FnDebugIterator( const QueryLoc& loc, std::vector<PlanIter_t>& args );

    bool hasToSuspend();
    
    void setStatus( ExecutionStatus aStatus, SuspensionCause aCause = CAUSE_USER );

    void run( std::istream * aQuery );

    void handleTcpClient( TCPSocket * aSock );

    void handshake( TCPSocket * aSock );

    void processMessage( AbstractCommandMessage * );

    void run();

    void suspend();

    void resume();

    void terminate();

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
