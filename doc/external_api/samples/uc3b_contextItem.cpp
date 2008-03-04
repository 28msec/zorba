
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace zorba;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Set the context item as integer value in dynamic context.
*/

int uc3b_contextItem(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	try{

		XQuery_t				xquery;
		DynamicQueryContext_t		dctx;

		//create and compile a query
    //"." is the context item
		xquery = zorba_engine->createQuery(". + 2");

		//create a dynamic context object
		dctx = zorba_engine->createDynamicContext();
		//set context item as int value
		dctx->setContextItemAsInt(1);


		//execute the query and serialize its result
		xquery->initExecution(dctx);
		xquery->serializeXML(std::cout);

	}catch(ZorbaException &x)
	{
		//output the error message
		cerr << x;
    exit(1);
	}

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);

	return 0;
}
