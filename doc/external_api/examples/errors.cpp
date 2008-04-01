/**
 *
 */
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/default_error_handler.h>

using namespace zorba;

bool
error_example_1(Zorba* aZorba)
{
  try {
	  XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 

    std::cout << lQuery << std::endl;
  } catch ( ZorbaException& e) {
    std::cout << e << std::endl;
    return true;
  }

	return false;
}

bool
error_example_2(Zorba* aZorba)
{
  try {
	  XQuery_t lQuery = aZorba->compileQuery("1 div"); 

  } catch ( StaticException& se ) {
    std::cout << se << std::endl;
    return true;
  } catch ( DynamicException& de ) {
    std::cout << de << std::endl;
  } catch ( ZorbaException& e) {
    std::cout << e << std::endl;
  }

	return false;
}

// for callback functions that are not overriden, an
// exception will be thrown (see example 4)
// for all the ones that we override, we call the callback function (see example 3)
class MyErrorHandler  : public DefaultErrorHandler 
{
public:
  void
  staticError(const StaticException& aStaticError ) 
  { 
    std::cerr << aStaticError << std::endl;
  }

};

bool
error_example_3(Zorba* aZorba)
{
  MyErrorHandler lHandler;

	XQuery_t lQuery = aZorba->compileQuery("for $i in", &lHandler); 

	return true;
}


bool
error_example_4(Zorba* aZorba)
{
  MyErrorHandler lHandler;

  try {
    // move this outside if constant folding is fixed
    XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 

    lQuery->registerErrorHandler(&lHandler);
    std::cout << lQuery << std::endl;
  } catch (DynamicException& e) {
    std::cerr << e << std::endl; 
    return true;
  }

	return false;
}


int 
errors(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance();

  std::cout << "executing example 1" << std::endl;
	assert(error_example_1(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
	assert(error_example_2(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
	assert(error_example_3(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
	assert(error_example_4(lZorba)); 
  std::cout << std::endl;
  
  return 0;
}
