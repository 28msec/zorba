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
	XQuery_t lQuery = aZorba->createQuery("declare variable $var external; $var + $var");

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
	XQuery_t lQuery = aZorba->createQuery("declare variable $var external; $var + $var");

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
	XQuery_t lQuery = aZorba->createQuery(".");

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

  XQuery_t lQuery = aZorba->createQuery("declare variable $var external; $var//book");

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

  XQuery_t lQuery = aZorba->createQuery("declare variable $var external; .//book");

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
#if 0
bool
context_example_2(Zorba* aZorba)
{
  StaticContext_t lStaticContext = aZorba->createStaticContext();

  lStaticContext->addCollation("http://flworfound.org/collations/PRIMARY/de/DE", "german");

	XQuery_t lQuery = aZorba->createQuery("fn:compare('Strasse', 'Straße', 'german')", lStaticContext); 

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}
#endif


#if 0
bool
context_example_4(Zorba* aZorba)
{
  StaticContext_t lRootContext = aZorba->createStaticContext();

  lRootContext->addCollation("http://www.flworfound.org/collations/PRIMARY/de", "german");

  StaticContext_t lChildContext = lRootContext->createChildContext();

	XQuery_t lQuery = aZorba->createQuery("fn:compare('Strasse', 'Straße', 'german')", lChildContext); 

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}
#endif


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
  
  return 0;
}
