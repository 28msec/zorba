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

#ifndef XQP_ZORBA_DEBUGGER_CLIENT_IMPL_CLIENT_H
#define XQP_ZORBA_DEBUGGER_CLIENT_IMPL_CLIENT_H

#include <iostream>
#include <vector>

#include <boost/thread.hpp>

#include <zorba/api_shared_types.h>
#include <zorba/debugger_client.hpp>

#include "debugger/debugger_common.hpp"

namespace zorba{

  class AbstractMessage;
  class AbstractCommandMessage;
  class TCPSocket;
  class TCPServerSocket;

  class ZorbaDebuggerClientImpl: public ZorbaDebuggerClient
  {

    public:

      ZorbaDebuggerClientImpl( unsigned short aRequestPortno, unsigned short aEventPortno );

      virtual ~ZorbaDebuggerClientImpl();

      bool isQueryRunning() const;

      bool isQueryIdle() const;

      bool isQuerySuspended() const;

      bool isQueryTerminated() const;
      
      void run();

      void suspend();

      void resume();

      void terminate();

      void stepInto();

      void stepOut();

      void stepOver();

      void addBreakpoint( const String & aFileName, const unsigned int aLineNo );

      void clearBreakpoint( const String & aFileName, const unsigned int aLineNo );
    
    protected:
 
      TCPSocket * theRequestSocket;
      
      TCPServerSocket * theEventServerSocket;

      ExecutionStatus theExecutionStatus; 

      boost::thread theEventListener;

      void handshake();

      void listenEvents();

      void send( AbstractCommandMessage * aMessage );

      void send( std::string aMessage );
  };
}//end of namespace
#endif
