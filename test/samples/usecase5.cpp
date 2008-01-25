
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	How to retrieve and print error messages.
	You can find the error codes and error classes in zorba/errors/errors.h.
*/

string make_absolute_file_name(const char *target_file_name, const char *this_file_name);


int usecase5(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;

	//create and compile a query with the static context
	xquery = zorba_engine.createQuery(".//book");
	if(xquery == NULL)
	{
		cout << "Error creating and compiling query" << endl;
		goto DisplayErrorsAndExit;
		return 1;
	}
	dctx = zorba_engine.createDynamicContext();
/*forget to set the context item
	//context item is set as variable with reserved name "."
	if(!dctx->SetVariableAsDocument(".", make_absolute_file_name("books.xml", __FILE__)))
	{
		assert(false);
		return 1;
	}
*/

	//execute the query and serialize its result
	if(!xquery->initExecution(dctx) ||
		!xquery->serializeXML(std::cout))
	{
		cout << "Error executing and serializing query" << endl;
		goto DisplayErrorsAndExit;
		return 1;
	}

	//shutdown the engine, just for exercise
	zorba_engine.shutdown();
	//using zorba objects after this moment is prohibited

	assert(false);//unreachable, should exit on error way

	return 0;

DisplayErrorsAndExit:
	
	zorba_engine.getAlertsManagerForCurrentThread().DumpAlerts(std::cout);

	zorba_engine.shutdown();

	return -1; 

}
