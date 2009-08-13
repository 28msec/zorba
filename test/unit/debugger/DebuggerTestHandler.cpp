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

DebuggerTestHandler::DebuggerTestHandler( zorba::Zorba* zorba, zorba::ZorbaDebuggerClient* client, std::string fileName )
: m_client(client), m_fileName(fileName), m_zorba(zorba)
{
}

DebuggerTestHandler::DebugEvent DebuggerTestHandler::getNextEvent()
{
	SYNC_CODE(AutoLock lock(m_lock, Lock::WRITE);)
	synchronous_logger::cout << "getNextEvent()\n";
	while (m_client->isQueryRunning()) {
		sleep(1);
	}
	if (m_client->isQueryTerminated()) {
		std::cout << "Query is terminated" << std::endl;
		return TERMINATED;
	} else if (m_client->isQuerySuspended()) {
		std::cout << "Query is suspended" << std::endl;
		return SUSPENDED;
	} else {
		std::cout << "Query is idle" << std::endl;
		return IDLE;
	}
}

DebuggerTestHandler::~DebuggerTestHandler()
{
}
}
