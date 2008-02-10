
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	This is a should fail example.
	It demonstrates how to set up a callback function to display errors when they appear
*/

/*
Callback for errors.
Will be called for any alert from zorba.
The alert will not be put in the error manager list anymore.
*/
int errCallback(ZorbaAlert_t alert_mess, 
                 XQuery         *current_xquery,
                 ResultIterator *current_result,
                 void *param)
{
  cerr << endl;

  alert_mess->dumpAlert(cerr);

  return -1;
}



int uc5b_errorCallback(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;
  ZorbaAlertsManager_t err_manager;

	try{
		err_manager = zorba_engine->getAlertsManagerForCurrentThread();

    err_manager->registerAlertCallback(errCallback, (void*)1);

    //create and compile a query with the static context
		xquery = zorba_engine->createQuery(".//book");

		dctx = zorba_engine->createDynamicContext();
	/*forget to set the context item
		//context item is set 
		dctx->SetContextItemAsDocumentFromFile(make_absolute_file_name("books.xml", __FILE__));
	*/

		//try to execute the query and serialize its result
		xquery->initExecution(dctx);
		xquery->serializeXML(std::cout);

		assert(false);//unreachable, should exit on error path
		return 1;
	}catch(ZorbaException &x)
	{
    //no more need to display error here
	}
  
  //reset the callback functions, for next usecases
  err_manager->registerAlertCallback(NULL, NULL);

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
