/**
 * 
 */
#include <iostream>

#include <zorba/zorba.h>

using namespace xqp;

bool
example_1(Zorba* aZorba)
{
	XQuery_t lQuery = zorba->createQuery("for i in (1 to 3) return <a>$i</a>"); 

  std::cout << lQuery << std::endl;

	return true;
}

bool
example_2(Zorba* aZorba)
{
	XQuery_t lQuery = zorba->createQuery("for i in (1 to 3) return <a>$i</a>"); 

  lQuery->serialize(std::cout);

	return true;
}

bool
example_3(Zorba* aZorba)
{
	XQuery_t lQuery = zorba->createQuery("for i in (1 to 3) return <a>$i</a>"); 

  lQuery->serialize(std::cout, Serialization::HTML);

	return true;
}

bool
example_4(Zorba* aZorba)
{
	XQuery_t lQuery = zorba->createQuery("for i in (1 to 3) return <a>$i</a>"); 

  lQuery->serialize(std::cout, Serialization::TEXT);

	return true;
}

bool
example_5(Zorba* aZorba)
{
	XQuery_t lQuery = zorba->createQuery("for i in (1 to 3) return <a>$i</a>"); 

  Serialization lSerialization;
  lSerialization.add(Serialization::INDENT);

  lQuery->serialize(std::cout, Serialization::XML, lSerialization);

	return true;
}

bool
example_6(Zorba* aZorba)
{
  PlanPrinter_t lPlanPrinter = zorba->getPlanPrinter();

  // TODO not sure about this notation

  // print the abstract syntax tree
  std::cout << lPlanPrinter->ast("(1, 2, 3)") << std::endl;
  
  // print normalized expression tree (unoptimized)
  std::cout << lPlanPrinter->expression("(1, 2, 3)", false) << std::endl;

  // print the optimized expression tree
  std::cout << lPlanPrinter->expression("(1, 2, 3)") << std::endl;

  // print the iterator tree 
  std::cout << PlanPrinter->iterator("(1, 2, 3)") << std::endl;
}

// TODO are there serialization errors?

int 
serialization(int argc, char* argv[])
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

  return 0;
}
