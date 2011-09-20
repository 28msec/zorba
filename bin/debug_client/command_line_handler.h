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
#pragma once

#include <set>
#include <cassert>
#include <zorba/debugger_client.h>
#include "debug_command.h"
#include "event_handler.h"

namespace zorba { namespace debugclient {
  
  enum Commands {
    Status,
    Run,
    BreakpointSet,
    BreakpointGet,
    BreakpointDel,
    BreakpointList,
    StackDepth,
    StackGet,
    ContextNames,
    ContextGet,
    Eval,
    Quit
  };
  
  class CommandLineHandler {
  private:
    typedef std::pair<bool, std::string> bstring;
    typedef std::pair<bool, int> bint;
  public:
    CommandLineHandler(unsigned short port,
                       LockFreeConsumer<std::size_t>& aConsumer,
                       LockFreeConsumer<bool>& aContinueQueue,
                       EventHandler& aHandler,
                       CommandLine& aCommandLine);
    ~CommandLineHandler();
  public:
    void execute();
  public: // Handlers
    template<int>
    void handle(ZORBA_TR1_NS::tuple<>& aTuple) { assert(false); }
    
    template<int>
    void handle(ZORBA_TR1_NS::tuple<bstring, bstring, bint>& t)
    {
      assert(false);
    }
    
    template<int>
    void handle(ZORBA_TR1_NS::tuple<bint>& aTuple)
    {
      assert(false);
    }
    
    template<int>
    void handle(ZORBA_TR1_NS::tuple<bstring>& aTuple)
    {
      assert(false);
    }
  private:
    LockFreeConsumer<std::size_t>& theConsumer;
    LockFreeConsumer<bool>& theContinueQueue;
    DebuggerClient* theClient;
    CommandLine& theCommandLine;
    bool theQuit;
    bool theContinue;
    std::size_t theWaitFor;
  private:
    void getNextId(std::set<std::size_t>& aIdList);
    void addCommands();
  };
  
  template<>
  void CommandLineHandler::handle<Status> (ZORBA_TR1_NS::tuple<>& t);
  
  template<>
  void CommandLineHandler::handle<Quit> (ZORBA_TR1_NS::tuple<>& t);
  
  template<>
  void CommandLineHandler::handle<Run> (ZORBA_TR1_NS::tuple<> &t);
  
  template<>
  void CommandLineHandler::handle<StackDepth> (ZORBA_TR1_NS::tuple<>& t);
  
  template<>
  void CommandLineHandler::handle<BreakpointList> (ZORBA_TR1_NS::tuple<>& aTuple);
  
  template<>
  void CommandLineHandler::handle<BreakpointSet> (ZORBA_TR1_NS::tuple<bstring, bstring, bint> &t);
  
  template<>
  void CommandLineHandler::handle<BreakpointGet> (ZORBA_TR1_NS::tuple<bint>& aTuple);
  
  template<>
  void CommandLineHandler::handle<BreakpointDel>(ZORBA_TR1_NS::tuple<bint> &aTuple);
  
  template<>
  void CommandLineHandler::handle<StackGet> (ZORBA_TR1_NS::tuple<bint>& aTuple);
  
  template<>
  void CommandLineHandler::handle<ContextNames>(ZORBA_TR1_NS::tuple<> &aTuple);
  
  template<>
  void CommandLineHandler::handle<ContextGet>(ZORBA_TR1_NS::tuple<bint> &aTuple);
  
  template<>
  void CommandLineHandler::handle<Eval>(ZORBA_TR1_NS::tuple<bstring>& aTuple);
  
}} // close namespaces zorba::debugclient
