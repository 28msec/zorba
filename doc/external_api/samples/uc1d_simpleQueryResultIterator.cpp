
#include "zorba/zorba_singlethread.h"

#include <iostream>

using namespace std;
using namespace zorba;
using namespace zorba::store;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Use the ResultIterator to retrieve result items one by one
*/

int uc1d_simpleQueryResultIterator(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread_t		zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;

	//create and compile a query
	xquery = zorba_engine->createQuery("(1,2)");
	//init execution
	xquery->initExecution();

  //get the result iterator
  //now you cannot call xquery->serialize anymore
  ResultIterator_t    result;
  result = xquery->getIterator();

  //iterate over the result items
  Item_t    item;
  item = result->nextItem();
  while(item != NULL)
  {
    std::cout << "Result item: " << item << std::endl;
    item = result->nextItem();
  }

	return 0;
}
