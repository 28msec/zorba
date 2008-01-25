
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Chain the result from one xquery to another xquery.
*/
string make_absolute_file_name(const char *target_file_name, const char *this_file_name);

int usecase6(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	DynamicQueryContext_t		dctx;
	XQuery_t				xquery1;
	XQuery_t				xquery2;
//	XQueryExecution_t		xqe1;
//	XQueryExecution_t		xqe2;

	XmlDataManager_t		zorba_store = zorba_engine.getXmlDataManager();

	//load a document into xml data manager
	//and then load it into a variable
	zorba_store->loadDocument(make_absolute_file_name("books.xml", __FILE__));


	//create and compile a query with the static context
	xquery1 = zorba_engine.createQuery(".//book");
	if(xquery1 == NULL)
	{
		cout << "Error creating and compiling query1" << endl;
		assert(false);
		return 1;
	}

	dctx = zorba_engine.createDynamicContext();
	//context item is set as variable with reserved name "."
	if(!dctx->SetVariableAsDocument(".", make_absolute_file_name("books.xml", __FILE__)))
	{
		cout << "cannot load document into context item" << endl;
		assert(false);
		return 1;
	}

	//create the first query execution (but do not execute yet)
	if(!xquery1->initExecution(dctx))
	{
		cout << "cannot create execution object of first query" << endl;
		assert(false);
		return 1;
	}
	
	//create the second query
	xquery2 = zorba_engine.createQuery("declare variable $var1 as document-node() external; $var1//chapter");
	if(xquery2 == NULL)
	{
		cout << "Error creating and compiling query2" << endl;
		assert(false);
		return 1;
	}

	//no need for dynamic context here
	if(!xquery2->initExecution())
	{
		cout << "cannot create execution object of second query" << endl;
		assert(false);
		return 1;
	}

	//chain the result from first query
	xquery2->SetVariable("var1", xquery1);

	//execute the query2 and serialize its result
	if(!xquery2->serializeXML(std::cout))
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
