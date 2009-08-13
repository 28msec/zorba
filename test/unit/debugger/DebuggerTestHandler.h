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
#ifndef DEBUGGER_TEST_HANDLER_H
#define DEBUGGER_TEST_HANDLER_H

#include <zorba/debugger_default_event_handler.h>
#include <zorba/debugger_client.h>
#include <zorba/zorba.h>
#include <zorbautils/lock.h>
#include <zorbatypes/rchandle.h>

#include <string>

namespace zorba {

class DebuggerTestHandler : public zorba::DefaultDebuggerEventHandler {
public:
	DebuggerTestHandler(zorba::Zorba* zorba, zorba::ZorbaDebuggerClient* client, std::string fileName);
  virtual ~DebuggerTestHandler();

public:
	enum DebugEvent {
		TERMINATED,
		SUSPENDED,
		IDLE
	};

public:
	DebugEvent getNextEvent();

private:
	zorba::ZorbaDebuggerClient* m_client;
	std::string m_fileName;
	zorba::Zorba* m_zorba;
	SYNC_CODE(zorba::Lock m_lock;)
};

}

#endif //DEBUGGER_TEST_HANDLER_H
