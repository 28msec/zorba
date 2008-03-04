
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace zorba;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Create a static context object and set the base uri.
  Load a document into XmlDataManager.
  Try to retrieve it in xquery using a relative URI.
*/


int uc6c_baseUri(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	StaticQueryContext_t		sctx;

	try{

		//create a static context object
		sctx = zorba_engine->createStaticContext();

    sctx->setBaseURI("http://flowrfound.ethz.ch/usecases");

		//create and compile a query with the static context containing the base URI
    xquery = zorba_engine->createQuery("fn:resolve-uri(\"books.xml\")", sctx);

    //execute the query and serialize its result
		xquery->initExecution();
		xquery->serializeXML(std::cout);
	}
	catch(ZorbaException &x)
	{
		//output the error message
		cerr << x;
		exit(1);
	}

	//set back the throw exceptions mode for next usecase
	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
