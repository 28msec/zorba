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
#include "DebuggerTestHandler.h"

#include <zorbaerrors/Assert.h>
#include <debugger/synchronous_logger.h>

#include <iostream>

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

namespace zorba {

DebuggerTestHandler::DebuggerTestHandler(zorba::DebuggerClient* client)
  : m_client(client)
{
}

DebuggerTestHandler::DebuggerState DebuggerTestHandler::getStateAfterRun()
{
	synchronous_logger::cout << "getStateAfterRun()\n";

	while (m_client->isQueryRunning()) {
		synchronous_logger::cout << "Query is running. Waiting...\n";
		sleep(1);
	}

	if (m_client->isQueryTerminated()) {
		synchronous_logger::cout << "Query is TERMINATED\n";
		return TERMINATED;
	} else if (m_client->isQuerySuspended()) {
		synchronous_logger::cout << "Query is SUSPENDED\n";
		return SUSPENDED;
	} else {
		synchronous_logger::cout << "Query is IDLE\n";
		return IDLE;
	}
}

DebuggerTestHandler::~DebuggerTestHandler()
{
}

void
DebuggerTestHandler::evaluated(String &anExpr, std::list<std::pair<String, String> > &aValuesAndTypes) {
  theLastValuesAndTypes.first = anExpr;
  theLastValuesAndTypes.second = aValuesAndTypes;
}

void
DebuggerTestHandler::evaluated(String &anExpr, String &aError)
{
  DefaultDebuggerEventHandler::evaluated(anExpr, aError);
}

std::pair<String, std::list<std::pair<String, String> > >
DebuggerTestHandler::getLastEvent() {
  return theLastValuesAndTypes;
}

}
