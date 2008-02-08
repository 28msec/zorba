
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Create a static context object.
  Set the default collation to be used at comparing strings.
*/

int uc6b_defaultCollation(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	StaticQueryContext_t		sctx;

	try{
		//create a static context object
		sctx = zorba_engine->createStaticContext();

    sctx->setDefaultCollation("http://flowrfound.ethz.ch/FLWOR1/collations/German");

		//create and compile a query with the static context
    xquery = zorba_engine->createQuery("fn:compare(\"string1\", \"string2\")", sctx);

    //execute the query and serialize its result
		xquery->initExecution();
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
