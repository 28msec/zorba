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

#include "debugger_handler.h"

#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#ifdef WIN32
#include <windows.h>
#endif
#include <zorba/zorba.h>
#include <zorba/uri_resolvers.h>
#include <zorba/debugger_client.h>

#include "zorbautils/synchronous_logger.h"

namespace zorba {
namespace suspendimpl {
  class Suspend {
    public:
      static void setHandler(DebuggerHandler* aHandler) {
        theHandler = aHandler;
      }
      static DebuggerHandler* getHandler() {
        return theHandler;
      }

    private:
      static DebuggerHandler* theHandler;
  };
  DebuggerHandler* Suspend::theHandler = 0;
}
}

static void exec_suspend() {
  zorba::DebuggerHandler* aHandler = zorba::suspendimpl::Suspend::getHandler();
  aHandler->suspend();
}

extern "C" {
  void handle_signal(int signum) {
    signal(SIGINT, handle_signal);
    exec_suspend();
  }
}

static void printSchnitzel() {
  zorba::cout << "         ___________\n";
  zorba::cout << "        /  .        \\\n";
  zorba::cout << " - - - |    .  :     \\\n";
  zorba::cout << "       |.    :    . . |  <-- Schnitzel\n";
  zorba::cout << " -- - /   .    .       \\\n";
  zorba::cout << "      \\.    :     : : /\n";
  zorba::cout << " - - - \\       .      |\n";
  zorba::cout << "        |_____________|\n";
  zorba::cout << "        /   \\     /   \\\n";
  zorba::cout << "       |  @  |    |  @  |\n";
  zorba::cout << "        \\___/     \\___/\n";
}

namespace zorba{

  DebuggerHandler::DebuggerHandler(Zorba* aZorba, DebuggerClient* aClient, std::string aFileName):
  theZorba(aZorba), theClient(aClient), theFileName(aFileName), theInterrupt(false)
  {
    suspendimpl::Suspend::setHandler(this);
    signal(SIGINT, handle_signal);
  }

  DebuggerHandler::~DebuggerHandler(){ /*we don't have the ownership on the client */ }

std::vector<std::string>
DebuggerHandler::getArgs(const std::string& str) const
{
  std::string::size_type lastPos = str.find_first_not_of(' ', 0);
  std::string::size_type pos = str.find_first_of(' ', lastPos);
  std::vector<std::string> tokens;
  while (std::string::npos != pos || std::string::npos != lastPos) {
    tokens.push_back(str.substr(lastPos, pos-lastPos));
    lastPos = str.find_first_not_of(' ', pos);
    pos = str.find_first_of(' ', lastPos);
  }
  return tokens;
}

std::string
DebuggerHandler::getExpression(const std::vector<std::string>& args) const
{
  std::string lExpr;
  std::vector<std::string>::const_iterator it;
  for (it = args.begin() + 1; it != args.end(); ++it) {
    lExpr += *it;
    lExpr += ' ';
  }
  return lExpr;
}

bool
DebuggerHandler::addBreakpoint(const std::vector<std::string>& args) const
{
  assert(theClient != 0);
  if (args.size() < 2 || args.size() > 3) {
    zorba::cerr << "Invalid syntax.\n";
    zorba::cerr << "(break | b) [<file_name> | <namespace>] <line_number>\n";
    return false;
  }

  std::string lNamespace;
  int lLine;
  if (args.size() == 2) {
    lNamespace = theFileName;
    if (!readInteger(args.at(1), lLine)) {
      zorba::cerr << "The value must be a positive integer."
          << "\n";
      return false;
    }
  } else {
    lNamespace = args.at(1);
    lLine = atoi(args.at(2).c_str());
  }
  QueryLocation_t lLocation(theClient->addBreakpoint(lNamespace, lLine));
  if(lLocation == 0) {
    zorba::cerr << "Couldn't find an expression to break in "
        << lNamespace << " at line " << lLine << "\n";
    return false;
  } else {
    zorba::cerr << "Set breakpoint at: "
        << lLocation.get()->toString().c_str() << "\n";
  }
  return true;
}

bool
DebuggerHandler::addWatchpoint(const std::vector<std::string>& args) const
{
  assert(theClient != 0);
  if(args.size() < 2) {
    zorba::cerr << "Invalid syntax." << "\n";
    zorba::cerr << "(watch | w) <expression>" << "\n";
    return false;
  }
  String lExpr(getExpression(args));
  theClient->addBreakpoint(lExpr);
  zorba::cerr << "Add watchpoint: " << lExpr.c_str() << "\n";
  return true;
}

bool
DebuggerHandler::resume() const
{
  assert(theClient != 0);
  if (theClient->isQueryIdle()) {
    zorba::cerr << "The execution can be resumed only when a query is suspended.\n";
    status();
    return false;
  }

  theClient->resume();
  return true;
}

bool
DebuggerHandler::run() const
{
  assert(theClient != 0);
  theClient->run();
  return true;
}

bool
DebuggerHandler::terminateQuery() const
{
  assert(theClient != 0);
  theClient->terminate();
  return true;
}

bool
DebuggerHandler::status() const
{
  assert(theClient != 0);
  if(theClient->isQueryRunning()) {
    zorba::cerr << "The query is running." << "\n";
  } else if (theClient->isQueryIdle()) {
    zorba::cerr << "The query is idle." << "\n";
  } else if (theClient->isQuerySuspended()) {
    zorba::cerr << "The query is suspended." << "\n";
  } else if (theClient->isQueryTerminated()) {
    zorba::cerr << "The query is terminated." << "\n";
  }
  return true;
}

bool
DebuggerHandler::list(const std::vector<std::string>& args) const
{
  bool lSuspended = theClient->isQuerySuspended();

  if (args.size() == 1) {
    if (lSuspended) {
      list(*theClient->getLocation());
    } else {
      list(theFileName);
    }
  } else if (args.size() == 2) {
    if (args.at(1) == "b") {
      std::map<unsigned int, String> lBreakpoints = theClient->getBreakpoints();
      std::map<unsigned int, String>::const_iterator it;
      for (it=lBreakpoints.begin(); it!=lBreakpoints.end(); ++it) {
        zorba::cerr << "id: " << it->first << "\t" << it->second
            << "\n";
      }
    } else if (args.at(1) == "all") {
      list(theFileName);
    } else {
      int lLine;
      if (readInteger(args.at(1), lLine)) {
        if (lSuspended) {
          if (lLine < 0) {
            zorba::cerr
                << "The value must be a positive integer." << "\n";
            return false;
          }
          list(*theClient->getLocation(), lLine);
        } else {
          list(theFileName);
        }
      } else {
        zorba::cerr << "Not implemented." << "\n";
        return false;

        // TODO: if NAMESPACE
        const String lStringURI(args.at(1));
        list(lStringURI);

        // TODO: if FILENAME
        // ...

        // TODO: else error
      }

    }
  }
  return true;
}

bool
DebuggerHandler::clear(const std::vector<std::string>& args)
{
  if (args.size() >= 2 && args.at(1) == "all") {
    theClient->clearBreakpoints();
    zorba::cerr << "All breakpoints have been cleared." << "\n";
  } else if (args.size() >= 2 && atoi(args.at(1).c_str()) > 0) {
    bool lResult = theClient->clearBreakpoint( atoi(args.at(1).c_str()) );
    if (lResult) {
      zorba::cerr << "Breakpoint " << atoi(args.at(1).c_str()) << " has been cleared.\n";
    } else {
      zorba::cerr << "The breakpoint " << atoi(args.at(1).c_str()) << " doesn't exist.\n";
    }
  } else {
    zorba::cerr << "Invalid syntax.\n";
    zorba::cerr << "(clear | cl) (<breakpoint_id> | all)\n";
    return false;
  }
  return true;
}

bool
DebuggerHandler::stepIn() const
{
  if(!canStep()) {
    return false;
  }

  theClient->stepInto();
  return true;
}

bool
DebuggerHandler::stepOut() const
{
  if(!canStep()) {
    return false;
  }

  theClient->stepOut();
  return true;
}

bool
DebuggerHandler::stepOver() const
{
  if(!canStep()) {
    return false;
  }

  theClient->stepOver();
  return true;
}

bool
DebuggerHandler::variables() const
{
  assert(theClient != 0);

  if (!theClient->isQuerySuspended()) {
    zorba::cerr << "The variables are only available while execution is suspended.\n";
    return false;
  }

  std::list<Variable> global;
  std::list<Variable> locals;
  try {
     global = theClient->getGlobalVariables();
     locals = theClient->getLocalVariables();
  } catch (std::exception const& ex) {
    std::cerr << ex.what() << std::endl;
    return false;
  }
  std::list<Variable>::iterator it;
  zorba::cerr << "Global variables:\n";
  for (it = global.begin(); it != global.end(); it++) {
    zorba::cerr << "$" << it->getName() << " " << it->getType() << "\n";
  }
  zorba::cerr << "\nLocal variables:\n";
  for (it = locals.begin(); it!=locals.end(); it++) {
    zorba::cerr << "$" << it->getName() << " " << it->getType() << "\n";
  }
  return true;
}

bool
DebuggerHandler::eval(const std::vector<std::string>& args)
{
  assert(theClient != 0);
  if (theClient->isQueryIdle()) {
    zorba::cerr << "Expressions can be evaluated only when a query is suspended.\n";
    status();
    return false;
  }
  if (args.size() < 2) {
    zorba::cerr << "Invalid syntax.\n";
    zorba::cerr << "(eval | e | print| p) <expression>\n";
    return false;
  } else {
    String lExpr(getExpression(args));
    theClient->eval(lExpr);
  }
  return true;
}

bool
DebuggerHandler::help(const std::vector<std::string>& aArgs) const
{
  if (aArgs.size() < 2) {
    printDefaultHelp();
  } else if (aArgs[1] == "run" || aArgs[1] == "r") {
    std::cerr << std::endl;
    std::cerr << "Usage: (run | r)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Run the query. If the query is suspended, this command restarts "
         << "the execution." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "continue" || aArgs[1] == "c") {
    std::cerr << std::endl;
    std::cerr << "Usage: (continue | c)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Continue the execution if the query is suspended" << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "status" || aArgs[1] == "st") {
    std::cerr << std::endl;
    std::cerr << "Usage: (status | st)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Print the current status of the engine." << std::endl;
    std::cerr << std::endl;
    std::cerr << "Possible status values are:" << std::endl;
    std::cerr << " - IDLE - This status is received before the execution of the "
         << "query or after the execution terminates." << std::endl;
    std::cerr << " - SUSPENDED - When the query is suspended during the by a "
         << "breakpoint or by a user request." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "where" || aArgs[1] == "loc") {
    std::cerr << std::endl;
    std::cerr << "Usage: (where | loc)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "NOT IMPLEMENTED!" << std::endl;
    std::cerr << "Displays the location where the execution currently is. The "
         << "result can be used for setting breakpoints." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "quit" || aArgs[1] == "q") {
    std::cerr << std::endl;
    std::cerr << "Usage: (quit | q)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Terminate the execution and quit the debugger." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "break" || aArgs[1] == "b") {
    std::cerr << std::endl;
    std::cerr << "Usage: (break | b) [(file_name | namespace)] <line_number>" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Sets a breakpoint at a given location. This command handles both"
         << "file paths and module namespaces." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "watch" || aArgs[1] == "w") {
    std::cerr << std::endl;
    std::cerr << "Usage: (watch | w) <expression>" << std::endl;
    std::cerr << std::endl;
    std::cerr << "NOT IMPLEMENTED!" << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "list" || aArgs[1] == "l") {
    std::cerr << std::endl;
    std::cerr << "Usage: (list | l) [<arg>]" << std::endl;
    std::cerr << std::endl;
    std::cerr << "List XQuery source code or breakpoints." << std::endl;
    std::cerr << std::endl;
    std::cerr << "The argument is optional. With no argument, when "
         << "the execution is IDLE, the entire source code of the main "
         << "module is displayed. During the SUSPENDED state the command "
         << "displays the source code of the module where the execution is "
         << "suspended. In the SUSPENDED state, only 5 lines below and "
         << "above the location where the execution is suspended are "
         << "displayed." << std::endl;
    std::cerr << std::endl;
    std::cerr << "The optional argument can take one of the following  values:"
         << std::endl;
    std::cerr << " - b: list all set breakpoints." << std::endl;
    std::cerr << " - all: list all the source code of the module where the "
         << "execution is suspended" << std::endl;
    std::cerr << " - INTEGER: a positive integer controlling how many lines of "
         << "code to be displayed before and after the location where the "
         << "execution is suspended." << std::endl;
    std::cerr << " - FILENAME: list the source of the module with the given "
         << "filename." << std::endl;
    std::cerr << " - NAMESPACE: list the source of the module having the given "
         << "namespace." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "clear" || aArgs[1] == "cl") {
    std::cerr << std::endl;
    std::cerr << "Usage: (clear | cl) <breakpoint_id>" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Deletes a breakpoint with a given id. This id can be found "
         << "using the command \"list b\"" << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "over" || aArgs[1] == "next" || aArgs[1] == "n"
      || aArgs[1] == "step" || aArgs[1] == "so") {
    std::cerr << std::endl;
    std::cerr << "Usage: (over | so | step | next | n)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Steps to the next breakable expression on the same level."
         << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "in" || aArgs[1] == "si") {
    std::cerr << std::endl;
    std::cerr << "Usage: (in | si)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Steps to the next breabable expression." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "out" || aArgs[1] == "sr" || aArgs[1] == "return") {
    std::cerr << std::endl;
    std::cerr << "Usage: (out | sr | return)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Steps to the parent breakable expression." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "vars" || aArgs[1] == "variables"
      || aArgs[1] == "var" || aArgs[1] == "var" || aArgs[1] == "v") {
    std::cerr << std::endl;
    std::cerr << "Usage: (variables | vars | var | v)" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Lists all variable in the current scope." << std::endl;
    std::cerr << std::endl;
  } else if (aArgs[1] == "eval" || aArgs[1] == "print" || aArgs[1] == "p"
      || aArgs[1] == "e") {
    std::cerr << std::endl;
    std::cerr << "Usage: (eval | e | print | p) <expression>" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Executes an XQuery expression in the current scope." << std::endl;
    std::cerr << std::endl;
  } else {
    printDefaultHelp();
  }
  return true;
}

void
DebuggerHandler::printDefaultHelp() const
{
  std::cerr << "List of available commands" << std::endl;
  std::cerr << std::endl;
  std::cerr << "Execution commands:" << std::endl;
  std::cerr << "  run, r      -- Start the query execution." << std::endl;
  std::cerr << "  continue, c -- Resume the query execution." << std::endl;
  std::cerr << "  status, st  -- Display the status of the query." << std::endl;
  std::cerr << "  quit, q     -- Quit the debugger." << std::endl;
  std::cerr << "  over, so, step, next, n" << std::endl;
  std::cerr << "              -- Step over the current expression." << std::endl;
  std::cerr << "  in, si      -- Step in a nested expression." << std::endl;
  std::cerr << "  out, sr, return" << std::endl;
  std::cerr << "              -- Step out from a nested expression." << std::endl;
  std::cerr << std::endl;
  std::cerr << "Breakpoint and source commands:" << std::endl;
  std::cerr << "  break, b    -- Set a breakpoint at the specified file and line." << std::endl;
  //cerr << "  watch, w    -- Add watchpoint to the query" << std::endl;
  std::cerr << "  clear, cl   -- Clear breakpoints." << std::endl;
  std::cerr << "  list, l     -- Display source code and list breakpoints." << std::endl;
  std::cerr << "  where, loc  -- Print the runtime stack frame." << std::endl;
  std::cerr << std::endl;
  std::cerr << "Data commands:" << std::endl;
  std::cerr << "  variables, vars, var, v" << std::endl;
  std::cerr << "              -- List all variables that are in scope." << std::endl;
  std::cerr << "  eval, e, print, p" << std::endl;
  std::cerr << "              -- Evaluate an xquery expression and print its result." << std::endl;
  std::cerr << std::endl;
  std::cerr << "Other commands:" << std::endl;
  std::cerr << "  help, h     -- This help. Use \"help <command>\" for more command details." << std::endl;
  std::cerr << std::endl;
}

bool
DebuggerHandler::readInteger(const std::string& aString, int& aResult) const
{
  std::istringstream lStream(aString);

  // try to read an INTEGER argument
  int lLine;
  lStream >> lLine;
  if (lStream.fail()) {
    return false;
  }
  aResult = lLine;
  return true;
}

bool
DebuggerHandler::canStep() const {
  assert(theClient != 0);
  if (theClient->isQueryIdle()) {
    zorba::cerr << "Step commands can be used only when the query is suspended.\n";
    status();
    return false;
  }
  return true;
}

std::istream*
DebuggerHandler::getSource(const String& aNamespace) const
{
  std::string lSource = theClient->listSource(aNamespace.c_str());
  if (lSource.length() == 0) {
    return NULL;
  }
  std::auto_ptr<std::istringstream> lStream(new std::istringstream());
  lStream->str(lSource);
  return lStream.release();
}

bool
DebuggerHandler::list(const String& aNamespace) const
{
  std::istream* lSource = getSource(aNamespace);
  if (lSource == 0) {
    return false;
  }

  std::auto_ptr<std::istream> lInput(lSource);
  if (lInput.get() != 0) {
    unsigned int lLineNo = 0;
    while (lInput->good()) {
      lLineNo++;
      std::string lLine;
      getline(*lInput, lLine, '\n');
      zorba::cerr << lLineNo << "\t" << lLine << "\n";
    }
  } else {
    std::cerr << "Couldn't find the query file for " << aNamespace << "\n";
    return false;
  }
  return true;
}

bool
DebuggerHandler::list(const QueryLocation& aLocation) const
{
  return list(aLocation, 5);
}

bool
DebuggerHandler::list(const QueryLocation& aLocation, int aLines) const
{
  const String lStringURI(aLocation.getFileName());
  std::auto_ptr<std::istream> lInput(getSource(lStringURI));
  if (lInput.get() != 0) {
    unsigned int lLineBegin = aLocation.getLineBegin();
    unsigned int lLineEnd = aLocation.getLineEnd();
    unsigned int lColumnBegin = aLocation.getColumnBegin();
    unsigned int lColumnEnd = aLocation.getColumnEnd();
    unsigned int lLineNo = std::max((int)lLineBegin - (aLines + 1), 0);
    std::string lLine;
    zorba::cout << "\n";
    while (lInput->good() && lLineNo <= lLineEnd + (aLines - 1)) {
      lLineNo++;
      getline(*lInput, lLine, '\n');
      unsigned int lBegin = (int)lLineBegin-10<0?0:lLineBegin-10;
      unsigned int lEnd = lLineEnd+10;
      if (lLineNo <= lBegin || lLineNo >= lEnd) {
        continue;
      }
      if (lLineNo >= lLineBegin && lLineNo <= lLineEnd) {
#ifdef WIN32
        HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO lConsoleInfo;
        GetConsoleScreenBufferInfo(lConsole, &lConsoleInfo);
        const int saved_configuration = lConsoleInfo.wAttributes;
        SetConsoleTextAttribute(lConsole, 15+0*16);
        zorba::cerr << lLineNo << "\t";
        SetConsoleTextAttribute(lConsole, saved_configuration);
        for (unsigned int j=1; j<=lLine.length(); j++) {
          // At this point it seems to be ok to just write to std::cerr
          // since other threads should be suspended at this time.
          if ((lLineNo==lLineBegin && j >= lColumnBegin) ||
              (lLineBegin != lLineEnd && lLineNo==lLineEnd && j <= lColumnEnd) ||
              (lLineNo > lLineBegin && lLineEnd)) {
            SetConsoleTextAttribute(lConsole, 15+0*16);
            std::cerr << lLine.at(j-1);
            SetConsoleTextAttribute(lConsole, saved_configuration);
          } else {
            std::cerr << lLine.at(j-1);
          }
        }
#else
        std::cerr << "\033[1m" << lLineNo << '\t' << "\033[0m";
        for (unsigned int j=1; j<=lLine.length(); j++) {
          if ((lLineNo==lLineBegin && j >= lColumnBegin) ||
              (lLineBegin != lLineEnd && lLineNo==lLineEnd && j <= lColumnEnd) ||
              (lLineNo > lLineBegin && lLineEnd))
          {
            std::cerr << "\033[1m" << lLine.at(j-1) << "\033[0m";
          } else {
            std::cerr << lLine.at(j-1);
          }
        }
#endif
        zorba::cerr << "\n";
      } else {
        zorba::cerr << lLineNo << "\t" << lLine << "\n";
      }
    }
    zorba::cerr << "\n";
  } else {
    zorba::cerr << "Could'nt find the query file for " << lStringURI << "\n";
    return false;
  }
  return true;
}

bool DebuggerHandler::where() const
{
  StackFrame_t lStack(theClient->getStack());
  while (!lStack->empty()) {
    const Frame* lFrame = lStack->top();
    zorba::cerr << lFrame->getSignature() << ' ' << lFrame->getLocation()->toString() << "\n";
    lStack->pop();
  }
  return true;
}

void
DebuggerHandler::suspend() {
  if (theClient->isQueryRunning()) {
    theClient->suspend();
  } else {
    theClient->terminate();
#ifdef WIN32
    std::cin.setstate(std::ios_base::eofbit);
#else
    close(0);
#endif
    theInterrupt = true;
  }
}

void
DebuggerHandler::handle()
{
  while (true) {
    if (!theInterrupt) {
      zorba::cerr << "(xqdb) ";
      std::string lLine;
      getline(std::cin, lLine, '\n');
      if (lLine == "") {
        continue;
      }
      std::vector<std::string> lArgs = getArgs(lLine);
      std::string lCommand = lArgs.at(0);

      if (lCommand == "r" || lCommand == "run") {
        if (run()) return;
      } else if (lCommand == "c" || lCommand == "continue") {
        if (resume()) return;
      } else if (lCommand == "q" || lCommand == "quit" ) {
        if (terminateQuery()) return;
      } else if (lCommand == "st" || lCommand == "status") {
        status();
      } else if (lCommand == "b" || lCommand == "break") {
        addBreakpoint(lArgs);
      } else if (lCommand == "w" || lCommand == "watch") {
        addWatchpoint(lArgs);
      } else if (lCommand == "l" || lCommand == "list") {
        list(lArgs);
      } else if (lCommand == "cl" || lCommand == "clear") {
        clear(lArgs);
      } else if (lCommand == "n" || lCommand == "so" || lCommand == "over" ||
            lCommand == "step" || lCommand == "next") {
        if (stepOver()) return;
      } else if (lCommand == "si" || lCommand == "in") {
        if (stepIn()) return;
      } else if (lCommand == "sr" || lCommand == "out" ||
          lCommand == "return") {
        if (stepOut()) return;
      } else if(lCommand == "v" || lCommand == "var" || lCommand == "vars" || lCommand == "variables"){
        variables();
      } else if(lCommand == "where" || lCommand == "loc"){
        where();
      } else if(lCommand == "p" || lCommand == "print" || lCommand == "e" || lCommand == "eval"){
        if (eval(lArgs)) return;
      } else if(lCommand == "h" || lCommand == "help"){
        help(lArgs);
      } else if (lCommand == "schnitzel") {
        printSchnitzel();
      } else {
        std::cerr << "Unknown command: " << lCommand << std::endl;
        printDefaultHelp();
      }
    } else {
      // cin not good
      // happens if user presses CTRL-C
      return;
    }
  } // while(true)
}

void
DebuggerHandler::started()
{
}

void
DebuggerHandler::idle()
{
  handle();
}

void
DebuggerHandler::suspended(QueryLocation& aLocation, SuspendedBy aCause)
{
  zorba::cout << "Query suspended at " << aLocation.toString() << "\n";
  list(aLocation);
  handle();
}

void
DebuggerHandler::resumed()
{
  zorba::cout << "Continue...\n";
}

void
DebuggerHandler::terminated()
{
  zorba::cout << "\n...End of query\n";
}

void
DebuggerHandler::evaluated(zorba::String &anExpr, std::list< std::pair<String, String> > &aValuesAndTypes)
{
  std::list< std::pair<String, String> >::iterator it;
  for (it = aValuesAndTypes.begin(); it != aValuesAndTypes.end(); ++it)  {
    zorba::cout << it->first << " " << it->second << "\n";
  }
  handle();
}

void
DebuggerHandler::evaluated(String& anExpr, String& anError)
{
  zorba::cout << anError << "\n";
  handle();
}

}//end of namespace
