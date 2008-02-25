
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	This is a should fail example.
	It demonstrates how to retrieve and print error messages.
	You can find the error codes and error classes in zorba/errors/errors.h.
*/


int uc5a_errorManager(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;

	try{
		//create and compile a query with the static context
		xquery = zorba_engine->createQuery("1/0");

		//try to execute the query and serialize its result
		xquery->initExecution();
		xquery->serializeXML(std::cout);

		exit(1);//unreachable, should exit on error path
		return 1;
	}catch(ZorbaException &x)
	{
		//multiple errors and warnings might get fired
		//display all of them
		ZorbaAlertsManager_t err_manager = zorba_engine->getAlertsManagerForCurrentThread();
		err_manager->dumpAlerts(std::cout);
	}

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
