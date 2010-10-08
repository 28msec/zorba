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

using namespace zorba;

namespace zorba {

  unsigned int getSeed()
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

  std::pair<short, short> getRandomPorts() 
  {
    srand(getSeed());
    int lPort1 = rand();
    lPort1 = lPort1 < 1026 ? lPort1 + 1026 : lPort1;
    int lPort2 = rand();
    lPort2 = lPort2 < 1026 ? lPort2 + 1026 : lPort2;

    while (lPort1 > 65535) {
      lPort1 -= 1000;
    }
    while (lPort2 > 65535) {
      lPort2 -= 1000;
    }
    return std::pair<short, short>(static_cast<short>(lPort1), static_cast<short>(lPort2));
  }

  XQuery_t createDebuggableQuery(Zorba* aZorba, std::iostream& os) {
    XQuery_t lQuery = aZorba->createQuery();
    lQuery->setFileName("test.xq");
		lQuery->setDebugMode(true);

		Zorba_CompilerHints lHints;
		lHints.opt_level = ZORBA_OPT_LEVEL_O0;

	  lQuery->compile(os, lHints);

    return lQuery;
  }

	int test_run(Zorba* lZorba) {

    std::stringstream qs;
    qs << "<a>Hello World</a>";

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(lZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->loadExecutionPlan(lState);

    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    {
      DebuggerTestClient client(lPorts.first, lPorts.second, qs);
      client.run();

      DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

      while (evt != DebuggerTestHandler::TERMINATED) {
      	evt = client.getNextEvent();
      	sleep(1);
      }

    }

    lServer.join();

    std::cout << "Result:\n" << lRes.str() << std::endl;

    if (lRes.str() != "<a>Hello World</a>") {
    	std::cerr << "Result does not match expected result" << std::endl;
    	return -1;
    }

    return 0;

  } // int test_run

	int test_terminate(Zorba* lZorba) {

    std::stringstream qs;
    qs << "if (fn:true())" << std::endl;
    qs << "then 1" << std::endl;
    qs << "else 2" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(lZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->loadExecutionPlan(lState);

    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    {
      DebuggerTestClient client(lPorts.first, lPorts.second, qs);

      std::string lFile("test.xq");
      std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 1" << std::endl;
      QueryLocation_t loc = client.addBreakpoint(lFile, 1);
      if (loc == NULL) {
        return -1;
      }
      std::cout << "Breakpoint set at location " << loc << std::endl;

      client.run();

      sleep(1); // wait for the query to start

      DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

      if (evt != DebuggerTestHandler::SUSPENDED) {
        std::cerr << "Query did not suspend at breakpoint" << std::endl;
        return 2;
      }

      client.terminate();
    }

    lServer.join();

    return 0;

  } // int test_terminate

  int test_terminate_immediately(Zorba* lZorba) {

    std::stringstream qs;
    qs << "declare variable $local:foo := 2;" << std::endl;

    qs << "declare function local:test($param) {" << std::endl;
    qs << "  let $x := 1" << std::endl;
    qs << "    return" << std::endl;
    qs << "    if (fn:true()) then" << std::endl;
    qs << "      $x + $param" << std::endl;
    qs << "    else using $x,$param eval {\"$x+$param\"}" << std::endl;
    qs << "};" << std::endl;

    qs << "if (fn:true()) then" << std::endl;
    qs << "local:test(15)" << std::endl;
    qs << "else 0" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(lZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->loadExecutionPlan(lState);


    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    {
      DebuggerTestClient client(lPorts.first, lPorts.second, qs);

      client.terminate();
    }

    lServer.join();

    return 0;

  } // int test_terminate_immediately
  
	int test_resume(Zorba* lZorba) {

    std::stringstream qs;
    qs << "if (fn:true())" << std::endl;
    qs << "then 1" << std::endl;
    qs << "else 2" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(lZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->loadExecutionPlan(lState);


    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    lServer.start();

    sleep(1);

    {
      DebuggerTestClient client(lPorts.first, lPorts.second, qs);

      std::string lFile("test.xq");
      std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 1" << std::endl;
      QueryLocation_t loc = client.addBreakpoint(lFile, 1);
      if (loc == NULL) {
        return -1;
      }
      std::cout << "Breakpoint set at location " << loc << std::endl;

      client.run();

      sleep(1); // wait for the query to start

      DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

      if (evt != DebuggerTestHandler::SUSPENDED) {
        std::cerr << "Query did not suspend at breakpoint" << std::endl;
        return 2;
      }

      client.resume();

      evt = client.getNextEvent();

    }

    lServer.join();

    return 0;

  } // int test_resume

  int test_clear_pending(Zorba* lZorba) {

    std::stringstream qs;
    qs << "for $x in 1 to 3" << std::endl;
    qs << "let $y := 2 * $x" << std::endl;
    qs << "return $y" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(lZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->loadExecutionPlan(lState);


    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    DebuggerTestClient client(lPorts.first, lPorts.second, qs);

    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 1" << std::endl;
    QueryLocation_t loc = client.addBreakpoint(lFile, 1);
    if (loc == NULL) {
      std::cerr << "Invalid query location received when setting a breakpoint" << std::endl;
      return -1;
    }
    std::cout << "Breakpoint pending at location " << loc << std::endl;

    client.clearBreakpoint(lFile, 1);
    std::cout << "Clearing breakpoint from file \"" << lFile << "\" at line 1" << std::endl;

    client.run();

    DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

    while (evt != DebuggerTestHandler::TERMINATED) {
      if (evt == DebuggerTestHandler::SUSPENDED) {
        std::cerr << "The query must not break after the breakpoint was cleared" << std::endl;
        client.terminate();
        lServer.join();
        return -1;
      }
      evt = client.getNextEvent();
      sleep(1);
    }

    client.terminate();
    lServer.join();
    return 0;

  } // int test_clear_pending

  int test_clear_set(Zorba* lZorba) {

    std::stringstream qs;
    qs << "for $x in 1 to 3" << std::endl;
    qs << "let $y := 2 * $x" << std::endl;
    qs << "return $y" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(lZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->loadExecutionPlan(lState);


    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    DebuggerTestClient client(lPorts.first, lPorts.second, qs);

    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 2" << std::endl;
    QueryLocation_t loc = client.addBreakpoint(lFile, 2);
    if (loc == NULL) {
      std::cerr << "Invalid query location received when setting a breakpoint" << std::endl;
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    client.run();

    DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

    bool lCleared = false;
    while (evt != DebuggerTestHandler::TERMINATED) {
      if (evt == DebuggerTestHandler::SUSPENDED) {
        if (!lCleared) {
          client.clearBreakpoint(lFile, 2);
          std::cout << "Clearing breakpoint from file \"" << lFile << "\" at line 2" << std::endl;
          lCleared = true;

          client.resume();
          evt = client.getNextEvent();
          sleep(1);
          continue; 
        }

        std::cerr << "The query must not break after the breakpoint was cleared" << std::endl;
        client.terminate();
        lServer.join();
        return -1;
      }

      evt = client.getNextEvent();
      sleep(1);
    }

    client.terminate();
    lServer.join();
    return 0;

  } // test_clear_set

  int test_vars(Zorba* aZorba) {
    std::stringstream qs;
    qs << "declare function local:test() {" << std::endl;
    qs << "  let $x := 1" << std::endl;
    qs << "  return" << std::endl;
    qs << "    if (fn:true()) then" << std::endl;
    qs << "      $x" << std::endl;
    qs << "    else 0" << std::endl;
    qs << "};" << std::endl;
    qs << "local:test()" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(aZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = aZorba->createQuery();
    lQuery->loadExecutionPlan(lState);


    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    DebuggerTestClient client(lPorts.first, lPorts.second, qs);

    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 4" << std::endl;
    QueryLocation_t loc = client.addBreakpoint(lFile, 4);
    if (loc == NULL) {
      client.terminate();
      lServer.join();
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    client.run();

    sleep(1); // wait for the query to start

    DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

    if (evt != DebuggerTestHandler::SUSPENDED) {
      std::cerr << "Query did not suspend at breakpoint" << std::endl;
      client.terminate();
      lServer.join();
      return 2;
    }

    std::vector<std::string> lVars = client.getVariableNames();
    for (std::vector<std::string>::const_iterator lIter = lVars.begin();
          lIter != lVars.end(); ++lIter) {
      std::cout << "received var " << *lIter << std::endl;
    }

    if (lVars.size() != 2 || lVars[0] != "$$dot" || lVars[1] != "x") {
      std::cerr << "vars did not return correct variables" << std::endl;
      client.terminate();
      lServer.join();
      return 3;
    }

    client.terminate();
    lServer.join();
    return 0;
  }

  int test_vars_repeated(Zorba* aZorba) {
    std::stringstream qs;
    qs << "for $i in 1 to 10" << std::endl
       << "return $i" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(aZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = aZorba->createQuery();
    lQuery->loadExecutionPlan(lState);


    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    DebuggerTestClient client(lPorts.first, lPorts.second, qs);

    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 2" << std::endl;
    QueryLocation_t loc = client.addBreakpoint(lFile, 2);
    if (loc == NULL) {
      client.terminate();
      lServer.join();
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    client.run();

    sleep(1); // wait for the query to start

    DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

    if (evt != DebuggerTestHandler::SUSPENDED) {
      std::cerr << "Query did not suspend at breakpoint" << std::endl;
      client.terminate();
      lServer.join();
      return 2;
    }

    std::vector<std::string> lVars = client.getVariableNames();
    for (std::vector<std::string>::const_iterator lIter = lVars.begin();
          lIter != lVars.end(); ++lIter) {
      std::cout << "received var " << *lIter << std::endl;
    }

    if (lVars.size() != 2 || lVars[0] != "$$dot" || lVars[1] != "i") {
      std::cerr << "vars did not return correct variables" << std::endl;
      client.terminate();
      lServer.join();
      return 3;
    }

    client.terminate();
    lServer.join();
    return 0;
  }

  int test_eval(Zorba* lZorba) {

    std::stringstream qs;
    qs << "for $i in 1" << std::endl;
    qs << "let $x := 2 * $i" << std::endl;
    qs << "return $x" << std::endl;

    std::ostringstream lRes;
    std::stringstream lState;
    {
      XQuery_t lQuery = createDebuggableQuery(lZorba, qs);
      lQuery->saveExecutionPlan(lState, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
    }
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->loadExecutionPlan(lState);


    std::pair<short, short> lPorts = getRandomPorts();
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    DebuggerServerRunnable lServer(lQuery, lRes, "127.0.0.1", lPorts.first,
      lPorts.second, lSerOptions);
    lServer.start();

    sleep(1);

    DebuggerTestClient client(lPorts.first, lPorts.second, qs);

    std::string lFile("test.xq");
    std::cout << "Adding breakpoint in file \"" << lFile << "\" at line 2" << std::endl;
    QueryLocation_t loc = client.addBreakpoint(lFile, 2);
    if (loc == NULL) {
      return -1;
    }
    std::cout << "Breakpoint set at location " << loc << std::endl;

    client.run();

    sleep(1); // wait for the query to start

    DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

    if (evt != DebuggerTestHandler::SUSPENDED) {
      std::cerr << "Query did not suspend at breakpoint" << std::endl;
      return 2;
    }

    client.eval("1");

    sleep(2); // wait for evaluation

    std::pair<String, std::list<std::pair<String, String> > > lEvaled;
    lEvaled = client.getLastEvent();

    std::cout << "Received evaled expression: " << lEvaled.first << std::endl;

    if (lEvaled.first != "1") {
      std::cerr << "Bad evaluation (expression)" << std::endl;
      return 3;
    }

    std::cout << "Received evaled list size: " << lEvaled.second.size() << std::endl;

    if (lEvaled.second.size() != 1) {
      std::cerr << "Bad evaluation result (size)" << std::endl;
      return 4;
    }

    std::list<std::pair<String, String> >::const_reference lPair = lEvaled.second.front();

    std::cout << "Received evaled expression value: " << lPair.first << std::endl;

    if (lPair.first != "1") {
      std::cerr << "Bad evaluation result (value)" << std::endl;
      return 5;
    }

    std::cout << "Received evaled expression type: " << lPair.second << std::endl;

    if (lPair.second != "integer") {
      std::cerr << "Bad evaluation result (type)" << std::endl;
      return 6;
    }

    client.terminate();
    lServer.join();

    return 0;

  } // int test_eval

} /* namespace zorba */

int test_debugger_server (int argc, char* argv[]) {
  void* store = zorba::StoreManager::getStore();
  Zorba* lZorba = zorba::Zorba::getInstance(store);

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_run" << std::endl;
  if (zorba::test_run(lZorba) != 0) {
  	return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_terminate" << std::endl;
  if (zorba::test_terminate(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_terminate_immediately" << std::endl;
  if (zorba::test_terminate_immediately(lZorba) != 0) {
    return 1;
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_resume" << std::endl;
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

  std::cout << "---------------------" << std::endl;
  std::cout << "executing test_eval" << std::endl;
  if (zorba::test_eval(lZorba) != 0) {
    return 1;
  }

  return 0;
}

