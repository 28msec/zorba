
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Create a static context object.
  Set an external variable type, to be known at compile time.
*/

int uc6a_staticContext(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	StaticQueryContext_t		sctx;
	DynamicQueryContext_t		dctx;

	try{
		//create a static context object
		sctx = zorba_engine->createStaticContext();

    sctx->addExternalVariableType("var1", new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));

		//create and compile a query with the static context
		xquery = zorba_engine->createQuery("$var1+2", sctx);

		//create a new generic dynamic context object
		dctx = zorba_engine->createDynamicContext();
		dctx->setVariableAsInt("var1", 1);//set as XS_INT

    //execute the query and serialize its result
		xquery->initExecution(dctx);
		xquery->serializeXML(std::cout);
	}
	catch(ZorbaException &x)
	{
		//output the error message
		cerr << x;
		assert(false);
	}
	//no need to care about freeing objects or closing the engine

	//set back the throw exceptions mode for next usecase
	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
