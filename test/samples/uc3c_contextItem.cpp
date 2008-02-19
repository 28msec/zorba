
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Set the context item as a document item in dynamic context.
*/

/*
  Utility function.
  Gives the full name of a file from the folder where another file resides
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


int uc3c_contextItem(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
	try{

		XQuery_t				xquery;
		DynamicQueryContext_t		dctx;

		//create and compile a query
    //"." is the context item
		xquery = zorba_engine->createQuery(".//book");

		//create a dynamic context object
		dctx = zorba_engine->createDynamicContext();
		//set context item as a document
		dctx->setContextItemAsDocumentFromFile(make_absolute_file_name("books.xml", __FILE__));


		//execute the query and serialize its result
		xquery->initExecution(dctx);
		xquery->serializeXML(std::cout);

	}catch(ZorbaException &x)
	{
		//output the error message
		cerr << x;
    exit(1);
	}

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);

	return 0;
}
