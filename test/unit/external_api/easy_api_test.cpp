#include <iostream>

#include <zorba/zorba_singlethread.h>

using namespace zorba;

/**
 * This file contains unit tests for the easy api.
 * Each function "test_i" contains a single (complete) code snippet 
 * that tests a particular function of the api.
 */

// test the very basic functionality of the api
// compile the query "1+1", execute it, and print the XML serialization ofthe result to the standard output
bool
test_1()
{
	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();
	XQuery_t lQuery = zorba_factory->createQuery("1+2"); 

	lQuery->initExecution();
  lQuery->serializeXML(std::cout);

	return true;
}

// test the very basic functionality of the api
// compile the query "1+1", execute it, and print the HTML serialization of the result to the standard output
bool
test_2()
{
	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();
	XQuery_t lQuery = zorba_factory->createQuery("1+2"); 

	lQuery->initExecution();
  lQuery->serializeHTML(std::cout);

	return true;
}

// test the very basic functionality of the api
// compile the query "1+1", execute it, and print the HTML serialization of the result to the standard output
bool
test_3()
{
	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();
	XQuery_t lQuery = zorba_factory->createQuery("1+2"); 

	lQuery->initExecution();
  lQuery->serializeTEXT(std::cout);

	return true;
}


// test setting external variables in the dynamic context and use them in the query
// and print the XML serialization of the result
bool
test_4()
{
  std::string lQueryString("declare variable $x external; for $i in 1 to $x return $i");

	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();
	XQuery_t lQuery = zorba_factory->createQuery(lQueryString); 

  DynamicQueryContext_t lDynCtxt = zorba_factory->createDynamicContext();
  lDynCtxt->setVariableAsInt("x", 2);

	lQuery->initExecution(lDynCtxt);
  lQuery->serializeXML(std::cout);

	return true;
}

// test setting external variables in the dynamic context and use them in the query
// executing the query should fail because a variable is not bound
// in case the correct exception is thrown, this function returns true, otherwise it returns false
bool
test_5()
{
  std::string lQueryString("declare variable $x external; for $i in 1 to $x return $i");

  ZorbaAlertsManager::setThrowExceptionsMode(true);
  ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();

  try
  {
	  XQuery_t lQuery = zorba_factory->createQuery(lQueryString.c_str()); 

    lQuery->serializeXML(std::cout);
  } catch (ZorbaException &e)
  {
    return true;
  }
  return false;
}

int easy_api_test(int argc, char* argv[])
{
  std::cout << std::endl  << "executing easy api test 1" << std::endl;
	assert(test_1()); 
  std::cout << std::endl;

  std::cout << std::endl  << "executing easy api test 2" << std::endl;;
	assert(test_2()); 
  std::cout << std::endl;

  std::cout << std::endl << "executing easy api test 3" << std::endl;;
	assert(test_3()); 
  std::cout << std::endl;

  std::cout << std::endl << "executing easy api test 4" << std::endl;;
	assert(test_4()); 
  std::cout << std::endl;

  std::cout << std::endl << "executing easy api test 5" << std::endl;;
  assert(test_5()); 
  std::cout << std::endl;

  return 0;
}
