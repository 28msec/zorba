
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Set the context item in dynamic context
*/

string make_absolute_file_name(const char *target_file_name, const char *this_file_name)
{
	string		str_result;
	string::size_type		pos;

	str_result = this_file_name;
	pos = str_result.rfind('/');
	if(pos == string::npos)
		pos = str_result.rfind('\\');
	if(pos == string::npos)
		return target_file_name;
	str_result.erase(pos+1);
	str_result += target_file_name;
//	cout << "make_absolute_file_name -> " << str_result << endl;
	return str_result;
}


int usecase4(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;

	XmlDataManager_t		zorba_store = zorba_engine.getXmlDataManager();

	//load a document into xml data manager
	//and then load it into a variable
	zorba_store->loadDocument(make_absolute_file_name("books.xml", __FILE__));

	//create and compile a query with the static context
	xquery = zorba_engine.createQuery(".//book");
	if(xquery == NULL)
	{
		cout << "Error creating and compiling query" << endl;
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
