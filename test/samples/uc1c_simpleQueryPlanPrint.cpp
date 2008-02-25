
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Print the plan at different stages for debugging purposes.
*/

int uc1c_simpleQueryPlanPrint(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread_t		zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
  XQueryTreePlans_t xquery_debug;

  //create and setup a debug plan print object
  xquery_debug = zorba_engine->createDebugPlanPrintObject();
  xquery_debug->setOutputASTPlan(&cout);
  xquery_debug->setOutputExpressionPlan(&cout);
  xquery_debug->setOutputNormalizedExpressionPlan(&cout);
  xquery_debug->setOutputRuntimePlan(&cout);

	//create and compile a query using the debug options
	xquery = zorba_engine->createQuery("1+2", NULL, "", false, xquery_debug);
	//init execution
	xquery->initExecution();
	//do actual execution
	xquery->serializeXML(std::cout);

	return 0;
}
