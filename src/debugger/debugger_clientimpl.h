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

#ifndef ZORBA_DEBUGGER_CLIENT_IMPL_CLIENT_H
#define ZORBA_DEBUGGER_CLIENT_IMPL_CLIENT_H

#include <iostream>
#include <vector>
#include <zorba/api_shared_types.h>
#include <zorba/debugger_client.h>

#include "zorbautils/thread.h"

#include "zorbatypes/xqpstring.h"

#include "debugger/debugger_common.h"
#include "debugger/debugger_protocol.h"

namespace zorba{

  class AbstractMessage;
  class AbstractCommandMessage;
  class TCPSocket;
  class TCPServerSocket;

  THREAD_RETURN_TYPE listenEvents( void * aClient );

  class ZorbaDebuggerClientImpl: public ZorbaDebuggerClient
  {
    friend
    THREAD_RETURN_TYPE listenEvents( void * aClient );

    public:
      ZorbaDebuggerClientImpl( unsigned short aRequestPortno, unsigned short aEventPortno );

      virtual ~ZorbaDebuggerClientImpl();

      void registerEventHandler( DebuggerEventHandler * anEventHandler );
      
      bool isQueryRunning() const;

      bool isQueryIdle() const;

      bool isQuerySuspended() const;

      bool isQueryTerminated() const;
      
      void run();

      void suspend();

      void resume();

      void terminate();

      void quit();

      void stepInto();

      void stepOut();

      void stepOver();

      void addBreakpoint( const String &anExpr );

      void addBreakpoint( const String &aFileName, const unsigned int aLineNo );

      void addBreakpoint( const unsigned int aLineNo );
      
      void clearBreakpoint( const String &aFileName, const unsigned int aLineNo );

      void clearBreakpoints();
      
      String getFileName() const;

      unsigned int getLineNo() const;

      void eval( String &anExpr );

      std::list<Variable> getAllVariables();
      
      std::list<Variable> getLocalVariables();
      
      std::list<Variable> getGlobalVariables();
    
    protected:

      DebuggerEventHandler * theEventHandler;

      std::string theRemoteFileName;

      unsigned int theRemoteLineNo;

      TCPSocket * theRequestSocket;
      
      TCPServerSocket * theEventServerSocket;

      ExecutionStatus theExecutionStatus; 

      Thread *theEventListener;

      void handshake();

      ReplyMessage* send( AbstractCommandMessage * aMessage );

      void send( std::string aMessage );

      std::list<Variable> parseLocalVariables( xqpString aJSON );
      
      std::list<Variable> parseGlobalVariables( xqpString aJSON );
  };
}//end of namespace
#endif
