#ifndef DEBUGGER_TEST_HANDLER_H
#define DEBUGGER_TEST_HANDLER_H

#include <zorba/debugger_default_event_handler.h>
#include <zorba/debugger_client.h>
#include <zorba/zorba.h>
#include <zorbautils/lock.h>

#include <string>

namespace zorba {

class DebuggerTestHandler : public zorba::DefaultDebuggerEventHandler {
public:
	DebuggerTestHandler(zorba::Zorba* zorba, zorba::ZorbaDebuggerClient* client, std::string fileName);

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
	zorba::Lock m_lock;
};

}

#endif //DEBUGGER_TEST_HANDLER_H
