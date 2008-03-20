/**
 *
 */
#include <iostream>
#include <fstream>

#include <zorba/zorba.h>

using namespace xqp;

bool
example_1(Zorba* aZorba)
{
}

int 
simple(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance();

  std::cout << "executing example 1" << std::endl;
	assert(example_1(lZorba)); 
  std::cout << std::endl;

  
  return 0;
}
