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

#include "debugger/synchronous_logger.h"

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

using namespace std;

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
	zorba::synchronous_logger::cout << "         ___________\n";
	zorba::synchronous_logger::cout << "        /  .        \\\n";
	zorba::synchronous_logger::cout << " - - - |    .  :     \\\n";
	zorba::synchronous_logger::cout << "       |.    :    . . |  <-- Schnitzel\n";
	zorba::synchronous_logger::cout << " -- - /   .    .       \\\n";
	zorba::synchronous_logger::cout << "      \\.    :     : : /\n";
	zorba::synchronous_logger::cout << " - - - \\       .      |\n";
	zorba::synchronous_logger::cout << "        |_____________|\n";
	zorba::synchronous_logger::cout << "        /   \\     /   \\\n";
	zorba::synchronous_logger::cout << "       |  @  |    |  @  |\n";
	zorba::synchronous_logger::cout << "        \\___/     \\___/\n";
}

namespace zorba{

	DebuggerHandler::DebuggerHandler(Zorba* aZorba, DebuggerClient* aClient, std::string aFileName):
	theZorba(aZorba), theClient(aClient), theFileName(aFileName), theInterrupt(false)
  {
    suspendimpl::Suspend::setHandler(this);
    signal(SIGINT, handle_signal);
  }

	DebuggerHandler::~DebuggerHandler(){ /*we don't have the ownership on the client */ }

	vector<string> DebuggerHandler::getArgs(const string& str) const
	{
		string::size_type lastPos = str.find_first_not_of(' ', 0);
		string::size_type pos = str.find_first_of(' ', lastPos);
		vector<string> tokens;
		while(string::npos != pos || string::npos != lastPos)
		{
			tokens.push_back(str.substr(lastPos, pos-lastPos));
			lastPos = str.find_first_not_of(' ', pos);
			pos = str.find_first_of(' ', lastPos);
		}
		return tokens;
	}

	string DebuggerHandler::getExpression(const vector<string>& args) const
	{
		string lExpr;
		vector<string>::const_iterator it;
		for(it=args.begin()+1; it!=args.end(); ++it)
		{
			lExpr += *it;
			lExpr += ' ';
		}
		return lExpr;
	}

bool
DebuggerHandler::addBreakpoint(const vector<string>& args) const
{
	assert(theClient != 0);
	if (args.size() < 2 || args.size() > 3) {
		synchronous_logger::cerr << "Invalid syntax.\n";
		synchronous_logger::cerr << "(break | b) [<file_name> | <namespace>] <line_number>\n";
		return false;
	}

	string lNamespace;
	int lLine;
	if(args.size() == 2) {
		lNamespace = theFileName;
    if(!readInteger(args.at(1), lLine)) {
      synchronous_logger::cerr << "The value must be a positive integer."
          << "\n";
		  return false;
    }
	} else {
		lNamespace = args.at(1);
		lLine = atoi(args.at(2).c_str());
	}
	QueryLocation_t lLocation(theClient->addBreakpoint(lNamespace, lLine));
  if(lLocation == 0) {
		synchronous_logger::cerr << "Couldn't find an expression to break in "
        << lNamespace << " at line " << lLine << "\n";
    return false;
	} else {
		synchronous_logger::cerr << "Set breakpoint at: "
        << lLocation.get()->toString().c_str() << "\n";
	}
  return true;
}

bool
DebuggerHandler::addWatchpoint(const vector<string>& args) const
{
	assert(theClient != 0);
	if(args.size() < 2) {
		synchronous_logger::cerr << "Invalid syntax." << "\n";
		synchronous_logger::cerr << "(watch | w) <expression>" << "\n";
		return false;
	}
	String lExpr(getExpression(args));
	theClient->addBreakpoint(lExpr);
	synchronous_logger::cerr << "Add watchpoint: " << lExpr.c_str() << "\n";
  return true;
}

bool
DebuggerHandler::resume() const
{
	assert(theClient != 0);
  if (theClient->isQueryIdle()) {
    synchronous_logger::cerr << "The execution can be resumed only when a query is suspended.\n";
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
		synchronous_logger::cerr << "The query is running." << "\n";
	} else if (theClient->isQueryIdle()) {
		synchronous_logger::cerr << "The query is idle." << "\n";
	} else if (theClient->isQuerySuspended()) {
		synchronous_logger::cerr << "The query is suspended." << "\n";
	} else if (theClient->isQueryTerminated()) {
		synchronous_logger::cerr << "The query is terminated." << "\n";
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
			  synchronous_logger::cerr << "id: " << it->first << "\t" << it->second
            << "\n";
      }
    } else if (args.at(1) == "all") {
		  list(theFileName);
	  } else {
      int lLine;
      if (readInteger(args.at(1), lLine)) {
        if (lSuspended) {
          if (lLine < 0) {
            synchronous_logger::cerr
                << "The value must be a positive integer." << "\n";
            return false;
          }
          list(*theClient->getLocation(), lLine);
        } else {
          list(theFileName);
        }
      } else {
        synchronous_logger::cerr << "Not implemented." << "\n";
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
		synchronous_logger::cerr << "All breakpoints have been cleared." << "\n";
	} else if (args.size() >= 2 && atoi(args.at(1).c_str()) > 0) {
		bool lResult = theClient->clearBreakpoint( atoi(args.at(1).c_str()) );
		if (lResult) {
			synchronous_logger::cerr << "Breakpoint " << atoi(args.at(1).c_str()) << " has been cleared.\n";
		} else {
			synchronous_logger::cerr << "The breakpoint " << atoi(args.at(1).c_str()) << " doesn't exist.\n";
		}
	} else {
		synchronous_logger::cerr << "Invalid syntax.\n";
		synchronous_logger::cerr << "(clear | cl) (<breakpoint_id> | all)\n";
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
    synchronous_logger::cerr << "The variables are only available while execution is suspended.\n";
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
	synchronous_logger::cerr << "Global variables:\n";
	for (it = global.begin(); it != global.end(); it++) {
		synchronous_logger::cerr << "$" << it->getName() << " " << it->getType() << "\n";
	}
  synchronous_logger::cerr << "\nLocal variables:\n";
	for (it = locals.begin(); it!=locals.end(); it++) {
		synchronous_logger::cerr << "$" << it->getName() << " " << it->getType() << "\n";
	}
  return true;
}

bool
DebuggerHandler::eval(const vector<string>& args)
{
	assert(theClient != 0);
  if (theClient->isQueryIdle()) {
    synchronous_logger::cerr << "Expressions can be evaluated only when a query is suspended.\n";
    status();
    return false;
  }
	if (args.size() < 2) {
		synchronous_logger::cerr << "Invalid syntax.\n";
		synchronous_logger::cerr << "(eval | e | print| p) <expression>\n";
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
    cerr << endl;
    cerr << "Usage: (run | r)" << endl;
    cerr << endl;
    cerr << "Run the query. If the query is suspended, this command restarts "
         << "the execution." << endl;
    cerr << endl;
  } else if (aArgs[1] == "continue" || aArgs[1] == "c") {
    cerr << endl;
    cerr << "Usage: (continue | c)" << endl;
    cerr << endl;
    cerr << "Continue the execution if the query is suspended" << endl;
    cerr << endl;
  } else if (aArgs[1] == "status" || aArgs[1] == "st") {
    cerr << endl;
    cerr << "Usage: (status | st)" << endl;
    cerr << endl;
    cerr << "Print the current status of the engine." << endl;
    cerr << endl;
    cerr << "Possible status values are:" << endl;
    cerr << " - IDLE - This status is received before the execution of the "
         << "query or after the execution terminates." << endl;
    cerr << " - SUSPENDED - When the query is suspended during the by a "
         << "breakpoint or by a user request." << endl;
    cerr << endl;
  } else if (aArgs[1] == "where" || aArgs[1] == "loc") {
    cerr << endl;
    cerr << "Usage: (where | loc)" << endl;
    cerr << endl;
    cerr << "NOT IMPLEMENTED!" << endl;
    cerr << "Displays the location where the execution currently is. The "
         << "result can be used for setting breakpoints." << endl;
    cerr << endl;
  } else if (aArgs[1] == "quit" || aArgs[1] == "q") {
    cerr << endl;
    cerr << "Usage: (quit | q)" << endl;
    cerr << endl;
    cerr << "Terminate the execution and quit the debugger." << endl;
    cerr << endl;
  } else if (aArgs[1] == "break" || aArgs[1] == "b") {
    cerr << endl;
    cerr << "Usage: (break | b) [(file_name | namespace)] <line_number>" << endl;
    cerr << endl;
    cerr << "Sets a breakpoint at a given location. This command handles both"
         << "file paths and module namespaces." << endl;
    cerr << endl;
  } else if (aArgs[1] == "watch" || aArgs[1] == "w") {
    cerr << endl;
    cerr << "Usage: (watch | w) <expression>" << endl;
    cerr << endl;
    cerr << "NOT IMPLEMENTED!" << endl;
    cerr << endl;
  } else if (aArgs[1] == "list" || aArgs[1] == "l") {
    cerr << endl;
    cerr << "Usage: (list | l) [<arg>]" << endl;
    cerr << endl;
    cerr << "List XQuery source code or breakpoints." << endl;
    cerr << endl;
    cerr << "The argument is optional. With no argument, when "
         << "the execution is IDLE, the entire source code of the main "
         << "module is displayed. During the SUSPENDED state the command "
         << "displays the source code of the module where the execution is "
         << "suspended. In the SUSPENDED state, only 5 lines below and "
         << "above the location where the execution is suspended are "
         << "displayed." << endl;
    cerr << endl;
    cerr << "The optional argument can take one of the following  values:"
         << endl;
    cerr << " - b: list all set breakpoints." << endl;
    cerr << " - all: list all the source code of the module where the "
         << "execution is suspended" << endl;
    cerr << " - INTEGER: a positive integer controlling how many lines of "
         << "code to be displayed before and after the location where the "
         << "execution is suspended." << endl;
    cerr << " - FILENAME: list the source of the module with the given "
         << "filename." << endl;
    cerr << " - NAMESPACE: list the source of the module having the given "
         << "namespace." << endl;
    cerr << endl;
  } else if (aArgs[1] == "clear" || aArgs[1] == "cl") {
    cerr << endl;
    cerr << "Usage: (clear | cl) <breakpoint_id>" << endl;
    cerr << endl;
    cerr << "Deletes a breakpoint with a given id. This id can be found "
         << "using the command \"list b\"" << endl;
    cerr << endl;
  } else if (aArgs[1] == "over" || aArgs[1] == "next" || aArgs[1] == "n"
      || aArgs[1] == "step" || aArgs[1] == "so") {
    cerr << endl;
    cerr << "Usage: (over | so | step | next | n)" << endl;
    cerr << endl;
    cerr << "Steps to the next breakable expression on the same level."
         << endl;
    cerr << endl;
  } else if (aArgs[1] == "in" || aArgs[1] == "si") {
    cerr << endl;
    cerr << "Usage: (in | si)" << endl;
    cerr << endl;
    cerr << "Steps to the next breabable expression." << endl;
    cerr << endl;
  } else if (aArgs[1] == "out" || aArgs[1] == "sr" || aArgs[1] == "return") {
    cerr << endl;
    cerr << "Usage: (out | sr | return)" << endl;
    cerr << endl;
    cerr << "Steps to the parent breakable expression." << endl;
    cerr << endl;
  } else if (aArgs[1] == "vars" || aArgs[1] == "variables"
      || aArgs[1] == "var" || aArgs[1] == "var" || aArgs[1] == "v") {
    cerr << endl;
    cerr << "Usage: (variables | vars | var | v)" << endl;
    cerr << endl;
    cerr << "Lists all variable in the current scope." << endl;
    cerr << endl;
  } else if (aArgs[1] == "eval" || aArgs[1] == "print" || aArgs[1] == "p"
      || aArgs[1] == "e") {
    cerr << endl;
    cerr << "Usage: (eval | e | print | p) <expression>" << endl;
    cerr << endl;
    cerr << "Executes an XQuery expression in the current scope." << endl;
    cerr << endl;
  } else {
    printDefaultHelp();
  }
  return true;
}

void
DebuggerHandler::printDefaultHelp() const
{
  cerr << "List of available commands" << endl;
  cerr << endl;
  cerr << "Execution commands:" << endl;
  cerr << "  run, r      -- Start the query execution." << endl;
  cerr << "  continue, c -- Resume the query execution." << endl;
  cerr << "  status, st  -- Display the status of the query." << endl;
  cerr << "  quit, q     -- Quit the debugger." << endl;
  cerr << "  over, so, step, next, n" << endl;
  cerr << "              -- Step over the current expression." << endl;
  cerr << "  in, si      -- Step in a nested expression." << endl;
  cerr << "  out, sr, return" << endl;
  cerr << "              -- Step out from a nested expression." << endl;
  cerr << endl;
  cerr << "Breakpoint and source commands:" << endl;
  cerr << "  break, b    -- Set a breakpoint at the specified file and line." << endl;
  //cerr << "  watch, w    -- Add watchpoint to the query" << endl;
  cerr << "  clear, cl   -- Clear breakpoints." << endl;
  cerr << "  list, l     -- Display source code and list breakpoints." << endl;
  cerr << "  where, loc  -- Print the runtime stack frame." << endl;
  cerr << endl;
  cerr << "Data commands:" << endl;
  cerr << "  variables, vars, var, v" << endl;
  cerr << "              -- List all variables that are in scope." << endl;
  cerr << "  eval, e, print, p" << endl;
  cerr << "              -- Evaluate an xquery expression and print its result." << endl;
  cerr << endl;
  cerr << "Other commands:" << endl;
  cerr << "  help, h     -- This help. Use \"help <command>\" for more command details." << endl;
  cerr << endl;
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
    synchronous_logger::cerr << "Step commands can be used only when the query is suspended.\n";
    status();
    return false;
  }
  return true;
}

istream*
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

  std::auto_ptr<istream> lInput(lSource);
	if (lInput.get() != 0) {
		unsigned int lLineNo = 0;
		while (lInput->good()) {
			lLineNo++;
			string lLine;
			getline(*lInput, lLine, '\n');
			synchronous_logger::cerr << lLineNo << "\t" << lLine << "\n";
		}
	} else {
		cerr << "Couldn't find the query file for " << aNamespace << "\n";
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
	auto_ptr<istream> lInput(getSource(lStringURI));
	if (lInput.get() != 0) {
		unsigned int lLineBegin = aLocation.getLineBegin();
		unsigned int lLineEnd = aLocation.getLineEnd();
		unsigned int lColumnBegin = aLocation.getColumnBegin();
		unsigned int lColumnEnd = aLocation.getColumnEnd();
    unsigned int lLineNo = max((int)lLineBegin - (aLines + 1), 0);
		string lLine;
		synchronous_logger::cout << "\n";
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
				synchronous_logger::cerr << lLineNo << "\t";
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
				cerr << "\033[1m" << lLineNo << '\t' << "\033[0m";
				for (unsigned int j=1; j<=lLine.length(); j++) {
					if ((lLineNo==lLineBegin && j >= lColumnBegin) ||
						  (lLineBegin != lLineEnd && lLineNo==lLineEnd && j <= lColumnEnd) ||
						  (lLineNo > lLineBegin && lLineEnd))
					{
						cerr << "\033[1m" << lLine.at(j-1) << "\033[0m";
					} else {
						cerr << lLine.at(j-1);
					}
				}
#endif
				synchronous_logger::cerr << "\n";
			} else {
				synchronous_logger::cerr << lLineNo << "\t" << lLine << "\n";
			}
		}
		synchronous_logger::cerr << "\n";
	} else {
		synchronous_logger::cerr << "Could'nt find the query file for " << lStringURI << "\n";
    return false;
	}
  return true;
}

bool DebuggerHandler::where() const
{
	StackFrame_t lStack(theClient->getStack());
	while (!lStack->empty()) {
		const Frame* lFrame = lStack->top();
		synchronous_logger::cerr << lFrame->getSignature() << ' ' << lFrame->getLocation()->toString() << "\n";
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
    cin.setstate(ios_base::eofbit);
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
	  	synchronous_logger::cerr << "(xqdb) ";
	  	string lLine;
	  	getline(cin, lLine, '\n');
	  	if (lLine == "") {
	  		continue;
	  	}
	  	vector<string> lArgs = getArgs(lLine);
	  	string lCommand = lArgs.at(0);

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
        cerr << "Unknown command: " << lCommand << endl;
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
	synchronous_logger::cout << "Query suspended at " << aLocation.toString() << "\n";
	list(aLocation);
	handle();
}

void
DebuggerHandler::resumed()
{
	synchronous_logger::cout << "Continue...\n";
}

void
DebuggerHandler::terminated()
{
	synchronous_logger::cout << "\n...End of query\n";
}

void
DebuggerHandler::evaluated(zorba::String &anExpr, std::list< pair<String, String> > &aValuesAndTypes)
{
	std::list< pair<String, String> >::iterator it;
	for (it=aValuesAndTypes.begin(); it!=aValuesAndTypes.end(); ++it)	{
		synchronous_logger::cout << it->first << " " << it->second << "\n";
	}
	handle();
}

void
DebuggerHandler::evaluated(String& anExpr, String& anError)
{
	synchronous_logger::cout << anError << "\n";
	handle();
}

}//end of namespace
