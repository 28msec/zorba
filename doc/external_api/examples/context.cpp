/**
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>

#include <zorba/zorba.h>

using namespace zorba;

bool
context_example_1(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; $var + $var");

  ItemFactory* lFactory = aZorba->getItemFactory();

  Item lItem = lFactory->createInteger(4);

  DynamicContext_t lCtx = lQuery->getDynamicContext();

  lCtx->setVariable("var", lItem);

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
context_example_2(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; $var + $var");

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

bool
context_example_3(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery(".");

  ItemFactory* lFactory = aZorba->getItemFactory();

  Item lItem = lFactory->createInteger(4);

  DynamicContext_t lCtx = lQuery->getDynamicContext();

  lCtx->setContextItem(lItem);

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
context_example_4(Zorba* aZorba)
{

  std::stringstream lDocStream("<books><book>Book 1</book><book>Book 2</book></books>");

  XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; $var//book");

  DynamicContext_t lCtx = lQuery->getDynamicContext();

  lCtx->setVariableAsDocument("var", "books.xml", lDocStream);

  try {
    std::cout << lQuery << std::endl;
  } catch (DynamicException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

bool
context_example_5(Zorba* aZorba)
{

  std::stringstream lDocStream("<books><book>Book 1</book><book>Book 2</book></books>");

  XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; .//book");

  DynamicContext_t lCtx = lQuery->getDynamicContext();

  lCtx->setContextItemAsDocument("books.xml", lDocStream);

  try {
    std::cout << lQuery << std::endl;
  } catch (DynamicException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

bool
context_example_6(Zorba* aZorba)
{
  StaticContext_t lStaticContext = aZorba->createStaticContext();

  lStaticContext->addCollation("http://www.flworfound.org/collations/PRIMARY/de/DE");

  lStaticContext->setBaseURI("http://www.flworfound.org/");

  if ( lStaticContext->getBaseURI() != "http://www.flworfound.org/")
    return false;

	XQuery_t lQuery = aZorba->compileQuery("fn:compare('Strasse', 'Straße', 'http://www.flworfound.org/collations/PRIMARY/de/DE')", 
                                         lStaticContext); 

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
context_example_7(Zorba* aZorba)
{
  StaticContext_t lStaticContext = aZorba->createStaticContext();

  try {
    lStaticContext->addCollation("http://www.flworfound.org/collations/PRIMARY");

    XQuery_t lQuery = aZorba->compileQuery("fn:compare('Strasse', 'Straße', 'http://www.flworfound.org/collations/PRIMARY')", 
        lStaticContext); 

    std::cout << lQuery << std::endl;

  } catch (StaticException &e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

bool
context_example_8(Zorba* aZorba)
{
	XQuery_t lQuery1 = aZorba->compileQuery("declare ordering ordered; 1"); 

  StaticContext_t lStaticContext1 = lQuery1->getStaticContext();
  
  if (lStaticContext1->getOrderingMode() != StaticContext::ordered)
    return false;

	XQuery_t lQuery2 = aZorba->compileQuery("declare ordering unordered; 1"); 

  StaticContext_t lStaticContext2 = lQuery2->getStaticContext();
  
  return (lStaticContext2->getOrderingMode() == StaticContext::unordered);
}

bool
context_example_9(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("fn:hours-from-dateTime(fn:current-dateTime())"); 

  DynamicContext_t lDynContext = lQuery->getDynamicContext();

  try {
    Item lDateTimeItem = aZorba->getItemFactory()->createDateTime(2008, 03, 30, 16, 05, 42, 0); 

    lDynContext->setCurrentDateTime(lDateTimeItem);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}


int 
context(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance();

  std::cout << "executing example 1" << std::endl;
	assert(context_example_1(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
	assert(context_example_2(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
	assert(context_example_3(lZorba)); 
  std::cout << std::endl;
  
  std::cout << "executing example 4" << std::endl;
	assert(context_example_4(lZorba)); 
  std::cout << std::endl;
  
  std::cout << "executing example 5" << std::endl;
	assert(context_example_5(lZorba)); 
  std::cout << std::endl;
  
  std::cout << "executing example 6" << std::endl;
	assert(context_example_6(lZorba)); 
  std::cout << std::endl;
  
  std::cout << "executing example 7" << std::endl;
	assert(context_example_7(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example_8" << std::endl;
	assert(context_example_8(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example_9" << std::endl;
	assert(context_example_9(lZorba)); 
  std::cout << std::endl;

  return 0;
}
