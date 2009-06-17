#include "DebuggerTestClient.h"

#include <zorba/zorba.h>
#include <simplestore/simplestore.h>

#include <iostream>
#include <sstream>
#include <memory>

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
#define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

using namespace std;
using namespace zorba;

ZORBA_THREAD_RETURN server(void* args) {
	std::cout << "Server thread started" << std::endl;
  std::auto_ptr<DebuggerTestClient::ArgStruct> arg((DebuggerTestClient::ArgStruct*)args);
	XQuery_t xquery = arg->xquery;
  // this call blocks
	xquery->debug(*(arg->stream), NULL, 8000, 9000);
	xquery->close();
	std::cout << "Server thread terminated" << std::endl;
	return 0;
}

namespace zorba {
	DebuggerTestClient::DebuggerTestClient( std::string filename, std::string query )
	{
		zorba::simplestore::SimpleStore* store = zorba::simplestore::SimpleStoreManager::getStore();
		m_zorbaInstance = zorba::Zorba::getInstance(store);
		m_queryStream = new istringstream(query);

		m_xquery = m_zorbaInstance->createQuery();
		m_xquery->setFileName(filename);
		m_xquery->setDebugMode(true);

		Zorba_CompilerHints lHints;
		lHints.opt_level = ZORBA_OPT_LEVEL_O0;

		m_xquery->compile(*m_queryStream, lHints);
		ArgStruct* arg = new ArgStruct();
		arg->xquery = m_xquery;
		arg->stream = &m_resultStream;
#ifdef ZORBA_HAVE_PTHREAD_H
		pthread_t lServerThread;
		if ( pthread_create( &lServerThread, 0, server, arg ) != 0 )
#else
		HANDLE lServerThread;
		if ( ( lServerThread = CreateThread( 0, 0, server, arg, 0, 0 ) ) == 0 )
#endif
		{
			std::cerr << "Couldn't start the server thread" << std::endl;
			return;
		}
		m_client = ZorbaDebuggerClient::createClient(8000, 9000);
		m_handler = new DebuggerTestHandler(m_zorbaInstance, m_client, filename);
		m_client->registerEventHandler(m_handler);
	}

	DebuggerTestClient::~DebuggerTestClient()
	{
		m_zorbaInstance->shutdown();
		delete m_queryStream;
		delete m_client;
	}

	void DebuggerTestClient::run()
	{
		m_client->run();
	}

	DebuggerTestHandler::DebugEvent DebuggerTestClient::getNextEvent()
	{
		DebuggerTestHandler::DebugEvent evt = m_handler->getNextEvent();
		if (evt == DebuggerTestHandler::TERMINATED) {
			m_queryResult = m_resultStream.str();
		}
		return evt;
	}

	std::string DebuggerTestClient::getQueryResult() const
	{
		return m_queryResult;
	}
}
