/**
 *
 */
#include <iostream>
#include <fstream>
#include <string>

#include <zorba/zorba.h>
#include <zorba/default_error_handler.h>

using namespace zorba;

/**
 * Example to show query chaining at work.
 * In this example, we will execute query 1 and chain the results
 * of that query as in input to another query (query 2) by means
 * of an external variable.
 */
bool
chaining_example_1(Zorba* aZorba)
{
  try {
    /* Query 1 */
    XQuery_t lQuery1 = aZorba->compileQuery("for $i in (1 to 20) return $i");

    ResultIterator_t lIterator = lQuery1->iterator();

    /* Query 2 */
    XQuery_t lQuery2 = aZorba->compileQuery("declare variable $x external; for $i in $x return $i * $i");

    DynamicContext* lCtx = lQuery2->getDynamicContext();

    /* We bind the iterator representing the output of query 1 as the value of
     * external variable (x) in query 2
     */
    lCtx->setVariable("x", lIterator);

    std::cout << lQuery2 << std::endl;

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

class MyChainingErrorHandler  : public DefaultErrorHandler 
{
public:
  MyChainingErrorHandler(const std::string& aIdentifier) 
    : theIdentifier(aIdentifier) {}

  void
  typeError(const TypeException& aTypeError ) 
  { 
    std::cerr << "error handler: " << theIdentifier << " error " << aTypeError << std::endl;
  }

protected:
  std::string theIdentifier;
};

/**
 * Example to show the use of error handlers to obtain errors from queries
 * instead of the executor throwing exceptions.
 * Other than that change in behavior, this example is functionally
 * equivalent to the above example.
 */
bool
chaining_example_2(Zorba* aZorba)
{
  MyChainingErrorHandler lErrorHandler1("handler 1");
  MyChainingErrorHandler lErrorHandler2("handler 2");

  XQuery_t lQuery1 = aZorba->compileQuery("let $i := (1 to 42) return $i * $i", &lErrorHandler1);

  ResultIterator_t lIterator = lQuery1->iterator();

  XQuery_t lQuery2 = aZorba->compileQuery("declare variable $x external; for $i in $x return $i * $i", &lErrorHandler2);

  DynamicContext* lCtx = lQuery2->getDynamicContext();

  lCtx->setVariable("x", lIterator);

  std::cout << lQuery2 << std::endl;

	return true;
}

int 
chaining(int argc, char* argv[])
{
#ifndef NDEBUG
  Zorba* lZorba = Zorba::getInstance();
  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = chaining_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = chaining_example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;
#endif
  
  return 0;
}
