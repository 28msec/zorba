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
#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#else
#include <windows.h>
#endif

#include <zorba/api_shared_types.h>
#include <zorba/debugger_client.h>

#include "debugger/debugger_common.h"

namespace zorba{

  class AbstractMessage;
  class AbstractCommandMessage;
  class TCPSocket;
  class TCPServerSocket;

#ifdef ZORBA_HAVE_PTHREAD_H
  void * listenEvents( void * aClient );
#else
  DWORD WINAPI listenEvents( LPVOID aClient );
#endif

  class ZorbaDebuggerClientImpl: public ZorbaDebuggerClient
  {
    friend
#ifdef ZORBA_HAVE_PTHREAD_H
  void * listenEvents( void * aClient );
#else
  DWORD WINAPI listenEvents( LPVOID aClient );
#endif

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

      void addBreakpoint( const String & aFileName, const unsigned int aLineNo );

      void addBreakpoint( const unsigned int aLineNo );
      
      void clearBreakpoint( const String & aFileName, const unsigned int aLineNo );

      void clearBreakpoints();
      
      String getFileName() const;

      unsigned int getLineNo() const;

      void eval( String &anExpr );

    protected:

      DebuggerEventHandler * theEventHandler;

      std::string theRemoteFileName;

      unsigned int theRemoteLineNo;

      TCPSocket * theRequestSocket;
      
      TCPServerSocket * theEventServerSocket;

      ExecutionStatus theExecutionStatus; 

#ifdef ZORBA_HAVE_PTHREAD_H
      pthread_t theEventListener;
#else
      HANDLE theEventListener;
#endif

      void handshake();

      void send( AbstractCommandMessage * aMessage );

      void send( std::string aMessage );
  };
}//end of namespace
#endif
