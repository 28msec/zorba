
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Set the context item in dynamic context
*/

int usecase4(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;

	//create and compile a query with the static context
	xquery = zorba_engine.createQuery(".//book");
	if(xquery.isNull())
	{
		cout << "Error creating and compiling query" << endl;
		assert(false);
		return 1;
	}

	dctx = zorba_engine.createDynamicContext();
	//context item is set as variable with reserved name "."
	if(!dctx->SetVariableAsDocument(".", "books.xml"))
	{
		cout << "cannot load document into context item" << endl;
		assert(false);
		return 1;
	}


	//execute the query and serialize its result
	if(!xquery->executeSerializeXML(std::cout, dctx))
	{
		cout << "Error executing and serializing query" << endl;
		assert(false);
		return 1;
	}

	//shutdown the engine, just for exercise
	zorba_engine.shutdown();
	//using zorba objects after this moment is prohibited

	return 0;
}
