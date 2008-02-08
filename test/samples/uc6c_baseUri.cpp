
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Create a static context object and set the base uri.
  Load a document into XmlDataManager.
  Try to retrieve it in xquery using a relative URI.
*/

string make_absolute_file_name(const char *target_file_name, const char *this_file_name);

int uc6c_baseUri(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	StaticQueryContext_t		sctx;
  XmlDataManager_t  xml_store;

	try{
    xml_store = zorba_engine->getXmlDataManager();

    xml_store->loadDocument(make_absolute_file_name("books.xml", __FILE__));


		//create a static context object
		sctx = zorba_engine->createStaticContext();

    sctx->setBaseURI(make_absolute_file_name("", __FILE__));

		//create and compile a query with the static context
    xquery = zorba_engine->createQuery("fn:doc(\"books.xml\")", sctx);

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

  //close the single threaded engine to make way to full api
  zorba_engine->shutdown();

	//set back the throw exceptions mode for next usecase
	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
