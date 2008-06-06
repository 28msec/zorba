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
#ifndef XQP_ZORBA_DEBUGGER_CLIENT_H
#define XQP_ZORBA_DEBUGGER_CLIENT_H

#include <zorba/api_shared_types.h>

namespace zorba{

  class ZorbaDebuggerClient{

    public:

      virtual ~ZorbaDebuggerClient(){}

      static ZorbaDebuggerClient *
      createClient( unsigned short aRequestPortno, unsigned short aEventPortno );

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
      stepInto() = 0;

      virtual void
      stepOut() = 0;

      virtual void
      stepOver() = 0;

      virtual void
      addBreakpoint( const String & aFileName, const unsigned int aLineNo ) = 0;

      virtual void
      addBreakpoint( const unsigned int aLineNo ) = 0;

      virtual void
      clearBreakpoint( const String & aFileName, const unsigned int aLineNo ) = 0;

      virtual String
      getFileName() const = 0;

      virtual unsigned int
      getLineNo() const = 0;
  };


}//end of namespace
#endif
