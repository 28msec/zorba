#ifndef DEBUGGER_TEST_CLIENT_H
#define DEBUGGER_TEST_CLIENT_H

#include "DebuggerTestHandler.h"

#include <zorba/api_shared_types.h>
#include <zorba/debugger_client.h>
#include <zorba/debugger_default_event_handler.h>

#include <string>
#include <iostream>
#include <sstream>

namespace zorba {

class DebuggerTestClient {
public:
	typedef struct {
		XQuery_t xquery;
		std::ostream* stream;
	} ArgStruct;
public:
	DebuggerTestClient(std::string filename, std::string query);
	virtual ~DebuggerTestClient();

public:
	void run();
	DebuggerTestHandler::DebugEvent getNextEvent();
	std::string getQueryResult() const;

private:
	zorba::Zorba* m_zorbaInstance;
	std::istream* m_queryStream;
	zorba::XQuery_t m_xquery;
	zorba::ZorbaDebuggerClient* m_client;
	DebuggerTestHandler* m_handler;
	std::string m_queryResult;
	std::ostringstream m_resultStream;
};

}

#endif // DEBUGGER_TEST_CLIENT_H
