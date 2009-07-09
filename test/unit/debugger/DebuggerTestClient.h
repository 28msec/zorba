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
		XQuery* xquery;
		std::ostream* stream;
	} ArgStruct;
public:
	DebuggerTestClient(std::string filename, std::string query);
	virtual ~DebuggerTestClient();

public:
	void run();
  void terminate();
	DebuggerTestHandler::DebugEvent getNextEvent();
	std::string getQueryResult() const;
  QueryLocation_t addBreakpoint(std::string nspace, unsigned int lNumber);
  std::list<Variable> getAllVariables(bool data);

private:
	zorba::Zorba* m_zorbaInstance;
	zorba::XQuery_t m_xquery;
	zorba::ZorbaDebuggerClient* m_client;
	DebuggerTestHandler* m_handler;
	std::string m_queryResult;
	std::ostringstream m_resultStream;
#ifdef ZORBA_HAVE_PTHREAD_H
	pthread_t theServerThread;
#else
	HANDLE theServerThread;
#endif

  ArgStruct  theArguments;
};

}

#endif // DEBUGGER_TEST_CLIENT_H
