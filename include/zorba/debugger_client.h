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
#ifndef ZORBA_DEBUGGER_CLIENT_H
#define ZORBA_DEBUGGER_CLIENT_H

#include <list>
#include <zorba/api_shared_types.h>
#include <zorba/debugger_event_handler.h>

namespace zorba{
  
  class ZORBA_EXTERN_DECL Variable
  {
    private:
      String theName;
      String theType;
    public:
      Variable( String &aName, String &aType ): theName(aName), theType(aType){}
      
      virtual ~Variable(){}

      String getName() const { return theName; }

      String getType() const { return theType; }
  };

  class ZORBA_EXTERN_DECL ZorbaDebuggerClient
  {

    public:

      virtual ~ZorbaDebuggerClient(){}

      static ZorbaDebuggerClient*
      createClient( unsigned short aRequestPortno, unsigned short aEventPortno );

      virtual void
      registerEventHandler( DebuggerEventHandler *aDebuggerEventHandler ) = 0;
      
      virtual bool
      isQueryRunning() const = 0;

      virtual bool
      isQueryIdle() const = 0;

      virtual bool
      isQuerySuspended() const = 0;

      virtual bool
      isQueryTerminated() const = 0;

      virtual void
      run() = 0;

      virtual void
      suspend() = 0;

      virtual void
      resume() = 0;

      virtual void
      terminate() = 0;

      virtual void
      quit() = 0;

      virtual void
      stepInto() = 0;

      virtual void
      stepOut() = 0;

      virtual void
      stepOver() = 0;

      virtual void
      addBreakpoint( const String &aFileName, const unsigned int aLineNo ) = 0;

      virtual void
      addBreakpoint( const unsigned int aLineNo ) = 0;

      virtual void
      addBreakpoint( const String &anExpr ) = 0;

      virtual void
      clearBreakpoint( const String &aFileName, const unsigned int aLineNo ) = 0;

      virtual void
      clearBreakpoints() = 0;

      virtual String
      getFileName() const = 0;

      virtual unsigned int
      getLineNo() const = 0;

      virtual void
      eval( String &anExpr ) = 0;

      virtual std::list<Variable>
      getAllVariables() = 0;

      virtual std::list<Variable>
      getLocalVariables() = 0;

      virtual std::list<Variable>
      getGlobalVariables() = 0;
  };
}//end of namespace
#endif
