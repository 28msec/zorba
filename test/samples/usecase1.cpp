
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
*/

int usecase1(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;

	//create and compile a query
	xquery = zorba_engine.createQuery("1+2");
	if(xquery.isNull())
	{
		cout << "Error creating and compiling \"1+2\"" << endl;
		assert(false);
		return 1;
	}

	//execute the query and serialize its result
	if(!xquery->executeSerializeXML(std::cout))
	{
		cout << "Error executing and serializing \"1+2\"" << endl;
		assert(false);
		return 1;
	}

	//no need to care about freeing objects or closing the engine

	return 0;
}
