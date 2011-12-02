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

namespace zorba { namespace debugger {
  
  using namespace ::ZORBA_TR1_NS;
  
CommandLineHandler::CommandLineHandler(
  unsigned short port,
  LockFreeConsumer<std::size_t>& aConsumer,
  LockFreeConsumer<bool>& aContinueQueue,
  EventHandler& aHandler,
  CommandPrompt& aCommandPrompt)
  : theConsumer(aConsumer),
    theContinueQueue(aContinueQueue),
    theClient(DebuggerClient::createDebuggerClient(&aHandler, port, "localhost")),
    theCommandLine(aCommandPrompt),
    theQuit(false), theTerminated(true), theContinue(false), theWaitFor(0)
  {
    addCommands();
  }
  
CommandLineHandler::~CommandLineHandler()
{
}
  
void
CommandLineHandler::execute()
{
  theClient->accept();
  std::set<std::size_t> lIdList;
  do {
    getNextId(lIdList);
    while (lIdList.find(theWaitFor) == lIdList.end()) {
      getNextId(lIdList);
      msleep(20);
    }
    bool lCanQuit;
    while (!theContinueQueue.consume(lCanQuit)) {
      msleep(20);
    }
    if (lCanQuit) {
      theTerminated = true;
    }
    theCommandLine.execute();
    while (theContinue) {
      theContinue = false;
      theCommandLine.execute();
    }
  } while (!theQuit);
}
  
void
CommandLineHandler::getNextId(std::set<std::size_t>& aIdList)
{
  std::size_t result;
  if (theConsumer.consume(result)) {
    aIdList.insert(result);
  }
}

template<>
void
CommandLineHandler::handle<Status>(ZORBA_TR1_NS::tuple<> &t)
{
  theWaitFor = theClient->status();
}

template<>
void
CommandLineHandler::handle<Variables>(ZORBA_TR1_NS::tuple<> &t)
{
  theWaitFor = theClient->variables();
}

template<>
void
CommandLineHandler::handle<Quit>(ZORBA_TR1_NS::tuple<> &t)
{
  if (!theTerminated) {
    bool answered = false;
    while (!answered) {
      std::cout << "Do you really want to stop debugging and exit? (y/n) ";
      std::string lAnswer;
      std::getline(std::cin, lAnswer);
      if (lAnswer == "y" || lAnswer == "yes") {
        answered = true;
      } else if (lAnswer == "n" || lAnswer == "no") {
        theContinue = true;
        return;
      }
    }
  }
  theWaitFor = theClient->stop();
  theClient->quit();
  theQuit = true;
}
  
template<>
void
CommandLineHandler::handle<Run>(ZORBA_TR1_NS::tuple<> &t)
{
  theTerminated = false;
  theWaitFor = theClient->run();
}

template<>
void
CommandLineHandler::handle<BreakpointSet>(std::tr1::tuple<bstring, bstring, bint> &aTuple)
{
  DebuggerClient::BreakpointType lType = DebuggerClient::Line;
  bool lEnabled = true;
  if (get<0>(aTuple).first) {
    if (get<0>(aTuple).second == "disabled") {
      lEnabled = false;
    }
  }
  theWaitFor = theClient->breakpoint_set(lType,
                                          lEnabled,
                                          get<1>(aTuple).second,
                                          get<2>(aTuple).second);
}
  
template<>
void
CommandLineHandler::handle<BreakpointGet>(tuple<bint> &aTuple)
{
  theWaitFor = theClient->breakpoint_get(get<0>(aTuple).second);
}
  
template<>
void
CommandLineHandler::handle<BreakpointRemove>(tuple<bint> &aTuple)
{
  theWaitFor = theClient->breakpoint_remove(get<0>(aTuple).second);
}
  
template<>
void
CommandLineHandler::handle<BreakpointList>(tuple<> &aTuple)
{
  theWaitFor = theClient->breakpoint_list();
}
  
template<>
void
CommandLineHandler::handle<StackDepth>(tuple<> &aTuple)
{
  theWaitFor = theClient->stack_depth();
}
  
template<>
void
CommandLineHandler::handle<StackGet>(tuple<bint> &aTuple)
{
  if (get<0>(aTuple).first) {
    theWaitFor = theClient->stack_get(get<0>(aTuple).second);
  } else {
    theWaitFor = theClient->stack_get();
  }
}
  
template<>
void
CommandLineHandler::handle<ContextNames>(tuple<>& aTuple)
{
  theWaitFor = theClient->context_names();
}
  
template<>
void CommandLineHandler::handle<ContextGet>(tuple<bint, bint> &aTuple)
{
  int lDepth = -1;
  int lContext = -1;

  if (get<0>(aTuple).first) {
    lDepth = get<0>(aTuple).second;
  }
  if (get<1>(aTuple).first) {
    lContext  = get<1>(aTuple).second;
  }
  theWaitFor = theClient->context_get(lDepth, lContext);
}

template<>
void CommandLineHandler::handle<Source>(tuple<bint, bint, bstring> &aTuple)
{
  theWaitFor = theClient->source(
    get<2>(aTuple).second,
    get<0>(aTuple).second,
    get<1>(aTuple).second);
}
  
template<>
void CommandLineHandler::handle<Eval>(tuple<bstring>& aTuple)
{
  theWaitFor = theClient->eval(get<0>(aTuple).second);
}

template<>
void
CommandLineHandler::handle<StepIn>(ZORBA_TR1_NS::tuple<> &t)
{
  theTerminated = false;
  theWaitFor = theClient->step_into();
}

template<>
void
CommandLineHandler::handle<StepOut>(ZORBA_TR1_NS::tuple<> &t)
{
  theWaitFor = theClient->step_out();
}

template<>
void
CommandLineHandler::handle<StepOver>(ZORBA_TR1_NS::tuple<> &t)
{
  theTerminated = false;
  theWaitFor = theClient->step_over();
}

void
CommandLineHandler::addCommands()
{
  typedef tuple<> TUPLE;
  typedef tuple<bint> TUPLE_INT;
  typedef tuple<bstring> TUPLE_STR;
  typedef tuple<bint, bint> TUPLE_INT_INT;
  typedef tuple<bstring, bstring, bint> TUPLE_STR_STR_INT;
  typedef tuple<bint, bint, bstring> TUPLE_INT_INT_STR;

  // DBGP: status
  theCommandLine << createCommand<Status>(TUPLE(), "status", *this, "Gets the status of the server");

  // ALIAS: variables (context_get -c -1)
  theCommandLine << createCommand<Variables>(TUPLE(), "variables", *this, "Gets the variables visible in the current scope");

  // META: quit
  theCommandLine << createCommand<Quit>(TUPLE(), "quit", *this, "Stops debugging and quits the client");

  // DBGP: run
  theCommandLine << createCommand<Run>(TUPLE(), "run", *this, "Run the query");

  // DBGP: breakpoint_set
  {
    Command<CommandLineHandler, TUPLE_STR_STR_INT, BreakpointSet>* lCommand =
      createCommand<BreakpointSet>(TUPLE_STR_STR_INT(), "bset", *this, "Set a breakpoint");

    lCommand->addArgument(0, "s", createArgType<TUPLE_STR_STR_INT, std::string, 0>(TUPLE_STR_STR_INT()), "breakpoint state (optional, 'enabled' or 'disabled', default: enabled)", false);
    lCommand->addArgument(1, "f", createArgType<TUPLE_STR_STR_INT, std::string, 1>(TUPLE_STR_STR_INT()), "name of the file where to stop", true);
    lCommand->addArgument(2, "l", createArgType<TUPLE_STR_STR_INT, int, 2>(TUPLE_STR_STR_INT()), "line number", true);
      
    theCommandLine << lCommand;
  }

  // DBGP: breakpoint_get
  {
    Command<CommandLineHandler, TUPLE_INT, BreakpointGet>* lCommand =
      createCommand<BreakpointGet>(TUPLE_INT(), "bget", *this, "Get information about a given breakpoint");

    lCommand->addArgument(0, "d", createArgType<TUPLE_INT, int, 0>(TUPLE_INT()), "breakpoint ID", true);
      
    theCommandLine << lCommand;
  }

  // DBGP: breakpoint_remove
  {
    Command<CommandLineHandler, TUPLE_INT, BreakpointRemove>* lCommand = 
      createCommand<BreakpointRemove>(TUPLE_INT(), "bremove", *this, "Delete a breakpoint");

    lCommand->addArgument(0, "d", createArgType<TUPLE_INT, int, 0>(TUPLE_INT()), "breakpoint ID", true);
      
    theCommandLine << lCommand;
  }

  // DBGP: breakpoint_list
  theCommandLine << createCommand<BreakpointList>(TUPLE(), "blist", *this, "List all set breakpoints");

  // DBGP: stack_depth
  theCommandLine << createCommand<StackDepth>(TUPLE(), "sdepth", *this, "Get the depth of the stack");

  // DBGP: stack_get
  {
    Command<CommandLineHandler, TUPLE_INT, StackGet>* lCommand =
      createCommand<StackGet>(TUPLE_INT(), "sget", *this, "Get information about one or all stack frames");

    lCommand->addArgument(0, "d", createArgType<TUPLE_INT, int, 0>(TUPLE_INT()), "stack frame to show: 0 for current stack frame, N for the main module (optional, all frames are shown if not provided)", false);

    theCommandLine << lCommand;
  }

  // DBGP: context_names
  theCommandLine << createCommand<ContextNames>(tuple<>(), "cnames", *this, "Get the names of the avilable contexts");
  // the DBGP -d arguments for this command is omitted since we always have/return: 0 - Local, 1 - Global

  // DBGP: context_get
  {
    Command<CommandLineHandler, TUPLE_INT_INT, ContextGet>* lCommand =
      createCommand<ContextGet>(TUPLE_INT_INT(), "cget", *this, "Get a context (list variables in this context)");

    lCommand->addArgument(0, "d", createArgType<TUPLE_INT_INT, int, 0>(TUPLE_INT_INT()), "stack depth (optional, default: 0)", false);
    lCommand->addArgument(0, "c", createArgType<TUPLE_INT_INT, int, 1>(TUPLE_INT_INT()), "context ID: 0 for Local, 1 for Global (optional, default: 0)", false);

    theCommandLine << lCommand;
  }

  // DBGP: source
  {
    Command<CommandLineHandler, TUPLE_INT_INT_STR, Source>* lCommand =
      createCommand<Source>(TUPLE_INT_INT_STR(), "source", *this, "List source code");

    lCommand->addArgument(0, "b", createArgType<TUPLE_INT_INT_STR, int, 0>(TUPLE_INT_INT_STR()), "begin line (optional, default: first line)", false);
    lCommand->addArgument(1, "e", createArgType<TUPLE_INT_INT_STR, int, 1>(TUPLE_INT_INT_STR()), "end line (optional, default: last line)", false);
    lCommand->addArgument(2, "f", createArgType<TUPLE_INT_INT_STR, std::string, 2>(TUPLE_INT_INT_STR()), "file URI (optional, default: the file in the top-most stack frame during execution, main module otherwise)", false);

    theCommandLine << lCommand;
  }

  // DBGP: eval
  {
    Command<CommandLineHandler, TUPLE_STR, Eval>* lCommand =
      createCommand<Eval>(TUPLE_STR(), "eval", *this, "Evaluate an expression");

    // TODO: this argument should not be here at all. Eval has the form: eval -i transaction_id -- {DATA}
    // Eval should be called with a command like: eval 1 + 3
    // - no need for an argument name
    // - everything following the fist contiguous set of whitespaces are sent as string
    lCommand->addArgument(0, "c", createArgType<TUPLE_STR, std::string, 0>(TUPLE_STR()), "expression to evaluate", true);
      
    theCommandLine << lCommand;
  }

  // DBGP: step_in
  theCommandLine << createCommand<StepIn>(TUPLE(), "in", *this, "Step in");

  // DBGP: step_out
  theCommandLine << createCommand<StepOut>(TUPLE(), "out", *this, "Step out");

  // DBGP: step_over
  theCommandLine << createCommand<StepOver>(TUPLE(), "over", *this, "Step over");
}
  
} // namespace zorba
} // namespace debugger
