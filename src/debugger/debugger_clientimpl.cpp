#include <iostream>
#include <memory>

#include <boost/thread/thread.hpp>
#include <boost/bind.hpp> 

#include "arpa/inet.h"

#include <zorba/api_shared_types.h>

#include "api/unmarshaller.h"
#include "zorbatypes/xqpstring.h"
#include "debugger/debugger_clientimpl.hpp"

#include "debugger/socket.hpp"
#include "debugger/debugger_protocol.hpp"
#include "debugger/message_factory.hpp"

namespace zorba{

  ZorbaDebuggerClientImpl::ZorbaDebuggerClientImpl( unsigned short aRequestPortno, unsigned short aEventPortno )
  :
    theRequestSocket(0), theEventServerSocket(0), theExecutionStatus( QUERY_IDLE ) 
  {
    try
    { 
      //Start the Event Server Socket
      theEventServerSocket = new TCPServerSocket( aEventPortno );
      //Connect the Request Client Socket
      theRequestSocket = new TCPSocket( "127.0.0.1", aRequestPortno );
      //Perform the handshake with the server
      handshake();
      //Start the event listener thread
      boost::thread theEventListener (
        boost::bind( &ZorbaDebuggerClientImpl::listenEvents,  this ) );
    } catch ( std::exception &e ) {
      std::cerr << e.what() << std::endl;
    }
  }

  ZorbaDebuggerClientImpl::~ZorbaDebuggerClientImpl()
  {
    delete theRequestSocket;
    delete theEventServerSocket;
  }

  void ZorbaDebuggerClientImpl::handshake()
  {
    bool result = false;
    char * msg = new char[ 12 ];
    memset(msg, '\0', 12);
    try
    {
      theRequestSocket->send( "XQHandshake", 11 );
      theRequestSocket->recv( msg, 11 );
      result = strcmp( msg, "XQHandshake" ) == 0; 
    } catch ( SocketException &e ) {
      std::cerr << e.what() << std::endl;
    }
    delete[] msg;
    if( !result )
    {
      std::cerr << "Received Handshake:" << msg << std::endl;
      throw MessageException( "Handshake failed" ); 
    } else {
      std::cerr << "Handshake is sucessful" << std::endl;
    }
  }

  void ZorbaDebuggerClientImpl::listenEvents()
  {
    TCPSocket * lSocket = theEventServerSocket->accept();
    
    while( ! isQueryTerminated() )
    { 
      AbstractMessage * lMessage = MessageFactory::buildMessage( lSocket );
      if ( dynamic_cast< SuspendedEvent * > ( lMessage ) )
      {
        theExecutionStatus = QUERY_SUSPENDED;
      } else if ( dynamic_cast< StartedEvent * > ( lMessage ) ) {
        theExecutionStatus = QUERY_RUNNING;
      } else if ( dynamic_cast< ResumedEvent * > ( lMessage ) ) {
        theExecutionStatus = QUERY_RESUMED;
      } else if ( dynamic_cast< TerminatedEvent * > ( lMessage ) ) {
        theExecutionStatus = QUERY_TERMINATED;
      } else {
        std::cerr << "Received an invalid event" << std::endl;
      }
      delete lMessage;
    }
    delete lSocket;
  }

  bool ZorbaDebuggerClientImpl::isQueryRunning() const
  {
    return theExecutionStatus == QUERY_RUNNING;
  }

  bool ZorbaDebuggerClientImpl::isQueryIdle() const
  {
    return theExecutionStatus == QUERY_IDLE;
  }

  bool ZorbaDebuggerClientImpl::isQuerySuspended() const
  {
    return theExecutionStatus == QUERY_SUSPENDED;
  }

  bool ZorbaDebuggerClientImpl::isQueryTerminated() const
  {
    return theExecutionStatus == QUERY_TERMINATED;
  }
 
  void ZorbaDebuggerClientImpl::send( AbstractCommandMessage * aMessage )
  {
    //Connect the client
    Length length;
    Byte * lMessage = aMessage->serialize( length);
    try
    {
      theRequestSocket->send( lMessage, length );
    } catch( SocketException &e ) {
      std::cerr << "Request client:" << e.what() << std::endl;
    }
    delete[] lMessage;
  }

  void ZorbaDebuggerClientImpl::run()
  {
#ifndef NDEBUG
    std::cerr << "Send a run message" << std::endl;
#endif
    RunMessage lMessage;
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::suspend()
  {
#ifndef NDEBUG
    std::cerr << "Send a suspend message" << std::endl;
#endif
    SuspendMessage lMessage;
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::resume()
  {
#ifndef NDEBUG
    std::cerr << "Send a resume message" << std::endl;
#endif
    ResumeMessage lMessage;
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::terminate()
  {
#ifndef NDEBUG
    std::cerr << "Send a terminate message" << std::endl;
#endif
    TerminateMessage lMessage;
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::stepInto()
  {
    StepMessage lMessage( STEP_INTO );
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::stepOver()
  {
    StepMessage lMessage( STEP_OVER );
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::stepOut()
  {
    StepMessage lMessage( STEP_OUT );
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::addBreakpoint( const String & aFileName, const unsigned int aLineNo )
  {
    xqpString lFilename = Unmarshaller::getInternalString( aFileName );
    QueryLoc loc;
    std::string lTmp(lFilename);
    loc.setFilenameBegin( &lTmp );
    loc.setLineBegin( aLineNo );
    
    SetMessage lMessage;
    lMessage.addLocation( loc );
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::clearBreakpoint( const String & aFileName, const unsigned int aLineNo )
  {
    xqpString lFilename = Unmarshaller::getInternalString( aFileName );
    QueryLoc loc;
    std::string lTmp(lFilename);
    loc.setFilenameBegin( &lTmp );
    loc.setLineBegin( aLineNo );
    
    SetMessage lMessage;
    lMessage.addLocation( loc );
    send( &lMessage );
  }
}//end of namespace
