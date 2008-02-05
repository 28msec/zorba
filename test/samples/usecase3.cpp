
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Add a variable into dynamic context before executing.
	Then change the variable value and execute again.
*/

int usecase3(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;

	try{
		//create and compile a query
		xquery = zorba_engine->createQuery("declare variable $var1 external; $var1+2");

		dctx = zorba_engine->createDynamicContext();
		dctx->setVariableAsInt("var1", 1);//set as XS_INTEGER


		//execute the query and serialize its result
		//use the dynamic context as parameter to initExecution
		xquery->initExecution(dctx);

		xquery->serializeXML(std::cout);

		
		//now change the variable value in dynamic context
		dctx->setVariableAsInt("var1", 998);//set as XS_INTEGER

		//re-init execution
		xquery->initExecution(dctx);

		xquery->serializeXML(std::cout);

	}
	catch(xqp_exception &x)
	{
		//output the error message
		cerr << x;
		assert(false);
	}
	//set back the throw exceptions mode for next usecase
	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);

	//no need to care about freeing objects or closing the engine

	return 0;
}
