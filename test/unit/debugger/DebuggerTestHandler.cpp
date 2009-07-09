#include "DebuggerTestHandler.h"

#include <zorbaerrors/Assert.h>

#include <iostream>

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

namespace zorba {

DebuggerTestHandler::DebuggerTestHandler( zorba::Zorba* zorba, zorba::ZorbaDebuggerClient* client, std::string fileName )
:
m_zorba(zorba), m_client(client), m_fileName(fileName)
{
}

DebuggerTestHandler::DebugEvent DebuggerTestHandler::getNextEvent()
{
	AutoLock lock(m_lock, Lock::WRITE);
	std::cout << "getNextEvent()" << std::endl;
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