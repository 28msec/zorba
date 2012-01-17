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
#ifndef ZORBA_DEBUGGER_RUNTIME_H
#define ZORBA_DEBUGGER_RUNTIME_H

#include <ostream>
#include <set>

#include "common/shared_types.h"

#include "zorbautils/runnable.h"
#include "zorbautils/lock.h"
#include "zorbatypes/rchandle.h"

#include "compiler/parser/query_loc.h"

#include "debugger/debugger_common.h"
#include "debugger/debugger_commons.h"
#include "debugger/stackimpl.h"


struct Zorba_SerializerOptions;
typedef struct Zorba_SerializerOptions Zorba_SerializerOptions_t;

namespace zorba {
  class XQueryImpl;
  class DebuggerCommunicator;
  class DebugIterator;

  typedef Zorba_SerializerOptions_t* (*itemHandler)(void* aUserData);

class DebuggerRuntime : public Runnable {

  public: // Creation and destruction

    DebuggerRuntime(
      XQueryImpl* xqueryImpl,
      std::ostream& oStream,
      Zorba_SerializerOptions&  serializerOptions,
      DebuggerCommunicator* communicator,
      itemHandler aHandler,
      void* aCallBackData,
      bool* aNotBremse);

    virtual ~DebuggerRuntime();

  public: // Runnable interface

    void
    run();

    void
    finish();

  public:

    void
    resetRuntime();

    ExecutionStatus
    getExecutionStatus() const;

    void
    suspendRuntime(QueryLoc location, SuspensionCause cause);

    // ************************************************************************
    // Breakpints

    unsigned int
    addBreakpoint(String& aFileName, unsigned int aLine, bool enabled);

    Breakable
    getBreakpoint(unsigned int id);

    BreakableVector
    getBreakpoints();

    void
    updateBreakpoint(
      unsigned int id,
      bool enabled,
      std::string condition,
      unsigned int hitValue);

    void
    removeBreakpoint(unsigned int id);

    // ************************************************************************
    // Stack frames

    unsigned int
    getStackDepth();

    std::vector<StackFrameImpl>
    getStackFrames();

    // ************************************************************************
    // Other

    void
    setLastContinuationCommand(int transactionID, std::string commandName);

    std::string
    listSource(
      String& fleName,
      unsigned int beginLine,
      unsigned int endLine,
      bool zorbaExtensions);

    std::vector<std::pair<std::string, std::string> >
    getVariables();

    std::vector<std::pair<std::string, std::string> >
    getVariables(bool locals);

    std::list<std::pair<zstring, zstring> >
    eval(zstring& expr);

    void runQuery();

    void
    startRuntime();

    void
    resumeRuntime();

    void
    terminateRuntime();
    
    void
    detachRuntime();

    void
    stepIn();

    void
    stepOver();

    void
    stepOut();

    bool
    getAndClearInterruptBreak();

    DebuggerRuntime*
    clone();

  private:

    DebuggerCommons* 
    getDebbugerCommons();

  private:

    XQueryImpl*                       theQuery;
    std::ostream&                     theOStream;
    Zorba_SerializerOptions&          theSerializerOptions;
    // Ownership of the communicator is hold by the server
    DebuggerCommunicator*                 theCommunicator;
    PlanWrapper_t                     theWrapper;
    ExecutionStatus                   theExecStatus;
    mutable Lock                      theLock;
    std::set<DebugIterator*>          theBreakpoints;
    bool                              thePlanIsOpen;
    serializer*                       theSerializer;
    itemHandler                       theItemHandler;
    void*                             theCallbackData;
    std::pair<int, std::string>       theLastContinuationCommand;
    bool*                             theNotBremse;
  };
}

#endif // ZORBA_DEBUGGER_RUNTIME_H
