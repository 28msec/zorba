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
#include "command_line_handler.h"

#ifndef WIN32
# include <unistd.h>
# define msleep(x) usleep(1000*x)
#else
# include <Windows.h>
# define msleep Sleep
#endif

namespace zorba { namespace debugclient {
  
  using namespace ::std;
  using namespace ::ZORBA_TR1_NS;
  
  CommandLineHandler::CommandLineHandler(unsigned short port,
                                         LockFreeConsumer<std::size_t>& aConsumer,
                                         LockFreeConsumer<bool>& aContinueQueue,
                                         EventHandler& aHandler,
                                         CommandLine& aCommandLine)
  : theConsumer(aConsumer),
    theContinueQueue(aContinueQueue),
    theClient(DebuggerClient::createDebuggerClient(&aHandler, port, "localhost")),
    theCommandLine(aCommandLine),
    theQuit(false), theContinue(false), theWaitFor(0)
  {
    addCommands();
  }
  
  CommandLineHandler::~CommandLineHandler()
  {
  }
  
  void CommandLineHandler::execute()
  {
    theClient->accept();
    std::set<std::size_t> lIdList;
    do {
      getNextId(lIdList);
      while (!theQuit && lIdList.find(theWaitFor) == lIdList.end()) {
        getNextId(lIdList);
        msleep(20);
      }
      while (!theContinueQueue.consume(theQuit)) {
        msleep(20);
      }
      theQuit = !theQuit;
      if (!theQuit) {
        theCommandLine.execute();
        while (theContinue) {
          theContinue = false;
          theCommandLine.execute();
        }
      }
    } while (!theQuit);
  }
  
  void CommandLineHandler::getNextId(std::set<std::size_t>& aIdList)
  {
    std::size_t result;
    if (theConsumer.consume(result)) {
      aIdList.insert(result);
    }
  }
  
  template<>
  void CommandLineHandler::handle<Status>(ZORBA_TR1_NS::tuple<> &t)
  {
    theWaitFor = theClient->status();
  }
  
  template<>
  void CommandLineHandler::handle<Quit>(ZORBA_TR1_NS::tuple<> &t)
  {
    bool answered = false;
    while (!answered) {
      std::cout << "Do you really want to stop debugging and exit? (y/n) ";
      char answer;
      std::cin >> answer;
      std::cout << std::endl;
      if (answer == 'y') {
        answered = true;
      } else if (answer == 'n') {
        theContinue = true;
        return;
      }
    }
    theWaitFor = theClient->stop();
    theClient->quit();
  }
  
  template<>
  void CommandLineHandler::handle<Run>(ZORBA_TR1_NS::tuple<> &t)
  {
    theWaitFor = theClient->run();
  }
  
  template<>
  void CommandLineHandler::handle<BreakpointSet>(std::tr1::tuple<bstring, bstring, bint> &t)
  {
    DebuggerClient::BreakpointType lType = DebuggerClient::Line;
    bool lEnabled = true;
    if (get<0>(t).first) {
      if (get<0>(t).second == "disabled") {
        lEnabled = false;
      }
    }
    theWaitFor = theClient->breakpoint_set(lType,
                                           lEnabled,
                                           get<1>(t).second,
                                           get<2>(t).second);
  }
  
  template<>
  void CommandLineHandler::handle<BreakpointGet>(tuple<bint> &aTuple)
  {
    theWaitFor = theClient->breakpoint_get(get<0>(aTuple).second);
  }
  
  template<>
  void CommandLineHandler::handle<BreakpointDel>(tuple<bint> &aTuple)
  {
    theWaitFor = theClient->breakpoint_remove(get<0>(aTuple).second);
  }
  
  template<>
  void CommandLineHandler::handle<BreakpointList>(tuple<> &t)
  {
    theWaitFor = theClient->breakpoint_list();
  }
  
  template<>
  void CommandLineHandler::handle<StackDepth>(tuple<> &t)
  {
    theWaitFor = theClient->stack_depth();
  }
  
  template<>
  void CommandLineHandler::handle<StackGet>(tuple<bint> &aTuple)
  {
    if (get<0>(aTuple).first) {
      theWaitFor = theClient->stack_get(get<0>(aTuple).second);
    } else {
      theWaitFor = theClient->stack_get();
    }
  }
  
  template<>
  void CommandLineHandler::handle<ContextNames>(tuple<>& aTuple)
  {
    theWaitFor = theClient->context_names();
  }
  
  template<>
  void CommandLineHandler::handle<ContextGet>(tuple<bint> &aTuple)
  {
    if (get<0>(aTuple).first)
      theWaitFor = theClient->context_get(get<0>(aTuple).second);
    else
      theWaitFor = theClient->context_get();
  }
  
  template<>
  void CommandLineHandler::handle<Eval>(tuple<bstring>& aTuple)
  {
    theWaitFor = theClient->eval(get<0>(aTuple).second);
  }
  
  void CommandLineHandler::addCommands()
  {
    theCommandLine << createCommand<Status>(tuple<>(), "status", *this,
                                            "Gets the status of the server");
    theCommandLine << createCommand<Quit>(tuple<>(), "quit", *this,
                                          "Stops debugging and quits the client");
    theCommandLine << createCommand<Run>(tuple<>(), "run", *this, "Run the Query");
    {
      Command<CommandLineHandler, tuple<bstring, bstring, bint>, BreakpointSet>* lCommand =
      createCommand<BreakpointSet>(tuple<bstring, bstring, bint>(), "break", *this, "Set a breakpoint");
      (*lCommand)(0, "s", createArgType<tuple<bstring, bstring, bint>, std::string, 0>(tuple<bstring, bstring, bint>()),
                  "breakpoint state (enabled or disabled - default: enabled)", false);
      (*lCommand)(1, "f", createArgType<tuple<bstring, bstring, bint>, std::string, 1>(tuple<bstring, bstring, bint>()),
                  "The name of the file where to stop", true);
      (*lCommand)(2, "l", createArgType<tuple<bstring, bstring, bint>, int, 2>(tuple<bstring, bstring, bint>()),
                  "The line number", true);
      
      theCommandLine << lCommand;
    }
    {
      Command<CommandLineHandler, tuple<bint>, BreakpointGet>* lCommand
      = createCommand<BreakpointGet>(tuple<bint>(), "binfo", *this, 
                                   "Get information about a given breakpoint");
      (*lCommand)(0, "i", createArgType<tuple<bint>, int, 0>(tuple<bint>()),
                  "The id of the breakpoint", true);
      
      theCommandLine << lCommand;
    }
    {
      Command<CommandLineHandler, tuple<bint>, BreakpointDel>* lCommand
      = createCommand<BreakpointDel>(tuple<bint>(), "bdel", *this, "Delete a breakpoint with a given id");
      (*lCommand)(0, "i", createArgType<tuple<bint>, int, 0>(tuple<bint>()), "The id of the breakpoint", true);
      
      theCommandLine << lCommand;
    }
    theCommandLine << createCommand<BreakpointList>(tuple<>(), "blist", *this, "List all set breakpoints");
    theCommandLine << createCommand<StackDepth>(tuple<>(), "sdepth", *this, "Get the depth of the stack");
    {
      Command<CommandLineHandler, tuple<bint>, StackGet>* lCommand
      = createCommand<StackGet>(tuple<bint>(), "sget", *this, "Get information about one or all stack frames");
      (*lCommand)(0, "d", createArgType<tuple<bint>, int, 0>(tuple<bint>()), "The stack entry two show (show all if not provided)", false);
      theCommandLine << lCommand;
    }
    theCommandLine << createCommand<ContextNames>(tuple<>(), "cnames", *this, "Get the names of the avilable contexts");
    {
      Command<CommandLineHandler, tuple<bint>, ContextGet>* lCommand
      = createCommand<ContextGet>(tuple<bint>(), "cget", *this, "Get a context");
      
      (*lCommand)(0, "c", createArgType<tuple<bint>, int, 0>(tuple<bint>()), "The id of the context", false);
      
      theCommandLine << lCommand;
    }
    {
      Command<CommandLineHandler, tuple<bstring>, Eval>* lCommand
      = createCommand<Eval>(tuple<bstring>(), "eval", *this, "Evaluate a function");
      
      (*lCommand)(0, "c", createArgType<tuple<bstring>, std::string, 0>(tuple<bstring>()), "The command to evaluate", true);
      
      theCommandLine << lCommand;
    }
  }
  
}} // namespace zorba::debugclient

