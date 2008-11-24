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

#include <list>
#include <utility>

#include <zorba/zorbastring.h>


namespace zorba{

  class QueryLocation;

  /* Cause of the suspension of the engine */
  enum SuspendedBy { A_USER, A_BREAKPOINT, A_STEP }; 
  
  /**
   * DebuggerEventHandler is the base handler for all debugging events.
   * During debugging, events are sent from the remote query to the client.
   * Once a client received an event, a callback is made to the debugger event
   * handler.
   */
  class ZORBA_DLL_PUBLIC DebuggerEventHandler
  {
    public:

      virtual
      ~DebuggerEventHandler(){}
      
      /** \brief Signal the query status as being started.
       *
       */
      virtual void
      started() = 0;

      /** \brief Signal the query status as being idle.
       *
       */
      virtual void
      idle() = 0;

      /** \brief Signal the query status as being suspended.
       *
       * When a suspended event is triggered, this method received the
       * cause of the suspension (user, breakpoint, step) and the location 
       * in the query where the debugger suspended.
       */
      virtual void
      suspended( QueryLocation &aLocation, SuspendedBy aCause ) = 0;


      /** \brief Signal the query status as being resumed.
       *
       */
      virtual void
      resumed() = 0;


      /** \brief Signal the query status as being terminated.
       *
       */      
      virtual void
      terminated() = 0;

      /** \brief Signal the result of an XQuery expression.
       *
       */
      virtual void
      evaluated(String &anExpr, std::list<std::pair<String, String> > &aValuesAndTypes) = 0;
  
      /** \brief Signal an Error from an XQuery expression.
       *
       * @param String the XQuery expression
       * @param String the Error description
       */
      virtual void
      evaluated(String &anExpr, String &anError) = 0;
  };
}//end of namespace
#endif
