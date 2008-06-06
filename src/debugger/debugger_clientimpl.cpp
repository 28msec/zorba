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

#include "common/common.h"

#include <iostream>
#include <memory>

#include <boost/thread/thread.hpp>
#include <boost/bind.hpp> 

#include <zorba/api_shared_types.h>

#include "api/unmarshaller.h"
#include "zorbatypes/xqpstring.h"
#include "debugger/debugger_clientimpl.h"

#include "debugger/socket.h"
#include "debugger/debugger_protocol.h"
#include "debugger/message_factory.h"

namespace zorba{

  ZorbaDebuggerClientImpl::ZorbaDebuggerClientImpl( unsigned short aRequestPortno, unsigned short aEventPortno )
  :
    theRequestSocket(0), theEventServerSocket(0), theExecutionStatus( QUERY_IDLE ) 
  {
    //try
    //{ 
      //Start the Event Server Socket
      theEventServerSocket = new TCPServerSocket( aEventPortno );
      //Connect the Request Client Socket
      theRequestSocket = new TCPSocket( "127.0.0.1", aRequestPortno );
      //Perform the handshake with the server
      handshake();
      //Start the event listener thread
      boost::thread theEventListener (
        boost::bind( &ZorbaDebuggerClientImpl::listenEvents,  this ) );
    //} catch ( SocketException &e ) {
      //std::cerr << e.what() << std::endl;
      //std::cerr << "Host: localhost" << std::endl;
      //std::cerr << "Request port: " << aRequestPortno << std::endl;
      //std::cerr << "Event port: " << aEventPortno << std::endl;
    //}
    //delete theRequestSocket;
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
      throw MessageException( "Handshake failed" ); 
    }
  }

  void ZorbaDebuggerClientImpl::listenEvents()
  {
    TCPSocket * lSocket = theEventServerSocket->accept();
    
    while( ! isQueryTerminated() )
    { 
      AbstractMessage * lMessage = MessageFactory::buildMessage( lSocket );
      SuspendedEvent * lSuspendedMsg;
      if ( lSuspendedMsg = dynamic_cast< SuspendedEvent * > ( lMessage ) )
      {
        theExecutionStatus = QUERY_SUSPENDED;
      } else if ( dynamic_cast< StartedEvent * > ( lMessage ) ) {
        theExecutionStatus = QUERY_RUNNING;
      } else if ( dynamic_cast< ResumedEvent * > ( lMessage ) ) {
        theExecutionStatus = QUERY_RESUMED;
      } else if ( dynamic_cast< TerminatedEvent * > ( lMessage ) ) {
        theExecutionStatus = QUERY_TERMINATED;
      }
      delete lMessage;
    }
    //delete lSocket;
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
    Byte * lMessage = aMessage->serialize( length );
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
    RunMessage lMessage;
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::suspend()
  {
    SuspendMessage lMessage;
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::resume()
  {
    ResumeMessage lMessage;
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::terminate()
  {
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

  void ZorbaDebuggerClientImpl::addBreakpoint( const unsigned int aLineNo )
  {
    QueryLoc loc;
    loc.setLineBegin( aLineNo );
    
    SetMessage lMessage;
    lMessage.addLocation( loc );
    send( &lMessage );
  }
  
  String ZorbaDebuggerClientImpl::getFileName() const
  {
    return String( theRemoteFileName );
  }

  unsigned int ZorbaDebuggerClientImpl::getLineNo() const
  {
    return theRemoteLineNo;
  }
}//end of namespace
