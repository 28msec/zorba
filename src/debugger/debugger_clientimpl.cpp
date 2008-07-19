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


#include "debugger/debugger_clientimpl.h"

#include <iostream>
#include <memory>

#include <zorba/api_shared_types.h>

#include "common/common.h"
#include "api/unmarshaller.h"
#include "zorbatypes/xqpstring.h"
#include "debugger/query_locationimpl.h"
#include "debugger/socket.h"
#include "debugger/debugger_protocol.h"
#include "debugger/message_factory.h"

namespace zorba{

  ZorbaDebuggerClientImpl::ZorbaDebuggerClientImpl( unsigned short aRequestPortno, unsigned short aEventPortno )
  :
    theEventHandler(0), 
    theRequestSocket( new TCPSocket( "127.0.0.1", aRequestPortno ) ),
    theEventServerSocket( new TCPServerSocket( aEventPortno ) ),
    theExecutionStatus( QUERY_IDLE ),
    theEventListener(0)	
  {
    //Perform the handshake with the server
    handshake();
    //Start the event listener thread
#ifdef ZORBA_HAVE_PTHREAD_H
    if ( pthread_create( &theEventListener, 0, listenEvents, this ) != 0 )
#else
    if ( (theEventListener = CreateThread( 0, 0, listenEvents, this, 0, 0 ) ) == 0 )
#endif
    {
      std::cerr << "Couldn't start the event listener thread" << std::endl;
    }
  }

  ZorbaDebuggerClientImpl::~ZorbaDebuggerClientImpl()
  {
    //TODO: shouldn't join but terminate and clean the listener thread
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_join( theEventListener, 0 );
#else
    WaitForSingleObject( theEventListener, INFINITE );
    CloseHandle( theEventListener );
#endif
    delete theRequestSocket;
    delete theEventServerSocket;
  }

  void ZorbaDebuggerClientImpl::registerEventHandler( DebuggerEventHandler * anEventHandler )
  {
    theEventHandler = anEventHandler;
    //Special case for event handler initialization
    if ( theEventHandler != 0 && theExecutionStatus == QUERY_IDLE )
    {
      theEventHandler->idle();
    }
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
#ifdef ZORBA_HAVE_PTHREAD_H
  void * listenEvents( void * aClient )
#else
  DWORD WINAPI listenEvents( LPVOID aClient )
#endif
  {
#ifdef ZORBA_HAVE_PTHREAD_H
    //TODO: to remove
    pthread_detach( pthread_self() );
#endif
    ZorbaDebuggerClientImpl * lClient = (ZorbaDebuggerClientImpl *) aClient;
#ifndef NDEBUG
    std::clog << "[Client Thread] start event listener thread" << std::endl;
    std::clog << "[Client Thread] wait for the event client to connect" << std::endl;
#endif

    TCPSocket * lSocket = lClient->theEventServerSocket->accept();
    
    while( lClient->theExecutionStatus != QUERY_QUITED )
    { 
      AbstractMessage *lMessage = MessageFactory::buildMessage( lSocket );
      SuspendedEvent  *lSuspendedMsg;
      EvaluatedEvent  *lEvaluatedEvent;
      if ( ( lSuspendedMsg = dynamic_cast< SuspendedEvent * > ( lMessage ) ) )
      {
#ifndef NDEBUG
        std::clog << "[Client Thread] received a suspended event" << std::endl;
#endif
        lClient->theExecutionStatus = QUERY_SUSPENDED;
        lClient->theRemoteLineNo    = lSuspendedMsg->getLocation().getLineno();
        lClient->theRemoteFileName  = lSuspendedMsg->getLocation().getFilename();
        if ( lClient->theEventHandler )
        {
          QueryLocationImpl loc( lSuspendedMsg->getLocation() );
          lClient->theEventHandler->suspended( loc, (SuspendedBy)lSuspendedMsg->getCause() );
        }
      } else if ( dynamic_cast< StartedEvent * > ( lMessage ) ) {
#ifndef NDEBUG
        std::clog << "[Client Thread] receive a started event" << std::endl;
#endif
        lClient->theExecutionStatus = QUERY_RUNNING;
        if ( lClient->theEventHandler )
        {
          lClient->theEventHandler->started();
        }
      } else if ( dynamic_cast< ResumedEvent * > ( lMessage ) ) {
#ifndef NDEBUG
        std::clog << "[Client Thread] receive a resumed event" << std::endl;
#endif
        lClient->theExecutionStatus = QUERY_RESUMED;
        if ( lClient->theEventHandler )
        {
          lClient->theEventHandler->resumed();
        }
      } else if ( dynamic_cast< TerminatedEvent * > ( lMessage ) ) {
#ifndef NDEBUG
        std::clog << "[Client Thread] receive a suspended event" << std::endl;
#endif
        if( lClient->theExecutionStatus != QUERY_IDLE )
        {
          lClient->theExecutionStatus = QUERY_TERMINATED;
          if ( lClient->theEventHandler )
          {
            lClient->theEventHandler->terminated();
          }
        }
      } else if ( (lEvaluatedEvent = dynamic_cast< EvaluatedEvent * >(lMessage))) {
#ifndef NDEBUG
        std::clog << "[Client Thread] evaluated expression" << std::endl;
#endif
        if ( lClient->theEventHandler )
        {
          String lExpr( lEvaluatedEvent->getExpr() );
          String lResult( lEvaluatedEvent->getResult() );
          lClient->theEventHandler->evaluated( lExpr, lResult );
        }
      }
      delete lMessage;
    }
    delete lSocket;
#ifndef NDEBUG
    std::clog << "[Client Thread] end of the event listener thread" << std::endl;
#endif
    return 0;
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
      //send the command
      theRequestSocket->send( lMessage, length );
      //check the reply
      AbstractMessage * lMsg = MessageFactory::buildMessage( theRequestSocket );
      ReplyMessage * lReplyMessage = dynamic_cast< ReplyMessage * >( lMsg );
      if ( lReplyMessage )
      {
        if( ! lReplyMessage->isOk() )
        {
          std::cerr << "Error occured: " << lReplyMessage->getMessage() << std::endl;
        }
        delete lReplyMessage;
      } else {
      //TODO: print the error message.
        std::cerr << "Internal error occured" << std::endl;
      }
      //delete[] lMsg;
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

  void ZorbaDebuggerClientImpl::quit()
  {
    QuitMessage lMessage;
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
    
    ClearMessage lMessage;
    lMessage.addLocation( loc );
    send( &lMessage );
  }

  void ZorbaDebuggerClientImpl::clearBreakpoints()
  {
     ClearMessage lMessage;
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


  void ZorbaDebuggerClientImpl::eval( String &anExpr )
  {
    xqpString lExpr = Unmarshaller::getInternalString( anExpr );
    //TODO: espace double quotes characters
    EvalMessage lMessage( lExpr );
    send( &lMessage );
  }
}//end of namespace
