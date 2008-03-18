
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace zorba;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Put code in try catch, to listen for errors.
	The zorba engine must be put in throw-exceptions-for-errors mode
*/

int uc2_simpleQueryWithErrorCheck(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;

	try{

		//create and compile a query with the static context
		xquery = zorba_engine->createQuery("1 idiv 0");

		//out query in execution mode 
		xquery->initExecution();
		
		//serialize its result
		xquery->serializeXML(std::cout);

    //unreachable
    exit(1);
	}
	catch(ZorbaException &x)
	{
		//output the error message
		cerr << x;
	}
	//no need to care about freeing objects or closing the engine in single thread mode

	//set back the throw exceptions mode for next usecase
	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
