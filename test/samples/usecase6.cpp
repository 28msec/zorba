
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Chain the result from one xquery to another xquery.
*/

int usecase6(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	DynamicQueryContext_t		dctx;
	XQuery_t				xquery1;
	XQuery_t				xquery2;
	XQueryExecution_t		xqe1;
	XQueryExecution_t		xqe2;

	//create and compile a query with the static context
	xquery1 = zorba_engine.createQuery(".//book");
	if(xquery1.isNull())
	{
		cout << "Error creating and compiling query1" << endl;
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

	//create the first query execution (but do not execute yet)
	xqe1 = xquery1->createExecution(dctx);
	if(xqe1.isNull())
	{
		cout << "cannot create execution object of first query" << endl;
		assert(false);
		return 1;
	}
	
	//create the second query
	xquery2 = zorba_engine.createQuery("declare variable $var1 external; $var1//chapter");
	if(xquery2.isNull())
	{
		cout << "Error creating and compiling query2" << endl;
		assert(false);
		return 1;
	}

	//no need for dynamic context here
	xqe2 = xquery2->createExecution();
	if(xqe2.isNull())
	{
		cout << "cannot create execution object of second query" << endl;
		assert(false);
		return 1;
	}

	//chain the result from first query
	xqe2->SetVariable("var1", xqe1);

	//execute the query2 and serialize its result
	if(!xqe2->serializeXML(std::cout))
	{
		cout << "Error executing and serializing query2" << endl;
		assert(false);
		return 1;
	}

	//shutdown the engine, just for exercise
	zorba_engine.shutdown();
	//using zorba objects after this moment is prohibited

	return 0;
}
