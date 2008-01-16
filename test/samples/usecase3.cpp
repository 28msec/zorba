
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Add a variable into dynamic context before executing
*/

int usecase3(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;

	//create and compile a query with the static context
	xquery = zorba_engine.createQuery("declare variable $var1 external; $var1+2");
	if(xquery.isNull())
	{
		cout << "Error creating and compiling query" << endl;
		assert(false);
		return 1;
	}

	dctx = zorba_engine.createDynamicContext();
	dctx->SetVariableAsInteger("var1", 746);//set as XS_INTEGER


	//execute the query and serialize its result
	if(!xquery->executeSerializeXML(std::cout, dctx))
	{
		cout << "Error executing and serializing query" << endl;
		assert(false);
		return 1;
	}

	//no need to care about freeing objects or closing the engine

	return 0;
}
