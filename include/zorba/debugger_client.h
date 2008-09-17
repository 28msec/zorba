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

#include <map>
#include <list>
#include <zorba/api_shared_types.h>
#include <zorba/debugger_event_handler.h>

namespace zorba{ 

  /**
   * zorba::Variable is the debugger representation of a variable on 
   * from the remote server to the client.
   */
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

  /** 
   * Client instance of Zorba debugger.
   * ZorbaDebuggerClient API provides to send commands to a
   * remote debugger and to handle events from it.
   */
  class ZORBA_EXTERN_DECL ZorbaDebuggerClient
  {

    public:

      virtual ~ZorbaDebuggerClient(){}

      /** \brief Gets a new instance of Zorba debugger client.
       *
       * This factory method create a new instance of the debugger.
       * The parameters are the network ports for the request and event connection
       * (by default: 8000 for commands and 9000 for events):
       * <pre>
       * ZorbaDebuggerClient* lClient = ZorbaDebuggerClient::createClient(8000, 9000);
       * </pre>
       *
       * @param unsigned short aRequestPortno Network port number for debugging commands
       * @param unsigned short aEventPortno
       * @return ZorbaDebuggerClient the newly created debugger client instance.
       */
      static ZorbaDebuggerClient*
      createClient( unsigned short aRequestPortno, unsigned short aEventPortno );

      /** \brief Register a debuggere vent handler to which runtime events on the remote 
       * debugger server are reported.
       *
       * @param aDebuggerEventHandler DebuggerEventHandler Handler for runtime events comming
       * from the remote debugger server.
       */
      virtual void
      registerEventHandler( DebuggerEventHandler *aDebuggerEventHandler ) = 0;
     
      /** \brief Indicates if the query is running.
       *
       * @return true if the query is running, false otherwise.
       */
      virtual bool
      isQueryRunning() const = 0;

      /** \brief Indicates if the query is idle.
       *
       * @return true if the query is idle, false otherwise.
       */
      virtual bool
      isQueryIdle() const = 0;

      /** \brief Indicates if the query is suspended.
       *
       * @return true if the query is suspended, false otherwise.
       */
      virtual bool
      isQuerySuspended() const = 0;

      /** \brief Indicates if the query is terminated.
       *
       * @return true if the query is terminated, false otherwise.
       */
      virtual bool
      isQueryTerminated() const = 0;

      /** \brief Request the remote query to run.
       *
       */
      virtual void
      run() = 0;

      /** \brief Request the remote query to suspend.
       *
       */
      virtual void
      suspend() = 0;

      /** \brief Request the remote query to resume.
       *
       */
      virtual void
      resume() = 0;
      
      /** \brief Request the remote query to terminate.
       *
       */
      virtual void
      terminate() = 0;

      
      /** \brief Request the remote query quit and the debugger server to shutdown.
       *
       */virtual void
      quit() = 0;

      /** \brief Set a new breakpoint.
       *
       * @param aFileName String Filename of the query or module.
       * @param aLineNo unsigned int Line number in the file.
       */
      virtual void
      addBreakpoint( const String &aFileName, const unsigned int aLineNo ) = 0;

      /** \brief Set a new breakpoint in the main query.
       *
       * @param aLineNo unsigned int Line number in the main query.
       */
      virtual void
      addBreakpoint( const unsigned int aLineNo ) = 0;

      /** \brief Set a new watchpoint.
       * 
       * A watchpoint suspend the query execution when the return 
       * value of its XQuery expression is true.
       *
       * @param anExpr String XQuery expression to be evaluated.
       */
      virtual void
      addBreakpoint( const String &anExpr ) = 0;

      /** \brief Remove a breakpoint or watchpoint of the given id
       *
       * @param anId unsigned int the breakpoint/watchpoint id
       * @return true if the breakpoint id is correct.
       */
      virtual bool
      clearBreakpoint( unsigned int anId ) = 0;

      /** \brief Remove a breakpoint or watchpoint of the given collection of ids
       *
       * @param Ids std::list<unsigned int> List of the breakpoint/watchpoint ids
       * @return true if all breakpoint ids are correct.
       */
      virtual void
      clearBreakpoints( std::list<unsigned int> &Ids ) = 0;
      
      /** \brief Get all breakpoints set on the remote query.
       *
       * @return a map of all breakpoints with their associated id.
       */
      virtual std::map<unsigned int, String>
      getBreakpoints() const = 0;

      /** \brief Remove all breakpoints on the remote query.
       *
       */
      virtual void
      clearBreakpoints() = 0;

      /** \brief Get the current location of the remote query.
       *
       * return the current location of the query or null is the query didn't start yet.
       */
      virtual QueryLocation*
      getLocation() const = 0;

      /** \brief Evaluate an XQuery expression on the remote debugger server.
       *
       * eval() sends an XQuery expression to the remote debugger server for evaluation.
       * This expression can use debugee query global and locals variables.
       * Because eval() can eventually compute very complex expression, the evaluation is
       * done in a separate thread. Once the expression computed, the server fires an event to
       * the client with the result or an error description if an error happened during evaluation.
       */
      virtual void
      eval( String &anExpr ) = 0;

      /** \brief Get all variables that are in scope in the remote query.
       *
       * @return a list of all variables that are in scope in the remote query.
       */
      virtual std::list<Variable>
      getAllVariables() = 0;

      /** \brief Get all local variables that are in scope in the remote query.
       *
       * @return a list of all local variables that are in scope in the remote query.
       */
      virtual std::list<Variable>
      getLocalVariables() = 0;

      /** \brief Get all global variables that are in scope in the remote query.
       *
       * @return a list of all global variables that are in scope in the remote query.
       */
      virtual std::list<Variable>
      getGlobalVariables() = 0;
  };
}//end of namespace
#endif
