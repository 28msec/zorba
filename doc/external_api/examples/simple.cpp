/**
 *
 */
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>

using namespace zorba;

bool
example_1(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery("1+2"); 

  std::cout << lQuery << std::endl;

	return true;
}

bool
example_2(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("1+2");

  ResultIterator_t lIterator = lQuery->iterator();
  lIterator->open();

  Item lItem;
  while ( lIterator->next(lItem) ) {
    std::cout << lItem.getStringValue() << std::endl;
  }

  lIterator->close();

	return true;
}

bool
example_3(Zorba* aZorba)
{

  try {
    // move this outside if constant folding is fixed
	  XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 
    std::cout << lQuery << std::endl;
  } catch ( DynamicException& e ) {
    std::cerr <<  e << std::endl;
    return true;
  }

	return false;
}


bool
example_4(Zorba* aZorba)
{

  try {
    XQuery_t lQuery = aZorba->compileQuery("for $x in (1, 2, 3)");
  } catch ( StaticException& e ) {
    std::cerr <<  e << std::endl;
    return true;
  }

  return false;
}

bool
example_5(Zorba* aZorba)
{
  std::string lQueryString("for $i in (1,2,3)");
  std::istringstream lInStream(lQueryString);

  try {
    XQuery_t lQuery = aZorba->compileQuery(lInStream);

    std::cout << lQuery << std::endl;
  } catch ( StaticException& se ) {
    std::cerr << se << std::endl;
    return true;
  } catch ( DynamicException& de ) {
    std::cerr << de << std::endl;
  }

  return false;
}

bool
example_6(Zorba* aZorba)
{
  // set compiler hint => don't optimize
  XQuery::CompilerHints lHints;
  lHints.opt_level = XQuery::CompilerHints::O0;

  XQuery_t lQuery = aZorba->compileQuery("1+1", lHints);

  std::cout << lQuery << std::endl;

  return true;
}

bool
example_7()
{

  std::cout << Zorba::version() << std::endl;

  return true;
}

bool
example_8( Zorba * aZorba )
{
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->setFileName("foo.xq");
  lQuery->compile("1+2");
  std::cout << lQuery << std::endl;
  return true;
}

bool
example_9( Zorba * aZorba )
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("1+1");
    lQuery->compile("1+2");
  } catch (SystemException & e) {
    std::cout << e << std::endl;
    return true;
  }
  return false;
}

int 
simple(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance();

  std::cout << "executing example 1" << std::endl;
	assert(example_1(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
	assert(example_2(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
	assert(example_3(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
	assert(example_4(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 5" << std::endl;
	assert(example_5(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 6" << std::endl;
	assert(example_6(lZorba)); 
  std::cout << std::endl;
  
  std::cout << "executing example 7" << std::endl;
	assert(example_7()); 
  std::cout << std::endl;

  std::cout << "executing example 8" << std::endl;
  assert(example_8(lZorba));
  std::cout << std::endl;

  std::cout << "executing example 9" << std::endl;
  assert(example_9(lZorba));
  std::cout << std::endl;

  lZorba->shutdown();
  return 0;
}
