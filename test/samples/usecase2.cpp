
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Change the static context for compiling the query.
*/

int usecase2(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	StaticQueryContext_t		sctx;

	//create a static context object
	sctx = zorba_engine.createStaticContext();
	sctx->AddNamespace("ns1", "http://www.flworfound.org/samples/ns1");
	cout << "new namespace " << (std::string)sctx->GetNamespaceURIByPrefix("ns1") << endl;
	sctx->SetDefaultElementAndTypeNamespace("http://www.flworfound.org/samples/ns1");
	cout << "default element ns " << (std::string)sctx->GetDefaultElementAndTypeNamespace() << endl;

	//create and compile a query with the static context
	xquery = zorba_engine.createQuery("1+2", sctx);
	if(xquery == NULL)
	{
		cout << "Error creating and compiling \"1+2\"" << endl;
		assert(false);
		return 1;
	}

	//execute the query and serialize its result
	if(!xquery->initExecution() ||
		!xquery->serializeXML(std::cout))
	{
		cout << "Error executing and serializing \"1+2\"" << endl;
		assert(false);
		return 1;
	}

	//no need to care about freeing objects or closing the engine

	return 0;
}
