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
#ifndef ZORBA_DEBUGGER_EVENT_HANDLER_H
#define ZORBA_DEBUGGER_EVENT_HANDLER_H

#include <zorba/zorbastring.h>

namespace zorba{

  /* Cause of the suspension of the engine */
  enum SuspendedBy { A_USER, A_BREAKPOINT, A_STEP }; 

  class ZORBA_EXTERN_DECL QueryLocation
  {
    public:

      virtual
      ~QueryLocation(){}

      virtual String
      getFileName() const = 0; 

      virtual unsigned int
      getLineBegin() const = 0;

      virtual unsigned int
      getLineEnd() const = 0;

      virtual unsigned int
      getColumnBegin() const = 0;

      virtual unsigned int
      getColumnEnd() const = 0;
  };

  class ZORBA_EXTERN_DECL DebuggerEventHandler
  {
    public:

      virtual
      ~DebuggerEventHandler(){}

      virtual void
      started() = 0;

      virtual void
      idle() = 0;

      virtual void
      suspended( QueryLocation &aLocation, SuspendedBy aCause ) = 0;

      virtual void
      resumed() = 0;

      virtual void
      terminated() = 0;

      virtual void
      evaluated(String &anExpr, String &aResult, String &aReturnType, String &anError) = 0;
  };
}//end of namespace
#endif
