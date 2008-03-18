
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace zorba;

/*
	Using Zorba in single thread mode.
	This is a should fail example.
	It demonstrates how to set up a callback function to display errors when they appear
*/

/*
Callback for errors.
Will be called for any alert from zorba.
The alert will not be put in the error manager list anymore.
Parameters:
alert : describes the alert, be it error, user error, user trace, warning, notification message
current_xquery : pointer to the current xquery being executed
current_result : pointer to the current result iterator
param : parameter registered by the user in ZorbaAlertsManager::registerAlertCallback
*/
int errCallback(ZorbaAlert_t    alert, 
                 XQuery         *current_xquery,
                 ResultIterator *current_result,
                 void *param)
{
  cerr << endl;

  alert->dumpAlert(cerr);

  return -1;
}



int uc5b_errorCallback(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
  ZorbaAlertsManager_t err_manager;

	try{
		err_manager = zorba_engine->getAlertsManagerForCurrentThread();

    err_manager->registerAlertCallback(errCallback, (void*)1);

    //create and compile a query with the static context
		xquery = zorba_engine->createQuery("1 idiv 0");

		//try to execute the query and serialize its result
		xquery->initExecution();
		xquery->serializeXML(std::cout);

		exit(1);//unreachable, should exit on error path
		return 1;
	}catch(ZorbaException &)
	{
    //no more need to display error here
	}
  
  //reset the callback functions, for next usecases
  err_manager->registerAlertCallback(NULL, NULL);

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
