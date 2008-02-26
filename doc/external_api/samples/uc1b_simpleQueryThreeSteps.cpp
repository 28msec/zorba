
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
*/

int uc1b_simpleQueryThreeSteps(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread_t		zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;

	//create and compile a query
	xquery = zorba_engine->createQuery("1+2");
	//init execution
	xquery->initExecution();
	//do actual execution
	xquery->serializeXML(std::cout);

	return 0;
}
