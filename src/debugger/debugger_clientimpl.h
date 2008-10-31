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

  ZORBA_THREAD_RETURN listenEvents( void * aClient );

  class ZorbaDebuggerClientImpl: public ZorbaDebuggerClient
  {
    friend
    ZORBA_THREAD_RETURN listenEvents( void * aClient );

    public:
      ZorbaDebuggerClientImpl(std::string aServerAddress = "127.0.0.1",
                              unsigned short aRequestPortno = 8000,
                              unsigned short aEventPortno = 9000);

      virtual ~ZorbaDebuggerClientImpl();

      ZorbaDebuggerClient* registerEventHandler( DebuggerEventHandler * anEventHandler );
      
      bool isQueryRunning() const;

      bool isQueryIdle() const;

      bool isQuerySuspended() const;

      bool isQueryTerminated() const;
      
      bool run();

      bool suspend();

      bool resume();

      bool terminate();

      bool stepInto();

      bool stepOut();

      bool stepOver();

      bool addBreakpoint( const String &anExpr );

      QueryLocation* addBreakpoint( const String &aFileName, const unsigned int aLineNo );

      QueryLocation* addBreakpoint( const unsigned int aLineNo );

      std::map<unsigned int, String> getBreakpoints() const;

      bool clearBreakpoint( unsigned int anId );

      bool clearBreakpoints( std::list<unsigned int> &Ids );

      bool clearBreakpoints();
      
      QueryLocation *getLocation() const;

      bool eval( String &anExpr ) const;

      std::list<Variable> getAllVariables() const;
      
      std::list<Variable> getLocalVariables() const;
      
      std::list<Variable> getGlobalVariables() const;
    
      StackFrame* getStack() const;
    
    protected:
      static unsigned int theLastId;

      DebuggerEventHandler * theEventHandler;

      QueryLoc theRemoteLocation;

      TCPSocket * theRequestSocket;
      
      TCPServerSocket * theEventServerSocket;

      ExecutionStatus theExecutionStatus; 

      Thread *theEventListener;

      std::map<unsigned int, String> theBreakpoints;

      QueryLocation* addBreakpoint(QueryLoc& aLocation);

      bool handshake();

      ReplyMessage* send( AbstractCommandMessage * aMessage ) const;

      void send( std::string aMessage ) const;
  };
}//end of namespace
#endif
