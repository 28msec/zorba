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
#include <simplestore/simplestore.h>

#include <string>
#include <iostream>

#ifdef WIN32
#define sleep(n) Sleep(1000*n)
#endif

using namespace zorba;

namespace zorba {

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
    XQuery_t lQuery = createDebuggableQuery(lZorba, qs);

    DebuggerServerRunnable lServer(lQuery, lRes, 8000, 9000);
    lServer.start();

    sleep(1);

    {
      DebuggerTestClient client(8000, 9000, qs);
      client.run();

      DebuggerTestHandler::DebugEvent evt = client.getNextEvent();

      while (evt != DebuggerTestHandler::TERMINATED) {
      	evt = client.getNextEvent();
      	sleep(1);
      }

    }

    lServer.join();

    std::cout << "Result:\n" << lRes.str() << std::endl;

    if (lRes.str() != "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<a>Hello World</a>") {
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
    XQuery_t lQuery = createDebuggableQuery(lZorba, qs);

    DebuggerServerRunnable lServer(lQuery, lRes, 8000, 9000);
    lServer.start();

    sleep(1);

    {
      DebuggerTestClient client(8000, 9000, qs);

      QueryLocation_t loc = client.addBreakpoint("test.xq", 1);
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

	int test_resume(Zorba* lZorba) {

    std::stringstream qs;
    qs << "if (fn:true())" << std::endl;
    qs << "then 1" << std::endl;
    qs << "else 2" << std::endl;

    std::ostringstream lRes;
    XQuery_t lQuery = createDebuggableQuery(lZorba, qs);

    DebuggerServerRunnable lServer(lQuery, lRes, 8000, 9000);
    lServer.start();

    sleep(1);

    {
      DebuggerTestClient client(8000, 9000, qs);

      QueryLocation_t loc = client.addBreakpoint("test.xq", 1);
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
//
//  int test_var() {
//    std::ostringstream query;
//
//    query << "<html>" << std::endl
//          << "  <head>" << std::endl
//          << "  </head>" << std::endl
//          << "  <body>" << std::endl
//          << " {" << std::endl
//          << "   for $act in <doc><ACT><TITLE>T</TITLE><SPEAKER></SPEAKER><SPEAKER>S2</SPEAKER></ACT></doc>" << std::endl
//          << "   let $speakers := distinct-values($act//SPEAKER)" << std::endl
//          << "   return" << std::endl
//          << "    (" << std::endl
//          << "      <h1>{$act/TITLE/text()}</h1>," << std::endl
//          << "      <ul>" << std::endl
//          << "        {" << std::endl
//          << "          for $speaker in $speakers" << std::endl
//          << "          return <li>{ $speaker }</li>" << std::endl
//          << "        }" << std::endl
//          << "      </ul>" << std::endl
//          << "     )" << std::endl
//          << " }" << std::endl
//          << " </body>" << std::endl
//          << "</html>" << std::endl;
//
//    DebuggerTestClient client("test.xq", query.str());
//    QueryLocation_t loc = client.addBreakpoint("test.xq", 14);
//    if (loc == NULL) {
//      return -1;
//    }
//    client.run();
//    DebuggerTestHandler::DebugEvent evt;
//    while((evt = client.getNextEvent()) == DebuggerTestHandler::IDLE) {
//      sleep(1);
//    }
//    if (evt != DebuggerTestHandler::SUSPENDED) {
//      return -1;
//    }
//    std::cout << "Starting reading variables";
//    std::list<Variable> vars = client.getAllVariables(true);
//    for (std::list<Variable>::const_iterator it = vars.begin(); it != vars.end(); it++) {
//      Variable v = *it;
//      std::cout << v.getName() << " " << v.getType() << ":\n";
//      std::cout.flush();
//      std::list<std::pair<String, String> > data = it->getData();
//      for (std::list<std::pair<String, String> >::const_iterator iter = data.begin(); iter != data.end(); iter++) {
//        std::cout << "  " << iter->first << " " << iter->second << std::endl;
//      }
//    }
//    client.terminate();
//    return 0;
//  }
//}
//
} /* namespace zorba */

int test_debugger_server (int argc, char* argv[]) {
  zorba::simplestore::SimpleStore* store = zorba::simplestore::SimpleStoreManager::getStore();
  Zorba* lZorba = zorba::Zorba::getInstance(store);

  std::cout << "executing test_run" << std::endl;
  if (zorba::test_run(lZorba) != 0) {
  	return 1;
  }
  std::cout << std::endl;

  std::cout << "executing test_terminate" << std::endl;
  if (zorba::test_terminate(lZorba) != 0) {
    return 1;
  }
  std::cout << std::endl;

  std::cout << "executing test_resume" << std::endl;
  if (zorba::test_resume(lZorba) != 0) {
    return 1;
  }
  std::cout << std::endl;
	return 0;
}

