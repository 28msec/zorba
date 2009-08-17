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
#include "DebuggerTestHandler.h"

#include <string>
#include <iostream>

#ifdef WIN32
#define sleep(n) Sleep(1000*n)
#endif

namespace zorba {
	  int test_run() {
    std::cout << "Run Test" << std::endl;
    DebuggerTestClient client("test.xq", "<a>Hello World</a>");
    client.run();
    DebuggerTestHandler::DebugEvent evt = client.getNextEvent();
    /*if (evt != DebuggerTestHandler::TERMINATED) {
    	return -1;
    }*/
    while (evt != DebuggerTestHandler::TERMINATED) {
    	evt = client.getNextEvent();
    	sleep(1);
    }
    std::string res = client.getQueryResult();
    if (res != "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<a>Hello World</a>") {
    	std::cerr << "Result:" << res << std::endl;
    	return -1;
    }
		return 0;
	}
  int test_var() {
    std::ostringstream query;

    query << "<html>" << std::endl
          << "  <head>" << std::endl
          << "  </head>" << std::endl
          << "  <body>" << std::endl
          << " {" << std::endl
          << "   for $act in <doc><ACT><TITLE>T</TITLE><SPEAKER></SPEAKER><SPEAKER>S2</SPEAKER></ACT></doc>" << std::endl
          << "   let $speakers := distinct-values($act//SPEAKER)" << std::endl
          << "   return" << std::endl
          << "    (" << std::endl
          << "      <h1>{$act/TITLE/text()}</h1>," << std::endl
          << "      <ul>" << std::endl
          << "        {" << std::endl
          << "          for $speaker in $speakers" << std::endl
          << "          return <li>{ $speaker }</li>" << std::endl
          << "        }" << std::endl
          << "      </ul>" << std::endl
          << "     )" << std::endl
          << " }" << std::endl
          << " </body>" << std::endl
          << "</html>" << std::endl;

    DebuggerTestClient client("test.xq", query.str());
    QueryLocation_t loc = client.addBreakpoint("test.xq", 14);
    if (loc == NULL) {
      return -1;
    }
    client.run();
    DebuggerTestHandler::DebugEvent evt;
    while((evt = client.getNextEvent()) == DebuggerTestHandler::IDLE) {
      sleep(1);
    }
    if (evt != DebuggerTestHandler::SUSPENDED) {
      return -1;
    }
    std::cout << "Starting reading variables";
    std::list<Variable> vars = client.getAllVariables(true);
    for (std::list<Variable>::const_iterator it = vars.begin(); it != vars.end(); it++) {
      Variable v = *it;
      std::cout << v.getName() << " " << v.getType() << ":\n";
      std::cout.flush();
      std::list<std::pair<String, String> > data = it->getData();
      for (std::list<std::pair<String, String> >::const_iterator iter = data.begin(); iter != data.end(); iter++) {
        std::cout << "  " << iter->first << " " << iter->second << std::endl;
      }
    }
    client.terminate();
    return 0;
  }
}

int test_debugger_server (int argc, char* argv[]) {
  if (zorba::test_run() != 0) {
  	return 1;
  }
  if (zorba::test_var() != 0) {
    return 1;
  }
	return 0;
}
