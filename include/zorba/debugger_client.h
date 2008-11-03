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
#include <stack>
#include <zorba/api_shared_types.h>
#include <zorba/debugger_event_handler.h>

namespace zorba{ 

  /**
   * Representation of the current location location 
   * in the remote query.
   * This location goes from the starting line and column
   * to the ending line and column.
   */
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

      virtual String
      toString() const = 0;
  };

  /**
   * Representation of the runtime frame.
   */
  class ZORBA_EXTERN_DECL Frame
  {
    public:
      virtual
      ~Frame(){}

      virtual const std::string&
      getSignature() const = 0;

      virtual const QueryLocation*
      getLocation() const = 0;
  };

  /**
   * Representation of the runtime stack frame.
   */
  class ZORBA_EXTERN_DECL StackFrame
  {
    public:
      virtual
      ~StackFrame(){}

      virtual const Frame*
      top() const = 0;

      virtual StackFrame*
      pop() = 0;

      virtual unsigned int
      size() const = 0;

      virtual bool
      empty() const = 0;
  };
 
  //string serialization of the query 
  ZORBA_EXTERN_DECL
  std::ostream& operator<< (std::ostream& os, const QueryLocation& aQuery); 
  ZORBA_EXTERN_DECL
  std::ostream& operator<< (std::ostream& os, const QueryLocation* aQuery); 

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
       * @param unsigned short aRequestPortno Network port number for debugging commands.
       * @param unsigned short aEventPortno.
       * @return ZorbaDebuggerClient the newly created debugger client instance.
       */
      static ZorbaDebuggerClient*
      createClient( unsigned short aRequestPortno = 8000, unsigned short aEventPortno = 9000 );

      /** \brief Gets a new instance of Zorba debugger client.
       *
       * This factory method create a new instance of the debugger client for remote 
       * debugging.
       * You can specify the IP address of the debugger server.
       * The parameters are the network ports for the request and event connection
       * (by default: 8000 for commands and 9000 for events).
       * <pre>
       * ZorbaDebuggerClient* lClient = ZorbaDebuggerClient::createClient("192.168.0.1");
       * </pre>
       *
       * @param std::string aServerAddress the IP address of the debugger server.
       * @param unsigned short aRequestPortno Network port number for debugging commands.
       * @param unsigned short aEventPortno.
       * @return ZorbaDebuggerClient the newly created debugger client instance.
       */
       static ZorbaDebuggerClient*
       createClient(std::string aServerAddress, unsigned short aRequestPortno = 8000, unsigned short aEventPortno = 9000 );


/** \brief Register a debuggere vent handler to which runtime events on the remote 
       * debugger server are reported.
       *
       * @param aDebuggerEventHandler DebuggerEventHandler Handler for runtime events comming
       * from the remote debugger server.
       */
      virtual ZorbaDebuggerClient*
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
      virtual bool
      run() = 0;

      /** \brief Request the remote query to suspend.
       *
       */
      virtual bool
      suspend() = 0;

      /** \brief Request the remote query to resume.
       *
       */
      virtual bool
      resume() = 0;
      
      /** \brief Request the remote query to terminate.
       *
       */
      virtual bool
      terminate() = 0;

      /** \brief Step into the function call.
       *
       */
      virtual bool
      stepInto() = 0;

      /** \brief Step out the function call.
       *
       */
      virtual bool
      stepOut() = 0;

      /** \brief Step over the expression
       *
       */
      virtual bool
      stepOver() = 0;

      /** \brief Set a new breakpoint.
       *
       * @param aFileName String Filename of the query or module.
       * @param aLineNo unsigned int Line number in the file.
       * @return the location where the breakpoint has been set.
       */
      virtual QueryLocation*
      addBreakpoint( const String &aFileName, const unsigned int aLineNo ) = 0;

      /** \brief Set a new breakpoint in the main query.
       *
       * @param aLineNo unsigned int Line number in the main query.
       * @return the location where the breakpoint has been set.
       */
      virtual QueryLocation*
      addBreakpoint( const unsigned int aLineNo ) = 0;

      /** \brief Set a new watchpoint.
       * 
       * A watchpoint suspend the query execution when the return 
       * value of its XQuery expression is true.
       *
       * @param anExpr String XQuery expression to be evaluated.
       */
      virtual bool
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
      virtual bool
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
      virtual bool
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
      virtual bool
      eval( String &anExpr ) const = 0;

      /** \brief Get all variables that are in scope in the remote query.
       *
       * @return a list of all variables that are in scope in the remote query.
       */
      virtual std::list<Variable>
      getAllVariables() const = 0;

      /** \brief Get all local variables that are in scope in the remote query.
       *
       * @return a list of all local variables that are in scope in the remote query.
       */
      virtual std::list<Variable>
      getLocalVariables() const = 0;

      /** \brief Get all global variables that are in scope in the remote query.
       *
       * @return a list of all global variables that are in scope in the remote query.
       */
      virtual std::list<Variable>
      getGlobalVariables() const = 0;

      /** \brief Get the runtime stack frame.
       *
       * @return the runtime stack frame.
       */
      virtual
      StackFrame* getStack() const = 0;
  
      /** \brief Catch all function executions
       *
       */
      virtual
      bool catchFunctionCall() const = 0;
  };
}//end of namespace
#endif
