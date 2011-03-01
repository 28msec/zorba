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
#ifndef DEBUGGER_TEST_CLIENT_H
#define DEBUGGER_TEST_CLIENT_H

#include "DebuggerTestHandler.h"

#include <zorba/api_shared_types.h>
#include <zorba/debugger_client.h>
#include <zorba/debugger_default_event_handler.h>

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

namespace zorba {

class DebuggerTestClient {
public:
	DebuggerTestClient(int aRequestPort, int aEventPort, std::iostream& aQuery);
	virtual ~DebuggerTestClient();

public:
	void
  run();

  void
  terminate();

  void
  resume();

  void
  eval(std::string anExpr);

  bool
  waitUntil(DebuggerTestHandler::DebuggerState aDesiredState, int aSeconds);

  std::pair<String, std::list<std::pair<String, String> > >
  getLastEvent();

  QueryLocation_t
  addBreakpoint(std::string& fileName, unsigned int aNumber);

  void
  clearBreakpoint(std::string& fileName, unsigned int aNumber);

  QueryLocation_t
  getLocation() const;

  std::vector<std::string> getVariableNames();

private:
  int m_request_port;
  int m_event_port;

	zorba::DebuggerClient* m_client;
	DebuggerTestHandler* m_handler;
  std::iostream& m_query;

};

}

#endif // DEBUGGER_TEST_CLIENT_H
