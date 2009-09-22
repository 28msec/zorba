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
	zorba::synchronous_logger::cout << "      \\.    :     : :  /\n";
	zorba::synchronous_logger::cout << " - - - \\       .      |\n";
	zorba::synchronous_logger::cout << "        |_____________|\n";
	zorba::synchronous_logger::cout << "        /   \\     /   \\\n";
	zorba::synchronous_logger::cout << "       |  @  |   |  @  |\n";
	zorba::synchronous_logger::cout << "        \\___/     \\___/\n";
}

namespace zorba{

	DebuggerHandler::DebuggerHandler(Zorba* aZorba, ZorbaDebuggerClient* aClient, std::string aFileName):
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

	bool DebuggerHandler::addBreakpoint(const vector<string>& args) const
	{
		assert(theClient != 0);
		if(args.size() < 2)
		{
			synchronous_logger::cerr << "Invalid syntax.\n";
			synchronous_logger::cerr << "(b|break) <namespace> <line number>\n";
			return false;
		}

		string lNamespace;
		unsigned int lLine;
		if(args.size() == 2)
		{
			lNamespace = theFileName;
			lLine = atoi(args.at(1).c_str());
		} else {
			lNamespace = args.at(1);
			lLine = atoi(args.at(2).c_str());
		}
		QueryLocation_t lLocation(theClient->addBreakpoint(lNamespace, lLine));
		if(lLocation->getLineBegin() == 0)
		{
			synchronous_logger::cerr << "Couldn't find an expression to break in " << lNamespace << " at line " << lLine << "\n";
      return false;
		} else {
			synchronous_logger::cerr << "Set breakpoint at: " <<  lLocation.get()->toString().c_str() << "\n";
		}
    return true;
	}

	bool DebuggerHandler::addWatchpoint(const vector<string>& args) const
	{
		assert(theClient != 0);
		if(args.size() < 2)
		{
			synchronous_logger::cerr << "Invalid syntax." << "\n";
			synchronous_logger::cerr << "(w|watch) <expression>" << "\n";
			return false;
		}
		String lExpr(getExpression(args));
		theClient->addBreakpoint(lExpr);
		synchronous_logger::cerr << "Add watchpoint: " << lExpr.c_str() << "\n";
    return true;
	}

	bool DebuggerHandler::resume() const
	{
		assert(theClient != 0);
		if(!theClient->isQuerySuspended())
		{
			synchronous_logger::cerr << "The query is not suspended or idle." << "\n";
			return false;
		}
		theClient->resume();
    return true;
	}

	bool DebuggerHandler::run() const
	{
		assert(theClient != 0);
		theClient->run();
    return true;
	}

	bool DebuggerHandler::terminateQuery() const
	{
		assert(theClient != 0);
		theClient->terminate();
    return true;
	}

	bool DebuggerHandler::status() const
	{
		assert(theClient != 0);
		if(theClient->isQueryRunning())
		{
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

	//List module source code
	bool DebuggerHandler::list(const std::vector<std::string>& args) const
	{
		if(args.size() >= 2 && args.at(1) == "b")
		{
			std::map<unsigned int, String> lBreakpoints = theClient->getBreakpoints();
			std::map<unsigned int, String>::const_iterator it;
			for(it=lBreakpoints.begin(); it!=lBreakpoints.end(); ++it)
			{
				synchronous_logger::cerr << "id: " << it->first << "\t" << it->second << "\n"; 
			}
		}else if(args.size() >= 2 && args.at(1) == "all"){
			list(theFileName); 
		}else if(args.size() >= 2){
			const String lStringURI(args.at(1));
			list(lStringURI);
		}
    return true;
	}

	//Clear a breakpoint
	bool DebuggerHandler::clear(const std::vector<std::string>& args)
	{
		if ( args.size() >= 2 && args.at(1) == "all" )
		{
			theClient->clearBreakpoints();
			synchronous_logger::cerr << "All breakpoints have been cleared." << "\n";
		} else if ( args.size() >= 2 && atoi(args.at(1).c_str()) > 0 ) {
			bool lResult = theClient->clearBreakpoint( atoi(args.at(1).c_str()) );
			if ( lResult )
			{
				synchronous_logger::cerr << "Breakpoint " << atoi(args.at(1).c_str()) << " has been cleared.\n";
			} else {
				synchronous_logger::cerr << "The breakpoint " << atoi(args.at(1).c_str()) << " doesn't exist.\n";
			}
		} else {
			synchronous_logger::cerr << "Invalid syntax.\n";
			synchronous_logger::cerr << "clear <number>\n";
			synchronous_logger::cerr << "clear all\n";
      return false;
		}
    return true;
	}

	//Execution steps
	bool DebuggerHandler::stepIn() const
	{
		assert(theClient != 0);
		theClient->stepInto();
    return true;
	}

	bool DebuggerHandler::stepOut() const
	{
		assert(theClient != 0);
		theClient->stepOut();
    return true;
	}

	bool DebuggerHandler::stepOver() const
	{
		assert(theClient != 0);
		theClient->stepOver();
    return true;
	}

	//List all scoped variables
	bool DebuggerHandler::variables() const
	{
    assert(theClient != 0);
    std::list<Variable> global;
    std::list<Variable> locals;
    try {
       global = theClient->getGlobalVariables();
       locals = theClient->getLocalVariables();
    } catch (std::exception& ex) {
      std::cerr << ex.what() << std::endl;
      return false;
    }
		std::list<Variable>::iterator it;
		synchronous_logger::cerr << "Global variables:\n";
		for(it = global.begin(); it != global.end(); it++)
		{
			synchronous_logger::cerr << "$" << it->getName() << " " << it->getType() << "\n";
		}
		synchronous_logger::cerr << "\n" << "Local variables:" << "\n";
		for(it = locals.begin(); it!=locals.end(); it++)
		{
			synchronous_logger::cerr << "$" << it->getName() << " " << it->getType() << "\n";
		}
    return true;
	}

	//Evaluate an expression
	bool DebuggerHandler::eval(const vector<string>& args)
	{
		assert(theClient != 0);
    if (theClient->isQueryIdle()) {
      synchronous_logger::cerr << "Cannot use eval, while the query is ide.\n";
      return false;
    }
		if(args.size() < 2)
		{
			synchronous_logger::cerr << "Invalid syntax.\n";
			synchronous_logger::cerr << "(p|print) <expr>\n";
			return false;
		} else {
			String lExpr(getExpression(args));
			theClient->eval(lExpr);
		}
    return true;
	}

	bool DebuggerHandler::help() const
	{
		cerr << "List of available commands." << endl;
		cerr << "Execution commands:" << endl;
		cerr << "  run       -- Start the query execution." << endl;
		cerr << "  resume    -- Resume the query execution." << endl;
		cerr << "  status    -- Display the status of the query." << endl;
		cerr << "  where     -- Print the runtime stack frame." << endl;
		cerr << "  terminate -- Terminate the query." << endl;
		cerr << "Breakpoint commands:" << endl;
		cerr << "  break     -- Set a breakpoint at the specified file and line." << endl;
		cerr << "  watch     -- Add watchpoint to the query" << endl;
		cerr << "  list      -- Display the executed query line." << endl;
		cerr << "  clear     -- Clear breakpoints." << endl;
		cerr << "  over      -- Steps over the expression." << endl;
		cerr << "  in        -- Steps inside the function call." << endl;
		cerr << "  out       -- Steps outside the function call." << endl;
		cerr << "Data commands:" << endl;
		cerr << "  vars      -- List all variables that are in scope." << endl;
		cerr << "  eval      -- Evaluate an xquery expression and print its result." << endl;
		cerr << "Zorba debugger:" << endl;
		cerr << "  help      -- This help." << endl;
    return true;
	}

	istream* DebuggerHandler::resolve(const String& aNamespace) const
	{
    std::string lSource = theClient->listSource(aNamespace.c_str());
    std::auto_ptr<std::istringstream> lStream(new std::istringstream());
    lStream->str(lSource);
    return lStream.release();
	}

	bool DebuggerHandler::list(const String& aNamespace) const
	{
		auto_ptr<istream> lInput(resolve(aNamespace));
		if(lInput.get() != 0)
		{
			unsigned int lLineNo = 0;
			while(lInput->good())
			{
				lLineNo++;
				string lLine;
				getline(*lInput, lLine, '\n');
				synchronous_logger::cerr << lLineNo << "\t" << lLine << "\n";
			}
		} else {
			cerr << "Could'nt find the query file for " << aNamespace << "\n";
      return false;
		}
    return true;
	}

	bool DebuggerHandler::list(const QueryLocation& aLocation) const
	{
		const String lStringURI(aLocation.getFileName());
		auto_ptr<istream> lInput(resolve(lStringURI));
		if(lInput.get() != 0)
		{
			unsigned int lLineBegin = aLocation.getLineBegin();
			unsigned int lLineEnd = aLocation.getLineEnd();
			unsigned int lColumnBegin = aLocation.getColumnBegin();
			unsigned int lColumnEnd = aLocation.getColumnEnd();
			unsigned int lLineNo = 0;
			string lLine;
			synchronous_logger::cout << "\n";
			while(lInput->good())
			{
				lLineNo++;
				getline(*lInput, lLine, '\n');
				unsigned int lBegin = (int)lLineBegin-10<0?0:lLineBegin-10;
				unsigned int lEnd = lLineEnd+10;
				if(lLineNo <= lBegin || lLineNo >= lEnd) continue;
				if(lLineNo >= lLineBegin && lLineNo <= lLineEnd)
				{
#ifdef WIN32
					HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					CONSOLE_SCREEN_BUFFER_INFO lConsoleInfo;
					GetConsoleScreenBufferInfo(lConsole, &lConsoleInfo);
					const int saved_configuration = lConsoleInfo.wAttributes;
					SetConsoleTextAttribute(lConsole, 15+0*16); 
					synchronous_logger::cerr << lLineNo << "\t";
					SetConsoleTextAttribute(lConsole, saved_configuration); 
					for(unsigned int j=1; j<=lLine.length(); j++)
					{
						// At this point it seems to be ok to just write to std::cerr
						// since other threads should be suspended at this time.
						if((lLineNo==lLineBegin && j >= lColumnBegin) ||
							(lLineBegin != lLineEnd && lLineNo==lLineEnd && j <= lColumnEnd) ||
							(lLineNo > lLineBegin && lLineEnd))
						{
							SetConsoleTextAttribute(lConsole, 15+0*16); 
							std::cerr << lLine.at(j-1);
							SetConsoleTextAttribute(lConsole, saved_configuration); 
						} else {
							std::cerr << lLine.at(j-1);
						}
					}
#else
					cerr << "\033[1m" << lLineNo << '\t' << "\033[0m";
					for(unsigned int j=1; j<=lLine.length(); j++)
					{
						if((lLineNo==lLineBegin && j >= lColumnBegin) ||
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
		while(!lStack->empty())
		{
			const Frame* lFrame = lStack->top();
			synchronous_logger::cerr << lFrame->getSignature() << ' ' << lFrame->getLocation()->toString() << "\n";
			lStack->pop();
		}
    return true;
	}

  void DebuggerHandler::suspend() {
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

	void DebuggerHandler::handle()
	{
    while (true) {
		  if(!theInterrupt)
		  {
		  	synchronous_logger::cerr << "(xqdb) ";
		  	string lLine;
		  	getline(cin, lLine, '\n');
		  	if(lLine == "")
		  	{
		  		continue;
		  	}
		  	vector<string> lArgs = getArgs(lLine);
		  	string lCommand = lArgs.at(0);

		  	if(lCommand == "r" || lCommand == "run"){
		  		if (!run()) continue;
          return;
		  	} else if(lCommand == "c" || lCommand == "resume"){
		  		if (!resume()) continue;
		  		return;
		  	} else if (lCommand == "t" || lCommand == "terminate" ) {
		  		if (!terminateQuery()) continue;
		  		return;
		  	} else if(lCommand == "s" || lCommand == "status"){
		  		if (!status()) continue;
		  	} else if(lCommand == "b" || lCommand == "break"){
		  		if (!addBreakpoint(lArgs)) continue;
		  	} else if(lCommand == "w" || lCommand == "watch"){
		  		if (!addWatchpoint(lArgs)) continue;
		  	} else if(lCommand == "l" || lCommand == "list"){
		  		if (!list(lArgs)) continue;
		  	} else if(lCommand == "cl" || lCommand == "clear"){
		  		if (!clear(lArgs)) continue;
		  	} else if(lCommand == "n" || lCommand == "over" || lCommand == "next") {
		  		if (!stepOver()) continue;
		  		return;
		  	} else if(lCommand == "s" || lCommand == "in") {
		  		if (!stepIn()) continue;
		  		return;
		  	} else if(lCommand == "o" || lCommand == "out"){
		  		if (!stepOut()) continue;
		  		return;
		  	} else if(lCommand == "v" || lCommand == "var" || lCommand == "vars" || lCommand == "variables"){
		  		if (!variables()) continue;
		  	} else if(lCommand == "where"){
		  		if (!where()) continue;
		  	} else if(lCommand == "p" || lCommand == "print" || lCommand == "e" || lCommand == "eval"){
		  		if (!eval(lArgs)) continue;
		  		return;
		  	} else if(lCommand == "h" || lCommand == "help"){
		  		if (!help()) continue;
		  	} else if (lCommand == "schnitzel") {
		  		printSchnitzel();
          continue;
		  	} else {
		  		cerr << "Unknown command " << lCommand << endl;
		  		if (!help()) continue;
		  	}
		  } else {
        // cin not good
        // happens if user presses CTRL-C
        return;
      }
    } // while(true)
	}

	void DebuggerHandler::started()
	{
	}

	void DebuggerHandler::idle()
	{
		handle();
	}

	void DebuggerHandler::suspended(QueryLocation& aLocation, SuspendedBy aCause)
	{
		synchronous_logger::cout << "Query suspended at " << aLocation.toString() << "\n";
		list(aLocation);
		handle();
	}

	void DebuggerHandler::resumed()
	{
		synchronous_logger::cout << "Continue...\n";
	}

	void DebuggerHandler::terminated()
	{
		synchronous_logger::cout << "\n...End of query\n";
	}

	void DebuggerHandler::evaluated(zorba::String &anExpr, std::list< pair<String, String> > &aValuesAndTypes)
	{
		std::list< pair<String, String> >::iterator it;
		for(it=aValuesAndTypes.begin(); it!=aValuesAndTypes.end(); ++it)
		{
			synchronous_logger::cout << it->first << " " << it->second << "\n";
		}
		handle();
	}

	void DebuggerHandler::evaluated(String& anExpr, String& anError)
	{
		synchronous_logger::cout << anError << "\n";
		handle();
	}

}//end of namespace
