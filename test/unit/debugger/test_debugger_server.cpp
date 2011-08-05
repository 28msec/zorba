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
#include "DebuggerTestClient.h"
#include "debugger_server_runnable.h"
#include "DebuggerTestHandler.h"

#include <zorba/zorba.h>
#include <zorba/store_manager.h>

#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <sstream>

#ifdef WIN32
#include <Windows.h>
#define sleep(n) Sleep(1000*n)
#else
#include <sys/time.h>
#include <limits.h>
#endif

namespace zorba {

class ClientServerWrapper {
  friend void initTest(Zorba*, std::stringstream&,
    std::ostringstream&, ClientServerWrapper&, bool);

  private:
    std::auto_ptr<DebuggerTestClient> theClient;
    std::auto_ptr<DebuggerServerRunnable> theServer;

  public:

    ClientServerWrapper() {
    }

    ~ClientServerWrapper() {
      if (theClient.get() != 0) {
        theClient->terminate();
      }
      if (theServer.get() != 0) {
        theServer->join();
      }
    }

    DebuggerServerRunnable* getServer() {
      return theServer.get();
    }

    DebuggerTestClient* getClient() {
      return theClient.get();
    }

  private:

    void setServer(DebuggerServerRunnable* aServer) {
      theServer.reset(aServer);
    }

    void setClient(DebuggerTestClient* aClient) {
      theClient.reset(aClient);
    }

};

unsigned int
getSeed()
{
#ifdef WIN32
  return GetTickCount();
#else
  struct timeval tv;
  gettimeofday(&tv, NULL);
  unsigned long long sec = tv.tv_sec;
  unsigned long long usec = tv.tv_usec;
  unsigned long long value = 1000000*sec + usec;

  return (unsigned int)(value & UINT_MAX);
#endif
}

std::pair<short, short>
getRandomPorts() 
{
  srand(getSeed());
  // using only ephemeral ports (49152-65535)
  int from = 49152;
  int to = 65535;
  int lPort1 = rand() % (to - from + 1) + from;
  int lPort2 = rand() % (to - from + 1) + from;

  return std::pair<short, short>(static_cast<short>(lPort1), static_cast<short>(lPort2));
}

XQuery_t
createDebuggableQuery(Zorba* aZorba, std::iostream& os)
{
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->setFileName("test.xq");
  lQuery->setDebugMode(true);

  Zorba_CompilerHints lHints;
  lHints.opt_level = ZORBA_OPT_LEVEL_O0;

  lQuery->compile(os, lHints);

  return lQuery;
}

void
initTest(
  Zorba* lZorba,
  std::stringstream& aQueryStr,
  std::ostringstream& aResult,
  ClientServerWrapper& aClientServer,
  bool aStartClient)
{
  XQuery_t lQuery = createDebuggableQuery(lZorba, aQueryStr);

  std::pair<short, short> lPorts = getRandomPorts();
  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  aClientServer.setServer(new DebuggerServerRunnable(
    lQuery, aResult, "127.0.0.1", lPorts.second, lSerOptions));
  aClientServer.getServer()->start();
  sleep(1);

  aClientServer.setClient(new DebuggerTestClient(lPorts.first, lPorts.second, aQueryStr));

  if (aStartClient) {
    aClientServer.getClient()->run();
  }
}

int
testResult(std::ostringstream& aActualResult, std::string& aExpectedResult)
{
  std::cout << "Result:\n" << aActualResult.str() << std::endl;
  if (aActualResult.str() != aExpectedResult) {
    std::cerr << "Result does not match expected result: " << aExpectedResult << std::endl;
    return -1;
  }

  return 0;
}

int
test_run(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "<a>Hello World</a>";
  std::string lExpectedResult("<a>Hello World</a>");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, true);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // wait for termination
    if (!(lClient->waitUntil(DebuggerTestHandler::TERMINATED, 15))) {
      std::cerr << "Query did not terminate in time" << std::endl;
      return 2;
    }
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // int test_run

int
test_terminate_suspended(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "if (fn:true())" << std::endl;
  lQueryStr << "then 1" << std::endl;
  lQueryStr << "else 2" << std::endl;
  std::string lExpectedResult("");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // add a breakpoint
    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 1" << std::endl;
    QueryLocation_t loc = lClient->addBreakpoint(lFile, 1);
    if (loc == NULL) {
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    // run the query
    lClient->run();

    // wait for execution to be suspended
    if (!(lClient->waitUntil(DebuggerTestHandler::SUSPENDED, 5))) {
      std::cerr << "Query did not suspend at breakpoint in time" << std::endl;
      return 2;
    }
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // int test_terminate_suspended

int
test_terminate_immediately(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "'this query will not be used anyway'" << std::endl;
  std::string lExpectedResult("");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    // the test content is handled by the init call and the wrapper destructor
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // int test_terminate_immediately
  
int
test_resume(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "if (fn:true())" << std::endl;
  lQueryStr << "then 1" << std::endl;
  lQueryStr << "else 2" << std::endl;
  std::string lExpectedResult("1");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // set a breakpoint
    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 1" << std::endl;
    QueryLocation_t loc = lClient->addBreakpoint(lFile, 1);
    if (loc == NULL) {
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    // run the query
    lClient->run();

    // wait for execution to be suspended
    if (!(lClient->waitUntil(DebuggerTestHandler::SUSPENDED, 5))) {
      std::cerr << "Query did not suspend at breakpoint in time" << std::endl;
      return 2;
    }

    // resume the execution
    lClient->resume();

    // expect the execution to terminate
    if (!(lClient->waitUntil(DebuggerTestHandler::TERMINATED, 5))) {
      std::cerr << "Query did not terminate in time after resume." << std::endl;
      return 2;
    }
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // int test_resume

int
test_clear_pending(Zorba* aZorba)
{    
  std::stringstream lQueryStr;
  lQueryStr << "for $x in 1 to 3" << std::endl;
  lQueryStr << "let $y := 2 * $x" << std::endl;
  lQueryStr << "return $y" << std::endl;
  std::string lExpectedResult("2 4 6");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // set a breakpoint
    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 1" << std::endl;
    QueryLocation_t loc = lClient->addBreakpoint(lFile, 1);
    if (loc == NULL) {
      std::cerr << "Invalid query location received when setting a breakpoint" << std::endl;
      return -1;
    }
    std::cout << "Breakpoint pending at location " << loc << std::endl;

    // clear a breakpoint before even starting the query
    lClient->clearBreakpoint(lFile, 1);
    std::cout << "Clearing breakpoint from file \"" << lFile << "\" at line 1" << std::endl;

    // run the query
    lClient->run();

    // expect the execution to terminate
    if (!(lClient->waitUntil(DebuggerTestHandler::TERMINATED, 5))) {
      std::cerr << "The query must have terminated already after the breakpoint was cleared" << std::endl;
      return -1;
    }
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // int test_clear_pending

int
test_clear_set(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "for $x in 1 to 3" << std::endl;
  lQueryStr << "let $y := 2 * $x" << std::endl;
  lQueryStr << "return $y" << std::endl;
  std::string lExpectedResult("2 4 6");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // set a breakpoint
    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 2" << std::endl;
    QueryLocation_t loc = lClient->addBreakpoint(lFile, 2);
    if (loc == NULL) {
      std::cerr << "Invalid query location received when setting a breakpoint" << std::endl;
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    // run the query
    lClient->run();

    // wait for the execution to be suspended
    if (!(lClient->waitUntil(DebuggerTestHandler::SUSPENDED, 5))) {
      std::cerr << "The query execution should have suspended at the breakpoint already" << std::endl;
      return -1;
    }

    // clear the breakpoint
    std::cout << "Clearing breakpoint from file \"" << lFile << "\" at line 2" << std::endl;
    lClient->clearBreakpoint(lFile, 2);

    // resume the query
    lClient->resume();

    // expect the execution to terminate
    if (!(lClient->waitUntil(DebuggerTestHandler::TERMINATED, 5))) {
      std::cerr << "The query execution should have terminated already. Was the breakpoint really cleared?" << std::endl;
      return -1;
    }
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // test_clear_set

int
test_vars(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "declare function local:test() {" << std::endl;
  lQueryStr << "  let $x := 1" << std::endl;
  lQueryStr << "  return" << std::endl;
  lQueryStr << "    if (fn:true()) then" << std::endl;
  lQueryStr << "      $x" << std::endl;
  lQueryStr << "    else 0" << std::endl;
  lQueryStr << "};" << std::endl;
  lQueryStr << "local:test()" << std::endl;
  std::string lExpectedResult("1");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // set a breakpoint
    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 4" << std::endl;
    QueryLocation_t loc = lClient->addBreakpoint(lFile, 4);
    if (loc == NULL) {
      std::cerr << "Invalid query location received when setting a breakpoint" << std::endl;
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    // run the query
    lClient->run();

    // wait for the execution to be suspended
    if (!(lClient->waitUntil(DebuggerTestHandler::SUSPENDED, 5))) {
      std::cerr << "Query did not suspend at breakpoint in time" << std::endl;
      return -1;
    }

    // ask for some variables
    std::vector<std::string> lVars = lClient->getVariableNames();
    for (std::vector<std::string>::const_iterator lIter = lVars.begin();
        lIter != lVars.end(); ++lIter) {
      std::cout << "received var " << *lIter << std::endl;
    }
    if (lVars.size() != 2 || lVars[0] != "$$dot" || lVars[1] != "x") {
      std::cerr << "vars did not return correct variables" << std::endl;
      return -1;
    }

    // resume the query
    lClient->resume();

    // expect the execution to terminate
    if (!(lClient->waitUntil(DebuggerTestHandler::TERMINATED, 5))) {
      std::cerr << "The query execution should have terminated already" << std::endl;
      return -1;
    }
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // test_vars

int
test_vars_repeated(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "for $i in 1 to 10" << std::endl;
  lQueryStr << "return $i" << std::endl;
  std::string lExpectedResult("1 2 3 4 5 6 7 8 9 10");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // set a breakpoint
    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 2" << std::endl;
    QueryLocation_t loc = lClient->addBreakpoint(lFile, 2);
    if (loc == NULL) {
      std::cerr << "Invalid query location received when setting a breakpoint" << std::endl;
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    // run the query
    lClient->run();

    for (int i = 0; i < 10; i++) {
      // wait for the execution to be suspended
      if (!(lClient->waitUntil(DebuggerTestHandler::SUSPENDED, 5))) {
        std::cerr << "Query did not suspend at breakpoint in time" << std::endl;
        return -1;
      }

      // ask for some variables
      std::vector<std::string> lVars = lClient->getVariableNames();
      for (std::vector<std::string>::const_iterator lIter = lVars.begin();
          lIter != lVars.end(); ++lIter) {
        std::cout << "received var " << *lIter << std::endl;
      }
      if (lVars.size() != 2 || lVars[0] != "$$dot" || lVars[1] != "i") {
        std::cerr << "vars did not return correct variables" << std::endl;
        return -1;
      }

      // resume the query
      lClient->resume();
      sleep(1);
    }

    // expect the execution to terminate
    if (!(lClient->waitUntil(DebuggerTestHandler::TERMINATED, 5))) {
      std::cerr << "The query execution should have terminated already" << std::endl;
      return -1;
    }
    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // test_vars_repeated

int
test_eval(Zorba* aZorba)
{
  std::stringstream lQueryStr;
  lQueryStr << "for $i in 1" << std::endl;
  lQueryStr << "let $x := 2 * $i" << std::endl;
  lQueryStr << "return $x" << std::endl;
  std::string lExpectedResult("2");
  std::ostringstream lResult;

  // the following block is needed in order to make sure that the
  // ClientServerWrapper is destroyed before the output stream is
  // read, otherwise a race condition is possible
  {
    ClientServerWrapper lClientServer;
    initTest(aZorba, lQueryStr, lResult, lClientServer, false);

    // begin testing ----------------------------------------------------
    //
    DebuggerTestClient* lClient = lClientServer.getClient();

    // set a breakpoint
    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 2" << std::endl;
    QueryLocation_t loc = lClient->addBreakpoint(lFile, 2);
    if (loc == NULL) {
      std::cerr << "Invalid query location received when setting a breakpoint" << std::endl;
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    // run the query
    lClient->run();

    // wait for the execution to be suspended
    if (!(lClient->waitUntil(DebuggerTestHandler::SUSPENDED, 5))) {
      std::cerr << "Query did not suspend at breakpoint in time" << std::endl;
      return -1;
    }

    // eval some expression
    lClient->eval("1");
    sleep(1); // wait for evaluation

    // check the result
    std::pair<String, std::list<std::pair<String, String> > > lEvaled;
    lEvaled = lClient->getLastEvent();
    std::cout << "Received evaled expression: " << lEvaled.first << std::endl;

    // is the returned expression correct?
    if (lEvaled.first != "1") {
      std::cerr << "Bad evaluation (expression)" << std::endl;
      return 3;
    }
    std::cout << "Received evaled list size: " << lEvaled.second.size() << std::endl;

    // does the result contain the correct number of elements?
    if (lEvaled.second.size() != 1) {
      std::cerr << "Bad evaluation result (size)" << std::endl;
      return 4;
    }

    // is the result value correct?
    std::list<std::pair<String, String> >::const_reference lPair = lEvaled.second.front();
    std::cout << "Received evaled expression value: " << lPair.first << std::endl;
    if (lPair.first != "1") {
      std::cerr << "Bad evaluation result (value)" << std::endl;
      return 5;
    }

    // is the result type correct?
    std::cout << "Received evaled expression type: " << lPair.second << std::endl;
    if (lPair.second != "integer") {
      std::cerr << "Bad evaluation result (type)" << std::endl;
      return 6;
    }

    // resume the query
    lClient->resume();

    // expect the execution to terminate
    if (!(lClient->waitUntil(DebuggerTestHandler::TERMINATED, 5))) {
      std::cerr << "The query execution should have terminated already" << std::endl;
      return -1;
    }

    //
    // end testing ------------------------------------------------------
  }
  return testResult(lResult, lExpectedResult);

} // int test_eval

} /* namespace zorba */

int test_debugger_server (int argc, char* argv[]) {
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* lZorba = zorba::Zorba::getInstance(store);

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_run" << std::endl;
  if (zorba::test_run(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_terminate_suspended" << std::endl;
  if (zorba::test_terminate_suspended(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_terminate_immediately" << std::endl;
  if (zorba::test_terminate_immediately(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_resume (" << std::endl;
  if (zorba::test_resume(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_clear_pending" << std::endl;
  if (zorba::test_clear_pending(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_clear_set" << std::endl;
  if (zorba::test_clear_set(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_vars" << std::endl;
  if (zorba::test_vars(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_vars_repeated" << std::endl;
  if (zorba::test_vars_repeated(lZorba) != 0) {
    return 1;
  }

//  there is still a problem with a race condition here. See bug #3196140
//  std::cout << "---------------------" << std::endl;
//  std::cout << "executing test_eval" << std::endl;
//  if (zorba::test_eval(lZorba) != 0) {
//    return 1;
//  }

  return 0;
}
/* vim:set et sw=2 ts=2: */
