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

#ifndef ZORBA_DEBUGGER_IMPL_H
#define ZORBA_DEBUGGER_IMPL_H

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <list>
#include <stack>

#include "compiler/parsetree/parsenode_base.h"

#include "api/xqueryimpl.h"

#include "debugger/debugger_common.h"
#include "debugger/profiler.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/debug/zorba_debugger_iterators.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/fncontext/FnContextImpl.h"

#include "zorbautils/thread.h"

namespace zorba{

class TCPSocket;
class TCPServerSocket;
class ZorbaDebuggerCommandMessage;
class ZorbaDebuggerReplyMessage;
class AbstractMessage;
class AbstractCommandMessage;
class RunExecutionMessage;
class SuspendExecutionMessage;
class ResumeExecutionMessage;
class TerminateExecutionMessage;
class StepExecutionMessage;

typedef std::map<const QueryLoc, std::stack<unsigned int> > Classification_t;

ZORBA_THREAD_RETURN runQuery(void *aQuery);

/**
 * @
 */
class ZorbaDebugger
{
  public:
    ZorbaDebugger():
      theQuery(0),
      theOutputStream(0),
      theSerOptions(0),
      theRequestServerSocket(0), 
      theEventSocket(0), 
      theStatus( QUERY_IDLE  ),
      thePlanState(0),
      theRuntimeThread(0),
      isSteppingOver(false),
      isSteppingInto(false),
      isSteppingOut(false),
      theProfiler(0),
      isFunctionExecution(false),
      catchFunctionExecution(false)
  {
  }

    virtual ~ZorbaDebugger();

    void runQuery();
    
    ExecutionStatus getStatus() const { return theStatus; }

    const QueryLoc getLocation() const { return theLocation; }

    void start( XQueryImpl *aQuery,
                std::ostream& aOutStream,
                const Zorba_SerializerOptions_t* aSerOptions,
                unsigned short aRequestPort = 8000,
                unsigned short aEventPort = 9000 );

  private:
    friend class FnDebugIterator;
    friend class XQueryCompiler;
    friend class UDFunctionCallIterator; 
    friend class XQueryImpl;
    friend class TranslatorImpl;
    friend ZORBA_THREAD_RETURN runtimeThread( void* );

    XQueryImpl* theQuery;

    std::ostream* theOutputStream;
    
    const Zorba_SerializerOptions_t* theSerOptions;

    TCPServerSocket* theRequestServerSocket;

    TCPSocket* theEventSocket;

    //The event port number
    unsigned short theEventPortno;

    //The execution status
    ExecutionStatus theStatus;

    //Last known location of the query
    QueryLoc theLocation;

    //The following attributes are used for the eval function
    PlanState * thePlanState;
    
    checked_vector<store::Item_t>  theVarnames;
    checked_vector<std::string>    theVarkeys;
    checked_vector<xqtref_t>       theVartypes;
    checked_vector<PlanIter_t>     theChildren;
    checked_vector<global_binding> theGlobals;

    //Map of breakpoints and watchpoints
    std::map<unsigned int, QueryLoc> theBreakpoints;
    std::map<unsigned int, xqpString> theWatchpoints;

    //The runtime thread
    Thread * theRuntimeThread;

    //The List of modules for the query
    std::list<parsenode_t> theModules;

    //The list of URIs to import for eval
    std::map<std::string, std::string> theImports;
   
  public:
    ZorbaDebugger* addModule(parsenode_t& anAST)
    {
      theModules.push_back(anAST);
      return this;
    }

    std::list<parsenode_t> getModules() const
    {
      return theModules;
    }

  private:
    //The dewey classification
    Classification_t theClassification;
    
    //True if the debugger is stepping
    bool isSteppingOver;
    bool isSteppingInto;
    bool isSteppingOut;
    bool hasToStepOver() const;
    bool hasToStepInto() const;
    bool hasToStepOut() const;
    void stepOver();
    void stepInto();
    void stepOut();

    //Size of the decimal to stop to
    unsigned int theDecimalSize;
    //The common base of the next decimal to stop to
    std::stack<unsigned int> theBaseDecimal;
    //The current function name
    std::string theFunctionName;

    //The stack frame
    std::stack< std::pair<std::string, QueryLoc> > theStack;
    std::stack< std::pair<std::string, QueryLoc> > theLastKnownStack;
    Profiler* theProfiler;

    void pushStack(std::pair<std::string, QueryLoc> aFrame)
    {
      theStack.push(aFrame);
      theProfiler->beginFn(aFrame.first, aFrame.second);
    }

    void popStack()
    {
      theStack.pop();
      theProfiler->endFn();
    }

    //is it a function execution ?
    bool isFunctionExecution;
    bool catchFunctionExecution;

    const QueryLoc addBreakpoint(const QueryLoc& aLocation);
    
    bool hasToSuspend();
    
    void setStatus( ExecutionStatus aStatus, SuspensionCause aCause = CAUSE_USER );

    void run();

    void handleTcpClient( TCPSocket* aSock );

    void handshake( TCPSocket* aSock );

    void processMessage( AbstractCommandMessage* );

    void suspend();

    void resume();

    void terminate();

    void sendEvent( AbstractCommandMessage* aMessage );

    void startedEvent();

    void suspendedEvent( QueryLoc& aLocation, SuspensionCause aCause );

    void resumedEvent();

    void terminatedEvent();

    void addBreakpoint( String& aFileName, unsigned int aLineNo );

    void clearBreakpoint( String& aFileName, unsigned int aLineNo );

    void eval( xqpString anExpr );

    void step( const StepCommand aKind );

    std::stack<unsigned int> getCurrentDecimal() const;

    std::string getCurrentFunctionName() const;

    std::auto_ptr<PlanWrapperHolder>
    compileEvalPlan(const QueryLoc& loc, CompilerCB* ccb, dynamic_context* dctx, const xqpString& anExpr, PlanState& planState);
};
}//end of namespace xqp
#endif
