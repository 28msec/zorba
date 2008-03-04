
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace zorba;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	Chain the result from one xquery to another xquery.
*/

int uc4_chainXQuery(int argc, char* argv[])
{
	bool original_throw_mode = ZorbaAlertsManager::setThrowExceptionsMode(true);
	//init the engine
	ZorbaSingleThread_t zorba_engine = ZorbaSingleThread::getInstance();
  
  try{

    DynamicQueryContext_t		dctx;
	  XQuery_t				xquery1;
	  XQuery_t				xquery2;
	  ResultIterator_t		xqe1;


	  //create and compile a query with the static context
	  xquery1 = zorba_engine->createQuery("1+1");

	  //create the first query execution (but do not execute yet)
	  xquery1->initExecution();
    //get the iterator over the result sequence
	  xqe1 = xquery1->getIterator();

	  //create the second query
	  xquery2 = zorba_engine->createQuery("declare variable $var1 external; $var1+1");

	  //no need for dynamic context here
	  xquery2->initExecution();

	  //chain in the result from first query
    //this function can be called only between initExecution and serialize or getIterator
	  xquery2->setVariableAsXQueryResult("var1", xqe1);

	  //execute the query2 and serialize its result
	  xquery2->serializeXML(std::cout);

  }catch(ZorbaException &x)
	{
		//output the error message
		cerr << x;
    exit(1);
	}

	ZorbaAlertsManager::setThrowExceptionsMode(original_throw_mode);

  return 0;
}
