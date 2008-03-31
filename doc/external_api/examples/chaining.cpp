/**
 *
 */
#include <iostream>
#include <fstream>

#include <zorba/zorba.h>

using namespace zorba;

bool
chaining_example_1(Zorba* aZorba)
{
  try {
    XQuery_t lQuery1 = aZorba->createQuery("for $i in (1 to 20) return $i");

    ResultIterator_t lIterator = lQuery1->iterator();

    XQuery_t lQuery2 = aZorba->createQuery("declare variable $x external; for $i in $x return $i * $i");

    DynamicContext_t lCtx = lQuery2->getDynamicContext();

    lCtx->setVariable("x", lIterator);

    std::cout << lQuery2 << std::endl;

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

int 
chaining(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance();

  std::cout << "executing example 1" << std::endl;
	assert(chaining_example_1(lZorba)); 
  std::cout << std::endl;

  
  return 0;
}
