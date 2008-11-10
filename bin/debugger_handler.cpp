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

using namespace std;

namespace zorba{

#ifdef SIGINT /* not all system have SIGINT */
ZorbaDebuggerClient* theDebugClient = 0;

void setDebugClient(ZorbaDebuggerClient* lClient)
{
  theDebugClient = lClient;
}

void suspend(int aSignum)
{
  if(theDebugClient != 0 && theDebugClient->isQueryRunning())
  {
    theDebugClient->suspend();
  } else {
  //if the query is not running, we calll the default signal handling
  signal(SIGINT, SIG_DFL);
  raise(SIGINT);
  }
}
#endif
DebuggerHandler::DebuggerHandler(Zorba* aZorba, ZorbaDebuggerClient* aClient, std::string aFileName):
  theZorba(aZorba), theClient(aClient), theFileName(aFileName){}

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

void DebuggerHandler::addBreakpoint(const vector<string>& args) const
{
  assert(theClient != 0);
  if(args.size() < 2)
  {
    cerr << "Invalid syntax." << endl;
    cerr << "(b|break) <namespace> <line number>" << endl;
    return;
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
    cerr << "Couldn't find an expression to break in " << lNamespace << " at line " << lLine << endl;
  } else {
    cerr << "Set breakpoint at: " <<  lLocation.get() << endl;
  }
}

void DebuggerHandler::addWatchpoint(const vector<string>& args) const
{
  assert(theClient != 0);
  if(args.size() < 2)
  {
    cerr << "Invalid syntax." << endl;
    cerr << "(w|watch) <expression>" << endl;
    return;
  }
  String lExpr(getExpression(args));
  theClient->addBreakpoint(lExpr);
  cerr << "Add watchpoint: " << lExpr << endl;
}

void DebuggerHandler::resume() const
{
  assert(theClient != 0);
  if(!theClient->isQueryIdle() && !theClient->isQuerySuspended())
  {
    cerr << "The query is not suspended or idle." << endl;
    return;
  }
  theClient->resume();
}

void DebuggerHandler::run() const
{
  assert(theClient != 0);
  theClient->run();
}

void DebuggerHandler::status() const
{
  assert(theClient != 0);
  if(theClient->isQueryRunning())
  {
    cerr << "The query is running." << endl;
  } else if (theClient->isQueryIdle()) {
    cerr << "The query is idle." << endl;
  } else if (theClient->isQuerySuspended()) {
    cerr << "The query is suspended." << endl;
  } else if (theClient->isQueryTerminated()) {
    cerr << "The query is terminated." << endl;
  }
}

//List module source code
void DebuggerHandler::list(const std::vector<std::string>& args) const
{
  if(args.size() >= 2 && args.at(1) == "b")
  {
    std::map<unsigned int, String> lBreakpoints = theClient->getBreakpoints();
    std::map<unsigned int, String>::const_iterator it;
    for(it=lBreakpoints.begin(); it!=lBreakpoints.end(); ++it)
    {
      cerr << "id: " << it->first << '\t' << it->second << endl; 
    }
  }else if(args.size() >= 2 && args.at(1) == "all"){
    list(theFileName); 
  }else if(args.size() >= 2){
    const String lStringURI(args.at(1));
    list(lStringURI);
  }
}

//Clear a breakpoint
void DebuggerHandler::clear(const std::vector<std::string>& args)
{
  if ( args.size() >= 2 && args.at(1) == "all" )
  {
    theClient->clearBreakpoints();
    cerr << "All breakpoints have been cleared." << endl;
  } else if ( args.size() >= 2 && atoi(args.at(1).c_str()) > 0 ) {
    bool lResult = theClient->clearBreakpoint( atoi(args.at(1).c_str()) );
    if ( lResult )
    {
      cerr << "Breakpoint " << atoi(args.at(1).c_str()) << " has been cleared." << endl;
    } else {
      cerr << "The breakpoint " << atoi(args.at(1).c_str()) << " doesn't exit." << endl;
    }
  } else {
    cerr << "Invalid syntax." << endl;
    cerr << "clear <number>" << endl;
    cerr << "clear all" << endl;
  }
}

//Execution steps
void DebuggerHandler::stepIn() const
{
  assert(theClient != 0);
  theClient->stepInto();
}

void DebuggerHandler::stepOut() const
{
  assert(theClient != 0);
  theClient->stepOut();
}

void DebuggerHandler::stepOver() const
{
  assert(theClient != 0);
  theClient->stepOver();
}

//List all scoped variables
void DebuggerHandler::variables() const
{
  assert(theClient != 0);
  std::list<Variable> global = theClient->getGlobalVariables();
  std::list<Variable>::iterator it;
  cerr << "Global variables:" << endl;
  for(it = global.begin(); it != global.end(); it++)
  {
    cerr << "$" << it->getName() << " " << it->getType() << endl;
  }
  cerr << endl << "Local variables:" << endl;
  std::list<Variable> locals = theClient->getLocalVariables();
  for(it = locals.begin(); it!=locals.end(); it++)
  {
    cerr << "$" << it->getName() << " " << it->getType() << endl;
  }
}

//Evaluate an expression
void DebuggerHandler::eval(const vector<string>& args)
{
  assert(theClient != 0);
  assert(!theClient->isQueryIdle());
  if(args.size() < 2)
  {
    cerr << "Invalid syntax." << endl;
    cerr << "(p|print) <expr>" << endl;
    handle();
  } else {
    String lExpr(getExpression(args));
    theClient->eval(lExpr);
  }
}

void DebuggerHandler::help() const
{
  cerr << "List of available commands." << endl;
  cerr << "Execution commands:" << endl;
  cerr << "  run      -- Start the query execution." << endl;
  cerr << "  resume   -- Resume the query execution." << endl;
  cerr << "  status   -- Display the status of the query." << endl;
  cerr << "  where    -- Print the runtime stack frame." << endl;
  cerr << "Breakpoint commands:" << endl;
  cerr << "  break    -- Set a breakpoint at the specified file and line." << endl;
  cerr << "  watch    -- Add watchpoint to the query" << endl;
  cerr << "  list     -- Display the executed query line." << endl;
  cerr << "  clear    -- Clear breakpoints." << endl;
  cerr << "  over     -- Steps over the expression." << endl;
  cerr << "  in       -- Steps inside the function call." << endl;
  cerr << "  out      -- Steps outside the function call." << endl;
  cerr << "Data commands:" << endl;
  cerr << "  vars     -- List all variables that are in scope." << endl;
  cerr << "  eval     -- Evaluate an xquery expression and print its result." << endl;
  cerr << "Zorba debugger:" << endl;
  cerr << "  help     -- This help." << endl;
}

istream* DebuggerHandler::resolve(const String& aNamespace) const
{
  assert(theZorba != 0);
  StaticContext_t lStaticCtx = theZorba->createStaticContext();
  assert(lStaticCtx != 0);
  ModuleURIResolver* lModuleURIResolver = lStaticCtx->getModuleURIResolver(); 
  auto_ptr<istream> lInput;
  if(lModuleURIResolver == 0)
  {
    stringstream lFilename;
    lFilename << aNamespace;
    lInput.reset(new ifstream(lFilename.str().c_str()));
  } else {
    //Resolve the logical/physical URI
    ItemFactory* lItemFactory = theZorba->getItemFactory();
    Item lURI = lItemFactory->createAnyURI(aNamespace);
    lInput.reset(lModuleURIResolver->resolve(lURI, 0)->getModule());
  }
  return lInput.release();
}

void DebuggerHandler::list(const String& aNamespace) const
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
      cerr << lLineNo << '\t' << lLine << endl;
    }
  } else {
    cerr << "Could'nt find the query file for " << aNamespace << endl;
  }
}

void DebuggerHandler::list(const QueryLocation& aLocation) const
{
  const String lStringURI(aLocation.getFileName());
  auto_ptr<istream> lInput(resolve(lStringURI));
  if(lInput.get() != 0)
  {
    int lLineBegin = aLocation.getLineBegin();
    int lLineEnd = aLocation.getLineEnd();
    int lColumnBegin = aLocation.getColumnBegin();
    int lColumnEnd = aLocation.getColumnEnd();
    int lLineNo = 0;
    string lLine;
    cout << endl;
    while(lInput->good())
    {
      lLineNo++;
      getline(*lInput, lLine, '\n');
      //std::cerr << "lLineNo: " << lLineNo << std::endl;
      //std::cerr << "lLineBegin-10:" << lLineBegin-10 << std::endl;
      //std::cerr << "lLineEnd-10:" << lLineEnd+10 << std::endl;
      if(lLineNo <= (lLineBegin-10) || lLineNo >= (lLineEnd+10)) continue;
      if(lLineNo >= lLineBegin && lLineNo <= lLineEnd)
      {
#ifdef WIN32
        HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO lConsoleInfo;
        GetConsoleScreenBufferInfo(lConsole, &lConsoleInfo);
        const int saved_configuration = lConsoleInfo.wAttributes;
        SetConsoleTextAttribute(lConsole, 15+0*16); 
        cerr << lLineNo << '\t';
        SetConsoleTextAttribute(lConsole, saved_configuration); 
        for(unsigned int j=1; j<=lLine.length(); j++)
        {
          if((lLineNo==lLineBegin && j >= lColumnBegin) ||
             (lLineBegin != lLineEnd && lLineNo==lLineEnd && j <= lColumnEnd) ||
             (lLineNo > lLineBegin && lLineEnd))
          {
            SetConsoleTextAttribute(lConsole, 15+0*16); 
            cerr << lLine.at(j-1);
            SetConsoleTextAttribute(lConsole, saved_configuration); 
          } else {
            cerr << lLine.at(j-1);
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
        cerr << endl;
      } else {
        cerr << lLineNo << '\t' << lLine << endl; 
      }
    }
    cerr << endl;
  } else {
    cerr << "Could'nt find the query file for " << lStringURI << endl;
  }
}

void DebuggerHandler::where() const
{
  StackFrame_t lStack(theClient->getStack());
  while(!lStack->empty())
  {
    const Frame* lFrame = lStack->top();
    cerr << lFrame->getSignature() << ' ' << lFrame->getLocation() << endl;
    lStack->pop();
  }
}

void DebuggerHandler::handle()
{
  if(cin.good())
  {
    cerr << "(xqdb) ";
    cerr.flush();
    string lLine;
    getline(cin, lLine, '\n');
    if(lLine == "")
    {
      handle(); 
    }
    vector<string> lArgs = getArgs(lLine);
    string lCommand = lArgs.at(0);
 
    if(lCommand == "r" || lCommand == "run"){
      run();
      return;
    } else if(lCommand == "c" || lCommand == "resume"){
      resume();
      return;
    } else if(lCommand == "s" || lCommand == "status"){
      status();
    } else if(lCommand == "b" || lCommand == "break"){
      addBreakpoint(lArgs);
    } else if(lCommand == "w" || lCommand == "watch"){
      addWatchpoint(lArgs);
    } else if(lCommand == "l" || lCommand == "list"){
      list(lArgs);
    } else if(lCommand == "cl" || lCommand == "clear"){
      clear(lArgs);
    } else if(lCommand == "n" || lCommand == "over" || lCommand == "next") {
      stepOver();
      return;
    } else if(lCommand == "s" || lCommand == "in") {
      stepIn();
      return;
    } else if(lCommand == "o" || lCommand == "out"){
      stepOut();
      return;
    } else if(lCommand == "v" || lCommand == "var" || lCommand == "vars" || lCommand == "variables"){
      variables();
    } else if(lCommand == "where"){
      where();
    } else if(lCommand == "p" || lCommand == "print" || lCommand == "e" || lCommand == "eval"){
      eval(lArgs);
      return;
    } else if(lCommand == "h" || lCommand == "help"){
      help();
    } else {
      cerr << "Unknown command " << lCommand << endl;
      help();
    }
    handle();
  }
}

void DebuggerHandler::started()
{
  cerr << "Execute the query..." << endl; 
}

void DebuggerHandler::idle()
{
  handle();
}

void DebuggerHandler::suspended(QueryLocation& aLocation, SuspendedBy aCause)
{
  cout << "Query suspended at " << aLocation << endl;
  list(aLocation);
  handle();
}

void DebuggerHandler::resumed()
{
  cout << "Continue..." << endl;
}

void DebuggerHandler::terminated()
{
  cout << endl << "...End of query" << endl;
}

void DebuggerHandler::evaluated(String& anExpr, map<String, String> &aValuesAndTypes)
{
  std::map<String, String>::iterator it;
  for(it=aValuesAndTypes.begin(); it!=aValuesAndTypes.end(); ++it)
  {
    cout << it->first << " " << it->second << std::endl;
  }
  handle();
}

void DebuggerHandler::evaluated(String& anExpr, String& anError)
{
  cout << anError << endl;
  handle();
}

}//end of namespace
