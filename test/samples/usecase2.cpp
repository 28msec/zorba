
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Compile the query with different static context settings.
*/

int usecase2(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	StaticQueryContext_t		sctx;

	try{
		//create a static context object
		sctx = zorba_engine->createStaticContext();
		sctx->addNamespace("ns1", "http://www.flworfound.org/samples/ns1");
		cout << "new namespace " << sctx->getNamespaceURIByPrefix("ns1") << endl;
		sctx->setDefaultElementAndTypeNamespace("http://www.flworfound.org/samples/ns1");
		cout << "default element ns " << sctx->getDefaultElementAndTypeNamespace() << endl;

		//create and compile a query with the static context
		xquery = zorba_engine->createQuery("1+2", sctx);

		//execute the query and serialize its result
		xquery->initExecution();
		xquery->serializeXML(std::cout);
	}
	catch(xqp_exception &x)
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
