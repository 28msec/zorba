
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Use the XmlDataManager to load a xml document into store.
  Then use this document as the context item for .//book
*/

/*
  Utility function.
  Gives the full name of a file from the folder where another file resides
*/
string make_absolute_file_name(const char *target_file_name, const char *this_file_name);

int uc8a_loadDocument(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	try{

		XQuery_t				xquery;
		DynamicQueryContext_t		dctx;
	  XmlDataManager_t		zorba_store = zorba_engine->getXmlDataManager();

	  //load a document into xml data manager
	  //and then load it into a variable
	  zorba_store->loadDocument(make_absolute_file_name("books.xml", __FILE__));

		//create and compile a query
    //"." is the context item
		xquery = zorba_engine->createQuery(".//book");

		//create a dynamic context object
		dctx = zorba_engine->createDynamicContext();
		//set context item as a document
		dctx->setContextItemAsDocument(make_absolute_file_name("books.xml", __FILE__));


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
