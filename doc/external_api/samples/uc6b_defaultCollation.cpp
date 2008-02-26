
#include <zorba/zorba_singlethread.h>

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
		//create and compile a query comparing two strings with normal collation
    xquery = zorba_engine->createQuery("fn:compare (\"Straße\", \"Strasse\")");

    //execute the query and serialize its result
		xquery->initExecution();
    //strings are different with Zorba default collation
		xquery->serializeXML(std::cout);

    //try again with German collation
    
    //create a static context object
		sctx = zorba_engine->createStaticContext();

    //set the German collation
    sctx->setDefaultCollation("http://flowrfound.ethz.ch/FLWOR1/collations/German");

		//create and compile a query with the static context
    xquery = zorba_engine->createQuery("fn:compare (\"Straße\", \"Strasse\")", sctx);

    //execute the query and serialize its result
		xquery->initExecution();
    //now the strings should compare equal
		xquery->serializeXML(std::cout);
	}
	catch(ZorbaException &x)
	{
		//output the error message
		cerr << x;
		exit(1);
	}
	//no need to care about freeing objects or closing the engine

	//set back the throw exceptions mode for next usecase
	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
