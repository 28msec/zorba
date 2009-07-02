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
  DebuggerTestClient::ArgStruct* arg = (DebuggerTestClient::ArgStruct*) args;
	XQuery* xquery = arg->xquery;
  // this call blocks
  try {
	  xquery->debug(*(arg->stream), NULL, 8000, 9000);
  } catch (ZorbaException& e) {
    std::cerr << "exception in server thread " << e << std::endl;
  } catch (...) {
    std::cerr << "caught exception" << std::endl;
  }
	std::cout << "Server thread terminated" << std::endl;
	return 0;
}

namespace zorba {
	DebuggerTestClient::DebuggerTestClient( std::string filename, std::string query )
    : m_client(0),
      m_handler(0)
	{
		zorba::simplestore::SimpleStore* store = zorba::simplestore::SimpleStoreManager::getStore();
		m_zorbaInstance = zorba::Zorba::getInstance(store);

    std::stringstream queryStream(query);

		m_xquery = m_zorbaInstance->createQuery();
		m_xquery->setFileName(filename);
		m_xquery->setDebugMode(true);

		Zorba_CompilerHints lHints;
		lHints.opt_level = ZORBA_OPT_LEVEL_O0;

		m_xquery->compile(queryStream, lHints);

		theArguments.xquery = m_xquery.get();
		theArguments.stream = &m_resultStream;

#ifdef ZORBA_HAVE_PTHREAD_H
		if ( pthread_create( &theServerThread, 0, server, &theArguments ) != 0 )
#else
		if ((theServerThread = CreateThread( 0, 0, server, &theArguments, 0, 0)) == NULL )
#endif
		{
			std::cerr << "Couldn't start the server thread" << std::endl;
			return;
		}
    sleep(1);
		m_client = ZorbaDebuggerClient::createClient(8000, 9000);
		m_handler = new DebuggerTestHandler(m_zorbaInstance, m_client, filename);
		m_client->registerEventHandler(m_handler);
	}

	DebuggerTestClient::~DebuggerTestClient()
	{
    m_client->terminate();
#ifdef ZORBA_HAVE_PTHREAD_H
    int res = pthread_join(theServerThread, 0);
    std::cerr << "joined server thread " << res << std::endl;
#endif
    delete m_handler;
    delete m_client;
    m_xquery->close(); // need to close before shutting down zorba
    m_zorbaInstance->shutdown();
    zorba::simplestore::SimpleStoreManager::shutdownStore(zorba::simplestore::SimpleStoreManager::getStore());
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

  QueryLocation_t DebuggerTestClient::addBreakpoint( std::string nspace, unsigned int lNumber )
  {
    QueryLocation_t lLocation(m_client->addBreakpoint(nspace, lNumber));
    if(lLocation->getLineBegin() == 0) {
      std::cerr << "Couldn't find an expression to break in " << nspace << " at line " << lNumber << "\n";
    } else {
      std::cerr << "Set breakpoint at: " <<  lLocation.get()->toString().c_str() << "\n";
    }
    return lLocation;
  }

  std::list<Variable> DebuggerTestClient::getAllVariables(bool data)
  {
    std::list<Variable> res = m_client->getAllVariables(data);
    return res;
  }
}
