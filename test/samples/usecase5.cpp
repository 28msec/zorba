
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	This is a should fail example.
	It demonstrates how to retrieve and print error messages.
	You can find the error codes and error classes in zorba/errors/errors.h.
*/

string make_absolute_file_name(const char *target_file_name, const char *this_file_name);


int usecase5(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;

	try{
		//create and compile a query with the static context
		xquery = zorba_engine->createQuery(".//book");

		dctx = zorba_engine->createDynamicContext();
	/*forget to set the context item
		//context item is set 
		dctx->SetContextItemAsDocument(make_absolute_file_name("books.xml", __FILE__));
	*/

		//try to execute the query and serialize its result
		xquery->initExecution(dctx);
		xquery->serializeXML(std::cout);

		assert(false);//unreachable, should exit on error path
		return 1;
	}catch(xqp_exception &x)
	{
		//multiple errors and warnings might get fired
		//display all of them
		ZorbaAlertsManager_t err_manager = zorba_engine->getAlertsManagerForCurrentThread();
		err_manager->dumpAlerts(std::cout);
	}

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
