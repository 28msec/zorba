
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	This is a should fail example.
	It demonstrates how to use multiple alert lists

  There are two xqueries, both fail to execute.
  The error lists will be kept separately.
*/


int uc5c_errorList(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery1;
	XQuery_t				xquery2;
	DynamicQueryContext_t		dctx;
  AlertList_t     alist1;
  AlertList_t     alist2;

	try{
		//create and compile a query with the static context
		xquery1 = zorba_engine->createQuery(".//book");

		dctx = zorba_engine->createDynamicContext();
	/*forget to set the context item
		//context item is set 
		dctx->SetContextItemAsDocumentFromFile(make_absolute_file_name("books.xml", __FILE__));
	*/

		//try to execute the query and serialize its result
		xquery1->initExecution(dctx);
		xquery1->serializeXML(std::cout);

		assert(false);//unreachable, should exit on error path
		return 1;
	}catch(ZorbaException &x)
	{
		ZorbaAlertsManager_t err_manager = zorba_engine->getAlertsManagerForCurrentThread();

    alist1 = err_manager->getAlertList();
    //renew the alert list from error manager
    err_manager->clearAlertList();
	}

// . . . . . . . . . 

	try{
		//create and compile a query with the static context
		xquery2 = zorba_engine->createQuery(".//chapter");

		dctx = zorba_engine->createDynamicContext();
	/*forget to set the context item
		//context item is set 
		dctx->SetContextItemAsDocumentFromFile(make_absolute_file_name("books.xml", __FILE__));
	*/

		//try to execute the query and serialize its result
		xquery2->initExecution(dctx);
		xquery2->serializeXML(std::cout);

		assert(false);//unreachable, should exit on error path
		return 1;
	}catch(ZorbaException &x)
	{
		ZorbaAlertsManager_t err_manager = zorba_engine->getAlertsManagerForCurrentThread();

    alist2 = err_manager->getAlertList();
    //renew the alert list from error manager
    err_manager->clearAlertList();
	}

  //now display the error lists
  std::cerr << "Error list for first xquery: " << endl;
  alist1->dumpAlerts(std::cerr);
  std::cerr << "Error list for second xquery: " << endl;
  alist2->dumpAlerts(std::cerr);

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);
	return 0;
}
